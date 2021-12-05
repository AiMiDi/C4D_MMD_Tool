
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace MEDIASESSION
{
	namespace AVI
	{
		namespace EXPORT
		{
			struct AVITYPE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5d274c39205a182eLL), maxon::UInt(41))> { };
			struct AVIHANDLER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x601f2bd93089b9d6LL), maxon::UInt(44))> { };
		}
	}
}
#ifdef MAXON_TARGET_WINDOWS
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

