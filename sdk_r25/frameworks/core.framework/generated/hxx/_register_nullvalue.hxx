#if 1
namespace maxon
{
#if !defined MAXON_COMPILER_MSVC || MAXON_COMPILER_MSVC >= 1928
#else
#endif
	namespace enum237
	{
		enum class NULL_RETURN_REASON
		{
			NULLPTR,
			MAKE_WRITABLE_FAILED,
			UNRESOLVED,
			NULLIMPL
		} ;
		static const maxon::UInt64 NULL_RETURN_REASON_values[] = {maxon::UInt64(enum237::NULL_RETURN_REASON::NULLPTR), maxon::UInt64(enum237::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED), maxon::UInt64(enum237::NULL_RETURN_REASON::UNRESOLVED), maxon::UInt64(enum237::NULL_RETURN_REASON::NULLIMPL)};
		static const maxon::EnumInfo NULL_RETURN_REASON_info{"NULL_RETURN_REASON", SIZEOF(NULL_RETURN_REASON), false, "NULLPTR\0MAKE_WRITABLE_FAILED\0UNRESOLVED\0NULLIMPL\0", NULL_RETURN_REASON_values, std::extent<decltype(NULL_RETURN_REASON_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NULL_RETURN_REASON237(){ return enum237::NULL_RETURN_REASON_info; }
#ifdef MAXON_TARGET_DEBUG
#else
#endif
}
#endif
