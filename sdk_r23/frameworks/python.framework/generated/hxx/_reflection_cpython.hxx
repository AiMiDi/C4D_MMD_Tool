#if 1
namespace maxon
{
	namespace py
	{
#ifdef MAXON_TARGET_WINDOWS
#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_PythonErrorInterface(PythonErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::PythonError");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class PythonErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, PythonErrorInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, PythonErrorInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(PythonErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_PythonErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PythonErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_PythonErrorInterface(nullptr, &PythonErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_PythonErrorInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_PythonTracebackErrorInterface(PythonTracebackErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::PythonTracebackError");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class PythonTracebackErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, PythonTracebackErrorInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, PythonTracebackErrorInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
			void SetUrl(const Url& url) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PythonTracebackErrorInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PythonTracebackErrorInterface_SetUrl_Offset), maxon::reflection::Argument::ByReference(url)};
				(*handler_)(_fn_PythonTracebackErrorInterface_SetUrl, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._PythonTracebackErrorInterface_SetUrl));
			}
			static const maxon::reflection::Function* _fn_PythonTracebackErrorInterface_SetUrl;
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PythonTracebackErrorInterface>();
				const Url* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PythonTracebackErrorInterface_GetUrl_Offset)};
				(*handler_)(_fn_PythonTracebackErrorInterface_GetUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Url&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PythonTracebackErrorInterface_GetUrl));
				return *proxy_result;
			}
			static const maxon::reflection::Function* _fn_PythonTracebackErrorInterface_GetUrl;
			void SetLineNumber(Int line) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PythonTracebackErrorInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PythonTracebackErrorInterface_SetLineNumber_Offset), maxon::reflection::Argument::ByValue(line)};
				(*handler_)(_fn_PythonTracebackErrorInterface_SetLineNumber, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, Int>::Invoke, (const void*) mt_._PythonTracebackErrorInterface_SetLineNumber));
			}
			static const maxon::reflection::Function* _fn_PythonTracebackErrorInterface_SetLineNumber;
			Int GetLineNumber() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PythonTracebackErrorInterface>();
				Int proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PythonTracebackErrorInterface_GetLineNumber_Offset)};
				(*handler_)(_fn_PythonTracebackErrorInterface_GetLineNumber, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._PythonTracebackErrorInterface_GetLineNumber));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_PythonTracebackErrorInterface_GetLineNumber;
		};
		const maxon::reflection::Function* PythonTracebackErrorInterface::ProxyComponent::_fn_PythonTracebackErrorInterface_SetUrl;
		const maxon::reflection::Function* PythonTracebackErrorInterface::ProxyComponent::_fn_PythonTracebackErrorInterface_GetUrl;
		const maxon::reflection::Function* PythonTracebackErrorInterface::ProxyComponent::_fn_PythonTracebackErrorInterface_SetLineNumber;
		const maxon::reflection::Function* PythonTracebackErrorInterface::ProxyComponent::_fn_PythonTracebackErrorInterface_GetLineNumber;
		PRIVATE_MAXON_COMPONENT_REGISTER(PythonTracebackErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_PythonTracebackErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0", 1LL, PythonTracebackErrorInterface, _PythonTracebackErrorInterface_SetUrl),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PythonTracebackErrorInterface, _PythonTracebackErrorInterface_GetUrl),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "line\0", 1LL, PythonTracebackErrorInterface, _PythonTracebackErrorInterface_SetLineNumber),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, PythonTracebackErrorInterface, _PythonTracebackErrorInterface_GetLineNumber),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PythonTracebackErrorInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_PythonTracebackErrorInterface(nullptr, &PythonTracebackErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_PythonTracebackErrorInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_PythonSystemExitErrorInterface(PythonSystemExitErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::PythonSystemExitError");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class PythonSystemExitErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, PythonSystemExitErrorInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, PythonSystemExitErrorInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
		};
		PRIVATE_MAXON_COMPONENT_REGISTER(PythonSystemExitErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_PythonSystemExitErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PythonSystemExitErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_PythonSystemExitErrorInterface(nullptr, &PythonSystemExitErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_PythonSystemExitErrorInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		static maxon::InterfaceDefinition s_CPythonLibraryInterface(CPythonLibraryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::py::CPythonLibraryRef");
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		class CPythonLibraryInterface::ProxyComponent : public maxon::Component<ProxyComponent, CPythonLibraryInterface>
		{
			MAXON_COMPONENT();
		public:
			using typename maxon::Component<ProxyComponent, CPythonLibraryInterface>::_Wrapper;
			static const maxon::Bool PROXY = true;
			maxon::reflection::ProxyHandler _handler;
			Result<void> Init(const Url& librarypath, Bool createSubLibrary) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_Init_Offset), maxon::reflection::Argument::ByReference(librarypath), maxon::reflection::Argument::ByValue(createSubLibrary)};
				(*handler_)(_fn_CPythonLibraryInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_Init));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_Init;
			Result<void> InitTypes() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_InitTypes_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_InitTypes, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_InitTypes));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_InitTypes;
			Result<void> InitBuiltinModules() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_InitBuiltinModules_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_InitBuiltinModules, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_InitBuiltinModules));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_InitBuiltinModules;
			void CPy_Initialize() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_Initialize_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_Initialize, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_Initialize));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_Initialize;
			void CPy_Finalize() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_Finalize_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_Finalize, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_Finalize));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_Finalize;
			CPyRef CPyModule_Create(const ModuleDefinition& module) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_Create_Offset), maxon::reflection::Argument::ByReference(module)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_Create, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const ModuleDefinition&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_Create));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_Create;
			void Free(const Delegate<void()>& shutdownEngine) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_Free_Offset), maxon::reflection::Argument::ByReference(shutdownEngine)};
				(*handler_)(_fn_CPythonLibraryInterface_Free, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const Delegate<void()>&>::Invoke, (const void*) mt_._CPythonLibraryInterface_Free));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_Free;
			const PythonDll& GetDll() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const PythonDll* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const PythonDll&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetDll_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetDll, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const PythonDll&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetDll));
				return *proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetDll;
			FILE_native* FopenNative(const Char* name, const Char* mode) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				FILE_native* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_FopenNative_Offset), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByValue(mode)};
				(*handler_)(_fn_CPythonLibraryInterface_FopenNative, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<FILE_native*, maxon::GenericComponent*, const Char*, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_FopenNative));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_FopenNative;
			Error LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Error proxy_result = maxon::PrivateIncompleteNullReturnValue<Error>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_LastPythonCallFailed_Offset), maxon::reflection::Argument::ByReference(allocLocation), maxon::reflection::Argument::ByValue(withTraceback), maxon::reflection::Argument::ByValue(restoreError)};
				(*handler_)(_fn_CPythonLibraryInterface_LastPythonCallFailed, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Error, maxon::GenericComponent*, const maxon::SourceLocation&, Bool, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_LastPythonCallFailed));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_LastPythonCallFailed;
			Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<MPyDataRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_RegisterComponentProxy_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByReference(registryId), maxon::reflection::Argument::ByReference(baseAndInterfaceIds), maxon::reflection::Argument::ByReference(cid), maxon::reflection::Argument::ByValue(printErrors), maxon::reflection::Argument::ByValue(kind), maxon::reflection::Argument::ByReference(loc), maxon::reflection::Argument::ByValue(createObject), maxon::reflection::Argument::ByReference(dtOfObject)};
				(*handler_)(_fn_CPythonLibraryInterface_RegisterComponentProxy, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<MPyDataRef>, maxon::GenericComponent*, const CPyRef&, const Id&, const ProxyDefinition&, const Id&, Bool, ClassInterface::KIND, const SourceLocation&, Bool, const DataType&>::Invoke, (const void*) mt_._CPythonLibraryInterface_RegisterComponentProxy));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_RegisterComponentProxy;
			Bool CPy_IsInitialized() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_IsInitialized_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_IsInitialized, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_IsInitialized));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_IsInitialized;
			const Char* CPy_GetVersion() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetVersion_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetVersion, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetVersion));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetVersion;
			const Char* CPy_GetPlatform() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetPlatform_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetPlatform, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetPlatform));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetPlatform;
			const Char* CPy_GetCopyright() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetCopyright_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetCopyright, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetCopyright));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetCopyright;
			const Char* CPy_GetCompiler() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetCompiler_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetCompiler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetCompiler));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetCompiler;
			const Char* CPy_GetBuildInfo() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetBuildInfo_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetBuildInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetBuildInfo));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetBuildInfo;
			Result<void> CPy_SetProgramName(const String& name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_SetProgramName_Offset), maxon::reflection::Argument::ByReference(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_SetProgramName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_SetProgramName));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_SetProgramName;
			Result<void> CPy_SetPythonHome(const Url& name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_SetPythonHome_Offset), maxon::reflection::Argument::ByReference(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_SetPythonHome, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_SetPythonHome));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_SetPythonHome;
			String CPy_GetProgramName() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetProgramName_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetProgramName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetProgramName));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetProgramName;
			String CPy_GetPythonHome() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_GetPythonHome_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_GetPythonHome, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_GetPythonHome));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_GetPythonHome;
			Bool ExecuteModule(const String& name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_ExecuteModule_Offset), maxon::reflection::Argument::ByReference(name)};
				(*handler_)(_fn_CPythonLibraryInterface_ExecuteModule, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._CPythonLibraryInterface_ExecuteModule));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_ExecuteModule;
			MPyCallerContextRef CPyCallerContext_New() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyCallerContextRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyCallerContextRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCallerContext_New_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCallerContext_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyCallerContextRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCallerContext_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCallerContext_New;
			Bool CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyRun_SimpleFileExFlags_Offset), maxon::reflection::Argument::ByValue(fp), maxon::reflection::Argument::ByValue(filename), maxon::reflection::Argument::ByValue(closeit), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, FILE_native*, const Char*, Int32, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyRun_SimpleFileExFlags));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags;
			Bool CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1_Offset), maxon::reflection::Argument::ByReference(url), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const Url&, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1;
			CPyRef CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyRun_SimpleStringFlags_Offset), maxon::reflection::Argument::ByReference(code), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyRun_SimpleStringFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const String&, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyRun_SimpleStringFlags));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyRun_SimpleStringFlags;
			NativePyObject* CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				NativePyObject* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyRun_FileExFlags_Offset), maxon::reflection::Argument::ByValue(fp), maxon::reflection::Argument::ByValue(filename), maxon::reflection::Argument::ByValue(start), maxon::reflection::Argument::ByValue(globals), maxon::reflection::Argument::ByValue(locals), maxon::reflection::Argument::ByValue(closeit), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyRun_FileExFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NativePyObject*, maxon::GenericComponent*, FILE_native*, const Char*, Int32, NativePyObject*, NativePyObject*, Int32, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyRun_FileExFlags));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyRun_FileExFlags;
			Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyRun_InteractiveLoopFlags_Offset), maxon::reflection::Argument::ByValue(fp), maxon::reflection::Argument::ByValue(filename), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyRun_InteractiveLoopFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, FILE*, const Char*, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyRun_InteractiveLoopFlags));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyRun_InteractiveLoopFlags;
			PYGILSTATE CPyGilState_Ensure() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				PYGILSTATE proxy_result = maxon::PrivateIncompleteNullReturnValue<PYGILSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyGilState_Ensure_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyGilState_Ensure, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<PYGILSTATE, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyGilState_Ensure));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyGilState_Ensure;
			void CPyGilState_Release(PYGILSTATE state) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyGilState_Release_Offset), maxon::reflection::Argument::ByValue(state)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyGilState_Release, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, PYGILSTATE>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyGilState_Release));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyGilState_Release;
			GILSTATE GetGilState() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				GILSTATE proxy_result = maxon::PrivateIncompleteNullReturnValue<GILSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetGilState_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetGilState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<GILSTATE, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetGilState));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetGilState;
			NativePyThreadState* CPyGILState_GetThisThreadState() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				NativePyThreadState* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyGILState_GetThisThreadState_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyGILState_GetThisThreadState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NativePyThreadState*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyGILState_GetThisThreadState));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyGILState_GetThisThreadState;
			NativePyThreadState* CPyThreadState_Swap(NativePyThreadState* state) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				NativePyThreadState* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyThreadState_Swap_Offset), maxon::reflection::Argument::ByValue(state)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyThreadState_Swap, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NativePyThreadState*, maxon::GenericComponent*, NativePyThreadState*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyThreadState_Swap));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyThreadState_Swap;
			CPyRef CPyThreadState_GetDict() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyThreadState_GetDict_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyThreadState_GetDict, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyThreadState_GetDict));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyThreadState_GetDict;
			CPyCodeRef CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyCodeRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_CompileStringFlags_Offset), maxon::reflection::Argument::ByValue(code), maxon::reflection::Argument::ByValue(filename), maxon::reflection::Argument::ByValue(start), maxon::reflection::Argument::ByValue(flags)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_CompileStringFlags, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyCodeRef, maxon::GenericComponent*, const Char*, const Char*, PYINPUT, CPyCompilerFlags*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_CompileStringFlags));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_CompileStringFlags;
			void CPy_Incref(NativePyObject* o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_Incref_Offset), maxon::reflection::Argument::ByValue(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_Incref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, NativePyObject*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_Incref));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_Incref;
			void CPy_Decref(NativePyObject* o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_Decref_Offset), maxon::reflection::Argument::ByValue(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_Decref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, NativePyObject*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_Decref));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_Decref;
			void CPy_SafeIncref(NativePyObject* o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_SafeIncref_Offset), maxon::reflection::Argument::ByValue(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_SafeIncref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, NativePyObject*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_SafeIncref));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_SafeIncref;
			void CPy_SafeDecref(NativePyObject* o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_SafeDecref_Offset), maxon::reflection::Argument::ByValue(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_SafeDecref, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, const maxon::GenericComponent*, NativePyObject*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_SafeDecref));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_SafeDecref;
			Int64 CPyGC_Collect() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int64 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyGC_Collect_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyGC_Collect, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int64, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyGC_Collect));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyGC_Collect;
			Int32 CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCode_Addr2Line_Offset), maxon::reflection::Argument::ByReference(codeObject), maxon::reflection::Argument::ByValue(x)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCode_Addr2Line, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32, maxon::GenericComponent*, const CPyCodeRef&, Int32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCode_Addr2Line));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCode_Addr2Line;
			CPyRef UnpackDataType(const CPyRef& obj) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_UnpackDataType_Offset), maxon::reflection::Argument::ByReference(obj)};
				(*handler_)(_fn_CPythonLibraryInterface_UnpackDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_UnpackDataType));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_UnpackDataType;
			CPyRef UnpackData(const CPyRef& obj) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_UnpackData_Offset), maxon::reflection::Argument::ByReference(obj)};
				(*handler_)(_fn_CPythonLibraryInterface_UnpackData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_UnpackData));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_UnpackData;
			CPyConstRef CPy_None() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_None_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_None, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_None));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_None;
			CPyConstRef CPy_True() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_True_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_True, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_True));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_True;
			CPyConstRef CPy_False() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_False_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_False, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_False));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_False;
			CPyConstRef CPy_NotImplemented() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_NotImplemented_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_NotImplemented, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_NotImplemented));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_NotImplemented;
			void CPyErr_Print() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_Print_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_Print, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_Print));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_Print;
			void CPyErr_Clear() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_Clear_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_Clear, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_Clear));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_Clear;
			Bool CPyErr_Occurred(CPyRef* type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_Occurred_Offset), maxon::reflection::Argument::ByValue(type)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_Occurred, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, CPyRef*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_Occurred));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_Occurred;
			CPyRef CPyErr_SetString(const CPyRef& errorType, const Char* errorString) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_SetString_Offset), maxon::reflection::Argument::ByReference(errorType), maxon::reflection::Argument::ByValue(errorString)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_SetString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_SetString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_SetString;
			CPyRef CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename_Offset), maxon::reflection::Argument::ByReference(errorType), maxon::reflection::Argument::ByValue(errorNumber), maxon::reflection::Argument::ByValue(filename)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, Int32, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename;
			CPyRef CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_SetWithErrno_Offset), maxon::reflection::Argument::ByReference(errorType), maxon::reflection::Argument::ByValue(errorNumber)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_SetWithErrno, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, Int32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_SetWithErrno));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_SetWithErrno;
			CPyRef CPyErr_SetString(const CPyRef& errorType, const String& errorString) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_SetString_1_Offset), maxon::reflection::Argument::ByReference(errorType), maxon::reflection::Argument::ByReference(errorString)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_SetString_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const String&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_SetString_1));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_SetString_1;
			void CPyErr_SetNone(const CPyRef& errorType) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_SetNone_Offset), maxon::reflection::Argument::ByReference(errorType)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_SetNone, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_SetNone));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_SetNone;
			void CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_Fetch_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByReference(value), maxon::reflection::Argument::ByReference(traceback)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_Fetch, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, CPyRef&, CPyRef&, CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_Fetch));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_Fetch;
			void CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_NormalizeException_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByReference(value), maxon::reflection::Argument::ByReference(traceback)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_NormalizeException, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, CPyRef&, CPyRef&, CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_NormalizeException));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_NormalizeException;
			void CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_Restore_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByReference(value), maxon::reflection::Argument::ByReference(traceback)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_Restore, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const CPyRef&, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_Restore));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_Restore;
			Bool CPyErr_ExceptionMatches(const CPyRef& exc) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyErr_ExceptionMatches_Offset), maxon::reflection::Argument::ByReference(exc)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyErr_ExceptionMatches, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyErr_ExceptionMatches));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyErr_ExceptionMatches;
			Bool CPyExceptionClass_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExceptionClass_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExceptionClass_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExceptionClass_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExceptionClass_Check;
			CPyRef CPyCapsule_New(void* pointer, const Char* name, CPyCapsule_Destructor* destructor) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_New_Offset), maxon::reflection::Argument::ByValue(pointer), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByValue(destructor)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, void*, const Char*, CPyCapsule_Destructor*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_New;
			Bool CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_SetPointer_Offset), maxon::reflection::Argument::ByReference(capsule), maxon::reflection::Argument::ByValue(pointer)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_SetPointer, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, void*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_SetPointer));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_SetPointer;
			void* CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				void* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_GetPointer_Offset), maxon::reflection::Argument::ByReference(capsule), maxon::reflection::Argument::ByValue(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_GetPointer, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<void*, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_GetPointer));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_GetPointer;
			void* CPyCapsule_GetContext(const CPyRef& capsule) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				void* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_GetContext_Offset), maxon::reflection::Argument::ByReference(capsule)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_GetContext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<void*, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_GetContext));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_GetContext;
			Bool CPyCapsule_SetContext(const CPyRef& capsule, void* context) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_SetContext_Offset), maxon::reflection::Argument::ByReference(capsule), maxon::reflection::Argument::ByValue(context)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_SetContext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, void*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_SetContext));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_SetContext;
			Bool CPyCapsule_CheckExact(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_CheckExact_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_CheckExact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_CheckExact));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_CheckExact;
			Bool CPyTraceBack_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTraceBack_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTraceBack_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTraceBack_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTraceBack_Check;
			Bool CPyClass_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyClass_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyClass_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyClass_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyClass_Check;
			CPyRef CPyTuple_New(UInt size) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_New_Offset), maxon::reflection::Argument::ByValue(size)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_New;
			UInt CPyTuple_Size(const CPyRef& tuple) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				UInt proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_Size_Offset), maxon::reflection::Argument::ByReference(tuple)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_Size, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UInt, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_Size));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_Size;
			CPyRef CPyTuple_GetItem(const CPyRef& tuple, UInt index) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_GetItem_Offset), maxon::reflection::Argument::ByReference(tuple), maxon::reflection::Argument::ByValue(index)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_GetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_GetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_GetItem;
			Bool CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_SetItem_Offset), maxon::reflection::Argument::ByReference(tuple), maxon::reflection::Argument::ByValue(index), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_SetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, UInt, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_SetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_SetItem;
			CPyRef CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_GetSlice_Offset), maxon::reflection::Argument::ByReference(tuple), maxon::reflection::Argument::ByValue(from), maxon::reflection::Argument::ByValue(to)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_GetSlice, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, UInt, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_GetSlice));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_GetSlice;
			Bool CPyTuple_CheckExact(const CPyRef& tuple) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_CheckExact_Offset), maxon::reflection::Argument::ByReference(tuple)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_CheckExact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_CheckExact));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_CheckExact;
			Bool CPyObject_HasAttrString(const CPyRef& o, const Char* attrName) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_HasAttrString_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByValue(attrName)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_HasAttrString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_HasAttrString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_HasAttrString;
			Bool CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_SetAttrString_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_SetAttrString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const Char*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_SetAttrString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_SetAttrString;
			CPyRef CPyObject_GetAttrString(const CPyRef& o, const Char* name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_GetAttrString_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByValue(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_GetAttrString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_GetAttrString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_GetAttrString;
			CPyRef CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Call_Offset), maxon::reflection::Argument::ByReference(callable_object), maxon::reflection::Argument::ByReference(tupleArg), maxon::reflection::Argument::ByReference(kw)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Call, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Call));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Call;
			CPyRef CPyObject_Str(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Str_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Str, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Str));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Str;
			CPyRef CPyObject_Repr(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Repr_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Repr, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Repr));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Repr;
			CPyRef CPyObject_Dir(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Dir_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Dir, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Dir));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Dir;
			CPyRef CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_RichCompare_Offset), maxon::reflection::Argument::ByReference(o1), maxon::reflection::Argument::ByReference(o2), maxon::reflection::Argument::ByValue(opid)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_RichCompare, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const CPyRef&, Int32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_RichCompare));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_RichCompare;
			Int64 CPyObject_Hash(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int64 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Hash_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Hash, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int64, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Hash));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Hash;
			Bool CPyObject_IsTrue(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_IsTrue_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_IsTrue, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_IsTrue));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_IsTrue;
			Bool CPyObject_Not(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Not_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Not, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Not));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Not;
			Bool CPyCallable_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCallable_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCallable_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCallable_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCallable_Check;
			Int CPyObject_Length(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Length_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Length, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Length));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Length;
			CPyRef CPyObject_GetItem(const CPyRef& o, const CPyRef& key) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_GetItem_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByReference(key)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_GetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_GetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_GetItem;
			CPyRef CPyObject_GetItemInt(const CPyRef& o, Int index) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_GetItemInt_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByValue(index)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_GetItemInt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, Int>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_GetItemInt));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_GetItemInt;
			CPyRef CPyObject_GetItemString(const CPyRef& o, const Char* index) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_GetItemString_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByValue(index)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_GetItemString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_GetItemString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_GetItemString;
			Bool CPyObject_DelItem(const CPyRef& o, const CPyRef& key) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_DelItem_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByReference(key)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_DelItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_DelItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_DelItem;
			Bool CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_SetItem_Offset), maxon::reflection::Argument::ByReference(o), maxon::reflection::Argument::ByReference(key), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_SetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_SetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_SetItem;
			Bool CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_TypeCheck_Offset), maxon::reflection::Argument::ByReference(object), maxon::reflection::Argument::ByReference(type)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_TypeCheck, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_TypeCheck));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_TypeCheck;
			CPyRef CPyObject_CallFunction(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_CallFunction_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_CallFunction, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_CallFunction));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_CallFunction;
			CPyRef CPySys_GetObject(const Char* name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySys_GetObject_Offset), maxon::reflection::Argument::ByValue(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySys_GetObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySys_GetObject));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySys_GetObject;
			Bool CPySys_SetObject(const Char* name, const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySys_SetObject_Offset), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySys_SetObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const Char*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySys_SetObject));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySys_SetObject;
			Result<void> CPy_SetPath(const BaseArray<Url>& paths) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_SetPath_Offset), maxon::reflection::Argument::ByReference(paths)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_SetPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BaseArray<Url>&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_SetPath));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_SetPath;
			Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySys_SetPath_Offset), maxon::reflection::Argument::ByReference(paths), maxon::reflection::Argument::ByValue(add)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySys_SetPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BaseArray<Url>&, PATHHANDLE>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySys_SetPath));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySys_SetPath;
			Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySys_SetArgvEx_Offset), maxon::reflection::Argument::ByReference(args), maxon::reflection::Argument::ByValue(updatepath)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySys_SetArgvEx, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const BaseArray<String>&, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySys_SetArgvEx));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySys_SetArgvEx;
			BaseArray<Url> CPySys_GetPath() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				BaseArray<Url> proxy_result = maxon::PrivateIncompleteNullReturnValue<BaseArray<Url>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySys_GetPath_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySys_GetPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<BaseArray<Url>, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySys_GetPath));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySys_GetPath;
			Result<void> CPySite_AddSiteDir(const Url& siteDir) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySite_AddSiteDir_Offset), maxon::reflection::Argument::ByReference(siteDir)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySite_AddSiteDir, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySite_AddSiteDir));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySite_AddSiteDir;
			Bool CPyUnicode_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_Check;
			CPyRef CPyUnicode_FromString(const Char* str) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_FromString_Offset), maxon::reflection::Argument::ByValue(str)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_FromString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_FromString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_FromString;
			CPyRef CPyUnicode_FromStringAndSize(const Block<const Char>& block) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_FromStringAndSize_Offset), maxon::reflection::Argument::ByReference(block)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_FromStringAndSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const Block<const Char>&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_FromStringAndSize));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_FromStringAndSize;
			Result<String> CPyUnicode_AsString(const CPyRef& str) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<String> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_AsString_Offset), maxon::reflection::Argument::ByReference(str)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_AsString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<String>, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_AsString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_AsString;
			const Char* CPyUnicode_AsCString(const CPyRef& str) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const Char* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_AsCString_Offset), maxon::reflection::Argument::ByReference(str)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_AsCString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const Char*, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_AsCString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_AsCString;
			Int CPyUnicode_GetLength(const CPyRef& str) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_GetLength_Offset), maxon::reflection::Argument::ByReference(str)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_GetLength, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_GetLength));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_GetLength;
			CPyRef CPyObject_GetIter(const CPyRef& o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_GetIter_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_GetIter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_GetIter));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_GetIter;
			CPyRef CPyIter_Next(const CPyRef& it) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyIter_Next_Offset), maxon::reflection::Argument::ByReference(it)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyIter_Next, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyIter_Next));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyIter_Next;
			CPyRef CPyDict_New() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_New_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_New;
			CPyRef CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_GetItem_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByReference(key), maxon::reflection::Argument::ByValue(raiseKeyError)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_GetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const CPyRef&, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_GetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_GetItem;
			CPyRef CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_GetItemString_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByValue(key), maxon::reflection::Argument::ByValue(raiseKeyError)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_GetItemString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, const Char*, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_GetItemString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_GetItemString;
			Bool CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_SetItem_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByReference(key), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_SetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_SetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_SetItem;
			Bool CPyDict_DelItem(const CPyRef& dict, const CPyRef& key) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_DelItem_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByReference(key)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_DelItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_DelItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_DelItem;
			CONTAINS CPyDict_Contains(const CPyRef& dict, const CPyRef& key) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CONTAINS proxy_result = maxon::PrivateIncompleteNullReturnValue<CONTAINS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Contains_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByReference(key)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Contains, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CONTAINS, maxon::GenericComponent*, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Contains));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Contains;
			void CPyDict_Clear(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Clear_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Clear, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Clear));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Clear;
			Bool CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Next_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByReference(pos), maxon::reflection::Argument::ByReference(key), maxon::reflection::Argument::ByReference(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Next, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, Int&, CPyRef&, CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Next));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Next;
			CPyRef CPyDict_Keys(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Keys_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Keys, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Keys));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Keys;
			CPyRef CPyDict_Values(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Values_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Values, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Values));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Values;
			CPyRef CPyDict_Items(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Items_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Items, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Items));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Items;
			Int CPyDict_Size(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Size_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Size, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Size));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Size;
			CPyRef CPyDict_Copy(const CPyRef& dict) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Copy_Offset), maxon::reflection::Argument::ByReference(dict)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Copy, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Copy));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Copy;
			Bool CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_SetItemString_Offset), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByValue(key), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_SetItemString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyRef&, const Char*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_SetItemString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_SetItemString;
			Bool CPyDict_Check(const CPyRef& o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Check;
			CPyRef CPyList_New(UInt size) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_New_Offset), maxon::reflection::Argument::ByValue(size)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_New;
			Bool CPyList_CheckExact(const CPyRef& list) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_CheckExact_Offset), maxon::reflection::Argument::ByReference(list)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_CheckExact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_CheckExact));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_CheckExact;
			Int CPyList_Size(const CPyRef& list) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Size_Offset), maxon::reflection::Argument::ByReference(list)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Size, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Size));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Size;
			CPyRef CPyList_GetItem(const CPyRef& list, UInt index) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_GetItem_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByValue(index)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_GetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_GetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_GetItem;
			Bool CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_SetItem_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByValue(anonymous_param_2), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_SetItem, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, UInt, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_SetItem));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_SetItem;
			Bool CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Insert_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByValue(anonymous_param_2), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Insert, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, UInt, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Insert));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Insert;
			Bool CPyList_Append(const CPyRef& list, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Append_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Append, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Append));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Append;
			CPyRef CPyList_GetSlice(const CPyRef& list, UInt from, UInt to) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_GetSlice_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByValue(from), maxon::reflection::Argument::ByValue(to)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_GetSlice, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&, UInt, UInt>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_GetSlice));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_GetSlice;
			Bool CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_SetSlice_Offset), maxon::reflection::Argument::ByReference(list), maxon::reflection::Argument::ByValue(from), maxon::reflection::Argument::ByValue(to), maxon::reflection::Argument::ByReference(item)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_SetSlice, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, UInt, UInt, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_SetSlice));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_SetSlice;
			Bool CPyList_Sort(const CPyRef& list) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Sort_Offset), maxon::reflection::Argument::ByReference(list)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Sort, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Sort));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Sort;
			Bool CPyList_Reverse(const CPyRef& list) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Reverse_Offset), maxon::reflection::Argument::ByReference(list)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Reverse, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Reverse));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Reverse;
			CPyRef CPyList_AsTuple(const CPyRef& list) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_AsTuple_Offset), maxon::reflection::Argument::ByReference(list)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_AsTuple, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_AsTuple));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_AsTuple;
			Bool CPyDict_DelItemString(const CPyRef& p, const Char* key) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_DelItemString_Offset), maxon::reflection::Argument::ByReference(p), maxon::reflection::Argument::ByValue(key)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_DelItemString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_DelItemString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_DelItemString;
			Bool CPyModule_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_Check;
			Bool CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_AddObject_Offset), maxon::reflection::Argument::ByReference(module), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByReference(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_AddObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const Char*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_AddObject));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_AddObject;
			CPyRef CPyModule_GetDict(const CPyRef& module) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_GetDict_Offset), maxon::reflection::Argument::ByReference(module)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_GetDict, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_GetDict));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_GetDict;
			Bool CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_AddIntConstant_Offset), maxon::reflection::Argument::ByReference(mod), maxon::reflection::Argument::ByValue(name), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_AddIntConstant, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&, const Char*, long>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_AddIntConstant));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_AddIntConstant;
			CPyRef CPyImport_ImportModule(const Char* name) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyImport_ImportModule_Offset), maxon::reflection::Argument::ByValue(name)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyImport_ImportModule, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const Char*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyImport_ImportModule));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyImport_ImportModule;
			CPyRef CPyImport_GetImporter(const CPyRef& path) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyImport_GetImporter_Offset), maxon::reflection::Argument::ByReference(path)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyImport_GetImporter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyImport_GetImporter));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyImport_GetImporter;
			CPyRef CPyImport_GetModuleDict() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyImport_GetModuleDict_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyImport_GetModuleDict, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyImport_GetModuleDict));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyImport_GetModuleDict;
			Bool CPyType_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_Check;
			Bool CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_IsSubtype_Offset), maxon::reflection::Argument::ByReference(a), maxon::reflection::Argument::ByReference(b)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_IsSubtype, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyTypeRef&, const CPyTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_IsSubtype));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_IsSubtype;
			Bool CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_HasFeature_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByValue(f)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_HasFeature, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyTypeRef&, Int64>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_HasFeature));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_HasFeature;
			Bool CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_FastSubclass_Offset), maxon::reflection::Argument::ByReference(type), maxon::reflection::Argument::ByValue(f)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_FastSubclass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyTypeRef&, Int64>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_FastSubclass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_FastSubclass;
			Result<String> CPyType_GetName(const CPyTypeRef& type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<String> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_GetName_Offset), maxon::reflection::Argument::ByReference(type)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<String>, maxon::GenericComponent*, const CPyTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_GetName));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_GetName;
			Bool CPyType_Ready(CPyTypeRef& type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_Ready_Offset), maxon::reflection::Argument::ByReference(type)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_Ready, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, CPyTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_Ready));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_Ready;
			NativePyThreadState* CPyEval_SaveThread() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				NativePyThreadState* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_SaveThread_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_SaveThread, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NativePyThreadState*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_SaveThread));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_SaveThread;
			void CPyEval_RestoreThread(NativePyThreadState* state) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_RestoreThread_Offset), maxon::reflection::Argument::ByValue(state)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_RestoreThread, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, NativePyThreadState*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_RestoreThread));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_RestoreThread;
			Bool CPyEval_ThreadsInitialized() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_ThreadsInitialized_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_ThreadsInitialized, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_ThreadsInitialized));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_ThreadsInitialized;
			void CPyEval_InitThreads() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_InitThreads_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_InitThreads, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_InitThreads));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_InitThreads;
			void CPyEval_AcquireThread(NativePyThreadState* state) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_AcquireThread_Offset), maxon::reflection::Argument::ByValue(state)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_AcquireThread, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, NativePyThreadState*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_AcquireThread));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_AcquireThread;
			void CPyEval_ReleaseThread(NativePyThreadState* state) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_ReleaseThread_Offset), maxon::reflection::Argument::ByValue(state)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_ReleaseThread, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, NativePyThreadState*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_ReleaseThread));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_ReleaseThread;
			void CPyEval_ReInitThreads() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_ReInitThreads_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_ReInitThreads, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_ReInitThreads));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_ReInitThreads;
			CPyRef CPyEval_GetBuiltins() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_GetBuiltins_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_GetBuiltins, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_GetBuiltins));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_GetBuiltins;
			CPyRef CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyEval_EvalCode_Offset), maxon::reflection::Argument::ByReference(code), maxon::reflection::Argument::ByReference(globals), maxon::reflection::Argument::ByReference(locals)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyEval_EvalCode, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*, const CPyCodeRef&, const CPyRef&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyEval_EvalCode));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyEval_EvalCode;
			Bool CPyFloat_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyFloat_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyFloat_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyFloat_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyFloat_Check;
			CPyRef CPyFloat_FromFloat32(Float32 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyFloat_FromFloat32_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyFloat_FromFloat32, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Float32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyFloat_FromFloat32));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyFloat_FromFloat32;
			CPyRef CPyFloat_FromFloat64(Float64 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyFloat_FromFloat64_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyFloat_FromFloat64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Float64>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyFloat_FromFloat64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyFloat_FromFloat64;
			Float64 CPyFloat_AsFloat64(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Float64 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyFloat_AsFloat64_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyFloat_AsFloat64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Float64, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyFloat_AsFloat64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyFloat_AsFloat64;
			Bool CPyLong_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_Check;
			CPyRef CPyBool_FromBool(Bool value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyBool_FromBool_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyBool_FromBool, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyBool_FromBool));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyBool_FromBool;
			CPyRef CPyLong_FromInt16(Int16 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromInt16_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromInt16, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Int16>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromInt16));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromInt16;
			CPyRef CPyLong_FromUInt16(UInt16 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromUInt16_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromUInt16, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, UInt16>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromUInt16));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromUInt16;
			CPyRef CPyLong_FromInt32(Int32 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromInt32_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromInt32, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Int32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromInt32));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromInt32;
			CPyRef CPyLong_FromUInt32(UInt32 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromUInt32_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromUInt32, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, UInt32>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromUInt32));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromUInt32;
			CPyRef CPyLong_FromInt64(Int64 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromInt64_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromInt64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, Int64>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromInt64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromInt64;
			CPyRef CPyLong_FromUInt64(UInt64 value) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_FromUInt64_Offset), maxon::reflection::Argument::ByValue(value)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_FromUInt64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, UInt64>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_FromUInt64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_FromUInt64;
			Int16 CPyLong_AsInt16(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int16 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsInt16_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsInt16, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int16, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsInt16));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsInt16;
			UInt16 CPyLong_AsUInt16(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				UInt16 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsUInt16_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsUInt16, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UInt16, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsUInt16));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsUInt16;
			Int32 CPyLong_AsInt32(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsInt32_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsInt32, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsInt32));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsInt32;
			UInt32 CPyLong_AsUInt32(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				UInt32 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsUInt32_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsUInt32, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UInt32, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsUInt32));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsUInt32;
			Int64 CPyLong_AsInt64(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int64 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsInt64_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsInt64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int64, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsInt64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsInt64;
			UInt64 CPyLong_AsUInt64(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				UInt64 proxy_result = 0;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_AsUInt64_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_AsUInt64, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UInt64, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_AsUInt64));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_AsUInt64;
			Bool CPyNumber_Check(const CPyRef& o) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyNumber_Check_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyNumber_Check, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyNumber_Check));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyNumber_Check;
			MPyFunctionRef MPyFunction_New(const reflection::Function* func) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyFunctionRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyFunctionRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyFunction_New_Offset), maxon::reflection::Argument::ByValue(func)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyFunction_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyFunctionRef, maxon::GenericComponent*, const reflection::Function*>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyFunction_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyFunction_New;
			MPyMemberRef MPyMember_New(const reflection::Member* member) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyMemberRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyMemberRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyMember_New_Offset), maxon::reflection::Argument::ByValue(member)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyMember_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyMemberRef, maxon::GenericComponent*, const reflection::Member*>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyMember_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyMember_New;
			Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyMem_SetAllocator_Offset), maxon::reflection::Argument::ByValue(domain), maxon::reflection::Argument::ByValue(allocator)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyMem_SetAllocator, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, CPyMemAllocatorDomain, CPyMemAllocatorEx*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyMem_SetAllocator));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyMem_SetAllocator;
			MPyClassRef MPyClass_New(const reflection::Class* cls) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyClassRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyClassRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyClass_New_Offset), maxon::reflection::Argument::ByValue(cls)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyClass_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyClassRef, maxon::GenericComponent*, const reflection::Class*>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyClass_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyClass_New;
			Int32* CPy_DebugFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_DebugFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_DebugFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_DebugFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_DebugFlag;
			Int32* CPy_VerboseFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_VerboseFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_VerboseFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_VerboseFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_VerboseFlag;
			Int32* CPy_InteractiveFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_InteractiveFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_InteractiveFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_InteractiveFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_InteractiveFlag;
			Int32* CPy_InspectFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_InspectFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_InspectFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_InspectFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_InspectFlag;
			Int32* CPy_OptimizeFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_OptimizeFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_OptimizeFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_OptimizeFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_OptimizeFlag;
			Int32* CPy_NoSiteFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_NoSiteFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_NoSiteFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_NoSiteFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_NoSiteFlag;
			Int32* CPy_BytesWarningFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_BytesWarningFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_BytesWarningFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_BytesWarningFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_BytesWarningFlag;
			Int32* CPy_FrozenFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_FrozenFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_FrozenFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_FrozenFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_FrozenFlag;
			Int32* CPy_IgnoreEnvironmentFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag;
			Int32* CPy_DontWriteBytecodeFlag() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_DontWriteBytecodeFlag_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_DontWriteBytecodeFlag, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_DontWriteBytecodeFlag));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_DontWriteBytecodeFlag;
			Int32* CPy_NoUserSiteDirectory() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Int32* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPy_NoUserSiteDirectory_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPy_NoUserSiteDirectory, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int32*, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPy_NoUserSiteDirectory));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPy_NoUserSiteDirectory;
			CPyConstRef CPyExc_BaseException() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_BaseException_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_BaseException, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_BaseException));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_BaseException;
			CPyConstRef CPyExc_Exception() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_Exception_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_Exception, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_Exception));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_Exception;
			CPyConstRef CPyExc_StopIteration() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_StopIteration_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_StopIteration, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_StopIteration));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_StopIteration;
			CPyConstRef CPyExc_GeneratorExit() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_GeneratorExit_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_GeneratorExit, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_GeneratorExit));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_GeneratorExit;
			CPyConstRef CPyExc_StandardError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_StandardError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_StandardError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_StandardError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_StandardError;
			CPyConstRef CPyExc_ArithmeticError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ArithmeticError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ArithmeticError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ArithmeticError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ArithmeticError;
			CPyConstRef CPyExc_LookupError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_LookupError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_LookupError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_LookupError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_LookupError;
			CPyConstRef CPyExc_AssertionError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_AssertionError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_AssertionError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_AssertionError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_AssertionError;
			CPyConstRef CPyExc_AttributeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_AttributeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_AttributeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_AttributeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_AttributeError;
			CPyConstRef CPyExc_EOFError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_EOFError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_EOFError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_EOFError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_EOFError;
			CPyConstRef CPyExc_FloatingPointError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_FloatingPointError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_FloatingPointError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_FloatingPointError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_FloatingPointError;
			CPyConstRef CPyExc_EnvironmentError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_EnvironmentError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_EnvironmentError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_EnvironmentError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_EnvironmentError;
			CPyConstRef CPyExc_IOError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_IOError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_IOError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_IOError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_IOError;
			CPyConstRef CPyExc_OSError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_OSError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_OSError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_OSError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_OSError;
			CPyConstRef CPyExc_ImportError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ImportError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ImportError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ImportError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ImportError;
			CPyConstRef CPyExc_IndexError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_IndexError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_IndexError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_IndexError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_IndexError;
			CPyConstRef CPyExc_KeyError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_KeyError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_KeyError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_KeyError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_KeyError;
			CPyConstRef CPyExc_KeyboardInterrupt() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_KeyboardInterrupt_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_KeyboardInterrupt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_KeyboardInterrupt));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_KeyboardInterrupt;
			CPyConstRef CPyExc_MemoryError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_MemoryError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_MemoryError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_MemoryError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_MemoryError;
			CPyConstRef CPyExc_NameError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_NameError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_NameError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_NameError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_NameError;
			CPyConstRef CPyExc_OverflowError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_OverflowError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_OverflowError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_OverflowError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_OverflowError;
			CPyConstRef CPyExc_RuntimeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_RuntimeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_RuntimeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_RuntimeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_RuntimeError;
			CPyConstRef CPyExc_NotImplementedError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_NotImplementedError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_NotImplementedError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_NotImplementedError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_NotImplementedError;
			CPyConstRef CPyExc_SyntaxError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_SyntaxError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_SyntaxError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_SyntaxError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_SyntaxError;
			CPyConstRef CPyExc_IndentationError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_IndentationError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_IndentationError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_IndentationError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_IndentationError;
			CPyConstRef CPyExc_TabError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_TabError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_TabError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_TabError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_TabError;
			CPyConstRef CPyExc_ReferenceError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ReferenceError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ReferenceError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ReferenceError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ReferenceError;
			CPyConstRef CPyExc_SystemError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_SystemError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_SystemError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_SystemError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_SystemError;
			CPyConstRef CPyExc_SystemExit() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_SystemExit_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_SystemExit, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_SystemExit));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_SystemExit;
			CPyConstRef CPyExc_TypeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_TypeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_TypeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_TypeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_TypeError;
			CPyConstRef CPyExc_UnboundLocalError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnboundLocalError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnboundLocalError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnboundLocalError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnboundLocalError;
			CPyConstRef CPyExc_UnicodeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnicodeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnicodeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnicodeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnicodeError;
			CPyConstRef CPyExc_UnicodeEncodeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnicodeEncodeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnicodeEncodeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnicodeEncodeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnicodeEncodeError;
			CPyConstRef CPyExc_UnicodeDecodeError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnicodeDecodeError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnicodeDecodeError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnicodeDecodeError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnicodeDecodeError;
			CPyConstRef CPyExc_UnicodeTranslateError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnicodeTranslateError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnicodeTranslateError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnicodeTranslateError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnicodeTranslateError;
			CPyConstRef CPyExc_ValueError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ValueError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ValueError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ValueError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ValueError;
			CPyConstRef CPyExc_ZeroDivisionError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ZeroDivisionError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ZeroDivisionError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ZeroDivisionError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ZeroDivisionError;
			CPyConstRef CPyExc_WindowsError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_WindowsError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_WindowsError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_WindowsError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_WindowsError;
			CPyConstRef CPyExc_BufferError() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_BufferError_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_BufferError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_BufferError));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_BufferError;
			CPyConstRef CPyExc_MemoryErrorInst() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_MemoryErrorInst_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_MemoryErrorInst, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_MemoryErrorInst));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_MemoryErrorInst;
			CPyConstRef CPyExc_RecursionErrorInst() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_RecursionErrorInst_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_RecursionErrorInst, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_RecursionErrorInst));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_RecursionErrorInst;
			CPyConstRef CPyExc_Warning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_Warning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_Warning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_Warning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_Warning;
			CPyConstRef CPyExc_UserWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UserWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UserWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UserWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UserWarning;
			CPyConstRef CPyExc_DeprecationWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_DeprecationWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_DeprecationWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_DeprecationWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_DeprecationWarning;
			CPyConstRef CPyExc_PendingDeprecationWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_PendingDeprecationWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_PendingDeprecationWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_PendingDeprecationWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_PendingDeprecationWarning;
			CPyConstRef CPyExc_SyntaxWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_SyntaxWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_SyntaxWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_SyntaxWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_SyntaxWarning;
			CPyConstRef CPyExc_RuntimeWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_RuntimeWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_RuntimeWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_RuntimeWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_RuntimeWarning;
			CPyConstRef CPyExc_FutureWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_FutureWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_FutureWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_FutureWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_FutureWarning;
			CPyConstRef CPyExc_ImportWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_ImportWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_ImportWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_ImportWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_ImportWarning;
			CPyConstRef CPyExc_UnicodeWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_UnicodeWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_UnicodeWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_UnicodeWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_UnicodeWarning;
			CPyConstRef CPyExc_BytesWarning() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyExc_BytesWarning_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyExc_BytesWarning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyExc_BytesWarning));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyExc_BytesWarning;
			CPyTypeConstRef CPyNullImporter_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyNullImporter_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyNullImporter_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyNullImporter_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyNullImporter_Type;
			CPyTypeConstRef CPySuper_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySuper_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySuper_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySuper_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySuper_Type;
			CPyTypeConstRef CPyBool_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyBool_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyBool_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyBool_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyBool_Type;
			CPyTypeConstRef CPyObject_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_Type;
			CPyTypeConstRef CPyModule_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyModule_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyModule_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyModule_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyModule_Type;
			CPyTypeConstRef CPyUnicode_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyUnicode_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyUnicode_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyUnicode_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyUnicode_Type;
			CPyTypeConstRef CPyLong_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyLong_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyLong_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyLong_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyLong_Type;
			CPyTypeConstRef CPyFloat_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyFloat_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyFloat_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyFloat_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyFloat_Type;
			CPyTypeConstRef CPyTuple_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTuple_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTuple_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTuple_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTuple_Type;
			CPyTypeConstRef CPyList_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyList_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyList_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyList_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyList_Type;
			CPyTypeConstRef CPyDict_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyDict_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyDict_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyDict_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyDict_Type;
			CPyTypeConstRef CPyClass_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyClass_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyClass_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyClass_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyClass_Type;
			CPyTypeConstRef CPyTraceBack_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyTraceBack_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyTraceBack_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyTraceBack_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyTraceBack_Type;
			CPyTypeConstRef CPySlice_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPySlice_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPySlice_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPySlice_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPySlice_Type;
			CPyTypeConstRef CPyType_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyType_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyType_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyType_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyType_Type;
			CPyTypeConstRef CPyMemoryView_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyMemoryView_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyMemoryView_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyMemoryView_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyMemoryView_Type;
			const PyChar* ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const PyChar* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_ConvertAndCacheString_Offset), maxon::reflection::Argument::ByReference(str), maxon::reflection::Argument::ByValue(encoding), maxon::reflection::Argument::ByValue(size)};
				(*handler_)(_fn_CPythonLibraryInterface_ConvertAndCacheString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const PyChar*, maxon::GenericComponent*, const String&, PyStringEncodings, UInt*>::Invoke, (const void*) mt_._CPythonLibraryInterface_ConvertAndCacheString));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_ConvertAndCacheString;
			Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_RegisterSpecificPythonClass_Offset), maxon::reflection::Argument::ByReference(typeId), maxon::reflection::Argument::ByReference(type)};
				(*handler_)(_fn_CPythonLibraryInterface_RegisterSpecificPythonClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Id&, const CPyTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_RegisterSpecificPythonClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_RegisterSpecificPythonClass;
			Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_PrivateRegisterBuiltinConverter_Offset), maxon::reflection::Argument::ByReference(dt), maxon::reflection::Argument::ByReference(f1), maxon::reflection::Argument::ByReference(f2)};
				(*handler_)(_fn_CPythonLibraryInterface_PrivateRegisterBuiltinConverter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const DataType&, const DelegatePyObject_AsData&, const DelegatePyObject_FromData<>&>::Invoke, (const void*) mt_._CPythonLibraryInterface_PrivateRegisterBuiltinConverter));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_PrivateRegisterBuiltinConverter;
			Url GetSpecialPath(SPECIALPATH anonymous_param_1) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetSpecialPath_Offset), maxon::reflection::Argument::ByValue(anonymous_param_1)};
				(*handler_)(_fn_CPythonLibraryInterface_GetSpecialPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Url, maxon::GenericComponent*, SPECIALPATH>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetSpecialPath));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetSpecialPath;
			void RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_RegisterSpecialPath_Offset), maxon::reflection::Argument::ByValue(anonymous_param_1), maxon::reflection::Argument::ByReference(path)};
				(*handler_)(_fn_CPythonLibraryInterface_RegisterSpecialPath, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, SPECIALPATH, const Url&>::Invoke, (const void*) mt_._CPythonLibraryInterface_RegisterSpecialPath));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_RegisterSpecialPath;
			CPyTypeConstRef MPyDataCapsule_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyDataCapsule_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyDataCapsule_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyDataCapsule_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyDataCapsule_Type;
			CPyTypeConstRef CPyData_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyData_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyData_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyData_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyData_Type;
			CPyTypeConstRef CPyCapsule_Type() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyTypeConstRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyCapsule_Type_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyCapsule_Type, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyTypeConstRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyCapsule_Type));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyCapsule_Type;
			CPyRef PrivateGetCurrentCallerContext() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_PrivateGetCurrentCallerContext_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_PrivateGetCurrentCallerContext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_PrivateGetCurrentCallerContext));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_PrivateGetCurrentCallerContext;
			CPyRef MPyDataType_ToMapperInstance(const CPyRef& capsule) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyDataType_ToMapperInstance_Offset), maxon::reflection::Argument::ByReference(capsule)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyDataType_ToMapperInstance, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyDataType_ToMapperInstance));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyDataType_ToMapperInstance;
			CPyRef MPyData_ToMapperInstance(const MPyDataRef& capsule) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyData_ToMapperInstance_Offset), maxon::reflection::Argument::ByReference(capsule)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyData_ToMapperInstance, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const MPyDataRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyData_ToMapperInstance));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyData_ToMapperInstance;
			CPyRef CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_ToMapperInstance_Offset), maxon::reflection::Argument::ByReference(dt), maxon::reflection::Argument::ByReference(capsule)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_ToMapperInstance, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const DataType&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_ToMapperInstance));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_ToMapperInstance;
			Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_AssociateDataTypeWithPythonTypes_Offset), maxon::reflection::Argument::ByReference(dt), maxon::reflection::Argument::ByReference(type)};
				(*handler_)(_fn_CPythonLibraryInterface_AssociateDataTypeWithPythonTypes, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const DataType&, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_AssociateDataTypeWithPythonTypes));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_AssociateDataTypeWithPythonTypes;
			Result<CPyRef> GetAssociatedDataType(const DataType& dt) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<CPyRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetAssociatedDataType_Offset), maxon::reflection::Argument::ByReference(dt)};
				(*handler_)(_fn_CPythonLibraryInterface_GetAssociatedDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<CPyRef>, maxon::GenericComponent*, const DataType&>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetAssociatedDataType));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetAssociatedDataType;
			DelegatePyObject_FromData<>* GetConverterPyObject_FromData(const DataType& dt) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				DelegatePyObject_FromData<>* proxy_result = nullptr;
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetConverterPyObject_FromData_Offset), maxon::reflection::Argument::ByReference(dt)};
				(*handler_)(_fn_CPythonLibraryInterface_GetConverterPyObject_FromData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<DelegatePyObject_FromData<>*, maxon::GenericComponent*, const DataType&>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetConverterPyObject_FromData));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetConverterPyObject_FromData;
			MPyDataRef MPyData_New(Data& data) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyDataRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyDataRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyData_New_Offset), maxon::reflection::Argument::ByReference(data)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyData_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyDataRef, maxon::GenericComponent*, Data&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyData_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyData_New;
			MPyDataRef MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyDataRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyDataRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyData_New_1_Offset), maxon::reflection::Argument::ByReference(dt), maxon::reflection::Argument::ByValue(data), maxon::reflection::Argument::ByValue(owner), maxon::reflection::Argument::ByReference(mapDt)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyData_New_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyDataRef, maxon::GenericComponent*, const DataType&, Generic*, Bool, const DataType&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyData_New_1));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyData_New_1;
			MPyDataTypeRef MPyDataType_New(const DataType& dt) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				MPyDataTypeRef proxy_result = maxon::PrivateIncompleteNullReturnValue<MPyDataTypeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyDataType_New_Offset), maxon::reflection::Argument::ByReference(dt)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyDataType_New, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MPyDataTypeRef, maxon::GenericComponent*, const DataType&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyDataType_New));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyDataType_New;
			Bool MPyDataType_CheckExact(const CPyRef& o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyDataType_CheckExact_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyDataType_CheckExact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyDataType_CheckExact));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyDataType_CheckExact;
			const DataType& MPyDataType_GetDataType(const MPyDataTypeRef& o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyDataType_GetDataType_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyDataType_GetDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const DataType&, const maxon::GenericComponent*, const MPyDataTypeRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyDataType_GetDataType));
				return *proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyDataType_GetDataType;
			Bool MPyData_CheckExact(const CPyRef& o) const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Bool proxy_result = maxon::PrivateLogNullptrError(false);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MPyData_CheckExact_Offset), maxon::reflection::Argument::ByReference(o)};
				(*handler_)(_fn_CPythonLibraryInterface_MPyData_CheckExact, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MPyData_CheckExact));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MPyData_CheckExact;
			Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<Data*> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_AsData_Offset), maxon::reflection::Argument::ByValue(stackDepth), maxon::reflection::Argument::ByReference(obj), maxon::reflection::Argument::ByReference(expected), maxon::reflection::Argument::ByReference(k), maxon::reflection::Argument::ByValue(n)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_AsData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data*>, maxon::GenericComponent*, Int, const CPyRef&, const DataType&, BlockArray<Data>&, BaseArray<reflection::Argument>*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_AsData));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_AsData;
			Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<BaseArray<TYPE_CONVERSION_TUPLE>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetRegisteredTypesWithConversions_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetRegisteredTypesWithConversions, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<TYPE_CONVERSION_TUPLE>>, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetRegisteredTypesWithConversions));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetRegisteredTypesWithConversions;
			Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<DataType> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_ParseDataType_Offset), maxon::reflection::Argument::ByReference(args), maxon::reflection::Argument::ByValue(argIndex), maxon::reflection::Argument::ByValue(canBeNone)};
				(*handler_)(_fn_CPythonLibraryInterface_ParseDataType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataType>, maxon::GenericComponent*, const CPyRef&, Int32, Bool>::Invoke, (const void*) mt_._CPythonLibraryInterface_ParseDataType));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_ParseDataType;
			void SetError(const Error& err) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_SetError_Offset), maxon::reflection::Argument::ByReference(err)};
				(*handler_)(_fn_CPythonLibraryInterface_SetError, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const Error&>::Invoke, (const void*) mt_._CPythonLibraryInterface_SetError));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_SetError;
			void SetError(const ErrorPtr& err) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_SetError_1_Offset), maxon::reflection::Argument::ByReference(err)};
				(*handler_)(_fn_CPythonLibraryInterface_SetError_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const ErrorPtr&>::Invoke, (const void*) mt_._CPythonLibraryInterface_SetError_1));
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_SetError_1;
			CPyRef MaxonConvertAuto(const CPyRef& capsule) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_MaxonConvertAuto_Offset), maxon::reflection::Argument::ByReference(capsule)};
				(*handler_)(_fn_CPythonLibraryInterface_MaxonConvertAuto, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const CPyRef&>::Invoke, (const void*) mt_._CPythonLibraryInterface_MaxonConvertAuto));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_MaxonConvertAuto;
			CPyRef CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected, Int* count) 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CPyObject_FromGeneric_Offset), maxon::reflection::Argument::ByReference(origDt), maxon::reflection::Argument::ByValue(object), maxon::reflection::Argument::ByValue(ownership), maxon::reflection::Argument::ByValue(expected), maxon::reflection::Argument::ByValue(count)};
				(*handler_)(_fn_CPythonLibraryInterface_CPyObject_FromGeneric, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, maxon::GenericComponent*, const DataType&, const Generic*, OWNERSHIP, const CPyTypeRef*, Int*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CPyObject_FromGeneric));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CPyObject_FromGeneric;
			CPyRef CreateGlobalDictionary() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				CPyRef proxy_result = maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_CreateGlobalDictionary_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_CreateGlobalDictionary, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<CPyRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_CreateGlobalDictionary));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_CreateGlobalDictionary;
			Result<BaseArray<SourceLocation>> GetCurrentTraceback() 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Result<BaseArray<SourceLocation>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCurrentTraceback_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCurrentTraceback, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<SourceLocation>>, maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCurrentTraceback));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCurrentTraceback;
			Class<CPyRef> GetCPyRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<CPyRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<CPyRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCPyRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCPyRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<CPyRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCPyRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCPyRefClass;
			Class<CPyTypeRef> GetCPyTypeRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<CPyTypeRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<CPyTypeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCPyTypeRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCPyTypeRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<CPyTypeRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCPyTypeRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCPyTypeRefClass;
			Class<CPyFrameRef> GetCPyFrameRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<CPyFrameRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<CPyFrameRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCPyFrameRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCPyFrameRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<CPyFrameRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCPyFrameRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCPyFrameRefClass;
			Class<CPyTracebackRef> GetCPyTracebackRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<CPyTracebackRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<CPyTracebackRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCPyTracebackRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCPyTracebackRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<CPyTracebackRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCPyTracebackRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCPyTracebackRefClass;
			Class<CPyCodeRef> GetCPyCodeRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<CPyCodeRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<CPyCodeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetCPyCodeRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetCPyCodeRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<CPyCodeRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetCPyCodeRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetCPyCodeRefClass;
			Class<MPyClassRef> GetMPyClassRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyClassRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyClassRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyClassRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyClassRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyClassRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyClassRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyClassRefClass;
			Class<MPyMemberRef> GetMPyMemberRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyMemberRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyMemberRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyMemberRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyMemberRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyMemberRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyMemberRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyMemberRefClass;
			Class<MPyFunctionRef> GetMPyFunctionRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyFunctionRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyFunctionRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyFunctionRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyFunctionRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyFunctionRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyFunctionRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyFunctionRefClass;
			Class<MPyDataTypeRef> GetMPyDataTypeRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyDataTypeRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyDataTypeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyDataTypeRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyDataTypeRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyDataTypeRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyDataTypeRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyDataTypeRefClass;
			Class<MPyDataRef> GetMPyDataRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyDataRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyDataRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyDataRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyDataRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyDataRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyDataRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyDataRefClass;
			Class<MPyCallerContextRef> GetMPyCallerContextRefClass() const 
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
				const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CPythonLibraryInterface>();
				Class<MPyCallerContextRef> proxy_result = maxon::PrivateIncompleteNullReturnValue<Class<MPyCallerContextRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
				maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CPythonLibraryInterface_GetMPyCallerContextRefClass_Offset)};
				(*handler_)(_fn_CPythonLibraryInterface_GetMPyCallerContextRefClass, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Class<MPyCallerContextRef>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CPythonLibraryInterface_GetMPyCallerContextRefClass));
				return proxy_result;
			}
			static const maxon::reflection::Function* _fn_CPythonLibraryInterface_GetMPyCallerContextRefClass;
		};
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_Init;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_InitTypes;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_InitBuiltinModules;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_Initialize;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_Finalize;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_Create;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_Free;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetDll;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_FopenNative;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_LastPythonCallFailed;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_RegisterComponentProxy;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_IsInitialized;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetVersion;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetPlatform;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetCopyright;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetCompiler;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetBuildInfo;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_SetProgramName;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_SetPythonHome;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetProgramName;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_GetPythonHome;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_ExecuteModule;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCallerContext_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyRun_SimpleStringFlags;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyRun_FileExFlags;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyRun_InteractiveLoopFlags;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyGilState_Ensure;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyGilState_Release;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetGilState;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyGILState_GetThisThreadState;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyThreadState_Swap;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyThreadState_GetDict;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_CompileStringFlags;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_Incref;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_Decref;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_SafeIncref;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_SafeDecref;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyGC_Collect;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCode_Addr2Line;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_UnpackDataType;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_UnpackData;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_None;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_True;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_False;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_NotImplemented;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_Print;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_Clear;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_Occurred;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_SetString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_SetWithErrno;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_SetString_1;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_SetNone;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_Fetch;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_NormalizeException;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_Restore;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyErr_ExceptionMatches;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExceptionClass_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_SetPointer;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_GetPointer;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_GetContext;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_SetContext;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_CheckExact;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTraceBack_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyClass_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_Size;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_GetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_SetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_GetSlice;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_CheckExact;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_HasAttrString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_SetAttrString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_GetAttrString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Call;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Str;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Repr;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Dir;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_RichCompare;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Hash;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_IsTrue;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Not;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCallable_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Length;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_GetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_GetItemInt;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_GetItemString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_DelItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_SetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_TypeCheck;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_CallFunction;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySys_GetObject;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySys_SetObject;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_SetPath;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySys_SetPath;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySys_SetArgvEx;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySys_GetPath;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySite_AddSiteDir;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_FromString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_FromStringAndSize;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_AsString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_AsCString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_GetLength;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_GetIter;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyIter_Next;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_GetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_GetItemString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_SetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_DelItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Contains;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Clear;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Next;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Keys;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Values;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Items;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Size;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Copy;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_SetItemString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_CheckExact;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Size;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_GetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_SetItem;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Insert;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Append;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_GetSlice;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_SetSlice;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Sort;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Reverse;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_AsTuple;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_DelItemString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_AddObject;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_GetDict;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_AddIntConstant;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyImport_ImportModule;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyImport_GetImporter;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyImport_GetModuleDict;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_IsSubtype;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_HasFeature;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_FastSubclass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_GetName;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_Ready;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_SaveThread;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_RestoreThread;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_ThreadsInitialized;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_InitThreads;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_AcquireThread;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_ReleaseThread;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_ReInitThreads;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_GetBuiltins;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyEval_EvalCode;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyFloat_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyFloat_FromFloat32;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyFloat_FromFloat64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyFloat_AsFloat64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyBool_FromBool;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromInt16;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromUInt16;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromInt32;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromUInt32;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromInt64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_FromUInt64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsInt16;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsUInt16;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsInt32;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsUInt32;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsInt64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_AsUInt64;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyNumber_Check;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyFunction_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyMember_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyMem_SetAllocator;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyClass_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_DebugFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_VerboseFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_InteractiveFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_InspectFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_OptimizeFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_NoSiteFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_BytesWarningFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_FrozenFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_DontWriteBytecodeFlag;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPy_NoUserSiteDirectory;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_BaseException;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_Exception;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_StopIteration;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_GeneratorExit;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_StandardError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ArithmeticError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_LookupError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_AssertionError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_AttributeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_EOFError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_FloatingPointError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_EnvironmentError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_IOError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_OSError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ImportError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_IndexError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_KeyError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_KeyboardInterrupt;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_MemoryError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_NameError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_OverflowError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_RuntimeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_NotImplementedError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_SyntaxError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_IndentationError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_TabError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ReferenceError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_SystemError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_SystemExit;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_TypeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnboundLocalError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnicodeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnicodeEncodeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnicodeDecodeError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnicodeTranslateError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ValueError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ZeroDivisionError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_WindowsError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_BufferError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_MemoryErrorInst;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_RecursionErrorInst;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_Warning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UserWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_DeprecationWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_PendingDeprecationWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_SyntaxWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_RuntimeWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_FutureWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_ImportWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_UnicodeWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyExc_BytesWarning;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyNullImporter_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySuper_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyBool_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyModule_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyUnicode_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyLong_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyFloat_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTuple_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyList_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyDict_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyClass_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyTraceBack_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPySlice_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyType_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyMemoryView_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_ConvertAndCacheString;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_RegisterSpecificPythonClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_PrivateRegisterBuiltinConverter;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetSpecialPath;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_RegisterSpecialPath;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyDataCapsule_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyData_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyCapsule_Type;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_PrivateGetCurrentCallerContext;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyDataType_ToMapperInstance;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyData_ToMapperInstance;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_ToMapperInstance;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_AssociateDataTypeWithPythonTypes;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetAssociatedDataType;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetConverterPyObject_FromData;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyData_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyData_New_1;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyDataType_New;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyDataType_CheckExact;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyDataType_GetDataType;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MPyData_CheckExact;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_AsData;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetRegisteredTypesWithConversions;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_ParseDataType;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_SetError;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_SetError_1;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_MaxonConvertAuto;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CPyObject_FromGeneric;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_CreateGlobalDictionary;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCurrentTraceback;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCPyRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCPyTypeRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCPyFrameRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCPyTracebackRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetCPyCodeRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyClassRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyMemberRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyFunctionRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyDataTypeRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyDataRefClass;
		const maxon::reflection::Function* CPythonLibraryInterface::ProxyComponent::_fn_CPythonLibraryInterface_GetMPyCallerContextRefClass;
		PRIVATE_MAXON_COMPONENT_REGISTER(CPythonLibraryInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_CPythonLibraryInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
				maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CPythonLibraryInterface::Hxx2::StaticMTable::_instance._CPythonLibraryInterface_ParseCommandLine)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "args\0res\0flags\0", 0LL, nullptr),
				maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CPythonLibraryInterface::Hxx2::StaticMTable::_instance._CPythonLibraryInterface_GetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pythonPath\0pythonLibrary\0pythonHome\0", 0LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPythonLibraryInterface::_staticInterface), maxon::ToBlock(functions));
		}
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
		static maxon::Result<void> RegisterReflection_CPythonLibraryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "librarypath\0createSubLibrary\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_Init),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_InitTypes),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_InitBuiltinModules),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_Initialize),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_Finalize),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "module\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_Create),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "shutdownEngine\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_Free),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetDll),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0mode\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_FopenNative),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "allocLocation\0withTraceback\0restoreError\0", 16LL, CPythonLibraryInterface, _CPythonLibraryInterface_LastPythonCallFailed),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0registryId\0baseAndInterfaceIds\0cid\0printErrors\0kind\0loc\0createObject\0dtOfObject\0", 87381LL, CPythonLibraryInterface, _CPythonLibraryInterface_RegisterComponentProxy),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_IsInitialized),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetVersion),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetPlatform),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetCopyright),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetCompiler),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetBuildInfo),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_SetProgramName),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_SetPythonHome),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetProgramName),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_GetPythonHome),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_ExecuteModule),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCallerContext_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "fp\0filename\0closeit\0flags\0", 85LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyRun_SimpleFileExFlags),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "url\0flags\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyRun_SimpleFileExFlags_1),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "code\0flags\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyRun_SimpleStringFlags),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "fp\0filename\0start\0globals\0locals\0closeit\0flags\0", 5461LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyRun_FileExFlags),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "fp\0filename\0flags\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyRun_InteractiveLoopFlags),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyGilState_Ensure),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyGilState_Release),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetGilState),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyGILState_GetThisThreadState),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyThreadState_Swap),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyThreadState_GetDict),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "code\0filename\0start\0flags\0", 85LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_CompileStringFlags),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_Incref),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_Decref),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_SafeIncref),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_SafeDecref),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyGC_Collect),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "codeObject\0x\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCode_Addr2Line),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "obj\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_UnpackDataType),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "obj\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_UnpackData),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_None),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_True),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_False),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_NotImplemented),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_Print),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_Clear),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0", 2LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_Occurred),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "errorType\0errorString\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_SetString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "errorType\0errorNumber\0filename\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_SetWithErrnoAndFilename),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "errorType\0errorNumber\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_SetWithErrno),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "errorType\0errorString\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_SetString_1),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "errorType\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_SetNone),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0value\0traceback\0", 42LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_Fetch),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0value\0traceback\0", 42LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_NormalizeException),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0value\0traceback\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_Restore),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "exc\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyErr_ExceptionMatches),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExceptionClass_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "pointer\0name\0destructor\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0pointer\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_SetPointer),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0name\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_GetPointer),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_GetContext),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0context\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_SetContext),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_CheckExact),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTraceBack_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyClass_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "size\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tuple\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_Size),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tuple\0index\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_GetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tuple\0index\0item\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_SetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tuple\0from\0to\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_GetSlice),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "tuple\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_CheckExact),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0attrName\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_HasAttrString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0name\0item\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_SetAttrString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0name\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_GetAttrString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "callable_object\0tupleArg\0kw\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Call),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Str),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Repr),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Dir),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o1\0o2\0opid\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_RichCompare),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Hash),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_IsTrue),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Not),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCallable_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Length),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0key\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_GetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0index\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_GetItemInt),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0index\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_GetItemString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0key\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_DelItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0key\0item\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_SetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "object\0type\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_TypeCheck),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_CallFunction),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySys_GetObject),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0o\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySys_SetObject),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "paths\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_SetPath),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "paths\0add\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySys_SetPath),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "args\0updatepath\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySys_SetArgvEx),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySys_GetPath),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "siteDir\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySite_AddSiteDir),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "str\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_FromString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "block\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_FromStringAndSize),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "str\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_AsString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "str\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_AsCString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "str\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_GetLength),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_GetIter),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "it\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyIter_Next),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0key\0raiseKeyError\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_GetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0key\0raiseKeyError\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_GetItemString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0key\0item\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_SetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0key\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_DelItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0key\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Contains),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Clear),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0pos\0key\0value\0", 93LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Next),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Keys),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Values),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Items),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Size),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dict\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Copy),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dict\0key\0item\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_SetItemString),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "size\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_CheckExact),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Size),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0index\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_GetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0anonymous_param_2\0item\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_SetItem),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0anonymous_param_2\0item\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Insert),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0item\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Append),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0from\0to\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_GetSlice),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0from\0to\0item\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_SetSlice),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Sort),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Reverse),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "list\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_AsTuple),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "p\0key\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_DelItemString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "module\0name\0value\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_AddObject),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "module\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_GetDict),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "mod\0name\0value\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_AddIntConstant),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyImport_ImportModule),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "path\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyImport_GetImporter),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyImport_GetModuleDict),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "a\0b\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_IsSubtype),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "type\0f\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_HasFeature),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "type\0f\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_FastSubclass),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_GetName),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "type\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_Ready),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_SaveThread),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_RestoreThread),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_ThreadsInitialized),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_InitThreads),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_AcquireThread),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "state\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_ReleaseThread),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_ReInitThreads),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_GetBuiltins),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "code\0globals\0locals\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyEval_EvalCode),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyFloat_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyFloat_FromFloat32),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyFloat_FromFloat64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyFloat_AsFloat64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyBool_FromBool),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromInt16),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromUInt16),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromInt32),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromUInt32),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromInt64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "value\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_FromUInt64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsInt16),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsUInt16),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsInt32),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsUInt32),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsInt64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_AsUInt64),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyNumber_Check),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "func\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyFunction_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "member\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyMember_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "domain\0allocator\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyMem_SetAllocator),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "cls\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyClass_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_DebugFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_VerboseFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_InteractiveFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_InspectFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_OptimizeFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_NoSiteFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_BytesWarningFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_FrozenFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_IgnoreEnvironmentFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_DontWriteBytecodeFlag),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPy_NoUserSiteDirectory),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_BaseException),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_Exception),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_StopIteration),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_GeneratorExit),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_StandardError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ArithmeticError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_LookupError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_AssertionError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_AttributeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_EOFError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_FloatingPointError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_EnvironmentError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_IOError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_OSError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ImportError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_IndexError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_KeyError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_KeyboardInterrupt),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_MemoryError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_NameError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_OverflowError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_RuntimeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_NotImplementedError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_SyntaxError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_IndentationError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_TabError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ReferenceError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_SystemError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_SystemExit),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_TypeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnboundLocalError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnicodeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnicodeEncodeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnicodeDecodeError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnicodeTranslateError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ValueError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ZeroDivisionError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_WindowsError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_BufferError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_MemoryErrorInst),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_RecursionErrorInst),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_Warning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UserWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_DeprecationWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_PendingDeprecationWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_SyntaxWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_RuntimeWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_FutureWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_ImportWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_UnicodeWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyExc_BytesWarning),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyNullImporter_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySuper_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyBool_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyModule_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyUnicode_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyLong_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyFloat_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTuple_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyList_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyDict_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyClass_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyTraceBack_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPySlice_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyType_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyMemoryView_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "str\0encoding\0size\0", 5LL, CPythonLibraryInterface, _CPythonLibraryInterface_ConvertAndCacheString),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "typeId\0type\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_RegisterSpecificPythonClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0f1\0f2\0", 21LL, CPythonLibraryInterface, _CPythonLibraryInterface_PrivateRegisterBuiltinConverter),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "anonymous_param_1\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetSpecialPath),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "anonymous_param_1\0path\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_RegisterSpecialPath),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyDataCapsule_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyData_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyCapsule_Type),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_PrivateGetCurrentCallerContext),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyDataType_ToMapperInstance),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyData_ToMapperInstance),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0capsule\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_ToMapperInstance),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0type\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_AssociateDataTypeWithPythonTypes),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetAssociatedDataType),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetConverterPyObject_FromData),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "data\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyData_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0data\0owner\0mapDt\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyData_New_1),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "dt\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyDataType_New),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyDataType_CheckExact),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyDataType_GetDataType),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "o\0", 1LL, CPythonLibraryInterface, _CPythonLibraryInterface_MPyData_CheckExact),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stackDepth\0obj\0expected\0k\0n\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_AsData),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetRegisteredTypesWithConversions),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "args\0argIndex\0canBeNone\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_ParseDataType),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "err\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_SetError),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "err\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_SetError_1),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "capsule\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_MaxonConvertAuto),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "origDt\0object\0ownership\0expected\0count\0", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CPyObject_FromGeneric),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_CreateGlobalDictionary),
				MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCurrentTraceback),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCPyRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCPyTypeRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCPyFrameRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCPyTracebackRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetCPyCodeRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyClassRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyMemberRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyFunctionRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyDataTypeRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyDataRefClass),
				MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CPythonLibraryInterface, _CPythonLibraryInterface_GetMPyCallerContextRefClass),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CPythonLibraryInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
		static maxon::reflection::ContainerInfo g_reflection_CPythonLibraryInterface(nullptr, &CPythonLibraryInterface::ProxyComponent::_descriptor, &RegisterReflection_CPythonLibraryInterface, &PRIVATE_MAXON_MODULE);
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_CPythonLibraryInterface_Static("net.maxon.python.interface.python.cpythonlibrary", nullptr, &RegisterReflection_CPythonLibraryInterface_Static, &PRIVATE_MAXON_MODULE);
	#endif
	}
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_PyModuleInterface(PyModuleInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::PyModuleRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class PyModuleInterface::ProxyComponent : public maxon::Component<ProxyComponent, PyModuleInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, PyModuleInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> GetFunctions37(BaseArray<NativePyCFunctionTable>& functions) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PyModuleInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PyModuleInterface_GetFunctions37_Offset), maxon::reflection::Argument::ByReference(functions)};
			(*handler_)(_fn_PyModuleInterface_GetFunctions37, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, BaseArray<NativePyCFunctionTable>&>::Invoke, (const void*) mt_._PyModuleInterface_GetFunctions37));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PyModuleInterface_GetFunctions37;
		Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PyModuleInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PyModuleInterface_GetConstants_Offset), maxon::reflection::Argument::ByReference(constants)};
			(*handler_)(_fn_PyModuleInterface_GetConstants, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, BaseArray<Tuple<const Char*, Int32>>&>::Invoke, (const void*) mt_._PyModuleInterface_GetConstants));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PyModuleInterface_GetConstants;
	};
	const maxon::reflection::Function* PyModuleInterface::ProxyComponent::_fn_PyModuleInterface_GetFunctions37;
	const maxon::reflection::Function* PyModuleInterface::ProxyComponent::_fn_PyModuleInterface_GetConstants;
	PRIVATE_MAXON_COMPONENT_REGISTER(PyModuleInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_PyModuleInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "functions\0", 0LL, PyModuleInterface, _PyModuleInterface_GetFunctions37),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "constants\0", 0LL, PyModuleInterface, _PyModuleInterface_GetConstants),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PyModuleInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_PyModuleInterface(nullptr, &PyModuleInterface::ProxyComponent::_descriptor, &RegisterReflection_PyModuleInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(PyModules);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(CPythonLibs);
#endif
}
#ifndef MAXON_COMPILER_GCC
#else
#endif
#endif
