
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Proxy::PrivateGetCppName() { return nullptr; }

struct Proxy::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Proxy_AddComponents, AddComponents, MAXON_EXPAND_VA_ARGS, (Result<Int>), ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces);
	PRIVATE_MAXON_SF_POINTER(Proxy_SetHandler, SetHandler, MAXON_EXPAND_VA_ARGS, (Result<void>), ObjectInterface* object, Int component, ProxyHandler&& handler);
	PRIVATE_MAXON_SF_POINTER(Proxy_SetHandler_1, SetHandler, MAXON_EXPAND_VA_ARGS, (Result<void>), ClassInterface* cls, Int component, ProxyHandler&& handler);
	PRIVATE_MAXON_SF_POINTER(Proxy_GetClass, GetClass, MAXON_EXPAND_VA_ARGS, (Result<maxon::Class<>>), const Block<const InterfaceReference* const>& interfaces);
	PRIVATE_MAXON_SF_POINTER(Proxy_Create, Create, MAXON_EXPAND_VA_ARGS, (Result<ObjectRef>), const maxon::Class<>& cls, ProxyHandler&& handler);
	template <typename IMPL> void Init()
	{
		Proxy_AddComponents = Proxy_AddComponents_GetPtr<IMPL>(true);
		Proxy_SetHandler = Proxy_SetHandler_GetPtr<IMPL>(true);
		Proxy_SetHandler_1 = Proxy_SetHandler_1_GetPtr<IMPL>(true);
		Proxy_GetClass = Proxy_GetClass_GetPtr<IMPL>(true);
		Proxy_Create = Proxy_Create_GetPtr<IMPL>(true);
	}
};

struct Proxy::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Result<Int> Proxy_AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) { return C::AddComponents(cls, classProxy, interfaces, includeBaseInterfaces); }
		static Result<void> Proxy_SetHandler(ObjectInterface* object, Int component, ProxyHandler&& handler) { return C::SetHandler(object, component, std::forward<ProxyHandler>(handler)); }
		static Result<void> Proxy_SetHandler_1(ClassInterface* cls, Int component, ProxyHandler&& handler) { return C::SetHandler(cls, component, std::forward<ProxyHandler>(handler)); }
		static Result<maxon::Class<>> Proxy_GetClass(const Block<const InterfaceReference* const>& interfaces) { return C::GetClass(interfaces); }
		static Result<ObjectRef> Proxy_Create(const maxon::Class<>& cls, ProxyHandler&& handler) { return C::Create(cls, std::forward<ProxyHandler>(handler)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) -> Result<Int>
{
	return MTable::_instance.Proxy_AddComponents(cls, classProxy, interfaces, includeBaseInterfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::SetHandler(ObjectInterface* object, Int component, ProxyHandler&& handler) -> Result<void>
{
	return MTable::_instance.Proxy_SetHandler(object, component, std::forward<ProxyHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler) -> Result<void>
{
	return MTable::_instance.Proxy_SetHandler_1(cls, component, std::forward<ProxyHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::GetClass(const Block<const InterfaceReference* const>& interfaces) -> Result<maxon::Class<>>
{
	return MTable::_instance.Proxy_GetClass(interfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::Create(const maxon::Class<>& cls, ProxyHandler&& handler) -> Result<ObjectRef>
{
	return MTable::_instance.Proxy_Create(cls, std::forward<ProxyHandler>(handler));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflection)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Proxy); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Proxy() { new (s_ui_maxon_reflection_Proxy) maxon::EntityUse(Proxy::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflection.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Proxy(Proxy::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflection.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

