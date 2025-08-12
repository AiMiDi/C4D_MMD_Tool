#if 1
#ifdef __API_INTERN__
#else
#endif
namespace cinema
{
	namespace enum34
	{
		enum class DATETIMEPARSERMODE
		{
			DATE,			///< Date.
			TIME				///< Time
		} ;
		static const maxon::UInt64 DATETIMEPARSERMODE_values[] = {maxon::UInt64(enum34::DATETIMEPARSERMODE::DATE), maxon::UInt64(enum34::DATETIMEPARSERMODE::TIME)};
		static const maxon::EnumInfo DATETIMEPARSERMODE_info{"DATETIMEPARSERMODE", SIZEOF(DATETIMEPARSERMODE), false, "DATE\0TIME\0", DATETIMEPARSERMODE_values, std::extent<decltype(DATETIMEPARSERMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DATETIMEPARSERMODE34(){ return enum34::DATETIMEPARSERMODE_info; }
/// @cond IGNORE

/// @endcond

}
#endif
