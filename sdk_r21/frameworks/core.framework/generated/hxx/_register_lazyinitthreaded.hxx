#if 1
namespace maxon
{
	namespace enum81 { enum class OPTIONS : Int
		{
			NONE = 0,
			FORWARD_CANCELLATION = 1,	 ///< Cancellation of the calling job will be forwarded.
			RETRY_ON_FAILURE = 2,			 ///< Retry initialization if it failed the first time.
			RETRY_ON_CANCELLATION = 4, ///< Retry initialization if it failed due to thread cancellation (ThreadCancelledError). This is a special
																 ///< case of RETRY_ON_FAILURE.
			DEFAULT = FORWARD_CANCELLATION | RETRY_ON_CANCELLATION ///< Default behaviour: Cancellation of the calling job will be forwarded,
																														 ///< initialization will be retried if it failed due to ThreadCancelledError.
		} ; }
	maxon::String PrivateToString_OPTIONS81(std::underlying_type<enum81::OPTIONS>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum81::OPTIONS::NONE, (maxon::UInt64) enum81::OPTIONS::FORWARD_CANCELLATION, (maxon::UInt64) enum81::OPTIONS::RETRY_ON_FAILURE, (maxon::UInt64) enum81::OPTIONS::RETRY_ON_CANCELLATION, (maxon::UInt64) enum81::OPTIONS::DEFAULT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LazyInitThreaded::OPTIONS", SIZEOF(x), true, values, "NONE\0FORWARD_CANCELLATION\0RETRY_ON_FAILURE\0RETRY_ON_CANCELLATION\0DEFAULT\0", fmt);
	}
}
#endif
