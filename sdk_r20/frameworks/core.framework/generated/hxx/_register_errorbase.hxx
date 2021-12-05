#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OutOfMemoryErrorInterface, "net.maxon.interface.outofmemoryerror", "maxon.OutOfMemoryErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const OutOfMemoryErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int OutOfMemoryErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OutOfMemoryErrorObject, , "net.maxon.error.outofmemory");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionNotImplementedErrorInterface, "net.maxon.interface.functionnotimplementederror", "maxon.FunctionNotImplementedErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const FunctionNotImplementedErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int FunctionNotImplementedErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FunctionNotImplementedErrorObject, , "net.maxon.error.functionnotimplemented");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnresolvedErrorInterface, "net.maxon.interface.unresolvederror", "maxon.UnresolvedErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnresolvedErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnresolvedErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnresolvedErrorObject, , "net.maxon.error.unresolved");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedOperationErrorInterface, "net.maxon.interface.unsupportedoperationerror", "maxon.UnsupportedOperationErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnsupportedOperationErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnsupportedOperationErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedOperationErrorObject, , "net.maxon.error.unsupportedoperation");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ThreadCancelledErrorInterface, "net.maxon.interface.threadcancellederror", "maxon.ThreadCancelledErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const ThreadCancelledErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int ThreadCancelledErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ThreadCancelledErrorObject, , "net.maxon.error.threadcancelled");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalArgumentErrorInterface, "net.maxon.interface.illegalargumenterror", "maxon.IllegalArgumentErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const IllegalArgumentErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int IllegalArgumentErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalArgumentErrorObject, , "net.maxon.error.illegalargument");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedArgumentErrorInterface, "net.maxon.interface.unsupportedargumenterror", "maxon.UnsupportedArgumentErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnsupportedArgumentErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnsupportedArgumentErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedArgumentErrorObject, , "net.maxon.error.unsupportedargument");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NullptrErrorInterface, "net.maxon.interface.nullptrerror", "maxon.NullptrErrorInterface", , &IllegalArgumentErrorInterface::_interface);
	const maxon::Char* const NullptrErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int NullptrErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NullptrErrorObject, , "net.maxon.error.nullptr");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IllegalStateErrorInterface, "net.maxon.interface.illegalstateerror", "maxon.IllegalStateErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const IllegalStateErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int IllegalStateErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IllegalStateErrorObject, , "net.maxon.error.illegalstate");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnknownErrorInterface, "net.maxon.interface.unknownerror", "maxon.UnknownErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnknownErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnknownErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnknownErrorObject, , "net.maxon.error.unknown");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ShutdownErrorInterface, "net.maxon.interface.shutdownerror", "maxon.ShutdownErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const ShutdownErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int ShutdownErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ShutdownErrorObject, , "net.maxon.error.shutdown");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnexpectedErrorInterface, "net.maxon.interface.unexpectederror", "maxon.UnexpectedErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnexpectedErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnexpectedErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnexpectedErrorObject, , "net.maxon.error.unexpected");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrnoErrorInterface, "net.maxon.interface.errnoerror", "maxon.ErrnoErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const ErrnoErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int ErrnoErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ErrnoErrorObject, , "net.maxon.error.errno");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnregisteredDataTypeErrorInterface, "net.maxon.interface.unregistereddatatypeerror", "maxon.UnregisteredDataTypeErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const UnregisteredDataTypeErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int UnregisteredDataTypeErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnregisteredDataTypeErrorObject, , "net.maxon.error.unregistereddatatype");
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AggregatedErrorInterface, "net.maxon.interface.aggregatederror", "maxon.AggregatedErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const AggregatedErrorInterface::MTable::_ids = 
		"AddError@b66a303abbdb7b74\0" // AddError(const Error& error)
		"AddError@1893bc554287342f\0" // AddError(Error&& error)
		"GetCount@4386c86\0" // GetCount() const
		"GetError@f6248416e94ff333\0" // GetError(Int index) const
	"";
	template <typename DUMMY> maxon::Int AggregatedErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Error&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ErrorObjectClass, , "net.maxon.class.errorobject");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AggregatedErrorObject, , "net.maxon.object.aggregatederror");
#ifdef MAXON_COMPILER_MSVC
#else
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_errorbase(0
	| maxon::OutOfMemoryErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::FunctionNotImplementedErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnresolvedErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnsupportedOperationErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ThreadCancelledErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::IllegalArgumentErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnsupportedArgumentErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::NullptrErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::IllegalStateErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnknownErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ShutdownErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnexpectedErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ErrnoErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnregisteredDataTypeErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::AggregatedErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
