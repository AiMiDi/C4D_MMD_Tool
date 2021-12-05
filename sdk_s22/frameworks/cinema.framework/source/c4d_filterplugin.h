/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FILTERPLUGIN_H__
#define C4D_FILTERPLUGIN_H__

#include "ge_math.h"
#include "c4d_filterdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct BITMAPLOADERPLUGIN : public STATICPLUGIN
{
	Bool				(BitmapLoaderData::*Identify			)(const Filename &name, UChar *probe, Int32 size);
	IMAGERESULT	(BitmapLoaderData::*Load					)(const Filename &name, BaseBitmap *bm, Int32 frame);
	Int32				(BitmapLoaderData::*GetSaver			)(void);
	Bool				(BitmapLoaderData::*GetInformation)(const Filename &name, Int32 *frames, Float *fps);
	IMAGERESULT	(BitmapLoaderData::*LoadAnimated	)(BitmapLoaderAnimatedData *bd, BITMAPLOADERACTION action, BaseBitmap *bm, Int32 frame);
	IMAGERESULT	(BitmapLoaderData::*ExtractSound	)(BitmapLoaderAnimatedData *bd, BaseSound *snd);
	IMAGERESULT	(BitmapLoaderData::*HasSound			)(BitmapLoaderAnimatedData *bd);

	void* reserved[(32-7)*C4DPL_MEMBERMULTIPLIER];
};

struct BITMAPSAVERPLUGIN : public STATICPLUGIN
{
	String *suffix;

	IMAGERESULT (BitmapSaverData::*Save							)(const Filename &name, BaseBitmap *bm, BaseContainer *data, SAVEBIT savebits);
	Bool				(BitmapSaverData::*Edit							)(BaseContainer *data);
	Int32				(BitmapSaverData::*GetMaxAlphas			)(BaseContainer *data);
	IMAGERESULT (BitmapSaverData::*Open							)(PluginMovieData *&md, const Filename &name, BaseBitmap *bm, BaseContainer *data, SAVEBIT savebits, Int32 fps);
	IMAGERESULT (BitmapSaverData::*Write						)(PluginMovieData *md, BaseBitmap *bm);
	IMAGERESULT (BitmapSaverData::*AddSound					)(PluginMovieData *md, BaseSound *snd);
	Int32				(BitmapSaverData::*GetMaxResolution	)(Bool layers);
	IMAGERESULT (BitmapSaverData::*Close						)(PluginMovieData *&md);
	void				(BitmapSaverData::*CorrectResolution)(const BaseContainer* settings, Int32 videoWidth, Int32 videoHeight, Int32& videoWidthPadded, Int32& videoHeightPadded);

	void* reserved[(32-9)*C4DPL_MEMBERMULTIPLIER-1];
};

struct SCENELOADERPLUGIN : public NODEPLUGIN
{
	Bool (SceneLoaderData::*Identify	)(BaseSceneLoader *node, const Filename &name, UChar *probe, Int32 size);
	FILEERROR (SceneLoaderData::*Load	)(BaseSceneLoader *node, const Filename &name, BaseDocument *doc, SCENEFILTER filterflags, maxon::String *error, BaseThread *bt);

	void* reserved[(32-2)*C4DPL_MEMBERMULTIPLIER-0];
};

struct SCENESAVERPLUGIN : public NODEPLUGIN
{
	String *suffix;

	FILEERROR (SceneSaverData::*Save)(BaseSceneSaver *node, const Filename &name, BaseDocument *doc, SCENEFILTER filterflags);

	void* reserved[(32-1)*C4DPL_MEMBERMULTIPLIER-1];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_FILTERPLUGIN_H__
