
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#if !defined MAXON_TARGET_WINDOWS && !defined MAXON_TARGET_ANDROID
#endif
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif

struct StackTrace::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
	Bool (*_StackTrace_FindSymbol) (const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset);
	template <typename IMPL> void Init()
	{
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
		_StackTrace_FindSymbol = &IMPL::_StackTrace_FindSymbol;
	}
};

struct StackTrace::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
	static Bool _StackTrace_FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset) { return C::FindSymbol(function, name, module, offset); }
	};

};
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto StackTrace::FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset) -> Bool
{
	return MTable::_instance._StackTrace_FindSymbol(function, name, module, offset);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StackTrace); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StackTrace() { new (s_ui_maxon_StackTrace) maxon::EntityUse(StackTrace::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stacktrace.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StackTrace(StackTrace::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stacktrace.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

