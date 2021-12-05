#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ResolveInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ResolveInterface::MTable::_instance._ResolveInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ResolveInterface::MTable::_instance._ResolveInterface_RemoveDotSegments)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ResolveInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ResolveInterface("net.maxon.interface.resolve", nullptr, &RegisterReflection_ResolveInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IoConnectionInterface(IoConnectionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class IoConnectionInterface::ProxyComponent : public maxon::Component<ProxyComponent, IoConnectionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, IoConnectionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const Url& GetUrl() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			const Url* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_GetUrl_Offset)};
			(*handler_)(_fn_IoConnectionInterface_GetUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Url&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoConnectionInterface_GetUrl));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_GetUrl;
		Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<IoBrowseRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_GetBrowseIterator_Offset), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoConnectionInterface_GetBrowseIterator, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<IoBrowseRef>, maxon::GenericComponent*, GETBROWSEITERATORFLAGS>::Invoke, (const void*) mt_._IoConnectionInterface_GetBrowseIterator));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_GetBrowseIterator;
		Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<InputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_OpenInputStream_Offset), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoConnectionInterface_OpenInputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<InputStreamRef>, maxon::GenericComponent*, OPENSTREAMFLAGS>::Invoke, (const void*) mt_._IoConnectionInterface_OpenInputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_OpenInputStream;
		Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<OutputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_OpenOutputStream_Offset), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoConnectionInterface_OpenOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<OutputStreamRef>, maxon::GenericComponent*, OPENSTREAMFLAGS>::Invoke, (const void*) mt_._IoConnectionInterface_OpenOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_OpenOutputStream;
		Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<InOutputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_OpenInOutputStream_Offset), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoConnectionInterface_OpenInOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<InOutputStreamRef>, maxon::GenericComponent*, OPENSTREAMFLAGS>::Invoke, (const void*) mt_._IoConnectionInterface_OpenInOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_OpenInOutputStream;
		Result<Int64> GetContentLength() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<Int64> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_GetContentLength_Offset)};
			(*handler_)(_fn_IoConnectionInterface_GetContentLength, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Int64>, maxon::GenericComponent*>::Invoke, (const void*) mt_._IoConnectionInterface_GetContentLength));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_GetContentLength;
		IODETECT IoDetect() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			IODETECT proxy_result = maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoDetect_Offset)};
			(*handler_)(_fn_IoConnectionInterface_IoDetect, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<IODETECT, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoConnectionInterface_IoDetect));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoDetect;
		Result<IOATTRIBUTES> IoGetAttributes() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<IOATTRIBUTES> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoGetAttributes_Offset)};
			(*handler_)(_fn_IoConnectionInterface_IoGetAttributes, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<IOATTRIBUTES>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoConnectionInterface_IoGetAttributes));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoGetAttributes;
		Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoSetAttributes_Offset), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByValue(mask)};
			(*handler_)(_fn_IoConnectionInterface_IoSetAttributes, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, IOATTRIBUTES, IOATTRIBUTES>::Invoke, (const void*) mt_._IoConnectionInterface_IoSetAttributes));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoSetAttributes;
		Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<UniversalDateTime> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoGetTime_Offset), maxon::reflection::Argument::ByValue(mode)};
			(*handler_)(_fn_IoConnectionInterface_IoGetTime, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<UniversalDateTime>, const maxon::GenericComponent*, IOTIMEMODE>::Invoke, (const void*) mt_._IoConnectionInterface_IoGetTime));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoGetTime;
		Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoSetTime_Offset), maxon::reflection::Argument::ByValue(mode), maxon::reflection::Argument::ByReference(dateTime)};
			(*handler_)(_fn_IoConnectionInterface_IoSetTime, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, IOTIMEMODE, const UniversalDateTime&>::Invoke, (const void*) mt_._IoConnectionInterface_IoSetTime));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoSetTime;
		Result<void> IoDelete(Bool force) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoDelete_Offset), maxon::reflection::Argument::ByValue(force)};
			(*handler_)(_fn_IoConnectionInterface_IoDelete, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Bool>::Invoke, (const void*) mt_._IoConnectionInterface_IoDelete));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoDelete;
		Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoCreateDirectory_Offset), maxon::reflection::Argument::ByValue(createParents), maxon::reflection::Argument::ByValue(createdDirs)};
			(*handler_)(_fn_IoConnectionInterface_IoCreateDirectory, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, Bool, BaseArray<Url>*>::Invoke, (const void*) mt_._IoConnectionInterface_IoCreateDirectory));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoCreateDirectory;
		Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoCopyFile_Offset), maxon::reflection::Argument::ByReference(destName), maxon::reflection::Argument::ByValue(overwrite), maxon::reflection::Argument::ByValue(removeReadOnly)};
			(*handler_)(_fn_IoConnectionInterface_IoCopyFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, Bool, Bool>::Invoke, (const void*) mt_._IoConnectionInterface_IoCopyFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoCopyFile;
		Result<void> IoMove(const Url& destName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoMove_Offset), maxon::reflection::Argument::ByReference(destName)};
			(*handler_)(_fn_IoConnectionInterface_IoMove, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._IoConnectionInterface_IoMove));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoMove;
		Result<void> IoRename(const Url& newName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoRename_Offset), maxon::reflection::Argument::ByReference(newName)};
			(*handler_)(_fn_IoConnectionInterface_IoRename, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._IoConnectionInterface_IoRename));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoRename;
		Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoGetFreeVolumeSpace_Offset), maxon::reflection::Argument::ByReference(availableBytes), maxon::reflection::Argument::ByReference(totalBytes)};
			(*handler_)(_fn_IoConnectionInterface_IoGetFreeVolumeSpace, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, Int64&, Int64&>::Invoke, (const void*) mt_._IoConnectionInterface_IoGetFreeVolumeSpace));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoGetFreeVolumeSpace;
		Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoConnectionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoConnectionInterface_IoShowInOS_Offset), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoConnectionInterface_IoShowInOS, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, IOSHOWINOSFLAGS>::Invoke, (const void*) mt_._IoConnectionInterface_IoShowInOS));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoConnectionInterface_IoShowInOS;
	};
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_GetUrl;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_GetBrowseIterator;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_OpenInputStream;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_OpenOutputStream;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_OpenInOutputStream;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_GetContentLength;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoDetect;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoGetAttributes;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoSetAttributes;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoGetTime;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoSetTime;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoDelete;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoCreateDirectory;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoCopyFile;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoMove;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoRename;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoGetFreeVolumeSpace;
	const maxon::reflection::Function* IoConnectionInterface::ProxyComponent::_fn_IoConnectionInterface_IoShowInOS;
	PRIVATE_MAXON_COMPONENT_REGISTER(IoConnectionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_IoConnectionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoConnectionInterface, _IoConnectionInterface_GetUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "flags\0", 1LL, IoConnectionInterface, _IoConnectionInterface_GetBrowseIterator),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "flags\0", 1LL, IoConnectionInterface, _IoConnectionInterface_OpenInputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "flags\0", 1LL, IoConnectionInterface, _IoConnectionInterface_OpenOutputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "flags\0", 1LL, IoConnectionInterface, _IoConnectionInterface_OpenInOutputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, IoConnectionInterface, _IoConnectionInterface_GetContentLength),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoConnectionInterface, _IoConnectionInterface_IoDetect),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoConnectionInterface, _IoConnectionInterface_IoGetAttributes),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "flags\0mask\0", 5LL, IoConnectionInterface, _IoConnectionInterface_IoSetAttributes),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "mode\0", 1LL, IoConnectionInterface, _IoConnectionInterface_IoGetTime),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "mode\0dateTime\0", 5LL, IoConnectionInterface, _IoConnectionInterface_IoSetTime),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "force\0", 1LL, IoConnectionInterface, _IoConnectionInterface_IoDelete),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "createParents\0createdDirs\0", 9LL, IoConnectionInterface, _IoConnectionInterface_IoCreateDirectory),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "destName\0overwrite\0removeReadOnly\0", 21LL, IoConnectionInterface, _IoConnectionInterface_IoCopyFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "destName\0", 1LL, IoConnectionInterface, _IoConnectionInterface_IoMove),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "newName\0", 1LL, IoConnectionInterface, _IoConnectionInterface_IoRename),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "availableBytes\0totalBytes\0", 10LL, IoConnectionInterface, _IoConnectionInterface_IoGetFreeVolumeSpace),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "flags\0", 1LL, IoConnectionInterface, _IoConnectionInterface_IoShowInOS),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoConnectionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_IoConnectionInterface(nullptr, &IoConnectionInterface::ProxyComponent::_descriptor, &RegisterReflection_IoConnectionInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
