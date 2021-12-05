#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(IOBROWSEFLAGS, "net.maxon.datatype.enum.iobrowseflags", SIZEOF(IOBROWSEFLAGS), true, "NONE\0IS_DIRECTORY\0IS_BUNDLE\0IS_READONLY\0IS_HIDDEN\0SUPPORT_REVISIONS\0IS_LINK\0IS_ENCRYPTED\0IS_DELETED\0IS_INVISIBLE\0", const maxon::UInt64 values[] = {(maxon::UInt64) IOBROWSEFLAGS::NONE, (maxon::UInt64) IOBROWSEFLAGS::IS_DIRECTORY, (maxon::UInt64) IOBROWSEFLAGS::IS_BUNDLE, (maxon::UInt64) IOBROWSEFLAGS::IS_READONLY, (maxon::UInt64) IOBROWSEFLAGS::IS_HIDDEN, (maxon::UInt64) IOBROWSEFLAGS::SUPPORT_REVISIONS, (maxon::UInt64) IOBROWSEFLAGS::IS_LINK, (maxon::UInt64) IOBROWSEFLAGS::IS_ENCRYPTED, (maxon::UInt64) IOBROWSEFLAGS::IS_DELETED, (maxon::UInt64) IOBROWSEFLAGS::IS_INVISIBLE})
#endif
/// @cond INTERNAL

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IoBrowseInterface(IoBrowseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class IoBrowseInterface::ProxyComponent : public maxon::Component<ProxyComponent, IoBrowseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, IoBrowseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
/// @cond INTERNAL

		Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Init_Offset), maxon::reflection::Argument::ByValue(connection), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_IoBrowseInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, IoConnectionInterface*, GETBROWSEITERATORFLAGS>::Invoke, (const void*) mt_._IoBrowseInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_Init;
/// @endcond

		const Url& GetBasePath() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			const Url* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetBasePath_Offset)};
			(*handler_)(_fn_IoBrowseInterface_GetBasePath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Url&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_GetBasePath));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_GetBasePath;
		Result<void> Reset() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Reset_Offset)};
			(*handler_)(_fn_IoBrowseInterface_Reset, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_Reset));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_Reset;
		Result<void> GetNext() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetNext_Offset)};
			(*handler_)(_fn_IoBrowseInterface_GetNext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_GetNext));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_GetNext;
		Bool HasEntry() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_HasEntry_Offset)};
			(*handler_)(_fn_IoBrowseInterface_HasEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_HasEntry));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_HasEntry;
		Url GetCurrentPath() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetCurrentPath_Offset)};
			(*handler_)(_fn_IoBrowseInterface_GetCurrentPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Url, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_GetCurrentPath));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_GetCurrentPath;
		IOBROWSEFLAGS IoGetFlags() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			IOBROWSEFLAGS proxy_result = maxon::PrivateIncompleteNullReturnValue<IOBROWSEFLAGS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetFlags_Offset)};
			(*handler_)(_fn_IoBrowseInterface_IoGetFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<IOBROWSEFLAGS, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_IoGetFlags));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_IoGetFlags;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Result<IOATTRIBUTES> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetAttributes_Offset)};
			(*handler_)(_fn_IoBrowseInterface_IoGetAttributes, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<IOATTRIBUTES>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_IoGetAttributes));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_IoGetAttributes;
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Result<UniversalDateTime> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetTime_Offset), maxon::reflection::Argument::ByValue(mode)};
			(*handler_)(_fn_IoBrowseInterface_IoGetTime, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<UniversalDateTime>, const maxon::GenericComponent*, IOTIMEMODE>::Invoke, (const void*) mt_._IoBrowseInterface_IoGetTime));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_IoGetTime;
		Int64 GetSize() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			Int64 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetSize_Offset)};
			(*handler_)(_fn_IoBrowseInterface_GetSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int64, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_GetSize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_GetSize;
		String GetExtraData() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoBrowseInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetExtraData_Offset)};
			(*handler_)(_fn_IoBrowseInterface_GetExtraData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoBrowseInterface_GetExtraData));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoBrowseInterface_GetExtraData;
	};
/// @cond INTERNAL

	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_Init;
/// @endcond

	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_GetBasePath;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_Reset;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_GetNext;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_HasEntry;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_GetCurrentPath;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_IoGetFlags;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_IoGetAttributes;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_IoGetTime;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_GetSize;
	const maxon::reflection::Function* IoBrowseInterface::ProxyComponent::_fn_IoBrowseInterface_GetExtraData;
	PRIVATE_MAXON_COMPONENT_REGISTER(IoBrowseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_IoBrowseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
/// @cond INTERNAL

			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "connection\0flags\0", 5LL, IoBrowseInterface, _IoBrowseInterface_Init),
/// @endcond

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_GetBasePath),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_Reset),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_GetNext),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_HasEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_GetCurrentPath),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_IoGetFlags),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_IoGetAttributes),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "mode\0", 1LL, IoBrowseInterface, _IoBrowseInterface_IoGetTime),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_GetSize),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoBrowseInterface, _IoBrowseInterface_GetExtraData),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoBrowseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_IoBrowseInterface(nullptr, &IoBrowseInterface::ProxyComponent::_descriptor, &RegisterReflection_IoBrowseInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
