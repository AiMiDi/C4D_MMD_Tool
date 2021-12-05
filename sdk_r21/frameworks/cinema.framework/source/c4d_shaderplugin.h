/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SHADERPLUGIN_H__
#define C4D_SHADERPLUGIN_H__

#include "ge_math.h"
#include "c4d_shaderdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SHADERPLUGIN : public NODEPLUGIN
{
	SHADERINFO				(ShaderData::*GetRenderInfo				)(BaseShader *chn);
	INITRENDERRESULT	(ShaderData::*InitRender					)(BaseShader *chn, const InitRenderStruct &irs);
	void							(ShaderData::*FreeRender					)(BaseShader *chn);
	Bool							(ShaderData::*Draw								)(BaseShader *chn, BaseObject *op, BaseTag *tag, BaseDraw *bd, BaseDrawHelp *bh);
	Vector						(ShaderData::*Output							)(BaseShader *chn, ChannelData *cd);
	GL_MESSAGE				(ShaderData::*GlMessage						)(BaseShader *sh, Int32 type, void *msgdata);
	Int32							(ShaderData::*InitGLImage					)(BaseShader *sh, BaseDocument* doc, BaseThread* th, BaseBitmap *bmp, Bool alpha, Int32 doccolorspace, Bool linearworkflow);
	void							(ShaderData::*DestroyGLImage			)(BaseShader *sh, BaseDocument* doc);
	void							(ShaderData::*InvalidateGLImage		)(BaseShader *sh, BaseDocument* doc);
	Bool							(ShaderData::*GetGLImageSize			)(BaseShader *sh, BaseDocument* doc, Int32 s, Bool noScale, Int32 &w, Int32 &h);
	BaseShader*				(ShaderData::*GetSubsurfaceShader	)(BaseShader *sh, Float &bestmpl);

	void* reserved[(32-11)*C4DPL_MEMBERMULTIPLIER-0];
};

void FillShaderPlugin(SHADERPLUGIN *np, DataAllocator *npalloc, Int32 info, Int32 disklevel);

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_SHADERPLUGIN_H__
