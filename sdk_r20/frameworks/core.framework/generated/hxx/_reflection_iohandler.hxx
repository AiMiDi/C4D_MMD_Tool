#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IoHandlerInterface(IoHandlerInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class IoHandlerInterface::ProxyComponent : public maxon::Component<IoHandlerInterface::ProxyComponent, IoHandlerInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const Id& GetUrlScheme() const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			const Id* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_GetUrlScheme_Offset)};
			(*handler_)(_fn_IoHandlerInterface_GetUrlScheme, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<const Id&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoHandlerInterface_GetUrlScheme));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_GetUrlScheme;
		Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_SetSystemPath_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByReference(systemPath)};
			(*handler_)(_fn_IoHandlerInterface_SetSystemPath, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, UrlInterface&, const String&>::Invoke, (const void*) mt_._IoHandlerInterface_SetSystemPath));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_SetSystemPath;
		Result<String> GetSystemPath(const UrlInterface& url) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<String> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_GetSystemPath_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_IoHandlerInterface_GetSystemPath, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<String>, const maxon::GenericComponent*, const UrlInterface&>::Invoke, (const void*) mt_._IoHandlerInterface_GetSystemPath));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_GetSystemPath;
		Result<void> AppendUrl(UrlInterface& url, const String& name) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_AppendUrl_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByReference(name)};
			(*handler_)(_fn_IoHandlerInterface_AppendUrl, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, UrlInterface&, const String&>::Invoke, (const void*) mt_._IoHandlerInterface_AppendUrl));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_AppendUrl;
		Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_AppendUrl_1_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByReference(relativeUrl)};
			(*handler_)(_fn_IoHandlerInterface_AppendUrl_1, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, UrlInterface&, const Url&>::Invoke, (const void*) mt_._IoHandlerInterface_AppendUrl_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_AppendUrl_1;
		Result<void> RemoveUrl(UrlInterface& url) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_RemoveUrl_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_IoHandlerInterface_RemoveUrl, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, UrlInterface&>::Invoke, (const void*) mt_._IoHandlerInterface_RemoveUrl));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_RemoveUrl;
		Result<IoConnectionRef> OpenConnection(const Url& name) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<IoConnectionRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_OpenConnection_Offset), maxon::reflection::Argument::ByReference(name)};
			(*handler_)(_fn_IoHandlerInterface_OpenConnection, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<IoConnectionRef>, const maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._IoHandlerInterface_OpenConnection));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_OpenConnection;
		Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<Url> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_Normalize_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoHandlerInterface_Normalize, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<Url>, const maxon::GenericComponent*, const Url&, NORMALIZEFLAGS>::Invoke, (const void*) mt_._IoHandlerInterface_Normalize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_Normalize;
		Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<IoHandlerInterface>();
			Result<Url> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_IoNormalize_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoHandlerInterface_IoNormalize, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<Url>, const maxon::GenericComponent*, const Url&, NORMALIZEFLAGS>::Invoke, (const void*) mt_._IoHandlerInterface_IoNormalize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoHandlerInterface_IoNormalize;
	};
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_GetUrlScheme;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_SetSystemPath;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_GetSystemPath;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_AppendUrl;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_AppendUrl_1;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_RemoveUrl;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_OpenConnection;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_Normalize;
	const maxon::reflection::Function* IoHandlerInterface::ProxyComponent::_fn_IoHandlerInterface_IoNormalize;
	PRIVATE_MAXON_COMPONENT_REGISTER(IoHandlerInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_IoHandlerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 0LL, IoHandlerInterface, _IoHandlerInterface_GetUrlScheme),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 24LL, IoHandlerInterface, _IoHandlerInterface_SetSystemPath),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 4LL, IoHandlerInterface, _IoHandlerInterface_GetSystemPath),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 28LL, IoHandlerInterface, _IoHandlerInterface_AppendUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 28LL, IoHandlerInterface, _IoHandlerInterface_AppendUrl_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 12LL, IoHandlerInterface, _IoHandlerInterface_RemoveUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 4LL, IoHandlerInterface, _IoHandlerInterface_OpenConnection),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 16LL, IoHandlerInterface, _IoHandlerInterface_Normalize),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 16LL, IoHandlerInterface, _IoHandlerInterface_IoNormalize),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoHandlerInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_IoHandlerInterface(nullptr, &IoHandlerInterface::ProxyComponent::_descriptor, &RegisterReflection_IoHandlerInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(IoHandlers);
#endif
}
#endif
