#if 1
namespace maxon
{
	namespace enum33 { enum class CONVERTPIXELFLAGS
	{
		NONE													= 0,				///< no options set.
		FORCECOLORPROFILECONVERSION		= (1 << 0),	///< if set it forces color profile conversion even if the color space are identical, otherwise the conversion will be performed only if the color spaces are different.
	} ; }
	maxon::String PrivateToString_CONVERTPIXELFLAGS33(std::underlying_type<enum33::CONVERTPIXELFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum33::CONVERTPIXELFLAGS::NONE, (maxon::UInt64) enum33::CONVERTPIXELFLAGS::FORCECOLORPROFILECONVERSION};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONVERTPIXELFLAGS", SIZEOF(x), true, values, "NONE\0FORCECOLORPROFILECONVERSION\0", fmt);
	}
	namespace enum45 { enum class GETPIXELHANDLERFLAGS
	{
		NONE,																		///< no options set.
		FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																						///< the conversion will be performed only if the color spaces are different.
		DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
		DONTAPPLYMASK = (1 << 2),								///< do not apply the alpha layer to the image data.
	} ; }
	maxon::String PrivateToString_GETPIXELHANDLERFLAGS45(std::underlying_type<enum45::GETPIXELHANDLERFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum45::GETPIXELHANDLERFLAGS::NONE, (maxon::UInt64) enum45::GETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION, (maxon::UInt64) enum45::GETPIXELHANDLERFLAGS::DEEPIMAGE, (maxon::UInt64) enum45::GETPIXELHANDLERFLAGS::DONTAPPLYMASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GETPIXELHANDLERFLAGS", SIZEOF(x), true, values, "NONE\0FORCECOLORPROFILECONVERSION\0DEEPIMAGE\0DONTAPPLYMASK\0", fmt);
	}
	namespace enum55 { enum class GETPIXELFLAGS
	{
		NONE,									///< no options set.
		DEEPIMAGE = (1 << 1), ///< provided a DeepImageConst/MutableBuffer structure.
	} ; }
	maxon::String PrivateToString_GETPIXELFLAGS55(std::underlying_type<enum55::GETPIXELFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum55::GETPIXELFLAGS::NONE, (maxon::UInt64) enum55::GETPIXELFLAGS::DEEPIMAGE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GETPIXELFLAGS", SIZEOF(x), true, values, "NONE\0DEEPIMAGE\0", fmt);
	}
	namespace enum69 { enum class SETPIXELHANDLERFLAGS
	{
		/// No options set.
		NONE = 0,
		FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																						///< the conversion will be performed only if the color spaces are different.
		DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
	} ; }
	maxon::String PrivateToString_SETPIXELHANDLERFLAGS69(std::underlying_type<enum69::SETPIXELHANDLERFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum69::SETPIXELHANDLERFLAGS::NONE, (maxon::UInt64) enum69::SETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION, (maxon::UInt64) enum69::SETPIXELHANDLERFLAGS::DEEPIMAGE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SETPIXELHANDLERFLAGS", SIZEOF(x), true, values, "NONE\0FORCECOLORPROFILECONVERSION\0DEEPIMAGE\0", fmt);
	}
	namespace enum78 { enum class SETPIXELFLAGS
	{
		NONE = 0,							///< No options set.
		DEEPIMAGE = (1 << 1), ///< provided a DeepImagePixelConst/MutableBuffer.
	} ; }
	maxon::String PrivateToString_SETPIXELFLAGS78(std::underlying_type<enum78::SETPIXELFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum78::SETPIXELFLAGS::NONE, (maxon::UInt64) enum78::SETPIXELFLAGS::DEEPIMAGE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SETPIXELFLAGS", SIZEOF(x), true, values, "NONE\0DEEPIMAGE\0", fmt);
	}
	const maxon::Char* const PixelFormatGroupInterface::MTable::_ids = 
		"GetEntries@ea079f152534cf42\0" // PixelFormatIterator GetEntries() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatGroupInterface, , "net.maxon.image.interface.pixelformatgroup", "maxon.PixelFormatGroupInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int PixelFormatGroupInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PixelFormatIterator>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const PixelFormatInterface::MTable::_ids = 
		"Init@30f34e0dc36d391a\0" // Result<void> Init(const PixelFormatGroup& group, const Char* shortName)
		"GetChannels@982dde769d8ed421\0" // Block<const ImageChannel> GetChannels() const
		"GetPixelFormatGroup@8219eb2dd8e8051e\0" // const PixelFormatGroup& GetPixelFormatGroup() const
		"CreatePix@1acbbe3bd6264494\0" // Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const
		"GetChannelCount@4386c86\0" // Int GetChannelCount() const
		"GetChannelOffsets@576637f8bf10b6a3\0" // const ChannelOffsets& GetChannelOffsets() const
		"GetBitsPerPixel@74cbf7fd\0" // BITS GetBitsPerPixel() const
		"GetBytesPerLine@1b08f59a4533b43c\0" // Int GetBytesPerLine(Int width, Int lineAlignment) const
		"GetPackedPixelCount@4386c86\0" // Int GetPackedPixelCount() const
		"HasAlpha@76f01901\0" // Bool HasAlpha() const
		"GetAlphaPixelFormat@244253989ae3bda8\0" // Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const
		"GetColorSpace@18edbd6218df033a\0" // ColorSpace GetColorSpace() const
		"GetDefaultColorProfile@3df3ba15a61a2dba\0" // const ColorProfile& GetDefaultColorProfile() const
		"GetConvertPixelFunc@b4041cf4610823a4\0" // Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const
		"ConvertPixelFromSlow@30a6e6b30f70a79a\0" // Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const
		"IsIdenticalPixel@b30df41fb8ee65fa\0" // Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
		"PixToString@ae58b4fabae4f6c0\0" // String PixToString(const Pix* src) const
		"GetConvertPixelFromFunc@851aff4da83b94f5\0" // Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const
		"GetConvertPixelToFunc@851aff4da83b94f5\0" // Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const
		"GetShortName@629b065104619f2e\0" // const Char* GetShortName() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatInterface, , "net.maxon.image.interface.pixelformat", "maxon.PixelFormatInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int PixelFormatInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BITS>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Block<const ImageChannel>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const ChannelOffsets&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const ColorProfile&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const PixelFormatGroup&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const PixelFormatIndexedColorInterface::MTable::_ids = 
		"InitColorTable@2c7ae5e41eff96fb\0" // Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
		"GetColorTablePixelFormat@90e8ba3989f75b34\0" // PixelFormat GetColorTablePixelFormat() const
		"GetColorTableSize@4386c86\0" // Int GetColorTableSize() const
		"SetIndex@d44b9c0b076b91ec\0" // Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
		"GetIndex@8e0e9d3b3011c6d1\0" // Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatIndexedColorInterface, , "net.maxon.image.interface.pixelformatindexedcolor", "maxon.PixelFormatIndexedColorInterface", (&PixelFormatInterface::_interface));
	template <typename DUMMY> maxon::Int PixelFormatIndexedColorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PixelFormat>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const PixelFormatsInterface::MTable::_ids = 
		"FindOrCreatePixelFormat@4efeedb8f5b1a067\0" // Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannel>& channels)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class PixelFormatsInterface::Hxx2::Unresolved : public PixelFormatsInterface
	{
	public:
		static const Unresolved* Get(const PixelFormatsInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(PixelFormatsInterface* o) { return (Unresolved*) o; }
		static Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return PixelFormatsInterface::FindOrCreatePixelFormat(channels); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE PixelFormatsInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<PixelFormat>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool PixelFormatsInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<PixelFormat>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_PixelFormatsInterface_FindOrCreatePixelFormat = &Hxx2::Wrapper<Hxx2::Unresolved>::_PixelFormatsInterface_FindOrCreatePixelFormat;
		#else
		tbl->_PixelFormatsInterface_FindOrCreatePixelFormat = &Hxx2::Wrapper<Hxx2::Unresolved>::_PixelFormatsInterface_FindOrCreatePixelFormat;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(PixelFormatsInterface, "net.maxon.image.interface.pixelformats", nullptr);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PixelFormatBaseClass, , "net.maxon.image.class.pixelformatbase");
	MAXON_REGISTRY_REGISTER(PixelFormats);
	namespace PixelFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBGroup, , "net.maxon.image.pixelformat.rgbgroup");
		MAXON_REGISTRY_REGISTER(RGB);
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_pixelformat(0
	| maxon::PixelFormatGroupInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::PixelFormatInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::PixelFormatIndexedColorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
