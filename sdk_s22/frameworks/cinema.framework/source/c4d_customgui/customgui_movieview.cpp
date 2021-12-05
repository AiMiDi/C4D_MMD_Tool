#include "customgui_movieview.h"

static CustomGuiMovieViewLib *lib_MovieView = nullptr;

static CustomGuiMovieViewLib *CheckGuiMovieViewLib(Int32 offset)
{
	return (CustomGuiMovieViewLib*)CheckLib(CUSTOMGUI_MOVIEVIEW, offset, (C4DLibrary**)&lib_MovieView);
}

#define MovieViewCallR(a, b) 	CustomGuiMovieViewLib *lib = CheckGuiMovieViewLib(LIBOFFSET(CustomGuiMovieViewLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iMovieViewCustomGui*)this)->*lib->b)

Bool MovieViewCustomGui::SetMovie(const Filename &f)
{
	MovieViewCallR(false, SetMovie)(f);
}
