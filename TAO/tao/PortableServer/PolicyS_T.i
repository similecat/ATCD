// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_CORBA_Policy_tie<T>::POA_CORBA_Policy_tie (T &t)
        : ptr_ (&t),
          poa_ (PortableServer::POA::_nil ()),
          rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Policy_tie<T>::POA_CORBA_Policy_tie (T &t, PortableServer::POA_ptr poa)
        : ptr_ (&t),
          poa_ (PortableServer::POA::_duplicate (poa)),
          rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Policy_tie<T>::POA_CORBA_Policy_tie (T *tp, CORBA::Boolean release)
        : ptr_ (tp),
          poa_ (PortableServer::POA::_nil ()),
          rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Policy_tie<T>::POA_CORBA_Policy_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
        : ptr_ (tp),
          poa_ (PortableServer::POA::_duplicate (poa)),
          rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Policy_tie<T>::~POA_CORBA_Policy_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_Policy_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_Policy_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_Policy_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_Policy_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_Policy_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_Policy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_Policy::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
CORBA::PolicyType POA_CORBA_Policy_tie<T>::policy_type  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->policy_type (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Policy_ptr POA_CORBA_Policy_tie<T>::copy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->copy (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Policy_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */
