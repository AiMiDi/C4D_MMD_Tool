#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataDescriptionDefinitionInterface(DataDescriptionDefinitionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DataDescriptionDefinition");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DataDescriptionDefinitionInterface::ProxyComponent : public maxon::Component<ProxyComponent, DataDescriptionDefinitionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DataDescriptionDefinitionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		DataDictionary GetInfo() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			DataDictionary proxy_result = maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetInfo_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_GetInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((DataDictionary)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_GetInfo)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_GetInfo;
		Result<void> SetInfo(const DataDictionary& info) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset), maxon::reflection::Argument::ByReference(info)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_SetInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const DataDictionary&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_SetInfo)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_SetInfo;
		Int GetEntryCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntryCount_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_GetEntryCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_GetEntryCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_GetEntryCount;
		Result<BaseArray<DataDescriptionEntry>> GetEntries() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<BaseArray<DataDescriptionEntry>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntries_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_GetEntries, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<BaseArray<DataDescriptionEntry>>)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_GetEntries)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_GetEntries;
		Result<DataDescriptionEntry> GetEntry(Int idx) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<DataDescriptionEntry> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntry_Offset), maxon::reflection::Argument::ByValue(idx)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_GetEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDescriptionEntry>), Int), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_GetEntry)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_GetEntry;
		Result<DataDescriptionEntry> FindEntry(const InternedId& id) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<DataDescriptionEntry> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_FindEntry_Offset), maxon::reflection::Argument::ByReference(id)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_FindEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDescriptionEntry>), const InternedId&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_FindEntry)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_FindEntry;
		Result<Int> AddEntry(const DataDescriptionEntry& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<Int> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_AddEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Int>), const DataDescriptionEntry&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_AddEntry)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_AddEntry;
		Result<void> ReplaceEntry(const DataDescriptionEntry& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_ReplaceEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const DataDescriptionEntry&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_ReplaceEntry)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_ReplaceEntry;
		Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<Bool> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset), maxon::reflection::Argument::ByValue(idx), maxon::reflection::Argument::ByReference(props)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_ReplaceEntry_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), Int, const DataDescriptionEntry&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_ReplaceEntry_1;
		Result<void> EraseEntry(Int idx) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset), maxon::reflection::Argument::ByValue(idx)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_EraseEntry, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), Int), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_EraseEntry)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_EraseEntry;
		Result<void> EraseEntry(const InternedId& id) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_1_Offset), maxon::reflection::Argument::ByReference(id)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_EraseEntry_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const InternedId&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_EraseEntry_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_EraseEntry_1;
		void Reset() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_Reset_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionInterface_Reset, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionInterface_Reset)));
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionInterface_Reset;
	};
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_GetInfo;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_SetInfo;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_GetEntryCount;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_GetEntries;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_GetEntry;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_FindEntry;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_AddEntry;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_ReplaceEntry;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_ReplaceEntry_1;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_EraseEntry;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_EraseEntry_1;
	const maxon::reflection::Function* DataDescriptionDefinitionInterface::ProxyComponent::_fn_DataDescriptionDefinitionInterface_Reset;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataDescriptionDefinitionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionDefinitionInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_MergeDescriptionDefinition)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0source\0overwriteIncludes\0skipIncludes\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataDefaults)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataEntry\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataValueOrDefaults)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataId\0dataEntry\0flags\0getDataCallback\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_Create)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_NullValuePtr)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDefinitionInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DataDescriptionDefinitionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_GetInfo),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "info\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_SetInfo),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_GetEntryCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_GetEntries),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "idx\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_GetEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "id\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_FindEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_AddEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "props\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_ReplaceEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "idx\0props\0", 5LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_ReplaceEntry_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "idx\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_EraseEntry),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "id\0", 1LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_EraseEntry_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionInterface, DataDescriptionDefinitionInterface_Reset),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDefinitionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDefinitionInterface(nullptr, &DataDescriptionDefinitionInterface::ProxyComponent::_descriptor, &RegisterReflection_DataDescriptionDefinitionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDefinitionInterface_Static("net.maxon.interface.datadescriptiondefinition", nullptr, &RegisterReflection_DataDescriptionDefinitionInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
