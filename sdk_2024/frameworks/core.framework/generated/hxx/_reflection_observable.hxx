#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FunctionBaseInterface(FunctionBaseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::FunctionBaseRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class FunctionBaseInterface::ProxyComponent : public maxon::Component<ProxyComponent, FunctionBaseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, FunctionBaseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset), maxon::reflection::Argument::ByValue(forwardFunction), maxon::reflection::Argument::ByReference(function)};
			(*handler_)(_fn_FunctionBaseInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const ObservableForwardFunction, DelegateBase&&), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_Init;
		Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset), maxon::reflection::Argument::ByValue(forwardFunction), maxon::reflection::Argument::ByReference(function), maxon::reflection::Argument::ByReference(queue)};
			(*handler_)(_fn_FunctionBaseInterface_Init_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const ObservableForwardFunction, DelegateBase&&, const JobQueueRef&), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_Init_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_Init_1;
		void Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset), maxon::reflection::Argument::ByValue(owner), maxon::reflection::Argument::ByValue(observer)};
			(*handler_)(_fn_FunctionBaseInterface_Set, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), ObserverObjectInterface*, ObserverObjectInterface*), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_Set)));
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_Set;
		void GetOwner(ObserverObjectRef& res) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetOwner_Offset), maxon::reflection::Argument::ByReference(res)};
			(*handler_)(_fn_FunctionBaseInterface_GetOwner, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), ObserverObjectRef&), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_GetOwner)));
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_GetOwner;
		void GetObserver(ObserverObjectRef& res) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserver_Offset), maxon::reflection::Argument::ByReference(res)};
			(*handler_)(_fn_FunctionBaseInterface_GetObserver, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), ObserverObjectRef&), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_GetObserver)));
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_GetObserver;
		const void* GetObserverPointer() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			const void* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserverPointer_Offset)};
			(*handler_)(_fn_FunctionBaseInterface_GetObserverPointer, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const void*)), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_GetObserverPointer)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_GetObserverPointer;
		Result<Data> Execute(const Block<const ConstDataPtr>& args) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FunctionBaseInterface>();
			Result<Data> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset), maxon::reflection::Argument::ByReference(args)};
			(*handler_)(_fn_FunctionBaseInterface_Execute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Data>), const Block<const ConstDataPtr>&), reinterpret_cast<const void* const&>(mt_.FunctionBaseInterface_Execute)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FunctionBaseInterface_Execute;
	};
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_Init;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_Init_1;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_Set;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_GetOwner;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_GetObserver;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_GetObserverPointer;
	const maxon::reflection::Function* FunctionBaseInterface::ProxyComponent::_fn_FunctionBaseInterface_Execute;
	PRIVATE_MAXON_COMPONENT_REGISTER(FunctionBaseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_FunctionBaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "forwardFunction\0function\0", 5LL, FunctionBaseInterface, FunctionBaseInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "forwardFunction\0function\0queue\0", 21LL, FunctionBaseInterface, FunctionBaseInterface_Init_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "owner\0observer\0", 5LL, FunctionBaseInterface, FunctionBaseInterface_Set),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "res\0", 0LL, FunctionBaseInterface, FunctionBaseInterface_GetOwner),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "res\0", 0LL, FunctionBaseInterface, FunctionBaseInterface_GetObserver),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FunctionBaseInterface, FunctionBaseInterface_GetObserverPointer),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "args\0", 1LL, FunctionBaseInterface, FunctionBaseInterface_Execute),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FunctionBaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_FunctionBaseInterface(nullptr, &FunctionBaseInterface::ProxyComponent::_descriptor, &RegisterReflection_FunctionBaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CombinerInterface(CombinerInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CombinerRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CombinerInterface::ProxyComponent : public maxon::Component<ProxyComponent, CombinerInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CombinerInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InitCombine(Result<Data>& combinedRes) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CombinerInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CombinerInterface_InitCombine_Offset), maxon::reflection::Argument::ByReference(combinedRes)};
			(*handler_)(_fn_CombinerInterface_InitCombine, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Result<Data>&), reinterpret_cast<const void* const&>(mt_.CombinerInterface_InitCombine)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CombinerInterface_InitCombine;
		Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CombinerInterface>();
			Result<Bool> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CombinerInterface_CombineResult_Offset), maxon::reflection::Argument::ByReference(combinedRes), maxon::reflection::Argument::ByReference(newRes)};
			(*handler_)(_fn_CombinerInterface_CombineResult, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), Result<Data>&, Result<Data>&&), reinterpret_cast<const void* const&>(mt_.CombinerInterface_CombineResult)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CombinerInterface_CombineResult;
	};
	const maxon::reflection::Function* CombinerInterface::ProxyComponent::_fn_CombinerInterface_InitCombine;
	const maxon::reflection::Function* CombinerInterface::ProxyComponent::_fn_CombinerInterface_CombineResult;
	PRIVATE_MAXON_COMPONENT_REGISTER(CombinerInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CombinerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "combinedRes\0", 2LL, CombinerInterface, CombinerInterface_InitCombine),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "combinedRes\0newRes\0", 7LL, CombinerInterface, CombinerInterface_CombineResult),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CombinerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CombinerInterface(nullptr, &CombinerInterface::ProxyComponent::_descriptor, &RegisterReflection_CombinerInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ObservableBaseInterface(ObservableBaseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ObservableBaseRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ObservableBaseInterface::ProxyComponent : public maxon::Component<ProxyComponent, ObservableBaseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ObservableBaseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(ObserverObjectInterface* owner, const Id& observableName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset), maxon::reflection::Argument::ByValue(owner), maxon::reflection::Argument::ByReference(observableName)};
			(*handler_)(_fn_ObservableBaseInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), ObserverObjectInterface*, const Id&), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_Init;
		Id GetObservableId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Id proxy_result = HXXRET3(NULLIMPL, Id);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObservableId_Offset)};
			(*handler_)(_fn_ObservableBaseInterface_GetObservableId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Id)), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_GetObservableId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_GetObservableId;
		void PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_PrivateDisconnectAll_Offset), maxon::reflection::Argument::ByValue(observer), maxon::reflection::Argument::ByValue(pass)};
			(*handler_)(_fn_ObservableBaseInterface_PrivateDisconnectAll, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), ObserverObjectInterface*, Int), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_PrivateDisconnectAll)));
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_PrivateDisconnectAll;
		Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset), maxon::reflection::Argument::ByValue(observer), maxon::reflection::Argument::ByReference(observerFunction), maxon::reflection::Argument::ByValue(priority)};
			(*handler_)(_fn_ObservableBaseInterface_AddObserver, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), ObserverObjectInterface*, const FunctionBaseRef&, Int), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_AddObserver)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_AddObserver;
		Result<Data> Notify(const Block<const ConstDataPtr>& args) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Result<Data> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Notify_Offset), maxon::reflection::Argument::ByReference(args)};
			(*handler_)(_fn_ObservableBaseInterface_Notify, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Data>), const Block<const ConstDataPtr>&), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_Notify)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_Notify;
		Bool RemoveObserver(const FunctionBaseRef& observerEntry) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset), maxon::reflection::Argument::ByReference(observerEntry)};
			(*handler_)(_fn_ObservableBaseInterface_RemoveObserver, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const FunctionBaseRef&), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_RemoveObserver)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_RemoveObserver;
		void SetInverseNotification(Bool inverse) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset), maxon::reflection::Argument::ByValue(inverse)};
			(*handler_)(_fn_ObservableBaseInterface_SetInverseNotification, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), Bool), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_SetInverseNotification)));
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_SetInverseNotification;
		Int GetObserverCount() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset)};
			(*handler_)(_fn_ObservableBaseInterface_GetObserverCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_GetObserverCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_GetObserverCount;
		ObserverObjectInterface* GetOwner() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObservableBaseInterface>();
			ObserverObjectInterface* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetOwner_Offset)};
			(*handler_)(_fn_ObservableBaseInterface_GetOwner, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((ObserverObjectInterface*)), reinterpret_cast<const void* const&>(mt_.ObservableBaseInterface_GetOwner)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObservableBaseInterface_GetOwner;
	};
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_Init;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_GetObservableId;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_PrivateDisconnectAll;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_AddObserver;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_Notify;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_RemoveObserver;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_SetInverseNotification;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_GetObserverCount;
	const maxon::reflection::Function* ObservableBaseInterface::ProxyComponent::_fn_ObservableBaseInterface_GetOwner;
	PRIVATE_MAXON_COMPONENT_REGISTER(ObservableBaseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ObservableBaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "owner\0observableName\0", 5LL, ObservableBaseInterface, ObservableBaseInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObservableBaseInterface, ObservableBaseInterface_GetObservableId),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "observer\0pass\0", 5LL, ObservableBaseInterface, ObservableBaseInterface_PrivateDisconnectAll),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "observer\0observerFunction\0priority\0", 21LL, ObservableBaseInterface, ObservableBaseInterface_AddObserver),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "args\0", 1LL, ObservableBaseInterface, ObservableBaseInterface_Notify),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "observerEntry\0", 1LL, ObservableBaseInterface, ObservableBaseInterface_RemoveObserver),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inverse\0", 0LL, ObservableBaseInterface, ObservableBaseInterface_SetInverseNotification),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, ObservableBaseInterface, ObservableBaseInterface_GetObserverCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObservableBaseInterface, ObservableBaseInterface_GetOwner),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ObservableBaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ObservableBaseInterface(nullptr, &ObservableBaseInterface::ProxyComponent::_descriptor, &RegisterReflection_ObservableBaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ObservableStaticInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ObservableStaticInterface::MTable::_instance.ObservableStaticInterface_GetOrAllocClass)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "id\0id1\0id2\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ObservableStaticInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ObservableStaticInterface("net.maxon.interface.observablestatic", nullptr, &RegisterReflection_ObservableStaticInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef DOXYGEN
#else
#endif
}
#endif
