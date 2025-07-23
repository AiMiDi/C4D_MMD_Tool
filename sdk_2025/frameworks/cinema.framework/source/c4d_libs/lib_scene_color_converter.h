/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SCENE_COLOR_CONVERTER_H__
#define LIB_SCENE_COLOR_CONVERTER_H__

#ifdef __API_INTERN__
#include "customgui_datetime.h"
#include "ge_string.h"
#else
#include "c4d_library.h"
#include "customgui_datetime.h"
#endif

namespace maxon
{
class OcioConfig;
}

namespace cinema
{

/// @addtogroup group_sceneconverterlibrary Scene Converter
/// @ingroup group_library
/// @{

/// Scene converter library ID.
#define C4D_SCENECONVERTER_LIBRARY_ID		450000274

//----------------------------------------------------------------------------------------
/// Class to convert color spaces in and between scenes.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SceneColorConverter
{
private:
	SceneColorConverter() {}
	~SceneColorConverter() {}

public:
	/// Conversion flags.
	enum class CONVERSION_FLAGS
	{
		NONE			= 0,			// No flags.
		ADD_UNDO	= 1 << 0, // Create an undo step for all changes. This must not be set when the conversion is called from a thread.
		CLASSIC_LINEAR_TO_SRGB = 1 << 1, // The Scene is a classic scene and would have converted Linear to sRGB on color values.
		CLASSIC_SRGB_TO_LINEAR = 1 << 2, // The Scene is a classic scene and would have converted sRGB to Linear on color values.
		FORCE_LINEAR_LIGHTS = 1 << 3, // Forces the conversion from classic or to classic color management to interpret lights to have linear brightness. Otherwise lights will adjust their brightness.
	} MAXON_ENUM_FLAGS_CLASS(CONVERSION_FLAGS);

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{scene converter}
	/// @return												@allocReturn{scene converter}
	//----------------------------------------------------------------------------------------
	static SceneColorConverter *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{scene converter}
	/// @param[in,out] conv						@theToDestruct{scene converter}
	//----------------------------------------------------------------------------------------
	static void Free(SceneColorConverter *&conv);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Initializes the color converter.
	/// @param[in] doc							The document from which the color settings are taken.
	/// @param[in] inputColorSpaceLowName	Name of the new input color space.
	/// @param[in] inputColorSpaceHighName	Name of the new input color space.
	/// @param[in] renderColorSpaceName	Name of the new input color space.
	/// @param[in] flags						Conversion flags.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Init(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName,
		CONVERSION_FLAGS flags = CONVERSION_FLAGS::ADD_UNDO);

	//----------------------------------------------------------------------------------------
	/// Initializes the color converter.
	/// @param[in] config						The ocio to be used for conversion.
	/// @param[in] inputColorSpaceLowName	Name of the new input color space.
	/// @param[in] inputColorSpaceHighName	Name of the new input color space.
	/// @param[in] renderColorSpaceName	Name of the new input color space.
	/// @param[in] flags						Conversion flags.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Init(const maxon::OcioConfig& config, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName,
		CONVERSION_FLAGS flags = CONVERSION_FLAGS::ADD_UNDO);

	//----------------------------------------------------------------------------------------
	/// Converts the colors of a single object.
	/// @param[in] doc							The document from which the color settings are taken. This must be the same that was used to initialize this class.
	/// @param[in] op								Object to convert.
	/// @param[out] processedObjects	A HashSet that will contain all the converted objects when the function returns.
	/// @return											true, if the object was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertObject(BaseDocument* doc, BaseList2D* op, maxon::HashSet<BaseList2D*>& processedObjects);

	//----------------------------------------------------------------------------------------
	/// Converts the colors of multiple objects
	/// @param[in] doc							The document from which the color settings are taken. This must be the same that was used to initialize this class.
	/// @param[in] objects					Objects to convert.
	/// @param[out] processedObjects	A HashSet that will contain all the converted objects when the function returns.
	/// @return											true, if at least one object was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertObjects(BaseDocument* doc, maxon::Block<BaseList2D*> objects, maxon::HashSet<BaseList2D*>& processedObjects);

	//----------------------------------------------------------------------------------------
	/// Converts colors for a single GeData.
	/// @param[in] data							The data object to convert.
	/// @param[in] treatVectorAsColor	Treat vector types as color.
	/// @return											true, if the data was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertData(GeData& data, Bool treatVectorAsColor = false);

	//----------------------------------------------------------------------------------------
	/// Converts the colors of multiple objects with generic delegates handling any application or context specific parts.
	/// @param[in] objects					A list of objects that should be converted.
	/// @param[in] addUndo					A Delegate that processes undo adding calls.
	/// @return											true, if at least one object was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertObjectsGeneric(maxon::Block<BaseList2D*> objects, const maxon::Delegate<void(BaseList2D*)>& addUndo);
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

} // namespace cinema

namespace maxon
{

class CINEWARE_SINGLEINHERITANCE iSceneColorConverter;

} // namespace maxon

namespace cinema
{

struct SceneColorConverterLibrary : public C4DLibrary
{
	SceneColorConverter*	(*Alloc)();
	void									(*Free)(SceneColorConverter*& dtp);

	maxon::Result<void>		(maxon::iSceneColorConverter::*Init)(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertObject)(BaseDocument* doc, BaseList2D* op, maxon::HashSet<BaseList2D*>& procesedObjects);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertObjects)(BaseDocument* doc, maxon::Block<BaseList2D*> objects, maxon::HashSet<BaseList2D*>& procesedObjects);
	maxon::Result<void>		(maxon::iSceneColorConverter::*Init2)(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName, SceneColorConverter::CONVERSION_FLAGS flags);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertData)(GeData& data, Bool treatVectorAsColor);
	maxon::Result<void>		(maxon::iSceneColorConverter::*Init3)(const maxon::OcioConfig& config, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName, SceneColorConverter::CONVERSION_FLAGS flags);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertObjects2)(maxon::Block<BaseList2D*> objects, const maxon::Delegate<void(BaseList2D*)>& addUndo);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_SCENE_COLOR_CONVERTER_H__
