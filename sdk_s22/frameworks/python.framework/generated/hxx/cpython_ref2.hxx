
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
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_CPyInterface_Init) (maxon::GenericComponent* this_, const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	maxon::Int _CPyInterface_Init_Offset;
	void (*_CPyInterface_Incref) (maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_Incref_Offset;
	void (*_CPyInterface_Decref) (maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_Decref_Offset;
	Int64 (*_CPyInterface_GetRefCount) (maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_GetRefCount_Offset;
	const CPythonLibraryInterface* (*_CPyInterface_GetLibrary) (const maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_GetLibrary_Offset;
	CPyTypeRef (*_CPyInterface_GetTypeRef) (const maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_GetTypeRef_Offset;
	NativePyObject* (*_CPyInterface_GetPyObject) (const maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_GetPyObject_Offset;
	NativePyObject* (*_CPyInterface_Disconnect) (maxon::GenericComponent* this_);
	maxon::Int _CPyInterface_Disconnect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Init), W, MTable>::type::_CPyInterface_Init;
			_CPyInterface_Init = reinterpret_cast<const decltype(_CPyInterface_Init)&>(ptr);
			_CPyInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Incref))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Incref), W, MTable>::type::_CPyInterface_Incref;
			_CPyInterface_Incref = reinterpret_cast<const decltype(_CPyInterface_Incref)&>(ptr);
			_CPyInterface_Incref_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Decref))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Decref), W, MTable>::type::_CPyInterface_Decref;
			_CPyInterface_Decref = reinterpret_cast<const decltype(_CPyInterface_Decref)&>(ptr);
			_CPyInterface_Decref_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetRefCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetRefCount), W, MTable>::type::_CPyInterface_GetRefCount;
			_CPyInterface_GetRefCount = reinterpret_cast<const decltype(_CPyInterface_GetRefCount)&>(ptr);
			_CPyInterface_GetRefCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetLibrary))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetLibrary), W, MTable>::type::_CPyInterface_GetLibrary;
			_CPyInterface_GetLibrary = reinterpret_cast<const decltype(_CPyInterface_GetLibrary)&>(ptr);
			_CPyInterface_GetLibrary_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetTypeRef))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetTypeRef), W, MTable>::type::_CPyInterface_GetTypeRef;
			_CPyInterface_GetTypeRef = reinterpret_cast<const decltype(_CPyInterface_GetTypeRef)&>(ptr);
			_CPyInterface_GetTypeRef_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetPyObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, GetPyObject), W, MTable>::type::_CPyInterface_GetPyObject;
			_CPyInterface_GetPyObject = reinterpret_cast<const decltype(_CPyInterface_GetPyObject)&>(ptr);
			_CPyInterface_GetPyObject_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Disconnect))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyInterface, Disconnect), W, MTable>::type::_CPyInterface_Disconnect;
			_CPyInterface_Disconnect = reinterpret_cast<const decltype(_CPyInterface_Disconnect)&>(ptr);
			_CPyInterface_Disconnect_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CPyInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
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
	static void _CPyInterface_Init(maxon::GenericComponent* this_, const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) { return ((typename S::Implementation*) this_)->Init(lib, refType, pyObject); }
	static void _CPyInterface_Incref(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Incref(); }
	static void _CPyInterface_Decref(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Decref(); }
	static Int64 _CPyInterface_GetRefCount(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetRefCount(); }
	static const CPythonLibraryInterface* _CPyInterface_GetLibrary(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLibrary(); }
	static CPyTypeRef _CPyInterface_GetTypeRef(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTypeRef(); }
	static NativePyObject* _CPyInterface_GetPyObject(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPyObject(); }
	static NativePyObject* _CPyInterface_Disconnect(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Disconnect(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_Init((maxon::GenericComponent*) this + mt_._CPyInterface_Init_Offset, lib, refType, pyObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Incref() -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_Incref((maxon::GenericComponent*) this + mt_._CPyInterface_Incref_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Decref() -> void
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_Decref((maxon::GenericComponent*) this + mt_._CPyInterface_Decref_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetRefCount() -> Int64
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_GetRefCount((maxon::GenericComponent*) this + mt_._CPyInterface_GetRefCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetLibrary() const -> const CPythonLibraryInterface*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_GetLibrary((const maxon::GenericComponent*) this + mt_._CPyInterface_GetLibrary_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetTypeRef() const -> CPyTypeRef
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_GetTypeRef((const maxon::GenericComponent*) this + mt_._CPyInterface_GetTypeRef_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::GetPyObject() const -> NativePyObject*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_GetPyObject((const maxon::GenericComponent*) this + mt_._CPyInterface_GetPyObject_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Disconnect() -> NativePyObject*
{
	const CPyInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyInterface, this); return mt_._CPyInterface_Disconnect((maxon::GenericComponent*) this + mt_._CPyInterface_Disconnect_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateRef27(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyRef { return (CPyInterface::CreateRef27(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateRef36(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyRef { return (CPyInterface::CreateRef36(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyRef { return (CPyInterface::CreateRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyConstRef { return (CPyInterface::CreateConstRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject) -> CPyTempRef { return (CPyInterface::CreateTempRef(lib, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Init_Offset, lib, refType, pyObject);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Init_Offset, lib, refType, pyObject);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::Incref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Incref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Incref(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Incref_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::Incref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Incref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Incref(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Incref_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::Decref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Decref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Decref(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Decref_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::Decref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Decref) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	mt_._CPyInterface_Decref(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Decref_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::GetRefCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetRefCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_GetRefCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_GetRefCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetRefCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetRefCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_GetRefCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_GetRefCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLibrary() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetLibrary) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_GetLibrary(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyInterface_GetLibrary_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTypeRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyTypeRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetTypeRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_GetTypeRef(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyInterface_GetTypeRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPyObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_GetPyObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_GetPyObject(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyInterface_GetPyObject_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::Disconnect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Disconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_Disconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Disconnect_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::Disconnect() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyInterface, o_, CPyInterface_Disconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyInterface>() : PRIVATE_MAXON_VTABLE(CPyInterface, o_); 
	return (mt_._CPyInterface_Disconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPyInterface_Disconnect_Offset));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CPyInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyInterface* o_ = (const CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->Get<T>());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::ReferenceFunctionsImpl<S>::GetAndIncref() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (o_->GetAndIncref<T>());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetAndIncref() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CPyInterface::GetAndIncref on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CPyInterface* o_ = (CPyInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetAndIncref<T>());
}
auto CPyInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyTypeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CPyTypeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyTypeInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTypeRef { return (CPyTypeInterface::CreateTypeRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTypeConstRef { return (CPyTypeInterface::CreateTypeConstRef(lib, refType, pyObject)); }
auto CPyTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	CPyFrameRef (*_CPyFrameInterface_GetBack) (const maxon::GenericComponent* this_);
	maxon::Int _CPyFrameInterface_GetBack_Offset;
	CPyCodeRef (*_CPyFrameInterface_GetCode) (const maxon::GenericComponent* this_);
	maxon::Int _CPyFrameInterface_GetCode_Offset;
	Int32 (*_CPyFrameInterface_GetLastInstruction) (const maxon::GenericComponent* this_);
	maxon::Int _CPyFrameInterface_GetLastInstruction_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetBack))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetBack), W, MTable>::type::_CPyFrameInterface_GetBack;
			_CPyFrameInterface_GetBack = reinterpret_cast<const decltype(_CPyFrameInterface_GetBack)&>(ptr);
			_CPyFrameInterface_GetBack_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetCode))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetCode), W, MTable>::type::_CPyFrameInterface_GetCode;
			_CPyFrameInterface_GetCode = reinterpret_cast<const decltype(_CPyFrameInterface_GetCode)&>(ptr);
			_CPyFrameInterface_GetCode_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetLastInstruction))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyFrameInterface, GetLastInstruction), W, MTable>::type::_CPyFrameInterface_GetLastInstruction;
			_CPyFrameInterface_GetLastInstruction = reinterpret_cast<const decltype(_CPyFrameInterface_GetLastInstruction)&>(ptr);
			_CPyFrameInterface_GetLastInstruction_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyFrameInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CPyFrameInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyFrameInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBack);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLastInstruction);
	static CPyFrameRef _CPyFrameInterface_GetBack(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBack(); }
	static CPyCodeRef _CPyFrameInterface_GetCode(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCode(); }
	static Int32 _CPyFrameInterface_GetLastInstruction(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLastInstruction(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetBack() const -> CPyFrameRef
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return mt_._CPyFrameInterface_GetBack((const maxon::GenericComponent*) this + mt_._CPyFrameInterface_GetBack_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetCode() const -> CPyCodeRef
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return mt_._CPyFrameInterface_GetCode((const maxon::GenericComponent*) this + mt_._CPyFrameInterface_GetCode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::GetLastInstruction() const -> Int32
{
	const CPyFrameInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyFrameInterface, this); return mt_._CPyFrameInterface_GetLastInstruction((const maxon::GenericComponent*) this + mt_._CPyFrameInterface_GetLastInstruction_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyFrameRef { return (CPyFrameInterface::CreateFrameRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBack() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetBack) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (mt_._CPyFrameInterface_GetBack(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyFrameInterface_GetBack_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (mt_._CPyFrameInterface_GetCode(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyFrameInterface_GetCode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyFrameInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLastInstruction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyFrameInterface* o_ = (const CPyFrameInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyFrameInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyFrameInterface, o_, CPyFrameInterface_GetLastInstruction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyFrameInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyFrameInterface>() : PRIVATE_MAXON_VTABLE(CPyFrameInterface, o_); 
	return (mt_._CPyFrameInterface_GetLastInstruction(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyFrameInterface_GetLastInstruction_Offset));
}
auto CPyFrameInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyFrameInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	CPyTracebackRef (*_CPyTracebackInterface_GetNext) (const maxon::GenericComponent* this_);
	maxon::Int _CPyTracebackInterface_GetNext_Offset;
	Int32 (*_CPyTracebackInterface_GetLineNumber) (const maxon::GenericComponent* this_);
	maxon::Int _CPyTracebackInterface_GetLineNumber_Offset;
	CPyFrameRef (*_CPyTracebackInterface_GetFrameRef) (const maxon::GenericComponent* this_);
	maxon::Int _CPyTracebackInterface_GetFrameRef_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetNext))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetNext), W, MTable>::type::_CPyTracebackInterface_GetNext;
			_CPyTracebackInterface_GetNext = reinterpret_cast<const decltype(_CPyTracebackInterface_GetNext)&>(ptr);
			_CPyTracebackInterface_GetNext_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetLineNumber))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetLineNumber), W, MTable>::type::_CPyTracebackInterface_GetLineNumber;
			_CPyTracebackInterface_GetLineNumber = reinterpret_cast<const decltype(_CPyTracebackInterface_GetLineNumber)&>(ptr);
			_CPyTracebackInterface_GetLineNumber_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetFrameRef))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyTracebackInterface, GetFrameRef), W, MTable>::type::_CPyTracebackInterface_GetFrameRef;
			_CPyTracebackInterface_GetFrameRef = reinterpret_cast<const decltype(_CPyTracebackInterface_GetFrameRef)&>(ptr);
			_CPyTracebackInterface_GetFrameRef_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyTracebackInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CPyTracebackInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyTracebackInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFrameRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLineNumber);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
	static CPyTracebackRef _CPyTracebackInterface_GetNext(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetNext(); }
	static Int32 _CPyTracebackInterface_GetLineNumber(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLineNumber(); }
	static CPyFrameRef _CPyTracebackInterface_GetFrameRef(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFrameRef(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetNext() const -> CPyTracebackRef
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return mt_._CPyTracebackInterface_GetNext((const maxon::GenericComponent*) this + mt_._CPyTracebackInterface_GetNext_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetLineNumber() const -> Int32
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return mt_._CPyTracebackInterface_GetLineNumber((const maxon::GenericComponent*) this + mt_._CPyTracebackInterface_GetLineNumber_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::GetFrameRef() const -> CPyFrameRef
{
	const CPyTracebackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyTracebackInterface, this); return mt_._CPyTracebackInterface_GetFrameRef((const maxon::GenericComponent*) this + mt_._CPyTracebackInterface_GetFrameRef_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateTracebackRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyTracebackRef { return (CPyTracebackInterface::CreateTracebackRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetNext() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTracebackRef>, CPyTracebackRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTracebackRef>, CPyTracebackRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyTracebackRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (mt_._CPyTracebackInterface_GetNext(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyTracebackInterface_GetNext_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLineNumber() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetLineNumber) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (mt_._CPyTracebackInterface_GetLineNumber(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyTracebackInterface_GetLineNumber_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyTracebackInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFrameRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyTracebackInterface* o_ = (const CPyTracebackInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyTracebackInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyTracebackInterface, o_, CPyTracebackInterface_GetFrameRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyTracebackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyTracebackInterface>() : PRIVATE_MAXON_VTABLE(CPyTracebackInterface, o_); 
	return (mt_._CPyTracebackInterface_GetFrameRef(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyTracebackInterface_GetFrameRef_Offset));
}
auto CPyTracebackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyTracebackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	CPyRef (*_CPyCodeInterface_GetFilename) (const maxon::GenericComponent* this_);
	maxon::Int _CPyCodeInterface_GetFilename_Offset;
	CPyRef (*_CPyCodeInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int _CPyCodeInterface_GetName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetFilename))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetFilename), W, MTable>::type::_CPyCodeInterface_GetFilename;
			_CPyCodeInterface_GetFilename = reinterpret_cast<const decltype(_CPyCodeInterface_GetFilename)&>(ptr);
			_CPyCodeInterface_GetFilename_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CPyCodeInterface, GetName), W, MTable>::type::_CPyCodeInterface_GetName;
			_CPyCodeInterface_GetName = reinterpret_cast<const decltype(_CPyCodeInterface_GetName)&>(ptr);
			_CPyCodeInterface_GetName_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CPyCodeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CPyCodeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CPyCodeInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFilename);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
	static CPyRef _CPyCodeInterface_GetFilename(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFilename(); }
	static CPyRef _CPyCodeInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::GetFilename() const -> CPyRef
{
	const CPyCodeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyCodeInterface, this); return mt_._CPyCodeInterface_GetFilename((const maxon::GenericComponent*) this + mt_._CPyCodeInterface_GetFilename_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::GetName() const -> CPyRef
{
	const CPyCodeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CPyCodeInterface, this); return mt_._CPyCodeInterface_GetName((const maxon::GenericComponent*) this + mt_._CPyCodeInterface_GetName_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> CPyCodeRef { return (CPyCodeInterface::CreateCodeRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFilename() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyCodeInterface* o_ = (const CPyCodeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyCodeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyCodeInterface, o_, CPyCodeInterface_GetFilename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyCodeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyCodeInterface>() : PRIVATE_MAXON_VTABLE(CPyCodeInterface, o_); 
	return (mt_._CPyCodeInterface_GetFilename(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyCodeInterface_GetFilename_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CPyCodeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CPyCodeInterface* o_ = (const CPyCodeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CPyCodeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CPyCodeInterface, o_, CPyCodeInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CPyCodeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CPyCodeInterface>() : PRIVATE_MAXON_VTABLE(CPyCodeInterface, o_); 
	return (mt_._CPyCodeInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CPyCodeInterface_GetName_Offset));
}
auto CPyCodeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CPyCodeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyClassInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyClassInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyClassRef { return (MPyClassInterface::CreateClassRef(lib, refType, pyObject)); }
auto MPyClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyMemberInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyMemberInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyMemberInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyMemberInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyMemberRef { return (MPyMemberInterface::CreateMemberRef(lib, refType, pyObject)); }
auto MPyMemberInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyMemberInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	const reflection::Function* (*_MPyFunctionInterface_GetFunction) (maxon::GenericComponent* this_);
	maxon::Int _MPyFunctionInterface_GetFunction_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyFunctionInterface, GetFunction))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyFunctionInterface, GetFunction), W, MTable>::type::_MPyFunctionInterface_GetFunction;
			_MPyFunctionInterface_GetFunction = reinterpret_cast<const decltype(_MPyFunctionInterface_GetFunction)&>(ptr);
			_MPyFunctionInterface_GetFunction_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyFunctionInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyFunctionInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyFunctionInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFunction);
	static const reflection::Function* _MPyFunctionInterface_GetFunction(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetFunction(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::GetFunction() -> const reflection::Function*
{
	const MPyFunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyFunctionInterface, this); return mt_._MPyFunctionInterface_GetFunction((maxon::GenericComponent*) this + mt_._MPyFunctionInterface_GetFunction_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyFunctionRef { return (MPyFunctionInterface::CreateFunctionRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::ReferenceFunctionsImpl<S>::GetFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MPyFunctionInterface* o_ = (MPyFunctionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyFunctionInterface, o_, MPyFunctionInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyFunctionInterface>() : PRIVATE_MAXON_VTABLE(MPyFunctionInterface, o_); 
	return (mt_._MPyFunctionInterface_GetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MPyFunctionInterface_GetFunction_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyFunctionInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetFunction() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MPyFunctionInterface* o_ = (MPyFunctionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyFunctionInterface, o_, MPyFunctionInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyFunctionInterface>() : PRIVATE_MAXON_VTABLE(MPyFunctionInterface, o_); 
	return (mt_._MPyFunctionInterface_GetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MPyFunctionInterface_GetFunction_Offset));
}
auto MPyFunctionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyFunctionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_py_MPyFunctionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_py_MPyFunctionInterface() { new (s_ui_maxon_py_MPyFunctionInterface) maxon::EntityUse(MPyFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_py_MPyFunctionInterface(MPyFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cpython_ref.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MPyDataTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetType);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType& (*_MPyDataTypeInterface_GetType) (const maxon::GenericComponent* this_);
	maxon::Int _MPyDataTypeInterface_GetType_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataTypeInterface, GetType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataTypeInterface, GetType), W, MTable>::type::_MPyDataTypeInterface_GetType;
			_MPyDataTypeInterface_GetType = reinterpret_cast<const decltype(_MPyDataTypeInterface_GetType)&>(ptr);
			_MPyDataTypeInterface_GetType_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyDataTypeInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyDataTypeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyDataTypeInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetType);
	static const DataType& _MPyDataTypeInterface_GetType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetType(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::GetType() const -> const DataType&
{
	const MPyDataTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataTypeInterface, this); return mt_._MPyDataTypeInterface_GetType((const maxon::GenericComponent*) this + mt_._MPyDataTypeInterface_GetType_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyDataTypeRef { return (MPyDataTypeInterface::CreateDataTypeRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MPyDataTypeInterface* o_ = (const MPyDataTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MPyDataTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataTypeInterface, o_, MPyDataTypeInterface_GetType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataTypeInterface>() : PRIVATE_MAXON_VTABLE(MPyDataTypeInterface, o_); 
	return (mt_._MPyDataTypeInterface_GetType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MPyDataTypeInterface_GetType_Offset));
}
auto MPyDataTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyDataTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType& (*_MPyDataInterface_GetType) (const maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_GetType_Offset;
	const DataType& (*_MPyDataInterface_GetMappingType) (const maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_GetMappingType_Offset;
	Data* (*_MPyDataInterface_GetData) (maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_GetData_Offset;
	const Data* (*_MPyDataInterface_GetData_1) (const maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_GetData_1_Offset;
	const Generic* (*_MPyDataInterface_PrivateGetPtr) (const maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_PrivateGetPtr_Offset;
	Generic* (*_MPyDataInterface_PrivateGetPtr_1) (maxon::GenericComponent* this_);
	maxon::Int _MPyDataInterface_PrivateGetPtr_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetType), W, MTable>::type::_MPyDataInterface_GetType;
			_MPyDataInterface_GetType = reinterpret_cast<const decltype(_MPyDataInterface_GetType)&>(ptr);
			_MPyDataInterface_GetType_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetMappingType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetMappingType), W, MTable>::type::_MPyDataInterface_GetMappingType;
			_MPyDataInterface_GetMappingType = reinterpret_cast<const decltype(_MPyDataInterface_GetMappingType)&>(ptr);
			_MPyDataInterface_GetMappingType_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData), W, MTable>::type::_MPyDataInterface_GetData;
			_MPyDataInterface_GetData = reinterpret_cast<const decltype(_MPyDataInterface_GetData)&>(ptr);
			_MPyDataInterface_GetData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, GetData), W, MTable>::type::_MPyDataInterface_GetData_1;
			_MPyDataInterface_GetData_1 = reinterpret_cast<const decltype(_MPyDataInterface_GetData_1)&>(ptr);
			_MPyDataInterface_GetData_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr), W, MTable>::type::_MPyDataInterface_PrivateGetPtr;
			_MPyDataInterface_PrivateGetPtr = reinterpret_cast<const decltype(_MPyDataInterface_PrivateGetPtr)&>(ptr);
			_MPyDataInterface_PrivateGetPtr_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MPyDataInterface, PrivateGetPtr), W, MTable>::type::_MPyDataInterface_PrivateGetPtr_1;
			_MPyDataInterface_PrivateGetPtr_1 = reinterpret_cast<const decltype(_MPyDataInterface_PrivateGetPtr_1)&>(ptr);
			_MPyDataInterface_PrivateGetPtr_1_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyDataInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyDataInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyDataInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMappingType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetPtr);
	static const DataType& _MPyDataInterface_GetType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetType(); }
	static const DataType& _MPyDataInterface_GetMappingType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMappingType(); }
	static Data* _MPyDataInterface_GetData(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetData(); }
	static const Data* _MPyDataInterface_GetData_1(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetData(); }
	static const Generic* _MPyDataInterface_PrivateGetPtr(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetPtr(); }
	static Generic* _MPyDataInterface_PrivateGetPtr_1(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->PrivateGetPtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetType() const -> const DataType&
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_GetType((const maxon::GenericComponent*) this + mt_._MPyDataInterface_GetType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetMappingType() const -> const DataType&
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_GetMappingType((const maxon::GenericComponent*) this + mt_._MPyDataInterface_GetMappingType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetData() -> Data*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_GetData((maxon::GenericComponent*) this + mt_._MPyDataInterface_GetData_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::GetData() const -> const Data*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_GetData_1((const maxon::GenericComponent*) this + mt_._MPyDataInterface_GetData_1_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::PrivateGetPtr() const -> const Generic*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_PrivateGetPtr((const maxon::GenericComponent*) this + mt_._MPyDataInterface_PrivateGetPtr_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::PrivateGetPtr() -> Generic*
{
	const MPyDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MPyDataInterface, this); return mt_._MPyDataInterface_PrivateGetPtr_1((maxon::GenericComponent*) this + mt_._MPyDataInterface_PrivateGetPtr_1_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyDataRef { return (MPyDataInterface::CreateDataRef(lib, refType, pyObject)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_GetType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_GetType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMappingType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetMappingType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_GetMappingType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_GetMappingType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ReferenceFunctionsImpl<S>::GetData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Data*>, Data*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Data*>, Data*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MPyDataInterface* o_ = (MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_GetData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_GetData_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_GetData_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_GetData_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_GetData_1_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateGetPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MPyDataInterface* o_ = (const MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MPyDataInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_PrivateGetPtr) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_PrivateGetPtr(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_PrivateGetPtr_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyDataInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateGetPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MPyDataInterface* o_ = (MPyDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MPyDataInterface, o_, MPyDataInterface_PrivateGetPtr_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MPyDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MPyDataInterface>() : PRIVATE_MAXON_VTABLE(MPyDataInterface, o_); 
	return (mt_._MPyDataInterface_PrivateGetPtr_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MPyDataInterface_PrivateGetPtr_1_Offset));
}
auto MPyDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CPyInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MPyCallerContextInterface, typename CPyInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MPyCallerContextInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MPyCallerContextInterface::Hxx2
{
	template <typename S> class Wrapper : public CPyInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MPyCallerContextInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) -> MPyCallerContextRef { return (MPyCallerContextInterface::CreateCallerContextRef(lib, refType, pyObject)); }
auto MPyCallerContextInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MPyCallerContextInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

