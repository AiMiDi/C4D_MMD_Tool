
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(TransformColors);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_InitBase, InitBase, true, maxon::GenericComponent,, (Result<void>), Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type);
	maxon::Int ImageBaseInterface_InitBase_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_AddChildren, AddChildren, true, maxon::GenericComponent,, (Result<void>), IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore);
	maxon::Int ImageBaseInterface_AddChildren_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetWidth, GetWidth, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImageBaseInterface_GetWidth_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetHeight, GetHeight, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImageBaseInterface_GetHeight_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetChannelCount, GetChannelCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImageBaseInterface_GetChannelCount_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetPixelFormat, GetPixelFormat, true, maxon::GenericComponent, const, (PixelFormat));
	maxon::Int ImageBaseInterface_GetPixelFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetPixelHandler, GetPixelHandler, true, maxon::GenericComponent, const, (Result<GetPixelHandlerStruct>), const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet);
	maxon::Int ImageBaseInterface_GetPixelHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_SetPixelHandler, SetPixelHandler, true, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags);
	maxon::Int ImageBaseInterface_SetPixelHandler_Offset;
/// @cond INTERNAL

	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_FreePixelHandler, FreePixelHandler, true, maxon::GenericComponent, const, (void), GetPixelHandlerStruct& pixel);
	maxon::Int ImageBaseInterface_FreePixelHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_FreePixelHandler_1, FreePixelHandler, true, maxon::GenericComponent, const, (void), SetPixelHandlerStruct& pixel);
	maxon::Int ImageBaseInterface_FreePixelHandler_1_Offset;
/// @endcond

	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_GetComponent, GetComponent, true, maxon::GenericComponent, const, (Result<void>), Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags);
	maxon::Int ImageBaseInterface_GetComponent_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_SetComponent, SetComponent, true, maxon::GenericComponent,, (Result<void>), Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	maxon::Int ImageBaseInterface_SetComponent_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_CreateSubImagePart, CreateSubImagePart, true, maxon::GenericComponent, const, (Result<ImageBaseRef>), const DrawRectInt& rect);
	maxon::Int ImageBaseInterface_CreateSubImagePart_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_TransformColors, TransformColors, true, maxon::GenericComponent,, (Result<ImageBaseRef>), const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags);
	maxon::Int ImageBaseInterface_TransformColors_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageBaseInterface_ObservableRegionChanged, ObservableRegionChanged, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableRegionChangedDelegate>), Bool create);
	maxon::Int ImageBaseInterface_ObservableRegionChanged_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, InitBase))
	{
		maxon::Tie(ImageBaseInterface_InitBase, ImageBaseInterface_InitBase_Offset) = ImageBaseInterface_InitBase_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, AddChildren))
	{
		maxon::Tie(ImageBaseInterface_AddChildren, ImageBaseInterface_AddChildren_Offset) = ImageBaseInterface_AddChildren_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetWidth))
	{
		maxon::Tie(ImageBaseInterface_GetWidth, ImageBaseInterface_GetWidth_Offset) = ImageBaseInterface_GetWidth_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetHeight))
	{
		maxon::Tie(ImageBaseInterface_GetHeight, ImageBaseInterface_GetHeight_Offset) = ImageBaseInterface_GetHeight_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetChannelCount))
	{
		maxon::Tie(ImageBaseInterface_GetChannelCount, ImageBaseInterface_GetChannelCount_Offset) = ImageBaseInterface_GetChannelCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelFormat))
	{
		maxon::Tie(ImageBaseInterface_GetPixelFormat, ImageBaseInterface_GetPixelFormat_Offset) = ImageBaseInterface_GetPixelFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetPixelHandler))
	{
		maxon::Tie(ImageBaseInterface_GetPixelHandler, ImageBaseInterface_GetPixelHandler_Offset) = ImageBaseInterface_GetPixelHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetPixelHandler))
	{
		maxon::Tie(ImageBaseInterface_SetPixelHandler, ImageBaseInterface_SetPixelHandler_Offset) = ImageBaseInterface_SetPixelHandler_GetPtr<W>(offset, true);
	}
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler))
	{
		maxon::Tie(ImageBaseInterface_FreePixelHandler, ImageBaseInterface_FreePixelHandler_Offset) = ImageBaseInterface_FreePixelHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, FreePixelHandler))
	{
		maxon::Tie(ImageBaseInterface_FreePixelHandler_1, ImageBaseInterface_FreePixelHandler_1_Offset) = ImageBaseInterface_FreePixelHandler_1_GetPtr<W>(offset, true);
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, GetComponent))
	{
		maxon::Tie(ImageBaseInterface_GetComponent, ImageBaseInterface_GetComponent_Offset) = ImageBaseInterface_GetComponent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, SetComponent))
	{
		maxon::Tie(ImageBaseInterface_SetComponent, ImageBaseInterface_SetComponent_Offset) = ImageBaseInterface_SetComponent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, CreateSubImagePart))
	{
		maxon::Tie(ImageBaseInterface_CreateSubImagePart, ImageBaseInterface_CreateSubImagePart_Offset) = ImageBaseInterface_CreateSubImagePart_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, TransformColors))
	{
		maxon::Tie(ImageBaseInterface_TransformColors, ImageBaseInterface_TransformColors_Offset) = ImageBaseInterface_TransformColors_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageBaseInterface, ObservableRegionChanged))
	{
		maxon::Tie(ImageBaseInterface_ObservableRegionChanged, ImageBaseInterface_ObservableRegionChanged_Offset) = ImageBaseInterface_ObservableRegionChanged_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageBaseInterface, typename HierarchyObjectInterface::MTable::template CombinedMTable<typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>>;
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(TransformColors);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename HierarchyObjectInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageBaseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_InitBase, maxon::GenericComponent,, (Result<void>), Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitBase(width, height, pixelFormat, type); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_AddChildren, maxon::GenericComponent,, (Result<void>), IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddChildren(hierarchy, newChildren, insertBefore); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetWidth, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetWidth(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetHeight, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHeight(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetChannelCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelCount(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetPixelFormat, maxon::GenericComponent, const, (PixelFormat)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPixelFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetPixelHandler, maxon::GenericComponent, const, (Result<GetPixelHandlerStruct>), const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPixelHandler(dstFormat, channelOffsets, dstColorProfile, flags, layerSet); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_SetPixelHandler, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, flags); }
/// @cond INTERNAL

		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_FreePixelHandler, maxon::GenericComponent, const, (void), GetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FreePixelHandler(pixel); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_FreePixelHandler_1, maxon::GenericComponent, const, (void), SetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FreePixelHandler(pixel); }
/// @endcond

		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_GetComponent, maxon::GenericComponent, const, (Result<void>), Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetComponent(component, pos, data, inc, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_SetComponent, maxon::GenericComponent,, (Result<void>), Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetComponent(component, pos, data, inc, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_CreateSubImagePart, maxon::GenericComponent, const, (Result<ImageBaseRef>), const DrawRectInt& rect) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CreateSubImagePart(rect); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_TransformColors, maxon::GenericComponent,, (Result<ImageBaseRef>), const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->TransformColors(srcProfile, dstProfile, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ImageBaseInterface_ObservableRegionChanged, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableRegionChangedDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableRegionChanged(create); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageBaseInterface_InitBase_Offset), mt_.ImageBaseInterface_InitBase, width, height, pixelFormat, type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageBaseInterface_AddChildren_Offset), mt_.ImageBaseInterface_AddChildren, hierarchy, newChildren, insertBefore);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetWidth() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetWidth_Offset), mt_.ImageBaseInterface_GetWidth);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetHeight() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetHeight_Offset), mt_.ImageBaseInterface_GetHeight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetChannelCount() const -> Int
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetChannelCount_Offset), mt_.ImageBaseInterface_GetChannelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetPixelFormat() const -> PixelFormat
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetPixelFormat_Offset), mt_.ImageBaseInterface_GetPixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const -> Result<GetPixelHandlerStruct>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetPixelHandler_Offset), mt_.ImageBaseInterface_GetPixelHandler, dstFormat, channelOffsets, dstColorProfile, flags, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) -> Result<SetPixelHandlerStruct>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageBaseInterface_SetPixelHandler_Offset), mt_.ImageBaseInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, flags);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> void
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_FreePixelHandler_Offset), mt_.ImageBaseInterface_FreePixelHandler, pixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::FreePixelHandler(SetPixelHandlerStruct& pixel) const -> void
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_FreePixelHandler_1_Offset), mt_.ImageBaseInterface_FreePixelHandler_1, pixel);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_GetComponent_Offset), mt_.ImageBaseInterface_GetComponent, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageBaseInterface_SetComponent_Offset), mt_.ImageBaseInterface_SetComponent, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::CreateSubImagePart(const DrawRectInt& rect) const -> Result<ImageBaseRef>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_CreateSubImagePart_Offset), mt_.ImageBaseInterface_CreateSubImagePart, rect);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags) -> Result<ImageBaseRef>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageBaseInterface_TransformColors_Offset), mt_.ImageBaseInterface_TransformColors, srcProfile, dstProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::ObservableRegionChanged(Bool create) const -> maxon::ObservableRef<ObservableRegionChangedDelegate>
{
	const ImageBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageBaseInterface_ObservableRegionChanged_Offset), mt_.ImageBaseInterface_ObservableRegionChanged, create);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::Fn<S>::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_InitBase); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_InitBase_Offset), mt_.ImageBaseInterface_InitBase, width, height, pixelFormat, type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWFn<S>::InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageBaseInterface_InitBase); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_InitBase_Offset), mt_.ImageBaseInterface_InitBase, width, height, pixelFormat, type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::Fn<S>::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_AddChildren); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_AddChildren_Offset), mt_.ImageBaseInterface_AddChildren, hierarchy, newChildren, insertBefore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWFn<S>::AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageBaseInterface_AddChildren); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_AddChildren_Offset), mt_.ImageBaseInterface_AddChildren, hierarchy, newChildren, insertBefore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetWidth() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(ImageBaseInterface_GetWidth); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetWidth_Offset), mt_.ImageBaseInterface_GetWidth));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetHeight() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(ImageBaseInterface_GetHeight); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetHeight_Offset), mt_.ImageBaseInterface_GetHeight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetChannelCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(ImageBaseInterface_GetChannelCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetChannelCount_Offset), mt_.ImageBaseInterface_GetChannelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetPixelFormat() const -> HXXADDRET2(PixelFormat)
{
	HXXRETURN0(HXXADDRET2(PixelFormat)); HXXRES; HXXCONST(HXXRET3(NULLPTR, PixelFormat)) HXXTABLE(ImageBaseInterface_GetPixelFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetPixelFormat_Offset), mt_.ImageBaseInterface_GetPixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const -> Result<GetPixelHandlerStruct>
{
	HXXRETURN0(Result<GetPixelHandlerStruct>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_GetPixelHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetPixelHandler_Offset), mt_.ImageBaseInterface_GetPixelHandler, dstFormat, channelOffsets, dstColorProfile, flags, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::Fn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) const -> Result<SetPixelHandlerStruct>
{
	HXXRETURN0(Result<SetPixelHandlerStruct>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_SetPixelHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetPixelHandler_Offset), mt_.ImageBaseInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWFn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) -> Result<SetPixelHandlerStruct>
{
	HXXRETURN0(Result<SetPixelHandlerStruct>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageBaseInterface_SetPixelHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetPixelHandler_Offset), mt_.ImageBaseInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, flags));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(ImageBaseInterface_FreePixelHandler); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_FreePixelHandler_Offset), mt_.ImageBaseInterface_FreePixelHandler, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::FreePixelHandler(SetPixelHandlerStruct& pixel) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(ImageBaseInterface_FreePixelHandler_1); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_FreePixelHandler_1_Offset), mt_.ImageBaseInterface_FreePixelHandler_1, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_GetComponent); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetComponent_Offset), mt_.ImageBaseInterface_GetComponent, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::Fn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_SetComponent); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetComponent_Offset), mt_.ImageBaseInterface_SetComponent, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWFn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageBaseInterface_SetComponent); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetComponent_Offset), mt_.ImageBaseInterface_SetComponent, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::CreateSubImagePart(const DrawRectInt& rect) const -> Result<ImageBaseRef>
{
	HXXRETURN0(Result<ImageBaseRef>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_CreateSubImagePart); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_CreateSubImagePart_Offset), mt_.ImageBaseInterface_CreateSubImagePart, rect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::Fn<S>::TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags) const -> Result<ImageBaseRef>
{
	HXXRETURN0(Result<ImageBaseRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageBaseInterface_TransformColors); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_TransformColors_Offset), mt_.ImageBaseInterface_TransformColors, srcProfile, dstProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::COWFn<S>::TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags) -> Result<ImageBaseRef>
{
	HXXRETURN0(Result<ImageBaseRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageBaseInterface_TransformColors); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_TransformColors_Offset), mt_.ImageBaseInterface_TransformColors, srcProfile, dstProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageBaseInterface::Hxx1::ConstFn<S>::ObservableRegionChanged(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableRegionChangedDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableRegionChangedDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableRegionChangedDelegate>::DefaultValue()) HXXTABLE(ImageBaseInterface_ObservableRegionChanged); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_ObservableRegionChanged_Offset), mt_.ImageBaseInterface_ObservableRegionChanged, create));
}
auto ImageBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
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
	PRIVATE_MAXON_MF_POINTER(ImageTextureInterface_Load, Load, true, maxon::GenericComponent,, (Result<MediaSessionRef>), const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet);
	maxon::Int ImageTextureInterface_Load_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageTextureInterface_Save, Save, true, maxon::GenericComponent, const, (Result<void>), const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession);
	maxon::Int ImageTextureInterface_Save_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Load))
	{
		maxon::Tie(ImageTextureInterface_Load, ImageTextureInterface_Load_Offset) = ImageTextureInterface_Load_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageTextureInterface, Save))
	{
		maxon::Tie(ImageTextureInterface_Save, ImageTextureInterface_Save_Offset) = ImageTextureInterface_Save_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageTextureInterface, typename ImageBaseInterface::MTable::template CombinedMTable<S>>;
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
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(ImageTextureInterface_LoadTexture, LoadTexture, MAXON_EXPAND_VA_ARGS, (Result<ImageTextureRef>), const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->ImageTextureInterface_LoadTexture = ImageTextureInterface_LoadTexture_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Load);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Save);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImageBaseInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageTextureInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageTextureInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<ImageTextureRef> ImageTextureInterface_LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) { return S::Implementation::LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet); }
		PRIVATE_MAXON_MF_WRAPPER(ImageTextureInterface_Load, maxon::GenericComponent,, (Result<MediaSessionRef>), const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Load(url, targetTime, flags, pixelStorageClass, layerSet); }
		PRIVATE_MAXON_MF_WRAPPER(ImageTextureInterface_Save, maxon::GenericComponent, const, (Result<void>), const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Save(fileFormat, flags, returnOpenSession); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<ImageTextureRef>
{
	return Hxx2::StaticMTable::_instance.ImageTextureInterface_LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<MediaSessionRef>
{
	const ImageTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageTextureInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageTextureInterface_Load_Offset), mt_.ImageTextureInterface_Load, url, targetTime, flags, pixelStorageClass, layerSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	const ImageTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageTextureInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageTextureInterface_Save_Offset), mt_.ImageTextureInterface_Save, fileFormat, flags, returnOpenSession);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstFn<S>::LoadTexture(const Url& name, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<ImageTextureRef>
{
	return (Hxx2::StaticMTable::_instance.ImageTextureInterface_LoadTexture(name, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::Fn<S>::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) const -> Result<MediaSessionRef>
{
	HXXRETURN0(Result<MediaSessionRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageTextureInterface_Load); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageTextureInterface_Load_Offset), mt_.ImageTextureInterface_Load, url, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::COWFn<S>::Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) -> Result<MediaSessionRef>
{
	HXXRETURN0(Result<MediaSessionRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageTextureInterface_Load); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageTextureInterface_Load_Offset), mt_.ImageTextureInterface_Load, url, targetTime, flags, pixelStorageClass, layerSet));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstFn<S>::Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageTextureInterface_Save); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageTextureInterface_Save_Offset), mt_.ImageTextureInterface_Save, fileFormat, flags, returnOpenSession));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageTextureInterface::Hxx1::ConstFn<S>::Save(const Url& fileName, const MediaOutputUrlRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXSUPER("ImageTextureInterface::Save"); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->Save(fileName, fileFormat, flags, returnOpenSession));
}
auto ImageTextureInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageTextureInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageTextureInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageTextureInterface() { new (s_ui_maxon_ImageTextureInterface) maxon::EntityUse(ImageTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageTextureInterface(ImageTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
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
	PRIVATE_MAXON_MF_POINTER(ImageInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor);
	maxon::Int ImageInterface_Init_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageInterface, Init))
	{
		maxon::Tie(ImageInterface_Init, ImageInterface_Init_Offset) = ImageInterface_Init_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageInterface, typename ImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageInterface::Hxx2
{
	template <typename S> class CWrapper : public ImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImageBaseInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImageInterface_Init, maxon::GenericComponent,, (Result<void>), Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(width, height, storageFormat, pixelFormat, defaultColor); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) -> Result<void>
{
	const ImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageInterface_Init_Offset), mt_.ImageInterface_Init, width, height, storageFormat, pixelFormat, defaultColor);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Hxx1::Fn<S>::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageInterface_Init_Offset), mt_.ImageInterface_Init, width, height, storageFormat, pixelFormat, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageInterface::Hxx1::COWFn<S>::Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageInterface_Init_Offset), mt_.ImageInterface_Init, width, height, storageFormat, pixelFormat, defaultColor));
}
auto ImageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
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
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageLayerInterface, typename ImageInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageLayerInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageLayerInterface::Hxx2
{
	template <typename S> class CWrapper : public ImageInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImageInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageLayerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageLayerInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto ImageLayerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageLayerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(ImageFunctionsInterface_CreateSubImagePart, CreateSubImagePart, MAXON_EXPAND_VA_ARGS, (Result<ImageBaseRef>), const ImageBaseRef& imageRef, const DrawRectInt& rect);
	template <typename IMPL> void Init()
	{
		ImageFunctionsInterface_CreateSubImagePart = ImageFunctionsInterface_CreateSubImagePart_GetPtr<IMPL>(true);
	}
};

struct ImageFunctionsInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<ImageBaseRef> ImageFunctionsInterface_CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect) { return S::CreateSubImagePart(imageRef, rect); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageFunctionsInterface::CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect) -> Result<ImageBaseRef>
{
	return MTable::_instance.ImageFunctionsInterface_CreateSubImagePart(imageRef, rect);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image)
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

