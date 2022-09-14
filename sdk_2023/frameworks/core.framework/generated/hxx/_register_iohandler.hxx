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
		if (maxon::details::NullReturnType<IoHandler>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoHandlerInterface_GetHandlerForScheme = PRIVATE_MAXON_MF_CAST(decltype(IoHandlerInterface_GetHandlerForScheme), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::IoHandlerInterface_GetHandlerForScheme);
		#else
		tbl->IoHandlerInterface_GetHandlerForScheme = PRIVATE_MAXON_MF_CAST(decltype(IoHandlerInterface_GetHandlerForScheme), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::IoHandlerInterface_GetHandlerForScheme);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const IoHandlerInterface::MTable::_ids = 
		"GetUrlScheme@daec66e7da84a648\0" // const Id& GetUrlScheme() const
		"SetSystemPath@1853237244640383\0" // Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const
		"GetSystemPath@e147d30b693c56ab\0" // Result<String> GetSystemPath(const UrlInterface& url) const
		"AppendUrl@1853237244640383\0" // Result<void> AppendUrl(UrlInterface& url, const String& name) const
		"AppendUrl@7f287f7204c4e323\0" // Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const
		"RemoveUrl@8280af40836051f9\0" // Result<void> RemoveUrl(UrlInterface& url) const
		"OpenConnection@7edac6fb78a97e6c\0" // Result<IoConnectionRef> OpenConnection(const Url& name) const
		"Normalize@49f7ba978dc60f4a\0" // Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const
		"IoNormalize@49f7ba978dc60f4a\0" // Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const
		"ConvertToUiName@a962c611129095a7\0" // Result<String> ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const
		"ConvertToUiNameWithRepository@9311c89f9a1d1b95\0" // Result<String> ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const
	"";
	const maxon::METHOD_FLAGS IoHandlerInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoHandlerInterface, , "net.maxon.interface.iohandler", "maxon.IoHandlerInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const IoHandlerInterface::Hxx2::StaticMTable::_ids = 
		"GetHandlerForScheme@c66ff200116807b6\0" // IoHandler GetHandlerForScheme(const UrlScheme& scheme)
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
