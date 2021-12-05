#ifndef FLOATINGPOINT_H__
#define FLOATINGPOINT_H__

#include "maxon/string.h"
#include "maxon/iostreams.h"
#include "maxon/datetime.h"


namespace maxon
{

class Misc
{
	MAXON_INTERFACE_NONVIRTUAL(Misc, MAXON_REFERENCE_NONE, "net.maxon.interface.misc");

public:
	//----------------------------------------------------------------------------------------
	/// Activates or deactivates floating point checks (exceptions).
	/// If (on && g_checkFloatZeroDivide) == true checks for division by zero will be active.
	/// If (on && g_checkFloatInvalid) == true checks for invalid floating point numbers will be active.
	/// If (on && g_checkFloatOverflow) == true checks for invalid floating overflows will be active.
	/// Currently under OS X all checks are disabled as the system and OpenGL throw exceptions in too many places.
	/// SetFloatingPointChecks works thread-specific.
	/// THREADSAFE.
	/// @param[in] on									The new state.
	/// @return												The old state.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SetFloatingPointChecks(Bool on);
};

// include auto generated header file here
#include "floatingpoint1.hxx"
// include auto generated header file here
#include "floatingpoint2.hxx"

//----------------------------------------------------------------------------------------
/// Helper class to temporarily deactivate all floating point checks.
/// The checks will be disabled and return to their previous states when the current scope is left (and therefore the class is destructed).
//----------------------------------------------------------------------------------------
class SuppressFloatingPointChecks
{
public:
	SuppressFloatingPointChecks() { oldState = Misc::SetFloatingPointChecks(false); }
	~SuppressFloatingPointChecks() { Misc::SetFloatingPointChecks(oldState); }
private:
	Bool oldState;
};

} // namespace maxon

#endif // FLOATINGPOINT_H__
