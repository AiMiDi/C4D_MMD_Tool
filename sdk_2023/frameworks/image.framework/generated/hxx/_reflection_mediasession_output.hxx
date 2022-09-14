#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaOutputInterface(MediaOutputInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaOutputRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaOutputInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaOutputInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaOutputInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ResetConverter() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_ResetConverter_Offset)};
			(*handler_)(_fn_MediaOutputInterface_ResetConverter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.MediaOutputInterface_ResetConverter)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputInterface_ResetConverter;
		Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_SetSelectionHandler_Offset), maxon::reflection::Argument::ByReference(selectionHandler)};
			(*handler_)(_fn_MediaOutputInterface_SetSelectionHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const MediaOutputSelectionHandler&), reinterpret_cast<const void* const&>(mt_.MediaOutputInterface_SetSelectionHandler)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputInterface_SetSelectionHandler;
		const MediaOutputSelectionHandler& GetSelectionHandler() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputInterface>();
			const MediaOutputSelectionHandler* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const MediaOutputSelectionHandler&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_GetSelectionHandler_Offset)};
			(*handler_)(_fn_MediaOutputInterface_GetSelectionHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const MediaOutputSelectionHandler&)), reinterpret_cast<const void* const&>(mt_.MediaOutputInterface_GetSelectionHandler)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputInterface_GetSelectionHandler;
		Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputInterface>();
			Result<SELECTIONHANDLERRESULT> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_CallSelectionHandler_Offset), maxon::reflection::Argument::ByReference(stream), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaOutputInterface_CallSelectionHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<SELECTIONHANDLERRESULT>), const MediaStreamRef&, const MediaStreamFormat&), reinterpret_cast<const void* const&>(mt_.MediaOutputInterface_CallSelectionHandler)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputInterface_CallSelectionHandler;
	};
	const maxon::reflection::Function* MediaOutputInterface::ProxyComponent::_fn_MediaOutputInterface_ResetConverter;
	const maxon::reflection::Function* MediaOutputInterface::ProxyComponent::_fn_MediaOutputInterface_SetSelectionHandler;
	const maxon::reflection::Function* MediaOutputInterface::ProxyComponent::_fn_MediaOutputInterface_GetSelectionHandler;
	const maxon::reflection::Function* MediaOutputInterface::ProxyComponent::_fn_MediaOutputInterface_CallSelectionHandler;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaOutputInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaOutputInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MediaOutputInterface, MediaOutputInterface_ResetConverter),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "selectionHandler\0", 1LL, MediaOutputInterface, MediaOutputInterface_SetSelectionHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaOutputInterface, MediaOutputInterface_GetSelectionHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stream\0props\0", 5LL, MediaOutputInterface, MediaOutputInterface_CallSelectionHandler),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaOutputInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaOutputInterface(nullptr, &MediaOutputInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaOutputInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaOutputTextureInterface(MediaOutputTextureInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaOutputTextureRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaOutputTextureInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaOutputTextureInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaOutputTextureInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputTextureInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset), maxon::reflection::Argument::ByReference(textureRef), maxon::reflection::Argument::ByReference(pixelStorageClass)};
			(*handler_)(_fn_MediaOutputTextureInterface_SetOutputTexture, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const ImageTextureRef&, const Class<ImagePixelStorage>&), reinterpret_cast<const void* const&>(mt_.MediaOutputTextureInterface_SetOutputTexture)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputTextureInterface_SetOutputTexture;
	};
	const maxon::reflection::Function* MediaOutputTextureInterface::ProxyComponent::_fn_MediaOutputTextureInterface_SetOutputTexture;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaOutputTextureInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaOutputTextureInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "textureRef\0pixelStorageClass\0", 5LL, MediaOutputTextureInterface, MediaOutputTextureInterface_SetOutputTexture),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaOutputTextureInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaOutputTextureInterface(nullptr, &MediaOutputTextureInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaOutputTextureInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaOutputUrlInterface(MediaOutputUrlInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaOutputUrlRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaOutputUrlInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaOutputUrlInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaOutputUrlInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Url GetOutputUrl() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputUrlInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetOutputUrl_Offset)};
			(*handler_)(_fn_MediaOutputUrlInterface_GetOutputUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Url)), reinterpret_cast<const void* const&>(mt_.MediaOutputUrlInterface_GetOutputUrl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputUrlInterface_GetOutputUrl;
		Result<void> SetOutputUrl(const Url& url) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputUrlInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_MediaOutputUrlInterface_SetOutputUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const Url&), reinterpret_cast<const void* const&>(mt_.MediaOutputUrlInterface_SetOutputUrl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputUrlInterface_SetOutputUrl;
		const FileFormat& GetFileFormat() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputUrlInterface>();
			const FileFormat* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetFileFormat_Offset)};
			(*handler_)(_fn_MediaOutputUrlInterface_GetFileFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const FileFormat&)), reinterpret_cast<const void* const&>(mt_.MediaOutputUrlInterface_GetFileFormat)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputUrlInterface_GetFileFormat;
		Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputUrlInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset), maxon::reflection::Argument::ByReference(settings), maxon::reflection::Argument::ByReference(getParentwindowHandle)};
			(*handler_)(_fn_MediaOutputUrlInterface_EditSystemOptions, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), DataDictionary&, const Delegate<Result<void*>()>&), reinterpret_cast<const void* const&>(mt_.MediaOutputUrlInterface_EditSystemOptions)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputUrlInterface_EditSystemOptions;
		Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaOutputUrlInterface>();
			Result<DrawDimensionInt> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_CheckBitmapSize_Offset), maxon::reflection::Argument::ByReference(settings), maxon::reflection::Argument::ByReference(bitmapSize)};
			(*handler_)(_fn_MediaOutputUrlInterface_CheckBitmapSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DrawDimensionInt>), const DataDictionary&, const DrawDimensionInt&), reinterpret_cast<const void* const&>(mt_.MediaOutputUrlInterface_CheckBitmapSize)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaOutputUrlInterface_CheckBitmapSize;
	};
	const maxon::reflection::Function* MediaOutputUrlInterface::ProxyComponent::_fn_MediaOutputUrlInterface_GetOutputUrl;
	const maxon::reflection::Function* MediaOutputUrlInterface::ProxyComponent::_fn_MediaOutputUrlInterface_SetOutputUrl;
	const maxon::reflection::Function* MediaOutputUrlInterface::ProxyComponent::_fn_MediaOutputUrlInterface_GetFileFormat;
	const maxon::reflection::Function* MediaOutputUrlInterface::ProxyComponent::_fn_MediaOutputUrlInterface_EditSystemOptions;
	const maxon::reflection::Function* MediaOutputUrlInterface::ProxyComponent::_fn_MediaOutputUrlInterface_CheckBitmapSize;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaOutputUrlInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaOutputUrlInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaOutputUrlInterface, MediaOutputUrlInterface_GetOutputUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0", 1LL, MediaOutputUrlInterface, MediaOutputUrlInterface_SetOutputUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaOutputUrlInterface, MediaOutputUrlInterface_GetFileFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "settings\0getParentwindowHandle\0", 7LL, MediaOutputUrlInterface, MediaOutputUrlInterface_EditSystemOptions),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "settings\0bitmapSize\0", 5LL, MediaOutputUrlInterface, MediaOutputUrlInterface_CheckBitmapSize),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaOutputUrlInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaOutputUrlInterface(nullptr, &MediaOutputUrlInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaOutputUrlInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
