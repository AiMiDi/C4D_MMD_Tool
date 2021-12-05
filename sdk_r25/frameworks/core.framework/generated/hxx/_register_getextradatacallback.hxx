#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
	const maxon::Char* const GetExtraDataCallbackInterface::MTable::_ids = 
		"GetExtraDataMessage@c751268c548ff0b5\0" // Result<DelegateBase> GetExtraDataMessage(const Id& cmdId)
	"";
	const maxon::METHOD_FLAGS GetExtraDataCallbackInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(GetExtraDataCallbackInterface, , "net.maxon.interface.getextradatacallback", "maxon.GetExtraDataCallbackInterface", (ObjectInterface::PrivateGetInterface()));
}
#ifdef __API_INTERN__
#endif
#endif
