/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LONGLAT_H__
#define CUSTOMGUI_LONGLAT_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Longitude/Latitude custom GUI ID.
#define CUSTOMGUI_LONG_LAT			1011148

/// @addtogroup LONG_LAT_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define LONG_LAT_LONGITUDE	1000			///< ::Bool @formatConstant{true} for Longitude mode, @formatConstant{false} for Latitude mode.
#define LONG_LAT_DECIMALS		1001			///< ::Bool @formatConstant{true} to allow decimal precision, @formatConstant{false} to allow integer values only.
/// @}

//----------------------------------------------------------------------------------------
/// Longitude/Latitude custom GUI (@ref CUSTOMGUI_LONG_LAT).\n
/// Here are the settings: @enumerateEnum{LONG_LAT_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class LongLatGui : public BaseCustomGui<CUSTOMGUI_LONG_LAT>
{
private:
	LongLatGui();
	~LongLatGui();
public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_LONGLAT_DEF_
	class iLongLatGui
	{
	};
#else
	class iLongLatGui;
#endif

struct CustomGuiLongLatLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LONGLAT_H__

