#if 1
namespace maxon
{
	const maxon::Char* const MediaSessionProgressInterface::MTable::_ids = 
		"InitProgress@f8ae82a61ac97474\0" // Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate)
		"AddProgressJob@295a967a1bb284d6\0" // Result<Int> AddProgressJob(const Float jobWeight, const String& jobName)
		"SetProgressAndCheckBreak@ee8350d84b0c3c87\0" // Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent)
		"ObservableProgressNotification@da5be79befde3c26\0" // maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaSessionProgressInterface, , "net.maxon.image.interface.mediasessionprogress", "maxon.MediaSessionProgressInterface", (&ObserverObjectInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaSessionProgressObject, , "net.maxon.image.class.mediasessionprogressobject");
}
#endif
