/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_LODOBJECT_H__
#define LIB_LODOBJECT_H__

#include "c4d_library.h"
#include "lib_description.h"

#ifdef __API_INTERN__
#include "pluginobject.h"

#else
#include "c4d_baseobject.h"
#endif


/// @addtogroup group_lodobjectlibrary LOD Object
/// @ingroup group_library
/// @since R19
/// @{

/// LodObject library ID. @since R19
#define ID_LODOBJECT_LIB 431000179


//----------------------------------------------------------------------------------------
/// Represents the LOD object.
/// @since R19
//----------------------------------------------------------------------------------------
class LodObject : public BaseObject
{
	INSTANCEOF(LodObject, BaseObject)

#ifndef __API_INTERN__
private:
	LodObject();
	~LodObject();
#endif

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{LodObject}
	/// @return												@allocReturn{LodObject}
	//----------------------------------------------------------------------------------------
	static LodObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{LodObjects}
	/// @param[in] op									@theToDestruct{LodObject}
	//----------------------------------------------------------------------------------------
	static void Free(LodObject*& op);

	/// @}

	/// @name Get Dynamic DescID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the hide control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetShowControlDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the object list for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetManualModeObjectListDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the simplify mode for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetSimplifyModeDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the decimation strength for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDecimateStrengthDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the per object control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetPerObjectControlDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the NullObject Display control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetNullDisplayDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the NullObject Radius control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetNullRadiusDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID of the NullObject Aspect Ratio control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetNullAspectRatioDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the NullObject Orientation control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetNullOrientationDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the Display Style Mode control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDisplayStModeDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the Display Shading Mode control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDisplayShModeDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the Display Backface Culling control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDisplayBFCDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the Display Texture control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDisplayTexDescID(Int32 level, DescID& resultId) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the dynamic DescID for the Display Extended OGL control for the passed LOD @formatParam{level}.
	/// @param[in] level							The LOD level.
	/// @param[out] resultId					The resulting DescID, if possible (mode and criteria are compatible with the requested parameter).
	/// @return												@trueIfOtherwiseFalse{DescID calculation successful}
	//----------------------------------------------------------------------------------------
	Bool GetDisplayEOGLDescID(Int32 level, DescID& resultId) const ;

	/// @}

	/// @name Level/Cache
	/// @{

	//----------------------------------------------------------------------------------------
	/// Queries the current LOD level.
	/// @return												The current LOD level index, or ::NOTOK in error case.
	//----------------------------------------------------------------------------------------
	Int32 GetCurrentLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the current number of LOD levels.
	/// @return												The current LOD level count, or ::NOTOK in error case.
	//----------------------------------------------------------------------------------------
	Int32 GetLevelCount() const;

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Int32 GetCacheCount() const;
	
	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseObject* GetCacheObject(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Queries the dirty checksum for the level switch. Every time the level changes, the counter is increased.
	/// @note The LOD object internally creates a cache to speedup the switch between different levels.
	/// @return												The LOD level dirty count.
	//----------------------------------------------------------------------------------------
	UInt32 GetLevelDirty() const;

	//----------------------------------------------------------------------------------------
	/// Queries the dirty checksum for the cache creation. Every time the cache is rebuilt, the counter is increased.
	/// @note The LOD object internally creates a cache to speedup the switch between different levels.
	/// @return												The LOD cache dirty count.
	//----------------------------------------------------------------------------------------
	UInt32 GetCacheDirty() const;

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iLodObject;

struct LodObjectLibrary : public C4DLibrary
{
	LodObject*	(*Alloc)																				();
	void				(*Free)																					(LodObject *&p);
	Bool 				(iLodObject::*GetShowControlDescID) 						(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetManualModeObjectListDescID) 		(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetSimplifyModeDescID) 						(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetDecimateStrengthDescID) 				(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetPerObjectControlDescID) 				(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetNullDisplayDescID) 						(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetNullRadiusDescID) 							(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetNullAspectRatioDescID) 				(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetNullOrientationDescID) 				(Int32 level, DescID& resultId) const;
	Bool 				(iLodObject::*GetDisplayStModeDescID)						(Int32 level, DescID& resultId) const;
	Bool				(iLodObject::*GetDisplayShModeDescID)						(Int32 level, DescID& resultId) const;
	Bool				(iLodObject::*GetDisplayBFCDescID)							(Int32 level, DescID& resultId) const;
	Bool				(iLodObject::*GetDisplayTexDescID)							(Int32 level, DescID& resultId) const;
	Bool				(iLodObject::*GetDisplayEOGLDescID)							(Int32 level, DescID& resultId) const;

	Int32 			(iLodObject::*GetCurrentLevel) 									() const;
	Int32 			(iLodObject::*GetLevelCount)										() const;

	Int32				(iLodObject::*GetCacheCount)										() const;
	BaseObject*	(iLodObject::*GetCacheObject)										(Int32 index) const;

	UInt32			(iLodObject::*GetLevelDirty)										() const;
	UInt32			(iLodObject::*GetCacheDirty)										() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_LODOBJECT_H__
