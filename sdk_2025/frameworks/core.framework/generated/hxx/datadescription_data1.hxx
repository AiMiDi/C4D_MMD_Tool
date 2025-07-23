#if 1
constexpr inline const maxon::Char* DT_VariadicIdsElement_CppName() { return "maxon::VariadicIdsElement"; }
namespace DESCRIPTION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace BASE
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE
	#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE
		class RESTRICT : public DESCRIPTION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace INCLUDE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE_INCLUDE
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE_INCLUDE
			class RESTRICT : public BASE::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
			namespace GROUP
			{
			#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE_INCLUDE_GROUP
			#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_BASE_INCLUDE_GROUP
				class RESTRICT : public INCLUDE::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
			#endif
			}
		}
	}
	namespace CLASSIFICATION
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_CLASSIFICATION
	#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_CLASSIFICATION
		class RESTRICT : public DESCRIPTION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace BASE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_CLASSIFICATION_BASE
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_CLASSIFICATION_BASE
			class RESTRICT : public CLASSIFICATION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
	namespace DATA
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA
	#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA
		class RESTRICT : public DESCRIPTION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace BASE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA_BASE
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA_BASE
			class RESTRICT : public DATA::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
		namespace INFO
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA_INFO
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_DATA_INFO
			class RESTRICT : public DATA::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
