#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace rla
{
	constexpr inline const maxon::Char* DT_MAXRenderInfo_CppName() { return "maxon::rla::MAXRenderInfo"; }
}
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace RLA
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RLA
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RLA
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RLA_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RLA_EXPORT
			class RESTRICT : public RLA::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
	namespace RPF
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RPF
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RPF
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace EXPORT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RPF_EXPORT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_RPF_EXPORT
			class RESTRICT : public RPF::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
