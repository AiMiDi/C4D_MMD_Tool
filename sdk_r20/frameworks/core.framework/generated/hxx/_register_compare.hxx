#if 1
#if 1
#endif
namespace maxon
{
	namespace enum26 { enum class COMPARERESULT
	{
		LESS				 = -1,	///< result is less than
		EQUAL				 =  0,	///< result is equal
		GREATER			 =  1,	///< result is greater than
		INCOMPARABLE = -2		///< values are incomparable (either a compare function doesn't exist, or we have a partial order)
	} ; }
	maxon::String PrivateToString_COMPARERESULT26(std::underlying_type<enum26::COMPARERESULT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum26::COMPARERESULT::LESS, (maxon::UInt64) enum26::COMPARERESULT::EQUAL, (maxon::UInt64) enum26::COMPARERESULT::GREATER, (maxon::UInt64) enum26::COMPARERESULT::INCOMPARABLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COMPARERESULT", SIZEOF(x), false, values, "LESS\0EQUAL\0GREATER\0INCOMPARABLE\0", fmt);
	}
	maxon::Id PrivateGetEnumId(COMPARERESULT*) { return maxon::Id("net.maxon.datatype.enum.compareresult"); }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_COMPARERESULT, , "net.maxon.datatype.enum.compareresult");
	namespace enum37 { enum class EQUALITY
	{
		SHALLOW,	///< A shallow equality-test shall be done. For pointers or (non-copy-on-write) references the object identity (pointer value) is used.
		DEEP			///< A deep equality-test shall be done. For pointers or (non-copy-on-write) references the referenced objects are compared for equality.
	} ; }
	maxon::String PrivateToString_EQUALITY37(std::underlying_type<enum37::EQUALITY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum37::EQUALITY::SHALLOW, (maxon::UInt64) enum37::EQUALITY::DEEP};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "EQUALITY", SIZEOF(x), false, values, "SHALLOW\0DEEP\0", fmt);
	}
	maxon::Id PrivateGetEnumId(EQUALITY*) { return maxon::Id("net.maxon.datatype.enum.equality"); }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_EQUALITY, , "net.maxon.datatype.enum.equality");
#ifdef MAXON_TARGET_64BIT
#else
#endif
#ifdef MAXON_TARGET_WINDOWS
#endif
}
#endif
