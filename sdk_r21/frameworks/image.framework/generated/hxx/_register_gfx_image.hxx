#if 1
namespace maxon
{
	namespace IMAGEPROPERTIES
	{
		namespace enum53 { enum class ITYPE
			{
				UNDEFINED,
				TEXTURE,
				IMAGE,
				ALPHA,
				LAYER,
				LAYERMASK,
				FOLDER,
				ADJUSTMENT,
				DEEPIMAGEDATA,
			} ; }
		maxon::String PrivateToString_ITYPE53(std::underlying_type<enum53::ITYPE>::type x, const maxon::FormatStatement* fmt)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum53::ITYPE::UNDEFINED, (maxon::UInt64) enum53::ITYPE::TEXTURE, (maxon::UInt64) enum53::ITYPE::IMAGE, (maxon::UInt64) enum53::ITYPE::ALPHA, (maxon::UInt64) enum53::ITYPE::LAYER, (maxon::UInt64) enum53::ITYPE::LAYERMASK, (maxon::UInt64) enum53::ITYPE::FOLDER, (maxon::UInt64) enum53::ITYPE::ADJUSTMENT, (maxon::UInt64) enum53::ITYPE::DEEPIMAGEDATA};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ITYPE", SIZEOF(x), false, values, "UNDEFINED\0TEXTURE\0IMAGE\0ALPHA\0LAYER\0LAYERMASK\0FOLDER\0ADJUSTMENT\0DEEPIMAGEDATA\0", fmt);
		}
		TYPE_PrivateAttribute TYPE;
		NAME_PrivateAttribute NAME;
		ALPHANAME_PrivateAttribute ALPHANAME;
		namespace TEXTURE
		{
			AUDIODATA_PrivateAttribute AUDIODATA;
		}
		namespace IMAGE
		{
			ASPECTRATIO_PrivateAttribute ASPECTRATIO;
			DPI_PrivateAttribute DPI;
			COLORPROFILE_PrivateAttribute COLORPROFILE;
			FPS_PrivateAttribute FPS;
			DURATION_PrivateAttribute DURATION;
			SAMPLETIME_PrivateAttribute SAMPLETIME;
			EXPORTSETTINGS_PrivateAttribute EXPORTSETTINGS;
			HOTSPOTX_PrivateAttribute HOTSPOTX;
			HOTSPOTY_PrivateAttribute HOTSPOTY;
			SUBIMAGEINDEX_PrivateAttribute SUBIMAGEINDEX;
		}
		namespace LAYER
		{
			ENABLED_PrivateAttribute ENABLED;
			BLENDMODE_PrivateAttribute BLENDMODE;
			OPACITY_PrivateAttribute OPACITY;
			FILLOPACITY_PrivateAttribute FILLOPACITY;
			TRANSPARENCYPROTECTED_PrivateAttribute TRANSPARENCYPROTECTED;
			LAYERGROUP_PrivateAttribute LAYERGROUP;
			MASKDEFCOLOR_PrivateAttribute MASKDEFCOLOR;
			BOUNDINGBOX_X_PrivateAttribute BOUNDINGBOX_X;
			BOUNDINGBOX_Y_PrivateAttribute BOUNDINGBOX_Y;
			BOUNDINGBOX_W_PrivateAttribute BOUNDINGBOX_W;
			BOUNDINGBOX_H_PrivateAttribute BOUNDINGBOX_H;
			namespace FOLDER
			{
				ISOPEN_PrivateAttribute ISOPEN;
			}
			namespace ADJUSTMENT
			{
				PSD_FILTERID_PrivateAttribute PSD_FILTERID;
				PSD_DATA_PrivateAttribute PSD_DATA;
			}
		}
	}
	namespace enum116 { enum class IMAGEHIERARCHY
	{
		TEXTURE,				///< Root of everything. Must not be used with AddChildren.
		IMAGE,					///< Adds a subImage to a texture. Images are only allowed under Textures.
		ALPHA,					///< Adds an alpha to a image. Alphas are allowed to insert under images.
		LAYER,					///< Adds an image layer to a image. Layers are only allowed under Images or other layers.
		MASK,						///< Adds a layer mask to a layer. Layer masks are allowed to insert under layers (layer mask).
		DEEPIMAGEDATA,	///< Adds deep image data to an image. Allowed to insert under images.
		MAX_ELEMENTS,
	} ; }
	maxon::String PrivateToString_IMAGEHIERARCHY116(std::underlying_type<enum116::IMAGEHIERARCHY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum116::IMAGEHIERARCHY::TEXTURE, (maxon::UInt64) enum116::IMAGEHIERARCHY::IMAGE, (maxon::UInt64) enum116::IMAGEHIERARCHY::ALPHA, (maxon::UInt64) enum116::IMAGEHIERARCHY::LAYER, (maxon::UInt64) enum116::IMAGEHIERARCHY::MASK, (maxon::UInt64) enum116::IMAGEHIERARCHY::DEEPIMAGEDATA, (maxon::UInt64) enum116::IMAGEHIERARCHY::MAX_ELEMENTS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IMAGEHIERARCHY", SIZEOF(x), false, values, "TEXTURE\0IMAGE\0ALPHA\0LAYER\0MASK\0DEEPIMAGEDATA\0MAX_ELEMENTS\0", fmt);
	}
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ImageBaseInterface::MTable::_ids = 
		"InitBase@23a7ade18ca16609\0" // Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type)
		"AddChildren@89ddd66b9ad65efe\0" // Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore)
		"GetWidth@4386c86\0" // Int GetWidth() const
		"GetHeight@4386c86\0" // Int GetHeight() const
		"GetChannelCount@4386c86\0" // Int GetChannelCount() const
		"GetPixelFormat@90e8ba3989f75b34\0" // PixelFormat GetPixelFormat() const
		"GetPixelHandler@c2c67003a0ed48f6\0" // Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const
		"SetPixelHandler@c87bfab7eac1636f\0" // Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags)
/// @cond INTERNAL

		"FreePixelHandler@ebc685a3edcb7bd4\0" // void FreePixelHandler(GetPixelHandlerStruct& pixel) const
		"FreePixelHandler@50eb4c73681eaae0\0" // void FreePixelHandler(SetPixelHandlerStruct& pixel) const
/// @endcond

		"GetComponent@b860f8ea3c0c8570\0" // Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
		"SetComponent@52e00d08ba432ab3\0" // Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
		"CreateSubImagePart@0c61977285a74313\0" // Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const
		"ObservableRegionChanged@b2df5d1998256aa2\0" // maxon::ObservableRef<ObservableRegionChangedDelegate> ObservableRegionChanged() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(ImageBaseInterface, ImageBaseInterface, , , "net.maxon.image.interface.imagebase", "maxon.ImageBaseInterface", (&DataDictionaryObjectInterface::_interface), (&HierarchyObjectInterface::_interface), nullptr);
	template <typename DUMMY> maxon::Int ImageBaseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PixelFormat>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageTextureInterface::Hxx2::Unresolved : public ImageTextureInterface
	{
	public:
		static Result<ImageTextureRef> LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImageTextureInterface::LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ImageTextureInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<ImageTextureRef>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageTextureInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ImageTextureRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ImageTextureInterface_LoadTexture = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ImageTextureInterface_LoadTexture;
		#else
		tbl->_ImageTextureInterface_LoadTexture = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ImageTextureInterface_LoadTexture;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ImageTextureInterface::MTable::_ids = 
		"Load@33dc3fb4ca9b95c7\0" // Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
		"Save@1d59106c69aeb391\0" // Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageTextureInterface, , "net.maxon.image.interface.imagetexture", "maxon.ImageTextureInterface", (&ImageBaseInterface::_interface));
	const maxon::Char* const ImageTextureInterface::Hxx2::StaticMTable::_ids = 
		"LoadTexture@839e3d2610e1fb6a\0" // Result<ImageTextureRef> LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ImageTextureInterface, , "net.maxon.image.interface.imagetexture");
	const maxon::Char* const ImageInterface::MTable::_ids = 
		"Init@0846b35e80daeac0\0" // Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageInterface, , "net.maxon.image.interface.image", "maxon.ImageInterface", (&ImageBaseInterface::_interface));
	const maxon::Char* const ImageLayerInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageLayerInterface, , "net.maxon.image.interface.imagelayer", "maxon.ImageLayerInterface", (&ImageInterface::_interface));
	const maxon::Char* const ImageFunctionsInterface::MTable::_ids = 
		"CreateSubImagePart@27bd1a21c5150292\0" // Result<ImageBaseRef> CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageFunctionsInterface::Hxx2::Unresolved : public ImageFunctionsInterface
	{
	public:
		static const Unresolved* Get(const ImageFunctionsInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ImageFunctionsInterface* o) { return (Unresolved*) o; }
		static Result<ImageBaseRef> CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ImageFunctionsInterface::CreateSubImagePart(imageRef, rect); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ImageFunctionsInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<ImageBaseRef>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageFunctionsInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ImageBaseRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ImageFunctionsInterface_CreateSubImagePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_ImageFunctionsInterface_CreateSubImagePart;
		#else
		tbl->_ImageFunctionsInterface_CreateSubImagePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_ImageFunctionsInterface_CreateSubImagePart;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ImageFunctionsInterface, "net.maxon.image.interface.imagefunctions", nullptr);
	MAXON_REGISTRY_REGISTER(ImageBaseClasses);
	MAXON_REGISTRY_REGISTER(ImageTextureClasses);
	MAXON_REGISTRY_REGISTER(ImageClasses);
	MAXON_REGISTRY_REGISTER(ImageLayerClasses);
	namespace ImageBaseClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BASE, , "net.maxon.image.imagebaseclass.base");
	}
	namespace ImageTextureClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(TEXTURE, , "net.maxon.image.imagetextureclass.texture");
	}
	namespace ImageClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IMAGE, , "net.maxon.image.imageclass.image");
	}
	namespace ImageLayerClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RASTER, , "net.maxon.image.imagelayerclass.raster");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image(0
	| maxon::ImageBaseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);