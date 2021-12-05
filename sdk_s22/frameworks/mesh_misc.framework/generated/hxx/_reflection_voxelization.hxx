#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_VoxelizationInterface(VoxelizationInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class VoxelizationInterface::ProxyComponent : public maxon::Component<ProxyComponent, VoxelizationInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, VoxelizationInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_Offset), maxon::reflection::Argument::ByValue(polyObject), maxon::reflection::Argument::ByValue(voxelResolution), maxon::reflection::Argument::ByValue(minResolution), maxon::reflection::Argument::ByReference(polyRanges), maxon::reflection::Argument::ByValue(pointOverride), maxon::reflection::Argument::ByValue(precise)};
			(*handler_)(_fn_VoxelizationInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, maxon::GenericComponent*, PolygonObject*, Int32, Int32, BaseArray<Range<Vector>>&, const Vector*, Bool>::Invoke, (const void*) mt_._VoxelizationInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_Init;
		Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_1_Offset), maxon::reflection::Argument::ByValue(polyObject), maxon::reflection::Argument::ByReference(polyIslands), maxon::reflection::Argument::ByValue(voxelResolution), maxon::reflection::Argument::ByValue(minResolution), maxon::reflection::Argument::ByReference(polyRanges), maxon::reflection::Argument::ByValue(pointOverride)};
			(*handler_)(_fn_VoxelizationInterface_Init_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, maxon::GenericComponent*, PolygonObject*, BaseArray<Int32>&, Int32, Int32, BaseArray<Range<Vector>>&, const Vector*>::Invoke, (const void*) mt_._VoxelizationInterface_Init_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_Init_1;
		Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_2_Offset), maxon::reflection::Argument::ByValue(hull), maxon::reflection::Argument::ByValue(voxelResolution), maxon::reflection::Argument::ByValue(minResolution), maxon::reflection::Argument::ByReference(polyRanges)};
			(*handler_)(_fn_VoxelizationInterface_Init_2, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, maxon::GenericComponent*, const ConvexHullData*, Int32, Int32, BaseArray<Range<Vector>>&>::Invoke, (const void*) mt_._VoxelizationInterface_Init_2));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_Init_2;
		Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_3_Offset), maxon::reflection::Argument::ByReference(facePoints), maxon::reflection::Argument::ByReference(points), maxon::reflection::Argument::ByValue(voxelResolution), maxon::reflection::Argument::ByValue(minResolution), maxon::reflection::Argument::ByReference(polyRanges)};
			(*handler_)(_fn_VoxelizationInterface_Init_3, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, maxon::GenericComponent*, const BaseArray<BaseArray<Int32>>&, const BaseArray<Vector>&, Int32, Int32, BaseArray<Range<Vector>>&>::Invoke, (const void*) mt_._VoxelizationInterface_Init_3));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_Init_3;
		Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetClosestPolys_Offset), maxon::reflection::Argument::ByValue(pos), maxon::reflection::Argument::ByReference(voxelPolys), maxon::reflection::Argument::ByValue(polyFilter)};
			(*handler_)(_fn_VoxelizationInterface_GetClosestPolys, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const Vector, BaseBitSet<>&, const BaseBitSet<>*>::Invoke, (const void*) mt_._VoxelizationInterface_GetClosestPolys));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetClosestPolys;
		Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndices_Offset), maxon::reflection::Argument::ByReference(toTestBox), maxon::reflection::Argument::ByReference(indexList)};
			(*handler_)(_fn_VoxelizationInterface_GetIntersectingIndices, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const Range<Vector>&, BaseArray<Int32>&>::Invoke, (const void*) mt_._VoxelizationInterface_GetIntersectingIndices));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetIntersectingIndices;
		Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndicesPrecise_Offset), maxon::reflection::Argument::ByReference(toTestBox), maxon::reflection::Argument::ByReference(polyRanges), maxon::reflection::Argument::ByReference(indexList)};
			(*handler_)(_fn_VoxelizationInterface_GetIntersectingIndicesPrecise, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const Range<Vector>&, const BaseArray<Range<Vector>>&, BaseArray<Int32>&>::Invoke, (const void*) mt_._VoxelizationInterface_GetIntersectingIndicesPrecise));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetIntersectingIndicesPrecise;
		Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndices_1_Offset), maxon::reflection::Argument::ByReference(point), maxon::reflection::Argument::ByReference(indexList)};
			(*handler_)(_fn_VoxelizationInterface_GetIntersectingIndices_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Bool>, const maxon::GenericComponent*, const Vector&, BaseArray<Int32>&>::Invoke, (const void*) mt_._VoxelizationInterface_GetIntersectingIndices_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetIntersectingIndices_1;
		const Range<Vector>& GetBoundingBox() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			const Range<Vector>* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Range<Vector>&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetBoundingBox_Offset)};
			(*handler_)(_fn_VoxelizationInterface_GetBoundingBox, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Range<Vector>&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VoxelizationInterface_GetBoundingBox));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetBoundingBox;
		Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Range<IntVector32> proxy_result = maxon::PrivateIncompleteNullReturnValue<Range<IntVector32>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset), maxon::reflection::Argument::ByReference(boundingBox)};
			(*handler_)(_fn_VoxelizationInterface_GetVoxelRangesFromBoundingBox, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Range<IntVector32>, const maxon::GenericComponent*, const Range<Vector>&>::Invoke, (const void*) mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_GetVoxelRangesFromBoundingBox;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VoxelizationInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_IsInitialized_Offset)};
			(*handler_)(_fn_VoxelizationInterface_IsInitialized, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VoxelizationInterface_IsInitialized));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VoxelizationInterface_IsInitialized;
	};
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_Init;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_Init_1;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_Init_2;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_Init_3;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetClosestPolys;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetIntersectingIndices;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetIntersectingIndicesPrecise;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetIntersectingIndices_1;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetBoundingBox;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_GetVoxelRangesFromBoundingBox;
	const maxon::reflection::Function* VoxelizationInterface::ProxyComponent::_fn_VoxelizationInterface_IsInitialized;
	PRIVATE_MAXON_COMPONENT_REGISTER(VoxelizationInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_VoxelizationInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "polyObject\0voxelResolution\0minResolution\0polyRanges\0pointOverride\0precise\0", 1429LL, VoxelizationInterface, _VoxelizationInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "polyObject\0polyIslands\0voxelResolution\0minResolution\0polyRanges\0pointOverride\0", 1621LL, VoxelizationInterface, _VoxelizationInterface_Init_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "hull\0voxelResolution\0minResolution\0polyRanges\0", 149LL, VoxelizationInterface, _VoxelizationInterface_Init_2),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "facePoints\0points\0voxelResolution\0minResolution\0polyRanges\0", 597LL, VoxelizationInterface, _VoxelizationInterface_Init_3),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pos\0voxelPolys\0polyFilter\0", 25LL, VoxelizationInterface, _VoxelizationInterface_GetClosestPolys),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "toTestBox\0indexList\0", 9LL, VoxelizationInterface, _VoxelizationInterface_GetIntersectingIndices),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "toTestBox\0polyRanges\0indexList\0", 37LL, VoxelizationInterface, _VoxelizationInterface_GetIntersectingIndicesPrecise),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "point\0indexList\0", 9LL, VoxelizationInterface, _VoxelizationInterface_GetIntersectingIndices_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VoxelizationInterface, _VoxelizationInterface_GetBoundingBox),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "boundingBox\0", 0LL, VoxelizationInterface, _VoxelizationInterface_GetVoxelRangesFromBoundingBox),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VoxelizationInterface, _VoxelizationInterface_IsInitialized),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&VoxelizationInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_VoxelizationInterface(nullptr, &VoxelizationInterface::ProxyComponent::_descriptor, &RegisterReflection_VoxelizationInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
