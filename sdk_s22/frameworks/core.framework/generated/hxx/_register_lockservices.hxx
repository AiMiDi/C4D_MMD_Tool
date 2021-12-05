#if 1
namespace maxon
{
/// @cond INTERNAL

	const maxon::Char* const LockServices::MTable::_ids = 
		"Serialize@30004aa157b4c1d8\0" // void Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam)
		"SerializeAsync@9e875d44d5d041d8\0" // void SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn)
		"AllocRWLockSlot@152db2aaac01a95b\0" // void AllocRWLockSlot(ARWLock* arw)
		"FreeRWLockSlot@152db2aaac01a95b\0" // void FreeRWLockSlot(ARWLock* arw)
		"ARWReadLock@152db2aaac01a95b\0" // void ARWReadLock(ARWLock* arw)
		"ARWReadUnlock@152db2aaac01a95b\0" // void ARWReadUnlock(ARWLock* arw)
		"ARWWriteLock@152db2aaac01a95b\0" // void ARWWriteLock(ARWLock* arw)
		"ARWWriteUnlock@152db2aaac01a95b\0" // void ARWWriteUnlock(ARWLock* arw)
		"ARWAttemptWriteLock@4295f821a0442b51\0" // Bool ARWAttemptWriteLock(ARWLock* arw)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LockServices::Hxx2::Unresolved : public LockServices
	{
	public:
		static const Unresolved* Get(const LockServices* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LockServices* o) { return (Unresolved*) o; }
		static void Serialize(CoreSerializerPOD& serializer, CoreSerializerCallback jobCallback, void* jobParam) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::Serialize(serializer, std::forward<CoreSerializerCallback>(jobCallback), jobParam); return maxon::PrivateLogNullptrError();}
		static void SerializeAsync(CoreSerializerPOD& serializer, CoreSerializerBuildWrapper wrapperCallback, void* fn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::SerializeAsync(serializer, std::forward<CoreSerializerBuildWrapper>(wrapperCallback), fn); return maxon::PrivateLogNullptrError();}
		static void AllocRWLockSlot(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::AllocRWLockSlot(arw); return maxon::PrivateLogNullptrError();}
		static void FreeRWLockSlot(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::FreeRWLockSlot(arw); return maxon::PrivateLogNullptrError();}
		static void ARWReadLock(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWReadLock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWReadUnlock(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWReadUnlock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWWriteLock(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWWriteLock(arw); return maxon::PrivateLogNullptrError();}
		static void ARWWriteUnlock(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWWriteUnlock(arw); return maxon::PrivateLogNullptrError();}
		static Bool ARWAttemptWriteLock(ARWLock* arw) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LockServices::ARWAttemptWriteLock(arw); return maxon::PrivateLogNullptrError(false);}
	};
	MAXON_WARNING_POP
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
		tbl->_LockServices_Serialize = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_Serialize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_SerializeAsync = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_SerializeAsync;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_AllocRWLockSlot = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_AllocRWLockSlot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_FreeRWLockSlot = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_FreeRWLockSlot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_ARWReadLock = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_ARWReadLock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_ARWReadUnlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_ARWReadUnlock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_ARWWriteLock = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_ARWWriteLock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_ARWWriteUnlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_ARWWriteUnlock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LockServices_ARWAttemptWriteLock = &Hxx2::Wrapper<Hxx2::Unresolved>::_LockServices_ARWAttemptWriteLock;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LockServices, "net.maxon.interface.lockservices", nullptr);
/// @endcond

}
#endif
