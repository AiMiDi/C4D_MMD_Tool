#if 1
namespace maxon
{
	const maxon::Char* const ConditionVariableInterface::MTable::_ids = 
		"Free@3ac7e24773d39807\0" // Free(const ConditionVariableInterface* object)
		"Alloc@4168a38ec3f6a598\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@7923cb15ebfae958\0" // Alloc(const maxon::SourceLocation& allocLocation, Bool isAutoClear)
		"Clear@b6e5268c2debf\0" // Clear(Int32 dependencyCnt)
		"AddDependency@6b2e10f\0" // AddDependency()
		"Set@3d63259\0" // Set()
		"Wait@cbbabfefbf9cfd4e\0" // Wait(const TimeValue& timeout, WAITMODE mode) const
		"PrivateAddFinishedObserver@8aea24115d26901f\0" // PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
	"";
	class ConditionVariableInterface::Unresolved : public ConditionVariableInterface
	{
	public:
		static const Unresolved* Get(const ConditionVariableInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ConditionVariableInterface* o) { return (Unresolved*) o; }
		static void Free(const ConditionVariableInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ConditionVariableInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ConditionVariableInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ConditionVariableInterface::Alloc(allocLocation); return nullptr;}
		static ConditionVariableInterface* Alloc(const maxon::SourceLocation& allocLocation, Bool isAutoClear) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ConditionVariableInterface::Alloc(allocLocation, isAutoClear); return nullptr;}
		void Clear(Int32 dependencyCnt) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ConditionVariableInterface*) this)->Clear(dependencyCnt); return maxon::PrivateLogNullptrError();}
		void AddDependency() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ConditionVariableInterface*) this)->AddDependency(); return maxon::PrivateLogNullptrError();}
		Bool Set() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ConditionVariableInterface*) this)->Set(); return maxon::PrivateLogNullptrError(false);}
		Bool Wait(const TimeValue& timeout, WAITMODE mode) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ConditionVariableInterface*) this)->Wait(timeout, mode); return maxon::PrivateLogNullptrError(false);}
		Result<void> PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ConditionVariableInterface*) this)->PrivateAddFinishedObserver(observerPod, observerQueue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ConditionVariableInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<ConditionVariableInterface*>::value,
		maxon::details::NullReturnType<ConditionVariableInterface*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ConditionVariableInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Free = &Wrapper<Unresolved>::_ConditionVariableInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Alloc = &Wrapper<Unresolved>::_ConditionVariableInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Alloc_1 = &Wrapper<Unresolved>::_ConditionVariableInterface_Alloc_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Clear = &Wrapper<Unresolved>::_ConditionVariableInterface_Clear;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_AddDependency = &Wrapper<Unresolved>::_ConditionVariableInterface_AddDependency;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Set = &Wrapper<Unresolved>::_ConditionVariableInterface_Set;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ConditionVariableInterface_Wait = &Wrapper<Unresolved>::_ConditionVariableInterface_Wait;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ConditionVariableInterface_PrivateAddFinishedObserver = &Wrapper<Unresolved>::_ConditionVariableInterface_PrivateAddFinishedObserver;
	#else
		tbl->_ConditionVariableInterface_PrivateAddFinishedObserver = &Wrapper<Unresolved>::_ConditionVariableInterface_PrivateAddFinishedObserver;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ConditionVariableInterface, "net.maxon.interface.conditionvariable", nullptr);
	template <typename DUMMY> maxon::Int ConditionVariableInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ObservableFinishedBase<ConditionVariableInterface>>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_conditionvariable(0
	| maxon::ConditionVariableInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
