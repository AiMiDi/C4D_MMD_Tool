#if 1
namespace maxon
{
	namespace reflection
	{
		const maxon::Char* const Proxy::MTable::_ids = 
		"AddComponents@e6754454df3f8e4e\0" // Result<Int> AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces)
		"SetHandler@366fbcaf32689a7d\0" // Result<void> SetHandler(ObjectInterface* object, Int component, ProxyHandler&& handler)
		"SetHandler@ea1ffd820954e2d4\0" // Result<void> SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler)
		"GetClass@4fb9eaea5ca8e601\0" // Result<maxon::Class<>> GetClass(const Block<const InterfaceReference* const>& interfaces)
		"Create@27ac3217615ddab4\0" // Result<ObjectRef> Create(const maxon::Class<>& cls, ProxyHandler&& handler)
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Proxy::Hxx2::Unresolved : public Proxy
		{
		public:
			static const Unresolved* Get(const Proxy* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Proxy* o) { return (Unresolved*) o; }
			static Result<Int> AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::AddComponents(cls, classProxy, interfaces, includeBaseInterfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<void> SetHandler(ObjectInterface* object, Int component, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::SetHandler(object, component, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<void> SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::SetHandler(cls, component, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<maxon::Class<>> GetClass(const Block<const InterfaceReference* const>& interfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::GetClass(interfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<ObjectRef> Create(const maxon::Class<>& cls, ProxyHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Proxy::Create(cls, std::forward<ProxyHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Proxy::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Result<Int>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::details::NullReturnType<Result<maxon::Class<>>>::value,
			maxon::details::NullReturnType<Result<ObjectRef>>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Proxy::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Proxy_AddComponents = PRIVATE_MAXON_MF_CAST(decltype(Proxy_AddComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_AddComponents);
			#else
			tbl->Proxy_AddComponents = PRIVATE_MAXON_MF_CAST(decltype(Proxy_AddComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_AddComponents);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Proxy_SetHandler = PRIVATE_MAXON_MF_CAST(decltype(Proxy_SetHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_SetHandler);
			#else
			tbl->Proxy_SetHandler = PRIVATE_MAXON_MF_CAST(decltype(Proxy_SetHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_SetHandler);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Proxy_SetHandler_1 = PRIVATE_MAXON_MF_CAST(decltype(Proxy_SetHandler_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_SetHandler_1);
			#else
			tbl->Proxy_SetHandler_1 = PRIVATE_MAXON_MF_CAST(decltype(Proxy_SetHandler_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_SetHandler_1);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<maxon::Class<>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Proxy_GetClass = PRIVATE_MAXON_MF_CAST(decltype(Proxy_GetClass), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_GetClass);
			#else
			tbl->Proxy_GetClass = PRIVATE_MAXON_MF_CAST(decltype(Proxy_GetClass), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_GetClass);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<ObjectRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Proxy_Create = PRIVATE_MAXON_MF_CAST(decltype(Proxy_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_Create);
			#else
			tbl->Proxy_Create = PRIVATE_MAXON_MF_CAST(decltype(Proxy_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::Proxy_Create);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Proxy, "net.maxon.reflection.interface.proxy", nullptr);
	}
}
#endif
