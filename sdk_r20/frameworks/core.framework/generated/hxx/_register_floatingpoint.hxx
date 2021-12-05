#if 1
namespace maxon
{
	const maxon::Char* const Misc::MTable::_ids = 
		"SetFloatingPointChecks@68c0cdfee8fa0\0" // SetFloatingPointChecks(Bool on)
	"";
	class Misc::Unresolved : public Misc
	{
	public:
		static const Unresolved* Get(const Misc* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Misc* o) { return (Unresolved*) o; }
		static Bool SetFloatingPointChecks(Bool on) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Misc::SetFloatingPointChecks(on); return maxon::PrivateLogNullptrError(false);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Misc::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Bool>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Misc::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Misc_SetFloatingPointChecks = &Wrapper<Unresolved>::_Misc_SetFloatingPointChecks;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Misc, "net.maxon.interface.misc", nullptr);
	template <typename DUMMY> maxon::Int Misc::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_floatingpoint(0
	| maxon::Misc::PrivateInstantiateNullValueHelper<maxon::Int>()
);
