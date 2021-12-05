#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace TIFF
		{
			namespace EXPORT
			{
				BYTEORDER_PrivateAttribute BYTEORDER;
				COMPRESSION_PrivateAttribute COMPRESSION;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Tif, , MEDIASESSION::TIFF::EXPORT::GetId());
	}
}
#endif
