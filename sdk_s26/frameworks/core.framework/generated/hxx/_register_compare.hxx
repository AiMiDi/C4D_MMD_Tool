#if 1
#ifndef APIBASE_H__
#endif
namespace maxon
{
	namespace enum26
	{
		enum class COMPARERESULT
		{
			LESS				 = -1,	///< result is less than
			EQUAL				 =  0,	///< result is equal
			GREATER			 =  1,	///< result is greater than
			INCOMPARABLE = -2		///< values are incomparable (either a compare function doesn't exist, or we have a partial order)
		} ;
		static const maxon::UInt64 COMPARERESULT_values[] = {maxon::UInt64(enum26::COMPARERESULT::LESS), maxon::UInt64(enum26::COMPARERESULT::EQUAL), maxon::UInt64(enum26::COMPARERESULT::GREATER), maxon::UInt64(enum26::COMPARERESULT::INCOMPARABLE)};
		static const maxon::EnumInfo COMPARERESULT_info{"COMPARERESULT", SIZEOF(COMPARERESULT), false, "LESS\0EQUAL\0GREATER\0INCOMPARABLE\0", COMPARERESULT_values, std::extent<decltype(COMPARERESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COMPARERESULT26(){ return enum26::COMPARERESULT_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_COMPARERESULT, , "net.maxon.datatype.enum.compareresult");
	namespace enum37
	{
		enum class EQUALITY
		{
			SHALLOW,	///< A shallow equality-test shall be done. For pointers or (non-copy-on-write) references the object identity (pointer value) is used.
			DEEP			///< A deep equality-test shall be done. For pointers or (non-copy-on-write) references the referenced objects are compared for equality.
		} ;
		static const maxon::UInt64 EQUALITY_values[] = {maxon::UInt64(enum37::EQUALITY::SHALLOW), maxon::UInt64(enum37::EQUALITY::DEEP)};
		static const maxon::EnumInfo EQUALITY_info{"EQUALITY", SIZEOF(EQUALITY), false, "SHALLOW\0DEEP\0", EQUALITY_values, std::extent<decltype(EQUALITY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_EQUALITY37(){ return enum37::EQUALITY_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_EQUALITY, , "net.maxon.datatype.enum.equality");
#ifdef MAXON_TARGET_WINDOWS
#endif
}
#endif
