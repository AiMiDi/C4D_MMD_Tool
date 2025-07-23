#if 1
#ifdef __API_INTERN__
#else
#endif
namespace cinema
{
	namespace enum37
	{
		enum class CUSTOMDATATAG_MODE
		{
			VERTEX = 0,
			POLYVERTEX,
		} ;
		static const maxon::UInt64 CUSTOMDATATAG_MODE_values[] = {maxon::UInt64(enum37::CUSTOMDATATAG_MODE::VERTEX), maxon::UInt64(enum37::CUSTOMDATATAG_MODE::POLYVERTEX)};
		static const maxon::EnumInfo CUSTOMDATATAG_MODE_info{"CUSTOMDATATAG_MODE", SIZEOF(CUSTOMDATATAG_MODE), false, "VERTEX\0POLYVERTEX\0", CUSTOMDATATAG_MODE_values, std::extent<decltype(CUSTOMDATATAG_MODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CUSTOMDATATAG_MODE37(){ return enum37::CUSTOMDATATAG_MODE_info; }
/// @cond IGNORE

/// @endcond

}
#endif
