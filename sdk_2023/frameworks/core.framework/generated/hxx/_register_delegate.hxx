#if 1
namespace maxon
{
	namespace enum21
	{
		enum class CALLBACKMODE
			{
				ALLOC = 0,								///< Allocates memory for an object.
				DESTRUCT_AND_RELEASE = 1,	///< Destructs the object to which dst points and releases the memory.
				COPY = 2,									///< Copies the object from src to dst and returns the size on success (0 on failure).
				MOVE_AND_DESTRUCT = 3			///< Moves the object from src to dst and returns the size (only used for internal storage, cannot fail).
			} ;
		static const maxon::UInt64 CALLBACKMODE_values[] = {maxon::UInt64(enum21::CALLBACKMODE::ALLOC), maxon::UInt64(enum21::CALLBACKMODE::DESTRUCT_AND_RELEASE), maxon::UInt64(enum21::CALLBACKMODE::COPY), maxon::UInt64(enum21::CALLBACKMODE::MOVE_AND_DESTRUCT)};
		static const maxon::EnumInfo CALLBACKMODE_info{"DelegateBase::CALLBACKMODE", SIZEOF(CALLBACKMODE), false, "ALLOC\0DESTRUCT_AND_RELEASE\0COPY\0MOVE_AND_DESTRUCT\0", CALLBACKMODE_values, std::extent<decltype(CALLBACKMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CALLBACKMODE21(void*){ return enum21::CALLBACKMODE_info; }
#ifdef PRIVATE_MAXON_MTABLE_PTMF
#else
#endif
#ifdef MAXON_TARGET_64BIT
#else
#endif
	namespace details
	{
#ifdef PRIVATE_MAXON_MTABLE_PTMF
#else
#endif
	}
#ifdef PRIVATE_MAXON_MTABLE_PTMF
#else
#endif
#ifdef PRIVATE_MAXON_MTABLE_PTMF
#else
#endif
#ifdef PRIVATE_MAXON_MTABLE_PTMF
#else
#endif
}
#endif
