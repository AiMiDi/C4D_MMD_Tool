#include "operatingsystem.h"
#include "c4d_bitmapfilter.h"
#include "c4d_bitmapfilterstruct.h"
#include "c4d_basecontainer.h"

#ifndef __API_INTERN__
	#include "c4d_basebitmap.h"
	#include "c4d_string.h"
#else
	#include "ge_string.h"
#endif

// just a wrapper
static BM_TILE* C4DOS_BfBitmapTileGet(BM_REF bm, const RECT32* src_rect, Int32 width, Int32 height, Int32 tile_mode, Int32 flags, Int32 rsvd)
{
	BM_TILE* tile;

	tile = C4DOS.Fi->BitmapTileGet(bm, src_rect, width, height, tile_mode, flags, rsvd);

	if (tile)
	{
		switch ((int) (tile_mode & MASK_TILE_TYPE))	// fill in the correct color space
		{
			case	TILE_TYPE_MASK:	tile->color_space = CSPACE_UNKNOWN; break;
			case	TILE_TYPE_BM:		tile->color_space = bm->image_color_space; break;
			default:							tile->color_space = CSPACE_UNKNOWN; break;
		}
	}
	return tile;	// return the scaled tile
}

BM_TILE* BfBitmapTileGet(BM_REF bm, const RECT32* src_rect, Int32 width, Int32 height, Int32 tile_mode, Int32 flags)
{
	if (width && height)
	{
		Int32	src_width;
		Int32	src_height;

		src_width	 = src_rect->x2 - src_rect->x1;
		src_height = src_rect->y2 - src_rect->y1;

		if (width != src_width || height != src_height)	// scaling necessary
		{
			BM_TILE* scaled_tile = nullptr;
			RECT32	 scaled_rect;

			scaled_rect.x1 = (src_rect->x1 * width) / src_width;
			scaled_rect.y1 = (src_rect->y1 * height) / src_height;
			scaled_rect.x2 = scaled_rect.x1 + width;
			scaled_rect.y2 = scaled_rect.y1 + height;

#ifndef __API_INTERN__

			if (tile_mode & TILE_MODE_READ)	// makes only sense for tiles you want to read from
			{
				BM_TILE* src_tile = C4DOS_BfBitmapTileGet(bm, src_rect, 0, 0, tile_mode, flags, 0);
				if (src_tile)
				{
					scaled_tile = C4DOS_BfBitmapTileGet(bm, &scaled_rect, 0, 0, tile_mode & ~TILE_MODE_READ, 0, 0);

					if (scaled_tile && C4DOS.Bm->scale_bm)
					{
						/*if you call this with the intel compiler it crashes later in "paint_detach_bitmap_tile" */

						if (C4DOS.Bm->scale_bm(src_tile, scaled_tile, src_rect, &scaled_rect, 0) != FILTER_OK)
						{
							BfBitmapTileDetach(bm, scaled_tile, false);
							scaled_tile = nullptr;	// scaling did not work; probably not enough memory
						}
					}
					BfBitmapTileDetach(bm, src_tile, false);	// free the source tile
					src_tile = nullptr;
				}
			}
			else if ((tile_mode & MASK_TILE_MODE) == TILE_MODE_SCRATCH)
			{
				scaled_tile = C4DOS_BfBitmapTileGet(bm, &scaled_rect, 0, 0, tile_mode, 0, 0);
			}

#endif

			return scaled_tile;	// return the scaled tile
		}
	}
	return C4DOS_BfBitmapTileGet(bm, src_rect, width, height, tile_mode, flags, 0);
}

Int32 BfBitmapTileDetach(BM_REF bm, BM_TILE* tile_buf, Int32 flags)
{
	return C4DOS.Fi->BitmapTileDetach(bm, tile_buf, flags);
}

Bool BfConvertTileToBasebmp(const BM_TILE* tile, const RECT32* tile_rect, BaseBitmap* bmp, Int32 zero)
{
	return C4DOS.Fi->ConvertTileToBasebmp(tile, tile_rect, bmp, zero);
}

Int32 BfDiscardChanges(BM_REF bm)
{
	return C4DOS.Fi->DiscardChanges(bm);
}

Int32 BfUpdateView(BM_REF bm)
{
	return C4DOS.Fi->UpdateView(bm);
}

PROGRESS_ID	BfProgressNew(BM_REF bm)
{
	return C4DOS.Fi->ProgressNew(bm);
}

Int32 BfProgressDelete(BM_REF bm, PROGRESS_ID pid)
{
	return C4DOS.Fi->ProgressDelete(bm, pid);
}

Int32 BfProgressUpdate(BM_REF bm, PROGRESS_ID pid, Int32 current_value, Int32 max_value, const maxon::String& text)
{
	return C4DOS.Fi->ProgressUpdate(bm, pid, current_value, max_value, &text);
}

Bool BfBitmapTileScale(BM_REF bm, BM_TILE* src_bm, BM_TILE* dst_bm, RECT32* src_rect, RECT32* dst_rect)
{
#ifndef __API_INTERN__

	if (C4DOS.Bm->scale_bm && C4DOS.Bm->scale_bm(src_bm, dst_bm, src_rect, dst_rect, 0) != FILTER_OK)
		return false;

	return true;
#else
	return false;
#endif
}

BaseContainer GetGlobalFilterPrefs(Int32 pluginid)
{
	BaseContainer filterprefs;
	C4DOS.Fi->GetGlobalFilterPrefs(&filterprefs);
#ifndef __API_INTERN__
	return filterprefs.GetContainer(pluginid);
#else
	return filterprefs;
#endif
}

Bool SetGlobalFilterPrefs(Int32 pluginid, const BaseContainer& prefs)
{
	BaseContainer filterprefs;
	C4DOS.Fi->GetGlobalFilterPrefs(&filterprefs);
#ifndef __API_INTERN__
	filterprefs.SetContainer(pluginid, prefs);
#endif
	return C4DOS.Fi->SetGlobalFilterPrefs(&filterprefs);
}

void* GetEditorWindow(void)
{
	return C4DOS.Fi->GetEditorWindow();
}

#ifdef MAXON_TARGET_MACOS
Bool Mac_hostProcessEvent(void* event)
{
	return C4DOS.Fi->Mac_hostProcessEvent(event);
}
#endif
