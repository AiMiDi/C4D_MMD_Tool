#ifndef Nsubstanceasset_H__
#define Nsubstanceasset_H__

enum
{
	Nsubstanceasset												= 1032106,
	SUBSTANCEASSET_PROPERTIES							= 2000,			// GROUP
	SUBSTANCEASSET_STATUS									= 1000,			// STATICTEXT
	SUBSTANCEASSET_FILENAME								= 1001,			// FILENAME
	SUBSTANCEASSET_MATERIAL								= 1002,			// GENERATED MATERIAL
	SUBSTANCEASSET_INPUT_MAPPING					= 1003,			// BaseContainer containing DescId <-> UId relation
	SUBSTANCEASSET_ENABLED								= 1004,			// BOOL
	SUBSTANCEASSET_NO_LEGACY_GAMMA				= 1005,			// BOOL
	SUBSTANCEASSET_LEGACY_GAMMA_HIDDEN		= 1006,			// BOOL

	SUBSTANCEASSET_INPUT_DYNAMIC_START		= 10000,		// start id of dynamic input parameters
	SUBSTANCEASSET_INPUT_DYNAMIC_END			= 89999,		// end id of dynamic input parameters

	SUBSTANCEASSET_OUTPUT_DYNAMIC_START		= 90000,		// start id of dynamic output channels
	SUBSTANCEASSET_OUTPUT_DYNAMIC_END			= 99999,		// end id of dynamic output channels

	SUBSTANCEASSET_GROUP_GRAPH						= 100000,		// special group id for "groupless" inputs
	SUBSTANCEASSET_GROUP_BASIC						= 101000,		// special group id for "groupless" inputs
	SUBSTANCEASSET_GROUP_OUTPUT						= 102000,		// special group id for image inputs
	SUBSTANCEASSET_GROUP_IMAGE						= 103000,		// special group id for image inputs
	SUBSTANCEASSET_GROUP_START						= 104000,		// start id of group ids
	SUBSTANCEASSET_GROUP_END							= 190000,		// end id of group ids
};

#endif //Nsubstanceasset_H__
