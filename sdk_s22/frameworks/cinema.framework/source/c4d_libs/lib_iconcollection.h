/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_ICONCOLLECTION_H__
#define LIB_ICONCOLLECTION_H__

#include "c4d_library.h"

/// @addtogroup group_iconcollectionlibrary Icon Collection
/// @ingroup group_library
/// @{

/// @addtogroup ICONFLAG
/// @ingroup group_enumeration
/// @{
enum class ICONFLAG
{
	NONE				= 0,						///< None.
	COPY				= (1 << 0),			///< Copies the bitmap instead of storing a pointer.
	OVERWRITE		= (1 << 1),			///< If this is specified and an icon is already present in the library under this ID it will be overwritten, otherwise the existing one will stay.
	DOUBLESIZE	= (1 << 2)			///< Doubles icon size.
} MAXON_ENUM_FLAGS(ICONFLAG);
/// @}

//----------------------------------------------------------------------------------------
/// Registers an icon from a bitmap.\n
/// Optionally a sub-icon can be specified within a larger image by giving a rectangle from (@formatParam{x},@formatParam{y}) to (@formatParam{x}+@formatParam{w}, @formatParam{y}+@formatParam{h}).\n
/// If no rectangle is specified the whole bitmap is used.
/// @warning Unless @ref ICONFLAG::COPY is set make sure that @formatParam{pBmp} points to a bitmap that will always be available.
/// @param[in] lIconID						@uniquePluginID
/// @param[in] pBmp								The bitmap to use for the icon. @callerOwnsPointed{bitmap}
/// @param[in] x									Optional X coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] y									Optional Y coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] w									Optional width of the sub-icon rectangle.
/// @param[in] h									Optional height of the sub-icon rectangle.
/// @param[in] lFlags							The flags: @enumerateEnum{ICONFLAG}
/// @return												@trueIfOtherwiseFalse{the icon was registered}
//----------------------------------------------------------------------------------------
Bool RegisterIcon(Int32 lIconID, BaseBitmap *pBmp, Int32 x = 0, Int32 y = 0, Int32 w = -1, Int32 h = -1, ICONFLAG lFlags = ICONFLAG::NONE);

//----------------------------------------------------------------------------------------
/// Registers an icon from an image file.\n
/// Optionally a sub-icon can be specified within a larger image by giving a rectangle from (@formatParam{x},@formatParam{y}) to (@formatParam{x}+@formatParam{w}, @formatParam{y}+@formatParam{h}).\n
/// If no rectangle is specified the whole bitmap is used.
/// @param[in] lIconID						@uniquePluginID
/// @param[in] fn									The filename of the image file to use for the icon.
/// @param[in] x									Optional X coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] y									Optional Y coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] w									Optional width of the sub-icon rectangle.
/// @param[in] h									Optional height of the sub-icon rectangle.
/// @param[in] lFlags							The flags: @enumerateEnum{ICONFLAG}
/// @return												@trueIfOtherwiseFalse{the icon was registered}
//----------------------------------------------------------------------------------------
Bool RegisterIcon(Int32 lIconID, Filename fn, Int32 x = 0, Int32 y = 0, Int32 w = -1, Int32 h = -1, ICONFLAG lFlags = ICONFLAG::NONE); // always creates a copy (ICONFLAG::COPY set)

//----------------------------------------------------------------------------------------
/// Retrieves an icon registered with RegisterIcon().
/// @param[in] lIconID						The ID of the icon.
/// @param[in,out] pData					Filled with information about the found icon. @callerOwnsPointed{icon data}
/// @return												@trueIfOtherwiseFalse{the icon data was retrieved}
//----------------------------------------------------------------------------------------
Bool GetIcon(Int32 lIconID, IconData* pData);

//----------------------------------------------------------------------------------------
/// Unregisters an icon registered with RegisterIcon().
/// @param[in] lIconID						The ID of the icon.
/// @return												@trueIfOtherwiseFalse{the icon was unregistered}
//----------------------------------------------------------------------------------------
Bool UnregisterIcon(Int32 lIconID);

/// Icon collection library ID.
#define LIBRARY_ICON_COLLECTION		1009310

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct IconCollectionLib : public C4DLibrary
{
	Bool			(*RegisterIconBitmap)(Int32 lIconID, BaseBitmap *pBmp, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG lFlags);
	Bool			(*RegisterIconFile	)(Int32 lIconID, Filename fn, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG lFlags);
	Bool			(*GetIcon)					(Int32 lIconID, IconData* pData);
	Bool			(*UnregisterIcon		)(Int32 lIconID);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_ICONCOLLECTION_H__
