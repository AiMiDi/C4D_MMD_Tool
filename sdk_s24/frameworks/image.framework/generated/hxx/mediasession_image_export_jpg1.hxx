#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace JPG
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_JPG
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_JPG
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_JPG_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_JPG_EXPORT
			class RESTRICT : public JPG::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
