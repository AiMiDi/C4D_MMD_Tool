#if 1
namespace maxon
{
	const maxon::Char* const FunctionBaseInterface::MTable::_ids = 
		"Init@f01085e345b890f8\0" // Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function)
		"Init@31b6ee37dd52daa6\0" // Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue)
		"Set@7587a52a2a864b84\0" // void Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer)
		"GetOwner@b00ec7f9b2e670da\0" // void GetOwner(ObserverObjectRef& res) const
		"GetObserver@b00ec7f9b2e670da\0" // void GetObserver(ObserverObjectRef& res) const
		"GetObserverPointer@c912d069b43da345\0" // const void* GetObserverPointer() const
		"Execute@c33f17c5a82f0057\0" // Result<Data> Execute(const Block<const ConstDataPtr>& args)
	"";
	const maxon::METHOD_FLAGS FunctionBaseInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionBaseInterface, , "net.maxon.interface.functionbase", "maxon.FunctionBaseInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const CombinerInterface::MTable::_ids = 
		"InitCombine@f2c6a61a6d74d66a\0" // Result<void> InitCombine(Result<Data>& combinedRes) const
		"CombineResult@5011e3a86078521d\0" // Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const
	"";
	const maxon::METHOD_FLAGS CombinerInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CombinerInterface, , "net.maxon.interface.combiner", "maxon.CombinerInterface", (ObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllComponent, , "net.maxon.component.observablecombinerrunall");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolOrComponent, , "net.maxon.component.observablecombinerrunallboolor");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolUntilFalse, , "net.maxon.component.observablecombinerrunallbooluntilfalse");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolUntilTrue, , "net.maxon.component.observablecombinerrunallbooluntiltrue");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllEnumFlagsOrComponent, , "net.maxon.component.observablecombinerrunallenumflagsor");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllEnumFlags64OrComponent, , "net.maxon.component.observablecombinerrunallenumflags64or");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllAggregateErrorsComponent, , "net.maxon.component.observablecombinerrunallaggregateerrors");
	const maxon::Char* const ObservableBaseInterface::MTable::_ids = 
		"Init@f8d3e016c8adbb41\0" // Result<void> Init(ObserverObjectInterface* owner, const Id& observableName)
		"GetObservableId@33636d531bf4ad19\0" // Id GetObservableId() const
		"_intDisconnectAll@5f3d9457126c0f5f\0" // void _intDisconnectAll(ObserverObjectInterface* observer, Int pass)
		"AddObserver@76ea7a7e890e0e89\0" // Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority)
		"Notify@21fa9b282efdab97\0" // Result<Data> Notify(const Block<const ConstDataPtr>& args) const
		"RemoveObserver@6f22cc823b12ad20\0" // Result<void> RemoveObserver(const FunctionBaseRef& observerEntry)
		"SetInverseNotification@add9409250097f0c\0" // void SetInverseNotification(Bool inverse)
		"GetObserverCount@6286b762fbbe6ae7\0" // Int GetObserverCount()
		"GetOwner@6499818c844b4bf2\0" // ObserverObjectInterface* GetOwner() const
	"";
	const maxon::METHOD_FLAGS ObservableBaseInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ObservableBaseInterface, , "net.maxon.interface.observablebase", "maxon.ObservableBaseInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ObservableBaseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FunctionBaseClass, , "net.maxon.class.functionbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableClass, , "net.maxon.class.observable");
	const maxon::Char* const ObservableStaticInterface::MTable::_ids = 
		"GetOrAllocClass@f954e853e6154194\0" // const ClassInterface* GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ObservableStaticInterface::Hxx2::Unresolved : public ObservableStaticInterface
	{
	public:
		static const Unresolved* Get(const ObservableStaticInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ObservableStaticInterface* o) { return (Unresolved*) o; }
		static const ClassInterface* GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ObservableStaticInterface::GetOrAllocClass(id, id1, id2); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ObservableStaticInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<const ClassInterface*>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ObservableStaticInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ObservableStaticInterface_GetOrAllocClass = PRIVATE_MAXON_MF_CAST(decltype(ObservableStaticInterface_GetOrAllocClass), &Hxx2::Wrapper<Hxx2::Unresolved>::ObservableStaticInterface_GetOrAllocClass);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ObservableStaticInterface, "net.maxon.interface.observablestatic", nullptr);
#ifndef DOXYGEN
#else
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_observable(0
	| maxon::ObservableBaseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
