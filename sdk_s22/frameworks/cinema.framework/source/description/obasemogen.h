#ifndef OBASEMOGEN_H__
#define OBASEMOGEN_H__

enum
{
	ID_MG_MOTIONGENERATOR_GROUP_EFFECTORS = 990,	// Effectors Group
	ID_MG_MOTIONGENERATOR_GROUP_TRANSFORM = 991,	// Transform Group
	ID_MG_MOTIONGENERATOR_GROUP_TRNPSR		= 992,	// Transform PSR Group
	ID_MG_MOTIONGENERATOR_GROUP_TRNRANDOM = 993,	// Transform Randomize Group
	ID_MG_MOTIONGENERATOR_GROUP_DISTRIBUTION = 994,	// Distributions
	ID_MG_MOTIONGENERATOR_GROUP_DISTRIBUTIONSELECTEDUI = 995, // Distribution pattern UI
	ID_MG_MOTIONGENERATOR_GROUP_DISTRIBUTION_SUBGROUP = 996, // Distribution wrapper group to hide everything when disabled
	ID_MG_MOTIONGENERATOR_GROUP_DISTRIBUTIONMODE = 997,

	ID_MG_MOTIONGENERATOR_DRAW						= 2000,	// Allow grid drawing
	ID_MG_MOTIONGENERATOR_EFFECTORLIST		= 2009,	// Effectors list

	ID_MG_MOTIONGENERATOR_MODE						= 2010,	// Cloning mode
	ID_MG_MOTIONGENERATOR_MODE_OBJECT			= 0,		// Object cloning mode
	ID_MG_MOTIONGENERATOR_MODE_LINEAR			= 1,		// Linear cloning mode
	ID_MG_MOTIONGENERATOR_MODE_RADIAL			= 2,		// Radial cloning mode
	ID_MG_MOTIONGENERATOR_MODE_GRIDARRAY	= 3,		// Grid Array cloning mode;
	ID_MG_MOTIONGENERATOR_MODE_HEXARRAY		= 4,		// Honeycomb Grid Array cloning mode;
	ID_MG_MOTIONGENERATOR_MODE_DISTRIBUTIONS = 5,	// New distributions hook point.
	ID_MG_MOTIONGENERATOR_MODE_RESERVED		= 2011,	// Future for using new modes
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_ENABLE = 2014,		// Switch flag between legacy and new modes.

	ID_MG_MOTIONGENERATOR_DISTRIBUTION_CATEGORY			= 2100,		// Category index, only valid at runtime.
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_CATEGORYID		= 2101,		// Category id, used for serialization.
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_MODE					= 2102,		// Mode index, only valid at runtime.
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_MODEID				= 2103,		// Mode id, used for serialization.
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_EDIT					= 2104,		// Edit node graph
	ID_MG_MOTIONGENERATOR_DISTRIBUTION_CLEAR_GRAPH	= 2105,		// Clear node graph
};
#endif																					// OBASEMOGEN_H__
