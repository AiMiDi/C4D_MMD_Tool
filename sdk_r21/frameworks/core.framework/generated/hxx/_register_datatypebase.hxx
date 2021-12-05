#if 1
namespace maxon
{
	namespace enum71 { enum class CONVERSION_FLAGS
	{
		NONE = 0,																							///< When no other flags are set, the conversion is a one-to-one correspondence (such as from Float to TimeValue and back).
		NARROWING = 1,																				///< The conversion contains a narrowing conversion. The conversion may not always be possible (such as converting a negative Int to a UInt), then it returns an error.
		WIDENING_LOSSY = 2,																		///< The conversion contains a widening conversion which is always possible, but it might result in loss of precision (a Float64 can't represent all bits of an Int64).
		WIDENING_LOSSLESS = 4,																///< The conversion contains a lossless widening conversion.
		REDUCING = 8,																					///< The conversion contains a reducing conversion such as from a vector to a scalar (or a higher-dimensional vector to a lower-dimensional vector).
		EXPANDING = 16,																				///< The conversion contains an expanding conversion such as from a scalar to a vector (or a lower-dimensional vector to a higher-dimensional vector).
		STRUCT_CAST = 32,																			///< The conversion contains a cast between layout-compatible structs (such as from Vector to Color).
		INCONVERTIBLE = 1024,																	///< No conversion possible.
		WIDENING_MASK = WIDENING_LOSSY | WIDENING_LOSSLESS,		///< Mask to check for a widening conversion (combination of WIDENING_LOSSY and WIDENING_LOSSLESS).
		NARROWING_REDUCING_MASK = NARROWING | REDUCING				///< Mask to check for a narrowing or reducing conversion (combination of NARROWING and REDUCING).
	} ; }
	maxon::String PrivateToString_CONVERSION_FLAGS71(std::underlying_type<enum71::CONVERSION_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum71::CONVERSION_FLAGS::NONE, (maxon::UInt64) enum71::CONVERSION_FLAGS::NARROWING, (maxon::UInt64) enum71::CONVERSION_FLAGS::WIDENING_LOSSY, (maxon::UInt64) enum71::CONVERSION_FLAGS::WIDENING_LOSSLESS, (maxon::UInt64) enum71::CONVERSION_FLAGS::REDUCING, (maxon::UInt64) enum71::CONVERSION_FLAGS::EXPANDING, (maxon::UInt64) enum71::CONVERSION_FLAGS::STRUCT_CAST, (maxon::UInt64) enum71::CONVERSION_FLAGS::INCONVERTIBLE, (maxon::UInt64) enum71::CONVERSION_FLAGS::WIDENING_MASK, (maxon::UInt64) enum71::CONVERSION_FLAGS::NARROWING_REDUCING_MASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONVERSION_FLAGS", SIZEOF(x), true, values, "NONE\0NARROWING\0WIDENING_LOSSY\0WIDENING_LOSSLESS\0REDUCING\0EXPANDING\0STRUCT_CAST\0INCONVERTIBLE\0WIDENING_MASK\0NARROWING_REDUCING_MASK\0", fmt);
	}
	namespace enum925 { enum class MEMBER_MATCH_MODE
		{
			ORDERED_EXACT,			///< Members have to match in name and type in their order.
			ORDERED_TYPE_ONLY,	///< Members have to match only in type.
			UNORDERED_BY_NAME		///< Members are matched by name, so their order is ignored.
		} ; }
	maxon::String PrivateToString_MEMBER_MATCH_MODE925(std::underlying_type<enum925::MEMBER_MATCH_MODE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum925::MEMBER_MATCH_MODE::ORDERED_EXACT, (maxon::UInt64) enum925::MEMBER_MATCH_MODE::ORDERED_TYPE_ONLY, (maxon::UInt64) enum925::MEMBER_MATCH_MODE::UNORDERED_BY_NAME};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DataType::MEMBER_MATCH_MODE", SIZEOF(x), false, values, "ORDERED_EXACT\0ORDERED_TYPE_ONLY\0UNORDERED_BY_NAME\0", fmt);
	}
#ifdef MAXON_TARGET_DEBUG
#endif
	namespace enum1026 { enum class GET_DATATYPE_POLICY
	{
		NONE = 0,
	
		/// Set this flag if the datatype of Generic shall be returned for a type which hasn't been registered (otherwise a compile-time error happens unless ERROR_FOR_UNKNOWN is set).
		GENERIC_FOR_UNKNOWN = 1,
	
		/// Set this flag if a runtime error shall be returned by CheckedGetDataType for a type which hasn't been registered (otherwise a compile-time error happens unless GENERIC_FOR_UNKNOWN is set).
		ERROR_FOR_UNKNOWN = 2,
	
		/// Set this flag if the template argument T of GetDataType shall not be decayed (by default the type is decayed so that T&, T&&, const T, const T&, const T&& all return the same as GetDataType<T>()).
		NO_DECAY = 4,
	
		ALLOW_BASEARRAY = 8,
	
		RESULT_FOR_UNKNOWN_MASK = GENERIC_FOR_UNKNOWN | ERROR_FOR_UNKNOWN
	} ; }
	maxon::String PrivateToString_GET_DATATYPE_POLICY1026(std::underlying_type<enum1026::GET_DATATYPE_POLICY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum1026::GET_DATATYPE_POLICY::NONE, (maxon::UInt64) enum1026::GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN, (maxon::UInt64) enum1026::GET_DATATYPE_POLICY::ERROR_FOR_UNKNOWN, (maxon::UInt64) enum1026::GET_DATATYPE_POLICY::NO_DECAY, (maxon::UInt64) enum1026::GET_DATATYPE_POLICY::ALLOW_BASEARRAY, (maxon::UInt64) enum1026::GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GET_DATATYPE_POLICY", SIZEOF(x), true, values, "NONE\0GENERIC_FOR_UNKNOWN\0ERROR_FOR_UNKNOWN\0NO_DECAY\0ALLOW_BASEARRAY\0RESULT_FOR_UNKNOWN_MASK\0", fmt);
	}
}
#endif
