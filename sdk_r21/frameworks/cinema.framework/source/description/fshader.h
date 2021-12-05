#ifndef FSHADER_H__
#define FSHADER_H__

enum
{
	// Careful not to clash with other shader params ID_MG_SHADER_CHANNELSELECT...

	ID_MG_SHADER_MODE_DEPRECATED = 2000,	// Int Cycle
	ID_MG_SHADER_GROUPSHADER2_DEPRECATED = 2001,

	FIELD_SHADER_FRAME_DEPENDENT = 2010,	// Bool
	FIELD_SHADER_REFRESH_GROUP = 2011,		// Group

};
#endif	// FSHADER_H__
