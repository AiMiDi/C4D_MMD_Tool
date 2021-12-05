
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct WeakRefServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_WeakRefServices_HasWeakReferences) (const void* target);
	Bool (*_WeakRefServices_AddWeakReference) (WeakRefBase& weakRef, const void* target);
	void (*_WeakRefServices_RemoveWeakReference) (WeakRefBase& weakRef);
	void (*_WeakRefServices_MoveWeakReference) (WeakRefBase& dst, WeakRefBase& src);
	Bool (*_WeakRefServices_CopyWeakReference) (WeakRefBase& dst, const WeakRefBase& src);
	Bool (*_WeakRefServices_ClearAllWeakReferences) (const void* target);
	Bool (*_WeakRefServices_TransferAllWeakReferences) (const void* oldTarget, const void* newTarget);
	Bool (*_WeakRefServices_AddObserver) (const void* target, MemoryObserverCallback callback, void* callbackData);
	Bool (*_WeakRefServices_AddMetadata) (const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct);
	Bool (*_WeakRefServices_EraseMetadata) (const void* target, const Id* uniqueId);
	MemoryMetadataProxy (*_WeakRefServices_GetMetadata) (const void* target, const Id* uniqueId);
	Result<Bool> (*_WeakRefServices_BrowseAllWeakReferences) (const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver);
	template <typename IMPL> void Init()
	{
		_WeakRefServices_HasWeakReferences = &IMPL::_WeakRefServices_HasWeakReferences;
		_WeakRefServices_AddWeakReference = &IMPL::_WeakRefServices_AddWeakReference;
		_WeakRefServices_RemoveWeakReference = &IMPL::_WeakRefServices_RemoveWeakReference;
		_WeakRefServices_MoveWeakReference = &IMPL::_WeakRefServices_MoveWeakReference;
		_WeakRefServices_CopyWeakReference = &IMPL::_WeakRefServices_CopyWeakReference;
		_WeakRefServices_ClearAllWeakReferences = &IMPL::_WeakRefServices_ClearAllWeakReferences;
		_WeakRefServices_TransferAllWeakReferences = &IMPL::_WeakRefServices_TransferAllWeakReferences;
		_WeakRefServices_AddObserver = &IMPL::_WeakRefServices_AddObserver;
		_WeakRefServices_AddMetadata = &IMPL::_WeakRefServices_AddMetadata;
		_WeakRefServices_EraseMetadata = &IMPL::_WeakRefServices_EraseMetadata;
		_WeakRefServices_GetMetadata = &IMPL::_WeakRefServices_GetMetadata;
		_WeakRefServices_BrowseAllWeakReferences = &IMPL::_WeakRefServices_BrowseAllWeakReferences;
	}
};

struct WeakRefServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Bool _WeakRefServices_HasWeakReferences(const void* target) { return C::HasWeakReferences(target); }
	static Bool _WeakRefServices_AddWeakReference(WeakRefBase& weakRef, const void* target) { return C::AddWeakReference(weakRef, target); }
	static void _WeakRefServices_RemoveWeakReference(WeakRefBase& weakRef) { return C::RemoveWeakReference(weakRef); }
	static void _WeakRefServices_MoveWeakReference(WeakRefBase& dst, WeakRefBase& src) { return C::MoveWeakReference(dst, src); }
	static Bool _WeakRefServices_CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src) { return C::CopyWeakReference(dst, src); }
	static Bool _WeakRefServices_ClearAllWeakReferences(const void* target) { return C::ClearAllWeakReferences(target); }
	static Bool _WeakRefServices_TransferAllWeakReferences(const void* oldTarget, const void* newTarget) { return C::TransferAllWeakReferences(oldTarget, newTarget); }
	static Bool _WeakRefServices_AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData) { return C::AddObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData); }
	static Bool _WeakRefServices_AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) { return C::AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct)); }
	static Bool _WeakRefServices_EraseMetadata(const void* target, const Id* uniqueId) { return C::EraseMetadata(target, uniqueId); }
	static MemoryMetadataProxy _WeakRefServices_GetMetadata(const void* target, const Id* uniqueId) { return C::GetMetadata(target, uniqueId); }
	static Result<Bool> _WeakRefServices_BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver) { return C::BrowseAllWeakReferences(oldTarget, receiver); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::HasWeakReferences(const void* target) -> Bool
{
	return MTable::_instance._WeakRefServices_HasWeakReferences(target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddWeakReference(WeakRefBase& weakRef, const void* target) -> Bool
{
	return MTable::_instance._WeakRefServices_AddWeakReference(weakRef, target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::RemoveWeakReference(WeakRefBase& weakRef) -> void
{
	return MTable::_instance._WeakRefServices_RemoveWeakReference(weakRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::MoveWeakReference(WeakRefBase& dst, WeakRefBase& src) -> void
{
	return MTable::_instance._WeakRefServices_MoveWeakReference(dst, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src) -> Bool
{
	return MTable::_instance._WeakRefServices_CopyWeakReference(dst, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::ClearAllWeakReferences(const void* target) -> Bool
{
	return MTable::_instance._WeakRefServices_ClearAllWeakReferences(target);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::TransferAllWeakReferences(const void* oldTarget, const void* newTarget) -> Bool
{
	return MTable::_instance._WeakRefServices_TransferAllWeakReferences(oldTarget, newTarget);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData) -> Bool
{
	return MTable::_instance._WeakRefServices_AddObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) -> Bool
{
	return MTable::_instance._WeakRefServices_AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::EraseMetadata(const void* target, const Id* uniqueId) -> Bool
{
	return MTable::_instance._WeakRefServices_EraseMetadata(target, uniqueId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::GetMetadata(const void* target, const Id* uniqueId) -> MemoryMetadataProxy
{
	return MTable::_instance._WeakRefServices_GetMetadata(target, uniqueId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakRefServices::BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver) -> Result<Bool>
{
	return MTable::_instance._WeakRefServices_BrowseAllWeakReferences(oldTarget, receiver);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

