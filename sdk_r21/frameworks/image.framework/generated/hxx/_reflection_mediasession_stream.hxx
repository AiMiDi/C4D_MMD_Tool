#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamInterface(MediaStreamInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<BaseArray<Data>> GetFormats() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Result<BaseArray<Data>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_GetFormats_Offset)};
			(*handler_)(_fn_MediaStreamInterface_GetFormats, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<Data>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamInterface_GetFormats));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_GetFormats;
		MediaStreamFormat GetFormat(const Data& formatId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			MediaStreamFormat proxy_result = maxon::PrivateIncompleteNullReturnValue<MediaStreamFormat>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_GetFormat_Offset), maxon::reflection::Argument::ByReference(formatId)};
			(*handler_)(_fn_MediaStreamInterface_GetFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MediaStreamFormat, const maxon::GenericComponent*, const Data&>::Invoke, (const void*) mt_._MediaStreamInterface_GetFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_GetFormat;
		const Data& GetSelectedFormat() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			const Data* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Data&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_GetSelectedFormat_Offset)};
			(*handler_)(_fn_MediaStreamInterface_GetSelectedFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Data&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamInterface_GetSelectedFormat));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_GetSelectedFormat;
		Result<void> SetSelectedFormat(const Data& formatId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_SetSelectedFormat_Offset), maxon::reflection::Argument::ByReference(formatId)};
			(*handler_)(_fn_MediaStreamInterface_SetSelectedFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Data&>::Invoke, (const void*) mt_._MediaStreamInterface_SetSelectedFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_SetSelectedFormat;
		Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_AddFormat_Offset), maxon::reflection::Argument::ByReference(formatId), maxon::reflection::Argument::ByReference(ref)};
			(*handler_)(_fn_MediaStreamInterface_AddFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Data&, const MediaStreamFormat&>::Invoke, (const void*) mt_._MediaStreamInterface_AddFormat));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_AddFormat;
		Result<void> SubscribeStream(const Data& formatId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_SubscribeStream_Offset), maxon::reflection::Argument::ByReference(formatId)};
			(*handler_)(_fn_MediaStreamInterface_SubscribeStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Data&>::Invoke, (const void*) mt_._MediaStreamInterface_SubscribeStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_SubscribeStream;
		Result<void> UnsubscribeStream() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_UnsubscribeStream_Offset)};
			(*handler_)(_fn_MediaStreamInterface_UnsubscribeStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamInterface_UnsubscribeStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_UnsubscribeStream;
		Bool IsSubscribed() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamInterface_IsSubscribed_Offset)};
			(*handler_)(_fn_MediaStreamInterface_IsSubscribed, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamInterface_IsSubscribed));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamInterface_IsSubscribed;
	};
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_GetFormats;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_GetFormat;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_GetSelectedFormat;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_SetSelectedFormat;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_AddFormat;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_SubscribeStream;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_UnsubscribeStream;
	const maxon::reflection::Function* MediaStreamInterface::ProxyComponent::_fn_MediaStreamInterface_IsSubscribed;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaStreamInterface, _MediaStreamInterface_GetFormats),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "formatId\0", 0LL, MediaStreamInterface, _MediaStreamInterface_GetFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaStreamInterface, _MediaStreamInterface_GetSelectedFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "formatId\0", 0LL, MediaStreamInterface, _MediaStreamInterface_SetSelectedFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "formatId\0ref\0", 0LL, MediaStreamInterface, _MediaStreamInterface_AddFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "formatId\0", 1LL, MediaStreamInterface, _MediaStreamInterface_SubscribeStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MediaStreamInterface, _MediaStreamInterface_UnsubscribeStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaStreamInterface, _MediaStreamInterface_IsSubscribed),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamInterface(nullptr, &MediaStreamInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamExifDataInterface(MediaStreamExifDataInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamExifDataInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamExifDataInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamExifDataInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamExifDataInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamExifDataInterface_SetCallbackHandler_Offset), maxon::reflection::Argument::ByReference(handleExifData)};
			(*handler_)(_fn_MediaStreamExifDataInterface_SetCallbackHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const ExifDataHandler&>::Invoke, (const void*) mt_._MediaStreamExifDataInterface_SetCallbackHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamExifDataInterface_SetCallbackHandler;
		Result<void> HandleExifData(const ExifRef& exifData) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamExifDataInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamExifDataInterface_HandleExifData_Offset), maxon::reflection::Argument::ByReference(exifData)};
			(*handler_)(_fn_MediaStreamExifDataInterface_HandleExifData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const ExifRef&>::Invoke, (const void*) mt_._MediaStreamExifDataInterface_HandleExifData));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamExifDataInterface_HandleExifData;
		Result<void> FinishStream(const MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamExifDataInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamExifDataInterface_FinishStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamExifDataInterface_FinishStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamExifDataInterface_FinishStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamExifDataInterface_FinishStream;
	};
	const maxon::reflection::Function* MediaStreamExifDataInterface::ProxyComponent::_fn_MediaStreamExifDataInterface_SetCallbackHandler;
	const maxon::reflection::Function* MediaStreamExifDataInterface::ProxyComponent::_fn_MediaStreamExifDataInterface_HandleExifData;
	const maxon::reflection::Function* MediaStreamExifDataInterface::ProxyComponent::_fn_MediaStreamExifDataInterface_FinishStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamExifDataInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamExifDataInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "handleExifData\0", 1LL, MediaStreamExifDataInterface, _MediaStreamExifDataInterface_SetCallbackHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "exifData\0", 0LL, MediaStreamExifDataInterface, _MediaStreamExifDataInterface_HandleExifData),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 0LL, MediaStreamExifDataInterface, _MediaStreamExifDataInterface_FinishStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamExifDataInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamExifDataInterface(nullptr, &MediaStreamExifDataInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamExifDataInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamImageBaseInterface(MediaStreamImageBaseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamImageBaseInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamImageBaseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamImageBaseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamImageBaseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamImageBaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamImageBaseInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamImageBaseInterface(nullptr, &MediaStreamImageBaseInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamImageBaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamImageDataImportInterface(MediaStreamImageDataImportInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamImageDataImportInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamImageDataImportInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamImageDataImportInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataImportInterface_SetCallbackHandler_Offset), maxon::reflection::Argument::ByReference(initHandler), maxon::reflection::Argument::ByReference(setPixelHandler), maxon::reflection::Argument::ByReference(finishHandler)};
			(*handler_)(_fn_MediaStreamImageDataImportInterface_SetCallbackHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const InitHandler&, const SetPixelHandler&, const FinishHandler&>::Invoke, (const void*) mt_._MediaStreamImageDataImportInterface_SetCallbackHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataImportInterface_SetCallbackHandler;
		Result<void> InitStream(const MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataImportInterface_InitStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamImageDataImportInterface_InitStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamImageDataImportInterface_InitStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataImportInterface_InitStream;
		Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataImportInterface>();
			Result<SetPixelHandlerStruct> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataImportInterface_SetPixelStream_Offset), maxon::reflection::Argument::ByReference(props), maxon::reflection::Argument::ByReference(srcChannelOffsets), maxon::reflection::Argument::ByValue(setPixelFlags)};
			(*handler_)(_fn_MediaStreamImageDataImportInterface_SetPixelStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<SetPixelHandlerStruct>, maxon::GenericComponent*, const MediaStreamProperties&, const ChannelOffsets&, SETPIXELHANDLERFLAGS>::Invoke, (const void*) mt_._MediaStreamImageDataImportInterface_SetPixelStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataImportInterface_SetPixelStream;
		Result<void> FinishStream(const MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataImportInterface_FinishStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamImageDataImportInterface_FinishStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamImageDataImportInterface_FinishStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataImportInterface_FinishStream;
	};
	const maxon::reflection::Function* MediaStreamImageDataImportInterface::ProxyComponent::_fn_MediaStreamImageDataImportInterface_SetCallbackHandler;
	const maxon::reflection::Function* MediaStreamImageDataImportInterface::ProxyComponent::_fn_MediaStreamImageDataImportInterface_InitStream;
	const maxon::reflection::Function* MediaStreamImageDataImportInterface::ProxyComponent::_fn_MediaStreamImageDataImportInterface_SetPixelStream;
	const maxon::reflection::Function* MediaStreamImageDataImportInterface::ProxyComponent::_fn_MediaStreamImageDataImportInterface_FinishStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamImageDataImportInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamImageDataImportInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "initHandler\0setPixelHandler\0finishHandler\0", 21LL, MediaStreamImageDataImportInterface, _MediaStreamImageDataImportInterface_SetCallbackHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamImageDataImportInterface, _MediaStreamImageDataImportInterface_InitStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0srcChannelOffsets\0setPixelFlags\0", 21LL, MediaStreamImageDataImportInterface, _MediaStreamImageDataImportInterface_SetPixelStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamImageDataImportInterface, _MediaStreamImageDataImportInterface_FinishStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamImageDataImportInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamImageDataImportInterface(nullptr, &MediaStreamImageDataImportInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamImageDataImportInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamImageDataExportInterface(MediaStreamImageDataExportInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamImageDataExportInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamImageDataExportInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamImageDataExportInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataExportInterface_SetCallbackHandler_Offset), maxon::reflection::Argument::ByReference(initHandler), maxon::reflection::Argument::ByReference(getPixelHandler), maxon::reflection::Argument::ByReference(finishHandler)};
			(*handler_)(_fn_MediaStreamImageDataExportInterface_SetCallbackHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const InitHandler&, const GetPixelHandler&, const FinishHandler&>::Invoke, (const void*) mt_._MediaStreamImageDataExportInterface_SetCallbackHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataExportInterface_SetCallbackHandler;
		Result<void> InitStream(MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataExportInterface_InitStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamImageDataExportInterface_InitStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamImageDataExportInterface_InitStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataExportInterface_InitStream;
		Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataExportInterface>();
			Result<GetPixelHandlerStruct> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataExportInterface_GetPixelStream_Offset), maxon::reflection::Argument::ByReference(props), maxon::reflection::Argument::ByReference(dstFormat), maxon::reflection::Argument::ByReference(channelOffsets), maxon::reflection::Argument::ByReference(dstColorProfile), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_MediaStreamImageDataExportInterface_GetPixelStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<GetPixelHandlerStruct>, maxon::GenericComponent*, const MediaStreamProperties&, const PixelFormat&, const ChannelOffsets&, const ColorProfile&, GETPIXELHANDLERFLAGS>::Invoke, (const void*) mt_._MediaStreamImageDataExportInterface_GetPixelStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataExportInterface_GetPixelStream;
		Result<void> FinishStream(const MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataExportInterface_FinishStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamImageDataExportInterface_FinishStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamImageDataExportInterface_FinishStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataExportInterface_FinishStream;
	};
	const maxon::reflection::Function* MediaStreamImageDataExportInterface::ProxyComponent::_fn_MediaStreamImageDataExportInterface_SetCallbackHandler;
	const maxon::reflection::Function* MediaStreamImageDataExportInterface::ProxyComponent::_fn_MediaStreamImageDataExportInterface_InitStream;
	const maxon::reflection::Function* MediaStreamImageDataExportInterface::ProxyComponent::_fn_MediaStreamImageDataExportInterface_GetPixelStream;
	const maxon::reflection::Function* MediaStreamImageDataExportInterface::ProxyComponent::_fn_MediaStreamImageDataExportInterface_FinishStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamImageDataExportInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamImageDataExportInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "initHandler\0getPixelHandler\0finishHandler\0", 21LL, MediaStreamImageDataExportInterface, _MediaStreamImageDataExportInterface_SetCallbackHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamImageDataExportInterface, _MediaStreamImageDataExportInterface_InitStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0dstFormat\0channelOffsets\0dstColorProfile\0flags\0", 341LL, MediaStreamImageDataExportInterface, _MediaStreamImageDataExportInterface_GetPixelStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamImageDataExportInterface, _MediaStreamImageDataExportInterface_FinishStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamImageDataExportInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamImageDataExportInterface(nullptr, &MediaStreamImageDataExportInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamImageDataExportInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamImageDataForwardImportInterface(MediaStreamImageDataForwardImportInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamImageDataForwardImportInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamImageDataForwardImportInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamImageDataForwardImportInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamImageDataForwardImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset), maxon::reflection::Argument::ByReference(sourceStream)};
			(*handler_)(_fn_MediaStreamImageDataForwardImportInterface_SetSourceStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamImageDataImportRef&>::Invoke, (const void*) mt_._MediaStreamImageDataForwardImportInterface_SetSourceStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamImageDataForwardImportInterface_SetSourceStream;
	};
	const maxon::reflection::Function* MediaStreamImageDataForwardImportInterface::ProxyComponent::_fn_MediaStreamImageDataForwardImportInterface_SetSourceStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamImageDataForwardImportInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamImageDataForwardImportInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "sourceStream\0", 1LL, MediaStreamImageDataForwardImportInterface, _MediaStreamImageDataForwardImportInterface_SetSourceStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamImageDataForwardImportInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamImageDataForwardImportInterface(nullptr, &MediaStreamImageDataForwardImportInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamImageDataForwardImportInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamAudioDataImportInterface(MediaStreamAudioDataImportInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamAudioDataImportInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamAudioDataImportInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamAudioDataImportInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset), maxon::reflection::Argument::ByReference(initHandler), maxon::reflection::Argument::ByReference(getAudioDataHandler), maxon::reflection::Argument::ByReference(finishHandler)};
			(*handler_)(_fn_MediaStreamAudioDataImportInterface_SetCallbackHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const InitHandler&, const SetAudioDataHandler&, const FinishHandler&>::Invoke, (const void*) mt_._MediaStreamAudioDataImportInterface_SetCallbackHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataImportInterface_SetCallbackHandler;
		Result<void> InitStream(MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataImportInterface_InitStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamAudioDataImportInterface_InitStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamAudioDataImportInterface_InitStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataImportInterface_InitStream;
		Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataImportInterface>();
			Result<SetAudioDataCallbackType> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamAudioDataImportInterface_SetAudioDataCallback, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<SetAudioDataCallbackType>, maxon::GenericComponent*, MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamAudioDataImportInterface_SetAudioDataCallback));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataImportInterface_SetAudioDataCallback;
		Result<void> FinishStream(const MediaStreamProperties& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataImportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataImportInterface_FinishStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamAudioDataImportInterface_FinishStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamAudioDataImportInterface_FinishStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataImportInterface_FinishStream;
	};
	const maxon::reflection::Function* MediaStreamAudioDataImportInterface::ProxyComponent::_fn_MediaStreamAudioDataImportInterface_SetCallbackHandler;
	const maxon::reflection::Function* MediaStreamAudioDataImportInterface::ProxyComponent::_fn_MediaStreamAudioDataImportInterface_InitStream;
	const maxon::reflection::Function* MediaStreamAudioDataImportInterface::ProxyComponent::_fn_MediaStreamAudioDataImportInterface_SetAudioDataCallback;
	const maxon::reflection::Function* MediaStreamAudioDataImportInterface::ProxyComponent::_fn_MediaStreamAudioDataImportInterface_FinishStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamAudioDataImportInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamAudioDataImportInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "initHandler\0getAudioDataHandler\0finishHandler\0", 21LL, MediaStreamAudioDataImportInterface, _MediaStreamAudioDataImportInterface_SetCallbackHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamAudioDataImportInterface, _MediaStreamAudioDataImportInterface_InitStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamAudioDataImportInterface, _MediaStreamAudioDataImportInterface_SetAudioDataCallback),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamAudioDataImportInterface, _MediaStreamAudioDataImportInterface_FinishStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamAudioDataImportInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamAudioDataImportInterface(nullptr, &MediaStreamAudioDataImportInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamAudioDataImportInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
