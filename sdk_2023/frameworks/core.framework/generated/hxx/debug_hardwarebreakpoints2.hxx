
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DebugHardwareBreakPointInterface::PrivateGetCppName() { return "maxon::DebugHardwareBreakPointRef"; }

struct DebugHardwareBreakPointInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(DebugHardwareBreakPointInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const DebugHardwareBreakPointInterface* object);
	PRIVATE_MAXON_SF_POINTER(DebugHardwareBreakPointInterface_SetHardwareBreakpoint, SetHardwareBreakpoint, MAXON_EXPAND_VA_ARGS, (Result<DebugHardwareBreakPointRef>), HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress);
	PRIVATE_MAXON_MF_POINTER(DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint, RemoveHardwareBreakpoint, false, DebugHardwareBreakPointInterface,, (Result<void>));
	template <typename IMPL> void Init()
	{
		DebugHardwareBreakPointInterface_Free = DebugHardwareBreakPointInterface_Free_GetPtr<IMPL>(true);
		DebugHardwareBreakPointInterface_SetHardwareBreakpoint = DebugHardwareBreakPointInterface_SetHardwareBreakpoint_GetPtr<IMPL>(true);
		DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint_GetPtr<IMPL>(0, true).first;
	}
};

struct DebugHardwareBreakPointInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void DebugHardwareBreakPointInterface_Free(const DebugHardwareBreakPointInterface* object) { return C::Free(object); }
		static Result<DebugHardwareBreakPointRef> DebugHardwareBreakPointInterface_SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) { return C::SetHardwareBreakpoint(type, size, watchAddress); }
		PRIVATE_MAXON_MF_WRAPPER(DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint, DebugHardwareBreakPointInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(DebugHardwareBreakPointInterface))->RemoveHardwareBreakpoint(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Free(const DebugHardwareBreakPointInterface* object) -> void
{
	return MTable::_instance.DebugHardwareBreakPointInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) -> Result<DebugHardwareBreakPointRef>
{
	return MTable::_instance.DebugHardwareBreakPointInterface_SetHardwareBreakpoint(type, size, watchAddress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::RemoveHardwareBreakpoint() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Hxx1::ConstFn<S>::SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) -> Result<DebugHardwareBreakPointRef>
{
	return (MTable::_instance.DebugHardwareBreakPointInterface_SetHardwareBreakpoint(type, size, watchAddress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Hxx1::Fn<S>::RemoveHardwareBreakpoint() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DebugHardwareBreakPointInterface* o_ = (DebugHardwareBreakPointInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_debug_hardwarebreakpoints)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DebugHardwareBreakPointInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DebugHardwareBreakPointInterface() { new (s_ui_maxon_DebugHardwareBreakPointInterface) maxon::EntityUse(DebugHardwareBreakPointInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/debug_hardwarebreakpoints.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DebugHardwareBreakPointInterface(DebugHardwareBreakPointInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/debug_hardwarebreakpoints.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

