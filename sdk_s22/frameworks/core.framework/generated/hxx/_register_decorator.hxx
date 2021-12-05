#if 1
namespace maxon
{
	const maxon::Char* const DecoratorInterface::MTable::_ids = 
		"PrivateGetDecoratedObject@ef93c5168b282b\0" // ObjectRef PrivateGetDecoratedObject() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DecoratorInterface, , "net.maxon.interface.decorator", "maxon.DecoratorInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int DecoratorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ObjectRef>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const EagerDecoratorInterface::MTable::_ids = 
		"PrivateSetDecoratedObject@fbe74d369bf62dde\0" // void PrivateSetDecoratedObject(const ObjectRef& object)
		"PrivateSetDecoratedObject@80b6070de25a5805\0" // void PrivateSetDecoratedObject(ObjectRef&& object)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(EagerDecoratorInterface, , "net.maxon.interface.eagerdecorator", "maxon.EagerDecoratorInterface", (&DecoratorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EagerDecoratorComponent, , "net.maxon.component.eagerdecorator");
	const maxon::Char* const WeakDecoratorInterface::MTable::_ids = 
		"PrivateSetDecoratedObject@fbe74d369bf62dde\0" // void PrivateSetDecoratedObject(const ObjectRef& object)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(WeakDecoratorInterface, , "net.maxon.interface.weakdecorator", "maxon.WeakDecoratorInterface", (&DecoratorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(WeakDecoratorComponent, , "net.maxon.component.weakdecorator");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_decorator(0
	| maxon::DecoratorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
