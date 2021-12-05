#if 1
namespace maxon
{
	namespace enum18
	{
		enum class BLENDPIXELFLAGS
		{
			NONE,									///< no options set.
		} ;
		static const maxon::UInt64 BLENDPIXELFLAGS_values[] = {maxon::UInt64(enum18::BLENDPIXELFLAGS::NONE)};
		static const maxon::EnumInfo BLENDPIXELFLAGS_info{"BLENDPIXELFLAGS", SIZEOF(BLENDPIXELFLAGS), true, "NONE\0", BLENDPIXELFLAGS_values, std::extent<decltype(BLENDPIXELFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BLENDPIXELFLAGS18(){ return enum18::BLENDPIXELFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_BlendPixelHandlerRef,, "net.maxon.datatype.blendpixelhandlerref");
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImagePixelBlendInterface::Hxx2::Unresolved : public ImagePixelBlendInterface
	{
	public:
		static Result<PixelFormat> GetOptimalPixelFormat(const Block<PixelFormat>& formats) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImagePixelBlendInterface::GetOptimalPixelFormat(formats); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ImagePixelBlendInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<PixelFormat>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImagePixelBlendInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<PixelFormat>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ImagePixelBlendInterface_GetOptimalPixelFormat = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ImagePixelBlendInterface_GetOptimalPixelFormat;
		#else
		tbl->_ImagePixelBlendInterface_GetOptimalPixelFormat = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ImagePixelBlendInterface_GetOptimalPixelFormat;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ImagePixelBlendInterface::MTable::_ids = 
		"GetBlendPixelHandler@cff3e0720b9df38d\0" // Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const
	"";
	const maxon::METHOD_FLAGS ImagePixelBlendInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImagePixelBlendInterface, , "net.maxon.image.interface.imagepixelblend", "maxon.ImagePixelBlendInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ImagePixelBlendInterface::Hxx2::StaticMTable::_ids = 
		"GetOptimalPixelFormat@bcd375325ca49092\0" // Result<PixelFormat> GetOptimalPixelFormat(const Block<PixelFormat>& formats)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ImagePixelBlendInterface, , "net.maxon.image.interface.imagepixelblend");
	MAXON_REGISTRY_REGISTER(ImagePixelBlends);
	namespace ImagePixelBlends
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Add, , "net.maxon.render.blendmode.add");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Average, , "net.maxon.render.blendmode.average");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Color, , "net.maxon.render.blendmode.color");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Colorburn, , "net.maxon.render.blendmode.colorburn");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Colordodge, , "net.maxon.render.blendmode.colordodge");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Darken, , "net.maxon.render.blendmode.darken");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Darker, , "net.maxon.render.blendmode.darker");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Difference, , "net.maxon.render.blendmode.difference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Dissolve, , "net.maxon.render.blendmode.dissolve");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Divide, , "net.maxon.render.blendmode.divide");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Exclusion, , "net.maxon.render.blendmode.exclusion");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Freeze, , "net.maxon.render.blendmode.freeze");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Glow, , "net.maxon.render.blendmode.glow");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Hardlight, , "net.maxon.render.blendmode.hardlight");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Hardmix, , "net.maxon.render.blendmode.hardmix");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Heat, , "net.maxon.render.blendmode.heat");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Hue, , "net.maxon.render.blendmode.hue");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Hypot, , "net.maxon.render.blendmode.hypot");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Levr, , "net.maxon.render.blendmode.levr");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Lighten, , "net.maxon.render.blendmode.lighten");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Lighter, , "net.maxon.render.blendmode.lighter");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Linearburn, , "net.maxon.render.blendmode.linearburn");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Lineardodge, , "net.maxon.render.blendmode.lineardodge");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Luminance, , "net.maxon.render.blendmode.luminance");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Multiply, , "net.maxon.render.blendmode.multiply");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Over, , "net.maxon.render.blendmode.over");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Overlay, , "net.maxon.render.blendmode.overlay");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Passfolder, , "net.maxon.render.blendmode.passfolder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Pinlight, , "net.maxon.render.blendmode.pinlight");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Reflect, , "net.maxon.render.blendmode.reflect");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Saturation, , "net.maxon.render.blendmode.saturation");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Screen, , "net.maxon.render.blendmode.screen");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Softlight, , "net.maxon.render.blendmode.softlight");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Stamp, , "net.maxon.render.blendmode.stamp");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Subtract, , "net.maxon.render.blendmode.subtract");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Vividlight, , "net.maxon.render.blendmode.vividlight");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Xor, , "net.maxon.render.blendmode.xor");
	}
	namespace ImagePixelBlendsInternal
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ApplyAlpha, , "net.maxon.render.blendmode.applyalpha");
	}
}
#endif
