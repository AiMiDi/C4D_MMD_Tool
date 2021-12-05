#if 1
namespace maxon
{
	namespace enum22 { enum class SELECTIONHANDLERRESULT
	{
		NONE = 0,																						 // nothing to load
		STRUCTURE = (1 << 0),																 ///< load the image structure (e.g. layers, folders) but create only the layers.
		CONTENT_FLAG = (1 << 1),														 ///< load the image/layer data.
		STRUCTURE_WITH_CONTENT = (CONTENT_FLAG | STRUCTURE), ///< load the image structure and load the image/layer data.
		ALL = STRUCTURE_WITH_CONTENT,												 ///< load all (e.g. like no filter would be set).
	} ; }
	maxon::String PrivateToString_SELECTIONHANDLERRESULT22(std::underlying_type<enum22::SELECTIONHANDLERRESULT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum22::SELECTIONHANDLERRESULT::NONE, (maxon::UInt64) enum22::SELECTIONHANDLERRESULT::STRUCTURE, (maxon::UInt64) enum22::SELECTIONHANDLERRESULT::CONTENT_FLAG, (maxon::UInt64) enum22::SELECTIONHANDLERRESULT::STRUCTURE_WITH_CONTENT, (maxon::UInt64) enum22::SELECTIONHANDLERRESULT::ALL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SELECTIONHANDLERRESULT", SIZEOF(x), true, values, "NONE\0STRUCTURE\0CONTENT_FLAG\0STRUCTURE_WITH_CONTENT\0ALL\0", fmt);
	}
	const maxon::Char* const MediaOutputInterface::MTable::_ids = 
		"ResetConverter@a54f4799cbe1a498\0" // Result<void> ResetConverter()
		"SetSelectionHandler@2c75c9f1a610b698\0" // Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler)
		"GetSelectionHandler@7b99381406383c77\0" // const MediaOutputSelectionHandler& GetSelectionHandler() const
		"CallSelectionHandler@900ae3dcda5150b9\0" // Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputInterface, , "net.maxon.image.interface.mediaoutput", "maxon.MediaOutputInterface", (&MediaConverterInterface::_interface));
	template <typename DUMMY> maxon::Int MediaOutputInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const MediaOutputSelectionHandler&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const MediaOutputTextureInterface::MTable::_ids = 
		"SetOutputTexture@f2f14c1d3396b033\0" // Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputTextureInterface, , "net.maxon.image.interface.mediaoutputtexture", "maxon.MediaOutputTextureInterface", (&MediaOutputInterface::_interface));
	namespace MEDIAOUTPUTURLPROPERTIES
	{
		SUPPORTS_IMAGE_PrivateAttribute SUPPORTS_IMAGE;
		SUPPORTS_VIDEO_PrivateAttribute SUPPORTS_VIDEO;
		SUPPORTS_AUDIO_PrivateAttribute SUPPORTS_AUDIO;
		SUPPORTS_SYSTEMOPTIONS_PrivateAttribute SUPPORTS_SYSTEMOPTIONS;
		MAXIMALALPHACHANNELS_PrivateAttribute MAXIMALALPHACHANNELS;
		MAXIMALIMAGERESOLUTION_PrivateAttribute MAXIMALIMAGERESOLUTION;
		MAXIMALLAYERRESOLUTION_PrivateAttribute MAXIMALLAYERRESOLUTION;
		BITDEPTHSIMAGE_PrivateAttribute BITDEPTHSIMAGE;
		BITDEPTHSLAYER_PrivateAttribute BITDEPTHSLAYER;
		EMBED_COLORPROFILE_PrivateAttribute EMBED_COLORPROFILE;
	}
	const maxon::Char* const MediaOutputUrlInterface::MTable::_ids = 
		"GetOutputUrl@4e33a06\0" // Url GetOutputUrl() const
		"SetOutputUrl@e1e93c17010d01ec\0" // Result<void> SetOutputUrl(const Url& url)
		"GetFileFormat@06c33bde295f8b8d\0" // const FileFormat& GetFileFormat() const
		"EditSystemOptions@584af9331113a50a\0" // Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle)
		"CheckBitmapSize@6a95840005a51532\0" // Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputUrlInterface, , "net.maxon.image.interface.mediaoutputurl", "maxon.MediaOutputUrlInterface", (&MediaOutputInterface::_interface));
	template <typename DUMMY> maxon::Int MediaOutputUrlInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const FileFormat&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputBaseClass, , "net.maxon.image.class.mediaoutputbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputTextureClass, , "net.maxon.image.class.mediaoutputtexture");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputUrlBaseClass, , "net.maxon.image.class.mediaoutputurlbase");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_output(0
	| maxon::MediaOutputInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::MediaOutputUrlInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
