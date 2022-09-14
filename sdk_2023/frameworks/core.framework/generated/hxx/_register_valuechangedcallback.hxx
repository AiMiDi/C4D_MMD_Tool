#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
	const maxon::Char* const ValueChangedCallbackInterface::MTable::_ids = 
		"ValueChangedMessage@d66b72e91f9ac52e\0" // Result<void> ValueChangedMessage(const InternedId& id)
	"";
	const maxon::METHOD_FLAGS ValueChangedCallbackInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ValueChangedCallbackInterface, , "net.maxon.interface.valuechangedcallback", "maxon.ValueChangedCallbackInterface", (ObjectInterface::PrivateGetInterface()));
}
#ifdef __API_INTERN__
#endif
#endif
