#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
	const maxon::Char* const DescriptionMessageCallbackInterface::MTable::_ids = 
		"DescriptionMessage@f2d7ce3fbf1be502\0" // Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data)
	"";
	const maxon::METHOD_FLAGS DescriptionMessageCallbackInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DescriptionMessageCallbackInterface, , "net.maxon.interface.descriptionmessagecallback", "maxon.DescriptionMessageCallbackInterface", (ObjectInterface::PrivateGetInterface()));
}
#ifdef __API_INTERN__
#endif
#endif
