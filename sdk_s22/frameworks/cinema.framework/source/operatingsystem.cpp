#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "operatingsystem.h"
#include "c4d_basebitmap.h"

OperatingSystem* t_C4DOS = nullptr;

Int32 InitOS(void* p)
{
	t_C4DOS = ((OperatingSystem*)p);
	return C4DOS.version;
}

BaseBitmap* IconData::GetClonePart() const
{
	if (!bmp)
		return nullptr;

	BaseBitmap* res = bmp->GetClonePart(x, y, w, h);
	if (!res)
		return nullptr;

	res->SetData(BASEBITMAP_DATA_GUIPIXELRATIO, bmp->GetData(BASEBITMAP_DATA_GUIPIXELRATIO, GeData(1.0)));

	return res;
}

BaseBitmap* IconData::GetGuiScalePart() const
{
	if (!bmp)
		return nullptr;

	Int32				dw	= GetGuiW();
	Int32				dh	= GetGuiH();
	BaseBitmap* res = BaseBitmap::Alloc();
	if (!res || (IMAGERESULT::OK != res->Init(dw, dh)))
	{
		BaseBitmap::Free(res);
		return nullptr;
	}

	if (bmp->GetInternalChannel() != nullptr)
		res->AddChannel(true, false);

	bmp->ScaleBicubic(res, x, y, x + w - 1, y + h - 1, 0, 0, dw - 1, dh - 1);
	res->SetData(BASEBITMAP_DATA_GUIPIXELRATIO, 1.0);
	return res;
}

Int32 IconData::GetGuiW() const
{
	if (!bmp)
		return w;

	Float f = bmp->GetData(BASEBITMAP_DATA_GUIPIXELRATIO, 1.0).GetFloat();
	Int32 d = w;
	if (f != 0.0)
	{
		d = Int32(d / f);
	}
	return d;
}

Int32 IconData::GetGuiH() const
{
	if (!bmp)
		return h;

	Float f = bmp->GetData(BASEBITMAP_DATA_GUIPIXELRATIO, 1.0).GetFloat();
	Int32 d = h;
	if (f != 0.0)
	{
		d = Int32(d / f);
	}
	return d;
}
