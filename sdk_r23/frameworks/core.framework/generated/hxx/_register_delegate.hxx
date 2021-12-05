#if 1
namespace maxon
{
	namespace enum21 { enum class CALLBACKMODE
		{
			ALLOC = 0,								///< Allocates memory for an object.
			DESTRUCT_AND_RELEASE = 1,	///< Destructs the object to which dst points and releases the memory.
			COPY = 2,									///< Copies the object from src to dst and returns the size on success (0 on failure).
			MOVE_AND_DESTRUCT = 3			///< Moves the object from src to dst and returns the size (only used for internal storage, cannot fail).
		} ; }
	maxon::String PrivateToString_CALLBACKMODE21(std::underlying_type<enum21::CALLBACKMODE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::CALLBACKMODE::ALLOC, (maxon::UInt64) enum21::CALLBACKMODE::DESTRUCT_AND_RELEASE, (maxon::UInt64) enum21::CALLBACKMODE::COPY, (maxon::UInt64) enum21::CALLBACKMODE::MOVE_AND_DESTRUCT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DelegateBase::CALLBACKMODE", SIZEOF(x), false, values, "ALLOC\0DESTRUCT_AND_RELEASE\0COPY\0MOVE_AND_DESTRUCT\0", fmt);
	}
#ifdef MAXON_TARGET_64BIT
#else
#endif
}
#endif
