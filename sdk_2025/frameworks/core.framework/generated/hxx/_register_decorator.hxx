#if 1
namespace maxon
{
	const maxon::Char* const DecoratorInterface::MTable::_ids = 
		"PrivateGetDecoratedObject@af35215710ef97fe\0" // ObjectRef PrivateGetDecoratedObject() const
	"";
	const maxon::METHOD_FLAGS DecoratorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DecoratorInterface, , "net.maxon.interface.decorator", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int DecoratorInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ObjectRef>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const EagerDecoratorInterface::MTable::_ids = 
		"PrivateSetDecoratedObject@61f66edbfd40892f\0" // void PrivateSetDecoratedObject(const ObjectRef& object)
		"PrivateSetDecoratedObject@aeb633506d50d1d8\0" // void PrivateSetDecoratedObject(ObjectRef&& object)
	"";
	const maxon::METHOD_FLAGS EagerDecoratorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(EagerDecoratorInterface, , "net.maxon.interface.eagerdecorator", (DecoratorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EagerDecoratorComponent, , "net.maxon.component.eagerdecorator");
	const maxon::Char* const WeakDecoratorInterface::MTable::_ids = 
		"PrivateSetDecoratedObject@61f66edbfd40892f\0" // void PrivateSetDecoratedObject(const ObjectRef& object)
	"";
	const maxon::METHOD_FLAGS WeakDecoratorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(WeakDecoratorInterface, , "net.maxon.interface.weakdecorator", (DecoratorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(WeakDecoratorComponent, , "net.maxon.component.weakdecorator");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_decorator(0
	| maxon::DecoratorInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
