#if 1
namespace maxon
{
	namespace IMAGEPROPERTIES
	{
		namespace enum53
		{
			enum class ITYPE
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
				} ;
			static const maxon::UInt64 ITYPE_values[] = {maxon::UInt64(enum53::ITYPE::UNDEFINED), maxon::UInt64(enum53::ITYPE::TEXTURE), maxon::UInt64(enum53::ITYPE::IMAGE), maxon::UInt64(enum53::ITYPE::ALPHA), maxon::UInt64(enum53::ITYPE::LAYER), maxon::UInt64(enum53::ITYPE::LAYERMASK), maxon::UInt64(enum53::ITYPE::FOLDER), maxon::UInt64(enum53::ITYPE::ADJUSTMENT), maxon::UInt64(enum53::ITYPE::DEEPIMAGEDATA)};
			static const maxon::EnumInfo ITYPE_info{"ITYPE", SIZEOF(ITYPE), false, "UNDEFINED\0TEXTURE\0IMAGE\0ALPHA\0LAYER\0LAYERMASK\0FOLDER\0ADJUSTMENT\0DEEPIMAGEDATA\0", ITYPE_values, std::extent<decltype(ITYPE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_ITYPE53(){ return enum53::ITYPE_info; }
		TYPE_PrivateAttribute TYPE;
		NAME_PrivateAttribute NAME;
		ALPHANAME_PrivateAttribute ALPHANAME;
		namespace TEXTURE
		{
			FILEFORMAT_PrivateAttribute FILEFORMAT;
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
	namespace enum117
	{
		enum class IMAGEHIERARCHY
		{
			TEXTURE,				///< Root of everything. Must not be used with AddChildren.
			IMAGE,					///< Adds a subImage to a texture. Images are only allowed under Textures.
			ALPHA,					///< Adds an alpha to a image. Alphas are allowed to insert under images.
			LAYER,					///< Adds an image layer to a image. Layers are only allowed under Images or other layers.
			MASK,						///< Adds a layer mask to a layer. Layer masks are allowed to insert under layers (layer mask).
			DEEPIMAGEDATA,	///< Adds deep image data to an image. Allowed to insert under images.
			MAX_ELEMENTS,
		} ;
		static const maxon::UInt64 IMAGEHIERARCHY_values[] = {maxon::UInt64(enum117::IMAGEHIERARCHY::TEXTURE), maxon::UInt64(enum117::IMAGEHIERARCHY::IMAGE), maxon::UInt64(enum117::IMAGEHIERARCHY::ALPHA), maxon::UInt64(enum117::IMAGEHIERARCHY::LAYER), maxon::UInt64(enum117::IMAGEHIERARCHY::MASK), maxon::UInt64(enum117::IMAGEHIERARCHY::DEEPIMAGEDATA), maxon::UInt64(enum117::IMAGEHIERARCHY::MAX_ELEMENTS)};
		static const maxon::EnumInfo IMAGEHIERARCHY_info{"IMAGEHIERARCHY", SIZEOF(IMAGEHIERARCHY), false, "TEXTURE\0IMAGE\0ALPHA\0LAYER\0MASK\0DEEPIMAGEDATA\0MAX_ELEMENTS\0", IMAGEHIERARCHY_values, std::extent<decltype(IMAGEHIERARCHY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IMAGEHIERARCHY117(){ return enum117::IMAGEHIERARCHY_info; }
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ImageBaseInterface::MTable::_ids = 
		"InitBase@f54123a46f81b96e\0" // Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type)
		"AddChildren@d4c7f905e9354221\0" // Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore)
		"GetWidth@7d0e6f3d29c239e7\0" // Int GetWidth() const
		"GetHeight@7d0e6f3d29c239e7\0" // Int GetHeight() const
		"GetChannelCount@7d0e6f3d29c239e7\0" // Int GetChannelCount() const
		"GetPixelFormat@8b8260adda7d69d9\0" // PixelFormat GetPixelFormat() const
		"GetPixelHandler@83255b216406660b\0" // Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const
		"SetPixelHandler@d2746ef4a662a48e\0" // Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags)
/// @cond INTERNAL

		"FreePixelHandler@940fb7680bc396b9\0" // void FreePixelHandler(GetPixelHandlerStruct& pixel) const
		"FreePixelHandler@4e7790fa5ea63c65\0" // void FreePixelHandler(SetPixelHandlerStruct& pixel) const
/// @endcond

		"GetComponent@3056c68bbd120ddf\0" // Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
		"SetComponent@32ef25d2e51865d6\0" // Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
		"CreateSubImagePart@c517c87eb2cb7430\0" // Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const
		"ObservableRegionChanged@99b45c0ccb3be545\0" // maxon::ObservableRef<ObservableRegionChangedDelegate> ObservableRegionChanged() const
	"";
	const maxon::METHOD_FLAGS ImageBaseInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
/// @cond INTERNAL

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
/// @endcond

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(ImageBaseInterface, ImageBaseInterface, , , "net.maxon.image.interface.imagebase", "maxon.ImageBaseInterface", (DataDictionaryObjectInterface::PrivateGetInterface()), (HierarchyObjectInterface::PrivateGetInterface()), nullptr);
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
		if (maxon::details::NullReturnType<Result<ImageTextureRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ImageTextureInterface_LoadTexture = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageTextureInterface_LoadTexture;
		#else
		tbl->ImageTextureInterface_LoadTexture = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageTextureInterface_LoadTexture;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ImageTextureInterface::MTable::_ids = 
		"Load@f628892561d23948\0" // Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
		"Save@8153e43e014956de\0" // Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const
	"";
	const maxon::METHOD_FLAGS ImageTextureInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageTextureInterface, , "net.maxon.image.interface.imagetexture", "maxon.ImageTextureInterface", (ImageBaseInterface::PrivateGetInterface()));
	const maxon::Char* const ImageTextureInterface::Hxx2::StaticMTable::_ids = 
		"LoadTexture@790cb2a757e10c55\0" // Result<ImageTextureRef> LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ImageTextureInterface, , "net.maxon.image.interface.imagetexture");
	const maxon::Char* const ImageInterface::MTable::_ids = 
		"Init@58ab16784dea9071\0" // Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor)
	"";
	const maxon::METHOD_FLAGS ImageInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageInterface, , "net.maxon.image.interface.image", "maxon.ImageInterface", (ImageBaseInterface::PrivateGetInterface()));
	const maxon::Char* const ImageLayerInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS ImageLayerInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageLayerInterface, , "net.maxon.image.interface.imagelayer", "maxon.ImageLayerInterface", (ImageInterface::PrivateGetInterface()));
	const maxon::Char* const ImageFunctionsInterface::MTable::_ids = 
		"CreateSubImagePart@8d99d0879b54f259\0" // Result<ImageBaseRef> CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect)
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
		if (maxon::details::NullReturnType<Result<ImageBaseRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ImageFunctionsInterface_CreateSubImagePart = &Hxx2::Wrapper<Hxx2::Unresolved>::ImageFunctionsInterface_CreateSubImagePart;
		#else
		tbl->ImageFunctionsInterface_CreateSubImagePart = &Hxx2::Wrapper<Hxx2::Unresolved>::ImageFunctionsInterface_CreateSubImagePart;
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
