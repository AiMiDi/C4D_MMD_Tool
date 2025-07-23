#if 1
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace AVI
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_AVI
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_AVI
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_AVI_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_AVI_EXPORT
			class RESTRICT : public AVI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#ifdef MAXON_TARGET_WINDOWS
#endif
#endif
