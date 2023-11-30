/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_INEXCLUDE_H__
#define CUSTOMGUI_INEXCLUDE_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseDocument;

/// InExclude custom GUI ID.
#define CUSTOMGUI_INEXCLUDE_LIST					1009290

/// InExclude custom data type ID.
#define CUSTOMDATATYPE_INEXCLUDE_LIST			1009290

#define IN_EXCLUDE_DATA_SELECTION					10			///< ::Bool @formatConstant{true} if @ref IN_EXCLUDE_FLAG_SEND_SELCHANGE_MSG is set and the object is selected in the list.
#define IN_EXCLUDE_DATA_BACKGROUND				11			///< ::Vector Custom background color of the object entry if set.
#define IN_EXCLUDE_FORBID_DOUBLECLICK			1036851 ///< ::Bool @markPrivate Set to @formatConstant{true} in BaseList2D data container to ignore double click selection. @since R18
#define IN_EXCLUDE_DATA_ROWFLAGS					12			///< ::Int32 Custom flag count for an object entry if set. @since R26

/// @addtogroup IN_EXCLUDE_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define IN_EXCLUDE_FLAG_NUM_FLAGS				2000			///< ::Int32 The number of different flags.
#define IN_EXCLUDE_FLAG_IMAGE_01_ON			2001			///< ::Int32 Image ID of the @em On state for column @em 01.
#define IN_EXCLUDE_FLAG_IMAGE_01_OFF		2002			///< ::Int32 Image ID of the @em Off state for column @em 01.
#define IN_EXCLUDE_FLAG_IMAGE_02_ON			2003			///< ::Int32 Image ID of the @em On state for column @em 02.
#define IN_EXCLUDE_FLAG_IMAGE_02_OFF		2004			///< ::Int32 Image ID of the @em Off state for column @em 02.
#define IN_EXCLUDE_FLAG_IMAGE_03_ON			2005			///< ::Int32 Image ID of the @em On state for column @em 03.
#define IN_EXCLUDE_FLAG_IMAGE_03_OFF		2006			///< ::Int32 Image ID of the @em Off state for column @em 03.
#define IN_EXCLUDE_FLAG_IMAGE_04_ON			2007			///< ::Int32 Image ID of the @em On state for column @em 04.
#define IN_EXCLUDE_FLAG_IMAGE_04_OFF		2008			///< ::Int32 Image ID of the @em Off state for column @em 04.
#define IN_EXCLUDE_FLAG_IMAGE_05_ON			2009			///< ::Int32 Image ID of the @em On state for column @em 05.
#define IN_EXCLUDE_FLAG_IMAGE_05_OFF		2010			///< ::Int32 Image ID of the @em Off state for column @em 05.
#define IN_EXCLUDE_FLAG_IMAGE_06_ON			2011			///< ::Int32 Image ID of the @em On state for column @em 06.
#define IN_EXCLUDE_FLAG_IMAGE_06_OFF		2012			///< ::Int32 Image ID of the @em Off state for column @em 06.
#define IN_EXCLUDE_FLAG_IMAGE_07_ON			2013			///< ::Int32 Image ID of the @em On state for column @em 07.
#define IN_EXCLUDE_FLAG_IMAGE_07_OFF		2014			///< ::Int32 Image ID of the @em Off state for column @em 07.
#define IN_EXCLUDE_FLAG_IMAGE_08_ON			2015			///< ::Int32 Image ID of the @em On state for column @em 08.
#define IN_EXCLUDE_FLAG_IMAGE_08_OFF		2016			///< ::Int32 Image ID of the @em Off state for column @em 08.
#define IN_EXCLUDE_FLAG_IMAGE_09_ON			2017			///< ::Int32 Image ID of the @em On state for column @em 09.
#define IN_EXCLUDE_FLAG_IMAGE_09_OFF		2018			///< ::Int32 Image ID of the @em Off state for column @em 09.
#define IN_EXCLUDE_FLAG_IMAGE_10_ON			2019			///< ::Int32 Image ID of the @em On state for column @em 10.
#define IN_EXCLUDE_FLAG_IMAGE_10_OFF		2020			///< ::Int32 Image ID of the @em Off state for column @em 10.
#define IN_EXCLUDE_FLAG_IMAGE_11_ON			2021			///< ::Int32 Image ID of the @em On state for column @em 11.
#define IN_EXCLUDE_FLAG_IMAGE_11_OFF		2022			///< ::Int32 Image ID of the @em Off state for column @em 11.
#define IN_EXCLUDE_FLAG_IMAGE_12_ON			2023			///< ::Int32 Image ID of the @em On state for column @em 12.
#define IN_EXCLUDE_FLAG_IMAGE_12_OFF		2024			///< ::Int32 Image ID of the @em Off state for column @em 12.
#define IN_EXCLUDE_FLAG_IMAGE_13_ON			2025			///< ::Int32 Image ID of the @em On state for column @em 13.
#define IN_EXCLUDE_FLAG_IMAGE_13_OFF		2026			///< ::Int32 Image ID of the @em Off state for column @em 13.
#define IN_EXCLUDE_FLAG_IMAGE_14_ON			2027			///< ::Int32 Image ID of the @em On state for column @em 14.
#define IN_EXCLUDE_FLAG_IMAGE_14_OFF		2028			///< ::Int32 Image ID of the @em Off state for column @em 14.
#define IN_EXCLUDE_FLAG_IMAGE_15_ON			2029			///< ::Int32 Image ID of the @em On state for column @em 15.
#define IN_EXCLUDE_FLAG_IMAGE_15_OFF		2030			///< ::Int32 Image ID of the @em Off state for column @em 15.
#define IN_EXCLUDE_FLAG_IMAGE_16_ON			2031			///< ::Int32 Image ID of the @em On state for column @em 16.
#define IN_EXCLUDE_FLAG_IMAGE_16_OFF		2032			///< ::Int32 Image ID of the @em Off state for column @em 16.
#define IN_EXCLUDE_FLAG_IMAGE_17_ON			2033			///< ::Int32 Image ID of the @em On state for column @em 17.
#define IN_EXCLUDE_FLAG_IMAGE_17_OFF		2034			///< ::Int32 Image ID of the @em Off state for column @em 17.
#define IN_EXCLUDE_FLAG_IMAGE_18_ON			2035			///< ::Int32 Image ID of the @em On state for column @em 18.
#define IN_EXCLUDE_FLAG_IMAGE_18_OFF		2036			///< ::Int32 Image ID of the @em Off state for column @em 18.
#define IN_EXCLUDE_FLAG_IMAGE_19_ON			2037			///< ::Int32 Image ID of the @em On state for column @em 19.
#define IN_EXCLUDE_FLAG_IMAGE_19_OFF		2038			///< ::Int32 Image ID of the @em Off state for column @em 19.
#define IN_EXCLUDE_FLAG_IMAGE_20_ON			2039			///< ::Int32 Image ID of the @em On state for column @em 20.
#define IN_EXCLUDE_FLAG_IMAGE_20_OFF		2040			///< ::Int32 Image ID of the @em Off state for column @em 20.
#define IN_EXCLUDE_FLAG_IMAGE_21_ON			2041			///< ::Int32 Image ID of the @em On state for column @em 21.
#define IN_EXCLUDE_FLAG_IMAGE_21_OFF		2042			///< ::Int32 Image ID of the @em Off state for column @em 21.
#define IN_EXCLUDE_FLAG_IMAGE_22_ON			2043			///< ::Int32 Image ID of the @em On state for column @em 22.
#define IN_EXCLUDE_FLAG_IMAGE_22_OFF		2044			///< ::Int32 Image ID of the @em Off state for column @em 22.
#define IN_EXCLUDE_FLAG_IMAGE_23_ON			2045			///< ::Int32 Image ID of the @em On state for column @em 23.
#define IN_EXCLUDE_FLAG_IMAGE_23_OFF		2046			///< ::Int32 Image ID of the @em Off state for column @em 23.
#define IN_EXCLUDE_FLAG_IMAGE_24_ON			2047			///< ::Int32 Image ID of the @em On state for column @em 24.
#define IN_EXCLUDE_FLAG_IMAGE_24_OFF		2048			///< ::Int32 Image ID of the @em Off state for column @em 24.
#define IN_EXCLUDE_FLAG_IMAGE_25_ON			2049			///< ::Int32 Image ID of the @em On state for column @em 25.
#define IN_EXCLUDE_FLAG_IMAGE_25_OFF		2050			///< ::Int32 Image ID of the @em Off state for column @em 25.
#define IN_EXCLUDE_FLAG_IMAGE_26_ON			2051			///< ::Int32 Image ID of the @em On state for column @em 26.
#define IN_EXCLUDE_FLAG_IMAGE_26_OFF		2052			///< ::Int32 Image ID of the @em Off state for column @em 26.
#define IN_EXCLUDE_FLAG_IMAGE_27_ON			2053			///< ::Int32 Image ID of the @em On state for column @em 27.
#define IN_EXCLUDE_FLAG_IMAGE_27_OFF		2054			///< ::Int32 Image ID of the @em Off state for column @em 27.
#define IN_EXCLUDE_FLAG_IMAGE_28_ON			2055			///< ::Int32 Image ID of the @em On state for column @em 28.
#define IN_EXCLUDE_FLAG_IMAGE_28_OFF		2056			///< ::Int32 Image ID of the @em Off state for column @em 28.
#define IN_EXCLUDE_FLAG_IMAGE_29_ON			2057			///< ::Int32 Image ID of the @em On state for column @em 29.
#define IN_EXCLUDE_FLAG_IMAGE_29_OFF		2058			///< ::Int32 Image ID of the @em Off state for column @em 29.
#define IN_EXCLUDE_FLAG_IMAGE_30_ON			2059			///< ::Int32 Image ID of the @em On state for column @em 30.
#define IN_EXCLUDE_FLAG_IMAGE_30_OFF		2060			///< ::Int32 Image ID of the @em Off state for column @em 30.
#define IN_EXCLUDE_FLAG_IMAGE_31_ON			2061			///< ::Int32 Image ID of the @em On state for column @em 31.
#define IN_EXCLUDE_FLAG_IMAGE_31_OFF		2062			///< ::Int32 Image ID of the @em Off state for column @em 31.
#define IN_EXCLUDE_FLAG_IMAGE_32_ON			2063			///< ::Int32 Image ID of the @em On state for column @em 32.
#define IN_EXCLUDE_FLAG_IMAGE_32_OFF		2064			///< ::Int32 Image ID of the @em Off state for column @em 32.
#define IN_EXCLUDE_FLAG_INIT_STATE			2065			///< ::Int32 The initial state of a newly inserted element.
#define IN_EXCLUDE_FLAG_SEND_SELCHANGE_MSG	2066	///< ::Bool @formatConstant{true} if the selection state should be stored in the object's data container.
#define IN_EXCLUDE_FLAG_SMALL_MODE_SIZE			2067	///< ::Int32 Size of the InExclude list in small mode. @since R18
#define IN_EXCLUDE_FLAG_BIG_MODE_SIZE				2068	///< ::Int32 Size of the InExclude list in big mode. @since R18
#define IN_EXCLUDE_FLAG_ENABLED_IN_TRISTATE	2069	///< ::Bool @formatConstant{true} if list is should be enabled in tristate (old behavior). If @formatConstant{false} list will be disabled in tristate and it will show text "<<Multiple Values>>". Tristate is when there are several lists selected but they contain different objects.
#define IN_EXCLUDE_FLAG_NO_RESIZABLE				2070	///< ::Bool @formatConstant{true} if resizable bar at bottom should be hidden. @since R21
#define IN_EXCLUDE_FLAG_DISABLE_CONTEXTMENU	2071	///< ::Bool @formatConstant{true} if right click context menu should be deactivated. @since R26
/// @}

class InclusionTable;

//-------------------------------------------------------------------------------------------------
/// InExclude custom data type (@ref CUSTOMDATATYPE_INEXCLUDE_LIST).
//-------------------------------------------------------------------------------------------------
class InExcludeData : public CustomDataTypeT<CUSTOMDATATYPE_INEXCLUDE_LIST>
{
private:
	InExcludeData();
	~InExcludeData();
public:
	/// @name Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts a link to @formatParam{pObject} into the list.
	/// @note Sends @ref MSG_DESCRIPTION_INEX_ADDED to the parent.
	/// @param[in] pObject						The object to add to the list.
	/// @param[in] lFlags							A bit field for the initial selection state of @formatParam{pObject}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InsertObject(BaseList2D* pObject, Int32 lFlags);

	//----------------------------------------------------------------------------------------
	/// Removes @formatParam{pObject} from the list.
	/// @note Sends @ref MSG_DESCRIPTION_INEX_DELETED to the parent.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to remove. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteObject(BaseDocument *doc, BaseList2D* pObject) { return DeleteObject(GetObjectIndex(doc, pObject)); }

	//----------------------------------------------------------------------------------------
	/// Removes the object at index @formatParam{lIndex} in the list.
	/// @note Sends @ref MSG_DESCRIPTION_INEX_DELETED to the parent.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteObject(Int32 lIndex);

	//----------------------------------------------------------------------------------------
	/// Resets the list.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Gets the index of @formatParam{pObject} in the list.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to search for. @callerOwnsPointed{object}
	/// @return												The object index, or ::NOTOK if it was not found.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectIndex(const BaseDocument *doc, const BaseList2D* pObject) const;

	//----------------------------------------------------------------------------------------
	/// Gets the object at index @formatParam{lIndex} in the list.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The found object, or @formatConstant{nullptr}. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	const BaseList2D* ObjectFromIndex(const BaseDocument* doc, Int32 lIndex) const;

	/// @copydoc ObjectFromIndex
	BaseList2D* ObjectFromIndex(BaseDocument* doc, Int32 lIndex) const { return const_cast<BaseList2D*>(ObjectFromIndex(static_cast<const BaseDocument*>(doc), lIndex)); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of objects in the list.
	/// @return												The object count.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectCount() const;

	/// @}

	/// @name Flags
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the flags for the object at index @formatParam{lIndex} in the list.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												A bit field for the selection state of the object.
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(Int32 lIndex) const;

	//----------------------------------------------------------------------------------------
	/// Sets the flags for the object at index @formatParam{lIndex} in the list.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @param[in] lFlags							A bit field for the selection state of the object.
	//----------------------------------------------------------------------------------------
	void SetFlags(Int32 lIndex, Int32 lFlags);

	//----------------------------------------------------------------------------------------
	/// Gets the flags for @formatParam{pObject}.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to get the flags for. @callerOwnsPointed{object}
	/// @return												A bit field for the selection state of the object.
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(BaseDocument *doc, BaseList2D* pObject) const { return GetFlags(GetObjectIndex(doc, pObject)); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of flags for each object.
	/// @since R18
	/// @return												The number of flags for each object.
	//----------------------------------------------------------------------------------------
	Int32 GetFlagCount() const;

	//----------------------------------------------------------------------------------------
	/// Sets the number of flags for each object.
	/// @since R18
	/// @param[in] lFlagCount					The number of flags for each object.
	//----------------------------------------------------------------------------------------
	void SetFlagCount(Int32 lFlagCount);

	//----------------------------------------------------------------------------------------
	/// Gets the default flag for new items in the list.
	/// @since R18
	/// @return												The default flag for new items in the list.
	//----------------------------------------------------------------------------------------
	Int32 GetDefaultFlag() const;

	//----------------------------------------------------------------------------------------
	/// Gets the default flag for this list.
	/// @since R18
	/// @param[in] defaultFlag				The default flag for new items in the list.
	//----------------------------------------------------------------------------------------
	void SetDefaultFlag(Int32 defaultFlag);

	/// @}

	/// @name Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the data container for the object at index @formatParam{lIndex} in the list.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The data container. See @ref IN_EXCLUDE_DATA_SELECTION. @theOwnsPointed{inexclude list,container}
	//----------------------------------------------------------------------------------------
	BaseContainer*			 GetData(Int32 lIndex);
	const BaseContainer* GetData(Int32 lIndex) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the data container for @formatParam{pObject}.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] pObject						The object to get the data for. @callerOwnsPointed{object}
	/// @return												The data container. See @ref IN_EXCLUDE_DATA_SELECTION. @theOwnsPointed{inexclude list,container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetData(const BaseDocument* doc, const BaseList2D* pObject)
	{
		return GetData(GetObjectIndex(doc, pObject));
	}
	const BaseContainer* GetData(const BaseDocument* doc, const BaseList2D* pObject) const
	{
		return GetData(GetObjectIndex(doc, pObject));
	}

	/// @}

	/// @name Inclusion Table
	/// @{

	//----------------------------------------------------------------------------------------
	/// Builds an inclusion table for a specific bit.
	/// @param[in] doc								The document to evaluate the links in. @callerOwnsPointed{document}
	/// @param[in] hierarchy_bit			The bit position to generate the table for.
	/// @return												The inclusion table, or @formatConstant{nullptr}. @callerOwnsPointed{inclusion table}\n
	/// 															Delete it afterward by calling @link FreeInclusionTable@endlink(<tt>table</tt>).
	//----------------------------------------------------------------------------------------
	InclusionTable *BuildInclusionTable(const BaseDocument *doc, Int32 hierarchy_bit = NOTOK) const;

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// Inclusion table for InExcludeData. Cannot be instantiated.
/// @note Use FreeInclusionTable() to free instances.
/// @see InExcludeData::BuildInclusionTable
//-------------------------------------------------------------------------------------------------
class InclusionTable
{
private:
	InclusionTable();
	~InclusionTable();

public:
	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{op} is in the table.
	/// @param[in] op									An object. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{@formatParam{op} is in the table}
	//----------------------------------------------------------------------------------------
	Bool Check(const BaseList2D *op) const;

	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{op} is in the table.
	/// @param[in] op									An object. @callerOwnsPointed{object}
	/// @param[out] flags							Assigned the bit field for the initial selection state of @formatParam{op}.
	/// @return												@trueIfOtherwiseFalse{@formatParam{op} is in the table}
	//----------------------------------------------------------------------------------------
	Bool Check(const BaseList2D *op, Int32 &flags) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of objects in the table.
	/// @return												The object count.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets an object in the table at index @formatParam{lIndex}.
	/// @param[in] lIndex							The object index: @em 0 <= @formatParam{lIndex} < GetObjectCount()
	/// @return												The object at index @formatParam{lIndex}, or @formatConstant{nullptr}. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetObject(Int32 lIndex) const;
};

//----------------------------------------------------------------------------------------
/// Frees inclusion tables created by InExcludeData::BuildInclusionTable.
/// @param[out] pTable						@theToDestruct{inclusion table}
//----------------------------------------------------------------------------------------
void FreeInclusionTable(InclusionTable*& pTable);

//----------------------------------------------------------------------------------------
/// InExclude custom GUI (@ref CUSTOMGUI_INEXCLUDE_LIST).\n
/// Here are the settings: @enumerateEnum{IN_EXCLUDE_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class InExcludeCustomGui : public BaseCustomGui<CUSTOMGUI_INEXCLUDE_LIST>
{
private:
	InExcludeCustomGui();
	~InExcludeCustomGui();
public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iInExcludeCustomGui : public iBaseCustomGui
	{
		iInExcludeCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class CINEWARE_SINGLEINHERITANCE iIncludeExcludeData {};
	class CINEWARE_SINGLEINHERITANCE iInclusionTable {};
#else
	class iInExcludeCustomGui;
	class iIncludeExcludeData;
	class iInclusionTable;
#endif

struct CustomGuiInExcludeLib : public BaseCustomGuiLib
{
	Bool						(iIncludeExcludeData::*InsertObject)(BaseList2D* pObject, Int32 lFlags);
	Int32						(iIncludeExcludeData::*GetObjectIndex)(const BaseDocument *doc, const BaseList2D* pObject) const;
	Bool						(iIncludeExcludeData::*DeleteObject)(Int32 lIndex);
	Int32						(iIncludeExcludeData::*GetObjectCount)() const;
	Int32						(iIncludeExcludeData::*GetFlags)(Int32 lIndex) const;
	const BaseList2D*			(iIncludeExcludeData::*ObjectFromIndex)(const BaseDocument *doc, Int32 lIndex) const;
	InclusionTable*	(iIncludeExcludeData::*BuildInclusionTable)(const BaseDocument *doc, Int32 hierarchy_bit) const;

	Bool						(iInclusionTable::*Check)(const BaseList2D *op) const;
	Int32						(iInclusionTable::*GetObjectCountT)() const;
	BaseList2D*			(iInclusionTable::*GetObject)(Int32 lIndex) const;
	void						(*LIB_FreeInclusionTable)(iInclusionTable *pTable);
	BaseContainer*	(iIncludeExcludeData::*GetData)(Int32 lIndex) const;
	Bool						(iInclusionTable::*CheckFlags)(const BaseList2D *op, Int32 &f) const;
	void						(iIncludeExcludeData::*SetFlags)(Int32 lIndex, Int32 lFlags);
	Int32						(iIncludeExcludeData::*GetFlagCount)() const;
	Int32						(iIncludeExcludeData::*GetDefaultFlag)() const;
	void						(iIncludeExcludeData::*SetFlagCount)(Int32 lFlagCount);
	void						(iIncludeExcludeData::*SetDefaultFlag)(Int32 defaultFlag);
	void						(iIncludeExcludeData::*Reset)();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
#endif // CUSTOMGUI_INEXCLUDE_H__
