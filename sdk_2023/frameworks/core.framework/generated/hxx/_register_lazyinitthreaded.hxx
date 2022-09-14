#if 1
namespace maxon
{
	namespace enum84
	{
		enum class OPTIONS : Int
			{
				NONE = 0,
				FORWARD_CANCELLATION = 1,	 ///< Cancellation of the calling job will be forwarded.
				RETRY_ON_FAILURE = 2,			 ///< Retry initialization if it failed the first time.
				RETRY_ON_CANCELLATION = 4, ///< Retry initialization if it failed due to thread cancellation (OperationCancelledError). This is a special
																	 ///< case of RETRY_ON_FAILURE.
				NO_EXCLUSIVE_RESOURCE = 8,	///< support cancellation etc. but do not span an exclusive resource around the lazy init threaded and all its sub-jobs
				DEFAULT = FORWARD_CANCELLATION | RETRY_ON_CANCELLATION ///< Default behaviour: Cancellation of the calling job will be forwarded,
																															 ///< initialization will be retried if it failed due to OperationCancelledError.
			} ;
		static const maxon::UInt64 OPTIONS_values[] = {maxon::UInt64(enum84::OPTIONS::NONE), maxon::UInt64(enum84::OPTIONS::FORWARD_CANCELLATION), maxon::UInt64(enum84::OPTIONS::RETRY_ON_FAILURE), maxon::UInt64(enum84::OPTIONS::RETRY_ON_CANCELLATION), maxon::UInt64(enum84::OPTIONS::NO_EXCLUSIVE_RESOURCE), maxon::UInt64(enum84::OPTIONS::DEFAULT)};
		static const maxon::EnumInfo OPTIONS_info{"LazyInitThreaded::OPTIONS", SIZEOF(OPTIONS), true, "NONE\0FORWARD_CANCELLATION\0RETRY_ON_FAILURE\0RETRY_ON_CANCELLATION\0NO_EXCLUSIVE_RESOURCE\0DEFAULT\0", OPTIONS_values, std::extent<decltype(OPTIONS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OPTIONS84(void*){ return enum84::OPTIONS_info; }
}
#endif
