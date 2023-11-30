#include "c4d_memory.h"
#include "c4d_baselist.h"
#include "c4d_basedocument.h"
#include "customgui_unitscale.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

VariableChanged::VariableChanged()
{
	map = nullptr;
	old_cnt	 = 0;
	new_cnt	 = 0;
	vc_flags = 0;
}

void GeListHead::Insert(GeListNode* bn, GeListNode* parent, GeListNode* prev)
{
	if (!bn)
		return;

	if (prev)
		bn->InsertAfter(prev);
	else if (parent)
		bn->InsertUnder(parent);
	else
		bn->InsertUnder(this);
}

Bool BaseList2D::SetLayerObject(const LayerObject* layer) { return BlCall(SetLayerObject)(layer); }

Bool BaseList2D::SetLayerData(BaseDocument* doc, const LayerData& layerData) { return BlCall(SetLayerData)(doc, layerData); }

Bool GeListNode::ChangeNBit    (NBIT bit, NBITCONTROL bitmode) { return AtCall(ChangeNBit) (bit, bitmode); }
String BaseList2D::GetTypeName   () const                   { return BlCall(GetTypeName) (); }
void BaseList2D::InsertTrackSorted(CTrack* track)       { BlCall(InsertTrackSorted) (track); }
BaseList2D*   BaseList2D::AnimationLayerRemap(BaseObject** layer){ return BlCall(AnimationLayerRemap) (layer); }
Bool BaseList2D::AddEventNotification(BaseList2D* bl, NOTIFY_EVENT eventid, NOTIFY_EVENT_FLAG flags, const BaseContainer* notifyData)       { return BlCall(AddEventNotification) (bl, eventid, flags, notifyData); }
Bool BaseList2D::RemoveEventNotification(const BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid)       { return BlCall(RemoveEventNotification) (doc, bl, eventid); }
Bool BaseList2D::FindEventNotification(const BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid)       { return BlCall(FindEventNotification) (doc, bl, eventid); }

Bool BaseList2D::SetDescIDState(const DescID& id, DESCIDSTATE descidstate)       { return BlCall(SetDescIDState) (id, descidstate); }
DESCIDSTATE BaseList2D::GetDescIDState(const DescID& id, Bool tolerant) const { return BlCall(GetDescIDState) (id, tolerant); }

void BaseList2D::ToggleBit(Int32 mask)
{
	Int32 bitfield = C4DOS_Bl->GetAllBits(this);

	if (bitfield & mask)
		bitfield = bitfield & ~mask;
	else
		bitfield = bitfield | mask;

	C4DOS_Bl->SetAllBits(this, bitfield);
}

void GeListNode::SetCustomData(GeListNode* node)
{
	C4DOS_Bl->SetCustomData(this, node);
}

GeListNode*	GeListNode::GetCustomData()
{
	return C4DOS_Bl->GetCustomData(this);
}

const GeListNode* GeListNode::GetCustomData() const
{
	return C4DOS_Bl->GetCustomData(MAXON_REMOVE_CONST(this));
}

/*Int32 BaseList2D::GetColor()
{
	return C4DOS_Bl->GetColor(this);
}

void BaseList2D::SetColor(Int32 c)
{
	C4DOS_Bl->SetColor(this, c);
}*/

Bool C4DAtom::Read(HyperFile* hf, Int32 id, Int32 level)
{
	return C4DOS_Bl->Read(this, hf, id, level);
}

Bool C4DAtom::Write(HyperFile* hf) const
{
	return C4DOS_Bl->Write(this, hf);
}

Bool C4DAtom::ReadObject(HyperFile* hf, Bool readheader)
{
	return C4DOS_Bl->ReadObject(this, hf, readheader);
}

Bool C4DAtom::WriteObject(HyperFile* hf) const
{
	return C4DOS_Bl->WriteObject(this, hf);
}

Bool C4DAtom::GetDescription(Description* description, DESCFLAGS_DESC flags) const
{
	return AtCall(GetDescription) (*description, flags);
}

Bool C4DAtom::GetParameter(const DescID& id, GeData& data, DESCFLAGS_GET flags) const
{
	return AtCall(GetParameter) (id, data, flags);
}

Bool C4DAtom::SetParameter(const DescID& id, const GeData& data, DESCFLAGS_SET flags)
{
	return AtCall(SetParameter) (id, data, flags);
}

Bool C4DAtom::GetEnabling(const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) const
{
	return AtCall(GetEnabling) (id, t_data, flags, itemdesc);
}

Bool C4DAtom::TranslateDescID(const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return AtCall(TranslateDescID) (id, res_id, res_at);
}

Bool BaseList2D::SetAnimatedParameter(const CTrack* track, const DescID& id, const GeData& t_data1, const GeData& t_data2, Float mix, DESCFLAGS_SET flags)
{
	return AtCall(SetAnimatedParameter)(track, id, t_data1, t_data2, mix, flags);
}

Bool BaseList2D::GetAnimatedParameter(const DescID& id, GeData& t_data1, GeData& t_data2, Float& mix, DESCFLAGS_GET flags) const
{
	return AtCall(GetAnimatedParameter) (id, t_data1, t_data2, mix, flags);
}

DynamicDescription* C4DAtom::GetDynamicDescriptionWritable()
{
	return AtCall(GetDynamicDescriptionWritable)();
}

const DynamicDescription* C4DAtom::GetDynamicDescription() const
{
	return AtCall(GetDynamicDescription)();
}

Bool BaseList2D::CopyDynamicDescriptionFrom(const BaseList2D* src)
{
	return BlCall(CopyDynamicDescriptionFrom)(src);
}


GeListHead* AllocListHead()
{
	return C4DOS_Bl->AllocListHead();
}

GeListNode* AllocListNode(Int32 id)
{
	return C4DOS_Bl->AllocListNode(0, &id, 1);
}

GeListNode* AllocSmallListNode(Int32 id)
{
	return C4DOS_Bl->AllocListNode(PLUGINFLAG_SMALLNODE, &id, 1);
}

GeListNode* AllocMultiNode(const Int32* id_array, Int32 id_cnt)
{
	return C4DOS_Bl->AllocListNode(0, id_array, id_cnt);
}

BaseLink* BaseLink::Alloc()
{
	return C4DOS_Ln->Alloc();
}

void BaseLink::Free(BaseLink*& link)
{
	if (link)
		C4DOS_Ln->Free(link);
	link = nullptr;
}

AliasTrans* AliasTrans::Alloc()
{
	return C4DOS_Ln->TrnAlloc();
}

void AliasTrans::Free(AliasTrans*& trn)
{
	if (trn)
		C4DOS_Ln->TrnFree(trn);
	trn = nullptr;
}

GeListHead* GeListHead::Alloc()
{
	return C4DOS_Bl->AllocListHead();
}

void GeListHead::Free(GeListHead*& head)
{
	if (head)
		C4DOS_Bl->Free(head);
	head = nullptr;
}

GeListHeadCB* GeListHeadCB::Alloc()
{
	return C4DOS_Bl->AllocListHeadCB();
}

void GeListHeadCB::Free(GeListHeadCB*& head)
{
	if (head)
		C4DOS_Bl->Free(head);
	head = nullptr;
}

BaseList2D* BaseList2D::Alloc(Int32 type)
{
	return C4DOS_Bl->Alloc(type);
}

void BaseList2D::Free(BaseList2D*& bl)
{
	if (bl)
		C4DOS_Bl->Free(bl);
	bl = nullptr;
}

Bool BaseList2D::Edit()
{
	return C4DOS_Bo->Edit(this);
}

void BaseList2D::GetIcon(IconData* dat) 
{
	C4DOS_Bo->GetIcon(this, dat);
}

const Char* BaseList2D::GetViewportRenderId(VIEWPORT_RENDER_ID typeId) const
{
	ViewportRenderIDMessageData msgData;
	msgData.typeId = typeId;
	msgData.viewportId = nullptr;
	const_cast<BaseList2D*>(this)->Message(MSG_GET_VIEWPORT_RENDER_ID, (void*) &msgData);
	return msgData.viewportId;
}

void HandleShaderMessage(GeListNode* node, BaseShader* ps, Int32 type, void* data)
{
	C4DOS_Ba->HandleShaderMessage(node, ps, type, data);
}

void HandleInitialChannel(GeListNode* node, Int32 id, Int32 type, void* data)
{
	if (type != MSG_INITIALCHANNEL)
		return;

	BaseList2D* shd = (BaseList2D*)data;
	if (!shd)
		return;

	shd->InsertUnder(node);
	static_cast<BaseList2D*>(node)->GetDataInstanceRef().SetLink(id, shd);
}


void BaseList2D::ClearKeyframeSelection()
{
	BlCall(ClearKeyframeSelection) ();
}

Bool BaseList2D::FindKeyframeSelection(const DescID& id)
{
	return BlCall(FindKeyframeSelection) (id);
}

Bool BaseList2D::SetKeyframeSelection(const DescID& id, Bool selection)
{
	return BlCall(SetKeyframeSelection) (id, selection);
}

Bool BaseList2D::KeyframeSelectionContent()
{
	return BlCall(KeyframeSelectionContent) ();
}

Float CalculateTranslationScale(const UnitScaleData* src, const UnitScaleData* dst)
{
	return C4DOS_Ge->CalculateTranslationScale(src, dst);
}

Float CalculateTranslationScale(BaseDocument* sdoc, BaseDocument* ddoc)
{
	return C4DOS_Ge->CalculateTranslationScale(sdoc->GetDataInstanceRef().GetCustomDataType<UnitScaleData>(DOCUMENT_DOCUNIT), ddoc->GetDataInstanceRef().GetCustomDataType<UnitScaleData>(DOCUMENT_DOCUNIT));
}

maxon::Result<BaseList2D*> NbmFindOrCreateCorrespondingBaseList(maxon::NimbusInterface* nbm, const maxon::CString& nodePath)
{
	return C4DOS_Bl->NbmFindOrCreateCorrespondingBaseList(nbm, nodePath);
}

maxon::Result<void> NbmPortToDescID(maxon::NimbusInterface* nbm, const maxon::NodePath& node, const maxon::NodePath& port, DescID& result)
{
	return C4DOS_Bl->NbmPortToDescID(nbm, node, port, result);
}

GeListHead* BaseList2D::GetOverrideRoot(Bool create)
{
	return BlCall(GetOverrideRoot)(create);
}

BaseOverride* BaseList2D::GetFirstOverride() { return BlCall(GetFirstOverride) (); }

GeListHead* BaseList2D::GetShaderRepositoryRoot(Bool create)
{
	return BlCall(GetShaderRepositoryRoot)(create);
}

GeListHead* BaseList2D::GetHiddenShaderRoot(Bool create)
{
	return BlCall(GetHiddenShaderRoot)(create);
}

maxon::Result<maxon::NimbusForwardRef> BaseList2D::PrivateGetOrCreateNimbusRef(const maxon::Id& spaceId)
{
	iferr_scope;
	maxon::NimbusInterface* ptr = BlCall(GetOrCreateNimbusRef)(spaceId) iferr_return;
	return maxon::NimbusForwardRef(reinterpret_cast<maxon::ObjectInterface*>(ptr));
}

void BaseList2D::RemoveNimbusRef(const maxon::Id& spaceId)
{
	return BlCall(RemoveNimbusRef)(spaceId);
}

maxon::Result<Bool> BaseList2D::GetAccessedObjects(METHOD_ID method, AccessedObjectsCallback& access) const
{
	return BlCall(GetAccessedObjects)(method, access);
}

maxon::Result<Bool> BaseList2D::GetAccessedObjectsRec(ACCESSED_OBJECTS_MASK read, ACCESSED_OBJECTS_MASK write, METHOD_ID method, Bool withSiblings, Bool withChildren, AccessedObjectsCallback& access) const
{
	return BlCall(GetAccessedObjectsRec)(read, write, method, withSiblings, withChildren, access);
}

maxon::Result<Bool> BaseList2D::GetAccessedObjectsOfHierarchy(ACCESSED_OBJECTS_MASK read, ACCESSED_OBJECTS_MASK write, METHOD_ID method, AccessedObjectsCallback& access) const
{
	return GetAccessedObjectsRec(read, write, method, false, true, access);
}

maxon::Result<Bool> BaseList2D::GetAccessedObjectsOfChildren(ACCESSED_OBJECTS_MASK read, ACCESSED_OBJECTS_MASK write, METHOD_ID method, AccessedObjectsCallback& access) const
{
	const BaseList2D* c = static_cast<const BaseList2D*>(GetDown());
	if (c)
		return c->GetAccessedObjectsRec(read, write, method, true, true, access);
	else
		return true;
}

maxon::Result<Bool> BaseList2D::GetAccessedObjectsOfFirstChildHierarchy(ACCESSED_OBJECTS_MASK read, ACCESSED_OBJECTS_MASK write, METHOD_ID method, AccessedObjectsCallback& access) const
{
	const BaseList2D* c = static_cast<const BaseList2D*>(GetDown());
	if (c)
		return c->GetAccessedObjectsRec(read, write, method, false, true, access);
	else
		return true;
}

maxon::Result<Filename> HandleModifyFilenameMessage(Int32 msgType, const void* msgData, const Filename& filename, BaseList2D* undoBl, const ModifyFilenameDelegate& modifyFilenameDelegate)
{
	return C4DOS_Ge->HandleModifyFilenameMessage(msgType, msgData, filename, undoBl, modifyFilenameDelegate);
}

maxon::Result<maxon::GenericData> BaseList2D::GroupChanges()
{
	return BlCall(GroupChanges)();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
