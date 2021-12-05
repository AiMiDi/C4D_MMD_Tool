/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_BITMAPBOOL_H__
#define CUSTOMGUI_BITMAPBOOL_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Bitmap bool custom GUI ID.
#define CUSTOMGUI_BITMAPBOOL	450000130

/// @addtogroup BITMAPBOOL_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define BITMAPBOOL_ACTIVE								1000			///< ::Int32 Active bitmap ID.
#define BITMAPBOOL_INACTIVE							1001			///< ::Int32 Inactive bitmap ID.
#define BITMAPBOOL_TRISTATE							1002			///< ::Int32 Tristate bitmap ID.
#define BITMAPBOOL_TOGGLEACTIVATION			1003			///< ::Bool @formatConstant{true} to display @ref BITMAPBOOL_ACTIVE bitmap, @formatConstant{false} to disable it. @since R19
#define BITMAPBOOL_CUSTOMSIZE						1004			///< ::Int32 Custom button size, default is @em 15. @since R19
#define BITMAPBOOL_FITBITMAP						1005			///< ::Bool If @formatConstant{true} the bitmap is resized to fit the available space. @since R19
/// @}

//----------------------------------------------------------------------------------------
/// Bitmap bool custom GUI (@ref CUSTOMGUI_BITMAPBOOL) for the ::Bool data type.\n
/// Here are the settings: @enumerateEnum{BITMAPBOOL_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class BitmapBoolGui : public BaseCustomGui<CUSTOMGUI_BITMAPBOOL>
{
private:
	BitmapBoolGui();
	~BitmapBoolGui();
public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_BITMAPBOOL_DEF_
	class iBitmapBoolGui
	{
	};
#else
	class iBitmapBoolGui;
#endif

struct CustomGuiBitmapBoolLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_BITMAPBOOL_H__

