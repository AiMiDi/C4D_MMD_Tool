
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<BlendPixelHandlerStruct> (*_ImagePixelBlendInterface_GetBlendPixelHandler) (const maxon::GenericComponent* this_, const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity);
	maxon::Int _ImagePixelBlendInterface_GetBlendPixelHandler_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelBlendInterface, GetBlendPixelHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelBlendInterface, GetBlendPixelHandler), W, MTable>::type::_ImagePixelBlendInterface_GetBlendPixelHandler;
			_ImagePixelBlendInterface_GetBlendPixelHandler = reinterpret_cast<const decltype(_ImagePixelBlendInterface_GetBlendPixelHandler)&>(ptr);
			_ImagePixelBlendInterface_GetBlendPixelHandler_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImagePixelBlendInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<PixelFormat> (*_ImagePixelBlendInterface_GetOptimalPixelFormat) (const Block<PixelFormat>& formats);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_ImagePixelBlendInterface_GetOptimalPixelFormat = &IMPL::_ImagePixelBlendInterface_GetOptimalPixelFormat;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBlendPixelHandler);
		static Result<PixelFormat> _ImagePixelBlendInterface_GetOptimalPixelFormat(const Block<PixelFormat>& formats) { return S::Implementation::GetOptimalPixelFormat(formats); }
		static Result<BlendPixelHandlerStruct> _ImagePixelBlendInterface_GetBlendPixelHandler(const maxon::GenericComponent* this_, const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) { return ((const typename S::Implementation*) this_)->GetBlendPixelHandler(bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::GetOptimalPixelFormat(const Block<PixelFormat>& formats) -> Result<PixelFormat>
{
	return Hxx2::StaticMTable::_instance._ImagePixelBlendInterface_GetOptimalPixelFormat(formats);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const -> Result<BlendPixelHandlerStruct>
{
	const ImagePixelBlendInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelBlendInterface, this); return mt_._ImagePixelBlendInterface_GetBlendPixelHandler((const maxon::GenericComponent*) this + mt_._ImagePixelBlendInterface_GetBlendPixelHandler_Offset, bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetOptimalPixelFormat(const Block<PixelFormat>& formats) -> Result<PixelFormat> { return (Hxx2::StaticMTable::_instance._ImagePixelBlendInterface_GetOptimalPixelFormat(formats)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelBlendInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const -> Result<BlendPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelBlendInterface* o_ = (const ImagePixelBlendInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelBlendInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelBlendInterface, o_, ImagePixelBlendInterface_GetBlendPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelBlendInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelBlendInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelBlendInterface, o_); 
	return (mt_._ImagePixelBlendInterface_GetBlendPixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelBlendInterface_GetBlendPixelHandler_Offset, bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity));
}
auto ImagePixelBlendInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImagePixelBlendInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImagePixelBlendInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImagePixelBlendInterface() { new (s_ui_maxon_ImagePixelBlendInterface) maxon::EntityUse(ImagePixelBlendInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImagePixelBlendInterface(ImagePixelBlendInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelblend.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

