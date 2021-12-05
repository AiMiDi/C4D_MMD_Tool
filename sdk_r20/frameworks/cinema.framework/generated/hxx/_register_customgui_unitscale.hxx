#if 1
namespace enum46 { enum class DOCUMENT_UNIT
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
} ; }
maxon::String PrivateToString_DOCUMENT_UNIT46(std::underlying_type<enum46::DOCUMENT_UNIT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum46::DOCUMENT_UNIT::UNDEFINED, (maxon::UInt64) enum46::DOCUMENT_UNIT::KM, (maxon::UInt64) enum46::DOCUMENT_UNIT::M, (maxon::UInt64) enum46::DOCUMENT_UNIT::CM, (maxon::UInt64) enum46::DOCUMENT_UNIT::MM, (maxon::UInt64) enum46::DOCUMENT_UNIT::MICRO, (maxon::UInt64) enum46::DOCUMENT_UNIT::NM, (maxon::UInt64) enum46::DOCUMENT_UNIT::MILE, (maxon::UInt64) enum46::DOCUMENT_UNIT::YARD, (maxon::UInt64) enum46::DOCUMENT_UNIT::FOOT, (maxon::UInt64) enum46::DOCUMENT_UNIT::INCH};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DOCUMENT_UNIT", SIZEOF(x), false, values, "UNDEFINED\0KM\0M\0CM\0MM\0MICRO\0NM\0MILE\0YARD\0FOOT\0INCH\0", fmt);
}
/// @cond IGNORE

#ifndef _INTERNAL_DEF_
#else
#endif
/// @endcond

#endif
