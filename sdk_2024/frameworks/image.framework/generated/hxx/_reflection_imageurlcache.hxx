#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageUrlCacheInterface(ImageUrlCacheInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageUrlCacheRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageUrlCacheInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageUrlCacheInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageUrlCacheInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache(Bool create) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageUrlCacheInterface>();
			maxon::ObservableRef<ObservableFreeCacheDelegate> proxy_result = maxon::ObservableRef<ObservableFreeCacheDelegate>::DefaultValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset), maxon::reflection::Argument::ByValue(create)};
			(*handler_)(_fn_ImageUrlCacheInterface_ObservableFreeCache, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((maxon::ObservableRef<ObservableFreeCacheDelegate>), Bool), reinterpret_cast<const void* const&>(mt_.ImageUrlCacheInterface_ObservableFreeCache)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageUrlCacheInterface_ObservableFreeCache;
		Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageUrlCacheInterface>();
			Result<Opt<ImageBaseRef>> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_Offset), maxon::reflection::Argument::ByReference(updateDelegate)};
			(*handler_)(_fn_ImageUrlCacheInterface_GetImage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&&), reinterpret_cast<const void* const&>(mt_.ImageUrlCacheInterface_GetImage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageUrlCacheInterface_GetImage;
		Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageUrlCacheInterface>();
			Result<Opt<ImageBaseRef>> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_1_Offset), maxon::reflection::Argument::ByReference(updateDelegate), maxon::reflection::Argument::ByValue(async)};
			(*handler_)(_fn_ImageUrlCacheInterface_GetImage_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&&, Bool), reinterpret_cast<const void* const&>(mt_.ImageUrlCacheInterface_GetImage_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageUrlCacheInterface_GetImage_1;
	};
	const maxon::reflection::Function* ImageUrlCacheInterface::ProxyComponent::_fn_ImageUrlCacheInterface_ObservableFreeCache;
	const maxon::reflection::Function* ImageUrlCacheInterface::ProxyComponent::_fn_ImageUrlCacheInterface_GetImage;
	const maxon::reflection::Function* ImageUrlCacheInterface::ProxyComponent::_fn_ImageUrlCacheInterface_GetImage_1;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageUrlCacheInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImageUrlCacheInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ImageUrlCacheInterface::Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_InvalidateCache)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ImageUrlCacheInterface::Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_FindOrCreate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageUrlCacheInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageUrlCacheInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "create\0", 0LL, ImageUrlCacheInterface, ImageUrlCacheInterface_ObservableFreeCache),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "updateDelegate\0", 1LL, ImageUrlCacheInterface, ImageUrlCacheInterface_GetImage),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "updateDelegate\0async\0", 5LL, ImageUrlCacheInterface, ImageUrlCacheInterface_GetImage_1),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageUrlCacheInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageUrlCacheInterface(nullptr, &ImageUrlCacheInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageUrlCacheInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImageUrlCacheInterface_Static("net.maxon.image.interface.imageurlcache", nullptr, &RegisterReflection_ImageUrlCacheInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
