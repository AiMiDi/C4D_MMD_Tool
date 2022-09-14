
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
	PRIVATE_MAXON_MF_POINTER(ImageChannelTypeInterface_GetDefaultFillValue, GetDefaultFillValue, true, maxon::GenericComponent, const, (Pix8u));
	maxon::Int ImageChannelTypeInterface_GetDefaultFillValue_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageChannelTypeInterface_GetColorSpace, GetColorSpace, true, maxon::GenericComponent, const, (ColorSpace));
	maxon::Int ImageChannelTypeInterface_GetColorSpace_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageChannelTypeInterface_GetChannel, GetChannel, true, maxon::GenericComponent, const, (ImageChannel), const DataType& pixelType);
	maxon::Int ImageChannelTypeInterface_GetChannel_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetDefaultFillValue))
	{
		maxon::Tie(ImageChannelTypeInterface_GetDefaultFillValue, ImageChannelTypeInterface_GetDefaultFillValue_Offset) = ImageChannelTypeInterface_GetDefaultFillValue_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetColorSpace))
	{
		maxon::Tie(ImageChannelTypeInterface_GetColorSpace, ImageChannelTypeInterface_GetColorSpace_Offset) = ImageChannelTypeInterface_GetColorSpace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelTypeInterface, GetChannel))
	{
		maxon::Tie(ImageChannelTypeInterface_GetChannel, ImageChannelTypeInterface_GetChannel_Offset) = ImageChannelTypeInterface_GetChannel_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageChannelTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageChannelTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelTypeInterface_GetDefaultFillValue, maxon::GenericComponent, const, (Pix8u)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDefaultFillValue(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelTypeInterface_GetColorSpace, maxon::GenericComponent, const, (ColorSpace)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetColorSpace(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelTypeInterface_GetChannel, maxon::GenericComponent, const, (ImageChannel), const DataType& pixelType) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannel(pixelType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetDefaultFillValue() const -> Pix8u
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetDefaultFillValue_Offset), mt_.ImageChannelTypeInterface_GetDefaultFillValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetColorSpace() const -> ColorSpace
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetColorSpace_Offset), mt_.ImageChannelTypeInterface_GetColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::GetChannel(const DataType& pixelType) const -> ImageChannel
{
	const ImageChannelTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelTypeInterface_GetChannel_Offset), mt_.ImageChannelTypeInterface_GetChannel, pixelType);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetDefaultFillValue() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Pix8u>, Pix8u>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Pix8u>, Pix8u>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Pix8u>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetDefaultFillValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetDefaultFillValue_Offset), mt_.ImageChannelTypeInterface_GetDefaultFillValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetColorSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetColorSpace_Offset), mt_.ImageChannelTypeInterface_GetColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetChannel(const DataType& pixelType) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ImageChannel>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelTypeInterface, o_, ImageChannelTypeInterface_GetChannel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelTypeInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelTypeInterface_GetChannel_Offset), mt_.ImageChannelTypeInterface_GetChannel, pixelType));
}
template <typename S> template <typename PIXELDEPTH> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelTypeInterface::Hxx1::ConstFn<S>::GetChannel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ImageChannelTypeInterface::GetChannel on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelTypeInterface* o_ = (const ImageChannelTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ImageChannel>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	PRIVATE_MAXON_MF_POINTER(ImageChannelInterface_GetChannelBits, GetChannelBits, true, maxon::GenericComponent, const, (BITS));
	maxon::Int ImageChannelInterface_GetChannelBits_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageChannelInterface_GetChannelType, GetChannelType, true, maxon::GenericComponent, const, (ImageChannelType));
	maxon::Int ImageChannelInterface_GetChannelType_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageChannelInterface_GetDataType, GetDataType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int ImageChannelInterface_GetDataType_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageChannelInterface_IsIdenticalComponent, IsIdenticalComponent, true, maxon::GenericComponent, const, (Bool), const void* a, const void* b, Int oneTolerance);
	maxon::Int ImageChannelInterface_IsIdenticalComponent_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetChannelBits))
	{
		maxon::Tie(ImageChannelInterface_GetChannelBits, ImageChannelInterface_GetChannelBits_Offset) = ImageChannelInterface_GetChannelBits_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetChannelType))
	{
		maxon::Tie(ImageChannelInterface_GetChannelType, ImageChannelInterface_GetChannelType_Offset) = ImageChannelInterface_GetChannelType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, GetDataType))
	{
		maxon::Tie(ImageChannelInterface_GetDataType, ImageChannelInterface_GetDataType_Offset) = ImageChannelInterface_GetDataType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageChannelInterface, IsIdenticalComponent))
	{
		maxon::Tie(ImageChannelInterface_IsIdenticalComponent, ImageChannelInterface_IsIdenticalComponent_Offset) = ImageChannelInterface_IsIdenticalComponent_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageChannelInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageChannelInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelInterface_GetChannelBits, maxon::GenericComponent, const, (BITS)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelBits(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelInterface_GetChannelType, maxon::GenericComponent, const, (ImageChannelType)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelType(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelInterface_GetDataType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageChannelInterface_IsIdenticalComponent, maxon::GenericComponent, const, (Bool), const void* a, const void* b, Int oneTolerance) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsIdenticalComponent(a, b, oneTolerance); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetChannelBits() const -> BITS
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetChannelBits_Offset), mt_.ImageChannelInterface_GetChannelBits);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetChannelType() const -> ImageChannelType
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetChannelType_Offset), mt_.ImageChannelInterface_GetChannelType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::GetDataType() const -> const DataType&
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_GetDataType_Offset), mt_.ImageChannelInterface_GetDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const -> Bool
{
	const ImageChannelInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageChannelInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageChannelInterface_IsIdenticalComponent_Offset), mt_.ImageChannelInterface_IsIdenticalComponent, a, b, oneTolerance);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetChannelBits() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetChannelBits) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetChannelBits_Offset), mt_.ImageChannelInterface_GetChannelBits));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetChannelType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannelType>, ImageChannelType>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannelType>, ImageChannelType>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ImageChannelType>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetChannelType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetChannelType_Offset), mt_.ImageChannelInterface_GetChannelType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_GetDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_GetDataType_Offset), mt_.ImageChannelInterface_GetDataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageChannelInterface::Hxx1::ConstFn<S>::IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageChannelInterface* o_ = (const ImageChannelInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageChannelInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageChannelInterface, o_, ImageChannelInterface_IsIdenticalComponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageChannelInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageChannelInterface>() : PRIVATE_MAXON_VTABLE(ImageChannelInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageChannelInterface_IsIdenticalComponent_Offset), mt_.ImageChannelInterface_IsIdenticalComponent, a, b, oneTolerance));
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

