#ifndef CREATEDEFAULTMATERIALDELEGATE_H__
#define CREATEDEFAULTMATERIALDELEGATE_H__

#include "maxon/delegate.h"
#include "maxon/numtostring.h"

class BaseDocument;
class BaseMaterial;

namespace maxon
{
using CreateDefaultMaterialDelegate = Delegate<::BaseMaterial*(::BaseDocument*)>;
MAXON_DATATYPE(CreateDefaultMaterialDelegate, "net.maxon.hybrid.datatype.createdefaultmaterialdelegate");
MAXON_REGISTRY(CreateDefaultMaterialDelegate, CreateDefaultMaterialDelegates, "net.maxon.hybrid.command.createdefaultmaterials");

#include "createdefaultmaterialdelegate1.hxx"
#include "createdefaultmaterialdelegate2.hxx"
}

#endif	// CREATEDEFAULTMATERIALDELEGATE_H__
