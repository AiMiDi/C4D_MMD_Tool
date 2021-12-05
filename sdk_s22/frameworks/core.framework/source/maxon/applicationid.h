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

	static const LiteralId UNKNOWN{"net.maxon.application.unknown"};
	static const LiteralId LITE{"net.maxon.application.lite"};
	static const LiteralId CINEBENCH{"net.maxon.application.cinebench"};
	static const LiteralId UPDATER{"net.maxon.application.updater"};
	static const LiteralId TEAMRENDER_SERVER{"net.maxon.application.trserver"};
	static const LiteralId TEAMRENDER_CLIENT{"net.maxon.application.trclient"};
	static const LiteralId CINEMA4D{"net.maxon.application.cinema4d"};
	static const LiteralId COMMANDLINE{"net.maxon.application.commandline"};
	static const LiteralId CINEWARE{"net.maxon.application.cineware"};
	static const LiteralId PYTHON{"net.maxon.application.python"};
	static const LiteralId PYTHON3{"net.maxon.application.python3"};
	static const LiteralId CINEWARE_ENGINE{"net.maxon.application.cineware.engine"};
	static const LiteralId KERNEL{"net.maxon.application.kernel"};
}


} // namespace maxon



#endif // APPLICATIONID_H__
