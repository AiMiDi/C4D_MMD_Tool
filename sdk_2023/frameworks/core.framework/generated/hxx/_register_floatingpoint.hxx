#if 1
namespace maxon
{
	const maxon::Char* const Misc::MTable::_ids = 
		"SetFloatingPointChecks@ef3606f53b1e3c6f\0" // Bool SetFloatingPointChecks(Bool on)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Misc::Hxx2::Unresolved : public Misc
	{
	public:
		static const Unresolved* Get(const Misc* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Misc* o) { return (Unresolved*) o; }
		static Bool SetFloatingPointChecks(Bool on) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Misc::SetFloatingPointChecks(on); return maxon::PrivateLogNullptrError(false);}
	};
	MAXON_WARNING_POP
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
		tbl->Misc_SetFloatingPointChecks = PRIVATE_MAXON_MF_CAST(decltype(Misc_SetFloatingPointChecks), &Hxx2::Wrapper<Hxx2::Unresolved>::Misc_SetFloatingPointChecks);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Misc, "net.maxon.interface.misc", nullptr);
}
#endif
