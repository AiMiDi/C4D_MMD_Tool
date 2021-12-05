#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	namespace enum26 { enum class JOBGROUPFLAGS
	{
		DEFAULT = 0,																														///< Default case.
		ENQUEUEING_THREAD_WAITS = 2,																						///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
		FINALIZE_ON_WAIT = 4,																										///< After Enqueue() further Add()s can be made which start the jobs ASAP. A following call to Wait() or GetResult() finalizes the group (no more jobs can be added). Can be useful if there is a lot of setup work before a job can be added.
		THREAD_AFFINITY = 8																											///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and therefore slower and only useful for special cases.
	} ; }
	maxon::String PrivateToString_JOBGROUPFLAGS26(std::underlying_type<enum26::JOBGROUPFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum26::JOBGROUPFLAGS::DEFAULT, (maxon::UInt64) enum26::JOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS, (maxon::UInt64) enum26::JOBGROUPFLAGS::FINALIZE_ON_WAIT, (maxon::UInt64) enum26::JOBGROUPFLAGS::THREAD_AFFINITY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOBGROUPFLAGS", SIZEOF(x), true, values, "DEFAULT\0ENQUEUEING_THREAD_WAITS\0FINALIZE_ON_WAIT\0THREAD_AFFINITY\0", fmt);
	}
/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

	namespace enum608 { enum class STATICJOBGROUPFLAGS
	{
		DEFAULT = 0,																																///< Safe default case.
		ENQUEUEING_THREAD_WAITS = 2,																								///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
		THREAD_AFFINITY = 8																													///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and therefore slower and only useful for special cases.
	} ; }
	maxon::String PrivateToString_STATICJOBGROUPFLAGS608(std::underlying_type<enum608::STATICJOBGROUPFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum608::STATICJOBGROUPFLAGS::DEFAULT, (maxon::UInt64) enum608::STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS, (maxon::UInt64) enum608::STATICJOBGROUPFLAGS::THREAD_AFFINITY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STATICJOBGROUPFLAGS", SIZEOF(x), true, values, "DEFAULT\0ENQUEUEING_THREAD_WAITS\0THREAD_AFFINITY\0", fmt);
	}
	namespace enum847 { enum class STATICJOBARRAYFLAGS
	{
		DEFAULT = 0,					///< Default behaviour: Array is empty.
		INITIALIZE_LATER = 1	///< Array consists of as many uninitialized elements as it has capacity. The caller will construct them later on (before it is added to the group).
	} ; }
	maxon::String PrivateToString_STATICJOBARRAYFLAGS847(std::underlying_type<enum847::STATICJOBARRAYFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum847::STATICJOBARRAYFLAGS::DEFAULT, (maxon::UInt64) enum847::STATICJOBARRAYFLAGS::INITIALIZE_LATER};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STATICJOBARRAYFLAGS", SIZEOF(x), true, values, "DEFAULT\0INITIALIZE_LATER\0", fmt);
	}
/// @cond IGNORE

/// @endcond

}
#endif
