#ifndef COMMANDGETSTATEDELEGATE_H__
#define COMMANDGETSTATEDELEGATE_H__

#include "maxon/delegate.h"
#include "maxon/datatype.h"
#include "maxon/utilities/numtostring.h"

namespace cinema
{

class BaseDocument;

} // namespace cinema

namespace maxon
{
using CommandGetStateDelegate = Delegate<Int32(cinema::BaseDocument*)>;
MAXON_DATATYPE(CommandGetStateDelegate, "net.maxon.hybrid.datatype.commandgetstate");
MAXON_REGISTRY(CommandGetStateDelegate, CommandGetStateDelegates, "net.maxon.hybrid.command.getstates");

#include "commandgetstatedelegate1.hxx"
#include "commandgetstatedelegate2.hxx"

} // namespace maxon

#endif	// COMMANDGETSTATEDELEGATE_H__
