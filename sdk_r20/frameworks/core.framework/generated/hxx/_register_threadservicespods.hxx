#if 1
namespace maxon
{
/// @cond INTERNAL

	namespace enum20 { enum class JOBOPTIONFLAGS : Int
	{
		DEFAULT = 0,												///< Default behaviour: Early job cancellation (before the worker method has been executed) will return OK.
		EARLY_CANCELLATION_IS_AN_ERROR = 1,	///< Early job cancellation (before the worker method has been executed) will return an error.
		KEEP_RUNNING_ON_EXIT = 2						///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded.
	} ; }
	maxon::String PrivateToString_JOBOPTIONFLAGS20(std::underlying_type<enum20::JOBOPTIONFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum20::JOBOPTIONFLAGS::DEFAULT, (maxon::UInt64) enum20::JOBOPTIONFLAGS::EARLY_CANCELLATION_IS_AN_ERROR, (maxon::UInt64) enum20::JOBOPTIONFLAGS::KEEP_RUNNING_ON_EXIT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOBOPTIONFLAGS", SIZEOF(x), true, values, "DEFAULT\0EARLY_CANCELLATION_IS_AN_ERROR\0KEEP_RUNNING_ON_EXIT\0", fmt);
	}
/// @endcond

	namespace enum167 { enum class THREADPRIORITY : Int16
	{
		NORMAL		= 0,
		ABOVE			= 63,
		BELOW			= -63,
		LOWEST		= -127
	} ; }
	maxon::String PrivateToString_THREADPRIORITY167(std::underlying_type<enum167::THREADPRIORITY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum167::THREADPRIORITY::NORMAL, (maxon::UInt64) enum167::THREADPRIORITY::ABOVE, (maxon::UInt64) enum167::THREADPRIORITY::BELOW, (maxon::UInt64) enum167::THREADPRIORITY::LOWEST};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "THREADPRIORITY", SIZEOF(x), false, values, "NORMAL\0ABOVE\0BELOW\0LOWEST\0", fmt);
	}
	namespace enum199 { enum class WAITMODE
	{
		DEFAULT						= 0,		///< Default case: Wait() will return if the condition is set or it has timed out.
		RETURN_ON_CANCEL	= 1,		///< Wait() should return if the caller has been cancelled even though the condition is not set yet.
		PRIVATE_BLOCKING	= 2,		///< Wait() won't execute other jobs on the thread while it is waiting (for legacy threads only).
		EXTERNAL_ENQUEUE	= 4			///< Wait() for a job which has been enqueued by a different thread (by default this is not allowed to prevent deadlocks).
	} ; }
	maxon::String PrivateToString_WAITMODE199(std::underlying_type<enum199::WAITMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum199::WAITMODE::DEFAULT, (maxon::UInt64) enum199::WAITMODE::RETURN_ON_CANCEL, (maxon::UInt64) enum199::WAITMODE::PRIVATE_BLOCKING, (maxon::UInt64) enum199::WAITMODE::EXTERNAL_ENQUEUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "WAITMODE", SIZEOF(x), true, values, "DEFAULT\0RETURN_ON_CANCEL\0PRIVATE_BLOCKING\0EXTERNAL_ENQUEUE\0", fmt);
	}
	namespace enum208 { enum class THREADTYPE
	{
		MAIN = 0,									///< The main thread.
		WORKER = 1,								///< A worker thread of a queue.
		STANDALONE = 2,						///< A standalone thread.
		ALIEN = 3,								///< An alien thread (only limited use of MAXON API allowed).
		ASSIMILATED = 4						///< An assimilated alien thread (full use of the MAXON API allowed).
	} ; }
	maxon::String PrivateToString_THREADTYPE208(std::underlying_type<enum208::THREADTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum208::THREADTYPE::MAIN, (maxon::UInt64) enum208::THREADTYPE::WORKER, (maxon::UInt64) enum208::THREADTYPE::STANDALONE, (maxon::UInt64) enum208::THREADTYPE::ALIEN, (maxon::UInt64) enum208::THREADTYPE::ASSIMILATED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "THREADTYPE", SIZEOF(x), false, values, "MAIN\0WORKER\0STANDALONE\0ALIEN\0ASSIMILATED\0", fmt);
	}
}
#endif
