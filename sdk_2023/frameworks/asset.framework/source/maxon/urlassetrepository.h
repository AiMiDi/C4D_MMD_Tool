#ifndef URLASSETREPOSITORY_H__
#define URLASSETREPOSITORY_H__

#include "maxon/assets.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Extends UpdatableAssetRepositoryInterface with a url on disk.
//----------------------------------------------------------------------------------------
class UrlAssetRepositoryInterface : MAXON_INTERFACE_BASES(UpdatableAssetRepositoryInterface)
{
	MAXON_INTERFACE(UrlAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.urlassetrepository");

public:
	//----------------------------------------------------------------------------------------
	/// GetUrl returns the storage url of the asset repository.
	/// @param[in] getOrigin					True to get the original mount path of the repository. False to get the effective url (e.g. this could be a ramdisk:// in case of http connections).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetUrl(Bool getOrigin) const;
};

#include "urlassetrepository1.hxx"

#include "urlassetrepository2.hxx"

}


#endif // URLASSETREPOSITORY_H__
