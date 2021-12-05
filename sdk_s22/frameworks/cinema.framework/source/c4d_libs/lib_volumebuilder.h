/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VOLUMEBUILDER_H__
#define LIB_VOLUMEBUILDER_H__

#include "c4d_library.h"
#ifdef __API_INTERN__
#include "baseobject.h"
#else
#include "c4d_baseobject.h"
#endif

#ifdef __API_INTERN__
#include "hntag.h"
#endif

enum class MIXVECTORTYPE
{
	NONE = 0,
	NORMAL = 1,
	ADD = 2,
	SUBTRACT = 3,
	CROSS = 4
};

/// @addtogroup group_volumeobjectlibrary VolumeObject
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// The Volume object class of type @ref Ovolume.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class VolumeBuilder : public BaseObject
{
private:
	VolumeBuilder();
	~VolumeBuilder();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VolumeObject object}
	/// @return												@allocReturn{VolumeObject object}
	//----------------------------------------------------------------------------------------
	static VolumeBuilder* Alloc() { return (VolumeBuilder*)BaseList2D::Alloc(1039859); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{VolumeObject objects}
	/// @param[in] p									@theToDestruct{VolumeObject object}
	//----------------------------------------------------------------------------------------
	static void Free(VolumeBuilder*& p)	{ BaseList2D::Free((BaseList2D*&)p); }

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns if an object index in the Object list is a child of the generator.
	/// @note Because the list is a tree, the index depends on the position shown in the UI. This means children are iterated first.
	/// @param[in] index							The index of the list object to check.
	/// @return												True if the input object is a child. False otherwise.
	//----------------------------------------------------------------------------------------
	Bool InputObjectIsChild(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of elements in the "Objects" list containing folders.
	/// @return												The number of elements in the "Objects" list.
	//----------------------------------------------------------------------------------------
	Int32 GetListEntryCount();

	//----------------------------------------------------------------------------------------
	/// Returns the number of objects in the "Objects" list.
	/// @param[in] countDouble				If true the objects that are multiple times in the list will be counted multiple times.
	/// @return												The number of objects in the "Objects" list.
	//----------------------------------------------------------------------------------------
	Int32 GetInputObjectCount(Bool countDouble);

	//----------------------------------------------------------------------------------------
	/// Retrieves the object referenced at the given @formatParam{index}.
	/// @note Because the list is a tree, the index depends on the position shown in the UI. This means children are iterated first.
	/// @param[in] index							The index of the object to access.
	/// @return												The object at the given @formatParam{index} or @formatConstant{nullptr} if folder.
	//----------------------------------------------------------------------------------------
	BaseObject* GetInputObject(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the object referenced in the "Sources" list with the given @formatParam{type}.
	/// @note If multiple objects with the given type exist the first is returned.
	/// @param[in] type								The type of object to access.
	/// @param[in] startIndex					Start search at index.
	/// @param[out] index							The index of the returned object.
	/// @return												The object at the given @formatParam{index} or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseObject* GetInputObjectByType(Int32 type, Int32 startIndex, Int32& index);

	//----------------------------------------------------------------------------------------
	/// Adds a valid object from the scene to the "Objects" list.
	/// @param[in] object							The object that should be added to the "Objects" list.
	/// @param[in] index							The index the object should be added to.
	/// @param[in] enabled						The enabled state of the added object.
	/// @param[in] boolMode						The bool mode of the added object.
	/// @param[in] mixMode						The mix mode of the added object.
	/// @return												@trueIfOtherwiseFalse{the object was added successfully}
	//----------------------------------------------------------------------------------------
	Bool AddSceneObject(BaseObject* object, Int32 index, Bool enabled, BOOLTYPE boolMode, MIXTYPE mixMode);

	//----------------------------------------------------------------------------------------
	/// Removes the object in the list at the given @formatParam{index}.
	/// @note Because the list is a tree, the index depends on the position shown in the UI. This means children are iterated first.
	/// @note If the object is a child of the VolumeBuilder, it will be automatically readded to the list. Removing the object from the hierarchy would prevent that.
	/// @param[in] index							The index of the object to remove.
	/// @return												@trueIfOtherwiseFalse{the object was removed successfully}
	//----------------------------------------------------------------------------------------
	Bool RemoveObject(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Clears the "Objects" list.
	//----------------------------------------------------------------------------------------
	void ClearInputObjects();

	//----------------------------------------------------------------------------------------
	/// Returns the internal container for the settings of an object input.
	/// @note Because the list is a tree, the index depends on the position shown in the UI. This means children are iterated first.
	/// @note Allows to change the settings that control the specific conversion of that object.
	/// @param[in] index							The index of the object in the "Objects" list.
	/// @return												The container for the settings if the index is in the list, otherwise @formatConstant{nullptr}. Also @formatConstant{nullptr} if folder or filter. @theOwnsPointed{VolumeBuilder,BaseContainer}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetSettingsContainerForIndex(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Returns the internal container for the settings of an object input.
	/// @note Allows to change the settings that control the specific conversion of that object.
	/// @param[in] object							The object in the "Objects" list.
	/// @return												The container for the settings if the object is in the "Objects" list, otherwise @formatConstant{nullptr}. Also @formatConstant{nullptr} if folder or filter. @theOwnsPointed{VolumeBuilder,BaseContainer}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetSettingsContainerForObject(BaseObject* object) const;

	//----------------------------------------------------------------------------------------
	/// Sets the bool mode for the index.
	/// @param[in] index							The index of the object to set the bool mode for.
	/// @param[in] mode								The bool mode to set.
	//----------------------------------------------------------------------------------------
	void SetBoolMode(Int32 index, BOOLTYPE mode);

	//----------------------------------------------------------------------------------------
	/// Gets the bool mode for the index.
	/// @param[in] index							The index of the object to get the bool mode for.
	/// @return												The bool mode for the object at the given @formatParam{index}.
	//----------------------------------------------------------------------------------------
	BOOLTYPE GetBoolMode(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets the mix mode for the index.
	/// @param[in] index							The index of the object to set the mix mode for.
	/// @param[in] mode								The mix mode to set.
	//----------------------------------------------------------------------------------------
	void SetMixMode(Int32 index, MIXTYPE mode);

	//----------------------------------------------------------------------------------------
	/// Gets the mix mode for the index.
	/// @param[in] index							The index of the object to get the mix mode for.
	/// @return												The mix mode for the object at the given @formatParam{index}.
	//----------------------------------------------------------------------------------------
	MIXTYPE GetMixMode(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets the enabled state for the index.
	/// @param[in] index							The index of the object to set the enabled state for.
	/// @param[in] enable							The enabled state to set.
	//----------------------------------------------------------------------------------------
	void SetEnable(Int32 index, Bool enable);

	//----------------------------------------------------------------------------------------
	/// Gets the enabled state for the index.
	/// @param[in] index							The index of the object to get the enabled state for.
	/// @return												True if the object at the given @formatParam{index} is enabled, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool GetEnable(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets the selection state for the index.
	/// @param[in] index							The index of the object to set the selection state for.
	/// @param[in] select							The selection state to set.
	//----------------------------------------------------------------------------------------
	void SetSelected(Int32 index, Bool select);

	//----------------------------------------------------------------------------------------
	/// Gets the selection state for the index.
	/// @param[in] index							The index of the object to get the selection state for.
	/// @return												True if the object at the given @formatParam{index} is selected, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool GetSelected(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets the mix vector mode for the index.
	/// @param[in] index							The index of the object to set the mix vector mode for.
	/// @param[in] mode								The mix vector mode to set.
	//----------------------------------------------------------------------------------------
	void SetMixVectorMode(Int32 index, MIXVECTORTYPE mode);

	//----------------------------------------------------------------------------------------
	/// Gets the mix vector mode for the index.
	/// @param[in] index							The index of the object to get the mix vector mode for.
	/// @return												The mix vector mode for the object at the given @formatParam{index}.
	//----------------------------------------------------------------------------------------
	MIXVECTORTYPE GetMixVectorMode(Int32 index) const;
	/// @}
};

/// Volume Builder library ID.
#define LIBRARY_VOLUMEBUILDER 1040366

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iVolumeBuilder;

struct VolumeBuilderLib : public C4DLibrary
{
	Bool									(iVolumeBuilder::*InputObjectIsChild)(Int32 index);
	Int32									(iVolumeBuilder::*GetInputObjectCount)(Bool countDouble);
	BaseObject*						(iVolumeBuilder::*GetInputObject)(Int32 index);
	BaseObject*						(iVolumeBuilder::*GetInputObjectByType)(Int32 type, Int32 startIndex, Int32& index);
	Bool									(iVolumeBuilder::*AddSceneObject)(BaseObject* object, Int32 index, Bool enabled , BOOLTYPE boolMode, MIXTYPE mixMode);
	Bool									(iVolumeBuilder::*RemoveObject)(Int32 index);
	void									(iVolumeBuilder::*ClearInputObjects)();
	BaseContainer*				(iVolumeBuilder::*GetSettingsContainerForIndex)(Int32 index);
	BaseContainer*				(iVolumeBuilder::*GetSettingsContainerForObject)(BaseObject* object);
	void									(iVolumeBuilder::*SetBoolMode)(Int32 index, BOOLTYPE mode);
	BOOLTYPE							(iVolumeBuilder::*GetBoolMode)(Int32 index);
	void									(iVolumeBuilder::*SetMixMode)(Int32 index, MIXTYPE mode);
	MIXTYPE								(iVolumeBuilder::*GetMixMode)(Int32 index);
	void									(iVolumeBuilder::*SetEnable)(Int index, Bool enable);
	Bool									(iVolumeBuilder::*GetEnable)(Int index);
	void									(iVolumeBuilder::*SetSelected)(Int index, Bool select);
	Bool									(iVolumeBuilder::*GetSelected)(Int index);
	Int32									(iVolumeBuilder::*GetListEntryCount)();
	void									(iVolumeBuilder::*SetMixVectorMode)(Int32 index, MIXVECTORTYPE mode);
	MIXVECTORTYPE					(iVolumeBuilder::*GetMixVectorMode)(Int32 index);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_VOLUMEBUILDER_H__
