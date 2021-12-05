/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_INSTANCEOBJECT_H__
#define LIB_INSTANCEOBJECT_H__

#include "c4d_library.h"
#include "lib_description.h"

#ifdef __API_INTERN__
#include "pluginobject.h"
#else
#include "c4d_baseobject.h"
#endif

/// @addtogroup group_objectinstancelibrary Object Instance
/// @ingroup group_library
/// @since R20
/// @{

/// InstanceObject library ID. @since R20
#define ID_INSTANCEOBJECT_LIB 431000180
struct InstanceObjectList;

//----------------------------------------------------------------------------------------
/// Class that contains the minimal data to represent one or multiple instances of an object.
/// This InstanceObject has two modes : single-instance mode or multi-instance mode.
/// @since R20
//----------------------------------------------------------------------------------------
class InstanceObject : public BaseObject
{
	INSTANCEOF(InstanceObject, BaseObject)

#ifndef __API_INTERN__
private:
	InstanceObject();
	~InstanceObject();
#endif

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{ObjectInstance object}
	/// @return												@allocReturn{ObjectInstance object}
	//----------------------------------------------------------------------------------------
	static InstanceObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{ObjectInstance objects}
	/// @param[in,out] bl							@theToDestruct{ObjectInstance object}
	//----------------------------------------------------------------------------------------
	static void Free(InstanceObject*& bl);

	/// @}


	/// @name Viewport helper. Internal Use only.
	/// @{
	/// @markPrivate

	//----------------------------------------------------------------------------------------
	/// Update pCurrent data with the given information, added to the list if one is provided.
	/// @param[in] pObj								Object used for the instance.
	/// @param[in] pCurrent						Data structure to fill up.
	/// @param[in,out] pList					Optional List, pCurrent is added to the list if provided.
	/// @param[in] m									Matrix to use for this instance.
	/// @param[in] instanceCRC				Unique pointer used for CRC (used for multi-instance).
	//----------------------------------------------------------------------------------------
	static void UpdateInstanceList(BaseObject* pObj, InstanceObjectList* pCurrent, InstanceObjectList*& pList, const Matrix& m, const void* instanceCRC = nullptr);

	//----------------------------------------------------------------------------------------
	/// Add op and its children as a dependency to the generator.
	/// @param[in] op									BaseObject the generator depends on.
	/// @param[in] generator					Generator to add the dependencies to.
	/// @param[in] hh									Optional HierarchyHelp.
	//----------------------------------------------------------------------------------------
	static void RecurseGenList(BaseObject* op, BaseObject* generator, HierarchyHelp* hh = nullptr);

	//----------------------------------------------------------------------------------------
	/// Update the instance list with the cached instance data.
	/// @param[in,out] pList					Current list to fill if provided. If null, a new list may be returned.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> AddCacheInstanceData(InstanceObjectList*& pList);
	/// @}


	/// @name Multi-instance reference object.
	/// @{
	//----------------------------------------------------------------------------------------
	/// Return the pointer to the BaseObject being instanciated.
	/// Same as accessing the INSTANCEOBJECT_LINK element in the BaseContainer.
	/// @param[in] doc								The current document.
	/// @return												Object being instanciated. Will be null if this instance object is unassigned.
	//----------------------------------------------------------------------------------------
	BaseObject* GetReferenceObject(BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// Set the reference object used for the multiple instances (INSTANCEOBJECT_LINK in BaseContainer).
	/// @param[in] refObj							desired reference object.
	//----------------------------------------------------------------------------------------
	maxon::Result<void>	SetReferenceObject(BaseObject* refObj);
	/// @}

	/// @name Multi-instance matrix and instance count management.
	/// @{
	//----------------------------------------------------------------------------------------
	/// Return whether this InstanceObject is in multi-instance mode.
	/// @return												True if in multi-instance mode.
	//----------------------------------------------------------------------------------------
	Bool	IsMultiInstance() const;

	//----------------------------------------------------------------------------------------
	/// Set matrices for the instance(s). The array size determines the instance count.
	/// @param[in] matrices						Instance matrix array.
	//----------------------------------------------------------------------------------------
	maxon::Result<void>	SetInstanceMatrices(const maxon::BaseArray<Matrix> &matrices);
	
	//----------------------------------------------------------------------------------------
	/// Returns an array of matrices with one element for each instance.
	/// @return												Pointer to the matrix array. Owned by the InstanceObject.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<Matrix>*	GetInstanceMatrices() const;

	//----------------------------------------------------------------------------------------
	/// Return the global matrix of the instance at the specified index.
	/// @param[in] index							Instance index.
	/// @return												Instance matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetInstanceMatrix(UInt index) const;

	//----------------------------------------------------------------------------------------
	/// Set the global matrix of the instance at the specified index. index must be valid, there is no allocation for index out of range.
	/// @param[in] index							Instance index.
	/// @param[in] globalMatrix				Instance matrix.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SetInstanceMatrix(UInt index, const Matrix& globalMatrix);

	//----------------------------------------------------------------------------------------
	/// Return the Matrix dirtyID of the instance at the specified index.
	/// @param[in] index							Instance index.
	/// @return												dirty ID.
	//----------------------------------------------------------------------------------------
	UInt32 GetMatrixDirtyID(UInt index) const;
	
	//----------------------------------------------------------------------------------------
	/// Return the multi-instance count (number of instances and matrices).
	/// @return												Multi-instance count.
	//----------------------------------------------------------------------------------------
	UInt GetInstanceCount() const;
	/// @}

	/// @name Multi-instance color accessors.
	/// @{
	//----------------------------------------------------------------------------------------
	/// Set colors for the instances.
	/// Colors will be clamped between 0 and 1.
	/// @param[in] colors							Array of instance colors.
	//----------------------------------------------------------------------------------------
	maxon::Result<void>	SetInstanceColors(const maxon::BaseArray<maxon::Color64> &colors);

	//----------------------------------------------------------------------------------------
	/// Return an array of instance colors.
	/// If the array is null or empty, the default color is used.
	/// @return												Pointer to the color array. Owned by the InstanceObject.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<maxon::Color64>*	GetInstanceColors() const;

	//----------------------------------------------------------------------------------------
	/// Return the color of the instance at the specified index.
	/// If no custom color is found or the index is invalid, the default color is returned.
	/// @param[in] index							Instance index.
	/// @return												Instance color.
	//----------------------------------------------------------------------------------------
	maxon::Color64	GetInstanceColor(UInt index) const;
	/// @}

	/// @name Multi-instance unique IP accessors.
	/// @{
	//----------------------------------------------------------------------------------------
	/// Set unique IP for the instances.
	/// @param[in] uniqueIPs					Array of instance unique IP.
	//----------------------------------------------------------------------------------------
	maxon::Result<void>	SetInstanceUniqueIPs(const maxon::BaseArray<Int32> &uniqueIPs);
	
	//----------------------------------------------------------------------------------------
	/// Return an array of instance unique IP.
	/// If the array is null or empty, 0 is used.
	/// @return												Pointer to the unique IP array. Owned by the InstanceObject.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<Int32>*	GetInstanceUniqueIPs() const;
	
	//----------------------------------------------------------------------------------------
	/// Return the unique IP of the instance at the specified index.
	/// If no unique IP is found or the index is invalid, 0 is returned.
	/// @param[in] index							Instance index.
	/// @return												Instance unique IP.
	//----------------------------------------------------------------------------------------
	Int32	GetInstanceUniqueIP(UInt index) const;
	/// @}
};

/// Multi-instance structure. @since R20
/// For the multi-instance mode of the InstanceObject, this helper structure is used to
/// extract all instance specific data.
struct MultiInstanceData
{
public:
	//----------------------------------------------------------------------------------------
	/// Clear Stored Data.
	//----------------------------------------------------------------------------------------
	void Clear()
	{
		instancedObject = nullptr;
		instanceMatrices.Reset();
		instanceColors.Reset();
		instanceUniqueIPs.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Extract all instance specific data for the specified InstanceObject.
	/// The InstanceObject must be in mutli-instance mode.
	/// @param[in] obj								Multi-instance object.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> ExtractInfo(InstanceObject* obj)
	{
		iferr_scope;
		Clear();
		if (!obj)
			return maxon::OK;

		if (obj->IsMultiInstance())
		{
			BaseDocument* doc = obj->GetDocument();
			instancedObject = obj->GetReferenceObject(doc);

			// mandatory
			if (obj->GetInstanceMatrices())
			{
				instanceMatrices.CopyFrom(*obj->GetInstanceMatrices()) iferr_return;
			}

			// this is optional
			if (obj->GetInstanceColors())
			{
				instanceColors.CopyFrom(*obj->GetInstanceColors()) iferr_return;
			}

			// this is optional
			if (obj->GetInstanceUniqueIPs())
			{
				instanceUniqueIPs.CopyFrom(*obj->GetInstanceUniqueIPs()) iferr_return;
			}
		}
		return maxon::OK;
	}

public:
	BaseObject* instancedObject = nullptr;	///< Pointer to the Object that is being instantiated. Only valid during object lifetime.
	maxon::BaseArray<Matrix> instanceMatrices; ///< Global matrices, one for each instance.
	maxon::BaseArray<maxon::Color64> instanceColors; ///< Color, one for each instance.
	maxon::BaseArray<Int32> instanceUniqueIPs; ///< Unique IP, one for each instance.
};




/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// Instance structure. This is used for the viewport instance code.
//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct InstanceObjectList
{
	InstanceObjectList* next = nullptr;	///< Next instance structure.
	BaseObject*					op		= nullptr;///< Object used by this instance. Only valid during object lifetime.
	Int32								cnt		= 0;			///< Instance count.
	UInt32							crc		= 0;			///< Instance CRC.
	Matrix							m;							///< Instance global matrix.
};



class iInstanceObject;

struct InstanceObjectLibrary : public C4DLibrary
{
	InstanceObject*									(*Alloc)																();
	void														(*Free)																	(InstanceObject *&p);

	void														(*UpdateInstanceList)										(BaseObject* pObj, InstanceObjectList* pCurrent, InstanceObjectList *&pList, const Matrix &m, const void* instanceCRC);
	void														(*RecurseGenList)												(BaseObject *op, BaseObject *generator, HierarchyHelp* hh);
	maxon::Result<void> 						(iInstanceObject::*AddCacheInstanceData)(InstanceObjectList*& pList);

	BaseObject*											(iInstanceObject::*GetReferenceObject)	(BaseDocument* doc) const;
	maxon::Result<void>							(iInstanceObject::*SetReferenceObject)	(BaseObject* refObj);

	Bool														(iInstanceObject::*IsMultiInstance)			() const;
	UInt 														(iInstanceObject::*GetInstanceCount)		() const;
	const maxon::BaseArray<Matrix>*	(iInstanceObject::*GetInstanceMatrices)	() const;
	maxon::Result<void>							(iInstanceObject::*SetInstanceMatrices)	(const maxon::BaseArray<Matrix>& matrices);
	Matrix													(iInstanceObject::*GetInstanceMatrix)		(UInt index) const;

	maxon::Result<void>											(iInstanceObject::*SetInstanceColors)	(const maxon::BaseArray<maxon::Color64>& colors);
	const maxon::BaseArray<maxon::Color64>*	(iInstanceObject::*GetInstanceColors)	() const;
	maxon::Color64													(iInstanceObject::*GetInstanceColor)	(UInt index) const;

	// Added for R21
	maxon::Result<void> (iInstanceObject::*SetInstanceMatrix)(UInt index, const Matrix& globalMatrix);
	UInt32 							(iInstanceObject::*GetMatrixDirtyID)(UInt index) const;
	maxon::Result<void>							(iInstanceObject::*SetInstanceUniqueIPs)(const maxon::BaseArray<Int32>& uniqueIPs);
	const maxon::BaseArray<Int32>*	(iInstanceObject::*GetInstanceUniqueIPs)() const;
	Int32														(iInstanceObject::*GetInstanceUniqueIP)(UInt index) const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_INSTANCEOBJECT_H__
