#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(INTERACTIONTYPE, "maxon::INTERACTIONTYPE", "net.maxon.command.interationtype", SIZEOF(INTERACTIONTYPE), false, "NONE\0START\0ITERATE\0END\0REALTIME\0", const maxon::UInt64 values[] = {(maxon::UInt64) INTERACTIONTYPE::NONE, (maxon::UInt64) INTERACTIONTYPE::START, (maxon::UInt64) INTERACTIONTYPE::ITERATE, (maxon::UInt64) INTERACTIONTYPE::END, (maxon::UInt64) INTERACTIONTYPE::REALTIME})
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandDataInterface(CommandDataInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandDataRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandDataInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandDataInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandDataInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandDataInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandDataInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandDataInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandDataInterface(nullptr, &CommandDataInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandDataInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_LegacyCommandDataInterface(LegacyCommandDataInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::LegacyCommandDataRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class LegacyCommandDataInterface::ProxyComponent : public maxon::Component<ProxyComponent, LegacyCommandDataInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, LegacyCommandDataInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Generic*> GetLegacyData(Int index) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LegacyCommandDataInterface>();
			Result<Generic*> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_GetLegacyData_Offset), maxon::reflection::Argument::ByValue(index)};
			(*handler_)(_fn_LegacyCommandDataInterface_GetLegacyData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Generic*>), Int), reinterpret_cast<const void* const&>(mt_.LegacyCommandDataInterface_GetLegacyData)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LegacyCommandDataInterface_GetLegacyData;
		Result<void> SetLegacyData(const Generic* data, Int index) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LegacyCommandDataInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_SetLegacyData_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(index)};
			(*handler_)(_fn_LegacyCommandDataInterface_SetLegacyData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const Generic*, Int), reinterpret_cast<const void* const&>(mt_.LegacyCommandDataInterface_SetLegacyData)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LegacyCommandDataInterface_SetLegacyData;
		Int GetLegacyDataCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LegacyCommandDataInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_GetLegacyDataCount_Offset)};
			(*handler_)(_fn_LegacyCommandDataInterface_GetLegacyDataCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.LegacyCommandDataInterface_GetLegacyDataCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LegacyCommandDataInterface_GetLegacyDataCount;
	};
	const maxon::reflection::Function* LegacyCommandDataInterface::ProxyComponent::_fn_LegacyCommandDataInterface_GetLegacyData;
	const maxon::reflection::Function* LegacyCommandDataInterface::ProxyComponent::_fn_LegacyCommandDataInterface_SetLegacyData;
	const maxon::reflection::Function* LegacyCommandDataInterface::ProxyComponent::_fn_LegacyCommandDataInterface_GetLegacyDataCount;
	PRIVATE_MAXON_COMPONENT_REGISTER(LegacyCommandDataInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_LegacyCommandDataInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "index\0", 1LL, LegacyCommandDataInterface, LegacyCommandDataInterface_GetLegacyData),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "data\0index\0", 5LL, LegacyCommandDataInterface, LegacyCommandDataInterface_SetLegacyData),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, LegacyCommandDataInterface, LegacyCommandDataInterface_GetLegacyDataCount),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LegacyCommandDataInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_LegacyCommandDataInterface(nullptr, &LegacyCommandDataInterface::ProxyComponent::_descriptor, &RegisterReflection_LegacyCommandDataInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandClassInterface(CommandClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<COMMANDSTATE> GetState(CommandDataRef& data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandClassInterface>();
			Result<COMMANDSTATE> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandClassInterface_GetState_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_CommandClassInterface_GetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<COMMANDSTATE>), CommandDataRef&), reinterpret_cast<const void* const&>(mt_.CommandClassInterface_GetState)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandClassInterface_GetState;
		Result<COMMANDRESULT> Execute(CommandDataRef& data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandClassInterface>();
			Result<COMMANDRESULT> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandClassInterface_Execute_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_CommandClassInterface_Execute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<COMMANDRESULT>), CommandDataRef&), reinterpret_cast<const void* const&>(mt_.CommandClassInterface_Execute)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandClassInterface_Execute;
	};
	const maxon::reflection::Function* CommandClassInterface::ProxyComponent::_fn_CommandClassInterface_GetState;
	const maxon::reflection::Function* CommandClassInterface::ProxyComponent::_fn_CommandClassInterface_Execute;
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 3LL, CommandClassInterface, CommandClassInterface_GetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 3LL, CommandClassInterface, CommandClassInterface_Execute),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandClassInterface(nullptr, &CommandClassInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandInteractionClassInterface(CommandInteractionClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandInteractionClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandInteractionClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandInteractionClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandInteractionClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandInteractionClassInterface>();
			Result<COMMANDRESULT> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandInteractionClassInterface_Interact_Offset), maxon::reflection::Argument::ByReference(data), maxon::reflection::Argument::ByValue(interactionType)};
			(*handler_)(_fn_CommandInteractionClassInterface_Interact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<COMMANDRESULT>), CommandDataRef&, INTERACTIONTYPE), reinterpret_cast<const void* const&>(mt_.CommandInteractionClassInterface_Interact)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandInteractionClassInterface_Interact;
	};
	const maxon::reflection::Function* CommandInteractionClassInterface::ProxyComponent::_fn_CommandInteractionClassInterface_Interact;
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandInteractionClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandInteractionClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0interactionType\0", 7LL, CommandInteractionClassInterface, CommandInteractionClassInterface_Interact),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandInteractionClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandInteractionClassInterface(nullptr, &CommandInteractionClassInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandInteractionClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandDescriptionClassInterface(CommandDescriptionClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandDescriptionClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandDescriptionClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandDescriptionClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandDescriptionClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandDescriptionClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandDescriptionClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandDescriptionClassInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandDescriptionClassInterface(nullptr, &CommandDescriptionClassInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandDescriptionClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_LegacyCommandClassInterface(LegacyCommandClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::LegacyCommandClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class LegacyCommandClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, LegacyCommandClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, LegacyCommandClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ConvertSettings(LegacyCommandDataRef& data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<LegacyCommandClassInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandClassInterface_ConvertSettings_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_LegacyCommandClassInterface_ConvertSettings, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), LegacyCommandDataRef&), reinterpret_cast<const void* const&>(mt_.LegacyCommandClassInterface_ConvertSettings)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_LegacyCommandClassInterface_ConvertSettings;
	};
	const maxon::reflection::Function* LegacyCommandClassInterface::ProxyComponent::_fn_LegacyCommandClassInterface_ConvertSettings;
	PRIVATE_MAXON_COMPONENT_REGISTER(LegacyCommandClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_LegacyCommandClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 3LL, LegacyCommandClassInterface, LegacyCommandClassInterface_ConvertSettings),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LegacyCommandClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_LegacyCommandClassInterface(nullptr, &LegacyCommandClassInterface::ProxyComponent::_descriptor, &RegisterReflection_LegacyCommandClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MigratedCommandClassInterface(MigratedCommandClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MigratedCommandClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MigratedCommandClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, MigratedCommandClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MigratedCommandClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Int32 GetMigratedCommandId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MigratedCommandClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MigratedCommandClassInterface_GetMigratedCommandId_Offset)};
			(*handler_)(_fn_MigratedCommandClassInterface_GetMigratedCommandId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.MigratedCommandClassInterface_GetMigratedCommandId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MigratedCommandClassInterface_GetMigratedCommandId;
	};
	const maxon::reflection::Function* MigratedCommandClassInterface::ProxyComponent::_fn_MigratedCommandClassInterface_GetMigratedCommandId;
	PRIVATE_MAXON_COMPONENT_REGISTER(MigratedCommandClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MigratedCommandClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MigratedCommandClassInterface, MigratedCommandClassInterface_GetMigratedCommandId),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MigratedCommandClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MigratedCommandClassInterface(nullptr, &MigratedCommandClassInterface::ProxyComponent::_descriptor, &RegisterReflection_MigratedCommandClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandConversionClassInterface(CommandConversionClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandConversionClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandConversionClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandConversionClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandConversionClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ConvertInput(LegacyCommandDataRef& data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandConversionClassInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ConvertInput_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_CommandConversionClassInterface_ConvertInput, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), LegacyCommandDataRef&), reinterpret_cast<const void* const&>(mt_.CommandConversionClassInterface_ConvertInput)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandConversionClassInterface_ConvertInput;
		Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandConversionClassInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ExecuteCustomActions_Offset), maxon::reflection::Argument::ByReference(data), maxon::reflection::Argument::ByValue(actionId), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_CommandConversionClassInterface_ExecuteCustomActions, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), LegacyCommandDataRef&, Int, Int), reinterpret_cast<const void* const&>(mt_.CommandConversionClassInterface_ExecuteCustomActions)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandConversionClassInterface_ExecuteCustomActions;
		Result<void> ConvertOutput(LegacyCommandDataRef& data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandConversionClassInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ConvertOutput_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_CommandConversionClassInterface_ConvertOutput, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), LegacyCommandDataRef&), reinterpret_cast<const void* const&>(mt_.CommandConversionClassInterface_ConvertOutput)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandConversionClassInterface_ConvertOutput;
		Int32 GetLegacyCommandId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandConversionClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_GetLegacyCommandId_Offset)};
			(*handler_)(_fn_CommandConversionClassInterface_GetLegacyCommandId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CommandConversionClassInterface_GetLegacyCommandId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandConversionClassInterface_GetLegacyCommandId;
		Id GetCommandId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandConversionClassInterface>();
			Id proxy_result = maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_GetCommandId_Offset)};
			(*handler_)(_fn_CommandConversionClassInterface_GetCommandId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Id)), reinterpret_cast<const void* const&>(mt_.CommandConversionClassInterface_GetCommandId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandConversionClassInterface_GetCommandId;
	};
	const maxon::reflection::Function* CommandConversionClassInterface::ProxyComponent::_fn_CommandConversionClassInterface_ConvertInput;
	const maxon::reflection::Function* CommandConversionClassInterface::ProxyComponent::_fn_CommandConversionClassInterface_ExecuteCustomActions;
	const maxon::reflection::Function* CommandConversionClassInterface::ProxyComponent::_fn_CommandConversionClassInterface_ConvertOutput;
	const maxon::reflection::Function* CommandConversionClassInterface::ProxyComponent::_fn_CommandConversionClassInterface_GetLegacyCommandId;
	const maxon::reflection::Function* CommandConversionClassInterface::ProxyComponent::_fn_CommandConversionClassInterface_GetCommandId;
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandConversionClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandConversionClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 0LL, CommandConversionClassInterface, CommandConversionClassInterface_ConvertInput),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0actionId\0flags\0", 0LL, CommandConversionClassInterface, CommandConversionClassInterface_ExecuteCustomActions),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 0LL, CommandConversionClassInterface, CommandConversionClassInterface_ConvertOutput),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CommandConversionClassInterface, CommandConversionClassInterface_GetLegacyCommandId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CommandConversionClassInterface, CommandConversionClassInterface_GetCommandId),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandConversionClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandConversionClassInterface(nullptr, &CommandConversionClassInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandConversionClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandCacheInterface(CommandCacheInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandCacheRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandCacheInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandCacheInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandCacheInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(CommandDataRef& data) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandCacheInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Init_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_CommandCacheInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), CommandDataRef&), reinterpret_cast<const void* const&>(mt_.CommandCacheInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandCacheInterface_Init;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandCacheInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Reset_Offset)};
			(*handler_)(_fn_CommandCacheInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.CommandCacheInterface_Reset)));
		}
		static const maxon::reflection::Function* _fn_CommandCacheInterface_Reset;
	};
	const maxon::reflection::Function* CommandCacheInterface::ProxyComponent::_fn_CommandCacheInterface_Init;
	const maxon::reflection::Function* CommandCacheInterface::ProxyComponent::_fn_CommandCacheInterface_Reset;
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandCacheInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandCacheInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "data\0", 0LL, CommandCacheInterface, CommandCacheInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CommandCacheInterface, CommandCacheInterface_Reset),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandCacheInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandCacheInterface(nullptr, &CommandCacheInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandCacheInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CommandExecutionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(CommandExecutionInterface::MTable::_instance.CommandExecutionInterface_Invoke)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "command\0data\0interactive\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CommandExecutionInterface::MTable::_instance.CommandExecutionInterface_Invoke_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "command\0data\0interactive\0setParameters\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CommandExecutionInterface::MTable::_instance.CommandExecutionInterface_Interact)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0interactionType\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandExecutionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CommandExecutionInterface("net.maxon.command.interface.execution", nullptr, &RegisterReflection_CommandExecutionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandDataClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(LegacyCommandDataClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(LegacyCommand);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(MigratedCommand);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandInteraction);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandDescription);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandConversionClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CommandCacheClasses);
#endif
}
#endif
