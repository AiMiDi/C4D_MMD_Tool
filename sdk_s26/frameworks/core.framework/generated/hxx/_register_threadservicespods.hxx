#if 1
namespace maxon
{
/// @cond INTERNAL

	namespace enum20
	{
		enum class JOBOPTIONFLAGS : Int
		{
			DEFAULT = 0,												///< Default behaviour: Early job cancellation (before the worker method has been executed) will return OK.
			EARLY_CANCELLATION_IS_AN_ERROR = 1,	///< Early job cancellation (before the worker method has been executed) will return an error.
			KEEP_RUNNING_ON_EXIT = 2						///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded.
		} ;
		static const maxon::UInt64 JOBOPTIONFLAGS_values[] = {maxon::UInt64(enum20::JOBOPTIONFLAGS::DEFAULT), maxon::UInt64(enum20::JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR), maxon::UInt64(enum20::JOBOPTIONFLAGS::KEEP_RUNNING_ON_EXIT)};
		static const maxon::EnumInfo JOBOPTIONFLAGS_info{"JOBOPTIONFLAGS", SIZEOF(JOBOPTIONFLAGS), true, "DEFAULT\0EARLY_CANCELLATION_IS_AN_ERROR\0KEEP_RUNNING_ON_EXIT\0", JOBOPTIONFLAGS_values, std::extent<decltype(JOBOPTIONFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JOBOPTIONFLAGS20(){ return enum20::JOBOPTIONFLAGS_info; }
/// @endcond

	namespace enum168
	{
		enum class THREADPRIORITY : Int16
		{
			NORMAL		= 0,
			ABOVE			= 63,
			BELOW			= -63,
			LOWEST		= -127,
			BACKGROUND_IDLE = -255
		} ;
		static const maxon::UInt64 THREADPRIORITY_values[] = {maxon::UInt64(enum168::THREADPRIORITY::NORMAL), maxon::UInt64(enum168::THREADPRIORITY::ABOVE), maxon::UInt64(enum168::THREADPRIORITY::BELOW), maxon::UInt64(enum168::THREADPRIORITY::LOWEST), maxon::UInt64(enum168::THREADPRIORITY::BACKGROUND_IDLE)};
		static const maxon::EnumInfo THREADPRIORITY_info{"THREADPRIORITY", SIZEOF(THREADPRIORITY), false, "NORMAL\0ABOVE\0BELOW\0LOWEST\0BACKGROUND_IDLE\0", THREADPRIORITY_values, std::extent<decltype(THREADPRIORITY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_THREADPRIORITY168(){ return enum168::THREADPRIORITY_info; }
	namespace enum201
	{
		enum class WAITMODE
		{
			DEFAULT						= 0,		///< Default case: Wait() will return if the condition is set or it has timed out.
			RETURN_ON_CANCEL	= 1,		///< Wait() should return if the caller has been cancelled even though the condition is not set yet.
			PRIVATE_BLOCKING	= 2,		///< Wait() won't execute other jobs on the thread while it is waiting (for legacy threads only).
			EXTERNAL_ENQUEUE	= 4,		///< Wait() for a job which has been enqueued by a different thread (by default this is not allowed to prevent deadlocks).
			DONT_WAIT					= 128		///< For ExecuteOnMainThread only: Do not wait.
		} ;
		static const maxon::UInt64 WAITMODE_values[] = {maxon::UInt64(enum201::WAITMODE::DEFAULT), maxon::UInt64(enum201::WAITMODE::RETURN_ON_CANCEL), maxon::UInt64(enum201::WAITMODE::PRIVATE_BLOCKING), maxon::UInt64(enum201::WAITMODE::EXTERNAL_ENQUEUE), maxon::UInt64(enum201::WAITMODE::DONT_WAIT)};
		static const maxon::EnumInfo WAITMODE_info{"WAITMODE", SIZEOF(WAITMODE), true, "DEFAULT\0RETURN_ON_CANCEL\0PRIVATE_BLOCKING\0EXTERNAL_ENQUEUE\0DONT_WAIT\0", WAITMODE_values, std::extent<decltype(WAITMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_WAITMODE201(){ return enum201::WAITMODE_info; }
	namespace enum210
	{
		enum class THREADTYPE
		{
			MAIN = 0,									///< The main thread.
			WORKER = 1,								///< A worker thread of a queue.
			STANDALONE = 2,						///< A standalone thread.
			ALIEN = 3,								///< An alien thread (only limited use of MAXON API allowed).
			ASSIMILATED = 4						///< An assimilated alien thread (full use of the MAXON API allowed).
		} ;
		static const maxon::UInt64 THREADTYPE_values[] = {maxon::UInt64(enum210::THREADTYPE::MAIN), maxon::UInt64(enum210::THREADTYPE::WORKER), maxon::UInt64(enum210::THREADTYPE::STANDALONE), maxon::UInt64(enum210::THREADTYPE::ALIEN), maxon::UInt64(enum210::THREADTYPE::ASSIMILATED)};
		static const maxon::EnumInfo THREADTYPE_info{"THREADTYPE", SIZEOF(THREADTYPE), false, "MAIN\0WORKER\0STANDALONE\0ALIEN\0ASSIMILATED\0", THREADTYPE_values, std::extent<decltype(THREADTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_THREADTYPE210(){ return enum210::THREADTYPE_info; }
}
#endif
