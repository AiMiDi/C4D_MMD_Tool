#if 1
namespace maxon
{
	namespace enum19
	{
		enum class HARDWAREBREAKPOINTTYPE
		{
			CODE,				///< Throws an exception when the program counter touches the code at the watch address.
			READWRITE,	///< Throws an exception when the watched memory will be read or written.
			WRITE,			///< Throws an exception when the watched memory will be written.
		} ;
		static const maxon::UInt64 HARDWAREBREAKPOINTTYPE_values[] = {maxon::UInt64(enum19::HARDWAREBREAKPOINTTYPE::CODE), maxon::UInt64(enum19::HARDWAREBREAKPOINTTYPE::READWRITE), maxon::UInt64(enum19::HARDWAREBREAKPOINTTYPE::WRITE)};
		static const maxon::EnumInfo HARDWAREBREAKPOINTTYPE_info{"HARDWAREBREAKPOINTTYPE", SIZEOF(HARDWAREBREAKPOINTTYPE), false, "CODE\0READWRITE\0WRITE\0", HARDWAREBREAKPOINTTYPE_values, std::extent<decltype(HARDWAREBREAKPOINTTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_HARDWAREBREAKPOINTTYPE19(){ return enum19::HARDWAREBREAKPOINTTYPE_info; }
	namespace enum30
	{
		enum class HARDWAREBREAKPOINTSIZE
		{
			SIZE1,	///< 1 byte.
			SIZE2,	///< 2 bytes.
			SIZE4,	///< 4 bytes.
			SIZE8,	///< 8 bytes.
		} ;
		static const maxon::UInt64 HARDWAREBREAKPOINTSIZE_values[] = {maxon::UInt64(enum30::HARDWAREBREAKPOINTSIZE::SIZE1), maxon::UInt64(enum30::HARDWAREBREAKPOINTSIZE::SIZE2), maxon::UInt64(enum30::HARDWAREBREAKPOINTSIZE::SIZE4), maxon::UInt64(enum30::HARDWAREBREAKPOINTSIZE::SIZE8)};
		static const maxon::EnumInfo HARDWAREBREAKPOINTSIZE_info{"HARDWAREBREAKPOINTSIZE", SIZEOF(HARDWAREBREAKPOINTSIZE), false, "SIZE1\0SIZE2\0SIZE4\0SIZE8\0", HARDWAREBREAKPOINTSIZE_values, std::extent<decltype(HARDWAREBREAKPOINTSIZE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_HARDWAREBREAKPOINTSIZE30(){ return enum30::HARDWAREBREAKPOINTSIZE_info; }
	const maxon::Char* const DebugHardwareBreakPointInterface::MTable::_ids = 
		"Free@6168e4d86e79bf05\0" // void Free(const DebugHardwareBreakPointInterface* object)
		"SetHardwareBreakpoint@d4b84aa3f43ad92a\0" // Result<DebugHardwareBreakPointRef> SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress)
		"RemoveHardwareBreakpoint@3008090429c5a175\0" // Result<void> RemoveHardwareBreakpoint()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DebugHardwareBreakPointInterface::Hxx2::Unresolved : public DebugHardwareBreakPointInterface
	{
	public:
		static const Unresolved* Get(const DebugHardwareBreakPointInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DebugHardwareBreakPointInterface* o) { return (Unresolved*) o; }
		static void Free(const DebugHardwareBreakPointInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DebugHardwareBreakPointInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<DebugHardwareBreakPointRef> SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DebugHardwareBreakPointInterface::SetHardwareBreakpoint(type, size, watchAddress); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RemoveHardwareBreakpoint() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DebugHardwareBreakPointInterface*) this)->RemoveHardwareBreakpoint(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
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
		tbl->_DebugHardwareBreakPointInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_DebugHardwareBreakPointInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DebugHardwareBreakPointRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
		#else
		tbl->_DebugHardwareBreakPointInterface_SetHardwareBreakpoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_DebugHardwareBreakPointInterface_SetHardwareBreakpoint;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
		#else
		tbl->_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DebugHardwareBreakPointInterface, "net.maxon.interface.debughardwarebreakpoint", nullptr);
}
#endif
