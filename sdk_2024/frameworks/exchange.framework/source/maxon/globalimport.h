#ifndef GLOBALIMPORT_H__
#define GLOBALIMPORT_H__

#include "maxon/fid.h"
#include "maxon/vector4d.h"
#include "materialparameter.h"

class BaseDocument;
class BaseMaterial;
class BaseObject;
class DescID;
class Description;
class GeListNode;

namespace maxon
{
//----------------------------------------------------------------------------------------
/// GlobalImport provides some functionality to handle and get global import settings
//----------------------------------------------------------------------------------------
class GlobalImportInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GlobalImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.exchange.interface.globalimport");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;

public:

	//----------------------------------------------------------------------------------------
	/// Fills a dropdown list and an array with all available node spaces.
	/// The selected entry will be the target read out of the world preferences.
  /// @param[in] description				The description containing the cycle gadget to be filled.
	/// @param[in] parameterId				The ID of the dropdown gadget.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FillDropdown(Description& description, const DescID& parameterId);

	//----------------------------------------------------------------------------------------
	/// Returns the target node space based on the global import settings.
	/// @return												Id of the target node space.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD maxon::Id GetTargetNodeSpace();

	//----------------------------------------------------------------------------------------
	/// Returns the (currently) default node space of Cinema 4D.
	/// @return												Id of the default node space.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD maxon::Id GetDefaultNodeSpace();
};


//----------------------------------------------------------------------------------------
/// GlobalUtils provides some helper functionality to react to global import settings
//----------------------------------------------------------------------------------------
class GlobalUtilsInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GlobalUtilsInterface, MAXON_REFERENCE_NORMAL, "net.maxon.exchange.interface.globalutils");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;

public:
	//-------------------------------------------------------------------------------------------------
	/// @brief Converts passed object to Redshift Objects.
	/// @param[in] objList                         The list of objects to convert.
	/// @return                                    The converted list of objects.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertObjects(BaseArray<BaseObject*>& objList, const Delegate<Result<void>(BaseObject*, BaseObject*)>& customOperation = nullptr);

	//-------------------------------------------------------------------------------------------------
	/// @brief Creates a generic material based on basic material data and node space.
	/// @param[in] materialData                   The properties of the material.
	/// @param[in] nodeSpace                      The node space ID the material is created for.
	/// @param[in] baseDocument                   The active document the import is happening. Note: The material will not be inserted into the document!
	/// @return                                   The pointer to the created material.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseMaterial*> CreateGenericMaterial(const material::MaterialExchangeData& materialData, Id nodeSpace, BaseDocument& baseDocument);

	//-------------------------------------------------------------------------------------------------
	/// @brief Convert an ImageTextureRef to an sRGB color profile.
	/// @param[in, out] textureRef 								The texture to transform the color profile.
	/// @return                                   The error if any.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertTextureTosRGB(ImageTextureRef& textureRef);
};

// global definition to be used across all importers
MAXON_ATTRIBUTE(Id, REDSHIFT_NODESPACE, "com.redshift3d.redshift4c4d.class.nodespace");

#include "globalimport1.hxx"

MAXON_DECLARATION(Class<GlobalImportRef>, GlobalImport, "net.maxon.exchange.class.globalimport");
MAXON_DECLARATION(Class<GlobalUtilsRef>, GlobalUtils, "net.maxon.exchange.class.globalutils");

#include "globalimport2.hxx"

} // namespace maxon

#endif // GLOBALIMPORT_H__
