#if 1
namespace maxon
{
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class IoHandlerInterface::Hxx2::Unresolved : public IoHandlerInterface
	{
	public:
		static IoHandler GetHandlerForScheme(const UrlScheme& scheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return IoHandlerInterface::GetHandlerForScheme(scheme); return maxon::PrivateIncompleteNullReturnValue<IoHandler>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE IoHandlerInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<IoHandler>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool IoHandlerInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<IoHandler>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoHandlerInterface_GetHandlerForScheme = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_IoHandlerInterface_GetHandlerForScheme;
		#else
		tbl->_IoHandlerInterface_GetHandlerForScheme = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_IoHandlerInterface_GetHandlerForScheme;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const IoHandlerInterface::MTable::_ids = 
		"GetUrlScheme@12b0ccb12f8b105\0" // const Id& GetUrlScheme() const
		"SetSystemPath@e4dd601efb58086a\0" // Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const
		"GetSystemPath@f0afce865dbded10\0" // Result<String> GetSystemPath(const UrlInterface& url) const
		"AppendUrl@e4dd601efb58086a\0" // Result<void> AppendUrl(UrlInterface& url, const String& name) const
		"AppendUrl@38fd3b590d82e4de\0" // Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const
		"RemoveUrl@abbb91af26210596\0" // Result<void> RemoveUrl(UrlInterface& url) const
		"OpenConnection@b803b313de5cecf1\0" // Result<IoConnectionRef> OpenConnection(const Url& name) const
		"Normalize@0706f803b656b23d\0" // Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const
		"IoNormalize@0706f803b656b23d\0" // Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoHandlerInterface, , "net.maxon.interface.iohandler", "maxon.IoHandlerInterface", (&ObjectInterface::_interface));
	const maxon::Char* const IoHandlerInterface::Hxx2::StaticMTable::_ids = 
		"GetHandlerForScheme@c2593cb4227932b5\0" // IoHandler GetHandlerForScheme(const UrlScheme& scheme)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(IoHandlerInterface, , "net.maxon.interface.iohandler");
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
