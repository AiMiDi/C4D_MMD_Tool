#if 1
namespace maxon
{
	const maxon::Char* const OutOfMemoryErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OutOfMemoryErrorInterface, , "net.maxon.interface.outofmemoryerror", "maxon.OutOfMemoryErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OutOfMemoryErrorObject, , "net.maxon.error.outofmemory");
	const maxon::Char* const FunctionNotImplementedErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionNotImplementedErrorInterface, , "net.maxon.interface.functionnotimplementederror", "maxon.FunctionNotImplementedErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FunctionNotImplementedErrorObject, , "net.maxon.error.functionnotimplemented");
	const maxon::Char* const IllegalArgumentErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalArgumentErrorInterface, , "net.maxon.interface.illegalargumenterror", "maxon.IllegalArgumentErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalArgumentErrorObject, , "net.maxon.error.illegalargument");
	const maxon::Char* const NullptrErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NullptrErrorInterface, , "net.maxon.interface.nullptrerror", "maxon.NullptrErrorInterface", (&IllegalArgumentErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NullptrErrorObject, , "net.maxon.error.nullptr");
	const maxon::Char* const IllegalStateErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalStateErrorInterface, , "net.maxon.interface.illegalstateerror", "maxon.IllegalStateErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalStateErrorObject, , "net.maxon.error.illegalstate");
	const maxon::Char* const UnexpectedErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnexpectedErrorInterface, , "net.maxon.interface.unexpectederror", "maxon.UnexpectedErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnexpectedErrorObject, , "net.maxon.error.unexpected");
	const maxon::Char* const AggregatedErrorInterface::MTable::_ids = 
		"AddError@b66a303abbdb7b74\0" // Bool AddError(const Error& error)
		"AddError@1893bc554287342f\0" // Bool AddError(Error&& error)
		"GetCount@4386c86\0" // Int GetCount() const
		"GetError@f6248416e94ff333\0" // const Error& GetError(Int index) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AggregatedErrorInterface, , "net.maxon.interface.aggregatederror", "maxon.AggregatedErrorInterface", (&ErrorInterface::_interface));
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
