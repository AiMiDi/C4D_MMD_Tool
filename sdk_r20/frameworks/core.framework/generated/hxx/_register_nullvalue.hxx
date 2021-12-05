#if 1
namespace maxon
{
#ifndef MAXON_COMPILER_MSVC
#else
#endif
	namespace enum237 { enum class NULL_RETURN_REASON
	{
		NULLPTR,
		MAKE_WRITABLE_FAILED,
		UNRESOLVED,
		NULLIMPL
	} ; }
	maxon::String PrivateToString_NULL_RETURN_REASON237(std::underlying_type<enum237::NULL_RETURN_REASON>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum237::NULL_RETURN_REASON::NULLPTR, (maxon::UInt64) enum237::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED, (maxon::UInt64) enum237::NULL_RETURN_REASON::UNRESOLVED, (maxon::UInt64) enum237::NULL_RETURN_REASON::NULLIMPL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NULL_RETURN_REASON", SIZEOF(x), false, values, "NULLPTR\0MAKE_WRITABLE_FAILED\0UNRESOLVED\0NULLIMPL\0", fmt);
	}
#ifdef MAXON_TARGET_DEBUG
#else
#endif
}
#endif
