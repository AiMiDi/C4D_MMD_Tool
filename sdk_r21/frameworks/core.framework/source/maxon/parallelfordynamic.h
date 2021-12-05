#ifndef PARALLELFORDYNAMIC_H__
#define PARALLELFORDYNAMIC_H__

#ifndef PARALLELFOR_H__
	#error "You must include parallelfor.h"
#endif

namespace maxon
{

/// @cond IGNORE

/// determines, whether parallel for will be evaluated using multiple threads. Can be changed during runtime.
extern Bool	g_enableParallelFor;

//----------------------------------------------------------------------------------------
/// Context for dynamic distribution.
/// @tparam USERCONTEXT						A class derived from BaseContext for thread local data storage.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
//----------------------------------------------------------------------------------------
template <typename USERCONTEXT, typename INDEXTYPE> struct ParallelFor::DynamicContext : public USERCONTEXT
{
	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] threadIndex				Initial thread index.
	/// @param[in] breakCondition			Pointer to a BreakCondition or nullptr (break not supported by context).
	//----------------------------------------------------------------------------------------
	DynamicContext(INDEXTYPE from, INDEXTYPE to, Int threadIndex, ParallelFor::BreakCondition* breakCondition) : _i(from)
	{
		// USERCONTEXT might not have a constructor forwarding to Context, therefore we use the default constructor and initialize the context manually
		ParallelFor::BaseContext::PrivateInit(from, to, threadIndex, breakCondition);
	}

	//----------------------------------------------------------------------------------------
	/// Iterates over the range specified in this context (which might belong to a different thread).
	/// @param[in] localContext				Context of the current thread, might differ from *this if a range is shared between different threads.
	/// @param[in] chunkSize					The number of iterations after which an atomic add on the potentially shared index is made.
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, USERCONTEXT&) used for the loop.
	/// @return												The number of iterations performed by the loop.
	//----------------------------------------------------------------------------------------
	template <typename LOOP> UInt LocalLoop(DynamicContext<USERCONTEXT, INDEXTYPE>& localContext, const Int chunkSize, const LOOP& obj)
	{
		UInt done = 0;
		INDEXTYPE from = INDEXTYPE(USERCONTEXT::_from);
		INDEXTYPE to = INDEXTYPE(USERCONTEXT::_to);

		for (INDEXTYPE i = (INDEXTYPE) _i.LoadRelaxed(); i < to; )
		{
			// To make sure i + chunkSize does not overflow (as long as _i has not overflown) the chunkSize will be 1 if _to is in a critical range.
			i = (INDEXTYPE) _i.SwapAdd(chunkSize);
			INDEXTYPE toChunk = Min(to, INDEXTYPE(i + chunkSize));

			// Return if there was an overflow due to concurrent SwapAdds (can happen if to + jobCnt * chunkSize are
			// bigger than LIMIT<INDEXTYPE>::MAX).
			// The comparison against from does work to detect an overflow because this cannot be LIMIT<INDEXTYPE>::MIN
			// if more than one thread is being used (and if there's only one thread there can be no overflow).
			if (MAXON_UNLIKELY(i < from))
				break;

			if (MAXON_UNLIKELY(i >= toChunk))
				break;

			// Increase the number of iterations by the planned chunk size.
			done += UInt(toChunk - i);

			do
			{
				// This will be removed by the compiler if the context is not derived from BreakContext.
				if (MAXON_UNLIKELY(localContext.IsCancelled() == true))
				{
					// Decrease the iteration count because the loop returns early.
					done -= UInt(toChunk - i);
					break;
				}

				localContext.template Invoke<const LOOP, USERCONTEXT>(obj, i);
			} while (++i < toChunk);
		}
		return done;
	}

private:
	DynamicContext();

private:
	alignas(MAXON_CACHE_LINE_SIZE) AtomicInt _i;
};

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
template <typename USERCONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename INIT, typename FINALIZE> struct alignas(MAXON_CACHE_LINE_SIZE) ParallelFor::ForState
{
	using JobContext = ForAlignedContext<DynamicContext<USERCONTEXT, INDEXTYPE>, INDEXTYPE, INIT, FINALIZE>;

	ForState(Int contextCnt, INDEXTYPE from, INDEXTYPE to, const Int chunkSize) :
		_iterationCnt(UInt(to - from)),
		_contextCnt(contextCnt),
		_chunkSize((LIMIT<INDEXTYPE>::MAX - (contextCnt * chunkSize) < to) ? 1 : chunkSize),	// Make sure that _i + _chunkSize does not get bigger than LIMIT<INDEXTYPE>::MAX and overflows.
		_referenceCount(contextCnt)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the size of a ForState object for the specified number of threads/jobs/contexts.
	/// @param[in] contextCnt					Number of contexts (jobs).
	/// @return												Object size in bytes.
	//----------------------------------------------------------------------------------------
	static Int GetSize(Int contextCnt)
	{
		return SIZEOF(ForState) + (contextCnt * SIZEOF(JobContext));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the context for a worker index.
	/// @param[in] threadIdx					Worker/context index.
	/// @return												Local context.
	//----------------------------------------------------------------------------------------
	JobContext& GetContext(Int threadIdx) const
	{
		return ((JobContext*) (this + 1))[threadIdx];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of workers.
	/// @return												Number of workers.
	//----------------------------------------------------------------------------------------
	Int GetContextCount() const
	{
		return _contextCnt;
	}

	//----------------------------------------------------------------------------------------
	/// Removes a worker's reference (called before the worker finished and will call Finalize()
	/// after the last worker has finished).
	//----------------------------------------------------------------------------------------
	void RemoveReference()
	{
		if (_referenceCount.SwapDecrement() == 1)
			this->~ForState();
	}

	//----------------------------------------------------------------------------------------
	/// Returns whether a worker has already finished (which means there is no more work to do for new workers).
	/// @return												True if the worker has already finished.
	//----------------------------------------------------------------------------------------
	Bool HaveJobsFinished() const
	{
		// This is of interest when a job runs on the same worker thread as an already finished one, therefore a relaxed load is sufficient.
		return _referenceCount.LoadRelaxed() != _contextCnt;
	}

	//----------------------------------------------------------------------------------------
	/// Calls Finalize() for the specified context.
	//----------------------------------------------------------------------------------------
	void FinalizeContext(JobContext& localContext)
	{
		localContext.Finalize();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of remaining iterations (does not account for iterations currently being "in flight").
	/// @return												Number of remaining iterations (0 if everything has been processed).
	//----------------------------------------------------------------------------------------
	UInt GetCurrentIterationCount() const
	{
		return _iterationCnt.LoadAcquire();
	}

	//----------------------------------------------------------------------------------------
	/// Updates the number of iterations still to be done (periodically called by the workers).
	/// @param[in] done								Number of iterations performed by the worker.
	/// @param[in] job								The current job.
	//----------------------------------------------------------------------------------------
	void UpdateIterationCount(UInt done, const JobInterface& job)
	{
		if (done)
		{
			UInt result = _iterationCnt.SwapAdd(UInt(-Int(done)));

			if (MAXON_UNLIKELY(result <= done))
			{
				if (result == done)
				{
					if (FLAGS == PARALLELFORFLAGS::NOINIT_NOFINALIZE)
					{
						// Let the group know that the iteration has finished early (some of the other DynamicJobs might not even have been dequeued yet).
						// There might be no group if the job was not enqueued (single-threaded execution).
						JobGroupInterface* group = job.GetJobGroup();
						if (group)
						{
							// When an error is returned the _breakCondition is set before the job returns with an error. Therefore
							// MarkAsFinished() must not be called because otherwise the EnqueueAndWait() could return with OK before
							// the breaking job has returned its error. The threads are synchronized via the _iterationCnt.SwapAdd()
							// which means the _breakCondition._value can be accessed using a relaxed load.
							if (_breakCondition._value.LoadRelaxed() == false)
								group->MarkAsFinished();
						}
					}
				}
				else
				{
					CriticalStop("Someone has broken ParallelFor.");
				}
			}
		}
	}

	BreakCondition& GetBreakCondition()
	{
		return _breakCondition;
	}

protected:
	~ForState()
	{
		for (Int threadIdx = 0; threadIdx < _contextCnt; threadIdx++)
			GetContext(threadIdx).~JobContext();
	}

public:
	BreakCondition _breakCondition;
	AtomicUInt _iterationCnt;
	const Int _contextCnt;
	const Int _chunkSize;
	AtomicInt _referenceCount;
};


//----------------------------------------------------------------------------------------
/// Worker job for ParallelFor::Dynamic.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext for thread local data storage.
/// @tparam FLAGS									Flags that specify whether init or finalize will be called threaded or synchronously.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
/// @tparam INIT									A class containing an operator ()(CONTEXT&) for per-thread initialization before the loop.
/// @tparam FINALIZE							A class containing an operator ()(CONTEXT&) for per-thread cleanup after the loop.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename LOOP, typename INIT, typename FINALIZE> class ParallelFor::DynamicJob : public ParallelFor::ParallelForJob
{
	using ForContexts = ForState<CONTEXT, FLAGS, INDEXTYPE, INIT, FINALIZE>;
	using JobContext = typename ForContexts::JobContext;
public:
	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] contextIdx					Index of the context.
	/// @param[in] contexts						Array of per worker thread data (GetCurrentWorkerThreadIndex() is used to pick the right one)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	//----------------------------------------------------------------------------------------
	DynamicJob(INDEXTYPE from, INDEXTYPE to, Int contextIdx, ForContexts& contexts, const LOOP& obj) : ParallelFor::ParallelForJob(GetJumpTable<DynamicJob>()), _contexts(contexts), _localContext(contexts.GetContext(contextIdx)), _obj(obj)
	{
		new (&_localContext) JobContext(from, to, contextIdx, &_contexts.GetBreakCondition());
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] contextIdx					Index of the context.
	/// @param[in] contexts						Array of per worker thread data (GetCurrentWorkerThreadIndex() is used to pick the right one)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] init								Lambda being called in the thread context before the loop starts.
	/// @param[in] finalize						Lambda being called in the thread context after the loop has finished.
	//----------------------------------------------------------------------------------------
	DynamicJob(INDEXTYPE from, INDEXTYPE to, Int contextIdx, ForContexts& contexts, const LOOP& obj, const INIT& init, const FINALIZE& finalize) : ParallelFor::ParallelForJob(GetJumpTable<DynamicJob>()), _contexts(contexts), _localContext(contexts.GetContext(contextIdx)), _obj(obj)
	{
		new (&_localContext) JobContext(from, to, contextIdx, &_contexts.GetBreakCondition(), init, finalize);

		// synchronous init?
		if ((FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC) || (FLAGS == PARALLELFORFLAGS::INITTHREADEDWITHSYNC_FINALIZESYNC))
			_localContext.Init();
	}

	Result<void> operator ()()
	{
		// Update the worker thread index of the context.
		_localContext.UpdateWorkerThreadIndex();

		// Do nothing if one of the jobs has already exited: This means there's no more work to do and we'd unnecessarily call Init() and Finalize(), perhaps even with a worker thread index that has been used for the finished job.
		if (_contexts.HaveJobsFinished() == false)
		{
			// Optional threaded initialization.
			if ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC))
				_localContext.Init();

			Int contextIdx = _localContext._localContextIndex;
			Int jobsTodo = _contexts.GetContextCount();

			while ((_contexts.GetCurrentIterationCount() != 0) && (jobsTodo > 0))
			{
				JobContext& currentContext = _contexts.GetContext(contextIdx++);

				UInt done = currentContext.LocalLoop(_localContext, _contexts._chunkSize, _obj);
				_contexts.UpdateIterationCount(done, *this);

				if (contextIdx >= _contexts.GetContextCount())
					contextIdx = 0;

				jobsTodo--;
			}

			// Optional threaded finalization.
			if ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED))
				_contexts.FinalizeContext(_localContext);
		}

		// Copy result before RemoveRefernce() might free the local context.
		Result<void> result = _localContext._result;
		_contexts.RemoveReference();
		return result;
	}

	// Used for INITTHREADEDWITHSYNC only. If there was an error the _result pointer will only be valid until the current job has returned.
	Result<void> GetResult() const
	{
		return _localContext._result;
	}

private:
	ForContexts& _contexts;
	JobContext& _localContext;
	const LOOP& _obj;
};

//----------------------------------------------------------------------------------------
/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
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
	typename CONTEXT::ResultValueType ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, Int threadCnt, const Int granularity, JobQueueInterface* queue)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_UNLIKELY(g_enableParallelFor == false))
		threadCnt = 1;

	if (MAXON_LIKELY(from < to))
	{
		using Worker = DynamicJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		using ForContexts = ForState<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, Dummy, Dummy>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_CACHE_LINE_SIZE + SIZEOF(ForContexts) + SIZEOF(typename ForContexts::JobContext)];
		StaticJobGroupRef<Worker> group;

		if (threadCnt != 1)
		{
			// Get the suggested number of threads for the queue and the parallel for nesting level.
			Int maxThreadCnt = JobQueueInterface::GetThreadCount(queue, PARALLELFOR_MAXIMUMDEPTH);
			if ((threadCnt == PARALLELFOR_USEMAXIMUMTHREADS) || (maxThreadCnt == 1))
				threadCnt = maxThreadCnt;
		}

		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, 1);

		// If the group cannot be allocated the loop will run single-threaded (using the dummy object's memory).
		if (MAXON_LIKELY(threadCnt > 1))
		{
			group = StaticJobGroupRef<Worker>::Create(threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS, ForContexts::GetSize(threadCnt)).GetValue();
			if (MAXON_UNLIKELY(group == nullptr))
				threadCnt = 1;
		}
		
		StaticJobArray<Worker> jobs(group, STATICJOBARRAYFLAGS::INITIALIZE_LATER, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(threadCnt, from, to, Min(granularity, Int(chunkSize)));
		Int threadIdx = 0;

		for (Worker& job : jobs)
		{
			// Make sure the last chunk has the right size.
			if (threadIdx == threadCnt - 1)
				chunkSize = to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj);
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
/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution.
/// @param[in] from								Start index.
/// @param[in] to									End index (excluded)
/// @param[in] init								Lambda being called in the thread context before the loop starts.
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] finalize						Lambda being called from the master thread after the loop has finished.
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
	typename CONTEXT::ResultValueType ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, Int threadCnt, const Int granularity, JobQueueInterface* queue)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_UNLIKELY(g_enableParallelFor == false))
		threadCnt = 1;

	if (from < to)
	{
		using Worker = DynamicJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>;
		using ForContexts = ForState<CONTEXT, FLAGS, INDEXTYPE, INIT, FINALIZE>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_CACHE_LINE_SIZE + SIZEOF(ForContexts) + SIZEOF(typename ForContexts::JobContext)];
		StaticJobGroupRef<Worker> group;

		if (threadCnt != 1)
		{
			// Get the suggested number of threads for the queue and the parallel for nesting level.
			Int maxThreadCnt = JobQueueInterface::GetThreadCount(queue, PARALLELFOR_MAXIMUMDEPTH);
			if ((threadCnt == PARALLELFOR_USEMAXIMUMTHREADS) || (maxThreadCnt == 1))
				threadCnt = maxThreadCnt;
		}

		INDEXTYPE chunkSize = CalculateStaticChunkSize<INDEXTYPE>(UInt(to - from), threadCnt, 1);

		// If the group cannot be allocated the loop will run single-threaded (using the dummy object's memory).
		if (MAXON_LIKELY(threadCnt > 1))
		{
			group = StaticJobGroupRef<Worker>::Create(threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS, ForContexts::GetSize(threadCnt)).GetValue();
			if (MAXON_UNLIKELY(group == nullptr))
				threadCnt = 1;
		}

		StaticJobArray<Worker> jobs(group, STATICJOBARRAYFLAGS::INITIALIZE_LATER, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(threadCnt, from, to, Min(granularity, Int(chunkSize)));

		if (FLAGS == PARALLELFORFLAGS::INITTHREADEDWITHSYNC_FINALIZESYNC)
		{
			AtomicBool initErrorOwner;
			Error initError;

			// Handle special case of running all Init() calls before the loop body is entered. The loop must not return an error because parts of the StaticJobArray would be uninitialized.
			ParallelFor::Dynamic(0, INDEXTYPE(threadCnt),
				[from, to, chunkSize, threadCnt, &contexts, &jobs, &obj, &init, &finalize, &initErrorOwner, &initError](INDEXTYPE threadIdx)
				{
					Worker& job = jobs[threadIdx];

					INDEXTYPE start = from + (threadIdx * chunkSize);
					INDEXTYPE end = (Int(threadIdx) == threadCnt - 1) ? to : start + chunkSize;

					new (&job) Worker(start, end, threadIdx, contexts, obj, init, finalize);

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

				new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj, init, finalize);
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



#endif // PARALLELFORDYNAMIC_H__
