// -*- C++ -*-

//=============================================================================
/**
 *  @file    Atomic_Op.h
 *
 *  $Id: Atomic_Op.h 85102 2009-04-17 14:04:36Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================

#ifndef ACE_ATOMIC_OP_H
#define ACE_ATOMIC_OP_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Thread_Mutex.h"

// Include the templates here.
#include "ace/Atomic_Op_T.h"

// Determine whether builtin atomic op support is
// available on this platform.
#if defined (ACE_HAS_THREADS)
# if defined (WIN32)
#  if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
#   define ACE_HAS_BUILTIN_ATOMIC_OP
#  endif /* ACE_HAS_INTRINSIC_INTERLOCKED */
#  if defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
#   define ACE_HAS_BUILTIN_ATOMIC_OP
#  else /* ACE_HAS_INTERLOCKED_EXCHANGEADD */
    // Inline assembly emulation of InterlockedExchangeAdd
    // is currently only implemented for MSVC (x86 only) and Borland.
#   if (defined (_MSC_VER) && defined (_M_IX86)) || defined (__BORLANDC__)
#    define ACE_HAS_BUILTIN_ATOMIC_OP
#   endif /* _MSC_VER || __BORLANDC__ */
#  endif /* ACE_HAS_INTERLOCKED_EXCHANGEADD */
# elif defined (ACE_HAS_INTEL_ASSEMBLY)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# elif defined (ACE_HAS_VXATOMICLIB)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# elif defined(sun)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# endif /* WIN32 */
#endif /* ACE_HAS_THREADS */

#if defined (ACE_HAS_BUILTIN_ATOMIC_OP)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Atomic_Op<ACE_Thread_Mutex, long>
 *
 * @brief Specialization of ACE_Atomic_Op for platforms that
 *        support atomic integer operations.
 *
 * Specialization of ACE_Atomic_Op for platforms that support atomic
 * integer operations.
 */
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, long>
{
public:
  /// Initialize <value_> to 0.
  ACE_Atomic_Op (void);

  /// Initialize <value_> to c.
  ACE_Atomic_Op (long c);

  /// Manage copying...
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &c);

  /// Atomically pre-increment <value_>.
  long operator++ (void);

  /// Atomically post-increment <value_>.
  long operator++ (int);

  /// Atomically increment <value_> by rhs.
  long operator+= (long rhs);

  /// Atomically pre-decrement <value_>.
  long operator-- (void);

  /// Atomically post-decrement <value_>.
  long operator-- (int);

  /// Atomically decrement <value_> by rhs.
  long operator-= (long rhs);

  /// Atomically compare <value_> with rhs.
  bool operator== (long rhs) const;

  /// Atomically compare <value_> with rhs.
  bool operator!= (long rhs) const;

  /// Atomically check if <value_> greater than or equal to rhs.
  bool operator>= (long rhs) const;

  /// Atomically check if <value_> greater than rhs.
  bool operator> (long rhs) const;

  /// Atomically check if <value_> less than or equal to rhs.
  bool operator<= (long rhs) const;

  /// Atomically check if <value_> less than rhs.
  bool operator< (long rhs) const;

  /// Atomically assign rhs to <value_>.
  ACE_Atomic_Op<ACE_Thread_Mutex, long> &operator= (long rhs);

  /// Atomically assign <rhs> to <value_>.
  ACE_Atomic_Op<ACE_Thread_Mutex, long> &operator= (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &rhs);

  /// Explicitly return <value_>.
  long value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Explicitly return <value_> (by reference).
  volatile long &value_i (void);

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /// Used during ACE object manager initialization to optimize the fast
  /// atomic op implementation according to the number of CPUs.
  static void init_functions (void);

private:

  // This function cannot be supported by this template specialization.
  // If you need access to an underlying lock, use the ACE_Atomic_Op_Ex
  // template instead.
  ACE_Thread_Mutex &mutex (void);

private:

  /// Current object decorated by the atomic op.
  volatile long value_;

  // Pointers to selected atomic op implementations.
  static long (*increment_fn_) (volatile long *);
  static long (*decrement_fn_) (volatile long *);
  static long (*exchange_fn_) (volatile long *, long);
  static long (*add_fn_) (volatile long *, long);
};

/**
 * @class ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>
 *
 * @brief Specialization of ACE_Atomic_Op for platforms that
 *        support atomic integer operations.
 *
 * Specialization of ACE_Atomic_Op for platforms that support atomic
 * integer operations.
 */
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>
{
public:
  /// Initialize <value_> to 0.
  ACE_Atomic_Op (void);

  /// Initialize <value_> to c.
  ACE_Atomic_Op (unsigned long c);

  /// Manage copying...
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &c);

  /// Atomically pre-increment <value_>.
  unsigned long operator++ (void);

  /// Atomically post-increment <value_>.
  unsigned long operator++ (int);

  /// Atomically increment <value_> by rhs.
  unsigned long operator+= (unsigned long rhs);

  /// Atomically pre-decrement <value_>.
  unsigned long operator-- (void);

  /// Atomically post-decrement <value_>.
  unsigned long operator-- (int);

  /// Atomically decrement <value_> by rhs.
  unsigned long operator-= (unsigned long rhs);

  /// Atomically compare <value_> with rhs.
  bool operator== (unsigned long rhs) const;

  /// Atomically compare <value_> with rhs.
  bool operator!= (unsigned long rhs) const;

  /// Atomically check if <value_> greater than or equal to rhs.
  bool operator>= (unsigned long rhs) const;

  /// Atomically check if <value_> greater than rhs.
  bool operator> (unsigned long rhs) const;

  /// Atomically check if <value_> less than or equal to rhs.
  bool operator<= (unsigned long rhs) const;

  /// Atomically check if <value_> less than rhs.
  bool operator< (unsigned long rhs) const;

  /// Atomically assign rhs to <value_>.
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &operator= (unsigned long rhs);

  /// Atomically assign <rhs> to <value_>.
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &operator= (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &rhs);

  /// Explicitly return <value_>.
  unsigned long value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Explicitly return <value_> (by reference).
  volatile unsigned long &value_i (void);

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /// Used during ACE object manager initialization to optimize the fast
  /// atomic op implementation according to the number of CPUs.
  static void init_functions (void);

private:

  // This function cannot be supported by this template specialization.
  // If you need access to an underlying lock, use the ACE_Atomic_Op_Ex
  // template instead.
  ACE_Thread_Mutex &mutex (void);

private:

  /// Current object decorated by the atomic op.
  volatile unsigned long value_;

  // Pointers to selected atomic op implementations.
  static long (*increment_fn_) (volatile long *);
  static long (*decrement_fn_) (volatile long *);
  static long (*exchange_fn_) (volatile long *, long);
  static long (*add_fn_) (volatile long *, long);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_BUILTIN_ATOMIC_OP */

// ATOMIC_* and *MemoryBarrier below are adapted from RE2 project namely from util/atomicops.h file
// The memory ordering constraints resemble the ones in C11.
// RELAXED - no memory ordering, just an atomic operation.
// CONSUME - data-dependent ordering.
// ACQUIRE - prevents memory accesses from hoisting above the operation.
// RELEASE - prevents memory accesses from sinking below the operation.
#if (__clang_major__ * 100 + __clang_minor__ >= 303) || \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ >= 40801)

#define ATOMIC_LOAD_RELAXED(x, p) do { (x) = __atomic_load_n((p), __ATOMIC_RELAXED); } while (0)
#define ATOMIC_LOAD_CONSUME(x, p) do { (x) = __atomic_load_n((p), __ATOMIC_CONSUME); } while (0)
#define ATOMIC_LOAD_ACQUIRE(x, p) do { (x) = __atomic_load_n((p), __ATOMIC_ACQUIRE); } while (0)
#define ATOMIC_STORE_RELAXED(p, v) __atomic_store_n((p), (v), __ATOMIC_RELAXED)
#define ATOMIC_STORE_RELEASE(p, v) __atomic_store_n((p), (v), __ATOMIC_RELEASE)

#elif defined(_MSC_VER)

#define ATOMIC_LOAD_RELAXED(x, p) do { (x) = *(p); } while (0)
#define ATOMIC_LOAD_CONSUME(x, p) do { (x) = *(p); } while (0)
#define ATOMIC_LOAD_ACQUIRE(x, p) do { (x) = *(p); _ReadBarrier(); } while (0)
#define ATOMIC_STORE_RELAXED(p, v) do { *(p) = (v); } while (0)
#define ATOMIC_STORE_RELEASE(p, v) do { *(p) = (v); _WriteBarrier(); } while (0)

#else // other compilers, old gcc/clang

#error Need atomic ops for this platform!

#endif // __clang_major__ * 100 ...

#if defined (__ACE_INLINE__)
#include "ace/Atomic_Op.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /*ACE_ATOMIC_OP_H*/
