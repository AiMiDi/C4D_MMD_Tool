
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif

struct AccessedObjectsCallback::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_IsReadable, IsReadable, false, AccessedObjectsCallback,, (Bool), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2);
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_EnsureReadable, EnsureReadable, false, AccessedObjectsCallback,, (maxon::Result<void>), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2);
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_MayAccess, MayAccess, false, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2, ACCESSED_OBJECTS_MASK anonymous_param_3);
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_MayAccessAnything, MayAccessAnything, false, AccessedObjectsCallback,, (maxon::Result<Bool>));
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_GetDocument, GetDocument, false, AccessedObjectsCallback,, (const BaseDocument*));
	PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_GetBuildFlags, GetBuildFlags, false, AccessedObjectsCallback,, (BUILDFLAGS));
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const AccessedObjectsCallback*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		AccessedObjectsCallback_IsReadable = AccessedObjectsCallback_IsReadable_GetPtr<IMPL>(0, true).first;
		AccessedObjectsCallback_EnsureReadable = AccessedObjectsCallback_EnsureReadable_GetPtr<IMPL>(0, true).first;
		AccessedObjectsCallback_MayAccess = AccessedObjectsCallback_MayAccess_GetPtr<IMPL>(0, true).first;
		AccessedObjectsCallback_MayAccessAnything = AccessedObjectsCallback_MayAccessAnything_GetPtr<IMPL>(0, true).first;
		AccessedObjectsCallback_GetDocument = AccessedObjectsCallback_GetDocument_GetPtr<IMPL>(0, true).first;
		AccessedObjectsCallback_GetBuildFlags = AccessedObjectsCallback_GetBuildFlags_GetPtr<IMPL>(0, true).first;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct AccessedObjectsCallback::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_IsReadable, AccessedObjectsCallback,, (Bool), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->IsReadable(anonymous_param_1, anonymous_param_2); }
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_EnsureReadable, AccessedObjectsCallback,, (maxon::Result<void>), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->EnsureReadable(anonymous_param_1, anonymous_param_2); }
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_MayAccess, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2, ACCESSED_OBJECTS_MASK anonymous_param_3) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->MayAccess(anonymous_param_1, anonymous_param_2, anonymous_param_3); }
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_MayAccessAnything, AccessedObjectsCallback,, (maxon::Result<Bool>)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->MayAccessAnything(); }
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_GetDocument, AccessedObjectsCallback,, (const BaseDocument*)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->GetDocument(); }
		PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_GetBuildFlags, AccessedObjectsCallback,, (BUILDFLAGS)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->GetBuildFlags(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::IsReadable(const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2) -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_IsReadable, anonymous_param_1, anonymous_param_2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::EnsureReadable(const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2) -> maxon::Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_EnsureReadable, anonymous_param_1, anonymous_param_2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::MayAccess(const BaseList2D* anonymous_param_1, ACCESSED_OBJECTS_MASK anonymous_param_2, ACCESSED_OBJECTS_MASK anonymous_param_3) -> maxon::Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_MayAccess, anonymous_param_1, anonymous_param_2, anonymous_param_3);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::MayAccessAnything() -> maxon::Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_MayAccessAnything);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::GetDocument() -> const BaseDocument*
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_GetDocument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::GetBuildFlags() -> BUILDFLAGS
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_GetBuildFlags);
}

AccessedObjectsCallback::AccessedObjectsCallback(const MTable& vtable) : _vtableCls(&vtable._info) { }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

