#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_PixelFormatInterface(PixelFormatInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::PixelFormat");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class PixelFormatInterface::ProxyComponent : public maxon::Component<ProxyComponent, PixelFormatInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, PixelFormatInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const PixelFormatGroup& group, const Char* shortName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_Init_Offset), maxon::reflection::Argument::ByReference(group), maxon::reflection::Argument::ByValue(shortName)};
			(*handler_)(_fn_PixelFormatInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const PixelFormatGroup&, const Char*>::Invoke, (const void*) mt_._PixelFormatInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_Init;
		Block<const ImageChannel> GetChannels() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Block<const ImageChannel> proxy_result = maxon::PrivateIncompleteNullReturnValue<Block<const ImageChannel>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannels_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetChannels, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Block<const ImageChannel>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetChannels));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetChannels;
		const PixelFormatGroup& GetPixelFormatGroup() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			const PixelFormatGroup* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const PixelFormatGroup&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetPixelFormatGroup_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetPixelFormatGroup, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const PixelFormatGroup&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetPixelFormatGroup));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetPixelFormatGroup;
		Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<Pix*> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_CreatePix_Offset), maxon::reflection::Argument::ByValue(width), maxon::reflection::Argument::ByValue(height), maxon::reflection::Argument::ByValue(lineAlignment)};
			(*handler_)(_fn_PixelFormatInterface_CreatePix, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Pix*>, const maxon::GenericComponent*, Int, Int, Int>::Invoke, (const void*) mt_._PixelFormatInterface_CreatePix));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_CreatePix;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannelCount_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetChannelCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetChannelCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetChannelCount;
		const ChannelOffsets& GetChannelOffsets() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			const ChannelOffsets* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const ChannelOffsets&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannelOffsets_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetChannelOffsets, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const ChannelOffsets&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetChannelOffsets));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetChannelOffsets;
		BITS GetBitsPerPixel() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			BITS proxy_result = maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetBitsPerPixel_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetBitsPerPixel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<BITS, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetBitsPerPixel));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetBitsPerPixel;
		Int GetBytesPerLine(Int width, Int lineAlignment) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetBytesPerLine_Offset), maxon::reflection::Argument::ByValue(width), maxon::reflection::Argument::ByValue(lineAlignment)};
			(*handler_)(_fn_PixelFormatInterface_GetBytesPerLine, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*, Int, Int>::Invoke, (const void*) mt_._PixelFormatInterface_GetBytesPerLine));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetBytesPerLine;
		Int GetPackedPixelCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetPackedPixelCount_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetPackedPixelCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetPackedPixelCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetPackedPixelCount;
		Bool HasAlpha() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_HasAlpha_Offset)};
			(*handler_)(_fn_PixelFormatInterface_HasAlpha, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_HasAlpha));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_HasAlpha;
		Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<Tuple<PixelFormat, Int>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetAlphaPixelFormat_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetAlphaPixelFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Tuple<PixelFormat, Int>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetAlphaPixelFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetAlphaPixelFormat;
		ColorSpace GetColorSpace() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			ColorSpace proxy_result = maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetColorSpace_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetColorSpace, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<ColorSpace, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetColorSpace));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetColorSpace;
		const ColorProfile& GetDefaultColorProfile() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			const ColorProfile* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetDefaultColorProfile_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetDefaultColorProfile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const ColorProfile&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetDefaultColorProfile));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetDefaultColorProfile;
		Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<CONVERTPIXELFUNC> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelFunc_Offset), maxon::reflection::Argument::ByReference(srcFormatPtr), maxon::reflection::Argument::ByReference(srcChannelOffset), maxon::reflection::Argument::ByReference(dstChannelOffset), maxon::reflection::Argument::ByReference(srcColorProfile), maxon::reflection::Argument::ByValue(dstColorProfile), maxon::reflection::Argument::ByValue(forceColorProfileConversion), maxon::reflection::Argument::ByReference(disableCaching)};
			(*handler_)(_fn_PixelFormatInterface_GetConvertPixelFunc, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<CONVERTPIXELFUNC>, const maxon::GenericComponent*, const PixelFormat&, const ChannelOffsets&, const ChannelOffsets&, const ColorProfile&, ColorProfile*, Bool, Bool&>::Invoke, (const void*) mt_._PixelFormatInterface_GetConvertPixelFunc));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetConvertPixelFunc;
		Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_ConvertPixelFromSlow_Offset), maxon::reflection::Argument::ByReference(dst), maxon::reflection::Argument::ByValue(count), maxon::reflection::Argument::ByReference(src), maxon::reflection::Argument::ByReference(srcColorProfile), maxon::reflection::Argument::ByValue(dstColorProfile), maxon::reflection::Argument::ByValue(cflags), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_PixelFormatInterface_ConvertPixelFromSlow, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const ImageMutableBuffer&, Int, const ImageConstBuffer&, const ColorProfile&, ColorProfile*, CONVERTPIXELFLAGS, GETPIXELFLAGS>::Invoke, (const void*) mt_._PixelFormatInterface_ConvertPixelFromSlow));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_ConvertPixelFromSlow;
		Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_IsIdenticalPixel_Offset), maxon::reflection::Argument::ByReference(a), maxon::reflection::Argument::ByReference(b), maxon::reflection::Argument::ByValue(oneTolerance)};
			(*handler_)(_fn_PixelFormatInterface_IsIdenticalPixel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const ImageConstBuffer&, const ImageConstBuffer&, Int>::Invoke, (const void*) mt_._PixelFormatInterface_IsIdenticalPixel));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_IsIdenticalPixel;
		String PixToString(const Pix* src) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_PixToString_Offset), maxon::reflection::Argument::ByValue(src)};
			(*handler_)(_fn_PixelFormatInterface_PixToString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*, const Pix*>::Invoke, (const void*) mt_._PixelFormatInterface_PixToString));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_PixToString;
		Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<CONVERTPIXELFUNC> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelFromFunc_Offset), maxon::reflection::Argument::ByReference(srcFormatPtr), maxon::reflection::Argument::ByReference(srcChannelOffset), maxon::reflection::Argument::ByReference(dstChannelOffset), maxon::reflection::Argument::ByValue(fastSize), maxon::reflection::Argument::ByReference(disableCaching)};
			(*handler_)(_fn_PixelFormatInterface_GetConvertPixelFromFunc, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<CONVERTPIXELFUNC>, const maxon::GenericComponent*, const PixelFormat&, const ChannelOffsets&, const ChannelOffsets&, Bool, Bool&>::Invoke, (const void*) mt_._PixelFormatInterface_GetConvertPixelFromFunc));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetConvertPixelFromFunc;
		Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			Result<CONVERTPIXELFUNC> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelToFunc_Offset), maxon::reflection::Argument::ByReference(dstFormatPtr), maxon::reflection::Argument::ByReference(dstChannelOffset), maxon::reflection::Argument::ByReference(srcChannelOffset), maxon::reflection::Argument::ByValue(fastSize), maxon::reflection::Argument::ByReference(disableCaching)};
			(*handler_)(_fn_PixelFormatInterface_GetConvertPixelToFunc, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<CONVERTPIXELFUNC>, const maxon::GenericComponent*, const PixelFormat&, const ChannelOffsets&, const ChannelOffsets&, Bool, Bool&>::Invoke, (const void*) mt_._PixelFormatInterface_GetConvertPixelToFunc));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetConvertPixelToFunc;
		const Char* GetShortName() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatInterface>();
			const Char* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetShortName_Offset)};
			(*handler_)(_fn_PixelFormatInterface_GetShortName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatInterface_GetShortName));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatInterface_GetShortName;
	};
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_Init;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetChannels;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetPixelFormatGroup;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_CreatePix;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetChannelCount;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetChannelOffsets;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetBitsPerPixel;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetBytesPerLine;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetPackedPixelCount;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_HasAlpha;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetAlphaPixelFormat;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetColorSpace;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetDefaultColorProfile;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetConvertPixelFunc;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_ConvertPixelFromSlow;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_IsIdenticalPixel;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_PixToString;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetConvertPixelFromFunc;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetConvertPixelToFunc;
	const maxon::reflection::Function* PixelFormatInterface::ProxyComponent::_fn_PixelFormatInterface_GetShortName;
	PRIVATE_MAXON_COMPONENT_REGISTER(PixelFormatInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_PixelFormatInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "group\0shortName\0", 5LL, PixelFormatInterface, _PixelFormatInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetChannels),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetPixelFormatGroup),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "width\0height\0lineAlignment\0", 21LL, PixelFormatInterface, _PixelFormatInterface_CreatePix),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetChannelCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetChannelOffsets),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetBitsPerPixel),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "width\0lineAlignment\0", 5LL, PixelFormatInterface, _PixelFormatInterface_GetBytesPerLine),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetPackedPixelCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_HasAlpha),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetAlphaPixelFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetColorSpace),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetDefaultColorProfile),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "srcFormatPtr\0srcChannelOffset\0dstChannelOffset\0srcColorProfile\0dstColorProfile\0forceColorProfileConversion\0disableCaching\0", 10069LL, PixelFormatInterface, _PixelFormatInterface_GetConvertPixelFunc),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dst\0count\0src\0srcColorProfile\0dstColorProfile\0cflags\0flags\0", 5973LL, PixelFormatInterface, _PixelFormatInterface_ConvertPixelFromSlow),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "a\0b\0oneTolerance\0", 21LL, PixelFormatInterface, _PixelFormatInterface_IsIdenticalPixel),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "src\0", 1LL, PixelFormatInterface, _PixelFormatInterface_PixToString),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "srcFormatPtr\0srcChannelOffset\0dstChannelOffset\0fastSize\0disableCaching\0", 597LL, PixelFormatInterface, _PixelFormatInterface_GetConvertPixelFromFunc),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dstFormatPtr\0dstChannelOffset\0srcChannelOffset\0fastSize\0disableCaching\0", 597LL, PixelFormatInterface, _PixelFormatInterface_GetConvertPixelToFunc),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatInterface, _PixelFormatInterface_GetShortName),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PixelFormatInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_PixelFormatInterface(nullptr, &PixelFormatInterface::ProxyComponent::_descriptor, &RegisterReflection_PixelFormatInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_PixelFormatsInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(PixelFormatsInterface::MTable::_instance._PixelFormatsInterface_FindOrCreatePixelFormat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "channels\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PixelFormatsInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_PixelFormatsInterface("net.maxon.image.interface.pixelformats", nullptr, &RegisterReflection_PixelFormatsInterface, &PRIVATE_MAXON_MODULE);
#endif
	namespace PixelFormats
	{
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		PRIVATE_MAXON_REGISTRY_DEFINE(RGB);
	#endif
	}
}
#endif
