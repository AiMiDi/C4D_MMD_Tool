#ifndef PARALLELFORDYNAMIC_H__
#define PARALLELFORDYNAMIC_H__

#ifndef PARALLELFOR_H__
	#error "You must include parallelfor.h"
#endif

namespace maxon
{

/// @cond IGNORE

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

	Bool ReserveInitialChunk(const Int chunkSize, INDEXTYPE& i, INDEXTYPE& toChunk)
	{
		INDEXTYPE to = INDEXTYPE(USERCONTEXT::_to);
		INDEXTYPE from = INDEXTYPE(USERCONTEXT::_from);

		if ((INDEXTYPE)_i.LoadRelaxed() >= to)
			return false;

		// To make sure i + chunkSize does not overflow (as long as _i has not overflown) the chunkSize will be 1 if _to is in a critical range.
		i = (INDEXTYPE) _i.SwapAdd(chunkSize);
		toChunk = MAXON_UNLIKELY(to - chunkSize < i) ? to : INDEXTYPE(i + chunkSize);

		// Return if there was an overflow due to concurrent SwapAdds (can happen if to + jobCnt * chunkSize are
		// bigger than LIMIT<INDEXTYPE>::MAX).
		// The comparison against from does work to detect an overflow because this cannot be LIMIT<INDEXTYPE>::MIN
		// if more than one thread is being used (and if there's only one thread there can be no overflow).
		if (MAXON_UNLIKELY(i < from))
			return false;

		if (MAXON_UNLIKELY(i >= toChunk))
			return false;

		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Iterates over the range specified in this context (which might belong to a different thread).
	/// @param[in] localContext				Context of the current thread, might differ from *this if a range is shared between different threads.
	/// @param[in] chunkSize					The number of iterations after which an atomic add on the potentially shared index is made.
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	/// @param[in] i									Index to start with for the first chunk.
	/// @param[in] toChunk						Index to end with for the first chunk.
	/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, USERCONTEXT&) used for the loop.
	/// @return												The number of iterations performed by the loop.
	//----------------------------------------------------------------------------------------
	template <typename LOOP> UInt LocalLoop(DynamicContext<USERCONTEXT, INDEXTYPE>& localContext, Int chunkSize, INDEXTYPE i, INDEXTYPE toChunk, const LOOP& obj)
	{
		UInt done = 0;
		const INDEXTYPE from = INDEXTYPE(USERCONTEXT::_from);
		const INDEXTYPE to = INDEXTYPE(USERCONTEXT::_to);
		const INDEXTYPE lastChunkStart = INDEXTYPE(to - chunkSize);

		chunkSize = toChunk - i;
		do
		{
			do
			{
				// This will be removed by the compiler if the context is not derived from BreakContext.
				if (MAXON_UNLIKELY(localContext.IsCancelled() == true))
				{
					done += UInt(toChunk - i);
					return done;
				}

				localContext.template Invoke<const LOOP, USERCONTEXT>(obj, i);
			} while (++i < toChunk);

			// Get the start index for the next chunk. Multiple threads might try to help this one with its local loop, therefore _i can exceed _to or even overflow.
			i = (INDEXTYPE) _i.SwapAdd(chunkSize);

			// Increase the number of performed iterations. 
			done += UInt(chunkSize);

			// This is the end index for the next chunk (unlesss there is an overflow or this is the last chunk).
			toChunk = INDEXTYPE(i + chunkSize);

			// The last chunk might be smaller than chunkSize, therefore limit toChunk. 
			if (MAXON_UNLIKELY(i > lastChunkStart))
			{
				toChunk = INDEXTYPE(lastChunkStart + chunkSize);
				chunkSize = toChunk - i;
				if (i >= toChunk) // INDEXTYPE(USERCONTEXT::_to))
					break;	
			}

			// Exit if there was an overflow due to concurrent SwapAdds (can happen if to + jobCnt * chunkSize are
			// bigger than LIMIT<INDEXTYPE>::MAX).
			// The comparison against from does work to detect an overflow because this cannot be LIMIT<INDEXTYPE>::MIN
			// if more than one thread is being used (and if there's only one thread there can be no overflow).
		} while (MAXON_LIKELY(i > from));

		return done;
	}

private:
	DynamicContext();

private:
	alignas(MAXON_FALSE_SHARING_SIZE) AtomicInt _i;
};

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
template <typename USERCONTEXT, PARALLELFORFLAGS FLAGS, typename INDEXTYPE, typename INIT, typename FINALIZE, typename WORKERJOB> struct alignas(MAXON_FALSE_SHARING_SIZE) ParallelFor::ForState
{
	using JobContext = ForAlignedContext<DynamicContext<USERCONTEXT, INDEXTYPE>, INDEXTYPE, INIT, FINALIZE>;

	ForState(WORKERJOB* jobs, Int contextCnt, INDEXTYPE from, INDEXTYPE to, const WorkerThreadPartitions& partitions) :
		_iterationCnt(UInt(to - from)),
		_contextCnt(contextCnt),
		_contexts(jobs),
		_partitions(partitions)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the context for a worker index.
	/// @param[in] threadIdx					Worker/context index.
	/// @return												Local context.
	//----------------------------------------------------------------------------------------
	JobContext& GetContext(Int threadIdx) const
	{
		return _contexts[threadIdx].GetContext();
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
	/// @return												True if the iteration count has become 0, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool UpdateIterationCount(UInt done)
	{
		if (done)
		{
			UInt result = _iterationCnt.SwapAdd(UInt(-Int(done)));
			if (MAXON_UNLIKELY(result <= done))
			{
				CriticalAssert(result == done, "Someone has broken ParallelFor.");
				return true;
			}
		}
		return false;
	}

	BreakCondition& GetBreakCondition()
	{
		return _breakCondition;
	}
	
	Int GetGranularitySize(Int workerThreadIndex) const
	{
		return (workerThreadIndex >= _partitions.firstECoreThreadIndex && workerThreadIndex <= _partitions.lastECoreThreadIndex) ? _partitions.eCoreGranularity : _partitions.pCoreGranularity;
	}

	UInt GetInitialPartitionSize(Int workerThreadIndex) const
	{
		return (workerThreadIndex >= _partitions.firstECoreThreadIndex && workerThreadIndex <= _partitions.lastECoreThreadIndex) ? _partitions.eCorePartitionSize : _partitions.pCorePartitionSize;
	}

public:
	BreakCondition _breakCondition;
	AtomicUInt _iterationCnt;
	const Int _contextCnt;
	WORKERJOB* const _contexts;
	const WorkerThreadPartitions _partitions;

	alignas(MAXON_FALSE_SHARING_SIZE) AtomicInt _threadedInitCnt;
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
	using ForContexts = ForState<CONTEXT, FLAGS, INDEXTYPE, INIT, FINALIZE, DynamicJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>>;
public:
	using JobContext = ForAlignedContext<DynamicContext<CONTEXT, INDEXTYPE>, INDEXTYPE, INIT, FINALIZE>;

	//----------------------------------------------------------------------------------------
	/// @param[in] from								Start index.
	/// @param[in] to									End index (excluded)
	/// @param[in] contextIdx					Index of the context.
	/// @param[in] contexts						Array of per worker thread data (GetCurrentWorkerThreadIndex() is used to pick the right one)
	/// @param[in] obj								Lambda or object with operator (), object will be referenced.
	//----------------------------------------------------------------------------------------
	DynamicJob(INDEXTYPE from, INDEXTYPE to, Int contextIdx, ForContexts& contexts, const LOOP& obj) : ParallelFor::ParallelForJob(GetJumpTable<DynamicJob, false>()), _contexts(contexts), _obj(obj)
	{
		new (_localContextBuffer) JobContext(from, to, contextIdx, &contexts.GetBreakCondition());
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
	DynamicJob(INDEXTYPE from, INDEXTYPE to, Int contextIdx, ForContexts& contexts, const LOOP& obj, const INIT& init, const FINALIZE& finalize) : ParallelFor::ParallelForJob(GetJumpTable<DynamicJob, false>()), _contexts(contexts), _obj(obj)
	{
		JobContext& localContext = *new (_localContextBuffer) JobContext(from, to, contextIdx, &_contexts.GetBreakCondition(), init, finalize);

		// synchronous init?
		if constexpr (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC)
			localContext.Init();
	}

	~DynamicJob()
	{
		// For threaded finalizer the context is destructed on the thread, for the synchronized case the SingleThreadedFinalizer has to destruct them.
		if constexpr (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED)
			GetContext().~JobContext();
	}

	Result<void> operator ()()
	{
		JobContext& localContext = GetContext();
		Bool markAsFinished = false;

		// Update the worker thread index of the context.
		localContext.UpdateWorkerThreadIndex();

		// Do nothing if there's no more work to do and we'd unnecessarily call Init() and Finalize(), perhaps even with a worker thread index that has been used for the finished job.
		if (_contexts.GetCurrentIterationCount() != 0)
		{
			Int contextIdx = localContext._localContextIndex;
			Int chunkSize = _contexts.GetGranularitySize(contextIdx);

			for (Int jobsTodo = _contexts.GetContextCount(); jobsTodo > 0; jobsTodo--, contextIdx++)
			{
				if (_contexts.GetCurrentIterationCount() == 0)
					break;
				if (contextIdx >= _contexts.GetContextCount())
					contextIdx = 0;

				JobContext& currentContext = _contexts.GetContext(contextIdx);
				INDEXTYPE i;
				INDEXTYPE toChunk;
				Bool hasChunk = currentContext.ReserveInitialChunk(chunkSize, i, toChunk);

				if constexpr ((FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED) || (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC))
				{
					// Optional threaded initialization (only once in localContext).
					if (&localContext == &currentContext)
					{
						// Return early if the precalculated partition for this job has already been calculated.
						if (hasChunk == false)
							break;

						localContext.Init();
						if constexpr (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED)
							_contexts._threadedInitCnt.SwapIncrement();						
					}
				}

				if (hasChunk)
				{
					UInt done = currentContext.LocalLoop(localContext, chunkSize, i, toChunk, _obj);
					markAsFinished = _contexts.UpdateIterationCount(done);
					if (markAsFinished)
						break;
				}
			}
		}

		// Copy result before MarkAsFinished might destruct the local context.
		Result<void> result = localContext._result;

		// For INITSYNC_FINALIZETHREADED finalize always because init has already been called.
		if constexpr (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED || FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED)
		{
			if (localContext.Finalize())
			{
				// For INITTHREADED_FINALIZETHREADED finalize only when init has been called.
				if constexpr (FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED)
				{
					_contexts._threadedInitCnt.SwapDecrement();
					if (markAsFinished)
					{
						// 
						while (_contexts._threadedInitCnt.LoadRelaxed() != 0)
							CpuYield::Wait(1);
					}	
				}
			}

			// INITSYNC_FINALIZETHREADED means all finalizers have to run.
			if constexpr (FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED)
				markAsFinished = false;
		}

		// If the count is zero let the group know that the iteration has finished early (some of the other DynamicJobs might not even have been dequeued yet).
		if (MAXON_UNLIKELY(markAsFinished))
		{
			// There might be no group if the job was not enqueued (single-threaded execution).
			JobGroupInterface* group = GetJobGroup();
			if (group)
			{
				// When an error is returned the _breakCondition is set before the job returns with an error. Therefore
				// MarkAsFinished() must not be called because otherwise the EnqueueAndWait() could return with OK before
				// the breaking job has returned its error. The threads are synchronized via the _iterationCnt.SwapAdd()
				// which means the _breakCondition._value can be accessed using a relaxed load.
				if (_contexts._breakCondition._value.LoadRelaxed() == false)
					group->MarkAsFinished();
			}
		}

		return result;
	}

	/// Returns the worker's local context.
	JobContext& GetContext()
	{
		return *reinterpret_cast<JobContext*>(_localContextBuffer);
	}

private:
	ForContexts& _contexts;
	const LOOP& _obj;
	alignas(alignof(JobContext)) Char	_localContextBuffer[SIZEOF(JobContext)];
};

//----------------------------------------------------------------------------------------
/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution. If CONTEXT
/// inherits from BreakContext you can exit the loop by calling context.Break() followed by return.
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
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
	typename CONTEXT::ResultValueType ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		using Worker = DynamicJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		using ForContexts = ForState<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, Dummy, Dummy, Worker>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_FALSE_SHARING_SIZE + SIZEOF(ForContexts)];

		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | STATICJOBGROUPFLAGS::NO_JOB_DESTRUCTOR, SIZEOF(ForContexts)).UncheckedGetValue();
		WorkerThreadPartitions partitions;
		threadCnt = ThreadServices::CalculatePartitions(UInt(to - from), threadCnt, granularity.value, partitions);
		
		StaticJobArray<Worker> jobs(threadCnt, group, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(jobs.GetFirst(), threadCnt, from, to, partitions);

		Int threadIdx = 0;
		for (Worker& job : jobs)
		{
			// Last partition has the remaining size, for the others it depends on P or E core preference.
			INDEXTYPE chunkSize = MAXON_LIKELY(threadIdx != threadCnt - 1) ? INDEXTYPE(contexts.GetInitialPartitionSize(threadIdx)) : to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj);
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
/// Runs a parallelized for (i = from; i < to; i++) loop using dynamic distribution.
/// @note CONTEXT must be derived from BreakContext (NoContextWithResult)
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] observeForCancellation	When this job is cancelled the for loop will be cancelled and return with OperationCancelledError. Can be nullptr (the loop does not automatically check for cancellation).
/// @param[in] granularity				The number of iterations after which a thread shares work with idle threads (1 means best distribution at the cost of higher synchronization, PARALLELFOR_DEFAULTGRANULARITY is the default).
/// @param[in] queue							Optional queue that the parallel for is executed within.
/// @tparam CONTEXT								A class derived from ParallelFor::BaseContext.
/// @tparam FROMTYPE							An integral type used for the from variable, might be different than INDEXTYPE but is not allowed to have a bigger range.
/// @tparam INDEXTYPE							An integral type used for the index of the loop.
/// @tparam LOOP									A class containing an operator ()(INDEXTYPE, CONTEXT&) used for the loop.
/// @return												OK on success or an error (on cancellation).  Any errors might be returned as an AggregatedError which you can iterate to check for individual errors.
//----------------------------------------------------------------------------------------
template <typename CONTEXT, typename FROMTYPE, typename INDEXTYPE, typename LOOP>
	Result<void> ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const LOOP& obj, JobStatusInterface* observeForCancellation, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (MAXON_LIKELY(from < to))
	{
		using Worker = DynamicJob<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, LOOP, Dummy, Dummy>;
		using ForContexts = ForState<CONTEXT, PARALLELFORFLAGS::NOINIT_NOFINALIZE, INDEXTYPE, Dummy, Dummy, Worker>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_FALSE_SHARING_SIZE + SIZEOF(ForContexts)];

		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | STATICJOBGROUPFLAGS::NO_JOB_DESTRUCTOR, SIZEOF(ForContexts)).GetValue();
		WorkerThreadPartitions partitions;
		threadCnt = ThreadServices::CalculatePartitions(UInt(to - from), threadCnt, granularity.value, partitions);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(jobs.GetFirst(), threadCnt, from, to, partitions);

		Int threadIdx = 0;
		for (Worker& job : jobs)
		{
			// Last partition has the remaining size, for the others it depends on P or E core preference.
			INDEXTYPE chunkSize = MAXON_LIKELY(threadIdx != threadCnt - 1) ? INDEXTYPE(contexts.GetInitialPartitionSize(threadIdx)) : to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj);
			from += chunkSize;
		}

		JobRef observer;
		JobRef tmp = reinterpret_cast<JobInterface*>(observeForCancellation);
		
		if (MAXON_LIKELY(observeForCancellation))
		{
			auto obs = [&contexts](){ contexts.GetBreakCondition()._value.StoreRelease(true); };
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
		if (contexts.GetBreakCondition()._value.LoadAcquire())
			return OperationCancelledError(MAXON_SOURCE_LOCATION);
	}
	return OK;
}

//----------------------------------------------------------------------------------------
/// Runs a complex parallelized for (i = from; i < to; i++) loop using dynamic distribution.
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] init								Lambda being called in the thread context before the loop starts.
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] finalize						Lambda being called from the master thread after the loop has finished.
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
	typename CONTEXT::ResultValueType ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (from < to)
	{
		constexpr const Bool USE_SINGLE_THREADED_FINALIZER = FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC;
		using Worker = DynamicJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>;
		using ForContexts = ForState<CONTEXT, FLAGS, INDEXTYPE, INIT, FINALIZE, Worker>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_FALSE_SHARING_SIZE + SIZEOF(ForContexts)];

		// Can't use NO_JOB_DESTRUCTOR because the CONTEXT might require destruction.
		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | (USE_SINGLE_THREADED_FINALIZER ? STATICJOBGROUPFLAGS::WILL_RUN_FINALIZER : STATICJOBGROUPFLAGS::DEFAULT), SIZEOF(ForContexts)).UncheckedGetValue();
		WorkerThreadPartitions partitions;
		threadCnt = ThreadServices::CalculatePartitions(UInt(to - from), threadCnt, granularity.value, partitions);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(jobs.GetFirst(), threadCnt, from, to, partitions);

		Int threadIdx = 0;
		for (Worker& job : jobs)
		{
			// Last partition has the remaining size, for the others it depends on P or E core preference.
			INDEXTYPE chunkSize = MAXON_LIKELY(threadIdx != threadCnt - 1) ? INDEXTYPE(contexts.GetInitialPartitionSize(threadIdx)) : to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj, init, finalize);
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

//----------------------------------------------------------------------------------------
/// Runs a complex parallelized for (i = from; i < to; i++) loop using dynamic distribution.
/// @note CONTEXT must be derived from BreakContext
/// @param[in] tfrom							Start index.
/// @param[in] to									End index (excluded)
/// @param[in] init								Lambda being called in the thread context before the loop starts.
/// @param[in] obj								Lambda or object with operator (), object will be referenced.
/// @param[in] finalize						Lambda being called from the master thread after the loop has finished.
/// @param[in] observeForCancellation	When this job is cancelled the for loop will be cancelled and return with OperationCancelledError. Can be nullptr (the loop does not automatically check for cancellation).
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
	Result<void> ParallelFor::Dynamic(FROMTYPE tfrom, INDEXTYPE to, const INIT& init, const LOOP& obj, const FINALIZE& finalize, JobStatusInterface* observeForCancellation, const Granularity& granularity, JobQueueInterface* queue, Int threadCnt)
{
	static_assert(sizeof(FROMTYPE) <= sizeof(INDEXTYPE), "INDEXTYPE must have same range");
	INDEXTYPE from = INDEXTYPE(tfrom);

	if (from < to)
	{
		constexpr const Bool USE_SINGLE_THREADED_FINALIZER = FLAGS == PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC || FLAGS == PARALLELFORFLAGS::INITSYNC_FINALIZESYNC;
		using Worker = DynamicJob<CONTEXT, FLAGS, INDEXTYPE, LOOP, INIT, FINALIZE>;
		using ForContexts = ForState<CONTEXT, FLAGS, INDEXTYPE, INIT, FINALIZE, Worker>;
		alignas(alignof(Worker)) Char dummy[SIZEOF(Worker) + MAXON_FALSE_SHARING_SIZE + SIZEOF(ForContexts)];

		// Can't use NO_JOB_DESTRUCTOR because the CONTEXT might require destruction.
		StaticJobGroupRef<Worker> group = StaticJobGroupRef<Worker>::Create(queue, threadCnt, STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS | (USE_SINGLE_THREADED_FINALIZER ? STATICJOBGROUPFLAGS::WILL_RUN_FINALIZER : STATICJOBGROUPFLAGS::DEFAULT), SIZEOF(ForContexts)).UncheckedGetValue();
		WorkerThreadPartitions partitions;
		threadCnt = ThreadServices::CalculatePartitions(UInt(to - from), threadCnt, granularity.value, partitions);

		StaticJobArray<Worker> jobs(threadCnt, group, dummy);
		ForContexts& contexts = *new(jobs.PrivateGetExtraBuffer()) ForContexts(jobs.GetFirst(), threadCnt, from, to, partitions);

		Int threadIdx = 0;
		for (Worker& job : jobs)
		{
			// Last partition has the remaining size, for the others it depends on P or E core preference.
			INDEXTYPE chunkSize = MAXON_LIKELY(threadIdx != threadCnt - 1) ? INDEXTYPE(contexts.GetInitialPartitionSize(threadIdx)) : to - from;

			new (&job) Worker(from, from + chunkSize, threadIdx++, contexts, obj, init, finalize);
			from += chunkSize;
		}

		JobRef observer;
		JobRef tmp = reinterpret_cast<JobInterface*>(observeForCancellation);
		
		if (MAXON_LIKELY(observeForCancellation))
		{
			auto obs = [&contexts](){ contexts.GetBreakCondition()._value.StoreRelease(true); };
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
		
		// If a single-threaded finalize has been requested construct the data to run the finalizers after EnqueueAndWait().
		SingleThreadedFinalize<Worker, USE_SINGLE_THREADED_FINALIZER> singleThreaded(jobs);

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
		if (contexts.GetBreakCondition()._value.LoadAcquire())
			return OperationCancelledError(MAXON_SOURCE_LOCATION);

		// Optionally run single-threaded finalizer.
		singleThreaded.Finalize();
	}
	return OK;
}

/// @endcond


/// @}

} // namespace maxon



#endif // PARALLELFORDYNAMIC_H__
