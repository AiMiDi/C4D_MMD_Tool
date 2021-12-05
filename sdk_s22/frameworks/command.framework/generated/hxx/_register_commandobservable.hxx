#if 1
namespace maxon
{
	const maxon::Char* const CommandObserverInterface::MTable::_ids = 
		"ObservableCommandStatus@63fe9f982314dc85\0" // maxon::ObservableRef<ObservableCommandStatusDelegate> ObservableCommandStatus() const
		"ObservableCommandInvoked@5f4d51820265959d\0" // maxon::ObservableRef<ObservableCommandInvokedDelegate> ObservableCommandInvoked() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandObserverInterface, , "net.maxon.command.interface.observer", "maxon.CommandObserverInterface", (&ObserverObjectInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CommandObserverObjectClass, , "net.maxon.command.class.observer");
}
#endif
