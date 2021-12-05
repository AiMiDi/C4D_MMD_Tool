#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ObserverObjectInterface::MTable::_ids = 
/// @cond INTERNAL

		"AddSenderSignal@4d38176f4a2edc9d\0" // Result<void> AddSenderSignal(ObservableBaseInterface* observable)
		"RemoveSenderSignal@28d794d0267fe414\0" // void RemoveSenderSignal(ObservableBaseInterface* observable)
/// @endcond

		"GetName@22c6ed80868\0" // String GetName() const
		"SetName@0a91ca997ced89a9\0" // void SetName(const String& name)
		"ObserverDestroyed@d0cafb14ea3d66dc\0" // maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed() const
		"ObserverDisconnectNotify@3814356cdea9c486\0" // maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify() const
		"ObserverConnectNotify@462943c07c1a2562\0" // maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ObserverObjectInterface, , "net.maxon.interface.observerobject", "maxon.ObserverObjectInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int ObserverObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObserverObjectClass, , "net.maxon.class.observerobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_observerobject(0
	| maxon::ObserverObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
