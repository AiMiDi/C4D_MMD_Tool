#if 1
namespace maxon
{
/// @cond INTERNAL

	const maxon::Char* const LockServices::MTable::_ids = 
		"Serialize@30004aa157b4c1d8\0" // Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam)
		"SerializeAsync@9e875d44d5d041d8\0" // SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn)
		"AllocRWLockSlot@1625bfafc6cdb9c\0" // AllocRWLockSlot(void* arw)
		"FreeRWLockSlot@1625bfafc6cdb9c\0" // FreeRWLockSlot(void* arw)
		"ARWReadLock@1625bfafc6cdb9c\0" // ARWReadLock(void* arw)
		"ARWReadUnlock@1625bfafc6cdb9c\0" // ARWReadUnlock(void* arw)
		"ARWWriteLock@1625bfafc6cdb9c\0" // ARWWriteLock(void* arw)
		"ARWWriteUnlock@1625bfafc6cdb9c\0" // ARWWriteUnlock(void* arw)
		"ARWAttemptWriteLock@caf58f769c8d66\0" // ARWAttemptWriteLock(void* arw)
	"";
	class LockServices::Unresolved : public LockServices
	{
	public:
		static const Unresolved* Get(const LockServices* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LockServices* o) { return (Unresolved*) o; }
		static void Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam); return maxon::PrivateLogNullptrError();}
		static void SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn); return maxon::PrivateLogNullptrError();}
		static void AllocRWLockSlot(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::AllocRWLockSlot(arw); return maxon::PrivateLogNullptrError();}
		static void FreeRWLockSlot(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::FreeRWLockSlot(arw); return maxon::PrivateLogNullptrError();}
		static void ARWReadLock(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWReadLock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWReadUnlock(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWReadUnlock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWWriteLock(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWWriteLock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWWriteUnlock(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWWriteUnlock(arw); return maxon::PrivateLogNullptrError();}
		static Bool ARWAttemptWriteLock(void* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWAttemptWriteLock(arw); return maxon::PrivateLogNullptrError(false);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LockServices::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LockServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_Serialize = &Wrapper<Unresolved>::_LockServices_Serialize;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_SerializeAsync = &Wrapper<Unresolved>::_LockServices_SerializeAsync;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_AllocRWLockSlot = &Wrapper<Unresolved>::_LockServices_AllocRWLockSlot;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_FreeRWLockSlot = &Wrapper<Unresolved>::_LockServices_FreeRWLockSlot;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_ARWReadLock = &Wrapper<Unresolved>::_LockServices_ARWReadLock;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_ARWReadUnlock = &Wrapper<Unresolved>::_LockServices_ARWReadUnlock;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_ARWWriteLock = &Wrapper<Unresolved>::_LockServices_ARWWriteLock;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_ARWWriteUnlock = &Wrapper<Unresolved>::_LockServices_ARWWriteUnlock;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LockServices_ARWAttemptWriteLock = &Wrapper<Unresolved>::_LockServices_ARWAttemptWriteLock;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LockServices, "net.maxon.interface.lockservices", nullptr);
	template <typename DUMMY> maxon::Int LockServices::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
/// @endcond

}
#endif
static maxon::details::ForceEvaluation s_forceEval_lockservices(0
	| maxon::LockServices::PrivateInstantiateNullValueHelper<maxon::Int>()
);
