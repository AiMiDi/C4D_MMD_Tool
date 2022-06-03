
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PixelFormatIndexedColorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorTablePixelFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorTableSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetIndex);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitColorTable);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetIndex);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*PixelFormatIndexedColorInterface_InitColorTable) (maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr);
	maxon::Int PixelFormatIndexedColorInterface_InitColorTable_Offset;
	PixelFormat (*PixelFormatIndexedColorInterface_GetColorTablePixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset;
	Int (*PixelFormatIndexedColorInterface_GetColorTableSize) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatIndexedColorInterface_GetColorTableSize_Offset;
	Result<void> (*PixelFormatIndexedColorInterface_SetIndex) (maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData);
	maxon::Int PixelFormatIndexedColorInterface_SetIndex_Offset;
	Result<void> (*PixelFormatIndexedColorInterface_GetIndex) (const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData);
	maxon::Int PixelFormatIndexedColorInterface_GetIndex_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, InitColorTable))
	{
		PixelFormatIndexedColorInterface_InitColorTable = &W::PixelFormatIndexedColorInterface_InitColorTable;
		PixelFormatIndexedColorInterface_InitColorTable_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTablePixelFormat))
	{
		PixelFormatIndexedColorInterface_GetColorTablePixelFormat = &W::PixelFormatIndexedColorInterface_GetColorTablePixelFormat;
		PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTableSize))
	{
		PixelFormatIndexedColorInterface_GetColorTableSize = &W::PixelFormatIndexedColorInterface_GetColorTableSize;
		PixelFormatIndexedColorInterface_GetColorTableSize_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, SetIndex))
	{
		PixelFormatIndexedColorInterface_SetIndex = &W::PixelFormatIndexedColorInterface_SetIndex;
		PixelFormatIndexedColorInterface_SetIndex_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetIndex))
	{
		PixelFormatIndexedColorInterface_GetIndex = &W::PixelFormatIndexedColorInterface_GetIndex;
		PixelFormatIndexedColorInterface_GetIndex_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatIndexedColorInterface, typename PixelFormatInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<PixelFormatIndexedColorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatIndexedColorInterface::Hxx2
{
	template <typename S> class CWrapper : public PixelFormatInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorTablePixelFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorTableSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIndex);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitColorTable);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetIndex);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename PixelFormatInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (PixelFormatIndexedColorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, PixelFormatIndexedColorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> PixelFormatIndexedColorInterface_InitColorTable(maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr) { return ((typename S::Implementation*) this_)->InitColorTable(count, srcFormatPtr); }
		static PixelFormat PixelFormatIndexedColorInterface_GetColorTablePixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTablePixelFormat(); }
		static Int PixelFormatIndexedColorInterface_GetColorTableSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTableSize(); }
		static Result<void> PixelFormatIndexedColorInterface_SetIndex(maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData) { return ((typename S::Implementation*) this_)->SetIndex(idx, srcPixelData); }
		static Result<void> PixelFormatIndexedColorInterface_GetIndex(const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData) { return ((const typename S::Implementation*) this_)->GetIndex(idx, dstPixelData); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_.PixelFormatIndexedColorInterface_InitColorTable((maxon::GenericComponent*) this + mt_.PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTablePixelFormat() const -> PixelFormat
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_.PixelFormatIndexedColorInterface_GetColorTablePixelFormat((const maxon::GenericComponent*) this + mt_.PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTableSize() const -> Int
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_.PixelFormatIndexedColorInterface_GetColorTableSize((const maxon::GenericComponent*) this + mt_.PixelFormatIndexedColorInterface_GetColorTableSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_.PixelFormatIndexedColorInterface_SetIndex((maxon::GenericComponent*) this + mt_.PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_.PixelFormatIndexedColorInterface_GetIndex((const maxon::GenericComponent*) this + mt_.PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::Fn<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWFn<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstFn<S>::GetColorTablePixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTablePixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_GetColorTablePixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstFn<S>::GetColorTableSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTableSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_GetColorTableSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_GetColorTableSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::Fn<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWFn<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstFn<S>::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_.PixelFormatIndexedColorInterface_GetIndex(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData));
}
auto PixelFormatIndexedColorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatIndexedColorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelformat_indexed)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatIndexedColorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatIndexedColorInterface() { new (s_ui_maxon_PixelFormatIndexedColorInterface) maxon::EntityUse(PixelFormatIndexedColorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_indexed.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatIndexedColorInterface(PixelFormatIndexedColorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_indexed.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

