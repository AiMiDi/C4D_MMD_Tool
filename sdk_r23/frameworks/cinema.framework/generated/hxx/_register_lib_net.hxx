#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef __NET_LIB__
#endif
namespace maxon
{
	namespace enum274 { enum class OUTPUTLOCATION
	{
		BETA = (1 << 0),	// only during beta
		C4D = (1 << 1),
		NET = (1 << 2),
		ALL = (1 << 1 | 1 << 2)
	} ; }
	maxon::String PrivateToString_OUTPUTLOCATION274(std::underlying_type<enum274::OUTPUTLOCATION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum274::OUTPUTLOCATION::BETA, (maxon::UInt64) enum274::OUTPUTLOCATION::C4D, (maxon::UInt64) enum274::OUTPUTLOCATION::NET, (maxon::UInt64) enum274::OUTPUTLOCATION::ALL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OUTPUTLOCATION", SIZEOF(x), true, values, "BETA\0C4D\0NET\0ALL\0", fmt);
	}
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum289 { enum class TASKSTATE
{
	NEW = 1000,	// Newly created, not yet touched
	ASSIGNED,	// Executing
	TRANSFERED,	// Transfered but not yet finished
	ASSEMBLED,	// Assembled and finished (final-state)
	SKIPPED // skipped because of frame range
} ; }
maxon::String PrivateToString_TASKSTATE289(std::underlying_type<enum289::TASKSTATE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum289::TASKSTATE::NEW, (maxon::UInt64) enum289::TASKSTATE::ASSIGNED, (maxon::UInt64) enum289::TASKSTATE::TRANSFERED, (maxon::UInt64) enum289::TASKSTATE::ASSEMBLED, (maxon::UInt64) enum289::TASKSTATE::SKIPPED};
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
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
