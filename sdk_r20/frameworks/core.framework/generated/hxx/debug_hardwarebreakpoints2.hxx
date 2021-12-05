
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DebugHardwareBreakPointInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_DebugHardwareBreakPointInterface_Free) (const DebugHardwareBreakPointInterface* object);
	Result<DebugHardwareBreakPointRef> (*_DebugHardwareBreakPointInterface_SetHardwareBreakpoint) (HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress);
	Result<void> (*_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint) (DebugHardwareBreakPointInterface* this_);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DebugHardwareBreakPointInterface_Free = &IMPL::_DebugHardwareBreakPointInterface_Free;
		tbl->_DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &IMPL::_DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
		tbl->_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &IMPL::_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
	}
};

template <typename C> class DebugHardwareBreakPointInterface::Wrapper
{
public:
	static void _DebugHardwareBreakPointInterface_Free(const DebugHardwareBreakPointInterface* object) { return C::Free(object); }
	static Result<DebugHardwareBreakPointRef> _DebugHardwareBreakPointInterface_SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) { return C::SetHardwareBreakpoint(type, size, watchAddress); }
	static Result<void> _DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(DebugHardwareBreakPointInterface* this_) { return ((C*) this_)->RemoveHardwareBreakpoint(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::Free(const DebugHardwareBreakPointInterface* object) -> void
{
	return MTable::_instance._DebugHardwareBreakPointInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) -> Result<DebugHardwareBreakPointRef>
{
	return MTable::_instance._DebugHardwareBreakPointInterface_SetHardwareBreakpoint(type, size, watchAddress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::RemoveHardwareBreakpoint() -> Result<void>
{
	return MTable::_instance._DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::ConstReferenceFunctionsImpl<S>::SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) -> Result<DebugHardwareBreakPointRef> { return (MTable::_instance._DebugHardwareBreakPointInterface_SetHardwareBreakpoint(type, size, watchAddress)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DebugHardwareBreakPointInterface::ReferenceFunctionsImpl<S>::RemoveHardwareBreakpoint() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DebugHardwareBreakPointInterface* o_ = (DebugHardwareBreakPointInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DebugHardwareBreakPointInterface(DebugHardwareBreakPointInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/debug_hardwarebreakpoints.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

