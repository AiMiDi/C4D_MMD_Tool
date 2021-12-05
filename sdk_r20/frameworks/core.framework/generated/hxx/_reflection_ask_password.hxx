#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_AskPasswordInterface(AskPasswordInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class AskPasswordInterface::ProxyComponent : public maxon::Component<AskPasswordInterface::ProxyComponent, AskPasswordInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<String> AskPasswordFromUser(const String& text) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<AskPasswordInterface>();
			Result<String> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AskPasswordInterface_AskPasswordFromUser_Offset), maxon::reflection::Argument::ByReference(text)};
			(*handler_)(_fn_AskPasswordInterface_AskPasswordFromUser, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<String>, const maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._AskPasswordInterface_AskPasswordFromUser));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_AskPasswordInterface_AskPasswordFromUser;
	};
	const maxon::reflection::Function* AskPasswordInterface::ProxyComponent::_fn_AskPasswordInterface_AskPasswordFromUser;
	PRIVATE_MAXON_COMPONENT_REGISTER(AskPasswordInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_AskPasswordInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 4LL, AskPasswordInterface, _AskPasswordInterface_AskPasswordFromUser),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&AskPasswordInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_AskPasswordInterface(nullptr, &AskPasswordInterface::ProxyComponent::_descriptor, &RegisterReflection_AskPasswordInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_AskPasswordMethod(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(AskPasswordMethod::MTable::_instance._AskPasswordMethod_Set)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(AskPasswordMethod::MTable::_instance._AskPasswordMethod_Get)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&AskPasswordMethod::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_AskPasswordMethod("net.maxon.interface.askpasswordmethod", nullptr, &RegisterReflection_AskPasswordMethod, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
