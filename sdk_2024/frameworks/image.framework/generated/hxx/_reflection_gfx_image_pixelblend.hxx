#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImagePixelBlendInterface(ImagePixelBlendInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImagePixelBlend");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImagePixelBlendInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImagePixelBlendInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImagePixelBlendInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelBlendInterface>();
			Result<BlendPixelHandlerStruct> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelBlendInterface_GetBlendPixelHandler_Offset), maxon::reflection::Argument::ByReference(bgFormat), maxon::reflection::Argument::ByReference(bgChannelOffsets), maxon::reflection::Argument::ByReference(fgFormat), maxon::reflection::Argument::ByReference(fgChannelOffsets), maxon::reflection::Argument::ByValue(opacity)};
			(*handler_)(_fn_ImagePixelBlendInterface_GetBlendPixelHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<BlendPixelHandlerStruct>), const PixelFormat&, const ChannelOffsets&, const PixelFormat&, const ChannelOffsets&, Float), reinterpret_cast<const void* const&>(mt_.ImagePixelBlendInterface_GetBlendPixelHandler)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelBlendInterface_GetBlendPixelHandler;
	};
	const maxon::reflection::Function* ImagePixelBlendInterface::ProxyComponent::_fn_ImagePixelBlendInterface_GetBlendPixelHandler;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImagePixelBlendInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImagePixelBlendInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ImagePixelBlendInterface::Hxx2::StaticMTable::_instance.ImagePixelBlendInterface_GetOptimalPixelFormat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "formats\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImagePixelBlendInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImagePixelBlendInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "bgFormat\0bgChannelOffsets\0fgFormat\0fgChannelOffsets\0opacity\0", 341LL, ImagePixelBlendInterface, ImagePixelBlendInterface_GetBlendPixelHandler),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImagePixelBlendInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImagePixelBlendInterface(nullptr, &ImagePixelBlendInterface::ProxyComponent::_descriptor, &RegisterReflection_ImagePixelBlendInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImagePixelBlendInterface_Static("net.maxon.image.interface.imagepixelblend", nullptr, &RegisterReflection_ImagePixelBlendInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImagePixelBlends);
#endif
}
#endif
