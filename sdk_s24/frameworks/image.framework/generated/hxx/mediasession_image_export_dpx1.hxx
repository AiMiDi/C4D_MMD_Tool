#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace DPX
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_DPX
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_DPX
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_DPX_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_DPX_EXPORT
			class RESTRICT : public DPX::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
