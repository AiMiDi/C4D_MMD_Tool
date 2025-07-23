#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_NoiseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0seed\0permutationTablePower\0", 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "seed\0permutationTablePower\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetSeed)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetPermutationTablePower)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetPermutationTable)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetGradientTable)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "gradient3D\0gradient\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetFbmTable)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "table\0fbm\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_GetRandomTable)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_SNoise)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_SNoise_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_PeriodicSNoise)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0repeatX\0repeatY\0repeatZ\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_PeriodicSNoise_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0repeatX\0repeatY\0repeatZ\0repeatT\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Voronoi)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0maximumOrder\0distance\0index\0", 165LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Voronoi_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0maximumOrder\0distance\0index\0", 165LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_InitFbm)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "lacunarity\0gain\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Fbm)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Fbm_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Turbulence)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0octaves\0absolute\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_Turbulence_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "p\0octaves\0absolute\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_RidgedMultifractal)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0offset\0threshold\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NoiseInterface::MTable::_instance.NoiseInterface_RidgedMultifractal_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "table\0p\0octaves\0offset\0threshold\0", 341LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NoiseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_NoiseInterface("net.maxon.render.interface.noise", nullptr, &RegisterReflection_NoiseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_RenderNoiseInterface(RenderNoiseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::RenderNoise");
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
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Init_Offset), maxon::reflection::Argument::ByValue(seed), maxon::reflection::Argument::ByValue(permutationTablePower), maxon::reflection::Argument::ByReference(additionalParameters)};
			(*handler_)(_fn_RenderNoiseInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), UInt32, Int, const DataDictionary&), reinterpret_cast<const void* const&>(mt_.RenderNoiseInterface_Init)));
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
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_Offset), maxon::reflection::Argument::ByReference(p), maxon::reflection::Argument::ByValue(time), maxon::reflection::Argument::ByValue(octaves), maxon::reflection::Argument::ByValue(absolute), maxon::reflection::Argument::ByValue(sampleRadius)};
			(*handler_)(_fn_RenderNoiseInterface_Noise, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Float32), const Vector32&, Float32, Float32, Bool, Float32), reinterpret_cast<const void* const&>(mt_.RenderNoiseInterface_Noise)));
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
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_1_Offset), maxon::reflection::Argument::ByReference(p), maxon::reflection::Argument::ByValue(time), maxon::reflection::Argument::ByValue(octaves), maxon::reflection::Argument::ByValue(absolute), maxon::reflection::Argument::ByValue(sampleRadius)};
			(*handler_)(_fn_RenderNoiseInterface_Noise_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Float32), const Vector2d32&, Float32, Float32, Bool, Float32), reinterpret_cast<const void* const&>(mt_.RenderNoiseInterface_Noise_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_RenderNoiseInterface_Noise_1;
	};
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Init;
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Noise;
	const maxon::reflection::Function* RenderNoiseInterface::ProxyComponent::_fn_RenderNoiseInterface_Noise_1;
	PRIVATE_MAXON_COMPONENT_REGISTER(RenderNoiseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_RenderNoiseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "seed\0permutationTablePower\0additionalParameters\0", 21LL, RenderNoiseInterface, RenderNoiseInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "p\0time\0octaves\0absolute\0sampleRadius\0", 341LL, RenderNoiseInterface, RenderNoiseInterface_Noise),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "p\0time\0octaves\0absolute\0sampleRadius\0", 341LL, RenderNoiseInterface, RenderNoiseInterface_Noise_1),
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
