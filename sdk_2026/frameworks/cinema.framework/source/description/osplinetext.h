#ifndef OSPLINETEXT_H__
#define OSPLINETEXT_H__

enum
{
	PRIM_TEXT_TEXT						= 2111,  // STRING - Text
	PRIM_TEXT_ALIGN						= 2112,	 // LONG - [0:Left; 1:Middle; 2:Right]
		PRIM_TEXT_ALIGN_LEFT			= 0,
		PRIM_TEXT_ALIGN_MIDDLE		= 1,
		PRIM_TEXT_ALIGN_RIGHT			= 2,
	PRIM_TEXT_HSPACING				= 2113,	// REAL - Horizontal Spacing
	PRIM_TEXT_VSPACING				= 2114,	// REAL - Vertical Spacing
	PRIM_TEXT_HEIGHT					= 2115,	// REAL - Vertical Spacing
	PRIM_TEXT_SEPARATE				= 2116,	// Bool - separate letters (make editable)
	PRIM_TEXT_FONT						= 2117, // FONT
	PRIM_TEXT_KERNING					= 2118	// Kerning
};

#endif // OSPLINETEXT_H__

