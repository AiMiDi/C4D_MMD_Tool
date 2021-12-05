
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct Proxy::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Int> (*_Proxy_AddComponents) (ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces);
	Result<void> (*_Proxy_SetHandler) (Object* object, Int component, ProxyHandler&& handler);
	Result<void> (*_Proxy_SetHandler_1) (ClassInterface* cls, Int component, ProxyHandler&& handler);
	Result<GenericClass> (*_Proxy_GetClass) (const Block<const InterfaceReference* const>& interfaces);
	Result<ObjectRef> (*_Proxy_Create) (const GenericClass& cls, ProxyHandler&& handler);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Proxy_AddComponents = &IMPL::_Proxy_AddComponents;
		tbl->_Proxy_SetHandler = &IMPL::_Proxy_SetHandler;
		tbl->_Proxy_SetHandler_1 = &IMPL::_Proxy_SetHandler_1;
		tbl->_Proxy_GetClass = &IMPL::_Proxy_GetClass;
		tbl->_Proxy_Create = &IMPL::_Proxy_Create;
	}
};

template <typename C> class Proxy::Wrapper
{
public:
	static Result<Int> _Proxy_AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) { return C::AddComponents(cls, classProxy, interfaces, includeBaseInterfaces); }
	static Result<void> _Proxy_SetHandler(Object* object, Int component, ProxyHandler&& handler) { return C::SetHandler(object, component, std::forward<ProxyHandler>(handler)); }
	static Result<void> _Proxy_SetHandler_1(ClassInterface* cls, Int component, ProxyHandler&& handler) { return C::SetHandler(cls, component, std::forward<ProxyHandler>(handler)); }
	static Result<GenericClass> _Proxy_GetClass(const Block<const InterfaceReference* const>& interfaces) { return C::GetClass(interfaces); }
	static Result<ObjectRef> _Proxy_Create(const GenericClass& cls, ProxyHandler&& handler) { return C::Create(cls, std::forward<ProxyHandler>(handler)); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces) -> Result<Int>
{
	return MTable::_instance._Proxy_AddComponents(cls, classProxy, interfaces, includeBaseInterfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::SetHandler(Object* object, Int component, ProxyHandler&& handler) -> Result<void>
{
	return MTable::_instance._Proxy_SetHandler(object, component, std::forward<ProxyHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler) -> Result<void>
{
	return MTable::_instance._Proxy_SetHandler_1(cls, component, std::forward<ProxyHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::GetClass(const Block<const InterfaceReference* const>& interfaces) -> Result<GenericClass>
{
	return MTable::_instance._Proxy_GetClass(interfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Proxy::Create(const GenericClass& cls, ProxyHandler&& handler) -> Result<ObjectRef>
{
	return MTable::_instance._Proxy_Create(cls, std::forward<ProxyHandler>(handler));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Proxy(Proxy::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflection.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

