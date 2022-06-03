
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImageChannelTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorSpace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDefaultFillValue);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Pix8u (*ImageChannelTypeInterface_GetDefaultFillValue) (const maxon::GenericComponent* this_);
	maxon::Int ImageChannelTypeInterface_GetDefaultFillValue_Offset;
	ColorSpace (*ImageChannelTypeInterface_GetColorSpace) (const maxon::GenericComponent* this_);
	maxon::Int ImageChannelTypeInterface_GetColorSpace_Offset;
	ImageChannel (*ImageChannelTypeInterface_GetChannel) (const maxon::GenericComponent* this_, const DataType& pixelType);
	maxon::Int ImageChannelTypeInterface_GetChannel_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetDefaultFillValue))
	{
		ImageChannelTypeInterface_GetDefaultFillValue = &W::ImageChannelTypeInterface_GetDefaultFillValue;
		ImageChannelTypeInterface_GetDefaultFillValue_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetColorSpace))
	{
		ImageChannelTypeInterface_GetColorSpace = &W::ImageChannelTypeInterface_GetColorSpace;
		ImageChannelTypeInterface_GetColorSpace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetChannel))
	{
		ImageChannelTypeInterface_GetChannel = &W::ImageChannelTypeInterface_GetChannel;
		ImageChannelTypeInterface_GetChannel_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageChannelTypeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageChannelTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageChannelTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorSpace);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDefaultFillValue);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImageChannelTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageChannelTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Pix8u ImageChannelTypeInterface_GetDefaultFillValue(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDefaultFillValue(); }
		static ColorSpace ImageChannelTypeInterface_GetColorSpace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorSpace(); }
		static ImageChannel ImageChannelTypeInterface_GetChannel(const maxon::GenericComponent* this_, const DataType& pixelType) { return ((const typename S::Implementation*) this_)->GetChannel(pixelType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetDefaultFillValue() const -> Pix8u
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return mt_.ImageChannelTypeInterface_GetDefaultFillValue((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetDefaultFillValue_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetColorSpace() const -> ColorSpace
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return mt_.ImageChannelTypeInterface_GetColorSpace((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetColorSpace_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetChannel(const DataType& pixelType) const -> ImageChannel
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return mt_.ImageChannelTypeInterface_GetChannel((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetChannel_Offset, pixelType);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetDefaultFillValue() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Pix8u>, Pix8u>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Pix8u>, Pix8u>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Pix8u>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetDefaultFillValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (mt_.ImageChannelTypeInterface_GetDefaultFillValue(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetDefaultFillValue_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetColorSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (mt_.ImageChannelTypeInterface_GetColorSpace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetColorSpace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetChannel(const DataType& pixelType) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ImageChannel>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetChannel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (mt_.ImageChannelTypeInterface_GetChannel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetChannel_Offset, pixelType));
}
template <typename S> template <typename PIXELDEPTH> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetChannel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ImageChannelTypeInterface::GetChannel on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ImageChannel>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetChannel<PIXELDEPTH>());
}
auto ImageChannelTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageChannelTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_imagechannel)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageChannelTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageChannelTypeInterface() { new (s_ui_maxon_ImageChannelTypeInterface) maxon::EntityUse(ImageChannelTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_imagechannel.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageChannelTypeInterface(ImageChannelTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_imagechannel.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ImageChannelInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelBits);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDataType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsIdenticalComponent);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	BITS (*ImageChannelInterface_GetChannelBits) (const maxon::GenericComponent* this_);
	maxon::Int ImageChannelInterface_GetChannelBits_Offset;
	ImageChannelType (*ImageChannelInterface_GetChannelType) (const maxon::GenericComponent* this_);
	maxon::Int ImageChannelInterface_GetChannelType_Offset;
	const DataType& (*ImageChannelInterface_GetDataType) (const maxon::GenericComponent* this_);
	maxon::Int ImageChannelInterface_GetDataType_Offset;
	Bool (*ImageChannelInterface_IsIdenticalComponent) (const maxon::GenericComponent* this_, const void* a, const void* b, Int oneTolerance);
	maxon::Int ImageChannelInterface_IsIdenticalComponent_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetChannelBits))
	{
		ImageChannelInterface_GetChannelBits = &W::ImageChannelInterface_GetChannelBits;
		ImageChannelInterface_GetChannelBits_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetChannelType))
	{
		ImageChannelInterface_GetChannelType = &W::ImageChannelInterface_GetChannelType;
		ImageChannelInterface_GetChannelType_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetDataType))
	{
		ImageChannelInterface_GetDataType = &W::ImageChannelInterface_GetDataType;
		ImageChannelInterface_GetDataType_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, IsIdenticalComponent))
	{
		ImageChannelInterface_IsIdenticalComponent = &W::ImageChannelInterface_IsIdenticalComponent;
		ImageChannelInterface_IsIdenticalComponent_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageChannelInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageChannelInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageChannelInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelBits);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDataType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsIdenticalComponent);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImageChannelInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageChannelInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static BITS ImageChannelInterface_GetChannelBits(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelBits(); }
		static ImageChannelType ImageChannelInterface_GetChannelType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelType(); }
		static const DataType& ImageChannelInterface_GetDataType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataType(); }
		static Bool ImageChannelInterface_IsIdenticalComponent(const maxon::GenericComponent* this_, const void* a, const void* b, Int oneTolerance) { return ((const typename S::Implementation*) this_)->IsIdenticalComponent(a, b, oneTolerance); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetChannelBits() const -> BITS
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return mt_.ImageChannelInterface_GetChannelBits((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetChannelBits_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetChannelType() const -> ImageChannelType
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return mt_.ImageChannelInterface_GetChannelType((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetChannelType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetDataType() const -> const DataType&
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return mt_.ImageChannelInterface_GetDataType((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetDataType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const -> Bool
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return mt_.ImageChannelInterface_IsIdenticalComponent((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_IsIdenticalComponent_Offset, a, b, oneTolerance);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetChannelBits() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetChannelBits) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (mt_.ImageChannelInterface_GetChannelBits(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetChannelBits_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetChannelType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannelType>, ImageChannelType>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannelType>, ImageChannelType>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ImageChannelType>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetChannelType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (mt_.ImageChannelInterface_GetChannelType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetChannelType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (mt_.ImageChannelInterface_GetDataType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetDataType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_IsIdenticalComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (mt_.ImageChannelInterface_IsIdenticalComponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_IsIdenticalComponent_Offset, a, b, oneTolerance));
}
auto ImageChannelInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageChannelInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_imagechannel)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageChannelInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageChannelInterface() { new (s_ui_maxon_ImageChannelInterface) maxon::EntityUse(ImageChannelInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_imagechannel.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageChannelInterface(ImageChannelInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_imagechannel.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

