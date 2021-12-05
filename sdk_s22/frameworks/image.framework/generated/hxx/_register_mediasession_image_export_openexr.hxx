#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace MEDIASESSION
	{
		namespace OPENEXR
		{
			namespace EXPORT
			{
				COMPRESSIONMETHOD_PrivateAttribute COMPRESSIONMETHOD;
				HALFFLOAT_PrivateAttribute HALFFLOAT;
				LAYERNUMBERING_PrivateAttribute LAYERNUMBERING;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OpenExr, , MEDIASESSION::OPENEXR::EXPORT::GetId());
	}
}
#endif
