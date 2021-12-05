#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ReadArchiveInterface(ReadArchiveInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ReadArchiveInterface::ProxyComponent : public maxon::Component<ProxyComponent, ReadArchiveInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ReadArchiveInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Open(const Url& inputFile, const String& password) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ReadArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Open_Offset), maxon::reflection::Argument::ByReference(inputFile), maxon::reflection::Argument::ByReference(password)};
			(*handler_)(_fn_ReadArchiveInterface_Open, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, const String&>::Invoke, (const void*) mt_._ReadArchiveInterface_Open));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ReadArchiveInterface_Open;
		Result<void> Close() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ReadArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Close_Offset)};
			(*handler_)(_fn_ReadArchiveInterface_Close, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._ReadArchiveInterface_Close));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ReadArchiveInterface_Close;
		Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ReadArchiveInterface>();
			Result<Url> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_ExtractSingleFile_Offset), maxon::reflection::Argument::ByReference(archiveFile), maxon::reflection::Argument::ByReference(outputDirectory), maxon::reflection::Argument::ByValue(thread), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(extractCallback)};
			(*handler_)(_fn_ReadArchiveInterface_ExtractSingleFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Url>, maxon::GenericComponent*, const String&, const Url&, ThreadRef, IOARCHIVEEXTRACTFLAGS, const ExtractCallback&>::Invoke, (const void*) mt_._ReadArchiveInterface_ExtractSingleFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ReadArchiveInterface_ExtractSingleFile;
		Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ReadArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Extract_Offset), maxon::reflection::Argument::ByReference(outputDirectory), maxon::reflection::Argument::ByValue(thread), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(extractCallback)};
			(*handler_)(_fn_ReadArchiveInterface_Extract, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, ThreadRef, IOARCHIVEEXTRACTFLAGS, const ExtractCallback&>::Invoke, (const void*) mt_._ReadArchiveInterface_Extract));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ReadArchiveInterface_Extract;
	};
	const maxon::reflection::Function* ReadArchiveInterface::ProxyComponent::_fn_ReadArchiveInterface_Open;
	const maxon::reflection::Function* ReadArchiveInterface::ProxyComponent::_fn_ReadArchiveInterface_Close;
	const maxon::reflection::Function* ReadArchiveInterface::ProxyComponent::_fn_ReadArchiveInterface_ExtractSingleFile;
	const maxon::reflection::Function* ReadArchiveInterface::ProxyComponent::_fn_ReadArchiveInterface_Extract;
	PRIVATE_MAXON_COMPONENT_REGISTER(ReadArchiveInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ReadArchiveInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputFile\0password\0", 5LL, ReadArchiveInterface, _ReadArchiveInterface_Open),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, ReadArchiveInterface, _ReadArchiveInterface_Close),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "archiveFile\0outputDirectory\0thread\0flags\0extractCallback\0", 341LL, ReadArchiveInterface, _ReadArchiveInterface_ExtractSingleFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "outputDirectory\0thread\0flags\0extractCallback\0", 85LL, ReadArchiveInterface, _ReadArchiveInterface_Extract),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ReadArchiveInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ReadArchiveInterface(nullptr, &ReadArchiveInterface::ProxyComponent::_descriptor, &RegisterReflection_ReadArchiveInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_WriteArchiveInterface(WriteArchiveInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class WriteArchiveInterface::ProxyComponent : public maxon::Component<ProxyComponent, WriteArchiveInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, WriteArchiveInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Open(const Url& inputFile, Bool append, const String& password) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Open_Offset), maxon::reflection::Argument::ByReference(inputFile), maxon::reflection::Argument::ByValue(append), maxon::reflection::Argument::ByReference(password)};
			(*handler_)(_fn_WriteArchiveInterface_Open, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, Bool, const String&>::Invoke, (const void*) mt_._WriteArchiveInterface_Open));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_Open;
		Result<void> Close() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Close_Offset)};
			(*handler_)(_fn_WriteArchiveInterface_Close, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._WriteArchiveInterface_Close));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_Close;
		Result<void> SetCompressionLevel(Int compressionLevel) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_SetCompressionLevel_Offset), maxon::reflection::Argument::ByValue(compressionLevel)};
			(*handler_)(_fn_WriteArchiveInterface_SetCompressionLevel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Int>::Invoke, (const void*) mt_._WriteArchiveInterface_SetCompressionLevel));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_SetCompressionLevel;
		Int GetCompressionLevel() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_GetCompressionLevel_Offset)};
			(*handler_)(_fn_WriteArchiveInterface_GetCompressionLevel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._WriteArchiveInterface_GetCompressionLevel));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_GetCompressionLevel;
		Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateDirectory_Offset), maxon::reflection::Argument::ByReference(name), maxon::reflection::Argument::ByReference(dateTime), maxon::reflection::Argument::ByValue(fileAttributes)};
			(*handler_)(_fn_WriteArchiveInterface_CreateDirectory, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, const UniversalDateTime&, IOATTRIBUTES>::Invoke, (const void*) mt_._WriteArchiveInterface_CreateDirectory));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_CreateDirectory;
		Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateFile_Offset), maxon::reflection::Argument::ByReference(name), maxon::reflection::Argument::ByReference(dateTime), maxon::reflection::Argument::ByValue(method), maxon::reflection::Argument::ByValue(fileAttributes), maxon::reflection::Argument::ByValue(cryptCrc)};
			(*handler_)(_fn_WriteArchiveInterface_CreateFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, const UniversalDateTime&, IOARCHIVESTOREMETHOD, IOATTRIBUTES, UInt32>::Invoke, (const void*) mt_._WriteArchiveInterface_CreateFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_CreateFile;
		Result<void> WriteFile(const Block<const Byte>& data) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_WriteFile_Offset), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_WriteArchiveInterface_WriteFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const Byte>&>::Invoke, (const void*) mt_._WriteArchiveInterface_WriteFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_WriteFile;
		Result<void> CloseFile() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CloseFile_Offset)};
			(*handler_)(_fn_WriteArchiveInterface_CloseFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._WriteArchiveInterface_CloseFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_CloseFile;
		Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WriteArchiveInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CopyFile_Offset), maxon::reflection::Argument::ByReference(fn), maxon::reflection::Argument::ByReference(str), maxon::reflection::Argument::ByValue(fileAttributes), maxon::reflection::Argument::ByValue(fileAttributesMask)};
			(*handler_)(_fn_WriteArchiveInterface_CopyFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, const String&, IOATTRIBUTES, IOATTRIBUTES>::Invoke, (const void*) mt_._WriteArchiveInterface_CopyFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_WriteArchiveInterface_CopyFile;
	};
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_Open;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_Close;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_SetCompressionLevel;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_GetCompressionLevel;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_CreateDirectory;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_CreateFile;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_WriteFile;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_CloseFile;
	const maxon::reflection::Function* WriteArchiveInterface::ProxyComponent::_fn_WriteArchiveInterface_CopyFile;
	PRIVATE_MAXON_COMPONENT_REGISTER(WriteArchiveInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_WriteArchiveInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputFile\0append\0password\0", 21LL, WriteArchiveInterface, _WriteArchiveInterface_Open),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, WriteArchiveInterface, _WriteArchiveInterface_Close),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "compressionLevel\0", 1LL, WriteArchiveInterface, _WriteArchiveInterface_SetCompressionLevel),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, WriteArchiveInterface, _WriteArchiveInterface_GetCompressionLevel),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0dateTime\0fileAttributes\0", 21LL, WriteArchiveInterface, _WriteArchiveInterface_CreateDirectory),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0dateTime\0method\0fileAttributes\0cryptCrc\0", 341LL, WriteArchiveInterface, _WriteArchiveInterface_CreateFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "data\0", 1LL, WriteArchiveInterface, _WriteArchiveInterface_WriteFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, WriteArchiveInterface, _WriteArchiveInterface_CloseFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "fn\0str\0fileAttributes\0fileAttributesMask\0", 85LL, WriteArchiveInterface, _WriteArchiveInterface_CopyFile),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&WriteArchiveInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_WriteArchiveInterface(nullptr, &WriteArchiveInterface::ProxyComponent::_descriptor, &RegisterReflection_WriteArchiveInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ReadArchiveClasses);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(WriteArchiveClasses);
#endif
}
#endif
