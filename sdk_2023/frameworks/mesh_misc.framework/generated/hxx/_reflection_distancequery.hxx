#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DistanceQueryInterface(DistanceQueryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DistanceQueryRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DistanceQueryInterface::ProxyComponent : public maxon::Component<ProxyComponent, DistanceQueryInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DistanceQueryInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(PolygonObject* mesh, Bool initVoxelization) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_Offset), maxon::reflection::Argument::ByValue(mesh), maxon::reflection::Argument::ByValue(initVoxelization)};
			(*handler_)(_fn_DistanceQueryInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), PolygonObject*, Bool), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_Init;
		Result<void> Init(SplineObject* spline) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_1_Offset), maxon::reflection::Argument::ByValue(spline)};
			(*handler_)(_fn_DistanceQueryInterface_Init_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), SplineObject*), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_Init_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_Init_1;
		Result<void> Init(LineObject* line) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_2_Offset), maxon::reflection::Argument::ByValue(line)};
			(*handler_)(_fn_DistanceQueryInterface_Init_2, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), LineObject*), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_Init_2)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_Init_2;
		Result<void> Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_3_Offset), maxon::reflection::Argument::ByValue(points), maxon::reflection::Argument::ByValue(polygons), maxon::reflection::Argument::ByReference(objectPosition)};
			(*handler_)(_fn_DistanceQueryInterface_Init_3, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const Block<const Vector>, const Block<const SimplePolygon>, const Matrix&), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_Init_3)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_Init_3;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Reset_Offset)};
			(*handler_)(_fn_DistanceQueryInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_Reset)));
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_Reset;
		Float GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Float proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetClosestMeshPrimitive_Offset), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByReference(primInfo), maxon::reflection::Argument::ByValue(polyFilter)};
			(*handler_)(_fn_DistanceQueryInterface_GetClosestMeshPrimitive, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Float), const Vector&, PrimitiveInformation&, const BaseBitSet<>*), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_GetClosestMeshPrimitive)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_GetClosestMeshPrimitive;
		void GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToMesh_Offset), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByReference(distInfo), maxon::reflection::Argument::ByValue(polyFilter), maxon::reflection::Argument::ByValue(onlyPolyPrimitives)};
			(*handler_)(_fn_DistanceQueryInterface_GetDistanceToMesh, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Vector&, MeshDistanceData&, const BaseBitSet<>*, Bool), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_GetDistanceToMesh)));
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_GetDistanceToMesh;
		void GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByReference(direction), maxon::reflection::Argument::ByValue(angle), maxon::reflection::Argument::ByReference(distInfo), maxon::reflection::Argument::ByValue(polyFilter), maxon::reflection::Argument::ByValue(onlyPolyPrimitives)};
			(*handler_)(_fn_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Vector&, const Vector&, const Float, MeshDistanceData&, const BaseBitSet<>*, Bool), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection)));
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection;
		void GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToSpline_Offset), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByReference(distInfo)};
			(*handler_)(_fn_DistanceQueryInterface_GetDistanceToSpline, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Vector&, SplineDistanceData&), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_GetDistanceToSpline)));
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_GetDistanceToSpline;
		Bool IsInitialized() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_IsInitialized_Offset)};
			(*handler_)(_fn_DistanceQueryInterface_IsInitialized, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool)), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_IsInitialized)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_IsInitialized;
		void SetThreading(Int32 threads) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DistanceQueryInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_SetThreading_Offset), maxon::reflection::Argument::ByValue(threads)};
			(*handler_)(_fn_DistanceQueryInterface_SetThreading, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), Int32), reinterpret_cast<const void* const&>(mt_.DistanceQueryInterface_SetThreading)));
		}
		static const maxon::reflection::Function* _fn_DistanceQueryInterface_SetThreading;
	};
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_Init;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_Init_1;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_Init_2;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_Init_3;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_Reset;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_GetClosestMeshPrimitive;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_GetDistanceToMesh;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_GetDistanceToSpline;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_IsInitialized;
	const maxon::reflection::Function* DistanceQueryInterface::ProxyComponent::_fn_DistanceQueryInterface_SetThreading;
	PRIVATE_MAXON_COMPONENT_REGISTER(DistanceQueryInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DistanceQueryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "mesh\0initVoxelization\0", 5LL, DistanceQueryInterface, DistanceQueryInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "spline\0", 1LL, DistanceQueryInterface, DistanceQueryInterface_Init_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "line\0", 1LL, DistanceQueryInterface, DistanceQueryInterface_Init_2),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "points\0polygons\0objectPosition\0", 21LL, DistanceQueryInterface, DistanceQueryInterface_Init_3),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, DistanceQueryInterface, DistanceQueryInterface_Reset),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pos\0primInfo\0polyFilter\0", 25LL, DistanceQueryInterface, DistanceQueryInterface_GetClosestMeshPrimitive),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pos\0distInfo\0polyFilter\0onlyPolyPrimitives\0", 89LL, DistanceQueryInterface, DistanceQueryInterface_GetDistanceToMesh),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pos\0direction\0angle\0distInfo\0polyFilter\0onlyPolyPrimitives\0", 1429LL, DistanceQueryInterface, DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pos\0distInfo\0", 9LL, DistanceQueryInterface, DistanceQueryInterface_GetDistanceToSpline),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DistanceQueryInterface, DistanceQueryInterface_IsInitialized),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "threads\0", 1LL, DistanceQueryInterface, DistanceQueryInterface_SetThreading),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DistanceQueryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DistanceQueryInterface(nullptr, &DistanceQueryInterface::ProxyComponent::_descriptor, &RegisterReflection_DistanceQueryInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
