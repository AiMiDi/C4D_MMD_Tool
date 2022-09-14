#if 1
namespace maxon
{
/// @cond INTERNAL

#ifdef MAXON_LARGE_VTABLE
#else
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
#ifdef MAXON_COMPONENT_HASHTABLE
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
/// @endcond

#ifdef MAXON_TARGET_DEBUG
#endif
	namespace details
	{
#ifndef _HAS_CPP20_COMPARISONS
#endif
	}
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0cid\0kind\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetId)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetKind)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetSize)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetComponents)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_AddComponent)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "component\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_RemoveLastComponent)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_AddComponents)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "cls\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_Finalize)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_IsFinalized)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetImplementedInterfaces)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetDataType)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_Create)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_CreatePointer)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "size\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_IsSubclassOf)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetMetaData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_InitMetaData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_DeleteInstance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_DestructInstance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_CopyInstance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dest\0src\0", 6LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetInfo)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_GetOrCreateMTable)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "info\0i\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ClassInterface::MTable::_instance.ClassInterface_AddProxyComponent)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "component\0shared\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ClassInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ClassInterface("net.maxon.interface.class", nullptr, &RegisterReflection_ClassInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @cond INTERNAL

#ifdef MAXON_COMPILER_MSVC
#else
#endif
/// @endcond

#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ObjectInterface(ObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ObjectRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ObjectInterface::ProxyComponent : public maxon::Component<ProxyComponent, ObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ObjectInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		String ToString(const FormatStatement* formatStatement) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_ToString_Offset), maxon::reflection::Argument::ByValue(formatStatement)};
			(*handler_)(_fn_ObjectInterface_ToString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String), const FormatStatement*), reinterpret_cast<const void* const&>(mt_.ObjectInterface_ToString)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_ToString;
		Result<void> InitObject(const void* argument) 
		{
			return OK;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_InitObject;
		Result<void> HandleMessage(const InternedId& message, void* argument) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleMessage_Offset), maxon::reflection::Argument::ByReference(message), maxon::reflection::Argument::ByValue(argument)};
			(*handler_)(_fn_ObjectInterface_HandleMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const InternedId&, void*), reinterpret_cast<const void* const&>(mt_.ObjectInterface_HandleMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_HandleMessage;
		Result<void> HandleConstMessage(const InternedId& message, void* argument) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleConstMessage_Offset), maxon::reflection::Argument::ByReference(message), maxon::reflection::Argument::ByValue(argument)};
			(*handler_)(_fn_ObjectInterface_HandleConstMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const InternedId&, void*), reinterpret_cast<const void* const&>(mt_.ObjectInterface_HandleConstMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_HandleConstMessage;
		Bool IsEqual(const maxon::ObjectInterface* other) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_IsEqual_Offset), maxon::reflection::Argument::ByValue(other)};
			(*handler_)(_fn_ObjectInterface_IsEqual, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), const maxon::ObjectInterface*), reinterpret_cast<const void* const&>(mt_.ObjectInterface_IsEqual)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_IsEqual;
		COMPARERESULT Compare(const maxon::ObjectInterface* other) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			COMPARERESULT proxy_result = maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_Compare_Offset), maxon::reflection::Argument::ByValue(other)};
			(*handler_)(_fn_ObjectInterface_Compare, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((COMPARERESULT), const maxon::ObjectInterface*), reinterpret_cast<const void* const&>(mt_.ObjectInterface_Compare)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_Compare;
		HashInt GetHashCodeImpl() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			HashInt proxy_result = maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetHashCodeImpl_Offset)};
			(*handler_)(_fn_ObjectInterface_GetHashCodeImpl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((HashInt)), reinterpret_cast<const void* const&>(mt_.ObjectInterface_GetHashCodeImpl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_GetHashCodeImpl;
		UniqueHash GetUniqueHashCodeImpl() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObjectInterface>();
			UniqueHash proxy_result = maxon::PrivateIncompleteNullReturnValue<UniqueHash>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetUniqueHashCodeImpl_Offset)};
			(*handler_)(_fn_ObjectInterface_GetUniqueHashCodeImpl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((UniqueHash)), reinterpret_cast<const void* const&>(mt_.ObjectInterface_GetUniqueHashCodeImpl)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObjectInterface_GetUniqueHashCodeImpl;
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	};
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_ToString;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_InitObject;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_HandleMessage;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_HandleConstMessage;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_IsEqual;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_Compare;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_GetHashCodeImpl;
	const maxon::reflection::Function* ObjectInterface::ProxyComponent::_fn_ObjectInterface_GetUniqueHashCodeImpl;
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_COMPONENT_REGISTER(ObjectInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, ObjectInterface, ObjectInterface_ToString),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "argument\0", 1LL, ObjectInterface, ObjectInterface_InitObject),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "message\0argument\0", 5LL, ObjectInterface, ObjectInterface_HandleMessage),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "message\0argument\0", 5LL, ObjectInterface, ObjectInterface_HandleConstMessage),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "other\0", 1LL, ObjectInterface, ObjectInterface_IsEqual),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "other\0", 1LL, ObjectInterface, ObjectInterface_Compare),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObjectInterface, ObjectInterface_GetHashCodeImpl),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObjectInterface, ObjectInterface_GetUniqueHashCodeImpl),
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ObjectInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ObjectInterface(nullptr, &ObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_ObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @cond INTERNAL

#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifndef MAXON_COMPONENT_HASHTABLE
#elif defined(MAXON_TARGET_DEBUG)
#else
#endif
/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ErrorInterface(ErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::Error");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, ErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const SourceLocation& GetLocation() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			const SourceLocation* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const SourceLocation&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetLocation_Offset)};
			(*handler_)(_fn_ErrorInterface_GetLocation, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const SourceLocation&)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_GetLocation)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_GetLocation;
		void SetLocation(const maxon::SourceLocation& allocLocation) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetLocation_Offset), maxon::reflection::Argument::ByReference(allocLocation)};
			(*handler_)(_fn_ErrorInterface_SetLocation, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const maxon::SourceLocation&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetLocation)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetLocation;
		Block<void* const> GetStackTrace() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			Block<void* const> proxy_result = maxon::PrivateIncompleteNullReturnValue<Block<void* const>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetStackTrace_Offset)};
			(*handler_)(_fn_ErrorInterface_GetStackTrace, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Block<void* const>)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_GetStackTrace)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_GetStackTrace;
		void SetStackTrace(const Block<void* const>& trace) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetStackTrace_Offset), maxon::reflection::Argument::ByReference(trace)};
			(*handler_)(_fn_ErrorInterface_SetStackTrace, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Block<void* const>&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetStackTrace)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetStackTrace;
		String GetMessage() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMessage_Offset)};
			(*handler_)(_fn_ErrorInterface_GetMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_GetMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_GetMessage;
		void SetMessage(const String& message) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessage_Offset), maxon::reflection::Argument::ByReference(message)};
			(*handler_)(_fn_ErrorInterface_SetMessage, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const String&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetMessage)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetMessage;
		String FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_FormatMessage_Offset), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(partFormatter)};
			(*handler_)(_fn_ErrorInterface_FormatMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String), const LanguageRef&, const PartFormatter&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_FormatMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_FormatMessage;
		void SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessageDelegate_Offset), maxon::reflection::Argument::ByReference(message)};
			(*handler_)(_fn_ErrorInterface_SetMessageDelegate, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetMessageDelegate)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetMessageDelegate;
		const Error& GetCause() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			const Error* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetCause_Offset)};
			(*handler_)(_fn_ErrorInterface_GetCause, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const Error&)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_GetCause)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_GetCause;
		void SetCause(const Error& cause) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetCause_Offset), maxon::reflection::Argument::ByReference(cause)};
			(*handler_)(_fn_ErrorInterface_SetCause, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Error&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetCause)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetCause;
		void GetMachine(MachineRef& machine) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMachine_Offset), maxon::reflection::Argument::ByReference(machine)};
			(*handler_)(_fn_ErrorInterface_GetMachine, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), MachineRef&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_GetMachine)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_GetMachine;
		void SetMachine(const MachineRef& machine) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMachine_Offset), maxon::reflection::Argument::ByReference(machine)};
			(*handler_)(_fn_ErrorInterface_SetMachine, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const MachineRef&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_SetMachine)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_SetMachine;
		Int PrivateGetCode() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetCode_Offset)};
			(*handler_)(_fn_ErrorInterface_PrivateGetCode, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_PrivateGetCode)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_PrivateGetCode;
		void PrivateSetCode(Int code) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetCode_Offset), maxon::reflection::Argument::ByValue(code)};
			(*handler_)(_fn_ErrorInterface_PrivateSetCode, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), Int), reinterpret_cast<const void* const&>(mt_.ErrorInterface_PrivateSetCode)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_PrivateSetCode;
		void PrivateSetPreallocation(ThreadReferencedError preallocation) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetPreallocation_Offset), maxon::reflection::Argument::ByValue(preallocation)};
			(*handler_)(_fn_ErrorInterface_PrivateSetPreallocation, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), ThreadReferencedError), reinterpret_cast<const void* const&>(mt_.ErrorInterface_PrivateSetPreallocation)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_PrivateSetPreallocation;
		ThreadReferencedError PrivateGetPreallocation() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			ThreadReferencedError proxy_result = maxon::PrivateIncompleteNullReturnValue<ThreadReferencedError>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetPreallocation_Offset)};
			(*handler_)(_fn_ErrorInterface_PrivateGetPreallocation, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((ThreadReferencedError)), reinterpret_cast<const void* const&>(mt_.ErrorInterface_PrivateGetPreallocation)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_PrivateGetPreallocation;
		void PrivateSetDebugError(const Error& cause) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetDebugError_Offset), maxon::reflection::Argument::ByReference(cause)};
			(*handler_)(_fn_ErrorInterface_PrivateSetDebugError, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const Error&), reinterpret_cast<const void* const&>(mt_.ErrorInterface_PrivateSetDebugError)));
		}
		static const maxon::reflection::Function* _fn_ErrorInterface_PrivateSetDebugError;
	};
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_GetLocation;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetLocation;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_GetStackTrace;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetStackTrace;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_GetMessage;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetMessage;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_FormatMessage;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetMessageDelegate;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_GetCause;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetCause;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_GetMachine;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_SetMachine;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_PrivateGetCode;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_PrivateSetCode;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_PrivateSetPreallocation;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_PrivateGetPreallocation;
	const maxon::reflection::Function* ErrorInterface::ProxyComponent::_fn_ErrorInterface_PrivateSetDebugError;
	PRIVATE_MAXON_COMPONENT_REGISTER(ErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_GetLocation),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "allocLocation\0", 1LL, ErrorInterface, ErrorInterface_SetLocation),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_GetStackTrace),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "trace\0", 1LL, ErrorInterface, ErrorInterface_SetStackTrace),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_GetMessage),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "message\0", 1LL, ErrorInterface, ErrorInterface_SetMessage),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "language\0partFormatter\0", 5LL, ErrorInterface, ErrorInterface_FormatMessage),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "message\0", 1LL, ErrorInterface, ErrorInterface_SetMessageDelegate),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_GetCause),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "cause\0", 1LL, ErrorInterface, ErrorInterface_SetCause),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "machine\0", 2LL, ErrorInterface, ErrorInterface_GetMachine),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "machine\0", 1LL, ErrorInterface, ErrorInterface_SetMachine),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_PrivateGetCode),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "code\0", 0LL, ErrorInterface, ErrorInterface_PrivateSetCode),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "preallocation\0", 0LL, ErrorInterface, ErrorInterface_PrivateSetPreallocation),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ErrorInterface, ErrorInterface_PrivateGetPreallocation),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "cause\0", 0LL, ErrorInterface, ErrorInterface_PrivateSetDebugError),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ErrorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ErrorInterface(nullptr, &ErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(Classes);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ClassTransformers);
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_NO_OBJECT_IMPL_DEPENDENCY)
#endif
/// @cond INTERNAL

/// @endcond

	namespace details
	{
#ifdef MAXON_TARGET_MACOS
#endif
	}
}
#endif
