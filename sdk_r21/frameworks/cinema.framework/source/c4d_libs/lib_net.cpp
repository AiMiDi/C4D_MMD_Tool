/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

#include "lib_prefs.h"
#include "lib_net.h"

static NetLibrary* net_lib_cache = nullptr;

static NetLibrary* CheckNetRenderLib(Int32 offset)
{
	return (NetLibrary*)CheckLib(C4D_NETRENDER_LIBRARY_ID, offset, (C4DLibrary**)&net_lib_cache);
}

Bool IsNetRenderInstalled()
{
	return IsLibraryInstalled(C4D_NETRENDER_LIBRARY_ID);
}

#ifndef __NET_LIB__

JOBSTATE RenderJob::GetState() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetRenderResult));
	if (!lib || !lib->RenderJobGetState) return (JOBSTATE)0;
	return (((RenderJob*)this)->*(lib->RenderJobGetState))();
}

RENDERRESULT RenderJob::GetRenderResult() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetRenderResult));
	if (!lib || !lib->RenderJobGetRenderResult) return RENDERRESULT::OUTOFMEMORY;
	return (((RenderJob*)this)->*(lib->RenderJobGetRenderResult))();
}

void RenderJob::SetState(JOBSTATE state, Bool sendSignal)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobSetState));
	if (!lib || !lib->RenderJobSetState) return;
	(((RenderJob*)this)->*(lib->RenderJobSetState))(state, sendSignal);
}

NetRenderService* RenderJob::GetNetRenderService() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetNetRenderService));
	if (!lib || !lib->GetNetRenderService) return nullptr;
	return (((RenderJob*)this)->*(lib->GetNetRenderService))();
}

const C4DUuid RenderJob::GetUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetUuid));
	if (!lib || !lib->RenderJobGetUuid) return C4DUuid(DC);
	return (((RenderJob*)this)->*(lib->RenderJobGetUuid))();
}

ProgressHook* RenderJob::GetProgressHook(void*& context)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetProgressHook));
	if (!lib || !lib->GetProgressHook) return nullptr;
	return (((RenderJob*)this)->*(lib->GetProgressHook))(context);
}

WriteProgressHook* RenderJob::GetWriteProgressHook(void*& context)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetWriteProgressHook));
	if (!lib || !lib->GetWriteProgressHook) return nullptr;
	return (((RenderJob*)this)->*(lib->GetWriteProgressHook))(context);
}

void SetErrorLevel(Bool printDebugErrors, Bool stackInErrors, Bool locationInErrors)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetErrorLevel));
	if (!lib || !lib->SetErrorLevel) return;
	(lib->SetErrorLevel)(printDebugErrors, stackInErrors, locationInErrors);
}

void RenderJob::SetDefaultScenePath(const Filename& defaultSceneName)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobSetDefaultSceneName));
	if (!lib || !lib->RenderJobSetDefaultSceneName) return;
	(((RenderJob*)this)->*(lib->RenderJobSetDefaultSceneName))(defaultSceneName);
}

Filename RenderJob::GetDefaultScenePath() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetDefaultSceneName));
	if (!lib || !lib->RenderJobGetDefaultSceneName) return Filename();
	return (((RenderJob*)this)->*(lib->RenderJobGetDefaultSceneName))();
}

const C4DUuid RenderJob::GetCreatorUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetCreatorUuid));
	if (!lib || !lib->RenderJobGetCreatorUuid) return C4DUuid(DC);
	return (((RenderJob*)this)->*(lib->RenderJobGetCreatorUuid))();
}

void RenderJob::SetCreatorUuid(const C4DUuid& creatorUuid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobSetCreatorUuid));
	if (!lib || !lib->RenderJobGetServerUuid) return;
	(((RenderJob*)this)->*(lib->RenderJobSetCreatorUuid))(creatorUuid);
}

const C4DUuid RenderJob::GetServerUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobGetServerUuid));
	if (!lib || !lib->RenderJobGetServerUuid) return C4DUuid(DC);
	return (((RenderJob*)this)->*(lib->RenderJobGetServerUuid))();
}

void RenderJob::SetServerUuid(const C4DUuid& serverUuid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RenderJobSetServerUuid));
	if (!lib || !lib->RenderJobSetServerUuid) return;
	(((RenderJob*)this)->*(lib->RenderJobSetServerUuid))(serverUuid);
}

void RenderJob::UpdateProgress(Float progress, Bool completed)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, UpdateProgress));
	if (!lib || !lib->UpdateProgress) return;
	(((RenderJob*)this)->*(lib->UpdateProgress))(progress, completed);
}

const NetRenderData* RenderJob::GetRenderData() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRenderData));
	if (!lib || !lib->GetRenderData) return nullptr;
	return (((RenderJob*)this)->*(lib->GetRenderData))();
}

RelativeFilename RenderJob::GetProjectFolder() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetProjectFolder));
	if (!lib || !lib->GetProjectFolder) return RelativeFilename();
	return (((RenderJob*)this)->*(lib->GetProjectFolder))();
}

MESSAGERESULT NetSpecialEventAdd(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, Bool forceConnect)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetSpecialEventAdd));
	if (!lib || !lib->NetSpecialEventAdd) return MESSAGERESULT::MEMORYERROR;
	return (lib->NetSpecialEventAdd)(service, remoteUuid, msg, forceConnect);
}

MESSAGERESULT NetGeSyncMessage(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, BaseContainer& result, BaseThread* bt, Bool forceConnect)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetGeSyncMessage));
	if (!lib || !lib->NetGeSyncMessage) return MESSAGERESULT::MEMORYERROR;
	return (lib->NetGeSyncMessage)(service, remoteUuid, msg, result, bt, forceConnect);
}

MESSAGERESULT NetSendData(NetRenderService* service, const C4DUuid& remoteUuid, NetRenderBuffer *data, NetRenderBuffer *result, BaseThread* bt)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetSendData));
	if (!lib || !lib->NetSendData) return MESSAGERESULT::MEMORYERROR;
	return (lib->NetSendData)(service, remoteUuid, data, result, bt);
}

Bool NetSendMessageToServer(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, const String& messageString, Bool doConsoleOutput, Int32 frameNumber)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetSendMessageToServer));
	if (!lib || !lib->NetSendMessageToServer) return false;
	return (lib->NetSendMessageToServer)(service, remoteUuid, jobUuid, type, messageString, doConsoleOutput, frameNumber);
}

Bool NetSendMessageToServer(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, RENDERRESULT res, const String& messageString, Bool doConsoleOutput , Int32 frameNumber)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetSendMessageToServer));
	if (!lib || !lib->NetSendMessageToServer) return false;
	return (lib->NetSendMessageToServer2)(service, remoteUuid, jobUuid, type, res, messageString, doConsoleOutput, frameNumber);
}

Bool NetRenderCacheGet(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, void* &data, Int32 &size)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderCacheGet));
	if (!lib || !lib->NetRenderCacheGet) return false;
	return (lib->NetRenderCacheGet)(context, isServer, cacheID, data, size);
}

Bool NetRenderCacheGetTask(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 &taskID, Int32 &taskSubdivisions)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderCacheGetTask));
	if (!lib || !lib->NetRenderCacheGetTask) return false;
	return (lib->NetRenderCacheGetTask)(context, isServer, cacheID, taskID, taskSubdivisions);
}

Bool NetRenderCacheSendTask(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 taskID, void *data, Int32 size, Bool progress)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderCacheSendTask));
	if (!lib || !lib->NetRenderCacheSendTask) return false;
	return (lib->NetRenderCacheSendTask)(context, isServer, cacheID, taskID, data, size, progress);
}

Bool NetRenderCacheProgress(NetRenderDocumentContext* context, Int32 cacheID, Int32 lastIndex, void* &data, Int32 &size, BaseThread* thread)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderCacheProgress));
	if (!lib || !lib->NetRenderCacheProgress) return false;
	return (lib->NetRenderCacheProgress)(context, cacheID, lastIndex, data, size, thread);
}

Bool NetRenderCachePrepass(NetRenderDocumentContext* context, Int32 cacheID, Bool &completed)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderCachePrepass));
	if (!lib || !lib->NetRenderCachePrepass) return false;
	return (lib->NetRenderCachePrepass)(context, cacheID, completed);
}

Bool NetRenderGetFileFromServer(NetRenderService* client, const Filename& sourcePathOrName, Filename& result, BaseThread* bt)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderGetFileFromServer));
	if (!lib || !lib->NetRenderGetFileFromServer) return false;
	return (lib->NetRenderGetFileFromServer)(client, sourcePathOrName, result, bt);
}

maxon::Result<void> NetRenderGetAssetFromServer(NetRenderService* service, const Filename& sourcePathOrName, Filename& result, SERVERMESSAGE raiseServerMessageIfNotFound, maxon::ThreadInterface* bt)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetRenderGetFileFromServer2));
	return (lib->NetRenderGetFileFromServer2)(service, sourcePathOrName, result, raiseServerMessageIfNotFound, bt);
}

NetRenderService* GetGlobalNetRenderService()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetGlobalNetRenderService));
	if (!lib || !lib->GetGlobalNetRenderService) return nullptr;
	return (lib->GetGlobalNetRenderService)();
}

String GetMachineDescription(const NetRenderService* service, Machine* m)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMachineDescription));
	if (!lib || !lib->GetMachineDescription) return String();
	return (lib->GetMachineDescription)(service, m);
}

String VerificationBitToString(VERIFICATIONBIT state)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, VerificationBitToString));
	if (!lib || !lib->VerificationBitToString) return String();
	return (lib->VerificationBitToString)(state);
}

String JobCommandToString(JOBCOMMAND state)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, JobCommandToString));
	if (!lib || !lib->JobCommandToString) return String();
	return (lib->JobCommandToString)(state);
}

String JobStateToString(JOBSTATE state)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, JobStateToString));
	if (!lib || !lib->JobStateToString) return String();
	return (lib->JobStateToString)(state);
}

String GetDebugStringOfMachine(const Machine* m)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetDebugStringOfMachine));
	if (!lib || !lib->GetDebugStringOfMachine) return String();
	return (lib->GetDebugStringOfMachine)(m);
}

Bool NetRenderService::AddLogToJob(const C4DUuid& jobUuid, const String& log, Bool doLock, Bool append)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, AddLogToJob));
	if (!lib || !lib->AddLogToJob) return false;
	return (((NetRenderService*)this)->*(lib->AddLogToJob))(jobUuid, log, doLock, append);
}

Bool NetRenderService::AddLogToMachine(const C4DUuid& machineUuid, const String& log, Bool doLock)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, AddLogToMachine));
	if (!lib || !lib->AddLogToMachine) return false;
	return (((NetRenderService*)this)->*(lib->AddLogToMachine))(machineUuid, log, doLock);
}

maxon::Result<void> NetRenderService::CopyRenderTaskFrom(const C4DUuid& jobUuid, maxon::BaseArray<RenderTask>& todo)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, AddLogToMachine));
	if (!lib || !lib->AddLogToMachine) return maxon::UnknownError(MAXON_SOURCE_LOCATION);
	return (((NetRenderService*)this)->*(lib->CopyRenderTaskFrom))(jobUuid, todo);
}

BaseContainer* NetRenderService::GetNetPreferences() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetNetPreferences));
	if (!lib || !lib->GetNetPreferences) return nullptr;
	return (((NetRenderService*)this)->*(lib->GetNetPreferences))();
}

EDITION NetRenderService::GetEdition() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetEdition));
	if (!lib || !lib->GetEdition) return EDITION::C4D;
	return (((NetRenderService*)this)->*(lib->GetEdition))();
}

String NetRenderService::GetName() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetName));
	if (!lib || !lib->GetName) return String();
	return (((NetRenderService*)this)->*(lib->GetName))();
}

Bool NetRenderService::IsRunning() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, IsRunning));
	if (!lib || !lib->IsRunning) return false;
	return (((NetRenderService*)this)->*(lib->IsRunning))();
}

Int32 NetRenderService::GetCpuCount() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetCpuCount));
	if (!lib || !lib->GetCpuCount) return false;
	return (((NetRenderService*)this)->*(lib->GetCpuCount))();
}

void NetRenderService::GetAllMachineUuids(maxon::BaseArray<C4DUuid>& machineUuids, MACHINELIST list, VERIFICATIONBIT bits, Bool includeLocalMachine, Bool includeZeroConfMachines)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetAllMachineUuids));
	if (!lib || !lib->GetAllMachineUuids) return;
	(((NetRenderService*)this)->*(lib->GetAllMachineUuids))(machineUuids, list, bits, includeLocalMachine, includeZeroConfMachines);
}

UserPool& NetRenderService::GetUserPool()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUserPool));
	if (!lib || !lib->GetUserPool) { CriticalStop(); }
	return (((NetRenderService*)this)->*(lib->GetUserPool))();
}

Bool NetRenderService::GetJobsList(const BaseContainer& settings, maxon::BaseArray<BaseContainer>& jobs, Bool triggerWatchDog, DETAILSELECTOR rdata, DETAILSELECTOR assets, DETAILSELECTOR results, DETAILSELECTOR log, const C4DUuid* getOnlyThisJob, Bool selectedJobOnly, const C4DUuid* user)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetJobsList2));
	if (!lib || !lib->GetJobsList2) { return false; }
	return (((NetRenderService*)this)->*(lib->GetJobsList2))(settings, jobs, triggerWatchDog, rdata, assets, results, log, getOnlyThisJob, selectedJobOnly, user);
}

Bool NetRenderService::GetMachinesList(maxon::BaseArray<BaseContainer>& machines, Int32 logCount, const C4DUuid* getOnlyThisMachine) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMachinesList));
	if (!lib || !lib->GetMachinesList) { return false; }
	return (((NetRenderService*)this)->*(lib->GetMachinesList))(machines, logCount, getOnlyThisMachine);
}

Bool NetRenderService::InsertJobBefore(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, InsertJobBefore));
	if (!lib || !lib->InsertJobBefore) return false;
	return (((NetRenderService*)this)->*(lib->InsertJobBefore))(jobUuid1, jobUuid2);
}

Bool NetRenderService::SetDefaultSceneName(const C4DUuid& jobUuid, const Filename& defaultSceneName)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetDefaultSceneName));
	if (!lib || !lib->SetDefaultSceneName) return false;
	return (((NetRenderService*)this)->*(lib->SetDefaultSceneName))(jobUuid, defaultSceneName);
}

Bool NetRenderService::InsertJobAfter(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, InsertJobAfter));
	if (!lib || !lib->InsertJobAfter) return false;
	return (((NetRenderService*)this)->*(lib->InsertJobAfter))(jobUuid1, jobUuid2);
}

RenderJob* NetRenderService::FindRenderJob(const C4DUuid& jobUuid, Bool lookInServerList) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, FindRenderJob));
	if (!lib || !lib->FindRenderJob) return nullptr;
	return (((NetRenderService*)this)->*(lib->FindRenderJob))(jobUuid, lookInServerList);
}

MachineGroup* NetRenderService::GetMachineHead() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMachineHead));
	if (!lib || !lib->GetMachineHead) return nullptr;
	return (((NetRenderService*)this)->*(lib->GetMachineHead))();
}

Machine* NetRenderService::GetFirstMachine() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFirstMachine));
	if (!lib || !lib->GetFirstMachine) return nullptr;
	return (((NetRenderService*)this)->*(lib->GetFirstMachine))();
}

Machine* NetRenderService::FindMachine(const C4DUuid& uid, MACHINELIST list, VERIFICATIONBIT bits) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, FindMachine));
	if (!lib || !lib->FindMachine) return nullptr;
	return (((NetRenderService*)this)->*(lib->FindMachine))(uid, list, bits);
}

maxon::RWSpinlock& NetRenderService::GetMachineLock()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMachineLock));
	return (((NetRenderService*)this)->*(lib->GetMachineLock))();
}

const C4DUuid NetRenderService::GetUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUuid2));
	if (!lib || !lib->GetUuid2) return C4DUuid();
	return (((NetRenderService*)this)->*(lib->GetUuid2))();
}

void NetRenderService::StopRendering(THREADMODE mode, const C4DUuid& jobUuid, RENDERRESULT result)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, StopRendering));
	if (!lib || !lib->StopRendering) return;
	return (((NetRenderService*)this)->*(lib->StopRendering))(mode, jobUuid, result);
}

void NetRenderService::GetMacAddress(maxon::BaseArray<UChar>& macAddress) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMacAddress2));
	if (!lib || !lib->GetMacAddress2) return;
	return (((NetRenderService*)this)->*(lib->GetMacAddress2))(macAddress);
}

void NetRenderService::GetGlobalSelectedMachines(maxon::BaseArray<C4DUuid>& machines, Bool& atLeastOneMachineOnline)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetGlobalSelectedMachines));
	if (!lib || !lib->GetGlobalSelectedMachines) return;
	(((NetRenderService*)this)->*(lib->GetGlobalSelectedMachines))(machines, atLeastOneMachineOnline);
}

void NetRenderService::CopyClientTasksFrom(maxon::BaseArray<C4DUuid>& jobUuids, maxon::BaseArray<Task>& tasks)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, CopyClientTasksFrom));
	if (!lib || !lib->CopyClientTasksFrom) return;
	(((NetRenderService*)this)->*(lib->CopyClientTasksFrom))(jobUuids, tasks);
}

Repository& NetRenderService::GetRepository()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRepository));
	if (!lib || !lib->GetRepository) { CriticalStop(); }
	return (((NetRenderService*)this)->*(lib->GetRepository))();
}

Bool NetRenderService::GetGlobalSelected(maxon::BaseArray<C4DUuid>& machines)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetGlobalSelected2));
	if (!lib || !lib->GetGlobalSelected2) return false;
	return (((NetRenderService*)this)->*(lib->GetGlobalSelected2))(machines);
}

CREATEJOBRESULT NetRenderService::CreateRenderJob(const String& docName, C4DUuid& jobUuid, RENDERJOBCREATOR creator, const String& username, BaseThread* bt, const Filename* watchFolderName)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, CreateRenderJob));
	if (!lib || !lib->CreateRenderJob) return (CREATEJOBRESULT)0;
	return (((NetRenderService*)this)->*(lib->CreateRenderJob))(docName, jobUuid, creator, username, bt, watchFolderName);
}

RENDERRESULT NetRenderService::StartRendering(THREADMODE mode, BaseDocument* doc, const C4DUuid& jobUuid, BaseThread* bt)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, StartRendering));
	if (!lib || !lib->StartRendering) return (RENDERRESULT) 0;
	return (((NetRenderService*)this)->*(lib->StartRendering))(mode, doc, jobUuid, bt);
}

Bool NetRenderService::ClearResults(const C4DUuid& jobUuid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ClearResults));
	if (!lib || !lib->ClearResults) return false;
	return (((NetRenderService*)this)->*(lib->ClearResults))(jobUuid);
}

Bool NetRenderService::RemoveResult(const C4DUuid& jobUuid, const Filename& resResultPath)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, RemoveResult));
	if (!lib || !lib->ClearResults) return false;
	return (((NetRenderService*)this)->*(lib->RemoveResult))(jobUuid, resResultPath);
}

Bool NetRenderService::Message(const C4DUuid& remoteUuid, const NetworkIpAddrPort* remoteAddr, Bool isPrivate, const BaseContainer& msg, BaseContainer& result)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, Message));
	if (!lib || !lib->Message) return false;
	return (((NetRenderService*)this)->*(lib->Message))(remoteUuid, remoteAddr, isPrivate, msg, result);
}

RENDERRESULT NetRenderService::InitRendering(BaseDocument* doc, const BaseContainer& rdata, const C4DUuid& jobUuid, NETRENDERFLAGS flags, PictureViewer* pv, const BaseContainer& machines, MultipassBitmap* bmp, ProgressHook* prog, WriteProgressHook* wprog, void* context, Bool* useFrameNumberAsSuffix, Filename* dispname, const maxon::BaseArray<Bool>* renderTasks)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, InitRendering));
	if (!lib || !lib->InitRendering) return RENDERRESULT::OUTOFMEMORY;
	return (((NetRenderService*)this)->*(lib->InitRendering))(doc, rdata, jobUuid, flags, pv, machines, bmp, prog, wprog, context, useFrameNumberAsSuffix, dispname, renderTasks);
}

Bool NetRenderService::VerifyServerOnClient(THREADMODE mode, const C4DUuid& machineUuid, const String& securityToken, Bool setClientAsGlobalSelected, Bool doLock, Int32 waitUntilExecutionInMs)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, VerifyServerOnClient));
	if (!lib || !lib->VerifyServerOnClient) return false;
	return (((NetRenderService*)this)->*(lib->VerifyServerOnClient))(mode, machineUuid, securityToken, setClientAsGlobalSelected, doLock, waitUntilExecutionInMs);
}

Bool NetRenderService::InitAndStartRenderingFullAsync(const C4DUuid& jobUuid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, InitAndStartRenderingFullAsync));
	if (!lib || !lib->InitAndStartRenderingFullAsync) return false;
	return (((NetRenderService*)this)->*(lib->InitAndStartRenderingFullAsync))(jobUuid);
}

Bool NetRenderService::DeleteRenderJob(const C4DUuid& jobUuid, Bool informClients)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, DeleteRenderJob));
	if (!lib || !lib->DeleteRenderJob) return false;
	return (((NetRenderService*)this)->*(lib->DeleteRenderJob))(jobUuid, informClients);
}

void NetRenderService::NetConsoleOutput(maxon::OUTPUT flags, const maxon::String& value, maxon::OUTPUTLOCATION output, const maxon::SourceLocation& loc)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, NetConsoleOutput));
	if (!lib || !lib->NetConsoleOutput) return;
	return (((NetRenderService*)this)->*(lib->NetConsoleOutput))(flags, value, output, loc);
}

String NetRenderService::GetCurrentJobCommandAsString() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetCurrentJobCommandAsString));
	if (!lib || !lib->GetCurrentJobCommandAsString) return String();
	return (((NetRenderService*)this)->*(lib->GetCurrentJobCommandAsString))();
}

RenderJob* NetRenderService::GetActive() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetActive));
	if (!lib || !lib->GetActive) return nullptr;
	return (((NetRenderService*)this)->*(lib->GetActive))();
}

maxon::RWSpinlock& NetRenderService::GetClientRenderJobLock()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetClientRenderJobLock));
	if (!lib || !lib->GetClientRenderJobLock)
	{
		static maxon::RWSpinlock lock;
		return lock;
	}
	return (((NetRenderService*)this)->*(lib->GetClientRenderJobLock))();
}

Bool NetRenderService::AddMachine(const String& address, const String& securityToken, Bool allowGui, const C4DUuid* uuidOfMachineToOverwrite)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, AddMachine2));
	if (!lib || !lib->AddMachine2) return false;
	return (((NetRenderService*)this)->*(lib->AddMachine2))(address, securityToken, allowGui, uuidOfMachineToOverwrite);
}

const C4DUuid Machine::GetUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUuid));
	if (!lib || !lib->GetUuid) return C4DUuid();
	return (((Machine*)this)->*(lib->GetUuid))();
}

EDITION Machine::GetEdition() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetEdition2));
	if (!lib || !lib->GetEdition2) return EDITION::C4D;
	return (((Machine*)this)->*(lib->GetEdition2))();
}

Bool Machine::GetGlobalSelected() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetGlobalSelected));
	if (!lib || !lib->GetGlobalSelected) return false;
	return (((Machine*)this)->*(lib->GetGlobalSelected))();
}

void Machine::SetGlobalSelected(Bool globalSelected)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetGlobalSelected));
	if (!lib || !lib->SetGlobalSelected) return;
	(((Machine*)this)->*(lib->SetGlobalSelected))(globalSelected);
}

String Machine::GetFullyQualifiedDomainName(Bool* isPrivate) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFullyQualifiedDomainName));
	if (!lib || !lib->GetFullyQualifiedDomainName) return String();
	return (((Machine*)this)->*(lib->GetFullyQualifiedDomainName))(isPrivate);
}

void Machine::ClearVerificationBit(VERIFICATIONBIT state)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ClearVerificationBit));
	if (!lib || !lib->ClearVerificationBit) return;
	return (((Machine*)this)->*(lib->ClearVerificationBit))(state);
}

Bool Machine::GetVerificationBit(VERIFICATIONBIT state) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetVerificationBit));
	if (!lib || !lib->GetVerificationBit) return false;
	return (((Machine*)this)->*(lib->GetVerificationBit))(state);
}

void Machine::SetVerificationBit(VERIFICATIONBIT state)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetVerificationBit));
	if (!lib || !lib->SetVerificationBit) return;
	return (((Machine*)this)->*(lib->SetVerificationBit))(state);
}

void Machine::SetUuid(const C4DUuid& uid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetUuid));
	if (!lib || !lib->GetUuid) return;
	(((Machine*)this)->*(lib->SetUuid))(uid);
}

void Machine::SetMacAddress(const maxon::BaseArray<UChar>& macAddress)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetMacAddress));
	if (!lib || !lib->SetMacAddress) return;
	(((Machine*)this)->*(lib->SetMacAddress))(macAddress);
}

void Machine::GetMacAddress(maxon::BaseArray<UChar>& macAddress) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMacAddress));
	if (!lib || !lib->GetMacAddress) return;
	return (((Machine*)this)->*(lib->GetMacAddress))(macAddress);
}

Vector Machine::GetColor(const Vector* bgColor) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetColor));
	if (!lib || !lib->GetColor) return Vector();
	return (((Machine*)this)->*(lib->GetColor))(bgColor);
}

void Machine::SetColor(const Vector& color)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetColor));
	if (!lib || !lib->SetColor) return;
	(((Machine*)this)->*(lib->SetColor))(color);
}

void Machine::FoundViaZeroConf(Bool foundViaZeroConf)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, FoundViaZeroConf));
	if (!lib || !lib->FoundViaZeroConf) return;
	(((Machine*)this)->*(lib->FoundViaZeroConf))(foundViaZeroConf);
}

Bool Machine::FoundViaZeroConf() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, FoundViaZeroConf2));
	if (!lib || !lib->FoundViaZeroConf2) return false;
	return (((Machine*)this)->*(lib->FoundViaZeroConf2))();
}

OPERATINGSYSTEM Machine::GetOperatingSystem()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetOperatingSystem));
	if (!lib || !lib->GetOperatingSystem) return (OPERATINGSYSTEM)0;
	return (((Machine*)this)->*(lib->GetOperatingSystem))();
}

void Machine::SetOperatingSystem(OPERATINGSYSTEM operatingSystem)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetOperatingSystem));
	if (!lib || !lib->SetOperatingSystem) return;
	(((Machine*)this)->*(lib->SetOperatingSystem))(operatingSystem);
}

const BaseContainer& Machine::GetMachineFeatures() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMachineFeatures));
	return (((Machine*)this)->*(lib->GetMachineFeatures))();
}

void Machine::SetMachineFeatures(const BaseContainer& t_bc)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetMachineFeatures));
	if (!lib || !lib->SetMachineFeatures) return;
	(((Machine*)this)->*(lib->SetMachineFeatures))(t_bc);
}

JOBCOMMAND Machine::GetCurrentJobCommand(C4DUuid* rendersFor) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetCurrentJobCommand));
	if (!lib || !lib->GetCurrentJobCommand) return (JOBCOMMAND)0;
	return (((Machine*)this)->*(lib->GetCurrentJobCommand))(rendersFor);
}

Filename Repository::GetRepositoryPath() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRepositoryPath));
	if (!lib || !lib->GetRepositoryPath) return Filename();
	return (((Repository*)this)->*(lib->GetRepositoryPath))();
}

Filename Repository::GetJobsPath(Bool server) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetJobsPath));
	if (!lib || !lib->GetJobsPath) return Filename();
	return (((Repository*)this)->*(lib->GetJobsPath))(server);
}

void Repository::SetRepositoryPath(const Filename& repositoryPath)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SetRepositoryPath));
	if (!lib || !lib->SetRepositoryPath) return;
	return (((Repository*)this)->*(lib->SetRepositoryPath))(repositoryPath);
}

Filename Repository::ConvertRelative2Absolute(RenderJob* job, Asset* asset) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ConvertRelative2Absolute));
	if (!lib || !lib->ConvertRelative2Absolute) return Filename();
	return (((Repository*)this)->*(lib->ConvertRelative2Absolute))(job, asset);
}

Bool Repository::ConvertAbsolute2RelativePath(const Filename &absolutePath, RelativeFilename &relativePath, Bool server) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ConvertAbsolute2RelativePath));
	if (!lib || !lib->ConvertAbsolute2RelativePath) return false;
	return (((Repository*)this)->*(lib->ConvertAbsolute2RelativePath))(absolutePath, relativePath, server);
}

Asset* RenderJob::GetFirstAsset() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFirstAsset));
	if (!lib || !lib->GetFirstAsset) return nullptr;
	return (((RenderJob*)this)->*(lib->GetFirstAsset))();
}

Bool UserPool::AddUser(const String& username, const String& password, const String& description, Bool isAdmin)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, AddUser));
	if (!lib || !lib->AddUser) return false;
	return (((UserPool*)this)->*(lib->AddUser))(username, password, description, isAdmin);
}

Bool UserPool::DeleteUser(const C4DUuid& userUuid)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, DeleteUser));
	if (!lib || !lib->DeleteUser) return false;
	return (((UserPool*)this)->*(lib->DeleteUser))(userUuid);
}

Bool UserPool::ChangePassword(const C4DUuid& userUuid, const String& oldPassword, const String& newPassword)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ChangePassword));
	if (!lib || !lib->ChangePassword) return false;
	return (((UserPool*)this)->*(lib->ChangePassword))(userUuid, oldPassword, newPassword);
}

Bool UserPool::ChangeDefaultLanguage(const C4DUuid& userUuid, const String& defaultLanguage)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ChangeDefaultLanguage));
	if (!lib || !lib->ChangeDefaultLanguage) return false;
	return (((UserPool*)this)->*(lib->ChangeDefaultLanguage))(userUuid, defaultLanguage);
}

Bool UserPool::CheckUserCredentials(const String& username, const String& password) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, CheckUserCredentials));
	if (!lib || !lib->CheckUserCredentials) return false;
	return (((UserPool*)this)->*(lib->CheckUserCredentials))(username, password);
}

void UserPool::GetUsers(maxon::BaseArray<User*>& users) const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUsers));
	if (!lib || !lib->GetUsers) return;
	return (((UserPool*)this)->*(lib->GetUsers))(users);
}

Bool UserPool::ChangeUserAccountType(const C4DUuid& userUuid, const Bool isAdmin)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ChangeUserAccountType));
	if (!lib || !lib->ChangeUserAccountType) return false;
	return (((UserPool*)this)->*(lib->ChangeUserAccountType))(userUuid, isAdmin);
}

Bool UserPool::ChangeUserInfo(const C4DUuid& userUuid, const String& description)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ChangeUserInfo));
	if (!lib || !lib->ChangeUserInfo) return false;
	return (((UserPool*)this)->*(lib->ChangeUserInfo))(userUuid, description);
}

Bool UserPool::ChangeUserPassword(const C4DUuid& userUuid, const String& password)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ChangeUserPassword));
	if (!lib || !lib->ChangeUserPassword) return false;
	return (((UserPool*)this)->*(lib->ChangeUserPassword))(userUuid, password);
}
C4DUuid User::GetUuid() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUserUuid));
	if (!lib || !lib->GetUserUuid) return C4DUuid(DC);
	return (((iUser*)this)->*(lib->GetUserUuid))();
}

String User::GetUsername() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUserUsername));
	if (!lib || !lib->GetUserUsername) return String();
	return (((iUser*)this)->*(lib->GetUserUsername))();
}

String User::GetDescription() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUserDescription));
	if (!lib || !lib->GetUserDescription) return String();
	return (((iUser*)this)->*(lib->GetUserDescription))();
}

Bool User::IsAdmin() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, IsUserAdmin));
	if (!lib || !lib->IsUserAdmin) return false;
	return (((iUser*)this)->*(lib->IsUserAdmin))();
}

String User::GetDefaultLanguage() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetUserDefaultLanguage));
	if (!lib || !lib->GetUserDefaultLanguage) return String();
	return (((iUser*)this)->*(lib->GetUserDefaultLanguage))();
}

User* User::Alloc()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, UserAlloc));
	if (!lib || !lib->UserAlloc) return nullptr;
	return (lib->UserAlloc)();
}

void User::Free(User*& p)
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, UserFree));
	if (lib && lib->UserFree)
		(lib->UserFree)(p);
}

String NetRenderData::GetName() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetName2));
	if (!lib || !lib->GetName2) return String();
	return (((NetRenderData*)this)->*(lib->GetName2))();
}


Bool NetRenderData::IsSingleFrameRendering() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, IsSingleFrameRendering));
	if (!lib || !lib->IsSingleFrameRendering) return false;
	return (((NetRenderData*)this)->*(lib->IsSingleFrameRendering))();
}

Int32 NetRenderData::GetRealFps() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRealFps));
	if (!lib || !lib->GetRealFps) return 0;
	return (((NetRenderData*)this)->*(lib->GetRealFps))();
}

Float NetRenderData::GetFps() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFps));
	if (!lib || !lib->GetFps) return 0;
	return (((NetRenderData*)this)->*(lib->GetFps))();
}

BaseTime NetRenderData::GetFrameFrom() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFrameFrom));
	if (!lib || !lib->GetFrameFrom) return BaseTime();
	return (((NetRenderData*)this)->*(lib->GetFrameFrom))();
}

BaseTime NetRenderData::GetFrameTo() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFrameTo));
	if (!lib || !lib->GetFrameTo) return BaseTime();
	return (((NetRenderData*)this)->*(lib->GetFrameTo))();
}

BaseContainer& NetRenderData::GetData()
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetData2));
	if (!lib || !lib->GetData2)
		DebugStop();
	return (((NetRenderData*)this)->*(lib->GetData2))();
}

const BaseContainer& NetRenderData::GetData() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetData3));
	if (!lib || !lib->GetData3)
		DebugStop();
	return (((NetRenderData*)this)->*(lib->GetData3))();
}

Int32 NetRenderData::GetWidth() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetWidth));
	if (!lib || !lib->GetWidth) return 0;
	return (((NetRenderData*)this)->*(lib->GetWidth))();
}

Int32  NetRenderData::GetHeight() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetHeight));
	if (!lib || !lib->GetHeight) return 0;
	return (((NetRenderData*)this)->*(lib->GetHeight))();
}

Int32 NetRenderData::GetFrameRange() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFrameRange));
	if (!lib || !lib->GetFrameRange) return 0;
	return (((NetRenderData*)this)->*(lib->GetFrameRange))();
}

Int32 NetRenderData::GetNameFormat() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetNameFormat));
	if (!lib || !lib->GetNameFormat) return 0;
	return (((NetRenderData*)this)->*(lib->GetNameFormat))();
}

Int32 NetRenderData::GetFrameStep() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFrameStep));
	if (!lib || !lib->GetFrameStep) return 0;
	return (((NetRenderData*)this)->*(lib->GetFrameStep))();
}

Bool NetRenderData::UseFrameNumberAsSuffix() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, UseFrameNumberAsSuffix));
	if (!lib || !lib->UseFrameNumberAsSuffix) return false;
	return (((NetRenderData*)this)->*(lib->UseFrameNumberAsSuffix))();
}

Bool NetRenderData::ShowHud() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ShowHud));
	if (!lib || !lib->ShowHud) return false;
	return (((NetRenderData*)this)->*(lib->ShowHud))();
}

Bool NetRenderData::SaveImage() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SaveImage));
	if (!lib || !lib->SaveImage) return false;
	return (((NetRenderData*)this)->*(lib->SaveImage))();
}

Int32 NetRenderData::GetImageFormat() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetImageFormat));
	if (!lib || !lib->GetImageFormat) return 0;
	return (((NetRenderData*)this)->*(lib->GetImageFormat))();
}

Filename NetRenderData::GetImageFilename() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetImageFilename));
	if (!lib || !lib->GetImageFilename) return Filename();
	return (((NetRenderData*)this)->*(lib->GetImageFilename))();
}

Filename NetRenderData::GetImageAbsResultFolder() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetImageAbsResultFolder));
	if (!lib || !lib->GetImageAbsResultFolder) return Filename();
	return (((NetRenderData*)this)->*(lib->GetImageAbsResultFolder))();
}

Bool NetRenderData::GetImageFormatIsMovie() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetImageFormatIsMovie));
	if (!lib || !lib->GetImageFormatIsMovie) return false;
	return (((NetRenderData*)this)->*(lib->GetImageFormatIsMovie))();
}


Bool NetRenderData::SaveMultipass() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, SaveMultipass));
	if (!lib || !lib->SaveMultipass) return false;
	return (((NetRenderData*)this)->*(lib->SaveMultipass))();
}

Int32 NetRenderData::GetMultipassImageFormat() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMultipassImageFormat));
	if (!lib || !lib->GetMultipassImageFormat) return false;
	return (((NetRenderData*)this)->*(lib->GetMultipassImageFormat))();
}

Filename NetRenderData::GetMultipassFilename() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMultipassFilename));
	if (!lib || !lib->GetMultipassFilename) return Filename();
	return (((NetRenderData*)this)->*(lib->GetMultipassFilename))();
}

Filename NetRenderData::GetMultipassAbsResultFolder() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMultipassAbsResultFolder));
	if (!lib || !lib->GetMultipassAbsResultFolder) return Filename();
	return (((NetRenderData*)this)->*(lib->GetMultipassAbsResultFolder))();
}

Bool NetRenderData::GetMultipassFormatIsMovie() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMultipassFormatIsMovie));
	if (!lib || !lib->GetMultipassFormatIsMovie) return false;
	return (((NetRenderData*)this)->*(lib->GetMultipassFormatIsMovie))();
}

Int32 NetRenderData::GetRealImageBitDepth() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRealImageBitDepth));
	if (!lib || !lib->GetRealImageBitDepth) return -1;
	return (((NetRenderData*)this)->*(lib->GetRealImageBitDepth))();
}

Int32 NetRenderData::GetRealMultipassBitDepth() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetRealMultipassBitDepth));
	if (!lib || !lib->GetRealMultipassBitDepth) return -1;
	return (((NetRenderData*)this)->*(lib->GetRealMultipassBitDepth))();
}

Bool NetRenderData::GetMultipassSaveMultilayer() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetMultipassSaveMultilayer));
	if (!lib || !lib->GetMultipassSaveMultilayer) return false;
	return (((NetRenderData*)this)->*(lib->GetMultipassSaveMultilayer))();
}

Bool NetRenderData::ShowTextureError() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, ShowTextureError));
	if (!lib || !lib->ShowTextureError) return false;
	return (((NetRenderData*)this)->*(lib->ShowTextureError))();
}

NETRENDERFLAGS NetRenderData::GetFlags() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetFlags));
	if (!lib || !lib->GetFlags) return NETRENDERFLAGS::NONE;
	return (((NetRenderData*)this)->*(lib->GetFlags))();
}

Filename NetRenderData::GetB3dTempFolder() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetB3dTempFolder));
	if (!lib || !lib->GetB3dTempFolder) return Filename();
	return (((NetRenderData*)this)->*(lib->GetB3dTempFolder))();
}

Filename NetRenderData::GetOriginDocumentDirectoryPath() const
{
	NetLibrary *lib = CheckNetRenderLib(LIBOFFSET(NetLibrary, GetOriginDocumentDirectoryPath));
	if (!lib || !lib->GetOriginDocumentDirectoryPath) return Filename();
	return (((NetRenderData*)this)->*(lib->GetOriginDocumentDirectoryPath))();
}

#endif
