// This file contains default implementations for the interfaces of system_process.h. They are intended for copy&paste usage only.

class MySystemProcessKilledErrorImpl : public maxon::Component<MySystemProcessKilledErrorImpl, SystemProcessKilledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MySystemProcessOperationErrorImpl : public maxon::Component<MySystemProcessOperationErrorImpl, SystemProcessOperationErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MySystemProcessObjectImpl : public maxon::Component<MySystemProcessObjectImpl, SystemProcessObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> StartProcess()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> KillProcess()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Int GetExitCode() const
	{
		return 0;
	}

	MAXON_METHOD Bool IsRunning() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD UInt GetProcessId() const
	{
		return 0;
	}

	MAXON_METHOD void* GetProcessHandle() const
	{
		return nullptr;
	}

	MAXON_METHOD Url GetProcessUrl() const
	{
		return HXXRET3(NULLIMPL, Url);
	}

	MAXON_METHOD Url GetLogFile() const
	{
		return HXXRET3(NULLIMPL, Url);
	}

	MAXON_METHOD void* GetUserData() const
	{
		return nullptr;
	}

	MAXON_METHOD Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProcessFinishedDelegate> ObservableProcessFinished(Bool create) const
	{
		return maxon::ObservableRef<ObservableProcessFinishedDelegate>::DefaultValue();
	}

};
