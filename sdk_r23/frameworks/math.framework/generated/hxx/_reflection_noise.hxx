#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_NoiseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "seed\0permutationTablePower\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetSeed)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetPermutationTablePower)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetPermutationTable)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetGradientTable)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "gradient3D\0gradient\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetFbmTable)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0fbm\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_GetRandomTable)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_SNoise)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_SNoise_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_PeriodicSNoise)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0repeatX\0repeatY\0repeatZ\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_PeriodicSNoise_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0repeatX\0repeatY\0repeatZ\0repeatT\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Voronoi)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0maximumOrder\0distance\0index\0", 165LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Voronoi_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0maximumOrder\0distance\0index\0", 165LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_InitFbm)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "lacunarity\0gain\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Fbm)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Fbm_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Turbulence)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0octaves\0absolute\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_Turbulence_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0octaves\0absolute\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_RidgedMultifractal)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0offset\0threshold\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NoiseInterface::MTable::_instance._NoiseInterface_RidgedMultifractal_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0offset\0threshold\0", 341LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NoiseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_NoiseInterface("net.maxon.render.interface.noise", nullptr, &RegisterReflection_NoiseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_RenderNoiseInterface(RenderNoiseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::RenderNoiseRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class RenderNoiseInterface::ProxyComponent : public maxon::Component<ProxyComponent, RenderNoiseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, RenderNoiseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<RenderNoiseInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Init_Offset), maxon::reflection::Argument::ByValue(seed), maxon::reflection::Argument::ByValue(permutationTablePower), maxon::reflection::Argument::ByReference(additionalParameters)};
			(*handler_)(_fn_RenderNoiseInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, UInt32, Int, const DataDictionary&>::Invoke, (const void*) mt_._RenderNoiseInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_RenderNoiseInterface_Init;
		Float32 Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<RenderNoiseInterface>();
			Float32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Noise_Offset), maxon::reflection::Argument::ByReference(p), maxon::reflection::Argument::ByValue(time), maxon::reflection::Argument::ByValue(octaves), maxon::reflection::Argument::ByValue(absolute), maxon::reflection::Argument::ByValue(sampleRadius)};
			(*handler_)(_fn_RenderNoiseInterface_Noise, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float32, const maxon::GenericComponent*, const Vector32&, Float32, Float32, Bool, Float32>::Invoke, (const void*) mt_._RenderNoiseInterface_Noise));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_RenderNoiseInterface_Noise;
		Float32 Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<RenderNoiseInterface>();
			Float32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Noise_1_Offset), maxon::reflection::Argument::ByReference(p), maxon::reflection::Argument::ByValue(time), maxon::reflection::Argument::ByValue(octaves), maxon::reflection::Argument::ByValue(absolute), maxon::reflection::Argument::ByValue(sampleRadius)};
			(*handler_)(_fn_RenderNoiseInterface_Noise_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float32, const maxon::GenericComponent*, const Vector2d32&, Float32, Float32, Bool, Float32>::Invoke, (const void*) mt_._RenderNoiseInterface_Noise_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_RenderNoiseInterface_Noise_1;
	};
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Init;
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Noise;
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Noise_1;
	PRIVATE_MAXON_COMPONENT_REGISTER(RenderNoiseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_RenderNoiseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "seed\0permutationTablePower\0additionalParameters\0", 21LL, RenderNoiseInterface, _RenderNoiseInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "p\0time\0octaves\0absolute\0sampleRadius\0", 341LL, RenderNoiseInterface, _RenderNoiseInterface_Noise),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "p\0time\0octaves\0absolute\0sampleRadius\0", 341LL, RenderNoiseInterface, _RenderNoiseInterface_Noise_1),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&RenderNoiseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_RenderNoiseInterface(nullptr, &RenderNoiseInterface::ProxyComponent::_descriptor, &RegisterReflection_RenderNoiseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(RenderNoiseClasses);
#endif
}
#endif
