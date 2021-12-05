
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
	template <typename IMPL> static void Init(MTable* tbl)
	{
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
		tbl->_StackTrace_FindSymbol = &IMPL::_StackTrace_FindSymbol;
	}
};

template <typename C> class StackTrace::Wrapper
{
public:
#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
	static Bool _StackTrace_FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset) { return C::FindSymbol(function, name, module, offset); }
};

#if defined MAXON_TARGET_WINDOWS || defined MAXON_TARGET_ANDROID
#else
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto StackTrace::FindSymbol(const void* function, const Block<Char>& name, const Block<Char>& module, Int& offset) -> Bool
{
	return MTable::_instance._StackTrace_FindSymbol(function, name, module, offset);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_StackTrace(StackTrace::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stacktrace.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

