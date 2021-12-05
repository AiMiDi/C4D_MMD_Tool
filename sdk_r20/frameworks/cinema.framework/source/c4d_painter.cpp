#include "c4d_painter.h"



TempUVHandle::TempUVHandle()
{
}

TempUVHandle::~TempUVHandle()
{
}

Int32 TempUVHandle::GetMode()
{
	return C4DOS.Pa->UVSetGetMode(this);
}

const Vector* TempUVHandle::GetPoint()
{
	return C4DOS.Pa->UVSetGetPoint(this);
}

Int32 TempUVHandle::GetPointCount()
{
	return C4DOS.Pa->UVSetGetPointCount(this);
}

const CPolygon* TempUVHandle::GetPoly()
{
	return C4DOS.Pa->UVSetGetPoly(this);
}

Int32 TempUVHandle::GetPolyCount()
{
	return C4DOS.Pa->UVSetGetPolyCount(this);
}

UVWStruct* TempUVHandle::GetUVW()
{
	return C4DOS.Pa->UVSetGetUVW(this);
}

BaseSelect* TempUVHandle::GetPolySel()
{
	return C4DOS.Pa->UVSetGetPolySel(this);
}

BaseSelect* TempUVHandle::GetPolyHid()
{
	return C4DOS.Pa->UVSetGetPolyHid(this);
}

BaseSelect* TempUVHandle::GetUVPointSel()
{
	return C4DOS.Pa->UVSetGetPointSel(this);
}

Bool TempUVHandle::IsEditable()
{
	return C4DOS.Pa->UVSetIsEditable(this);
}

BaseObject* TempUVHandle::GetBaseObject()
{
	return C4DOS.Pa->UVSetGetBaseObject(this);
}

Bool TempUVHandle::SetUVW(UVWStruct* uvw)
{
	return C4DOS.Pa->UVSetSetUVW(this, uvw);
}

Bool TempUVHandle::SetUVWFromTextureView(UVWStruct* uvw, Bool ignoreHidden, Bool ignoreUnselected, Bool autoSelectAll, Bool registerUndo)
{
	return C4DOS.Pa->UVSetSetUVWFromTextureView(this, uvw, ignoreHidden, ignoreUnselected, autoSelectAll, registerUndo);
}

Int32 IdentifyImage(const Filename& texpath)
{
	return C4DOS.Pa->IdentifyImage(texpath);
}

void* SendPainterCommand(Int32 command, BaseDocument* doc, PaintTexture* tex, BaseContainer* bc)
{
	return C4DOS.Pa->SendPainterCommand(command, doc, tex, bc);
}

TempUVHandle* GetActiveUVSet(BaseDocument* doc, Int32 flags)
{
	return C4DOS.Pa->GetActiveUVSet(doc, flags);
}

void FreeActiveUVSet(TempUVHandle* handle)
{
	C4DOS.Pa->FreeActiveUVSet(handle);
}

Bool CallUVCommand(const Vector* padr, Int32 PointCount, const CPolygon* polys, Int32 lPolyCount, UVWStruct* uvw, BaseSelect* polyselection,
									 BaseSelect* pointselection, BaseObject* op, Int32 mode, Int32 cmdid, const BaseContainer& settings)
{
	return C4DOS.Pa->CallUVCommand(padr, PointCount, polys, lPolyCount, uvw, polyselection, pointselection, op, mode, cmdid, settings);
}

#ifndef __API_INTERN__

PaintTexture* PaintTexture::CreateNewTexture(const Filename& path, const BaseContainer& settings)
{
	return C4DOS.Pa->CreateNewTexture(path, settings);
}

Bool PaintTexture::GetTextureDefaults(Int32 channel, BaseContainer& settings)
{
	return C4DOS.Pa->GetTextureDefaults(channel, settings);
}

#endif

Bool BPSetupWizardWithParameters(BaseDocument* doc, const BaseContainer& settings, AtomArray& objects, AtomArray& material)
{
	return C4DOS.Pa->BPSetupWizardWithParameters(doc, settings, objects, material);
}

Bool CalculateTextureSize(BaseDocument* doc, AtomArray& materials, TextureSize*& sizes)
{
	return C4DOS.Pa->CalculateTextureSize(doc, materials, sizes);
}

Bool GetAllStrings_AddTexture(const void* msgdata, const BaseContainer& d)
{
	return C4DOS.Pa->GetAllStrings_AddTexture(msgdata, d);
}

void PainterActivateChannel(Int32 channel, Bool multi, Bool enable)
{
	C4DOS.Pa->PN_ActivateChannel(channel, multi, enable);
}

PaintTexture*	PainterCreateNewTextureDialog(String& result, Filename& resultdirectory, Int32 channelid, BaseMaterial* bmat)
{
	return C4DOS.Pa->PT_CreateNewTextureDialog(result, resultdirectory, channelid, bmat);
}

#ifndef __API_INTERN__

static Int32 RecCntLayer(PaintLayer* a)
{
	Int32 cnt = 0;
	for (; a; a = (PaintLayer*)a->GetNext())
	{
		cnt++;
		if (a->GetLayerDownFirst())
			cnt += RecCntLayer(a->GetLayerDownFirst());
	}
	return cnt;
}

Int32 PaintTexture::GetAlphaCount() const
{
	return RecCntLayer(((PaintTexture*)this)->GetAlphaFirst());
}

Int32 PaintTexture::GetLayerCount() const
{
	return RecCntLayer(((PaintTexture*)this)->GetFirstLayer());
}

#endif
