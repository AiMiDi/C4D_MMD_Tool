#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef __NET_LIB__
#endif
namespace maxon
{
	namespace enum268 { enum class OUTPUTLOCATION
	{
		BETA = (1 << 0),	// only during beta
		C4D = (1 << 1),
		NET = (1 << 2),
		ALL = (1 << 1 | 1 << 2)
	} ; }
	maxon::String PrivateToString_OUTPUTLOCATION268(std::underlying_type<enum268::OUTPUTLOCATION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum268::OUTPUTLOCATION::BETA, (maxon::UInt64) enum268::OUTPUTLOCATION::C4D, (maxon::UInt64) enum268::OUTPUTLOCATION::NET, (maxon::UInt64) enum268::OUTPUTLOCATION::ALL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OUTPUTLOCATION", SIZEOF(x), true, values, "BETA\0C4D\0NET\0ALL\0", fmt);
	}
}
namespace enum279 { enum class TASKSTATE
{
	NEW = 1000,	// Newly created, not yet touched
	ASSIGNED,	// Executing
	TRANSFERED,	// Transfered but not yet finished
	ASSEMBLED,	// Assembled and finished (final-state)
	SKIPPED // skipped because of frame range
} ; }
maxon::String PrivateToString_TASKSTATE279(std::underlying_type<enum279::TASKSTATE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum279::TASKSTATE::NEW, (maxon::UInt64) enum279::TASKSTATE::ASSIGNED, (maxon::UInt64) enum279::TASKSTATE::TRANSFERED, (maxon::UInt64) enum279::TASKSTATE::ASSEMBLED, (maxon::UInt64) enum279::TASKSTATE::SKIPPED};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TASKSTATE", SIZEOF(x), true, values, "NEW\0ASSIGNED\0TRANSFERED\0ASSEMBLED\0SKIPPED\0", fmt);
}
#ifdef __NET_LIB__
#endif
#ifdef __NET_LIB__
#endif
#ifdef __NET_LIB__
#endif
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
#endif
