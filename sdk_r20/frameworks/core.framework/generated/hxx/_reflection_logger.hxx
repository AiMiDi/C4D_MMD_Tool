#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_LoggerTypeInterface(LoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class LoggerTypeInterface::ProxyComponent : public maxon::Component<LoggerTypeInterface::ProxyComponent, LoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<LoggerTypeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Write_Offset), maxon::reflection::Argument::ByReference(str), maxon::reflection::Argument::ByReference(loc), maxon::reflection::Argument::ByValue(level)};
			(*handler_)(_fn_LoggerTypeInterface_Write, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, const SourceLocation&, WRITEMETA>::Invoke, (const void*) mt_._LoggerTypeInterface_Write));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_Write;
		Result<void> Flush() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<LoggerTypeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_Flush_Offset)};
			(*handler_)(_fn_LoggerTypeInterface_Flush, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._LoggerTypeInterface_Flush));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_Flush;
		maxon::ObservableRef<ObservableLoggerNotifyDelegate> ObservableLoggerNotify() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<LoggerTypeInterface>();
			maxon::ObservableRef<ObservableLoggerNotifyDelegate> proxy_result = maxon::ObservableRef<ObservableLoggerNotifyDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LoggerTypeInterface_ObservableLoggerNotify_Offset)};
			(*handler_)(_fn_LoggerTypeInterface_ObservableLoggerNotify, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableLoggerNotifyDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._LoggerTypeInterface_ObservableLoggerNotify));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_ObservableLoggerNotify;
	};
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_Write;
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_Flush;
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_ObservableLoggerNotify;
	PRIVATE_MAXON_COMPONENT_REGISTER(LoggerTypeInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_LoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 84LL, LoggerTypeInterface, _LoggerTypeInterface_Write),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 0LL, LoggerTypeInterface, _LoggerTypeInterface_Flush),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 0LL, LoggerTypeInterface, _LoggerTypeInterface_ObservableLoggerNotify),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_LoggerTypeInterface(nullptr, &LoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_LoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FileLoggerTypeInterface(FileLoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class FileLoggerTypeInterface::ProxyComponent : public maxon::Component<FileLoggerTypeInterface::ProxyComponent, FileLoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const Url& url) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<FileLoggerTypeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileLoggerTypeInterface_Init_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_FileLoggerTypeInterface_Init, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._FileLoggerTypeInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileLoggerTypeInterface_Init;
		Url GetUrl() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<FileLoggerTypeInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileLoggerTypeInterface_GetUrl_Offset)};
			(*handler_)(_fn_FileLoggerTypeInterface_GetUrl, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Url, const maxon::GenericComponent*>::Invoke, (const void*) mt_._FileLoggerTypeInterface_GetUrl));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileLoggerTypeInterface_GetUrl;
	};
	const maxon::reflection::Function* FileLoggerTypeInterface::ProxyComponent::_fn_FileLoggerTypeInterface_Init;
	const maxon::reflection::Function* FileLoggerTypeInterface::ProxyComponent::_fn_FileLoggerTypeInterface_GetUrl;
	PRIVATE_MAXON_COMPONENT_REGISTER(FileLoggerTypeInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_FileLoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 4LL, FileLoggerTypeInterface, _FileLoggerTypeInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 0LL, FileLoggerTypeInterface, _FileLoggerTypeInterface_GetUrl),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileLoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_FileLoggerTypeInterface(nullptr, &FileLoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_FileLoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UserLoggerTypeInterface(UserLoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UserLoggerTypeInterface::ProxyComponent : public maxon::Component<UserLoggerTypeInterface::ProxyComponent, UserLoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<UserLoggerTypeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Iterate_Offset), maxon::reflection::Argument::ByReference(callback)};
			(*handler_)(_fn_UserLoggerTypeInterface_Iterate, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Delegate<Result<void>(LoggerLine&)>&>::Invoke, (const void*) mt_._UserLoggerTypeInterface_Iterate));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_Iterate;
		Int GetCount() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<UserLoggerTypeInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_GetCount_Offset)};
			(*handler_)(_fn_UserLoggerTypeInterface_GetCount, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Int, maxon::GenericComponent*>::Invoke, (const void*) mt_._UserLoggerTypeInterface_GetCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_GetCount;
		void Reset() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<UserLoggerTypeInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._UserLoggerTypeInterface_Reset_Offset)};
			(*handler_)(_fn_UserLoggerTypeInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._UserLoggerTypeInterface_Reset));
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_Reset;
	};
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_Iterate;
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_GetCount;
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_Reset;
	PRIVATE_MAXON_COMPONENT_REGISTER(UserLoggerTypeInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UserLoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 4LL, UserLoggerTypeInterface, _UserLoggerTypeInterface_Iterate),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 0LL, UserLoggerTypeInterface, _UserLoggerTypeInterface_GetCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 0LL, UserLoggerTypeInterface, _UserLoggerTypeInterface_Reset),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UserLoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_UserLoggerTypeInterface(nullptr, &UserLoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_UserLoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_LoggerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_AddLoggerType)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 84LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_RemoveLoggerType)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_RemoveLoggerTypes)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_Write)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 340LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_GetName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_SetName)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_Enable)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_IsEnabled)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_GetLoggerTypes)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_ObservableLoggerNew)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LoggerInterface::MTable::_instance._LoggerInterface_AddNewLogger)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 16LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LoggerInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_LoggerInterface("net.maxon.interface.logger", nullptr, &RegisterReflection_LoggerInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(LoggerTypes);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(Loggers);
#endif
}
#endif
