// -*- C++ -*- $Id$ */
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

#include "PollableC.h"

#if (TAO_HAS_AMI_POLLER == 1)

#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/Any.h"

#if !defined (__ACE_INLINE__)
#include "PollableC.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, PollableC, "$Id$")

// *************************************************************
// Operations for class CORBA_Pollable_var
// *************************************************************

CORBA_Pollable_var::CORBA_Pollable_var (void) // default constructor
  : ptr_ (CORBA_Pollable::_nil ())
{}

::CORBA_Pollable_ptr
CORBA_Pollable_var::ptr (void) const
{
  return this->ptr_;
}

CORBA_Pollable_var::CORBA_Pollable_var (const ::CORBA_Pollable_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA_Pollable::_duplicate (p.ptr ()))
{}

CORBA_Pollable_var::~CORBA_Pollable_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

CORBA_Pollable_var &
CORBA_Pollable_var::operator= (CORBA_Pollable_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

CORBA_Pollable_var &
CORBA_Pollable_var::operator= (const ::CORBA_Pollable_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::CORBA_Pollable::_duplicate (p.ptr ());
  }
  return *this;
}

CORBA_Pollable_var::operator const ::CORBA_Pollable_ptr &() const // cast
{
  return this->ptr_;
}

CORBA_Pollable_var::operator ::CORBA_Pollable_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::operator-> (void) const
{
  return this->ptr_;
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::in (void) const
{
  return this->ptr_;
}

::CORBA_Pollable_ptr &
CORBA_Pollable_var::inout (void)
{
  return this->ptr_;
}

::CORBA_Pollable_ptr &
CORBA_Pollable_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_Pollable::_nil ();
  return this->ptr_;
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::CORBA_Pollable_ptr val = this->ptr_;
  this->ptr_ = ::CORBA_Pollable::_nil ();
  return val;
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::duplicate (CORBA_Pollable_ptr p)
{
  return ::CORBA_Pollable::_duplicate (p);
}

void
CORBA_Pollable_var::release (CORBA_Pollable_ptr p)
{
  CORBA::release (p);
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::nil (void)
{
  return ::CORBA_Pollable::_nil ();
}

::CORBA_Pollable_ptr
CORBA_Pollable_var::narrow (
    CORBA::Object *p,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ::CORBA_Pollable::_narrow (p, ACE_TRY_ENV);
}

CORBA::Object *
CORBA_Pollable_var::upcast (void *src)
{
  CORBA_Pollable **tmp =
    ACE_static_cast (CORBA_Pollable **, src);
  return *tmp;
}
// *************************************************************
// Inline operations for class CORBA_Pollable_out
// *************************************************************

CORBA_Pollable_out::CORBA_Pollable_out (CORBA_Pollable_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::CORBA_Pollable::_nil ();
}

CORBA_Pollable_out::CORBA_Pollable_out (CORBA_Pollable_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_Pollable::_nil ();
}

CORBA_Pollable_out::CORBA_Pollable_out (const ::CORBA_Pollable_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_Pollable_out &, p).ptr_)
{}

::CORBA_Pollable_out &
CORBA_Pollable_out::operator= (const ::CORBA_Pollable_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_Pollable_out&, p).ptr_;
  return *this;
}

CORBA_Pollable_out &
CORBA_Pollable_out::operator= (const ::CORBA_Pollable_var &p)
{
  this->ptr_ = ::CORBA_Pollable::_duplicate (p.ptr ());
  return *this;
}

CORBA_Pollable_out &
CORBA_Pollable_out::operator= (CORBA_Pollable_ptr p)
{
  this->ptr_ = p;
  return *this;
}

CORBA_Pollable_out::operator ::CORBA_Pollable_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_Pollable_ptr &
CORBA_Pollable_out::ptr (void) // ptr
{
  return this->ptr_;
}

::CORBA_Pollable_ptr
CORBA_Pollable_out::operator-> (void)
{
  return this->ptr_;
}


// default constructor
CORBA_Pollable::CORBA_Pollable ()
{
  }

// destructor
CORBA_Pollable::~CORBA_Pollable (void)
{}

CORBA_Pollable_ptr CORBA_Pollable::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return CORBA_Pollable::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_Pollable_ptr CORBA_Pollable::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Pollable::_nil ();
  return
      ACE_reinterpret_cast
        (
          CORBA_Pollable_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_Pollable::_narrow
                  )
              )
        );
}

CORBA_Pollable_ptr
CORBA_Pollable::_duplicate (CORBA_Pollable_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *CORBA_Pollable::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_Pollable::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_Pollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Pollable:1.0";
}

// *************************************************************
// Operations for class CORBA_DIIPollable_var
// *************************************************************

CORBA_DIIPollable_var::CORBA_DIIPollable_var (void) // default constructor
  : ptr_ (CORBA_DIIPollable::_nil ())
{}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::ptr (void) const
{
  return this->ptr_;
}

CORBA_DIIPollable_var::CORBA_DIIPollable_var (const ::CORBA_DIIPollable_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA_DIIPollable::_duplicate (p.ptr ()))
{}

CORBA_DIIPollable_var::~CORBA_DIIPollable_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

CORBA_DIIPollable_var &
CORBA_DIIPollable_var::operator= (CORBA_DIIPollable_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

CORBA_DIIPollable_var &
CORBA_DIIPollable_var::operator= (const ::CORBA_DIIPollable_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::CORBA_DIIPollable::_duplicate (p.ptr ());
  }
  return *this;
}

CORBA_DIIPollable_var::operator const ::CORBA_DIIPollable_ptr &() const // cast
{
  return this->ptr_;
}

CORBA_DIIPollable_var::operator ::CORBA_DIIPollable_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::operator-> (void) const
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::in (void) const
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr &
CORBA_DIIPollable_var::inout (void)
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr &
CORBA_DIIPollable_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_DIIPollable::_nil ();
  return this->ptr_;
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::CORBA_DIIPollable_ptr val = this->ptr_;
  this->ptr_ = ::CORBA_DIIPollable::_nil ();
  return val;
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::duplicate (CORBA_DIIPollable_ptr p)
{
  return ::CORBA_DIIPollable::_duplicate (p);
}

void
CORBA_DIIPollable_var::release (CORBA_DIIPollable_ptr p)
{
  CORBA::release (p);
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::nil (void)
{
  return ::CORBA_DIIPollable::_nil ();
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_var::narrow (
    CORBA::Object *p,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ::CORBA_DIIPollable::_narrow (p, ACE_TRY_ENV);
}

CORBA::Object *
CORBA_DIIPollable_var::upcast (void *src)
{
  CORBA_DIIPollable **tmp =
    ACE_static_cast (CORBA_DIIPollable **, src);
  return *tmp;
}
// *************************************************************
// Inline operations for class CORBA_DIIPollable_out
// *************************************************************

CORBA_DIIPollable_out::CORBA_DIIPollable_out (CORBA_DIIPollable_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::CORBA_DIIPollable::_nil ();
}

CORBA_DIIPollable_out::CORBA_DIIPollable_out (CORBA_DIIPollable_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_DIIPollable::_nil ();
}

CORBA_DIIPollable_out::CORBA_DIIPollable_out (const ::CORBA_DIIPollable_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DIIPollable_out &, p).ptr_)
{}

::CORBA_DIIPollable_out &
CORBA_DIIPollable_out::operator= (const ::CORBA_DIIPollable_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DIIPollable_out&, p).ptr_;
  return *this;
}

CORBA_DIIPollable_out &
CORBA_DIIPollable_out::operator= (const ::CORBA_DIIPollable_var &p)
{
  this->ptr_ = ::CORBA_DIIPollable::_duplicate (p.ptr ());
  return *this;
}

CORBA_DIIPollable_out &
CORBA_DIIPollable_out::operator= (CORBA_DIIPollable_ptr p)
{
  this->ptr_ = p;
  return *this;
}

CORBA_DIIPollable_out::operator ::CORBA_DIIPollable_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr &
CORBA_DIIPollable_out::ptr (void) // ptr
{
  return this->ptr_;
}

::CORBA_DIIPollable_ptr
CORBA_DIIPollable_out::operator-> (void)
{
  return this->ptr_;
}


// default constructor
CORBA_DIIPollable::CORBA_DIIPollable ()
{
  }

// destructor
CORBA_DIIPollable::~CORBA_DIIPollable (void)
{}

CORBA_DIIPollable_ptr CORBA_DIIPollable::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return CORBA_DIIPollable::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_DIIPollable_ptr CORBA_DIIPollable::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_DIIPollable::_nil ();
  return
      ACE_reinterpret_cast
        (
          CORBA_DIIPollable_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_DIIPollable::_narrow
                  )
              )
        );
}

CORBA_DIIPollable_ptr
CORBA_DIIPollable::_duplicate (CORBA_DIIPollable_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *CORBA_DIIPollable::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_DIIPollable::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_Pollable::_narrow))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            CORBA_Pollable_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_DIIPollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DIIPollable:1.0";
}

// *************************************************************
// Operations for class CORBA_PollableSet_var
// *************************************************************

CORBA_PollableSet_var::CORBA_PollableSet_var (void) // default constructor
  : ptr_ (CORBA_PollableSet::_nil ())
{}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::ptr (void) const
{
  return this->ptr_;
}

CORBA_PollableSet_var::CORBA_PollableSet_var (const ::CORBA_PollableSet_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA_PollableSet::_duplicate (p.ptr ()))
{}

CORBA_PollableSet_var::~CORBA_PollableSet_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

CORBA_PollableSet_var &
CORBA_PollableSet_var::operator= (CORBA_PollableSet_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

CORBA_PollableSet_var &
CORBA_PollableSet_var::operator= (const ::CORBA_PollableSet_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::CORBA_PollableSet::_duplicate (p.ptr ());
  }
  return *this;
}

CORBA_PollableSet_var::operator const ::CORBA_PollableSet_ptr &() const // cast
{
  return this->ptr_;
}

CORBA_PollableSet_var::operator ::CORBA_PollableSet_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::operator-> (void) const
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::in (void) const
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr &
CORBA_PollableSet_var::inout (void)
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr &
CORBA_PollableSet_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_PollableSet::_nil ();
  return this->ptr_;
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::CORBA_PollableSet_ptr val = this->ptr_;
  this->ptr_ = ::CORBA_PollableSet::_nil ();
  return val;
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::duplicate (CORBA_PollableSet_ptr p)
{
  return ::CORBA_PollableSet::_duplicate (p);
}

void
CORBA_PollableSet_var::release (CORBA_PollableSet_ptr p)
{
  CORBA::release (p);
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::nil (void)
{
  return ::CORBA_PollableSet::_nil ();
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_var::narrow (
    CORBA::Object *p,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ::CORBA_PollableSet::_narrow (p, ACE_TRY_ENV);
}

CORBA::Object *
CORBA_PollableSet_var::upcast (void *src)
{
  CORBA_PollableSet **tmp =
    ACE_static_cast (CORBA_PollableSet **, src);
  return *tmp;
}
// *************************************************************
// Inline operations for class CORBA_PollableSet_out
// *************************************************************

CORBA_PollableSet_out::CORBA_PollableSet_out (CORBA_PollableSet_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::CORBA_PollableSet::_nil ();
}

CORBA_PollableSet_out::CORBA_PollableSet_out (CORBA_PollableSet_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_PollableSet::_nil ();
}

CORBA_PollableSet_out::CORBA_PollableSet_out (const ::CORBA_PollableSet_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_PollableSet_out &, p).ptr_)
{}

::CORBA_PollableSet_out &
CORBA_PollableSet_out::operator= (const ::CORBA_PollableSet_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_PollableSet_out&, p).ptr_;
  return *this;
}

CORBA_PollableSet_out &
CORBA_PollableSet_out::operator= (const ::CORBA_PollableSet_var &p)
{
  this->ptr_ = ::CORBA_PollableSet::_duplicate (p.ptr ());
  return *this;
}

CORBA_PollableSet_out &
CORBA_PollableSet_out::operator= (CORBA_PollableSet_ptr p)
{
  this->ptr_ = p;
  return *this;
}

CORBA_PollableSet_out::operator ::CORBA_PollableSet_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr &
CORBA_PollableSet_out::ptr (void) // ptr
{
  return this->ptr_;
}

::CORBA_PollableSet_ptr
CORBA_PollableSet_out::operator-> (void)
{
  return this->ptr_;
}


// default constructor
CORBA_PollableSet::CORBA_PollableSet ()
{
  }

// destructor
CORBA_PollableSet::~CORBA_PollableSet (void)
{}

CORBA_PollableSet_ptr CORBA_PollableSet::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return CORBA_PollableSet::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_PollableSet_ptr CORBA_PollableSet::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PollableSet::_nil ();
  return
      ACE_reinterpret_cast
        (
          CORBA_PollableSet_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_PollableSet::_narrow
                  )
              )
        );
}

CORBA_PollableSet_ptr
CORBA_PollableSet::_duplicate (CORBA_PollableSet_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *CORBA_PollableSet::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_PollableSet::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_PollableSet::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA_PollableSet:1.0";
}

// Default constructor.
CORBA_PollableSet::NoPossiblePollable::NoPossiblePollable (void)
  : CORBA_UserException ("IDL:omg.org/CORBA_PollableSet/NoPossiblePollable:1.0")
{
}

// Destructor - all members are of self managing types.
CORBA_PollableSet::NoPossiblePollable::~NoPossiblePollable (void)
{
}

// Copy constructor.
CORBA_PollableSet::NoPossiblePollable::NoPossiblePollable (const ::CORBA_PollableSet::NoPossiblePollable &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// Assignment operator.
CORBA_PollableSet::NoPossiblePollable&
CORBA_PollableSet::NoPossiblePollable::operator= (const ::CORBA_PollableSet::NoPossiblePollable &_tao_excp)
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// Narrow.
CORBA_PollableSet::NoPossiblePollable *
CORBA_PollableSet::NoPossiblePollable::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA_PollableSet/NoPossiblePollable:1.0", exc->_id ()))
    {
      return ACE_dynamic_cast (NoPossiblePollable *, exc);
    }
  else
    {
      return 0;
    }
}

void CORBA_PollableSet::NoPossiblePollable::_raise ()
{
  TAO_RAISE (*this);
}

void CORBA_PollableSet::NoPossiblePollable::_tao_encode (
    TAO_OutputCDR &,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_PollableSet::NoPossiblePollable::_tao_decode (
    TAO_InputCDR &,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_PollableSet::NoPossiblePollable::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA_PollableSet::NoPossiblePollable, 0);
  return retval;
}

// Default constructor.
CORBA_PollableSet::UnknownPollable::UnknownPollable (void)
  : CORBA_UserException ("IDL:omg.org/CORBA_PollableSet/UnknownPollable:1.0")
{
}

// Destructor - all members are of self managing types.
CORBA_PollableSet::UnknownPollable::~UnknownPollable (void)
{
}

// Copy constructor.
CORBA_PollableSet::UnknownPollable::UnknownPollable (const ::CORBA_PollableSet::UnknownPollable &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// Assignment operator.
CORBA_PollableSet::UnknownPollable&
CORBA_PollableSet::UnknownPollable::operator= (const ::CORBA_PollableSet::UnknownPollable &_tao_excp)
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// Narrow.
CORBA_PollableSet::UnknownPollable *
CORBA_PollableSet::UnknownPollable::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA_PollableSet/UnknownPollable:1.0", exc->_id ()))
    {
      return ACE_dynamic_cast (UnknownPollable *, exc);
    }
  else
    {
      return 0;
    }
}

void CORBA_PollableSet::UnknownPollable::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_PollableSet::UnknownPollable::_tao_encode (
    TAO_OutputCDR &,
    CORBA::Environment &ACE_TRY_ENV) const
{
  ACE_THROW (CORBA::MARSHAL ());
}


void CORBA_PollableSet::UnknownPollable::_tao_decode (
    TAO_InputCDR &,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method.
CORBA::Exception *CORBA_PollableSet::UnknownPollable::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA_PollableSet::UnknownPollable, 0);
  return retval;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<CORBA_Pollable,CORBA_Pollable_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<CORBA_Pollable,CORBA_Pollable_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<CORBA_DIIPollable,CORBA_DIIPollable_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<CORBA_DIIPollable,CORBA_DIIPollable_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<CORBA_PollableSet,CORBA_PollableSet_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<CORBA_PollableSet,CORBA_PollableSet_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_AMI_POLLER == 1 */
