#if 1
namespace maxon
{
	namespace py
	{
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPyInterface(CPyInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPyRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPyInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPyInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPyInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		void Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Init_Offset), maxon::reflection::Argument::ByValue(lib), maxon::reflection::Argument::ByValue(refType), maxon::reflection::Argument::ByValue(pyObject)};
			(*handler_)(_fn_CPyInterface_Init, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void), const CPythonLibraryInterface*, REFTYPE, NativePyObject*), reinterpret_cast<const void* const&>(mt_.CPyInterface_Init)));
		}
		static const maxon::reflection::Function* _fn_CPyInterface_Init;
		void Incref() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Incref_Offset)};
			(*handler_)(_fn_CPyInterface_Incref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.CPyInterface_Incref)));
		}
		static const maxon::reflection::Function* _fn_CPyInterface_Incref;
		void Decref() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Decref_Offset)};
			(*handler_)(_fn_CPyInterface_Decref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((void)), reinterpret_cast<const void* const&>(mt_.CPyInterface_Decref)));
		}
		static const maxon::reflection::Function* _fn_CPyInterface_Decref;
		Int64 GetRefCount() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			Int64 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetRefCount_Offset)};
			(*handler_)(_fn_CPyInterface_GetRefCount, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int64)), reinterpret_cast<const void* const&>(mt_.CPyInterface_GetRefCount)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyInterface_GetRefCount;
		const CPythonLibraryInterface* GetLibrary() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			const CPythonLibraryInterface* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetLibrary_Offset)};
			(*handler_)(_fn_CPyInterface_GetLibrary, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const CPythonLibraryInterface*)), reinterpret_cast<const void* const&>(mt_.CPyInterface_GetLibrary)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyInterface_GetLibrary;
		CPyTypeRef GetTypeRef() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			CPyTypeRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetTypeRef_Offset)};
			(*handler_)(_fn_CPyInterface_GetTypeRef, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyTypeRef)), reinterpret_cast<const void* const&>(mt_.CPyInterface_GetTypeRef)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyInterface_GetTypeRef;
		NativePyObject* GetPyObject() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			NativePyObject* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_GetPyObject_Offset)};
			(*handler_)(_fn_CPyInterface_GetPyObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((NativePyObject*)), reinterpret_cast<const void* const&>(mt_.CPyInterface_GetPyObject)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyInterface_GetPyObject;
		NativePyObject* Disconnect() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyInterface>();
			NativePyObject* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyInterface_Disconnect_Offset)};
			(*handler_)(_fn_CPyInterface_Disconnect, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((NativePyObject*)), reinterpret_cast<const void* const&>(mt_.CPyInterface_Disconnect)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyInterface_Disconnect;
		};
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_Init;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_Incref;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_Decref;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_GetRefCount;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_GetLibrary;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_GetTypeRef;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_GetPyObject;
	const maxon::reflection::Function* CPyInterface::ProxyComponent::_fn_CPyInterface_Disconnect;
		PRIVATE_MAXON_COMPONENT_REGISTER(CPyInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPyInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "lib\0refType\0pyObject\0", 5LL, CPyInterface, CPyInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_Incref),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_Decref),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_GetRefCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_GetLibrary),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_GetTypeRef),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_GetPyObject),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPyInterface, CPyInterface_Disconnect),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPyInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPyInterface(nullptr, &CPyInterface::ProxyComponent::_descriptor, &RegisterReflection_CPyInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPyTypeInterface(CPyTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPyTypeRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPyTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPyTypeInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPyTypeInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(CPyTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPyTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPyTypeInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPyTypeInterface(nullptr, &CPyTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_CPyTypeInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPyFrameInterface(CPyFrameInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPyFrameRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPyFrameInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPyFrameInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPyFrameInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		CPyFrameRef GetBack() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyFrameInterface>();
			CPyFrameRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetBack_Offset)};
			(*handler_)(_fn_CPyFrameInterface_GetBack, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyFrameRef)), reinterpret_cast<const void* const&>(mt_.CPyFrameInterface_GetBack)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyFrameInterface_GetBack;
		CPyCodeRef GetCode() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyFrameInterface>();
			CPyCodeRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetCode_Offset)};
			(*handler_)(_fn_CPyFrameInterface_GetCode, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyCodeRef)), reinterpret_cast<const void* const&>(mt_.CPyFrameInterface_GetCode)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyFrameInterface_GetCode;
		Int32 GetLastInstruction() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyFrameInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyFrameInterface_GetLastInstruction_Offset)};
			(*handler_)(_fn_CPyFrameInterface_GetLastInstruction, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CPyFrameInterface_GetLastInstruction)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyFrameInterface_GetLastInstruction;
		};
	const maxon::reflection::Function* CPyFrameInterface::ProxyComponent::_fn_CPyFrameInterface_GetBack;
	const maxon::reflection::Function* CPyFrameInterface::ProxyComponent::_fn_CPyFrameInterface_GetCode;
	const maxon::reflection::Function* CPyFrameInterface::ProxyComponent::_fn_CPyFrameInterface_GetLastInstruction;
		PRIVATE_MAXON_COMPONENT_REGISTER(CPyFrameInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPyFrameInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyFrameInterface, CPyFrameInterface_GetBack),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyFrameInterface, CPyFrameInterface_GetCode),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyFrameInterface, CPyFrameInterface_GetLastInstruction),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPyFrameInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPyFrameInterface(nullptr, &CPyFrameInterface::ProxyComponent::_descriptor, &RegisterReflection_CPyFrameInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPyTracebackInterface(CPyTracebackInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPyTracebackRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPyTracebackInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPyTracebackInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPyTracebackInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		CPyTracebackRef GetNext() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyTracebackInterface>();
			CPyTracebackRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTracebackRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetNext_Offset)};
			(*handler_)(_fn_CPyTracebackInterface_GetNext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyTracebackRef)), reinterpret_cast<const void* const&>(mt_.CPyTracebackInterface_GetNext)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyTracebackInterface_GetNext;
		Int32 GetLineNumber() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyTracebackInterface>();
			Int32 proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetLineNumber_Offset)};
			(*handler_)(_fn_CPyTracebackInterface_GetLineNumber, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Int32)), reinterpret_cast<const void* const&>(mt_.CPyTracebackInterface_GetLineNumber)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyTracebackInterface_GetLineNumber;
		CPyFrameRef GetFrameRef() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyTracebackInterface>();
			CPyFrameRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyTracebackInterface_GetFrameRef_Offset)};
			(*handler_)(_fn_CPyTracebackInterface_GetFrameRef, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyFrameRef)), reinterpret_cast<const void* const&>(mt_.CPyTracebackInterface_GetFrameRef)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyTracebackInterface_GetFrameRef;
		};
	const maxon::reflection::Function* CPyTracebackInterface::ProxyComponent::_fn_CPyTracebackInterface_GetNext;
	const maxon::reflection::Function* CPyTracebackInterface::ProxyComponent::_fn_CPyTracebackInterface_GetLineNumber;
	const maxon::reflection::Function* CPyTracebackInterface::ProxyComponent::_fn_CPyTracebackInterface_GetFrameRef;
		PRIVATE_MAXON_COMPONENT_REGISTER(CPyTracebackInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPyTracebackInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyTracebackInterface, CPyTracebackInterface_GetNext),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyTracebackInterface, CPyTracebackInterface_GetLineNumber),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyTracebackInterface, CPyTracebackInterface_GetFrameRef),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPyTracebackInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPyTracebackInterface(nullptr, &CPyTracebackInterface::ProxyComponent::_descriptor, &RegisterReflection_CPyTracebackInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPyCodeInterface(CPyCodeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPyCodeRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPyCodeInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPyCodeInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPyCodeInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		CPyRef GetFilename() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyCodeInterface>();
			CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyCodeInterface_GetFilename_Offset)};
			(*handler_)(_fn_CPyCodeInterface_GetFilename, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyRef)), reinterpret_cast<const void* const&>(mt_.CPyCodeInterface_GetFilename)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyCodeInterface_GetFilename;
		CPyRef GetName() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPyCodeInterface>();
			CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CPyCodeInterface_GetName_Offset)};
			(*handler_)(_fn_CPyCodeInterface_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((CPyRef)), reinterpret_cast<const void* const&>(mt_.CPyCodeInterface_GetName)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CPyCodeInterface_GetName;
		};
	const maxon::reflection::Function* CPyCodeInterface::ProxyComponent::_fn_CPyCodeInterface_GetFilename;
	const maxon::reflection::Function* CPyCodeInterface::ProxyComponent::_fn_CPyCodeInterface_GetName;
		PRIVATE_MAXON_COMPONENT_REGISTER(CPyCodeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPyCodeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyCodeInterface, CPyCodeInterface_GetFilename),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPyCodeInterface, CPyCodeInterface_GetName),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPyCodeInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPyCodeInterface(nullptr, &CPyCodeInterface::ProxyComponent::_descriptor, &RegisterReflection_CPyCodeInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyClassInterface(MPyClassInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyClassRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyClassInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyClassInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyClassInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyClassInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyClassInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyClassInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyClassInterface(nullptr, &MPyClassInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyClassInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyMemberInterface(MPyMemberInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyMemberRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyMemberInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyMemberInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyMemberInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyMemberInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyMemberInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyMemberInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyMemberInterface(nullptr, &MPyMemberInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyMemberInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyFunctionInterface(MPyFunctionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyFunctionRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyFunctionInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyFunctionInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyFunctionInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		const reflection::Function* GetFunction() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyFunctionInterface>();
			const reflection::Function* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyFunctionInterface_GetFunction_Offset)};
			(*handler_)(_fn_MPyFunctionInterface_GetFunction, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const reflection::Function*)), reinterpret_cast<const void* const&>(mt_.MPyFunctionInterface_GetFunction)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyFunctionInterface_GetFunction;
		};
	const maxon::reflection::Function* MPyFunctionInterface::ProxyComponent::_fn_MPyFunctionInterface_GetFunction;
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyFunctionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyFunctionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MPyFunctionInterface, MPyFunctionInterface_GetFunction),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyFunctionInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyFunctionInterface(nullptr, &MPyFunctionInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyFunctionInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyHashMapInterface(MPyHashMapInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyHashMapRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyHashMapInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyHashMapInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyHashMapInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		HashMap<Data, Data>* GetHashMap() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyHashMapInterface>();
			HashMap<Data, Data>* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyHashMapInterface_GetHashMap_Offset)};
			(*handler_)(_fn_MPyHashMapInterface_GetHashMap, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((HashMap<Data, Data>*)), reinterpret_cast<const void* const&>(mt_.MPyHashMapInterface_GetHashMap)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyHashMapInterface_GetHashMap;
		};
	const maxon::reflection::Function* MPyHashMapInterface::ProxyComponent::_fn_MPyHashMapInterface_GetHashMap;
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyHashMapInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyHashMapInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MPyHashMapInterface, MPyHashMapInterface_GetHashMap),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyHashMapInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyHashMapInterface(nullptr, &MPyHashMapInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyHashMapInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyDataTypeInterface(MPyDataTypeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyDataTypeRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyDataTypeInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyDataTypeInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyDataTypeInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		const DataType& GetType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataTypeInterface>();
			const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataTypeInterface_GetType_Offset)};
			(*handler_)(_fn_MPyDataTypeInterface_GetType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.MPyDataTypeInterface_GetType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataTypeInterface_GetType;
		};
	const maxon::reflection::Function* MPyDataTypeInterface::ProxyComponent::_fn_MPyDataTypeInterface_GetType;
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyDataTypeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyDataTypeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MPyDataTypeInterface, MPyDataTypeInterface_GetType),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyDataTypeInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyDataTypeInterface(nullptr, &MPyDataTypeInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyDataTypeInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyDataInterface(MPyDataInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyDataRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyDataInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyDataInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyDataInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		const DataType& GetType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetType_Offset)};
			(*handler_)(_fn_MPyDataInterface_GetType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_GetType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_GetType;
		const DataType& GetMappingType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetMappingType_Offset)};
			(*handler_)(_fn_MPyDataInterface_GetMappingType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DataType&)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_GetMappingType)));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_GetMappingType;
		Data* GetData() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			Data* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetData_Offset)};
			(*handler_)(_fn_MPyDataInterface_GetData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Data*)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_GetData)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_GetData;
		const Data* GetData() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			const Data* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_GetData_1_Offset)};
			(*handler_)(_fn_MPyDataInterface_GetData_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const Data*)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_GetData_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_GetData_1;
		const Generic* PrivateGetPtr() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			const Generic* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_PrivateGetPtr_Offset)};
			(*handler_)(_fn_MPyDataInterface_PrivateGetPtr, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const Generic*)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_PrivateGetPtr)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_PrivateGetPtr;
		Generic* PrivateGetPtr() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MPyDataInterface>();
			Generic* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MPyDataInterface_PrivateGetPtr_1_Offset)};
			(*handler_)(_fn_MPyDataInterface_PrivateGetPtr_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Generic*)), reinterpret_cast<const void* const&>(mt_.MPyDataInterface_PrivateGetPtr_1)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MPyDataInterface_PrivateGetPtr_1;
		};
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_GetType;
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_GetMappingType;
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_GetData;
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_GetData_1;
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_PrivateGetPtr;
	const maxon::reflection::Function* MPyDataInterface::ProxyComponent::_fn_MPyDataInterface_PrivateGetPtr_1;
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyDataInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyDataInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_GetType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_GetMappingType),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_GetData),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_GetData_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_PrivateGetPtr),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MPyDataInterface, MPyDataInterface_PrivateGetPtr_1),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyDataInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyDataInterface(nullptr, &MPyDataInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyDataInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_MPyCallerContextInterface(MPyCallerContextInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::MPyCallerContextRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class MPyCallerContextInterface::ProxyComponent : public maxon::Component<ProxyComponent, MPyCallerContextInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, MPyCallerContextInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(MPyCallerContextInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_MPyCallerContextInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MPyCallerContextInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_MPyCallerContextInterface(nullptr, &MPyCallerContextInterface::ProxyComponent::_descriptor, &RegisterReflection_MPyCallerContextInterface, &PRIVATE_MAXON_MODULE);
	#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		PRIVATE_MAXON_REGISTRY_DEFINE(CPyReferences3);
	#endif
	}
}
#endif
