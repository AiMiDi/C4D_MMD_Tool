#if 1
namespace maxon
{
	namespace reflection
	{
		const maxon::Char* const Proxy::MTable::_ids = 
		"AddComponents@2852a9a82b3e719d\0" // AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces)
		"SetHandler@17f6988a33ff5ed1\0" // SetHandler(Object* object, Int component, ProxyHandler&& handler)
		"SetHandler@ce28b222132600af\0" // SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler)
		"GetClass@490a71ce9415958e\0" // GetClass(const Block<const InterfaceReference* const>& interfaces)
		"Create@9c43ea65fc6c92c9\0" // Create(const GenericClass& cls, ProxyHandler&& handler)
		"";
		class Proxy::Unresolved : public Proxy
		{
		public:
			static const Unresolved* Get(const Proxy* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Proxy* o) { return (Unresolved*) o; }
			static Result<Int> AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::AddComponents(cls, classProxy, interfaces, includeBaseInterfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<void> SetHandler(Object* object, Int component, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::SetHandler(object, component, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<void> SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::SetHandler(cls, component, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<GenericClass> GetClass(const Block<const InterfaceReference* const>& interfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::GetClass(interfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<ObjectRef> Create(const GenericClass& cls, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::Create(cls, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		};
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Proxy::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Result<Int>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::details::NullReturnType<Result<GenericClass>>::value,
			maxon::details::NullReturnType<Result<ObjectRef>>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Proxy::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Proxy_AddComponents = &Wrapper<Unresolved>::_Proxy_AddComponents;
		#else
			tbl->_Proxy_AddComponents = &Wrapper<Unresolved>::_Proxy_AddComponents;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Proxy_SetHandler = &Wrapper<Unresolved>::_Proxy_SetHandler;
		#else
			tbl->_Proxy_SetHandler = &Wrapper<Unresolved>::_Proxy_SetHandler;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Proxy_SetHandler_1 = &Wrapper<Unresolved>::_Proxy_SetHandler_1;
		#else
			tbl->_Proxy_SetHandler_1 = &Wrapper<Unresolved>::_Proxy_SetHandler_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<GenericClass>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Proxy_GetClass = &Wrapper<Unresolved>::_Proxy_GetClass;
		#else
			tbl->_Proxy_GetClass = &Wrapper<Unresolved>::_Proxy_GetClass;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<ObjectRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Proxy_Create = &Wrapper<Unresolved>::_Proxy_Create;
		#else
			tbl->_Proxy_Create = &Wrapper<Unresolved>::_Proxy_Create;
		#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Proxy, "net.maxon.reflection.interface.proxy", nullptr);
		template <typename DUMMY> maxon::Int Proxy::PrivateInstantiateNullValueHelper()
		{
			return 0
			;
		}
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_reflection(0
	| maxon::reflection::Proxy::PrivateInstantiateNullValueHelper<maxon::Int>()
);
