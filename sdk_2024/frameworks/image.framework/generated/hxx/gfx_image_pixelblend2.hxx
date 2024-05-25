
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImagePixelBlendInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBlendPixelHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ImagePixelBlendInterface_GetBlendPixelHandler, GetBlendPixelHandler, true, maxon::GenericComponent, const, (Result<BlendPixelHandlerStruct>), const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity);
	maxon::Int ImagePixelBlendInterface_GetBlendPixelHandler_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelBlendInterface, GetBlendPixelHandler))
	{
		maxon::Tie(ImagePixelBlendInterface_GetBlendPixelHandler, ImagePixelBlendInterface_GetBlendPixelHandler_Offset) = ImagePixelBlendInterface_GetBlendPixelHandler_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImagePixelBlendInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImagePixelBlendInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImagePixelBlendInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(ImagePixelBlendInterface_GetOptimalPixelFormat, GetOptimalPixelFormat, MAXON_EXPAND_VA_ARGS, (Result<PixelFormat>), const Block<PixelFormat>& formats);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->ImagePixelBlendInterface_GetOptimalPixelFormat = ImagePixelBlendInterface_GetOptimalPixelFormat_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBlendPixelHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImagePixelBlendInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImagePixelBlendInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<PixelFormat> ImagePixelBlendInterface_GetOptimalPixelFormat(const Block<PixelFormat>& formats) { return S::Implementation::GetOptimalPixelFormat(formats); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelBlendInterface_GetBlendPixelHandler, maxon::GenericComponent, const, (Result<BlendPixelHandlerStruct>), const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBlendPixelHandler(bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::GetOptimalPixelFormat(const Block<PixelFormat>& formats) -> Result<PixelFormat>
{
	return Hxx2::StaticMTable::_instance.ImagePixelBlendInterface_GetOptimalPixelFormat(formats);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const -> Result<BlendPixelHandlerStruct>
{
	const ImagePixelBlendInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelBlendInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelBlendInterface_GetBlendPixelHandler_Offset), mt_.ImagePixelBlendInterface_GetBlendPixelHandler, bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::Hxx1::ConstFn<S>::GetOptimalPixelFormat(const Block<PixelFormat>& formats) -> Result<PixelFormat>
{
	return (Hxx2::StaticMTable::_instance.ImagePixelBlendInterface_GetOptimalPixelFormat(formats));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::Hxx1::ConstFn<S>::GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const -> Result<BlendPixelHandlerStruct>
{
	HXXRETURN0(Result<BlendPixelHandlerStruct>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImagePixelBlendInterface_GetBlendPixelHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelBlendInterface_GetBlendPixelHandler_Offset), mt_.ImagePixelBlendInterface_GetBlendPixelHandler, bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity));
}
auto ImagePixelBlendInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImagePixelBlendInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelblend)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImagePixelBlendInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImagePixelBlendInterface() { new (s_ui_maxon_ImagePixelBlendInterface) maxon::EntityUse(ImagePixelBlendInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImagePixelBlendInterface(ImagePixelBlendInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelblend)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_ImagePixelBlendInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_ImagePixelBlendInterface() { new (s_usi_maxon_ImagePixelBlendInterface) maxon::EntityUse(ImagePixelBlendInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_ImagePixelBlendInterface(ImagePixelBlendInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

