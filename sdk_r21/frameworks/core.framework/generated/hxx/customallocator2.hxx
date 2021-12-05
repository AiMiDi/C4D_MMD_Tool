
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	template <typename IMPL> void Init()
	{
		_CustomAllocatorInterface_Free = &IMPL::_CustomAllocatorInterface_Free;
		_CustomAllocatorInterface_Alloc = &IMPL::_CustomAllocatorInterface_Alloc;
		_CustomAllocatorInterface_Alloc_1 = &IMPL::_CustomAllocatorInterface_Alloc_1;
		_CustomAllocatorInterface_AllocClear = &IMPL::_CustomAllocatorInterface_AllocClear;
		_CustomAllocatorInterface_Realloc = &IMPL::_CustomAllocatorInterface_Realloc;
		_CustomAllocatorInterface_PrivateAlloc = &IMPL::_CustomAllocatorInterface_PrivateAlloc;
		_CustomAllocatorInterface_PrivateFree = &IMPL::_CustomAllocatorInterface_PrivateFree;
		_CustomAllocatorInterface_PrivateGetDataSize = &IMPL::_CustomAllocatorInterface_PrivateGetDataSize;
	}
};

struct CustomAllocatorInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
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

auto CustomAllocatorInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<CustomAllocatorRef>
{
	CustomAllocatorInterface* res_ = CustomAllocatorInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CustomAllocatorRef(maxon::ForwardResultPtr<CustomAllocatorInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::ReferenceFunctionsImpl<S>::Alloc(Int s, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_Alloc_1(o_, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::ReferenceFunctionsImpl<S>::AllocClear(Int s, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_AllocClear(o_, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::ReferenceFunctionsImpl<S>::Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomAllocatorInterface* o_ = (CustomAllocatorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return nullptr; 
	return (MTable::_instance._CustomAllocatorInterface_Realloc(o_, data, size, allocLocation));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CustomAllocatorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CustomAllocatorInterface() { new (s_ui_maxon_CustomAllocatorInterface) maxon::EntityUse(CustomAllocatorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/customallocator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CustomAllocatorInterface(CustomAllocatorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/customallocator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

