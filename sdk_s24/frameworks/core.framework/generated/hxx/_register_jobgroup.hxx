#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	namespace enum26
	{
		enum class JOBGROUPFLAGS
		{
			DEFAULT = 0,																														///< Default case.
			ENQUEUEING_THREAD_WAITS = 2,																						///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
			FINALIZE_ON_WAIT = 4,																										///< After Enqueue() further Add()s can be made which start the jobs ASAP. A following call to Wait() or GetResult() finalizes the group (no more jobs can be added). Can be useful if there is a lot of setup work before a job can be added.
			THREAD_AFFINITY = 8																											///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and is therefore slower and only useful for special cases. If a group with thread affinity had more jobs than the queue had threads its jobs must not have dependencies or wait calls. Only supported for queues where thread affinity has been enabled.
		} ;
		static const maxon::UInt64 JOBGROUPFLAGS_values[] = {maxon::UInt64(enum26::JOBGROUPFLAGS::DEFAULT), maxon::UInt64(enum26::JOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS), maxon::UInt64(enum26::JOBGROUPFLAGS::FINALIZE_ON_WAIT), maxon::UInt64(enum26::JOBGROUPFLAGS::THREAD_AFFINITY)};
		static const maxon::EnumInfo JOBGROUPFLAGS_info{"JOBGROUPFLAGS", SIZEOF(JOBGROUPFLAGS), true, "DEFAULT\0ENQUEUEING_THREAD_WAITS\0FINALIZE_ON_WAIT\0THREAD_AFFINITY\0", JOBGROUPFLAGS_values, std::extent<decltype(JOBGROUPFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JOBGROUPFLAGS26(){ return enum26::JOBGROUPFLAGS_info; }
/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

	namespace enum608
	{
		enum class STATICJOBGROUPFLAGS
		{
			DEFAULT = 0,																																///< Safe default case.
			ENQUEUEING_THREAD_WAITS = 2,																								///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
			THREAD_AFFINITY = 8																													///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and therefore slower and only useful for special cases.
		} ;
		static const maxon::UInt64 STATICJOBGROUPFLAGS_values[] = {maxon::UInt64(enum608::STATICJOBGROUPFLAGS::DEFAULT), maxon::UInt64(enum608::STATICJOBGROUPFLAGS::ENQUEUEING_THREAD_WAITS), maxon::UInt64(enum608::STATICJOBGROUPFLAGS::THREAD_AFFINITY)};
		static const maxon::EnumInfo STATICJOBGROUPFLAGS_info{"STATICJOBGROUPFLAGS", SIZEOF(STATICJOBGROUPFLAGS), true, "DEFAULT\0ENQUEUEING_THREAD_WAITS\0THREAD_AFFINITY\0", STATICJOBGROUPFLAGS_values, std::extent<decltype(STATICJOBGROUPFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STATICJOBGROUPFLAGS608(){ return enum608::STATICJOBGROUPFLAGS_info; }
	namespace enum847
	{
		enum class STATICJOBARRAYFLAGS
		{
			DEFAULT = 0,					///< Default behaviour: Array is empty.
			INITIALIZE_LATER = 1	///< Array consists of as many uninitialized elements as it has capacity. The caller will construct them later on (before it is added to the group).
		} ;
		static const maxon::UInt64 STATICJOBARRAYFLAGS_values[] = {maxon::UInt64(enum847::STATICJOBARRAYFLAGS::DEFAULT), maxon::UInt64(enum847::STATICJOBARRAYFLAGS::INITIALIZE_LATER)};
		static const maxon::EnumInfo STATICJOBARRAYFLAGS_info{"STATICJOBARRAYFLAGS", SIZEOF(STATICJOBARRAYFLAGS), true, "DEFAULT\0INITIALIZE_LATER\0", STATICJOBARRAYFLAGS_values, std::extent<decltype(STATICJOBARRAYFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STATICJOBARRAYFLAGS847(){ return enum847::STATICJOBARRAYFLAGS_info; }
/// @cond IGNORE

/// @endcond

}
#endif
