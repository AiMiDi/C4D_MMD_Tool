#ifndef PARALLELFORSTATIC_H__
#define PARALLELFORSTATIC_H__

#ifndef PARALLELFOR_H__
	#error "You must include parallelfor.h"
#endif

namespace maxon
{

/// @cond IGNORE

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
public:
	using JobContext = ForAlignedContext<StaticContext<CONTEXT, INDEXTYPE>, INDEXTYPE, INIT, FINALIZE>;

	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] threadIndex				Initial thread index.
	/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	//----------------------------------------------------------------------------------------
	StaticJob(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition, const LOOP& obj) : ParallelFor::ParallelForJob(GetJumpTable<StaticJob, false>()), _obj(obj)
	{
		new (_localContextBuffer) JobContext(from, to, threadIndex, breakCondition);
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
	StaticJob(INDEXTYPE from, INDEXTYPE to, Int threadIndex, BreakCondition* breakCondition, const LOOP& obj, const INIT& init, const FINALIZE& finalize) : ParallelFor::ParallelForJob(GetJumpTable<StaticJob, false>()), _obj(obj)
	{
		JobContext& localContext = *new (_localContextBuffer) JobContext(from, to, threadIndex, breakCondition, init, finalize);

		// synchronous init?
		if constexpr (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC)
			localContext.Init();
	}

	~StaticJob()
	{
		// For threaded finalizer the context is destructed on the thread, for the synchronized case the SingleThreadedFinalizer has to destruct them.
		if constexpr (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED)
			GetContext().~JobContext();
	}

	Result<void> operator ()()
	{
		JobContext& localContext = GetContext();

		// Update the worker thread index of the context.
		localContext.UpdateWorkerThreadIndex();

			// Optional threaded initialization.
		if constexpr ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC))
			localContext.Init();

		for (INDEXTYPE i = INDEXTYPE(localContext._from); i < INDEXTYPE(localContext._to); i++)
		{
			// This will be removed by the compiler if context is not derived from BreakContext.
			if (MAXON_UNLIKELY(localContext.IsCancelled() == true))
				break;

			localContext.template Invoke<const LOOP, CONTEXT, INDEXTYPE>(_obj, i);
		}

		// Optional threaded finalization.
		if constexpr ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED))	// threaded finalize?
			localContext.Finalize();

		return localContext._result;
	}

	/// Returns the worker's local context.
	JobContext& GetContext()
	{
		return *reinterpret_cast<JobContext*>(_localContextBuffer);
	}

private:
	const LOOP& _obj;
	alignas(alignof(JobContext)) Char	_localContextBuffer[SIZEOF(JobContext)];
};

//----------------------------------------------------------------------------------------
/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] granularity				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
/// @param[in] queue							Optional queue that the parallel for is executed within.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, BreakContext&) used for the loop.
/// @return												Depending on the type of #LOOP and #CONTEXT either void or Result<void> (OK on success. Will only return an error if your loop object returns one).
/// 															Any errors will be returned as an AggregatedError which you can iterate to check for individual errors.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
	typename CONTEXT::ResultValueType ParallelFor::Static(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		using Worker = StaticJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker)];
		BreakCondition breakCondition;

		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | STATICJOBGROUPFLAGS::NO_JOB_DESTRUCTOR).UncheckedGetValue();
		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, granularity.value);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);

		for (Worker& job : jobs)
		{
			// Make sure the last chunk has the right size.
			if (threadCnt-- == 1)
				chunkSize = to - from;

			new (&job) Worker(from, from + chunkSize, InvalidArrayIndex, &breakCondition, obj);
			from += chunkSize;
		}

		// Enqueue if more than one thread is to be used, otherwise run loop on the current thread.
		if (MAXON_LIKELY(jobs.GetCount() > 1))
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
/// Runs a parallelized for (i = from; i < to; i++) loop using static distribution.
/// @note CONTEXT must be derived from BreakContext (NoContextWithResult)
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] observeForCancellation	When this job is cancelled the for loop will be cancelled and return with OperationCancelledError.
/// @param[in] granularity				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
/// @param[in] queue							Optional queue that the parallel for is executed within.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, BreakContext&) used for the loop.
/// @return												OK on success or an error (on cancellation).  Any errors might be returned as an AggregatedError which you can iterate to check for individual errors.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
	Result<void> ParallelFor::Static(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, JobStatusInterface* observeForCancellation, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		using Worker = StaticJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker)];
		BreakCondition breakCondition;
		JobRef observer;
		JobRef tmp = reinterpret_cast<JobInterface*>(observeForCancellation);
		
		if (MAXON_LIKELY(observeForCancellation))
		{
			auto obs = [&breakCondition](){ breakCondition._value.StoreRelease(true); };
			ifnoerr (observer = maxon::details::CreateCancelledObserver(obs))
			{
				tmp.ObservableCancelled().AddObserver(observer) iferr_ignore("Continue without cancellation");
			}
		}

		// The observer must be deleted before breakCondition goes out of scope
		finally
		{
			tmp.ObservableCancelled().RemoveObserver(observer) iferr_cannot_fail("The observer was successfully added");
		};

		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | STATICJOBGROUPFLAGS::NO_JOB_DESTRUCTOR).UncheckedGetValue();
		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, granularity.value);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);

		for (Worker& job : jobs)
		{
			// Make sure the last chunk has the right size.
			if (threadCnt-- == 1)
				chunkSize = to - from;

			new (&job) Worker(from, from + chunkSize, InvalidArrayIndex, &breakCondition, obj);
			from += chunkSize;
		}

		// Enqueue if more than one thread is to be used, otherwise run loop on the current thread.
		if (MAXON_LIKELY(jobs.GetCount() > 1))
		{
			group->Add(jobs);
			iferr (group->EnqueueAndWait(queue))
				return err;
		}
		else
		{
			iferr (CONTEXT::Return(jobs[0]()))
				return err;
		}
		// Return OperationCancelledError if the loop was left early due to the observed job being cancelled.
		if (breakCondition._value.LoadAcquire())
			return OperationCancelledError(MAXON_SOURCE_LOCATION);
	}
	return OK;
}


//----------------------------------------------------------------------------------------
/// Runs a complex parallelized for (i = from; i < to; i++) loop using static distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] init								Lambda being called before the loop starts (threaded by default)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] finalize						Lambda being called after the loop has finished (synchronously by default)
/// @param[in] granularity				Minimum number of loops that one thread should handle (default is PARALLELFOR_DEFAULTGRANULARITY)
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
	typename CONTEXT::ResultValueType ParallelFor::Static(FROMTYPE tfrom, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		constexpr const Bool USE_SINGLE_THREADED_FINALIZER = FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC;
		using Worker = StaticJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker)];
		BreakCondition breakCondition;

		// Can't use NO_JOB_DESTRUCTOR because the CONTEXT might require destruction.
		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | (USE_SINGLE_THREADED_FINALIZER ? STATICJOBGROUPFLAGS::WILL_RUN_FINALIZER : STATICJOBGROUPFLAGS::DEFAULT)).UncheckedGetValue();
		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, granularity.value);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);
		Int threadIdx = 0;
		for (Worker& job : jobs)
		{
			// Make sure the last chunk has the right size.
			if (threadIdx == threadCnt - 1)
				chunkSize = to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, &breakCondition, obj, init, finalize);
			from += chunkSize;
		}

		// If a single-threaded finalize has been requested construct the data to run the finalizers after EnqueueAndWait().
		SingleThreadedFinalize<Worker, USE_SINGLE_THREADED_FINALIZER> singleThreaded(jobs);

		// Enqueue if more than one thread is to be used, otherwise run loop on the current thread.
		if (MAXON_LIKELY(jobs.GetCount() > 1))
		{
			group->Add(jobs);
			iferr (group->EnqueueAndWait(queue))
				return CONTEXT::Return(err);
		}
		else
		{
			iferr (jobs[0]())
				return CONTEXT::Return(err);
		}

		// Optionally run single-threaded finalizer.
		singleThreaded.Finalize();
	}
	return CONTEXT::Return(OK);
}

/// @endcond


/// @}

} // namespace maxon



#endif // PARALLELFORSTATIC_H__
