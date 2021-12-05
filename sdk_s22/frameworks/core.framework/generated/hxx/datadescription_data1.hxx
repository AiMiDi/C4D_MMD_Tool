#if 1
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
