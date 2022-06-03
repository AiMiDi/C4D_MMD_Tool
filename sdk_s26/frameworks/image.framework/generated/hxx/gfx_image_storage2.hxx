
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
	Result<void> (*ImagePixelStorageInterface_Init) (maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor);
	maxon::Int ImagePixelStorageInterface_Init_Offset;
	Int (*ImagePixelStorageInterface_GetWidth) (const maxon::GenericComponent* this_);
	maxon::Int ImagePixelStorageInterface_GetWidth_Offset;
	Int (*ImagePixelStorageInterface_GetHeight) (const maxon::GenericComponent* this_);
	maxon::Int ImagePixelStorageInterface_GetHeight_Offset;
	Int (*ImagePixelStorageInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int ImagePixelStorageInterface_GetChannelCount_Offset;
	PixelFormat (*ImagePixelStorageInterface_GetPixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int ImagePixelStorageInterface_GetPixelFormat_Offset;
	Result<GetPixelHandlerStruct> (*ImagePixelStorageInterface_GetPixelHandler) (const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
	maxon::Int ImagePixelStorageInterface_GetPixelHandler_Offset;
	Result<SetPixelHandlerStruct> (*ImagePixelStorageInterface_SetPixelHandler) (maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int ImagePixelStorageInterface_SetPixelHandler_Offset;
/// @cond INTERNAL

	void (*ImagePixelStorageInterface_FreePixelHandler) (const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel);
	maxon::Int ImagePixelStorageInterface_FreePixelHandler_Offset;
	void (*ImagePixelStorageInterface_FreePixelHandler_1) (const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int ImagePixelStorageInterface_FreePixelHandler_1_Offset;
/// @endcond

	Result<void> (*ImagePixelStorageInterface_GetComponent) (const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags);
	maxon::Int ImagePixelStorageInterface_GetComponent_Offset;
	Result<void> (*ImagePixelStorageInterface_SetComponent) (maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	maxon::Int ImagePixelStorageInterface_SetComponent_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, Init))
	{
		ImagePixelStorageInterface_Init = &W::ImagePixelStorageInterface_Init;
		ImagePixelStorageInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetWidth))
	{
		ImagePixelStorageInterface_GetWidth = &W::ImagePixelStorageInterface_GetWidth;
		ImagePixelStorageInterface_GetWidth_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetHeight))
	{
		ImagePixelStorageInterface_GetHeight = &W::ImagePixelStorageInterface_GetHeight;
		ImagePixelStorageInterface_GetHeight_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetChannelCount))
	{
		ImagePixelStorageInterface_GetChannelCount = &W::ImagePixelStorageInterface_GetChannelCount;
		ImagePixelStorageInterface_GetChannelCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelFormat))
	{
		ImagePixelStorageInterface_GetPixelFormat = &W::ImagePixelStorageInterface_GetPixelFormat;
		ImagePixelStorageInterface_GetPixelFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelHandler))
	{
		ImagePixelStorageInterface_GetPixelHandler = &W::ImagePixelStorageInterface_GetPixelHandler;
		ImagePixelStorageInterface_GetPixelHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetPixelHandler))
	{
		ImagePixelStorageInterface_SetPixelHandler = &W::ImagePixelStorageInterface_SetPixelHandler;
		ImagePixelStorageInterface_SetPixelHandler_Offset = offset;
	}
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
	{
		ImagePixelStorageInterface_FreePixelHandler = &W::ImagePixelStorageInterface_FreePixelHandler;
		ImagePixelStorageInterface_FreePixelHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
	{
		ImagePixelStorageInterface_FreePixelHandler_1 = &W::ImagePixelStorageInterface_FreePixelHandler_1;
		ImagePixelStorageInterface_FreePixelHandler_1_Offset = offset;
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetComponent))
	{
		ImagePixelStorageInterface_GetComponent = &W::ImagePixelStorageInterface_GetComponent;
		ImagePixelStorageInterface_GetComponent_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetComponent))
	{
		ImagePixelStorageInterface_SetComponent = &W::ImagePixelStorageInterface_SetComponent;
		ImagePixelStorageInterface_SetComponent_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImagePixelStorageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImagePixelStorageInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ImagePixelStorageInterface_Init(maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) { return ((typename S::Implementation*) this_)->Init(width, height, format, defaultColor); }
		static Int ImagePixelStorageInterface_GetWidth(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetWidth(); }
		static Int ImagePixelStorageInterface_GetHeight(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHeight(); }
		static Int ImagePixelStorageInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
		static PixelFormat ImagePixelStorageInterface_GetPixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPixelFormat(); }
		static Result<GetPixelHandlerStruct> ImagePixelStorageInterface_GetPixelHandler(const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) { return ((const typename S::Implementation*) this_)->GetPixelHandler(dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags); }
		static Result<SetPixelHandlerStruct> ImagePixelStorageInterface_SetPixelHandler(maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((typename S::Implementation*) this_)->SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification); }
/// @cond INTERNAL

		static void ImagePixelStorageInterface_FreePixelHandler(const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel); }
		static void ImagePixelStorageInterface_FreePixelHandler_1(const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel, updateRegionNotification); }
/// @endcond

		static Result<void> ImagePixelStorageInterface_GetComponent(const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) this_)->GetComponent(component, pos, data, inc, flags); }
		static Result<void> ImagePixelStorageInterface_SetComponent(maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) { return ((typename S::Implementation*) this_)->SetComponent(component, pos, data, inc, flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_Init((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetWidth() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetWidth((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetWidth_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetHeight() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetHeight((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetHeight_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetChannelCount() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelFormat() const -> PixelFormat
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetPixelFormat((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetPixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetPixelHandler((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_SetPixelHandler((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_FreePixelHandler((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_FreePixelHandler_Offset, pixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_FreePixelHandler_1((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_FreePixelHandler_1_Offset, pixel, updateRegionNotification);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_GetComponent((const maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_GetComponent_Offset, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_.ImagePixelStorageInterface_SetComponent((maxon::GenericComponent*) this + mt_.ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetWidth) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetWidth(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetWidth_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetHeight() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetHeight) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetHeight(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetHeight_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetPixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetPixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetPixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	mt_.ImagePixelStorageInterface_FreePixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_Offset, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	mt_.ImagePixelStorageInterface_FreePixelHandler_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_1_Offset, pixel, updateRegionNotification);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstFn<S>::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_GetComponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::Fn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWFn<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_.ImagePixelStorageInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags));
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

