/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef X4D_FILTER_H__
#define X4D_FILTER_H__

#include "x4d_macros.h"	// defines for platform independency
#include "x4d_colors.h"	// color spaces and pixel formats
#include "operatingsystem.h"

//----------------------------------------------------------------------------------------
// Coordinates ...
//----------------------------------------------------------------------------------------
struct RECT32	// rectangle for 32 bit coordinates
{
	Int32	x1;
	Int32	y1;
	Int32	x2;
	Int32	y2;
};


//----------------------------------------------------------------------------------------
// Output context
//----------------------------------------------------------------------------------------
typedef	void* DRAW_CONTEXT;	// tk: bei uns gibts kein windows oder mac !!!

//----------------------------------------------------------------------------------------
// Private and public filter settings
//----------------------------------------------------------------------------------------
typedef void* FILTER_PARAM;	// private filter settings

#define	FLAT_SETTINGS_MAGIC	CHAR_CONST32('fflt')
struct FLAT_FILTER_SETTINGS					// structure for filter settings (that could be saved to disk)
{
	UInt32 magic;											// 'fflt'
	Int32	 length;										// size
	Int32	 format;										// format (0)
	Int32	 reserved;									// reserved (0)

	UChar	 data[VARIABLE_ARRAY_SIZE];	// misc. data
};

#define	sizeof_FLAT_FILTER_SETTINGS	offsetofI(FLAT_FILTER_SETTINGS, data)	// size without the data array


//----------------------------------------------------------------------------------------
// The following structure is an argument to filter_start(). The Filter uses
// it as reference (to the bitmap) when it has to call services of the kernel.
//----------------------------------------------------------------------------------------
#define	BM_REF_MAGIC CHAR_CONST32('bmrf')

struct BM_INFO		// public definition
{
	UInt32 magic;		// 'bmrf'
	Int32	 length;	// size
	Int32	 format;	// format (0)
	Int32	 flags;
#define BMFLAG_NOUPDATE			1
#define BMFLAG_REPEATEFFECT	2

	Int32	 image_color_space;	// color space of the image
	UInt32 image_px_format;		// pixel format of the image
	UInt32 mask_px_format;		// pixel format of the selection mask
	Int32	 reserved1;

	Int32	 preferred_tile_width;	// most efficient size for tiles
	Int32	 preferred_tile_height;
	Int32	 reserved2;
	Int32	 reserved3;

	RECT32 image_rect;	// coordinate space of the image bitmap
	RECT32 mask_rect;		// (bounding) rectangle of the selected area [equal or smaller than image_rect]

};

struct FI_INFO
{
	Int32	size;
	Int32	pluginid;
};

typedef BM_INFO* BM_REF;
typedef FI_INFO* FI_REF;


//----------------------------------------------------------------------------------------
// BitmapTileGet() returns this structure for the requested bitmap tile
//----------------------------------------------------------------------------------------
#define	BM_TILE_MAGIC	CHAR_CONST32('bmtl')

struct BM_TILE
{
	UInt32 magic;				// 'bmtl'
	Int32	 length;			// size
	Int32	 format;			// format (0)
	Int32	 reserved;		// reserved (0)

	void*	 addr;				// pointer to the bitmap data
	Int32	 width;				// width of a line in bytes
	Int32	 color_space;	// color space
	UInt32 px_format;		// pixel format

	Int32	 xmin;				// minimum discrete x-coordinate of the bitmap
	Int32	 ymin;				// minimum discrete y-coordinate of the bitmap
	Int32	 xmax;				// maximum discrete x-coordinate of the bitmap + 1
	Int32	 ymax;				// maximum discrete y-coordinate of the bitmap + 1

	Int32	 reserved4;		// [reference of the color table] (0)
	Int32	 reserved3;		// [reference of the inverse color table] (0)
	Int32	 reserved2;		// reserved (0)
	Int32	 reserved1;		// reserved (0)

};


//----------------------------------------------------------------------------------------
// Server definitions
//----------------------------------------------------------------------------------------

// Tile modes
#define	TILE_MODE_SCRATCH			 0x0000
#define	TILE_MODE_READ				 0x0001
#define	TILE_MODE_WRITE				 0x0002
#define	TILE_MODE_READ_WRITE	 0x0003
#define	TILE_MODE_READ_SCRATCH 0x0004	// used only in the row fetcher (not supported by BfBitmapTileGet so far)

// tile types
#define	MASK_TILE_TYPE 0xFF00
#define	MASK_TILE_MODE 0x000F

#define	TILE_TYPE_MASK 0x0100
#define	TILE_TYPE_BM	 0x0200

// diverse Kachel-Typen
#define	TILE_MASK_SCRATCH		 0x0100	// temporary buffer [with the mask's pixel format]
#define	TILE_MASK_READ_ONLY	 0x0101	// tile containing the selection mask
#define	TILE_MASK_WRITE			 0x0102	// tile will be used as new selection mask
#define	TILE_MASK_READ_WRITE 0x0103	// tile contains the selection mask and will be used as new mask

#define	TILE_BM_SCRATCH			 0x0200	// temporary buffer [with the image's pixel format]
#define	TILE_BM_READ_ONLY		 0x0201	// tile containing the image bitmap
#define	TILE_BM_WRITE				 0x0202	// tile will be used as new image bitmap
#define	TILE_BM_READ_WRITE	 0x0203	// tile contains the image bitmap and will be used as new bitmap
#define	TILE_BM_READ_SCRATCH 0x0204	// used only in the row fetcher (not supported by BfBitmapTileGet so far)

// flags of GetBitmapTile()
#define TILE_REPEAT_BORDER (1 << 0)	// repeats the border for each pixel outside the bitmap
#define TILE_REPEAT_TILING (1 << 1)	// repeats the tiled image (wrap around)
#define TILE_LAST_RESULT	 (1 << 2)	// deliver the changed data instead of original data


// handling tiles
typedef	BM_TILE* TYPE_BitmapTileGet (BM_REF bm, const RECT32 * src_rect, Int32 width, Int32 height, Int32 tile_mode, Int32 flags, Int32 unused);
typedef	Int32	TYPE_BitmapTileDetach (BM_REF bm, BM_TILE * tile_buf, Int32 flags);
typedef	Int32	TYPE_DiscardChanges (BM_REF bm);
typedef	Int32	TYPE_UpdateView (BM_REF bm);

// progress handling
typedef	Int32	PROGRESS_ID;
typedef	PROGRESS_ID	TYPE_ProgressNew (void);
typedef	Int32	TYPE_ProgressDelete (PROGRESS_ID pid);
typedef	Int32	TYPE_ProgressUpdate (PROGRESS_ID pid, Int32 current_value, Int32 max_value);

typedef	Int32	TYPE_display_bitmap (DRAW_CONTEXT dc, const BM_TILE * src, const RECT32 * src_rect, const RECT32 * dst_rect, Int32 zero);


//----------------------------------------------------------------------------------------
// Client definitions
//----------------------------------------------------------------------------------------

// Error codes for the filter
#define	FILTER_OK			0
#define	FILTER_CANCEL	1
#define	FILTER_ABORT	2			// filter action was stopped (TestBreak)

#define	FILTER_PARAM_ERR -1	// invalid parameter
#define	FILTER_MEM_ERR	 -2	// not enough memory
#define	FILTER_MISC_ERR	 -3	// specific reason for error is unknown (e.g. intializing a class did not work)


// filter actions
typedef	Int32	TYPE_filter_start (FI_REF fi, BM_REF bm, FILTER_PARAM settings);
typedef	Int32	TYPE_filter_end (FI_REF fi, BM_REF bm, FILTER_PARAM settings);
typedef	Int32	TYPE_filter_run (FI_REF fi, BM_REF bm, FILTER_PARAM settings, Bool use_gui);

// filter settings
typedef	FILTER_PARAM TYPE_filter_new_settings (FI_REF fi, const BaseContainer * bc);
typedef	Int32	TYPE_filter_delete_settings (FI_REF fi, FILTER_PARAM settings);
typedef	FLAT_FILTER_SETTINGS* TYPE_filter_flatten_settings (FI_REF fi, FILTER_PARAM settings, void*(*flat_malloc)(Int32 size));
typedef	FILTER_PARAM TYPE_filter_unflatten_settings (FI_REF fi, FLAT_FILTER_SETTINGS * flat_settings);


//----------------------------------------------------------------------------------------
// function pointers
//----------------------------------------------------------------------------------------

#define BITMAPFILTER_MAGIC_V2	'bmpf'
#define BITMAPFILTER_MAGIC_V3	'bmf3'

struct BITMAP_FILTER
{
	Int32	magicid;

	// filter settings
	TYPE_filter_new_settings*				filter_new_settings;
	TYPE_filter_delete_settings*		filter_delete_settings;
	TYPE_filter_flatten_settings*		filter_flatten_settings;
	TYPE_filter_unflatten_settings* filter_unflatten_settings;

	// filter actions
	TYPE_filter_start* filter_start;
	TYPE_filter_end*	 filter_end;
	TYPE_filter_run*	 filter_run;

	// BITMAPFILTER_MAGIC_V3
	UInt32 flags;
#define BMFI_SUPPORT_8BIT		 (1 << 0)
#define BMFI_SUPPORT_16BIT	 (1 << 1)
#define BMFI_SUPPORT_32BIT	 (1 << 2)
#define BMFI_SUPPORT_NO_GREY (1 << 3)
#define BMFI_SUPPORT_NO_RGB	 (1 << 4)
};

#endif // X4D_FILTER_H__
