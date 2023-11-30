#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "operatingsystem.h"
#include "c4d_basebitmap.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif

// PrivateGetOS allows a trick to declare the variable t_C4DOS as "OperatingSystem* const"
// without this assignment the compiler moves t_C4DOS into readonly memory which causes an exception in InitOS();
MAXON_ATTRIBUTE_NO_INLINE static const void* PrivateGetOS()
{
	return nullptr;
}

OperatingSystem* const t_C4DOS = (OperatingSystem* const)PrivateGetOS();
C4D_General* const			 t_C4DOS_Ge = (C4D_General * const)PrivateGetOS();
C4D_Shader* const				 t_C4DOS_Sh = (C4D_Shader * const)PrivateGetOS();
C4D_HyperFile* const		 t_C4DOS_Hf = (C4D_HyperFile * const)PrivateGetOS();
C4D_BaseContainer* const t_C4DOS_Bc = (C4D_BaseContainer * const)PrivateGetOS();
C4D_String* const				 t_C4DOS_St = (C4D_String * const)PrivateGetOS();
C4D_Bitmap* const				 t_C4DOS_Bm = (C4D_Bitmap * const)PrivateGetOS();
C4D_MovieSaver* const		 t_C4DOS_Ms = (C4D_MovieSaver * const)PrivateGetOS();
C4D_BaseChannel* const	 t_C4DOS_Ba = (C4D_BaseChannel * const)PrivateGetOS();
C4D_Filename* const			 t_C4DOS_Fn = (C4D_Filename * const)PrivateGetOS();
C4D_File* const					 t_C4DOS_Fl = (C4D_File * const)PrivateGetOS();
C4D_BrowseFiles* const	 t_C4DOS_Bf = (C4D_BrowseFiles * const)PrivateGetOS();
C4D_Dialog* const				 t_C4DOS_Cd = (C4D_Dialog * const)PrivateGetOS();
C4D_UserArea* const			 t_C4DOS_Cu = (C4D_UserArea * const)PrivateGetOS();
C4D_Parser* const				 t_C4DOS_Pr = (C4D_Parser * const)PrivateGetOS();
C4D_Resource* const			 t_C4DOS_Lr = (C4D_Resource * const)PrivateGetOS();
C4D_BaseList* const			 t_C4DOS_Bl = (C4D_BaseList * const)PrivateGetOS();
C4D_Tag* const					 t_C4DOS_Tg = (C4D_Tag * const)PrivateGetOS();
C4D_Object* const				 t_C4DOS_Bo = (C4D_Object * const)PrivateGetOS();
C4D_Document* const			 t_C4DOS_Bd = (C4D_Document * const)PrivateGetOS();
C4D_Thread* const				 t_C4DOS_Bt = (C4D_Thread * const)PrivateGetOS();
C4D_Material* const			 t_C4DOS_Mt = (C4D_Material * const)PrivateGetOS();
C4D_Texture* const			 t_C4DOS_Tx = (C4D_Texture * const)PrivateGetOS();
C4D_BaseSelect* const		 t_C4DOS_Bs = (C4D_BaseSelect * const)PrivateGetOS();
C4D_BaseSound* const		 t_C4DOS_Bu = (C4D_BaseSound * const)PrivateGetOS();
C4D_BaseDraw* const			 t_C4DOS_Br = (C4D_BaseDraw * const)PrivateGetOS();
C4D_BaseView* const			 t_C4DOS_Bv = (C4D_BaseView * const)PrivateGetOS();
C4D_Neighbor* const			 t_C4DOS_Nb = (C4D_Neighbor * const)PrivateGetOS();
C4D_Pool* const					 t_C4DOS_Pl = (C4D_Pool * const)PrivateGetOS();
C4D_BitmapFilter* const	 t_C4DOS_Fi = (C4D_BitmapFilter * const)PrivateGetOS();
C4D_Painter* const			 t_C4DOS_Pa = (C4D_Painter * const)PrivateGetOS();
C4D_Link* const					 t_C4DOS_Ln = (C4D_Link * const)PrivateGetOS();
C4D_GraphView* const		 t_C4DOS_Gv = (C4D_GraphView * const)PrivateGetOS();
C4D_GeData* const				 t_C4DOS_Gd = (C4D_GeData * const)PrivateGetOS();
C4D_Atom* const					 t_C4DOS_At = (C4D_Atom * const)PrivateGetOS();
C4D_CAnimation* const		 t_C4DOS_CA = (C4D_CAnimation * const)PrivateGetOS();
C4D_Network* const			 t_C4DOS_Ne = (C4D_Network * const)PrivateGetOS();
C4D_FieldLayer* const		 t_C4DOS_FL = (C4D_FieldLayer * const)PrivateGetOS();

Int32 InitOS(void* p)
{
	*(OperatingSystem**)&t_C4DOS = (OperatingSystem*)p;

	*(C4D_General**)&t_C4DOS_Ge = ((OperatingSystem*)p)->_Ge;
	*(C4D_Shader**)&t_C4DOS_Sh = ((OperatingSystem*)p)->_Sh;
	*(C4D_HyperFile**)&t_C4DOS_Hf = ((OperatingSystem*)p)->_Hf;
	*(C4D_BaseContainer**)&t_C4DOS_Bc = ((OperatingSystem*)p)->_Bc;
	*(C4D_String**)&t_C4DOS_St = ((OperatingSystem*)p)->_St;
	*(C4D_Bitmap**)&t_C4DOS_Bm = ((OperatingSystem*)p)->_Bm;
	*(C4D_MovieSaver**)&t_C4DOS_Ms = ((OperatingSystem*)p)->_Ms;
	*(C4D_BaseChannel**)&t_C4DOS_Ba = ((OperatingSystem*)p)->_Ba;
	*(C4D_Filename**)&t_C4DOS_Fn = ((OperatingSystem*)p)->_Fn;
	*(C4D_File**)&t_C4DOS_Fl = ((OperatingSystem*)p)->_Fl;
	*(C4D_BrowseFiles**)&t_C4DOS_Bf = ((OperatingSystem*)p)->_Bf;
	*(C4D_Dialog**)&t_C4DOS_Cd = ((OperatingSystem*)p)->_Cd;
	*(C4D_UserArea**)&t_C4DOS_Cu = ((OperatingSystem*)p)->_Cu;
	*(C4D_Parser**)&t_C4DOS_Pr = ((OperatingSystem*)p)->_Pr;
	*(C4D_Resource**)&t_C4DOS_Lr = ((OperatingSystem*)p)->_Lr;
	*(C4D_BaseList**)&t_C4DOS_Bl = ((OperatingSystem*)p)->_Bl;
	*(C4D_Tag**)&t_C4DOS_Tg = ((OperatingSystem*)p)->_Tg;
	*(C4D_Object**)&t_C4DOS_Bo = ((OperatingSystem*)p)->_Bo;
	*(C4D_Document**)&t_C4DOS_Bd = ((OperatingSystem*)p)->_Bd;
	*(C4D_Thread**)&t_C4DOS_Bt = ((OperatingSystem*)p)->_Bt;
	*(C4D_Material**)&t_C4DOS_Mt = ((OperatingSystem*)p)->_Mt;
	*(C4D_Texture**)&t_C4DOS_Tx = ((OperatingSystem*)p)->_Tx;
	*(C4D_BaseSelect**)&t_C4DOS_Bs = ((OperatingSystem*)p)->_Bs;
	*(C4D_BaseSound**)&t_C4DOS_Bu = ((OperatingSystem*)p)->_Bu;
	*(C4D_BaseDraw**)&t_C4DOS_Br = ((OperatingSystem*)p)->_Br;
	*(C4D_BaseView**)&t_C4DOS_Bv = ((OperatingSystem*)p)->_Bv;
	*(C4D_Neighbor**)&t_C4DOS_Nb = ((OperatingSystem*)p)->_Nb;
	*(C4D_Pool**)&t_C4DOS_Pl = ((OperatingSystem*)p)->_Pl;
	*(C4D_BitmapFilter**)&t_C4DOS_Fi = ((OperatingSystem*)p)->_Fi;
	*(C4D_Painter**)&t_C4DOS_Pa = ((OperatingSystem*)p)->_Pa;
	*(C4D_Link**)&t_C4DOS_Ln = ((OperatingSystem*)p)->_Ln;
	*(C4D_GraphView**)&t_C4DOS_Gv = ((OperatingSystem*)p)->_Gv;
	*(C4D_GeData**)&t_C4DOS_Gd = ((OperatingSystem*)p)->_Gd;
	*(C4D_Atom**)&t_C4DOS_At = ((OperatingSystem*)p)->_At;
	*(C4D_CAnimation**)&t_C4DOS_CA = ((OperatingSystem*)p)->_CA;
	*(C4D_Network**)&t_C4DOS_Ne = ((OperatingSystem*)p)->_Ne;
	*(C4D_FieldLayer**)&t_C4DOS_FL = ((OperatingSystem*)p)->_FL;

	CriticalAssert(t_C4DOS_Ge &&
									t_C4DOS_Sh && 
									t_C4DOS_Hf && 
									t_C4DOS_Bc && 
									t_C4DOS_St && 
									t_C4DOS_Bm && 
									t_C4DOS_Ms && 
									t_C4DOS_Ba && 
									t_C4DOS_Fn && 
									t_C4DOS_Fl && 
									t_C4DOS_Bf && 
									t_C4DOS_Cd && 
									t_C4DOS_Cu && 
									t_C4DOS_Pr && 
									t_C4DOS_Lr && 
									t_C4DOS_Bl && 
									t_C4DOS_Tg && 
									t_C4DOS_Bo && 
									t_C4DOS_Bd && 
									t_C4DOS_Bt && 
									t_C4DOS_Mt && 
									t_C4DOS_Tx && 
									t_C4DOS_Bs && 
									t_C4DOS_Bu && 
									t_C4DOS_Br && 
									t_C4DOS_Bv && 
									t_C4DOS_Nb && 
									t_C4DOS_Pl && 
									t_C4DOS_Fi && 
									t_C4DOS_Pa && 
									t_C4DOS_Ln && 
									t_C4DOS_Gv && 
									t_C4DOS_Gd && 
									t_C4DOS_At && 
									t_C4DOS_CA && 
									t_C4DOS_Ne && 
									t_C4DOS_FL);

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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
