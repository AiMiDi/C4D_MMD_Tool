#include "c4d_memory.h"
#include "c4d_baselist.h"
#include "c4d_basedocument.h"
#include "customgui_unitscale.h"

namespace cinema
{

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

Float CalculateTranslationScale(const BaseDocument* sdoc, const BaseDocument* ddoc)
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


String GetScriptDefaultCode(const SCRIPT_CONTEXT& context)
{
	switch (context)
	{
		case SCRIPT_CONTEXT::SCRIPT_MANAGER:
		{
			return String(
				"import c4d\n"
				"\n"
				"doc: c4d.documents.BaseDocument  # The currently active document.\n"
				"op: c4d.BaseObject | None  # The primary selected object in `doc`. Can be `None`.\n"
				"\n"
				"def main() -> None:\n"
				"    \"\"\"Called by Cinema 4D when the script is being executed.\n"
				"    \"\"\"\n"
				"    c4d.gui.MessageDialog(\"Hello World!\")\n"
				"\n"
				"\n"
				"if __name__ == '__main__':\n"
				"    main()\n"
			);
		}
		case SCRIPT_CONTEXT::GENERATOR_PYTHON:
		{
			return String(
				"import c4d\n"
				"\n"
				"doc: c4d.documents.BaseDocument # The document the object `op` is contained in.\n"
				"op: c4d.BaseObject # The Python generator object holding this code.\n"
				"hh: \"PyCapsule\" # A HierarchyHelp object, only defined when main is executed.\n"
				"\n"
				"def main() -> c4d.BaseObject:\n"
				"    \"\"\"Called by Cinema 4D to retrieve the cache of the Python Generator object.\n"
				"    \"\"\"\n"
				"    return c4d.BaseObject(c4d.Ocube)\n"
			);
		}
		case SCRIPT_CONTEXT::EFFECTOR_PARAMETER_MODE:
		{
			return String(
				"\"\"\"Realizes an effector that attracts MoGraph particles spherically around its origin.\n"
				"\n"
				"Add the example to a Matrix object to understand its effect. Because in Parameter Control mode\n"
				"we cannot arbitrarily set the values of particles, only scale the values set by the user, this\n"
				"code can only realize \"attraction\" along the vector defined by the Parameter.Position parameter\n"
				"of the effector. Compare this example to Full Control mode to understand the difference.\n"
				"\"\"\"\n"
				"import c4d\n"
				"\n"
				"op: c4d.BaseObject # The Python Effector object containing this code.\n"
				"gen: c4d.BaseObject # The MoGraph Generator executing `op`.\n"
				"doc: c4d.documents.BaseDocument # The document `op` and `gen`are contained in.\n"
				"\n"
				"def main() -> c4d.Vector | float | int:\n"
				"    \"\"\"Called by Cinema 4D to evaluate the effector.\n"
				"    \"\"\"\n"
				"    # Get the particle data for the effector #op. Get out when either the data cannot be retrieved \n"
				"    # or we are not being polled for modifying the particle positions.\n"
				"    data: c4d.modules.mograph.MoData = c4d.modules.mograph.GeGetMoData(op)\n"
				"    if data is None or data.GetBlendID() != c4d.ID_MG_BASEEFFECTOR_POSITION:\n"
				"        return 1.0\n"
				"\n"
				"    # The currently sampled particle and its current position value and the transform of both\n"
				"    # the generator and the effector.\n"
				"    i: int = data.GetCurrentIndex()\n"
				"    p: c4d.Vector = data.GetArrayValue(c4d.MODATA_MATRIX, i).off\n"
				"    mgGen: c4d.Matrix = gen.GetMg()\n"
				"    mgEff: c4d.Matrix = op.GetMg()\n"
				"\n"
				"    # Compute output weight as the distance between the particle #i and the effector #op, clamped\n"
				"    # to a sphere of of the radius of 100 units at the origin of #op.\n"
				"    s: float = c4d.utils.RangeMap((mgGen * ~mgEff * p).GetLength(), 0., 100., 0., 1., True)\n"
				"\n"
				"    # Set the weight #s as the value of all channels of a scaling vector which scales the\n"
				"    # Parameter.Position value of the effector #op.\n"
				"    return c4d.Vector(s)\n"
			);
		}
		case SCRIPT_CONTEXT::EFFECTOR_FULL_MODE:
		{
			return String(
				"\"\"\"Realizes an effector that attracts MoGraph particles spherically around its origin.\n"
				"\n"
				"Add the example to a Matrix object to understand its effect. In Full Control mode we can realize\n"
				"a true attraction force as we have full control over the particle values. Compare this example to\n"
				"Parameter Control mode to understand the difference.\n"
				"\"\"\"\n"
				"import c4d\n"
				"\n"
				"op: c4d.BaseObject # The Python Effector object containing this code.\n"
				"gen: c4d.BaseObject # The MoGraph Generator executing `op`.\n"
				"doc: c4d.documents.BaseDocument # The document `op` and `gen`are contained in.\n"
				"\n"
				"def main() -> bool:\n"
				"    \"\"\"Called by Cinema 4D to evaluate the effector.\n"
				"    \"\"\"\n"
				"    # Get the particle data for the effector #op. Get out when either the data cannot be retrieved.\n"
				"    data: c4d.modules.mograph.MoData = c4d.modules.mograph.GeGetMoData(op)\n"
				"    if data is None:\n"
				"        return 1.0\n"
				"\n"
				"    # The transform of both the generator and the effector, the transforms of all particles, and\n"
				"    # finally the position of the effector as if it would live in the coordinate system of the\n"
				"    # generator.\n"
				"    mgGen: c4d.Matrix = gen.GetMg()\n"
				"    mgEff: c4d.Matrix = op.GetMg()\n"
				"    matrices: list[c4d.Matrix] = data.GetArray(c4d.MODATA_MATRIX)\n"
				"    q: c4d.Vector = ~mgGen * mgEff.off\n"
				"\n"
				"    # For each particle compute a weight `w` for how much the particle should be attracted to the\n"
				"    # attraction point `q`, and then blend the particle position between the attraction point and \n"
				"    # its own position `p`.\n"
				"    for i in range(data.GetCount()) :\n"
				"        p: c4d.Vector = matrices[i].off\n"
				"        w: float = c4d.utils.RangeMap((mgGen * ~mgEff * p).GetLength(), 0., 100., 0., 1., True) ** 3.\n"
				"        matrices[i].off = c4d.utils.MixVec(q, p, w)\n"
				"\n"
				"    # Write the new data back.\n"
				"    data.SetArray(c4d.MODATA_MATRIX, matrices, op[c4d.FIELDS].HasContent())\n"
				"    return True\n");
		}
		case SCRIPT_CONTEXT::FIELD_OBJECT:
		{
			return String(
				"\"\"\"Realizes a field that exerts weight based on the distance of a sample point to the origin of\n"
				"the effector.\n"
				"\n"
				"Add a Plain Effector to a densely tessellated Sphere object and set the effector to Deformer.Point\n"
				"mode and its Parameter.Position value to (0, 0, 100). Then link this field in the effector to \n"
				"explore this example.\n"
				"\"\"\"\n"
				"\n"
				"import c4d\n"
				"\n"
				"doc: c4d.documents.BaseDocument  # The document containing this field object.\n"
				"\n"
				"def Sample(op: c4d.modules.mograph.FieldObject, inputs: c4d.modules.mograph.FieldInput,\n"
				"           outputs: c4d.modules.mograph.FieldOutputBlock, info: c4d.modules.mograph.FieldInfo) -> bool:\n"
				"    \"\"\"Called by Cinema 4D to sample the field.\n"
				"    \"\"\"\n"
				"    mgEffector: c4d.Matrix = op.GetMg() # The transform of the field.\n"
				"    mgInput: c4d.Matrix = inputs._transform # The transform of the inputs.\n"
				"\n"
				"    # Compute output weights as the distance of the sample points to the origin of the field #op,\n"
				"    # clamped to a 100 units radius sphere at the origin of the field #op.\n"
				"    outputs._value = [\n"
				"        c4d.utils.RangeMap((~mgEffector * mgInput * p).GetLength(), 100., 0., 0., 1., True)\n"
				"        for p in inputs._position\n"
				"    ]\n"
				"\n"
				"    outputs.ClearDeactivated(False)\n"
				"    return True\n");
		}
		case SCRIPT_CONTEXT::FIELD_LAYER:
		{
			return String(
				"import c4d\n"
				"import math\n"
				"\n"
				"doc: c4d.documents.BaseDocument  # The document evaluating this fields layer\n"
				"\n"
				"\n"
				"def Sample(op: c4d.modules.mograph.FieldLayer,  # The Python field layer\n"
				"           inputs: c4d.modules.mograph.FieldInput,  # The input value to sample\n"
				"           outputs: c4d.modules.mograph.FieldOutputBlock,  # The sampling output arrays (pre-allocated)\n"
				"           info: c4d.modules.mograph.FieldInfo) -> bool:  # The sampling context\n"
				"    # Calculate the output values for the specified set of input points.\n"
				"\n"
				"    time = doc.GetTime().Get()\n"
				"\n"
				"    # Getting/Setting outputs underlying list from C++ to Python is costly.\n"
				"    # So we retrieve a python list that we will set back once values are computed.\n"
				"    values = outputs._value\n"
				"    colors = outputs._color\n"
				"    positions = inputs._position\n"
				"    if not positions:\n"
				"        positions = [c4d.Vector()] * inputs._blockCount\n"
				"\n"
				"    for i in range(0, inputs._blockCount):\n"
				"        index: int = i + inputs._blockOffset\n"
				"        lastIndex: int = inputs._fullArraySize - 1\n"
				"\n"
				"        # Calculate the Value channel of the Python Field bellow\n"
				"        value = math.sin(math.pi * time * 2 + float(index) * 4 / lastIndex) * 0.5 + 0.5\n"
				"        radius = 1 - positions[i].GetLength() / 100.0\n"
				"        cosradius = math.cos(radius * 4 + time * math.pi * 2) * 0.5 + 0.5\n"
				"        values[i] = value * cosradius\n"
				"\n"
				"        # Depending on the color parameters of the Effector and FieldLayer, color arrays could be empty.\n"
				"        if colors:\n"
				"            radius = 1 - min(1.0, positions[i].GetLength() / 200.0)\n"
				"            colors[i] = c4d.Vector(radius, radius / 2.0, 0.3)\n"
				"\n"
				"    outputs._value = values\n"
				"    if colors:\n"
				"        outputs._alpha = [1.0] * inputs._blockCount\n"
				"        outputs._color = colors\n"
				"\n"
				"    # No shape clipping here.\n"
				"    outputs.ClearDeactivated(False)\n"
				"\n"
				"    # Return false to cancel further sampling.\n"
				"    return True\n");
		}
		case SCRIPT_CONTEXT::TAG_PYTHON:
		{
			return String(
				"\"\"\"Realizes a tag that drives the orientation of the object it is attached to.\n"
				"\n"
				"Uncomment the last line of the script and press play to the see the effect of the tag. You can still \n"
				"set the position of the object this tag is attached to, but the tag will drive its orientation. The \n"
				"object will rotate around its x-axis based on the current document time.\n"
				"\"\"\"\n"
				" \n"
				"import c4d\n"
				"\n"
				"doc: c4d.documents.BaseDocument  # The document containing this field object.\n"
				"op: c4d.BaseTag # The Python tag containing this code.\n"
				"flags: int # The execution flags of `main()`. See c4d.EXECUTIONFLAGS for details.\n"
				"priority: int # The execution priority of this tag. See c4d.EXECUTIONPRIORITY for details.\n"
				"tp: c4d.modules.thinkingparticles.TP_MasterSystem # The TP system of the document.\n"
				"\n"
				"def main() -> None:\n"
				"    \"\"\"Called by Cinema 4D to execute the tag.\n"
				"    \"\"\"\n"
				"    # Get the object the tag is attached to and its global position.\n"
				"    obj: c4d.BaseObject = op.GetObject()\n"
				"    off: c4d.Vector = obj.GetMg().off\n"
				"\n"
				"    # Compute a transform for a rotation around the x-axis based on the current document time and\n"
				"    # write the global position `off` into it. Then write the whole transform into `obj.`\n"
				"    mg: c4d.Matrix = c4d.utils.MatrixRotX(doc.GetTime().Get() * 2.)\n"
				"    mg.off = off\n"
				"\n"
				"    # Uncomment the line below to cause the tag to drive the rotation of its host.\n"
				"    # obj.SetMg(mg)\n");
		}
		case SCRIPT_CONTEXT::TAG_INTERACTION:
		{
			return String(
				"\"\"\"Prints text to the console when the user presses the left mouse button.\n"
				"\"\"\"\n"
				"\n"
				"import c4d\n"
				"\n"
				"doc: c4d.documents.BaseDocument  # The document containing this tag.\n"
				"tag: c4d.BaseTag # The Interaction tag containing this code.\n"
				"op: c4d.BaseObject # The object which is holding this tag.\n"
				"qualifier: int # The currently pressed qualifier keys. Can be c4d.QUALIFIER_SHIFT, c4d.QUALIFIER_CTRL, or 0.\n"
				"proxy: c4d.BaseObject | None # The object where action should occur. Can be `None`.\n"
				"\n"
				"def mouseDown():\n"
				"    \"\"\"Called by Cinema 4D when the user presses the left mouse button.\n"
				"    \"\"\"\n"
				"    print(f\"Mouse Down: {qualifier = }\")\n");
		}
		// TODO: (Ferdinand) Provide more sensible default code for S&T material and CA tag scripts.
		case SCRIPT_CONTEXT::TAG_VISUAL_SELECTOR:
			return String("");
		case SCRIPT_CONTEXT::TAG_CHARACTER_COMPONENT:
			return String("");
		case SCRIPT_CONTEXT::MAT_SKETCHTOON_COLOR:
		{
			return String(
				"import c4d\n"
				"#Welcome to the world of Python\n"
				"\n"
				"def main():\n"
				"    return c4d.Vector()\n");
		}
		case SCRIPT_CONTEXT::MAT_SKETCHTOON_THICKNESS:
		{
			return String(
				"import c4d\n"
				"#Welcome to the world of Python\n"
				"\n"
				"def main():\n"
				"    return 1.0\n");
		}
		case SCRIPT_CONTEXT::MAT_SKETCHTOON_OPACITY:
		{
			return String(
				"import c4d\n"
				"#Welcome to the world of Python\n"
				"\n"
				"def main():\n"
				"    return 1.0\n");
		}
		case SCRIPT_CONTEXT::GVNODE_PYTHON:
		{
			return String(
				"import c4d\n"
				"\n"
				"op: c4d.modules.graphview.GvNode # The Python Xpresso node containing this code.\n"
				"doc: c4d.documents.BaseDocument # The document `op` is contained in.\n"
				"tp: c4d.modules.thinkingparticles.TP_MasterSystem # The TP particle system of `doc`.\n"
				"\n"
				"def main() -> None:\n"
				"    \"\"\"Called by Cinema 4D to compute the node.\n"
				"\n"
				"    All output ports must be defined as global variables as shown below.\n"
				"    \"\"\"\n"
				"    global Output1\n"
				"    Output1 = Input1 + Input2\n");
		}
		default:
			return ""_s;
			break;
	}
}

} // namespace cinema
