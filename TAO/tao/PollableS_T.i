/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_CORBA::Pollable_tie<T>::Pollable_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::Pollable_tie<T>::Pollable_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::Pollable_tie<T>::Pollable_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::Pollable_tie<T>::Pollable_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::Pollable_tie<T>::~Pollable_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA::Pollable_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::Pollable_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::Pollable_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA::Pollable_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA::Pollable_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA::Pollable_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());
  else
  {
    TAO_POA *poa = TAO_ORB_Core_instance ()->root_poa ();
    PortableServer::POA_var result = poa->_this (env);
    if (env.exception () != 0)
      return PortableServer::POA::_nil ();
    else
      return result._retn ();
  }
}

template <class T> ACE_INLINE
CORBA::Boolean POA_CORBA::Pollable_tie<T>::is_ready  (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->is_ready (
    timeout,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::PollableSet_ptr POA_CORBA::Pollable_tie<T>::create_pollable_set  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->create_pollable_set (
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_CORBA::DIIPollable_tie<T>::DIIPollable_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::DIIPollable_tie<T>::DIIPollable_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::DIIPollable_tie<T>::DIIPollable_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::DIIPollable_tie<T>::DIIPollable_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::DIIPollable_tie<T>::~DIIPollable_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA::DIIPollable_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::DIIPollable_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::DIIPollable_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA::DIIPollable_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA::DIIPollable_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA::DIIPollable_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());
  else
  {
    TAO_POA *poa = TAO_ORB_Core_instance ()->root_poa ();
    PortableServer::POA_var result = poa->_this (env);
    if (env.exception () != 0)
      return PortableServer::POA::_nil ();
    else
      return result._retn ();
  }
}

template <class T> ACE_INLINE
CORBA::Boolean POA_CORBA::DIIPollable_tie<T>::is_ready  (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->is_ready (
    timeout,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::PollableSet_ptr POA_CORBA::DIIPollable_tie<T>::create_pollable_set  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->create_pollable_set (
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_CORBA::PollableSet_tie<T>::PollableSet_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::PollableSet_tie<T>::PollableSet_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::PollableSet_tie<T>::PollableSet_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::PollableSet_tie<T>::PollableSet_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::PollableSet_tie<T>::~PollableSet_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA::PollableSet_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::PollableSet_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::PollableSet_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA::PollableSet_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA::PollableSet_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA::PollableSet_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());
  else
  {
    TAO_POA *poa = TAO_ORB_Core_instance ()->root_poa ();
    PortableServer::POA_var result = poa->_this (env);
    if (env.exception () != 0)
      return PortableServer::POA::_nil ();
    else
      return result._retn ();
  }
}

template <class T> ACE_INLINE
CORBA::DIIPollable_ptr POA_CORBA::PollableSet_tie<T>::create_dii_pollable  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->create_dii_pollable (
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA::PollableSet_tie<T>::add_pollable  (
    CORBA::Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->ptr_->add_pollable (
    potential,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::Pollable_ptr POA_CORBA::PollableSet_tie<T>::poll  (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->poll (
    timeout,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA::PollableSet_tie<T>::remove  (
    CORBA::Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->ptr_->remove (
    potential,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::UShort POA_CORBA::PollableSet_tie<T>::number_left  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->number_left (
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */
