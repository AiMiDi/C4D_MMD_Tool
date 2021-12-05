#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DecoratorInterface, "net.maxon.interface.decorator", "maxon.DecoratorInterface", , &Object::_interface);
	const maxon::Char* const DecoratorInterface::MTable::_ids = 
		"PrivateGetDecoratedObject@d1c34fec2c09d786\0" // PrivateGetDecoratedObject() const
	"";
	template <typename DUMMY> maxon::Int DecoratorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const ObjectRef&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(EagerDecoratorInterface, "net.maxon.interface.eagerdecorator", "maxon.EagerDecoratorInterface", , &DecoratorInterface::_interface);
	const maxon::Char* const EagerDecoratorInterface::MTable::_ids = 
		"PrivateSetDecoratedObject@fbe74d369bf62dde\0" // PrivateSetDecoratedObject(const ObjectRef& object)
		"PrivateSetDecoratedObject@80b6070de25a5805\0" // PrivateSetDecoratedObject(ObjectRef&& object)
	"";
	template <typename DUMMY> maxon::Int EagerDecoratorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EagerDecoratorComponent, , "net.maxon.component.eagerdecorator");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_decorator(0
	| maxon::DecoratorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::EagerDecoratorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
