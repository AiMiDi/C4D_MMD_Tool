/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LENSGLOW_H__
#define CUSTOMGUI_LENSGLOW_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "customgui_base.h"

/// Lens Glow custom GUI ID.
#define CUSTOMGUI_LENSGLOW			1000996

/// Lens Glow custom data ID.
#define CUSTOMDATATYPE_LENSGLOW	1000997

/// Maximum number of glows.
#define MAXGLOW_CNT		5

/// Maximum number of streaks.
#define MAXSTREAK_CNT	5

struct Streak
{
	Bool		random,					///< Random distribution.
					randomlen,			///< Random beam length.
					star;						///< Star-like.

	Int32		cnt,						///< Number of beams.
					holecnt;				///< Number of breaks.

	Float		size,						///< Size.
					sv,							///< Ratio.
					holewidth,			///< Break width.
					thickness,			///< Thickness.
					rot;						///< Angle.

	Vector	col;						///< Color.
	Int32		type;						///< Type.
};

struct Glow
{
	Float		size,			///< Size.
					sv;				///< Ratio.
	Vector	col;			///< Color.
	Int32		type;			///< Type.
};

struct Halo
{
	Float		size,			///< Size.
					sv;				///< Ratio.
	Vector	col;			///< Color.
	Int32		type;			///< Type.
};

//----------------------------------------------------------------------------------------
/// Lens Glow data type (@ref CUSTOMDATATYPE_LENSGLOW) for use with LensGlowCustomGui.
//----------------------------------------------------------------------------------------
class LensGlowStruct : public CustomDataType
{
public:
		Glow		glow[MAXGLOW_CNT];					///< Glow array.
		Streak	streak[MAXSTREAK_CNT];			///< Streak array.
		Halo		halo;												///< Halo.
};

//----------------------------------------------------------------------------------------
/// Lens Glow custom GUI (CUSTOMGUI_LENSGLOW) for use with the LensGlowStruct data type.
//----------------------------------------------------------------------------------------
class LensGlowCustomGui : public BaseCustomGui<CUSTOMGUI_LENSGLOW>
{
	LensGlowCustomGui();
	~LensGlowCustomGui();
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iLensGlowCustomGui
	{
	};
#else
	class iLensGlowCustomGui;
#endif

struct CustomGuiLensGlowLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LENSGLOW_H__
