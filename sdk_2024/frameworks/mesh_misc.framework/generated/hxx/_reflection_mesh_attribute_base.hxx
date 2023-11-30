#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CustomDataTagDisplayInterface(CustomDataTagDisplayInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CustomDataTagDisplayRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CustomDataTagDisplayInterface::ProxyComponent : public maxon::Component<ProxyComponent, CustomDataTagDisplayInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CustomDataTagDisplayInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(BaseTag* tag) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Init_Offset), maxon::reflection::Argument::ByValue(tag)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), BaseTag*), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_Init;
		Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Draw_Offset), maxon::reflection::Argument::ByValue(tag), maxon::reflection::Argument::ByValue(op), maxon::reflection::Argument::ByValue(bd), maxon::reflection::Argument::ByValue(bh)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_Draw, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), BaseTag*, BaseObject*, BaseDraw*, BaseDrawHelp*), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_Draw)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_Draw;
		Result<void> DisplayControl(const BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_DisplayControl_Offset), maxon::reflection::Argument::ByValue(tag), maxon::reflection::Argument::ByValue(doc), maxon::reflection::Argument::ByValue(op), maxon::reflection::Argument::ByValue(bd), maxon::reflection::Argument::ByValue(bh), maxon::reflection::Argument::ByReference(cds)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_DisplayControl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const BaseTag*, BaseDocument*, BaseObject*, BaseDraw*, BaseDrawHelp*, ControlDisplayStruct&), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_DisplayControl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_DisplayControl;
		Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset), maxon::reflection::Argument::ByValue(tag), maxon::reflection::Argument::ByValue(doc), maxon::reflection::Argument::ByValue(bd), maxon::reflection::Argument::ByValue(active)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_InitDisplayControl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), BaseTag*, BaseDocument*, BaseDraw*, const AtomArray*), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_InitDisplayControl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_InitDisplayControl;
		void FreeDisplayControl(BaseTag* tag) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset), maxon::reflection::Argument::ByValue(tag)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_FreeDisplayControl, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), BaseTag*), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_FreeDisplayControl)));
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_FreeDisplayControl;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagDisplayInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Reset_Offset)};
			(*handler_)(_fn_CustomDataTagDisplayInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.CustomDataTagDisplayInterface_Reset)));
		}
		static const maxon::reflection::Function* _fn_CustomDataTagDisplayInterface_Reset;
	};
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_Init;
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_Draw;
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_DisplayControl;
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_InitDisplayControl;
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_FreeDisplayControl;
	const maxon::reflection::Function* CustomDataTagDisplayInterface::ProxyComponent::_fn_CustomDataTagDisplayInterface_Reset;
	PRIVATE_MAXON_COMPONENT_REGISTER(CustomDataTagDisplayInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CustomDataTagDisplayInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tag\0", 1LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tag\0op\0bd\0bh\0", 85LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_Draw),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "tag\0doc\0op\0bd\0bh\0cds\0", 1365LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_DisplayControl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tag\0doc\0bd\0active\0", 85LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_InitDisplayControl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tag\0", 1LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_FreeDisplayControl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CustomDataTagDisplayInterface, CustomDataTagDisplayInterface_Reset),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CustomDataTagDisplayInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CustomDataTagDisplayInterface(nullptr, &CustomDataTagDisplayInterface::ProxyComponent::_descriptor, &RegisterReflection_CustomDataTagDisplayInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MeshAttributeClassInterface(MeshAttributeClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MeshAttributeClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MeshAttributeClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, MeshAttributeClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MeshAttributeClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const DataType& GetDataType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			const DataType* proxy_result = &HXXRET3(NULLIMPL, const DataType&);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDataType_Offset)};
			(*handler_)(_fn_MeshAttributeClassInterface_GetDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_GetDataType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_GetDataType;
		const DataType& GetUnderlyingDataType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			const DataType* proxy_result = &HXXRET3(NULLIMPL, const DataType&);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetUnderlyingDataType_Offset)};
			(*handler_)(_fn_MeshAttributeClassInterface_GetUnderlyingDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_GetUnderlyingDataType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_GetUnderlyingDataType;
		void InterpolateLinear(void* data1, const void* data2, Float blend) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateLinear_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2), maxon::reflection::Argument::ByValue(blend)};
			(*handler_)(_fn_MeshAttributeClassInterface_InterpolateLinear, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*, Float), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_InterpolateLinear)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_InterpolateLinear;
		void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateInOutline_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByReference(outline), maxon::reflection::Argument::ByReference(weights)};
			(*handler_)(_fn_MeshAttributeClassInterface_InterpolateInOutline, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const Block<void*>&, const Block<Float>&), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_InterpolateInOutline)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_InterpolateInOutline;
		void GetDefaultValue(void* data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDefaultValue_Offset), maxon::reflection::Argument::ByValue(data)};
			(*handler_)(_fn_MeshAttributeClassInterface_GetDefaultValue, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_GetDefaultValue)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_GetDefaultValue;
		Bool AtrLessThen(const void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrLessThen_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrLessThen, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrLessThen)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrLessThen;
		Bool AtrIsEqual(const void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrIsEqual_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrIsEqual, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrIsEqual)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrIsEqual;
		void AtrAdd(void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrAdd_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrAdd, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrAdd)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrAdd;
		void AtrSubstract(void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrSubstract_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrSubstract, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrSubstract)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrSubstract;
		void AtrMultiply(void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrMultiply, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrMultiply)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrMultiply;
		void AtrMultiply(void* data, Float value) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_1_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(value)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrMultiply_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, Float), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrMultiply_1)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrMultiply_1;
		void AtrDivide(void* data1, const void* data2) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrDivide, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrDivide)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrDivide;
		void AtrDivide(void* data, Float value) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_1_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(value)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrDivide_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, Float), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrDivide_1)));
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrDivide_1;
		String AtrToString(const void* data, const FormatStatement* formatStatement) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MeshAttributeClassInterface>();
			String proxy_result = HXXRET3(NULLIMPL, String);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrToString_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(formatStatement)};
			(*handler_)(_fn_MeshAttributeClassInterface_AtrToString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String), const void*, const FormatStatement*), reinterpret_cast<const void* const&>(mt_.MeshAttributeClassInterface_AtrToString)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MeshAttributeClassInterface_AtrToString;
	};
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_GetDataType;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_GetUnderlyingDataType;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_InterpolateLinear;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_InterpolateInOutline;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_GetDefaultValue;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrLessThen;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrIsEqual;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrAdd;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrSubstract;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrMultiply;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrMultiply_1;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrDivide;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrDivide_1;
	const maxon::reflection::Function* MeshAttributeClassInterface::ProxyComponent::_fn_MeshAttributeClassInterface_AtrToString;
	PRIVATE_MAXON_COMPONENT_REGISTER(MeshAttributeClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MeshAttributeClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MeshAttributeClassInterface, MeshAttributeClassInterface_GetDataType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MeshAttributeClassInterface, MeshAttributeClassInterface_GetUnderlyingDataType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0blend\0", 23LL, MeshAttributeClassInterface, MeshAttributeClassInterface_InterpolateLinear),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0outline\0weights\0", 23LL, MeshAttributeClassInterface, MeshAttributeClassInterface_InterpolateInOutline),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0", 2LL, MeshAttributeClassInterface, MeshAttributeClassInterface_GetDefaultValue),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 5LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrLessThen),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 5LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrIsEqual),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrAdd),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrSubstract),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrMultiply),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0value\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrMultiply_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrDivide),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0value\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrDivide_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0formatStatement\0", 7LL, MeshAttributeClassInterface, MeshAttributeClassInterface_AtrToString),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MeshAttributeClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MeshAttributeClassInterface(nullptr, &MeshAttributeClassInterface::ProxyComponent::_descriptor, &RegisterReflection_MeshAttributeClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CustomDataTagClassInterface(CustomDataTagClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CustomDataTagClass");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CustomDataTagClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, CustomDataTagClassInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CustomDataTagClassInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Int32 GetTagPluginId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginId_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetTagPluginId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetTagPluginId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetTagPluginId;
		const String& GetTagPluginName() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			const String* proxy_result = &HXXRET3(NULLIMPL, const String&);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginName_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetTagPluginName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const String&)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetTagPluginName)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetTagPluginName;
		const String& GetResourceId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			const String* proxy_result = &HXXRET3(NULLIMPL, const String&);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetResourceId_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetResourceId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const String&)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetResourceId)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetResourceId;
		Int32 GetTagPluginLevel() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginLevel_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetTagPluginLevel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetTagPluginLevel)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetTagPluginLevel;
		Id GetDisplayClassId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Id proxy_result = HXXRET3(NULLIMPL, Id);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetDisplayClassId_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetDisplayClassId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Id)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetDisplayClassId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetDisplayClassId;
		Bool IsSdsCompatible(Int32& floatSize) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_IsSdsCompatible_Offset), maxon::reflection::Argument::ByReference(floatSize)};
			(*handler_)(_fn_CustomDataTagClassInterface_IsSdsCompatible, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), Int32&), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_IsSdsCompatible)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_IsSdsCompatible;
		Result<void> Read(void* data, HyperFile* hf, Int32 level) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Read_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(hf), maxon::reflection::Argument::ByValue(level)};
			(*handler_)(_fn_CustomDataTagClassInterface_Read, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), void*, HyperFile*, Int32), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_Read)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_Read;
		Result<void> Write(const void* data, HyperFile* hf) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Write_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(hf)};
			(*handler_)(_fn_CustomDataTagClassInterface_Write, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const void*, HyperFile*), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_Write)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_Write;
		Int32 GetIcon(Bool perPolyVertex) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetIcon_Offset), maxon::reflection::Argument::ByValue(perPolyVertex)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetIcon, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32), Bool), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetIcon)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetIcon;
		Int32 GetTagPluginFlags() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginFlags_Offset)};
			(*handler_)(_fn_CustomDataTagClassInterface_GetTagPluginFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_GetTagPluginFlags)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_GetTagPluginFlags;
		Bool Message(GeListNode* node, Int32 type, void* data) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CustomDataTagClassInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Message_Offset), maxon::reflection::Argument::ByValue(node), maxon::reflection::Argument::ByValue(type), maxon::reflection::Argument::ByValue(data)};
			(*handler_)(_fn_CustomDataTagClassInterface_Message, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), GeListNode*, Int32, void*), reinterpret_cast<const void* const&>(mt_.CustomDataTagClassInterface_Message)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CustomDataTagClassInterface_Message;
	};
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetTagPluginId;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetTagPluginName;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetResourceId;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetTagPluginLevel;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetDisplayClassId;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_IsSdsCompatible;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_Read;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_Write;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetIcon;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_GetTagPluginFlags;
	const maxon::reflection::Function* CustomDataTagClassInterface::ProxyComponent::_fn_CustomDataTagClassInterface_Message;
	PRIVATE_MAXON_COMPONENT_REGISTER(CustomDataTagClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CustomDataTagClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetTagPluginId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetTagPluginName),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetResourceId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetTagPluginLevel),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetDisplayClassId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "floatSize\0", 2LL, CustomDataTagClassInterface, CustomDataTagClassInterface_IsSdsCompatible),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0hf\0level\0", 21LL, CustomDataTagClassInterface, CustomDataTagClassInterface_Read),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0hf\0", 5LL, CustomDataTagClassInterface, CustomDataTagClassInterface_Write),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "perPolyVertex\0", 1LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetIcon),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CustomDataTagClassInterface, CustomDataTagClassInterface_GetTagPluginFlags),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "node\0type\0data\0", 21LL, CustomDataTagClassInterface, CustomDataTagClassInterface_Message),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CustomDataTagClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CustomDataTagClassInterface(nullptr, &CustomDataTagClassInterface::ProxyComponent::_descriptor, &RegisterReflection_CustomDataTagClassInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CustomDataTagClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CustomDataTagDisplayClasses);
#endif
}
#endif
