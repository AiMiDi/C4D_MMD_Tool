
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

constexpr const maxon::Char* LockServices::PrivateGetCppName() { return nullptr; }

struct LockServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(LockServices_Serialize, Serialize, MAXON_EXPAND_VA_ARGS, (void), CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam);
	PRIVATE_MAXON_SF_POINTER(LockServices_SerializeAsync, SerializeAsync, MAXON_EXPAND_VA_ARGS, (void), CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn);
	PRIVATE_MAXON_SF_POINTER(LockServices_AllocRWLockSlot, AllocRWLockSlot, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_FreeRWLockSlot, FreeRWLockSlot, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_ARWReadLock, ARWReadLock, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_ARWReadUnlock, ARWReadUnlock, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_ARWWriteLock, ARWWriteLock, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_ARWWriteUnlock, ARWWriteUnlock, MAXON_EXPAND_VA_ARGS, (void), ARWLock* arw);
	PRIVATE_MAXON_SF_POINTER(LockServices_ARWAttemptWriteLock, ARWAttemptWriteLock, MAXON_EXPAND_VA_ARGS, (Bool), ARWLock* arw);
	template <typename IMPL> void Init()
	{
		LockServices_Serialize = LockServices_Serialize_GetPtr<IMPL>(true);
		LockServices_SerializeAsync = LockServices_SerializeAsync_GetPtr<IMPL>(true);
		LockServices_AllocRWLockSlot = LockServices_AllocRWLockSlot_GetPtr<IMPL>(true);
		LockServices_FreeRWLockSlot = LockServices_FreeRWLockSlot_GetPtr<IMPL>(true);
		LockServices_ARWReadLock = LockServices_ARWReadLock_GetPtr<IMPL>(true);
		LockServices_ARWReadUnlock = LockServices_ARWReadUnlock_GetPtr<IMPL>(true);
		LockServices_ARWWriteLock = LockServices_ARWWriteLock_GetPtr<IMPL>(true);
		LockServices_ARWWriteUnlock = LockServices_ARWWriteUnlock_GetPtr<IMPL>(true);
		LockServices_ARWAttemptWriteLock = LockServices_ARWAttemptWriteLock_GetPtr<IMPL>(true);
	}
};

struct LockServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void LockServices_Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) { return C::Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam); }
		static void LockServices_SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) { return C::SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn); }
		static void LockServices_AllocRWLockSlot(ARWLock* arw) { return C::AllocRWLockSlot(arw); }
		static void LockServices_FreeRWLockSlot(ARWLock* arw) { return C::FreeRWLockSlot(arw); }
		static void LockServices_ARWReadLock(ARWLock* arw) { return C::ARWReadLock(arw); }
		static void LockServices_ARWReadUnlock(ARWLock* arw) { return C::ARWReadUnlock(arw); }
		static void LockServices_ARWWriteLock(ARWLock* arw) { return C::ARWWriteLock(arw); }
		static void LockServices_ARWWriteUnlock(ARWLock* arw) { return C::ARWWriteUnlock(arw); }
		static Bool LockServices_ARWAttemptWriteLock(ARWLock* arw) { return C::ARWAttemptWriteLock(arw); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) -> void
{
	return MTable::_instance.LockServices_Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) -> void
{
	return MTable::_instance.LockServices_SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::AllocRWLockSlot(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_AllocRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::FreeRWLockSlot(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_FreeRWLockSlot(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadLock(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_ARWReadLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWReadUnlock(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_ARWReadUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteLock(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_ARWWriteLock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWWriteUnlock(ARWLock* arw) -> void
{
	return MTable::_instance.LockServices_ARWWriteUnlock(arw);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LockServices::ARWAttemptWriteLock(ARWLock* arw) -> Bool
{
	return MTable::_instance.LockServices_ARWAttemptWriteLock(arw);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_lockservices)
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

