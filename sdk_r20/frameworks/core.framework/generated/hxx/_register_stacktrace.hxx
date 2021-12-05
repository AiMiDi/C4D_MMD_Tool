#if 1
#if !defined MAXON_TARGET_WINDOWS && !defined MAXON_TARGET_ANDROID
#endif
namespace maxon
{
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
	const maxon::Char* const StackTrace::MTable::_ids = 
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
		"FindSymbol@f3e6fd546fd10680\0" // FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset)
	"";
	class StackTrace::Unresolved : public StackTrace
	{
	public:
		static const Unresolved* Get(const StackTrace* o) { return (const Unresolved*) o; }
		static Unresolved* Get(StackTrace* o) { return (Unresolved*) o; }
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
		static Bool FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StackTrace::FindSymbol(function, name, module, offset); return maxon::PrivateLogNullptrError(false);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE StackTrace::MTable::_returnTypes[] = 
	{
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
		maxon::details::NullReturnType<Bool>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool StackTrace::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_StackTrace_FindSymbol = &Wrapper<Unresolved>::_StackTrace_FindSymbol;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(StackTrace, "net.maxon.interface.stacktrace", nullptr);
	template <typename DUMMY> maxon::Int StackTrace::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stacktrace(0
	| maxon::StackTrace::PrivateInstantiateNullValueHelper<maxon::Int>()
);
