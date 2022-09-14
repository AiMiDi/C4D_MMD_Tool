#if 1
namespace maxon
{
	namespace enum56
	{
		enum class STATE : Int32
			{
				UNINITIALIZED = 0,
				PENDING = 1,
				INITIALIZED = 2
			} ;
		static const maxon::UInt64 STATE_values[] = {maxon::UInt64(enum56::STATE::UNINITIALIZED), maxon::UInt64(enum56::STATE::PENDING), maxon::UInt64(enum56::STATE::INITIALIZED)};
		static const maxon::EnumInfo STATE_info{"LazyInit::STATE", SIZEOF(STATE), false, "UNINITIALIZED\0PENDING\0INITIALIZED\0", STATE_values, std::extent<decltype(STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STATE56(void*){ return enum56::STATE_info; }
}
#endif
