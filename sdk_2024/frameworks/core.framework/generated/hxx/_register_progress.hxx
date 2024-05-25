#if 1
namespace maxon
{
	const maxon::Char* const ProgressInterface::MTable::_ids = 
		"InitProgress@405bb396d4416985\0" // Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
		"AddProgressJob@de32333bb6317caa\0" // Result<Int> AddProgressJob(Float jobWeight, const String& jobName)
		"SetProgressAndCheckBreak@b1e4a8f684988fec\0" // Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
		"GetProgress@ae0e97e769676c7e\0" // Result<Float> GetProgress(Int jobIndex)
		"GetTotalWeight@e6d3186387d3ce58\0" // Float GetTotalWeight() const
		"ObservableProgressNotification@9f56f9d31f300977\0" // maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification(Bool create) const
		"GetTime@6eae4a349415f4b3\0" // Result<Tuple<TimeValue, TimeValue>> GetTime() const
		"GetDetailsText@b8f12dfa16054f01\0" // String GetDetailsText() const
		"SetDetailsText@cc63eccfe460c07a\0" // void SetDetailsText(const String& details)
		"SupportsCancelJob@12e73654e6d65520\0" // Bool SupportsCancelJob() const
		"SetCancelJobDelegate@80e9f9e81b61c1a1\0" // Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate)
		"CancelJob@3008090429c5a175\0" // Result<void> CancelJob()
		"IsCancelled@d7a8c99431e20a5a\0" // Bool IsCancelled()
	"";
	const maxon::METHOD_FLAGS ProgressInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ProgressInterface, , "net.maxon.interface.progress", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ProgressInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ProgressObject, , "net.maxon.image.class.mediasessionprogressobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_progress(0
	| maxon::ProgressInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
