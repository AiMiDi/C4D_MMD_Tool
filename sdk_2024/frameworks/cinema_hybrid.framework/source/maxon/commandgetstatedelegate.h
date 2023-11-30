#ifndef COMMANDGETSTATEDELEGATE_H__
#define COMMANDGETSTATEDELEGATE_H__

#include "maxon/delegate.h"
#include "maxon/utilities/numtostring.h"

class BaseDocument;

namespace maxon
{
using CommandGetStateDelegate = Delegate<Int32(::BaseDocument*)>;
MAXON_DATATYPE(CommandGetStateDelegate, "net.maxon.hybrid.datatype.commandgetstate");
MAXON_REGISTRY(CommandGetStateDelegate, CommandGetStateDelegates, "net.maxon.hybrid.command.getstates");

#include "commandgetstatedelegate1.hxx"
#include "commandgetstatedelegate2.hxx"
}

#endif	// COMMANDGETSTATEDELEGATE_H__
