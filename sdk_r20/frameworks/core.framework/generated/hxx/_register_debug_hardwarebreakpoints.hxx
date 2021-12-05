#if 1
namespace maxon
{
	namespace enum19 { enum class HARDWAREBREAKPOINTTYPE
	{
		CODE,				///< Throws an exception when the program counter touches the code at the watch address.
		READWRITE,	///< Throws an exception when the watched memory will be read or written.
		WRITE,			///< Throws an exception when the watched memory will be written.
	} ; }
	maxon::String PrivateToString_HARDWAREBREAKPOINTTYPE19(std::underlying_type<enum19::HARDWAREBREAKPOINTTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::HARDWAREBREAKPOINTTYPE::CODE, (maxon::UInt64) enum19::HARDWAREBREAKPOINTTYPE::READWRITE, (maxon::UInt64) enum19::HARDWAREBREAKPOINTTYPE::WRITE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HARDWAREBREAKPOINTTYPE", SIZEOF(x), false, values, "CODE\0READWRITE\0WRITE\0", fmt);
	}
	namespace enum30 { enum class HARDWAREBREAKPOINTSIZE
	{
		SIZE1,	///< 1 byte.
		SIZE2,	///< 2 bytes.
		SIZE4,	///< 4 bytes.
		SIZE8,	///< 8 bytes.
	} ; }
	maxon::String PrivateToString_HARDWAREBREAKPOINTSIZE30(std::underlying_type<enum30::HARDWAREBREAKPOINTSIZE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum30::HARDWAREBREAKPOINTSIZE::SIZE1, (maxon::UInt64) enum30::HARDWAREBREAKPOINTSIZE::SIZE2, (maxon::UInt64) enum30::HARDWAREBREAKPOINTSIZE::SIZE4, (maxon::UInt64) enum30::HARDWAREBREAKPOINTSIZE::SIZE8};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HARDWAREBREAKPOINTSIZE", SIZEOF(x), false, values, "SIZE1\0SIZE2\0SIZE4\0SIZE8\0", fmt);
	}
	const maxon::Char* const DebugHardwareBreakPointInterface::MTable::_ids = 
		"Free@02ffa9ad9d24f912\0" // Free(const DebugHardwareBreakPointInterface* object)
		"SetHardwareBreakpoint@bcc2d3ec6c4cae11\0" // SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress)
		"RemoveHardwareBreakpoint@a54f4799cbe1a498\0" // RemoveHardwareBreakpoint()
	"";
	class DebugHardwareBreakPointInterface::Unresolved : public DebugHardwareBreakPointInterface
	{
	public:
		static const Unresolved* Get(const DebugHardwareBreakPointInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DebugHardwareBreakPointInterface* o) { return (Unresolved*) o; }
		static void Free(const DebugHardwareBreakPointInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DebugHardwareBreakPointInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<DebugHardwareBreakPointRef> SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DebugHardwareBreakPointInterface::SetHardwareBreakpoint(type, size, watchAddress); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RemoveHardwareBreakpoint() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DebugHardwareBreakPointInterface*) this)->RemoveHardwareBreakpoint(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DebugHardwareBreakPointInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<DebugHardwareBreakPointRef>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DebugHardwareBreakPointInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DebugHardwareBreakPointInterface_Free = &Wrapper<Unresolved>::_DebugHardwareBreakPointInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DebugHardwareBreakPointRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &Wrapper<Unresolved>::_DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
	#else
		tbl->_DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &Wrapper<Unresolved>::_DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &Wrapper<Unresolved>::_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
	#else
		tbl->_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &Wrapper<Unresolved>::_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DebugHardwareBreakPointInterface, "net.maxon.interface.debughardwarebreakpoint", nullptr);
	template <typename DUMMY> maxon::Int DebugHardwareBreakPointInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_debug_hardwarebreakpoints(0
	| maxon::DebugHardwareBreakPointInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
