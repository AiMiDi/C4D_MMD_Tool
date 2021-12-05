/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_NODEDATA_H__
#define C4D_NODEDATA_H__

#include "c4d_basedata.h"
#include "ge_prepass.h"

class C4DAtom;
class GeListNode;
class HyperFile;
class AliasTrans;
class BaseDocument;
class String;
class Description;
class DescID;
class GeData;
class BaseContainer;
class BaseBitmap;
struct NODEPLUGIN;
struct BranchInfo;


//----------------------------------------------------------------------------------------
/// A data class for creating node plugins.
/// @note See the derived classes for creating standard node plugins, like objects, tags and materials.
///
/// Use RegisterNodePlugin() to register a node plugin.
//----------------------------------------------------------------------------------------
class NodeData : public BaseData
{
protected:
	GeListNode* private_link;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	NodeData() : private_link(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Gets the GeListNode connected with the NodeData instance.
	/// @return												The list node connected with this instance. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* Get(void) const { return private_link; }

	/// @name Init/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when a new instance of the node data is allocated.\n
	/// Allocate and initialize member variables of the node data class here.
	/// Fill also the container of the node data and connected nodes with default values:
	/// @code
	/// Bool BlinkerKey::Init(GeListNode *node)
	/// {
	/// 	BaseKey *op = (BaseKey*) node;
	/// 	BaseContainer *data = op->GetDataInstance();
	///
	/// 	data->SetFloat(BLINKERKEY_NUMBER, 1.0);
	/// 	data->SetFloat(BLINKERKEY_STRENGTH, 1.0);
	/// 	data->SetBool(BLINKERKEY_SOFT, false);
	///
	/// 	return true;
	/// }
	/// @endcode
	/// @note If the node data class has a constructor it is called as usual before, but at that time there is no GeListNode link established.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @return												@trueIfOtherwiseFalse{the @formatParam{node} was initialized}
	//----------------------------------------------------------------------------------------
	virtual Bool Init(GeListNode* node);

	//----------------------------------------------------------------------------------------
	/// Called when a node data instance is deallocated.\n
	/// Deallocate member variables of the node data class here.
	/// @note If the node data class has a destructor it is called as usual after.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	virtual void Free(GeListNode* node);

	/// @}

	/// @name Read/Write/Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when a node is loaded from a file.
	/// @warning If at least one of Read(), Write() and CopyTo() is implemented, it is recommended to implement all three, otherwise data might be lost.
	///
	/// Read any member variable for the node data class.
	/// <b>Example:</b>
	/// @code
	/// hf->ReadLong(&offset);
	/// hf->ReadBool(&object_access);
	/// @endcode
	/// For future extensions of the node data check the @formatParam{level} and only read the appropriate values:
	/// @code
	/// if (level >= 0)
	/// {
	/// 	hf->ReadLong(&offset);
	/// 	hf->ReadBool(&object_access);
	/// }
	/// if (level >= 1)
	/// {
	/// 	hf->ReadReal(&new_feature);
	/// }
	/// @endcode
	/// @note Init() is called before Read().
	/// @warning It is recommended to store as much as possible in the @formatParam{node}'s container as @C4D handles the reading of those values automatically. Only use member variables when necessary.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] hf									The hyper file to read from. @cinemaOwnsPointed{hyper file}
	/// @param[in] level							The plugin level is similar to a version number. The default level is @em 0.\n
	/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
	/// 															As an example you may have updated a plugin. If you now need to write additional information for new member variables or changed types for old members increase the level.\n
	/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
	/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
	/// 															@formatParam{level} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.\n\n
	/// 															If all values are stored in the @formatParam{node}'s container, you do not have to deal with the level.
	/// @return												@trueIfOtherwiseFalse{the @formatParam{node} was read}
	//----------------------------------------------------------------------------------------
	virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);

	//----------------------------------------------------------------------------------------
	/// Called when a node is saved to a file.
	/// @warning If at least one of Read(), Write() and CopyTo() is implemented, it is recommended to implement all three, otherwise data might be lost.
	///
	/// Write any member variable for the node data class.\n
	/// @b Example:
	/// @code
	/// hf->WriteLong(offset);
	/// hf->WriteBool(object_access);
	/// @endcode
	/// For future extensions of the node data make sure to introduce a new level when writing new values:
	/// @code
	/// // Level 0
	/// hf->WriteLong(offset);
	/// hf->WriteBool(object_access);
	///
	/// // Level 1
	/// hf->WriteReal(new_feature);
	/// @endcode
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] hf									The hyper file to write to. @cinemaOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the @formatParam{node} was written}
	//----------------------------------------------------------------------------------------
	virtual Bool Write(GeListNode* node, HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// Called when a node is duplicated.
	/// @warning If at least one of Read(), Write() and CopyTo() is implemented, it is recommended to implement all three, otherwise data might be lost.
	///
	/// Copy any member variable for the node plugin. Simply transfer from @formatParam{this} to @formatParam{dest} and/or @formatParam{snode} to @formatParam{dnode}:
	/// @code
	/// dest->offset = offset;
	/// dest->object_access = object_access;
	/// @endcode
	/// @note Init() is called for the destination node before.
	/// @warning It is recommended to store as much as possible in the node's container as @C4D handles the copying of those values automatically. Only use member variables when necessary.
	/// @param[out] dest							The destination node data. @cinemaOwnsPointed{node}
	/// @param[in] snode							The source node. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[out] dnode							The destination node. @cinemaOwnsPointed{node}
	/// @param[in] flags							The copy flags: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @senderOwnsPointed{alias translator}
	/// @return												@trueIfOtherwiseFalse{the @formatParam{node} was copied}
	//----------------------------------------------------------------------------------------
	virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called when a node receives messages.
	/// @see C4DAtom::Message
	/// @note Some notification messages are automatically passed along to branches: @ref MSG_POINTS_CHANGED, @ref MSG_POLYGONS_CHANGED and @ref MSG_SEGMENTS_CHANGED. This is for convenience and historical reasons.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] type								The message type: @enumerateEnum{MSG}
	/// @param[in,out] data						The message data. @senderOwnsPointed{data}
	/// @return												@formatConstant{true} or @formatConstant{false} depending on the message @formatParam{type}.
	//----------------------------------------------------------------------------------------
	virtual Bool Message(GeListNode* node, Int32 type, void* data);

	//----------------------------------------------------------------------------------------
	/// Called to create a contextual bubble help and status bar information for the node.
	/// @note	When dealing with strings it is advised to use the string resources files and the GeLoadString function.\n
	///				This keeps the plugin easy to localize for any language to support and makes full use of the language features of @C4D.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] str								The bubble help string.
	//----------------------------------------------------------------------------------------
	virtual void GetBubbleHelp(GeListNode* node, maxon::String& str);

	//----------------------------------------------------------------------------------------
	/// Called to tell @C4D how to retrieve the document for the @formatParam{node}.\n
	/// Any call to GeListNode::GetDocument() ends up here.
	/// @note Useful if new BaseList elements are defined.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @return												The document for the @formatParam{node}.
	//----------------------------------------------------------------------------------------
	virtual BaseDocument* GetDocument(GeListNode* node);

	//----------------------------------------------------------------------------------------
	/// Called to specify that the node acts as a container of other nodes.\n
	/// This is for instance used by the animator module to make sure that the nodes are animated. Simply fill in the passed array:
	/// @code
	/// info[0].head = myHead;
	/// info[0].name ="MyName";
	/// ...
	/// info[1].head = myOtherHead;
	/// ...
	/// return 2; // 2 elements filled
	/// @endcode
	/// @note For the standard node types, for example objects, it is not needed to override @ref GetBranchInfo. @C4D already knows that objects contain tags.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[out] info							An array of max BranchInfo structures to fill in. @cinemaOwnsPointed{array}
	/// @param[in] max								The number of BranchInfo structures in the info array.
	/// @param[in] flags							The get branch info flags: @enumerateEnum{GETBRANCHINFO}
	/// @return												The number of BranchInfo elements filled in the @formatParam{info} array.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetBranchInfo(GeListNode* node, BranchInfo* info, Int32 max, GETBRANCHINFO flags);

	//----------------------------------------------------------------------------------------
	/// Called to check if the @formatParam{node} is an instance of a base @formatParam{type}.
	/// @see C4DAtom::IsInstanceOf.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] type								The type to check.
	/// @return												@trueIfOtherwiseFalse{the @formatParam{node} is an instance of the given @formatParam{type}}
	//----------------------------------------------------------------------------------------
	virtual Bool IsInstanceOf(const GeListNode* node, Int32 type) const;

	/// @name Description
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to add parameters to the description for the node.\n
	/// Modify the passed @formatParam{description} as needed, set the appropriate @formatParam{flags} and then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDDescription(data, description, flags, parentdescription);
	/// @endcode
	/// @note If only a description resource is used it is not needed to overload @ref GetDDescription.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in,out] description		The node's description to add the parameters to. @cinemaOwnsPointed{description}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);

	//----------------------------------------------------------------------------------------
	/// Called to override the reading of description parameters.\n
	/// Necessary for parameters that are not simply stored in the node's container, e.g. the global position of an object.\n
	/// Modify the passed @formatParam{t_data} if the right @formatParam{id} is provided, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDParameter(data, id, t_data, flags);
	/// @endcode
	/// @note If only a description resource is used it is not needed to overload @ref GetDParameter.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The parameter data to return. @cinemaOwnsPointed{data}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_GET}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDParameter(GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to override the writing of parameters.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, store the data, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::SetDParameter(data, id, t_data, flags);
	/// @endcode
	/// @note If only a description resource is used it is not needed to overload @ref SetDParameter.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The parameter data to set. @cinemaOwnsPointed{data}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_SET}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to decide which description parameters should be enabled or disabled.\n
	/// Can be used both for parameters that are stored in the node's description and for dynamic parameters.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, and return @formatConstant{true} to enable the parameter or @formatConstant{false} to disable it. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDEnabling(data, id, t_data, flags, itemdesc);
	/// @endcode
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The parameter data. @cinemaOwnsPointed{data}
	/// @param[in] flags							Not used.
	/// @param[in] itemdesc						The parameter's description, encoded to a container as described in Description.
	/// @return												@trueIfOtherwiseFalse{the parameter should be enabled} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// Called by the Attribute Manager for every object and every description ID.\n
	/// Gives a node data the opportunity to route a description ID in the description of a GeListNode to another one.\n
	/// For example used for tags that are embedded in an object description so that the keyframer for a tag property creates the track on the tag and not on the object.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] id									The source description ID.
	/// @param[out] res_id						Assign the target description ID.
	/// @param[out] res_at						Assign the target object.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool TranslateDescID(GeListNode* node, const DescID& id, DescID& res_id, C4DAtom*& res_at);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called by the Attribute Manager for correct undo handling.
	/// @warning Should not be overloaded by regular plugins and should be used with extra care. If @formatConstant{false} is returned no undo is possible.
	/// @param[in] node								The GeListNode connected with the NodeData instance. Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] docrelated					Assign @formatConstant{true} if the node is part of the document, otherwise @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool IsDocumentRelated(const GeListNode* node, Bool& docrelated) const;
};

/// NodeData allocator.
typedef NodeData* DataAllocator (void);

/// @markPrivate
void FillNodePlugin(NODEPLUGIN* np, Int32 info, DataAllocator* g, BaseBitmap* icon, Int32 disklevel);

//----------------------------------------------------------------------------------------
/// Registers a node plugin.
/// @note Normally this function is not used, but rather the specific registration functions for each NodeData child class.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The node plugin info flags: @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the node plugin. This is a pointer to a function that creates a new instance of NodeData with NewObj().
/// @param[in] icon								The icon for the node. The bitmap is copied. \n
/// 															The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
/// 															It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @param[in] fallback						@markPrivate
/// @return												@trueIfOtherwiseFalse{the node plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterNodePlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, BaseBitmap* icon, Int32 disklevel, Int32* fallback);

#endif // C4D_NODEDATA_H__
