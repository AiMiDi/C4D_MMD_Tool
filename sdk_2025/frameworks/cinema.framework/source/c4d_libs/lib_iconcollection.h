/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_ICONCOLLECTION_H__
#define LIB_ICONCOLLECTION_H__

#include "c4d_library.h"

namespace cinema
{

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
/// @warning Unless @ref ICONFLAG::COPY is set make sure that @formatParam{bmp} points to a bitmap that will always be available.
/// @param[in] iconId							@uniquePluginID
/// @param[in] bmp								The bitmap to use for the icon. @callerOwnsPointed{bitmap}
/// @param[in] x									Optional X coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] y									Optional Y coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] w									Optional width of the sub-icon rectangle.
/// @param[in] h									Optional height of the sub-icon rectangle.
/// @param[in] flags							The flags: @enumerateEnum{ICONFLAG}
/// @return												@trueIfOtherwiseFalse{the icon was registered}
//----------------------------------------------------------------------------------------
Bool RegisterIcon(Int32 iconId, BaseBitmap* bmp, Int32 x = 0, Int32 y = 0, Int32 w = -1, Int32 h = -1, ICONFLAG flags = ICONFLAG::NONE);

//----------------------------------------------------------------------------------------
/// Registers an icon from an image file.\n
/// Optionally a sub-icon can be specified within a larger image by giving a rectangle from (@formatParam{x},@formatParam{y}) to (@formatParam{x}+@formatParam{w}, @formatParam{y}+@formatParam{h}).\n
/// If no rectangle is specified the whole bitmap is used.
/// @param[in] iconId							@uniquePluginID
/// @param[in] fn									The filename of the image file to use for the icon.
/// @param[in] x									Optional X coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] y									Optional Y coordinate of the top left corner of the sub-icon rectangle.
/// @param[in] w									Optional width of the sub-icon rectangle.
/// @param[in] h									Optional height of the sub-icon rectangle.
/// @param[in] flags							The flags: @enumerateEnum{ICONFLAG}. Note that @ref ICONFLAG::COPY is not relevant in this context.
/// @return												@trueIfOtherwiseFalse{the icon was registered}
//----------------------------------------------------------------------------------------
Bool RegisterIcon(Int32 iconId, Filename fn, Int32 x = 0, Int32 y = 0, Int32 w = -1, Int32 h = -1, ICONFLAG flags = ICONFLAG::NONE);

//----------------------------------------------------------------------------------------
/// Retrieves an icon registered with @ref RegisterIcon().
/// @param[in] iconId							The ID of the icon.
/// @param[in,out] data						Filled with information about the found icon. @callerOwnsPointed{icon data}
/// @return												@trueIfOtherwiseFalse{the icon data was retrieved}
//----------------------------------------------------------------------------------------
Bool GetIcon(Int32 iconId, IconData* data);

//----------------------------------------------------------------------------------------
/// Colorizes an icon registered with @ref RegisterIcon() in the given color. If @formatParam{color} is empty or not a valid, the icon will be restored (i.e. "de-colorized") to its original state.
/// @param[in] iconId							The ID of the icon.
/// @param[in] color							The color. Can be either a valid color ID from c4d_colors.h, e.g. @formatConstant{COLOR_BG} or a @ref Vector color in range @formatConstant{(0.0,1.0)} or an empty or invalid data, which will de-colorize the icon.
/// @return												@trueIfOtherwiseFalse{the icon data was properly colorized}
//----------------------------------------------------------------------------------------
Bool ColorizeIcon(Int32 iconId, const GeData& color);

//----------------------------------------------------------------------------------------
/// Returns a colorized copy of the defined icon. If @formatParam{color} is empty or not a valid, the returned copied will be the original non-colorized version of the icon.
/// @param[in] iconId							The ID of the icon.
/// @param[in] color							The color. Can be either a valid color ID from c4d_colors.h, e.g. @formatConstant{COLOR_BG} or a @ref Vector color in range @formatConstant{(0.0,1.0)} or an empty or invalid data, which will return a non-colorized icon.
/// @return												A colorized copy of the icon bitmap. @callerOwnsPointed{bitmap}.
//----------------------------------------------------------------------------------------
BaseBitmap* GetColorizedIcon(Int32 iconId, const GeData& color);

//----------------------------------------------------------------------------------------
/// Unregisters an icon registered with RegisterIcon().
/// @param[in] iconId							The ID of the icon.
/// @return												@trueIfOtherwiseFalse{the icon was unregistered}
//----------------------------------------------------------------------------------------
Bool UnregisterIcon(Int32 iconId);

/// Icon collection library ID.
#define LIBRARY_ICON_COLLECTION		1009310

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct IconCollectionLib : public C4DLibrary
{
	Bool				(*RegisterIconBitmap 	 )(Int32 iconId, BaseBitmap* bmp, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG flags);
	Bool				(*RegisterIconFile	 	 )(Int32 iconId, Filename fn, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG flags);
	Bool				(*GetIcon						 	 )(Int32 iconId, IconData* data);
	Bool				(*UnregisterIcon		 	 )(Int32 iconId);
	Bool				(*ColorizeIcon				 )(Int32 iconId, const GeData& color);
	BaseBitmap*	(*GetColorizedIcon		 )(Int32 iconId, const GeData& color);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_ICONCOLLECTION_H__
