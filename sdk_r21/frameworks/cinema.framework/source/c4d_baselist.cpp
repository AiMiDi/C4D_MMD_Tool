#include "c4d_memory.h"
#include "c4d_baselist.h"
#include "c4d_basedocument.h"
#include "customgui_unitscale.h"

#define BlCall(fnc) (this->*C4DOS.Bl->fnc)

VariableChanged::VariableChanged(void)
{
	map = nullptr;
	old_cnt	 = 0;
	new_cnt	 = 0;
	vc_flags = VC_SAFETY;
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

LayerObject* BaseList2D::GetLayerObject(BaseDocument* doc)                       { return BlCall(GetLayerObject) (doc); }
Bool BaseList2D::SetLayerObject(LayerObject* layer)                      { return BlCall(SetLayerObject) (layer); }
const LayerData* BaseList2D::GetLayerData  (BaseDocument* doc, Bool rawdata)        { return BlCall(GetLayerData) (doc, rawdata); }
Bool BaseList2D::SetLayerData  (BaseDocument* doc, const LayerData& layerData){ return BlCall(SetLayerData) (doc, layerData); }


UInt32 GeListNode::GetNBitMask(Int32 index) const { return AtCall(GetNBitMask)(index); }
Bool GeListNode::GetNBit       (NBIT bit) const { return AtCall(GetNBit) (bit); }
Bool GeListNode::ChangeNBit    (NBIT bit, NBITCONTROL bitmode) { return AtCall(ChangeNBit) (bit, bitmode); }
GeListHead*   BaseList2D::GetCTrackRoot (void)                   { return BlCall(GetCTrackRoot) (); }
CTrack*       BaseList2D::GetFirstCTrack(void)                   { return BlCall(GetFirstCTrack) (); }
CTrack*       BaseList2D::FindCTrack    (const DescID& id)       { return BlCall(FindCTrack) (id); }
String BaseList2D::GetTypeName   (void)                   { return BlCall(GetTypeName) (); }
BaseList2D* BaseList2D::GetMain       (void) const { return AtCall(GetMain) (); }
void BaseList2D::InsertTrackSorted(CTrack* track)       { BlCall(InsertTrackSorted) (track); }
GeListHead*   BaseList2D::GetNLARoot    (void)                   { return BlCall(GetNLARoot) (); }
BaseList2D*   BaseList2D::AnimationLayerRemap(BaseObject** layer){ return BlCall(AnimationLayerRemap) (layer); }
Bool BaseList2D::AddEventNotification(BaseList2D* bl, NOTIFY_EVENT eventid, NOTIFY_EVENT_FLAG flags, const BaseContainer* notifyData)       { return BlCall(AddEventNotification) (bl, eventid, flags, notifyData); }
Bool BaseList2D::RemoveEventNotification(BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid)       { return BlCall(RemoveEventNotification) (doc, bl, eventid); }
Bool BaseList2D::FindEventNotification(BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid)       { return BlCall(FindEventNotification) (doc, bl, eventid); }

Bool BaseList2D::SetDescIDState(const DescID& id, DESCIDSTATE descidstate)       { return BlCall(SetDescIDState) (id, descidstate); }
DESCIDSTATE BaseList2D::GetDescIDState(const DescID& id, Bool tolerant) const { return BlCall(GetDescIDState) (id, tolerant); }

void BaseList2D::ToggleBit(Int32 mask)
{
	Int32 bitfield = C4DOS.Bl->GetAllBits(this);

	if (bitfield & mask)
		bitfield = bitfield & ~mask;
	else
		bitfield = bitfield | mask;

	C4DOS.Bl->SetAllBits(this, bitfield);
}

Int32 GeListNode::GetInfo(void)
{
	return C4DOS.Bo->GetInfo(this);
}

void GeListNode::SetCustomData(GeListNode* node)
{
	C4DOS.Bl->SetCustomData(this, node);
}

GeListNode*	GeListNode::GetCustomData(void)
{
	return C4DOS.Bl->GetCustomData(this);
}

/*Int32 BaseList2D::GetColor(void)
{
	return C4DOS.Bl->GetColor(this);
}

void BaseList2D::SetColor(Int32 c)
{
	C4DOS.Bl->SetColor(this, c);
}*/

Bool C4DAtom::Read(HyperFile* hf, Int32 id, Int32 level)
{
	return C4DOS.Bl->Read(this, hf, id, level);
}

Bool C4DAtom::Write(HyperFile* hf)
{
	return C4DOS.Bl->Write(this, hf);
}

Bool C4DAtom::ReadObject(HyperFile* hf, Bool readheader)
{
	return C4DOS.Bl->ReadObject(this, hf, readheader);
}

Bool C4DAtom::WriteObject(HyperFile* hf)
{
	return C4DOS.Bl->WriteObject(this, hf);
}

Bool C4DAtom::GetDescription(Description* description, DESCFLAGS_DESC flags)
{
	return AtCall(GetDescription) (*description, flags);
}

Bool C4DAtom::GetParameter(const DescID& id, GeData& data, DESCFLAGS_GET flags)
{
	return AtCall(GetParameter) (id, data, flags);
}

Bool C4DAtom::SetParameter(const DescID& id, const GeData& data, DESCFLAGS_SET flags)
{
	return AtCall(SetParameter) (id, data, flags);
}

Bool C4DAtom::GetEnabling(const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	return AtCall(GetEnabling) (id, t_data, flags, itemdesc);
}

Bool C4DAtom::TranslateDescID(const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return AtCall(TranslateDescID) (id, res_id, res_at);
}

Bool BaseList2D::SetAnimatedParameter(CTrack* track, const DescID& id, const GeData& t_data1, const GeData& t_data2, Float mix, DESCFLAGS_SET flags)
{
	return AtCall(SetAnimatedParameter) (track, id, t_data1, t_data2, mix, flags);
}

Bool BaseList2D::GetAnimatedParameter(const DescID& id, GeData& t_data1, GeData& t_data2, Float& mix, DESCFLAGS_GET flags)
{
	return AtCall(GetAnimatedParameter) (id, t_data1, t_data2, mix, flags);
}

DynamicDescription* C4DAtom::GetDynamicDescription()
{
	return AtCall(GetDynamicDescription) ();
}

GeListHead* AllocListHead(void)
{
	return C4DOS.Bl->AllocListHead();
}

GeListNode* AllocListNode(Int32 id)
{
	return C4DOS.Bl->AllocListNode(0, &id, 1);
}

GeListNode* AllocSmallListNode(Int32 id)
{
	return C4DOS.Bl->AllocListNode(PLUGINFLAG_SMALLNODE, &id, 1);
}

GeListNode* AllocMultiNode(Int32* id_array, Int32 id_cnt)
{
	return C4DOS.Bl->AllocListNode(0, id_array, id_cnt);
}

BaseLink* BaseLink::Alloc(void)
{
	return C4DOS.Ln->Alloc();
}

void BaseLink::Free(BaseLink*& link)
{
	if (link)
		C4DOS.Ln->Free(link);
	link = nullptr;
}

AliasTrans* AliasTrans::Alloc(void)
{
	return C4DOS.Ln->TrnAlloc();
}

void AliasTrans::Free(AliasTrans*& trn)
{
	if (trn)
		C4DOS.Ln->TrnFree(trn);
	trn = nullptr;
}

GeListHead* GeListHead::Alloc(void)
{
	return C4DOS.Bl->AllocListHead();
}

void GeListHead::Free(GeListHead*& head)
{
	if (head)
		C4DOS.Bl->Free(head);
	head = nullptr;
}

GeListHeadCB* GeListHeadCB::Alloc(void)
{
	return C4DOS.Bl->AllocListHeadCB();
}

void GeListHeadCB::Free(GeListHeadCB*& head)
{
	if (head)
		C4DOS.Bl->Free(head);
	head = nullptr;
}

BaseList2D* BaseList2D::Alloc(Int32 type)
{
	return C4DOS.Bl->Alloc(type);
}

void BaseList2D::Free(BaseList2D*& bl)
{
	if (bl)
		C4DOS.Bl->Free(bl);
	bl = nullptr;
}

Bool BaseList2D::Edit(void)
{
	return C4DOS.Bo->Edit(this);
}

void BaseList2D::GetIcon(IconData* dat)
{
	C4DOS.Bo->GetIcon(this, dat);
}

void HandleShaderMessage(GeListNode* node, BaseShader* ps, Int32 type, void* data)
{
	C4DOS.Ba->HandleShaderMessage(node, ps, type, data);
}

void HandleInitialChannel(GeListNode* node, Int32 id, Int32 type, void* data)
{
	if (type != MSG_INITIALCHANNEL)
		return;

	BaseList2D* shd = (BaseList2D*)data;
	if (!shd)
		return;

	shd->InsertUnder(node);
	((BaseList2D*)node)->GetDataInstance()->SetLink(id, shd);
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
	return C4DOS.Ge->CalculateTranslationScale(src, dst);
}

Float CalculateTranslationScale(BaseDocument* sdoc, BaseDocument* ddoc)
{
	return C4DOS.Ge->CalculateTranslationScale((const UnitScaleData*)sdoc->GetDataInstance()->GetCustomDataType(DOCUMENT_DOCUNIT, CUSTOMDATATYPE_UNITSCALE), (const UnitScaleData*)ddoc->GetDataInstance()->GetCustomDataType(DOCUMENT_DOCUNIT, CUSTOMDATATYPE_UNITSCALE));
}

maxon::Result<BaseList2D*> NbmFindOrCreateCorrespondingBaseList(maxon::NimbusInterface* nbm, const maxon::CString& nodePath)
{
	return C4DOS.Bl->NbmFindOrCreateCorrespondingBaseList(nbm, nodePath);
}

maxon::Result<void> NbmPortToDescID(maxon::NimbusInterface* nbm, const maxon::GraphNode& node, const maxon::GraphNode& port, DescID& result)
{
	return C4DOS.Bl->NbmPortToDescID(nbm, node, port, result);
}

GeListHead* BaseList2D::GetOverrideRoot(void) { return BlCall(GetOverrideRoot) (); }

BaseOverride* BaseList2D::GetFirstOverride(void) { return BlCall(GetFirstOverride) (); }

GeListHead* BaseList2D::GetShaderRepositoryRoot(void) { return BlCall(GetShaderRepositoryRoot) (); }

GeListHead* BaseList2D::GetHiddenShaderRoot() { return BlCall(GetHiddenShaderRoot) (); }

maxon::NimbusInterface* BaseList2D::GetNimbusRef(const maxon::Id& spaceId) const
{
	return BlCall(GetNimbusRef)(spaceId);
}

maxon::Result<maxon::NimbusInterface*> BaseList2D::GetOrCreateNimbusRef(const maxon::Id& spaceId)
{
	return BlCall(GetOrCreateNimbusRef)(spaceId);
}

void BaseList2D::RemoveNimbusRef(const maxon::Id& spaceId)
{
	return BlCall(RemoveNimbusRef)(spaceId);
}

maxon::Result<maxon::HashMap<maxon::Id, maxon::ForwardRef<maxon::NimbusRef>>> BaseList2D::GetAllNimbusRefs() const
{
	return BlCall(GetAllNimbusRefs)();
}

Bool BaseList2D::IsNodeBased() const
{
	return BlCall(IsNodeBased)();
}