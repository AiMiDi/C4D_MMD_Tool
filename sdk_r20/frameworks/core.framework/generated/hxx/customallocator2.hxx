
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct CustomAllocatorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_CustomAllocatorInterface_Free) (const CustomAllocatorInterface* object);
	CustomAllocatorInterface* (*_CustomAllocatorInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	void* (*_CustomAllocatorInterface_Alloc_1) (CustomAllocatorInterface* this_, Int s, const maxon::SourceLocation& allocLocation);
	void* (*_CustomAllocatorInterface_AllocClear) (CustomAllocatorInterface* this_, Int s, const maxon::SourceLocation& allocLocation);
	void* (*_CustomAllocatorInterface_Realloc) (CustomAllocatorInterface* this_, void* data, Int size, const maxon::SourceLocation& allocLocation);
	void* (*_CustomAllocatorInterface_PrivateAlloc) (CustomAllocatorInterface* this_, Int size, Bool clear, const maxon::SourceLocation& allocLocation);
	void (*_CustomAllocatorInterface_PrivateFree) (CustomAllocatorInterface* this_, void* data);
	Int (*_CustomAllocatorInterface_PrivateGetDataSize) (CustomAllocatorInterface* this_, void* data);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_CustomAllocatorInterface_Free = &IMPL::_CustomAllocatorInterface_Free;
		tbl->_CustomAllocatorInterface_Alloc = &IMPL::_CustomAllocatorInterface_Alloc;
		tbl->_CustomAllocatorInterface_Alloc_1 = &IMPL::_CustomAllocatorInterface_Alloc_1;
		tbl->_CustomAllocatorInterface_AllocClear = &IMPL::_CustomAllocatorInterface_AllocClear;
		tbl->_CustomAllocatorInterface_Realloc = &IMPL::_CustomAllocatorInterface_Realloc;
		tbl->_CustomAllocatorInterface_PrivateAlloc = &IMPL::_CustomAllocatorInterface_PrivateAlloc;
		tbl->_CustomAllocatorInterface_PrivateFree = &IMPL::_CustomAllocatorInterface_PrivateFree;
		tbl->_CustomAllocatorInterface_PrivateGetDataSize = &IMPL::_CustomAllocatorInterface_PrivateGetDataSize;
	}
};

template <typename C> class CustomAllocatorInterface::Wrapper
{
public:
	static void _CustomAllocatorInterface_Free(const CustomAllocatorInterface* object) { return C::Free(object); }
	static CustomAllocatorInterface* _CustomAllocatorInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static void* _CustomAllocatorInterface_Alloc_1(CustomAllocatorInterface* this_, Int s, const maxon::SourceLocation& allocLocation) { return ((C*) this_)->Alloc(s, allocLocation); }
	static void* _CustomAllocatorInterface_AllocClear(CustomAllocatorInterface* this_, Int s, const maxon::SourceLocation& allocLocation) { return ((C*) this_)->AllocClear(s, allocLocation); }
	static void* _CustomAllocatorInterface_Realloc(CustomAllocatorInterface* this_, void* data, Int size, const maxon::SourceLocation& allocLocation) { return ((C*) this_)->Realloc(data, size, allocLocation); }
	static void* _CustomAllocatorInterface_PrivateAlloc(CustomAllocatorInterface* this_, Int size, Bool clear, const maxon::SourceLocation& allocLocation) { return ((C*) this_)->PrivateAlloc(size, clear, allocLocation); }
	static void _CustomAllocatorInterface_PrivateFree(CustomAllocatorInterface* this_, void* data) { return ((C*) this_)->PrivateFree(data); }
	static Int _CustomAllocatorInterface_PrivateGetDataSize(CustomAllocatorInterface* this_, void* data) { return ((C*) this_)->PrivateGetDataSize(data); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Free(const CustomAllocatorInterface* object) -> void
{
	return MTable::_instance._CustomAllocatorInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Alloc(const maxon::SourceLocation& allocLocation) -> CustomAllocatorInterface*
{
	return MTable::_instance._CustomAllocatorInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Alloc(Int s, const maxon::SourceLocation& allocLocation) -> void*
{
	return MTable::_instance._CustomAllocatorInterface_Alloc_1(this, s, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::AllocClear(Int s, const maxon::SourceLocation& allocLocation) -> void*
{
	return MTable::_instance._CustomAllocatorInterface_AllocClear(this, s, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) -> void*
{
	return MTable::_instance._CustomAllocatorInterface_Realloc(this, data, size, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation) -> void*
{
	return MTable::_instance._CustomAllocatorInterface_PrivateAlloc(this, size, clear, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateFree(void* data) -> void
{
	return MTable::_instance._CustomAllocatorInterface_PrivateFree(this, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateGetDataSize(void* data) -> Int
{
	return MTable::_instance._CustomAllocatorInterface_PrivateGetDataSize(this, data);
}

auto CustomAllocatorInterface::Reference::Create() -> maxon::ResultMemT<CustomAllocatorRef>
{
	CustomAllocatorInterface* res_ = CustomAllocatorInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CustomAllocatorRef(maxon::ForwardResultPtr<CustomAllocatorInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::Alloc(Int s, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_Alloc_1(o_, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::AllocClear(Int s, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_AllocClear(o_, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_Realloc(o_, data, size, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_PrivateAlloc(o_, size, clear, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::PrivateFree(void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._CustomAllocatorInterface_PrivateFree(o_, data);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::ReferenceFunctionsImpl<S>::PrivateGetDataSize(void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return 0; 
	return (MTable::_instance._CustomAllocatorInterface_PrivateGetDataSize(o_, data));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_CustomAllocatorInterface(CustomAllocatorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/customallocator.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

