
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CPyInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Decref);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Disconnect);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLibrary);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPyObject);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetRefCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTypeRef);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Incref);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_Init, Init, true, maxon::GenericComponent,, (void), const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	maxon::Int CPyInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_Incref, Incref, true, maxon::GenericComponent,, (void));
	maxon::Int CPyInterface_Incref_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_Decref, Decref, true, maxon::GenericComponent,, (void));
	maxon::Int CPyInterface_Decref_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_GetRefCount, GetRefCount, true, maxon::GenericComponent,, (Int64));
	maxon::Int CPyInterface_GetRefCount_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_GetLibrary, GetLibrary, true, maxon::GenericComponent, const, (const CPythonLibraryInterface*));
	maxon::Int CPyInterface_GetLibrary_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_GetTypeRef, GetTypeRef, true, maxon::GenericComponent, const, (CPyTypeRef));
	maxon::Int CPyInterface_GetTypeRef_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_GetPyObject, GetPyObject, true, maxon::GenericComponent, const, (NativePyObject*));
	maxon::Int CPyInterface_GetPyObject_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyInterface_Disconnect, Disconnect, true, maxon::GenericComponent,, (NativePyObject*));
	maxon::Int CPyInterface_Disconnect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Init))
	{
		maxon::Tie(CPyInterface_Init, CPyInterface_Init_Offset) = CPyInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Incref))
	{
		maxon::Tie(CPyInterface_Incref, CPyInterface_Incref_Offset) = CPyInterface_Incref_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Decref))
	{
		maxon::Tie(CPyInterface_Decref, CPyInterface_Decref_Offset) = CPyInterface_Decref_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetRefCount))
	{
		maxon::Tie(CPyInterface_GetRefCount, CPyInterface_GetRefCount_Offset) = CPyInterface_GetRefCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetLibrary))
	{
		maxon::Tie(CPyInterface_GetLibrary, CPyInterface_GetLibrary_Offset) = CPyInterface_GetLibrary_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetTypeRef))
	{
		maxon::Tie(CPyInterface_GetTypeRef, CPyInterface_GetTypeRef_Offset) = CPyInterface_GetTypeRef_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetPyObject))
	{
		maxon::Tie(CPyInterface_GetPyObject, CPyInterface_GetPyObject_Offset) = CPyInterface_GetPyObject_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Disconnect))
	{
		maxon::Tie(CPyInterface_Disconnect, CPyInterface_Disconnect_Offset) = CPyInterface_Disconnect_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CPyInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Decref);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Disconnect);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLibrary);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPyObject);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetRefCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTypeRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Incref);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CPyInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CPyInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_Init, maxon::GenericComponent,, (void), const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(lib, refType, pyObject); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_Incref, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Incref(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_Decref, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Decref(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_GetRefCount, maxon::GenericComponent,, (Int64)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetRefCount(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_GetLibrary, maxon::GenericComponent, const, (const CPythonLibraryInterface*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLibrary(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_GetTypeRef, maxon::GenericComponent, const, (CPyTypeRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTypeRef(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_GetPyObject, maxon::GenericComponent, const, (NativePyObject*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPyObject(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyInterface_Disconnect, maxon::GenericComponent,, (NativePyObject*)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Disconnect(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CPyInterface_Init_Offset), mt_.CPyInterface_Init, lib, refType, pyObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Incref() -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CPyInterface_Incref_Offset), mt_.CPyInterface_Incref);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Decref() -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CPyInterface_Decref_Offset), mt_.CPyInterface_Decref);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetRefCount() -> Int64
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CPyInterface_GetRefCount_Offset), mt_.CPyInterface_GetRefCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetLibrary() const -> const CPythonLibraryInterface*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyInterface_GetLibrary_Offset), mt_.CPyInterface_GetLibrary);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetTypeRef() const -> CPyTypeRef
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyInterface_GetTypeRef_Offset), mt_.CPyInterface_GetTypeRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetPyObject() const -> NativePyObject*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyInterface_GetPyObject_Offset), mt_.CPyInterface_GetPyObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Disconnect() -> NativePyObject*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CPyInterface_Disconnect_Offset), mt_.CPyInterface_Disconnect);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyRef
{
	return (CPyInterface::CreateRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyConstRef
{
	return (CPyInterface::CreateConstRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject) -> CPyTempRef
{
	return (CPyInterface::CreateTempRef(lib, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Init_Offset), mt_.CPyInterface_Init, lib, refType, pyObject);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Init_Offset), mt_.CPyInterface_Init, lib, refType, pyObject);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::Incref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Incref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Incref_Offset), mt_.CPyInterface_Incref);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::Incref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Incref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Incref_Offset), mt_.CPyInterface_Incref);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::Decref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Decref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Decref_Offset), mt_.CPyInterface_Decref);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::Decref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Decref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Decref_Offset), mt_.CPyInterface_Decref);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::GetRefCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetRefCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetRefCount_Offset), mt_.CPyInterface_GetRefCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::GetRefCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetRefCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetRefCount_Offset), mt_.CPyInterface_GetRefCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::GetLibrary() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetLibrary) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetLibrary_Offset), mt_.CPyInterface_GetLibrary));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::GetTypeRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyTypeRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetTypeRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetTypeRef_Offset), mt_.CPyInterface_GetTypeRef));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::GetPyObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetPyObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetPyObject_Offset), mt_.CPyInterface_GetPyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::Disconnect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Disconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Disconnect_Offset), mt_.CPyInterface_Disconnect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::Disconnect() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Disconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Disconnect_Offset), mt_.CPyInterface_Disconnect));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstFn<S>::Get() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CPyInterface::Get on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->Get<T>());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::Fn<S>::GetAndIncref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (o_->GetAndIncref<T>());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWFn<S>::GetAndIncref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CPyInterface::GetAndIncref on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetAndIncref<T>());
}
auto CPyInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_CPyInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_CPyInterface() { new (s_ui_maxon_py_CPyInterface) maxon::EntityUse(CPyInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_CPyInterface(CPyInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CPyTypeInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyTypeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CPyTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CPyTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CPyTypeInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTypeInterface::Hxx1::ConstFn<S>::CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTypeRef
{
	return (CPyTypeInterface::CreateTypeRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTypeInterface::Hxx1::ConstFn<S>::CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTypeConstRef
{
	return (CPyTypeInterface::CreateTypeConstRef(lib, refType, pyObject));
}
auto CPyTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_CPyTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_CPyTypeInterface() { new (s_ui_maxon_py_CPyTypeInterface) maxon::EntityUse(CPyTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_CPyTypeInterface(CPyTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CPyFrameInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBack);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLastInstruction);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CPyFrameInterface_GetBack, GetBack, true, maxon::GenericComponent, const, (CPyFrameRef));
	maxon::Int CPyFrameInterface_GetBack_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyFrameInterface_GetCode, GetCode, true, maxon::GenericComponent, const, (CPyCodeRef));
	maxon::Int CPyFrameInterface_GetCode_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyFrameInterface_GetLastInstruction, GetLastInstruction, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CPyFrameInterface_GetLastInstruction_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetBack))
	{
		maxon::Tie(CPyFrameInterface_GetBack, CPyFrameInterface_GetBack_Offset) = CPyFrameInterface_GetBack_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetCode))
	{
		maxon::Tie(CPyFrameInterface_GetCode, CPyFrameInterface_GetCode_Offset) = CPyFrameInterface_GetCode_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetLastInstruction))
	{
		maxon::Tie(CPyFrameInterface_GetLastInstruction, CPyFrameInterface_GetLastInstruction_Offset) = CPyFrameInterface_GetLastInstruction_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyFrameInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CPyFrameInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyFrameInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBack);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLastInstruction);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CPyFrameInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CPyFrameInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CPyFrameInterface_GetBack, maxon::GenericComponent, const, (CPyFrameRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBack(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyFrameInterface_GetCode, maxon::GenericComponent, const, (CPyCodeRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCode(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyFrameInterface_GetLastInstruction, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLastInstruction(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetBack() const -> CPyFrameRef
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyFrameInterface_GetBack_Offset), mt_.CPyFrameInterface_GetBack);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetCode() const -> CPyCodeRef
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyFrameInterface_GetCode_Offset), mt_.CPyFrameInterface_GetCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetLastInstruction() const -> Int32
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyFrameInterface_GetLastInstruction_Offset), mt_.CPyFrameInterface_GetLastInstruction);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstFn<S>::CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyFrameRef
{
	return (CPyFrameInterface::CreateFrameRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstFn<S>::GetBack() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetBack) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetBack_Offset), mt_.CPyFrameInterface_GetBack));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstFn<S>::GetCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetCode_Offset), mt_.CPyFrameInterface_GetCode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstFn<S>::GetLastInstruction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetLastInstruction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetLastInstruction_Offset), mt_.CPyFrameInterface_GetLastInstruction));
}
auto CPyFrameInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyFrameInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_CPyFrameInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_CPyFrameInterface() { new (s_ui_maxon_py_CPyFrameInterface) maxon::EntityUse(CPyFrameInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_CPyFrameInterface(CPyFrameInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CPyTracebackInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFrameRef);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLineNumber);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNext);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CPyTracebackInterface_GetNext, GetNext, true, maxon::GenericComponent, const, (CPyTracebackRef));
	maxon::Int CPyTracebackInterface_GetNext_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyTracebackInterface_GetLineNumber, GetLineNumber, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CPyTracebackInterface_GetLineNumber_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyTracebackInterface_GetFrameRef, GetFrameRef, true, maxon::GenericComponent, const, (CPyFrameRef));
	maxon::Int CPyTracebackInterface_GetFrameRef_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetNext))
	{
		maxon::Tie(CPyTracebackInterface_GetNext, CPyTracebackInterface_GetNext_Offset) = CPyTracebackInterface_GetNext_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetLineNumber))
	{
		maxon::Tie(CPyTracebackInterface_GetLineNumber, CPyTracebackInterface_GetLineNumber_Offset) = CPyTracebackInterface_GetLineNumber_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetFrameRef))
	{
		maxon::Tie(CPyTracebackInterface_GetFrameRef, CPyTracebackInterface_GetFrameRef_Offset) = CPyTracebackInterface_GetFrameRef_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyTracebackInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CPyTracebackInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyTracebackInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFrameRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLineNumber);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CPyTracebackInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CPyTracebackInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CPyTracebackInterface_GetNext, maxon::GenericComponent, const, (CPyTracebackRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetNext(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyTracebackInterface_GetLineNumber, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLineNumber(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyTracebackInterface_GetFrameRef, maxon::GenericComponent, const, (CPyFrameRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFrameRef(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetNext() const -> CPyTracebackRef
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyTracebackInterface_GetNext_Offset), mt_.CPyTracebackInterface_GetNext);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetLineNumber() const -> Int32
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyTracebackInterface_GetLineNumber_Offset), mt_.CPyTracebackInterface_GetLineNumber);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetFrameRef() const -> CPyFrameRef
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyTracebackInterface_GetFrameRef_Offset), mt_.CPyTracebackInterface_GetFrameRef);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstFn<S>::CreateTracebackRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTracebackRef
{
	return (CPyTracebackInterface::CreateTracebackRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstFn<S>::GetNext() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTracebackRef>, CPyTracebackRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTracebackRef>, CPyTracebackRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyTracebackRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetNext_Offset), mt_.CPyTracebackInterface_GetNext));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstFn<S>::GetLineNumber() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetLineNumber) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetLineNumber_Offset), mt_.CPyTracebackInterface_GetLineNumber));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstFn<S>::GetFrameRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetFrameRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetFrameRef_Offset), mt_.CPyTracebackInterface_GetFrameRef));
}
auto CPyTracebackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyTracebackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_CPyTracebackInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_CPyTracebackInterface() { new (s_ui_maxon_py_CPyTracebackInterface) maxon::EntityUse(CPyTracebackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_CPyTracebackInterface(CPyTracebackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CPyCodeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFilename);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CPyCodeInterface_GetFilename, GetFilename, true, maxon::GenericComponent, const, (CPyRef));
	maxon::Int CPyCodeInterface_GetFilename_Offset;
	PRIVATE_MAXON_MF_POINTER(CPyCodeInterface_GetName, GetName, true, maxon::GenericComponent, const, (CPyRef));
	maxon::Int CPyCodeInterface_GetName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetFilename))
	{
		maxon::Tie(CPyCodeInterface_GetFilename, CPyCodeInterface_GetFilename_Offset) = CPyCodeInterface_GetFilename_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetName))
	{
		maxon::Tie(CPyCodeInterface_GetName, CPyCodeInterface_GetName_Offset) = CPyCodeInterface_GetName_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyCodeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CPyCodeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyCodeInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFilename);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CPyCodeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CPyCodeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CPyCodeInterface_GetFilename, maxon::GenericComponent, const, (CPyRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFilename(); }
		PRIVATE_MAXON_MF_WRAPPER(CPyCodeInterface_GetName, maxon::GenericComponent, const, (CPyRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::GetFilename() const -> CPyRef
{
	const CPyCodeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyCodeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyCodeInterface_GetFilename_Offset), mt_.CPyCodeInterface_GetFilename);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::GetName() const -> CPyRef
{
	const CPyCodeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyCodeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CPyCodeInterface_GetName_Offset), mt_.CPyCodeInterface_GetName);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstFn<S>::CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyCodeRef
{
	return (CPyCodeInterface::CreateCodeRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstFn<S>::GetFilename() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyCodeInterface* o_ = (const CPyCodeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyCodeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyCodeInterface, o_, CPyCodeInterface_GetFilename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyCodeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyCodeInterface>() : PRIVATE_MAXON_VTABLE(CPyCodeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyCodeInterface_GetFilename_Offset), mt_.CPyCodeInterface_GetFilename));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CPyCodeInterface* o_ = (const CPyCodeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CPyCodeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyCodeInterface, o_, CPyCodeInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CPyCodeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyCodeInterface>() : PRIVATE_MAXON_VTABLE(CPyCodeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CPyCodeInterface_GetName_Offset), mt_.CPyCodeInterface_GetName));
}
auto CPyCodeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyCodeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_CPyCodeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_CPyCodeInterface() { new (s_ui_maxon_py_CPyCodeInterface) maxon::EntityUse(CPyCodeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_CPyCodeInterface(CPyCodeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyClassInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyClassInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyClassInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyClassInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyClassInterface::Hxx1::ConstFn<S>::CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyClassRef
{
	return (MPyClassInterface::CreateClassRef(lib, refType, pyObject));
}
auto MPyClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyClassInterface() { new (s_ui_maxon_py_MPyClassInterface) maxon::EntityUse(MPyClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyClassInterface(MPyClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyMemberInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyMemberInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyMemberInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyMemberInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyMemberInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyMemberInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyMemberInterface::Hxx1::ConstFn<S>::CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyMemberRef
{
	return (MPyMemberInterface::CreateMemberRef(lib, refType, pyObject));
}
auto MPyMemberInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyMemberInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyMemberInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyMemberInterface() { new (s_ui_maxon_py_MPyMemberInterface) maxon::EntityUse(MPyMemberInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyMemberInterface(MPyMemberInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyFunctionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFunction);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MPyFunctionInterface_GetFunction, GetFunction, true, maxon::GenericComponent,, (const reflection::Function*));
	maxon::Int MPyFunctionInterface_GetFunction_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyFunctionInterface, GetFunction))
	{
		maxon::Tie(MPyFunctionInterface_GetFunction, MPyFunctionInterface_GetFunction_Offset) = MPyFunctionInterface_GetFunction_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyFunctionInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyFunctionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyFunctionInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFunction);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyFunctionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyFunctionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MPyFunctionInterface_GetFunction, maxon::GenericComponent,, (const reflection::Function*)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetFunction(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::GetFunction() -> const reflection::Function*
{
	const MPyFunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyFunctionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MPyFunctionInterface_GetFunction_Offset), mt_.MPyFunctionInterface_GetFunction);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::ConstFn<S>::CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyFunctionRef
{
	return (MPyFunctionInterface::CreateFunctionRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::Fn<S>::GetFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyFunctionInterface* o_ = (MPyFunctionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyFunctionInterface, o_, MPyFunctionInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyFunctionInterface>() : PRIVATE_MAXON_VTABLE(MPyFunctionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyFunctionInterface_GetFunction_Offset), mt_.MPyFunctionInterface_GetFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::COWFn<S>::GetFunction() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyFunctionInterface* o_ = (MPyFunctionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyFunctionInterface, o_, MPyFunctionInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyFunctionInterface>() : PRIVATE_MAXON_VTABLE(MPyFunctionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyFunctionInterface_GetFunction_Offset), mt_.MPyFunctionInterface_GetFunction));
}
auto MPyFunctionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyFunctionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyFunctionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyFunctionInterface() { new (s_ui_maxon_py_MPyFunctionInterface) maxon::EntityUse(MPyFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyFunctionInterface(MPyFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyHashMapInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHashMap);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MPyHashMapInterface_GetHashMap, GetHashMap, true, maxon::GenericComponent,, (HashMap<Data, Data>*));
	maxon::Int MPyHashMapInterface_GetHashMap_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyHashMapInterface, GetHashMap))
	{
		maxon::Tie(MPyHashMapInterface_GetHashMap, MPyHashMapInterface_GetHashMap_Offset) = MPyHashMapInterface_GetHashMap_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyHashMapInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyHashMapInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyHashMapInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHashMap);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyHashMapInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyHashMapInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MPyHashMapInterface_GetHashMap, maxon::GenericComponent,, (HashMap<Data, Data>*)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetHashMap(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyHashMapInterface::GetHashMap() -> HashMap<Data, Data>*
{
	const MPyHashMapInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyHashMapInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MPyHashMapInterface_GetHashMap_Offset), mt_.MPyHashMapInterface_GetHashMap);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyHashMapInterface::Hxx1::ConstFn<S>::CreateHashMapRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyHashMapRef
{
	return (MPyHashMapInterface::CreateHashMapRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyHashMapInterface::Hxx1::Fn<S>::GetHashMap() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashMap<Data, Data>*>, HashMap<Data, Data>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashMap<Data, Data>*>, HashMap<Data, Data>*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyHashMapInterface* o_ = (MPyHashMapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyHashMapInterface, o_, MPyHashMapInterface_GetHashMap) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyHashMapInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyHashMapInterface>() : PRIVATE_MAXON_VTABLE(MPyHashMapInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyHashMapInterface_GetHashMap_Offset), mt_.MPyHashMapInterface_GetHashMap));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyHashMapInterface::Hxx1::COWFn<S>::GetHashMap() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HashMap<Data, Data>*, maxon::Result<HashMap<Data, Data>*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HashMap<Data, Data>*, maxon::Result<HashMap<Data, Data>*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyHashMapInterface* o_ = (MPyHashMapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyHashMapInterface, o_, MPyHashMapInterface_GetHashMap) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyHashMapInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyHashMapInterface>() : PRIVATE_MAXON_VTABLE(MPyHashMapInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyHashMapInterface_GetHashMap_Offset), mt_.MPyHashMapInterface_GetHashMap));
}
auto MPyHashMapInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyHashMapInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyHashMapInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyHashMapInterface() { new (s_ui_maxon_py_MPyHashMapInterface) maxon::EntityUse(MPyHashMapInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyHashMapInterface(MPyHashMapInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyDataTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetType);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MPyDataTypeInterface_GetType, GetType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int MPyDataTypeInterface_GetType_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataTypeInterface, GetType))
	{
		maxon::Tie(MPyDataTypeInterface_GetType, MPyDataTypeInterface_GetType_Offset) = MPyDataTypeInterface_GetType_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyDataTypeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyDataTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyDataTypeInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetType);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyDataTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyDataTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MPyDataTypeInterface_GetType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetType(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::GetType() const -> const DataType&
{
	const MPyDataTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MPyDataTypeInterface_GetType_Offset), mt_.MPyDataTypeInterface_GetType);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::Hxx1::ConstFn<S>::CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyDataTypeRef
{
	return (MPyDataTypeInterface::CreateDataTypeRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::Hxx1::ConstFn<S>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MPyDataTypeInterface* o_ = (const MPyDataTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MPyDataTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataTypeInterface, o_, MPyDataTypeInterface_GetType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataTypeInterface>() : PRIVATE_MAXON_VTABLE(MPyDataTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MPyDataTypeInterface_GetType_Offset), mt_.MPyDataTypeInterface_GetType));
}
auto MPyDataTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyDataTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyDataTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyDataTypeInterface() { new (s_ui_maxon_py_MPyDataTypeInterface) maxon::EntityUse(MPyDataTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyDataTypeInterface(MPyDataTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyDataInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMappingType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetPtr);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_GetType, GetType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int MPyDataInterface_GetType_Offset;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_GetMappingType, GetMappingType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int MPyDataInterface_GetMappingType_Offset;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_GetData, GetData, true, maxon::GenericComponent,, (Data*));
	maxon::Int MPyDataInterface_GetData_Offset;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_GetData_1, GetData, true, maxon::GenericComponent, const, (const Data*));
	maxon::Int MPyDataInterface_GetData_1_Offset;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_PrivateGetPtr, PrivateGetPtr, true, maxon::GenericComponent, const, (const Generic*));
	maxon::Int MPyDataInterface_PrivateGetPtr_Offset;
	PRIVATE_MAXON_MF_POINTER(MPyDataInterface_PrivateGetPtr_1, PrivateGetPtr, true, maxon::GenericComponent,, (Generic*));
	maxon::Int MPyDataInterface_PrivateGetPtr_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetType))
	{
		maxon::Tie(MPyDataInterface_GetType, MPyDataInterface_GetType_Offset) = MPyDataInterface_GetType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetMappingType))
	{
		maxon::Tie(MPyDataInterface_GetMappingType, MPyDataInterface_GetMappingType_Offset) = MPyDataInterface_GetMappingType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData))
	{
		maxon::Tie(MPyDataInterface_GetData, MPyDataInterface_GetData_Offset) = MPyDataInterface_GetData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData))
	{
		maxon::Tie(MPyDataInterface_GetData_1, MPyDataInterface_GetData_1_Offset) = MPyDataInterface_GetData_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr))
	{
		maxon::Tie(MPyDataInterface_PrivateGetPtr, MPyDataInterface_PrivateGetPtr_Offset) = MPyDataInterface_PrivateGetPtr_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr))
	{
		maxon::Tie(MPyDataInterface_PrivateGetPtr_1, MPyDataInterface_PrivateGetPtr_1_Offset) = MPyDataInterface_PrivateGetPtr_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyDataInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyDataInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyDataInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMappingType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetPtr);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyDataInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyDataInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_GetType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetType(); }
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_GetMappingType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetMappingType(); }
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_GetData, maxon::GenericComponent,, (Data*)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetData(); }
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_GetData_1, maxon::GenericComponent, const, (const Data*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetData(); }
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_PrivateGetPtr, maxon::GenericComponent, const, (const Generic*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetPtr(); }
		PRIVATE_MAXON_MF_WRAPPER(MPyDataInterface_PrivateGetPtr_1, maxon::GenericComponent,, (Generic*)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateGetPtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetType() const -> const DataType&
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MPyDataInterface_GetType_Offset), mt_.MPyDataInterface_GetType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetMappingType() const -> const DataType&
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MPyDataInterface_GetMappingType_Offset), mt_.MPyDataInterface_GetMappingType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetData() -> Data*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MPyDataInterface_GetData_Offset), mt_.MPyDataInterface_GetData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetData() const -> const Data*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MPyDataInterface_GetData_1_Offset), mt_.MPyDataInterface_GetData_1);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::PrivateGetPtr() const -> const Generic*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MPyDataInterface_PrivateGetPtr_Offset), mt_.MPyDataInterface_PrivateGetPtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::PrivateGetPtr() -> Generic*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MPyDataInterface_PrivateGetPtr_1_Offset), mt_.MPyDataInterface_PrivateGetPtr_1);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstFn<S>::CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyDataRef
{
	return (MPyDataInterface::CreateDataRef(lib, refType, pyObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstFn<S>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetType_Offset), mt_.MPyDataInterface_GetType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstFn<S>::GetMappingType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetMappingType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetMappingType_Offset), mt_.MPyDataInterface_GetMappingType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::Fn<S>::GetData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Data*>, Data*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Data*>, Data*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyDataInterface* o_ = (MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetData_Offset), mt_.MPyDataInterface_GetData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstFn<S>::GetData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetData_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetData_1_Offset), mt_.MPyDataInterface_GetData_1));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstFn<S>::PrivateGetPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_PrivateGetPtr) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_PrivateGetPtr_Offset), mt_.MPyDataInterface_PrivateGetPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::Fn<S>::PrivateGetPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MPyDataInterface* o_ = (MPyDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_PrivateGetPtr_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_PrivateGetPtr_1_Offset), mt_.MPyDataInterface_PrivateGetPtr_1));
}
auto MPyDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyDataInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyDataInterface() { new (s_ui_maxon_py_MPyDataInterface) maxon::EntityUse(MPyDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyDataInterface(MPyDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyCallerContextInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyCallerContextInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MPyCallerContextInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyCallerContextInterface::Hxx2
{
	template <typename S> class CWrapper : public CPyInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CPyInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MPyCallerContextInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MPyCallerContextInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyCallerContextInterface::Hxx1::ConstFn<S>::CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyCallerContextRef
{
	return (MPyCallerContextInterface::CreateCallerContextRef(lib, refType, pyObject));
}
auto MPyCallerContextInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyCallerContextInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cpython_ref)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyCallerContextInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyCallerContextInterface() { new (s_ui_maxon_py_MPyCallerContextInterface) maxon::EntityUse(MPyCallerContextInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyCallerContextInterface(MPyCallerContextInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

