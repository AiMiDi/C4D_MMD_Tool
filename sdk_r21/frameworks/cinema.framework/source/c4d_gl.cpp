#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "ge_math.h"
#include "c4d_gl.h"

#define GlStringCall(fn) (this->*C4DOS.GL->fn)
#define GlPFCall(fn) (this->*C4DOS.GL->fn)
#define GlVBCall(fn) (this->*C4DOS.GL->fn)

/************************************************************************/
/* GlString                                                             */
/************************************************************************/
GlString::GlString()
{
	GlStringCall(SDKInit1)();
}

GlString::GlString(const char* pszString)
{
	GlStringCall(SDKInit2)(pszString);
}

GlString::GlString(const GlString& str)
{
	GlStringCall(SDKInit3)(str);
}

GlString::GlString(Int32 n)
{
	GlStringCall(SDKInit4)(n);
}

GlString::GlString(Float r, const char* pszFormat)
{
	GlStringCall(SDKInit5)(r, pszFormat);
}

GlString::~GlString()
{
	GlStringCall(SDKFree)();
}

const GlString& GlString::operator = (const GlString &str)
{
	return GlStringCall(SDKAssign1)(str);
}

const GlString& GlString::operator = (const char* pszString)
{
	return GlStringCall(SDKAssign2)(pszString);
}

const GlString operator + (const GlString &str1, const GlString &str2)
{
	return C4DOS.GL->GlStringAdd1(str1, str2);
}

const GlString& GlString::operator += (const GlString &str)
{
	return GlStringCall(GlStringAdd3)(str);
}

const GlString operator + (const GlString &str1, const char* str2)
{
	return C4DOS.GL->GlStringAdd2(str1, str2);
}

const GlString& GlString::operator += (const char* str)
{
	return GlStringCall(GlStringAdd4)(str);
}

Int32 GlString::Compare(const GlString& s) const
{
	return GlStringCall(Compare)(s);
}

const char* GlString::GetCString() const
{
	return GlStringCall(GetCString)();
}

Int GlString::GetLength() const
{
	return GlStringCall(GetLength)();
}

Int32 GlString::Replace(const GlString& strSearch, const GlString &strReplace, Int lStart, Bool bReplaceAll, Bool bOnlyWord)
{
	return GlStringCall(Replace)(strSearch, strReplace, lStart, bReplaceAll, bOnlyWord);
}



/************************************************************************/
/* GlProgramFactory                                                   */
/************************************************************************/
GlProgramFactory::GlProgramFactory()
{
}

GlProgramFactory::~GlProgramFactory()
{
}

GlProgramFactory* GlProgramFactory::GetFactory(const BaseDraw* pBaseDraw, C4DAtom* pObj, Int32 lIndex, GlProgramFactoryMessageCallback fnCallback, void* pIdentity, Int lIdentityLength,
																							 const GlLight* const* ppLights, Int32 lLightCount, UInt64 ulFlags,
																							 const GlVertexBufferAttributeInfo* const* ppBufferAttributeInfo, Int32 lBufferAttributeInfoCount,
																							 const GlVertexBufferVectorInfo* const* ppBufferVectorInfo, Int32 lBufferVectorInfoCount,
																							 GlFBAdditionalTextureInfo* pAdditionalTextures)
{
	return C4DOS.GL->GetFactory(pBaseDraw, pObj, lIndex, fnCallback, pIdentity, lIdentityLength, ppLights, lLightCount, ulFlags, ppBufferAttributeInfo,
		lBufferAttributeInfoCount, ppBufferVectorInfo, lBufferVectorInfoCount, pAdditionalTextures);
}

void GlProgramFactory::RemoveReference(C4DAtom* pObj, UInt64 ulIndex)
{
	C4DOS.GL->RemoveReference(pObj, ulIndex);
}

void GlProgramFactory::RemoveTextureReference(C4DAtom* pObj, Int32 lIndex)
{
	C4DOS.GL->RemoveTextureReferenceA(pObj, lIndex);
}

void GlProgramFactory::RemoveTextureReference(const Filename &fn)
{
	C4DOS.GL->RemoveTextureReferenceB(fn);
}

#undef IncreaseBufferSize
void* GlProgramFactory::_IncreaseBufferSize(GlGetIdentity* pIdentity, Int lNeededSize, Int32 lLine, const char* pszFile)
{
	return C4DOS.GL->IncreaseBufferSize(pIdentity, lNeededSize, lLine, pszFile);
}

Bool GlProgramFactory::BindToView(const BaseDraw* pDraw)
{
	return GlPFCall(BindToView)(pDraw);
}

Bool GlProgramFactory::CompilePrograms()
{
	return GlPFCall(CompilePrograms)();
}

Bool GlProgramFactory::CompileCgFX(const Filename& fn, UInt32 ulFlags)
{
	return GlPFCall(CompileCgFX)(fn, ulFlags);
}

Bool GlProgramFactory::IsPrecompiled() const
{
	return GlPFCall(IsPrecompiled)();
}

Bool GlProgramFactory::BindPrograms()
{
	return GlPFCall(BindPrograms)();
}

Bool GlProgramFactory::BindCgFXPrograms(Int32 lTechnique, Int32 lPass)
{
	return GlPFCall(BindCgFXPrograms)(lTechnique, lPass);
}

Bool GlProgramFactory::UnbindPrograms()
{
	return GlPFCall(UnbindPrograms)();
}

Bool GlProgramFactory::DestroyPrograms()
{
	return GlPFCall(DestroyPrograms)(false);
}

void GlProgramFactory::LockFactory()
{
	GlPFCall(LockFactory)();
}

void GlProgramFactory::UnlockFactory()
{
	GlPFCall(UnlockFactory)();
}

Bool GlProgramFactory::InitLightParameters()
{
	return GlPFCall(InitLightParameters)();
}

Int32 GlProgramFactory::GetMaxLights()
{
	return GlPFCall(GetMaxLights)();
}

void* GlProgramFactory::GetPrivateData(const void* pObj, Int32 lDataIndex, GlProgramFactoryAllocPrivate fnAlloc, GlProgramFactoryFreePrivate fnFree)
{
	return GlPFCall(GetPrivateData)(pObj, lDataIndex, fnAlloc, fnFree);
}

void* GlProgramFactory::GetDescriptionData(Int32 lObjIndex, Int32 lDataIndex, GlProgramFactoryAllocPrivate fnAlloc, GlProgramFactoryFreePrivate fnFree, GlProgramFactoryReadDescription fnRead, GlProgramFactoryWriteDescription fnWrite)
{
	return GlPFCall(GetDescriptionData)(lObjIndex, lDataIndex, fnAlloc, fnFree, fnRead, fnWrite);
}

Bool GlProgramFactory::IsProgram(GlProgramType t)
{
	return GlPFCall(IsProgram)(t);
}

void GlProgramFactory::InitSetParameters()
{
	GlPFCall(InitSetParameters)();
}

void GlProgramFactory::SetScreenCoordinates(BaseDraw* pBaseDraw)
{
	GlPFCall(SetScreenCoordinates)(pBaseDraw);
}

void GlProgramFactory::AddErrorHandler(GlProgramFactoryErrorHandler fn)
{
	GlPFCall(AddErrorHandler)(fn);
}

Bool GlProgramFactory::SetParameterMatrixTransform(GlProgramParameter param)
{
	return GlPFCall(SetParameterMatrixTransform)(param);
}

Bool GlProgramFactory::SetParameterMatrix(GlProgramParameter param, const Matrix4d32 &m)
{
	return GlPFCall(SetParameterMatrix1)(param, m);
}

Bool GlProgramFactory::SetParameterMatrix(GlProgramParameter paramOffset, GlProgramParameter paramAxes, GlProgramParameter paramNormalTrans, const Matrix32 &m)
{
	return GlPFCall(SetParameterMatrix2)(paramOffset, paramAxes, paramNormalTrans, m);
}

Bool GlProgramFactory::SetParameterMatrix3x3(GlProgramParameter param, const Float32* r)
{
	return GlPFCall(SetParameterMatrix3x3)(param, r);
}

Bool GlProgramFactory::SetParameterMatrix4x4(GlProgramParameter param, const Float32* r)
{
	return GlPFCall(SetParameterMatrix4x4)(param, r);
}

Bool GlProgramFactory::SetParameterVector(GlProgramParameter param, const Vector32 &v)
{
	return GlPFCall(SetParameterVector1)(param, v);
}

Bool GlProgramFactory::SetParameterVector(GlProgramParameter param, const Vector4d32 &v)
{
	return GlPFCall(SetParameterVector2)(param, v);
}

Bool GlProgramFactory::SetParameterVector(GlProgramParameter param, const Vector32 &v, Float32 w)
{
	return GlPFCall(SetParameterVector3)(param, v, w);
}

Bool GlProgramFactory::SetParameterColor(GlProgramParameter param, const Vector &v, Float rBrightness)
{
	return GlPFCall(SetParameterColor1)(param, v, rBrightness);
}

Bool GlProgramFactory::SetParameterColor(GlProgramParameter param, const Vector &v, Float rBrightness, Float32 rAlpha)
{
	return GlPFCall(SetParameterColor2)(param, v, rBrightness, rAlpha);
}

Bool GlProgramFactory::SetParameterColorReverse(GlProgramParameter param, const Vector &v, Float rBrightness)
{
	return GlPFCall(SetParameterColorReverse1)(param, v, rBrightness);
}

Bool GlProgramFactory::SetParameterColorReverse(GlProgramParameter param, const Vector &v, Float rBrightness, Float32 rAlpha)
{
	return GlPFCall(SetParameterColorReverse2)(param, v, rBrightness, rAlpha);
}

Bool GlProgramFactory::SetParameterReal(GlProgramParameter param, const Float32 r)
{
	return GlPFCall(SetParameterReal)(param, r);
}

Bool GlProgramFactory::SetParameterReal2(GlProgramParameter param, Float32 a, Float32 b)
{
	return GlPFCall(SetParameterReal2a)(param, a, b);
}

Bool GlProgramFactory::SetParameterReal2(GlProgramParameter param, const Float32* v)
{
	return GlPFCall(SetParameterReal2b)(param, v);
}

Bool GlProgramFactory::SetParameterReal3(GlProgramParameter param, Float32 a, Float32 b, Float32 c)
{
	return GlPFCall(SetParameterReal3a)(param, a, b, c);
}

Bool GlProgramFactory::SetParameterReal3(GlProgramParameter param, const Float32* v)
{
	return GlPFCall(SetParameterReal3b)(param, v);
}

Bool GlProgramFactory::SetParameterReal4(GlProgramParameter param, Float32 a, Float32 b, Float32 c, Float32 d)
{
	return GlPFCall(SetParameterReal4a)(param, a, b, c, d);
}

Bool GlProgramFactory::SetParameterReal4(GlProgramParameter param, const Float32* v)
{
	return GlPFCall(SetParameterReal4b)(param, v);
}

Bool GlProgramFactory::SetParameterInt(GlProgramParameter param, int a)
{
	return GlPFCall(SetParameterInt)(param, a);
}

Bool GlProgramFactory::SetParameterInt2(GlProgramParameter param, int a, int b)
{
	return GlPFCall(SetParameterInt2a)(param, a, b);
}

Bool GlProgramFactory::SetParameterInt2(GlProgramParameter param, const int* v)
{
	return GlPFCall(SetParameterInt2b)(param, v);
}

Bool GlProgramFactory::SetParameterInt3(GlProgramParameter param, int a, int b, int c)
{
	return GlPFCall(SetParameterInt3a)(param, a, b, c);
}

Bool GlProgramFactory::SetParameterInt3(GlProgramParameter param, const int* v)
{
	return GlPFCall(SetParameterInt3b)(param, v);
}

Bool GlProgramFactory::SetParameterInt4(GlProgramParameter param, int a, int b, int c, int d)
{
	return GlPFCall(SetParameterInt4a)(param, a, b, c, d);
}

Bool GlProgramFactory::SetParameterInt4(GlProgramParameter param, const int* v)
{
	return GlPFCall(SetParameterInt4b)(param, v);
}

Bool GlProgramFactory::SetParameterUint(GlProgramParameter param, unsigned int l)
{
	return GlPFCall(SetParameterUint)(param, l);
}

Bool GlProgramFactory::SetParameterUint2(GlProgramParameter param, unsigned int a, unsigned int b)
{
	return GlPFCall(SetParameterUint2a)(param, a, b);
}

Bool GlProgramFactory::SetParameterUint2(GlProgramParameter param, const unsigned int* v)
{
	return GlPFCall(SetParameterUint2b)(param, v);
}

Bool GlProgramFactory::SetParameterUint3(GlProgramParameter param, unsigned int a, unsigned int b, unsigned int c)
{
	return GlPFCall(SetParameterUint3a)(param, a, b, c);
}

Bool GlProgramFactory::SetParameterUint3(GlProgramParameter param, const unsigned int* v)
{
	return GlPFCall(SetParameterUint3b)(param, v);
}

Bool GlProgramFactory::SetParameterUint4(GlProgramParameter param, unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	return GlPFCall(SetParameterUint4a)(param, a, b, c, d);
}

Bool GlProgramFactory::SetParameterUint4(GlProgramParameter param, const unsigned int* v)
{
	return GlPFCall(SetParameterUint4b)(param, v);
}

Bool GlProgramFactory::SetParameterRealArray(GlProgramParameter param, Int32 lElements, const Float32 *r)
{
	return GlPFCall(SetParameterRealArray)(param, lElements, r);
}

Bool GlProgramFactory::SetParameterTexture2D(GlProgramParameter param, const BaseBitmap* pBmp, Int32 lFlags, DRAW_ALPHA alphamode, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTexture2D1)(param, pBmp, lFlags, alphamode, pnHandle);
}

Bool GlProgramFactory::SetParameterTexture2D(GlProgramParameter param, const Filename &fn, Int32 lFrame, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, const LayerSet* pLayerSet, GlTextureInfo* pInfo, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTexture2D2)(param, fn, lFrame, pObj, lIndex, lFlags, alphamode, lMaxSize, pLayerSet, pInfo, pnHandle);
}

Bool GlProgramFactory::SetParameterTexture2D(GlProgramParameter param, const BaseBitmap* pBmp, UInt32 ulDirty, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlTextureInfo* pInfo, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTexture2D3)(param, pBmp, ulDirty, pObj, lIndex, lFlags, alphamode, lMaxSize, pInfo, pnHandle);
}

Bool GlProgramFactory::CacheTextureFn(BaseDraw* pBaseDraw, const Filename &fn, Int32 lFrame, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlProgramType progType, const LayerSet* pLayerSet, GlTextureInfo* pInfo, C4DGLuint* pnHandle)
{
	return C4DOS.GL->CacheTextureFn(pBaseDraw, fn, lFrame, pObj, lIndex, lFlags, alphamode, lMaxSize, progType, pLayerSet, pInfo, pnHandle);
}

Bool GlProgramFactory::CacheTextureBmp(BaseDraw* pBaseDraw, const BaseBitmap* pBmp, UInt32 ulDirty, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlProgramType progType, GlTextureInfo* pInfo, C4DGLuint* pnHandle)
{
	return C4DOS.GL->CacheTextureBmp(pBaseDraw, pBmp, ulDirty, pObj, lIndex, lFlags, alphamode, lMaxSize, progType, pInfo, pnHandle);
}

Bool GlProgramFactory::SetParameterTexture(GlProgramParameter param, Int32 lDimension, C4DGLuint nTexture)
{
	return GlPFCall(SetParameterTexture)(param, lDimension, nTexture);
}

Bool GlProgramFactory::SetParameterTextureCube(GlProgramParameter param, C4DGLuint nTexture)
{
	return GlPFCall(SetParameterTextureCube)(param, nTexture);
}

Bool GlProgramFactory::SetParameterTexture2DDepth(GlProgramParameter param, C4DGLuint nTexture)
{
	return GlPFCall(SetParameterTexture2DDepth)(param, nTexture);
}

Bool GlProgramFactory::SetParameterTextureCubeDepth(GlProgramParameter param, C4DGLuint nTexture)
{
	return GlPFCall(SetParameterTextureCubeDepth)(param, nTexture);
}

Bool GlProgramFactory::SetParameterTextureGradient(GlProgramParameter param, const Gradient* pGradient, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTextureGradient)(param, pGradient, pObj, lIndex, lFlags, pnHandle);
}

Bool GlProgramFactory::SetParameterTextureFunction(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, GlProgramFactoryCreateTextureFunctionCallback fn, void* pData, Int lDataLen,
		Int32 lInParams, Int32 lOutParams, Int32 lCycle, Bool bInterpolate, Int32 lSizeX, Int32 lSizeY, Int32 lSizeZ, Bool bParallel, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTextureFunction)(param, pObj, lIndex, lFlags, lDataType, fn, pData, lDataLen, lInParams, lOutParams, lCycle, bInterpolate, lSizeX, lSizeY, lSizeZ, bParallel, pnHandle);
}

Bool GlProgramFactory::SetParameterTextureRaw(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, const void* pData, Int lDataLen, UInt32 ulDirty,
														Int32 lDimension, Int32 lComponents, Int32 lCycle, Bool bInterpolate, Int32 lSizeX, Int32 lSizeY, Int32 lSizeZ, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTextureRaw)(param, pObj, lIndex, lFlags, lDataType, pData, lDataLen, ulDirty, lDimension, lComponents, lCycle, bInterpolate, lSizeX, lSizeY, lSizeZ, pnHandle);
}

Bool GlProgramFactory::SetParameterTextureCubeMap(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, GlProgramFactoryCreateTextureFunctionCallback fn, void* pData, Int lDataLen,
																Int32 lOutParams, Int32 lCycle, Bool bInterpolate, Int32 lSize, Bool bParallel, C4DGLuint* pnHandle)
{
	return GlPFCall(SetParameterTextureCubeMap)(param, pObj, lIndex, lFlags, lDataType, fn, pData, lDataLen, lOutParams, lCycle, bInterpolate, lSize, bParallel, pnHandle);
}

Bool GlProgramFactory::SetLightParameters(const GlLight* const* ppLights, Int32 lLightCount, const Matrix4d32& mObject)
{
	return GlPFCall(SetLightParameters)(ppLights, lLightCount, mObject);
}

UInt64 GlProgramFactory::Init(Int32 lSubdivisionCount, Int32 lGeometryTypeIn, Int32 lGeometryTypeOut, Int32 lMaxOutVertices)
{
	return GlPFCall(Init)(lSubdivisionCount, lGeometryTypeIn, lGeometryTypeOut, lMaxOutVertices);
}

void GlProgramFactory::AddParameters(UInt64 ulParameters, UInt64 ulFormat)
{
	GlPFCall(AddParameters)(ulParameters, ulFormat);
}

UInt64 GlProgramFactory::GetParameters() const
{
	return GlPFCall(GetParameters)();
}

UInt64 GlProgramFactory::GetParameterFormats() const
{
	return GlPFCall(GetParameterFormats)();
}

GlString GlProgramFactory::AddUniformParameter(GlProgramType t, GlUniformParamType p, const char* pszName)
{
	return GlPFCall(AddUniformParameter1)(t, p, pszName);
}

GlString GlProgramFactory::AddUniformParameter(GlProgramType t, GlUniformParamType p, Int32 lCount, const char* pszName)
{
	return GlPFCall(AddUniformParameter2)(t, p, lCount, pszName);
}

Bool GlProgramFactory::HeaderFinished()
{
	return GlPFCall(HeaderFinished)();
}

const UChar* GlProgramFactory::GetIdentity() const
{
	return GlPFCall(GetIdentity)();
}

GlProgramParameter GlProgramFactory::GetParameterHandle(GlProgramType t, const char* pszName) const
{
	return GlPFCall(GetParameterHandle)(t, pszName);
}

Bool GlProgramFactory::GetCgFXDescription(BaseContainer* pbcDescription)
{
	return GlPFCall(GetCgFXDescription)(pbcDescription);
}

Bool GlProgramFactory::AddLightProjection()
{
	return GlPFCall(AddLightProjection)();
}

void GlProgramFactory::AddLine(GlProgramType t, const GlString &strLine)
{
	GlPFCall(AddLine)(t, strLine);
}

void GlProgramFactory::AddDepthCompareCondition(GlProgramType t, const GlString &strPeelTexture)
{
	GlPFCall(AddDepthCompareCondition)(t, strPeelTexture);
}

Bool GlProgramFactory::AddEncryptedBlock(GlProgramType t, const char* pchData, Int lDataLength, const UChar* pchKey, Int32 lKeyLength)
{
	return GlPFCall(AddEncryptedBlock)(t, pchData, lDataLength, pchKey, lKeyLength);
}

GlString GlProgramFactory::AddColorBlendFunction(GlProgramType t, Int32 lBlendMode)
{
	return GlPFCall(AddColorBlendFunction)(t, lBlendMode);
}

GlString GlProgramFactory::AddRGBToHSVFunction(GlProgramType t)
{
	return GlPFCall(AddRGBToHSVFunction)(t);
}

GlString GlProgramFactory::AddHSVToRGBFunction(GlProgramType t)
{
	return GlPFCall(AddHSVToRGBFunction)(t);
}

GlString GlProgramFactory::AddRGBToHSLFunction(GlProgramType t)
{
	return GlPFCall(AddRGBToHSLFunction)(t);
}

GlString GlProgramFactory::AddHSLToRGBFunction(GlProgramType t)
{
	return GlPFCall(AddHSLToRGBFunction)(t);
}

Bool GlProgramFactory::AddFunction(GlProgramType t, const GlString &strFunction)
{
	return GlPFCall(AddFunction)(t, strFunction);
}

Bool GlProgramFactory::AddEmitVertex()
{
	return GlPFCall(AddEmitVertex)();
}

void GlProgramFactory::StartLightLoop()
{
	GlPFCall(StartLightLoop)();
}

Bool GlProgramFactory::EndLightLoop()
{
	return GlPFCall(EndLightLoop)();
}

GlString GlProgramFactory::GetUniqueID()
{
	return GlPFCall(GetUniqueID)();
}

Int32 GlProgramFactory::GetUniqueIDCount()
{
	return GlPFCall(GetUniqueIDCount)();
}

Bool GlProgramFactory::HasNoiseSupport(GlProgramType t, Int32 lNoise, BaseDraw* pBaseDraw, Int32 lCompiler)
{
	return C4DOS.GL->HasNoiseSupport(t, lNoise, pBaseDraw, lCompiler);
}

const GlString& GlProgramFactory::AddNoiseFunction(GlProgramType t, Int32 lNoise, Int32 lFlags)
{
	return GlPFCall(AddNoiseFunction)(t, lNoise, lFlags);
}

void GlProgramFactory::GetVectorInfo(Int32 &lVectorCount, const GlVertexBufferVectorInfo* const* &ppVectorInfo) const
{
	return GlPFCall(GetVectorInfo)(lVectorCount, ppVectorInfo);
}

UInt32 GlProgramFactory::GetLanguageFeatures(BaseDraw* bd, Int32 lCompiler, Int32 lFlags)
{
	return C4DOS.GL->GetLanguageFeatures(bd, lCompiler, lFlags);
}

Int32 GlProgramFactory::GetCompiler()
{
	return GlPFCall(GetCompiler)();
}

Bool GlProgramFactory::WriteParameter(GlWriteDescriptionData* pFile, GlProgramParameter param)
{
	return C4DOS.GL->WriteParameter(pFile, param);
}

Bool GlProgramFactory::ReadParameter(GlReadDescriptionData* pFile, GlProgramParameter& param)
{
	return C4DOS.GL->ReadParameter(pFile, param);
}

/************************************************************************/
/* GlFrameBuffer                                                        */
/************************************************************************/
GlFrameBuffer* GlFrameBuffer::GetFrameBuffer(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2, UINT nWidth, UINT nHeight, Int32 lColorTextureCount,
																						 Int32 lDepthTextureCount, Int32 lColorCubeCount, Int32 lDepthCubeCount, UInt32 ulFlags,
																						 Int32 lAAMode, GlFBAdditionalTextureInfo* pAdditionalTextures)
{
	return C4DOS.GL->GetFrameBuffer(pBaseDraw, lID1, lID2, nWidth, nHeight, lColorTextureCount, lDepthTextureCount, lColorCubeCount, lDepthCubeCount, ulFlags, lAAMode, pAdditionalTextures);
}

GlFrameBuffer* GlFrameBuffer::FindFrameBuffer(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2)
{
	return C4DOS.GL->FindFrameBuffer(pBaseDraw, lID1, lID2);
}

void GlFrameBuffer::RemoveObject(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2)
{
	C4DOS.GL->RemoveObjectF(pBaseDraw, lID1, lID2);
}

void GlFrameBuffer::PrepareForRendering(BaseDraw* pBaseDraw, Int32 lTexture)
{
	GlPFCall(PrepareForRendering)(pBaseDraw, lTexture);
}

void GlFrameBuffer::SetInterpolation(BaseDraw* pBaseDraw, Int32 lInterpolate, Int32 lTexture, Int32 lFlags)
{
	GlPFCall(SetInterpolation)(pBaseDraw, lInterpolate, lTexture, lFlags);
}

Bool GlFrameBuffer::Activate(BaseDraw* pBaseDraw)
{
	return GlPFCall(Activate)(pBaseDraw);
}

void GlFrameBuffer::Deactivate(BaseDraw* pBaseDraw)
{
	GlPFCall(Deactivate)(pBaseDraw);
}

Bool GlFrameBuffer::SetRenderTarget(Int32 lTexture, Int32 lFlags)
{
	return GlPFCall(SetRenderTarget)(lTexture, lFlags);
}

void GlFrameBuffer::GetRatios(Int32 lFlags, Float& rWidth, Float& rHeight)
{
	GlPFCall(GetRatios)(lFlags, rWidth, rHeight);
}

void GlFrameBuffer::GetSize(Int32 lFlags, UINT &nWidth, UINT &nHeight, Bool bFramesize)
{
	GlPFCall(GetSize)(lFlags, nWidth, nHeight, bFramesize);
}

C4DGLuint GlFrameBuffer::GetTexture(Int32 lTexture, Int32 lFlags) const
{
	return GlPFCall(GetTexture)(lTexture, lFlags);
}

GlFBAdditionalTextureInfo* GlFrameBuffer::GetAdditionalTexture(Int32 lType, void* pBuffer) const
{
	return GlPFCall(GetAdditionalTexture)(lType, pBuffer);
}

IMAGERESULT GlFrameBuffer::SaveTextureToDisk(BaseDraw* pBaseDraw, const Filename &fn, Int32 lTexture, Int32 lFlags)
{
	return GlPFCall(SaveTextureToDisk)(pBaseDraw, fn, lTexture, lFlags);
}

Bool GlFrameBuffer::CopyToBitmap(BaseDraw* pBaseDraw, BaseBitmap* pBmp, Int32 lTexture, Int32 lFlags)
{
	return GlPFCall(CopyToBitmap)(pBaseDraw, pBmp, lTexture, lFlags);
}

Bool GlFrameBuffer::GetTextureData(BaseDraw* pBaseDraw, Int32 x1, Int32 y1, Int32 x2, Int32 y2, void* pData, Int32 lTexture, Int32 lFlags) const
{
	return GlPFCall(GetTextureData)(pBaseDraw, x1, y1, x2, y2, pData, lTexture, lFlags);
}

Bool GlFrameBuffer::CopyToBuffer(void* pBuffer, Int lBufferSize, Int32 lTexture, Int32 lFlags) const
{
	return GlPFCall(CopyToBuffer)(pBuffer, lBufferSize, lTexture, lFlags);
}

Bool GlFrameBuffer::DrawBuffer(Int32 lTexture, Int32 lFlags, Bool bCopyAlpha, Int32 lColorConversion, C4DGLint nConversionTexture, Float32 rAlpha, const Vector32 &vColor, Float32 xs1, Float32 ys1, Float32 xs2, Float32 ys2, Float32 xd1, Float32 yd1, Float32 xd2, Float32 yd2)
{
	return GlPFCall(DrawBuffer)(lTexture, lFlags, bCopyAlpha, lColorConversion, nConversionTexture, rAlpha, vColor, xs1, ys1, xs2, ys2, xd1, yd1, xd2, yd2);
}

void GlFrameBuffer::Clear()
{
	GlPFCall(Clear1)();
}

void GlFrameBuffer::Clear(const Vector32 &vColor, Float32 rAlpha)
{
	GlPFCall(Clear2)(vColor, rAlpha);
}

Bool GlFrameBuffer::IsNPOTBuffer()
{
	return GlPFCall(IsNPOTBuffer)();
}

/************************************************************************/
/* GlVertexBuffer                                                       */
/************************************************************************/
GlVertexBuffer* GlVertexBuffer::GetVertexBuffer(const BaseDraw* pBaseDraw, C4DAtom* pObj, Int32 lIndex, void* pIdentity, Int lIdentityLen, UInt32 ulFlags)
{
	return C4DOS.GL->GetVertexBuffer(pBaseDraw, pObj, lIndex, pIdentity, lIdentityLen, ulFlags);
}

void GlVertexBuffer::RemoveObject(C4DAtom* pObj, Int32 lIndex)
{
	C4DOS.GL->RemoveObjectV(pObj, lIndex);
}

Bool GlVertexBuffer::IsDirty()
{
	return GlVBCall(IsDirty)();
}

void GlVertexBuffer::SetDirty(Bool bDirty)
{
	GlVBCall(SetDirty)(bDirty);
}

Bool GlVertexBuffer::DrawSubBuffer(const BaseDraw* pBaseDraw, const GlVertexSubBufferData* pVertexSubBuffer, const GlVertexSubBufferData* pElementSubBuffer,
									 Int32 lDrawinfoCount, const GlVertexBufferDrawSubbuffer* pDrawInfo,
									 Int32 lVectorCount, const GlVertexBufferVectorInfo* const* ppVectorInfo, UInt32 flags,
									 GlVertexBufferDrawElementCallback fnCallback, void* pCallbackData)
{
	return C4DOS.GL->DrawSubBuffer(pBaseDraw, pVertexSubBuffer, pElementSubBuffer, lDrawinfoCount, pDrawInfo, lVectorCount, ppVectorInfo, flags, fnCallback, pCallbackData);
}

GlVertexSubBufferData* GlVertexBuffer::AllocSubBuffer(const BaseDraw* pBaseDraw, GlVertexBufferSubBufferType type, Int lSize, const void* pData)
{
	return GlVBCall(AllocSubBuffer)(pBaseDraw, type, lSize, pData);
}

GlVertexSubBufferData* GlVertexBuffer::AllocIndexSubBuffer(const BaseDraw* pBaseDraw, Int32 lCount, UInt32* pulIndex, Int32 lMaxIndex)
{
	return GlVBCall(AllocIndexSubBuffer1)(pBaseDraw, lCount, pulIndex, lMaxIndex);
}

GlVertexSubBufferData* GlVertexBuffer::AllocIndexSubBuffer(const BaseDraw* pBaseDraw, Int32 lCount, const UInt16* puwIndex)
{
	return GlVBCall(AllocIndexSubBuffer2)(pBaseDraw, lCount, puwIndex);
}

Bool GlVertexBuffer::FlushAllSubBuffers(const BaseDraw* pBaseDraw)
{
	return GlVBCall(FlushAllSubBuffers)(pBaseDraw);
}

Bool GlVertexBuffer::FreeBuffers(const BaseDraw* pBaseDraw, GlVertexBufferSubBufferType type)
{
	return GlVBCall(FreeBuffers)(pBaseDraw, type);
}

Bool GlVertexBuffer::FreeBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pBuffer)
{
	return GlVBCall(FreeBuffer)(pBaseDraw, pBuffer);
}

Bool GlVertexBuffer::MarkAllForDelete()
{
	return GlVBCall(MarkAllForDelete)();
}

Bool GlVertexBuffer::MarkBuffersForDelete(GlVertexBufferSubBufferType type)
{
	return GlVBCall(MarkBuffersForDelete)(type);
}

Bool GlVertexBuffer::MarkBufferForDelete(GlVertexSubBufferData* pBuffer)
{
	return GlVBCall(MarkBufferForDelete)(pBuffer);
}

Bool GlVertexBuffer::DeleteMarkedBuffers(const BaseDraw* pBaseDraw)
{
	return GlVBCall(DeleteMarkedBuffers)(pBaseDraw);
}

Bool GlVertexBuffer::SetSubBufferData(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer, Int lSize, const void* pData)
{
	return GlVBCall(SetSubBufferData)(pBaseDraw, pSubBuffer, lSize, pData);
}

Int32 GlVertexBuffer::GetSubBufferCount() const
{
	return GlVBCall(GetSubBufferCount)();
}

GlVertexSubBufferData* GlVertexBuffer::GetSubBuffer(Int32 n)
{
	return GlVBCall(GetSubBuffer)(n);
}

void* GlVertexBuffer::MapBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer, GlVertexBufferAccessFlags flags)
{
	return GlVBCall(MapBuffer)(pBaseDraw, pSubBuffer, flags);
}

Bool GlVertexBuffer::UnmapBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer)
{
	return GlVBCall(UnmapBuffer)(pBaseDraw, pSubBuffer);
}
