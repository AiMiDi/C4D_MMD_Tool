#if 1
namespace maxon
{
	namespace enum36
	{
		enum class CONVERTPIXELFLAGS
		{
			NONE													= 0,				///< no options set.
			FORCECOLORPROFILECONVERSION		= (1 << 0),	///< if set it forces color profile conversion even if the color space are identical, otherwise the conversion will be performed only if the color spaces are different.
		} ;
		static const maxon::UInt64 CONVERTPIXELFLAGS_values[] = {maxon::UInt64(enum36::CONVERTPIXELFLAGS::NONE), maxon::UInt64(enum36::CONVERTPIXELFLAGS::FORCECOLORPROFILECONVERSION)};
		static const maxon::EnumInfo CONVERTPIXELFLAGS_info{"CONVERTPIXELFLAGS", SIZEOF(CONVERTPIXELFLAGS), true, "NONE\0FORCECOLORPROFILECONVERSION\0", CONVERTPIXELFLAGS_values, std::extent<decltype(CONVERTPIXELFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONVERTPIXELFLAGS36(){ return enum36::CONVERTPIXELFLAGS_info; }
	namespace enum48
	{
		enum class GETPIXELHANDLERFLAGS
		{
			NONE,																		///< no options set.
			FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																							///< the conversion will be performed only if the color spaces are different.
			DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
			DONTAPPLYMASK = (1 << 2),								///< do not apply the alpha layer to the image data.
		} ;
		static const maxon::UInt64 GETPIXELHANDLERFLAGS_values[] = {maxon::UInt64(enum48::GETPIXELHANDLERFLAGS::NONE), maxon::UInt64(enum48::GETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION), maxon::UInt64(enum48::GETPIXELHANDLERFLAGS::DEEPIMAGE), maxon::UInt64(enum48::GETPIXELHANDLERFLAGS::DONTAPPLYMASK)};
		static const maxon::EnumInfo GETPIXELHANDLERFLAGS_info{"GETPIXELHANDLERFLAGS", SIZEOF(GETPIXELHANDLERFLAGS), true, "NONE\0FORCECOLORPROFILECONVERSION\0DEEPIMAGE\0DONTAPPLYMASK\0", GETPIXELHANDLERFLAGS_values, std::extent<decltype(GETPIXELHANDLERFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_GETPIXELHANDLERFLAGS48(){ return enum48::GETPIXELHANDLERFLAGS_info; }
	namespace enum58
	{
		enum class GETPIXELFLAGS
		{
			NONE,									///< no options set.
			DEEPIMAGE = (1 << 1), ///< provided a DeepImageConst/MutableBuffer structure.
		} ;
		static const maxon::UInt64 GETPIXELFLAGS_values[] = {maxon::UInt64(enum58::GETPIXELFLAGS::NONE), maxon::UInt64(enum58::GETPIXELFLAGS::DEEPIMAGE)};
		static const maxon::EnumInfo GETPIXELFLAGS_info{"GETPIXELFLAGS", SIZEOF(GETPIXELFLAGS), true, "NONE\0DEEPIMAGE\0", GETPIXELFLAGS_values, std::extent<decltype(GETPIXELFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_GETPIXELFLAGS58(){ return enum58::GETPIXELFLAGS_info; }
	namespace enum72
	{
		enum class SETPIXELHANDLERFLAGS
		{
			/// No options set.
			NONE = 0,
			FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																							///< the conversion will be performed only if the color spaces are different.
			DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
		} ;
		static const maxon::UInt64 SETPIXELHANDLERFLAGS_values[] = {maxon::UInt64(enum72::SETPIXELHANDLERFLAGS::NONE), maxon::UInt64(enum72::SETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION), maxon::UInt64(enum72::SETPIXELHANDLERFLAGS::DEEPIMAGE)};
		static const maxon::EnumInfo SETPIXELHANDLERFLAGS_info{"SETPIXELHANDLERFLAGS", SIZEOF(SETPIXELHANDLERFLAGS), true, "NONE\0FORCECOLORPROFILECONVERSION\0DEEPIMAGE\0", SETPIXELHANDLERFLAGS_values, std::extent<decltype(SETPIXELHANDLERFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SETPIXELHANDLERFLAGS72(){ return enum72::SETPIXELHANDLERFLAGS_info; }
	namespace enum81
	{
		enum class SETPIXELFLAGS
		{
			NONE = 0,							///< No options set.
			DEEPIMAGE = (1 << 1), ///< provided a DeepImagePixelConst/MutableBuffer.
		} ;
		static const maxon::UInt64 SETPIXELFLAGS_values[] = {maxon::UInt64(enum81::SETPIXELFLAGS::NONE), maxon::UInt64(enum81::SETPIXELFLAGS::DEEPIMAGE)};
		static const maxon::EnumInfo SETPIXELFLAGS_info{"SETPIXELFLAGS", SIZEOF(SETPIXELFLAGS), true, "NONE\0DEEPIMAGE\0", SETPIXELFLAGS_values, std::extent<decltype(SETPIXELFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SETPIXELFLAGS81(){ return enum81::SETPIXELFLAGS_info; }
	const maxon::Char* const PixelFormatInterface::MTable::_ids = 
		"Init@6d447fdceafa5735\0" // Result<void> Init(const PixelFormatGroup& group, const Char* shortName)
		"GetChannels@39a41fd1d2c965b2\0" // Block<const ImageChannel> GetChannels() const
		"GetPixelFormatGroup@bafc20b0acaa65d9\0" // const PixelFormatGroup& GetPixelFormatGroup() const
		"CreatePix@b178eabea8e889bf\0" // Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const
		"GetChannelCount@7d0e6f3d29c239e7\0" // Int GetChannelCount() const
		"GetChannelOffsets@35bca7bc00dfa14c\0" // const ChannelOffsets& GetChannelOffsets() const
		"GetBitsPerPixel@4f41d0db287c303c\0" // BITS GetBitsPerPixel() const
		"GetBytesPerLine@d6cc46dc4796bbdd\0" // Int GetBytesPerLine(Int width, Int lineAlignment) const
		"GetPackedPixelCount@7d0e6f3d29c239e7\0" // Int GetPackedPixelCount() const
		"HasAlpha@12e73654e6d65520\0" // Bool HasAlpha() const
		"GetAlphaPixelFormat@282f66c3b6abb9b3\0" // Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const
		"GetColorSpace@38fcf0c8f66c1007\0" // ColorSpace GetColorSpace() const
		"GetDefaultColorProfile@7d9b125a5b255027\0" // const ColorProfile& GetDefaultColorProfile() const
		"GetConvertPixelFunc@dc8e390555cb5c91\0" // Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const
		"GetConvertPixelFunc@6c19e4ea3d305a59\0" // Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const
		"ConvertPixelFromSlow@ea5d8b178cbe83f5\0" // Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const
		"IsIdenticalPixel@3d2706517643b0c7\0" // Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
		"PixToString@d98a188e9b942dd9\0" // String PixToString(const Pix* src) const
		"GetConvertPixelFromFunc@905b1f34f07600de\0" // Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const
		"GetConvertPixelToFunc@905b1f34f07600de\0" // Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const
		"GetShortName@f7184b4eb0b21baf\0" // const Char* GetShortName() const
	"";
	const maxon::METHOD_FLAGS PixelFormatInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatInterface, , "net.maxon.image.interface.pixelformat", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int PixelFormatInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<BITS>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<Block<const ImageChannel>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const ChannelOffsets&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const ColorProfile&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const PixelFormatGroup&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const PixelFormatsInterface::MTable::_ids = 
		"FindOrCreatePixelFormat@2a3f27a3e13d7ea8\0" // Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannel>& channels)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class PixelFormatsInterface::Hxx2::Unresolved : public PixelFormatsInterface
	{
	public:
		static const Unresolved* Get(const PixelFormatsInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(PixelFormatsInterface* o) { return (Unresolved*) o; }
		static Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return PixelFormatsInterface::FindOrCreatePixelFormat(channels); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE PixelFormatsInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<PixelFormat>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool PixelFormatsInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<PixelFormat>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->PixelFormatsInterface_FindOrCreatePixelFormat = PRIVATE_MAXON_MF_CAST(decltype(PixelFormatsInterface_FindOrCreatePixelFormat), &Hxx2::Wrapper<Hxx2::Unresolved>::PixelFormatsInterface_FindOrCreatePixelFormat);
		#else
		tbl->PixelFormatsInterface_FindOrCreatePixelFormat = PRIVATE_MAXON_MF_CAST(decltype(PixelFormatsInterface_FindOrCreatePixelFormat), &Hxx2::Wrapper<Hxx2::Unresolved>::PixelFormatsInterface_FindOrCreatePixelFormat);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(PixelFormatsInterface, "net.maxon.image.interface.pixelformats", nullptr, maxon::EntityBase::FLAGS::NONE);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PixelFormatBaseClass, , "net.maxon.image.class.pixelformatbase");
	namespace PixelFormats
	{
		MAXON_REGISTRY_REGISTER(RGB);
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_pixelformat(0
	| maxon::PixelFormatInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
