// $Id$

#include "tao/Transport_Cache_Manager.h"
#include "tao/Transport.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"

#include "ace/Handle_Set.h"

#if !defined (__ACE_INLINE__)
# include "tao/Transport_Cache_Manager.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID (TAO,
           Transport_Cache_Manager,
           "$Id$")


TAO_Transport_Cache_Manager::TAO_Transport_Cache_Manager (void)
  : cache_map_ (),
    cache_lock_ (0)
{
}


TAO_Transport_Cache_Manager::~TAO_Transport_Cache_Manager (void)
{
  // Delete the lock that we have
  delete this->cache_lock_;
}

int
TAO_Transport_Cache_Manager::open (TAO_ORB_Core *orb_core,
                                    size_t size)
{
  // Create the cache_lock
  this->cache_lock_ =
    orb_core->resource_factory ()->create_cached_connection_lock ();

  if (this->cache_lock_ == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("TAO (%P|%t) ERROR TAO_Transport_Cache_Manager::open: "),
                         ACE_TEXT ("Lock creation error\n")),
                        -1);
    }

  // Now open the cache map
  return this->cache_map_.open (size);
}


int
TAO_Transport_Cache_Manager::bind_i (TAO_Cache_ExtId &ext_id,
                                      TAO_Cache_IntId &int_id)
{
  // Get the entry too
  HASH_MAP_ENTRY *entry = 0;

  // When it comes for bind we know the transport is going to be busy
  // and is marked for a partcular thread. So, mark it busy
  int_id.recycle_state (ACE_RECYCLABLE_BUSY);

  int retval = this->cache_map_.bind (ext_id,
                                      int_id,
                                      entry);
  if (retval == 0)
    {
      // The entry has been added to cache succesfully
      // Add the cache_map_entry to the transport
      int_id.transport () ->cache_map_entry (entry);

    }
  else if (retval == 1)
    {
      if (TAO_debug_level > 4 && retval != 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("(%P|%t) TAO_Transport_Cache_Manager::bind_i")
                      ACE_TEXT (" unable to bind in the first attempt \n")
                      ACE_TEXT (" So trying with a new index\n")));
        }


      // There was an entry like this before, so let us do some
      // minor adjustments and rebind
      retval = this->get_last_index_bind (ext_id,
                                          int_id,
                                          entry);
      if (retval == 0)
        {
          int_id.transport ()->cache_map_entry (entry);
        }
    }

  if (TAO_debug_level > 5 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Transport_Cache_Manager::bind_i")
                  ACE_TEXT (" unable to bind \n")));
    }

  return retval;
}

// Used to be in the .inl, but moved here b/c the use of
// TAO_Transport::_duplicate() caused an include file cycle with
// inlining turned on.
int
TAO_Transport_Cache_Manager::find_transport (
  TAO_Transport_Descriptor_Interface *prop,
  TAO_Transport *&transport)
{
  if (prop == 0)
    {
      transport = 0;
      return -1;
    }

  // Compose the ExternId
  TAO_Cache_ExtId ext_id (prop);
  TAO_Cache_IntId int_id;

  int retval = this->find (ext_id,
                           int_id);
  if (retval == 0)
    {
      transport = int_id.relinquish_transport ();
    }

  return retval;
}

int
TAO_Transport_Cache_Manager::find_i (const TAO_Cache_ExtId &key,
                                     TAO_Cache_IntId &value)
{
  HASH_MAP_ENTRY *entry = 0;

  // Get the entry from the Hash Map
  int retval = 0;

  // Get the index of the <key>
  int index = key.index ();

  // Make a temporary object. It does not do a copy.
  TAO_Cache_ExtId tmp_key (key.property ());

  while (retval == 0)
    {
      // Look for an entry in the map
      retval = this->cache_map_.find (tmp_key,
                                      entry);

      // We have an entry in the map, check whether it is idle. If it
      // is idle it would be marked as busy.
      if (entry)
        {
          CORBA::Boolean idle =
            this->is_entry_idle (entry);

          if (idle)
            {
              // Successfully found a TAO_Transport.

              // NOTE: This assignment operator indirectly incurs two
              //       lock operations since it duplicates and releases
              //       TAO_Transport objects.
              value = entry->int_id_;

              if (TAO_debug_level > 4)
                {
                  ACE_DEBUG ((LM_DEBUG,
                              ACE_TEXT ("(%P |%t) index in find <%d>\n"),
                              entry->ext_id_.index ()));
                }
              return 0;
            }
        }

      // Bump the index up
      tmp_key.index (++index);
    }

  // If we are here then it is an error
  if (TAO_debug_level > 4 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Transport_Cache_Manager::find_i")
                  ACE_TEXT (" unable to locate a free connection\n")));
    }

  return retval;
}

int
TAO_Transport_Cache_Manager::rebind_i (const TAO_Cache_ExtId &key,
                                       const TAO_Cache_IntId &value)
{
  return this->cache_map_.rebind (key,
                                  value);
}

int
TAO_Transport_Cache_Manager::trybind_i (const TAO_Cache_ExtId &key,
                                        TAO_Cache_IntId &value)
{
  return this->cache_map_.trybind (key, value);
}

int
TAO_Transport_Cache_Manager::unbind_i (const TAO_Cache_ExtId &key)
{
  return this->cache_map_.unbind (key);
}

int
TAO_Transport_Cache_Manager::unbind_i (const TAO_Cache_ExtId &key,
                                       TAO_Cache_IntId &value)
{
  return this->cache_map_.unbind (key,
                          value);
}

int
TAO_Transport_Cache_Manager::make_idle_i (HASH_MAP_ENTRY *&entry)
{
  if (entry == 0)
    return -1;

  // First get the entry again (if at all things had changed in the
  // cache map in the mean time)
  HASH_MAP_ENTRY *new_entry = 0;
  int retval = this->cache_map_.find (entry->ext_id_,
                                      new_entry);
  if (retval == 0)
    {

      new_entry->int_id_.
        recycle_state (ACE_RECYCLABLE_IDLE_AND_PURGABLE);

      entry = new_entry;
    }
  else if (TAO_debug_level > 0 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Transport_Cache_Manager::make_idle_i:\n")
                  ACE_TEXT ("(%P|%t)     unable to locate the entry to make it idle\n")));
    }

  return retval;
}


int
TAO_Transport_Cache_Manager::close_i (ACE_Handle_Set &handle_set)
{
  for (HASH_MAP_ITER iter = this->cache_map_.begin ();
       iter != this->cache_map_.end ();
       ++iter)
    {
      // First we look through whether we have an entry that has already
      // been closed.

      if ((*iter).int_id_.recycle_state () != ACE_RECYCLABLE_CLOSED)
        {
#if 0
          // @@ This code from Connection_Cache_Manager disappeared
          // during the changeover; we need the functional equivalent back.
          // The problem is that with the locking stuff that we're putting
          // in to the Transport, we might want to encapsulate the whole
          // exercise of adding to the handle set in a method on the transport
          // rather than doing it here.  That way, the locking is correct.
          if ((*iter).int_id_.handler ()->is_registered ())
            {
              handle_set.set_bit ((*iter).int_id_.handler ()->fetch_handle ());
            }
#else
          // Get the transport to fill its associated connection's handle in
          // the handle_set.
          (*iter).int_id_.transport ()->provide_handle (handle_set);
#endif
          // Inform the transport that has a reference to the entry in the
          // map that we are *gone* now. So, the transport should not use
          // the reference to the entry that he has, to acces us *at any
          // time*.
          (*iter).int_id_.transport ()->cache_map_entry (0);
        }
     }

  // Unbind all the entries in the map
  this->cache_map_.unbind_all ();

  return 0;
}

int
TAO_Transport_Cache_Manager::purge_entry_i (HASH_MAP_ENTRY *&entry)
{
  int retval = 0;

  if (entry)
    {
      // Remove the enrty from the Map
     retval =  this->cache_map_.unbind (entry);
    }

  // Set the entry pointer to zero
  entry = 0;

  return retval;
}

void
TAO_Transport_Cache_Manager::mark_invalid_i (HASH_MAP_ENTRY *&entry)
{
  if (entry)
    {
      // Mark the entry as not usable
      entry->int_id_.recycle_state (ACE_RECYCLABLE_PURGABLE_BUT_NOT_IDLE);
    }

}



int
TAO_Transport_Cache_Manager::get_last_index_bind (TAO_Cache_ExtId &key,
                                                  TAO_Cache_IntId &val,
                                                  HASH_MAP_ENTRY *&entry)
{
  CORBA::ULong ctr = entry->ext_id_.index ();

  int retval = 0;

  while (retval == 0)
    {
      // Set the index
      key.index (++ctr);

      // Check to see if an element exists in the Map. If it exists we
      // loop, else we drop out of the loop
      retval =
        this->cache_map_.find (key);
    }

  // Now do a bind again with the new index
  return  this->cache_map_.bind (key,
                                 val,
                                 entry);
}


int
TAO_Transport_Cache_Manager::is_entry_idle (HASH_MAP_ENTRY *&entry)
{
  if (entry->int_id_.recycle_state () == ACE_RECYCLABLE_IDLE_AND_PURGABLE ||
      entry->int_id_.recycle_state () == ACE_RECYCLABLE_IDLE_BUT_NOT_PURGABLE)
    {
      // Save that in the transport
      entry->int_id_.transport ()->cache_map_entry (entry);

      // Mark the connection as busy
      entry->int_id_.recycle_state (ACE_RECYCLABLE_BUSY);

      return 1;
    }

  return 0;
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  // Instantiations for the Hash Map
template class ACE_Equal_To<TAO_Cache_ExtId>;
template class ACE_Hash<TAO_Cache_ExtId>;
template class ACE_Hash_Map_Entry<TAO_Cache_ExtId, TAO_Cache_IntId>;
template class ACE_Hash_Map_Manager<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Manager_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

  // Instantiations for the Hash Map
#pragma instantiate ACE_Equal_To<TAO_Cache_ExtId>
#pragma instantiate ACE_Hash<TAO_Cache_ExtId>
#pragma instantiate ACE_Hash_Map_Entry<TAO_Cache_ExtId, TAO_Cache_IntId>
#pragma instantiate ACE_Hash_Map_Manager<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
