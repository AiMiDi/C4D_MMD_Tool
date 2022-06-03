#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ObserverObjectInterface::MTable::_ids = 
/// @cond INTERNAL

		"AddSenderSignal@c4464e28723e6816\0" // Result<void> AddSenderSignal(ObservableBaseInterface* observable)
		"RemoveSenderSignal@741086434453b0cb\0" // void RemoveSenderSignal(ObservableBaseInterface* observable)
/// @endcond

		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"SetName@cc63eccfe460c07a\0" // void SetName(const String& name)
		"ObserverDestroyed@83bd1b23f794947f\0" // maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed() const
		"ObserverDisconnectNotify@93f465124e839643\0" // maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify() const
		"ObserverConnectNotify@887d35cb636457b7\0" // maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify() const
	"";
	const maxon::METHOD_FLAGS ObserverObjectInterface::MTable::_flags[] = 
	{
/// @cond INTERNAL

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
/// @endcond

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ObserverObjectInterface, , "net.maxon.interface.observerobject", "maxon.ObserverObjectInterface", (ObjectInterface::PrivateGetInterface()));
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
