#ifndef NEW_TRETARGET_H__
#define NEW_TRETARGET_H__

enum
{
	NEW_RT_SOURCE             = 10001, // link
	NEW_RT_DEST               = 10002, // link
	NEW_RT_REF                = 10003, // link
	NEW_RT_USE_HIERARCHY      = 10004, // bool
	NEW_RT_LEGACY             = 10005, // group

	RT_SAVED_SOURCE       = 10006, // link
	RT_SAVED_DEST         = 10007, // link
	RT_SAVED_REF          = 10008, // link
	RT_SAVED_HIERARCHICAL = 10009, // bool
	RT_SAVED_ASSO_MODE    = 10010, // int32
	RT_SAVED_SEPARATOR    = 10011, // String

	RT_AUTO_ASSO_MODE     = 11000, // int32  
	RT_ASSO_SOURCE        = 11001, // link
	RT_ASSO_DESTINATION   = 11002, // link	
	RT_ASSO_REFERENCE     = 11003, // link
	RT_ASSO_SEPARATOR     = 11004, // String
	  
	RT_ASSO_HIERARCHICAL = 0,
	RT_ASSO_FULL_NAME,
	RT_ASSO_NAMING_CONVENTION,

	RESCAN_BUTTON         =  3000, // Button
	RETARGET_RECURSIVE,            // Group
	RT_RECURSIVE_BUT,              // Button
	RT_RECURSIVE_DEST,             // link
	RT_RECURSIVE_SRC,              // link
	DEV_GROUP,                     // Group

	/////////////////////////////////////////////
	// Dev section for testing only
	RT_DEV_SETTINGS,               // Group
	RT_SRC_REF,                    // Link
	RT_DEST_REF,                   // Link
	RT_SET_REF_POSE_BUT,           // Button
	RT_REMOVE_REF_POSE_BUT,        // Button
	RT_ARE_REF_POSES_SET,          // Bool
	RT_RESET_TO_INITIAL_STATE,     // Button
	RT_ASSO_DEST_POSE,             // Link
	RT_ASSO_SRC_POSE,              // Link
	RT_USE_REF_POSE_BUT,           // Bool
	/////////////////////////////////////////////

	ID_ASSOCIATION_GROUP = 5000,
	ID_ASSOCIATION_LINKS_GROUP,    // Group
	ID_ASSOCIATION_POSE_GROUP,     // Group

	// TODO need to determine a number of elements, this is only arbitrary
	ID_ASSOCIATION_ELEMENTS = 999,
	ID_ASSOCIATION_COUNT = 12000,

	RT_ASSO_BEGIN   = 13000, 
	RT_ASSO_END     = 14000, 
	
	NEW_RT_DUMMY
};

#endif // NEW_TRETARGET_H__
