
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	void (*_LockServices_AllocRWLockSlot) (ARWLock* arw);
	void (*_LockServices_FreeRWLockSlot) (ARWLock* arw);
	void (*_LockServices_ARWReadLock) (ARWLock* arw);
	void (*_LockServices_ARWReadUnlock) (ARWLock* arw);
	void (*_LockServices_ARWWriteLock) (ARWLock* arw);
	void (*_LockServices_ARWWriteUnlock) (ARWLock* arw);
	Bool (*_LockServices_ARWAttemptWriteLock) (ARWLock* arw);
	template <typename IMPL> void Init()
	{
		_LockServices_Serialize = &IMPL::_LockServices_Serialize;
		_LockServices_SerializeAsync = &IMPL::_LockServices_SerializeAsync;
		_LockServices_AllocRWLockSlot = &IMPL::_LockServices_AllocRWLockSlot;
		_LockServices_FreeRWLockSlot = &IMPL::_LockServices_FreeRWLockSlot;
		_LockServices_ARWReadLock = &IMPL::_LockServices_ARWReadLock;
		_LockServices_ARWReadUnlock = &IMPL::_LockServices_ARWReadUnlock;
		_LockServices_ARWWriteLock = &IMPL::_LockServices_ARWWriteLock;
		_LockServices_ARWWriteUnlock = &IMPL::_LockServices_ARWWriteUnlock;
		_LockServices_ARWAttemptWriteLock = &IMPL::_LockServices_ARWAttemptWriteLock;
	}
};

struct LockServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _LockServices_Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) { return C::Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam); }
	static void _LockServices_SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) { return C::SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn); }
	static void _LockServices_AllocRWLockSlot(ARWLock* arw) { return C::AllocRWLockSlot(arw); }
	static void _LockServices_FreeRWLockSlot(ARWLock* arw) { return C::FreeRWLockSlot(arw); }
	static void _LockServices_ARWReadLock(ARWLock* arw) { return C::ARWReadLock(arw); }
	static void _LockServices_ARWReadUnlock(ARWLock* arw) { return C::ARWReadUnlock(arw); }
	static void _LockServices_ARWWriteLock(ARWLock* arw) { return C::ARWWriteLock(arw); }
	static void _LockServices_ARWWriteUnlock(ARWLock* arw) { return C::ARWWriteUnlock(arw); }
	static Bool _LockServices_ARWAttemptWriteLock(ARWLock* arw) { return C::ARWAttemptWriteLock(arw); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) -> void
{
	return MTable::_instance._LockServices_Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) -> void
{
	return MTable::_instance._LockServices_SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::AllocRWLockSlot(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_AllocRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::FreeRWLockSlot(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_FreeRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadLock(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_ARWReadLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadUnlock(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_ARWReadUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteLock(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_ARWWriteLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteUnlock(ARWLock* arw) -> void
{
	return MTable::_instance._LockServices_ARWWriteUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWAttemptWriteLock(ARWLock* arw) -> Bool
{
	return MTable::_instance._LockServices_ARWAttemptWriteLock(arw);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LockServices); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LockServices() { new (s_ui_maxon_LockServices) maxon::EntityUse(LockServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/lockservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LockServices(LockServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/lockservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @endcond

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

