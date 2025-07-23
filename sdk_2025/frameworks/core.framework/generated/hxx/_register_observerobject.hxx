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
		"ObserverDestroyed@64cffe089dff7c10\0" // maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed(maxon::Bool create) const
		"ObserverDisconnectNotify@b3a4cc9321576e3c\0" // maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify(maxon::Bool create) const
		"ObserverConnectNotify@248a84715a2c6aa8\0" // maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify(maxon::Bool create) const
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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ObserverObjectInterface, , "net.maxon.interface.observerobject", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ObserverObjectInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObserverObjectClass, , "net.maxon.class.observerobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_observerobject(0
	| maxon::ObserverObjectInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
