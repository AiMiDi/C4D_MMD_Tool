#if 1
namespace maxon
{
	const maxon::Char* const CommandObserverInterface::MTable::_ids = 
		"ObservableCommandStatus@1f4d0c9508a72d00\0" // maxon::ObservableRef<ObservableCommandStatusDelegate> ObservableCommandStatus() const
		"ObservableCommandInvoked@75fc08a1ece47a5e\0" // maxon::ObservableRef<ObservableCommandInvokedDelegate> ObservableCommandInvoked() const
		"ObservableCommandPrepareInfo@647929ad1499f067\0" // maxon::ObservableRef<ObservableCommandPrepareInfoDelegate> ObservableCommandPrepareInfo() const
		"ObservableCommandInvokedInfo@95029e75da52dc02\0" // maxon::ObservableRef<ObservableCommandInvokedInfoDelegate> ObservableCommandInvokedInfo() const
	"";
	const maxon::METHOD_FLAGS CommandObserverInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CommandObserverInterface, , "net.maxon.command.interface.observer", "maxon.CommandObserverInterface", (ObserverObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CommandObserverObjectClass, , "net.maxon.command.class.observer");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_InvocationState,, "net.maxon.datatype.command.invokationstate");
}
#endif
