#if 1
namespace maxon
{
	const maxon::Char* const UnsupportedArgumentErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnsupportedArgumentErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedArgumentErrorInterface, , "net.maxon.interface.unsupportedargumenterror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedArgumentErrorObject, , "net.maxon.error.unsupportedargument");
	const maxon::Char* const UnresolvedErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnresolvedErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnresolvedErrorInterface, , "net.maxon.interface.unresolvederror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnresolvedErrorObject, , "net.maxon.error.unresolved");
	const maxon::Char* const UnknownErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnknownErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnknownErrorInterface, , "net.maxon.interface.unknownerror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnknownErrorObject, , "net.maxon.error.unknown");
	const maxon::Char* const UnsupportedOperationErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnsupportedOperationErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnsupportedOperationErrorInterface, , "net.maxon.interface.unsupportedoperationerror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnsupportedOperationErrorObject, , "net.maxon.error.unsupportedoperation");
	const maxon::Char* const ShutdownErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS ShutdownErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ShutdownErrorInterface, , "net.maxon.interface.shutdownerror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ShutdownErrorObject, , "net.maxon.error.shutdown");
	const maxon::Char* const DisabledErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DisabledErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DisabledErrorInterface, , "net.maxon.interface.disablederror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DisabledErrorObject, , "net.maxon.error.disabled");
	const maxon::Char* const ErrnoErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS ErrnoErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrnoErrorInterface, , "net.maxon.interface.errnoerror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ErrnoErrorObject, , "net.maxon.error.errno");
}
#endif
