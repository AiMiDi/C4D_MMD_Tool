#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FileFormatDetectionCacheInterface(FileFormatDetectionCacheInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::FileFormatDetectionCacheRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class FileFormatDetectionCacheInterface::ProxyComponent : public maxon::Component<ProxyComponent, FileFormatDetectionCacheInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, FileFormatDetectionCacheInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FileFormatDetectionCacheInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FileFormatDetectionCacheInterface_DetectFile_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(limitDetection)};
			(*handler_)(_fn_FileFormatDetectionCacheInterface_DetectFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), const Url&, FILEFORMATDETECTIONFLAGS, const Block<const DataType>&), reinterpret_cast<const void* const&>(mt_.FileFormatDetectionCacheInterface_DetectFile)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FileFormatDetectionCacheInterface_DetectFile;
	};
	const maxon::reflection::Function* FileFormatDetectionCacheInterface::ProxyComponent::_fn_FileFormatDetectionCacheInterface_DetectFile;
	PRIVATE_MAXON_COMPONENT_REGISTER(FileFormatDetectionCacheInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_FileFormatDetectionCacheInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0flags\0limitDetection\0", 21LL, FileFormatDetectionCacheInterface, FileFormatDetectionCacheInterface_DetectFile),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileFormatDetectionCacheInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_FileFormatDetectionCacheInterface(nullptr, &FileFormatDetectionCacheInterface::ProxyComponent::_descriptor, &RegisterReflection_FileFormatDetectionCacheInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
