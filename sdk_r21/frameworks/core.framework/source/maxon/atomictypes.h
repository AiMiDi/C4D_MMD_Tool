#ifndef ATOMICTYPES_H__
#define ATOMICTYPES_H__

#include "maxon/apibase.h"

#include "maxon/private_atomic_core.h"

namespace maxon
{

/// @addtogroup MEMORY Memory
/// @{


/// The term load means "read access to a memory location" and a store is a "write access to a memory location".
/// The terms acquire and release which are used to describe a type of barrier are derived from the way a mutex works: When it
/// is acquired (locked), it ensures that the current thread will see the stores of other threads (which have released the mutex).
/// And when a mutex is released (unlocked), it ensures that the stores of the current thread will be visible to other threads
/// (when they acquire the mutex).
///
/// MemoryFenceAcquire() prevents the reordering of any load which precedes it in program order
/// with any load or store which follows it in program order.
/// Which is another way of saying it works as LoadLoad and LoadStore barrier. It is equivalent
/// to a std::atomic_thread_fence(std::memory_order_acquire) even though the description in the C++11
/// standard is not that explicit.
///
/// The following example might illustrate which kind of reordering is allowed when MemoryFenceAcquire() is used:
/// @code
/// *pa = a; [1] store a in the location pa points to
/// b = *pb; [2] load b from the location pb
/// MemoryFenceAcquire();
/// *pc = c; [3] store c in the location pc points to
/// d = *pd; [4] load d from the location pd
/// @endcode
///
/// The store [1] can be reordered and executed after the fence (or happen before [2]).
/// The load [2] must be executed before the fence (but it could be reordered and happen before [1]).
/// The store [3] must be executed after the fence (but it could be reordered and happen after [4]).
/// The load [4] must be executed after the fence (but it could be reordered and happen before [3]).
///
/// A typical application is that once you have acquired a specific variable (a synchronization point)
/// and it has a certain trigger value you can be sure that all the variables you are loading after
/// the fence are valid and contain the values that have been stored before the corresponding release
/// fence to that synchronization point in another thread.
///
/// Furthermore a load operation with acquire semantics like value.LoadAcquire() is equivalent
/// to a relaxed value.LoadAcquire() followed by a MemoryFenceAcquire().
#if defined(MAXON_TARGET_CPU_INTEL)
	// On x86 it is sufficient if the compiler doesn't reorder the code.
	#define MemoryFenceAcquire()							CompilerOptimizationBarrier()
#elif defined(MAXON_TARGET_CPU_PPC)
	// PPC has weaker memory ordering than x86: lwsync doesn't order loads with respect to previous stores and is executed as sync on older ppcs.
	#define MemoryFenceAcquire()							asm volatile ("lwsync" : : : "memory")
#else
	// ARM (or whatever else) has weaker memory ordering than x86 and depending on the specific architecture might use dmb.
	#define MemoryFenceAcquire()							std::atomic_thread_fence(std::memory_order_acquire)
#endif


/// The term load means "read access to a memory location" and a store is a "write access to a memory location".
/// The terms acquire and release which are used to describe a type of barrier are derived from the way a mutex works: When it
/// is acquired (locked), it ensures that the current thread will see the stores of other threads (which have released the mutex).
/// And when a mutex is released (unlocked), it ensures that the stores of the current thread will be visible to other threads
/// (when they acquire the mutex).
///
/// MemoryFenceRelease() prevents the reordering of any load or store which precedes it in program order
/// with any store which follows it in program order.
/// This means it works as LoadStore and StoreStore barrier. It is equivalent to a C++11 fence of type
/// std::atomic_thread_fence(std::memory_order_release) even though the description in the C++11 standard
/// is not that explicit.
///
/// The following example might illustrate which kind of reordering is allowed when MemoryFenceRelease() is used:
/// @code
/// *pa = a; [1] store a in the location pa points to
/// b = *pb; [2] load b from the location pb
/// MemoryFenceRelease();
/// *pc = c; [3] store c in the location pc points to
/// d = *pd; [4] load d from the location pd
/// @endcode
///
/// The store [1] must be executed before the fence (but it could be reordered and happen before [2]).
/// The load [2] must be executed before the fence (but it could be reordered and happen before [1]).
/// The store [3] must be executed after the fence (but it could be reordered and happen after [4]).
/// The load [4] can be reordered and executed before the fence
///
/// A store operation with release semantics like value.StoreRelease() is equivalent to a MemoryFenceRelease()
/// followed by a value.StoreRelaxed(). Due to the fence preceding the store there is the following perhaps
/// unexpected behaviour: When a StoreRelease() is followed by a StoreRelaxed() the relaxed store might be
/// reordered and executed first (but none of the stores will jump across the fence).
#if defined(MAXON_TARGET_CPU_INTEL)
	// On x86 it is sufficient if the compiler doesn't reorder the code.
	#define MemoryFenceRelease()							CompilerOptimizationBarrier()
#elif defined(MAXON_TARGET_CPU_PPC)
	// PPC has weaker memory ordering than x86: lwsync doesn't order loads with respect to previous stores and is executed as sync on older ppcs.
	#define	MemoryFenceRelease()							asm volatile ("lwsync" : : : "memory")
#else
	// ARM (or whatever else) has weaker memory ordering than x86 and depending on the specific architecture might use dmb.
	#define MemoryFenceRelease()							std::atomic_thread_fence(std::memory_order_release)
#endif

/// The term load means "read access to a memory location" and a store is a "write access to a memory location".
/// The terms acquire and release which are used to describe a type of barrier are derived from the way a mutex works: When it
/// is acquired (locked), it ensures that the current thread will see the stores of other threads (which have released the mutex).
/// And when a mutex is released (unlocked), it ensures that the stores of the current thread will be visible to other threads
/// (when they acquire the mutex).
///
/// MemoryFenceSequential() prevents the reordering of any load or store which precedes it in program order
/// with any load or store which follows it in program order. It makes sure that they are globally
/// visible before any load or store that follows it.
/// Besides being a LoadLoad, LoadStore and StoreStore barrier this also works as StoreLoad barrier
/// which none of the other two fences does. It is equivalent to a std::atomic_thread_fence(memory_order_seq_cst).
#if defined(MAXON_TARGET_CPU_INTEL)
	// Available since Pentium 4.
	#ifdef MAXON_TARGET_WINDOWS
		#define	MemoryFenceSequential()					_mm_mfence()
	#else
		#define	MemoryFenceSequential()					asm volatile ("mfence" : : : "memory")
	#endif
#elif defined(MAXON_TARGET_CPU_PPC)
	// PPC has weaker memory ordering than x86: sync is quite costly.
	#define	MemoryFenceSequential()						asm volatile ("sync" : : : "memory")
#else
	// ARM (or whatever else) has weaker memory ordering than x86 and depending on the specific architecture might use dmb.
	#define	MemoryFenceSequential()						std::atomic_thread_fence(std::memory_order_seq_cst)
#endif

//----------------------------------------------------------------------------------------
/// Atomic 32 bit integer template.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
template <typename T> class Atomic32
{
	static_assert(sizeof(T) == sizeof(Int32), "sizeof(T) != sizeof(Int32)");

	T volatile _value;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(Atomic32);

public:
	MAXON_IMPLICIT Atomic32(T value = T()) : _value(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Load() const
	{
		return (T) atomic_sequential_load32((Int32 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T newValue)
	{
		atomic_sequential_store32((Int32 volatile*) &_value, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadRelaxed() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T newValue)
	{
		_value = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadAcquire() const
	{
		return (T) atomic_acquire_load32((Int32 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T newValue)
	{
		atomic_release_store32((Int32 volatile*) &_value, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadConsume() const
	{
		return (T) atomic_consume_load32((Int32 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(T newValue, T compare)
	{
		return atomic_try_cas32((Int32 volatile*) &_value, (Int32) newValue, (Int32) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	Swap(T newValue)
	{
		return (T) atomic_swap32((Int32 volatile*) &_value, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapAdd(T add)
	{
		return (T) atomic_swap_add32((Int32 volatile*) &_value, (Int32) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapIncrement()
	{
		return (T) atomic_swap_add32((Int32 volatile*) &_value, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic subtract with sequentially consistent memory order.
	/// Subtracts the specified value from the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] sub								Value to be subtracted.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapSubtract(T sub)
	{
		return (T)atomic_swap_add32((Int32 volatile*)&_value, -(Int32)sub);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapDecrement()
	{
		return (T) atomic_swap_add32((Int32 volatile*) &_value, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic or with sequentially consistent memory order.
	/// Ors the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] orValue						Value to be ored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapOr(T orValue)
	{
		return (T) atomic_swap_or32((Int32 volatile*) &_value, (Int32) orValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic and with sequentially consistent memory order.
	/// Ands the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] andValue						Value to be anded.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapAnd(T andValue)
	{
		return (T) atomic_swap_and32((Int32 volatile*) &_value, (Int32) andValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Pointer to the memory location.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	static inline Bool TryCompareAndSwap(T volatile* v, T newValue, T compare)
	{
		return atomic_try_cas32((Int32 volatile*) v, (Int32) newValue, (Int32) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Pointer to the memory location.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	Swap(T volatile* v, T newValue)
	{
		return (T) atomic_swap32((Int32 volatile*) v, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T Load(T volatile* v)
	{
		return (T) atomic_sequential_load32((Int32 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void Store(T volatile* v, T newValue)
	{
		atomic_sequential_store32((Int32 volatile*) v, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadRelaxed(T volatile* v)
	{
		return (T) *v;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void	StoreRelaxed(T volatile* v, T newValue)
	{
		*v = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadAcquire(T volatile* v)
	{
		return (T) atomic_acquire_load32((Int32 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void StoreRelease(T volatile* v, T newValue)
	{
		atomic_release_store32((Int32 volatile*) v, (Int32) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadConsume(T volatile* v)
	{
		return (T) atomic_consume_load32((Int32 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapAdd(T volatile* v, T add)
	{
		return (T) atomic_swap_add32((Int32 volatile*) v, (Int32) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapIncrement(T volatile* v)
	{
		return (T) atomic_swap_add32((Int32 volatile*) v, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapDecrement(T volatile* v)
	{
		return (T) atomic_swap_add32((Int32 volatile*) v, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic or with sequentially consistent memory order.
	/// Ors the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @param[in] orValue						Value to be ored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapOr(T volatile* v, T orValue)
	{
		return (T) atomic_swap_or32((Int32 volatile*) v, (Int32) orValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic and with sequentially consistent memory order.
	/// Ands the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @param[in] andValue						Value to be anded.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapAnd(T volatile* v, T andValue)
	{
		return (T) atomic_swap_and32((Int32 volatile*) v, (Int32) andValue);
	}

	using ValueType = T;
};


using AtomicInt32 = Atomic32<Int32>;												///< Atomic integer with the same size as Int32.
using AtomicUInt32 = Atomic32<UInt32>;											///< Atomic unsigned integer with the same size as UInt32.
#ifndef MAXON_TARGET_64BIT
using AtomicInt = Atomic32<Int>;														///< Atomic integer with the same size as Int.
using AtomicUInt = Atomic32<UInt>;													///< Atomic unsigned integer with the same size as UInt.
#endif

static_assert(sizeof(AtomicInt32) == 4, "wrong AtomicInt32 size");
static_assert(sizeof(AtomicUInt32) == 4, "wrong AtomicUInt32 size");

//----------------------------------------------------------------------------------------
/// Atomic 64 bit integer template.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
#ifdef MAXON_TARGET_64BIT
template <typename T> class Atomic64
{
	T volatile _value;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(Atomic64);

public:
	MAXON_IMPLICIT Atomic64(T value = T()) : _value(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Load() const
	{
		return (T) atomic_sequential_load64((Int64 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T newValue)
	{
		atomic_sequential_store64((Int64 volatile*) &_value, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadRelaxed() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T newValue)
	{
		_value = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadAcquire() const
	{
		return (T) atomic_acquire_load64((Int64 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T newValue)
	{
		atomic_release_store64((Int64 volatile*) &_value, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadConsume() const
	{
		return (T) atomic_consume_load64((Int64 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(T newValue, T compare)
	{
		return atomic_try_cas64((Int64 volatile*) &_value, (Int64) newValue, (Int64) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	Swap(T newValue)
	{
		return (T) atomic_swap64((Int64 volatile*) &_value, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapAdd(T add)
	{
		return (T) atomic_swap_add64((Int64 volatile*) &_value, (Int64) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapIncrement()
	{
		return (T) atomic_swap_add64((Int64 volatile*) &_value, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapDecrement()
	{
		return (T) atomic_swap_add64((Int64 volatile*) &_value, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Pointer to the memory location.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	static inline Bool TryCompareAndSwap(T volatile* v, T newValue, T compare)
	{
		return atomic_try_cas64((Int64 volatile*) v, (Int64) newValue, (Int64) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Pointer to the memory location.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	Swap(T volatile* v, T newValue)
	{
		return (T) atomic_swap64((Int64 volatile*) v, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T Load(T volatile* v)
	{
		return (T) atomic_sequential_load64((Int64 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void Store(T volatile* v, T newValue)
	{
		atomic_sequential_store64((Int64 volatile*) v, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadAcquire(T volatile* v)
	{
		return (T) atomic_acquire_load64((Int64 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void StoreRelease(T volatile* v, T newValue)
	{
		atomic_release_store64((Int64 volatile*) v, (Int64) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadConsume(T volatile* v)
	{
		return (T) atomic_consume_load64((Int64 volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T LoadRelaxed(T volatile* v)
	{
		return (T) *v;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void	StoreRelaxed(T volatile* v, T newValue)
	{
		*v = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapAdd(T volatile* v, T add)
	{
		return (T) atomic_swap_add64((Int64 volatile*) v, (Int64) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapIncrement(T volatile* v)
	{
		return (T) atomic_swap_add64((Int64 volatile*) v, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] v									Memory location.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T	SwapDecrement(T volatile* v)
	{
		return (T) atomic_swap_add64((Int64 volatile*) v, -1);
	}

	using ValueType = T;
};

using AtomicInt64 = Atomic64<Int64>;												///< Atomic integer with the same size as Int64.
using AtomicUInt64 = Atomic64<UInt64>;											///< Atomic unsigned integer with the same size as UInt64.
using AtomicInt = Atomic64<Int>;														///< Atomic integer with the same size as Int.
using AtomicUInt = Atomic64<UInt>;													///< Atomic unsigned integer with the same size as UInt.

static_assert(sizeof(AtomicInt64) == 8, "wrong AtomicInt64 size");
static_assert(sizeof(AtomicUInt64) == 8, "wrong AtomicUInt64 size");

#endif

//----------------------------------------------------------------------------------------
/// Atomic 16 bit integer template.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
template <typename T> class Atomic16
{
	T volatile _value;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(Atomic16);

public:
	MAXON_IMPLICIT Atomic16(T value = T()) : _value(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Load() const
	{
		return (T) atomic_sequential_load16((Int16 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T newValue)
	{
		atomic_sequential_store16((Int16 volatile*) &_value, (Int16) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadRelaxed() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T newValue)
	{
		_value = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadAcquire() const
	{
		return (T) atomic_acquire_load16((Int16 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T newValue)
	{
		atomic_release_store16((Int16 volatile*) &_value, (Int16) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadConsume() const
	{
		return (T) atomic_consume_load16((Int16 volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapAdd(T add)
	{
		return (T) atomic_swap_add16((Int16 volatile*) &_value, (Int16) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapIncrement()
	{
		return (T) atomic_swap_add16((Int16 volatile*) &_value, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapDecrement()
	{
		return (T) atomic_swap_add16((Int16 volatile*) &_value, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(T newValue, T compare)
	{
		return atomic_try_cas16((Int16 volatile*) &_value, (Int16) newValue, (Int16) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	Swap(T newValue)
	{
		return (T) atomic_swap16((Int16 volatile*) &_value, (Int16) newValue);
	}

	using ValueType = T;
};

using AtomicInt16 = Atomic16<Int16>;										///< Atomic integer with the same size as Char.
using AtomicUInt16 = Atomic16<UInt16>;									///< Atomic unsigned integer with the same size as UChar.

static_assert(sizeof(AtomicInt16) == 2, "wrong AtomicInt16 size");
static_assert(sizeof(AtomicUInt16) == 2, "wrong AtomicUInt16 size");

//----------------------------------------------------------------------------------------
/// Atomic 8 bit integer template.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
template <typename T> class Atomic8
{
	T volatile _value;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(Atomic8);

public:
	MAXON_IMPLICIT Atomic8(T value = T()) : _value(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Load() const
	{
		return (T) atomic_sequential_load8((Char volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T newValue)
	{
		atomic_sequential_store8((Char volatile*) &_value, (Char) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadRelaxed() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T newValue)
	{
		_value = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadAcquire() const
	{
		return (T) atomic_acquire_load8((Char volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T newValue)
	{
		atomic_release_store8((Char volatile*) &_value, (Char) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadConsume() const
	{
		return (T) atomic_consume_load8((Char volatile*) &_value);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapAdd(T add)
	{
		return (T) atomic_swap_add8((Char volatile*) &_value, (Char) add);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic increment with sequentially consistent memory order.
	/// Increments the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapIncrement()
	{
		return (T) atomic_swap_add8((Char volatile*) &_value, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic decrement with sequentially consistent memory order.
	/// Decrements the value of the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	SwapDecrement()
	{
		return (T) atomic_swap_add8((Char volatile*) &_value, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(T newValue, T compare)
	{
		return atomic_try_cas8((Char volatile*) &_value, (Char) newValue, (Char) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T	Swap(T newValue)
	{
		return (T) atomic_swap8((Char volatile*) &_value, (Char) newValue);
	}

	using ValueType = T;
};

using AtomicInt8 = Atomic8<Char>;												///< Atomic integer with the same size as Char.
using AtomicUInt8 = Atomic8<UChar>;											///< Atomic unsigned integer with the same size as UChar.

static_assert(sizeof(AtomicInt8) == 1, "wrong AtomicInt8 size");
static_assert(sizeof(AtomicUInt8) == 1, "wrong AtomicUInt8 size");

//----------------------------------------------------------------------------------------
/// Atomic bool.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
class AtomicBool
{
	Char volatile _value;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(AtomicBool);

public:
	MAXON_IMPLICIT AtomicBool(Bool value = false) : _value(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline Bool Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(Bool newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline Bool Load() const
	{
		return atomic_sequential_load8((Char volatile*) &_value) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(Bool newValue)
	{
		atomic_sequential_store8((Char volatile*) &_value, (Char) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline Bool LoadRelaxed() const
	{
		return _value != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(Bool newValue)
	{
		_value = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline Bool LoadAcquire() const
	{
		return atomic_acquire_load8((Char volatile*) &_value) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(Bool newValue)
	{
		atomic_release_store8((Char volatile*) &_value, (Char) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline Bool LoadConsume() const
	{
		return atomic_consume_load8((Char volatile*) &_value) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(Bool newValue, Bool compare)
	{
		return atomic_try_cas8(&_value, (Char) newValue, (Char) compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline Bool	Swap(Bool newValue)
	{
		return atomic_swap8((Char volatile*) &_value, (Char) newValue) != 0;
	}

	using ValueType = Bool;
};

static_assert(sizeof(AtomicBool) == 1, "wrong AtomicBool size");


//----------------------------------------------------------------------------------------
/// Atomic float template.
/// Since floating point loads and stores are not atomic the template uses integers loads and
/// stores and then safely reinterprets them as floats.
//----------------------------------------------------------------------------------------
template <typename T> class AtomicFloatType
{
	// Prevent anything other than floating point types.
	static_assert(std::is_floating_point<T>::value, "Only floating point types allowed.");

	// Prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(AtomicFloatType);

public:
	using ValueType		= T;
	using IntT				= typename IntType<SIZEOF(T)>::type;
	using AtomicType	= typename std::conditional<SIZEOF(T) == 4, Atomic32<Int32>, Atomic64<Int64>>::type;

	MAXON_IMPLICIT AtomicFloatType(T value = T()) : _value(reinterpret_cast<IntT&>(value))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T Load() const
	{
		IntT buf = _value.Load();
		return reinterpret_cast<const T&>(buf);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T newValue)
	{
		T buf = newValue;
		_value.Store(reinterpret_cast<IntT&>(buf));
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadRelaxed() const
	{
		IntT buf = _value.LoadRelaxed();
		return reinterpret_cast<const T&>(buf);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T newValue)
	{
		_value.Store(reinterpret_cast<IntT&>(newValue));
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T LoadAcquire() const
	{
		IntT buf = _value.LoadAcquire();
		return reinterpret_cast<const T&>(buf);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T& newValue)
	{
		_value.StoreRelease(reinterpret_cast<IntT&>(newValue));
	}
	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(const T& newValue, const T& compare)
	{
		return _value.TryCompareAndSwap(reinterpret_cast<const IntT&>(newValue), reinterpret_cast<const IntT&>(compare));
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T Swap(T& newValue)
	{
		IntT buf = _value.Swap(reinterpret_cast<IntT&>(newValue));
		return reinterpret_cast<T&>(buf);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic add with sequentially consistent memory order.
	/// Adds the specified value to the memory location and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] add								Value to be added.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T SwapAdd(T add)
	{
		T compare = LoadRelaxed();
		while (TryCompareAndSwap(compare +  add, compare) == false)
			compare = LoadAcquire();
	
		return compare;
	}
	
private:
	AtomicType _value;
};

using AtomicFloat32 = AtomicFloatType<Float32>;					///< Atomic float with 32 bit size.
using AtomicFloat64 = AtomicFloatType<Float64>;					///< Atomic float with 64 bit size.


/// @cond IGNORE

template <typename T> inline Bool AtomicCASPtr(T* volatile* dst, T* xchg, T* cmp)
{
#ifdef MAXON_TARGET_64BIT
	return atomic_try_cas64((Int64 volatile*) dst, (Int64) xchg, (Int64) cmp);
#else
	return atomic_try_cas32((Int32 volatile*) dst, (Int32) xchg, (Int32) cmp);
#endif
}

template <typename T> inline T* AtomicSwapPtr(T* volatile* dst, T* xchg)
{
	return (T*) AtomicInt::Swap((Int volatile*) dst, (Int) xchg);
}

/// @endcond

//----------------------------------------------------------------------------------------
/// Atomic pointer template.
///
/// = Relaxed Ordering
/// : Relaxed ordering means that stores to or loads from a memory location can be reordered
///   by the CPU which means that other threads may observe a completely different order of
///   loads and stores than what your thread seems to do.
///
/// = Acquire-Release Ordering
/// : If another thread has released a store on a memory location it is guaranteed that after
///   a load with acquire memory order all following loads will see the (relaxed) stores that
///   preceded the release. Furthermore subsequent loads or stores will not be speculatively
///   executed before this load.
///
/// = Sequentially Consistent Ordering
/// : As the name implies operations with this ordering appear in the same order to other
///   threads. This comes at the cost of relatively expensive synchronization between the
///   CPU cores.
///
/// By default all memory accesses in C++ are relaxed, any write or read to a variable can
/// be reordered by the CPU. Please note that even if your target CPU does not change the
/// order of memory accesses the C compiler may do so.
/// x86 style CPUs adhere to acquire-release ordering for most memory accesses as long as
/// you don't make use of SSE/AVX. This means that multi threaded code without atomic
/// variables appears to run just fine as long as the compiler doesn't reorder accesses.
/// Of course this code might fail miserably on other platforms (e.g. ARM) or when a new
/// compiler performs optimizations. Therefore you should use AtomicInt*/AtomicPtr for variables
/// that are shared by different threads.
//----------------------------------------------------------------------------------------
template <typename T> class AtomicPtr
{
	T* volatile _ptr;

	// prevent unintended unsafe copy of an atomic value
	MAXON_DISALLOW_COPY_AND_ASSIGN(AtomicPtr);

public:
	MAXON_IMPLICIT AtomicPtr(T* newValue = (T*) nullptr) : _ptr(newValue)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to get an atomic value.
	/// It is identical to Load() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T* Get() const
	{
		return Load();
	}

	//----------------------------------------------------------------------------------------
	/// Default routine to set an atomic value.
	/// It is identical to Store() with sequentially consistent memory order. Other routines might deliver improved performance.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Set(T* newValue)
	{
		Store(newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with sequentially consistent memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T* Load() const
	{
		return (T*) AtomicInt::Load((Int volatile*) &_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with sequentially consistent memory order.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void Store(T* newValue)
	{
		AtomicInt::Store((Int volatile*) &_ptr, (Int) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with relaxed memory order.
	/// This load is completely unordered (might be prefetched). You should only use it within
	/// the same thread when guarded with preceding acquire load or a fence. Fences are
	/// implicitly created by TryCompareAndSwap, Swap, SwapAdd, SwapIncrement, SwapDecrement
	/// and by locks.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T* LoadRelaxed() const
	{
		return (T*) _ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with relaxed memory order.
	/// This store is completely unordered. You should only use it within the same thread
	/// when guarded by a following release store or a fence.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void	StoreRelaxed(T* newValue)
	{
		_ptr = newValue;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T* LoadAcquire() const
	{
		return (T*) AtomicInt::LoadAcquire((Int volatile*) &_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	inline void StoreRelease(T* newValue)
	{
		AtomicInt::StoreRelease((Int volatile*) &_ptr, (Int) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	inline T* LoadConsume() const
	{
		return (T*) AtomicInt::LoadConsume((Int volatile*) &_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	inline Bool	TryCompareAndSwap(T* newValue, T* compare)
	{
		return AtomicCASPtr(&_ptr, newValue, compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	inline T* Swap(T* newValue)
	{
		return AtomicSwapPtr(&_ptr, newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with acquire memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with acquire memory order all following loads will see the (relaxed) stores that
	/// preceded the release. Furthermore subsequent loads or stores will not be speculatively
	/// executed before this load.
	/// This is equivalent to a relaxed load followed by a MemoryFenceAcquire().
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T* LoadAcquire(T* volatile* v)
	{
		return (T*) AtomicInt::LoadAcquire((Int volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic store with release memory order.
	/// As soon as another thread reads on this location using LoadAcquire() and obtains the
	/// stored value it is guaranteed that all prior (relaxed) stores are visible to it.
	/// This is equivalent to a MemoryFenceRelease() followed by a relaxed store.
	/// @param[in] v									Memory location.
	/// @param[in] newValue						Value to be stored.
	//----------------------------------------------------------------------------------------
	static inline void StoreRelease(T* volatile* v, T* newValue)
	{
		AtomicInt::StoreRelease((Int volatile*) v, (Int) newValue);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic load with consume memory order.
	/// If another thread has released a store on this location it is guaranteed that after a
	/// load with consume memory order that reads the value stored direct dependencies are
	/// synchronized (e.g. if the value is a pointer to a structure you can safely access the
	/// elements of the structure that have been written before the release).
	/// This means that unrelated loads following this method might be reordered by the compiler
	/// or the CPU and can be executed before it.
	/// For most CPU architectures this the same instruction as an ordinary load which implies
	/// no performance penalty compared to a load with relaxed memory order.
	/// @param[in] v									Memory location.
	/// @return												Read memory location content.
	//----------------------------------------------------------------------------------------
	static inline T* LoadConsume(T* volatile* v)
	{
		return (T*) AtomicInt::LoadConsume((Int volatile*) v);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap with sequentially consistent memory order.
	/// If the previous memory location value equals compare newValue is written to the memory
	/// location and true is returned. If the memory location contained a different value it
	/// is not changed and false will be returned.
	/// If the value is exchanged this call enforces a sequentially consistent memory order
	/// which means that it might require potentially expensive synchronization between the CPUs.
	/// @param[in] dst								Pointer to the memory location.
	/// @param[in] newValue						Value to be stored if memory location contains compare.
	/// @param[in] compare						Value to compare with memory location.
	/// @return												True if the memory value was exchanged.
	//----------------------------------------------------------------------------------------
	static inline Bool TryCompareAndSwap(T* volatile* dst, T* newValue, T* compare)
	{
		return AtomicCASPtr(dst, newValue, compare);
	}

	//----------------------------------------------------------------------------------------
	/// Atomic swap with sequentially consistent memory order.
	/// Exchanges the value of the memory location with newValue and returns the previous value.
	/// This call enforces a sequentially consistent memory order	which means that it might
	/// require potentially expensive synchronization between the CPUs.
	/// @param[in] dst								Pointer to the memory location.
	/// @param[in] newValue						Value to be stored.
	/// @return												Previous value of the memory location.
	//----------------------------------------------------------------------------------------
	static inline T* Swap(T* volatile* dst, T* newValue)
	{
		return AtomicSwapPtr(dst, newValue);
	}

	using ValueType = T*;
};

using AtomicVoidPtr = AtomicPtr<void>;


//----------------------------------------------------------------------------------------
/// Atomic reference counter.
//----------------------------------------------------------------------------------------
class StrongReferenceCounter
{
public:
	StrongReferenceCounter() {}

	// This data type does not support copying or moving, but we have to add dummy operators for data type registration.
	StrongReferenceCounter(const StrongReferenceCounter&) { __debugbreak(); }
	void operator =(const StrongReferenceCounter&)  { __debugbreak(); }

	//----------------------------------------------------------------------------------------
	/// Increments reference counter (the caller acquires a strong reference).
	/// @return												True for the very first reference, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool Inc()
	{
		UInt oldValue = _value.SwapAdd(16);

		// #killedObjectCheck: if this assert pops up a already destructed object will be ref counted again.
		DebugAssert(Int(oldValue) >= 0);

		return oldValue == UInt(0);
	}

	//----------------------------------------------------------------------------------------
	/// Decrements reference counter (the caller removes a strong reference).
	/// @return												True if no more strong references are held, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool Dec()
	{
		UInt oldValue = _value.SwapAdd(UInt(-16));

		DebugAssert(Int(oldValue) > 0, "Reference count is invalid.");

		return oldValue < UInt(32);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a reference if the object is still strongly referenced.
	/// @return												True if a strong reference was added, false if the object is currently being destructed.
	//----------------------------------------------------------------------------------------
	Bool ConditionalInc()
	{
		UInt oldValue = 0;

		// Only add a reference if at least one strong reference is still existing (oldValue must be at least 16).
		do
		{
			oldValue = _value.LoadRelaxed();
		} while (oldValue >= 16 && _value.TryCompareAndSwap(oldValue + 16, oldValue) == false);

		DebugAssert(oldValue != UInt(0x6d6d6d6d6d6d6d6d) && oldValue != UInt(-1), "Warning: You might access invalid memory.");

		return oldValue >= UInt(16);
	}

	//----------------------------------------------------------------------------------------
	/// Adds references.
	/// @param[in] additionalReferences	The number of additional references to add.
	//----------------------------------------------------------------------------------------
	void Add(UInt additionalReferences)
	{
		_value.SwapAdd(additionalReferences << 4);
	}

	//----------------------------------------------------------------------------------------
	/// Sets a specifc reference count - for initialization only!
	/// @note You must guarantee that the access is exclusive and single-threaded. Use only for
	/// initialization of static objects which are not to destructed.
	//----------------------------------------------------------------------------------------
	void SetRelaxed(UInt referenceCount)
	{
		_value.StoreRelaxed(referenceCount << 4);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of strong references to the object.
	/// @return												The number of strong references.
	//----------------------------------------------------------------------------------------
	operator UInt() const
	{
		return _value.LoadAcquire() >> 4;
	}

	//----------------------------------------------------------------------------------------
	/// Returns whether an object has more than a single reference.
	/// For an object without a reference it will return false.
	/// For an object with one reference it will return false.
	/// For an object with a single reference and weak references it will return true.
	/// For an object with two references it will return true.
	/// @return												True if the object has more than a single reference, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasMultipleReferences() const
	{
		return _value.LoadRelaxed() >= 24;
	}

	//----------------------------------------------------------------------------------------
	/// The underlying integral type of this reference counter.
	//----------------------------------------------------------------------------------------
	using ValueType = UInt;

	static const StrongReferenceCounter& NullValue()
	{
		return GetZeroRef<StrongReferenceCounter>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the reference counter for classes which do not implement custom AddReference/RemoveReference methods.
	//----------------------------------------------------------------------------------------
	static StrongReferenceCounter& Get(const void* object)
	{
#ifdef MAXON_TARGET_64BIT
		if (UInt(object) & 31)
		{
			DebugStop("The object pointer is not properly aligned. Check for referenced objects with non-virtual base class and virtual subclasses.");
		}
#else
		if (UInt(object) & 15)
		{
			DebugStop("The object pointer is not properly aligned. Check for referenced objects with non-virtual base class and virtual subclasses.");
		}
#endif
		return *(StrongReferenceCounter*)(UInt(object) - SIZEOF(StrongReferenceCounter));
	}

protected:
	AtomicUInt _value;
};

/// @}

} // namespace maxon

#endif // ATOMICTYPES_H__
