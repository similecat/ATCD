/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Group_Adapter.h
//
// = AUTHOR
//    Frank Hunleth
//
// ============================================================================

#ifndef TAO_GROUP_ADAPTER_H
#define TAO_GROUP_ADAPTER_H
#include "ace/pre.h"


#include "portablegroup_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

// ****************************************************************

// Forward declaration


class TAO_PortableGroup_Export TAO_Group_Adapter : public TAO_Adapter
{
  // = TITLE
  //     Defines the Group Adapter abstraction.
  //
  // = DESCRIPTION
  //     This class will be used as a facade for the PGAs in a server
public:

  friend class TAO_PGA;

  typedef PortableServer::ObjectId poa_name;
  typedef PortableServer::ObjectId_var poa_name_var;
  typedef PortableServer::ObjectId_out poa_name_out;

  TAO_Group_Adapter (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters,
                      TAO_ORB_Core &orb_core);
  // Constructor.

  ~TAO_Group_Adapter (void);
  // Destructor.

  int dispatch_servant (const TAO_ObjectKey &key,
                        TAO_ServerRequest &req,
                        void *context,
                        CORBA::Object_out forward_to,
                        CORBA_Environment &ACE_TRY_ENV);

  int locate_servant (const TAO_ObjectKey &key,
                      CORBA_Environment &ACE_TRY_ENV);

  TAO_SERVANT_LOCATION find_servant (const TAO_ObjectKey &key,
                                     PortableServer::Servant &servant,
                                     CORBA_Environment &ACE_TRY_ENV);

  int find_poa (const poa_name &system_name,
                CORBA::Boolean activate_it,
                CORBA::Boolean root,
                const TAO_Temporary_Creation_Time &poa_creation_time,
                TAO_POA *&poa,
                CORBA_Environment &ACE_TRY_ENV);

  int bind_poa (const poa_name &folded_name,
                TAO_POA *poa,
                poa_name_out system_name);

  int unbind_poa (TAO_POA *poa,
                  const poa_name &folded_name,
                  const poa_name &system_name);

  int activate_poa (const poa_name &folded_name,
                    TAO_POA *&poa,
                    CORBA_Environment &ACE_TRY_ENV);

  ACE_Lock &lock (void);

  TAO_SYNCH_MUTEX &thread_lock (void);

  ACE_Reverse_Lock<ACE_Lock> &reverse_lock (void);

  TAO_POA *root_poa (void) const;
  // Access the root poa.

  TAO_ORB_Core &orb_core (void) const;
  // Access to ORB Core.

  void wait_for_non_servant_upcalls_to_complete (CORBA::Environment &ACE_TRY_ENV);
  // Wait for non-servant upcalls to complete.

  void wait_for_non_servant_upcalls_to_complete (void);
  // Non-exception throwing version.

  static CORBA::ULong transient_poa_name_size (void);


  // = The TAO_Adapter methods, please check tao/Adapter.h for the
  // documentation
  virtual void open (CORBA::Environment &ACE_TRY_ENV);
  virtual void close (int wait_for_completion,
                      CORBA::Environment &ACE_TRY_ENV);
  virtual void check_close (int wait_for_completion,
                            CORBA::Environment &ACE_TRY_ENV);
  virtual int priority (void) const;
  virtual int dispatch (TAO_ObjectKey &key,
                        TAO_ServerRequest &request,
                        void *context, /* unused? */
                        CORBA::Object_out foward_to,
                        CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual const char *name (void) const;
  virtual CORBA::Object_ptr root (void);
  virtual CORBA::Object_ptr create_collocated_object (TAO_Stub *,
                                                      const TAO_MProfile &);

protected:

  int locate_servant_i (const TAO_ObjectKey &key,
                        CORBA_Environment &ACE_TRY_ENV);

  TAO_SERVANT_LOCATION find_servant_i (const TAO_ObjectKey &key,
                                       PortableServer::Servant &servant,
                                       CORBA_Environment &ACE_TRY_ENV);

  void dispatch_servant_i (const TAO_ObjectKey &key,
                           TAO_ServerRequest &req,
                           void *context,
                           CORBA_Environment &ACE_TRY_ENV);

  void locate_poa (const TAO_ObjectKey &key,
                   PortableServer::ObjectId &id,
                   TAO_POA *&poa,
                   CORBA_Environment &ACE_TRY_ENV);

  int find_transient_poa (const poa_name &system_name,
                          CORBA::Boolean root,
                          const TAO_Temporary_Creation_Time &poa_creation_time,
                          TAO_POA *&poa,
                          CORBA_Environment &ACE_TRY_ENV);

  int find_persistent_poa (const poa_name &system_name,
                           TAO_POA *&poa,
                           CORBA_Environment &ACE_TRY_ENV);

  int bind_transient_poa (TAO_POA *poa,
                          poa_name_out system_name);

  int bind_persistent_poa (const poa_name &folded_name,
                           TAO_POA *poa,
                           poa_name_out system_name);

  int unbind_transient_poa (const poa_name &system_name);

  int unbind_persistent_poa (const poa_name &folded_name,
                             const poa_name &system_name);

  static ACE_Lock *create_lock (int enable_locking,
                                TAO_SYNCH_MUTEX &thread_lock);

public:

  class TAO_PortableServer_Export Hint_Strategy
  {
    // = TITLE
    //     Base class for POA active hint strategy.
    //
    // = DESCRIPTION
    //     This class also provides for common structures used by all
    //     the derived classes.
  public:

    virtual ~Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV) = 0;

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name) = 0;

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name) = 0;

    void object_adapter (TAO_Group_Adapter *oa);

  protected:

    TAO_Group_Adapter *object_adapter_;
  };

  class TAO_PortableServer_Export Active_Hint_Strategy : public Hint_Strategy
  {
    // = TITLE
    //     This class uses active demux hint for POA active hint
    //     strategy.
    //
    // = DESCRIPTION
    //     This class will append an active hint to the POA name,
    //     making the POA lookups fast and predictable.
  public:

    Active_Hint_Strategy (CORBA::ULong map_size);

    virtual ~Active_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV);

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name);

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name);

  protected:

    typedef ACE_Active_Map_Manager_Adapter<
    poa_name,
      TAO_POA *,
      TAO_Preserve_Original_Key_Adapter> persistent_poa_system_map;

    persistent_poa_system_map persistent_poa_system_map_;
  };

  class TAO_PortableServer_Export No_Hint_Strategy : public Hint_Strategy
  {
    // = TITLE
    //     This class doesn't use any hints for POA active hint
    //     strategy.
    //
    // = DESCRIPTION
    //     This class will simply use the POA names as is. And since
    //     no hint is added, the IORs will be smaller.
  public:

    virtual ~No_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV);

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name);

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name);

  };

protected:

  Hint_Strategy *hint_strategy_;

  typedef ACE_Map<
  poa_name,
    TAO_POA *> transient_poa_map;
  // Base class of the id map.

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<poa_name>,
    TAO_Incremental_Key_Generator> transient_poa_hash_map;
  // Id hash map.
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Incremental_Key_Generator> transient_poa_linear_map;
  // Id linear map.
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

  typedef ACE_Active_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Ignore_Original_Key_Adapter> transient_poa_active_map;
  // Id active map.

  typedef ACE_Map<
  poa_name,
    TAO_POA *> persistent_poa_name_map;
  // Base class of the name map.

  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<PortableServer::ObjectId>,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_hash_map;
  // Id hash map.

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_linear_map;
  // Id linear map.
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

public:

  persistent_poa_name_map *persistent_poa_name_map_;
  transient_poa_map *transient_poa_map_;

protected:

  static size_t transient_poa_name_size_;

  static void set_transient_poa_name_size (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters);

  TAO_ORB_Core &orb_core_;

  int enable_locking_;

  TAO_SYNCH_MUTEX thread_lock_;

  ACE_Lock *lock_;

  ACE_Reverse_Lock<ACE_Lock> reverse_lock_;

public:

  class TAO_PortableServer_Export poa_name_iterator
  {
    // = TITLE
    //     Iterator for a folded poa name.
  public:

    poa_name_iterator (int begin,
                       CORBA::ULong size,
                       const CORBA::Octet *folded_buffer);
    // Constructor.

    int operator== (const poa_name_iterator &rhs) const;
    int operator!= (const poa_name_iterator &rhs) const;
    // Comparison operators.

    ACE_CString operator* () const;
    // Dereference operator.

    poa_name_iterator &operator++ (void);
    // Prefix advance.

  protected:

    CORBA::ULong size_;
    CORBA::ULong position_;
    const CORBA::Octet *folded_buffer_;
    CORBA::ULong last_separator_;
  };

  class TAO_PortableServer_Export iteratable_poa_name
  {
    // = TITLE
    //     This class allows iteration over a folded poa name.
  public:

    typedef poa_name_iterator iterator;

    iteratable_poa_name (const poa_name &folded_name);

    iterator begin (void) const;
    iterator end (void) const;

  protected:

    const poa_name &folded_name_;
  };

  class TAO_PortableServer_Export Non_Servant_Upcall
  {
    // = TITLE
    //     This class helps us with a recursive thread lock without
    //     using a recursive thread lock.  Non_Servant_Upcall has a
    //     magic constructor and destructor.  We unlock the
    //     Object_Adapter lock for the duration of the non-servant
    //     (i.e., adapter activator and servant activator) upcalls;
    //     reacquiring once the upcalls complete.  Even though we are
    //     releasing the lock, other threads will not be able to make
    //     progress since
    //     <Object_Adapter::non_servant_upcall_in_progress_> has been
    //     set.
  public:

    Non_Servant_Upcall (TAO_POA &poa);
    // Constructor.

    ~Non_Servant_Upcall (void);
    // Destructor.

    TAO_PGA &poa (void) const;

  protected:

    TAO_Group_Adapter &object_adapter_;
    TAO_PGA &pga_;
  };

  friend class Non_Servant_Upcall;

  class TAO_PortableServer_Export Servant_Upcall
  {
    // = TITLE
    //     This class finds out the POA and the servant to perform an
    //     upcall.  It can only be instantiated without the object
    //     adapter's lock held.
  public:

    friend class TAO_POA;

    // @@ PPOA: Servant_Upcall (TAO_Group_Adapter &object_adapter);
    Servant_Upcall (TAO_ORB_Core *orb_core);
    // Constructor.

    ~Servant_Upcall (void);
    // Destructor.

    int prepare_for_upcall (const TAO_ObjectKey &key,
                            const char *operation,
                            CORBA::Object_out forward_to,
                            CORBA::Environment &ACE_TRY_ENV = TAO_default_environment ());
    // Locate POA and servant.

    TAO_POA &poa (void) const;
    // POA accessor.

    TAO_Group_Adapter &object_adapter (void) const;
    // Object Adapter accessor.

    const PortableServer::ObjectId &id (void) const;
    // ID accessor.

    PortableServer::Servant servant (void) const;
    // Servant accessor.

#if (TAO_HAS_MINIMUM_POA == 0)

    PortableServer::ServantLocator::Cookie locator_cookie (void) const;
    // Get the Servant Locator's cookie

    void locator_cookie (PortableServer::ServantLocator::Cookie cookie);
    // Set the Servant Locator's cookie

    const char *operation (void) const;
    // Get the operation name.

    void operation (const char *);
    // Set the operation name.

#endif /* TAO_HAS_MINIMUM_POA == 0 */

    void active_object_map_entry (TAO_Active_Object_Map::Map_Entry *entry);
    // Set the <active_object_map_entry>.

    TAO_Active_Object_Map::Map_Entry *active_object_map_entry (void) const;
    // Get the <active_object_map_entry>.

    void using_servant_locator (void);
    // We are using the servant locator for this upcall.

  protected:

    void servant_locator_cleanup (void);
    void single_threaded_poa_setup (CORBA::Environment &ACE_TRY_ENV);
    void single_threaded_poa_cleanup (void);
    void servant_cleanup (void);
    void poa_cleanup (void);

    TAO_Group_Adapter *object_adapter_;

    TAO_POA *poa_;

    PortableServer::Servant servant_;

    enum State
    {
      INITIAL_STAGE,
      OBJECT_ADAPTER_LOCK_ACQUIRED,
      POA_CURRENT_SETUP,
      OBJECT_ADAPTER_LOCK_RELEASED,
      SERVANT_LOCK_ACQUIRED
    };

    State state_;

    PortableServer::ObjectId id_;

    TAO_POA_Current_Impl current_context_;

#if (TAO_HAS_MINIMUM_POA == 0)

    PortableServer::ServantLocator::Cookie cookie_;
    // Servant Locator's cookie

    const char *operation_;
    // Operation name for this current.

#endif /* TAO_HAS_MINIMUM_POA == 0 */

    TAO_Active_Object_Map::Map_Entry *active_object_map_entry_;
    // Pointer to the entry in the TAO_Active_Object_Map corresponding
    // to the servant for this request.

    int using_servant_locator_;
    // Are we using the servant locator?

  private:
    Servant_Upcall (const Servant_Upcall &);
    void operator= (const Servant_Upcall &);
  };

  friend class Servant_Upcall;

#if (TAO_HAS_RT_CORBA == 1)

  class TAO_PortableServer_Export Priority_Model_Processing
  {
    // = TITLE
    //     This class encapsulates processing necessary for
    //     RTCORBA CLIENT_PROPAGATED priority model.
    //
    //     Although the destructor of this class resets the priority of
    //     the thread to it's original value, application should use
    //     <post_invoke> method for that purpose: destructor cannot
    //     propagate possible exceptions to the callee.  Destructor's
    //     reset capability is intended as a last resort, i.e., if
    //     <post_invoke> isn't reached for some reason.
    //
  public:

    Priority_Model_Processing (TAO_POA &poa);
    // Constructor.

    ~Priority_Model_Processing (void);
    // Resets the priority of the current thread back to its original
    // value if necessary, i.e., if it was changed and the
    // <post_invoke> method hasn't been called.  Unlike <post_invoke>,
    // this method cannot propagate exceptions to the user.

    void pre_invoke (TAO_Service_Context &request_service_context,
                     TAO_Service_Context &reply_service_context,
                     CORBA::Environment &ACE_TRY_ENV);
    // Checks if target POA supports RTCORBA::CLIENT_PROPAGATED
    // PriorityModel.  If so, stores the original priority of the
    // current thread, and sets the thread to the client-propagated
    // priority.

    void post_invoke (CORBA::Environment &ACE_TRY_ENV);
    // Resets the priority of the current thread back to its original
    // value, if necessary.

  private:

    Priority_Model_Processing (const Priority_Model_Processing &);
    void operator= (const Priority_Model_Processing &);

    enum State
    {
      NO_ACTION_REQUIRED,
      PRIORITY_RESET_REQUIRED
    };

    State state_;
    // Indicates whether the priority of the thread needs to be reset
    // back to its original value.

    TAO_POA &poa_;
    // Poa of the target servant.

    RTCORBA::Priority original_priority_;
    // Original priority of the thread.
  };

#endif /* TAO_HAS_RT_CORBA == 1 */

public:

  Non_Servant_Upcall *non_servant_upcall_in_progress (void) const;
  // Pointer to the non-servant upcall in progress.  If no non-servant
  // upcall is in progress, this pointer is zero.

private:

  TAO_SYNCH_CONDITION non_servant_upcall_condition_;
  // Condition variable for waiting on non-servant upcalls to end.

  Non_Servant_Upcall *non_servant_upcall_in_progress_;
  // Pointer to the non-servant upcall in progress.  If no non-servant
  // upcall is in progress, this pointer is zero.

  ACE_thread_t non_servant_upcall_thread_;
  // Id of thread making the non-servant upcall.

  TAO_POA *root_;
  // The Root POA
};

// ****************************************************************

class TAO_PortableServer_Export TAO_Group_Adapter_Factory : public TAO_Adapter_Factory
{
public:
  TAO_Group_Adapter_Factory (void);
  // Constructor

  // = The TAO_Adapter_Factory methods, please read tao/Adapter.h for
  // details.
  virtual TAO_Adapter *create (TAO_ORB_Core *orb_core);
};

ACE_STATIC_SVC_DECLARE (TAO_Group_Adapter_Factory)
ACE_FACTORY_DECLARE (TAO_PortableGroup, TAO_Group_Adapter_Factory)

// ****************************************************************

#if defined (__ACE_INLINE__)
# include "Group_Adapter.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_GROUP_ADAPTER_H */
