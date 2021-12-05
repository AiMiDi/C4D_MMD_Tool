#if 1
namespace maxon
{
	class IoHandlerInterface::Unresolved : public IoHandlerInterface
	{
	public:
		static IoHandler GetHandlerForScheme(const UrlScheme& scheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return IoHandlerInterface::GetHandlerForScheme(scheme); return maxon::PrivateIncompleteNullReturnValue<IoHandler>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE IoHandlerInterface::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<IoHandler>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool IoHandlerInterface::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<IoHandler>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoHandlerInterface_GetHandlerForScheme = &Wrapper<maxon::StaticHelper<Unresolved>>::_IoHandlerInterface_GetHandlerForScheme;
	#else
		tbl->_IoHandlerInterface_GetHandlerForScheme = &Wrapper<maxon::StaticHelper<Unresolved>>::_IoHandlerInterface_GetHandlerForScheme;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoHandlerInterface, "net.maxon.interface.iohandler", "maxon.IoHandlerInterface", , &Object::_interface);
	const maxon::Char* const IoHandlerInterface::MTable::_ids = 
		"GetUrlScheme@12b0ccb12f8b105\0" // GetUrlScheme() const
		"SetSystemPath@e4dd601efb58086a\0" // SetSystemPath(UrlInterface& url, const String& systemPath) const
		"GetSystemPath@f0afce865dbded10\0" // GetSystemPath(const UrlInterface& url) const
		"AppendUrl@e4dd601efb58086a\0" // AppendUrl(UrlInterface& url, const String& name) const
		"AppendUrl@38fd3b590d82e4de\0" // AppendUrl(UrlInterface& url, const Url& relativeUrl) const
		"RemoveUrl@abbb91af26210596\0" // RemoveUrl(UrlInterface& url) const
		"OpenConnection@b803b313de5cecf1\0" // OpenConnection(const Url& name) const
		"Normalize@0706f803b656b23d\0" // Normalize(const Url& url, NORMALIZEFLAGS flags) const
		"IoNormalize@0706f803b656b23d\0" // IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
	"";
	const maxon::Char* const IoHandlerInterface::StaticMTable::_ids = 
		"GetHandlerForScheme@c2593cb4227932b5\0" // GetHandlerForScheme(const UrlScheme& scheme)
	"";
	MAXON_INTERFACE_REGISTER_STATIC(IoHandlerInterface, "net.maxon.interface.iohandler");
	template <typename DUMMY> maxon::Int IoHandlerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<IoHandler>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(IoHandlers);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoHandlerObjectBaseClass, , "net.maxon.class.iohandlerobjectbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoHandlerObjectFileClass, , "net.maxon.class.iohandlerobjectfile");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iohandler(0
	| maxon::IoHandlerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
