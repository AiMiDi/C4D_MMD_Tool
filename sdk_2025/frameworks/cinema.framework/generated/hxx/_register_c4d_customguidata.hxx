#if 1
namespace cinema
{
	namespace enum94
	{
		enum class CUSTOMTYPE
		{
			END,			///< End marker.
			FLAG,			///< Bool data. (Either the property is there or not.)
			LONG,			///< ::Int32 data.
			REAL,			///< ::Float data.
			STRING,		///< String data. (An ID from the string table.)
			VECTOR,		///< ::Vector data.
		
			HIDE_ID = (1 << 30)
		} ;
		static const maxon::UInt64 CUSTOMTYPE_values[] = {maxon::UInt64(enum94::CUSTOMTYPE::END), maxon::UInt64(enum94::CUSTOMTYPE::FLAG), maxon::UInt64(enum94::CUSTOMTYPE::LONG), maxon::UInt64(enum94::CUSTOMTYPE::REAL), maxon::UInt64(enum94::CUSTOMTYPE::STRING), maxon::UInt64(enum94::CUSTOMTYPE::VECTOR), maxon::UInt64(enum94::CUSTOMTYPE::HIDE_ID)};
		static const maxon::EnumInfo CUSTOMTYPE_info{"CUSTOMTYPE", SIZEOF(CUSTOMTYPE), false, "END\0FLAG\0LONG\0REAL\0STRING\0VECTOR\0HIDE_ID\0", CUSTOMTYPE_values, std::extent<decltype(CUSTOMTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CUSTOMTYPE94(){ return enum94::CUSTOMTYPE_info; }
}
#endif
