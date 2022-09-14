#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace DPX
		{
			namespace EXPORT
			{
				BITDEPTH_PrivateAttribute BITDEPTH;
				PLANAR_PrivateAttribute PLANAR;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Dpx, , MEDIASESSION::DPX::EXPORT::GetId());
	}
}
#endif
