#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FileFormatHandlerInterface(FileFormatHandlerInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class FileFormatHandlerInterface::ProxyComponent : public maxon::Component<ProxyComponent, FileFormatHandlerInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, FileFormatHandlerInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileFormatHandlerInterface>();
			const FileFormat* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetFileFormat_Offset)};
			(*handler_)(_fn_FileFormatHandlerInterface_GetFileFormat, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const FileFormat&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._FileFormatHandlerInterface_GetFileFormat));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileFormatHandlerInterface_GetFileFormat;
		Result<DataType> GetHandlerType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileFormatHandlerInterface>();
			Result<DataType> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetHandlerType_Offset)};
			(*handler_)(_fn_FileFormatHandlerInterface_GetHandlerType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataType>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._FileFormatHandlerInterface_GetHandlerType));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileFormatHandlerInterface_GetHandlerType;
		Result<ObjectRef> CreateHandler(const Url& url) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileFormatHandlerInterface>();
			Result<ObjectRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_CreateHandler_Offset), maxon::reflection::Argument::ByReference(url)};
			(*handler_)(_fn_FileFormatHandlerInterface_CreateHandler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<ObjectRef>, const maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._FileFormatHandlerInterface_CreateHandler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileFormatHandlerInterface_CreateHandler;
		FILEFORMAT_PRIORITY GetDependends() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileFormatHandlerInterface>();
			FILEFORMAT_PRIORITY proxy_result = maxon::PrivateIncompleteNullReturnValue<FILEFORMAT_PRIORITY>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FileFormatHandlerInterface_GetDependends_Offset)};
			(*handler_)(_fn_FileFormatHandlerInterface_GetDependends, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<FILEFORMAT_PRIORITY, const maxon::GenericComponent*>::Invoke, (const void*) mt_._FileFormatHandlerInterface_GetDependends));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileFormatHandlerInterface_GetDependends;
	};
	const maxon::reflection::Function* FileFormatHandlerInterface::ProxyComponent::_fn_FileFormatHandlerInterface_GetFileFormat;
	const maxon::reflection::Function* FileFormatHandlerInterface::ProxyComponent::_fn_FileFormatHandlerInterface_GetHandlerType;
	const maxon::reflection::Function* FileFormatHandlerInterface::ProxyComponent::_fn_FileFormatHandlerInterface_CreateHandler;
	const maxon::reflection::Function* FileFormatHandlerInterface::ProxyComponent::_fn_FileFormatHandlerInterface_GetDependends;
	PRIVATE_MAXON_COMPONENT_REGISTER(FileFormatHandlerInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_FileFormatHandlerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FileFormatHandlerInterface, _FileFormatHandlerInterface_GetFileFormat),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FileFormatHandlerInterface, _FileFormatHandlerInterface_GetHandlerType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "url\0", 1LL, FileFormatHandlerInterface, _FileFormatHandlerInterface_CreateHandler),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FileFormatHandlerInterface, _FileFormatHandlerInterface_GetDependends),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileFormatHandlerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_FileFormatHandlerInterface(nullptr, &FileFormatHandlerInterface::ProxyComponent::_descriptor, &RegisterReflection_FileFormatHandlerInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_FileFormatDetectionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
#ifndef MAXON_COMPILER_CLANG
#endif
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(FileFormatDetectionInterface::MTable::_instance._FileFormatDetectionInterface_DetectAll)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0limitDetection\0detectedCallback\0", 21LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileFormatDetectionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_FileFormatDetectionInterface("net.maxon.interface.fileformatdetection", nullptr, &RegisterReflection_FileFormatDetectionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(FileFormatHandlers);
#endif
}
#endif
