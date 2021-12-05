#if 1
namespace maxon
{
	namespace enum83
	{
		enum class OPTIONS : Int
			{
				NONE = 0,
				FORWARD_CANCELLATION = 1,	 ///< Cancellation of the calling job will be forwarded.
				RETRY_ON_FAILURE = 2,			 ///< Retry initialization if it failed the first time.
				RETRY_ON_CANCELLATION = 4, ///< Retry initialization if it failed due to thread cancellation (ThreadCancelledError). This is a special
																	 ///< case of RETRY_ON_FAILURE.
				DEFAULT = FORWARD_CANCELLATION | RETRY_ON_CANCELLATION ///< Default behaviour: Cancellation of the calling job will be forwarded,
																															 ///< initialization will be retried if it failed due to ThreadCancelledError.
			} ;
		static const maxon::UInt64 OPTIONS_values[] = {maxon::UInt64(enum83::OPTIONS::NONE), maxon::UInt64(enum83::OPTIONS::FORWARD_CANCELLATION), maxon::UInt64(enum83::OPTIONS::RETRY_ON_FAILURE), maxon::UInt64(enum83::OPTIONS::RETRY_ON_CANCELLATION), maxon::UInt64(enum83::OPTIONS::DEFAULT)};
		static const maxon::EnumInfo OPTIONS_info{"LazyInitThreaded::OPTIONS", SIZEOF(OPTIONS), true, "NONE\0FORWARD_CANCELLATION\0RETRY_ON_FAILURE\0RETRY_ON_CANCELLATION\0DEFAULT\0", OPTIONS_values, std::extent<decltype(OPTIONS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OPTIONS83(void*){ return enum83::OPTIONS_info; }
}
#endif
