
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_PixelFormatIndexedColorInterface_InitColorTable) (maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr);
	maxon::Int _PixelFormatIndexedColorInterface_InitColorTable_Offset;
	PixelFormat (*_PixelFormatIndexedColorInterface_GetColorTablePixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset;
	Int (*_PixelFormatIndexedColorInterface_GetColorTableSize) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatIndexedColorInterface_GetColorTableSize_Offset;
	Result<void> (*_PixelFormatIndexedColorInterface_SetIndex) (maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData);
	maxon::Int _PixelFormatIndexedColorInterface_SetIndex_Offset;
	Result<void> (*_PixelFormatIndexedColorInterface_GetIndex) (const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData);
	maxon::Int _PixelFormatIndexedColorInterface_GetIndex_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, InitColorTable))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, InitColorTable), W, MTable>::type::_PixelFormatIndexedColorInterface_InitColorTable;
			_PixelFormatIndexedColorInterface_InitColorTable = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_InitColorTable)&>(ptr);
			_PixelFormatIndexedColorInterface_InitColorTable_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTablePixelFormat))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTablePixelFormat), W, MTable>::type::_PixelFormatIndexedColorInterface_GetColorTablePixelFormat;
			_PixelFormatIndexedColorInterface_GetColorTablePixelFormat = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetColorTablePixelFormat)&>(ptr);
			_PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTableSize))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTableSize), W, MTable>::type::_PixelFormatIndexedColorInterface_GetColorTableSize;
			_PixelFormatIndexedColorInterface_GetColorTableSize = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetColorTableSize)&>(ptr);
			_PixelFormatIndexedColorInterface_GetColorTableSize_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, SetIndex))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, SetIndex), W, MTable>::type::_PixelFormatIndexedColorInterface_SetIndex;
			_PixelFormatIndexedColorInterface_SetIndex = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_SetIndex)&>(ptr);
			_PixelFormatIndexedColorInterface_SetIndex_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetIndex))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetIndex), W, MTable>::type::_PixelFormatIndexedColorInterface_GetIndex;
			_PixelFormatIndexedColorInterface_GetIndex = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetIndex)&>(ptr);
			_PixelFormatIndexedColorInterface_GetIndex_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!PixelFormatInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
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
		static Result<void> _PixelFormatIndexedColorInterface_InitColorTable(maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr) { return ((typename S::Implementation*) this_)->InitColorTable(count, srcFormatPtr); }
		static PixelFormat _PixelFormatIndexedColorInterface_GetColorTablePixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTablePixelFormat(); }
		static Int _PixelFormatIndexedColorInterface_GetColorTableSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTableSize(); }
		static Result<void> _PixelFormatIndexedColorInterface_SetIndex(maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData) { return ((typename S::Implementation*) this_)->SetIndex(idx, srcPixelData); }
		static Result<void> _PixelFormatIndexedColorInterface_GetIndex(const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData) { return ((const typename S::Implementation*) this_)->GetIndex(idx, dstPixelData); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_InitColorTable((maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTablePixelFormat() const -> PixelFormat
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTableSize() const -> Int
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetColorTableSize((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetColorTableSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_SetIndex((maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetIndex((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ReferenceFunctionsImpl<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorTablePixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTablePixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorTableSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTableSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetColorTableSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTableSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetIndex(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData));
}
auto PixelFormatIndexedColorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatIndexedColorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

