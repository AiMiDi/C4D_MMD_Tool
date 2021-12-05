#ifndef PARALLELFORSTATIC_H__
#define PARALLELFORSTATIC_H__

#ifndef PARALLELFOR_H__
	#error "You must include parallelfor.h"
#endif

namespace maxon
{

/// @cond IGNORE

/// determines, whether parallel for will be evaluated using multiple threads. Can be changed during runtime.
extern Bool	g_enableParallelFor;

//----------------------------------------------------------------------------------------
/// Context for static distribution.
/// @tparam USERCONTEXT						A class derived from BaseContext for thread local data storage.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
//----------------------------------------------------------------------------------------
template <typename USERCONTEXT, typename INDEXTYPE> struct ParallelFor::StaticContext : public USERCONTEXT
{
	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] threadIndex				Initial thread index.
	/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
	//----------------------------------------------------------------------------------------
	StaticContext(INDEXTYPE from, INDEXTYPE to, Int threadIndex, ParallelFor::BreakCondition* breakCondition)
	{
		// USERCONTEXT might not have a constructor forwarding to Context, therefore we use the default constructor and initialize the context manually.
		ParallelFor::BaseContext::PrivateInit(from, to, threadIndex, breakCondition);
	}
};

//----------------------------------------------------------------------------------------
/// Worker job for ParallelFor::Static.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
/// @tparam FLAGS									Flags that specify whether init or finalize will be called threaded or synchronously.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE> class ParallelFor::StaticJob : public ParallelFor::ParallelForJob
{
	using JobContext = ForAlignedContext<StaticContext<CONTEXT, INDEXTYPE>, INDEXTYPE, INIT, FINALIZE>;
public:
	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] threadIndex				Initial thread index.
	/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	//----------------------------------------------------------------------------------------
	StaticJob(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition, const LOOP& obj) : ParallelFor::ParallelForJob(GetJumpTable<StaticJob>()), _context(from, to, threadIndex, breakCondition), _obj(obj)
	{
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] threadIndex				Initial thread index.
	/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] init								Lambda being called in the thread context before the loop starts.
	/// @param[in] finalize						Lambda being called in the thread context after the loop has finished.
	//----------------------------------------------------------------------------------------
	StaticJob(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition, const LOOP& obj, const INIT& init, const FINALIZE& finalize) : ParallelFor::ParallelForJob(GetJumpTable<StaticJob>()), _context(from, to, threadIndex, breakCondition, init, finalize), _obj(obj)
	{
		// synchronous init?
		if ((FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC) || (FLAGS == PARALLELFORFLAGS::INITTHREADEDWITHSYNC_FINALIZESYNC))
			_context.Init();
	}

	Result<void> operator ()()
	{
		// Update the worker thread index of the context.
		_context.UpdateWorkerThreadIndex();

			// Optional threaded initialization.
		if ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC))
			_context.Init();

		for (INDEXTYPE i = INDEXTYPE(_context._from); i < INDEXTYPE(_context._to); i++)
		{
			// This will be removed by the compiler if context is not derived from BreakContext.
			if (MAXON_UNLIKELY(_context.IsCancelled() == true))
				break;

			_context.template Invoke<const LOOP, CONTEXT, INDEXTYPE>(_obj, i);
		}

		// Optional threaded finalization.
		if ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED))	// threaded finalize?
			_context.Finalize();

		return _context._result;
	}

	// Used for INITTHREADEDWITHSYNC only. If there was an error the _result pointer will only be valid until the current job has returned.
	Result<void> GetResult() const
	{
		return _context._result;
	}

private:
	JobContext _context;
	const LOOP& _obj;
};

//----------------------------------------------------------------------------------------
/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] threadCnt					PARALLELFOR_USEMAXIMUMTHREADS for default handling (uses the maximum number of threads available), otherwise maximum number of threads to be used. A value of 1 will disable parallelization.
/// @param[in] minChunkSize				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
/// @param[in] queue							Optional queue that the parallel for is executed within.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, BreakContext&) used for the loop.
/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
	typename CONTEXT::ResultValueType ParallelFor::Static(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, Int threadCnt, const Int minChunkSize, JobQueueInterface* queue)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_UNLIKELY(g_enableParallelFor == false))
		threadCnt = 1;

	if (MAXON_LIKELY(from < to))
	{
		using Worker = StaticJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker)];
		StaticJobGroupRef<Worker> group;
		BreakCondition breakCondition;

		if (threadCnt != 1)
		{
			// Get the suggested number of threads for the queue and the parallel for nesting level.
			Int maxThreadCnt = JobQueueInterface::GetThreadCount(queue, PARALLELFOR_MAXIMUMDEPTH);
			if ((threadCnt == PARALLELFOR_USEMAXIMUMTHREADS) || (maxThreadCnt == 1))
				threadCnt = maxThreadCnt;
		}

		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, minChunkSize);

		// If the group cannot be allocated the loop will run single-threaded (using the dummy object's memory).
		if (MAXON_LIKELY(threadCnt > 1))
		{
			group = StaticJobGroupRef<Worker>::Create(threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS).GetValue();
			if (MAXON_UNLIKELY(group == nullptr))
				threadCnt = 1;
		}

		StaticJobArray<Worker> jobs(group, STATICJOBARRAYFLAGS::INITIALIZE_LATER, dummy);

		for (Worker& job : jobs)
		{
			// Make sure the last chunk has the right size.
			if (threadCnt-- == 1)
				chunkSize = to - from;

			new (&job) Worker(from, from + chunkSize, InvalidArrayIndex, &breakCondition, obj);
			from += chunkSize;
		}

		// The group is only nullptr in the single-threaded case.
		if (MAXON_LIKELY(group != nullptr))
		{
			group->Add(jobs);
			return CONTEXT::Return(group->EnqueueAndWait(queue));
		}
		else
		{
			return CONTEXT::Return(jobs[0]());
		}
	}
	return CONTEXT::Return(OK);
}




//----------------------------------------------------------------------------------------
/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
/// @param[in] tfrom							Start index.
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
	typename CONTEXT::ResultValueType ParallelFor::Static(FROMTYPE tfrom, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt, const Int minChunkSize, JobQueueInterface* queue)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		using Worker = StaticJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>;
		alignas(alignof(Worker)) Char dummyWorker[SIZEOF(Worker)];
		StaticJobGroupRef<Worker> group;
		BreakCondition breakCondition;

		if (MAXON_UNLIKELY(g_enableParallelFor == false))
		{
			threadCnt = 1;
		}
		else if (threadCnt != 1)
		{
			// Get the suggested number of threads for the queue and the parallel for nesting level.
			Int maxThreadCnt = JobQueueInterface::GetThreadCount(queue, PARALLELFOR_MAXIMUMDEPTH);
			if ((threadCnt == PARALLELFOR_USEMAXIMUMTHREADS) || (maxThreadCnt == 1))
				threadCnt = maxThreadCnt;
		}

		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, minChunkSize);

		// If the group cannot be allocated the loop will run single-threaded (using the dummy object's memory).
		if (MAXON_LIKELY(threadCnt > 1))
		{
			group = StaticJobGroupRef<Worker>::Create(threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS).GetValue();
			if (MAXON_UNLIKELY(group == nullptr))
				threadCnt = 1;
		}

		StaticJobArray<Worker> jobs(group, STATICJOBARRAYFLAGS::INITIALIZE_LATER, dummyWorker);

		if (FLAGS == PARALLELFORFLAGS::INITTHREADEDWITHSYNC_FINALIZESYNC)
		{
			AtomicBool initErrorOwner;
			Error initError;

			// Handle special case of running all Init() calls before the loop body is entered. The loop must not return an error because parts of the StaticJobArray would be uninitialized.
			ParallelFor::Dynamic(0, INDEXTYPE(threadCnt),
				[from, to, chunkSize, threadCnt, &jobs, &breakCondition, &obj, &init, &finalize, &initErrorOwner, &initError](INDEXTYPE threadIdx)
				{
					Worker& job = jobs[threadIdx];

					INDEXTYPE start = from + (threadIdx * chunkSize);
					INDEXTYPE end = (threadIdx == threadCnt - 1) ? to : start + chunkSize;

					new (&job) Worker(start, end, threadIdx, &breakCondition, obj, init, finalize);

					// If there is an error during initialization just return the first one.
					iferr (job.GetResult())
					{
						if (initErrorOwner.TryCompareAndSwap(true, false))
							initError = err;
					}
				}, threadCnt, 1, queue);

			if (initError)
				return CONTEXT::Return(initError);
		}
		else
		{
			Int threadIdx = 0;

			for (Worker& job : jobs)
			{
				// Make sure the last chunk has the right size.
				if (threadIdx == threadCnt - 1)
					chunkSize = to - from;

				new (&job) Worker(from, from + chunkSize, threadIdx++, &breakCondition, obj, init, finalize);
				from += chunkSize;
			}
		}

		// The group is only nullptr in the single-threaded case.
		if (group)
		{
			group->Add(jobs);
			return CONTEXT::Return(group->EnqueueAndWait(queue));
		}
		else
		{
			return CONTEXT::Return(jobs[0]());
		}
	}
	return CONTEXT::Return(OK);
}

/// @endcond


/// @}

} // namespace maxon



#endif // PARALLELFORSTATIC_H__
