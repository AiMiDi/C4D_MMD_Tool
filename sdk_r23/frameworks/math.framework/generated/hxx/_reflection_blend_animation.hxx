#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_BlendTweenInterface(BlendTweenInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::BlendTweenRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class BlendTweenInterface::ProxyComponent : public maxon::Component<ProxyComponent, BlendTweenInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, BlendTweenInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Data> GetMappedValue(Float xValue) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<Data> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetMappedValue_Offset), maxon::reflection::Argument::ByValue(xValue)};
			(*handler_)(_fn_BlendTweenInterface_GetMappedValue, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data>, maxon::GenericComponent*, Float>::Invoke, (const void*) mt_._BlendTweenInterface_GetMappedValue));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_GetMappedValue;
		Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetNewTarget_Offset), maxon::reflection::Argument::ByReference(blendFunction), maxon::reflection::Argument::ByReference(endValue)};
			(*handler_)(_fn_BlendTweenInterface_SetNewTarget, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BlendFunctionRef&, const Data&>::Invoke, (const void*) mt_._BlendTweenInterface_SetNewTarget));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_SetNewTarget;
		Result<void> SetFunction(const BlendFunctionRef& blendFunction) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetFunction_Offset), maxon::reflection::Argument::ByReference(blendFunction)};
			(*handler_)(_fn_BlendTweenInterface_SetFunction, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BlendFunctionRef&>::Invoke, (const void*) mt_._BlendTweenInterface_SetFunction));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_SetFunction;
		BlendFunctionRef GetFunction() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			BlendFunctionRef proxy_result = maxon::PrivateIncompleteNullReturnValue<BlendFunctionRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetFunction_Offset)};
			(*handler_)(_fn_BlendTweenInterface_GetFunction, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<BlendFunctionRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendTweenInterface_GetFunction));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_GetFunction;
		Result<void> SetStart(const Data& value) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetStart_Offset), maxon::reflection::Argument::ByReference(value)};
			(*handler_)(_fn_BlendTweenInterface_SetStart, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Data&>::Invoke, (const void*) mt_._BlendTweenInterface_SetStart));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_SetStart;
		Result<Data> GetStart() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<Data> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetStart_Offset)};
			(*handler_)(_fn_BlendTweenInterface_GetStart, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendTweenInterface_GetStart));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_GetStart;
		Result<void> SetEnd(const Data& value) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetEnd_Offset), maxon::reflection::Argument::ByReference(value)};
			(*handler_)(_fn_BlendTweenInterface_SetEnd, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Data&>::Invoke, (const void*) mt_._BlendTweenInterface_SetEnd));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_SetEnd;
		Result<Data> GetEnd() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			Result<Data> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetEnd_Offset)};
			(*handler_)(_fn_BlendTweenInterface_GetEnd, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendTweenInterface_GetEnd));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_GetEnd;
		maxon::ObservableRef<ObservableAnimationDelegate> ObservableAnimation() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendTweenInterface>();
			maxon::ObservableRef<ObservableAnimationDelegate> proxy_result = maxon::ObservableRef<ObservableAnimationDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_ObservableAnimation_Offset)};
			(*handler_)(_fn_BlendTweenInterface_ObservableAnimation, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableAnimationDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendTweenInterface_ObservableAnimation));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendTweenInterface_ObservableAnimation;
	};
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_GetMappedValue;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_SetNewTarget;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_SetFunction;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_GetFunction;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_SetStart;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_GetStart;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_SetEnd;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_GetEnd;
	const maxon::reflection::Function* BlendTweenInterface::ProxyComponent::_fn_BlendTweenInterface_ObservableAnimation;
	PRIVATE_MAXON_COMPONENT_REGISTER(BlendTweenInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_BlendTweenInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "xValue\0", 1LL, BlendTweenInterface, _BlendTweenInterface_GetMappedValue),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "blendFunction\0endValue\0", 5LL, BlendTweenInterface, _BlendTweenInterface_SetNewTarget),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "blendFunction\0", 1LL, BlendTweenInterface, _BlendTweenInterface_SetFunction),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendTweenInterface, _BlendTweenInterface_GetFunction),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, BlendTweenInterface, _BlendTweenInterface_SetStart),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendTweenInterface, _BlendTweenInterface_GetStart),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, BlendTweenInterface, _BlendTweenInterface_SetEnd),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendTweenInterface, _BlendTweenInterface_GetEnd),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendTweenInterface, _BlendTweenInterface_ObservableAnimation),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BlendTweenInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_BlendTweenInterface(nullptr, &BlendTweenInterface::ProxyComponent::_descriptor, &RegisterReflection_BlendTweenInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_BlendAnimationInterface(BlendAnimationInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::BlendAnimationRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class BlendAnimationInterface::ProxyComponent : public maxon::Component<ProxyComponent, BlendAnimationInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, BlendAnimationInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Result<BlendTweenRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_AddTween_Offset), maxon::reflection::Argument::ByReference(blendFunction), maxon::reflection::Argument::ByReference(startValue), maxon::reflection::Argument::ByReference(endValue)};
			(*handler_)(_fn_BlendAnimationInterface_AddTween, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BlendTweenRef>, maxon::GenericComponent*, const BlendFunctionRef&, const Data&, const Data&>::Invoke, (const void*) mt_._BlendAnimationInterface_AddTween));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_AddTween;
		Result<void> RemoveTween(const BlendTweenRef& tween) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_RemoveTween_Offset), maxon::reflection::Argument::ByReference(tween)};
			(*handler_)(_fn_BlendAnimationInterface_RemoveTween, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BlendTweenRef&>::Invoke, (const void*) mt_._BlendAnimationInterface_RemoveTween));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_RemoveTween;
		Result<BaseArray<BlendTweenRef>> GetTweens() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Result<BaseArray<BlendTweenRef>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetTweens_Offset)};
			(*handler_)(_fn_BlendAnimationInterface_GetTweens, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<BlendTweenRef>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendAnimationInterface_GetTweens));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_GetTweens;
		Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_StartAnimation_Offset), maxon::reflection::Argument::ByReference(timerInterval), maxon::reflection::Argument::ByReference(startDelay), maxon::reflection::Argument::ByReference(duration)};
			(*handler_)(_fn_BlendAnimationInterface_StartAnimation, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const TimeValue&, const TimeValue&, const TimeValue&>::Invoke, (const void*) mt_._BlendAnimationInterface_StartAnimation));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_StartAnimation;
		Float GetProgress() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Float proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetProgress_Offset)};
			(*handler_)(_fn_BlendAnimationInterface_GetProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendAnimationInterface_GetProgress));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_GetProgress;
		ANIMBLENDSTATE GetState() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			ANIMBLENDSTATE proxy_result = maxon::PrivateIncompleteNullReturnValue<ANIMBLENDSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetState_Offset)};
			(*handler_)(_fn_BlendAnimationInterface_GetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<ANIMBLENDSTATE, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendAnimationInterface_GetState));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_GetState;
		void CancelAndWait() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_CancelAndWait_Offset)};
			(*handler_)(_fn_BlendAnimationInterface_CancelAndWait, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendAnimationInterface_CancelAndWait));
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_CancelAndWait;
		Result<TimerRef> GetTimerRef() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<BlendAnimationInterface>();
			Result<TimerRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetTimerRef_Offset)};
			(*handler_)(_fn_BlendAnimationInterface_GetTimerRef, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<TimerRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._BlendAnimationInterface_GetTimerRef));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_BlendAnimationInterface_GetTimerRef;
	};
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_AddTween;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_RemoveTween;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_GetTweens;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_StartAnimation;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_GetProgress;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_GetState;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_CancelAndWait;
	const maxon::reflection::Function* BlendAnimationInterface::ProxyComponent::_fn_BlendAnimationInterface_GetTimerRef;
	PRIVATE_MAXON_COMPONENT_REGISTER(BlendAnimationInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_BlendAnimationInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "blendFunction\0startValue\0endValue\0", 0LL, BlendAnimationInterface, _BlendAnimationInterface_AddTween),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tween\0", 0LL, BlendAnimationInterface, _BlendAnimationInterface_RemoveTween),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendAnimationInterface, _BlendAnimationInterface_GetTweens),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "timerInterval\0startDelay\0duration\0", 0LL, BlendAnimationInterface, _BlendAnimationInterface_StartAnimation),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendAnimationInterface, _BlendAnimationInterface_GetProgress),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendAnimationInterface, _BlendAnimationInterface_GetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, BlendAnimationInterface, _BlendAnimationInterface_CancelAndWait),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, BlendAnimationInterface, _BlendAnimationInterface_GetTimerRef),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BlendAnimationInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_BlendAnimationInterface(nullptr, &BlendAnimationInterface::ProxyComponent::_descriptor, &RegisterReflection_BlendAnimationInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
