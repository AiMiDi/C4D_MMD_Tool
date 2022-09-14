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

	maxon::Result<void> Init(BaseDocument* doc, const maxon::CString& inputColorSpaceLowName, const maxon::CString& inputColorSpaceHighName, const maxon::CString& renderColorSpaceName);
	maxon::Result<Bool> ConvertObject(BaseDocument* doc, BaseList2D* op, maxon::HashSet<BaseList2D*>& procesedObjects);
	maxon::Result<Bool> ConvertObjects(BaseDocument* doc, maxon::Block<BaseList2D*> objects, maxon::HashSet<BaseList2D*>& procesedObjects);
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
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // LIB_SCENE_COLOR_CONVERTER_H__
