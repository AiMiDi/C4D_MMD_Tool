#if 1
namespace maxon
{
	const maxon::Char* const WeakRefServices::MTable::_ids = 
		"HasWeakReferences@b66a303b0f4a6203\0" // HasWeakReferences(const void* target)
		"AddWeakReference@7c31309f224ab303\0" // AddWeakReference(WeakRefBase& weakRef, const void* target)
		"RemoveWeakReference@83b8507ab5636c5a\0" // RemoveWeakReference(WeakRefBase& weakRef)
		"MoveWeakReference@7dffaf62edf2e986\0" // MoveWeakReference(WeakRefBase& dst, WeakRefBase& src)
		"CopyWeakReference@dd245808952ec313\0" // CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src)
		"ClearAllWeakReferences@b66a303b0f4a6203\0" // ClearAllWeakReferences(const void* target)
		"TransferAllWeakReferences@f3108c6d608d9d36\0" // TransferAllWeakReferences(const void* oldTarget, const void* newTarget)
		"AddObserver@1cad72fa82c5db6e\0" // AddObserver(const void* target, StrongRefObserverCallback callback, void* callbackData)
		"AddMetadata@0aa2deab213db67e\0" // AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct)
		"EraseMetadata@bb8647017208cd5d\0" // EraseMetadata(const void* target, const Id* uniqueId)
		"GetMetadata@0fab712779798509\0" // GetMetadata(const void* target, const Id* uniqueId)
	"";
	class WeakRefServices::Unresolved : public WeakRefServices
	{
	public:
		static const Unresolved* Get(const WeakRefServices* o) { return (const Unresolved*) o; }
		static Unresolved* Get(WeakRefServices* o) { return (Unresolved*) o; }
		static Bool HasWeakReferences(const void* target) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::HasWeakReferences(target); return maxon::PrivateLogNullptrError(false);}
		static Bool AddWeakReference(WeakRefBase& weakRef, const void* target) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::AddWeakReference(weakRef, target); return maxon::PrivateLogNullptrError(false);}
		static void RemoveWeakReference(WeakRefBase& weakRef) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::RemoveWeakReference(weakRef); return maxon::PrivateLogNullptrError();}
		static void MoveWeakReference(WeakRefBase& dst, WeakRefBase& src) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::MoveWeakReference(dst, src); return maxon::PrivateLogNullptrError();}
		static Bool CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::CopyWeakReference(dst, src); return maxon::PrivateLogNullptrError(false);}
		static Bool ClearAllWeakReferences(const void* target) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::ClearAllWeakReferences(target); return maxon::PrivateLogNullptrError(false);}
		static Bool TransferAllWeakReferences(const void* oldTarget, const void* newTarget) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::TransferAllWeakReferences(oldTarget, newTarget); return maxon::PrivateLogNullptrError(false);}
		static Bool AddObserver(const void* target, StrongRefObserverCallback callback, void* callbackData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::AddObserver(target, std::forward<StrongRefObserverCallback>(callback), callbackData); return maxon::PrivateLogNullptrError(false);}
		static Bool AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct)); return maxon::PrivateLogNullptrError(false);}
		static Bool EraseMetadata(const void* target, const Id* uniqueId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::EraseMetadata(target, uniqueId); return maxon::PrivateLogNullptrError(false);}
		static MemoryMetadataProxy GetMetadata(const void* target, const Id* uniqueId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::GetMetadata(target, uniqueId); return maxon::PrivateIncompleteNullReturnValue<MemoryMetadataProxy>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE WeakRefServices::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<MemoryMetadataProxy>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool WeakRefServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_HasWeakReferences = &Wrapper<Unresolved>::_WeakRefServices_HasWeakReferences;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_AddWeakReference = &Wrapper<Unresolved>::_WeakRefServices_AddWeakReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_RemoveWeakReference = &Wrapper<Unresolved>::_WeakRefServices_RemoveWeakReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_MoveWeakReference = &Wrapper<Unresolved>::_WeakRefServices_MoveWeakReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_CopyWeakReference = &Wrapper<Unresolved>::_WeakRefServices_CopyWeakReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_ClearAllWeakReferences = &Wrapper<Unresolved>::_WeakRefServices_ClearAllWeakReferences;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_TransferAllWeakReferences = &Wrapper<Unresolved>::_WeakRefServices_TransferAllWeakReferences;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_AddObserver = &Wrapper<Unresolved>::_WeakRefServices_AddObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_AddMetadata = &Wrapper<Unresolved>::_WeakRefServices_AddMetadata;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_WeakRefServices_EraseMetadata = &Wrapper<Unresolved>::_WeakRefServices_EraseMetadata;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<MemoryMetadataProxy>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_WeakRefServices_GetMetadata = &Wrapper<Unresolved>::_WeakRefServices_GetMetadata;
	#else
		tbl->_WeakRefServices_GetMetadata = &Wrapper<Unresolved>::_WeakRefServices_GetMetadata;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(WeakRefServices, "net.maxon.interface.weakrefservices", nullptr);
	template <typename DUMMY> maxon::Int WeakRefServices::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MemoryMetadataProxy>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_weakrefservices(0
	| maxon::WeakRefServices::PrivateInstantiateNullValueHelper<maxon::Int>()
);
