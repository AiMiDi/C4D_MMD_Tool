#if 1
namespace maxon
{
	namespace enum20
	{
		enum class MEMORY_OBSERVER_FLAGS : Int
		{
			DEFAULT = 0,												///< Default behaviour: Continue with destruction, observer will be removed.
			CLAIM_SHARED_OWNERSHIP = 1,					///< The observer claims shared ownership of the target, do not destruct the object.
			CLAIM_EXCLUSIVE_OWNERSHIP = 2,			///< The first observer/creator claims exclusive ownership of the target, do not destruct the object.
			KEEP_OBSERVER = 4,									///< Do not delete the observer (usually only makes sense if ownership is claimed).
			INVOKE_WITH_UNLOCKED_TARGET = 8			///< Ask to invoke the observer again without the target being locked (if you need to destruct associated objects).
		} ;
		static const maxon::UInt64 MEMORY_OBSERVER_FLAGS_values[] = {maxon::UInt64(enum20::MEMORY_OBSERVER_FLAGS::DEFAULT), maxon::UInt64(enum20::MEMORY_OBSERVER_FLAGS::CLAIM_SHARED_OWNERSHIP), maxon::UInt64(enum20::MEMORY_OBSERVER_FLAGS::CLAIM_EXCLUSIVE_OWNERSHIP), maxon::UInt64(enum20::MEMORY_OBSERVER_FLAGS::KEEP_OBSERVER), maxon::UInt64(enum20::MEMORY_OBSERVER_FLAGS::INVOKE_WITH_UNLOCKED_TARGET)};
		static const maxon::EnumInfo MEMORY_OBSERVER_FLAGS_info{"MEMORY_OBSERVER_FLAGS", SIZEOF(MEMORY_OBSERVER_FLAGS), true, "DEFAULT\0CLAIM_SHARED_OWNERSHIP\0CLAIM_EXCLUSIVE_OWNERSHIP\0KEEP_OBSERVER\0INVOKE_WITH_UNLOCKED_TARGET\0", MEMORY_OBSERVER_FLAGS_values, std::extent<decltype(MEMORY_OBSERVER_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORY_OBSERVER_FLAGS20(){ return enum20::MEMORY_OBSERVER_FLAGS_info; }
	namespace enum28
	{
		enum class MEMORY_OBSERVER_STATE : Int
		{
			DEFAULT = 0,
			TARGET_IS_LOCKED = 1,								///< The target is locked and you must not directly or indireclty modify itself or any related objects.
			TARGET_HAS_EXCLUSIVE_OWNERSHIP = 2	///< The target is exclusively owned and you cannot claim shared ownership.
		} ;
		static const maxon::UInt64 MEMORY_OBSERVER_STATE_values[] = {maxon::UInt64(enum28::MEMORY_OBSERVER_STATE::DEFAULT), maxon::UInt64(enum28::MEMORY_OBSERVER_STATE::TARGET_IS_LOCKED), maxon::UInt64(enum28::MEMORY_OBSERVER_STATE::TARGET_HAS_EXCLUSIVE_OWNERSHIP)};
		static const maxon::EnumInfo MEMORY_OBSERVER_STATE_info{"MEMORY_OBSERVER_STATE", SIZEOF(MEMORY_OBSERVER_STATE), true, "DEFAULT\0TARGET_IS_LOCKED\0TARGET_HAS_EXCLUSIVE_OWNERSHIP\0", MEMORY_OBSERVER_STATE_values, std::extent<decltype(MEMORY_OBSERVER_STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORY_OBSERVER_STATE28(){ return enum28::MEMORY_OBSERVER_STATE_info; }
	const maxon::Char* const WeakRefServices::MTable::_ids = 
		"HasWeakReferences@e24130458056202\0" // Bool HasWeakReferences(const void* target)
		"AddWeakReference@9ef9e63044875acc\0" // Bool AddWeakReference(WeakRefBase& weakRef, const void* target)
		"RemoveWeakReference@f0540d7d9f694e77\0" // void RemoveWeakReference(WeakRefBase& weakRef)
		"MoveWeakReference@d0b031100d58b525\0" // void MoveWeakReference(WeakRefBase& dst, WeakRefBase& src)
		"CopyWeakReference@26a8edf4528e090c\0" // Bool CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src)
		"ClearAllWeakReferences@e24130458056202\0" // Bool ClearAllWeakReferences(const void* target)
		"TransferAllWeakReferences@f2d86d20afe6b503\0" // Bool TransferAllWeakReferences(const void* oldTarget, const void* newTarget)
		"AddObserver@9990c653add8493e\0" // Bool AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData)
		"EraseObserver@9990c653add8493e\0" // Bool EraseObserver(const void* target, MemoryObserverCallback callback, void* callbackData)
		"AddMetadata@3ce2a1af5b3a11e9\0" // Bool AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct)
		"EraseMetadata@29ff2145d0e20114\0" // Bool EraseMetadata(const void* target, const Id* uniqueId)
		"GetMetadata@dd1bcd97add913c\0" // MemoryMetadataProxy GetMetadata(const void* target, const Id* uniqueId)
		"BrowseAllWeakReferences@fa9781e6f1114fe2\0" // Result<Bool> BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class WeakRefServices::Hxx2::Unresolved : public WeakRefServices
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
		static Bool AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::AddObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData); return maxon::PrivateLogNullptrError(false);}
		static Bool EraseObserver(const void* target, MemoryObserverCallback callback, void* callbackData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::EraseObserver(target, std::forward<MemoryObserverCallback>(callback), callbackData); return maxon::PrivateLogNullptrError(false);}
		static Bool AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::AddMetadata(target, uniqueId, metadata, std::forward<MemoryMetadataDestructor>(destruct)); return maxon::PrivateLogNullptrError(false);}
		static Bool EraseMetadata(const void* target, const Id* uniqueId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::EraseMetadata(target, uniqueId); return maxon::PrivateLogNullptrError(false);}
		static MemoryMetadataProxy GetMetadata(const void* target, const Id* uniqueId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return WeakRefServices::GetMetadata(target, uniqueId); return maxon::PrivateIncompleteNullReturnValue<MemoryMetadataProxy>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<Bool> BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return WeakRefServices::BrowseAllWeakReferences(oldTarget, receiver); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
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
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<MemoryMetadataProxy>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool WeakRefServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_HasWeakReferences = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_HasWeakReferences), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_HasWeakReferences);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_AddWeakReference = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_AddWeakReference), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_AddWeakReference);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_RemoveWeakReference = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_RemoveWeakReference), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_RemoveWeakReference);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_MoveWeakReference = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_MoveWeakReference), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_MoveWeakReference);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_CopyWeakReference = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_CopyWeakReference), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_CopyWeakReference);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_ClearAllWeakReferences = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_ClearAllWeakReferences), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_ClearAllWeakReferences);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_TransferAllWeakReferences = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_TransferAllWeakReferences), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_TransferAllWeakReferences);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_AddObserver = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_AddObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_AddObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_EraseObserver = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_EraseObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_EraseObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_AddMetadata = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_AddMetadata), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_AddMetadata);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->WeakRefServices_EraseMetadata = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_EraseMetadata), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_EraseMetadata);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<MemoryMetadataProxy>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->WeakRefServices_GetMetadata = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_GetMetadata), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_GetMetadata);
		#else
		tbl->WeakRefServices_GetMetadata = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_GetMetadata), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_GetMetadata);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->WeakRefServices_BrowseAllWeakReferences = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_BrowseAllWeakReferences), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_BrowseAllWeakReferences);
		#else
		tbl->WeakRefServices_BrowseAllWeakReferences = PRIVATE_MAXON_MF_CAST(decltype(WeakRefServices_BrowseAllWeakReferences), &Hxx2::Wrapper<Hxx2::Unresolved>::WeakRefServices_BrowseAllWeakReferences);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
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
#ifdef WEAKREF_H__
#ifdef MAXON_TARGET_64BIT
#else
#endif
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_weakrefservices(0
	| maxon::WeakRefServices::PrivateInstantiateNullValueHelper<maxon::Int>()
);
