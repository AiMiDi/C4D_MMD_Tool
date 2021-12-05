#if 1
namespace maxon
{
	namespace DESCRIPTION
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
	#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
		class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace STRING
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_STRING
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_STRING
			class RESTRICT : public DESCRIPTION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
			namespace BASE
			{
			#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_STRING_BASE
			#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_STRING_BASE
				class RESTRICT : public STRING::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
			#endif
			}
		}
	}
	namespace OBJECT
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_OBJECT
	#define PRIVATE_MAXON_GUARD_maxon_OBJECT
		class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace BASE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_OBJECT_BASE
		#define PRIVATE_MAXON_GUARD_maxon_OBJECT_BASE
			class RESTRICT : public OBJECT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
