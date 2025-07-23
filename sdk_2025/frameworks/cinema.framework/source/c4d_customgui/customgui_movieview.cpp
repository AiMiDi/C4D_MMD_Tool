#include "customgui_movieview.h"

namespace cinema
{

static CustomGuiMovieViewLib *lib_MovieView = nullptr;

static CustomGuiMovieViewLib *CheckGuiMovieViewLib(Int32 offset)
{
	return CheckLib<CustomGuiMovieViewLib>(CUSTOMGUI_MOVIEVIEW, offset, lib_MovieView);
}

#define MovieViewCallR(a, b) 	cinema::CustomGuiMovieViewLib *lib = cinema::CheckGuiMovieViewLib(LIBOFFSET(cinema::CustomGuiMovieViewLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iMovieViewCustomGui*>(this)->*lib->b)

Bool MovieViewCustomGui::SetMovie(const Filename &f)
{
	MovieViewCallR(false, SetMovie)(f);
}

} // namespace cinema
