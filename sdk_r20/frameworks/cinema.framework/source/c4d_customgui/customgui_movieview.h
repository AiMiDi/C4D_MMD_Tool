/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_MOVIEVIEW_H__
#define CUSTOMGUI_MOVIEVIEW_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// Movie viewer custom GUI ID.
#define CUSTOMGUI_MOVIEVIEW	1022263

//----------------------------------------------------------------------------------------
/// Movie viewer custom GUI (@ref CUSTOMGUI_MOVIEVIEW). Currently Mac only.
//----------------------------------------------------------------------------------------
class MovieViewCustomGui : public BaseCustomGui<CUSTOMGUI_MOVIEVIEW>
{
	MovieViewCustomGui();
	~MovieViewCustomGui();

public:
	//----------------------------------------------------------------------------------------
	/// Sets the filename of the movie to be displayed.
	/// @param[in] f									The filename of the movie.
	/// @return												@trueIfOtherwiseFalse{the movie could be loaded}
	//----------------------------------------------------------------------------------------
	Bool SetMovie(const Filename &f);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iMovieViewCustomGui : public iBaseCustomGui
	{
		iMovieViewCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iMovieViewCustomGui;
#endif

struct CustomGuiMovieViewLib : public BaseCustomGuiLib
{
	Bool	(iMovieViewCustomGui::*SetMovie)(const Filename &f);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_MOVIEVIEW_H__
