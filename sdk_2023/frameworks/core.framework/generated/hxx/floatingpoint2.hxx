
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Misc::PrivateGetCppName() { return nullptr; }

struct Misc::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Misc_SetFloatingPointChecks, SetFloatingPointChecks, MAXON_EXPAND_VA_ARGS, (Bool), Bool on);
	template <typename IMPL> void Init()
	{
		Misc_SetFloatingPointChecks = Misc_SetFloatingPointChecks_GetPtr<IMPL>(true);
	}
};

struct Misc::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Bool Misc_SetFloatingPointChecks(Bool on) { return C::SetFloatingPointChecks(on); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Misc::SetFloatingPointChecks(Bool on) -> Bool
{
	return MTable::_instance.Misc_SetFloatingPointChecks(on);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_floatingpoint)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Misc); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Misc() { new (s_ui_maxon_Misc) maxon::EntityUse(Misc::_interface.GetReference(), &maxon::g_translationUnit, "maxon/floatingpoint.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Misc(Misc::_interface.GetReference(), &maxon::g_translationUnit, "maxon/floatingpoint.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

