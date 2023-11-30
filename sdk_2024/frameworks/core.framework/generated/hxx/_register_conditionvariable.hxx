#if 1
namespace maxon
{
	const maxon::Char* const ConditionVariableInterface::MTable::_ids = 
		"Free@b563dcac29f4d26\0" // void Free(const ConditionVariableInterface* object)
		"Alloc@cf3400e841c29fcf\0" // ConditionVariableInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@a8b547c7da12cad3\0" // ConditionVariableInterface* Alloc(const maxon::SourceLocation& allocLocation, Bool isAutoClear)
		"Clear@26d30ab205d458\0" // void Clear(Int32 dependencyCnt)
		"AddDependency@780cdac8f1a33934\0" // void AddDependency()
		"Set@d7a8c99431e20a5a\0" // Bool Set()
		"Wait@3397eb0e4d5f8e27\0" // Bool Wait(const TimeValue& timeout, WAITMODE mode) const
		"PrivateAddFinishedObserver@ad7a64788ef673ee\0" // Result<void> PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ConditionVariableInterface::Hxx2::Unresolved : public ConditionVariableInterface
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
		Result<void> PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ConditionVariableInterface*) this)->PrivateAddFinishedObserver(observerPod, observerQueue); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ConditionVariableInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<ConditionVariableInterface*>::value,
		maxon::details::UnresolvedReturnType<ConditionVariableInterface*>::value,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ConditionVariableInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Clear = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Clear), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Clear);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_AddDependency = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_AddDependency), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_AddDependency);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Set = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Set), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Set);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConditionVariableInterface_Wait = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_Wait), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_Wait);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ConditionVariableInterface_PrivateAddFinishedObserver = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_PrivateAddFinishedObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_PrivateAddFinishedObserver);
		#else
		tbl->ConditionVariableInterface_PrivateAddFinishedObserver = PRIVATE_MAXON_MF_CAST(decltype(ConditionVariableInterface_PrivateAddFinishedObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::ConditionVariableInterface_PrivateAddFinishedObserver);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ConditionVariableInterface, "net.maxon.interface.conditionvariable", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int ConditionVariableInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ObservableFinishedBase<ConditionVariableInterface>>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_conditionvariable(0
	| maxon::ConditionVariableInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
