#ifndef ASSET_CREATION_ENUMS_H__
#define ASSET_CREATION_ENUMS_H__

#include "maxon/fid.h"
#include "maxon/datadictionary.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// used as parameter in AssetCreationInterface::CreateObjectsOnDrag()
//----------------------------------------------------------------------------------------
enum class ASSETINSERTOBJECTMODE
{
	ASOBJECT,					///< create new assets as an individual object
	ASINSTANCE,				///< if one object of the same object was already dragged into the scene create a instance
	ASRENDERINSTANCE, ///< if one object of the same object was already dragged into the scene create a render instance
	ASXREF,						///< if one object of the same object was already dragged into the scene create a simple xref
} MAXON_ENUM_LIST(ASSETINSERTOBJECTMODE);

namespace APPSETTINGS
{
namespace ASSETS
{
	MAXON_ATTRIBUTE(ASSETINSERTOBJECTMODE, INSERTOBJECTAS, "net.maxon.appsettings.assets.insertobjectas");
	MAXON_ATTRIBUTE(Id, LASTSAVEREPOSITORY, "net.maxon.appsettings.assets.lastsaverepository");
}
}

enum class GENERATESCENEPREVIEWIMAGEFLAGS
{
	NONE = 0,
	ISORIGINALDOCUMENT = (1 << 0),			///< if set the document will be cloned for rendering, otherwise the document will be used and modified directly.
	FRAMESCENE = (1 << 1),							///< frames the scene before rendering
	PREVIEWRENDER = (1 << 2),						///< use the preview renderer instead of the selected render engine
	GEOMETRYONLY = (1 << 3),						///< apply geometry only rendering to the scene (in case of PREVIEWRENDER)
	AUTODETECT_RENDERENGINE = (1 << 4), ///< detect render engine from document
	BAKE_OCIO_VIEW_TRANSFORM = (1 << 5),	///< render in raw render space and bake the OCIO view transform into the preview, so it matches the Picture Viewer render result.
} MAXON_ENUM_FLAGS(GENERATESCENEPREVIEWIMAGEFLAGS);

enum class OPENSAVEASSETDIALOGFLAGS
{
	NONE = 0,
	ALLOW_EDIT_ID = (1 << 0),				 ///< enabled the editfield of the assset id to allow the user editing of the id.
	ALLOW_EDIT_NAME = (1 << 1),			 ///< allows to edit the name of the asset
	SHOW_VERSION = (1 << 2),				 ///< shows the version edit field to let the user enter a version name
	ALLOW_EMPTY_CATEGORY = (1 << 3), ///< set to allow to clear the category (make it blank). otherwise the user needs to choose a category.
	SHOW_MAKE_DEFAULT = (1 << 4),		 ///< enabled the "make as default" checkbox for presets.
	HIDE_AI_BUTTON = (1 << 5),			 ///< hides AI button next to the search bar.
} MAXON_ENUM_FLAGS(OPENSAVEASSETDIALOGFLAGS);

namespace URLFLAGS
{
MAXON_ATTRIBUTE(DataDictionary, SCENE_CREATION_EVENT, "net.maxon.url.scene_creation_event");
MAXON_ATTRIBUTE(DataDictionary, ASSET_BROWSER_USE_EVENT, "net.maxon.url.asset_browser_use_event"); ///< @markDeprecated
}

namespace ASSETMETADATA
{
/// @markPrivate
MAXON_ATTRIBUTE(DataDictionary, ANALYTICS, "net.maxon.assetmetadata.analytics");
}

#include "asset_creation_enums1.hxx"
#include "asset_creation_enums2.hxx"

}

#endif // ASSET_CREATION_ENUMS_H__
