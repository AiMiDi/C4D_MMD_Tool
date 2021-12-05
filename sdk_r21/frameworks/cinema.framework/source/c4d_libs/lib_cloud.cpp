#include "lib_cloud.h"

static CloudObjectLib *lib_CloudObject = nullptr;

static CloudObjectLib *CheckCloudObjectLib(Int32 offset)
{
	return (CloudObjectLib*)CheckLib(LIB_CLOUD, offset, (C4DLibrary**)&lib_CloudObject);
}

#define CloudCall(b)       CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(((iCloudObject*)this)->*lib->b)

#define CloudCallR(a, b)     CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iCloudObject*)this)->*lib->b)


CloudObject* CloudObject::Alloc()
{
	CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, Alloc));
	if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void CloudObject::Free(CloudObject *&pObj)
{
	CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, Free));
	if (!lib || !lib->Free) return;
	lib->Free(pObj);
}

void CloudObject::SetDrawHook(CloudDrawFn fn)
{
	CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, SetDrawHook));
	if (!lib || !lib->SetDrawHook) return;
	lib->SetDrawHook(fn);
}


void CloudObject::GetSize(Vector& vSize)
{
	CloudCall(GetSize1)(vSize);
}

void CloudObject::GetSize(Int32 &x, Int32 &y, Int32 &z)
{
	CloudCall(GetSize2)(x, y, z);
}

UChar* CloudObject::GetDensity()
{
	CloudCallR(nullptr, GetDensity)();
}

UChar* CloudObject::GetToolData()
{
	CloudCallR(nullptr, GetToolData)();
}

Bool CloudObject::AllocToolData()
{
	CloudCallR(false, AllocToolData)();
}

void CloudObject::FreeToolData()
{
	CloudCall(FreeToolData)();
}

Int CloudObject::GetDensitySize()
{
	CloudCallR(0, GetDensitySize)();
}

Float CloudObject::GetAltitude(BaseObject* pCloudGroup)
{
	CloudCallR(0.0f, GetAltitude)(pCloudGroup);
}

Bool CloudObject::Resize(Int32 x, Int32 y, Int32 z, Bool bResample)
{
	CloudCallR(false, Resize)(x, y, z, bResample);
}

Bool CloudObject::SmoothBorders(Float rDist, Float rVariance, SplineData* pSpline)
{
	CloudCallR(false, SmoothBorders)(rDist, rVariance, pSpline);
}

Bool CloudObject::SmoothAll(Float rStrength, Float rVariance)
{
	CloudCallR(false, SmoothAll)(rStrength, rVariance);
}

void CloudObject::Clear(UChar chDensity)
{
	CloudCall(Clear)(chDensity);
}

void CloudObject::FillPlane(Float rRadius, UChar chDensity)
{
	CloudCall(FillPlane)(rRadius, chDensity);
}

void CloudObject::FillSphere(Float rRadius, UChar chDensity)
{
	CloudCall(FillSphere)(rRadius, chDensity);
}

Bool CloudObject::IsVisible(Bool bEditor, Bool &bDrawBox, BaseObject *&pSkyObject, BaseObject** ppGroup)
{
	CloudCallR(false, IsVisible)(bEditor, bDrawBox, pSkyObject, ppGroup);
}

Bool CloudObject::IsLocked()
{
	CloudCallR(false, IsLocked)();
}

Int32 CloudObject::GetPlaneIndex()
{
	CloudCallR(-1, GetPlaneIndex)();
}

void CloudObject::SetPlaneIndex(Int32 lPlane)
{
	CloudCall(SetPlaneIndex)(lPlane);
}

Int32 CloudObject::GetPlanePosition()
{
	CloudCallR(-1, GetPlanePosition)();
}

void CloudObject::SetPlanePosition(Int32 lPos)
{
	CloudCall(SetPlanePosition)(lPos);
}

void CloudObject::Draw(BaseDraw* pBaseDraw, BaseDrawHelp* pDrawHelp, Int32 lGrid, Float rQuality, Bool bDrawPlane)
{
	CloudCall(Draw)(pBaseDraw, pDrawHelp, lGrid, rQuality, bDrawPlane);
}

void* CloudObject::GetPrivateData(CloudDataAllocator fnAlloc, ClodDataDeleter fnFree)
{
	CloudCallR(nullptr, GetPrivateData)(fnAlloc, fnFree);
}

BaseObject* FindSkyObject(BaseDocument* pDoc)
{
	CloudObjectLib *lib = CheckCloudObjectLib(LIBOFFSET(CloudObjectLib, FindSkyObject));
	if (!lib || !lib->FindSkyObject) return nullptr;
	return lib->FindSkyObject(pDoc);
}

