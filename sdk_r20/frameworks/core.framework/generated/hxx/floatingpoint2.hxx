
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct Misc::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_Misc_SetFloatingPointChecks) (Bool on);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Misc_SetFloatingPointChecks = &IMPL::_Misc_SetFloatingPointChecks;
	}
};

template <typename C> class Misc::Wrapper
{
public:
	static Bool _Misc_SetFloatingPointChecks(Bool on) { return C::SetFloatingPointChecks(on); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Misc::SetFloatingPointChecks(Bool on) -> Bool
{
	return MTable::_instance._Misc_SetFloatingPointChecks(on);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_Misc(Misc::_interface.GetReference(), &maxon::g_translationUnit, "maxon/floatingpoint.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

