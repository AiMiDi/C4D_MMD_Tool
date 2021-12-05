#if 1
namespace maxon
{
	namespace enum55 { enum class STATE : Int32
		{
			UNINITIALIZED = 0,
			PENDING = 1,
			INITIALIZED = 2
		} ; }
	maxon::String PrivateToString_STATE55(std::underlying_type<enum55::STATE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum55::STATE::UNINITIALIZED, (maxon::UInt64) enum55::STATE::PENDING, (maxon::UInt64) enum55::STATE::INITIALIZED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LazyInit::STATE", SIZEOF(x), false, values, "UNINITIALIZED\0PENDING\0INITIALIZED\0", fmt);
	}
#ifdef JOB_H__
#endif
}
#endif
