#ifndef NEW_TRETARGET_H__
#define NEW_TRETARGET_H__

enum
{
	NEW_RT_SOURCE                   = 10001, // link
	NEW_RT_DEST                     = 10002, // link

	// To preserve older projects, 10003 to 10005 won't be used

	RT_SAVED_SOURCE                 = 10006, // link
	RT_SAVED_DEST                   = 10007, // link
												          
	RT_MATCHING_METHOD              = 10008, // int32  
	RT_ASSO_SOURCE                  = 10009, // link
	RT_ASSO_DESTINATION             = 10010, // link	
	RT_ASSO_TYPE                    = 10011, // int32
	RT_MATCHING_SEPARATOR           = 10012, // String
	RT_ANIMATION_STRENGTH           = 10013, // Float
	RT_SCALE_FACTOR                 = 10014, // Float
	RT_AUTO_MATCH_BUTTON            = 10015, // Button
	RT_MATCHING                     = 10016, // Group
	RT_MATCHING_ITEMTREE            = 10017, // ItemTree
	RT_OBJECTS_GROUP                = 10018, // Group
	RT_POSE_ADD_FOLDER              = 10019, // Button
	RT_POSE_REMOVE_FOLDER           = 10020, // Button
	RT_MATCHING_ITEMTREE_GROUP      = 10021, // Group

	// Matching methods
	RT_MATCHING_METHOD_HIERARCHICAL = 0,     // int32
	RT_MATCHING_METHOD_NAMING,				       // int32

	// Type of associations
	RT_ASSO_TYPE_DEFAULT              = 0,   // int32
	RT_ASSO_TYPE_CONTROLLER,                 // int32
	RT_ASSO_TYPE_CHARACTER,                  // int32
	
	// Tree selected info
	RT_SHOW_NODE_INFO               = 10100, // Group
	RT_SHOW_NODE_NAME               = 10101, // String
	RT_SHOW_NODE_STRENGTH           = 10102, // Float
	RT_SHOW_NODE_SOURCE             = 10103, // Link
	RT_SHOW_NODE_TARGET             = 10104, // Link

	// All associations / folders
	RT_NODE_FOLDERS                 = 10300, // Group
	RT_NODE_ASSOCIATIONS            = 10301, // Group
	RT_NODE_TYPE_FOLDER             = 10302, // Int32
	RT_NODE_TYPE_ASSOCIATION        = 10303, // Int32
	//                                Removed Id 10304 while in alpha. Ids can be ordered before release
	RT_NODE_FOLDERS_LAST_INDEX      = 10305, // Int32
	RT_NODE_ASSOCIATIONS_COUNT      = 10306, // Int32
	RT_ITEMTREE_NODE_ID             = 10307, // Int32
	RT_ITEMTREE_NODE_TYPE           = 10308, // Int32
	RT_ITEMTREE_NODE_TARGET_LINK    = 10309, // Link
	RT_ITEMTREE_NODE_USE_REF_POSE   = 10310, // String
	RT_ITEMTREE_NODE_STRENGTH       = 10311, // String

	// Common node information
	RT_NODE_STRENGTH                = 0,     // Float
	RT_NODE_ENABLE,                          // Bool
	RT_NODE_UP_STRENGTH,                     // Float

	// Folder node information
	RT_NODE_FOLDER_NAME             = 1000,  // String

	// Association node information
	RT_NODE_ASSO_SOURCE             = 1000,  // Link
	RT_NODE_ASSO_TARGET,                     // Link
	RT_NODE_ASSO_SOURCE_REF,                 // Group
	RT_NODE_ASSO_TARGET_REF,                 // Group           
	RT_NODE_ASSO_SOURCE_IS_REF_SET,          // Bool
	RT_NODE_ASSO_TARGET_IS_REF_SET,          // Bool
	
	ID_REFERENCE_POSES              = 12000, // Group (tab)
	RT_FORCE_REF_POSES              = 12001, // Bool

	// Set source reference pose settings
	RT_POSE_SRC_GROUP               = 12100, // Group
	RT_POSE_SRC_USE_EXT_REF         = 12101, // Bool
	RT_POSE_SRC                     = 12102, // Link
	RT_POSE_SRC_SET_BUT             = 12103, // Button
	RT_POSE_SRC_CLEAR_BUT           = 12104, // Button
	RT_POSE_SRC_MATCHED_RATIO_STR   = 12105, // String
	RT_POSE_SRC_IS_SET              = 12106, // Bool
	RT_POSE_SRC_MATCHING_METHOD     = 12107, // Int32
	RT_POSE_SRC_MATCHING_SEPARATOR  = 12108, // String
	RT_POSE_SRC_MATCHING_SETTINGS   = 12109, // Group

	// Set target reference pose settings
	RT_POSE_DEST_GROUP              = 12200, // Group
	RT_POSE_DEST_USE_EXT_REF        = 12201, // Bool
	RT_POSE_DEST                    = 12202, // Link
	RT_POSE_DEST_SET_BUT            = 12203, // Button
	RT_POSE_DEST_CLEAR_BUT          = 12204, // Button
	RT_POSE_DEST_MATCHED_RATIO_STR  = 12205, // String
	RT_POSE_DEST_IS_SET             = 12206, // Bool
	RT_POSE_DEST_MATCHING_METHOD    = 12207, // Int32
	RT_POSE_DEST_MATCHING_SEPARATOR = 12208, // String
	RT_POSE_DEST_MATCHING_SETTINGS  = 12209, // Group
	
	// Pose informations, Id starts at 1 as RT_POSE_MG was removed. Before official build, we could set _UP_MG at 0
	// Same goes for RT_POSE_ABS_POS, that was remove
	RT_POSE_UP_MG                   = 1,     // Matrix
	RT_POSE_NAME                    = 3,     // String
	RT_POSE_ML                      = 4,     // Matrix

	// Infos for hashmap construction
	RT_REF_SRC_PARTS_GROUP          = 12300, // Group
	RT_REF_SRC_PARTS_COUNT          = 12301, // Int32
	RT_REF_SRC_PARTS_MATCHED_COUNT  = 12302, // int32	
	RT_REF_DEST_PARTS_GROUP         = 12303, // Group
	RT_REF_DEST_PARTS_COUNT         = 12304, // Int32
	RT_REF_DEST_PARTS_MATCHED_COUNT = 12305, // int32	
	
	// Link and its matched ref pose infos as hashmap entry
	RT_REF_PART                     = 0,     // link
	RT_REF_PART_INFO_BC,                     // group

	NEW_RT_DUMMY
};

#endif // NEW_TRETARGET_H__
