
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1
/// @cond INTERNAL


struct LockServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_LockServices_Serialize) (CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam);
	void (*_LockServices_SerializeAsync) (CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn);
	void (*_LockServices_AllocRWLockSlot) (void* arw);
	void (*_LockServices_FreeRWLockSlot) (void* arw);
	void (*_LockServices_ARWReadLock) (void* arw);
	void (*_LockServices_ARWReadUnlock) (void* arw);
	void (*_LockServices_ARWWriteLock) (void* arw);
	void (*_LockServices_ARWWriteUnlock) (void* arw);
	Bool (*_LockServices_ARWAttemptWriteLock) (void* arw);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_LockServices_Serialize = &IMPL::_LockServices_Serialize;
		tbl->_LockServices_SerializeAsync = &IMPL::_LockServices_SerializeAsync;
		tbl->_LockServices_AllocRWLockSlot = &IMPL::_LockServices_AllocRWLockSlot;
		tbl->_LockServices_FreeRWLockSlot = &IMPL::_LockServices_FreeRWLockSlot;
		tbl->_LockServices_ARWReadLock = &IMPL::_LockServices_ARWReadLock;
		tbl->_LockServices_ARWReadUnlock = &IMPL::_LockServices_ARWReadUnlock;
		tbl->_LockServices_ARWWriteLock = &IMPL::_LockServices_ARWWriteLock;
		tbl->_LockServices_ARWWriteUnlock = &IMPL::_LockServices_ARWWriteUnlock;
		tbl->_LockServices_ARWAttemptWriteLock = &IMPL::_LockServices_ARWAttemptWriteLock;
	}
};

template <typename C> class LockServices::Wrapper
{
public:
	static void _LockServices_Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) { return C::Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam); }
	static void _LockServices_SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) { return C::SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn); }
	static void _LockServices_AllocRWLockSlot(void* arw) { return C::AllocRWLockSlot(arw); }
	static void _LockServices_FreeRWLockSlot(void* arw) { return C::FreeRWLockSlot(arw); }
	static void _LockServices_ARWReadLock(void* arw) { return C::ARWReadLock(arw); }
	static void _LockServices_ARWReadUnlock(void* arw) { return C::ARWReadUnlock(arw); }
	static void _LockServices_ARWWriteLock(void* arw) { return C::ARWWriteLock(arw); }
	static void _LockServices_ARWWriteUnlock(void* arw) { return C::ARWWriteUnlock(arw); }
	static Bool _LockServices_ARWAttemptWriteLock(void* arw) { return C::ARWAttemptWriteLock(arw); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) -> void
{
	return MTable::_instance._LockServices_Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) -> void
{
	return MTable::_instance._LockServices_SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::AllocRWLockSlot(void* arw) -> void
{
	return MTable::_instance._LockServices_AllocRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::FreeRWLockSlot(void* arw) -> void
{
	return MTable::_instance._LockServices_FreeRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadLock(void* arw) -> void
{
	return MTable::_instance._LockServices_ARWReadLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadUnlock(void* arw) -> void
{
	return MTable::_instance._LockServices_ARWReadUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteLock(void* arw) -> void
{
	return MTable::_instance._LockServices_ARWWriteLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteUnlock(void* arw) -> void
{
	return MTable::_instance._LockServices_ARWWriteUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWAttemptWriteLock(void* arw) -> Bool
{
	return MTable::_instance._LockServices_ARWAttemptWriteLock(arw);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_LockServices(LockServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/lockservices.h", false);
#endif
/// @endcond

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

