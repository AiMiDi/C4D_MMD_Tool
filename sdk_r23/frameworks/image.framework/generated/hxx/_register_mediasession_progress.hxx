#if 1
namespace maxon
{
	const maxon::Char* const MediaSessionProgressInterface::MTable::_ids = 
		"InitProgress@405bb396d4416985\0" // Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
		"AddProgressJob@3b90bbc08ab04e25\0" // Result<Int> AddProgressJob(const Float jobWeight, const String& jobName)
		"SetProgressAndCheckBreak@b1e4a8f684988fec\0" // Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
		"ObservableProgressNotification@857127b157b0091b\0" // maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaSessionProgressInterface, , "net.maxon.image.interface.mediasessionprogress", "maxon.MediaSessionProgressInterface", (ObserverObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaSessionProgressObject, , "net.maxon.image.class.mediasessionprogressobject");
}
#endif
