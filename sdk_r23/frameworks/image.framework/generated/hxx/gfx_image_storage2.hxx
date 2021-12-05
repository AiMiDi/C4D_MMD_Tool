
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ImagePixelStorageInterface_Init) (maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor);
	maxon::Int _ImagePixelStorageInterface_Init_Offset;
	Int (*_ImagePixelStorageInterface_GetWidth) (const maxon::GenericComponent* this_);
	maxon::Int _ImagePixelStorageInterface_GetWidth_Offset;
	Int (*_ImagePixelStorageInterface_GetHeight) (const maxon::GenericComponent* this_);
	maxon::Int _ImagePixelStorageInterface_GetHeight_Offset;
	Int (*_ImagePixelStorageInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int _ImagePixelStorageInterface_GetChannelCount_Offset;
	PixelFormat (*_ImagePixelStorageInterface_GetPixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int _ImagePixelStorageInterface_GetPixelFormat_Offset;
	Result<GetPixelHandlerStruct> (*_ImagePixelStorageInterface_GetPixelHandler) (const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
	maxon::Int _ImagePixelStorageInterface_GetPixelHandler_Offset;
	Result<SetPixelHandlerStruct> (*_ImagePixelStorageInterface_SetPixelHandler) (maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int _ImagePixelStorageInterface_SetPixelHandler_Offset;
/// @cond INTERNAL

	void (*_ImagePixelStorageInterface_FreePixelHandler) (const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel);
	maxon::Int _ImagePixelStorageInterface_FreePixelHandler_Offset;
	void (*_ImagePixelStorageInterface_FreePixelHandler_1) (const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
	maxon::Int _ImagePixelStorageInterface_FreePixelHandler_1_Offset;
/// @endcond

	Result<void> (*_ImagePixelStorageInterface_GetComponent) (const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags);
	maxon::Int _ImagePixelStorageInterface_GetComponent_Offset;
	Result<void> (*_ImagePixelStorageInterface_SetComponent) (maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	maxon::Int _ImagePixelStorageInterface_SetComponent_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, Init), W, MTable>::type::_ImagePixelStorageInterface_Init;
			_ImagePixelStorageInterface_Init = reinterpret_cast<const decltype(_ImagePixelStorageInterface_Init)&>(ptr);
			_ImagePixelStorageInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetWidth))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetWidth), W, MTable>::type::_ImagePixelStorageInterface_GetWidth;
			_ImagePixelStorageInterface_GetWidth = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetWidth)&>(ptr);
			_ImagePixelStorageInterface_GetWidth_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetHeight))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetHeight), W, MTable>::type::_ImagePixelStorageInterface_GetHeight;
			_ImagePixelStorageInterface_GetHeight = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetHeight)&>(ptr);
			_ImagePixelStorageInterface_GetHeight_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetChannelCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetChannelCount), W, MTable>::type::_ImagePixelStorageInterface_GetChannelCount;
			_ImagePixelStorageInterface_GetChannelCount = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetChannelCount)&>(ptr);
			_ImagePixelStorageInterface_GetChannelCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelFormat))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelFormat), W, MTable>::type::_ImagePixelStorageInterface_GetPixelFormat;
			_ImagePixelStorageInterface_GetPixelFormat = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetPixelFormat)&>(ptr);
			_ImagePixelStorageInterface_GetPixelFormat_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetPixelHandler), W, MTable>::type::_ImagePixelStorageInterface_GetPixelHandler;
			_ImagePixelStorageInterface_GetPixelHandler = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetPixelHandler)&>(ptr);
			_ImagePixelStorageInterface_GetPixelHandler_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetPixelHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetPixelHandler), W, MTable>::type::_ImagePixelStorageInterface_SetPixelHandler;
			_ImagePixelStorageInterface_SetPixelHandler = reinterpret_cast<const decltype(_ImagePixelStorageInterface_SetPixelHandler)&>(ptr);
			_ImagePixelStorageInterface_SetPixelHandler_Offset = offset;
		}
/// @cond INTERNAL

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler), W, MTable>::type::_ImagePixelStorageInterface_FreePixelHandler;
			_ImagePixelStorageInterface_FreePixelHandler = reinterpret_cast<const decltype(_ImagePixelStorageInterface_FreePixelHandler)&>(ptr);
			_ImagePixelStorageInterface_FreePixelHandler_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, FreePixelHandler), W, MTable>::type::_ImagePixelStorageInterface_FreePixelHandler_1;
			_ImagePixelStorageInterface_FreePixelHandler_1 = reinterpret_cast<const decltype(_ImagePixelStorageInterface_FreePixelHandler_1)&>(ptr);
			_ImagePixelStorageInterface_FreePixelHandler_1_Offset = offset;
		}
/// @endcond

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetComponent))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, GetComponent), W, MTable>::type::_ImagePixelStorageInterface_GetComponent;
			_ImagePixelStorageInterface_GetComponent = reinterpret_cast<const decltype(_ImagePixelStorageInterface_GetComponent)&>(ptr);
			_ImagePixelStorageInterface_GetComponent_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetComponent))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImagePixelStorageInterface, SetComponent), W, MTable>::type::_ImagePixelStorageInterface_SetComponent;
			_ImagePixelStorageInterface_SetComponent = reinterpret_cast<const decltype(_ImagePixelStorageInterface_SetComponent)&>(ptr);
			_ImagePixelStorageInterface_SetComponent_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
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
		static Result<void> _ImagePixelStorageInterface_Init(maxon::GenericComponent* this_, Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) { return ((typename S::Implementation*) this_)->Init(width, height, format, defaultColor); }
		static Int _ImagePixelStorageInterface_GetWidth(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetWidth(); }
		static Int _ImagePixelStorageInterface_GetHeight(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHeight(); }
		static Int _ImagePixelStorageInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
		static PixelFormat _ImagePixelStorageInterface_GetPixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPixelFormat(); }
		static Result<GetPixelHandlerStruct> _ImagePixelStorageInterface_GetPixelHandler(const maxon::GenericComponent* this_, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) { return ((const typename S::Implementation*) this_)->GetPixelHandler(dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags); }
		static Result<SetPixelHandlerStruct> _ImagePixelStorageInterface_SetPixelHandler(maxon::GenericComponent* this_, const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((typename S::Implementation*) this_)->SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification); }
/// @cond INTERNAL

		static void _ImagePixelStorageInterface_FreePixelHandler(const maxon::GenericComponent* this_, GetPixelHandlerStruct& pixel) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel); }
		static void _ImagePixelStorageInterface_FreePixelHandler_1(const maxon::GenericComponent* this_, SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) { return ((const typename S::Implementation*) this_)->FreePixelHandler(pixel, updateRegionNotification); }
/// @endcond

		static Result<void> _ImagePixelStorageInterface_GetComponent(const maxon::GenericComponent* this_, Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) this_)->GetComponent(component, pos, data, inc, flags); }
		static Result<void> _ImagePixelStorageInterface_SetComponent(maxon::GenericComponent* this_, Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) { return ((typename S::Implementation*) this_)->SetComponent(component, pos, data, inc, flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_Init((maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetWidth() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetWidth((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetWidth_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetHeight() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetHeight((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetHeight_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetChannelCount() const -> Int
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelFormat() const -> PixelFormat
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetPixelFormat((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetPixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetPixelHandler((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_SetPixelHandler((maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_FreePixelHandler((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_FreePixelHandler_Offset, pixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> void
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_FreePixelHandler_1((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_FreePixelHandler_1_Offset, pixel, updateRegionNotification);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_GetComponent((const maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_GetComponent_Offset, component, pos, data, inc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	const ImagePixelStorageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, this); return mt_._ImagePixelStorageInterface_SetComponent((maxon::GenericComponent*) this + mt_._ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_Init_Offset, width, height, format, defaultColor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetWidth) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetWidth(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetWidth_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHeight() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetHeight) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetHeight(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetHeight_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetPixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetPixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetPixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetPixelHandler_Offset, dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetPixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_SetPixelHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_SetPixelHandler_Offset, srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FreePixelHandler(GetPixelHandlerStruct& pixel) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	mt_._ImagePixelStorageInterface_FreePixelHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_FreePixelHandler_Offset, pixel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_FreePixelHandler_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	mt_._ImagePixelStorageInterface_FreePixelHandler_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_FreePixelHandler_1_Offset, pixel, updateRegionNotification);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImagePixelStorageInterface* o_ = (const ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImagePixelStorageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_GetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_GetComponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_GetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::ReferenceFunctionsImpl<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImagePixelStorageInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImagePixelStorageInterface* o_ = (ImagePixelStorageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImagePixelStorageInterface, o_, ImagePixelStorageInterface_SetComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ImagePixelStorageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImagePixelStorageInterface>() : PRIVATE_MAXON_VTABLE(ImagePixelStorageInterface, o_); 
	return (mt_._ImagePixelStorageInterface_SetComponent(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImagePixelStorageInterface_SetComponent_Offset, component, pos, data, inc, flags));
}
auto ImagePixelStorageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImagePixelStorageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

