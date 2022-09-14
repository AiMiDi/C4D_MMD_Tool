#ifndef ICONPROVIDER_H__
#define ICONPROVIDER_H__

#include "maxon/url.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// An icon provider is queried to return a Url of an icon file (png or svg) for a given CString identifier.
/// The identifier can stem e.g. from the NODE::BASE::ICON attribute of a node resource.
/// To resolve such an identifier to a Url, all icon providers registered at the IconProviders registry
/// are queried, and the first one which returns a non-null Url will be used.
//----------------------------------------------------------------------------------------
using IconProvider = Delegate<Result<Url>(const CString&)>;

//----------------------------------------------------------------------------------------
/// Registry for IconProvider, see there. You have to register your own provider if you want
/// to use own icons with the IconProvider mechanism.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(IconProvider, IconProviders, "net.maxon.registry.iconproviders");

}

#endif // ICONPROVIDER_H__
