#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ProgressInterface(ProgressInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ProgressRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ProgressInterface::ProxyComponent : public maxon::Component<ProxyComponent, ProgressInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ProgressInterface>::_Wrapper;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_InitProgress_Offset), maxon::reflection::Argument::ByReference(delayFirstProgress), maxon::reflection::Argument::ByReference(minProgressUpdate)};
			(*handler_)(_fn_ProgressInterface_InitProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const TimeValue&, const TimeValue&>::Invoke, (const void*) mt_.ProgressInterface_InitProgress));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_InitProgress;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<Int> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_AddProgressJob_Offset), maxon::reflection::Argument::ByValue(jobWeight), maxon::reflection::Argument::ByReference(jobName)};
			(*handler_)(_fn_ProgressInterface_AddProgressJob, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Int>, maxon::GenericComponent*, const Float, const String&>::Invoke, (const void*) mt_.ProgressInterface_AddProgressJob));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_AddProgressJob;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset), maxon::reflection::Argument::ByValue(jobIndex), maxon::reflection::Argument::ByValue(percent)};
			(*handler_)(_fn_ProgressInterface_SetProgressAndCheckBreak, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, Float>::Invoke, (const void*) mt_.ProgressInterface_SetProgressAndCheckBreak));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_SetProgressAndCheckBreak;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<Float> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetProgress_Offset), maxon::reflection::Argument::ByValue(jobIndex)};
			(*handler_)(_fn_ProgressInterface_GetProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Float>, maxon::GenericComponent*, Int>::Invoke, (const void*) mt_.ProgressInterface_GetProgress));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_GetProgress;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Float proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTotalWeight_Offset)};
			(*handler_)(_fn_ProgressInterface_GetTotalWeight, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_GetTotalWeight));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_GetTotalWeight;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			maxon::ObservableRef<ObservableProgressNotificationDelegate> proxy_result = maxon::ObservableRef<ObservableProgressNotificationDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_ObservableProgressNotification_Offset)};
			(*handler_)(_fn_ProgressInterface_ObservableProgressNotification, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableProgressNotificationDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_ObservableProgressNotification));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_ObservableProgressNotification;
		Result<Tuple<TimeValue, TimeValue>> GetTime() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<Tuple<TimeValue, TimeValue>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTime_Offset)};
			(*handler_)(_fn_ProgressInterface_GetTime, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Tuple<TimeValue, TimeValue>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_GetTime));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_GetTime;
		String GetDetailsText() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetDetailsText_Offset)};
			(*handler_)(_fn_ProgressInterface_GetDetailsText, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_GetDetailsText));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_GetDetailsText;
		void SetDetailsText(const String& details) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetDetailsText_Offset), maxon::reflection::Argument::ByReference(details)};
			(*handler_)(_fn_ProgressInterface_SetDetailsText, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_.ProgressInterface_SetDetailsText));
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_SetDetailsText;
		Bool SupportsCancelJob() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SupportsCancelJob_Offset)};
			(*handler_)(_fn_ProgressInterface_SupportsCancelJob, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_SupportsCancelJob));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_SupportsCancelJob;
		Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetCancelJobDelegate_Offset), maxon::reflection::Argument::ByReference(cancelJobDelegate)};
			(*handler_)(_fn_ProgressInterface_SetCancelJobDelegate, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, JobCancelDelegate&&>::Invoke, (const void*) mt_.ProgressInterface_SetCancelJobDelegate));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_SetCancelJobDelegate;
		Result<void> CancelJob() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_CancelJob_Offset)};
			(*handler_)(_fn_ProgressInterface_CancelJob, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_CancelJob));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_CancelJob;
		Bool IsCancelled() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ProgressInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_IsCancelled_Offset)};
			(*handler_)(_fn_ProgressInterface_IsCancelled, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*>::Invoke, (const void*) mt_.ProgressInterface_IsCancelled));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ProgressInterface_IsCancelled;
	};
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_InitProgress;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_AddProgressJob;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_SetProgressAndCheckBreak;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_GetProgress;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_GetTotalWeight;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_ObservableProgressNotification;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_GetTime;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_GetDetailsText;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_SetDetailsText;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_SupportsCancelJob;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_SetCancelJobDelegate;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_CancelJob;
	const maxon::reflection::Function* ProgressInterface::ProxyComponent::_fn_ProgressInterface_IsCancelled;
	PRIVATE_MAXON_COMPONENT_REGISTER(ProgressInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ProgressInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "delayFirstProgress\0minProgressUpdate\0", 5LL, ProgressInterface, ProgressInterface_InitProgress),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobWeight\0jobName\0", 1LL, ProgressInterface, ProgressInterface_AddProgressJob),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobIndex\0percent\0", 5LL, ProgressInterface, ProgressInterface_SetProgressAndCheckBreak),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "jobIndex\0", 1LL, ProgressInterface, ProgressInterface_GetProgress),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_GetTotalWeight),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_ObservableProgressNotification),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_GetTime),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_GetDetailsText),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "details\0", 1LL, ProgressInterface, ProgressInterface_SetDetailsText),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_SupportsCancelJob),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "cancelJobDelegate\0", 1LL, ProgressInterface, ProgressInterface_SetCancelJobDelegate),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_CancelJob),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, ProgressInterface, ProgressInterface_IsCancelled),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ProgressInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ProgressInterface(nullptr, &ProgressInterface::ProxyComponent::_descriptor, &RegisterReflection_ProgressInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
