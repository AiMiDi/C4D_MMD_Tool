#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageRegionTilesObserverInterface(ImageRegionTilesObserverInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageRegionTilesObserverRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageRegionTilesObserverInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageRegionTilesObserverInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageRegionTilesObserverInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(Int tileSize) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionTilesObserverInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_Init_Offset), maxon::reflection::Argument::ByValue(tileSize)};
			(*handler_)(_fn_ImageRegionTilesObserverInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int>::Invoke, (const void*) mt_.ImageRegionTilesObserverInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageRegionTilesObserverInterface_Init;
		Result<void> GetAndResetDirtyState(DirtyState& dirtyState) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionTilesObserverInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset), maxon::reflection::Argument::ByReference(dirtyState)};
			(*handler_)(_fn_ImageRegionTilesObserverInterface_GetAndResetDirtyState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, DirtyState&>::Invoke, (const void*) mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageRegionTilesObserverInterface_GetAndResetDirtyState;
	};
	const maxon::reflection::Function* ImageRegionTilesObserverInterface::ProxyComponent::_fn_ImageRegionTilesObserverInterface_Init;
	const maxon::reflection::Function* ImageRegionTilesObserverInterface::ProxyComponent::_fn_ImageRegionTilesObserverInterface_GetAndResetDirtyState;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageRegionTilesObserverInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageRegionTilesObserverInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tileSize\0", 1LL, ImageRegionTilesObserverInterface, ImageRegionTilesObserverInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dirtyState\0", 2LL, ImageRegionTilesObserverInterface, ImageRegionTilesObserverInterface_GetAndResetDirtyState),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageRegionTilesObserverInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageRegionTilesObserverInterface(nullptr, &ImageRegionTilesObserverInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageRegionTilesObserverInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
