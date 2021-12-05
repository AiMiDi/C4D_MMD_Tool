#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_PixelFormatIndexedColorInterface(PixelFormatIndexedColorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class PixelFormatIndexedColorInterface::ProxyComponent : public maxon::Component<ProxyComponent, PixelFormatIndexedColorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, PixelFormatIndexedColorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatIndexedColorInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset), maxon::reflection::Argument::ByValue(count), maxon::reflection::Argument::ByReference(srcFormatPtr)};
			(*handler_)(_fn_PixelFormatIndexedColorInterface_InitColorTable, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, const PixelFormat&>::Invoke, (const void*) mt_._PixelFormatIndexedColorInterface_InitColorTable));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatIndexedColorInterface_InitColorTable;
		PixelFormat GetColorTablePixelFormat() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatIndexedColorInterface>();
			PixelFormat proxy_result = maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset)};
			(*handler_)(_fn_PixelFormatIndexedColorInterface_GetColorTablePixelFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<PixelFormat, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatIndexedColorInterface_GetColorTablePixelFormat;
		Int GetColorTableSize() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatIndexedColorInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTableSize_Offset)};
			(*handler_)(_fn_PixelFormatIndexedColorInterface_GetColorTableSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PixelFormatIndexedColorInterface_GetColorTableSize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatIndexedColorInterface_GetColorTableSize;
		Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatIndexedColorInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset), maxon::reflection::Argument::ByValue(idx), maxon::reflection::Argument::ByReference(srcPixelData)};
			(*handler_)(_fn_PixelFormatIndexedColorInterface_SetIndex, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int, const ImageConstBuffer&>::Invoke, (const void*) mt_._PixelFormatIndexedColorInterface_SetIndex));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatIndexedColorInterface_SetIndex;
		Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatIndexedColorInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetIndex_Offset), maxon::reflection::Argument::ByValue(idx), maxon::reflection::Argument::ByReference(dstPixelData)};
			(*handler_)(_fn_PixelFormatIndexedColorInterface_GetIndex, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, Int, const ImageMutableBuffer&>::Invoke, (const void*) mt_._PixelFormatIndexedColorInterface_GetIndex));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatIndexedColorInterface_GetIndex;
	};
	const maxon::reflection::Function* PixelFormatIndexedColorInterface::ProxyComponent::_fn_PixelFormatIndexedColorInterface_InitColorTable;
	const maxon::reflection::Function* PixelFormatIndexedColorInterface::ProxyComponent::_fn_PixelFormatIndexedColorInterface_GetColorTablePixelFormat;
	const maxon::reflection::Function* PixelFormatIndexedColorInterface::ProxyComponent::_fn_PixelFormatIndexedColorInterface_GetColorTableSize;
	const maxon::reflection::Function* PixelFormatIndexedColorInterface::ProxyComponent::_fn_PixelFormatIndexedColorInterface_SetIndex;
	const maxon::reflection::Function* PixelFormatIndexedColorInterface::ProxyComponent::_fn_PixelFormatIndexedColorInterface_GetIndex;
	PRIVATE_MAXON_COMPONENT_REGISTER(PixelFormatIndexedColorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_PixelFormatIndexedColorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "count\0srcFormatPtr\0", 5LL, PixelFormatIndexedColorInterface, _PixelFormatIndexedColorInterface_InitColorTable),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatIndexedColorInterface, _PixelFormatIndexedColorInterface_GetColorTablePixelFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PixelFormatIndexedColorInterface, _PixelFormatIndexedColorInterface_GetColorTableSize),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "idx\0srcPixelData\0", 5LL, PixelFormatIndexedColorInterface, _PixelFormatIndexedColorInterface_SetIndex),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "idx\0dstPixelData\0", 5LL, PixelFormatIndexedColorInterface, _PixelFormatIndexedColorInterface_GetIndex),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PixelFormatIndexedColorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_PixelFormatIndexedColorInterface(nullptr, &PixelFormatIndexedColorInterface::ProxyComponent::_descriptor, &RegisterReflection_PixelFormatIndexedColorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
