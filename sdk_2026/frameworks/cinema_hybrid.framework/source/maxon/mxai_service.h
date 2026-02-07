#ifndef __MXAI_SERVICE_H__
#define __MXAI_SERVICE_H__

#include "maxon/basearray.h"
#include "maxon/datadictionary.h"
#include "maxon/observable.h"

namespace maxon
{

static constexpr LiteralId MSG_MXAI_SERVICE_STATUS_CHANGED = LiteralId("mxai.status.changed");


class MXAIServiceInterface
{
	MAXON_INTERFACE_NONVIRTUAL(MXAIServiceInterface, MAXON_REFERENCE_STATIC, "net.maxon.interface.mxaiservice");

public:
	static MAXON_METHOD Result<void> StartService();

	static MAXON_METHOD Result<void> StopService();

	static MAXON_METHOD Bool CheckSystemSupport();

	static MAXON_METHOD Bool CheckAvailability(Bool checkIfRunning);

	static MAXON_METHOD Result<BaseArray<DataDictionary>> SendRequestJson(const Url& queryUrl, Bool reconnectService = true);

	MAXON_OBSERVABLE_STATIC(void, ObservableServiceMessage, (const Id& msgId, const DataDictionary& msgData), ObservableCombinerRunAllComponent);
};

#include "mxai_service1.hxx"
#include "mxai_service2.hxx"

}


#endif // __MXAI_SERVICE_H__
