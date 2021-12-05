#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionBaseInterface, "net.maxon.interface.functionbase", "maxon.FunctionBaseInterface", , &Object::_interface);
	const maxon::Char* const FunctionBaseInterface::MTable::_ids = 
		"Init@90e09bcffb38d21d\0" // Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function)
		"Init@7f1eb98c2fd3a913\0" // Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue)
		"Set@f8972f72044b21bd\0" // Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer)
		"GetOwner@9021ada5c783aa63\0" // GetOwner(ObserverObjectRef& res) const
		"GetObserver@9021ada5c783aa63\0" // GetObserver(ObserverObjectRef& res) const
		"GetObserverPointer@629b065b9a9bb850\0" // GetObserverPointer() const
		"Execute@9198464198f2b400\0" // Execute(const Block<const ConstDataPtr>& args)
	"";
	template <typename DUMMY> maxon::Int FunctionBaseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CombinerInterface, "net.maxon.interface.combiner", "maxon.CombinerInterface", , &Object::_interface);
	const maxon::Char* const CombinerInterface::MTable::_ids = 
		"InitCombine@28034eb61c8ae3a1\0" // InitCombine(Result<Data>& combinedRes) const
		"CombineResult@e830bf526b528dbc\0" // CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const
	"";
	template <typename DUMMY> maxon::Int CombinerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllComponent, , "net.maxon.component.observablecombinerrunall");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolOrComponent, , "net.maxon.component.observablecombinerrunallboolor");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolUntilFalse, , "net.maxon.component.observablecombinerrunallbooluntilfalse");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllBoolUntilTrue, , "net.maxon.component.observablecombinerrunallbooluntiltrue");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllEnumFlagsOrComponent, , "net.maxon.component.observablecombinerrunallenumflagsor");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllEnumFlags64OrComponent, , "net.maxon.component.observablecombinerrunallenumflags64or");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableCombinerRunAllAggregateErrorsComponent, , "net.maxon.component.observablecombinerrunallaggregateerrors");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ObservableBaseInterface, "net.maxon.interface.observablebase", "maxon.ObservableBaseInterface", , &Object::_interface);
	const maxon::Char* const ObservableBaseInterface::MTable::_ids = 
		"Init@a86d1fa719a8ae40\0" // Init(ObserverObjectInterface* owner, const Id& observableName)
		"GetObservableId@22aaf2\0" // GetObservableId() const
		"_intDisconnectAll@4118184dbe9ed778\0" // _intDisconnectAll(ObserverObjectInterface* observer, Int pass)
		"AddObserver@575b5600f0868ea7\0" // AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction)
		"Notify@a17081f18563cc3a\0" // Notify(const Block<const ConstDataPtr>& args) const
		"RemoveObserver@b33edf8e75214631\0" // RemoveObserver(const FunctionBaseRef& observerEntry)
		"SetInverseNotification@5e65c14d7099\0" // SetInverseNotification(Bool inverse)
		"GetObserverCount@22da34\0" // GetObserverCount()
		"GetOwner@b569d276831df0bd\0" // GetOwner() const
	"";
	template <typename DUMMY> maxon::Int ObservableBaseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FunctionBaseClass, , "net.maxon.class.functionbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObservableClass, , "net.maxon.class.observable");
	const maxon::Char* const ObservableStaticInterface::MTable::_ids = 
		"GetOrAllocClass@fd3dca4a076ac733\0" // GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2)
	"";
	class ObservableStaticInterface::Unresolved : public ObservableStaticInterface
	{
	public:
		static const Unresolved* Get(const ObservableStaticInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ObservableStaticInterface* o) { return (Unresolved*) o; }
		static const ClassInterface* GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ObservableStaticInterface::GetOrAllocClass(id, id1, id2); return nullptr;}
	};
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
		tbl->_ObservableStaticInterface_GetOrAllocClass = &Wrapper<Unresolved>::_ObservableStaticInterface_GetOrAllocClass;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ObservableStaticInterface, "net.maxon.interface.observablestatic", nullptr);
	template <typename DUMMY> maxon::Int ObservableStaticInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
#ifndef DOXYGEN
#else
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_observable(0
	| maxon::FunctionBaseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::CombinerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ObservableBaseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ObservableStaticInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
