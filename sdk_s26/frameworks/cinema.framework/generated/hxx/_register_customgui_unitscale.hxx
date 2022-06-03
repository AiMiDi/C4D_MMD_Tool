#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum50
{
	enum class DOCUMENT_UNIT
	{
		UNDEFINED						= 0,			///< Undefined.
		KM									= 1,			///< Kilometer.
		M										= 2,			///< Meter.
		CM									= 3,			///< Centimeter.
		MM									= 4,			///< Millimeter.
		MICRO								= 5,			///< Micrometer.
		NM									= 6,			///< Nanometer.
		MILE								= 7,			///< Mile.
		YARD								= 8,			///< Yard.
		FOOT								= 9,			///< Foot.
		INCH								= 10			///< Inch.
	} ;
	static const maxon::UInt64 DOCUMENT_UNIT_values[] = {maxon::UInt64(enum50::DOCUMENT_UNIT::UNDEFINED), maxon::UInt64(enum50::DOCUMENT_UNIT::KM), maxon::UInt64(enum50::DOCUMENT_UNIT::M), maxon::UInt64(enum50::DOCUMENT_UNIT::CM), maxon::UInt64(enum50::DOCUMENT_UNIT::MM), maxon::UInt64(enum50::DOCUMENT_UNIT::MICRO), maxon::UInt64(enum50::DOCUMENT_UNIT::NM), maxon::UInt64(enum50::DOCUMENT_UNIT::MILE), maxon::UInt64(enum50::DOCUMENT_UNIT::YARD), maxon::UInt64(enum50::DOCUMENT_UNIT::FOOT), maxon::UInt64(enum50::DOCUMENT_UNIT::INCH)};
	static const maxon::EnumInfo DOCUMENT_UNIT_info{"DOCUMENT_UNIT", SIZEOF(DOCUMENT_UNIT), false, "UNDEFINED\0KM\0M\0CM\0MM\0MICRO\0NM\0MILE\0YARD\0FOOT\0INCH\0", DOCUMENT_UNIT_values, std::extent<decltype(DOCUMENT_UNIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DOCUMENT_UNIT50(){ return enum50::DOCUMENT_UNIT_info; }
/// @cond IGNORE

#ifndef _INTERNAL_DEF_
#else
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
