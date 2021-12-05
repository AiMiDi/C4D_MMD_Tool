#include "c4d_memory.h"
#include "c4d_general.h"
#include "c4d_materialplugin.h"
#include "c4d_resource.h"
#ifdef __API_INTERN__
	#include "shdlist.h"
#else
	#include "ge_prepass.h"
#endif

Bool MaterialData::Draw(BaseMaterial* mat, BaseObject* op, BaseTag* tag, BaseDraw* bd, BaseDrawHelp* bh)
{
	return true;
}

VOLUMEINFO MaterialData::GetRenderInfo(BaseMaterial* mat)
{
	return VOLUMEINFO::NONE;
}

INITRENDERRESULT MaterialData::InitRender(BaseMaterial* mat, const InitRenderStruct& irs)
{
	return INITRENDERRESULT::OK;
}

void MaterialData::FreeRender(BaseMaterial* mat)
{
}

void MaterialData::InitCalculation(BaseMaterial* mat, VolumeData* vd, INITCALCULATION type)
{
}

void MaterialData::Displace(BaseMaterial* mat, VolumeData* vd)
{
}

void MaterialData::ChangeNormal(BaseMaterial* mat, VolumeData* vd)
{
}

void MaterialData::CalcSurface(BaseMaterial* mat, VolumeData* vd)
{
}

void MaterialData::CalcTransparency(BaseMaterial* mat, VolumeData* vd)
{
}

void MaterialData::CalcAlpha(BaseMaterial* mat, VolumeData* vd)
{
}

void MaterialData::CalcVolumetric(BaseMaterial* mat, VolumeData* vd)
{
}

Bool MaterialData::InitGLImage(BaseMaterial* mat, BaseDocument* doc, BaseThread* th, BaseBitmap* bmp, Int32 doccolorspace, Bool linearworkflow)
{
	return true;
}

GL_MESSAGE MaterialData::GlMessage(BaseMaterial* mat, Int32 type, void* data)
{
	return GL_MESSAGE::ERROR_;
}

Bool MaterialData::HasEditorTransparency(BaseMaterial* mat)
{
	return false;
}


static void FillMaterialPlugin(MATERIALPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel)
{
	FillNodePlugin(np, info, npalloc, nullptr, disklevel);

	np->Draw = &MaterialData::Draw;
	np->GetRenderInfo	= &MaterialData::GetRenderInfo;
	np->InitRender = &MaterialData::InitRender;
	np->FreeRender = &MaterialData::FreeRender;
	np->InitCalculation	= &MaterialData::InitCalculation;
	np->Displace = &MaterialData::Displace;
	np->ChangeNormal = &MaterialData::ChangeNormal;
	np->CalcSurface	 = &MaterialData::CalcSurface;
	np->CalcTransparency = &MaterialData::CalcTransparency;
	np->CalcAlpha	= &MaterialData::CalcAlpha;
	np->CalcVolumetric = &MaterialData::CalcVolumetric;
	np->InitGLImage = &MaterialData::InitGLImage;
	np->GlMessage = &MaterialData::GlMessage;
	np->HasEditorTransparency = &MaterialData::HasEditorTransparency;
}

Bool RegisterMaterialPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* npalloc, const maxon::String& description, Int32 disklevel)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	MATERIALPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillMaterialPlugin(&np, npalloc, info, disklevel);
	return GeRegisterPlugin(PLUGINTYPE::MATERIAL, id, str, &np, sizeof(np));
}
