#include "c4d_painter.h"


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif


TempUVHandle::TempUVHandle()
{
}

TempUVHandle::~TempUVHandle()
{
}

Int32 TempUVHandle::GetMode()
{
	return C4DOS_Pa->UVSetGetMode(this);
}

const Vector* TempUVHandle::GetPoint()
{
	return C4DOS_Pa->UVSetGetPoint(this);
}

Int32 TempUVHandle::GetPointCount()
{
	return C4DOS_Pa->UVSetGetPointCount(this);
}

const CPolygon* TempUVHandle::GetPoly()
{
	return C4DOS_Pa->UVSetGetPoly(this);
}

Int32 TempUVHandle::GetPolyCount()
{
	return C4DOS_Pa->UVSetGetPolyCount(this);
}

UVWStruct* TempUVHandle::GetUVW()
{
	return C4DOS_Pa->UVSetGetUVW(this);
}

BaseSelect* TempUVHandle::GetPolySel()
{
	return C4DOS_Pa->UVSetGetPolySel(this);
}

BaseSelect* TempUVHandle::GetPolyHid()
{
	return C4DOS_Pa->UVSetGetPolyHid(this);
}

BaseSelect* TempUVHandle::GetUVPointSel()
{
	return C4DOS_Pa->UVSetGetPointSel(this);
}

EdgeBaseSelect* TempUVHandle::GetUVEdgeSel()
{
	return C4DOS_Pa->UVSetGetEdgeSel(this);
}

maxon::Block<Int32> TempUVHandle::GetUVIslands()
{
	return C4DOS_Pa->UVGetIslands(this);
}

Bool TempUVHandle::IsEditable()
{
	return C4DOS_Pa->UVSetIsEditable(this);
}

BaseObject* TempUVHandle::GetBaseObject()
{
	return C4DOS_Pa->UVSetGetBaseObject(this);
}

Bool TempUVHandle::SetUVW(UVWStruct* uvw)
{
	return C4DOS_Pa->UVSetSetUVW(this, uvw);
}

Bool TempUVHandle::SetUVWFromTextureView(UVWStruct* uvw, Bool ignoreHidden, Bool ignoreUnselected, Bool autoSelectAll, Bool registerUndo)
{
	return C4DOS_Pa->UVSetSetUVWFromTextureView(this, uvw, ignoreHidden, ignoreUnselected, autoSelectAll, registerUndo);
}

Bool TempUVHandle::SetUVPointSelectionFromTextureView(const BaseSelect* uvPointSelection, Bool bleedSelection)
{
	return C4DOS_Pa->UVSetSetUVPointSelectionFromTextureView(this, uvPointSelection, bleedSelection);
}

Bool TempUVHandle::SetUVEdgeSelection(const BaseSelect* uvEdgeSelection)
{
	return C4DOS_Pa->UVSetSetUVEdgeSelection(this, uvEdgeSelection);
}

Int32 IdentifyImage(const Filename& texpath)
{
	return C4DOS_Pa->IdentifyImage(texpath);
}

void* SendPainterCommand(Int32 command, BaseDocument* doc, PaintTexture* tex, BaseContainer* bc)
{
	return C4DOS_Pa->SendPainterCommand(command, doc, tex, bc);
}

TempUVHandle* GetActiveUVSet(BaseDocument* doc, Int32 flags)
{
	return C4DOS_Pa->GetActiveUVSet(doc, flags);
}

Bool UpdateMeshUV(Bool fullUpdate)
{
	return C4DOS_Pa->UpdateMeshUVInt(fullUpdate);
}

const EdgeBaseSelect* GetUVSeams(const BaseObject* obj)
{
	return C4DOS_Pa->GetUVSeams(obj);
}

const EdgeBaseSelect* GetUVSeams2(const BaseObject* obj, Bool checkUVSettings)
{
	return C4DOS_Pa->GetUVSeams2(obj, checkUVSettings);
}

void FreeActiveUVSet(TempUVHandle* handle)
{
	C4DOS_Pa->FreeActiveUVSet(handle);
}

Bool CallUVCommand(const Vector* padr, Int32 PointCount, const CPolygon* polys, Int32 lPolyCount, UVWStruct* uvw, BaseSelect* polyselection,
									 BaseSelect* pointselection, BaseObject* op, Int32 mode, Int32 cmdid, const BaseContainer& settings)
{
	return C4DOS_Pa->CallUVCommand(padr, PointCount, polys, lPolyCount, uvw, polyselection, pointselection, op, mode, cmdid, settings);
}

#ifndef __API_INTERN__

PaintTexture* PaintTexture::CreateNewTexture(const Filename& path, const BaseContainer& settings)
{
	return C4DOS_Pa->CreateNewTexture(path, settings);
}

Bool PaintTexture::GetTextureDefaults(Int32 channel, BaseContainer& settings)
{
	return C4DOS_Pa->GetTextureDefaults(channel, settings);
}

#endif

Bool BPSetupWizardWithParameters(BaseDocument* doc, const BaseContainer& settings, AtomArray& objects, AtomArray& material)
{
	return C4DOS_Pa->BPSetupWizardWithParameters(doc, settings, objects, material);
}

Bool CalculateTextureSize(BaseDocument* doc, AtomArray& materials, TextureSize*& sizes)
{
	return C4DOS_Pa->CalculateTextureSize(doc, materials, sizes);
}

Bool GetAllStrings_AddTexture(const void* msgdata, const BaseContainer& d)
{
	return C4DOS_Pa->GetAllStrings_AddTexture(msgdata, d);
}

void PainterActivateChannel(Int32 channel, Bool multi, Bool enable)
{
	C4DOS_Pa->PN_ActivateChannel(channel, multi, enable);
}

PaintTexture*	PainterCreateNewTextureDialog(String& result, Filename& resultdirectory, Int32 channelid, BaseMaterial* bmat)
{
	return C4DOS_Pa->PT_CreateNewTextureDialog(result, resultdirectory, channelid, bmat);
}

maxon::Result<maxon::DrawportTextureInterface*> PainterGetBrush(BaseDraw* bd, PaintBrushData& brushData)
{
	return C4DOS_Pa->PT_GetBrush(bd, brushData);
}


#ifndef __API_INTERN__

static Int32 RecCntLayer(const PaintLayer* a)
{
	Int32 cnt = 0;
	for (; a; a = static_cast<const PaintLayer*>(a->GetNext()))
	{
		cnt++;
		if (a->GetLayerDownFirst())
			cnt += RecCntLayer(a->GetLayerDownFirst());
	}
	return cnt;
}

Int32 PaintTexture::GetAlphaCount() const
{
	return RecCntLayer(GetAlphaFirst());
}

Int32 PaintTexture::GetLayerCount() const
{
	return RecCntLayer(GetFirstLayer());
}

#endif


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
