#if 1
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#ifdef __OBJC__
#else
#endif
#else
#endif
namespace maxon
{
	const maxon::Char* const SystemErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS SystemErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SystemErrorInterface, , "net.maxon.interface.systemerror", "maxon.SystemErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemErrorObject, , "net.maxon.error.system");
	const maxon::Char* const NSSystemErrorInterface::MTable::_ids = 
		"SetNSError@6ff84fb35be80407\0" // void SetNSError(NSError* osError)
		"GetNSError@1edade26201c7637\0" // NSError* GetNSError() const
	"";
	const maxon::METHOD_FLAGS NSSystemErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NSSystemErrorInterface, , "net.maxon.interface.nsystemerror", "maxon.NSSystemErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NSSystemErrorObject, , "net.maxon.error.nsystem");
}
#endif
