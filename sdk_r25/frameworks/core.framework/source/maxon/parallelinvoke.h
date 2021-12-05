#ifndef PARALLELINVOKE_H__
#define PARALLELINVOKE_H__

#include "maxon/jobgroup.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

/// @cond IGNORE

namespace details
{

class ParallelInvokeBaseJob : public JobInterface
{
public:
	explicit ParallelInvokeBaseJob(const JobInterfaceJumpTablePOD& jmpTable) : JobInterface(jmpTable) { }
	explicit ParallelInvokeBaseJob(void* obj, const JobInterfaceJumpTablePOD& jmpTable) : JobInterface(jmpTable), _obj(obj)
	{
	}

	Result<void> operator ()() { DebugStop(); return IllegalStateError(MAXON_SOURCE_LOCATION); }
protected:
	void* _obj;
};

template <typename T, typename RESULT> class ParallelInvokeJobWithResult : public ParallelInvokeBaseJob
{
public:
	explicit ParallelInvokeJobWithResult(T&& obj, const JobInterfaceJumpTablePOD& jmpTable) : ParallelInvokeBaseJob((void*) &obj, jmpTable)
	{
	}

	static Result<void> Invoke(const T& obj)
	{
		return obj();
	}
};

template <typename T> class ParallelInvokeJobWithResult<T, void> : public ParallelInvokeBaseJob
{
public:
	explicit ParallelInvokeJobWithResult(T&& obj, const JobInterfaceJumpTablePOD& jmpTable) : ParallelInvokeBaseJob(&obj, jmpTable)
	{
	}

	static Result<void> Invoke(const T& obj)
	{
		obj();
		return OK;
	}
};

template <typename T> class ParallelInvokeJob : public ParallelInvokeJobWithResult<T, typename std::result_of<typename std::remove_reference<T>::type()>::type>
{
	using Super = ParallelInvokeJobWithResult<T, typename std::result_of<typename std::remove_reference<T>::type()>::type>;
public:
	explicit ParallelInvokeJob(T&& obj) : Super(std::forward<T>(obj), JobInterface::GetJumpTable<ParallelInvokeJob<T>>())
	{
		static_assert(sizeof(ParallelInvokeJob) == sizeof(ParallelInvokeBaseJob), "ParallelInvokeBaseJob size mismatch");
	}

	Result<void> operator ()()
	{
		return Super::Invoke(*(T*) this->_obj);
	}
};

template <typename... ARGS> class ParallelExecution
{
public:
	//----------------------------------------------------------------------------------------
	/// Executes multiple functions in parallel and waits until they have finished.
	/// The parallel flag should be used for recursive code and set to false once the work
	/// item size is so small it wouldn't make sense to parallelize it any further.
	/// Please note that using ParallelInvoke() to parallelize a recursive algorithm is handy
	/// but will never perform as good as using a parallelized non-recursive algorithm because
	/// of the required synchronization at each recursion level.
	/// Execution of the parallel code is guaranteed - even under low memory conditions. If the lambdas do not return Result<void> the routine will return OK.
	/// @param[in] parallel						True for parallel execution, false if amount of work has become very small.
	/// @param[in] args								Callable objects, usually lambdas.
	/// @tparam INDICES								Indices for the job array from 0 to number of arguments - 1.
	/// @return												OK on success. Will only return an error if a lambda returns one via Result<void>.
	/// 															Please note that you'll receive an AggregatedError here that contains the errors created in the lambda and not the errors directly.
	//----------------------------------------------------------------------------------------
	template <size_t... INDICES> static inline Result<void> Invoke(Bool parallel, ARGS&&... args, const std::index_sequence<INDICES...>&)
	{
		if (MAXON_LIKELY(parallel))
		{
			// ParallelInvokeBaseJob is a placeholder for ParallelInvokeJob<argN_type>
			auto group = StaticJobGroupRef<ParallelInvokeBaseJob>::Create(sizeof...(ARGS), STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS).GetValue();

			if (MAXON_LIKELY(group != nullptr))
			{
				StaticJobArray<ParallelInvokeBaseJob> jobs(group, STATICJOBARRAYFLAGS::INITIALIZE_LATER);

				// Call ConstructJob for each argument.
				ForEach{ConstructJob(jobs[INDICES], std::forward<ARGS>(args))...};

				group->Add(jobs);
				return group->EnqueueAndWait();
			}
		}

		// Invoke the lambdas sequentially.
		Error err;
		ForEach{InvokeJob(std::forward<ARGS>(args), err)...};

		return err;
	}

private:
	template <typename ARG> static Int ConstructJob(ParallelInvokeBaseJob& job, ARG&& arg)
	{
		new (&job) ParallelInvokeJob<ARG>(std::forward<ARG>(arg));
		return 0;
	}

	template <typename ARG> static Int InvokeJob(ARG&& arg, Error& out)
	{
		if (out == nullptr)
		{
			iferr (ParallelInvokeJob<ARG>::Invoke(std::forward<ARG>(arg)))
			{
				out = err;
				return 1;
			}
		}
		return 0;
	}
};

}
/// @endcond

//----------------------------------------------------------------------------------------
/// Executes multiple functions in parallel and waits until they have finished.
/// The parallel flag should be used for recursive code and set to false once the work
/// item size is so small it wouldn't make sense to parallelize it any further.
/// Please note that using ParallelInvoke() to parallelize a recursive algorithm is handy
/// but will never perform as good as using a parallelized non-recursive algorithm because
/// of the required synchronization at each recursion level.
/// Execution of the parallel code is guaranteed - even under low memory conditions. If the lambdas do not return Result<void> the routine will return OK.
/// @param[in] parallel						True for parallel execution, false if amount of work has become very small.
/// @param[in] args								Callable objects, usually lambdas.
/// @tparam ARGS									Parameter types.
/// @return												OK on success. Will only return an error if a lambda returns one via Result<void>.
/// 															Please note that you'll receive an AggregatedError here that contains the errors created in the lambda and not the errors directly.
//----------------------------------------------------------------------------------------
template <typename... ARGS> inline Result<void> ParallelInvoke(Bool parallel, ARGS&&... args)
{
	std::make_index_sequence<sizeof...(ARGS)> indices;

	return maxon::details::ParallelExecution<ARGS...>::Invoke(parallel, std::forward<ARGS>(args)..., indices);
}

/// @}

} // namespace maxon

#endif // PARALLELINVOKE_H__
