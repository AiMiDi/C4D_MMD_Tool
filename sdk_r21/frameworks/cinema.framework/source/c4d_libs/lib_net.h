/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

//---------------------------------------------------
#ifndef LIB_NET_H__
#define LIB_NET_H__

// Used for ::CoreMessage to detect if a NET message did arrive
#define C4DPL_NETMESSAGE				300002188

// Triggered when the machine list was changed
#define MSG_UPDATEDMACHINE			300002175
#define MSG_ADDEDMACHINE				300002176
#define MSG_REMOVEDMACHINE			300002177

#define MSG_SERVICE_PORTOPEN	357867586
#define MSG_SERVICE_STATECHANGE	300002172

#define C4DPL_JOBCREATE_PRE	300002197
#define C4DPL_JOBCREATE_POST 300002198
#define C4DPL_JOBINITIALIZE_PRE 300002223
#define C4DPL_JOBINITIALIZE_POST 300002224
#define C4DPL_JOBSTART_PRE	300002199
#define C4DPL_JOBSTART_POST	300002200
#define C4DPL_JOBRENDER	300002226
#define C4DPL_JOBASSEMBLE	300002201
#define C4DPL_JOBFINISH 300002202

// used for the webserver
#define C4DPL_WEBSERVER_START 300002207
#define C4DPL_WEBSERVER_STOPPED 300002208
#define C4DPL_WEBSERVER_PORTCHANGED 300002217
#define C4DPL_WEBSERVER_ERROR 300002221
#define C4DPL_WEBSERVER_CREATEANDSTART 300002222

// used in NetGeSyncMessage/NetSpecialEventAdd/NetSendData and comes in NetRenderService::Message
#define MSG_NETRENDER_GETSTATE									300002130
#define MSG_NETRENDER_SECURITYTOKENCHANGED			300002131
#define MSG_NETRENDER_INFORMABOUTUNVERIFICATION 300002167
#define MSG_NETRENDER_RESTART										300002138
#define MSG_NETRENDER_PING											300002139
#define MSG_NETRENDER_SIMULATEDISCONNECT				300002140

// Elements to override address lookup
#define MSG_NETRENDER_OVERRIDEN_NETWORKIPADDR                 500000 // NetworkIpAddr
#define MSG_NETRENDER_OVERRIDEN_HOSTNAME                      500001 // String
#define MSG_NETRENDER_OVERRIDEN_PORT                          500002 // Int32
#define MSG_NETRENDER_OVERRIDEN_PRINTERRORONCONNECTIONERROR   500003

#define MSG_NETRENDER_GETCREDENTIALS 300002225
	#define MSG_NETRENDER_GETCREDENTIALS_SECURITYTOKEN 1000			// String

#define MSG_NETRENDER_CONNECTTOSERVER						300002195
	#define MSG_NETRENDER_CONNECTTOSERVER_CLIENTSECURITYOKEN 1000 // String
	#define MSG_NETRENDER_CONNECTTOSERVER_SERVERSECURITYOKEN 1001 // String
	#define MSG_NETRENDER_CONNECTTOSERVER_RESULT 1002 // Bool
	#define MSG_NETRENDER_CONNECTTOSERVER_RESULT_ERROR 1003 // String

#define MSG_NETRENDER_BUCKET_INFO			0x1000	// Render Bucket Info (Client->Server, blocking expects result)
#define MSG_NETRENDER_BUCKET_INDEX		0x1001	// Render Bucket Index (Client->Server, blocking expects result)
#define MSG_NETRENDER_BUCKET_STARTED	0x1002	// Render Bucket Started (Client->Server, non blocking)
#define MSG_NETRENDER_BUCKET_FINISHED	0x1003	// Render Bucket Finished (Client->Server, non blocking)
#define MSG_NETRENDER_BUCKET_REQUEST	0x1004	// Render Bucket Requested (Client->Server, non blocking)
#define MSG_NETRENDER_CACHE_GET_CACHE	0x1010	// Render Cache Get Cache (Client->Server, blocking expects result)
#define MSG_NETRENDER_CACHE_GET_TASK	0x1011	// Render Cache Get Task (Client->Server, blocking expects result)
#define MSG_NETRENDER_CACHE_SEND_TASK	0x1012	// Render Cache Send Task (Client->Server, non blocking)
#define MSG_NETRENDER_CACHE_PROGRESS	0x1013	// Render Cache Progress (Server->Server, blocking expects result)
#define MSG_NETRENDER_CACHE_PREPASS		0x1014	// Render Cache Prepass State (Client->Server, blocking expects result)

#define MSG_NETRENDER_ANIMATION_RANGE	0x1100	// Get the next animation range (Client->Server, blocking expects results)
	#define CONTAINER_JOBUUID					1002		// C4DUuid
	#define CONTAINER_RANGE_AVAILABLE	1200		// Bool
	#define CONTAINER_RANGE_FROM			1300		// Int32
	#define CONTAINER_RANGE_TO				1140		// Int32

#define MSG_NETRENDER_WENTONLINE 300002135
	#define MSG_NETRENDER_WENTONLINE_NEWPORT						1000 // Int32
	#define MSG_NETRENDER_WENTONLINE_RESULT_VERIFIEDME	2000 // Bool
	#define MSG_NETRENDER_WENTONLINE_RESULT_SHARED			3000 // Bool

#define MSG_NETRENDER_ADDNEWMACHINETORENDERING 300002191
	#define MSG_NETRENDER_ADDNEWMACHINETORENDERING_ENABLE 1000 // Bool

#define MSG_NETRENDER_SHUTDOWN 28457847

#define MSG_NETRENDER_UPDATEPORT 4786746
	#define MSG_NETRENDER_UPDATEPORT_PORT 1000

#define MSG_NETRENDER_ADDMEASSEEDER 457484
	#define MSG_NETRENDER_ADDMEASSEEDER_JOBUUID 1000 // C4DUuid
	#define MSG_NETRENDER_ADDMEASSEEDER_ASSETPARTUUID 1001 // C4DUuid

#define MSG_NETRENDER_GETMETAINFO 75874385
	#define MSG_NETRENDER_GETMETAINFO_UUID 1000
	#define MSG_NETRENDER_GETMETAINFO_BUILDID 1001
	#define MSG_NETRENDER_GETMETAINFO_MACHINEFEATURES 1002
	#define MSG_NETRENDER_GETMETAINFO_DYNAMICPORT 1003
	#define MSG_NETRENDER_GETMETAINFO_EDITION 1004

#define MSG_NETRENDER_SENDCREDENTIAL 74758345
	#define MSG_NETRENDER_SENDCREDENTIAL_REMOTESECURITYTOKEN 1000
	#define MSG_NETRENDER_SENDCREDENTIAL_NAME 1001
	#define MSG_NETRENDER_SENDCREDENTIAL_PORT 1002
	#define MSG_NETRENDER_SENDCREDENTIAL_SECURITYTOKEN 1003
	#define MSG_NETRENDER_SENDCREDENTIAL_SECURITYTOKENISVALID 1004
	#define MSG_NETRENDER_SENDCREDENTIAL_BUILDID 1005
	#define MSG_NETRENDER_SENDCREDENTIAL_BUILDIDISVALID 1006

#define MSG_NETRENDER_UNVERIFYME 394574385
	#define MSG_NETRENDER_UNVERIFYMEANDREMOVE 1000 // Bool

#define MSG_NETRENDER_UNVERIFY 94574385
	#define MSG_NETRENDER_UNVERIFYANDREMOVE 1000 // Bool

#define MSG_NETRENDER_REDISTRIBUTED 300002166
	#define MSG_NETRENDER_REDISTRIBUTED_JOBUUID 1000 // C4DUuid

#define MSG_NETRENDER_SENDSTATE 300002129
	#define MSG_NETRENDER_SENDSTATE_STATE		1000 // Int32
	#define MSG_NETRENDER_SENDSTATE_COUNTER 1001 // Int64
	#define MSG_NETRENDER_SENDSTATE_SERVERUUID 1002 // C4DUuid
	#define MSG_NETRENDER_SENDSTATE_DELETEDJOBRECENTLY 1003 // Bool

#define MSG_NETRENDER_MACHINENAMECHANGED 300002132
	#define MSG_NETRENDER_MACHINENAMECHANGED_NAME 1000 // String

#define MSG_NETRENDER_MACHINECPUCOUNTCHANGED 300002133
	#define MSG_NETRENDER_MACHINECPUCOUNTCHANGED_VALUE 1000 // Int32

#define MSG_NETRENDER_MACHINESHARED 300002189
	#define MSG_NETRENDER_MACHINESHARED_ON 1000 // Bool

#define MSG_NETRENDER_IHAVETASKFORYOU 300002206
	#define MSG_NETRENDER_IHAVETASKFORYOU_JOBNAME 0
	#define MSG_NETRENDER_IHAVETASKFORYOU_TIMESTAMP 1
	#define MSG_NETRENDER_IHAVETASKFORYOU_JOBUUID 2
	#define MSG_NETRENDER_IHAVETASKFORYOU_COMMAND 3
	// First element name
	// Second element timestamp
	// Third Element uuid
	// Command1, Command2, ...

#define MSG_NETRENDER_SENDMESSAGE 300002134
	#define MSG_NETRENDER_SENDERROR_UUID				1001 // C4DUuid
	#define MSG_NETRENDER_SENDERROR_MESSAGE			1000 // String
	#define MSG_NETRENDER_SENDERROR_TYPE				1002 // Int
	#define MSG_NETRENDER_SENDERROR_FRAMENUMBER 1003 // Int32

#define MSG_NETRENDER_PORTCHANGED 300002147
	#define MSG_NETRENDER_PORTCHANGED_PORT 1000 // Int32

#define MSG_NETRENDER_THREADCOUNTCHANGED 300003147
	#define MSG_NETRENDER_THREADCOUNTCHANGED_COUNT 1000 // Int32

#define MSG_NETRENDER_INSERT 300002219
	#define MSG_NETRENDER_INSERT_JOBUUID1 1001
	#define MSG_NETRENDER_INSERT_JOBUUID2 1002
	#define MSG_NETRENDER_INSERT_AFTER 1000

#define MSG_NETRENDER_MONITOR 300002205 // Private

#define ID_GLOBALMACHINELIST 300002136

// Container Elements for GetMachineList
#define MACHINE_CONTAINER 			 300002210
#define MACHINE_ID							 1000
#define MACHINE_UUID						 1001
#define MACHINE_NAME						 1002
#define MACHINE_DESC						 1003
#define MACHINE_STATE						 1004
#define MACHINE_DRIVERVERSION		 1005
#define MACHINE_SELECTED				 1006
#define MACHINE_VERIFICATIONBITS 1007
#define MACHINE_ISLOCAL					 1008
#define MACHINE_OS							 1009
#define MACHINE_CINEMAVERSION		 1010
#define MACHINE_GRAPHICCARD			 1011
#define MACHINE_PROCESSOR				 1012
#define MACHINE_PLUGINS					 1013
#define MACHINE_CURRENTLOG			 1014
#define MACHINE_ADDRESS					 1015
#define MACHINE_CURRENTJOB			 1016
#define MACHINE_FRAMESTART       1017
#define MACHINE_FRAMEEND         1018


// Container Elements for GetJobsList
#define JOB_CONTAINER			300002211
#define JOB_ID						1000
#define JOB_NAME					1001
#define JOB_UUID					1002
#define JOB_DIRECTORY			1003
#define JOB_STATE					1004
#define JOB_FRAMERANGE		1005
#define JOB_CREATOR_UUID	1006
#define JOB_SERVER_UUID		1007
#define JOB_RENDER_RESULT	1008
#define JOB_USER					1009
#define JOB_RDATA					1010
#define JOB_FRAMES				1012
#define JOB_DATETIME_CREATE	1013
#define JOB_DATETIME_START	1014
#define JOB_DATETIME_RENDERTIME	1031
#define JOB_PROGRESS			1015
#define JOB_CURRENTLOG		1016
#define JOB_DEFAULTSCENENAME	1017
#define JOB_ASSET_MODIFIED		1032
#define JOB_ASSET		1018 // container array with containers
	#define JOB_ASSET_NAME	1019 // String
	#define JOB_ASSET_DIRECTORYPATH	1026 // Filename
	#define JOB_ASSET_RELDIRECTORYPATH	1028 // Filename
	#define JOB_ASSET_SIZE	1020 // Int64
	#define JOB_ASSET_IMAGESEQUENCE	1034 // Bool
	#define JOB_ASSET_IMAGESEQUENCE_PREFIX 5000
	#define JOB_ASSET_IMAGESEQUENCE_APPENDIX 5001
	#define JOB_ASSET_IMAGESEQUENCE_FROM 5002
	#define JOB_ASSET_IMAGESEQUENCE_TO 5003
#define JOB_RESULTASSET_MODIFIED		1033
#define JOB_RESULTASSET		1021 // container array with containers
	#define JOB_RESULTASSET_NAME	1022 // String
	#define JOB_RESULTASSET_DIRECTORYPATH	1027 // Filename
	#define JOB_RESULTASSET_SIZE	1023 // Int64
#define JOB_ERRORCOUNT		1024
#define JOB_INVOLVEDMACHINES	1025
#define JOB_FRAMES_REL	1029
#define JOB_FRAMES_ABS	1030
#define JOB_RDATA_TAKE_NAME 1035		///< @since R18
#define JOB_RDATA_NAME 1036					///< @since R18

#ifdef __API_INTERN__
	#include "intbaselist.h"

	#include "c4d_basetime.h"
	#include "c4d_library.h"
	#include "c4d_gui.h"

	#include "hyperfile.h"
	#include "ge_string.h"
	#include "c4d_uuid.h"
	#include "ge_prepass.h"
	#include "customgui_listview.h"
	#include "lib_py.h"
#else
	#include "c4d_library.h"
	#include "c4d_network.h"

	#include "customgui_listview.h"
	#include "lib_py.h"
#endif

#ifdef __NET_LIB__
	#include "maxon/utilities/memoryallocationbase.h"
#endif

namespace maxon
{
#define TeamRenderOutput(service, flags, value, output) service->NetConsoleOutput(flags, value, output, MAXON_SOURCE_LOCATION)

enum class OUTPUTLOCATION
{
	BETA = (1 << 0),	// only during beta
	C4D = (1 << 1),
	NET = (1 << 2),
	ALL = (1 << 1 | 1 << 2)
} MAXON_ENUM_FLAGS(OUTPUTLOCATION);

} // namespace maxon

enum class TASKSTATE
{
	NEW = 1000,	// Newly created, not yet touched
	ASSIGNED,	// Executing
	TRANSFERED,	// Transfered but not yet finished
	ASSEMBLED,	// Assembled and finished (final-state)
	SKIPPED // skipped because of frame range
} MAXON_ENUM_FLAGS(TASKSTATE);

struct RenderTask
{
	maxon::BaseArray<C4DUuid> _machines;
	Int32											_frameNumber = 0;
	TASKSTATE									_state = TASKSTATE::NEW;	// true if task is done, otherwise False
	Int32											_renderTime = 0;
	MultipassBitmap*					_frameBmp = nullptr;
	GeListNode*								_pv_image = nullptr;
	maxon::BaseArray<C4DUuid> _renderingMachines;
	maxon::BaseArray<C4DUuid>	_announcedFinishedRendering;

	RenderTask() = default;

	RenderTask(RenderTask&& src) : _machines(std::move(src._machines)), _frameNumber(std::move(src._frameNumber)), _renderTime(std::move(src._renderTime)), _renderingMachines(std::move(src._renderingMachines)), _announcedFinishedRendering(std::move(src._announcedFinishedRendering))
	{
		_frameBmp = src._frameBmp;
		_pv_image = src._pv_image;

		src._pv_image = nullptr;
		src._frameBmp = nullptr;
	}

#ifdef __NET_LIB__
	maxon::Result<void> CopyFrom(const RenderTask& src)
	{
		iferr_scope;

		_frameNumber = src._frameNumber;
		_state = src._state;
		_renderTime = src._renderTime;
		_frameBmp = src._frameBmp;
		_pv_image = src._pv_image;

		_announcedFinishedRendering.CopyFrom(src._announcedFinishedRendering) iferr_return;
		_renderingMachines.CopyFrom(src._renderingMachines) iferr_return;
		_machines.CopyFrom(src._machines) iferr_return;

		return maxon::OK;
	}
#endif
};

struct RenderTaskTransfer : public RenderTask
{
	Int _originalIndex = 0;

	RenderTaskTransfer() = default;
	RenderTaskTransfer(RenderTaskTransfer&& src) : RenderTask(std::move(src)), _originalIndex(std::move(src._originalIndex)) { }

#ifdef __NET_LIB__
	maxon::Result<void> CopyFrom(const RenderTaskTransfer& src)
	{
		iferr_scope;

		RenderTask::CopyFrom(src) iferr_return;
		_originalIndex = src._originalIndex;

		return maxon::OK;
	}
#endif
};

class Task
{
public:
	C4DUuid _serverUuid;					// uuid of server which has a job
	maxon::BaseArray<JOBCOMMAND> _commands;
	Float _creationTimeStamp;
	Bool _moved;
	String _jobName;

	Task() : _serverUuid(DC), _creationTimeStamp(0.0), _moved(false) { }
	Task(const Task& src) : _serverUuid(src._serverUuid), _creationTimeStamp(src._creationTimeStamp), _moved(src._moved)
	{
		// TODO: (Seb) this can fail
		if (_commands.CopyFrom(src._commands) == maxon::FAILED)
			DiagnosticOutput("Task.CopyFrom() error.");
	}

	const maxon::BaseArray<JOBCOMMAND>& GetCommands() const
	{
		return _commands;
	}

	maxon::BaseArray<JOBCOMMAND>& GetCommands()
	{
		return _commands;
	}

#ifdef __NET_LIB__
	maxon::Result<void> CopyFrom(const Task& task)
	{
		_serverUuid = task._serverUuid;
		_creationTimeStamp = task._creationTimeStamp;
		_moved = task._moved;
		_jobName = task._jobName;
		iferr (_commands.CopyFrom(task._commands))
			return maxon::ResultMem(false);

		return maxon::ResultMem(true);
	}
#endif
};

#define C4D_NETRENDER_LIBRARY_ID		1027247

Bool IsNetRenderInstalled();

class PictureViewer;
class NetRenderService;
class Repository;
class Asset;
class UserPool;
class User;
class MachineGroup;
class Machine;

struct NetRenderBuffer;
struct NetRenderDocumentContext;

class MachineGroup : public BaseList2D
{
#ifndef __API_INTERN__
private:
	MachineGroup();
	~MachineGroup();
#endif
};

class NetRenderData
{
private:
	NetRenderData();
	~NetRenderData();

public:
	String					GetName() const;

	Bool						IsSingleFrameRendering() const;
	Int32						GetRealFps() const;
	Float						GetFps() const;
	BaseTime				GetFrameFrom() const;
	BaseTime				GetFrameTo() const;
	Int32						GetWidth() const;
	Int32						GetHeight() const;
	Int32						GetFrameRange() const;
	Int32						GetNameFormat() const;
	Int32						GetFrameStep() const;
	Bool						UseFrameNumberAsSuffix() const;
	Bool						ShowHud() const;
	BaseContainer&	GetData();
	const BaseContainer& GetData() const;

	Int32						GetRealImageBitDepth() const;
	Int32						GetRealMultipassBitDepth() const;

	Bool						SaveImage() const;
	Int32						GetImageFormat() const;
	Filename				GetImageFilename() const;
	Filename				GetImageAbsResultFolder() const;
	Bool						GetImageFormatIsMovie() const;

	Bool						SaveMultipass() const;
	Int32						GetMultipassImageFormat() const;
	Filename				GetMultipassFilename() const;
	Filename				GetMultipassAbsResultFolder() const;
	Bool						GetMultipassFormatIsMovie() const;
	Bool						GetMultipassSaveMultilayer() const;

	Bool						ShowTextureError() const;

	NETRENDERFLAGS	GetFlags() const;
	Filename				GetB3dTempFolder() const;
	Filename				GetOriginDocumentDirectoryPath() const;
};

class Machine : public BaseList2D
{
#ifndef __API_INTERN__
private:
	Machine();
	~Machine();
#endif
public:
	Machine* GetNext() const { return (Machine*)AtCall(GetNext)(); }
	Machine* GetPred() const { return (Machine*)AtCall(GetPred)(); }

	const C4DUuid GetUuid() const;
	void SetUuid(const C4DUuid& uid);

	Vector GetColor(const Vector* bgColor = nullptr) const;
	void SetColor(const Vector& color);

	Bool GetGlobalSelected() const;
	void SetGlobalSelected(Bool globalSelected);

	void FoundViaZeroConf(Bool foundViaZeroConf);
	Bool FoundViaZeroConf() const;

	String GetFullyQualifiedDomainName(Bool* isPrivate) const;

	OPERATINGSYSTEM GetOperatingSystem();
	void SetOperatingSystem(OPERATINGSYSTEM operatingSystem);

	const BaseContainer& GetMachineFeatures() const;
	void SetMachineFeatures(const BaseContainer& t_bc);

	JOBCOMMAND GetCurrentJobCommand(C4DUuid* rendersFor = nullptr) const;

	void SetMacAddress(const maxon::BaseArray<UChar>& macAddress);
	void GetMacAddress(maxon::BaseArray<UChar>& macAddress) const;

	void ClearVerificationBit(VERIFICATIONBIT state);
	Bool GetVerificationBit(VERIFICATIONBIT state) const;
	void SetVerificationBit(VERIFICATIONBIT state);

	EDITION GetEdition() const;
};

class RenderJob : public BaseList2D
{
#ifndef __API_INTERN__
private:
	RenderJob();
	~RenderJob();
#endif

public:
	JOBSTATE							GetState() const;
	RENDERRESULT					GetRenderResult() const;
	void									SetState(JOBSTATE state, Bool sendSignal = TRUE);
	const C4DUuid					GetUuid() const;
	const C4DUuid					GetCreatorUuid() const;
	void									SetCreatorUuid(const C4DUuid& creatorUuid);
	const C4DUuid					GetServerUuid() const;
	void									SetServerUuid(const C4DUuid& serverUuid);

	void									UpdateProgress(Float progress, Bool completed);
	const NetRenderData*	GetRenderData() const;

	NetRenderService*			GetNetRenderService() const;
	RelativeFilename			GetProjectFolder() const;
	Asset*								GetFirstAsset() const;

	ProgressHook*					GetProgressHook(void*& context);
	WriteProgressHook*		GetWriteProgressHook(void*& context);

	void									SetDefaultScenePath(const Filename& defaultSceneName);
	Filename							GetDefaultScenePath() const;
};

class NetService
{
};

class Asset : public BaseList2D
{
#ifndef __API_INTERN__
private:
	Asset();
	~Asset();
#endif

public:
	Asset* GetNext() const { return (Asset*)AtCall(GetNext)(); }
	Asset* GetPred() const { return (Asset*)AtCall(GetPred)(); }
};

class Repository
{
public:
	Filename GetRepositoryPath() const;
	Filename GetJobsPath(Bool server) const;
	void SetRepositoryPath(const Filename& repositoryPath);
	Filename ConvertRelative2Absolute(RenderJob* job, Asset* asset = nullptr) const;
	Bool ConvertAbsolute2RelativePath(const Filename &absolutePath, RelativeFilename &relativePath, Bool server) const;
};

class UserPool
{
public:
	Bool AddUser(const String& username, const String& password, const String& description, Bool isAdmin);
	Bool DeleteUser(const C4DUuid& userUuid);
	Bool ChangePassword(const C4DUuid& userUuid, const String& oldPassword, const String& newPassword);
	Bool ChangeDefaultLanguage(const C4DUuid& userUuid, const String& defaultLanguage);
	Bool ChangeUserAccountType(const C4DUuid& userUuid, const Bool isAdmin);
	Bool ChangeUserInfo(const C4DUuid& userUuid, const String& description);
	Bool ChangeUserPassword(const C4DUuid& userUuid, const String& password);
	Bool CheckUserCredentials(const String& username, const String& password) const;
	void GetUsers(maxon::BaseArray<User*>& users) const;
	User* GetUser(const String& username);
};

class User
{
public:
	C4DUuid GetUuid() const;
	String GetUsername() const;
	String GetDescription() const;
	Bool IsAdmin() const;
	String GetDefaultLanguage() const;

	static User* Alloc();
	static void Free(User*& p);
};

class NetRenderService : public NetService
{
public:
	MachineGroup* GetMachineHead() const;
	Machine* GetFirstMachine() const;
	Machine* FindMachine(const C4DUuid& uid, MACHINELIST list, VERIFICATIONBIT bits = VERIFICATIONBIT::NONE) const;
	maxon::RWSpinlock& GetMachineLock();
	void GetAllMachineUuids(maxon::BaseArray<C4DUuid>& machineUuids, MACHINELIST list = MACHINELIST::ALL, VERIFICATIONBIT bits = VERIFICATIONBIT::NONE, Bool includeLocalMachine = true, Bool includeZeroConfMachines = true);
	RenderJob* FindRenderJob(const C4DUuid& jobUuid, Bool lookInServerList) const;
	const C4DUuid GetUuid() const;
	void GetMacAddress(maxon::BaseArray<UChar>& macAddress) const;
	void CopyClientTasksFrom(maxon::BaseArray<C4DUuid>& jobUuids, maxon::BaseArray<Task>& tasks);
	Repository& GetRepository();
	UserPool& GetUserPool();
	maxon::RWSpinlock& GetClientRenderJobLock();
	String GetName() const;
	Bool IsRunning() const;
	Int32 GetCpuCount() const;
	void NetConsoleOutput(maxon::OUTPUT flags, const maxon::String& value, maxon::OUTPUTLOCATION output, const maxon::SourceLocation& loc);
	Bool AddLogToJob(const C4DUuid& jobUuid, const String& log, Bool doLock, Bool append);
	Bool AddLogToMachine(const C4DUuid& machineUuid, const String& log, Bool doLock);
	Bool AddMachine(const String& address = String(), const String& securityToken = String(), Bool allowGui = true, const C4DUuid* uuidOfMachineToOverwrite = nullptr);

	// client
	String				GetCurrentJobCommandAsString() const;
	RenderJob*		GetActive() const;

	// server
	CREATEJOBRESULT CreateRenderJob(const String& docName, C4DUuid& jobUuid, RENDERJOBCREATOR creator, const String& username, BaseThread* bt = nullptr, const Filename* watchFolderName = nullptr);
	RENDERRESULT InitRendering(BaseDocument* doc, const BaseContainer& rdata, const C4DUuid& jobUuid, NETRENDERFLAGS flags, PictureViewer* pv, const BaseContainer& machines, MultipassBitmap* bmp = nullptr, ProgressHook* prog = nullptr, WriteProgressHook* wprog = nullptr, void* context = nullptr, Bool* useFrameNumberAsSuffix = nullptr, Filename* dispname = nullptr, const maxon::BaseArray<Bool>* renderTasks = nullptr);
	RENDERRESULT StartRendering(THREADMODE mode, BaseDocument* doc, const C4DUuid& jobUuid, BaseThread* bt);
	Bool VerifyServerOnClient(THREADMODE mode, const C4DUuid& machineUuid, const String& securityToken, Bool setClientAsGlobalSelected, Bool doLock = true, Int32 waitUntilExecutionInMs = 0);
	Bool DeleteRenderJob(const C4DUuid& jobUuid, Bool informClients);
	Bool GetGlobalSelected(maxon::BaseArray<C4DUuid>& machines);
	Bool GetJobsList(const BaseContainer& settings, maxon::BaseArray<BaseContainer>& jobs, Bool triggerWatchDog, DETAILSELECTOR rdata, DETAILSELECTOR assets, DETAILSELECTOR results, DETAILSELECTOR log, const C4DUuid* getOnlyThisJob = nullptr, Bool selectedJobOnly = false, const C4DUuid* user = nullptr);
	Bool GetMachinesList(maxon::BaseArray<BaseContainer>& machines, Int32 logCount, const C4DUuid* getOnlyThisMachine) const;
	void GetGlobalSelectedMachines(maxon::BaseArray<C4DUuid>& machines, Bool& atLeastOneMachineOnline);
	Bool InitAndStartRenderingFullAsync(const C4DUuid& jobUuid);
	void StopRendering(THREADMODE mode, const C4DUuid& jobUuid, RENDERRESULT result);
	Bool InsertJobBefore(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2);
	Bool InsertJobAfter(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2);
	Bool SetDefaultSceneName(const C4DUuid& jobUuid, const Filename& defaultSceneName);
	Bool Message(const C4DUuid& remoteUuid, const NetworkIpAddrPort* remoteAddr, Bool isPrivate, const BaseContainer& msg, BaseContainer& result);
	Bool ClearResults(const C4DUuid& jobUuid);
	Bool RemoveResult(const C4DUuid& jobUuid, const Filename& resResultPath);
	EDITION GetEdition() const;
	BaseContainer* GetNetPreferences() const;
	maxon::Result<void> CopyRenderTaskFrom(const C4DUuid& jobUuid, maxon::BaseArray<RenderTask>& todo);
};

NetRenderService* GetGlobalNetRenderService();

String GetMachineDescription(const NetRenderService* service, Machine* m);
String VerificationBitToString(VERIFICATIONBIT state);
String JobCommandToString(JOBCOMMAND command);
String JobStateToString(JOBSTATE state);
String GetDebugStringOfMachine(const Machine* m);

void SetErrorLevel(Bool printDebugErrors, Bool stackInErrors, Bool locationInErrors);

MESSAGERESULT NetSpecialEventAdd(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, Bool forceConnect = false);
MESSAGERESULT NetGeSyncMessage(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, BaseContainer& result, BaseThread* bt = nullptr, Bool forceConnect = false);
MESSAGERESULT NetSendData(NetRenderService* service, const C4DUuid& remoteUuid, NetRenderBuffer *data, NetRenderBuffer *result, BaseThread* bt = nullptr);

Bool NetSendMessageToServer(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, const String& messageString, Bool doConsoleOutput = false, Int32 frameNumber = NOTOK);
Bool NetSendMessageToServer(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, RENDERRESULT res, const String& messageString, Bool doConsoleOutput = false, Int32 frameNumber = NOTOK);

Bool NetRenderCacheGet(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, void* &data, Int32 &size);
Bool NetRenderCacheGetTask(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 &taskID, Int32 &taskSubdivisions);
Bool NetRenderCacheSendTask(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 taskID, void *data, Int32 size, Bool progress);
Bool NetRenderCacheProgress(NetRenderDocumentContext* context, Int32 cacheID, Int32 lastIndex, void* &data, Int32 &size, BaseThread* thread);
Bool NetRenderCachePrepass(NetRenderDocumentContext* context, Int32 cacheID, Bool &completed);
Bool NetRenderGetFileFromServer(NetRenderService* context, const Filename& sourcePathOrName, Filename& result, BaseThread* bt = nullptr);

namespace maxon
{
class ThreadInterface;
}

maxon::Result<void> NetRenderGetAssetFromServer(NetRenderService* service, const Filename& sourcePathOrName, Filename& result, SERVERMESSAGE raiseServerMessageIfNotFound, maxon::ThreadInterface* bt = nullptr);


//---------------------------------------------------
//	---INTERNAL STUFF

// Net Bucket Border Dimensions
#define NET_BUCKET_BORDER						4
#define NET_BUCKET_BORDER_2					8

// Net C4D Cache IDs (always register your own IDs to avoid potential conflicts)
#define NET_CACHE_ID_SSS_POINTS			0x1100
#define NET_CACHE_ID_SSS_IRRADIANCE	0x1101
//
#define NET_CACHE_ID_GI_COMPLETE		0x1200
#define NET_CACHE_ID_GI_PREPASS			0x1201
#define NET_CACHE_ID_GI_PASSES			0x1210 // All 16 are reserved
#define NET_CACHE_ID_GI_PROGRESS		0x1220 // All 16 are reserved
//
#define NET_CACHE_ID_AO_COMPLETE		0x1300
#define NET_CACHE_ID_AO_PREPASS			0x1301
#define NET_CACHE_ID_AO_PASSES			0x1310 // All 16 are reserved
#define NET_CACHE_ID_AO_PROGRESS		0x1320 // All 16 are reserved
//
#define NET_CACHE_ID_LM_COMPLETE		0x1400
#define NET_CACHE_ID_LM_PREPASS			0x1401
#define NET_CACHE_ID_LM_PASSES			0x1402
#define NET_CACHE_ID_LM_PROGRESS		0x1403
//
#define NET_CACHE_ID_RM_COMPLETE		0x1500
#define NET_CACHE_ID_RM_PREPASS			0x1501
#define NET_CACHE_ID_RM_PASSES			0x1502
#define NET_CACHE_ID_RM_PROGRESS		0x1503


struct NetRenderBuffer
{
	Int32									id;
	C4DUuid								job;
	Int32									size;
	void*									data;

	NetRenderBuffer() : id(0), job(DC), size(0), data(nullptr)
	{
	}

	void MoveTo(NetRenderBuffer& dst)
	{
		dst.id = id;
		dst.job = job;
		dst.size = size;
		dst.data = data;
		data = nullptr;
	}

	~NetRenderBuffer()
	{
		if (data)
			DeleteMem(data);
	}
};

struct NetRenderMsgBucketInfo
{
	NetRenderMsgBucketInfo() : weightData(false), bucketSize(0) { }

	Bool									weightData;
	Int32									bucketSize;
};

struct NetRenderMsgBucketIndex
{
	Int32									bucketID;
};

struct NetRenderMsgBucketStarted
{
	Int32									bucketID;

	Int32									regionX1;
	Int32									regionX2;
	Int32									regionY1;
	Int32									regionY2;
};

struct NetRenderMsgBucketFinished
{
	Int32									bucketID;

	Int32									offsetX;
	Int32									offsetY;
	Int32									sizeX;
	Int32									sizeY;
	Int32									borderX;
	Int32									borderY;

	Int32									tilex;
	Int32									tiley;
	Int32									passCount;

	Int32									bufferSize;
	Int32									fragmentsSize;
	Int32									weightMapSize;
	Int32									glowSize;
	Int32									lensDataSize;

	Float32*							buffer;
	UChar*								fragments;
	Bool*									weightMap;
	UChar*								glow;
	Float32*							lensData;
};

struct NetRenderMsgCacheGetCache
{
	Int32									cacheID;

	Bool									cacheValid;
	Int32									cacheSize;
	void*									cacheData;
};

struct NetRenderMsgCacheGetTask
{
	Int32									cacheID;

	Int32									taskID;
	Int32									taskSubdivisions;
};

struct NetRenderMsgCacheSendTask
{
	Int32									cacheID;

	Int32									taskID;
	Int32									taskSize;
	void*									taskData;
	Bool									taskProgress;
};

struct NetRenderMsgCacheProgress
{
	Int32									cacheID;
	Int32									lastIndex;
	BaseThread*						threadPtr;

	Int32									progressSize;
	void*									progressData;
};

struct NetRenderMsgCachePrepass
{
	Int32									cacheID;

	Bool									completed;
};

struct NetRenderDocumentContext
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(NetRenderDocumentContext);

	RenderJob*						_renderJob;
	NetRenderService*			_service;
	Bool									_singleImageDistribution;				// If true it's Distributed Rendering, otherwise Animation Rendering
	Int32									_cpuCount;
	Bool									_redistributed;
	Bool									_valid;
	Int32									_currentFrame;
	BaseThread*						_bt;
	NetRenderDocumentContext() : _renderJob(nullptr), _service(nullptr), _singleImageDistribution(false), _cpuCount(GeGetCurrentThreadCount()), _redistributed(false), _valid(true), _currentFrame(NOTOK), _bt(nullptr) { }
	~NetRenderDocumentContext() { _valid = false; }
	maxon::BaseArray<String>	_missingFiles;
	maxon::Spinlock						_missingFilesLock;
};

class iUser;

struct NetLibrary : public C4DLibrary
{
	JOBSTATE							(RenderJob::*RenderJobGetState)						() const;
	void									(RenderJob::*RenderJobSetState)						(JOBSTATE state, Bool sendSignal);
	const C4DUuid					(RenderJob::*RenderJobGetUuid)						() const;
	const C4DUuid					(RenderJob::*RenderJobGetCreatorUuid)			() const;
	void									(RenderJob::*RenderJobSetCreatorUuid)			(const C4DUuid& creatorUuid);
	const C4DUuid					(RenderJob::*RenderJobGetServerUuid)			() const;
	void									(RenderJob::*RenderJobSetServerUuid)			(const C4DUuid& serverUuid);
	NetRenderService*			(RenderJob::*GetNetRenderService)					() const;
	const NetRenderData*	(RenderJob::*GetRenderData)								() const;

	Bool									(RenderJob::*AddMachine)									(const C4DUuid& machineUuid);
	Bool									(RenderJob::*AddMachines)									(const maxon::BaseArray<C4DUuid>& machineUuids, Bool flush);
	Bool									(RenderJob::*RemoveMachine)								(const C4DUuid& machineUuid);
	Bool									(RenderJob::*ExRemoveMachines)						(const maxon::BaseArray<C4DUuid>& machineUuids);
	void									(RenderJob::*GetMachines)									(maxon::BaseArray<C4DUuid>& machineUuids) const;

	void									(RenderJob::*UpdateProgress)							(Float progress, Bool completed);

	const C4DUuid					(Machine::*GetUuid)												() const;
	void									(Machine::*SetUuid)												(const C4DUuid& uid);
	Vector								(Machine::*GetColor)											(const Vector* bgColor) const;
	void									(Machine::*SetColor)											(const Vector& color);
	void									(Machine::*FoundViaZeroConf)							(Bool foundViaZeroConf);
	Bool									(Machine::*FoundViaZeroConf2)							() const;
	OPERATINGSYSTEM				(Machine::*GetOperatingSystem)						();
	void									(Machine::*SetOperatingSystem)						(OPERATINGSYSTEM operatingSystem);
	const BaseContainer&	(Machine::*GetMachineFeatures)						() const;
	void									(Machine::*SetMachineFeatures)						(const BaseContainer& t_bc);
	JOBCOMMAND						(Machine::*GetCurrentJobCommand)					(C4DUuid* rendersFor) const;
	void									(Machine::*SetMacAddress)									(const maxon::BaseArray<UChar>& macAddress);
	void									(Machine::*GetMacAddress)									(maxon::BaseArray<UChar>& macAddress) const;
	String								(Machine::*GetFullyQualifiedDomainName)		(Bool* isPrivate) const;
	void									(Machine::*ClearVerificationBit)					(VERIFICATIONBIT state);
	Bool									(Machine::*GetVerificationBit)						(VERIFICATIONBIT state) const;
	void									(Machine::*SetVerificationBit)						(VERIFICATIONBIT state);
	Bool									(Machine::*GetGlobalSelected)							() const;
	void									(Machine::*SetGlobalSelected)							(Bool globalSelected);

	Machine*							(NetRenderService::*FindMachine)						(const C4DUuid& uid, MACHINELIST list, VERIFICATIONBIT bits) const;
	MachineGroup*					(NetRenderService::*ExGetOnlineHead)					() const;
	MachineGroup*					(NetRenderService::*GetMachineHead)					() const;
	Machine*							(NetRenderService::*ExGetFirstOnline)				() const;
	Machine*							(NetRenderService::*GetFirstMachine)				() const;
	maxon::RWSpinlock&		(NetRenderService::*GetMachineLock)					();
	void									(NetRenderService::*GetAllMachineUuids)			(maxon::BaseArray<C4DUuid>& machineUuids, MACHINELIST list, VERIFICATIONBIT bits, Bool includeLocalMachine, Bool includeZeroConfMachines);
	RenderJob*						(NetRenderService::*FindRenderJob)					(const C4DUuid& jobUuid, Bool lookInServerList) const;
	const C4DUuid					(NetRenderService::*GetUuid2)								() const;
	void									(NetRenderService::*GetMacAddress2)					(maxon::BaseArray<UChar>& macAddress) const;
	Int32									(NetRenderService::*ExGetInternalPort)			() const;
	Int32									(NetRenderService::*ExGetExternalPort)			() const;
	String								(NetRenderService::*ExGetHostname)					() const;
	void									(NetRenderService::*CopyClientTasksFrom)		(maxon::BaseArray<C4DUuid>& jobUuids, maxon::BaseArray<Task>& tasks) const;
	Repository&						(NetRenderService::*GetRepository)					();
	maxon::RWSpinlock&		(NetRenderService::*GetClientRenderJobLock)	();
	RENDERRESULT					(NetRenderService::*InitRendering)					(BaseDocument* doc, const BaseContainer& rdata, const C4DUuid& jobUuid, NETRENDERFLAGS flags, PictureViewer* pv, const BaseContainer& machines, MultipassBitmap* bmp, ProgressHook* prog, WriteProgressHook* wprog, void* context, Bool* useFrameNumberAsSuffix, Filename* dispname, const maxon::BaseArray<Bool>* renderTasks);
	CREATEJOBRESULT				(NetRenderService::*CreateRenderJob)				(const String& docName, C4DUuid& jobUuid, RENDERJOBCREATOR creator, const String& username, BaseThread* bt, const Filename* watchFolderName);
	RENDERRESULT					(NetRenderService::*StartRendering)					(THREADMODE mode, BaseDocument* doc, const C4DUuid& jobUuid, BaseThread* bt);
	Bool									(NetRenderService::*VerifyServerOnClient)		(THREADMODE mode, const C4DUuid& machineUuid, const String& securityToken, Bool setClientAsGlobalSelected, Bool doLock, Int32 waitUntilExecutionInMs);
	Bool									(NetRenderService::*DeleteRenderJob)				(const C4DUuid& jobUuid, Bool informClients);
	Bool									(NetRenderService::*GetGlobalSelected2)			(maxon::BaseArray<C4DUuid>& machines);
	UserPool&							(NetRenderService::*GetUserPool)						();
	Bool									(NetRenderService::*GetJobsList1)						(maxon::BaseArray<BaseContainer>& jobs, Bool triggerWatchDog, DETAILSELECTOR rdata, DETAILSELECTOR assets, DETAILSELECTOR results, DETAILSELECTOR log, const C4DUuid* getOnlyThisJob, Bool selectedJobOnly, const C4DUuid* user);
	void									(NetRenderService::*GetGlobalSelectedMachines)(maxon::BaseArray<C4DUuid>& machines, Bool& atLeastOneMachineOnline);

	String								(NetRenderService::*GetCurrentJobCommandAsString)	() const;

	MESSAGERESULT					(*NetSpecialEventAdd)												(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, Bool forceConnect);
	MESSAGERESULT					(*NetGeSyncMessage)													(NetRenderService* service, const C4DUuid& remoteUuid, const BaseContainer& msg, BaseContainer& result, BaseThread* bt, Bool forceConnect);
	MESSAGERESULT					(*NetSendData)															(NetRenderService* service, const C4DUuid& remoteUuid, NetRenderBuffer *data, NetRenderBuffer *result, BaseThread* bt);

	Bool									(*NetRenderCacheGet)												(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, void* &data, Int32 &size);
	Bool									(*NetRenderCacheGetTask)										(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 &taskID, Int32 &taskSubdivisions);
	Bool									(*NetRenderCacheSendTask)										(NetRenderDocumentContext* context, Bool isServer, Int32 cacheID, Int32 taskID, void *data, Int32 size, Bool progress);
	Bool									(*NetRenderCacheProgress)										(NetRenderDocumentContext* context, Int32 cacheID, Int32 lastIndex, void* &data, Int32 &size, BaseThread* thread);
	Bool									(*NetRenderCachePrepass)										(NetRenderDocumentContext* context, Int32 cacheID, Bool &completed);
	Bool									(*NetRenderGetFileFromServer)								(NetRenderService* client, const Filename& sourceNameOrPath, Filename& result, BaseThread* bt);

	NetRenderService*			(*GetGlobalNetRenderService)								();
	String								(*GetMachineDescription)										(const NetRenderService* service, Machine* m);
	String								(*VerificationBitToString)									(VERIFICATIONBIT state);
	String								(*JobCommandToString)												(JOBCOMMAND command);
	String								(*GetDebugStringOfMachine)									(const Machine* m);

	Filename							(Repository::*GetRepositoryPath)						() const;
	Filename							(Repository::*GetJobsPath)									(Bool server) const;
	void									(Repository::*SetRepositoryPath)						(const Filename& repositoryPath);
	Bool									(Repository::*ConvertAbsolute2RelativePath)	(const Filename &absolutePath, RelativeFilename &relativePath, Bool server) const;
	Filename							(Repository::*ConvertRelative2Absolute)			(RenderJob* job, Asset* asset) const;

	RenderJob*						(NetRenderService::*GetActive)							() const;
	RelativeFilename			(RenderJob::*GetProjectFolder)							() const;
	Asset*								(RenderJob::*GetFirstAsset)									() const;

	Bool									(UserPool::*AddUser)												(const String& username, const String& password, const String& description, Bool isAdmin);
	Bool									(UserPool::*DeleteUser)											(const C4DUuid& userUuid);
	Bool									(UserPool::*ChangePassword)									(const C4DUuid& userUuid, const String& oldPassword, const String& newPassword);
	Bool									(UserPool::*CheckUserCredentials)						(const String& username, const String& password) const;
	void									(UserPool::*GetUsers)												(maxon::BaseArray<User*>& users) const;

	ProgressHook*					(RenderJob::*GetProgressHook)								(void*& context);
	WriteProgressHook*		(RenderJob::*GetWriteProgressHook)					(void*& context);
	String								(NetRenderService::*GetName)								() const;
	Bool									(NetRenderService::*IsRunning)							() const;

	String								(NetRenderData::*GetName2)										() const;
	Bool									(NetRenderData::*IsSingleFrameRendering)			() const;
	Int32									(NetRenderData::*GetRealFps)									() const;
	Float									(NetRenderData::*GetFps)											() const;
	BaseTime							(NetRenderData::*GetFrameFrom)								() const;
	BaseTime							(NetRenderData::*GetFrameTo)									() const;
	Int32									(NetRenderData::*GetWidth)										() const;
	Int32									(NetRenderData::*GetHeight)										() const;
	Int32									(NetRenderData::*GetFrameRange)								() const;
	Int32									(NetRenderData::*GetNameFormat)								() const;
	Int32									(NetRenderData::*GetFrameStep)								() const;
	BaseContainer					(NetRenderData::*GetData)											() const;
	Bool									(NetRenderData::*UseFrameNumberAsSuffix)			() const;
	Bool									(NetRenderData::*ShowHud)											() const;
	Bool									(NetRenderData::*SaveImage)										() const;
	Int32									(NetRenderData::*GetImageFormat)							() const;
	Filename							(NetRenderData::*GetImageFilename)						() const;
	Filename							(NetRenderData::*GetImageAbsResultFolder)			() const;
	Bool									(NetRenderData::*GetImageFormatIsMovie)				() const;
	Bool									(NetRenderData::*SaveMultipass)								() const;
	Int32									(NetRenderData::*GetMultipassImageFormat)			() const;
	Filename							(NetRenderData::*GetMultipassFilename)				() const;
	Filename							(NetRenderData::*GetMultipassAbsResultFolder)	() const;
	Bool									(NetRenderData::*GetMultipassFormatIsMovie) 	() const;
	Bool									(NetRenderData::*GetMultipassSaveMultilayer)	() const;
	Bool									(NetRenderData::*ShowTextureError)						() const;
	NETRENDERFLAGS				(NetRenderData::*GetFlags)										() const;
	Filename							(NetRenderData::*GetB3dTempFolder)						() const;

	void									(NetRenderService::*NetConsoleOutput)					(maxon::OUTPUT flags, const maxon::String& value, maxon::OUTPUTLOCATION output, const maxon::SourceLocation& loc);

	C4DUuid								(iUser::*GetUserUuid)																() const;
	String								(iUser::*GetUserUsername)														() const;
	String								(iUser::*GetUserDescription)												() const;
	Bool									(iUser::*IsUserAdmin)																() const;
	String								(iUser::*GetUserDefaultLanguage)										() const;

	Bool									(UserPool::*ChangeDefaultLanguage)									(const C4DUuid& userUuid, const String& defaultLanguage);
	Bool									(UserPool::*ExGetUser)															(const String& username);

	User*									(*UserAlloc)																				();
	void									(*UserFree)																					(User*& p);


	Bool									(NetRenderService::*GetMachinesList)									(maxon::BaseArray<BaseContainer>& jobs, Int32 logCount, const C4DUuid* getOnlyThisMachine) const;
	Bool									(NetRenderService::*InitAndStartRenderingFullAsync)	(const C4DUuid& jobUuid);
	void									(NetRenderService::*StopRendering)									(THREADMODE mode, const C4DUuid& jobUuid, RENDERRESULT result);
	Bool									(NetRenderService::*InsertJobBefore)								(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2);
	Bool									(NetRenderService::*InsertJobAfter)									(const C4DUuid& jobUuid1, const C4DUuid& jobUuid2);
	Bool									(NetRenderService::*SetDefaultSceneName)						(const C4DUuid& jobUuid, const Filename& defaultSceneName);

	Bool									(UserPool::*ChangeUserAccountType)									(const C4DUuid& userUuid, const Bool isAdmin);
	Bool									(UserPool::*ChangeUserInfo)													(const C4DUuid& userUuid, const String& description);
	Bool									(UserPool::*ChangeUserPassword)											(const C4DUuid& userUuid, const String& password);

	void									(RenderJob::*RenderJobSetDefaultSceneName)					(const Filename& defaultSceneName);
	Filename							(RenderJob::*RenderJobGetDefaultSceneName)					() const;
	Bool									(NetRenderService::*Message)												(const C4DUuid& remoteUuid, const NetworkIpAddrPort* remoteAddr, Bool isPrivate, const BaseContainer& msg, BaseContainer& result);
	Bool									(NetRenderService::*ClearResults)										(const C4DUuid& jobUuid);
	EDITION								(NetRenderService::*GetEdition)											() const;
	String								(*JobStateToString)																	(JOBSTATE state);

	maxon::Result<void>		(*NetRenderGetFileFromServer2)											(NetRenderService* client, const Filename& sourceNameOrPath, Filename& result, SERVERMESSAGE sendWarningIfFailed, maxon::ThreadInterface* bt);

	Bool									(NetRenderService::*AddLogToJob)										(const C4DUuid& jobUuid, const String& log, Bool doLock, Bool append);
	BaseBitmap*						(NetRenderService::*ExGetRenderPreview)							(const C4DUuid& jobUuid); // PRIVATE
	Bool									(*NetSendMessageToServer)														(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, const String& messageString, Bool doConsoleOutput , Int32 frameNumber);
	BaseContainer*				(NetRenderService::*GetNetPreferences)							() const;
	Bool									(NetRenderService::*AddLogToMachine)								(const C4DUuid& machineUuid, const String& log, Bool doLock);
	Bool									(NetRenderService::*GetJobsList2)										(const BaseContainer& settings, maxon::BaseArray<BaseContainer>& jobs, Bool triggerWatchDog, DETAILSELECTOR rdata, DETAILSELECTOR assets, DETAILSELECTOR results, DETAILSELECTOR log, const C4DUuid* getOnlyThisJob, Bool selectedJobOnly, const C4DUuid* user);

	void									(*SetErrorLevel)																		(Bool printDebugErrors, Bool stackInErrors, Bool locationInErrors);
	Bool									(NetRenderService::*AddMachine2)										(const String& address, const String& securityToken, Bool allowGui, const C4DUuid* uuidOfMachineToOverwrite);
	Filename							(NetRenderData::*GetOriginDocumentDirectoryPath)		() const;
	BaseContainer&				(NetRenderData::*GetData2)													();
	const BaseContainer&	(NetRenderData::*GetData3)													() const;
	RENDERRESULT					(RenderJob::*RenderJobGetRenderResult)							() const;
	Int32									(NetRenderData::*GetRealImageBitDepth)							() const;
	Int32									(NetRenderData::*GetRealMultipassBitDepth)					() const;
	Bool									(*NetSendMessageToServer2)													(NetRenderService* service, const C4DUuid& remoteUuid, const C4DUuid& jobUuid, SERVERMESSAGE type, RENDERRESULT res, const String& messageString, Bool doConsoleOutput, Int32 frameNumber);
	Bool									(NetRenderService::*RemoveResult)										(const C4DUuid& jobUuid, const Filename& relResultPath);

	maxon::Result<void>		(NetRenderService::*CopyRenderTaskFrom)							(const C4DUuid& jobUuid, maxon::BaseArray<RenderTask>& todo);
	EDITION								(Machine::*GetEdition2)															() const;
	Int32									(NetRenderService::*GetCpuCount)										() const;
};

#endif // LIB_NET_H__
