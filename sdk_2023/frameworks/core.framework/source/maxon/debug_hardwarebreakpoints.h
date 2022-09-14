#ifndef DEBUG_HARDWAREBREAKPOINTS_H__
#define DEBUG_HARDWAREBREAKPOINTS_H__


#include "maxon/interface.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Hardware breakpoint type.
//----------------------------------------------------------------------------------------
enum class HARDWAREBREAKPOINTTYPE
{
	CODE,				///< Throws an exception when the program counter touches the code at the watch address.
	READWRITE,	///< Throws an exception when the watched memory will be read or written.
	WRITE,			///< Throws an exception when the watched memory will be written.
} MAXON_ENUM_LIST(HARDWAREBREAKPOINTTYPE);

//----------------------------------------------------------------------------------------
/// Hardware breakpoint size.
//----------------------------------------------------------------------------------------
enum class HARDWAREBREAKPOINTSIZE
{
	SIZE1,	///< 1 byte.
	SIZE2,	///< 2 bytes.
	SIZE4,	///< 4 bytes.
	SIZE8,	///< 8 bytes.
} MAXON_ENUM_LIST(HARDWAREBREAKPOINTSIZE);

class DebugHardwareBreakPointRef;

//----------------------------------------------------------------------------------------
/// WARNING: This functionality must not be used in production code. it's only allowed to use this for debugging purposes and needs to be
/// removed/deactivated before submitting.
/// Windows: Please note that intel cpus support only 4 hardware breakpoints. If you try to set more than 4 breakpoints an error will be returned.
///   A good praxis is to create a Ringbuffer<DebugHardwareBreakPointRef, DebugHardwareBreakPointInterface::MAXHARDWAREBREAKPOINTS> and free the oldest hardware breakpoints before creating new one.
//----------------------------------------------------------------------------------------
class DebugHardwareBreakPointInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DebugHardwareBreakPointInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.debughardwarebreakpoint");

public:
	static const Int MAXHARDWAREBREAKPOINTS = 4;

	//----------------------------------------------------------------------------------------
	/// Sets a hardware breakpoint for all running threads. When the program hit the watched memory a single_step exception will be fired and
	/// the debugger stops at this point where the memory is accessed.
	/// @param[in] type								Trigger type of the breakpoint.
	/// @param[in] size								Number of bytes to be watched starting from watchAddress.
	/// @param[in] watchAddress				Start address of the watched memory.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DebugHardwareBreakPointRef> SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress);

	//----------------------------------------------------------------------------------------
	/// Removes a hardware breakpoint from all threads.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveHardwareBreakpoint();
};

#include "debug_hardwarebreakpoints1.hxx"
#include "debug_hardwarebreakpoints2.hxx"

}

#endif // DEBUG_HARDWAREBREAKPOINTS_H__
