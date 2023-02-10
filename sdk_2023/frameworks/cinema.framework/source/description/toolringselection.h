#ifndef TOOLRINGSELECTION_H__
#define TOOLRINGSELECTION_H__

enum
{
	MDATA_RING_SEL_STOP_AT_SELECTIONS			= 1100, // BOOL
	MDATA_RING_SEL_STOP_AT_NON_QUADS			= 1110, // BOOL
	MDATA_RING_SEL_STOP_AT_POLES					= 1120, // BOOL
	MDATA_RING_FIRST_VERTEX								= 1130, // LONG
	MDATA_RING_SECOND_VERTEX							= 1131, // LONG
	MDATA_RING_POLYGON_INDEX							= 1132, // LONG
	MDATA_RING_BOTH_SIDES									= 1133, // BOOL
	MDATA_RING_SWAP_SIDES									= 1134, // BOOL
	MDATA_RING_SELECTION_TYPE							= 1140, // LONG (must be SELECTION_NEW, SELECTION_ADD or SELECTION_SUB)
	MDATA_RING_SEL_POLYGON_OBJECT					= 1150, // LINK
};

#endif // TOOLRINGSELECTION_H__