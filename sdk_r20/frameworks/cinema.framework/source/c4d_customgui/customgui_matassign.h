/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_MATASSIGN_H__
#define CUSTOMGUI_MATASSIGN_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

class BaseDocument;

/// %Material assignment custom GUI ID.
#define CUSTOMGUI_MATASSIGN						200000026

/// %Material assignment custom data type ID.
#define CUSTOMDATATYPE_MATASSIGN			200000027

/// @addtogroup MATASSIGN_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define MATASSIGN_TAG_ID								1000			///< ::Int32 %Material assign tag ID.
																									///< If the user drags an object into the list a tag of this ID is created. (Default is @ref Ttexture.)
#define MATASSIGN_CONTAINER_ID					1001			///< ::Int32 %Material assign container ID.
																									///< If the user drags an object into the list the tag created gets a link to the object at this ID in its container. (Default is @ref TEXTURETAG_MATERIAL.)
#define MATASSIGN_MATERIAL_ID						1002			///< ::Int32 %Material assign material ID. The list must belong to a material with this type. (Default is @ref Mmaterial.)
/// @}

class MatAssignTable;

//----------------------------------------------------------------------------------------
/// %Material assignment custom data type (@ref CUSTOMDATATYPE_MATASSIGN).
//----------------------------------------------------------------------------------------
class MatAssignData : public CustomDataType
{
private:
	MatAssignData();
	~MatAssignData();
public:
	/// @name Material
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the materials.
	/// @param[in] materials					The materials.
	//----------------------------------------------------------------------------------------
	void SetMaterial(const AtomArray &materials);

	//----------------------------------------------------------------------------------------
	/// Retrieves the materials.
	/// @param[in] doc								The document for the materials. @callerOwnsPointed{document}
	/// @param[out] materials					Filled with the materials.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetMaterial(BaseDocument *doc, AtomArray &materials);

	/// @}

	/// @name Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts an object into the list.
	/// @param[in] pObject						The object to insert. @callerOwnsPointed{object}
	/// @param[in] lFlags							A bit field for the initial selection state of @formatParam{pObject}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InsertObject(BaseList2D* pObject, Int32 lFlags);

	//----------------------------------------------------------------------------------------
	/// Deletes an object from the list.
	/// @param[in] doc								The document for @formatParam{pObject}. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to delete. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteObject(BaseDocument *doc, BaseList2D* pObject) { return DeleteObject(GetObjectIndex(doc, pObject)); }

	//----------------------------------------------------------------------------------------
	/// Deletes an object by index.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteObject(Int32 lIndex);

	//----------------------------------------------------------------------------------------
	/// Gets an object's index in the list.
	/// @param[in] doc								The document for @formatParam{pObject}. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to get the index for. @callerOwnsPointed{object}
	/// @return												The object index, or ::NOTOK if it is not found.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectIndex(BaseDocument *doc, BaseList2D* pObject);

	//----------------------------------------------------------------------------------------
	/// Gets an object by index.
	/// @param[in] doc								The document for the object. @callerOwnsPointed{document}
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The object, as inserted with InsertObject().
	//----------------------------------------------------------------------------------------
	BaseList2D* ObjectFromIndex(BaseDocument *doc, Int32 lIndex);

	//----------------------------------------------------------------------------------------
	/// Gets the object count.
	/// @return												The number of objects in the list.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectCount();

	/// @}

	/// @name Flags
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the flags of an object by index.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												A bit field for the selection state of the object at @formatParam{lIndex} in the list.
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(Int32 lIndex);

	//----------------------------------------------------------------------------------------
	/// Gets the flags of an object.
	/// @param[in] doc								The document for @formatParam{pObject}. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to get the flags for. @callerOwnsPointed{object}
	/// @return												A bit field for the initial selection state of @formatParam{pObject}.
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(BaseDocument *doc, BaseList2D* pObject) { return GetFlags(GetObjectIndex(doc, pObject)); }

	/// @}

	/// @name Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for an object by index.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The data.
	//----------------------------------------------------------------------------------------
	BaseContainer* GetData(Int32 lIndex);

	//----------------------------------------------------------------------------------------
	/// Gets the data for an object.
	/// @param[in] doc								The document for @formatParam{pObject}. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to get the data for. @callerOwnsPointed{object}
	/// @return												The data.
	//----------------------------------------------------------------------------------------
	BaseContainer* GetData(BaseDocument *doc, BaseList2D* pObject) { return GetData(GetObjectIndex(doc, pObject)); }

	/// @}

	/// @name Inclusion Table
	/// @{

	//----------------------------------------------------------------------------------------
	/// Builds a material inclusion table containing all included objects.
	/// @param[in] doc								The document. @callerOwnsPointed{document}
	/// @param[in] hierarchy_bit			The hierarchy bit. Starts at @em 0.
	/// @return												The inclusion table. Delete the list by calling @link FreeInclusionTable@endlink(<tt>table</tt>).
	//----------------------------------------------------------------------------------------
	MatAssignTable *BuildInclusionTable(BaseDocument *doc, Int32 hierarchy_bit = NOTOK);

	/// @}
};

//----------------------------------------------------------------------------------------
/// %Material assignment table for MatAssignData. Cannot be instantiated.\n
/// Use FreeInclusionTable() to free instances.
/// @see MatAssignData::BuildInclusionTable
//----------------------------------------------------------------------------------------
class MatAssignTable
{
private:
	MatAssignTable();
	~MatAssignTable();

public:
	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{op} is in the table.
	/// @param[in] op									The object to check. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{@formatParam{op} is in the table}
	//----------------------------------------------------------------------------------------
	Bool Check(BaseList2D *op);

	//----------------------------------------------------------------------------------------
	/// Gets the object count.
	/// @return												The number of objects in the list.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectCount();

	//----------------------------------------------------------------------------------------
	/// Gets an object from the table by index.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The object, as inserted in the MatAssignData.
	//----------------------------------------------------------------------------------------
	BaseList2D* GetObject(Int32 lIndex);
};

//----------------------------------------------------------------------------------------
/// Frees inclusion tables created by MatAssignData::BuildInclusionTable.
/// @param[out] pTable						@theToDestruct{inclusion table}
//----------------------------------------------------------------------------------------
void FreeInclusionTable(MatAssignTable*& pTable);

//----------------------------------------------------------------------------------------
/// %Material assignment custom GUI (@ref CUSTOMGUI_MATASSIGN).\n
/// Here are the settings: @enumerateEnum{MATASSIGN_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class MatAssignCustomGui : public BaseCustomGui<CUSTOMGUI_MATASSIGN>
{
private:
	MatAssignCustomGui();
	~MatAssignCustomGui();
public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iMatAssignCustomGui : public iBaseCustomGui
	{
		iMatAssignCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iMatAssignData {};
	class iMatAssignTable {};
#else
	class iMatAssignCustomGui;
	class iMatAssignData;
	class iMatAssignTable;
#endif

struct CustomGuiMatAssignLib : public BaseCustomGuiLib
{
	Bool						(iMatAssignData::*InsertObject)(BaseList2D* pObject, Int32 lFlags);
	Int32						(iMatAssignData::*GetObjectIndex)(BaseDocument *doc, BaseList2D* pObject);
	Bool						(iMatAssignData::*DeleteObject)(Int32 lIndex);
	Int32						(iMatAssignData::*GetObjectCount)();
	BaseList2D*			(iMatAssignData::*ObjectFromIndex)(BaseDocument *doc, Int32 lIndex);

	Bool						(iMatAssignTable::*Check)(BaseList2D *op);
	Int32						(iMatAssignTable::*GetObjectCountT)();
	BaseList2D*			(iMatAssignTable::*GetObject)(Int32 lIndex);
	void						(*LIB_FreeInclusionTable)(iMatAssignTable *pTable);
	BaseContainer*	(iMatAssignData::*GetData)(Int32 lIndex);
	void						(iMatAssignData::*SetMaterial)(const AtomArray &materials);
	Bool						(iMatAssignData::*GetMaterial)(BaseDocument *doc, AtomArray &materials);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_MATASSIGN_H__
