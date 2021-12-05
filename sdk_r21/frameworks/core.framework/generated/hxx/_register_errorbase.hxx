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
	const maxon::Char* const UnresolvedErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnresolvedErrorInterface, , "net.maxon.interface.unresolvederror", "maxon.UnresolvedErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnresolvedErrorObject, , "net.maxon.error.unresolved");
	const maxon::Char* const UnsupportedOperationErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedOperationErrorInterface, , "net.maxon.interface.unsupportedoperationerror", "maxon.UnsupportedOperationErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedOperationErrorObject, , "net.maxon.error.unsupportedoperation");
	const maxon::Char* const ThreadCancelledErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ThreadCancelledErrorInterface, , "net.maxon.interface.threadcancellederror", "maxon.ThreadCancelledErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ThreadCancelledErrorObject, , "net.maxon.error.threadcancelled");
	const maxon::Char* const IllegalArgumentErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalArgumentErrorInterface, , "net.maxon.interface.illegalargumenterror", "maxon.IllegalArgumentErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalArgumentErrorObject, , "net.maxon.error.illegalargument");
	const maxon::Char* const UnsupportedArgumentErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedArgumentErrorInterface, , "net.maxon.interface.unsupportedargumenterror", "maxon.UnsupportedArgumentErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedArgumentErrorObject, , "net.maxon.error.unsupportedargument");
	const maxon::Char* const NullptrErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NullptrErrorInterface, , "net.maxon.interface.nullptrerror", "maxon.NullptrErrorInterface", (&IllegalArgumentErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NullptrErrorObject, , "net.maxon.error.nullptr");
	const maxon::Char* const IllegalStateErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalStateErrorInterface, , "net.maxon.interface.illegalstateerror", "maxon.IllegalStateErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalStateErrorObject, , "net.maxon.error.illegalstate");
	const maxon::Char* const UnknownErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnknownErrorInterface, , "net.maxon.interface.unknownerror", "maxon.UnknownErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnknownErrorObject, , "net.maxon.error.unknown");
	const maxon::Char* const ShutdownErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ShutdownErrorInterface, , "net.maxon.interface.shutdownerror", "maxon.ShutdownErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ShutdownErrorObject, , "net.maxon.error.shutdown");
	const maxon::Char* const UnexpectedErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnexpectedErrorInterface, , "net.maxon.interface.unexpectederror", "maxon.UnexpectedErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnexpectedErrorObject, , "net.maxon.error.unexpected");
	const maxon::Char* const DisabledErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DisabledErrorInterface, , "net.maxon.interface.disablederror", "maxon.DisabledErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DisabledErrorObject, , "net.maxon.error.disabled");
	const maxon::Char* const ErrnoErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrnoErrorInterface, , "net.maxon.interface.errnoerror", "maxon.ErrnoErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ErrnoErrorObject, , "net.maxon.error.errno");
	const maxon::Char* const UnregisteredDataTypeErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnregisteredDataTypeErrorInterface, , "net.maxon.interface.unregistereddatatypeerror", "maxon.UnregisteredDataTypeErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnregisteredDataTypeErrorObject, , "net.maxon.error.unregistereddatatype");
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
