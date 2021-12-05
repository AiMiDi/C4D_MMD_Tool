
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

/// @endcond


struct ImageBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddChildren);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreateSubImagePart);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FreePixelHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetComponent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHeight);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetWidth);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitBase);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableRegionChanged);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetComponent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetPixelHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ImageBaseInterface_InitBase) (maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type);
	maxon::Int _ImageBaseInterface_InitBase_Offset;
	Result<void> (*_ImageBaseInterface_AddChildren) (maxon::GenericComponent* this_, IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore);
	maxon::Int _ImageBaseInterface_AddChildren_Offset;
	Int (*_ImageBaseInterface_GetWidth) (const maxon::GenericComponent* this_);
	maxon::Int _ImageBaseInterface_GetWidth_Offset;
	Int (*_ImageBaseInterface_GetHeight) (const maxon::GenericComponent* this_);
	maxon::Int _ImageBaseInterface_GetHeight_Offset;
	Int (*_ImageBaseInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int _ImageBaseInterface_GetChannelCount_Offset;
	PixelFormat (*_ImageBaseInterface_GetPixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int _ImageBaseInterface_GetPixelFormat_Offset;
	Result<GetPixelHandlerStruct> (*_ImageBaseInterface_GetPixelHandler) (const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet);
	maxon::Int _ImageBaseInterface_GetPixelHandler_Offset;
	Result<SetPixelHandlerStruct> (*_ImageBaseInterface_SetPixelHandler) (maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags);
	maxon::Int _ImageBaseInterface_SetPixelHandler_Offset;
/// @cond INTERNAL

	void (*_ImageBaseInterface_FreePixelHandler) (const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel);
	maxon::Int _ImageBaseInterface_FreePixelHandler_Offset;
	void (*_ImageBaseInterface_FreePixelHandler_1) (const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel);
	maxon::Int _ImageBaseInterface_FreePixelHandler_1_Offset;
/// @endcond

	Result<void> (*_ImageBaseInterface_GetComponent) (const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags);
	maxon::Int _ImageBaseInterface_GetComponent_Offset;
	Result<void> (*_ImageBaseInterface_SetComponent) (maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	maxon::Int _ImageBaseInterface_SetComponent_Offset;
	Result<ImageBaseRef> (*_ImageBaseInterface_CreateSubImagePart) (const maxon::GenericComponent* this_, const DrawRectInt& rect);
	maxon::Int _ImageBaseInterface_CreateSubImagePart_Offset;
	maxon::ObservableRef<ObservableRegionChangedDelegate> (*_ImageBaseInterface_ObservableRegionChanged) (const maxon::GenericComponent* this_);
	maxon::Int _ImageBaseInterface_ObservableRegionChanged_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, InitBase))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, InitBase), W, MTable>::type::_ImageBaseInterface_InitBase;
		_ImageBaseInterface_InitBase = reinterpret_cast<const decltype(_ImageBaseInterface_InitBase)&>(ptr);
		_ImageBaseInterface_InitBase_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, AddChildren))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, AddChildren), W, MTable>::type::_ImageBaseInterface_AddChildren;
		_ImageBaseInterface_AddChildren = reinterpret_cast<const decltype(_ImageBaseInterface_AddChildren)&>(ptr);
		_ImageBaseInterface_AddChildren_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetWidth))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetWidth), W, MTable>::type::_ImageBaseInterface_GetWidth;
		_ImageBaseInterface_GetWidth = reinterpret_cast<const decltype(_ImageBaseInterface_GetWidth)&>(ptr);
		_ImageBaseInterface_GetWidth_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetHeight))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetHeight), W, MTable>::type::_ImageBaseInterface_GetHeight;
		_ImageBaseInterface_GetHeight = reinterpret_cast<const decltype(_ImageBaseInterface_GetHeight)&>(ptr);
		_ImageBaseInterface_GetHeight_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetChannelCount))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetChannelCount), W, MTable>::type::_ImageBaseInterface_GetChannelCount;
		_ImageBaseInterface_GetChannelCount = reinterpret_cast<const decltype(_ImageBaseInterface_GetChannelCount)&>(ptr);
		_ImageBaseInterface_GetChannelCount_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelFormat))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelFormat), W, MTable>::type::_ImageBaseInterface_GetPixelFormat;
		_ImageBaseInterface_GetPixelFormat = reinterpret_cast<const decltype(_ImageBaseInterface_GetPixelFormat)&>(ptr);
		_ImageBaseInterface_GetPixelFormat_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelHandler))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelHandler), W, MTable>::type::_ImageBaseInterface_GetPixelHandler;
		_ImageBaseInterface_GetPixelHandler = reinterpret_cast<const decltype(_ImageBaseInterface_GetPixelHandler)&>(ptr);
		_ImageBaseInterface_GetPixelHandler_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetPixelHandler))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetPixelHandler), W, MTable>::type::_ImageBaseInterface_SetPixelHandler;
		_ImageBaseInterface_SetPixelHandler = reinterpret_cast<const decltype(_ImageBaseInterface_SetPixelHandler)&>(ptr);
		_ImageBaseInterface_SetPixelHandler_Offset = offset;
	}
/// @cond INTERNAL

	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler), W, MTable>::type::_ImageBaseInterface_FreePixelHandler;
		_ImageBaseInterface_FreePixelHandler = reinterpret_cast<const decltype(_ImageBaseInterface_FreePixelHandler)&>(ptr);
		_ImageBaseInterface_FreePixelHandler_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler), W, MTable>::type::_ImageBaseInterface_FreePixelHandler_1;
		_ImageBaseInterface_FreePixelHandler_1 = reinterpret_cast<const decltype(_ImageBaseInterface_FreePixelHandler_1)&>(ptr);
		_ImageBaseInterface_FreePixelHandler_1_Offset = offset;
	}
/// @endcond

	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetComponent))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetComponent), W, MTable>::type::_ImageBaseInterface_GetComponent;
		_ImageBaseInterface_GetComponent = reinterpret_cast<const decltype(_ImageBaseInterface_GetComponent)&>(ptr);
		_ImageBaseInterface_GetComponent_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetComponent))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetComponent), W, MTable>::type::_ImageBaseInterface_SetComponent;
		_ImageBaseInterface_SetComponent = reinterpret_cast<const decltype(_ImageBaseInterface_SetComponent)&>(ptr);
		_ImageBaseInterface_SetComponent_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, CreateSubImagePart))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, CreateSubImagePart), W, MTable>::type::_ImageBaseInterface_CreateSubImagePart;
		_ImageBaseInterface_CreateSubImagePart = reinterpret_cast<const decltype(_ImageBaseInterface_CreateSubImagePart)&>(ptr);
		_ImageBaseInterface_CreateSubImagePart_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, ObservableRegionChanged))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, ObservableRegionChanged), W, MTable>::type::_ImageBaseInterface_ObservableRegionChanged;
		_ImageBaseInterface_ObservableRegionChanged = reinterpret_cast<const decltype(_ImageBaseInterface_ObservableRegionChanged)&>(ptr);
		_ImageBaseInterface_ObservableRegionChanged_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset) || !HierarchyObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageBaseInterface, typename HierarchyObjectInterface::MTable::template CombinedMTable<typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageBaseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageBaseInterface::Hxx2
{
	template <typename S> class CWrapper : public HierarchyObjectInterface::Hxx2::template CWrapper<typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddChildren);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateSubImagePart);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FreePixelHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetComponent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHeight);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetWidth);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitBase);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableRegionChanged);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetComponent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetPixelHandler);
		static Result<void> _ImageBaseInterface_InitBase(maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) { return ((typename S::Implementation*) this_)->InitBase(width, height, pixelFormat, type); }
		static Result<void> _ImageBaseInterface_AddChildren(maxon::GenericComponent* this_, IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) { return ((typename S::Implementation*) this_)->AddChildren(hierarchy, newChildren, insertBefore); }
		static Int _ImageBaseInterface_GetWidth(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetWidth(); }
		static Int _ImageBaseInterface_GetHeight(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHeight(); }
		static Int _ImageBaseInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
		static PixelFormat _ImageBaseInterface_GetPixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPixelFormat(); }
		static Result<GetPixelHandlerStruct> _ImageBaseInterface_GetPixelHandler(const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) { return ((const typename S::Implementation*) this_)->GetPixelHandler(dstFormat, channelOffsets, dstColorProfile, flags, layerSet); }
		static Result<SetPixelHandlerStruct> _ImageBaseInterface_SetPixelHandler(maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) { return ((typename S::Implementation*) this_)->SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, flags); }
/// @cond INTERNAL

		static void _ImageBaseInterface_FreePixelHandler(const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel); }
		static void _ImageBaseInterface_FreePixelHandler_1(const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel); }
/// @endcond

		static Result<void> _ImageBaseInterface_GetComponent(const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) this_)->GetComponent(component, pos, data, inc, flags); }
		static Result<void> _ImageBaseInterface_SetComponent(maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) { return ((typename S::Implementation*) this_)->SetComponent(component, pos, data, inc, flags); }
		static Result<ImageBaseRef> _ImageBaseInterface_CreateSubImagePart(const maxon::GenericComponent* this_, const DrawRectInt& rect) { return ((const typename S::Implementation*) this_)->CreateSubImagePart(rect); }
		static maxon::ObservableRef<ObservableRegionChangedDelegate> _ImageBaseInterface_ObservableRegionChanged(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableRegionChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_InitBase((maxon::GenericComponent*) this + mt_._ImageBaseInterface_InitBase_Offset, width, height, pixelFormat, type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_AddChildren((maxon::GenericComponent*) this + mt_._ImageBaseInterface_AddChildren_Offset, hierarchy, newChildren, insertBefore);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetWidth() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetWidth((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetWidth_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetHeight() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetHeight((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetHeight_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetChannelCount() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetPixelFormat() const -> PixelFormat
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetPixelFormat((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetPixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const -> Result<GetPixelHandlerStruct>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetPixelHandler((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, dstColorProfile, flags, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) -> Result<SetPixelHandlerStruct>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_SetPixelHandler((maxon::GenericComponent*) this + mt_._ImageBaseInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, flags);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> void
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_FreePixelHandler((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_FreePixelHandler_Offset, pixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::FreePixelHandler(SetPixelHandlerStruct& pixel) const -> void
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_FreePixelHandler_1((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_FreePixelHandler_1_Offset, pixel);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_GetComponent((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_GetComponent_Offset, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_SetComponent((maxon::GenericComponent*) this + mt_._ImageBaseInterface_SetComponent_Offset, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::CreateSubImagePart(const DrawRectInt& rect) const -> Result<ImageBaseRef>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_CreateSubImagePart((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_CreateSubImagePart_Offset, rect);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::ObservableRegionChanged() const -> maxon::ObservableRef<ObservableRegionChangedDelegate>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return mt_._ImageBaseInterface_ObservableRegionChanged((const maxon::GenericComponent*) this + mt_._ImageBaseInterface_ObservableRegionChanged_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_InitBase) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_InitBase(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_InitBase_Offset, width, height, pixelFormat, type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_InitBase) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_InitBase(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_InitBase_Offset, width, height, pixelFormat, type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_AddChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_AddChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_AddChildren_Offset, hierarchy, newChildren, insertBefore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_AddChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_AddChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_AddChildren_Offset, hierarchy, newChildren, insertBefore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetWidth) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetWidth(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetWidth_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHeight() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetHeight) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetHeight(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetHeight_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetPixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetPixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetPixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, dstColorProfile, flags, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) const -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, flags));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_FreePixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	mt_._ImageBaseInterface_FreePixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_FreePixelHandler_Offset, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FreePixelHandler(SetPixelHandlerStruct& pixel) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_FreePixelHandler_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	mt_._ImageBaseInterface_FreePixelHandler_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_FreePixelHandler_1_Offset, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_GetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_GetComponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_GetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_SetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageBaseInterface* o_ = (ImageBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_SetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateSubImagePart(const DrawRectInt& rect) const -> Result<ImageBaseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ImageBaseRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_CreateSubImagePart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_CreateSubImagePart(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_CreateSubImagePart_Offset, rect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableRegionChanged() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableRegionChangedDelegate>>, maxon::ObservableRef<ObservableRegionChangedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableRegionChangedDelegate>>, maxon::ObservableRef<ObservableRegionChangedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageBaseInterface* o_ = (const ImageBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageBaseInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableRegionChangedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageBaseInterface, o_, ImageBaseInterface_ObservableRegionChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageBaseInterface>() : PRIVATE_MAXON_VTABLE(ImageBaseInterface, o_); 
	return (mt_._ImageBaseInterface_ObservableRegionChanged(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageBaseInterface_ObservableRegionChanged_Offset));
}
auto ImageBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageBaseInterface() { new (s_ui_maxon_ImageBaseInterface) maxon::EntityUse(ImageBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageBaseInterface(ImageBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ImageTextureInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Load);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Save);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<MediaSessionRef> (*_ImageTextureInterface_Load) (maxon::GenericComponent* this_, const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet);
	maxon::Int _ImageTextureInterface_Load_Offset;
	Result<void> (*_ImageTextureInterface_Save) (const maxon::GenericComponent* this_, const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession);
	maxon::Int _ImageTextureInterface_Save_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Load))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Load), W, MTable>::type::_ImageTextureInterface_Load;
		_ImageTextureInterface_Load = reinterpret_cast<const decltype(_ImageTextureInterface_Load)&>(ptr);
		_ImageTextureInterface_Load_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Save))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Save), W, MTable>::type::_ImageTextureInterface_Save;
		_ImageTextureInterface_Save = reinterpret_cast<const decltype(_ImageTextureInterface_Save)&>(ptr);
		_ImageTextureInterface_Save_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ImageBaseInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageTextureInterface, typename ImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageTextureInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageTextureInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<ImageTextureRef> (*_ImageTextureInterface_LoadTexture) (const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_ImageTextureInterface_LoadTexture = &IMPL::_ImageTextureInterface_LoadTexture;
		}
	};
	template <typename S> class CWrapper : public ImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Load);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Save);
		static Result<ImageTextureRef> _ImageTextureInterface_LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) { return S::Implementation::LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet); }
		static Result<MediaSessionRef> _ImageTextureInterface_Load(maxon::GenericComponent* this_, const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) { return ((typename S::Implementation*) this_)->Load(url, targetTime, flags, pixelStorageClass, layerSet); }
		static Result<void> _ImageTextureInterface_Save(const maxon::GenericComponent* this_, const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) { return ((const typename S::Implementation*) this_)->Save(fileFormat, flags, returnOpenSession); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<ImageTextureRef>
{
	return Hxx2::StaticMTable::_instance._ImageTextureInterface_LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<MediaSessionRef>
{
	const ImageTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageTextureInterface, this); return mt_._ImageTextureInterface_Load((maxon::GenericComponent*) this + mt_._ImageTextureInterface_Load_Offset, url, targetTime, flags, pixelStorageClass, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	const ImageTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageTextureInterface, this); return mt_._ImageTextureInterface_Save((const maxon::GenericComponent*) this + mt_._ImageTextureInterface_Save_Offset, fileFormat, flags, returnOpenSession);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstReferenceFunctionsImpl<S>::LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<ImageTextureRef>
{
	return (Hxx2::StaticMTable::_instance._ImageTextureInterface_LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ReferenceFunctionsImpl<S>::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) const -> Result<MediaSessionRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<MediaSessionRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageTextureInterface* o_ = (ImageTextureInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageTextureInterface, o_, ImageTextureInterface_Load) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageTextureInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageTextureInterface>() : PRIVATE_MAXON_VTABLE(ImageTextureInterface, o_); 
	return (mt_._ImageTextureInterface_Load(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageTextureInterface_Load_Offset, url, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::COWReferenceFunctionsImpl<S>::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<MediaSessionRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<MediaSessionRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageTextureInterface* o_ = (ImageTextureInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageTextureInterface, o_, ImageTextureInterface_Load) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageTextureInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageTextureInterface>() : PRIVATE_MAXON_VTABLE(ImageTextureInterface, o_); 
	return (mt_._ImageTextureInterface_Load(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageTextureInterface_Load_Offset, url, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageTextureInterface* o_ = (const ImageTextureInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageTextureInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageTextureInterface, o_, ImageTextureInterface_Save) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageTextureInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageTextureInterface>() : PRIVATE_MAXON_VTABLE(ImageTextureInterface, o_); 
	return (mt_._ImageTextureInterface_Save(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImageTextureInterface_Save_Offset, fileFormat, flags, returnOpenSession));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Save(const Url& fileName, const MediaOutputUrlRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ImageTextureInterface::Save on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageTextureInterface* o_ = (const ImageTextureInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageTextureInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Save(fileName, fileFormat, flags, returnOpenSession));
}
auto ImageTextureInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageTextureInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageTextureInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageTextureInterface() { new (s_ui_maxon_ImageTextureInterface) maxon::EntityUse(ImageTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageTextureInterface(ImageTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_ImageTextureInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_ImageTextureInterface() { new (s_usi_maxon_ImageTextureInterface) maxon::EntityUse(ImageTextureInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_ImageTextureInterface(ImageTextureInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ImageInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ImageInterface_Init) (maxon::GenericComponent* this_, Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor);
	maxon::Int _ImageInterface_Init_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageInterface, Init))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageInterface, Init), W, MTable>::type::_ImageInterface_Init;
		_ImageInterface_Init = reinterpret_cast<const decltype(_ImageInterface_Init)&>(ptr);
		_ImageInterface_Init_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ImageBaseInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageInterface, typename ImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageInterface::Hxx2
{
	template <typename S> class CWrapper : public ImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static Result<void> _ImageInterface_Init(maxon::GenericComponent* this_, Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) { return ((typename S::Implementation*) this_)->Init(width, height, storageFormat, pixelFormat, defaultColor); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) -> Result<void>
{
	const ImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageInterface, this); return mt_._ImageInterface_Init((maxon::GenericComponent*) this + mt_._ImageInterface_Init_Offset, width, height, storageFormat, pixelFormat, defaultColor);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageInterface* o_ = (ImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageInterface, o_, ImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageInterface>() : PRIVATE_MAXON_VTABLE(ImageInterface, o_); 
	return (mt_._ImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageInterface_Init_Offset, width, height, storageFormat, pixelFormat, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageInterface* o_ = (ImageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageInterface, o_, ImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageInterface>() : PRIVATE_MAXON_VTABLE(ImageInterface, o_); 
	return (mt_._ImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageInterface_Init_Offset, width, height, storageFormat, pixelFormat, defaultColor));
}
auto ImageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageInterface() { new (s_ui_maxon_ImageInterface) maxon::EntityUse(ImageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageInterface(ImageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ImageLayerInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ImageInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageLayerInterface, typename ImageInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageLayerInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageLayerInterface::Hxx2
{
	template <typename S> using CWrapper = typename ImageInterface::Hxx2::template CWrapper<S>;
};

auto ImageLayerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageLayerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageLayerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageLayerInterface() { new (s_ui_maxon_ImageLayerInterface) maxon::EntityUse(ImageLayerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageLayerInterface(ImageLayerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ImageFunctionsInterface::PrivateGetCppName() { return nullptr; }

struct ImageFunctionsInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<ImageBaseRef> (*_ImageFunctionsInterface_CreateSubImagePart) (const ImageBaseRef& imageRef, const DrawRectInt& rect);
	template <typename IMPL> void Init()
	{
		_ImageFunctionsInterface_CreateSubImagePart = &IMPL::_ImageFunctionsInterface_CreateSubImagePart;
	}
};

struct ImageFunctionsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<ImageBaseRef> _ImageFunctionsInterface_CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect) { return C::CreateSubImagePart(imageRef, rect); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageFunctionsInterface::CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect) -> Result<ImageBaseRef>
{
	return MTable::_instance._ImageFunctionsInterface_CreateSubImagePart(imageRef, rect);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageFunctionsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageFunctionsInterface() { new (s_ui_maxon_ImageFunctionsInterface) maxon::EntityUse(ImageFunctionsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageFunctionsInterface(ImageFunctionsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

