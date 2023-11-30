#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageBaseInterface(ImageBaseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageBaseRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageBaseInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageBaseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageBaseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_InitBase_Offset), maxon::reflection::Argument::ByValue(width), maxon::reflection::Argument::ByValue(height), maxon::reflection::Argument::ByReference(pixelFormat), maxon::reflection::Argument::ByValue(type)};
			(*handler_)(_fn_ImageBaseInterface_InitBase, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Int, Int, const PixelFormat&, IMAGEPROPERTIES::ITYPE), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_InitBase)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_InitBase;
		Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_AddChildren_Offset), maxon::reflection::Argument::ByValue(hierarchy), maxon::reflection::Argument::ByReference(newChildren), maxon::reflection::Argument::ByReference(insertBefore)};
			(*handler_)(_fn_ImageBaseInterface_AddChildren, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), IMAGEHIERARCHY, const ImageBaseRef&, const ImageBaseRef&), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_AddChildren)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_AddChildren;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetWidth_Offset)};
			(*handler_)(_fn_ImageBaseInterface_GetWidth, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetWidth)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetWidth;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetHeight_Offset)};
			(*handler_)(_fn_ImageBaseInterface_GetHeight, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetHeight)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetHeight;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetChannelCount_Offset)};
			(*handler_)(_fn_ImageBaseInterface_GetChannelCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetChannelCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetChannelCount;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			PixelFormat proxy_result = HXXRET3(NULLIMPL, PixelFormat);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetPixelFormat_Offset)};
			(*handler_)(_fn_ImageBaseInterface_GetPixelFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((PixelFormat)), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetPixelFormat)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetPixelFormat;
		Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<GetPixelHandlerStruct> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetPixelHandler_Offset), maxon::reflection::Argument::ByReference(dstFormat), maxon::reflection::Argument::ByReference(channelOffsets), maxon::reflection::Argument::ByReference(dstColorProfile), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByValue(layerSet)};
			(*handler_)(_fn_ImageBaseInterface_GetPixelHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<GetPixelHandlerStruct>), const PixelFormat&, const ChannelOffsets&, const ColorProfile&, GETPIXELHANDLERFLAGS, const LayerSetInterface*), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetPixelHandler)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetPixelHandler;
		Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<SetPixelHandlerStruct> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetPixelHandler_Offset), maxon::reflection::Argument::ByReference(srcFormat), maxon::reflection::Argument::ByReference(channelOffsets), maxon::reflection::Argument::ByReference(srcColorProfile), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImageBaseInterface_SetPixelHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<SetPixelHandlerStruct>), const PixelFormat&, const ChannelOffsets&, const ColorProfile&, SETPIXELHANDLERFLAGS), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_SetPixelHandler)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_SetPixelHandler;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_FreePixelHandler_Offset), maxon::reflection::Argument::ByReference(pixel)};
			(*handler_)(_fn_ImageBaseInterface_FreePixelHandler, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), GetPixelHandlerStruct&), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_FreePixelHandler)));
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_FreePixelHandler;
		void FreePixelHandler(SetPixelHandlerStruct& pixel) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_FreePixelHandler_1_Offset), maxon::reflection::Argument::ByReference(pixel)};
			(*handler_)(_fn_ImageBaseInterface_FreePixelHandler_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), SetPixelHandlerStruct&), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_FreePixelHandler_1)));
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_FreePixelHandler_1;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_GetComponent_Offset), maxon::reflection::Argument::ByValue(component), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(inc), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImageBaseInterface_GetComponent, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Int, const ImagePos&, Pix*, Int, GETPIXELFLAGS), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_GetComponent)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_GetComponent;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_SetComponent_Offset), maxon::reflection::Argument::ByValue(component), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(inc), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImageBaseInterface_SetComponent, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Int, const ImagePos&, const Pix*, Int, SETPIXELFLAGS), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_SetComponent)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_SetComponent;
		Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<ImageBaseRef> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_CreateSubImagePart_Offset), maxon::reflection::Argument::ByReference(rect)};
			(*handler_)(_fn_ImageBaseInterface_CreateSubImagePart, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<ImageBaseRef>), const DrawRectInt&), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_CreateSubImagePart)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_CreateSubImagePart;
		Result<ImageBaseRef> TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			Result<ImageBaseRef> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_TransformColors_Offset), maxon::reflection::Argument::ByReference(srcProfile), maxon::reflection::Argument::ByReference(dstProfile), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_ImageBaseInterface_TransformColors, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<ImageBaseRef>), const ColorProfile&, const ColorProfile&, TRANSFORM_COLORS_FLAGS), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_TransformColors)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_TransformColors;
		maxon::ObservableRef<ObservableRegionChangedDelegate> ObservableRegionChanged(Bool create) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageBaseInterface>();
			maxon::ObservableRef<ObservableRegionChangedDelegate> proxy_result = maxon::ObservableRef<ObservableRegionChangedDelegate>::DefaultValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageBaseInterface_ObservableRegionChanged_Offset), maxon::reflection::Argument::ByValue(create)};
			(*handler_)(_fn_ImageBaseInterface_ObservableRegionChanged, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((maxon::ObservableRef<ObservableRegionChangedDelegate>), Bool), reinterpret_cast<const void* const&>(mt_.ImageBaseInterface_ObservableRegionChanged)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageBaseInterface_ObservableRegionChanged;
	};
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_InitBase;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_AddChildren;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetWidth;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetHeight;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetChannelCount;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetPixelFormat;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetPixelHandler;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_SetPixelHandler;
/// @cond INTERNAL

	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_FreePixelHandler;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_FreePixelHandler_1;
/// @endcond

	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_GetComponent;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_SetComponent;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_CreateSubImagePart;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_TransformColors;
	const maxon::reflection::Function* ImageBaseInterface::ProxyComponent::_fn_ImageBaseInterface_ObservableRegionChanged;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageBaseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageBaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "width\0height\0pixelFormat\0type\0", 85LL, ImageBaseInterface, ImageBaseInterface_InitBase),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "hierarchy\0newChildren\0insertBefore\0", 21LL, ImageBaseInterface, ImageBaseInterface_AddChildren),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImageBaseInterface, ImageBaseInterface_GetWidth),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImageBaseInterface, ImageBaseInterface_GetHeight),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImageBaseInterface, ImageBaseInterface_GetChannelCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ImageBaseInterface, ImageBaseInterface_GetPixelFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dstFormat\0channelOffsets\0dstColorProfile\0flags\0layerSet\0", 341LL, ImageBaseInterface, ImageBaseInterface_GetPixelHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "srcFormat\0channelOffsets\0srcColorProfile\0flags\0", 85LL, ImageBaseInterface, ImageBaseInterface_SetPixelHandler),
/// @cond INTERNAL

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pixel\0", 0LL, ImageBaseInterface, ImageBaseInterface_FreePixelHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pixel\0", 0LL, ImageBaseInterface, ImageBaseInterface_FreePixelHandler_1),
/// @endcond

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "component\0pos\0data\0inc\0flags\0", 341LL, ImageBaseInterface, ImageBaseInterface_GetComponent),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "component\0pos\0data\0inc\0flags\0", 341LL, ImageBaseInterface, ImageBaseInterface_SetComponent),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "rect\0", 1LL, ImageBaseInterface, ImageBaseInterface_CreateSubImagePart),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "srcProfile\0dstProfile\0flags\0", 21LL, ImageBaseInterface, ImageBaseInterface_TransformColors),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "create\0", 0LL, ImageBaseInterface, ImageBaseInterface_ObservableRegionChanged),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageBaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageBaseInterface(nullptr, &ImageBaseInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageBaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageTextureInterface(ImageTextureInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageTextureRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageTextureInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageTextureInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageTextureInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageTextureInterface>();
			Result<MediaSessionRef> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageTextureInterface_Load_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByReference(targetTime), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(pixelStorageClass), maxon::reflection::Argument::ByValue(layerSet)};
			(*handler_)(_fn_ImageTextureInterface_Load, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<MediaSessionRef>), const Url&, const TimeValue&, MEDIASESSIONFLAGS, const Class<ImagePixelStorage>&, const LayerSetInterface*), reinterpret_cast<const void* const&>(mt_.ImageTextureInterface_Load)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageTextureInterface_Load;
		Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageTextureInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageTextureInterface_Save_Offset), maxon::reflection::Argument::ByReference(fileFormat), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByValue(returnOpenSession)};
			(*handler_)(_fn_ImageTextureInterface_Save, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const MediaOutputRef&, MEDIASESSIONFLAGS, MediaSessionRef*), reinterpret_cast<const void* const&>(mt_.ImageTextureInterface_Save)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageTextureInterface_Save;
	};
	const maxon::reflection::Function* ImageTextureInterface::ProxyComponent::_fn_ImageTextureInterface_Load;
	const maxon::reflection::Function* ImageTextureInterface::ProxyComponent::_fn_ImageTextureInterface_Save;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageTextureInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImageTextureInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ImageTextureInterface::Hxx2::StaticMTable::_instance.ImageTextureInterface_LoadTexture)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "name\0targetTime\0flags\0pixelStorageClass\0layerSet\0", 341LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageTextureInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageTextureInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0targetTime\0flags\0pixelStorageClass\0layerSet\0", 341LL, ImageTextureInterface, ImageTextureInterface_Load),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "fileFormat\0flags\0returnOpenSession\0", 21LL, ImageTextureInterface, ImageTextureInterface_Save),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageTextureInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageTextureInterface(nullptr, &ImageTextureInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageTextureInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImageTextureInterface_Static("net.maxon.image.interface.imagetexture", nullptr, &RegisterReflection_ImageTextureInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageInterface(ImageInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ImageInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageInterface_Init_Offset), maxon::reflection::Argument::ByValue(width), maxon::reflection::Argument::ByValue(height), maxon::reflection::Argument::ByReference(storageFormat), maxon::reflection::Argument::ByReference(pixelFormat), maxon::reflection::Argument::ByValue(defaultColor)};
			(*handler_)(_fn_ImageInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Int, Int, const Class<ImagePixelStorage>&, const PixelFormat&, const Block<Pix>*), reinterpret_cast<const void* const&>(mt_.ImageInterface_Init)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ImageInterface_Init;
	};
	const maxon::reflection::Function* ImageInterface::ProxyComponent::_fn_ImageInterface_Init;
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "width\0height\0storageFormat\0pixelFormat\0defaultColor\0", 341LL, ImageInterface, ImageInterface_Init),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageInterface(nullptr, &ImageInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImageLayerInterface(ImageLayerInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImageLayerRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImageLayerInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImageLayerInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImageLayerInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ImageLayerInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImageLayerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageLayerInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImageLayerInterface(nullptr, &ImageLayerInterface::ProxyComponent::_descriptor, &RegisterReflection_ImageLayerInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ImageFunctionsInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ImageFunctionsInterface::MTable::_instance.ImageFunctionsInterface_CreateSubImagePart)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "imageRef\0rect\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImageFunctionsInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ImageFunctionsInterface("net.maxon.image.interface.imagefunctions", nullptr, &RegisterReflection_ImageFunctionsInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImageBaseClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImageTextureClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImageClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ImageLayerClasses);
#endif
}
#endif
