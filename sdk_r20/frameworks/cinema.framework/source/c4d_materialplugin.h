/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MATERIALPLUGIN_H__
#define C4D_MATERIALPLUGIN_H__

#include "ge_math.h"
#include "c4d_materialdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct MATERIALPLUGIN : public NODEPLUGIN
{
	Bool							(MaterialData::*Draw							)(BaseMaterial *mat, BaseObject *op, BaseTag *tag, BaseDraw *bd, BaseDrawHelp *bh);

	VOLUMEINFO				(MaterialData::*GetRenderInfo			)(BaseMaterial *mat);
	INITRENDERRESULT	(MaterialData::*InitRender				)(BaseMaterial *mat, const InitRenderStruct &irs);
	void							(MaterialData::*FreeRender				)(BaseMaterial *mat);
	void							(MaterialData::*InitCalculation		)(BaseMaterial *mat, VolumeData *vd, INITCALCULATION type);
	void							(MaterialData::*Displace					)(BaseMaterial *mat, VolumeData *vd);
	void							(MaterialData::*ChangeNormal			)(BaseMaterial *mat, VolumeData *vd);
	void							(MaterialData::*CalcSurface				)(BaseMaterial *mat, VolumeData *vd);
	void							(MaterialData::*CalcTransparency	)(BaseMaterial *mat, VolumeData *vd);
	void							(MaterialData::*CalcAlpha					)(BaseMaterial *mat, VolumeData *vd);
	void							(MaterialData::*CalcVolumetric		)(BaseMaterial *mat, VolumeData *vd);
	Bool							(MaterialData::*InitGLImage				)(BaseMaterial *mat, BaseDocument* doc, BaseThread* th, BaseBitmap *bmp, Int32 doccolorspace, Bool linearworkflow);
	GL_MESSAGE				(MaterialData::*GlMessage					)(BaseMaterial *mat, Int32 type, void *data);
	Bool							(MaterialData::*HasEditorTransparency)(BaseMaterial *mat);

	void* reserved[(32-14)*C4DPL_MEMBERMULTIPLIER-0];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_MATERIALPLUGIN_H__
