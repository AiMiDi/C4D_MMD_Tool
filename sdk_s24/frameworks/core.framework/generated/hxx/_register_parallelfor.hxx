#if 1
namespace maxon
{
#if defined(MAXON_COMPILER_MSVC)
#endif
	namespace enum38
	{
		enum class PARALLELFORFLAGS
		{
			INITTHREADED_FINALIZETHREADED			= 0,		///< Init() and Finalize() calls are threaded.
			INITTHREADED_FINALIZESYNC					= 1,		///< Init() is called threaded, Finalize() is called synchronously (default case).
			INITSYNC_FINALIZETHREADED					= 2,		///< Init() is called synchronously, Finalize() is called threaded.
			INITSYNC_FINALIZESYNC							= 3,		///< Init() and Finalize() are called synchronously.
			NOINIT_NOFINALIZE									= 4,		///< no call to Init() or Finalize().
			INITTHREADEDWITHSYNC_FINALIZESYNC = 5			///< Init() is called threaded but the parallel loop body won't start until Init() has finished for all threads, Finalize() is called synchronously.
		} ;
		static const maxon::UInt64 PARALLELFORFLAGS_values[] = {maxon::UInt64(enum38::PARALLELFORFLAGS::INITTHREADED_FINALIZETHREADED), maxon::UInt64(enum38::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC), maxon::UInt64(enum38::PARALLELFORFLAGS::INITSYNC_FINALIZETHREADED), maxon::UInt64(enum38::PARALLELFORFLAGS::INITSYNC_FINALIZESYNC), maxon::UInt64(enum38::PARALLELFORFLAGS::NOINIT_NOFINALIZE), maxon::UInt64(enum38::PARALLELFORFLAGS::INITTHREADEDWITHSYNC_FINALIZESYNC)};
		static const maxon::EnumInfo PARALLELFORFLAGS_info{"PARALLELFORFLAGS", SIZEOF(PARALLELFORFLAGS), true, "INITTHREADED_FINALIZETHREADED\0INITTHREADED_FINALIZESYNC\0INITSYNC_FINALIZETHREADED\0INITSYNC_FINALIZESYNC\0NOINIT_NOFINALIZE\0INITTHREADEDWITHSYNC_FINALIZESYNC\0", PARALLELFORFLAGS_values, std::extent<decltype(PARALLELFORFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_PARALLELFORFLAGS38(){ return enum38::PARALLELFORFLAGS_info; }
/// @cond IGNORE

/// @endcond

#if defined(MAXON_COMPILER_MSVC)
#endif
}
#endif
