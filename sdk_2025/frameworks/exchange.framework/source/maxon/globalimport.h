#ifndef GLOBALIMPORT_H__
#define GLOBALIMPORT_H__

#include "maxon/fid.h"
#include "maxon/vector4d.h"
#include "materialparameter.h"

namespace cinema
{

class BaseDocument;
class BaseMaterial;
class BaseObject;
class DescID;
class Description;
class GeListNode;

} // namespace cinema


namespace maxon
{
namespace exchange
{
MAXON_ATTRIBUTE(Id, CONVERTION_DIRECTION, "com.maxon.exchange.convertion.convertiondirection",
		RESOURCE_DEFINE(ENUM_RENDERSPACE_TO_SRGBLINEAR, LiteralId("renderspacetosrgblinear"))
		RESOURCE_DEFINE(ENUM_SRGBLINEAR_TO_RENDERSPACE, LiteralId("srgblineartorenderspace")));
}


//----------------------------------------------------------------------------------------
/// GlobalImport provides some functionality to handle and get global import settings
//----------------------------------------------------------------------------------------
class GlobalImportInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GlobalImportInterface, MAXON_REFERENCE_STATIC, "net.maxon.exchange.interface.globalimport");

public:

	//----------------------------------------------------------------------------------------
	/// Fills a dropdown list and an array with all available node spaces.
	/// The selected entry will be the target read out of the world preferences.
  /// @param[in] description				The description containing the cycle gadget to be filled.
	/// @param[in] parameterId				The ID of the dropdown gadget.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FillDropdown(cinema::Description& description, const cinema::DescID& parameterId);

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
class GlobalUtilsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GlobalUtilsInterface, MAXON_REFERENCE_STATIC, "net.maxon.exchange.interface.globalutils");

public:
	//-------------------------------------------------------------------------------------------------
	/// @brief Converts passed object to Redshift Objects.
	/// @param[in] objList                         The list of objects to convert.
	/// @return                                    The converted list of objects.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertObjects(BaseArray<cinema::BaseObject*>& objList, const Delegate<Result<void>(cinema::BaseObject*, cinema::BaseObject*)>& customOperation = nullptr);

	//-------------------------------------------------------------------------------------------------
	/// @brief Creates a generic material based on basic material data and node space.
	/// @param[in] materialData                   The properties of the material.
	/// @param[in] nodeSpace                      The node space ID the material is created for.
	/// @param[in] baseDocument                   The active document the import is happening. Note: The material will not be inserted into the document!
	/// @return                                   The pointer to the created material.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<cinema::BaseMaterial*> CreateGenericMaterial(const material::MaterialExchangeData& materialData, Id nodeSpace, cinema::BaseDocument& baseDocument);

	//-------------------------------------------------------------------------------------------------
	/// @brief Convert an ImageTextureRef to an sRGB color profile.
	/// @param[in, out] textureRef 								The texture to transform the color profile.
	/// @return                                   The error if any.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertTextureTosRGB(ImageTextureRef& textureRef);

	//-------------------------------------------------------------------------------------------------
	/// @brief Convert a temperature value to a RGB color value.
	/// @param[in] fTemperature 									The temperature value to convert.
	/// @param[in] fReference 										The reference temperature usually 6500
	/// @param[in] bNormalize 										Normalize the color, so values are between 0 and 1.
	/// @return																		The corresponding color value.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Color ComputeColorTemperatureRGB(Float fTemperature, Bool bNormalize, Float fReference = 6500);

	//-------------------------------------------------------------------------------------------------
	/// @brief Retrieve base intensity from the redshift light object. Base intensity is a raw (unnormalized, no scaling factor, in metric spatial system) intensity that is used for "Image" units in redshift lights.
	/// @param[in] object													redshift light object
	/// @return																		base intensity calculated from the given redshift light object
	//-----------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float> RSLightGetBaseIntensity(cinema::BaseObject* object);

	//-------------------------------------------------------------------------------------------------
	/// @brief Convert given redshift light intensity to the target units
	/// @param[in, out] object										redshift light object to perform conversion on
	/// @param[in] targetUnitId										id of the target light units (defined in orslight.h with prefix REDSHIFT_LIGHT_UNITSTYPE_)
	/// @return																		The error if any
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RSLightConvertToUnit(cinema::BaseObject* object, Int32 targetUnitId);

	//-------------------------------------------------------------------------------------------------
	/// @brief Creates a random color with a random hue but consistent saturation and value (lightness).
	/// @param[in] seed														Seed for random number generator
	/// @return																		Random color
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Color GetRandomColor(Int32 seed);

	//-------------------------------------------------------------------------------------------------
	/// @brief Initializes the global export color conversion handler that is used by ConvertColorWithGlobalHandler.
	/// The color conversion will be initialized to convert from current active document render color space to the chosen export color space.
	/// In case the source document is in legacy color management, the low source color space will be sRGB non linear and the high color space sRGB linear.
	/// Colors in the node editor use the high color space and need to pass low = false when ConvertColorWithGlobalHandler is called.
	/// @param[in] doc													Optional document to read the source settings from. Active document is taken otherwise.
	/// @return																	OK on success
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> InitializeGlobalColorConversionHandler(const cinema::BaseDocument* doc = nullptr);

	//-------------------------------------------------------------------------------------------------
	/// @brief Clears the global color conversion handler.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD void ClearGlobalColorConversionHandler();

	//-------------------------------------------------------------------------------------------------
	/// @brief Converts a color from document color space to export color space.
	/// InitializeGlobalColorConversionHandler needs to be called before using this.
	/// @param[in,out] color											A reference to the color to convert.
	/// @param[in] low														If true the low source color space will be used. The high color space otherwise.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD void ConvertColorWithGlobalHandler(Vector& color, Bool low = true);

	//-------------------------------------------------------------------------------------------------
	/// @brief Converts a color from document color space to export color space.
	/// InitializeGlobalColorConversionHandler needs to be called before using this.
	/// @param[in,out] color											A reference to the color to convert.
	/// @param[in] low														If true the low source color space will be used. The high color space otherwise.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD void ConvertColorWithGlobalHandler(Vector32& color, Bool low = true);

	//-------------------------------------------------------------------------------------------------
	/// @brief Converts a scene to the export color space defined in the preferences.
	///	The scene is not allowed to be the active scene! only scene copies should be converted to export space.
	/// @param[in] doc													The Document to convert.
	/// @return																	OK on success
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ConvertSceneToExportSpace(cinema::BaseDocument* doc);


	//-------------------------------------------------------------------------------------------------
	/// @brief Convert a color between the render spaces and sRGB linear. It can be used on both direction
	/// @param[in] doc													The document to retrieve the converter.
	/// @param[in] color												The color to convert.
	/// @param[in] direction										The direction of the conversion.   
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD void ConvertColorRenderSpaceSRGBLinear(cinema::BaseDocument* doc, Color& color, const LiteralId& direction);
	static MAXON_METHOD void ConvertColorRenderSpaceSRGBLinear(cinema::BaseDocument* doc, Color32& color, const LiteralId& direction);
	static MAXON_METHOD void ConvertColorRenderSpaceSRGBLinear(cinema::BaseDocument* doc, ColorA& color, const LiteralId& direction);
	static MAXON_METHOD void ConvertColorRenderSpaceSRGBLinear(cinema::BaseDocument* doc, ColorA32& color, const LiteralId& direction);

	
};

// global definition to be used across all importers
MAXON_ATTRIBUTE(Id, REDSHIFT_NODESPACE, "com.redshift3d.redshift4c4d.class.nodespace");

#include "globalimport1.hxx"
#include "globalimport2.hxx"

} // namespace maxon

#endif // GLOBALIMPORT_H__
