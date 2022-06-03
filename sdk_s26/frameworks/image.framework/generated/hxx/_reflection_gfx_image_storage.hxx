#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImagePixelStorageInterface(ImagePixelStorageInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImagePixelStorage");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImagePixelStorageInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImagePixelStorageInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImagePixelStorageInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_Init_Offset), maxon::reflection::Argument::ByValue(width), maxon::reflection::Argument::ByValue(height), maxon::reflection::Argument::ByReference(format), maxon::reflection::Argument::ByValue(defaultColor)};
			(*handler_)(_fn_ImagePixelStorageInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, Int, const PixelFormat&, const Block<Pix>*>::Invoke, (const void*) mt_.ImagePixelStorageInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_Init;
		Int GetWidth() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetWidth_Offset)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetWidth, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetWidth));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetWidth;
		Int GetHeight() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetHeight_Offset)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetHeight, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetHeight));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetHeight;
		Int GetChannelCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetChannelCount_Offset)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetChannelCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetChannelCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetChannelCount;
		PixelFormat GetPixelFormat() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			PixelFormat proxy_result = maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelFormat_Offset)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetPixelFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<PixelFormat, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetPixelFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetPixelFormat;
		Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Result<GetPixelHandlerStruct> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetPixelHandler_Offset), maxon::reflection::Argument::ByReference(dstFormat), maxon::reflection::Argument::ByReference(channelOffsets), maxon::reflection::Argument::ByReference(srcColorProfile), maxon::reflection::Argument::ByReference(dstColorProfile), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetPixelHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<GetPixelHandlerStruct>, const maxon::GenericComponent*, const PixelFormat&, const ChannelOffsets&, const ColorProfile&, const ColorProfile&, GETPIXELHANDLERFLAGS>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetPixelHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetPixelHandler;
		Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Result<SetPixelHandlerStruct> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetPixelHandler_Offset), maxon::reflection::Argument::ByReference(srcFormat), maxon::reflection::Argument::ByReference(channelOffsets), maxon::reflection::Argument::ByReference(srcColorProfile), maxon::reflection::Argument::ByReference(dstColorProfile), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(updateRegionNotification)};
			(*handler_)(_fn_ImagePixelStorageInterface_SetPixelHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<SetPixelHandlerStruct>, maxon::GenericComponent*, const PixelFormat&, const ChannelOffsets&, const ColorProfile&, const ColorProfile&, SETPIXELHANDLERFLAGS, const Delegate<void(const UpdateRegion&)>&>::Invoke, (const void*) mt_.ImagePixelStorageInterface_SetPixelHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_SetPixelHandler;
/// @cond INTERNAL

		void FreePixelHandler(GetPixelHandlerStruct& pixel) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_Offset), maxon::reflection::Argument::ByReference(pixel)};
			(*handler_)(_fn_ImagePixelStorageInterface_FreePixelHandler, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, GetPixelHandlerStruct&>::Invoke, (const void*) mt_.ImagePixelStorageInterface_FreePixelHandler));
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_FreePixelHandler;
		void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_FreePixelHandler_1_Offset), maxon::reflection::Argument::ByReference(pixel), maxon::reflection::Argument::ByReference(updateRegionNotification)};
			(*handler_)(_fn_ImagePixelStorageInterface_FreePixelHandler_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, SetPixelHandlerStruct&, const Delegate<void(const UpdateRegion&)>&>::Invoke, (const void*) mt_.ImagePixelStorageInterface_FreePixelHandler_1));
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_FreePixelHandler_1;
/// @endcond

		Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_GetComponent_Offset), maxon::reflection::Argument::ByValue(component), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(inc), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImagePixelStorageInterface_GetComponent, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, Int, const ImagePos&, Pix*, Int, GETPIXELFLAGS>::Invoke, (const void*) mt_.ImagePixelStorageInterface_GetComponent));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_GetComponent;
		Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImagePixelStorageInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImagePixelStorageInterface_SetComponent_Offset), maxon::reflection::Argument::ByValue(component), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(inc), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImagePixelStorageInterface_SetComponent, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, const ImagePos&, const Pix*, Int, SETPIXELFLAGS>::Invoke, (const void*) mt_.ImagePixelStorageInterface_SetComponent));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImagePixelStorageInterface_SetComponent;
	};
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_Init;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetWidth;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetHeight;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetChannelCount;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetPixelFormat;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetPixelHandler;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_SetPixelHandler;
/// @cond INTERNAL

	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_FreePixelHandler;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_FreePixelHandler_1;
/// @endcond

	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_GetComponent;
	const maxon::reflection::Function* ImagePixelStorageInterface::ProxyComponent::_fn_ImagePixelStorageInterface_SetComponent;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImagePixelStorageInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImagePixelStorageInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "width\0height\0format\0defaultColor\0", 85LL, ImagePixelStorageInterface, ImagePixelStorageInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetWidth),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetHeight),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetChannelCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetPixelFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dstFormat\0channelOffsets\0srcColorProfile\0dstColorProfile\0flags\0", 341LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetPixelHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "srcFormat\0channelOffsets\0srcColorProfile\0dstColorProfile\0flags\0updateRegionNotification\0", 341LL, ImagePixelStorageInterface, ImagePixelStorageInterface_SetPixelHandler),
/// @cond INTERNAL

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pixel\0", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_FreePixelHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pixel\0updateRegionNotification\0", 0LL, ImagePixelStorageInterface, ImagePixelStorageInterface_FreePixelHandler_1),
/// @endcond

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "component\0pos\0data\0inc\0flags\0", 341LL, ImagePixelStorageInterface, ImagePixelStorageInterface_GetComponent),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "component\0pos\0data\0inc\0flags\0", 341LL, ImagePixelStorageInterface, ImagePixelStorageInterface_SetComponent),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImagePixelStorageInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImagePixelStorageInterface(nullptr, &ImagePixelStorageInterface::ProxyComponent::_descriptor, &RegisterReflection_ImagePixelStorageInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImagePixelStorageClasses);
#endif
}
#endif
