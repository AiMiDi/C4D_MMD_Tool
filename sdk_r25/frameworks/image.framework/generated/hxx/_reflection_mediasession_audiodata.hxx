#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaStreamAudioDataExportInterface(MediaStreamAudioDataExportInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaStreamAudioDataExportRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaStreamAudioDataExportInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaStreamAudioDataExportInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaStreamAudioDataExportInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InitWithAudioData(const AudioObjectRef& audioData) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitWithAudioData_Offset), maxon::reflection::Argument::ByReference(audioData)};
			(*handler_)(_fn_MediaStreamAudioDataExportInterface_InitWithAudioData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const AudioObjectRef&>::Invoke, (const void*) mt_._MediaStreamAudioDataExportInterface_InitWithAudioData));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataExportInterface_InitWithAudioData;
		AudioObjectRef GetAudioObject() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataExportInterface>();
			AudioObjectRef proxy_result = maxon::PrivateIncompleteNullReturnValue<AudioObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_GetAudioObject_Offset)};
			(*handler_)(_fn_MediaStreamAudioDataExportInterface_GetAudioObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<AudioObjectRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamAudioDataExportInterface_GetAudioObject));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataExportInterface_GetAudioObject;
		Result<void> SetCallbackHandler() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset)};
			(*handler_)(_fn_MediaStreamAudioDataExportInterface_SetCallbackHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataExportInterface_SetCallbackHandler;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamAudioDataExportInterface_InitStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamAudioDataExportInterface_InitStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataExportInterface_InitStream;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaStreamAudioDataExportInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_FinishStream_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_MediaStreamAudioDataExportInterface_FinishStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const MediaStreamProperties&>::Invoke, (const void*) mt_._MediaStreamAudioDataExportInterface_FinishStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaStreamAudioDataExportInterface_FinishStream;
	};
	const maxon::reflection::Function* MediaStreamAudioDataExportInterface::ProxyComponent::_fn_MediaStreamAudioDataExportInterface_InitWithAudioData;
	const maxon::reflection::Function* MediaStreamAudioDataExportInterface::ProxyComponent::_fn_MediaStreamAudioDataExportInterface_GetAudioObject;
	const maxon::reflection::Function* MediaStreamAudioDataExportInterface::ProxyComponent::_fn_MediaStreamAudioDataExportInterface_SetCallbackHandler;
	const maxon::reflection::Function* MediaStreamAudioDataExportInterface::ProxyComponent::_fn_MediaStreamAudioDataExportInterface_InitStream;
	const maxon::reflection::Function* MediaStreamAudioDataExportInterface::ProxyComponent::_fn_MediaStreamAudioDataExportInterface_FinishStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaStreamAudioDataExportInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaStreamAudioDataExportInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "audioData\0", 1LL, MediaStreamAudioDataExportInterface, _MediaStreamAudioDataExportInterface_InitWithAudioData),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaStreamAudioDataExportInterface, _MediaStreamAudioDataExportInterface_GetAudioObject),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MediaStreamAudioDataExportInterface, _MediaStreamAudioDataExportInterface_SetCallbackHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamAudioDataExportInterface, _MediaStreamAudioDataExportInterface_InitStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, MediaStreamAudioDataExportInterface, _MediaStreamAudioDataExportInterface_FinishStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaStreamAudioDataExportInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaStreamAudioDataExportInterface(nullptr, &MediaStreamAudioDataExportInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaStreamAudioDataExportInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
