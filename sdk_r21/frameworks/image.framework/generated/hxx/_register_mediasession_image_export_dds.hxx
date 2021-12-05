#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace DDS
		{
			namespace EXPORT
			{
				COMPRESSION_PrivateAttribute COMPRESSION;
				MIPMAPS_PrivateAttribute MIPMAPS;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Dds, , MEDIASESSION::DDS::EXPORT::GetId());
	}
}
#endif
