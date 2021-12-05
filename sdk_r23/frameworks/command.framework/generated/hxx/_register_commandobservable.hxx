#if 1
namespace maxon
{
	const maxon::Char* const CommandObserverInterface::MTable::_ids = 
		"ObservableCommandStatus@1f4d0c9508a72d00\0" // maxon::ObservableRef<ObservableCommandStatusDelegate> ObservableCommandStatus() const
		"ObservableCommandInvoked@75fc08a1ece47a5e\0" // maxon::ObservableRef<ObservableCommandInvokedDelegate> ObservableCommandInvoked() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandObserverInterface, , "net.maxon.command.interface.observer", "maxon.CommandObserverInterface", (ObserverObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CommandObserverObjectClass, , "net.maxon.command.class.observer");
}
#endif
