#if 1
namespace maxon
{
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataSerializeInterface(DataSerializeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataSerializeInterface::ProxyComponent : public maxon::Component<DataSerializeInterface::ProxyComponent, DataSerializeInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> DescribeElement(const Char* name, const DataType* dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_DescribeElement_Offset), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByValue(dt), maxon::reflection::Argument::ByValue(objectOffset), maxon::reflection::Argument::ByValue(func), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByValue(mask), maxon::reflection::Argument::ByValue(value)};
			(*handler_)(_fn_DataSerializeInterface_DescribeElement, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const Char*, const DataType*, Int, KeyValueConversionFunc*, DESCRIBEFLAGS, UInt64, UInt64>::Invoke, (const void*) mt_._DataSerializeInterface_DescribeElement));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeInterface_DescribeElement;
		Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_PrepareHelperClass_Offset), maxon::reflection::Argument::ByValue(createFunc), maxon::reflection::Argument::ByValue(deleteFunc), maxon::reflection::Argument::ByValue(readFunc), maxon::reflection::Argument::ByValue(writeFunc), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_DataSerializeInterface_PrepareHelperClass, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, CreateIoHelperFunc*, DeleteIoHelperFunc*, ReadIoHelperFunc*, WriteIoHelperFunc*, PREPAREHELPERFLAGS>::Invoke, (const void*) mt_._DataSerializeInterface_PrepareHelperClass));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeInterface_PrepareHelperClass;
		Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_RegisterObjectSubstitution_Offset), maxon::reflection::Argument::ByReference(func)};
			(*handler_)(_fn_DataSerializeInterface_RegisterObjectSubstitution, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, ReferenceSubstitutionFunction&&>::Invoke, (const void*) mt_._DataSerializeInterface_RegisterObjectSubstitution));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeInterface_RegisterObjectSubstitution;
		Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeInterface>();
			Result<void*> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_RegisterDefaults_Offset), maxon::reflection::Argument::ByValue(createFunc), maxon::reflection::Argument::ByValue(deleteFunc)};
			(*handler_)(_fn_DataSerializeInterface_RegisterDefaults, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void*>, const maxon::GenericComponent*, CreateIoHelperFunc*, DeleteIoHelperFunc*>::Invoke, (const void*) mt_._DataSerializeInterface_RegisterDefaults));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeInterface_RegisterDefaults;
	};
	const maxon::reflection::Function* DataSerializeInterface::ProxyComponent::_fn_DataSerializeInterface_DescribeElement;
	const maxon::reflection::Function* DataSerializeInterface::ProxyComponent::_fn_DataSerializeInterface_PrepareHelperClass;
	const maxon::reflection::Function* DataSerializeInterface::ProxyComponent::_fn_DataSerializeInterface_RegisterObjectSubstitution;
	const maxon::reflection::Function* DataSerializeInterface::ProxyComponent::_fn_DataSerializeInterface_RegisterDefaults;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataSerializeInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataSerializeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 21844LL, DataSerializeInterface, _DataSerializeInterface_DescribeElement),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 1364LL, DataSerializeInterface, _DataSerializeInterface_PrepareHelperClass),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 4LL, DataSerializeInterface, _DataSerializeInterface_RegisterObjectSubstitution),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 20LL, DataSerializeInterface, _DataSerializeInterface_RegisterDefaults),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataSerializeInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataSerializeInterface(nullptr, &DataSerializeInterface::ProxyComponent::_descriptor, &RegisterReflection_DataSerializeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataSerializeWriterInterface(DataSerializeWriterInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataSerializeWriterInterface::ProxyComponent : public maxon::Component<DataSerializeWriterInterface::ProxyComponent, DataSerializeWriterInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> WriteDocument(const Id& id, const ConstDataPtr& data) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeWriterInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeWriterInterface_WriteDocument_Offset), maxon::reflection::Argument::ByReference(id), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_DataSerializeWriterInterface_WriteDocument, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Id&, const ConstDataPtr&>::Invoke, (const void*) mt_._DataSerializeWriterInterface_WriteDocument));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeWriterInterface_WriteDocument;
	};
	const maxon::reflection::Function* DataSerializeWriterInterface::ProxyComponent::_fn_DataSerializeWriterInterface_WriteDocument;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataSerializeWriterInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataSerializeWriterInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 20LL, DataSerializeWriterInterface, _DataSerializeWriterInterface_WriteDocument),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataSerializeWriterInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataSerializeWriterInterface(nullptr, &DataSerializeWriterInterface::ProxyComponent::_descriptor, &RegisterReflection_DataSerializeWriterInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataSerializeReaderInterface(DataSerializeReaderInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataSerializeReaderInterface::ProxyComponent : public maxon::Component<DataSerializeReaderInterface::ProxyComponent, DataSerializeReaderInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ReadDocument(const Id& id, const DataPtr& data) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataSerializeReaderInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeReaderInterface_ReadDocument_Offset), maxon::reflection::Argument::ByReference(id), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_DataSerializeReaderInterface_ReadDocument, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Id&, const DataPtr&>::Invoke, (const void*) mt_._DataSerializeReaderInterface_ReadDocument));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataSerializeReaderInterface_ReadDocument;
	};
	const maxon::reflection::Function* DataSerializeReaderInterface::ProxyComponent::_fn_DataSerializeReaderInterface_ReadDocument;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataSerializeReaderInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataSerializeReaderInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 20LL, DataSerializeReaderInterface, _DataSerializeReaderInterface_ReadDocument),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataSerializeReaderInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataSerializeReaderInterface(nullptr, &DataSerializeReaderInterface::ProxyComponent::_descriptor, &RegisterReflection_DataSerializeReaderInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
