#ifndef ICONPROVIDER_H__
#define ICONPROVIDER_H__

#include "maxon/url.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// An icon provider is queried to return a Url of an icon file (png or svg) for a given CString identifier.
/// The identifier can stem e.g. from the NODE::BASE::ICON attribute of a node resource.
/// To resolve such an identifier to a Url, all icon providers registered at the IconProviders registry
/// are queried by GetUrlFromIconProviders(), and the first one which returns a non-null Url will be used.
//----------------------------------------------------------------------------------------
using IconProvider = Delegate<Result<Url>(const CString&)>;

//----------------------------------------------------------------------------------------
/// Registry for IconProvider, see there. You have to register your own provider if you want
/// to use own icons with the IconProvider mechanism.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(IconProvider, IconProviders, "net.maxon.registry.iconproviders");


inline Result<Url> GetUrlFromIconProviders(const CString& iconId)
{
	iferr_scope;
	if (iconId.IsPopulated())
	{
		for (const IconProvider& ip : IconProviders::GetEntries())
		{
			Url u = ip(iconId) iferr_return;
			if (u.IsPopulated())
			{
				return u;
			}
		}
	}
	return Url();
}

}

#endif // ICONPROVIDER_H__
