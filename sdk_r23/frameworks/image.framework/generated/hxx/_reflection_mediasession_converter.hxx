#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaConverterInterface(MediaConverterInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaConverterRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaConverterInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaConverterInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaConverterInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Bool SupportImportStrategy() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_SupportImportStrategy_Offset)};
			(*handler_)(_fn_MediaConverterInterface_SupportImportStrategy, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaConverterInterface_SupportImportStrategy));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_SupportImportStrategy;
		Bool SupportExportStrategy() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_SupportExportStrategy_Offset)};
			(*handler_)(_fn_MediaConverterInterface_SupportExportStrategy, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaConverterInterface_SupportExportStrategy));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_SupportExportStrategy;
		Result<BaseArray<MediaConverterRef>> GetInputConverter() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<BaseArray<MediaConverterRef>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_GetInputConverter_Offset)};
			(*handler_)(_fn_MediaConverterInterface_GetInputConverter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<MediaConverterRef>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaConverterInterface_GetInputConverter));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_GetInputConverter;
		Result<void> AddOutputStream(const MediaStreamRef& stream) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_AddOutputStream_Offset), maxon::reflection::Argument::ByReference(stream)};
			(*handler_)(_fn_MediaConverterInterface_AddOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamRef&>::Invoke, (const void*) mt_._MediaConverterInterface_AddOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_AddOutputStream;
		Result<void> RemoveOutputStream(const MediaStreamRef& stream) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_RemoveOutputStream_Offset), maxon::reflection::Argument::ByReference(stream)};
			(*handler_)(_fn_MediaConverterInterface_RemoveOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamRef&>::Invoke, (const void*) mt_._MediaConverterInterface_RemoveOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_RemoveOutputStream;
		Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<BaseArray<MediaStreamRef>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_GetOutputStreams_Offset), maxon::reflection::Argument::ByValue(flattenChildren)};
			(*handler_)(_fn_MediaConverterInterface_GetOutputStreams, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<MediaStreamRef>>, const maxon::GenericComponent*, Bool>::Invoke, (const void*) mt_._MediaConverterInterface_GetOutputStreams));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_GetOutputStreams;
		Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Analyze_Offset), maxon::reflection::Argument::ByReference(inputs), maxon::reflection::Argument::ByReference(targetTime), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_MediaConverterInterface_Analyze, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const MediaConverterRef>&, const TimeValue&, MEDIASESSIONFLAGS>::Invoke, (const void*) mt_._MediaConverterInterface_Analyze));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_Analyze;
		Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_PrepareExecute_Offset), maxon::reflection::Argument::ByReference(inputs), maxon::reflection::Argument::ByReference(targetTime), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_MediaConverterInterface_PrepareExecute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const MediaConverterRef>&, const TimeValue&, MEDIASESSIONFLAGS>::Invoke, (const void*) mt_._MediaConverterInterface_PrepareExecute));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_PrepareExecute;
		Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Execute_Offset), maxon::reflection::Argument::ByReference(inputs), maxon::reflection::Argument::ByReference(targetTime), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_MediaConverterInterface_Execute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const MediaConverterRef>&, const TimeValue&, MEDIASESSIONFLAGS>::Invoke, (const void*) mt_._MediaConverterInterface_Execute));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_Execute;
		Result<void> Close(const Block<const MediaConverterRef>& inputs) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaConverterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Close_Offset), maxon::reflection::Argument::ByReference(inputs)};
			(*handler_)(_fn_MediaConverterInterface_Close, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const MediaConverterRef>&>::Invoke, (const void*) mt_._MediaConverterInterface_Close));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaConverterInterface_Close;
	};
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_SupportImportStrategy;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_SupportExportStrategy;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_GetInputConverter;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_AddOutputStream;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_RemoveOutputStream;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_GetOutputStreams;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_Analyze;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_PrepareExecute;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_Execute;
	const maxon::reflection::Function* MediaConverterInterface::ProxyComponent::_fn_MediaConverterInterface_Close;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaConverterInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaConverterInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaConverterInterface, _MediaConverterInterface_SupportImportStrategy),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaConverterInterface, _MediaConverterInterface_SupportExportStrategy),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaConverterInterface, _MediaConverterInterface_GetInputConverter),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stream\0", 0LL, MediaConverterInterface, _MediaConverterInterface_AddOutputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stream\0", 0LL, MediaConverterInterface, _MediaConverterInterface_RemoveOutputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "flattenChildren\0", 1LL, MediaConverterInterface, _MediaConverterInterface_GetOutputStreams),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputs\0targetTime\0flags\0", 21LL, MediaConverterInterface, _MediaConverterInterface_Analyze),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputs\0targetTime\0flags\0", 21LL, MediaConverterInterface, _MediaConverterInterface_PrepareExecute),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputs\0targetTime\0flags\0", 21LL, MediaConverterInterface, _MediaConverterInterface_Execute),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputs\0", 1LL, MediaConverterInterface, _MediaConverterInterface_Close),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaConverterInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaConverterInterface(nullptr, &MediaConverterInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaConverterInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaConverterErrorInterface(MediaConverterErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaConverterError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaConverterErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaConverterErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaConverterErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaConverterErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaConverterErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaConverterErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaConverterErrorInterface(nullptr, &MediaConverterErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaConverterErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
