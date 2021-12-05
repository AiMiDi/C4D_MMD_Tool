/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VORONOIFRACTURE_H__
#define LIB_VORONOIFRACTURE_H__

#include "c4d_library.h"
#include "c4d_baseobject.h"

/// @addtogroup group_voronoifracturelibrary VoronoiFracture Library
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// Voronoi Fracture object.
/// @since R18
//----------------------------------------------------------------------------------------
class VoronoiFracture : public BaseObject
{
private:
	VoronoiFracture();
	~VoronoiFracture();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VoronoiFracture object}
	/// @return												@allocReturn{VoronoiFracture object}
	//----------------------------------------------------------------------------------------
	static VoronoiFracture* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{VoronoiFracture objects}
	/// @param[in] fracture						@theToDestruct{VoronoiFracture object}
	//----------------------------------------------------------------------------------------
	static void Free(VoronoiFracture*& fracture);

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns the number of elements in the "Sources" list, including point generators.
	/// @return												The number of elements in the "Sources" list.
	//----------------------------------------------------------------------------------------
	Int32 GetSourcesCount();

	//----------------------------------------------------------------------------------------
	/// Retrieves the object referenced at the given @formatParam{index}.
	/// @note If @formatParam{index} references a point generator that point generator object is returned.
	/// @param[in] index							The index of the source element to access.
	/// @return												The object at the given @formatParam{index} or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseObject* GetSource(const Int32 index);

	//----------------------------------------------------------------------------------------
	/// Retrieves the object referenced in the "Sources" list with the given @formatParam{type}.
	/// @note If multiple objects with the given type exist the first is returned.
	/// @param[in] type								The type of object to access.
	/// @param[in] startIndex					Start search at index.
	/// @param[out] index							The index of the returned object.
	/// @return												The found object.
	//----------------------------------------------------------------------------------------
	BaseObject* GetSourceByType(const Int32 type, const Int32 startIndex = NOTOK, Int32* const index = nullptr);

	//----------------------------------------------------------------------------------------
	/// Removes the source element in the list at the given @formatParam{index}.
	/// @note If the index references a point generator it is also deleted from the internal list.
	/// @param[in] index							The index of the source element to remove.
	/// @return												@trueIfOtherwiseFalse{the element was removed successfully}
	//----------------------------------------------------------------------------------------
	Bool RemoveSource(const Int32 index);

	//----------------------------------------------------------------------------------------
	/// Adds a new point generator.
	/// @param[in] type								The type of point generator, either ::ID_POINTCREATOR_CREATORTYPE_DISTRIBUTION or ::ID_POINTCREATOR_CREATORTYPE_SHADER.
	/// @param[in] shaderType					If a "Shader" generator is created a shader of this type is automatically added to it. Pass ::NOTOK if the parameter should be ignored.
	/// @param[out] index							The index of the newly created point generator.
	/// @return												The created point generator. @theOwnsPointed{Fracture object, object}
	//----------------------------------------------------------------------------------------
	BaseObject* AddPointGenerator(const Int32 type, const Int32 shaderType = NOTOK, Int32* const index = nullptr);

	//----------------------------------------------------------------------------------------
	/// Adds a valid object from the scene to the "Sources" list.
	/// @param[in] object							The object that should be added to the Fracture object's "Sources" list.
	/// @param[out] index							The index of the newly added object.
	/// @return												@trueIfOtherwiseFalse{the object was added successfully}
	//----------------------------------------------------------------------------------------
	Bool AddSceneObject(BaseObject* object, Int32* const index = nullptr);

	//----------------------------------------------------------------------------------------
	/// Clears the "Sources" list and deletes all point generators.
	//----------------------------------------------------------------------------------------
	void ClearSources();

	//----------------------------------------------------------------------------------------
	/// Returns the internal container for the settings of an external source input, like a polygon object as point source.
	/// @since R19
	/// @note Allows to change the settings that control for example the distribution of points in the object and the point count.
	/// @param[in] index							The index of the object in the Sources list.
	/// @return												The container for the source settings if the index fits to an external Source input, otherwise @formatConstant{nullptr}. @theOwnsPointed{VoronoiFracture,BaseContainer}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetSourceSettingsContainerForIndex(const Int32 index);

	//----------------------------------------------------------------------------------------
	/// Returns the internal container for the settings of an external source input, like a polygon object as point source.
	/// @since R19
	/// @note Allows to change the settings that control for example the distribution of points in the object and the point count.
	/// @param[in] object							The external source object in the Sources list. @callerOwnsPointed{BaseObject}
	/// @return												The container for the source settings if the object is in the Sources list, otherwise @formatConstant{nullptr}. @theOwnsPointed{VoronoiFracture,BaseContainer}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetSourceSettingsContainerForObject(BaseObject* object);

	/// @}
};

/// VoronoiFracture library ID.
#define VORONOIFRACTURELIB		1037586

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iVoronoiFracture;

struct VoronoiFractureLibrary : public C4DLibrary
{
	VoronoiFracture*	(*Alloc)();
	void(*Free)				(VoronoiFracture *&p);
	Int32							(iVoronoiFracture::*GetSourcesCount)();
	BaseObject*				(iVoronoiFracture::*GetSource)(const Int32 index);
	BaseObject*				(iVoronoiFracture::*GetSourceByType)(const Int32 type, const Int32 startIndex, Int32* const index);
	Bool							(iVoronoiFracture::*RemoveSource)(const Int32 index);
	BaseObject*				(iVoronoiFracture::*AddPointGenerator)(const Int32 type, const Int32 shaderType, Int32* const index);
	Bool							(iVoronoiFracture::*AddSceneObject)(BaseObject* object, Int32* const index);
	void							(iVoronoiFracture::*ClearSources)();
	BaseContainer*		(iVoronoiFracture::*GetSourceSettingsContainerForIndex)(const Int32 index);
	BaseContainer*		(iVoronoiFracture::*GetSourceSettingsContainerForObject)(BaseObject* object);

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_VORONOIFRACTURE_H__
