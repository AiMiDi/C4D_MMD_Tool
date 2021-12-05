#ifndef THREADSERVICESPODS_H__
#define THREADSERVICESPODS_H__

#include "maxon/apibase.h"
#include "maxon/defaultallocator.h"

namespace maxon
{

/// @cond INTERNAL
class JobInterface;
class JobDependencyGroupInterface;
class CoreJob;

enum class JOBOPTIONFLAGS : Int
{
	DEFAULT = 0,												///< Default behaviour: Early job cancellation (before the worker method has been executed) will return OK.
	EARLY_CANCELLATION_IS_AN_ERROR = 1,	///< Early job cancellation (before the worker method has been executed) will return an error.
	KEEP_RUNNING_ON_EXIT = 2						///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded.
} MAXON_ENUM_FLAGS(JOBOPTIONFLAGS);

using DestructWorkerPtr = void* (*)(const JobInterface* self);
using RunWorkerPtr = const ErrorInterface* (*)(const JobInterface* self);
using GetWorkerOptionsPtr = void* (*)(const JobInterface* self, Int selector, void* param);
using GetWorkerDependencyGroupPtr = const JobDependencyGroupInterface* (*)(const JobInterface* self);

struct JobInterfaceJumpTablePOD
{
	DestructWorkerPtr		_destructWorker;											///< Pointer to the destructor.
	RunWorkerPtr				_worker;															///< Pointer to the worker method.
	GetWorkerOptionsPtr	_getOptions;													///< Pointer to a method which returns less time critical parameters.
	GetWorkerDependencyGroupPtr _getDependencyGroup;					///< Can be nullptr to indicate default dependency behaviour.
};

/// Base class of JobInterface.
struct JobInterfacePOD
{
	const JobInterfaceJumpTablePOD *_jmpTable;								///< Pointer to the jump table (guaranteed to be valid).
	mutable CoreJob* _job;																		///< Internal job data (can be nullptr when no job is running). 
};

class JobInterfaceBase : public JobInterfacePOD
{
protected:
	virtual ~JobInterfaceBase() { }
};

MAXON_ASSERT_STANDARD_LAYOUT(JobInterfacePOD);

/// For all calls that receive a JobFunctorPOD as input parameter its self pointer is guaranteed to be valid.
struct JobFunctorPOD
{
	const JobInterface* _self;																///< JobInterface's this pointer (guaranteed to be valid).
};

class JobFunctor : public JobFunctorPOD
{
public:
	JobFunctor()
	{
		static_assert(SIZEOF(JobFunctor) == SIZEOF(JobFunctorPOD), "JobFunctor must have the same size as JobFunctorPOD");
		_self = nullptr;
	}
	explicit JobFunctor(const JobInterface* self)
	{
		_self = self;
	}

	explicit JobFunctor(const JobInterfacePOD& self)
	{
		const JobInterfaceBase* dummy = (JobInterfaceBase*) sizeof(JobInterfaceBase);
		const JobInterfacePOD* dummy2 = dummy;
		const Int offset = Int(dummy2) - Int(dummy);

		_self = (JobInterface*)((Char*)&self - offset);
	}

	JobFunctorPOD& operator =(const JobFunctorPOD& src)
	{
		_self = src._self;
		return *this;
	}

	static inline const JobFunctor& FromPOD(const JobFunctorPOD& pod)
	{
		return (const JobFunctor&) pod;
	}

	//----------------------------------------------------------------------------------------
	/// This operator returns true if the self pointer is valid
	/// operator bool() would be ambiguous because it can be used for integer arithmetic.
	/// For C++11 we use explicit bool to avoid that implicit conversion, for older
	/// compilers void* is returned because you can't do arithmetic with it.
	/// @return												False if the self pointer is nullptr.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return Bool(_self != nullptr);
	}

	Bool operator ==(const JobFunctor& b) const
	{
		return _self == b._self;
	}

	Bool operator !=(const JobFunctor& b) const
	{
		return _self != b._self;
	}

	//----------------------------------------------------------------------------------------
	/// @return												Address of the object (which might be different from the JobInterface* if the inhereting class contains virtual methods).
	//----------------------------------------------------------------------------------------
	void* Destruct() const
	{
		return GetJobInterfacePOD()._jmpTable->_destructWorker(_self);
	}

	//----------------------------------------------------------------------------------------
	/// @return												Pointer to an error (indicates failure) or nullptr (success).
	//----------------------------------------------------------------------------------------
	const ErrorInterface* operator ()()
	{
		return GetJobInterfacePOD()._jmpTable->_worker(_self);
	}

	//----------------------------------------------------------------------------------------
	/// @return												The job name.
	//----------------------------------------------------------------------------------------
	const Char* GetName() const
	{
		return reinterpret_cast<const Char*>(GetJobInterfacePOD()._jmpTable->_getOptions(_self, 0, nullptr));
	}

	//----------------------------------------------------------------------------------------
	/// @return												Job options (e.g. regarding early cancellation).
	//----------------------------------------------------------------------------------------
	JOBOPTIONFLAGS GetOptionFlags() const
	{
		return (JOBOPTIONFLAGS) Int(GetJobInterfacePOD()._jmpTable->_getOptions(_self, 1, nullptr));
	}

	JobInterfacePOD& GetJobInterfacePOD() const
	{
		return *(JobInterfaceBase*) _self;
	}

	JobInterface* GetJobInterface() const
	{
		return const_cast<JobInterface*>(_self);
	}

	const JobInterfaceJumpTablePOD* GetJumpTable() const
	{
		return GetJobInterfacePOD()._jmpTable;
	}
};

/// @endcond

enum class THREADPRIORITY : Int16
{
	NORMAL		= 0,
	ABOVE			= 63,
	BELOW			= -63,
	LOWEST		= -127,
	BACKGROUND_IDLE = -255
} MAXON_ENUM_LIST(THREADPRIORITY);

/// WAITMODE can be optionally specified for almost all objects with a Wait() method.
/// Most of the time you don't have to specify anything and implicitely use the default.
/// You can however specify WAITMODE::RETURN_ON_CANCEL in cases where your job/thread might be
/// cancelled and you don't want it to hang in a Wait() call.
///
/// @code
/// {
/// 	// ... your job/ thread code doing something ...
///
/// 	// wait for something (could be a job, thread, group, condition variable ...)
/// 	if (something.Wait(TIMEVALUE_INFINITE, WAITMODE::RETURN_ON_CANCEL) == false)
/// 	{
/// 		// At this point Wait() has returned even though something we waited for has not completed.
/// 		// We might have to cancel something for (e.g. if it depends on data owned by this job)
/// 		// and wait until it has done so. This looks like the following:
/// 		something.Cancel();
///
/// 		// Now wait until it has really cancelled (does not access our data anymore).
/// 		something.Wait();
/// 	}
///
/// 	// Here you might release whatever data you owned which something was accessing.
/// }
/// @endcode
enum class WAITMODE
{
	DEFAULT						= 0,		///< Default case: Wait() will return if the condition is set or it has timed out.
	RETURN_ON_CANCEL	= 1,		///< Wait() should return if the caller has been cancelled even though the condition is not set yet.
	PRIVATE_BLOCKING	= 2,		///< Wait() won't execute other jobs on the thread while it is waiting (for legacy threads only).
	EXTERNAL_ENQUEUE	= 4			///< Wait() for a job which has been enqueued by a different thread (by default this is not allowed to prevent deadlocks).
} MAXON_ENUM_FLAGS(WAITMODE);

enum class THREADTYPE
{
	MAIN = 0,									///< The main thread.
	WORKER = 1,								///< A worker thread of a queue.
	STANDALONE = 2,						///< A standalone thread.
	ALIEN = 3,								///< An alien thread (only limited use of MAXON API allowed).
	ASSIMILATED = 4						///< An assimilated alien thread (full use of the MAXON API allowed).
} MAXON_ENUM_LIST(THREADTYPE);

} // namespace maxon

#endif // THREADSERVICESPODS_H__
