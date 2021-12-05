#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaSessionProgressInterface(MediaSessionProgressInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaSessionProgressRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaSessionProgressInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaSessionProgressInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaSessionProgressInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_InitProgress_Offset), maxon::reflection::Argument::ByReference(delayFirstProgress), maxon::reflection::Argument::ByReference(minProgressUpdate)};
			(*handler_)(_fn_MediaSessionProgressInterface_InitProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const TimeValue&, const TimeValue&>::Invoke, (const void*) mt_._MediaSessionProgressInterface_InitProgress));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_InitProgress;
		Result<Int> AddProgressJob(const Float jobWeight, const String& jobName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			Result<Int> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_AddProgressJob_Offset), maxon::reflection::Argument::ByValue(jobWeight), maxon::reflection::Argument::ByReference(jobName)};
			(*handler_)(_fn_MediaSessionProgressInterface_AddProgressJob, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Int>, maxon::GenericComponent*, const Float, const String&>::Invoke, (const void*) mt_._MediaSessionProgressInterface_AddProgressJob));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_AddProgressJob;
		Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset), maxon::reflection::Argument::ByValue(jobIndex), maxon::reflection::Argument::ByValue(percent)};
			(*handler_)(_fn_MediaSessionProgressInterface_SetProgressAndCheckBreak, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, Float>::Invoke, (const void*) mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_SetProgressAndCheckBreak;
		Result<Float> GetProgress(Int jobIndex) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			Result<Float> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_GetProgress_Offset), maxon::reflection::Argument::ByValue(jobIndex)};
			(*handler_)(_fn_MediaSessionProgressInterface_GetProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Float>, maxon::GenericComponent*, Int>::Invoke, (const void*) mt_._MediaSessionProgressInterface_GetProgress));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_GetProgress;
		maxon::ObservableRef<ObservableProgressNotificationDelegate> ObservableProgressNotification() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			maxon::ObservableRef<ObservableProgressNotificationDelegate> proxy_result = maxon::ObservableRef<ObservableProgressNotificationDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_ObservableProgressNotification_Offset)};
			(*handler_)(_fn_MediaSessionProgressInterface_ObservableProgressNotification, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableProgressNotificationDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaSessionProgressInterface_ObservableProgressNotification));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_ObservableProgressNotification;
		Float GetTotalWeight() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionProgressInterface>();
			Float proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_GetTotalWeight_Offset)};
			(*handler_)(_fn_MediaSessionProgressInterface_GetTotalWeight, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaSessionProgressInterface_GetTotalWeight));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionProgressInterface_GetTotalWeight;
	};
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_InitProgress;
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_AddProgressJob;
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_SetProgressAndCheckBreak;
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_GetProgress;
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_ObservableProgressNotification;
	const maxon::reflection::Function* MediaSessionProgressInterface::ProxyComponent::_fn_MediaSessionProgressInterface_GetTotalWeight;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaSessionProgressInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaSessionProgressInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "delayFirstProgress\0minProgressUpdate\0", 5LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_InitProgress),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobWeight\0jobName\0", 1LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_AddProgressJob),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobIndex\0percent\0", 5LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_SetProgressAndCheckBreak),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobIndex\0", 1LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_GetProgress),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_ObservableProgressNotification),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaSessionProgressInterface, _MediaSessionProgressInterface_GetTotalWeight),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaSessionProgressInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaSessionProgressInterface(nullptr, &MediaSessionProgressInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaSessionProgressInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
