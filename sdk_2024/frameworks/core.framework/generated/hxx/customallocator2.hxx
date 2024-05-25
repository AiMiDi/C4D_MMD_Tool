
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* CustomAllocatorInterface::PrivateGetCppName() { return "maxon::CustomAllocatorRef"; }

struct CustomAllocatorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(CustomAllocatorInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const CustomAllocatorInterface* object);
	PRIVATE_MAXON_SF_POINTER(CustomAllocatorInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (CustomAllocatorInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_Alloc_1, Alloc, false, CustomAllocatorInterface,, (void*), Int s, const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_AllocClear, AllocClear, false, CustomAllocatorInterface,, (void*), Int s, const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_Realloc, Realloc, false, CustomAllocatorInterface,, (void*), void* data, Int size, const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_PrivateAlloc, PrivateAlloc, false, CustomAllocatorInterface,, (void*), Int size, Bool clear, const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_PrivateFree, PrivateFree, false, CustomAllocatorInterface,, (void), void* data);
	PRIVATE_MAXON_MF_POINTER(CustomAllocatorInterface_PrivateGetDataSize, PrivateGetDataSize, false, CustomAllocatorInterface,, (Int), void* data);
	template <typename IMPL> void Init()
	{
		CustomAllocatorInterface_Free = CustomAllocatorInterface_Free_GetPtr<IMPL>(true);
		CustomAllocatorInterface_Alloc = CustomAllocatorInterface_Alloc_GetPtr<IMPL>(true);
		CustomAllocatorInterface_Alloc_1 = CustomAllocatorInterface_Alloc_1_GetPtr<IMPL>(0, true).first;
		CustomAllocatorInterface_AllocClear = CustomAllocatorInterface_AllocClear_GetPtr<IMPL>(0, true).first;
		CustomAllocatorInterface_Realloc = CustomAllocatorInterface_Realloc_GetPtr<IMPL>(0, true).first;
		CustomAllocatorInterface_PrivateAlloc = CustomAllocatorInterface_PrivateAlloc_GetPtr<IMPL>(0, true).first;
		CustomAllocatorInterface_PrivateFree = CustomAllocatorInterface_PrivateFree_GetPtr<IMPL>(0, true).first;
		CustomAllocatorInterface_PrivateGetDataSize = CustomAllocatorInterface_PrivateGetDataSize_GetPtr<IMPL>(0, true).first;
	}
};

struct CustomAllocatorInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void CustomAllocatorInterface_Free(const CustomAllocatorInterface* object) { return S::Free(object); }
		static CustomAllocatorInterface* CustomAllocatorInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_Alloc_1, CustomAllocatorInterface,, (void*), Int s, const maxon::SourceLocation& allocLocation) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->Alloc(s, allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_AllocClear, CustomAllocatorInterface,, (void*), Int s, const maxon::SourceLocation& allocLocation) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->AllocClear(s, allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_Realloc, CustomAllocatorInterface,, (void*), void* data, Int size, const maxon::SourceLocation& allocLocation) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->Realloc(data, size, allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_PrivateAlloc, CustomAllocatorInterface,, (void*), Int size, Bool clear, const maxon::SourceLocation& allocLocation) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->PrivateAlloc(size, clear, allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_PrivateFree, CustomAllocatorInterface,, (void), void* data) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->PrivateFree(data); }
		PRIVATE_MAXON_MF_WRAPPER(CustomAllocatorInterface_PrivateGetDataSize, CustomAllocatorInterface,, (Int), void* data) { return S::Get(PRIVATE_MAXON_MF_THIS(CustomAllocatorInterface))->PrivateGetDataSize(data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Free(const CustomAllocatorInterface* object) -> void
{
	return MTable::_instance.CustomAllocatorInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Alloc(const maxon::SourceLocation& allocLocation) -> CustomAllocatorInterface*
{
	return MTable::_instance.CustomAllocatorInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Alloc(Int s, const maxon::SourceLocation& allocLocation) -> void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_Alloc_1, s, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::AllocClear(Int s, const maxon::SourceLocation& allocLocation) -> void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_AllocClear, s, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) -> void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_Realloc, data, size, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation) -> void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_PrivateAlloc, size, clear, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateFree(void* data) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_PrivateFree, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::PrivateGetDataSize(void* data) -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CustomAllocatorInterface_PrivateGetDataSize, data);
}

auto CustomAllocatorInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<CustomAllocatorRef>
{
	CustomAllocatorInterface* res_ = CustomAllocatorInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CustomAllocatorRef(maxon::ForwardResultPtr<CustomAllocatorInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::Fn<S>::Alloc(Int s, const maxon::SourceLocation& allocLocation) const -> HXXADDRET2(void*)
{
	HXXRETURN0(HXXADDRET2(void*)); HXXRES; HXXNONCONST(, , false, nullptr) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CustomAllocatorInterface_Alloc_1, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::Fn<S>::AllocClear(Int s, const maxon::SourceLocation& allocLocation) const -> HXXADDRET2(void*)
{
	HXXRETURN0(HXXADDRET2(void*)); HXXRES; HXXNONCONST(, , false, nullptr) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CustomAllocatorInterface_AllocClear, s, allocLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomAllocatorInterface::Hxx1::Fn<S>::Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) const -> HXXADDRET2(void*)
{
	HXXRETURN0(HXXADDRET2(void*)); HXXRES; HXXNONCONST(, , false, nullptr) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CustomAllocatorInterface_Realloc, data, size, allocLocation));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_customallocator)
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

