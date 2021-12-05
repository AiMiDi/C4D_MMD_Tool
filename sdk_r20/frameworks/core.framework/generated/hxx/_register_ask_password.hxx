#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AskPasswordInterface, "net.maxon.interface.askpassword", "maxon.AskPasswordInterface", , &Object::_interface);
	const maxon::Char* const AskPasswordInterface::MTable::_ids = 
		"AskPasswordFromUser@fa6a9fe074ce2057\0" // AskPasswordFromUser(const String& text) const
	"";
	template <typename DUMMY> maxon::Int AskPasswordInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	const maxon::Char* const AskPasswordMethod::MTable::_ids = 
		"Set@f8ec179de6d91fc8\0" // Set(const AskPasswordRef& method)
		"Get@a949ed4b40937b4a\0" // Get()
	"";
	class AskPasswordMethod::Unresolved : public AskPasswordMethod
	{
	public:
		static const Unresolved* Get(const AskPasswordMethod* o) { return (const Unresolved*) o; }
		static Unresolved* Get(AskPasswordMethod* o) { return (Unresolved*) o; }
		static void Set(const AskPasswordRef& method) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return AskPasswordMethod::Set(method); return maxon::PrivateLogNullptrError();}
		static const AskPasswordRef& Get() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return AskPasswordMethod::Get(); return maxon::PrivateIncompleteNullReturnValue<const AskPasswordRef&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE AskPasswordMethod::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const AskPasswordRef&>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool AskPasswordMethod::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_AskPasswordMethod_Set = &Wrapper<Unresolved>::_AskPasswordMethod_Set;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const AskPasswordRef&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_AskPasswordMethod_Get = &Wrapper<Unresolved>::_AskPasswordMethod_Get;
	#else
		tbl->_AskPasswordMethod_Get = &Wrapper<Unresolved>::_AskPasswordMethod_Get;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(AskPasswordMethod, "net.maxon.interface.askpasswordmethod", MAXON_INTERFACE_REGISTER_NULLIMPL(AskPasswordMethod));
	template <typename DUMMY> maxon::Int AskPasswordMethod::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const AskPasswordRef&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_ask_password(0
	| maxon::AskPasswordInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::AskPasswordMethod::PrivateInstantiateNullValueHelper<maxon::Int>()
);
