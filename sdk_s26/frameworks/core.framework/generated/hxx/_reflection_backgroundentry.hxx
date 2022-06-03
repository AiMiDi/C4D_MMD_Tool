#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_BackgroundEntryInterface(BackgroundEntryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::BackgroundEntryRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class BackgroundEntryInterface::ProxyComponent : public maxon::Component<ProxyComponent, BackgroundEntryInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, BackgroundEntryInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		String GetName() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetName_Offset)};
			(*handler_)(_fn_BackgroundEntryInterface_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetName));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetName;
		UniversalDateTime GetStartTime() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			UniversalDateTime proxy_result = maxon::PrivateIncompleteNullReturnValue<UniversalDateTime>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStartTime_Offset)};
			(*handler_)(_fn_BackgroundEntryInterface_GetStartTime, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UniversalDateTime, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetStartTime));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetStartTime;
		TimeValue GetDuration() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			TimeValue proxy_result = maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetDuration_Offset)};
			(*handler_)(_fn_BackgroundEntryInterface_GetDuration, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<TimeValue, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetDuration));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetDuration;
		STATE GetState() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			STATE proxy_result = maxon::PrivateIncompleteNullReturnValue<STATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset)};
			(*handler_)(_fn_BackgroundEntryInterface_GetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<STATE, maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetState));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetState;
		Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStates_Offset), maxon::reflection::Argument::ByReference(state)};
			(*handler_)(_fn_BackgroundEntryInterface_GetStates, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, const maxon::GenericComponent*, const ValueReceiver<STATE, const String&>&>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetStates));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetStates;
		Int GetStateCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStateCount_Offset)};
			(*handler_)(_fn_BackgroundEntryInterface_GetStateCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundEntryInterface_GetStateCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_GetStateCount;
		Result<void> AddState(STATE state, const String& message) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundEntryInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset), maxon::reflection::Argument::ByValue(state), maxon::reflection::Argument::ByReference(message)};
			(*handler_)(_fn_BackgroundEntryInterface_AddState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, STATE, const String&>::Invoke, (const void*) mt_.BackgroundEntryInterface_AddState));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundEntryInterface_AddState;
	};
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetName;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetStartTime;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetDuration;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetState;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetStates;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_GetStateCount;
	const maxon::reflection::Function* BackgroundEntryInterface::ProxyComponent::_fn_BackgroundEntryInterface_AddState;
	PRIVATE_MAXON_COMPONENT_REGISTER(BackgroundEntryInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_BackgroundEntryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundEntryInterface, BackgroundEntryInterface_GetName),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundEntryInterface, BackgroundEntryInterface_GetStartTime),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundEntryInterface, BackgroundEntryInterface_GetDuration),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, BackgroundEntryInterface, BackgroundEntryInterface_GetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "state\0", 1LL, BackgroundEntryInterface, BackgroundEntryInterface_GetStates),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundEntryInterface, BackgroundEntryInterface_GetStateCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0message\0", 5LL, BackgroundEntryInterface, BackgroundEntryInterface_AddState),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BackgroundEntryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_BackgroundEntryInterface(nullptr, &BackgroundEntryInterface::ProxyComponent::_descriptor, &RegisterReflection_BackgroundEntryInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_BackgroundProgressInterface(BackgroundProgressInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::BackgroundProgressRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class BackgroundProgressInterface::ProxyComponent : public maxon::Component<ProxyComponent, BackgroundProgressInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, BackgroundProgressInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<BackgroundProgressRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), maxon::reflection::Argument::ByReference(title), maxon::reflection::Argument::ByValue(sendToHistory)};
			(*handler_)(_fn_BackgroundProgressInterface_AddActiveEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BackgroundProgressRef>, maxon::GenericComponent*, const String&, Bool>::Invoke, (const void*) mt_.BackgroundProgressInterface_AddActiveEntry));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_AddActiveEntry;
		Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), maxon::reflection::Argument::ByReference(entry)};
			(*handler_)(_fn_BackgroundProgressInterface_RemoveActiveEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BackgroundProgressRef&>::Invoke, (const void*) mt_.BackgroundProgressInterface_RemoveActiveEntry));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_RemoveActiveEntry;
		Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveEntries_Offset), maxon::reflection::Argument::ByReference(entry)};
			(*handler_)(_fn_BackgroundProgressInterface_GetActiveEntries, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, const maxon::GenericComponent*, const ValueReceiver<const BackgroundProgressRef&>&>::Invoke, (const void*) mt_.BackgroundProgressInterface_GetActiveEntries));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_GetActiveEntries;
		Int GetActiveCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveCount_Offset)};
			(*handler_)(_fn_BackgroundProgressInterface_GetActiveCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundProgressInterface_GetActiveCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_GetActiveCount;
		Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset), maxon::reflection::Argument::ByReference(entry)};
			(*handler_)(_fn_BackgroundProgressInterface_GetHistoryEntries, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, const maxon::GenericComponent*, const ValueReceiver<const BackgroundEntryRef&>&>::Invoke, (const void*) mt_.BackgroundProgressInterface_GetHistoryEntries));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_GetHistoryEntries;
		Int GetHistoryCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryCount_Offset)};
			(*handler_)(_fn_BackgroundProgressInterface_GetHistoryCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundProgressInterface_GetHistoryCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_GetHistoryCount;
		Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), maxon::reflection::Argument::ByReference(entry)};
			(*handler_)(_fn_BackgroundProgressInterface_RemoveHistoryEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BackgroundEntryRef&>::Invoke, (const void*) mt_.BackgroundProgressInterface_RemoveHistoryEntry));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_RemoveHistoryEntry;
		Result<void> ClearHistory() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset)};
			(*handler_)(_fn_BackgroundProgressInterface_ClearHistory, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundProgressInterface_ClearHistory));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_ClearHistory;
		maxon::ObservableRef<ObservableStateChangedDelegate> ObservableStateChanged() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			maxon::ObservableRef<ObservableStateChangedDelegate> proxy_result = maxon::ObservableRef<ObservableStateChangedDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset)};
			(*handler_)(_fn_BackgroundProgressInterface_ObservableStateChanged, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableStateChangedDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundProgressInterface_ObservableStateChanged));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_ObservableStateChanged;
		maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> ObservableTotalProgressNotification() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BackgroundProgressInterface>();
			maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> proxy_result = maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset)};
			(*handler_)(_fn_BackgroundProgressInterface_ObservableTotalProgressNotification, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_.BackgroundProgressInterface_ObservableTotalProgressNotification));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BackgroundProgressInterface_ObservableTotalProgressNotification;
	};
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_AddActiveEntry;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_RemoveActiveEntry;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_GetActiveEntries;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_GetActiveCount;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_GetHistoryEntries;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_GetHistoryCount;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_RemoveHistoryEntry;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_ClearHistory;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_ObservableStateChanged;
	const maxon::reflection::Function* BackgroundProgressInterface::ProxyComponent::_fn_BackgroundProgressInterface_ObservableTotalProgressNotification;
	PRIVATE_MAXON_COMPONENT_REGISTER(BackgroundProgressInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_BackgroundProgressInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BackgroundProgressInterface::Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BackgroundProgressInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_BackgroundProgressInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "title\0sendToHistory\0", 5LL, BackgroundProgressInterface, BackgroundProgressInterface_AddActiveEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "entry\0", 1LL, BackgroundProgressInterface, BackgroundProgressInterface_RemoveActiveEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "entry\0", 1LL, BackgroundProgressInterface, BackgroundProgressInterface_GetActiveEntries),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundProgressInterface, BackgroundProgressInterface_GetActiveCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "entry\0", 1LL, BackgroundProgressInterface, BackgroundProgressInterface_GetHistoryEntries),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundProgressInterface, BackgroundProgressInterface_GetHistoryCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "entry\0", 1LL, BackgroundProgressInterface, BackgroundProgressInterface_RemoveHistoryEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, BackgroundProgressInterface, BackgroundProgressInterface_ClearHistory),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundProgressInterface, BackgroundProgressInterface_ObservableStateChanged),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BackgroundProgressInterface, BackgroundProgressInterface_ObservableTotalProgressNotification),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BackgroundProgressInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_BackgroundProgressInterface(nullptr, &BackgroundProgressInterface::ProxyComponent::_descriptor, &RegisterReflection_BackgroundProgressInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_BackgroundProgressInterface_Static("net.maxon.interface.backgroundprogress", nullptr, &RegisterReflection_BackgroundProgressInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
