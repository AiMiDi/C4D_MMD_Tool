#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_LoggerTypeInterface(LoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::LoggerTypeRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class LoggerTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, LoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, LoggerTypeInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LoggerTypeInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Write_Offset), maxon::reflection::Argument::ByReference(str), maxon::reflection::Argument::ByReference(loc), maxon::reflection::Argument::ByValue(level)};
			(*handler_)(_fn_LoggerTypeInterface_Write, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const String&, const SourceLocation&, WRITEMETA), reinterpret_cast<const void* const&>(mt_.LoggerTypeInterface_Write)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_Write;
		Result<void> Flush() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LoggerTypeInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_Flush_Offset)};
			(*handler_)(_fn_LoggerTypeInterface_Flush, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.LoggerTypeInterface_Flush)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_Flush;
		maxon::ObservableRef<ObservableLoggerNotifyDelegate> ObservableLoggerNotify(Bool create) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LoggerTypeInterface>();
			maxon::ObservableRef<ObservableLoggerNotifyDelegate> proxy_result = maxon::ObservableRef<ObservableLoggerNotifyDelegate>::DefaultValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LoggerTypeInterface_ObservableLoggerNotify_Offset), maxon::reflection::Argument::ByValue(create)};
			(*handler_)(_fn_LoggerTypeInterface_ObservableLoggerNotify, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((maxon::ObservableRef<ObservableLoggerNotifyDelegate>), Bool), reinterpret_cast<const void* const&>(mt_.LoggerTypeInterface_ObservableLoggerNotify)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LoggerTypeInterface_ObservableLoggerNotify;
	};
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_Write;
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_Flush;
	const maxon::reflection::Function* LoggerTypeInterface::ProxyComponent::_fn_LoggerTypeInterface_ObservableLoggerNotify;
	PRIVATE_MAXON_COMPONENT_REGISTER(LoggerTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_LoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "str\0loc\0level\0", 21LL, LoggerTypeInterface, LoggerTypeInterface_Write),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, LoggerTypeInterface, LoggerTypeInterface_Flush),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "create\0", 0LL, LoggerTypeInterface, LoggerTypeInterface_ObservableLoggerNotify),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_LoggerTypeInterface(nullptr, &LoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_LoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FileLoggerTypeInterface(FileLoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::FileLoggerTypeRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class FileLoggerTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, FileLoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, FileLoggerTypeInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const Url& url) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileLoggerTypeInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_Init_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_FileLoggerTypeInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const Url&), reinterpret_cast<const void* const&>(mt_.FileLoggerTypeInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileLoggerTypeInterface_Init;
		Url GetUrl() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileLoggerTypeInterface>();
			Url proxy_result = HXXRET3(NULLIMPL, Url);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileLoggerTypeInterface_GetUrl_Offset)};
			(*handler_)(_fn_FileLoggerTypeInterface_GetUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Url)), reinterpret_cast<const void* const&>(mt_.FileLoggerTypeInterface_GetUrl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileLoggerTypeInterface_GetUrl;
	};
	const maxon::reflection::Function* FileLoggerTypeInterface::ProxyComponent::_fn_FileLoggerTypeInterface_Init;
	const maxon::reflection::Function* FileLoggerTypeInterface::ProxyComponent::_fn_FileLoggerTypeInterface_GetUrl;
	PRIVATE_MAXON_COMPONENT_REGISTER(FileLoggerTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_FileLoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0", 1LL, FileLoggerTypeInterface, FileLoggerTypeInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FileLoggerTypeInterface, FileLoggerTypeInterface_GetUrl),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileLoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_FileLoggerTypeInterface(nullptr, &FileLoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_FileLoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UserLoggerTypeInterface(UserLoggerTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::UserLoggerTypeRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class UserLoggerTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, UserLoggerTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, UserLoggerTypeInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<UserLoggerTypeInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Iterate_Offset), maxon::reflection::Argument::ByReference(callback)};
			(*handler_)(_fn_UserLoggerTypeInterface_Iterate, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const Delegate<Result<void>(LoggerLine&)>&), reinterpret_cast<const void* const&>(mt_.UserLoggerTypeInterface_Iterate)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_Iterate;
		Int GetCount() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<UserLoggerTypeInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_GetCount_Offset)};
			(*handler_)(_fn_UserLoggerTypeInterface_GetCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.UserLoggerTypeInterface_GetCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_GetCount;
		void Reset() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<UserLoggerTypeInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.UserLoggerTypeInterface_Reset_Offset)};
			(*handler_)(_fn_UserLoggerTypeInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.UserLoggerTypeInterface_Reset)));
		}
		static const maxon::reflection::Function* _fn_UserLoggerTypeInterface_Reset;
	};
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_Iterate;
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_GetCount;
	const maxon::reflection::Function* UserLoggerTypeInterface::ProxyComponent::_fn_UserLoggerTypeInterface_Reset;
	PRIVATE_MAXON_COMPONENT_REGISTER(UserLoggerTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_UserLoggerTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "callback\0", 1LL, UserLoggerTypeInterface, UserLoggerTypeInterface_Iterate),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, UserLoggerTypeInterface, UserLoggerTypeInterface_GetCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, UserLoggerTypeInterface, UserLoggerTypeInterface_Reset),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UserLoggerTypeInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_UserLoggerTypeInterface(nullptr, &UserLoggerTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_UserLoggerTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LoggerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_AddLoggerType)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ta\0loggerTypeCls\0cb\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_RemoveLoggerType)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "loggerType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_RemoveLoggerTypes)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "loggerTypeCls\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_Write)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ta\0str\0loc\0level\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_GetName)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_SetName)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_Enable)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "enable\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_IsEnabled)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_GetLoggerTypes)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_ObservableLoggerNew)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LoggerInterface::MTable::_instance.LoggerInterface_AddNewLogger)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "id\0logger\0module\0", 16LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LoggerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
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
