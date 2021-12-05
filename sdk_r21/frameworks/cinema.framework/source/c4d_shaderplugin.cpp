#include "operatingsystem.h"
#include "c4d_general.h"
#include "c4d_shaderplugin.h"
#include "c4d_resource.h"
#ifndef __API_INTERN__
	#include "c4d_tools.h"
#else
	#include "shdlist.h"
#endif

SHADERINFO ShaderData::GetRenderInfo(BaseShader* chn)
{
	return SHADERINFO::NONE;
}

INITRENDERRESULT ShaderData::InitRender(BaseShader* chn, const InitRenderStruct& irs)
{
	return INITRENDERRESULT::OK;
}

void ShaderData::FreeRender(BaseShader* chn)
{
}

Vector ShaderData::Output(BaseShader* chn, ChannelData* cd)
{
	return Vector(0.0);
}

Bool ShaderData::Draw(BaseShader* chn, BaseObject* op, BaseTag* tag, BaseDraw* bd, BaseDrawHelp* bh)
{
	return true;
}

GL_MESSAGE ShaderData::GlMessage(BaseShader* sh, Int32 type, void* msgdata)
{
	return GL_MESSAGE::ERROR_;
}

Int32 ShaderData::InitGLImage(BaseShader* sh, BaseDocument* doc, BaseThread* th, BaseBitmap* bmp, Bool alpha, Int32 doccolorspace, Bool linearworkflow)
{
	return 0;
}

void ShaderData::DestroyGLImage(BaseShader* sh, BaseDocument* doc)
{
}

void ShaderData::InvalidateGLImage(BaseShader* sh, BaseDocument* doc)
{
}

Bool ShaderData::GetGLImageSize(BaseShader* sh, BaseDocument* doc, Int32 s, Bool noScale, Int32& w, Int32& h)
{
	return false;
}

BaseShader* ShaderData::GetSubsurfaceShader(BaseShader* sh, Float& bestmpl)
{
	return nullptr;
}

void FillShaderPlugin(SHADERPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel)
{
	FillNodePlugin(np, info, npalloc, nullptr, disklevel);

	np->Draw = &ShaderData::Draw;
	np->GetRenderInfo	= &ShaderData::GetRenderInfo;
	np->InitRender = &ShaderData::InitRender;
	np->FreeRender = &ShaderData::FreeRender;
	np->Output = &ShaderData::Output;
	np->GlMessage	= &ShaderData::GlMessage;
	np->InitGLImage	= &ShaderData::InitGLImage;
	np->GetGLImageSize = &ShaderData::GetGLImageSize;
	np->DestroyGLImage = &ShaderData::DestroyGLImage;
	np->InvalidateGLImage	= &ShaderData::InvalidateGLImage;
	np->GetSubsurfaceShader	= &ShaderData::GetSubsurfaceShader;
}

Bool RegisterShaderPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* npalloc, const maxon::String& description, Int32 disklevel)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	SHADERPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillShaderPlugin(&np, npalloc, info, disklevel);
	return GeRegisterPlugin(PLUGINTYPE::SHADER, id, str, &np, sizeof(np));
}
