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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SystemErrorInterface, , "net.maxon.interface.systemerror", "maxon.SystemErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemErrorObject, , "net.maxon.error.system");
	const maxon::Char* const NSSystemErrorInterface::MTable::_ids = 
		"SetNSError@323b482753bf9f56\0" // void SetNSError(NSError* osError)
		"GetNSError@795d8d7a10bfe\0" // NSError* GetNSError() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NSSystemErrorInterface, , "net.maxon.interface.nsystemerror", "maxon.NSSystemErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NSSystemErrorObject, , "net.maxon.error.nsystem");
}
#endif
