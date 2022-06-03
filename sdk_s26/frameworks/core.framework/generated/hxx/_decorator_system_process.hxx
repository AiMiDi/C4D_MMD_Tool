// This file contains decorator implementations for the interfaces of system_process.h. They are intended for copy&paste usage only.

class SystemProcessKilledErrorDecoratorImpl : public maxon::Component<SystemProcessKilledErrorDecoratorImpl, SystemProcessKilledErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class SystemProcessOperationErrorDecoratorImpl : public maxon::Component<SystemProcessOperationErrorDecoratorImpl, SystemProcessOperationErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class SystemProcessObjectDecoratorImpl : public maxon::Component<SystemProcessObjectDecoratorImpl, SystemProcessObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> StartProcess()
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).StartProcess();
	}

	MAXON_METHOD Result<void> KillProcess()
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).KillProcess();
	}

	MAXON_METHOD Int GetExitCode() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetExitCode();
	}

	MAXON_METHOD Bool IsRunning() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).IsRunning();
	}

	MAXON_METHOD UInt GetProcessId() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetProcessId();
	}

	MAXON_METHOD void* GetProcessHandle() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetProcessHandle();
	}

	MAXON_METHOD Url GetProcessUrl() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetProcessUrl();
	}

	MAXON_METHOD Url GetLogFile() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetLogFile();
	}

	MAXON_METHOD void* GetUserData() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetUserData();
	}

	MAXON_METHOD Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).GetLoadedDlls(dlls);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableProcessFinishedDelegate> ObservableProcessFinished() const
	{
		return maxon::Cast<SystemProcessObjectRef>(self.GetDecoratedObject()).ObservableProcessFinished();
	}

};
