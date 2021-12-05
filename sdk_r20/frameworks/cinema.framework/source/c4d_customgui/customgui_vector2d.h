/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_VECTOR2D_H__
#define CUSTOMGUI_VECTOR2D_H__

#ifdef _INTERNAL_VECTOR2D
	#define _INTERNAL_BASECUSTOM_
#endif

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_customdatatype.h"
#include "lib_description.h"

/// 2D vector custom GUI ID.
#define CUSTOMGUI_VECTOR2D	200000101

/// @addtogroup VECTOR2D_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define VECTOR2D_BORDER										'brdr'			///< ::Bool Not used.
#define VECTOR2D_VERTICAL									'vert'			///< ::Bool Align the numerical input fields vertically.
#define VECTOR2D_XYZCOMBO									'xyzc'			///< ::Int32 @em 0: Use XY @em 1: Use XZ @em 2: Use YZ.
/// @}

class BaseList2D;

//----------------------------------------------------------------------------------------
/// Vector 2D custom GUI (@ref CUSTOMGUI_VECTOR2D) for the ::Vector data type.\n
/// Here are the settings: @enumerateEnum{VECTOR2D_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class Vector2dCustomGui : public BaseCustomGui<CUSTOMGUI_VECTOR2D>
{
	private:
		Vector2dCustomGui();
		~Vector2dCustomGui();
	public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_VECTOR2D
	class iVector2dCustomGui : public iBaseCustomGui
	{
		iVector2dCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iVector2dCustomGui;
#endif

struct Vector2dLib : public BaseCustomGuiLib
{
//	Bool		(iVector2dCustomGui::*SetImageA			)(BaseBitmap *bmp,Bool copybmp,Bool secondstate);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_VECTOR2D_H__
