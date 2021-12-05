
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace ASF
		{
			namespace EXPORT
			{
			}
		}
		namespace GP3
		{
			namespace EXPORT
			{
			}
		}
		namespace MF
		{
			namespace EXPORT
			{
				struct CODEC_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xbf3351542ee9a991LL), maxon::UInt(38))> { };
				struct AUDIO_CODEC_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x8aea670e8e133139LL), maxon::UInt(44))> { };
				struct AUDIO_SAMPLERATE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9355b8b96f4ffa47LL), maxon::UInt(49))> { };
				struct AUDIO_KILOBITRATE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd74ad2706fa85bcfLL), maxon::UInt(50))> { };
			}
		}
		namespace MOV
		{
			namespace EXPORT
			{
			}
		}
		namespace MP4
		{
			namespace EXPORT
			{
			}
		}
		namespace WMV
		{
			namespace EXPORT
			{
			}
		}
	}
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

