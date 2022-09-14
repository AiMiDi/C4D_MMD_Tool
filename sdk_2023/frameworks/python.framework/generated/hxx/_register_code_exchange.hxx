#if 1
namespace maxon
{
	namespace CodeExchangeLanguageId
	{
		Python_PrivateAttribute Python;
	}
	const maxon::Char* const CodeExchangeInterface::MTable::_ids = 
		"Start@3008090429c5a175\0" // Result<void> Start()
		"Stop@3008090429c5a175\0" // Result<void> Stop()
		"SendScriptToIDE@76a9f0626bcf77bc\0" // Result<void> SendScriptToIDE(const PythonElementScriptRef& script)
		"SendConsoleOutput@d85d74e087a2f051\0" // Result<void> SendConsoleOutput(const String& content)
		"GetLanguage@c59539060884aef4\0" // InternedId GetLanguage() const
		"GetName@b8f12dfa16054f01\0" // String GetName() const
	"";
	const maxon::METHOD_FLAGS CodeExchangeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CodeExchangeInterface, , "net.maxon.python.interface.codeexchange", "maxon.CodeExchangeInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int CodeExchangeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<InternedId>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(CodeExchanges);
	MAXON_REGISTRY_REGISTER(CodeExchangesEnabled);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_code_exchange(0
	| maxon::CodeExchangeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
