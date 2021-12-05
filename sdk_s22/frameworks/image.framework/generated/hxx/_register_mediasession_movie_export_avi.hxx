#if 1
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace AVI
		{
			namespace EXPORT
			{
				AVITYPE_PrivateAttribute AVITYPE;
				AVIHANDLER_PrivateAttribute AVIHANDLER;
			}
		}
	}
#ifdef MAXON_TARGET_WINDOWS
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Avi, , MEDIASESSION::AVI::EXPORT::GetId());
	}
#endif
}
#endif
