
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
	void (*DebugHardwareBreakPointInterface_Free) (const DebugHardwareBreakPointInterface* object);
	Result<DebugHardwareBreakPointRef> (*DebugHardwareBreakPointInterface_SetHardwareBreakpoint) (HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress);
	Result<void> (*DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint) (DebugHardwareBreakPointInterface* this_);
	template <typename IMPL> void Init()
	{
		DebugHardwareBreakPointInterface_Free = &IMPL::DebugHardwareBreakPointInterface_Free;
		DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &IMPL::DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
		DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &IMPL::DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
	}
};

struct DebugHardwareBreakPointInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void DebugHardwareBreakPointInterface_Free(const DebugHardwareBreakPointInterface* object) { return C::Free(object); }
		static Result<DebugHardwareBreakPointRef> DebugHardwareBreakPointInterface_SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) { return C::SetHardwareBreakpoint(type, size, watchAddress); }
		static Result<void> DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(DebugHardwareBreakPointInterface* this_) { return C::Get(this_)->RemoveHardwareBreakpoint(); }
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
	return MTable::_instance.DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Hxx1::ConstFn<S>::SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) -> Result<DebugHardwareBreakPointRef>
{
	return (MTable::_instance.DebugHardwareBreakPointInterface_SetHardwareBreakpoint(type, size, watchAddress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Hxx1::Fn<S>::RemoveHardwareBreakpoint() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DebugHardwareBreakPointInterface* o_ = (DebugHardwareBreakPointInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(o_));
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

