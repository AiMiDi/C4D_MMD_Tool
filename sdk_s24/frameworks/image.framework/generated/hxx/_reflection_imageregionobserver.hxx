#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageRegionObserverInterface(ImageRegionObserverInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageRegionObserverRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageRegionObserverInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageRegionObserverInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageRegionObserverInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> OnConnect(const IntVector2d& dimensions) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionObserverInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnConnect_Offset), maxon::reflection::Argument::ByReference(dimensions)};
			(*handler_)(_fn_ImageRegionObserverInterface_OnConnect, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const IntVector2d&>::Invoke, (const void*) mt_._ImageRegionObserverInterface_OnConnect));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageRegionObserverInterface_OnConnect;
		void OnResize(const IntVector2d& dimensions) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionObserverInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnResize_Offset), maxon::reflection::Argument::ByReference(dimensions)};
			(*handler_)(_fn_ImageRegionObserverInterface_OnResize, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const IntVector2d&>::Invoke, (const void*) mt_._ImageRegionObserverInterface_OnResize));
		}
		static const maxon::reflection::Function* _fn_ImageRegionObserverInterface_OnResize;
		void OnRegionDirty(const Range<IntVector2d>& dirtyRegion) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionObserverInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnRegionDirty_Offset), maxon::reflection::Argument::ByReference(dirtyRegion)};
			(*handler_)(_fn_ImageRegionObserverInterface_OnRegionDirty, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const Range<IntVector2d>&>::Invoke, (const void*) mt_._ImageRegionObserverInterface_OnRegionDirty));
		}
		static const maxon::reflection::Function* _fn_ImageRegionObserverInterface_OnRegionDirty;
		void OnDisconnect() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageRegionObserverInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnDisconnect_Offset)};
			(*handler_)(_fn_ImageRegionObserverInterface_OnDisconnect, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._ImageRegionObserverInterface_OnDisconnect));
		}
		static const maxon::reflection::Function* _fn_ImageRegionObserverInterface_OnDisconnect;
	};
	const maxon::reflection::Function* ImageRegionObserverInterface::ProxyComponent::_fn_ImageRegionObserverInterface_OnConnect;
	const maxon::reflection::Function* ImageRegionObserverInterface::ProxyComponent::_fn_ImageRegionObserverInterface_OnResize;
	const maxon::reflection::Function* ImageRegionObserverInterface::ProxyComponent::_fn_ImageRegionObserverInterface_OnRegionDirty;
	const maxon::reflection::Function* ImageRegionObserverInterface::ProxyComponent::_fn_ImageRegionObserverInterface_OnDisconnect;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageRegionObserverInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageRegionObserverInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dimensions\0", 1LL, ImageRegionObserverInterface, _ImageRegionObserverInterface_OnConnect),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dimensions\0", 1LL, ImageRegionObserverInterface, _ImageRegionObserverInterface_OnResize),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dirtyRegion\0", 1LL, ImageRegionObserverInterface, _ImageRegionObserverInterface_OnRegionDirty),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, ImageRegionObserverInterface, _ImageRegionObserverInterface_OnDisconnect),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageRegionObserverInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageRegionObserverInterface(nullptr, &ImageRegionObserverInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageRegionObserverInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImageRegionObservableInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableInterface::MTable::_instance._ImageRegionObservableInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableInterface::MTable::_instance._ImageRegionObservableInterface_RegisterObserver)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "observerId\0observer\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageRegionObservableInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImageRegionObservableInterface("net.maxon.interface.imageregionobservable", nullptr, &RegisterReflection_ImageRegionObservableInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImageRegionObservableHandlerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableHandlerInterface::MTable::_instance._ImageRegionObservableHandlerInterface_Create)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dimensions\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableHandlerInterface::MTable::_instance._ImageRegionObservableHandlerInterface_ResizeImage)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "dimensions\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableHandlerInterface::MTable::_instance._ImageRegionObservableHandlerInterface_MarkDirty)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "dirtyRegion\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ImageRegionObservableHandlerInterface::MTable::_instance._ImageRegionObservableHandlerInterface_GetObservable)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageRegionObservableHandlerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImageRegionObservableHandlerInterface("net.maxon.interface.imageregionobservablehandler", nullptr, &RegisterReflection_ImageRegionObservableHandlerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
