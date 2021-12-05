#ifdef PRIVATE_MAXON_REGISTRATION_UNIT
#include "maxon/job.h"
#endif

#ifndef CLOSUREJOB_H__
#define CLOSUREJOB_H__

#ifndef JOB_H__
	#error "Do not include this file directly"
#endif

namespace maxon
{

/// @cond IGNORE

/// Error handling when a job is cancelled before its worker was called (for Create()/Enqueue() with a lambda).
enum class JOBCANCELLATION
{
	AUTOMATIC,						///< If a lambda does not return anything early cancellation is not an error, if it has a return value it is considered an error.
	ISOK,									///< If a lambda returns nothing or Result<void> early cancellation is not an error.
	ISERROR,							///< Early cancellation is always an error.
	KEEP_RUNNING_ON_EXIT	///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded. Early cancellation of the job will return an error.
} MAXON_ENUM_LIST(JOBCANCELLATION);

using THREADCANCELLATION = JOBCANCELLATION;

template <typename IMPLEMENTATION, typename FN, JOBCANCELLATION CANCELISERROR, typename RESULT, typename... ARGS> class ClosureJobTemplate : public JobInterfaceTemplate<IMPLEMENTATION, RESULT>
{
public:
	explicit ClosureJobTemplate(FN&& src, ARGS&&... args) : _obj(std::forward<FN>(src)), _members(std::forward<ARGS>(args)...)
	{
	}

	Result<void> operator ()()
	{
		std::make_index_sequence<sizeof...(ARGS)> indices;

		return Invoke(indices);
	}

	const Char* GetName() const
	{
		return "ClosureJob";
	}

	JOBOPTIONFLAGS GetJobOptions() const
	{
		JOBOPTIONFLAGS options = JOBOPTIONFLAGS::DEFAULT;
		
		if (std::is_same<RESULT, void>::value)
		{
			// The lambda does not return anything. Therefore early cancellation cannot prevent it from returning an error.
			// It is only considered an error when the user explicitely requests it.
			if (CANCELISERROR == JOBCANCELLATION::ISERROR)
				options = JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR;
		}
		else if (std::is_same<RESULT, Result<void>>::value)
		{
			// Early cancellation could prevent the lambda from returning an error. On the other hand the lambda could be fine with early
			// cancellation. This is ambiguous and in automatic mode we consider early cancellation an error. You can choose a different
			// behaviour by specifying it upon Create/Enqueue of the lambda.
			if (CANCELISERROR != JOBCANCELLATION::ISOK)
				options = JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR;
		}
		else
		{
			// Early cancellation would prevent the lambda from returning a valid value. Therefore it is always
			// considered an error (even explicitely choosing a different option at enqueue does not change this).
			options = JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR;
		}

		if (CANCELISERROR == JOBCANCELLATION::KEEP_RUNNING_ON_EXIT)
			options = JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR | JOBOPTIONFLAGS::KEEP_RUNNING_ON_EXIT;

		return options;
	}

protected:
	template <size_t... INDICES> inline Result<void> Invoke(const std::index_sequence<INDICES ...>&)
	{
		return JobResultInterface<RESULT>::Invoke(_obj, TupleGet<INDICES>(std::move(_members))...);
	}

private:
	typename std::decay<FN>::type _obj;
	Tuple<typename std::decay<ARGS>::type...> _members;
};

template <typename FN, JOBCANCELLATION CANCELISERROR, typename RESULT, typename... ARGS> class ClosureJob : public ClosureJobTemplate<ClosureJob<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>
{
public:
	explicit ClosureJob(FN&& src, ARGS&&... args) : ClosureJobTemplate<ClosureJob<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>(std::forward<FN>(src), std::forward<ARGS>(args)...)
	{
	}
};


/// This implementation supports CancelAndWait() which will only wait if the job is already in execution at the cost of an extra atomic operation in the hot code path.
template <typename FN, JOBCANCELLATION CANCELISERROR, typename RESULT, typename... ARGS> class ClosureJobWithConfirmedCancellation : public ClosureJobTemplate<ClosureJobWithConfirmedCancellation<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>
{
	using Super = ClosureJobTemplate<ClosureJobWithConfirmedCancellation<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>;
public:
	explicit ClosureJobWithConfirmedCancellation(FN&& src, ARGS&&... args) : Super(std::forward<FN>(src), std::forward<ARGS>(args)...)
	{
	}
	
	Result<void> operator ()()
	{
		// If the AtomicBool is already set it means that CancelAndWait() was called just after the internal cancellation and before the worker was invoked.
		// In this case return immediately (the job result will most likely be ignored because it was cancelled due to some other reason).
		if (_isInExecution.TryCompareAndSwap(true, false) == false)
			return ThreadCancelledError(MAXON_SOURCE_LOCATION);
			
		return Super::operator ()();
	}
	
	/// This specific implementation of CancelAndWait() will only wait if the job is already in execution.
	void CancelAndWait()
	{
		this->Cancel();
		
		// Check if the job is already in execution and wait for it only if necessary.
		if (_isInExecution.TryCompareAndSwap(true, false) == false)
			this->Wait();
	}
	
private:
	AtomicBool _isInExecution;
};

/// This implementation allows to associate a job to a specific dependency group (for example the UI dependency group to avoid recursive redraws).
template <typename FN, JOBCANCELLATION CANCELISERROR, typename RESULT, typename... ARGS> class ClosureJobWithDependency : public ClosureJobTemplate<ClosureJobWithDependency<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>
{
public:
	explicit ClosureJobWithDependency(FN&& src, const JobDependencyGroupInterface* dependencyGroup, ARGS&&... args) : ClosureJobTemplate<ClosureJobWithDependency<FN, CANCELISERROR, RESULT, ARGS...>, FN, CANCELISERROR, RESULT, ARGS...>(std::forward<FN>(src), std::forward<ARGS>(args)...), _dependencyGroup(dependencyGroup)
	{
	}

	const JobDependencyGroupInterface* GetDependencyGroup() const
	{
		return _dependencyGroup;
	}
private:
	const JobDependencyGroupInterface* _dependencyGroup;
};

/// @endcond

}

#endif // CLOSUREJOB_H__
