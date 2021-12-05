#if 1
namespace maxon
{
	namespace enum70 { enum class CONVERSION_FLAGS
	{
		NONE = 0,
		IDENTITY = 1,						///< The conversion contains an identity conversion such as from Vector to Color.
		NARROWING = 2,					///< The conversion contains a narrowing conversion. The conversion may not always be possible (such as converting a negative Int to a UInt), then it returns an error.
		WIDENING_LOSSY = 4,			///< The conversion contains a widening conversion which is always possible, but it might result in loss of precision (a Float64 can't represent all bits of an Int64).
		WIDENING_LOSSLESS = 8,	///< The conversion contains a lossless widening conversion.
		EXPANDING = 16,					///< The conversion contains a expanding conversion such as from a scalar to a vector (or a lower-dimensional vector to a higher-dimensional vector).
		REDUCING = 32,					///< The conversion contains a reducing conversion such as from a vector to a scalar (or a higher-dimensional vector to a lower-dimensional vector).
		WIDENING_MASK = WIDENING_LOSSY | WIDENING_LOSSLESS
	} ; }
	maxon::String PrivateToString_CONVERSION_FLAGS70(std::underlying_type<enum70::CONVERSION_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum70::CONVERSION_FLAGS::NONE, (maxon::UInt64) enum70::CONVERSION_FLAGS::IDENTITY, (maxon::UInt64) enum70::CONVERSION_FLAGS::NARROWING, (maxon::UInt64) enum70::CONVERSION_FLAGS::WIDENING_LOSSY, (maxon::UInt64) enum70::CONVERSION_FLAGS::WIDENING_LOSSLESS, (maxon::UInt64) enum70::CONVERSION_FLAGS::EXPANDING, (maxon::UInt64) enum70::CONVERSION_FLAGS::REDUCING, (maxon::UInt64) enum70::CONVERSION_FLAGS::WIDENING_MASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONVERSION_FLAGS", SIZEOF(x), true, values, "NONE\0IDENTITY\0NARROWING\0WIDENING_LOSSY\0WIDENING_LOSSLESS\0EXPANDING\0REDUCING\0WIDENING_MASK\0", fmt);
	}
	namespace enum738 { enum class MEMBER_MATCH_MODE
		{
			ORDERED_EXACT,			///< Members have to match in name and type in their order.
			ORDERED_TYPE_ONLY,	///< Members have to match only in type.
			UNORDERED_BY_NAME		///< Members are matched by name, so their order is ignored.
		} ; }
	maxon::String PrivateToString_MEMBER_MATCH_MODE738(std::underlying_type<enum738::MEMBER_MATCH_MODE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum738::MEMBER_MATCH_MODE::ORDERED_EXACT, (maxon::UInt64) enum738::MEMBER_MATCH_MODE::ORDERED_TYPE_ONLY, (maxon::UInt64) enum738::MEMBER_MATCH_MODE::UNORDERED_BY_NAME};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DataType::MEMBER_MATCH_MODE", SIZEOF(x), false, values, "ORDERED_EXACT\0ORDERED_TYPE_ONLY\0UNORDERED_BY_NAME\0", fmt);
	}
	namespace enum953 { enum class GET_DATATYPE_POLICY
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
	maxon::String PrivateToString_GET_DATATYPE_POLICY953(std::underlying_type<enum953::GET_DATATYPE_POLICY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum953::GET_DATATYPE_POLICY::NONE, (maxon::UInt64) enum953::GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN, (maxon::UInt64) enum953::GET_DATATYPE_POLICY::ERROR_FOR_UNKNOWN, (maxon::UInt64) enum953::GET_DATATYPE_POLICY::NO_DECAY, (maxon::UInt64) enum953::GET_DATATYPE_POLICY::ALLOW_BASEARRAY, (maxon::UInt64) enum953::GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GET_DATATYPE_POLICY", SIZEOF(x), true, values, "NONE\0GENERIC_FOR_UNKNOWN\0ERROR_FOR_UNKNOWN\0NO_DECAY\0ALLOW_BASEARRAY\0RESULT_FOR_UNKNOWN_MASK\0", fmt);
	}
}
#endif
