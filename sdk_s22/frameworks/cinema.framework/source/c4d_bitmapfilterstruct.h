/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BITMAPFILTERSTRUCT_H__
#define C4D_BITMAPFILTERSTRUCT_H__

struct BM_TILE;
struct BM_INFO;
typedef BM_INFO* BM_REF;
struct RECT32;
typedef Int32 PROGRESS_ID;

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct C4D_BitmapFilter
{
	BM_TILE*		(*BitmapTileGet)(BM_REF bm, const RECT32 *src_rect, Int32 width, Int32 height, Int32 tile_mode, Int32 flags, Int32 unused);
	Int32				(*BitmapTileDetach)(BM_REF bm, BM_TILE* tile_buf, Int32 flags);
	Bool				(*ConvertTileToBasebmp)(const BM_TILE* tile, const RECT32* tile_rect, BaseBitmap* bmp, Int32 zero);

	Int32				(*DiscardChanges)(BM_REF bm);
	Int32				(*UpdateView)(BM_REF bm);

	Bool				(*GetGlobalFilterPrefs)(BaseContainer* prefs);
	Bool				(*SetGlobalFilterPrefs)(const BaseContainer* prefs);

	void*				(*GetEditorWindow)(void);
	Bool				(*IsHostWindow)(void* win);
	Bool				(*Mac_hostProcessEvent)(void* event);

	PROGRESS_ID	(*ProgressNew)(BM_REF bm);
	Int32				(*ProgressDelete)(BM_REF bm, PROGRESS_ID pid);
	Int32				(*ProgressUpdate)(BM_REF bm, PROGRESS_ID pid, Int32 current_value, Int32 max_value, const maxon::String* text);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_BITMAPFILTERSTRUCT_H__
