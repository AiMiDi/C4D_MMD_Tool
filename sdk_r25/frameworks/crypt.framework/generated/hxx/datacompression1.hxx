#if 1
namespace STREAMCONVERSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION
#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace GZIP
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_GZIP
	#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_GZIP
		class RESTRICT : public STREAMCONVERSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace ENCODER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_GZIP_ENCODER
		#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_GZIP_ENCODER
			class RESTRICT : public GZIP::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
	namespace LZ4
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4
	#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4
		class RESTRICT : public STREAMCONVERSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace DECODER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4_DECODER
		#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4_DECODER
			class RESTRICT : public LZ4::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
		namespace ENCODER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4_ENCODER
		#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_LZ4_ENCODER
			class RESTRICT : public LZ4::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
	namespace ZIP
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_ZIP
	#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_ZIP
		class RESTRICT : public STREAMCONVERSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace ENCODER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_ZIP_ENCODER
		#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSION_ZIP_ENCODER
			class RESTRICT : public ZIP::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
#endif
