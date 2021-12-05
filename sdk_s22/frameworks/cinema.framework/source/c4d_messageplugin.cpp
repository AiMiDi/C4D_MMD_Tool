#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_messageplugin.h"
#include "c4d_general.h"

Int32 MessageData::GetTimer(void)
{
	return 0;
}

Bool RegisterMessagePlugin(Int32 id, const maxon::String& str, Int32 info, MessageData* dat)
{
	if (!dat)
		return false;

	MESSAGEPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.info	= info;
	np.Destructor	 = &BaseData::Destructor;
	np.CoreMessage = &MessageData::CoreMessage;
	np.GetTimer	= &MessageData::GetTimer;

	return GeRegisterPlugin(PLUGINTYPE::COREMESSAGE, id, str, &np, sizeof(np));
}
