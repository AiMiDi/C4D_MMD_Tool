
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* WeakRefServices::PrivateGetCppName() { return nullptr; }

struct WeakRefServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_HasWeakReferences, HasWeakReferences, MAXON_EXPAND_VA_ARGS, (Bool), const void* target);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_AddWeakReference, AddWeakReference, MAXON_EXPAND_VA_ARGS, (Bool), WeakRefBase& weakRef, const void* target);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_RemoveWeakReference, RemoveWeakReference, MAXON_EXPAND_VA_ARGS, (void), WeakRefBase& weakRef);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_MoveWeakReference, MoveWeakReference, MAXON_EXPAND_VA_ARGS, (void), WeakRefBase& dst, WeakRefBase& src);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_CopyWeakReference, CopyWeakReference, MAXON_EXPAND_VA_ARGS, (Bool), WeakRefBase& dst, const WeakRefBase& src);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_ClearAllWeakReferences, ClearAllWeakReferences, MAXON_EXPAND_VA_ARGS, (Bool), const void* target);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_TransferAllWeakReferences, TransferAllWeakReferences, MAXON_EXPAND_VA_ARGS, (Bool), const void* oldTarget, const void* newTarget);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_AddObserver, AddObserver, MAXON_EXPAND_VA_ARGS, (Bool), const void* target, MemoryObserverCallback callback, void* callbackData);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_EraseObserver, EraseObserver, MAXON_EXPAND_VA_ARGS, (Bool), const void* target, MemoryObserverCallback callback, void* callbackData);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_AddMetadata, AddMetadata, MAXON_EXPAND_VA_ARGS, (Bool), const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_EraseMetadata, EraseMetadata, MAXON_EXPAND_VA_ARGS, (Bool), const void* target, const Id* uniqueId);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_GetMetadata, GetMetadata, MAXON_EXPAND_VA_ARGS, (MemoryMetadataProxy), const void* target, const Id* uniqueId);
	PRIVATE_MAXON_SF_POINTER(WeakRefServices_BrowseAllWeakReferences, BrowseAllWeakReferences, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver);
	template <typename IMPL> void Init()
	{
		WeakRefServices_HasWeakReferences = WeakRefServices_HasWeakReferences_GetPtr<IMPL>(true);
		WeakRefServices_AddWeakReference = WeakRefServices_AddWeakReference_GetPtr<IMPL>(true);
		WeakRefServices_RemoveWeakReference = WeakRefServices_RemoveWeakReference_GetPtr<IMPL>(true);
		WeakRefServices_MoveWeakReference = WeakRefServices_MoveWeakReference_GetPtr<IMPL>(true);
		WeakRefServices_CopyWeakReference = WeakRefServices_CopyWeakReference_GetPtr<IMPL>(true);
		WeakRefServices_ClearAllWeakReferences = WeakRefServices_ClearAllWeakReferences_GetPtr<IMPL>(true);
		WeakRefServices_TransferAllWeakReferences = WeakRefServices_TransferAllWeakReferences_GetPtr<IMPL>(true);
		WeakRefServices_AddObserver = WeakRefServices_AddObserver_GetPtr<IMPL>(true);
		WeakRefServices_EraseObserver = WeakRefServices_EraseObserver_GetPtr<IMPL>(true);
		WeakRefServices_AddMetadata = WeakRefServices_AddMetadata_GetPtr<IMPL>(true);
		WeakRefServices_EraseMetadata = WeakRefServices_EraseMetadata_GetPtr<IMPL>(true);
		WeakRefServices_GetMetadata = WeakRefServices_GetMetadata_GetPtr<IMPL>(true);
		WeakRefServices_BrowseAllWeakReferences = WeakRefServices_BrowseAllWeakReferences_GetPtr<IMPL>(true);
	}
};

struct WeakRefServices::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Bool WeakRefServices_HasWeakReferences(const void* target) { return S::HasWeakReferences(target); }
		static Bool WeakRefServices_AddWeakReference(WeakRefBase& weakRef, const void* target) { return S::AddWeakReference(weakRef, target); }
		static void WeakRefServices_RemoveWeakReference(WeakRefBase& weakRef) { return S::RemoveWeakReference(weakRef); }
		static void WeakRefServices_MoveWeakReference(WeakRefBase& dst, WeakRefBase& src) { return S::MoveWeakReference(dst, src); }
		static Bool WeakRefServices_CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src) { return S::CopyWeakReference(dst, src); }
		static Bool WeakRefServices_ClearAllWeakReferences(const void* target) { return S::ClearAllWeakReferences(target); }
		static Bool WeakRefServices_TransferAllWeakReferences(const void* oldTarget, const void* newTarget) { return S::TransferAllWeakReferences(oldTarget, newTarget); }
		static Bool WeakRefServices_AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData) { return S::AddObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData); }
		static Bool WeakRefServices_EraseObserver(const void* target, MemoryObserverCallback callback, void* callbackData) { return S::EraseObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData); }
		static Bool WeakRefServices_AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) { return S::AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct)); }
		static Bool WeakRefServices_EraseMetadata(const void* target, const Id* uniqueId) { return S::EraseMetadata(target, uniqueId); }
		static MemoryMetadataProxy WeakRefServices_GetMetadata(const void* target, const Id* uniqueId) { return S::GetMetadata(target, uniqueId); }
		static Result<Bool> WeakRefServices_BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver) { return S::BrowseAllWeakReferences(oldTarget, receiver); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::HasWeakReferences(const void* target) -> Bool
{
	return MTable::_instance.WeakRefServices_HasWeakReferences(target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddWeakReference(WeakRefBase& weakRef, const void* target) -> Bool
{
	return MTable::_instance.WeakRefServices_AddWeakReference(weakRef, target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::RemoveWeakReference(WeakRefBase& weakRef) -> void
{
	return MTable::_instance.WeakRefServices_RemoveWeakReference(weakRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::MoveWeakReference(WeakRefBase& dst, WeakRefBase& src) -> void
{
	return MTable::_instance.WeakRefServices_MoveWeakReference(dst, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src) -> Bool
{
	return MTable::_instance.WeakRefServices_CopyWeakReference(dst, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::ClearAllWeakReferences(const void* target) -> Bool
{
	return MTable::_instance.WeakRefServices_ClearAllWeakReferences(target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::TransferAllWeakReferences(const void* oldTarget, const void* newTarget) -> Bool
{
	return MTable::_instance.WeakRefServices_TransferAllWeakReferences(oldTarget, newTarget);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData) -> Bool
{
	return MTable::_instance.WeakRefServices_AddObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::EraseObserver(const void* target, MemoryObserverCallback callback, void* callbackData) -> Bool
{
	return MTable::_instance.WeakRefServices_EraseObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) -> Bool
{
	return MTable::_instance.WeakRefServices_AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::EraseMetadata(const void* target, const Id* uniqueId) -> Bool
{
	return MTable::_instance.WeakRefServices_EraseMetadata(target, uniqueId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::GetMetadata(const void* target, const Id* uniqueId) -> MemoryMetadataProxy
{
	return MTable::_instance.WeakRefServices_GetMetadata(target, uniqueId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver) -> Result<Bool>
{
	return MTable::_instance.WeakRefServices_BrowseAllWeakReferences(oldTarget, receiver);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_weakrefservices)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_WeakRefServices); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_WeakRefServices() { new (s_ui_maxon_WeakRefServices) maxon::EntityUse(WeakRefServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/weakrefservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_WeakRefServices(WeakRefServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/weakrefservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef WEAKREF_H__
#ifdef MAXON_TARGET_64BIT
#else
#endif
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

