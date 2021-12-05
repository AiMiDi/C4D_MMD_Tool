#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum95 { enum class CUSTOMTYPE
{
	END,			///< End marker.
	FLAG,			///< Bool data. (Either the property is there or not.)
	LONG,			///< ::Int32 data.
	REAL,			///< ::Float data.
	STRING,		///< String data. (An ID from the string table.)
	VECTOR,		///< ::Vector data.

	HIDE_ID = (1 << 30)
} ; }
maxon::String PrivateToString_CUSTOMTYPE95(std::underlying_type<enum95::CUSTOMTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum95::CUSTOMTYPE::END, (maxon::UInt64) enum95::CUSTOMTYPE::FLAG, (maxon::UInt64) enum95::CUSTOMTYPE::LONG, (maxon::UInt64) enum95::CUSTOMTYPE::REAL, (maxon::UInt64) enum95::CUSTOMTYPE::STRING, (maxon::UInt64) enum95::CUSTOMTYPE::VECTOR, (maxon::UInt64) enum95::CUSTOMTYPE::HIDE_ID};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CUSTOMTYPE", SIZEOF(x), false, values, "END\0FLAG\0LONG\0REAL\0STRING\0VECTOR\0HIDE_ID\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
