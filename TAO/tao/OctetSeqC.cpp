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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "OctetSeqC.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "OctetSeqC.i"
#endif /* !defined INLINE */

#include "Any_T.h"
#include "ORB_Core.h"

#if !defined (_CORBA_OCTETSEQ_CS_)
#define _CORBA_OCTETSEQ_CS_

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:250

// *************************************************************
// CORBA::OctetSeq
// *************************************************************

CORBA::OctetSeq::OctetSeq (void)
{}

CORBA::OctetSeq::OctetSeq (CORBA::ULong max)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}

CORBA::OctetSeq::OctetSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet *buffer,
    CORBA::Boolean release
  )
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}

CORBA::OctetSeq::OctetSeq (const OctetSeq &seq)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}

CORBA::OctetSeq::~OctetSeq (void) // dtor
{}

void CORBA::OctetSeq::_tao_any_destructor (void *_tao_void_pointer)
{
  OctetSeq *tmp = ACE_static_cast (OctetSeq*, _tao_void_pointer);
  delete tmp;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_OctetSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f4f63), 
  ACE_NTOHL (0x74657453), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
    9,
  ACE_NTOHL (0x4f637465), 
  ACE_NTOHL (0x74536571), 
  ACE_NTOHL (0x0),  // name = OctetSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_OctetSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_OctetSeq),
    (char *) &_oc_CORBA_OctetSeq,
    0,
    sizeof (CORBA::OctetSeq)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_OctetSeq,
    &_tc_TAO_tc_CORBA_OctetSeq
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::OctetSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::insert_copy (
      _tao_any,
      CORBA::OctetSeq::_tao_any_destructor,
      CORBA::_tc_OctetSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::OctetSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::insert (
      _tao_any,
      CORBA::OctetSeq::_tao_any_destructor,
      CORBA::_tc_OctetSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::OctetSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::OctetSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::OctetSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::extract (
        _tao_any,
        CORBA::OctetSeq::_tao_any_destructor,
        CORBA::_tc_OctetSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::OctetSeq>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::OctetSeq>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:125

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::OctetSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
          ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (CORBA::OctetSeq *)&_tao_sequence);
        if (oseq->mb ())
          return strm.write_octet_array_mb (oseq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }
      
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::OctetSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      if (ACE_BIT_DISABLED (strm.start ()->flags (),
      ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();
        if (orb_core != 0 &&
        strm.orb_core ()->resource_factory ()->
        input_cdr_allocator_type_locked () == 1)
        {
          TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
            ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
          oseq->replace (_tao_seq_len, strm.start ());
          oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
          strm.skip_bytes (_tao_seq_len);
          return 1;
        }
      }
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return 0;
}

