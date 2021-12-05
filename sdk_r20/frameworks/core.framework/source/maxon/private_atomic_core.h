#ifndef ATOMICTYPES_H__
	#error "You must include atomictypes.h"
#endif

#ifndef PRIVATE_ATOMIC_CORE_H__
#define PRIVATE_ATOMIC_CORE_H__

#include "maxon/apibase.h"																				// basic type definitions

#ifdef MAXON_TARGET_WINDOWS
	#pragma push_macro("id")
	#undef id
	#include <intrin.h>

	#if !defined MAXON_COMPILER_INTEL && !defined MAXON_COMPILER_CLANG
		#pragma intrinsic(_InterlockedCompareExchange)
		#pragma intrinsic(_InterlockedExchangeAdd)
		#pragma intrinsic(_InterlockedOr)
		#pragma intrinsic(_InterlockedAnd)
		#pragma intrinsic(_InterlockedExchange)
		#pragma intrinsic(_ReadWriteBarrier)

		#ifdef MAXON_TARGET_64BIT
			#pragma intrinsic(_InterlockedCompareExchange64)
			#pragma intrinsic(_InterlockedExchangeAdd64)
			#pragma intrinsic(_InterlockedExchange64)
			#pragma intrinsic(_InterlockedCompareExchange128)
		#endif
	#endif
	#pragma pop_macro("id")
#elif defined(MAXON_TARGET_ANDROID) || defined(MAXON_TARGET_CPU_ARM)
	#include <atomic>
	static_assert(sizeof(std::atomic<maxon::Int32>) == 4, "wrong std::atomic 32 bit size");
	static_assert(sizeof(std::atomic<maxon::Int64>) == 8, "wrong std::atomic 64 bit size");
#endif

// Compiler fence: This makes sure that compiler optimizations won't move loads and stores from a point before the
// barrier to a point behind it (and vice versa). This barrier does not generate any code nor does guarantee a
// certain load and store order or synchronization (use the memory barriers for that).
#if defined MAXON_TARGET_WINDOWS && !defined MAXON_COMPILER_CLANG
	#define	CompilerOptimizationBarrier()				_ReadWriteBarrier()
#else
	#define	CompilerOptimizationBarrier()				asm volatile ("" : : : "memory")
#endif

// stylecheck.naming=false

namespace maxon
{


//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparison value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchg								New value.
/// @param[in] cmp								Comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas32(Int32 volatile* dst, Int32 xchg, Int32 cmp)
{
#ifdef MAXON_TARGET_WINDOWS
	Int32 prev = (Int32) _InterlockedCompareExchange((long volatile*) dst, (long) xchg, (long) cmp);

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_PPC)
	Int32 prev;
	Int32	tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lwarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"addi		%1,r1,-8\n\t"												// address in red zone
								"cmpw		%0,%4\n\t"													// matches comparison value?
								"beq+		2f\n\t"

								"stwcx. %3,0,%1\n\t"												// on 970 must release reservation, store into red zone to release
								"b			3f\n\t"

								"2:"
								"stwcx. %3,0,%2\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								"3:"
								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (xchg), "r" (cmp)					// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int32 prev;

	asm volatile ("lock; cmpxchgl %2,%1"
								: "=a" (prev), "=m" (*dst)									// output: from eax
								: "r" (xchg), "0" (cmp)											// inputs: cmp takes the same register as output (eax)
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#else
	std::atomic<Int32>& rdst = *(std::atomic<Int32>*)dst;

	return rdst.compare_exchange_strong(cmp, xchg, std::memory_order_seq_cst, std::memory_order_relaxed);
#endif
}

inline Bool atomic_try_cas32HLE(Int32 volatile* dst, Int32 xchg, Int32 cmp)
{
#if defined(MAXON_TARGET_CPU_INTEL) && defined(MAXON_ASSEMBLY_GCC)
	Int32	prev;

	__asm__ volatile (".byte 0xf2\t\n"
										"lock	cmpxchgl %2,%1"
										: "=a" (prev), "=m" (*dst)							// output: from eax
										: "r" (xchg), "0" (cmp)									// inputs: cmp takes the same register as output (eax)
										: "memory", "cc");											// memory and condition code register are modified

	return prev == cmp;																				// previous memory content
#else
	return atomic_try_cas32(dst, xchg, cmp);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Add: Add value to memory location content and return the previous value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							Value to add.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Char	atomic_swap_add8(Char volatile* dst, Char value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Char) _InterlockedExchangeAdd8((char volatile*) dst, (char) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Char	prev, tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required
								"0:\n\t"
								"lbarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"add		%1,%0,%3\n\t"												// tmp = prev + value
								"stbcx.	%1,0,%2\n\t"												// store new value (tmp) if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (value)										// input
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	asm volatile ("lock; xaddb %0,%1"
								: "=r" (value), "=m" (*dst)									// output: dst is modified
								: "0" (value)																// input: value takes the same register as on output
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#else
	std::atomic<Char>& rdst = *(std::atomic<Char>*)dst;

	return rdst.fetch_add(value, std::memory_order_seq_cst);
#endif
}


//----------------------------------------------------------------------------------------
/// Atomic Add: Add value to memory location content and return the previous value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							Value to add.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int16	atomic_swap_add16(Int16 volatile* dst, Int16 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int16) _InterlockedExchangeAdd16((short volatile*) dst, (short) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int16	prev, tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required
								"0:\n\t"
								"lharx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"add		%1,%0,%3\n\t"												// tmp = prev + value
								"sthcx.	%1,0,%2\n\t"												// store new value (tmp) if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (value)										// input
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	asm volatile ("lock; xaddw %0,%1"
								: "=r" (value), "=m" (*dst)									// output: dst is modified
								: "0" (value)																// input: value takes the same register as on output
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#else
	std::atomic<Int16>& rdst = *(std::atomic<Int16>*)dst;

	return rdst.fetch_add(value, std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Add: Add value to memory location content and return the previous value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							Value to add.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int32	atomic_swap_add32(Int32 volatile* dst, Int32 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int32) _InterlockedExchangeAdd((long volatile*) dst, (long) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int32	prev, tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required
								"0:\n\t"
								"lwarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"add		%1,%0,%3\n\t"												// tmp = prev + value
								"stwcx.	%1,0,%2\n\t"												// store new value (tmp) if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (value)										// input
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	asm volatile ("lock; xaddl %0,%1"
								: "=r" (value), "=m" (*dst)									// output: dst is modified
								: "0" (value)																// input: value takes the same register as on output
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#else
	std::atomic<Int32>& rdst = *(std::atomic<Int32>*)dst;

	return rdst.fetch_add(value, std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Swap: Store a value and return the memory location's previous value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							New value.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Char atomic_swap8(Char volatile* dst, Char value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Char) _InterlockedExchange8((char volatile*) dst, (char) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Char	prev;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lbarx	%0,0,%1\n\t"												// load memory location content, reserve for write
								"stbcx. %2,0,%1\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev)															// output
								: "b" (dst), "r" (value)										// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Char	prev;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgb %0,%1"
								: "=r" (prev), "=m" (*dst)
								: "m" (*dst), "0" (value)
								: "memory");

	return prev;
#else
	std::atomic<Char>& rdst = *(std::atomic<Char>*)dst;

	return rdst.exchange(value);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Swap: Store a value and return the memory location's previous value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							New value.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int16 atomic_swap16(Int16 volatile* dst, Int16 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int16) _InterlockedExchange16((short volatile*) dst, (short) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int16	prev;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lharx	%0,0,%1\n\t"												// load memory location content, reserve for write
								"sthcx. %2,0,%1\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev)															// output
								: "b" (dst), "r" (value)										// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int16	prev;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgw %0,%1"
								: "=r" (prev), "=m" (*dst)
								: "m" (*dst), "0" (value)
								: "memory");

	return prev;
#else
	std::atomic<Int16>& rdst = *(std::atomic<Int16>*)dst;

	return rdst.exchange(value);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Swap: Store a value and return the memory location's previous value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							New value.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int32 atomic_swap32(Int32 volatile* dst, Int32 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int32) _InterlockedExchange((long volatile*) dst, (long) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int32	prev;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lwarx	%0,0,%1\n\t"												// load memory location content, reserve for write
								"stwcx. %2,0,%1\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev)															// output
								: "b" (dst), "r" (value)										// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int32	prev;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgl %0,%1"
								: "=r" (prev), "=m" (*dst)
								: "m" (*dst), "0" (value)
								: "memory");

	return prev;
#else
	std::atomic<Int32>& rdst = *(std::atomic<Int32>*)dst;

	return rdst.exchange(value);
#endif
}

#ifndef MAXON_TARGET_64BIT
//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparision value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchghi							Upper 32 bit of the new value.
/// @param[in] xchglo							Lower 32 bit of the new value.
/// @param[in] cmphi							Upper 32 bit of the comparison value.
/// @param[in] cmplo							Lower 32 bit of the comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas64(Int64 volatile* dst, Int32 xchghi, Int32 xchglo, Int32 cmphi, Int32 cmplo)
{
#ifdef MAXON_TARGET_WINDOWS
	const Int32	xchg[2] = { xchglo, xchghi };
	const Int32	cmp[2] = { cmplo, cmphi };

	return _InterlockedCompareExchange64(dst, *(Int64*) &xchg, *(Int64*) &cmp) == *(Int64*) &cmp;
#elif defined(MAXON_TARGET_CPU_INTEL)
	char	success;
	Int32	tmp[2] = { xchglo, cmplo };

	asm volatile ("push %%ebx							\n\t"

								"mov	0(%%eax),	%%ebx		\n\t"								// xchglo
								"mov	4(%%eax),	%%eax		\n\t"								// cmplo

								"lock cmpxchg8b	(%%esi)	\n\t"
								"sete	%0								\n\t"

								"pop	%%ebx							\n\t"
								: "=a" (success), "=d" (cmphi), "=m" (*dst)	// edx will be modified but GAS is too dumb to realize that an input register can be modified (clobbered), therefore I made it an output too
								: "a" (tmp), "c" (xchghi), "d" (cmphi), "S" (dst)	// input registers
								: "memory", "cc");													// memory and condition code register are modified

	return success;
#else
	DebugStop();
	return false;
#endif
}

#endif

#ifdef MAXON_TARGET_64BIT
//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparision value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchg								New value.
/// @param[in] cmp								Comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas64(Int64 volatile* dst, Int64 xchg, Int64 cmp)
{
#ifdef MAXON_TARGET_WINDOWS
	Int64 prev = (Int64) _InterlockedCompareExchange64(dst, xchg, cmp);

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_PPC)
	Int64	prev;
	Int64	tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"ldarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"addi		%1,r1,-8\n\t"												// address in red zone
								"cmpd		%0,%4\n\t"													// matches comparison value?
								"beq+		2f\n\t"

								"stdcx. %3,0,%1\n\t"												// on 970 must release reservation, store into red zone to release
								"b			3f\n\t"

								"2:"
								"stdcx. %3,0,%2\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								"3:"
								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (xchg), "r" (cmp)					// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int64	prev;

	asm volatile ("lock; cmpxchgq %2,%1"
								: "=a" (prev), "=m" (*dst)
								: "q" (xchg), "0" (cmp)
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#else
	std::atomic<Int64>& rdst = *(std::atomic<Int64>*)dst;

	return rdst.compare_exchange_strong(cmp, xchg, std::memory_order_seq_cst, std::memory_order_relaxed);
#endif
}

inline Bool atomic_try_cas64HLE(Int64 volatile* dst, Int64 xchg, Int64 cmp)
{
#if defined(MAXON_TARGET_CPU_INTEL) && defined(MAXON_ASSEMBLY_GCC)
	Int32	prev;

	__asm__ volatile (".byte 0xf2\t\n"
										"lock	cmpxchgq %2,%1"
										: "=a" (prev), "=m" (*dst)							// output: from eax
										: "r" (xchg), "0" (cmp)									// inputs: cmp takes the same register as output (eax)
										: "memory", "cc");											// memory and condition code register are modified

	return prev == cmp;																				// previous memory content
#else
	return atomic_try_cas64(dst, xchg, cmp);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparision value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchghi							Upper 64 bit of the new value.
/// @param[in] xchglo							Lower 64 bit of the new value.
/// @param[in] cmphi							Upper 64 bit of the comparison value.
/// @param[in] cmplo							Lower 64 bit of the comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas128(Int64 volatile* dst, Int64 xchghi, Int64 xchglo, Int64 cmphi, Int64 cmplo)
{
#ifdef MAXON_TARGET_WINDOWS
	Int64	cmp[2] = { cmplo, cmphi };												// this will be overwritten with the content of dst
#ifdef MAXON_COMPILER_INTEL																// the intel compiler uses a void pointer for the destination
	return _InterlockedCompareExchange128((volatile __int64*) dst, xchghi, xchglo, cmp) != 0;
#else
	return _InterlockedCompareExchange128(dst, xchghi, xchglo, cmp) != 0;
#endif
#elif defined(MAXON_TARGET_CPU_INTEL)
	char success;

	asm volatile ("lock cmpxchg16b %2\n\t"
								"sete	%0"

								: "=a" (success), "=d" (cmphi), "=m" (*dst)	// rdx will be modified but GAS is too dumb to realize that an input register can be modified (clobbered), therefore I made it an output too
								: "a" (cmplo), "b" (xchglo), "c" (xchghi), "d" (cmphi)	// input registers
								: "memory", "cc");													// memory and condition code register are modified

	return success;
#else
	DebugStop();
	return false;
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Add: Add value to memory location content and return the previous value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							Value to add.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int64	atomic_swap_add64(Int64 volatile* dst, Int64 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int64)	_InterlockedExchangeAdd64(dst, value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int64	prev;
	Int64	tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required
								"0:\n\t"
								"ldarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"add		%1,%0,%3\n\t"												// tmp = prev + value
								"stdcx.	%1,0,%2\n\t"												// store new value (tmp) if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (value)										// input
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int64	prev;

	asm volatile ("lock; xaddq %0,%1"
								: "=r" (prev), "=m" (*dst)									// output: dst is modified
								: "m" (*dst), "0" (value)										// input: value takes the same register as on output
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#else
	std::atomic<Int64>& rdst = *(std::atomic<Int64>*)dst;

	return rdst.fetch_add(value, std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Swap: Store a value and return the memory location's previous value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] value							New value.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int64 atomic_swap64(Int64 volatile* dst, Int64 value)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int64) _InterlockedExchange64(dst, value);
#elif defined(MAXON_TARGET_CPU_PPC)
	Int64	prev;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"ldarx	%0,0,%1\n\t"												// load memory location content, reserve for write
								"stdcx. %2,0,%1\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								: "=&r" (prev)															// output
								: "b" (dst), "r" (value)										// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int64	prev;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgq %0,%1"
								: "=r" (prev), "=m" (*dst)
								: "m" (*dst), "0" (value)
								: "memory");

	return prev;
#else
	std::atomic<Int64>& rdst = *(std::atomic<Int64>*)dst;

	return rdst.exchange(value);
#endif
}

#endif

//----------------------------------------------------------------------------------------
/// Atomic Or: Or value to memory location content and return the previous value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] mask								Mask for bitwise or.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int32	atomic_swap_or32(Int32 volatile* dst, Int32 mask)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int32) _InterlockedOr((long volatile*) dst, (long) mask);
#else
	Int32	old_value;
	Int32	new_value;

	do
	{
		old_value = *dst;
		new_value = old_value | mask;
	} while (atomic_try_cas32(dst, new_value, old_value) == false);

	return old_value;
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic And: And value to memory location content and return the previous value
/// This function implicitely creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] mask								Mask for bitwise and.
/// @return												Previous memory location content.
//----------------------------------------------------------------------------------------
inline Int32	atomic_swap_and32(Int32 volatile* dst, Int32 mask)
{
#ifdef MAXON_TARGET_WINDOWS
	return (Int32) _InterlockedAnd((long volatile*) dst, (long) mask);
#else
	Int32	old_value;
	Int32	new_value;

	do
	{
		old_value = *dst;
		new_value = old_value & mask;
	} while (atomic_try_cas32(dst, new_value, old_value) == false);

	return old_value;
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparison value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchg								New value.
/// @param[in] cmp								Comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas8(Char volatile* dst, Char xchg, Char cmp)
{
#ifdef MAXON_TARGET_WINDOWS
	Char prev = (Char) _InterlockedCompareExchange8((char volatile*) dst, (char) xchg, (char) cmp);

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_PPC)
	Char prev;
	Char	tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lbarx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"addi		%1,r1,-8\n\t"												// address in red zone
								"cmpw		%0,%4\n\t"													// matches comparison value?
								"beq+		2f\n\t"

								"stbcx. %3,0,%1\n\t"												// on 970 must release reservation, store into red zone to release
								"b			3f\n\t"

								"2:"
								"stbcx. %3,0,%2\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								"3:"
								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (xchg), "r" (cmp)					// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Char prev;

	asm volatile ("lock; cmpxchgb %2,%1"
								: "=a" (prev), "=m" (*dst)									// output: from eax
								: "r" (xchg), "0" (cmp)											// inputs: cmp takes the same register as output (eax)
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#else
	std::atomic<Char>& rdst = *(std::atomic<Char>*)dst;

	return rdst.compare_exchange_strong(cmp, xchg, std::memory_order_seq_cst, std::memory_order_relaxed);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic Compare And Swap: Exchange memory location content with new value if its equal to comparison value
/// This function implicitly creates a memory barrier.
/// @param[in,out] dst						Memory location.
/// @param[in] xchg								New value.
/// @param[in] cmp								Comparison value.
/// @return												True if successul, false if memory location wasn't changed.
//----------------------------------------------------------------------------------------
inline Bool atomic_try_cas16(Int16 volatile* dst, Int16 xchg, Int16 cmp)
{
#ifdef MAXON_TARGET_WINDOWS
	Int16 prev = (Int16) _InterlockedCompareExchange16((short volatile*) dst, (short) xchg, (short) cmp);

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_PPC)
	Int16 prev;
	Int16	tmp;

	asm volatile ("sync\n\t"																	// lwsync is OK for acquire release, but for sequential consistency hwsync is required

								"0:\n\t"
								"lharx	%0,0,%2\n\t"												// load memory location content, reserve for write
								"addi		%1,r1,-8\n\t"												// address in red zone
								"cmpw		%0,%4\n\t"													// matches comparison value?
								"beq+		2f\n\t"

								"sthcx. %3,0,%1\n\t"												// on 970 must release reservation, store into red zone to release
								"b			3f\n\t"

								"2:"
								"sthcx. %3,0,%2\n\t"												// store swap value if the reservation is still valid
								"bne-		0b\n\t"															// retry if the memory location has been modified in between
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded

								"3:"
								: "=&r" (prev), "=&r" (tmp)									// output
								: "b" (dst), "r" (xchg), "r" (cmp)					// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int16 prev;

	asm volatile ("lock; cmpxchgw %2,%1"
								: "=a" (prev), "=m" (*dst)									// output: from eax
								: "r" (xchg), "0" (cmp)											// inputs: cmp takes the same register as output (eax)
								: "memory", "cc");													// memory and condition code register are modified

	return prev == cmp;
#else
	std::atomic<Int16>& rdst = *(std::atomic<Int16>*)dst;

	return rdst.compare_exchange_strong(cmp, xchg, std::memory_order_seq_cst, std::memory_order_relaxed);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with consume memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with consume memory order that reads the value stored direct dependencies are
/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
/// elements of the structure that have been written before the release).
/// This means that unrelated loads following this method might be reordered by the compiler
/// or the CPU and can be executed before it.
/// For most cpu architectures this the same instruction as an ordinary load which implies
/// no performance penalty compared to a load with relaxed memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Char atomic_consume_load8(Char volatile* src)
{
#if defined(MAXON_TARGET_CPU_INTEL) || defined(MAXON_TARGET_CPU_PPC)
	return *src;
#else
	std::atomic<Char>& rsrc = *(std::atomic<Char>*)src;
	return rsrc.load(std::memory_order_consume);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with consume memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with consume memory order that reads the value stored direct dependencies are
/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
/// elements of the structure that have been written before the release).
/// This means that unrelated loads following this method might be reordered by the compiler
/// or the CPU and can be executed before it.
/// For most cpu architectures this the same instruction as an ordinary load which implies
/// no performance penalty compared to a load with relaxed memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int16 atomic_consume_load16(Int16 volatile* src)
{
#if defined(MAXON_TARGET_CPU_INTEL) || defined(MAXON_TARGET_CPU_PPC)
	return *src;
#else
	std::atomic<Int16>& rsrc = *(std::atomic<Int16>*)src;
	return rsrc.load(std::memory_order_consume);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with consume memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with consume memory order that reads the value stored direct dependencies are
/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
/// elements of the structure that have been written before the release).
/// This means that unrelated loads following this method might be reordered by the compiler
/// or the CPU and can be executed before it.
/// For most cpu architectures this the same instruction as an ordinary load which implies
/// no performance penalty compared to a load with relaxed memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int32 atomic_consume_load32(Int32 volatile* src)
{
#if defined(MAXON_TARGET_CPU_INTEL) || defined(MAXON_TARGET_CPU_PPC)
	return *src;
#else
	std::atomic<Int32>& rsrc = *(std::atomic<Int32>*)src;
	return rsrc.load(std::memory_order_consume);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with consume memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with consume memory order that reads the value stored direct dependencies are
/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
/// elements of the structure that have been written before the release).
/// This means that unrelated loads following this method might be reordered by the compiler
/// or the CPU and can be executed before it.
/// For most cpu architectures this the same instruction as an ordinary load which implies
/// no performance penalty compared to a load with relaxed memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int64 atomic_consume_load64(Int64 volatile* src)
{
#if defined(MAXON_TARGET_CPU_INTEL) || defined(MAXON_TARGET_CPU_PPC)
	return *src;
#else
	std::atomic<Int64>& rsrc = *(std::atomic<Int64>*)src;
	return rsrc.load(std::memory_order_consume);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with acquire memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with acquire memory order all following loads will see the (relaxed) stores that
/// preceeding the release. Furthermore subsequent loads or stores will not be speculatively
/// executed before this load.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Char atomic_acquire_load8(Char volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	Char value = *src;

	// discard prefetched loads of following instructions (could use lwsync as well)
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Char value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Char>& rsrc = *(std::atomic<Char>*)src;
	return rsrc.load(std::memory_order_acquire);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with acquire memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with acquire memory order all following loads will see the (relaxed) stores that
/// preceeding the release. Furthermore subsequent loads or stores will not be speculatively
/// executed before this load.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int16 atomic_acquire_load16(Int16 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	Int16 value = *src;

	// discard prefetched loads of following instructions (could use lwsync as well)
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int16 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int16>& rsrc = *(std::atomic<Int16>*)src;
	return rsrc.load(std::memory_order_acquire);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with acquire memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with acquire memory order all following loads will see the (relaxed) stores that
/// preceeding the release. Furthermore subsequent loads or stores will not be speculatively
/// executed before this load.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int32 atomic_acquire_load32(Int32 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	Int32 value = *src;

	// discard prefetched loads of following instructions (could use lwsync as well)
	asm volatile ("cmpw		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int32 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int32>& rsrc = *(std::atomic<Int32>*)src;
	return rsrc.load(std::memory_order_acquire);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with acquire memory order.
/// If another thread has released a store on this location it is guaranteed that after a
/// load with acquire memory order all following loads will see the (relaxed) stores that
/// preceeding the release. Furthermore subsequent loads or stores will not be speculatively
/// executed before this load.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int64 atomic_acquire_load64(Int64 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	Int64 value = *src;

	// discard prefetched loads of following instructions (could use lwsync as well)
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int64 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int64>& rsrc = *(std::atomic<Int64>*)src;
	return rsrc.load(std::memory_order_acquire);
#endif
}


//----------------------------------------------------------------------------------------
/// Atomic load with sequentially consistent memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Char atomic_sequential_load8(Char volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	MemoryFenceSequential();																	// hwsync before reading
	Char value = *src;

	// discard prefetched loads of following instructions
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	Char value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Char>& rsrc = *(std::atomic<Char>*)src;
	return rsrc.load(std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with sequentially consistent memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int16 atomic_sequential_load16(Int16 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	MemoryFenceSequential();																	// hwsync before reading
	Int16 value = *src;

	// discard prefetched loads of following instructions
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	Int16 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int16>& rsrc = *(std::atomic<Int16>*)src;
	return rsrc.load(std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with sequentially consistent memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int32 atomic_sequential_load32(Int32 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	MemoryFenceSequential();																	// hwsync before reading
	Int32 value = *src;

	// discard prefetched loads of following instructions
	asm volatile ("cmpw		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	Int32 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int32>& rsrc = *(std::atomic<Int32>*)src;
	return rsrc.load(std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic load with sequentially consistent memory order.
/// @param[in] src								Memory location.
/// @return												Read memory location content.
//----------------------------------------------------------------------------------------
inline Int64 atomic_sequential_load64(Int64 volatile* src)
{
#if defined(MAXON_TARGET_CPU_PPC)
	MemoryFenceSequential();																	// hwsync before reading
	Int64 value = *src;

	// discard prefetched loads of following instructions
	asm volatile ("cmpd		%0,r0\n\t"													// dummy compare
								"beq-		1f\n\t"															// dummy branch
								"1:"
								"isync\n\t"																	// read barrier, make sure that prefetches of following instructions are discarded
								:																						// no outputs
								: "r" (value)																// inputs
								: "memory", "cc");													// memory and condition code register are modified

	return value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	Int64 value = *src;

	CompilerOptimizationBarrier();														// make sure the compiler does not move the load after following instructions

	return value;
#else
	std::atomic<Int64>& rsrc = *(std::atomic<Int64>*)src;
	return rsrc.load(std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with release memory order.
/// As soon as another thread reads on this location and obtains the stored value it is
/// guaranteed that all prior (relaxed) stores are visible to it.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_release_store8(Char volatile* dst, Char value)
{
#if defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("lwsync" : : : "memory");										// complete pending stores before storing this value
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure that the compiler doesn't move the following store to a point before the barrier
	*dst = value;
#else
	std::atomic<Char>& rdst = *(std::atomic<Char>*)dst;
	rdst.store(value, std::memory_order_release);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with release memory order.
/// As soon as another thread reads on this location and obtains the stored value it is
/// guaranteed that all prior (relaxed) stores are visible to it.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_release_store16(Int16 volatile* dst, Int16 value)
{
#if defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("lwsync" : : : "memory");										// complete pending stores before storing this value
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure that the compiler doesn't move the following store to a point before the barrier
	*dst = value;
#else
	std::atomic<Int16>& rdst = *(std::atomic<Int16>*)dst;
	rdst.store(value, std::memory_order_release);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with release memory order.
/// As soon as another thread reads on this location and obtains the stored value it is
/// guaranteed that all prior (relaxed) stores are visible to it.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_release_store32(Int32 volatile* dst, Int32 value)
{
#if defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("lwsync" : : : "memory");										// complete pending stores before storing this value
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure that the compiler doesn't move the following store to a point before the barrier
	*dst = value;
#else
	std::atomic<Int32>& rdst = *(std::atomic<Int32>*)dst;
	rdst.store(value, std::memory_order_release);
#endif
}

inline void atomic_release_store32HLE(Int32 volatile* dst, Int32 value)
{
#if defined(MAXON_TARGET_CPU_INTEL) && defined(MAXON_ASSEMBLY_GCC)
	__asm__ volatile (".byte 0xf3\t\n"
										"movl %1, %0"
										: "=m" (*dst)
										: "r" (value)
										: "memory", "cc");
#else
	return atomic_release_store32(dst, value);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with release memory order.
/// As soon as another thread reads on this location and obtains the stored value it is
/// guaranteed that all prior (relaxed) stores are visible to it.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_release_store64(Int64 volatile* dst, Int64 value)
{
#if defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("lwsync" : : : "memory");										// complete pending stores before storing this value
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	CompilerOptimizationBarrier();														// make sure that the compiler doesn't move the following store to a point before the barrier
	*dst = value;
#else
	std::atomic<Int64>& rdst = *(std::atomic<Int64>*)dst;
	rdst.store(value, std::memory_order_release);
#endif
}

inline void atomic_release_store64HLE(Int64 volatile* dst, Int64 value)
{
#if defined(MAXON_TARGET_CPU_INTEL) && defined(MAXON_TARGET_64BIT) && defined(MAXON_ASSEMBLY_GCC)
	__asm__ volatile (".byte 0xf3\t\n"
										"movq %1, %0"
										: "=m" (*dst)
										: "r" (value)
										: "memory", "cc");
#else
	return atomic_release_store64(dst, value);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with sequentially consistent memory order.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_sequential_store8(Char volatile* dst, Char value)
{
#ifdef MAXON_TARGET_WINDOWS
	_InterlockedExchange8(dst, value);
#elif defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("sync" : : : "memory");
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Char	dummy;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgb %0,%1"
								: "=r" (dummy), "=m" (*dst)
								: "0" (value)
								: "memory");

	(void) dummy;
#else
	std::atomic<Char>& rdst = *(std::atomic<Char>*)dst;
	rdst.store(value, std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with sequentially consistent memory order.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_sequential_store16(Int16 volatile* dst, Int16 value)
{
#ifdef MAXON_TARGET_WINDOWS
	_InterlockedExchange16(dst, value);
#elif defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("sync" : : : "memory");
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int16	dummy;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgw %0,%1"
								: "=r" (dummy), "=m" (*dst)
								: "0" (value)
								: "memory");

	(void) dummy;
#else
	std::atomic<Int16>& rdst = *(std::atomic<Int16>*)dst;
	rdst.store(value, std::memory_order_seq_cst);
#endif
}

//----------------------------------------------------------------------------------------
/// Atomic store with sequentially consistent memory order.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_sequential_store32(Int32 volatile* dst, Int32 value)
{
#ifdef MAXON_TARGET_WINDOWS
	_InterlockedExchange((long volatile*) dst, (long) value);
#elif defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("sync" : : : "memory");
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int32	dummy;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgl %0,%1"
								: "=r" (dummy), "=m" (*dst)
								: "0" (value)
								: "memory");

	(void) dummy;
#else
	std::atomic<Int32>& rdst = *(std::atomic<Int32>*)dst;
	rdst.store(value, std::memory_order_seq_cst);
#endif
}

#ifdef MAXON_TARGET_64BIT
//----------------------------------------------------------------------------------------
/// Atomic store with sequentially consistent memory order.
/// @param[in] dst								Memory location.
/// @param[in] value							Value to be stored.
//----------------------------------------------------------------------------------------
inline void atomic_sequential_store64(Int64 volatile* dst, Int64 value)
{
#ifdef MAXON_TARGET_WINDOWS
	_InterlockedExchange64(dst, value);
#elif defined(MAXON_TARGET_CPU_PPC)
	asm volatile ("sync" : : : "memory");
	*dst = value;
#elif defined(MAXON_TARGET_CPU_INTEL)
	Int64	dummy;

	// lock prefix is implicit for xchg (but not cmpxchg)
	asm volatile ("xchgq %0,%1"
								: "=r" (dummy), "=m" (*dst)
								: "0" (value)
								: "memory");

	(void) dummy;
#else
	std::atomic<Int64>& rdst = *(std::atomic<Int64>*)dst;
	rdst.store(value, std::memory_order_seq_cst);
#endif
}
#endif

} // namespace maxon

#endif // PRIVATE_ATOMIC_CORE_H__
