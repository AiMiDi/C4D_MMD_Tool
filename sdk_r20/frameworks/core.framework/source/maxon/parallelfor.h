#ifndef PARALLELFOR_H__
#define PARALLELFOR_H__

#include "maxon/thread.h"

namespace maxon
{

#if defined(MAXON_COMPILER_MSVC)
	#pragma warning(push)
	#pragma warning(disable:4458) // declaration of ... hides class member
#endif

/// @addtogroup THREADING Threading
/// @{

/// Flags controlling the threading of the init and finalize section of ParallelFor.
/// The default case is INITTHREADED_FINALIZESYNC. Each worker thread will independently call the init section for its
/// part of the loop and then execute the loop body. The init section of a thread might be executed after any another
/// thread has almost executed the whole loop - <B>there's no guarantee that all init sections have finished before the
/// loop body is entered, you might even have worker threads that don't run the init, loop and finalize section because
/// another thread has already done the whole work</B>. After the loop has finished for each init section the corresponding
/// finalize will be called synchronously one after another.
/// There might be cases where you must make sure that the init section for all worker threads has finished before the loop
/// is executed, for example because you also must initialize some global variables for each worker thread that will be
/// utilized by nested ParallelFors or other sub-jobs. Depending on your needs you might specify INITSYNC_FINALIZETHREADED,
/// INITSYNC_FINALIZESYNC or INITTHREADEDWITHSYNC_FINALIZESYNC.
/// Please note that INITTHREADEDWITHSYNC_FINALIZESYNC is slower than INITTHREADED_FINALIZESYNC because of the additional
/// synchronization after the init phase.
enum class PARALLELFORFLAGS
{
	INITTHREADED_FINALIZETHREADED			= 0,		///< Init() and Finalize() calls are threaded.
	INITTHREADED_FINALIZESYNC					= 1,		///< Init() is called threaded, Finalize() is called synchronously (default case).
	INITSYNC_FINALIZETHREADED					= 2,		///< Init() is called synchronously, Finalize() is called threaded.
	INITSYNC_FINALIZESYNC							= 3,		///< Init() and Finalize() are called synchronously.
	NOINIT_NOFINALIZE									= 4,		///< no call to Init() or Finalize().
	INITTHREADEDWITHSYNC_FINALIZESYNC = 5			///< Init() is called threaded but the parallel loop body won't start until Init() has finished for all threads, Finalize() is called synchronously.
} MAXON_ENUM_FLAGS(PARALLELFORFLAGS);

static const Int PARALLELFOR_DEFAULTGRANULARITY = 16;
static const Int PARALLELFOR_MINIMUMGRANULARITY = 1;
static const Int PARALLELFOR_USEMAXIMUMTHREADS = 0;
static const Int PARALLELFOR_DISABLETHREADING = 1;
static const Int PARALLELFOR_MAXIMUMDEPTH = 8;

// Helper macro to avoid a conflict between Dynamic/Static without init/finalize but all parameters and Dynamic/Static with all three lambdas but without optional parameters.
#define DISABLE_IF_LOOP_TYPE_IS_INT(TYPE, ...) typename std::enable_if<!std::is_convertible<typename std::remove_reference<TYPE>::type, maxon::Int>::value, __VA_ARGS__>::type

//----------------------------------------------------------------------------------------
/// This class contains of several methods that implement a for loop which is distributing
/// the work load on multiple threads. You can choose between static or dynamic distribution
/// and optionally specify objects to initialize and finalize per worker thread data.
//----------------------------------------------------------------------------------------
class ParallelFor
{
	template <typename CONTEXT, typename RESULTVALUETYPE> class InvokeSelector;
public:
	struct BreakCondition
	{
		AtomicBool _value;

		BreakCondition() : _value(false)
		{
		}
	};

	//----------------------------------------------------------------------------------------
	/// Basic context for ParallelFor loops. Each worker thread has its own local context.
	//----------------------------------------------------------------------------------------
	class BaseContext
	{
	public:
		BaseContext()
		{
			// intentionally does nothing
		}

		//----------------------------------------------------------------------------------------
		/// Intializes the custom user data for a complex loop.
		/// @param[in] from								Start index.
		/// @param[in] to									End index (excluded)
		/// @param[in] threadIndex				Initial thread index.
		/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
		//----------------------------------------------------------------------------------------
		template <typename INDEXTYPE> void PrivateInit(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition)
		{
			_from = Int(from);
			_to = Int(to);
			_workerThreadIndex = threadIndex;
			_localContextIndex = threadIndex;
			_breakCondition = breakCondition;
		}

		//----------------------------------------------------------------------------------------
		/// Invokes the loop body object.
		/// @param[in] obj								Reference to loop body object.
		/// @param[in] i									Index.
		/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
		/// @tparam CONTEXT								Type of context super class.
		/// @tparam INDEXTYPE							An integral type used for the index of the loop.
		//----------------------------------------------------------------------------------------
		template <typename FN, typename CONTEXT, typename INDEXTYPE> void Invoke(FN& obj, INDEXTYPE i)
		{
			using LoopResultType = decltype(obj(i, *(CONTEXT*)this));

			InvokeSelector<CONTEXT, LoopResultType>::Loop(obj, i, *(CONTEXT*)this);
		}

		//----------------------------------------------------------------------------------------
		/// Returns true if the loop should be quit.
		/// @return												Always return false so that the compiler can remove unnecessary compares and jumps.
		//----------------------------------------------------------------------------------------
		Bool IsCancelled() const
		{
			return false;
		}

		//----------------------------------------------------------------------------------------
		/// Returns the index of the worker thread.
		/// This is the same value as returned by JobRef::GetCurrentWorkerThreadIndex() (but with less
		/// overhead) and is guaranteed to be identical for nested ParallelFors on the same worker thread.
		/// <B>The worker thread index might be greater than the number of threads you specified</B>
		/// because your code will be scheduled to run on the first available thread of the queue.
		/// @return												Worker thread index (between 0 and number of worker threads for the queue - 1).
		//----------------------------------------------------------------------------------------
		Int GetWorkerThreadIndex() const
		{
			DebugAssert(_workerThreadIndex != InvalidArrayIndex);
			return _workerThreadIndex;
		}

		//----------------------------------------------------------------------------------------
		/// Updates the worker thread index once a loop is a started on a job.
		//----------------------------------------------------------------------------------------
		void UpdateWorkerThreadIndex(Int threadIndex = JobRef::GetCurrentWorkerThreadIndex())
		{
			_workerThreadIndex = threadIndex;
		}

		//----------------------------------------------------------------------------------------
		/// Returns a local thread index between 0 and the the number of threads requested - 1.
		/// <B>The value is different from GetWorkerThreadIndex()/GetCurrentWorkerThreadIndex()
		/// and for nested ParallelFors it can be different on the same worker thread.</B>
		/// @return												Local thread index (between 0 and number of requested threads - 1).
		//----------------------------------------------------------------------------------------
		Int GetLocalThreadIndex() const
		{
			DebugAssert(_localContextIndex != InvalidArrayIndex);
			return _localContextIndex;
		}

		//----------------------------------------------------------------------------------------
		/// Does nothing (use BreakContext).
		/// @param[in] result							Used to return an optional error.
		//----------------------------------------------------------------------------------------
		void Break(Result<void> result = OK)
		{
			DebugStop("You must inherit from BreakContext.");
		}

		// Any loop using just a BaseContext must return void.
		using ResultValueType = void;

		/// Ignores the result of the StaticJobGroup because it cannot fail (and the loop body returns void).
		static ResultValueType Return(Result<void>&& r)
		{
			iferr (r)
			{
				DebugStop("Someone has broken ParallelFor or the StaticJobGroup");
			}
		}

	private:
		MAXON_DISALLOW_COPY_AND_ASSIGN(BaseContext);

	public:
		Int _from;
		Int _to;
		Int _workerThreadIndex;
		Int _localContextIndex;
		Result<void> _result;
		BreakCondition* _breakCondition;
	};

	//----------------------------------------------------------------------------------------
	/// Context for ParallelFor loops that support cancellation.
	//----------------------------------------------------------------------------------------
	class BreakContext : public BaseContext
	{
	public:
		//----------------------------------------------------------------------------------------
		/// Asks all ParallelFor threads to cancel.
		/// @param[in] result							Used to return an optional error.
		//----------------------------------------------------------------------------------------
		void Break(Result<void> result = OK)
		{
			_result = result;
			_breakCondition->_value.StoreRelease(true);
		}

		//----------------------------------------------------------------------------------------
		/// Returns true if the loop should be quit.
		/// @return												True if the loop should be quit.
		//----------------------------------------------------------------------------------------
		Bool IsCancelled() const
		{
			return _breakCondition->_value.LoadAcquire();
		}

		// For BreakContext the result type of ParallelFor must always be Result<void> because it might return an error due to Break/Cancellation.
		using ResultValueType = Result<void>;

		static ResultValueType Return(Result<void>&& r) { return std::forward<Result<void>>(r); }
	};

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution.
	/// @code
	/// ParallelFor::Dynamic(from, to,
	/// 	[](Int i)
	/// 	{
	/// 	  // ... do something ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] granularity				The number of iterations after which a thread shares work with idle threads (1 means best distribution at the cost of higher synchronization, PARALLELFOR_DEFAULTGRANULARITY is the default).
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @return												Depending on the type of #LOOP either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename FROMTYPE, typename INDEXTYPE, typename LOOP>
		static inline auto Dynamic(FROMTYPE from, INDEXTYPE to, const LOOP& obj, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int granularity = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT) -> decltype(obj(to))
	{
		// Select either NoContext or BreakContext based on return value type.
		using Context = typename NoContextSelector<decltype(obj(to))>::Context;

		return Dynamic<Context, FROMTYPE, INDEXTYPE, LOOP>(from, to, obj, threadCnt, granularity, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution.
	/// @code
	/// ParallelFor::Dynamic<ParallelFor::BreakContext>(from, to,
	/// 	[&shouldWeBreak](Int i, ParallelFor::BreakContext& context)
	/// 	{
	/// 	  // ... example for a break condition ...
	/// 		if (shouldWeBreak)
	/// 		{
	/// 			// tell ParallelFor that it should cancel the loop and return from the closure
	/// 			context.Break();
	/// 			return;
	/// 		}
	/// 		// ... do something ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] granularity				The number of iterations after which a thread shares work with idle threads (1 means best distribution at the cost of higher synchronization, PARALLELFOR_DEFAULTGRANULARITY is the default).
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
		static MAXON_ATTRIBUTE_NO_INLINE typename CONTEXT::ResultValueType
		Dynamic(FROMTYPE from, INDEXTYPE to, const LOOP& obj, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int granularity = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT);

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution. The init
	/// method is called concurrently per worker thread whereas the finalize method is called
	/// synchronously (no concurrency) after the loop has finished.
	/// @code
	/// struct MyContext : public ParallelFor::BaseContext
	/// {
	///   // your thread local data ...
	/// };
	/// ParallelFor::Dynamic<MyContext>(from, to,
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... init thread local data ...
	/// 	},
	/// 	[](Int i, MyContext& context)
	/// 	{
	/// 		// ... computation in the loop body ...
	/// 	},
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... finalize thread local data ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] init								Lambda being called before the loop starts (threaded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] finalize						Lambda being called after the loop has finished (synchronous)
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] granularity				The number of iterations after which a thread shares work with idle threads (1 means best distribution at the cost of higher synchronization, PARALLELFOR_DEFAULTGRANULARITY is the default).
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
	/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
	/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE>
		static inline DISABLE_IF_LOOP_TYPE_IS_INT(LOOP, typename CONTEXT::ResultValueType)
		Dynamic(FROMTYPE from, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int granularity = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		return Dynamic<CONTEXT, PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC, FROMTYPE, INDEXTYPE, LOOP, INIT, FINALIZE>(from, to, init, obj, finalize, threadCnt, granularity, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution. The FLAGS
	/// template parameter can be used to specify if the init or finalize closure are called serialized
	/// or threaded.
	/// @code
	/// struct MyContext : public ParallelFor::BaseContext
	/// {
	///   // your thread local data ...
	/// };
	/// ParallelFor::Dynamic<MyContext, PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(from, to,
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... init thread local data ...
	/// 	},
	/// 	[](Int i, MyContext& context)
	/// 	{
	/// 		// ... computation in the loop body ...
	/// 	},
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... finalize thread local data ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] init								Lambda being called before the loop starts (threaded by default)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] finalize						Lambda being called after the loop has finished (synchronous by default)
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] granularity				The number of iterations after which a thread shares work with idle threads (1 means best distribution at the cost of higher synchronization, PARALLELFOR_DEFAULTGRANULARITY is the default).
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
	/// @tparam FLAGS									Flags that specify whether init or finalize will be called threaded or synchronously.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
	/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
	/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename FROMTYPE, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE>
		static MAXON_ATTRIBUTE_NO_INLINE typename CONTEXT::ResultValueType
		Dynamic(FROMTYPE from, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int granularity = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT);

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution.
	/// @code
	/// ParallelFor::Static(from, to,
	/// 	[](Int i)
	/// 	{
	/// 	  // ... do something ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] minChunkSize				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @return												Depending on the type of #LOOP either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename FROMTYPE, typename INDEXTYPE, typename LOOP>
		static inline auto Static(FROMTYPE from, INDEXTYPE to, const LOOP& obj, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int minChunkSize = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT) -> decltype(obj(to))
	{
		// Select either NoContext or BreakContext based on return value type.
		using Context = typename NoContextSelector<decltype(obj(to))>::Context;

		return Static<Context, FROMTYPE, INDEXTYPE, LOOP>(from, to, obj, threadCnt, minChunkSize, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution.
	/// @code
	/// ParallelFor::Static<ParallelFor::BreakContext>(from, to,
	/// 	[&shouldWeBreak](Int i, ParallelFor::BreakContext& context)
	/// 	{
	/// 	  // ... example for a break condition ...
	/// 		if (shouldWeBreak)
	/// 		{
	/// 			// tell ParallelFor that it should cancel the loop and return from the closure
	/// 			context.Break();
	/// 			return;
	/// 		}
	/// 	  // ... do something ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] minChunkSize				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
		static MAXON_ATTRIBUTE_NO_INLINE typename CONTEXT::ResultValueType
		Static(FROMTYPE from, INDEXTYPE to, const LOOP& obj, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int minChunkSize = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT);

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution. The init
	/// method is called concurrently per worker thread whereas the finalize method is called
	/// synchronously (no concurrency) after the loop has finished.
	/// @code
	/// struct MyContext : public ParallelFor::BaseContext
	/// {
	///   // your thread local data ...
	/// };
	/// ParallelFor::Static<MyContext>(from, to,
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... init thread local data ...
	/// 	},
	/// 	[](Int i, MyContext& context)
	/// 	{
	/// 		// ... computation in the loop body ...
	/// 	},
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... finalize thread local data ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] init								Lambda being called before the loop starts (threaded)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] finalize						Lambda being called after the loop has finished (synchronously)
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] minChunkSize				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
	/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
	/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE>
		static inline DISABLE_IF_LOOP_TYPE_IS_INT(LOOP, typename CONTEXT::ResultValueType)
		Static(FROMTYPE from, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int minChunkSize = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		return Static<CONTEXT, PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC, FROMTYPE, INDEXTYPE, LOOP, INIT, FINALIZE>(from, to, init, obj, finalize, threadCnt, minChunkSize, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution. The FLAGS
	/// template parameter can be used to specify if the init or finalize closure are called serialized
	/// or threaded.
	/// @code
	/// struct MyContext : public ParallelFor::BaseContext
	/// {
	///   // your thread local data ...
	/// };
	/// ParallelFor::Dynamic<MyContext, PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(from, to,
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... init thread local data ...
	/// 	},
	/// 	[](Int i, MyContext& context)
	/// 	{
	/// 		// ... computation in the loop body ...
	/// 	},
	/// 	[](MyContext& context)
	/// 	{
	/// 		// ... finalize thread local data ...
	/// 	});
	/// @endcode
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] init								Lambda being called before the loop starts (threaded by default)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] finalize						Lambda being called after the loop has finished (synchronously by default)
	/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
	/// @param[in] minChunkSize				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
	/// @param[in] queue							Optional queue that the parallel for is executed within.
	/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
	/// @tparam FLAGS									Flags that specify whether init or finalize will be called threaded or synchronously.
	/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
	/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
	/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
	/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
	/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
	//----------------------------------------------------------------------------------------
	template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename FROMTYPE, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE>
		static MAXON_ATTRIBUTE_NO_INLINE typename CONTEXT::ResultValueType
		Static(FROMTYPE from, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt = PARALLELFOR_USEMAXIMUMTHREADS, const Int minChunkSize = PARALLELFOR_DEFAULTGRANULARITY, JobQueueInterface* queue = JOBQUEUE_CURRENT);

	/// Dummy class for init or finalize
	class Dummy
	{
	public:
		void operator ()(BaseContext& context) const
		{
		}
	};

private:
	//----------------------------------------------------------------------------------------
	/// Computes chunk size for static distribution.
	/// If only one thread is used, the index is signed and the range of the loop requires an
	/// unsigned counter the return value will overflow, but the loops that assign the chunks
	/// to the jobs take care of this.
	/// @param[in] cnt								Number of iterations.
	/// @param[in,out] threadCnt			Number of threads to use.
	/// @param[in] minChunkSize				Minimum chunk size.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @return												Size of a chunk.
	//----------------------------------------------------------------------------------------
	template <typename INDEXTYPE> static inline INDEXTYPE CalculateStaticChunkSize(UInt cnt, Int& threadCnt, Int minChunkSize)
	{
		UInt chunkSize = cnt / UInt(threadCnt);

		// Chunk too small?
		if (chunkSize < UInt(minChunkSize))
		{
			chunkSize = UInt(minChunkSize);

			// Reduce the number of threads.
			threadCnt = Int(cnt / UInt(minChunkSize));
			if (threadCnt == 0)
				threadCnt = 1;
		}

		DebugAssert(threadCnt > 0);

		return INDEXTYPE(chunkSize);
	}

	//----------------------------------------------------------------------------------------
	/// Context for lambdas which don't expect a context pointer as argument and return nothing.
	//----------------------------------------------------------------------------------------
	class NoContext : public BaseContext
	{
	public:
		//----------------------------------------------------------------------------------------
		/// Invokes the loop body object.
		/// @param[in] obj								Reference to loop body object.
		/// @param[in] i									Index.
		/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
		/// @tparam CONTEXT								Type of context super class.
		/// @tparam INDEXTYPE							An integral type used for the index of the loop.
		//----------------------------------------------------------------------------------------
		template <typename FN, typename CONTEXT, typename INDEXTYPE> void Invoke(FN& obj, INDEXTYPE i)
		{
			obj(i);
		}

		void UpdateWorkerThreadIndex(Int threadIndex = InvalidArrayIndex) const
		{
			// intentionally does nothing because the context is not available to the closure
			(void) threadIndex;
		}

		// With NoContext the loop cannot return an error and therefore ParallelFor will be void.
		using ResultValueType = void;

		/// Ignores the result of the StaticJobGroup because it cannot fail (and the loop body returns void).
		static ResultValueType Return(Result<void>&& r)
		{
			iferr (r)
			{
				DebugStop("Someone has broken ParallelFor or the StaticJobGroup");
			}
		}
	};

	//----------------------------------------------------------------------------------------
	/// Context for lambdas which don't expect a context pointer as argument and return Result<void>.
	//----------------------------------------------------------------------------------------
	class NoBreakContext : public BreakContext
	{
	public:
		//----------------------------------------------------------------------------------------
		/// Invokes the loop body object.
		/// @param[in] obj								Reference to loop body object.
		/// @param[in] i									Index.
		/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
		/// @tparam CONTEXT								Type of context super class.
		/// @tparam INDEXTYPE							An integral type used for the index of the loop.
		//----------------------------------------------------------------------------------------
		template <typename FN, typename CONTEXT, typename INDEXTYPE> void Invoke(FN& obj, INDEXTYPE i)
		{
			iferr (obj(i))
				Break(err);
		}

		void UpdateWorkerThreadIndex(Int threadIndex = InvalidArrayIndex) const
		{
			// intentionally does nothing because the context is not available to the closure
			(void) threadIndex;
		}

		// With NoBreakContext the loop may return an error and therefore ParallelFor returns a Result<void>.
		using ResultValueType = Result<void>;

		static ResultValueType Return(Result<void>&& r) { return std::forward<Result<void>>(r); }
	};


	//----------------------------------------------------------------------------------------
	/// Helper template for lambdas with Result<void> and without context.
	//----------------------------------------------------------------------------------------
	template <typename RESULTVALUETYPE> class NoContextSelector
	{
	public:
		using Context = NoBreakContext;
	};

	class ParallelForJob : public JobInterface
	{
	public:
		explicit ParallelForJob(const JobInterfaceJumpTablePOD& jmpTable) : JobInterface(jmpTable) {}

		const Char* GetName() const
		{
			return "ParallelForJob";
		}
	};

	//----------------------------------------------------------------------------------------
	/// Context for complex loops including init and finalize section.
	/// @tparam FORCONTEXT						Either DynamicContext<CONTEXT> or StaticContext<CONTEXT>.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
	/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
	//----------------------------------------------------------------------------------------
	template <typename FORCONTEXT, typename INDEXTYPE, typename INIT, typename FINALIZE> struct alignas(MAXON_CACHE_LINE_SIZE) ForAlignedContext : public FORCONTEXT
	{
		//----------------------------------------------------------------------------------------
		/// @param[in] from								Start index.
		/// @param[in] to									End index (excluded)
		/// @param[in] threadIndex				Initial thread index.
		/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
		/// @param[in] init								Lambda being called in the thread context before the loop starts.
		/// @param[in] finalize						Lambda being called in the thread context after the loop has finished.
		//----------------------------------------------------------------------------------------
		ForAlignedContext(INDEXTYPE from, INDEXTYPE to, Int threadIndex, ParallelFor::BreakCondition* breakCondition, const INIT& init, const FINALIZE& finalize) : FORCONTEXT(from, to, threadIndex, breakCondition), _init(init), _finalize(finalize), _isInitialized(false)
		{
		}

		~ForAlignedContext()
		{
			Finalize();
		}

		/// Calls INIT method for user data initialization of the context.
		void Init()
		{
			if (_isInitialized == false)
			{
				using ResultValueType = decltype(_init(*(FORCONTEXT*)this));

				InvokeSelector<FORCONTEXT, ResultValueType>::Init(_init, *(FORCONTEXT*)this);
			}
			_isInitialized = true;
		}

		/// Calls FINALIZE method to finalize user data of the context.
		void Finalize()
		{
			if (_isInitialized)
			{
				using ResultValueType = decltype(_finalize(*(FORCONTEXT*)this));

				InvokeSelector<FORCONTEXT, ResultValueType>::Finalize(_finalize, *(FORCONTEXT*)this);
			}
			_isInitialized = false;
		}

	private:
		const INIT& _init;
		const FINALIZE& _finalize;
		Bool _isInitialized;																			// false means _context has not been initialized yet
	};

	//----------------------------------------------------------------------------------------
	/// Context for loops to be used without init and finalize section.
	/// @tparam FORCONTEXT						Either DynamicContext<CONTEXT> or StaticContext<CONTEXT>.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	//----------------------------------------------------------------------------------------
	template <typename FORCONTEXT, typename INDEXTYPE> struct alignas(MAXON_CACHE_LINE_SIZE) ForAlignedContext<FORCONTEXT, INDEXTYPE, Dummy, Dummy> : public FORCONTEXT
	{
		//----------------------------------------------------------------------------------------
		/// @param[in] from								Start index.
		/// @param[in] to									End index (excluded)
		/// @param[in] threadIndex				Initial thread index.
		/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
		//----------------------------------------------------------------------------------------
		ForAlignedContext(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition) : FORCONTEXT(from, to, threadIndex, breakCondition)
		{
		}

		/// No INIT method to be called.
		void Init()
		{
		}

		/// No FINALIZE method to be called.
		void Finalize()
		{
		}
	};


	template <typename USERCONTEXT, typename INDEXTYPE> struct StaticContext;
	template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE> class StaticJob;

	template <typename USERCONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename INIT, typename FINALIZE> struct alignas(MAXON_CACHE_LINE_SIZE) ForState;
	template <typename USERCONTEXT, typename INDEXTYPE> struct DynamicContext;
	template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE> class DynamicJob;
};

/// @cond IGNORE

//----------------------------------------------------------------------------------------
/// Helper template for lambdas without return value and without context.
//----------------------------------------------------------------------------------------
template <> class ParallelFor::NoContextSelector<void>
{
public:
	using Context = ParallelFor::NoContext;
};

//----------------------------------------------------------------------------------------
/// InvokeSelector is a helper class to call init, loop or finalize object which might
/// either return void or Result<void>.
/// @tparam CONTEXT								Type of context super class.
/// @tparam RESULTVALUETYPE				Type of result value (either Result<void> or void).
//----------------------------------------------------------------------------------------
template <typename CONTEXT, typename RESULTVALUETYPE> class ParallelFor::InvokeSelector
{
public:
	//----------------------------------------------------------------------------------------
	/// Invokes the initialization object.
	/// @param[in] obj								Reference to initialization object.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(CONTEXT&) for initialization.
	//----------------------------------------------------------------------------------------
	template <typename FN> static void Init(FN& obj, CONTEXT& self)
	{
		static_assert(AlwaysFalse<FN>::value, "The init lambda must either return void or Result<void>.");
	}

	//----------------------------------------------------------------------------------------
	/// Invokes the loop body object.
	/// @param[in] obj								Reference to loop body object.
	/// @param[in] i									Index.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename INDEXTYPE> static void Loop(FN& obj, INDEXTYPE i, CONTEXT& self)
	{
		static_assert(AlwaysFalse<FN>::value, "The loop lambda must either return void or Result<void>.");
	}

	//----------------------------------------------------------------------------------------
	/// Invokes the finalization object.
	/// @param[in] obj								Reference to finalization object.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(CONTEXT&) for finalization.
	//----------------------------------------------------------------------------------------
	template <typename FN> static void Finalize(FN& obj, CONTEXT& self)
	{
		static_assert(AlwaysFalse<FN>::value, "The finalize lambda must return void.");
	}
};

//----------------------------------------------------------------------------------------
/// Helper template for lambdas with Result<void> and with context.
//----------------------------------------------------------------------------------------
template <typename CONTEXT> class ParallelFor::InvokeSelector<CONTEXT, Result<void>>
{
public:
	//----------------------------------------------------------------------------------------
	/// Invokes the initialization object.
	/// @param[in] obj								Reference to initialization object.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(CONTEXT&) for initialization.
	//----------------------------------------------------------------------------------------
	template <typename FN> static void Init(FN& obj, CONTEXT& self)
	{
		iferr (obj(self))
			self.Break(err);
	}

	//----------------------------------------------------------------------------------------
	/// Invokes the loop body object.
	/// @param[in] obj								Reference to loop body object.
	/// @param[in] i									Index.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename INDEXTYPE> static void Loop(FN& obj, INDEXTYPE i, CONTEXT& self)
	{
		iferr (obj(i, self))
			self.Break(err);
	}

	//----------------------------------------------------------------------------------------
	/// Invokes the finalization object.
	/// @param[in] obj								Reference to finalization object.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(CONTEXT&) for finalization.
	//----------------------------------------------------------------------------------------
	template <typename FN> static void Finalize(FN& obj, CONTEXT& self)
	{
		static_assert(AlwaysFalse<FN>::value, "The finalize lambda must return void.");
	}
};

//----------------------------------------------------------------------------------------
/// Helper template for lambdas without result and with context.
//----------------------------------------------------------------------------------------
template <typename CONTEXT> class ParallelFor::InvokeSelector<CONTEXT, void>
{
public:
		//----------------------------------------------------------------------------------------
		/// Invokes the initialization object.
		/// @param[in] obj								Reference to initialization object.
		/// @param[in] self								Context reference.
		/// @tparam FN										A class containing an operator ()(CONTEXT&) for initialization.
		//----------------------------------------------------------------------------------------
		template <typename FN> static void Init(FN& obj, CONTEXT& self)
		{
			obj(self);
		}

	//----------------------------------------------------------------------------------------
	/// Invokes the loop body object.
	/// @param[in] obj								Reference to loop body object.
	/// @param[in] i									Index.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(INDEXTYPE) used for the loop.
	/// @tparam INDEXTYPE							An integral type used for the index of the loop.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename INDEXTYPE> static void Loop(FN& obj, INDEXTYPE i, CONTEXT& self)
	{
		obj(i, self);
	}

	//----------------------------------------------------------------------------------------
	/// Invokes the finalization object.
	/// @param[in] obj								Reference to finalization object.
	/// @param[in] self								Context reference.
	/// @tparam FN										A class containing an operator ()(CONTEXT&) for finalization.
	//----------------------------------------------------------------------------------------
	template <typename FN> static void Finalize(FN& obj, CONTEXT& self)
	{
		obj(self);
	}
};

/// @endcond

/// @}

#if defined(MAXON_COMPILER_MSVC)
	#pragma warning(pop)
#endif

} // namespace maxon

#include "parallelforstatic.h"
#include "parallelfordynamic.h"

#endif // PARALLELFOR_H__

