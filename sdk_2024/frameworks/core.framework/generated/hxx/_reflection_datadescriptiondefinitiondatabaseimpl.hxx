#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataDescriptionDefinitionDatabaseImplInterface(DataDescriptionDefinitionDatabaseImplInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DataDescriptionDefinitionDatabaseImplRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent : public maxon::Component<ProxyComponent, DataDescriptionDefinitionDatabaseImplInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DataDescriptionDefinitionDatabaseImplInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(dataType), maxon::reflection::Argument::ByReference(language)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_Contains, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const Id&, const IdAndVersion&, const LanguageRef&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_Contains;
		Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<DataDescriptionDefinition> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset), maxon::reflection::Argument::ByValue(mode), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(dataType), maxon::reflection::Argument::ByValue(foundInDatabase)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDescriptionDefinition>), LOADDESCRIPTIONMODE, const Id&, const LanguageRef&, const IdAndVersion&, Id*), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription;
		Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<Tuple<Bool, DataDescriptionDefinition*>> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset), maxon::reflection::Argument::ByReference(databaseId), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(dataType), maxon::reflection::Argument::ByReference(description), maxon::reflection::Argument::ByReference(overwrittenDescription), maxon::reflection::Argument::ByValue(usePendingSystem)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Tuple<Bool, DataDescriptionDefinition*>>), const Id&, const Id&, const LanguageRef&, const IdAndVersion&, const DataDescriptionDefinition&, const DataDescriptionDefinition&, Bool), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription;
		Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<Bool> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(dataType)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), const Id&, const LanguageRef&, const IdAndVersion&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription;
		Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<BaseArray<IdAndVersion>> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<BaseArray<IdAndVersion>>), const Id&, const LanguageRef&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions;
		Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<BaseArray<LanguageRef>> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<BaseArray<LanguageRef>>)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages;
		Result<void> WriteDataBases() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases;
		Result<Int> RenameId(const Id& oldId, const Id& newId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<Int> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset), maxon::reflection::Argument::ByReference(oldId), maxon::reflection::Argument::ByReference(newId)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_RenameId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Int>), const Id&, const Id&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_RenameId;
		Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<Int> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset), maxon::reflection::Argument::ByReference(oldId), maxon::reflection::Argument::ByReference(newId)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Int>), const InternedId&, const InternedId&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute;
		Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<Bool> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset), maxon::reflection::Argument::ByReference(searchId)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Bool>), const InternedId&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName;
		Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<DataDescription> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(dataTypeId), maxon::reflection::Argument::ByReference(language)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDescription>), const Id&, const IdAndVersion&, const LanguageRef&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions;
		Bool IsWritableDatabase(const Id& languageId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset), maxon::reflection::Argument::ByReference(languageId)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const Id&), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase;
		Int GetChangeCounts() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts;
		Int GetUserChangeCount() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount;
		Result<void> Write() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Write_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_Write, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_Write)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_Write;
		Result<void> WriteUserChangedDataBases() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset)};
			(*handler_)(_fn_DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases;
	};
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_Contains;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_RenameId;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_Write;
	const maxon::reflection::Function* DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_fn_DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DataDescriptionDefinitionDatabaseImplInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "category\0dataType\0language\0", 21LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_Contains),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "mode\0category\0language\0dataType\0foundInDatabase\0", 596LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_LoadDescription),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "databaseId\0category\0language\0dataType\0description\0overwrittenDescription\0usePendingSystem\0", 341LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "category\0language\0dataType\0", 21LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "category\0language\0", 5LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "oldId\0newId\0", 5LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_RenameId),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "oldId\0newId\0", 5LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "searchId\0", 1LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "category\0dataTypeId\0language\0", 21LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "languageId\0", 1LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_Write),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, DataDescriptionDefinitionDatabaseImplInterface, DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDefinitionDatabaseImplInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDefinitionDatabaseImplInterface(nullptr, &DataDescriptionDefinitionDatabaseImplInterface::ProxyComponent::_descriptor, &RegisterReflection_DataDescriptionDefinitionDatabaseImplInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
