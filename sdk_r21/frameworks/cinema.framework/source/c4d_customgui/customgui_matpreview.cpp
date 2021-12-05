#include "customgui_matpreview.h"

static CustomGuiMatPreviewLib *lib_MatPreview = nullptr;


static CustomGuiMatPreviewLib *CheckGuiMatPreviewLib(Int32 offset)
{
	return (CustomGuiMatPreviewLib*)CheckLib(CUSTOMGUI_MATPREVIEW, offset, (C4DLibrary**)&lib_MatPreview);
}

#define MatPreviewCall(b) 			CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																			if (!lib || !lib->b) return; \
																			(((iMatPreviewData*)this)->*lib->b)

#define MatPreviewCallR(a, b) 		CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																			if (!lib || !lib->b) return a; \
																			return (((iMatPreviewData*)this)->*lib->b)

#define MatPreviewGuiCall(b) 		CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																			if (!lib || !lib->b) return; \
																			(((iMatPreviewCustomGui*)this)->*lib->b)

#define MatPreviewGuiCallR(a, b) CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																		if (!lib || !lib->b) return a; \
																		return (((iMatPreviewCustomGui*)this)->*lib->b)

#define MatPreviewCallFn(b)     CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																		if (!lib || !lib->b) return; \
																		lib->b

#define MatPreviewCallFnR(a, b) CustomGuiMatPreviewLib *lib = CheckGuiMatPreviewLib(LIBOFFSET(CustomGuiMatPreviewLib, b)); \
																		if (!lib || !lib->b) return a; \
																		return lib->b

Bool MaterialPreviewData::Init(BaseChannel *pChannel, Int32 lCount)
{
	MatPreviewCallR(false, InitChannel)(pChannel, lCount);
}

Bool MaterialPreviewData::Init(BaseShader* pShader, Int32 lCount)
{
	MatPreviewCallR(false, InitShader)(pShader, lCount);
}

Bool MaterialPreviewData::Init(BaseMaterial* pMaterial, Int32 lCount)
{
	MatPreviewCallR(false, InitMaterial)(pMaterial, lCount);
}

Bool MaterialPreviewData::Init(BaseBitmap* pImage, Int32 lCount)
{
	MatPreviewCallR(false, InitBitmap)(pImage, lCount);
}

Bool MaterialPreviewData::Init(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, Int32 lCount)
{
	MatPreviewCallR(false, InitFunction)(fn, pUserData, lUserID, lCount);
}

void MaterialPreviewData::AnimatePreview(Bool bAnimate)
{
	MatPreviewCall(AnimatePreview)(bAnimate);
}

Bool MaterialPreviewData::PreviewIsAnimated()
{
	MatPreviewCallR(false, PreviewIsAnimated)();
}

void MaterialPreviewData::SetPreviewType(MatPreviewType t)
{
	MatPreviewCall(SetPreviewType)(t);
}

MatPreviewType MaterialPreviewData::GetPreviewType()
{
	MatPreviewCallR(MatPreviewFlat2D, GetPreviewType)();
}

void MaterialPreviewData::SetPreviewSize(MatPreviewSize s)
{
	MatPreviewCall(SetPreviewSize)(s);
}

MatPreviewSize MaterialPreviewData::GetPreviewSize()
{
	MatPreviewCallR(MatPreviewSizeDefault, GetPreviewSize)();
}

void MaterialPreviewData::SetObjectMatrix(const Matrix &m)
{
	MatPreviewCall(SetObjectMatrix)(m);
}

Bool MaterialPreviewData::GetObjectMatrix(Matrix &m)
{
	MatPreviewCallR(false, GetObjectMatrix)(m);
}

void MaterialPreviewData::SetUserPreviewSceneName(const maxon::String &strName)
{
	MatPreviewCall(SetUserPreviewSceneName)(strName);
}

String MaterialPreviewData::GetUserPreviewSceneName()
{
	MatPreviewCallR(String(), GetUserPreviewSceneName)();
}

void MaterialPreviewData::ClearObjectMatrix()
{
	MatPreviewCall(ClearObjectMatrix)();
}

Float MaterialPreviewData::GetWorldSize()
{
	MatPreviewCallR(1.0, GetWorldSize)();
}

void MaterialPreviewData::SetWorldSize(Float r)
{
	MatPreviewCall(SetWorldSize)(r);
}

Float MaterialPreviewData::GetPreviewStartTime()
{
	MatPreviewCallR(0.0, GetPreviewStartTime)();
}

void MaterialPreviewData::SetPreviewStartTime(Float r)
{
	MatPreviewCall(SetPreviewStartTime)(r);
}

void MaterialPreviewData::GetEnvironment(Vector &col, Float &strength)
{
	MatPreviewCall(GetEnvironment)(col, strength);
}

void MaterialPreviewData::SetEnvironment(const Vector &col, const Float &strength)
{
	MatPreviewCall(SetEnvironment)(col, strength);
}

Int32 MaterialPreviewData::GetDirtyCount()
{
	MatPreviewCallR(-1, GetDirtyCount)();
}

Bool MaterialPreviewData::GetRegion(Float &l, Float &t, Float &r, Float &b)
{
	MatPreviewCallR(false, GetRegion)(l, t, r, b);
}

void MaterialPreviewData::SetRegion(Bool bActive, Float l, Float t, Float r, Float b)
{
	MatPreviewCall(SetRegion)(bActive, l, t, r, b);
}

Int32 MaterialPreviewData::GetPreviewChannel()
{
	MatPreviewCallR(-1, GetPreviewChannel)();
}

void MaterialPreviewData::SetPreviewChannel(Int32 lChannel)
{
	MatPreviewCall(SetPreviewChannel)(lChannel);
}

Int32 MaterialPreviewData::GetReflectionLayer()
{
	MatPreviewCallR(-1, GetReflectionLayer)();
}

void MaterialPreviewData::SetReflectionLayer(Int32 lLayer)
{
	MatPreviewCall(SetReflectionLayer)(lLayer);
}

Bool SetDParameterPreview(BaseContainer* pContainer, const GeData* pData, DESCFLAGS_SET &lFlags, Int32 lID)
{
	MatPreviewCallFnR(false, MatPreview_SetDParameterPreview)(pContainer, pData, lFlags, lID);
}

Bool GetDParameterPreview(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseMaterial* pMaterial)
{
	MatPreviewCallFnR(false, MatPreview_GetDParameterPreviewMat)(pContainer, pData, lFlags, lID, lCount, pMaterial);
}

Bool GetDParameterPreview(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseShader* pShader)
{
	MatPreviewCallFnR(false, MatPreview_GetDParameterPreviewShd)(pContainer, pData, lFlags, lID, lCount, pShader);
}

RENDERRESULT RenderMaterialPreview(const Filename &docpath, BaseMaterial* pMatClone, BaseMaterial* pOrigMat, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags)
{
	MatPreviewCallFnR(RENDERRESULT::OUTOFMEMORY, MatPreview_RenderMaterialPreview)(docpath, pMatClone, pOrigMat, pThread, pDest, pOriginalDoc, rCurrentTime, lFlags);
}

RENDERRESULT RenderShaderPreview(const Filename &docpath, BaseShader* pShaderClone, BaseShader* pOrigShader, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags)
{
	MatPreviewCallFnR(RENDERRESULT::OUTOFMEMORY, MatPreview_RenderShaderPreview)(docpath, pShaderClone, pOrigShader, pThread, pDest, pOriginalDoc, rCurrentTime, lFlags);
}

RENDERRESULT RenderCustomPreview(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, BaseThread* pThread, BaseBitmap* pDest, Int32 lFlags)
{
	MatPreviewCallFnR(RENDERRESULT::OUTOFMEMORY, MatPreview_RenderCustomPreview)(fn, pUserData, lUserID, pThread, pDest, lFlags);
}

BaseContainer GetPreviewScenes(Bool bIncludeFlat2D, Bool bIncludeDefault, Int32 lObjectID)
{
	MatPreviewCallFnR(BaseContainer(), MatPreview_GetPreviewScenes)(bIncludeFlat2D, bIncludeDefault, lObjectID);
}

Bool HandlePreviewSceneMessage(Int32 lID, MatPreviewType &t, maxon::String &strScene)
{
	MatPreviewCallFnR(false, MatPreview_HandlePreviewSceneMessage)(lID, t, strScene);
}

Bool AddUserPreviewScene(const Filename &fn, Int32 lID, maxon::String* pstrName)
{
	MatPreviewCallFnR(false, MatPreview_AddUserPreviewScene)(fn, lID, pstrName);
}
