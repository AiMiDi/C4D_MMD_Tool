#ifndef URLASSETREPOSITORY_H__
#define URLASSETREPOSITORY_H__

#include "maxon/assets.h"

namespace maxon
{

class UrlAssetRepositoryInterface : MAXON_INTERFACE_BASES(UpdatableAssetRepositoryInterface)
{
	MAXON_INTERFACE(UrlAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.urlassetrepository");

public:
	MAXON_METHOD Url GetUrl() const;
};

#include "urlassetrepository1.hxx"

#include "urlassetrepository2.hxx"

}


#endif // URLASSETREPOSITORY_H__
