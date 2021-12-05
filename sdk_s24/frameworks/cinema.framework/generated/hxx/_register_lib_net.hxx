#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef __NET_LIB__
#endif
namespace maxon
{
	namespace enum274
	{
		enum class OUTPUTLOCATION
		{
			BETA = (1 << 0),	// only during beta
			C4D = (1 << 1),
			NET = (1 << 2),
			ALL = (1 << 1 | 1 << 2)
		} ;
		static const maxon::UInt64 OUTPUTLOCATION_values[] = {maxon::UInt64(enum274::OUTPUTLOCATION::BETA), maxon::UInt64(enum274::OUTPUTLOCATION::C4D), maxon::UInt64(enum274::OUTPUTLOCATION::NET), maxon::UInt64(enum274::OUTPUTLOCATION::ALL)};
		static const maxon::EnumInfo OUTPUTLOCATION_info{"OUTPUTLOCATION", SIZEOF(OUTPUTLOCATION), true, "BETA\0C4D\0NET\0ALL\0", OUTPUTLOCATION_values, std::extent<decltype(OUTPUTLOCATION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OUTPUTLOCATION274(){ return enum274::OUTPUTLOCATION_info; }
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum289
{
	enum class TASKSTATE
	{
		NEW = 1000,	// Newly created, not yet touched
		ASSIGNED,	// Executing
		TRANSFERED,	// Transfered but not yet finished
		ASSEMBLED,	// Assembled and finished (final-state)
		SKIPPED // skipped because of frame range
	} ;
	static const maxon::UInt64 TASKSTATE_values[] = {maxon::UInt64(enum289::TASKSTATE::NEW), maxon::UInt64(enum289::TASKSTATE::ASSIGNED), maxon::UInt64(enum289::TASKSTATE::TRANSFERED), maxon::UInt64(enum289::TASKSTATE::ASSEMBLED), maxon::UInt64(enum289::TASKSTATE::SKIPPED)};
	static const maxon::EnumInfo TASKSTATE_info{"TASKSTATE", SIZEOF(TASKSTATE), true, "NEW\0ASSIGNED\0TRANSFERED\0ASSEMBLED\0SKIPPED\0", TASKSTATE_values, std::extent<decltype(TASKSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TASKSTATE289(){ return enum289::TASKSTATE_info; }
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
