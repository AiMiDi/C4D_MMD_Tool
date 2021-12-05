/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CTRACKDATA_H__
#define C4D_CTRACKDATA_H__

#include "c4d_nodedata.h"

class CKey;
class CTrack;
class BaseList2D;
class BaseDocument;
class BaseTime;
class GeClipMap;
class CAnimInfo;

//----------------------------------------------------------------------------------------
/// A data class for creating timeline track plugins.\n
/// Use RegisterCTrackPlugin() to register a track plugin.
//----------------------------------------------------------------------------------------
class CTrackData : public NodeData
{
public:
	// Inherited from NodeData
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, maxon::String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// Inherited from NodeData

	//----------------------------------------------------------------------------------------
	/// Called during redraw or whenever @C4D wants to evaluate the animation track.
	/// @note All times are given with respect to time curves for instance, so time might not be the same as @c doc->GetTime().
	/// @calledThreadContext
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] info								The animation parameters.\n
	/// 															It is the responsibility of each track plugin to interpolate the values in @formatParam{info} correctly.
	/// @param[out] chg								If not @formatConstant{nullptr}, set it to @formatConstant{true} if the value has changed due to the animation.
	/// @param[out] data							If not @formatConstant{nullptr}, the animated value should not be applied to the object, but assigned to this parameter instead.
	/// @return												@trueIfOtherwiseFalse{the track was animated successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool Animate(CTrack* track, const CAnimInfo* info, Bool* chg, void* data);

	//----------------------------------------------------------------------------------------
	/// Called to process GUI messages e.g. for drag-and-drop, drawing etc.
	/// @markPrivate
	/// @see GeDialog::Message for more information.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] msg								The message container.
	/// @param[in,out] result					The message result container.
	/// @return												The GUI message return value.
	//----------------------------------------------------------------------------------------
	virtual Int32 GuiMessage(CTrack* track, const BaseContainer& msg, BaseContainer& result);

	//----------------------------------------------------------------------------------------
	/// Called to draw additional stuff, e.g. like the sound track draws a sound wave.\n
	/// @note Called when GetHeight() returns a positive height for the track of the sequence.
	/// @calledThreadContext
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[out] map								The clip map to draw to. @cinemaOwnsPointed{clip map}
	/// @param[in] clip_left					The left time clipping.
	/// @param[in] clip_right					The right time clipping.
	/// @return												@trueIfOtherwiseFalse{the track was drawn successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(CTrack* track, GeClipMap* map, const BaseTime& clip_left, const BaseTime& clip_right);

	//----------------------------------------------------------------------------------------
	/// Called to get the height to draw additional data for the sequence in the timeline, e.g. the sound wave of a sound track.\n
	/// The default value is @em 0, which means no additional data.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @return												The extra height of the track in pixels.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetHeight(CTrack* track);

	//----------------------------------------------------------------------------------------
	/// Called to fill a newly created key with default values for object @formatParam{bl}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] bl									The object of the key. @cinemaOwnsPointed{object}
	/// @param[out] key								The key to fill. @cinemaOwnsPointed{key}
	/// @return												@trueIfOtherwiseFalse{the key was filled successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool FillKey(CTrack* track, BaseDocument* doc, BaseList2D* bl, CKey* key);

	//----------------------------------------------------------------------------------------
	/// Called to set (@formatParam{set}=@formatConstant{true}) or get (@formatParam{set}==@formatConstant{false}) information for a track at the current time (@formatParam{key}==nullptr) or at a specified key.
	/// The information to get/set is available in @formatParam{str}. The information is shown in the UI for example when hovering over a value.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] key								The key that the information concerns or @formatConstant{nullptr} if the information concerns @c doc->GetTime(). @cinemaOwnsPointed{key}
	/// @param[in,out] str						The string to get/set.
	/// @param[in] set								@formatConstant{true} if the information should be set, otherwise @formatConstant{false} if it should be retrieved.
	/// @return												@trueIfOtherwiseFalse{the track information was get/set successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool TrackInformation(CTrack* track, BaseDocument* doc, CKey* key, maxon::String* str, Bool set);

	//----------------------------------------------------------------------------------------
	/// Handles NodeData::Message for the key @formatParam{node}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] node								The key node. @cinemaOwnsPointed{key}
	/// @param[in] type								The message type.
	/// @param[in,out] data						The message data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeyMessage(CTrack* track, CKey* node, Int32 type, void* data);

	//----------------------------------------------------------------------------------------
	/// Handles NodeData::GetDDescription for the key @formatParam{node}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] node								The key node. @cinemaOwnsPointed{key}
	/// @param[in,out] description		The description to add parameters to. @cinemaOwnsPointed{description}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeyGetDDescription(CTrack* track, CKey* node, Description* description, DESCFLAGS_DESC& flags);

	//----------------------------------------------------------------------------------------
	/// Handles NodeData::GetDParameter for the key @formatParam{node}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] node								The key node. @cinemaOwnsPointed{key}
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The current data for the parameter.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeyGetDParameter(CTrack* track, CKey* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);

	//----------------------------------------------------------------------------------------
	/// Handles NodeData::GetDEnabling for the key @formatParam{node}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] node								The key node. @cinemaOwnsPointed{key}
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The current data for the parameter.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @param[in] itemdesc						The description for the parameter, encoded to a container as described in Description.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeyGetDEnabling(CTrack* track, CKey* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// Handles NodeData::SetDParameter for the key @formatParam{node}.
	/// @param[in] track							Equal to @c static_cast<CTrack*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{track}
	/// @param[in] node								The key node. @cinemaOwnsPointed{key}
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The data for the parameter.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeySetDParameter(CTrack* track, CKey* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);
};

//----------------------------------------------------------------------------------------
/// Registers a custom timeline track plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{PLUGINFLAG}
/// @param[in] npalloc						The allocator for the track plugin. This is a pointer to a function that creates a new instance of CTrackData with NewObj().
/// @param[in] description				The name of the description resource file to use for the track plugin without @em .res extension, for example @em "CTpla".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the track plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterCTrackPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* npalloc, const maxon::String& description, Int32 disklevel);

#endif // C4D_CTRACKDATA_H__
