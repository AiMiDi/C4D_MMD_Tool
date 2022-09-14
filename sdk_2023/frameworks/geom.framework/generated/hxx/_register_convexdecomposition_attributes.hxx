#if 1
namespace maxon
{
	namespace CONVEXDECOMPOSITIONATTRIBUTES
	{
		namespace enum17
		{
			enum class DECOMPOSITION_MODE
				{
					COARSE = 0,
					MEDIUM = 1,
					FINE = 2
				} ;
			static const maxon::UInt64 DECOMPOSITION_MODE_values[] = {maxon::UInt64(enum17::DECOMPOSITION_MODE::COARSE), maxon::UInt64(enum17::DECOMPOSITION_MODE::MEDIUM), maxon::UInt64(enum17::DECOMPOSITION_MODE::FINE)};
			static const maxon::EnumInfo DECOMPOSITION_MODE_info{"DECOMPOSITION_MODE", SIZEOF(DECOMPOSITION_MODE), false, "COARSE\0MEDIUM\0FINE\0", DECOMPOSITION_MODE_values, std::extent<decltype(DECOMPOSITION_MODE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_DECOMPOSITION_MODE17(){ return enum17::DECOMPOSITION_MODE_info; }
		ASYNCH_PrivateAttribute ASYNCH;
		MODE_PrivateAttribute MODE;
		THREADCOUNT_PrivateAttribute THREADCOUNT;
	}
}
#endif
