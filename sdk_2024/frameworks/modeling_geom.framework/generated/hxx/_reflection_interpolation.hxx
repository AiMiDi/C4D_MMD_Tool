#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_InterpolateTypeInterface(InterpolateTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::InterpolateType");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class InterpolateTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, InterpolateTypeInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, InterpolateTypeInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const DataType& GetInterpolateDataType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<InterpolateTypeInterface>();
			const DataType* proxy_result = &HXXRET3(NULLIMPL, const DataType&);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_GetInterpolateDataType_Offset)};
			(*handler_)(_fn_InterpolateTypeInterface_GetInterpolateDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.InterpolateTypeInterface_GetInterpolateDataType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_InterpolateTypeInterface_GetInterpolateDataType;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<InterpolateTypeInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_InterpolateLinear_Offset), maxon::reflection::Argument::ByValue(data1), maxon::reflection::Argument::ByValue(data2), maxon::reflection::Argument::ByValue(blend)};
			(*handler_)(_fn_InterpolateTypeInterface_InterpolateLinear, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const void*, Float), reinterpret_cast<const void* const&>(mt_.InterpolateTypeInterface_InterpolateLinear)));
		}
		static const maxon::reflection::Function* _fn_InterpolateTypeInterface_InterpolateLinear;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<InterpolateTypeInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_InterpolateInOutline_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByReference(outline), maxon::reflection::Argument::ByReference(weights)};
			(*handler_)(_fn_InterpolateTypeInterface_InterpolateInOutline, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const Block<void*>&, const Block<Float>&), reinterpret_cast<const void* const&>(mt_.InterpolateTypeInterface_InterpolateInOutline)));
		}
		static const maxon::reflection::Function* _fn_InterpolateTypeInterface_InterpolateInOutline;
		void Average(void* data, const Block<const void*>& dataSet) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<InterpolateTypeInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_Average_Offset), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByReference(dataSet)};
			(*handler_)(_fn_InterpolateTypeInterface_Average, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), void*, const Block<const void*>&), reinterpret_cast<const void* const&>(mt_.InterpolateTypeInterface_Average)));
		}
		static const maxon::reflection::Function* _fn_InterpolateTypeInterface_Average;
	};
	const maxon::reflection::Function* InterpolateTypeInterface::ProxyComponent::_fn_InterpolateTypeInterface_GetInterpolateDataType;
	const maxon::reflection::Function* InterpolateTypeInterface::ProxyComponent::_fn_InterpolateTypeInterface_InterpolateLinear;
	const maxon::reflection::Function* InterpolateTypeInterface::ProxyComponent::_fn_InterpolateTypeInterface_InterpolateInOutline;
	const maxon::reflection::Function* InterpolateTypeInterface::ProxyComponent::_fn_InterpolateTypeInterface_Average;
	PRIVATE_MAXON_COMPONENT_REGISTER(InterpolateTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_InterpolateTypeInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(InterpolateTypeInterface::Hxx2::StaticMTable::_instance.InterpolateTypeInterface_GetInterpolationClass)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "datatype\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&InterpolateTypeInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_InterpolateTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, InterpolateTypeInterface, InterpolateTypeInterface_GetInterpolateDataType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data1\0data2\0blend\0", 23LL, InterpolateTypeInterface, InterpolateTypeInterface_InterpolateLinear),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0outline\0weights\0", 23LL, InterpolateTypeInterface, InterpolateTypeInterface_InterpolateInOutline),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "data\0dataSet\0", 7LL, InterpolateTypeInterface, InterpolateTypeInterface_Average),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&InterpolateTypeInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_InterpolateTypeInterface(nullptr, &InterpolateTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_InterpolateTypeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_InterpolateTypeInterface_Static("net.maxon.geometry.interface.interpolate", nullptr, &RegisterReflection_InterpolateTypeInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(InterpolateTypes);
#endif
}
#endif
