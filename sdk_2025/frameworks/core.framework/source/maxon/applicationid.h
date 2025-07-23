#ifndef APPLICATIONID_H__
#define APPLICATIONID_H__

#include "maxon/apibase.h"

namespace maxon
{

// List of common application Ids as returned by System::GetApplicationId
// Due to the dependency system MAXON_ATTRIBUTE cannot be used here.
namespace APPLICATIONID
{
	// declare IDs

	static constexpr LiteralId UNKNOWN{"net.maxon.application.unknown"};
	static constexpr LiteralId LITE{"net.maxon.application.lite"};
	static constexpr LiteralId CINEBENCH{"net.maxon.application.cinebench"};
	static constexpr LiteralId TEAMRENDER_SERVER{"net.maxon.application.trserver"};
	static constexpr LiteralId TEAMRENDER_CLIENT{"net.maxon.application.trclient"};
	static constexpr LiteralId CINEMA4D{"net.maxon.application.cinema4d"};
	static constexpr LiteralId COMMANDLINE{"net.maxon.application.commandline"};
	static constexpr LiteralId PYTHON{"net.maxon.application.python"};
	static constexpr LiteralId CINEWARE_DLL{"net.maxon.application.cineware_dll"};
	static constexpr LiteralId CINEWARE_STATIC{"net.maxon.application.cineware_static"};
	static constexpr LiteralId KERNEL{"net.maxon.application.kernel"};
	static constexpr LiteralId DRAWPORT_UNITTESTS{ "net.maxon.application.drawport_unittests" };
	static constexpr LiteralId FORGER{"net.maxon.application.forger"};
	static constexpr LiteralId MOVES{"net.maxon.application.moves"};
}


} // namespace maxon



#endif // APPLICATIONID_H__
