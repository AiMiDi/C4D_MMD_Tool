#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace BMP
		{
			namespace EXPORT
			{
				BITMAPINFOHEADER_PrivateAttribute BITMAPINFOHEADER;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Bmp, , MEDIASESSION::BMP::EXPORT::GetId());
	}
}
#endif
