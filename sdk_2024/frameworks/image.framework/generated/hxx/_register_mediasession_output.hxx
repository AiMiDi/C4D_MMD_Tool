#if 1
namespace maxon
{
	namespace enum26
	{
		enum class SELECTIONHANDLERRESULT
		{
			NONE = 0,																						 // nothing to load
			STRUCTURE = (1 << 0),																 ///< load the image structure (e.g. layers, folders) but create only the layers.
			CONTENT_FLAG = (1 << 1),														 ///< load the image/layer data.
			STRUCTURE_WITH_CONTENT = (CONTENT_FLAG | STRUCTURE), ///< load the image structure and load the image/layer data.
			ALL = STRUCTURE_WITH_CONTENT,												 ///< load all (e.g. like no filter would be set).
		} ;
		static const maxon::UInt64 SELECTIONHANDLERRESULT_values[] = {maxon::UInt64(enum26::SELECTIONHANDLERRESULT::NONE), maxon::UInt64(enum26::SELECTIONHANDLERRESULT::STRUCTURE), maxon::UInt64(enum26::SELECTIONHANDLERRESULT::CONTENT_FLAG), maxon::UInt64(enum26::SELECTIONHANDLERRESULT::STRUCTURE_WITH_CONTENT), maxon::UInt64(enum26::SELECTIONHANDLERRESULT::ALL)};
		static const maxon::EnumInfo SELECTIONHANDLERRESULT_info{"SELECTIONHANDLERRESULT", SIZEOF(SELECTIONHANDLERRESULT), true, "NONE\0STRUCTURE\0CONTENT_FLAG\0STRUCTURE_WITH_CONTENT\0ALL\0", SELECTIONHANDLERRESULT_values, std::extent<decltype(SELECTIONHANDLERRESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SELECTIONHANDLERRESULT26(){ return enum26::SELECTIONHANDLERRESULT_info; }
	const maxon::Char* const MediaOutputInterface::MTable::_ids = 
		"ResetConverter@3008090429c5a175\0" // Result<void> ResetConverter()
		"SetSelectionHandler@7385c89d88f09387\0" // Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler)
		"GetSelectionHandler@de26c30080cd0492\0" // const MediaOutputSelectionHandler& GetSelectionHandler() const
		"CallSelectionHandler@aa1cb1d22acc7394\0" // Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props)
	"";
	const maxon::METHOD_FLAGS MediaOutputInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputInterface, , "net.maxon.image.interface.mediaoutput", (MediaConverterInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int MediaOutputInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<const MediaOutputSelectionHandler&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const MediaOutputTextureInterface::MTable::_ids = 
		"SetOutputTexture@8a34318e50b32986\0" // Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass)
	"";
	const maxon::METHOD_FLAGS MediaOutputTextureInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputTextureInterface, , "net.maxon.image.interface.mediaoutputtexture", (MediaOutputInterface::PrivateGetInterface()));
	const maxon::Char* const MediaOutputUrlInterface::MTable::_ids = 
		"GetOutputUrl@f0cc56ca89511da7\0" // Url GetOutputUrl() const
		"SetOutputUrl@1db4eca46d9225b9\0" // Result<void> SetOutputUrl(const Url& url)
		"GetFileFormat@fbd152031b99bea0\0" // const FileFormat& GetFileFormat() const
		"EditSystemOptions@13ce1ba7c2fda519\0" // Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle)
		"CheckBitmapSize@c72eba9c6a030261\0" // Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const
	"";
	const maxon::METHOD_FLAGS MediaOutputUrlInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaOutputUrlInterface, , "net.maxon.image.interface.mediaoutputurl", (MediaOutputInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int MediaOutputUrlInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Url>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const FileFormat&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputBaseClass, , "net.maxon.image.class.mediaoutputbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputTextureClass, , "net.maxon.image.class.mediaoutputtexture");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaOutputUrlBaseClass, , "net.maxon.image.class.mediaoutputurlbase");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_output(0
	| maxon::MediaOutputInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::MediaOutputUrlInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
