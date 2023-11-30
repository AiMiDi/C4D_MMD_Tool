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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

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
	/// Converts the colors of a single object. 
	/// @param[in] doc							The document from which the color settings are taken. This must be the same that was used to initialize this class.
	/// @param[in] op								Object to convert.
	/// @param[out] procesedObjects	A HashSet that will contain all the converted objects when the function returns.
	/// @return											true, if the object was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertObject(BaseDocument* doc, BaseList2D* op, maxon::HashSet<BaseList2D*>& procesedObjects);

	//----------------------------------------------------------------------------------------
	/// Converts the colors of multiple objects 
	/// @param[in] doc							The document from which the color settings are taken. This must be the same that was used to initialize this class.
	/// @param[in] objects					Objects to convert.
	/// @param[out] procesedObjects	A HashSet that will contain all the converted objects when the function returns.
	/// @return											true, if at least one object was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertObjects(BaseDocument* doc, maxon::Block<BaseList2D*> objects, maxon::HashSet<BaseList2D*>& procesedObjects);

	//----------------------------------------------------------------------------------------
	/// Converts colors for a single GeData.
	/// @param[in] data							The data object to convert.
	/// @param[in] treatVectorAsColor	Treat vector types as color.
	/// @return											true, if the data was converted, false otherwise.
	//----------------------------------------------------------------------------------------
	maxon::Result<Bool> ConvertData(GeData& data, Bool treatVectorAsColor = false);
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

namespace maxon
{

class CINEWARE_SINGLEINHERITANCE iSceneColorConverter;

} // namespace maxon

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

struct SceneColorConverterLibrary : public C4DLibrary
{
	SceneColorConverter*	(*Alloc)();
	void									(*Free)(SceneColorConverter*& dtp);

	maxon::Result<void>		(maxon::iSceneColorConverter::*Init)(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertObject)(BaseDocument* doc, BaseList2D* op, maxon::HashSet<BaseList2D*>& procesedObjects);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertObjects)(BaseDocument* doc, maxon::Block<BaseList2D*> objects, maxon::HashSet<BaseList2D*>& procesedObjects);
	maxon::Result<void>		(maxon::iSceneColorConverter::*Init2)(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName, SceneColorConverter::CONVERSION_FLAGS flags);
	maxon::Result<Bool>		(maxon::iSceneColorConverter::*ConvertData)(GeData& data, Bool treatVectorAsColor);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // LIB_SCENE_COLOR_CONVERTER_H__
