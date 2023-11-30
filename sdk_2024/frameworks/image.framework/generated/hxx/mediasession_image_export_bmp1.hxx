#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace BMP
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_BMP
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_BMP
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_BMP_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_BMP_EXPORT
			class RESTRICT : public BMP::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
