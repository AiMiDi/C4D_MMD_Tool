#ifndef SPLASH_H__
#define SPLASH_H__

#include "maxon/machine.h"


namespace maxon
{

namespace MACHINE_MESSAGE
{
	namespace MSG_INITIALIZATION_STAGE
	{
		MAXON_ATTRIBUTE(InternedId, ID, "net.maxon.msg.initialization.stage");
		MAXON_ATTRIBUTE(String, STAGETEXT, "net.maxon.msg.initialization.stage.text"); ///< progress text to be displayed in the splash
	}
	namespace MSG_INITIALIZATION_IMAGE
	{
		MAXON_ATTRIBUTE(InternedId, ID, "net.maxon.msg.initialization.image");
		MAXON_ATTRIBUTE(Url, IMAGEURL, "net.maxon.msg.initialization.imageurl"); ///< url to the image to be displayed in the splash
	}
	namespace MSG_INITIALIZATION_BLOCKING_START
	{
		MAXON_ATTRIBUTE(InternedId, ID, "net.maxon.msg.initialization.blocking.start"); ///< main thread blocking section starts (will make the splash 100% visible if still in animation)
	}
	namespace MSG_INITIALIZATION_SPLASH_SHOW
	{
		MAXON_ATTRIBUTE(InternedId, ID, "net.maxon.msg.initialization.splash.show");
		MAXON_ATTRIBUTE(Bool, SHOW, "net.maxon.msg.initialization.splash.show.flag"); ///< false to hide the splash, true to show it
	}
}

#include "splash1.hxx"
#include "splash2.hxx"

inline void SetSplashMessage(const String& text)
{
	iferr_scope_handler
	{
		return;
	};
	MachineRef		 machine = MachinesInterface::GetLocal();
	DataDictionary msg;
	msg.Set(MACHINE_MESSAGE::MSG_ID, MACHINE_MESSAGE::MSG_INITIALIZATION_STAGE::ID) iferr_return;
	msg.Set(MACHINE_MESSAGE::MSG_INITIALIZATION_STAGE::STAGETEXT, text) iferr_return;
	machine.ObservableMessageReceived().Notify(machine, msg) iferr_return;
}

inline void SetSplashImage(const Url& url)
{
	iferr_scope_handler
	{
		return;
	};
	MachineRef		 machine = MachinesInterface::GetLocal();
	DataDictionary msg;
	msg.Set(MACHINE_MESSAGE::MSG_ID, MACHINE_MESSAGE::MSG_INITIALIZATION_IMAGE::ID) iferr_return;
	msg.Set(MACHINE_MESSAGE::MSG_INITIALIZATION_IMAGE::IMAGEURL, url) iferr_return;
	machine.ObservableMessageReceived().Notify(machine, msg) iferr_return;
}

inline void SetSplashStartBlocking()
{
	iferr_scope_handler
	{
		return;
	};
	MachineRef		 machine = MachinesInterface::GetLocal();
	DataDictionary msg;
	msg.Set(MACHINE_MESSAGE::MSG_ID, MACHINE_MESSAGE::MSG_INITIALIZATION_BLOCKING_START::ID) iferr_return;
	machine.ObservableMessageReceived().Notify(machine, msg) iferr_return;
}

inline void SetSplashShow(Bool show)
{
	iferr_scope_handler
	{
		return;
	};
	MachineRef		 machine = MachinesInterface::GetLocal();
	DataDictionary msg;
	msg.Set(MACHINE_MESSAGE::MSG_ID, MACHINE_MESSAGE::MSG_INITIALIZATION_SPLASH_SHOW::ID) iferr_return;
	msg.Set(MACHINE_MESSAGE::MSG_INITIALIZATION_SPLASH_SHOW::SHOW, show) iferr_return;
	machine.ObservableMessageReceived().Notify(machine, msg) iferr_return;
}

}

#endif // SPLASH_H__