#if 1
namespace maxon
{
	const maxon::Char* const OutOfMemoryErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS OutOfMemoryErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OutOfMemoryErrorInterface, , "net.maxon.interface.outofmemoryerror", "maxon.OutOfMemoryErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OutOfMemoryErrorObject, , "net.maxon.error.outofmemory");
	const maxon::Char* const FunctionNotImplementedErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS FunctionNotImplementedErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionNotImplementedErrorInterface, , "net.maxon.interface.functionnotimplementederror", "maxon.FunctionNotImplementedErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FunctionNotImplementedErrorObject, , "net.maxon.error.functionnotimplemented");
	const maxon::Char* const IllegalArgumentErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS IllegalArgumentErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalArgumentErrorInterface, , "net.maxon.interface.illegalargumenterror", "maxon.IllegalArgumentErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalArgumentErrorObject, , "net.maxon.error.illegalargument");
	const maxon::Char* const NullptrErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS NullptrErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NullptrErrorInterface, , "net.maxon.interface.nullptrerror", "maxon.NullptrErrorInterface", (IllegalArgumentErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NullptrErrorObject, , "net.maxon.error.nullptr");
	const maxon::Char* const IllegalStateErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS IllegalStateErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalStateErrorInterface, , "net.maxon.interface.illegalstateerror", "maxon.IllegalStateErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalStateErrorObject, , "net.maxon.error.illegalstate");
	const maxon::Char* const UnexpectedErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnexpectedErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnexpectedErrorInterface, , "net.maxon.interface.unexpectederror", "maxon.UnexpectedErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnexpectedErrorObject, , "net.maxon.error.unexpected");
	const maxon::Char* const OperationCancelledErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS OperationCancelledErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OperationCancelledErrorInterface, , "net.maxon.interface.OperationCancelledError", "maxon.OperationCancelledErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OperationCancelledErrorObject, , "net.maxon.error.OperationCancelledError");
	const maxon::Char* const AggregatedErrorInterface::MTable::_ids = 
		"AddError@866427872137cf37\0" // Bool AddError(const Error& error)
		"AddError@8600c94a8d495b78\0" // Bool AddError(Error&& error)
		"GetCount@7d0e6f3d29c239e7\0" // Int GetCount() const
		"GetError@c4bd7bfb133ab4ec\0" // const Error& GetError(Int index) const
	"";
	const maxon::METHOD_FLAGS AggregatedErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AggregatedErrorInterface, , "net.maxon.interface.aggregatederror", "maxon.AggregatedErrorInterface", (ErrorInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int AggregatedErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Error&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ErrorObjectClass, , "net.maxon.class.errorobject");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AggregatedErrorObject, , "net.maxon.object.aggregatederror");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_errorbase(0
	| maxon::AggregatedErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
