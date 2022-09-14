
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


struct ImagePixelStorageInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FreePixelHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetComponent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHeight);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetWidth);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetComponent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetPixelHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor);
	maxon::Int ImagePixelStorageInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetWidth, GetWidth, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImagePixelStorageInterface_GetWidth_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetHeight, GetHeight, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImagePixelStorageInterface_GetHeight_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetChannelCount, GetChannelCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int ImagePixelStorageInterface_GetChannelCount_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetPixelFormat, GetPixelFormat, true, maxon::GenericComponent, const, (PixelFormat));
	maxon::Int ImagePixelStorageInterface_GetPixelFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetPixelHandler, GetPixelHandler, true, maxon::GenericComponent, const, (Result<GetPixelHandlerStruct>), const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
	maxon::Int ImagePixelStorageInterface_GetPixelHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_SetPixelHandler, SetPixelHandler, true, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int ImagePixelStorageInterface_SetPixelHandler_Offset;
/// @cond INTERNAL

	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_FreePixelHandler, FreePixelHandler, true, maxon::GenericComponent, const, (void), GetPixelHandlerStruct& pixel);
	maxon::Int ImagePixelStorageInterface_FreePixelHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_FreePixelHandler_1, FreePixelHandler, true, maxon::GenericComponent, const, (void), SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int ImagePixelStorageInterface_FreePixelHandler_1_Offset;
/// @endcond

	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_GetComponent, GetComponent, true, maxon::GenericComponent, const, (Result<void>), Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags);
	maxon::Int ImagePixelStorageInterface_GetComponent_Offset;
	PRIVATE_MAXON_MF_POINTER(ImagePixelStorageInterface_SetComponent, SetComponent, true, maxon::GenericComponent,, (Result<void>), Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	maxon::Int ImagePixelStorageInterface_SetComponent_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, Init))
	{
		maxon::Tie(ImagePixelStorageInterface_Init, ImagePixelStorageInterface_Init_Offset) = ImagePixelStorageInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetWidth))
	{
		maxon::Tie(ImagePixelStorageInterface_GetWidth, ImagePixelStorageInterface_GetWidth_Offset) = ImagePixelStorageInterface_GetWidth_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetHeight))
	{
		maxon::Tie(ImagePixelStorageInterface_GetHeight, ImagePixelStorageInterface_GetHeight_Offset) = ImagePixelStorageInterface_GetHeight_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetChannelCount))
	{
		maxon::Tie(ImagePixelStorageInterface_GetChannelCount, ImagePixelStorageInterface_GetChannelCount_Offset) = ImagePixelStorageInterface_GetChannelCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelFormat))
	{
		maxon::Tie(ImagePixelStorageInterface_GetPixelFormat, ImagePixelStorageInterface_GetPixelFormat_Offset) = ImagePixelStorageInterface_GetPixelFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelHandler))
	{
		maxon::Tie(ImagePixelStorageInterface_GetPixelHandler, ImagePixelStorageInterface_GetPixelHandler_Offset) = ImagePixelStorageInterface_GetPixelHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetPixelHandler))
	{
		maxon::Tie(ImagePixelStorageInterface_SetPixelHandler, ImagePixelStorageInterface_SetPixelHandler_Offset) = ImagePixelStorageInterface_SetPixelHandler_GetPtr<W>(offset, true);
	}
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
	{
		maxon::Tie(ImagePixelStorageInterface_FreePixelHandler, ImagePixelStorageInterface_FreePixelHandler_Offset) = ImagePixelStorageInterface_FreePixelHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
	{
		maxon::Tie(ImagePixelStorageInterface_FreePixelHandler_1, ImagePixelStorageInterface_FreePixelHandler_1_Offset) = ImagePixelStorageInterface_FreePixelHandler_1_GetPtr<W>(offset, true);
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetComponent))
	{
		maxon::Tie(ImagePixelStorageInterface_GetComponent, ImagePixelStorageInterface_GetComponent_Offset) = ImagePixelStorageInterface_GetComponent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetComponent))
	{
		maxon::Tie(ImagePixelStorageInterface_SetComponent, ImagePixelStorageInterface_SetComponent_Offset) = ImagePixelStorageInterface_SetComponent_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImagePixelStorageInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImagePixelStorageInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImagePixelStorageInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FreePixelHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetComponent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHeight);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetWidth);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetComponent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetPixelHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImagePixelStorageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImagePixelStorageInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_Init, maxon::GenericComponent,, (Result<void>), Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(width, height, format, defaultColor); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetWidth, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetWidth(); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetHeight, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHeight(); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetChannelCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelCount(); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetPixelFormat, maxon::GenericComponent, const, (PixelFormat)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPixelFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetPixelHandler, maxon::GenericComponent, const, (Result<GetPixelHandlerStruct>), const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPixelHandler(dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_SetPixelHandler, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification); }
/// @cond INTERNAL

		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_FreePixelHandler, maxon::GenericComponent, const, (void), GetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FreePixelHandler(pixel); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_FreePixelHandler_1, maxon::GenericComponent, const, (void), SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FreePixelHandler(pixel, updateRegionNotification); }
/// @endcond

		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_GetComponent, maxon::GenericComponent, const, (Result<void>), Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetComponent(component, pos, data, inc, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ImagePixelStorageInterface_SetComponent, maxon::GenericComponent,, (Result<void>), Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetComponent(component, pos, data, inc, flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_Init_Offset), mt_.ImagePixelStorageInterface_Init, width, height, format, defaultColor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetWidth() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetWidth_Offset), mt_.ImagePixelStorageInterface_GetWidth);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetHeight() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetHeight_Offset), mt_.ImagePixelStorageInterface_GetHeight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetChannelCount() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetChannelCount_Offset), mt_.ImagePixelStorageInterface_GetChannelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelFormat() const -> PixelFormat
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetPixelFormat_Offset), mt_.ImagePixelStorageInterface_GetPixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetPixelHandler_Offset), mt_.ImagePixelStorageInterface_GetPixelHandler, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset), mt_.ImagePixelStorageInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_FreePixelHandler_Offset), mt_.ImagePixelStorageInterface_FreePixelHandler, pixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_FreePixelHandler_1_Offset), mt_.ImagePixelStorageInterface_FreePixelHandler_1, pixel, updateRegionNotification);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetComponent_Offset), mt_.ImagePixelStorageInterface_GetComponent, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_SetComponent_Offset), mt_.ImagePixelStorageInterface_SetComponent, component, pos, data, inc, flags);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_Init_Offset), mt_.ImagePixelStorageInterface_Init, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_Init_Offset), mt_.ImagePixelStorageInterface_Init, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetWidth) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetWidth_Offset), mt_.ImagePixelStorageInterface_GetWidth));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetHeight() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetHeight) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetHeight_Offset), mt_.ImagePixelStorageInterface_GetHeight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetChannelCount_Offset), mt_.ImagePixelStorageInterface_GetChannelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetPixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelFormat_Offset), mt_.ImagePixelStorageInterface_GetPixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelHandler_Offset), mt_.ImagePixelStorageInterface_GetPixelHandler, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset), mt_.ImagePixelStorageInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset), mt_.ImagePixelStorageInterface_SetPixelHandler, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_Offset), mt_.ImagePixelStorageInterface_FreePixelHandler, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_1_Offset), mt_.ImagePixelStorageInterface_FreePixelHandler_1, pixel, updateRegionNotification);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetComponent_Offset), mt_.ImagePixelStorageInterface_GetComponent, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetComponent_Offset), mt_.ImagePixelStorageInterface_SetComponent, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetComponent_Offset), mt_.ImagePixelStorageInterface_SetComponent, component, pos, data, inc, flags));
}
auto ImagePixelStorageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImagePixelStorageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_storage)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImagePixelStorageInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImagePixelStorageInterface() { new (s_ui_maxon_ImagePixelStorageInterface) maxon::EntityUse(ImagePixelStorageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_storage.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImagePixelStorageInterface(ImagePixelStorageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_storage.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

