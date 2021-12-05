#ifndef OBASEMOGEN_H__
#define OBASEMOGEN_H__

enum
{
	ID_MG_MOTIONGENERATOR_GROUP_EFFECTORS = 990,	// Effectors Group
	ID_MG_MOTIONGENERATOR_GROUP_TRANSFORM = 991,	// Transform Group
	ID_MG_MOTIONGENERATOR_GROUP_TRNPSR		= 992,	// Transform PSR Group
	ID_MG_MOTIONGENERATOR_GROUP_TRNRANDOM = 993,	// Transform Randomize Group

	ID_MG_MOTIONGENERATOR_DRAW						= 2000,	// Allow grid drawing
	ID_MG_MOTIONGENERATOR_EFFECTORLIST		= 2009,	// Effectors list

	ID_MG_MOTIONGENERATOR_MODE						= 2010,	// Cloning mode
	ID_MG_MOTIONGENERATOR_MODE_OBJECT			= 0,		// Object cloning mode
	ID_MG_MOTIONGENERATOR_MODE_LINEAR			= 1,		// Linear cloning mode
	ID_MG_MOTIONGENERATOR_MODE_RADIAL			= 2,		// Radial cloning mode
	ID_MG_MOTIONGENERATOR_MODE_GRIDARRAY	= 3,		// Grid Array cloning mode;
	ID_MG_MOTIONGENERATOR_MODE_HEXARRAY		= 4			// Honeycomb Grid Array cloning mode};
};
#endif																					// OBASEMOGEN_H__
