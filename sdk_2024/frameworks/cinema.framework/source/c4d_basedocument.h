/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEDOCUMENT_H__
#define C4D_BASEDOCUMENT_H__

#ifdef __API_INTERN__
	#error "Do not include in the kernel"
#endif


namespace maxon
{
class UpdatableAssetRepositoryRef;
class DocumentModeControllerRef;
}

#include "c4d_baselist.h"
#include "c4d_file.h"
#include "c4d_tools.h"
#include "operatingsystem.h"

namespace maxon
{
class OcioConfig;
class ColorProfile;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseTag;
class TextureTag;
class BaseObject;
class BaseMaterial;
class C4DThread;
class BaseSound;
class TakeData;

#define BdCall(fnc) (this->*C4DOS_Bd->fnc)

//-------------------------------------------------------------------------------------------------
/// The class for plugin scene hooks. Cannot be instantiated.\n
/// Call FindPlugin() or FilterPluginList() with the plugin type @ref PLUGINTYPE::SCENEHOOK to retrieve scene hook instances. You can alternatively browse through all the plugin instances with GetFirstPlugin().
/// @see SceneHookData
//-------------------------------------------------------------------------------------------------
class BaseSceneHook : public BaseList2D
{
private:
	BaseSceneHook();
	~BaseSceneHook();

public:
	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool InitDisplayControl(BaseDocument* doc, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void FreeDisplayControl();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const;

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void Draw(BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags);
};

//-------------------------------------------------------------------------------------------------
/// The node for multipass. The @em VPBUFFER type and description parameters are stored in its container.\n
/// Here is how to allocate and insert a multipass in the active document:
/// @code
/// // Allocate a MultipassObject.
/// MultipassObject* multipass = (MultipassObject*)MultipassObject::Alloc(Zmultipass);
/// if (multipass==nullptr)
/// 	return false;
///
/// // Get the multipass container instance.
/// BaseContainer& data = multipass->GetDataInstanceRef();
///
/// // Set the multipass type to RGBA.
/// data.SetInt32(MULTIPASSOBJECT_TYPE, VPBUFFER_RGBA);
///
/// RenderData* rd = doc->GetActiveRenderData();
/// if (rd==nullptr)
/// 	return false;
///
/// doc->StartUndo();
///
/// // Insert the multipass in the active document render data.
/// rd->InsertMultipass(multipass, nullptr);
///
/// doc->AddUndo(UNDOTYPE::NEWOBJ, multipass);
/// doc->EndUndo();
///
/// // Update the render data.
/// rd->Message(MSG_UPDATE);
/// EventAdd();
/// @endcode
//-------------------------------------------------------------------------------------------------
class MultipassObject : public BaseList2D
{
private:
	MultipassObject();
	~MultipassObject();

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next multipass channel in the list. Convenience version of GeListNode::GetNext() returning a pointer to a MultipassObject.
	/// @return												The next multipass channel, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	MultipassObject* GetNext() { return (MultipassObject*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous multipass channel in the list. Convenience version of GeListNode::GetNext() returning a pointer to a MultipassObject.
	/// @return												The previous multipass channel, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	MultipassObject* GetPred() { return (MultipassObject*)AtCall(GetPred) (); }

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// The RenderData class contains a container with all render settings. One can add multiple render data classes to a document. The active one will be used for the render.\n
/// The render settings in @C4D are description based. The valid IDs are listed in @em drendersettings.h (open @C4D render settings for more information, see @em drendersettings.res for the container definition).
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class RenderData : public BaseList2D
{
private:
	RenderData();
	~RenderData();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{render data}
	/// @return												@allocReturn{render data}
	//----------------------------------------------------------------------------------------
	static RenderData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{render data}
	/// @param[in,out] bl							@theToDestruct{render data}
	//----------------------------------------------------------------------------------------
	static void Free(RenderData*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next render data in the list. Convenience version of GeListNode::GetNext() returning a pointer to a RenderData.
	/// @return												The next render data, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetNext() { return (RenderData*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous render data in the list. Convenience version of GeListNode::GetPred() returning a pointer to a RenderData.
	/// @return												The previous render data, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetPred() { return (RenderData*)AtCall(GetPred) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent render data of the list node. Convenience version of GeListNode::GetUp() returning a pointer to a RenderData.
	/// @return												The parent render data, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetUp() { return (RenderData*)AtCall(GetUp) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child render data of the list node. Convenience version of GeListNode::GetDown() returning a pointer to a RenderData.
	/// @return												The first child render data, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetDown() { return (RenderData*)AtCall(GetDown) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child render data of the list node. Convenience version of GeListNode::GetDownLast() returning a pointer to a RenderData.
	/// @return												The last child render data, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetDownLast() { return (RenderData*)AtCall(GetDownLast) (); }

	/// @}

	/// @name VideoPost
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first video post of the render data.
	/// @return												The first video post. @theOwnsPointed{render data, video post}
	//----------------------------------------------------------------------------------------
	BaseVideoPost* GetFirstVideoPost();

	//----------------------------------------------------------------------------------------
	/// Inserts @formatParam{pvp} as a video post in the render data. The insertion position can be specified with @formatParam{pred}, inserting the video post below the specified @formatParam{pred} video post.
	/// @param[in] pvp								The video post to insert. The render data takes over the ownership of the pointed video post.
	/// @param[in] pred								The optional video post to insert @formatParam{pvp} after, or @formatConstant{nullptr} (default) to insert it first.
	//----------------------------------------------------------------------------------------
	void InsertVideoPost(BaseVideoPost* pvp, BaseVideoPost* pred = nullptr);

	//----------------------------------------------------------------------------------------
	/// Inserts @formatParam{pvp} as the last video post in the render data.
	/// @param[in] pvp								The video post to insert last. The render data takes over the ownership of the pointed video post.
	//----------------------------------------------------------------------------------------
	void InsertVideoPostLast(BaseVideoPost* pvp);

	/// @}

	/// @name Multipass
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first multipass channel MultipassObject of the render data. The other multipass channels in the render data can be accessed by using the base class list functions, MultipassObject::GetNext().
	/// @return												The first multipass channel, or @formatConstant{nullptr} if there is no multipass channels in the render data. @theOwnsPointed{render data,multipass}
	//----------------------------------------------------------------------------------------
	MultipassObject* GetFirstMultipass();

	//----------------------------------------------------------------------------------------
	/// Inserts the multipass channel @formatParam{obj} into the render data.\n
	/// The insertion position can be specified with @formatParam{pred}, inserting the multipass below the specified @formatParam{pred} multipass. Otherwise the multipass channel is inserted at the first position in the list.
	/// @param[in] obj								The multipass channel to insert. The render data takes over the ownership of the pointed multipass.
	/// @param[in] pred								The optional multipass to insert @formatParam{obj} after, or @formatConstant{nullptr} (default) to insert it first.
	//----------------------------------------------------------------------------------------
	void InsertMultipass(MultipassObject* obj, MultipassObject* pred = nullptr);

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// Represents a layer in a document.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class LayerObject : public BaseList2D
{
private:
	LayerObject();
	~LayerObject();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{layer}
	/// @return												@allocReturn{layer}
	//----------------------------------------------------------------------------------------
	static LayerObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{layers}
	/// @param[in] bl									@theToDestruct{layer}
	//----------------------------------------------------------------------------------------
	static void Free(LayerObject*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next layer in the list. Convenience version of GeListNode::GetNext() returning a pointer to a LayerObject.
	/// @return												The next layer, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	LayerObject* GetNext() { return (LayerObject*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous layer in the list. Convenience version of GeListNode::GetPred() returning a pointer to a LayerObject.
	/// @return												The previous layer, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	LayerObject* GetPred() { return (LayerObject*)AtCall(GetPred) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent layer of the list node. Convenience version of GeListNode::GetUp() returning a pointer to a LayerObject.
	/// @return												The parent layer, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	LayerObject* GetUp() { return (LayerObject*)AtCall(GetUp) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child layer of the list node. Convenience version of GeListNode::GetDown() returning a pointer to a LayerObject.
	/// @return												The first child layer, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	LayerObject* GetDown() { return (LayerObject*)AtCall(GetDown) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child layer of the list node. Convenience version of GeListNode::GetDownLast() returning a pointer to a LayerObject.
	/// @return												The last child layer, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	LayerObject* GetDownLast() { return (LayerObject*)AtCall(GetDownLast) (); }

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// Holds information data about a layer in a document.
/// @see BaseList2D::GetLayerData() BaseList2D::SetLayerData()
//-------------------------------------------------------------------------------------------------
struct LayerData
{
	/// Solo Mode.
	/// @note After setting the LayerData solo mode the document's @ref NBIT::SOLO_LAYER bit has to be cleared:
	/// @code
	/// // Get the list head for the document's layers.
	/// GeListHead* list = doc->GetLayerObjectRoot();
	/// if (list==nullptr)
	/// 	return false;
	///
	/// LayerObject* layer = (LayerObject*)list->GetFirst();
	/// if (layer==nullptr)
	/// 	return true;
	///
	/// // Get the LayerData.
	/// const LayerData* data = layer->GetLayerData(doc, true);
	/// LayerData newdata(*data);
	/// // Set the solo mode to false
	/// newdata.solo = false;
	///
	/// doc->StartUndo();
	///
	/// // Set the new layer data with the changed solo mode.
	/// doc->AddUndo(UNDO_CHANGE, layer);
	/// layer->SetLayerData(doc, newdata);
	///
	/// // Clear the Solo bit.
	/// doc->AddUndo(UNDO_BITS, doc);
	/// doc->ChangeNBit(NBIT::SOLO_LAYER, NBITCONTROL::CLEAR);
	/// doc->EndUndo();
	///
	/// EventAdd();
	/// @endcode
	Bool solo;

	Bool view;				///< Visible in editor view.
	Bool render;			///< Visible in render view.
	Bool manager;			///< Visible in Object Manager and Timeline.
	Bool locked;			///< Not selectable and no modification possible, grayed out in Object Manager.
	Bool generators;	///< Generators on/off.
	Bool deformers;		///< Deformers on/off.
	Bool expressions;	///< Expressions on/off.
	Bool animation;		///< Animation on/off.

	Vector color;			///< Layer color.

	Bool xref;				///< Import with XRef.

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	LayerData()
	{
		solo = false;
		view = true;
		render = true;
		manager = true;
		locked = false;
		deformers = true;
		generators = true;
		expressions = true;
		animation = true;
		xref = true;
		color = Vector(1.0);
	}
};


/// @addtogroup SELECTION
/// @ingroup group_enumeration
/// @{
#define SELECTION_NEW 0			///< Starts a new selection.
#define SELECTION_ADD 1			///< Adds to the current selection.
#define SELECTION_SUB 2			///< Subtracts from the current selection.
/// @}


struct PickSessionDataStruct;

//----------------------------------------------------------------------------------------
/// Pick session callback. Called when a pick session has been started.\n
/// Used to change the state of the pick session button for instance and to check if a pick session has been canceled.
/// @see PickSessionDataStruct for an example.
/// @param[in] flags							Flags: @ref PICKSESSION_FLAG_CANCELED.
/// @param[in] psd								The passed pick session data structure.
//----------------------------------------------------------------------------------------
typedef void (*PickSessionCallBack)(Int32 flags, const PickSessionDataStruct* psd);

#define PICKSESSION_FLAG_CANCELED 1			///< Pick session was canceled.

//-------------------------------------------------------------------------------------------------
/// A pick session allows to select objects in the viewport or in the Object Manager.\n
/// An example of pick session is the way objects are selected for a link field pressing its interrogation's button.\n
/// A session is usually started with BaseDocument::StartPickSession() and can be ended by the developer with BaseDocument::StopPickSession().\n
/// @b Example:<br>
/// First, declare a static variable for the pick session data:
/// @code static PickSessionDataStruct* pickSessionData = nullptr; @endcode
/// Define two functions to allocate and free the session data:
/// @code
/// Bool AllocPickSession()
/// {
/// 	pickSessionData = NewObj(PickSessionDataStruct);
/// 	return pickSessionData!=nullptr;
/// }
///
/// void FreePickSession()
/// {
/// 	DeleteObj(pickSessionData);
/// }
/// @endcode
/// In PluginStart() (usually defined in the @em Main.cpp of the plugin) call @em AllocPickSession() and in PluginEnd() call @em FreePickSession().\n
/// Do not forget to forward declare @em AllocPickSession() and @em FreePickSession() at the beginning of @em Main.cpp. (Otherwise linking errors are raised by the compiler.)\n
/// Then the pick data can be initialized and the session started:
/// @code
/// if (pickSessionData)
/// {
/// 	doc->StopPickSession(true);
/// 	pickSessionData->multi = true;
/// 	pickSessionData->callback = pickSessionCallBack;
/// 	doc->StartPickSession(pickSessionData);
/// }
/// @endcode
/// PickSessionDataStruct::multi is set to @formatConstant{true} to start a multi-object pick session. It is also possible to assign custom data to PickSessionDataStruct::userdata for use in the pick session callback.\n
/// Finally, the callback can be defined like this:
/// @code
/// void pickSessionCallBack(Int32 flags, const PickSessionDataStruct *psd)
/// {
/// 	for (Int32 i=0; i<psd->active->GetCount(); i++)
/// 	{
/// 		C4DAtom* atom = psd->active->GetIndex(i);
/// 		if (atom && atom->IsInstanceOf(Obase))
/// 		{
/// 			BaseObject *ob = (BaseObject*)atom;
/// 			if (ob)
/// 				GePrint(ob->GetName());
/// 		}
/// 	}
/// }
/// @endcode
/// The callback is called when the pick session has ended. PickSessionDataStruct::active holds the list of picked objects. In this example, the name of the selected object(s) during the pick session is printed to the console.
/// @note	Drag&Drop is handled automatically for an AtomArray by this functionality.\n
///				If GeUserArea::HandleMouseDrag() is used with an AtomArray, all the objects in the array are pickable. There is no additional work needed.
//-------------------------------------------------------------------------------------------------
struct PickSessionDataStruct
{
	AtomArray* active;								///< Filled with the picked objects.
	maxon::Delegate<void(Int32, const PickSessionDataStruct*)> callback;	///< The pick session callback. The arguments are the flags and the populated PickSesionDataStruct with any selected objects linked in the active AtomArray
	void* userdata;										///< The user data passed to the pick session @ref callback. @callerOwnsPointed{user data}
	Bool multi;												///< Set to @formatConstant{true} for multi-pick sessions. Usually a pick session ends when something is selected. With a multi-pick session it ends when the user terminates it (@em ESC or @em double-click).

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	PickSessionDataStruct()
	{
		callback = nullptr;
		userdata = nullptr;
		multi = false;
		active = AtomArray::Alloc();
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~PickSessionDataStruct()
	{
		AtomArray::Free(active);
	}
};

//----------------------------------------------------------------------------------------
/// doc->GetDataInstanceRef().GetBool(BASEDOCUMENT_PREVIEWSCENE_MARKER) returns if the scene is a material preview scene
//----------------------------------------------------------------------------------------
#define BASEDOCUMENT_PREVIEWSCENE_MARKER 200001037

//-------------------------------------------------------------------------------------------------
/// This class contains the complete description of a scene.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseDocument : public BaseList2D
{
private:
	BaseDocument();
	~BaseDocument();

public:

	/// @name Alloc/Free/Flush
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{document}
	/// @return												@allocReturn{document}
	//----------------------------------------------------------------------------------------
	static BaseDocument* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{documents}
	/// @param[in,out] bl							@theToDestruct{document}
	//----------------------------------------------------------------------------------------
	static void Free(BaseDocument*& bl);

	//-------------------------------------------------------------------------------------------------
	/// Empties the document; deletes and frees all resources used.
	//-------------------------------------------------------------------------------------------------
	void Flush();

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next document in the list. Convenience version of GeListNode::GetNext() returning a pointer to a BaseDocument.
	/// @return												The next document, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetNext() { return (BaseDocument*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous document in the list. Convenience version of GeListNode::GetNext() returning a pointer to a BaseDocument.
	/// @return												The previous document, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetPred() { return (BaseDocument*)AtCall(GetPred) (); }

	/// @}

	/// @name Data/Settings
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the container settings of the specified @formatParam{type}.
	/// @param[in] type								Selects the type of settings to get for the document: @enumerateEnum{DOCUMENTSETTINGS}
	/// @return												The settings for the document.
	//----------------------------------------------------------------------------------------
	BaseContainer GetData(DOCUMENTSETTINGS type) const { return C4DOS_Bd->GetData(this, type); }

	//----------------------------------------------------------------------------------------
	/// Merges the container for the settings of the specified @formatParam{type}.
	/// @param[in] type								Selects the type of settings to merge for the document: @enumerateEnum{DOCUMENTSETTINGS}
	/// @param[in] bc									The container to take the new settings from.
	//----------------------------------------------------------------------------------------
	void SetData(DOCUMENTSETTINGS type, const BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the container settings of the specified type. Changes to the pointed container are reflected in the document so it is not needed to call SetData() manually.
	/// @param[in] type								Selects the type of settings to get for the document: @enumerateEnum{DOCUMENTSETTINGS}
	/// @return												The pointer to the settings container. @theOwnsPointed{document,container}
	//----------------------------------------------------------------------------------------
	const BaseContainer* GetSettingsInstance(Int32 type) const { return C4DOS_Bd->GetDataInstance(this, type); }

	BaseContainer* GetSettingsInstance(Int32 type) { return C4DOS_Bd->GetDataInstanceWritable(this, type); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a context on a client during a NET rendering.
	/// @since R16
	/// @return												The information about the current NET rendering. @cinemaOwnsPointed{structure}
	//----------------------------------------------------------------------------------------
	NetRenderDocumentContext* GetNetRenderDocumentContext() const;

	//----------------------------------------------------------------------------------------
	/// Sets the current context on a client during a NET rendering.
	/// @since R16
	/// @param[in] context						The information about the current NET rendering. @callerOwnsPointed{structure}
	//----------------------------------------------------------------------------------------
	void SetNetRenderDocumentContext(NetRenderDocumentContext* context);

	/// @}

	/// @name Object/Material/Tag/Render Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first object of the document. The other objects in the document can be accessed with BaseObject::GetNext(), BaseObject::GetPred(), BaseObject::GetDown() etc.
	/// @return												The first object of the document, or @formatConstant{nullptr} if there are no objects in the document. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetFirstObject() const;

	//----------------------------------------------------------------------------------------
	/// Gets the first material of the document. The other materials in the document can be accessed with BaseMaterial::GetNext() and BaseMaterial::GetPred().
	/// @return												The first material of the document, or @formatConstant{nullptr} if there are no materials in the document. @theOwnsPointed{document,material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetFirstMaterial() const;

	//----------------------------------------------------------------------------------------
	/// Gets the first render data or options of the document. The other render settings in the document can be accessed by using the base class list functions, RenderData::GetNext(), RenderData::GetPred(), RenderData::GetDown() etc.
	/// @return												The first render data of the document, or @formatConstant{nullptr} if there are no render data associated with the document. @theOwnsPointed{document,render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetFirstRenderData() const;

	//----------------------------------------------------------------------------------------
	/// Gets the first scene hook of the document.
	/// @return												The first scene hook of the document.
	//----------------------------------------------------------------------------------------
	BaseSceneHook* GetFirstSceneHook() const;

	//----------------------------------------------------------------------------------------
	/// Inserts the object into the document's object hierarchy.\n
	/// Optionally the insertion position can either be specified by the @formatParam{parent} parameter, inserting the object as the first child of the specified @formatParam{parent}, or by the @formatParam{pred} parameter, inserting the object below the specified @formatParam{pred} object.\n
	/// If neither is given, the object is inserted at the top of the hierarchy.
	/// @note If both @formatParam{parent} and @formatParam{pred} are provided then @formatParam{pred} has precedence.
	/// @param[in] op									The object to insert into the document. The document takes over the ownership of the pointed object.
	/// @param[in] parent							An optional parent object in the document to insert the object as a child of. Can be @formatConstant{nullptr}. @callerOwnsPointed{object}
	/// @param[in] pred								An optional object in the document to use as insertion point. @callerOwnsPointed{object}
	/// @param[in] checknames					@markDeprecated
	/// @param[in] sendNotification		True to send MSG_DOCUMENTINFO_TYPE_OBJECT_INSERT notification all scenehook (default). False to prevent doing this.
	//----------------------------------------------------------------------------------------
	void InsertObject(BaseObject* op, BaseObject* parent, BaseObject* pred, Bool checknames = false, Bool sendNotification = true);

	//----------------------------------------------------------------------------------------
	/// Inserts the material into the document's material list.\n
	/// Optionally the insertion position can be specified by the @formatParam{pred} parameter, giving the material before (just to the left of) the wanted position. Otherwise the material is inserted at the first position in the list.
	/// @param[in] mat								The material to insert into the document. The document takes over the ownership of the pointed material.
	/// @param[in] pred								An optional material in the document to use as insertion point. @callerOwnsPointed{material}
	/// @param[in] checknames					@markDeprecated
	//----------------------------------------------------------------------------------------
	void InsertMaterial(BaseMaterial* mat, BaseMaterial* pred = nullptr, Bool checknames = false);

	//----------------------------------------------------------------------------------------
	/// Inserts the render data into the document's render settings hierarchy.\n
	/// Optionally the insertion position can either be specified by the @formatParam{parent} parameter, inserting the render data as the first child of the specified @formatParam{parent}, or by the @formatParam{pred} parameter, inserting the render data below the specified @formatParam{pred} render data.\n
	/// If neither is given, the render data is inserted at the top of the hierarchy.
	/// @param[in] rd									The render data to insert. The document takes over the ownership of the pointed render data.
	/// @param[in] parent							An optional parent to insert the render data as a child of. @callerOwnsPointed{render data}
	/// @param[in] pred								An optional render data of the document to use as insertion point. @callerOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	void InsertRenderData(RenderData* rd, RenderData* parent, RenderData* pred);

	//----------------------------------------------------------------------------------------
	/// Inserts the render data as last child into the document's render data list.
	/// @param[in] rd									The render data to insert. The document takes over the ownership of the pointed render data.
	//----------------------------------------------------------------------------------------
	void InsertRenderDataLast(RenderData* rd);

	//----------------------------------------------------------------------------------------
	/// Gets the active object in the document. This is the object the user has selected in the Object Manager.
	/// @return												The active object, or @formatConstant{nullptr} if no object is active. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetActiveObject() {return C4DOS_Bd->GetActiveObject(this); }

	/// @copydoc GetActiveObject
	const BaseObject* GetActiveObject() const { return MAXON_REMOVE_CONST(this)->GetActiveObject(); }

	//----------------------------------------------------------------------------------------
	/// Gets the active material in the document. This is the material the user has selected in the %Material Manager.
	/// @return												The active material, or @formatConstant{nullptr} if no material is active or multiple are selected. @theOwnsPointed{document,material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetActiveMaterial() { return C4DOS_Bd->GetActiveMaterial(this); }

	/// @copydoc GetActiveMaterial
	const BaseMaterial* GetActiveMaterial() const { return MAXON_REMOVE_CONST(this)->GetActiveMaterial(); }

	//----------------------------------------------------------------------------------------
	/// Gets the active tag in the document. This is the tag the user has selected in the Object Manager.
	/// @note Call GetActiveTags() to get multiple selections.
	/// @return												The active tag, or @formatConstant{nullptr} if no tag is active. @theOwnsPointed{document,tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetActiveTag() { return C4DOS_Bd->GetActiveTag(this, nullptr); }

	/// @copydoc GetActiveTag
	const BaseTag* GetActiveTag() const { return MAXON_REMOVE_CONST(this)->GetActiveTag(); }

	//----------------------------------------------------------------------------------------
	/// Gets the active render data for the document. These are the settings used for rendering the document.
	/// @return												The active rendering settings. @theOwnsPointed{document,render data}
	//----------------------------------------------------------------------------------------
	RenderData* GetActiveRenderData();

	/// @copydoc GetActiveRenderData
	const RenderData* GetActiveRenderData() const { return MAXON_REMOVE_CONST(this)->GetActiveRenderData(); }

	//----------------------------------------------------------------------------------------
	/// Gets the active object or the dummy axis if multiple objects are selected.
	/// @param[in] help								Can be set to @formatConstant{nullptr} or for speedup purposes pass an array of active objects. @callerOwnsPointed{atom array}
	/// @param[out] multi							Assigned @formatConstant{true} if multiple objects are selected. Can be @formatConstant{nullptr}.
	/// @return												The active object or the dummy axis if multiple objects are selected and @formatConstant{nullptr} if no object is selected. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetRealActiveObject(AtomArray* help, Bool* multi);

	//----------------------------------------------------------------------------------------
	/// Gets the active object multi-selection and optionally the selection order and/or children.
	/// @param[out] selection					Filled with the selected objects.
	/// @param[in] flags							Flags: @enumerateEnum{GETACTIVEOBJECTFLAGS}
	//----------------------------------------------------------------------------------------
	void GetActiveObjects(AtomArray& selection, GETACTIVEOBJECTFLAGS flags) const { BdCall(GetActiveObjects)(selection, flags); }

	//----------------------------------------------------------------------------------------
	/// Gets the subset of polygon objects in the active object multi-selection.
	/// @param[out] selection					Filled with the selected polygon objects.
	/// @param[in] children						If @formatConstant{true} then children are also added to selection, provided that they are selected. Otherwise only the topmost parent in each chain is added.
	//----------------------------------------------------------------------------------------
	void GetActivePolygonObjects(AtomArray& selection, Bool children) const;

	//----------------------------------------------------------------------------------------
	/// Gets the active object multi-selection and removes objects that do not match the filter given by @formatParam{type} and @formatParam{instanceof}.
	/// @param[out] selection					Filled with the selected objects.
	/// @param[in] children						If @formatConstant{true} then children are also added to selection, provided that they are selected. Otherwise only the topmost parent in each chain is added.
	/// @param[in] type								Checked against C4DAtom::GetType(). Pass @ref NOTOK to ignore the test.
	/// @param[in] instanceof					Checked against C4DAtom::IsInstanceOf(). Pass NOTOK to ignore the test.
	//----------------------------------------------------------------------------------------
	void GetActiveObjectsFilter(AtomArray& selection, Bool children, Int32 type, Int32 instanceof) const;

	//----------------------------------------------------------------------------------------
	/// Gets the active material multi-selection.
	/// @param[out] selection					Filled with the selected materials.
	//----------------------------------------------------------------------------------------
	void GetActiveMaterials(AtomArray& selection) const;

	//----------------------------------------------------------------------------------------
	/// Gets the active tag multi-selection.
	/// @param[out] selection					Filled with the selected tags.
	//----------------------------------------------------------------------------------------
	void GetActiveTags(AtomArray& selection) const;

	//----------------------------------------------------------------------------------------
	/// Gets the active selection. This function deals with both objects and tags.
	/// @param[out] selection					Filled with the objects and tags selection.
	//----------------------------------------------------------------------------------------
	void GetSelection(AtomArray& selection) const;

	//----------------------------------------------------------------------------------------
	/// Modifies the current object multi-selection with @formatParam{op} depending on @formatParam{mode}.
	/// @param[in] op									The object to use. Must be in the document already. @theOwnsPointed{document,object}
	/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
	//----------------------------------------------------------------------------------------
	void SetActiveObject(BaseObject* op, Int32 mode = SELECTION_NEW);

	//----------------------------------------------------------------------------------------
	/// Modifies the current material multi-selection with @formatParam{mat} depending on @formatParam{mode}.
	/// @param[in] mat								The material within the document that you want to make active. Must be in the document already. @theOwnsPointed{document,material}
	/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
	//----------------------------------------------------------------------------------------
	void SetActiveMaterial(BaseMaterial* mat, Int32 mode = SELECTION_NEW);

	//----------------------------------------------------------------------------------------
	/// Modifies the current tag multi-selection with @formatParam{tag} depending on @formatParam{mode}.
	/// @note This method also activates the object the tag is attached to if it was not previously activated.
	/// @param[in] tag								The tag to make active. Must be in the document already. @theOwnsPointed{document,tag}
	/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
	//----------------------------------------------------------------------------------------
	void SetActiveTag(BaseTag* tag, Int32 mode = SELECTION_NEW);

	//----------------------------------------------------------------------------------------
	/// Sets the active render data for the document. These are the settings that are used for rendering.
	/// @param[in] rd									The render data to make active. Must be in the document already. @theOwnsPointed{document,render data}
	//----------------------------------------------------------------------------------------
	void SetActiveRenderData(RenderData* rd);

	//----------------------------------------------------------------------------------------
	/// Sets the active selection. This function deals with both objects, tags and materials.
	/// @param[in] bl									The baselist object within the document that you want to make active. Must be in the document already. @theOwnsPointed{document,base list object}
	/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
	//----------------------------------------------------------------------------------------
	void SetSelection(BaseList2D* bl, Int32 mode = SELECTION_NEW);

	/// @}

	/// @name Search Object/Material
	/// @{

	//----------------------------------------------------------------------------------------
	/// Searches for an object with the case sensitive name given.
	/// @param[in] str								The case sensitive name of the object to search for.
	/// @return												The found object, or @formatConstant{nullptr} if no object was found. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* SearchObject(const maxon::String& str);

	//----------------------------------------------------------------------------------------
	/// Searches for a material with the case sensitive name given.
	/// @param[in] str								The case sensitive name of the material to search for.
	/// @return												The found material, or @formatConstant{nullptr} of no material was found. @theOwnsPointed{document,material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* SearchMaterial(const maxon::String& str);

	/// @}

	/// @name Changed State
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the document has been changed since it was last saved.
	/// @return												@trueIfOtherwiseFalse{the document was changed}
	//----------------------------------------------------------------------------------------
	Bool GetChanged();

	//-------------------------------------------------------------------------------------------------
	/// Sets the changed state of the document to reflect it has been modified.
	//-------------------------------------------------------------------------------------------------
	void SetChanged();

	/// @}

	/// @name Name/Path
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the name of the document.
	/// @return												The name of the file for the document.
	//----------------------------------------------------------------------------------------
	Filename GetDocumentName() const;

	//----------------------------------------------------------------------------------------
	/// Gets the path of the document.
	/// @return												The path of the file for the document. If the document has not been saved then the path is empty.
	//----------------------------------------------------------------------------------------
	Filename GetDocumentPath() const;

	//----------------------------------------------------------------------------------------
	/// Sets the name of the document.
	/// @param[in] fn									The new name for the document's file. Must contain the name part only.
	//----------------------------------------------------------------------------------------
	void SetDocumentName(const Filename& fn);

	//----------------------------------------------------------------------------------------
	/// Sets the path of the document.
	/// @param[in] path								The new path for the document's file. Must contain the path part only.
	//----------------------------------------------------------------------------------------
	void SetDocumentPath(const Filename& path);

	/// @}

	/// @name LOD
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the Level of Detail for the document.
	/// @return												The Level of Detail for the document.\n
	/// 															The default values are:
	/// 															- Low = 0.25
	/// 															- Medium = 0.5
	/// 															- High = 1.0
	//----------------------------------------------------------------------------------------
	Float GetLOD() const;

	//----------------------------------------------------------------------------------------
	/// Sets the Level of Detail for the document.
	/// @param[in] lod								The Level of Detail to set for the document.
	/// 															The default values are:
	/// 															- Low = 0.25
	/// 															- Medium = 0.5
	/// 															- High = 1.0
	//----------------------------------------------------------------------------------------
	void SetLOD(Float lod);

	//----------------------------------------------------------------------------------------
	/// Checks if the Level of Detail for rendering should be used in the editor.
	/// @return												@trueIfOtherwiseFalse{using the render LOD}
	//----------------------------------------------------------------------------------------
	Bool GetRenderLod() const;

	//----------------------------------------------------------------------------------------
	/// Sets if the the Level of Detail for rendering should be used in the editor.
	/// @param[in] lod								@trueIfOtherwiseFalse{the render LOD should be used}
	//----------------------------------------------------------------------------------------
	void SetRenderLod(Bool lod);

	/// @}

	/// @name Time
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the current time for the document's Timeline.\n
	/// Here is how to get the current frame with GetTime():
	/// @code
	/// Int32 fps = doc.GetFps();
	/// BaseTime time = doc->GetTime();
	/// frame = time.GetFrame(fps);
	/// @endcode
	/// @see GetFps()
	/// @return												The current time of the Timeline.
	//----------------------------------------------------------------------------------------
	const BaseTime& GetTime() const { return BdCall(GetTime)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the current time for the document's Timeline.
	/// @see GetTime()
	/// @warning This method only changes the document time, it does not start a redraw and/or animation/expressions. This is done using a combination of the following functions: ExecutePasses(), DrawViews() and EventAdd().
	/// @param[in] t									The new current time of the Timeline.
	//----------------------------------------------------------------------------------------
	void SetTime(const BaseTime& t);

	//----------------------------------------------------------------------------------------
	/// Gets the number of frames per second (FPS).
	/// @note	The framerate defined in the render settings is independent from the document framerate.\n
	///			In the viewport, and for a render in the viewport, it will return the project's setting FrameRate.\n
	///			Rendering elsewhere, it will return the RenderData FrameRate setting.
	/// @return												The number of frames per second.
	//----------------------------------------------------------------------------------------
	Int32 GetFps() const;

	//----------------------------------------------------------------------------------------
	/// Sets the number of frames per second (FPS).
	/// @param[in] fps								The new number of frames per second.
	//----------------------------------------------------------------------------------------
	void SetFps(Int32 fps);

	//----------------------------------------------------------------------------------------
	/// Gets the starting time for the Timeline in the document.
	/// @return												The starting time of the document's Timeline.
	//----------------------------------------------------------------------------------------
	BaseTime GetMinTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the starting time for the Timeline in the document.
	/// @param[in] t									The new starting time of the document's Timeline.
	//----------------------------------------------------------------------------------------
	void SetMinTime(const BaseTime& t);

	//----------------------------------------------------------------------------------------
	/// Gets the ending time for for the Timeline in the document.
	/// @return												The ending time of the document's Timeline.
	//----------------------------------------------------------------------------------------
	BaseTime GetMaxTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the ending time for the Timeline in the document.
	/// @see BaseTime for conversion of FPS or other time units.
	/// @see GetFps()
	/// @param[in] t									The new ending time of the document's Timeline.
	//----------------------------------------------------------------------------------------
	void SetMaxTime(const BaseTime& t);

	//----------------------------------------------------------------------------------------
	/// Gets the lower bound of the range of time used by all sequences, tracks, keys etc. Optionally the calculation is done only for the given object @formatParam{check}.
	/// @note Though the @formatParam{check} parameter supports all kinds of nodes, the test when @formatParam{check}==@formatConstant{nullptr} is only done for objects.
	/// @param[in] check							An object to check or @formatConstant{nullptr} to check the document's objects.
	/// @return												The minimal used time in the document.
	//----------------------------------------------------------------------------------------
	BaseTime GetUsedMinTime(BaseList2D* check);

	//----------------------------------------------------------------------------------------
	/// Gets the upper bound of the range of time used by all sequences, tracks, keys etc. Optionally the calculation is done only for the given object @formatParam{check}.
	/// @note Though the @formatParam{check} parameter supports all kinds of nodes, the test when @formatParam{check}==@formatConstant{nullptr} is only done for objects.
	/// @param[in] check							An object to check or @formatConstant{nullptr} to check the document's objects.
	/// @return												The maximum used time in the document.
	//----------------------------------------------------------------------------------------
	BaseTime GetUsedMaxTime(BaseList2D* check);

	//----------------------------------------------------------------------------------------
	/// Gets the time of the left boundary of the document's loop or preview range.
	/// @return												The starting time for the document's loop range.
	//----------------------------------------------------------------------------------------
	BaseTime GetLoopMinTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the time of the left boundary of the document's loop or preview range.
	/// @param[in] t									The new starting time for the document's loop range.
	//----------------------------------------------------------------------------------------
	void SetLoopMinTime(const BaseTime& t);

	//----------------------------------------------------------------------------------------
	/// Gets the time of the right boundary of the document's loop or preview range.
	/// @return												The ending time for the document's loop range.
	//----------------------------------------------------------------------------------------
	BaseTime GetLoopMaxTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the time of the right boundary of the document's loop or preview range.
	/// @param[in] t									The new ending time for the document's loop range.
	//----------------------------------------------------------------------------------------
	void SetLoopMaxTime(const BaseTime& t);

	/// @}

	/// @name Mode/Action
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the main editor mode.
	/// @return												The values for the editor mode are: @enumerateEnum{EditorModes}
	//----------------------------------------------------------------------------------------
	Int32 GetMode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the main editor mode.
	/// @param[in] m									The values for the editor mode are: @enumerateEnum{EditorModes}
	//----------------------------------------------------------------------------------------
	void SetMode(Int32 m);

	//----------------------------------------------------------------------------------------
	/// Checks if the editor is in editable mode. It basically checks if GetMode() is @ref Mpoints, @ref Medges or @ref Mpolygons.
	/// @return												@trueIfOtherwiseFalse{the editor is in point/edge/poly editing mode}
	//----------------------------------------------------------------------------------------
	Bool IsEditMode() const;

	//----------------------------------------------------------------------------------------
	/// Gets the current action tool in the editor.
	/// @return												The return values are @ref ID_MODELING_MOVE, @ref ID_MODELING_SCALE, @ref ID_MODELING_ROTATE etc.
	//----------------------------------------------------------------------------------------
	Int32 GetAction() const;

	//----------------------------------------------------------------------------------------
	/// Sets the current action tool in the editor.
	/// @param[in] a									The values are @ref ID_MODELING_MOVE, @ref ID_MODELING_SCALE, @ref ID_MODELING_ROTATE etc.
	//----------------------------------------------------------------------------------------
	void SetAction(Int32 a);

	/// @}

	/// @name Undo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Tells @C4D to start building a list of undos into a single undo action for the user. This must be paired with an EndUndo().
	/// @note Before calling StartUndo() in an asynchronous situation, do not forget to call StopAllThreads()
	/// @return												@trueIfOtherwiseFalse{the undo list was successfully started}
	//----------------------------------------------------------------------------------------
	Bool StartUndo();

	//----------------------------------------------------------------------------------------
	/// Ends the building of multiple undo actions into a single user undo. This must be paired with StartUndo().
	/// @return												@trueIfOtherwiseFalse{the undo list was successfully finished}
	//----------------------------------------------------------------------------------------
	Bool EndUndo();

	//----------------------------------------------------------------------------------------
	/// Adds an undo @formatParam{type} to the list of undo operations started with StartUndo().
	/// @note	AddUndo() always has to be called before a change is made.\n
	///				In the case of the creation of a new object the call is done afterwards, after insertion into the document/object/track/sequence but before calling subsequent functions like SetActiveObject() which creates another undo:
	///				@code
	///				BaseTag* tag = UVWTag::Alloc();
	///				op->InsertTag(tag);
	///				doc->AddUndo(UNDOTYPE::NEWOBJ, tag);
	///				@endcode
	/// @param[in] type								The values for the undo type are: @enumerateEnum{UNDOTYPE}
	/// @param[in] data								The object the undo has been added for.
	/// @param[in] allowFromThread		If an undo is added from a thread this is not executed. (As a safety measure, because normally this does not make any sense.)\n
	/// 															For explicit cases where a thread has to call AddUndo() (the view redraw and everything else is blocked) this can be set to @formatConstant{true}.
	/// @return												@trueIfOtherwiseFalse{the change was successfully added to the undo list}
	//----------------------------------------------------------------------------------------
	Bool AddUndo(UNDOTYPE type, void* data, Bool allowFromThread = false);

	//----------------------------------------------------------------------------------------
	/// Adds an undo for a BaseDraw to the list of undo operations started with StartUndo().
	/// @param[in] bd									The base draw to add the change to the undo list.
	/// @return												@trueIfOtherwiseFalse{the change for the base draw was successfully added to the undo list}
	//----------------------------------------------------------------------------------------
	Bool AddUndo(BaseDraw* bd);

	//----------------------------------------------------------------------------------------
	/// Perform an undo operation, same as the user doing @em Undo from within @C4D's interface.
	/// @param[in] multiple						This parameter only matters if DoUndo() is called between AddUndo() and EndUndo().\n
	/// 															If @formatParam{multiple} is @formatConstant{true} then all the AddUndo() steps will be undone. Otherwise only the last AddUndo() step will be undone.\n
	/// 															In addition if @formatParam{multiple} is set then EndUndo() will be invoked internally so if further undos are to be created after this point StartUndo() must be called afterwards.\n
	/// 															If EndUndo() has been called then all steps are always undone regardless of this setting.
	/// @return												@trueIfOtherwiseFalse{the undo list was successfully undone}
	//----------------------------------------------------------------------------------------
	Bool DoUndo(Bool multiple = false);

	//----------------------------------------------------------------------------------------
	/// Performs a redo operation (undo the last undo).
	/// @note DoRedo() must always be called after EndUndo().
	/// @return												@trueIfOtherwiseFalse{the last undo was successfully undone}
	//----------------------------------------------------------------------------------------
	Bool DoRedo();

	//----------------------------------------------------------------------------------------
	/// Flushes the complete undo + redo buffer.
	/// @warning Only call when absolutely needed.
	/// @param[in] lastEntryOnly			If true only the last or currently ongoing undo is removed, e.g. when an operation failed.
	/// 															Otherwises flushes the complete undo and redo buffer.
	//----------------------------------------------------------------------------------------
	void FlushUndoBuffer(Bool lastEntryOnly = false) { C4DOS_Bd->FlushUndoBuffer(this, lastEntryOnly); }

	//----------------------------------------------------------------------------------------
	/// Gets the element (object, tag, material, etc.) of the last undo action.\n
	/// E.g. if you have added a BaseObject undo you can retrieve the object by calling GetUndoPtr() but always be sure to check the type of the result first.
	/// @return												The last undo element. @theOwnsPointed{document,element}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetUndoPtr() { return C4DOS_Bd->GetUndoPtr(this); }

	//----------------------------------------------------------------------------------------
	/// Finds the last undo state of the @C4D element @formatParam{bl} (object, tag, material, etc.) for the specified undo @formatParam{type}.\n
	/// For instance here is how to retrieve the pre-undo object after a change has been made:
	/// @code BaseObject* preundo = (BaseObject*)doc->FindUndoPtr(op, UNDOTYPE::CHANGE); @endcode
	/// @param[in] bl									The element to obtain the last undo action.
	/// @param[in] type								The undo type to check: @enumerateEnum{UNDOTYPE}
	/// @return												The last undo state of the element.@theOwnsPointed{document,element}
	//----------------------------------------------------------------------------------------
	BaseList2D* FindUndoPtr(BaseList2D* bl, UNDOTYPE type) { return C4DOS_Bd->FindUndoPtr(this, bl, type); }

	/// @}

	/// @name Key
	/// @{

	//----------------------------------------------------------------------------------------
	/// Compares the object chain @formatParam{op} to object chain @formatParam{undo} and sets keyframes for all the changes.
	/// @param[in] undo								The object chain to compare to. @callerOwnsPointed{object chain}
	/// @param[in,out] op							The object chain to add the keys to. @callerOwnsPointed{object chain}
	/// @param[in] recursive					If @formatConstant{true} then the function applies to all children of @formatParam{op} as well. The hierarchy of @formatParam{op} and @formatParam{undo} must match.
	/// @param[in] pos								If @formatConstant{true} keyframes are added for differences in position.
	/// @param[in] scale							If @formatConstant{true} keyframes are added for differences in scale.
	/// @param[in] rot								If @formatConstant{true} keyframes are added for differences in rotation.
	/// @param[in] param							If @formatConstant{true} keyframes are added for differences in parameters.
	/// @param[in] pla								If @formatConstant{true} keyframes are added as PLA for differences in point positions.
	//----------------------------------------------------------------------------------------
	void AutoKey(BaseList2D* undo, BaseList2D* op, Bool recursive, Bool pos, Bool scale, Bool rot, Bool param, Bool pla) { C4DOS_Bd->AutoKey(this, undo, op, recursive, pos, scale, rot, param, pla); }

	//----------------------------------------------------------------------------------------
	/// Records a key for @formatParam{op} at @formatParam{time}.
	/// @param[in,out] op							The object to record.
	/// @param[in] time								The time to record.
	/// @param[in] id									The description ID to record.
	/// @param[in] undo								The object in @formatParam{op} in the old state. This is necessary e.g. for auto-keyframing so that @C4D can compare values. Usually this is the object from the undo buffer.\n
	/// 															To record keys without auto-keyframing then @formatConstant{nullptr} can be passed.
	/// @param[in] eval_attribmanager	If @formatConstant{true} Attribute Manager is evaluated.
	/// @param[in] autokeying					If @formatConstant{true} auto-keyframing is used and @formatParam{undo} needs to be passed for comparison.
	/// @param[in] allow_linking			If @formatConstant{true} and a Y key will be generated in auto-keyframing, then automatically the @em X and @em Z components will be completed. If @formatConstant{false} then only the @em Y key will be generated.
	/// @return												@trueIfOtherwiseFalse{the key was successfully recorded}
	//----------------------------------------------------------------------------------------
	Bool RecordKey(BaseList2D* op, const BaseTime& time, const DescID& id, BaseList2D* undo, Bool eval_attribmanager, Bool autokeying, Bool allow_linking) { return C4DOS_Bd->RecordKey(this, op, time, id, undo, eval_attribmanager, autokeying, allow_linking); }

	//-------------------------------------------------------------------------------------------------
	/// Records the active objects.
	/// @note Same as pushing the "Record Active Objects" button in the user interface.
	//-------------------------------------------------------------------------------------------------
	void Record() { C4DOS_Bd->Record(this); }

	/// @}

	/// @name BaseDraw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the activate BaseDraw in the editor.
	/// @return												The active view in the editor or @formatConstant{nullptr} if there is no active view. @theOwnsPointed{document,view}
	//----------------------------------------------------------------------------------------
	BaseDraw* GetActiveBaseDraw() const;

	//----------------------------------------------------------------------------------------
	/// Gets the BaseDraw the user has chosen as <i>Render View</i> in the editor (see @em View menu in @C4D).
	/// @return												The render view in the editor or @formatConstant{nullptr} if there is no render view. @theOwnsPointed{document,view}
	//----------------------------------------------------------------------------------------
	BaseDraw* GetRenderBaseDraw() const;

	//----------------------------------------------------------------------------------------
	/// Gets the BaseDraw from one of the editor views.
	/// @param[in] num								If there are multiple views this selects the view. @em 0 <= @formatParam{num} < GetBaseDrawCount()
	/// @return												The requested view in the editor, or @formatConstant{nullptr} if it is not available. @theOwnsPointed{document,view}
	//----------------------------------------------------------------------------------------
	BaseDraw* GetBaseDraw(Int32 num) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of views in the editor.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The BaseDraw count in the editor.
	//----------------------------------------------------------------------------------------
	Int32 GetBaseDrawCount() const;

	//-------------------------------------------------------------------------------------------------
	/// Call this method to Make sure that GetBaseDraw(0) is accessible. This is only important in import filters where, at the time, there are no valid drawing views.
	//-------------------------------------------------------------------------------------------------
	void ForceCreateBaseDraw();

	//----------------------------------------------------------------------------------------
	/// Gets the editor redraw time.
	/// @return												The editor redraw time.
	//----------------------------------------------------------------------------------------
	Int32 GetDrawTime() { return C4DOS_Bd->GetDrawTime(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the default clipping planes for the document.
	/// @param[out] nearPlane					Near plane.
	/// @param[out] farPlane					Far plane.
	/// @param[in] preset							If this is not nullptr, it must be an Int32 value which is any of the DOCUMENT_CLIPPING_PRESET_* constants.
	//----------------------------------------------------------------------------------------
	void GetDefaultClippingPlanes(Float &nearPlane, Float &farPlane, const GeData* preset = nullptr) const { return C4DOS_Bd->GetDefaultClippingPlanes(this, nearPlane, farPlane, preset); }

	/// @}

	/// @name Pick Session
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the data structure of the current pick session.
	/// @return												The data structure of the current pick session, or @formatConstant{nullptr} if there is none. @theOwnsPointed{document,pick session data}
	//----------------------------------------------------------------------------------------
	const PickSessionDataStruct* GetPickSession() const;

	//----------------------------------------------------------------------------------------
	/// Starts a pick session.
	/// @param[in] psd								The initialized data structure for the pick session. @callerOwnsPointed{pick session data}
	//----------------------------------------------------------------------------------------
	void StartPickSession(PickSessionDataStruct* psd);

	//----------------------------------------------------------------------------------------
	/// Ends the pick session. For instance after filling the pick session array.
	/// @param[in] cancel							Pass @formatConstant{true} to cancel a pick session, for instance if an error occurred. Pass @formatConstant{false} if the pick session is ended regularly.
	//----------------------------------------------------------------------------------------
	void StopPickSession(Bool cancel);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Animates the object @formatParam{op} in the document at the given @formatParam{time}.
	/// @note Does not take expressions into account.
	/// @param[in] op									The object to animate. @callerOwnsPointed{object}
	/// @param[in] time								The time at which @formatParam{op} is animated.
	/// @param[in] flags							The animate flags: @enumerateEnum{ANIMATEFLAGS}
	//----------------------------------------------------------------------------------------
	void AnimateObject(BaseList2D* op, const BaseTime& time, ANIMATEFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Animates the current frame of the document. Send an update message using EventAdd() to update the editor afterwards.
	/// @param[in] bt									The thread can either be @formatConstant{nullptr} (for the main @C4D thread) or if you are within your own thread then you pass it. @callerOwnsPointed{thread}
	/// @param[in] animation					If @formatConstant{true} animations are evaluated.
	/// @param[in] expressions				If @formatConstant{true} expressions are evaluated.
	/// @param[in] caches							If @formatConstant{true} caches are evaluated.
	/// @param[in] flags							The build flags: @enumerateEnum{BUILDFLAGS}
	/// @return												@trueIfOtherwiseFalse{the passes were executed successfully}
	//----------------------------------------------------------------------------------------
	Bool ExecutePasses(BaseThread* bt, Bool animation, Bool expressions, Bool caches, BUILDFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Makes a clone of the document and turns all objects into polygon based objects.
	/// @param[in] keepanimation			If @formatConstant{true} the animation is kept on the objects.
	/// @return												The cloned polygon based document or @formatConstant{nullptr} if it failed. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* Polygonize(Bool keepanimation = false);

	//----------------------------------------------------------------------------------------
	/// Collects all enabled soundtracks and calculates the downmix of the tracks. The result is stored in @formatParam{snd}.
	/// @param[out] snd								The downmix of the collected soundtracks. @callerOwnsPointed{sound}
	/// @param[in] from								The starting time of for the downmix.
	/// @param[in] to									The ending time for the downmix.
	/// @return												@trueIfOtherwiseFalse{collecting all the document's sounds was successful}
	//----------------------------------------------------------------------------------------
	Bool CollectSounds(BaseSound* snd, const BaseTime& from, const BaseTime& to);

	//----------------------------------------------------------------------------------------
	/// Finds a scene hook by ID.
	/// @param[in] id									The scene hook ID.
	/// @return												The found scene hook, or @formatConstant{nullptr} if there is no scene hook with the searched @formatParam{id}. @theOwnsPointed{document, scene hook}
	//----------------------------------------------------------------------------------------
	BaseSceneHook* FindSceneHook(Int32 id) const { return C4DOS_Bd->FindSceneHook(this, id); }

	// TODO: (Ole) make this const-correct
	// const BaseSceneHook* FindSceneHook(Int32 id) const { return const_cast<BaseDocument*>(this)->FindSceneHook(id); }

	//----------------------------------------------------------------------------------------
	/// Gets the plane in which the splines are created, such as @em XY plane.
	/// @return												The values for the spline planes are: @ref PRIM_PLANE_XY, @ref PRIM_PLANE_ZY and @ref PRIM_PLANE_XZ.
	//----------------------------------------------------------------------------------------
	Int32 GetSplinePlane();

	//----------------------------------------------------------------------------------------
	/// Gets the list of layers in the document.
	/// @return												The head of the list of the document's layers. @theOwnsPointed{document,list head}
	//----------------------------------------------------------------------------------------
	GeListHead* GetLayerObjectRoot();

	//----------------------------------------------------------------------------------------
	/// Gets all used textures for the objects in @formatParam{ar}.
	/// @param[in] ar									An atom array. If @formatConstant{nullptr}, all used textures in the document will be returned.
	/// @return												A container with all textures filename.
	//----------------------------------------------------------------------------------------
	BaseContainer GetAllTextures(const AtomArray* ar);

	//----------------------------------------------------------------------------------------
	/// Gets all used textures for the objects in @formatParam{ar}.
	/// @note  If @formatParam{isNet} is passed @formatConstant{true} then the function only delivers the textures of the current take. Set the parameter to @formatConstant{false} to get all.
	/// @param[in] isNet							Pass @formatConstant{true} to retrieve the textures used in the current NET rendering.
	/// @param[in] ar									An atom array to get the textures for. If @formatConstant{nullptr}, all used textures in the document will be returned.
	/// @return												A container with all textures filename.
	//----------------------------------------------------------------------------------------
	BaseContainer GetAllTextures(Bool isNet, const AtomArray* ar);

	//----------------------------------------------------------------------------------------
	/// Gets the first object in the Object Manager hierarchy of the specified @formatParam{type}. It searches objects that are not deactivated in the Object Manager (set to red).
	/// @param[in] type								The object type to search for.
	/// @param[in] editor							@formatConstant{true} will search using the <i>editor</i> dot in the Object Manager, @formatConstant{false} will use the <i>render dot</i>.
	/// @return												The first object of the requested @formatParam{type} or @formatConstant{nullptr} if no object was found. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetHighest(Int32 type, Bool editor);

	//----------------------------------------------------------------------------------------
	/// Gets the preview bitmap of the document.
	/// @return												The preview bitmap of the document. @theOwnsPointed{document,bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetDocPreviewBitmap();

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void GetHighlightedObjects(AtomArray& selection) const;

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetHighlightedObject(BaseObject* op, Int32 mode = SELECTION_NEW);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetHighlightedObjects(AtomArray& selection, Int32 mode = SELECTION_NEW);

	//----------------------------------------------------------------------------------------
	/// Gets the document's default keying settings.
	/// @param[in] pKey								Assigned the default keying settings. @cinemaOwnsPointed{key}
	/// @param[in] bOverdub						Assigned the document's default overdub.
	/// @return												@trueIfOtherwiseFalse{the document's default keying settings were retrieved successfully}
	//----------------------------------------------------------------------------------------
	Bool GetDefaultKey(CKey* pKey, Bool& bOverdub) const;

	//----------------------------------------------------------------------------------------
	/// Sets the document's default keying settings.
	/// @param[in] pKey								The new default keying settings. @cinemaOwnsPointed{key}
	/// @param[in] bOverdub						The new document's default overdub.\n
	/// 															If a keyframe already exists, the existing keyframe's interpolation type will be maintained when a new keyframe is recorded (only the Value Key will be overwritten).
	//----------------------------------------------------------------------------------------
	void SetDefaultKey(CKey* pKey, Bool bOverdub);

	//----------------------------------------------------------------------------------------
	/// Sets the track default interpolation mode.
	/// @param[in] mode								Interpolation mode.
	//----------------------------------------------------------------------------------------
	void SetTrackDefaultInterpolationMode(CURVEINTERPOLATION_MODE mode);

	//----------------------------------------------------------------------------------------
	/// Gets the track default interpolation mode.
	/// @return												Interpolation mode.
	//----------------------------------------------------------------------------------------
	CURVEINTERPOLATION_MODE GetTrackDefaultInterpolationMode() const;

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool IsCacheBuilt(Bool force = false) { return C4DOS_Bd->IsCacheBuilt(this, force); }

	//----------------------------------------------------------------------------------------
	/// Checks the state of the object axis modifier.
	/// @return												@trueIfOtherwiseFalse{the object axis modifier is enabled}
	//----------------------------------------------------------------------------------------
	Bool IsAxisEnabled() const;

	//----------------------------------------------------------------------------------------
	/// Gets the helper axis for the current multi-selection.
	/// @return												The axis object. @theOwnsPointed{document,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetHelperAxis();

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool HandleSelectedTextureFilename(BaseChannel* bc, const Filename& fn, Filename* resfilename, Bool undo, GEMB_R* already_answered);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool ReceiveMaterials(BaseObject* op, AtomArray* mat, Bool clearfirst);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool ReceiveNewTexture (BaseObject* op, const Filename& filename, Bool sdown, GEMB_R* already_answered);

	//----------------------------------------------------------------------------------------
	/// Sends @ref MSG_DOCUMENTINFO messages.
	/// @param[in] type								The document info message type: @enumerateEnum{MSG_DOCUMENTINFO_TYPE}
	/// @param[in] format							The file format: (Set for load, merge and before/after save only. Otherwise @ref NOTOK.) @enumerateEnum{FORMAT_FILES}
	/// @param[in] fn									The document filename.
	/// 															@note This is not always the same as the filename returned by BaseDocument::GetDocumentPath().\n
	/// 															e.g. for @ref MSG_DOCUMENTINFO_TYPE_SAVE_BEFORE BaseDocument::GetDocumentPath() still contains the old path whereas @formatParam{fn} designates the real file.
	/// @param[in] bl									The object/tag/material that got inserted. It is used if @formatParam{type} is of one of the following values:
	/// 															- @ref MSG_DOCUMENTINFO_TYPE_OBJECT_INSERT
	/// 															- @ref MSG_DOCUMENTINFO_TYPE_TAG_INSERT
	/// 															- @ref MSG_DOCUMENTINFO_TYPE_MATERIAL_INSERT
	/// @param[in] hooks_only					If @formatConstant{true} the message is sent to scene hooks only.
	//----------------------------------------------------------------------------------------
	void SendInfo(Int32 type, Int32 format, const Filename& fn, BaseList2D* bl, Bool hooks_only) { return C4DOS_Bd->SendInfo(this, type, format, fn, bl, hooks_only); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void RecordZero() { C4DOS_Bd->RecordZero(this); }

	//-------------------------------------------------------------------------------------------------
	/// markPrivate
	//-------------------------------------------------------------------------------------------------
	void RecordNoEvent() { C4DOS_Bd->RecordNoEvent(this); }

	//----------------------------------------------------------------------------------------
	/// In NodeData::SetDParameter() some operators, objects etc. can call @link BaseDocument doc@endlink->@link BaseDocument::SetRewind() SetRewind()@endlink so that @C4D rewinds the whole document (from time @em 0 to current time) when the next event @ref EVMSG_CHANGE or DrawViews() is processed.
	/// @param[in] flags							Not used.
	//----------------------------------------------------------------------------------------
	void SetRewind(Int32 flags = 0);

	/// @}

	/// @name Take Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the take data for the document.
	/// @since R17.032
	/// @return												The take data. @theOwnsPointed{document,take data}
	//----------------------------------------------------------------------------------------
	TakeData* GetTakeData() const;

	/// @}

	/// @name Target Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets target object within a multi-selection.
	/// @since R17.032
	/// @note	This is the last object selected and is used by commands such as Spline Boolean in order to allow the user to control which object will be used as the target for the command.\n
	///				The target object displays in the Object Manager as highlighted.
	/// @return												The target object, or @formatConstant{nullptr} if it fails or there is no selection.
	//----------------------------------------------------------------------------------------
	BaseObject* GetTargetObject() const;

	//----------------------------------------------------------------------------------------
	/// Sets target object within a multi-selection.
	/// @since R17.032
	/// @note	Implies selection of an object if it is not currently selected, adding it to the existing selection. \n
	///				Moves the object to the very end of the list when calling @ref BaseDocument::GetActiveObjects(@ref GETACTIVEOBJECTFLAGS::SELECTIONORDER).
	/// @param[in] op									The object to set as the target.
	//----------------------------------------------------------------------------------------
	void SetTargetObject(BaseObject* op);

	//----------------------------------------------------------------------------------------
	/// Returns the SceneRepository description.
	/// @param[in] create							True to create if not existing.
	/// @return												Reference to a repository on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<const maxon::UpdatableAssetRepositoryRef&> GetSceneRepository(Bool create);
	/// @markprivate
	/// @Since R20.000
	void SetTemporaryManipulatorObject(BaseObject* temp);
	
	/// @markprivate
	/// @since R20.000
	BaseObject* GetTemporaryManipulatorObject() const;

	/// @markprivate
	/// @since R22.000
	maxon::DocumentModeControllerRef& GetModeController();

	/// @markprivate
	/// @since R22.000
	Int32 GetMode(const maxon::Id& group) const { return BdCall(GetMode)(group); }

	/// @markprivate
	/// @since R22.000
	void			SetMode(Int32 mode, const maxon::Id& group);
		
	//----------------------------------------------------------------------------------------
	/// Gets the path of the OCIO coniguration file. 
	/// @since R2023.000
	/// If fullPath is set to true, the full path is returned, otherwise the string that is entered in the document settings.
	/// If the path is set to "$OCIO" by the user, the path is taken from the environment variable "OCIO".
	/// @param[in] fullPath						True, if the full path should be returned.
	/// @return												OCIO config path.
	//----------------------------------------------------------------------------------------
	Filename GetOcioConfigPath(Bool fullPath = true) const;

	//----------------------------------------------------------------------------------------
	/// Gets the OCIO configuration.
	/// @since R2023.200
	/// @markprivate
	/// @return												OCIO config.
	//----------------------------------------------------------------------------------------
	const maxon::OcioConfig& GetOcioConfig() const;
	
	//----------------------------------------------------------------------------------------
	/// Gets the OCIO color profiles.
	/// @since R2023.200
	/// @param[out] renderingColorSpace	Rendering color space.
	/// @param[out] displayColorSpace	Display color space.
	/// @param[out] viewTransform			View transform for rendering.
	/// @param[out] viewTransformThumbnails	View transform for thumbnails.
	//----------------------------------------------------------------------------------------
	void GetOcioProfiles(maxon::ColorProfile& renderingColorSpace, maxon::ColorProfile& displayColorSpace, maxon::ColorProfile& viewTransform, maxon::ColorProfile& viewTransformThumbnails) const;

	//----------------------------------------------------------------------------------------
	/// Gets the OCIO configuration and the according color profiles.
	/// @since R2023.000
	/// @markprivate
	/// @param[out] ocioConfig				OCIO config.
	/// @param[out] renderingColorSpace	Rendering color space.
	/// @param[out] displayColorSpace	Display color space.
	/// @param[out] viewTransform			View transform for rendering.
	/// @param[out] viewTransformThumbnails	View transform for thumbnails.
	//----------------------------------------------------------------------------------------
	void GetOcioConfigAndProfiles(maxon::OcioConfig& ocioConfig, maxon::ColorProfile& renderingColorSpace, maxon::ColorProfile& displayColorSpace, maxon::ColorProfile& viewTransform, maxon::ColorProfile& viewTransformThumbnails) const;

	//----------------------------------------------------------------------------------------
	/// Gets the name of the OCIO color spaces.
	/// @since R2023.000
	/// @param[out] renderingColorSpace	Rendering color space name.
	/// @param[out] displayColorSpace	Display color space name.
	/// @param[out] viewTransform			View transform for rendering name.
	/// @param[out] viewTransformThumbnails	View transform for thumbnails name.
	//----------------------------------------------------------------------------------------
	void GetActiveOcioColorSpacesNames(maxon::CString& renderingColorSpace, maxon::CString& displayColorSpace, maxon::CString& viewTransform, maxon::CString& viewTransformThumbnails) const;

	//----------------------------------------------------------------------------------------
	// Gets the names of all color spaces that are defined by the current configuration.
	/// @since R2023.100
	/// @return												An array containing the names of the color spaces.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<maxon::CString>& GetOcioColorSpaceNames();
	
	//----------------------------------------------------------------------------------------
	// Gets the names of all rendering color spaces that are defined by the current configuration.
	/// @since R2023.100
	/// @return												An array containing the names of the rendering color spaces.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<maxon::CString>& GetOcioRenderingColorSpaceNames();
	
	//----------------------------------------------------------------------------------------
	// Gets the names of all color spaces as menu items to be used as a menu.
	/// @since R2023.200
	/// @return												A BaseContainer containing the names of all color spaces.
	//----------------------------------------------------------------------------------------
	const BaseContainer& GetOcioColorSpacesPopupMenu() const;

	//----------------------------------------------------------------------------------------
	// Gets the names of all view transforms that are defined by the current configuration.
	/// @since R2023.100
	/// @return												An array containing the names of the view transforms.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<maxon::CString>& GetOcioViewTransformNames();
	
	//----------------------------------------------------------------------------------------
	// Gets the names of all display color spaces that are defined by the current configuration.
	/// @since R2023.100
	/// @return												An array containing the names of the display color spaces.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<maxon::CString>& GetOcioDisplayColorSpaceNames();
	
	//----------------------------------------------------------------------------------------
	// Gets the name of a color space that is defined by category and index. Returns an empty string if category or index are out of range.
	/// @since R2023.000
	/// category must be one of these values: DOCUMENT_OCIO_INPUT_COLORSPACE, DOCUMENT_OCIO_RENDER_COLORSPACE, DOCUMENT_OCIO_VIEW_TRANSFORM, 
	/// DOCUMENT_OCIO_VIEW_TRANSFORM_THUMBNAILS or DOCUMENT_OCIO_DISPLAY_COLORSPACE.
	/// @param[in] category						Category.
	/// @param[in] index							Index within the list that is specified by category.
	/// @return												An array containg the names of the display color spaces.
	//----------------------------------------------------------------------------------------
	maxon::CString GetNameFromColorSpaceId(Int32 category, Int32 index) const;

	//----------------------------------------------------------------------------------------
	// Gets the index of a color space that is defined by category and its name. Returns NOTOK if category is out of range ot if the name does not exist.
	/// @since R2023.000
	/// category must be one of these values: DOCUMENT_OCIO_INPUT_COLORSPACE, DOCUMENT_OCIO_RENDER_COLORSPACE, DOCUMENT_OCIO_VIEW_TRANSFORM, 
	/// DOCUMENT_OCIO_VIEW_TRANSFORM_THUMBNAILS or DOCUMENT_OCIO_DISPLAY_COLORSPACE.
	/// @param[in] category						Category.
	/// @param[in] name								Name of a color space within the list that is specified by category.
	/// @return												An array containg the names of the display color spaces.
	//----------------------------------------------------------------------------------------
	Int32 GetColorSpaceIdFromName(Int32 category, const maxon::CString& name) const;

	//----------------------------------------------------------------------------------------
	/// Copies the settings for linear workflow and OCIO configurations to another document.
	/// @since 2023.000
	/// @param[in] src								Document from where the settings are read. If this is nullptr, the settings are taken from the active document.
	/// @param[in] dst								Document in which the settings should be copied.
	/// @param[in] isMaterialPreview	Must be set to true, if the document is a preview render document.
	//----------------------------------------------------------------------------------------
	static void CopyLinearWorkflow(const BaseDocument *src, BaseDocument *dst, Bool isMaterialPreview);

	//----------------------------------------------------------------------------------------
	/// Updates the OCIO spaces that are stored internally in the document. Should be called after CopyLinearWorkflow.
	//----------------------------------------------------------------------------------------
	void UpdateOcioColorSpaces();

	//----------------------------------------------------------------------------------------
	/// Gets the color converter for the current document.
	/// The returned value is never nullptr. If OCIO is not active or if there was an error to create the OCIO converter a dummy is returned.
	/// @return												The color converter that belongs to the document.
	//----------------------------------------------------------------------------------------
	const OcioConverterRef& GetColorConverter() const;

	//----------------------------------------------------------------------------------------
	/// Gets the dummy converter that is used when there was an error to create the document-sprcific converter.
	/// @return												The dummy color converter.
	//----------------------------------------------------------------------------------------
	static const OcioConverterRef& GetBasicColorConverter();

	//----------------------------------------------------------------------------------------
	/// Gets the color converter for the active document.
	/// @return												The converter for the active document or the dummy converter if there is no active document.
	//----------------------------------------------------------------------------------------
	static const OcioConverterRef& GetColorConverterForActiveDocument();

	//----------------------------------------------------------------------------------------
	/// PrivateSetBaseRepository is a private functions to add a base asset repository base to the current document
	/// document. This can be used for preview renderings to connect the textures/nodes from the local scene repository.
	/// @param[in] baseRepo						repository to set as base in the current scene repository.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> PrivateSetBaseRepository(const maxon::UpdatableAssetRepositoryRef& baseRepo);

	//----------------------------------------------------------------------------------------
	/// Returns the current build run id (for cache building). This id increases for every cache build run of the document.
	/// This value is used in maxon::MemoizationCacheInterface.
	//----------------------------------------------------------------------------------------
	Int GetCacheRunId() const { return BdCall(GetCacheRunId)(); }

	//----------------------------------------------------------------------------------------
	/// Checks if the scene contains uncached dynamics. Even the scene contains i.e. cloth, rope or dynamics objects/tags this
	/// function still return false when all objects are cached.
	///
	/// @return			True if dynamics that are not cached are present, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool HasUncachedDynamics() const { return BdCall(HasUncachedDynamics)(); }

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// This class allows to perform some functions on all of the objects in a hierarchy.\n
/// @b Example:
/// @code
/// struct ExampleStruct
/// {
/// 	Int32 parent_state;
/// };
///
/// class ExampleHierarchy : public Hierarchy
/// {
/// public:
/// 	virtual void *Alloc() { return NewObjPtr(ExampleStruct); }
/// 	virtual void Free(void *data) { ExampleStruct *es = (ExampleStruct*)data; DeleteObj(es); }
/// 	virtual void CopyTo(void *src, void *dst) { *(static_cast<ExampleStruct*>(dst)) = *static_cast<ExampleStruct*>(src); }
/// 	virtual Bool Do(void *data, BaseObject *op, const Matrix &mg, Bool controlobject);
/// };
///
/// Bool ExampleHierarchy::Do(void *data, BaseObject *op, const Matrix &mg, Bool controlobject)
/// {
/// 	ExampleStruct* dt = (ExampleStruct*)data;
///
/// 	Int32 mode = op->GetRenderMode();
/// 	if (mode != MODE_UNDEF) // if mode is MODE_ON or MODE_OFF
/// 		d->parent_state = mode;
///
/// 	// Important: Do this parent-data inheritance always, even if you do not evaluate an object
/// 	// Reason: A child of an invisible control object might be visible again...
///
/// 	if (controlobject)
/// 		return true; // This object is not visible, has been used by generator
/// 	if (op->GetType() != Opolygon)
/// 		return true; // We cannot use this
///
/// 	// Do something with polygonized object op
/// 	// The object has matrix mg and local data dt
///
/// 	return true;
/// }
/// @endcode
//-------------------------------------------------------------------------------------------------
class Hierarchy
{
private:
	BaseDocument* doc;
	BaseThread* bt;

public:
	//----------------------------------------------------------------------------------------
	/// Override the method to allocate the private data for a single level in the hierarchy.\n
	/// @C4D itself will pass the parent matrix but all other data that might be needed must be passed down the hierarchy using a private data structure and this is where it is allocated.
	/// @return												The private data that is allocated.
	//----------------------------------------------------------------------------------------
	virtual void* Alloc() = 0;

	//----------------------------------------------------------------------------------------
	/// Override the method so that the private data allocated in Alloc() can be freed.
	/// @param[in,out] data						The private data to free.
	//----------------------------------------------------------------------------------------
	virtual void Free(void* data) = 0;

	//----------------------------------------------------------------------------------------
	/// Override the method so that the private data can be copied.
	/// @param[in] src								The source private data to copy from.
	/// @param[out] dst								The destination private data to copy to.
	//----------------------------------------------------------------------------------------
	virtual void CopyTo(void* src, void* dst) = 0;

	//----------------------------------------------------------------------------------------
	/// Override the method to be called for every object, virtual and non-virtual, in the hierarchy run.
	/// @param[in] data								The private data allocated in Alloc().
	/// @param[in] op									The object the function is being called for.
	/// @param[in] mg									The global matrix for this object down the hierarchy chain.
	/// @param[in] controlobject			If @formatConstant{true} then the object has been used by a generator and usually will no longer be used (but the routine goes through all objects in any case).
	/// @return												@trueIfOtherwiseFalse{the function was successful and the run through the hierarchy should continue}
	//----------------------------------------------------------------------------------------
	virtual Bool Do(void* data, BaseObject* op, const Matrix& mg, Bool controlobject) = 0;

	//----------------------------------------------------------------------------------------
	/// Performs Do() on all objects (virtual and non-virtual) in the hierarchy.\n
	/// Using this class will build all caches for dirty objects for the entire hierarchy, this can be time intensive and should be used carefully.\n
	/// If a polygon object is needed it is generally faster to call SendModelingCommand() with @ref MCOMMAND_CURRENTSTATETOOBJECT.
	/// @param[in] doc								The document with the objects you want to process.
	/// @param[in] spheres						If @formatConstant{true} the process will not polygonize perfect spheres.
	/// @param[in] lod								The level of detail to use.
	/// @param[in] uselod							If @formatConstant{true} the level of detail @formatParam{lod} should be evaluated.
	/// @param[in] flags							The build flags are: @enumerateEnum{BUILDFLAGS}
	/// 															@b Note: Either @ref BUILDFLAGS::INTERNALRENDERER or @ref BUILDFLAGS::EXTERNALRENDERER must be set because some generators check for these flags and generate different results.\n
	/// 															For example the Metaball object has different settings in the edit dialog for internal and external rendering.
	/// @param[in] startdata					The initial private data to pass into the hierarchy.
	/// @param[in] bt									The custom thread, or @formatConstant{nullptr} if called from the main @C4D thread.
	/// @return												The success of calling Do() for each object.
	//----------------------------------------------------------------------------------------
	Bool Run(BaseDocument* doc, Bool spheres, Float lod, Bool uselod, BUILDFLAGS flags, void* startdata, BaseThread* bt);
};

//-------------------------------------------------------------------------------------------------
/// Stores priorities in the execution pipeline.
/// @see	ObjectData::Execute()
///				TagData::Execute()
///				SceneHookData::Execute()
//-------------------------------------------------------------------------------------------------
class PriorityList
{
private:
	PriorityList();
	~PriorityList();

public:
	//----------------------------------------------------------------------------------------
	/// Adds an execution point for the object @formatParam{node} and the pipeline point specified by @formatParam{priority}.
	/// @param[in] node								The node to execute. @callerOwnsPointed{object}
	/// @param[in] priority						The priority in the pipeline: @enumerateEnum{EXECUTIONPRIORITY}
	/// @param[in] flags							The execution flags: @enumerateEnum{EXECUTIONFLAGS}
	//----------------------------------------------------------------------------------------
	void Add(BaseList2D* node, Int32 priority, EXECUTIONFLAGS flags) { C4DOS_Bd->PrAdd(this, node, priority, flags); }
};

//----------------------------------------------------------------------------------------
/// Gets the active document within the @C4D editor.
/// @return												The active document. @cinemaOwnsPointed{document}
//----------------------------------------------------------------------------------------
BaseDocument* GetActiveDocument();

//----------------------------------------------------------------------------------------
/// Gets the first document in the list of documents within @C4D.
/// @return												The first document. @cinemaOwnsPointed{document}
//----------------------------------------------------------------------------------------
BaseDocument* GetFirstDocument();

//----------------------------------------------------------------------------------------
/// Asks @C4D to load a file. This can be a document, an image, a layout or a <i>lib4d</i>/<i>cat4d</i> file.
/// @param[in] name								The name of the file to load.
/// @param[in] allowAsync					True to allow loading the file async. Pleasee note that the function returns before loading is finished in that case.
/// @return												@trueIfOtherwiseFalse{the file was loaded successfully or the async job was successfully enqueued}
//----------------------------------------------------------------------------------------
Bool LoadFile(const Filename& name, Bool allowAsync);

//----------------------------------------------------------------------------------------
/// Inserts a document into the list of documents within @C4D.
/// @note SetActiveDocument() is called implicitly.
/// @warning	If the current active document is empty then it will be destroyed in the process of inserting the new document.\n
///						Be careful passing a document pointing to the previous active one.
/// @param[in] doc								The document to insert. @C4D takes over the ownership of the pointed document.
//----------------------------------------------------------------------------------------
void InsertBaseDocument(BaseDocument* doc);

//----------------------------------------------------------------------------------------
/// Sets the document in the editor that the user is editing, this is the active document.
/// @warning It's mandatory that the passed doc is already inserted into the @C4D list of documents. This can be done with InsertBaseDocument().
/// @param[in] doc								The document to become active. @callerOwnsPointed{document}
//----------------------------------------------------------------------------------------
void SetActiveDocument(BaseDocument* doc);

//----------------------------------------------------------------------------------------
/// Closes all open documents.
/// @return												@trueIfOtherwiseFalse{all documents have been closed}
//----------------------------------------------------------------------------------------
Bool CloseAllDocuments();

//----------------------------------------------------------------------------------------
/// Removes and frees all resources of the passed document.
/// @param[in,out] doc						@theToDestruct{document}
//----------------------------------------------------------------------------------------
void KillDocument(BaseDocument*& doc);

//----------------------------------------------------------------------------------------
/// used by LoadDocument to inform about the progress of the operation.
/// Return True to continue the operation, False to cancel the operation.
//----------------------------------------------------------------------------------------
using ProgressDelegate = maxon::Delegate<Bool(Float percent)>;

//----------------------------------------------------------------------------------------
/// Similar to LoadFile() but this time the document is not put into the editors list of documents and it gives control over the loaded document.
/// @param[in] name								The name of the file to load the document from.
/// @param[in] loadflags					The scene filter flags for the loader: @enumerateEnum{SCENEFILTER}
/// @param[in] thread							The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @param[out] errorString				Assigned a string if an error occurred.
/// @param[in] progressDelegate		ProgressDelegate to receive the progress. see ProgressDelegate.
/// @return												The document that was loaded, or @formatConstant{nullptr} if it failed.
//----------------------------------------------------------------------------------------
BaseDocument* LoadDocument(const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString = nullptr, const ProgressDelegate& progressDelegate = ProgressDelegate());

//----------------------------------------------------------------------------------------
/// Merges the file @formatParam{name} into the document @formatParam{doc}.
/// @param[in] doc								The document to merge the loaded document @formatParam{name} into. @callerOwnsPointed{document}
/// @param[in] name								The file to merge into @formatParam{doc}.
/// @param[in] loadflags					The scene filter flags for the loader: @enumerateEnum{SCENEFILTER}
/// @param[in] thread							The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @param[out] errorString				Assigned a string if an error occurred.
/// @param[in] progressDelegate		ProgressDelegate to receive the progress. see ProgressDelegate.
/// @return												@trueIfOtherwiseFalse{merging the file @formatParam{name} into the document @formatParam{doc} was successful}
//----------------------------------------------------------------------------------------
Bool MergeDocument(BaseDocument* doc, const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString = nullptr, const ProgressDelegate& progressDelegate = ProgressDelegate());

//----------------------------------------------------------------------------------------
/// Saves a document to a file.
/// @param[in] doc								The document to save to a file. @callerOwnsPointed{document}
/// @param[in] name								The file to save the document to.
/// @param[in] saveflags					A combination of the flags for saving a document: @enumerateEnum{SAVEDOCUMENTFLAGS}
/// @param[in] format							The file format to save the document as: @enumerateEnum{FORMAT_FILES}
/// @return												@trueIfOtherwiseFalse{the document was saved successful}
//----------------------------------------------------------------------------------------
Bool SaveDocument(BaseDocument* doc, const Filename& name, SAVEDOCUMENTFLAGS saveflags, Int32 format);

//----------------------------------------------------------------------------------------
/// A helper routine to copy the objects @formatParam{t_objects} of document @formatParam{doc} to a new document returned.\n
/// All materials associated are also copied over and the links are corrected.
/// @param[in] doc								The document that contains the objects in the array @formatParam{t_objects}. @callerOwnsPointed{document}
/// @param[in] t_objects					The objects to isolate.
/// @return												The document containing the isolated objects. @callerOwnsPointed{document}
//----------------------------------------------------------------------------------------
BaseDocument* IsolateObjects(BaseDocument* doc, const AtomArray& t_objects);

//----------------------------------------------------------------------------------------
/// Renders a document to a bitmap.
/// @note A MultipassBitmap must be passed to render the image with an alpha channel:
/// @code
/// MultipassBitmap* bitmap = MultipassBitmap::Alloc(512, 512, COLORMODE::RGB);
/// bitmap->AddChannel(true, true);
/// ...
/// RenderDocument(doc, data, nullptr, nullptr, tmp, RENDERFLAGS::EXTERNAL, nullptr);
/// ...
/// MultipassBitmap::Free(bitmap);
/// @endcode
/// @param[in] doc								The document to render. Can be a clone of the real document to save memory usage. @callerOwnsPointed{document}
/// @param[in] rdata							The render data.
/// @param[in] prog								The progress bar hook. Can be @formatConstant{nullptr}. @callerOwnsPointed{progress hook}
/// @param[in] private_data				The private data for the progress hook @formatParam{prog}, or @formatConstant{nullptr}. @callerOwnsPointed{private data}
/// @param[in] bmp								The bitmap to render to, this must have been allocated and initialized with the right size. @callerOwnsPointed{bitmap}
/// @param[in] renderflags				A combination of the render flags: @enumerateEnum{RENDERFLAGS}
/// @param[in] th									The thread to test for a break or @formatConstant{nullptr}.
/// @param[in] wprog							The write progress hook for the render operation.@callerOwnsPointed{write progress hook}
/// @param[in] data								The private data for the write progress hook @formatParam{wprog}.
/// @return												A render result: @enumerateEnum{RENDERRESULT}
//----------------------------------------------------------------------------------------
RENDERRESULT RenderDocument(BaseDocument* doc, const BaseContainer& rdata, ProgressHook* prog, void* private_data, BaseBitmap* bmp, RENDERFLAGS renderflags, BaseThread* th, WriteProgressHook* wprog = nullptr, void* data = nullptr);


//----------------------------------------------------------------------------------------
/// Saves the document as a project (menu <i>"Save Project with Assets"</i>).
/// @param[in] doc								The document to save as project. @callerOwnsPointed{document}
/// @param[in] flags							A combination of the save project flags: @enumerateEnum{SAVEPROJECT}
/// @param[in] targetPath					The path to save the project to.
/// @param[out] assets						Filled by the found assets.
/// @param[out] missingAssets			Filled by the missing assets.
/// @return												@trueOtherwiseFalse{saving the document as a project was successful}
//----------------------------------------------------------------------------------------
Bool SaveProject(BaseDocument* doc, SAVEPROJECT flags, Filename targetPath, maxon::BaseArray<AssetEntry>* assets = nullptr, maxon::BaseArray<AssetEntry>* missingAssets = nullptr);

//----------------------------------------------------------------------------------------
/// Retrieves all assets from a document. It is e.g. used by <i>"Save Project with Assets"</i> menu and SaveProject().
/// @param[in] doc								The document to get the assets from. @callerOwnsPointed{document}
/// @param[in] allowDialogs				If @formatConstant{true} this function can open dialogs. For example a file select dialog will be opened if a node of the scene points to a file which does not exist anymore.
/// @param[in] assets							Assigned the assets in document @formatParam{doc}.
/// @param[out] lastPath					Filled with the last path used.\n
///																If a file dialog is opened and the user selects the missing file on the hard disk, the folder of this asset is assigned to @formatParam{lastPath}.\n
/// 															The developer can store this value somewhere and pass it next time so @C4D know where to look first before asking the user again.
/// @param[in] flags							Flags to decide which assets should be collected: @enumerateEnum{ASSETDATA_FLAG}
/// @return												The result if all assets were collected: @enumerateEnum{GETALLASSETSRESULT}
//----------------------------------------------------------------------------------------
GETALLASSETSRESULT GetAllAssets(BaseDocument* doc, Bool allowDialogs, maxon::BaseArray<AssetEntry>& assets, Filename& lastPath, ASSETDATA_FLAG flags = ASSETDATA_FLAG::NONE);


/// @addtogroup EditorModes
/// @ingroup group_enumeration
/// @{
/// The editor modes.
/// @see BaseDocument::GetMode()
enum
{
	Mcamera					= 0,				///< Camera mode.
	Mobject					= 1,				///< Object mode.
	Mtexture				= 3,				///< Texture mode.
	Mtextureaxis		= 4,				///< Texture axis mode.
	Mpoints					= 5,				///< Point edit mode.
	Medges					= 6,				///< Edge edit mode.
	Mpolygons				= 7,				///< Polygon edit mode.
	Manimation			= 9,				///< Animation mode.
	Mkinematic			= 10,				///< IK mode.
	Mmodel					= 11,				///< Model mode.
	Mpaint					= 12,				///< Paint mode.
	Muvpoints				= 13,				///< UV points mode.
	Muvpolygons			= 14,				///< UV polygons mode.
	Mpolyedgepoint	= 15,				///< Combined poly/edge/point mode. Must only be used in ViewportSelect.
	Medgepoint			= 16,				///< Combined edge/point mode. Must only be used in ViewportSelect.
	Mworkplane			= 17,				///< Workplane mode.
	M2dtracks				= 18,				///< 2D Tracks mode (Motion tracker).
	Muvedges				= 19,				///< UV edges mode.
	Muvon						= 100,			///< UV on
	Mdrag						= 1000			///< Drag mode.
};
/// @}


//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
Bool InteractiveModeling_Rewind(BaseDocument* doc);

//----------------------------------------------------------------------------------------
/// Used for modeling tools with GUI input. Applies the last modeling undo so that new values of the modeling tool can be applied.\n
/// Here is an example from the edge cut code:
/// @code
/// Bool EdgeCutTool::MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* draw, EditorWindow* win, const BaseContainer& msg)
/// {
/// 	if (!doc)
/// 		return false;
///
/// 	if (doc->GetMode() == Medges)
/// 	{
/// 		AutoAlloc<AtomArray> objects;
/// 		if (!objects)
/// 			return false;
///
/// 		doc->GetActiveObjects(*objects, true);
///
/// 		BaseContainer* toolData = GetToolData(doc, ID_MODELING_EDGECUT_TOOL);
/// 		if (!toolData)
/// 			return false;
///
/// 		// Undo the step before
/// 		InteractiveModeling_Restart(doc);
///
/// 		ModelingEdgeCut(objects, MODIFY_EDGESELECTION, toolData, doc, win, &msg, true, this);
/// 		EventAdd();
/// 	}
///
/// 	return true;
/// }
/// @endcode
/// @param[in] doc								The document for the operation. @callerOwnsPointed{document}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool InteractiveModeling_Restart(BaseDocument* doc);


//----------------------------------------------------------------------------------------
/// Controls the animation in a document.
/// @param[in] doc								The document to animate. Usually GetActiveDocument(). @callerOwnsPointed{document}
/// @param[in] forward						If @formatConstant{true} the direction is set to forward, otherwise it is set to backward.
/// @param[in] stop								If @formatConstant{true} the animation is stopped, otherwise it is running.
//----------------------------------------------------------------------------------------
void RunAnimation(BaseDocument* doc, Bool forward, Bool stop);

//----------------------------------------------------------------------------------------
/// Controls the time of a document.\n
/// @note Unlike BaseDocument::SetTime() this function handles running animation.
/// @param[in] doc								The document to set the time. Usually GetActiveDocument(). @callerOwnsPointed{document}
/// @param[in] time								The time to set.
//----------------------------------------------------------------------------------------
void SetDocumentTime(BaseDocument* doc, const BaseTime& time);

//----------------------------------------------------------------------------------------
/// Stops the external renderer.
/// @return												@trueIfOtherwiseFalse{the external rendering has been canceled}
//----------------------------------------------------------------------------------------
Bool StopExternalRenderer();

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASEDOCUMENT_H__
