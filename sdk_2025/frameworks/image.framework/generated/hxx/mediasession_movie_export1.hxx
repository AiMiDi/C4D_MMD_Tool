#if 1
namespace maxon
{
	namespace MEDIASESSION
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
		class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace MF
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_MF
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_MF
			class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
			namespace EXPORT
			{
			#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_MF_EXPORT
			#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_MF_EXPORT
				class RESTRICT : public MF::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
			#endif
			}
		}
	}
}
#endif
