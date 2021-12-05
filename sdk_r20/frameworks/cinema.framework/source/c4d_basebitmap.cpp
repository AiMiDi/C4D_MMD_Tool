#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "operatingsystem.h"
#include "c4d_basebitmap.h"
#include "c4d_memory.h"
#include "c4d_file.h"
#include "c4d_general.h"
#include "c4d_basecontainer.h"
#include "c4d_filterplugin.h"
#include "lib_iconcollection.h"
#include "c4d_gui.h"

#define BmCall(fnc) (this->*C4DOS.Bm->fnc)

BaseBitmapLink* BaseBitmapLink::Alloc(void)
{
	return C4DOS.Bm->BBL_Alloc();
}

void BaseBitmapLink::Free(BaseBitmapLink*& bll)
{
	C4DOS.Bm->BBL_Free(bll);
	bll = nullptr;
}

BaseBitmap* BaseBitmapLink::Get() const
{
	return C4DOS.Bm->BBL_Get((BaseBitmapLink*)this);
}

void BaseBitmapLink::Set(BaseBitmap* bmp)
{
	C4DOS.Bm->BBL_Set(this, bmp);
}

BaseBitmap* BaseBitmap::Alloc(void)
{
	return C4DOS.Bm->Alloc();
}

void BaseBitmap::Free(BaseBitmap*& bm)
{
	C4DOS.Bm->Free(bm);
	bm = nullptr;
}

void MultipassBitmap::Free(MultipassBitmap*& bm)
{
	C4DOS.Bm->Free(bm);
	bm = nullptr;
}

COLORMODE BaseBitmap::GetColorMode(void) const
{
	return (COLORMODE)C4DOS.Bm->MPB_GetParameter((const MultipassBitmap*)this, MPBTYPE::COLORMODE).GetInt32();
}

BaseBitmap* BaseBitmap::GetClone(void) const
{
	return C4DOS.Bm->GetClone(this);
}

Bool BaseBitmap::CopyTo(BaseBitmap* dst) const
{
	return C4DOS.Bm->CopyTo(this, dst);
}

Bool BaseBitmap::CopyPartTo(BaseBitmap* dst, Int32 x, Int32 y, Int32 w, Int32 h) const
{
	return C4DOS.Bm->CopyPartTo(this, dst, x, y, w, h);
}

BaseBitmap* BaseBitmap::GetClonePart(Int32 x, Int32 y, Int32 w, Int32 h) const
{
	return C4DOS.Bm->GetClonePart(this, x, y, w, h);
}

void BaseBitmap::FlushAll(void)
{
	C4DOS.Bm->FlushAll(this);
}

IMAGERESULT BaseBitmap::Init(Int32 x, Int32 y, Int32 depth, INITBITMAPFLAGS flags)
{
	return C4DOS.Bm->Init1(this, x, y, depth, flags);
}

IMAGERESULT BaseBitmap::Init(const Filename& name, Int32 frame, Bool* ismovie)
{
	return C4DOS.Bm->Init2(this, &name, frame, ismovie);
}

IMAGERESULT BaseBitmap::Init(BaseBitmap*& res, const Filename& name, Int32 frame, Bool* ismovie, BitmapLoaderPlugin** loaderplugin, const maxon::Delegate<void(Float progress)>& progressCallback)
{
	return C4DOS.Bm->Init4(res, name, frame, ismovie, loaderplugin, progressCallback);
}

IMAGERESULT BaseBitmap::Save(const Filename& name, Int32 format, BaseContainer* data, SAVEBIT savebits) const
{
	return BmCall(Save) (name, format, data, savebits);
}

Bool MultipassBitmap::SetTempColorProfile(const ColorProfile* profile, Bool dithering)
{
	return BmCall(SetTempColorProfile) (profile, dithering);
}

Int32 MultipassBitmap::GetUserID(void) const
{
	return BmCall(GetUserID) ();
}

void MultipassBitmap::SetUserID(Int32 id)
{
	BmCall(SetUserID) (id);
}

void MultipassBitmap::SetUserSubID(Int32 subid)
{
	BmCall(SetUserSubID) (subid);
}

void MultipassBitmap::SetSave(Bool save)
{
	BmCall(SetSave) (save);
}

void MultipassBitmap::SetBlendMode(Int32 mode)
{
	BmCall(SetBlendMode) (mode);
}

void MultipassBitmap::SetName(const maxon::String& name)
{
	BmCall(SetName) (name);
}

void MultipassBitmap::SetColorMode(COLORMODE mode)
{
	BmCall(SetColorMode) (mode);
}

void MultipassBitmap::SetComponent(Int32 c)
{
	BmCall(SetComponent) (c);
}

void MultipassBitmap::SetDpi(Int32 dpi)
{
	BmCall(SetDpi) (dpi);
}

void BaseBitmap::SetCMAP(Int32 i, Int32 r, Int32 g, Int32 b)
{
	C4DOS.Bm->SetCMAP(this, i, r, g, b);
}

void BaseBitmap::ScaleBicubic(BaseBitmap* dest, Int32 src_xmin, Int32 src_ymin, Int32 src_xmax, Int32 src_ymax, Int32 dst_xmin, Int32 dst_ymin, Int32 dst_xmax, Int32 dst_ymax) const
{
	C4DOS.Bm->ScaleBicubic(this, dest, src_xmin, src_ymin, src_xmax, src_ymax, dst_xmin, dst_ymin, dst_xmax, dst_ymax);
}

void BaseBitmap::ScaleIt(BaseBitmap* dst, Int32 intens, Bool sample, Bool nprop) const
{
	C4DOS.Bm->ScaleIt(this, dst, intens, sample, nprop);
}

void BaseBitmap::Clear(Int32 r, Int32 g, Int32 b)
{
	C4DOS.Bm->Clear(this, 0, 0, GetBw() - 1, GetBh() - 1, r, g, b);
}

void BaseBitmap::Clear(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Int32 r, Int32 g, Int32 b)
{
	C4DOS.Bm->Clear(this, x1, y1, x2, y2, r, g, b);
}

BaseBitmap* BaseBitmap::AddChannel(Bool internal, Bool straight)
{
	return C4DOS.Bm->AddChannel(this, internal, straight);
}

void BaseBitmap::RemoveChannel(BaseBitmap* channel)
{
	C4DOS.Bm->RemoveChannel(this, channel);
}

const BaseBitmap* BaseBitmap::GetInternalChannel(void) const
{
	return C4DOS.Bm->GetInternalChannel(((BaseBitmap*)this));
}

BaseBitmap* BaseBitmap::GetInternalChannel(void)
{
	return C4DOS.Bm->GetInternalChannel(this);
}

Int32 BaseBitmap::GetChannelCount(void) const
{
	return C4DOS.Bm->GetChannelCount(this);
}

BaseBitmap* BaseBitmap::GetChannelNum(Int32 num)
{
	return C4DOS.Bm->GetChannelNum(this, num);
}

const BaseBitmap* BaseBitmap::GetChannelNum(Int32 num) const
{
	return C4DOS.Bm->GetChannelNum(((BaseBitmap*)this), num);
}

Bool BaseBitmap::SetData(Int32 id, const GeData& data)
{
	return C4DOS.Bm->SetBaseBitmapData(this, id, data);
}

GeData BaseBitmap::GetData(Int32 id, const GeData& t_default) const
{
	return C4DOS.Bm->GetBaseBitmapData(this, id, t_default);
}

Bool BaseBitmap::IsMultipassBitmap(void) const
{
	return C4DOS.Bm->IsMultipassBitmap(this);
}

MovieLoader* MovieLoader::Alloc(void)
{
	return NewObjClear(MovieLoader);
}

void MovieLoader::Free(MovieLoader*& ml)
{
	DeleteObj(ml);
}

MovieLoader::MovieLoader(void)
{
	InitData();
}

MovieLoader::~MovieLoader(void)
{
	FreeData();
}

void MovieLoader::InitData(void)
{
	plugin = nullptr;
	bm = nullptr;
	is_movie	= false;
	frame_cnt = 0;
	fps = 0.0;
	frame_idx = -2;
	result = IMAGERESULT::OK;
}

void MovieLoader::FreeData(void)
{
	if (plugin)
	{
		plugin->BmLoadAnimated(&plugin_data, BITMAPLOADERACTION::FREE, nullptr, 0);
		plugin = nullptr;
	}

	if (bm)
		BaseBitmap::Free(bm);
}

IMAGERESULT MovieLoader::Open(const Filename& fn)
{
#ifdef MAXON_TARGET_DEBUG
	if (plugin)
		CriticalStop();		// call Close() before reusing a MovieLoader
	if (bm)
		CriticalStop();
	FreeData();	// release a previously used bitmap/plugin
	InitData();	// back to start
#endif

	result = BaseBitmap::Init(bm, fn, frame_idx, &is_movie, &plugin);
	if ((result != IMAGERESULT::OK) || (plugin == nullptr))
	{
		if ((plugin == nullptr) && (result == IMAGERESULT::OK))	// this shouldn't happen
			result = IMAGERESULT::WRONGTYPE;

		plugin = nullptr;
		BaseBitmap::Free(bm);
		return result;
	}

	if (is_movie)
	{
		if (GeGetMovieInfo(fn, &frame_cnt, &fps) == false)
		{
			frame_cnt = 0;
			fps = 0.0;
			CriticalStop();	// don't return an error here - examine the problem
		}

		plugin_data.moviename = fn;
		result = plugin->BmLoadAnimated(&plugin_data, BITMAPLOADERACTION::INIT, nullptr, 0);
		if (result != IMAGERESULT::OK)
		{
			FreeData();
			return result;
		}
		frame_idx = -2;	// nothing loaded yet
	}

	return result;
}

void MovieLoader::Close(void)
{
	FreeData();
	InitData();	// back to start
}

//----------------------------------------------------------------------------------------
// Read a frame and return the bitmap pointer
// Function result:		BaseBitmap (MovieLoader is the owner) or nullptr (check _result)
// new_frame_idx:			frame index
// _result:						used to return the result code (IMAGERESULT::OK or error code), can be nullptr
//----------------------------------------------------------------------------------------
BaseBitmap* MovieLoader::Read(Int32 new_frame_idx, Int32* _result)
{
	if (is_movie == false)
		return bm;										// always return the image initally loaded at the init call

	if (new_frame_idx == frame_idx)	// frame already loaded?
		return bm;

	result = plugin->BmLoadAnimated(&plugin_data, BITMAPLOADERACTION::LOAD, bm, new_frame_idx);	// read the requested frame
	if (result == IMAGERESULT::OK)
	{
		frame_idx = new_frame_idx;
		if (_result)
			*_result = (Int32)IMAGERESULT::OK;
		return bm;
	}

	frame_idx = -2;	// loading a new frame failed, content of bm is unknown
	if (_result)
		*_result = (Int32)result;
	return nullptr;
}

//----------------------------------------------------------------------------------------
// Get movie/bitmap info
// Function result:		number of frames (0: Open failed)
// _fps:							used to return frame rate
//----------------------------------------------------------------------------------------
Int32 MovieLoader::GetInfo(Float* _fps)
{
	if (_fps)
		*_fps = fps;

	if (is_movie)
		return frame_cnt;

	if (result == IMAGERESULT::OK)
		return 1;

	return 0;	// Open failed
}

MovieSaver* MovieSaver::Alloc(void)
{
	return C4DOS.Ms->Alloc();
}

void MovieSaver::Free(MovieSaver*& ms)
{
	C4DOS.Ms->Free(ms);
	ms = nullptr;
}

IMAGERESULT MovieSaver::Open(const Filename& name, BaseBitmap* bm, Int32 fps, Int32 id, BaseContainer* data, SAVEBIT savebits, BaseSound* sound)
{
	return C4DOS.Ms->Open(this, &name, bm, fps, id, data, savebits, sound);
}

IMAGERESULT MovieSaver::Write(BaseBitmap* bm)
{
	return C4DOS.Ms->Write(this, bm);
}

void MovieSaver::Close(void)
{
	C4DOS.Ms->Close(this);
}

Bool MovieSaver::Choose(Int32 id, BaseContainer* bc)
{
	return C4DOS.Ms->Choose(this, id, bc);
}

#define CallBmLoader(fnc) (((BitmapLoaderData*)(((BITMAPLOADERPLUGIN*)GetPluginStructure())->adr))->*((BITMAPLOADERPLUGIN*)GetPluginStructure())->fnc)
#define CallBmSaver(fnc)	(((BitmapSaverData*)(((BITMAPSAVERPLUGIN*)GetPluginStructure())->adr))->*((BITMAPSAVERPLUGIN*)GetPluginStructure())->fnc)

Bool BitmapLoaderPlugin::BmIdentify(const Filename& name, UChar* probe, Int32 size)
{
	return CallBmLoader(Identify) (name, probe, size);
}

IMAGERESULT BitmapLoaderPlugin::BmLoad(const Filename& name, BaseBitmap* bm, Int32 frame)
{
	return CallBmLoader(Load) (name, bm, frame);
}

Int32 BitmapLoaderPlugin::BmGetSaver(void)
{
	if (!((BITMAPLOADERPLUGIN*)GetPluginStructure())->GetSaver)
		return 0;
	return CallBmLoader(GetSaver) ();
}

Bool BitmapLoaderPlugin::BmGetInformation(const Filename& name, Int32* frames, Float* fps)
{
	if (!((BITMAPLOADERPLUGIN*)GetPluginStructure())->GetInformation)
		return false;
	return CallBmLoader(GetInformation) (name, frames, fps);
}

IMAGERESULT BitmapLoaderPlugin::BmLoadAnimated(BitmapLoaderAnimatedData* bd, BITMAPLOADERACTION action, BaseBitmap* bm, Int32 frame)
{
	if (!((BITMAPLOADERPLUGIN*)GetPluginStructure())->LoadAnimated)
		return IMAGERESULT::NOTEXISTING;
	return CallBmLoader(LoadAnimated) (bd, action, bm, frame);
}

IMAGERESULT BitmapLoaderPlugin::BmExtractSound(BitmapLoaderAnimatedData* bd, BaseSound* snd)
{
	if (!((BITMAPLOADERPLUGIN*)GetPluginStructure())->ExtractSound)
		return IMAGERESULT::NOTEXISTING;
	return CallBmLoader(ExtractSound) (bd, snd);
}

IMAGERESULT BitmapLoaderPlugin::BmHasSound(BitmapLoaderAnimatedData* bd)
{
	if (!((BITMAPLOADERPLUGIN*)GetPluginStructure())->HasSound)
		return IMAGERESULT::NOTEXISTING;
	return CallBmLoader(HasSound) (bd);
}

void BitmapSaverPlugin::BmGetDetails(Int32* alpha, maxon::String* suffix)
{
	if (alpha)
	{
		BaseContainer bc;
		*alpha = CallBmSaver(GetMaxAlphas) (&bc);
	}

	if (suffix)
	{
		*suffix = String();
		String* str = ((BITMAPSAVERPLUGIN*)GetPluginStructure())->suffix;
		if (str)
			*suffix = *str;
	}
}

Int32 BitmapSaverPlugin::BmGetMaxResolution(Bool layers)
{
	if (!((BITMAPSAVERPLUGIN*)GetPluginStructure())->GetMaxResolution)
		return 32000;
	return CallBmSaver(GetMaxResolution) (layers);
}

void BitmapSaverPlugin::BmCorrectResolution(const BaseContainer* settings, Int32 videoWidth, Int32 videoHeight, Int32& videoWidthPadded, Int32& videoHeightPadded)
{
	if (!((BITMAPSAVERPLUGIN*)GetPluginStructure())->CorrectResolution)
	{
		videoWidthPadded = videoWidth;
		videoHeightPadded = videoHeight;
		return;
	}
	return CallBmSaver(CorrectResolution)(settings, videoWidth, videoHeight, videoWidthPadded, videoHeightPadded);
}

Bool BitmapSaverPlugin::BmEdit(BaseContainer* data)
{
	return CallBmSaver(Edit) (data);
}

IMAGERESULT BitmapSaverPlugin::BmSave(const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits)
{
	Int32 maxres = BmGetMaxResolution(Bool(savebits & SAVEBIT::MULTILAYER));
	if (bm->GetBw() > maxres || bm->GetBh() > maxres)
		return IMAGERESULT::PARAM_ERROR;

	return CallBmSaver(Save) (name, bm, data, savebits);
}

IMAGERESULT BitmapSaverPlugin::BmOpen(PluginMovieData*& md, const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits, Int32 fps)
{
	if (!((BITMAPSAVERPLUGIN*)GetPluginStructure())->Open)
		return IMAGERESULT::OUTOFMEMORY;
	return CallBmSaver(Open) (md, name, bm, data, savebits, fps);
}

IMAGERESULT BitmapSaverPlugin::BmWrite(PluginMovieData* md, BaseBitmap* bm)
{
	if (!((BITMAPSAVERPLUGIN*)GetPluginStructure())->Write)
		return IMAGERESULT::OUTOFMEMORY;
	return CallBmSaver(Write) (md, bm);
}

void BitmapSaverPlugin::BmClose(PluginMovieData*& md)
{
	if (!((BITMAPSAVERPLUGIN*)GetPluginStructure())->Close)
		return;
	CallBmSaver(Close) (md);
}

IconData InitResourceIcon(Int32 resource_id)
{
	IconData dat;
	if (!GetIcon(resource_id, &dat) || !dat.bmp)
		return IconData();
	return dat;
}

BaseBitmap* InitResourceBitmap(Int32 resource_id)
{
	IconData dat;
	if (!GetIcon(resource_id, &dat) || !dat.bmp)
		return nullptr;
	return dat.GetClonePart();
}

Bool MultipassBitmap::GetLayers(maxon::BaseArray<BaseBitmap*>& list, MPB_GETLAYERS flags)
{
	list.Flush();
	if (!IsMultipassBitmap())
	{
		// must never happen. if this is the case the pointer is not a multipassbmp the call must be caught outside!
		CriticalStop();
		return false;
	}
	Int32				 count = 0;
	BaseBitmap** arr = nullptr;

	if (!C4DOS.Bm->MPB_GetLayers(this, flags, arr, count))
		return false;

	Int32 i;
	for (i = 0; i < count; i++)
	{
		if (!arr[i])
			continue;
		iferr (list.Append(arr[i]))
		{
			DeleteMem(arr);
			return false;
		}
	}
	DeleteMem(arr);
	return true;
}

Bool MultipassBitmap::GetLayers(maxon::BaseArray<MultipassBitmap*>& list, MPB_GETLAYERS flags)
{
	list.Flush();
	if (!IsMultipassBitmap())
	{
		// must never happen. if this is the case the pointer is not a multipassbmp the call must be caught outside!
		CriticalStop();
		return false;
	}
	Int32				 count = 0;
	BaseBitmap** arr = nullptr;

	if (!C4DOS.Bm->MPB_GetLayers(this, flags, arr, count))
		return false;
	if (!arr)
		return false;

	Int32 i;
	for (i = 0; i < count; i++)
	{
		if (!arr[i] || !arr[i]->IsMultipassBitmap())
			continue;
		iferr (list.Append((MultipassBitmap*)arr[i]))
		{
			DeleteMem(arr);
			return false;
		}
	}
	DeleteMem(arr);
	return true;
}



// ColorProfile Stuff starts here

ColorProfile* ColorProfile::Alloc(void)
{
	return C4DOS.Bm->ProfileAlloc();
}

void ColorProfile::Free(ColorProfile*& profile)
{
	C4DOS.Bm->ProfileFree(profile);
	profile = nullptr;
}

ColorProfile& ColorProfile::operator = (const ColorProfile& src)
{
	C4DOS.Bm->ProfileCopy(&src, this);
	return *this;
}

Bool ColorProfile::operator == (const ColorProfile& src) const
{
	return C4DOS.Bm->ProfileEqual(&src, this);
}

Bool ColorProfile::operator != (const ColorProfile& src) const
{
	return !C4DOS.Bm->ProfileEqual(&src, this);
}

const ColorProfile* ColorProfile::GetDefaultSRGB()
{
	return C4DOS.Bm->ProfileSRGB();
}

const ColorProfile* ColorProfile::GetDefaultLinearRGB()
{
	return C4DOS.Bm->ProfileLinearRGB();
}

const ColorProfile* ColorProfile::GetDefaultSGray()
{
	return C4DOS.Bm->ProfileSGray();
}

const ColorProfile* ColorProfile::GetDefaultLinearGray()
{
	return C4DOS.Bm->ProfileLinearGray();
}

Bool ColorProfile::CreateDefaultWindow(GeDialog* dlg)
{
	return C4DOS.Bm->ProfileWindow(this, dlg ? dlg->Get() : nullptr);
}

Bool ColorProfile::OpenProfileFromFile(const Filename& fn)
{
	return C4DOS.Bm->ProfileFromFile(this, fn);
}

Bool ColorProfile::OpenProfileFromMemory(const void* mem, Int64 memsize)
{
	return C4DOS.Bm->ProfileFromMemory(this, mem, memsize);
}

Bool ColorProfile::WriteProfileToMemory(void*& mem, Int64& memsize) const
{
	return C4DOS.Bm->ProfileToMemory(this, mem, memsize);
}

Bool ColorProfile::WriteProfileToFile(const Filename& fn) const
{
	return C4DOS.Bm->ProfileToFile(this, fn);
}

String ColorProfile::GetInfo(COLORPROFILEINFO info) const
{
	return C4DOS.Bm->ProfileInfo(this, info);
}

Bool ColorProfile::HasProfile() const
{
	return C4DOS.Bm->ProfileHasProfile(this);
}

const void* ColorProfile::GetInternalProfile() const
{
	return C4DOS.Bm->ProfileGetInternalProfile(this);
}

Bool ColorProfile::CheckColorMode(COLORMODE colormode) const
{
	return C4DOS.Bm->ProfileCheckColorMode(this, colormode);
}

Bool ColorProfile::IsMonitorProfileMode() const
{
	return C4DOS.Bm->ProfileIsMonitorMode(this);
}

Bool ColorProfile::SetMonitorProfileMode(Bool on)
{
	return C4DOS.Bm->ProfileSetMonitorMode(this, on);
}


ColorProfileConvert* ColorProfileConvert::Alloc(void)
{
	return C4DOS.Bm->ProfileConvAlloc();
}

void ColorProfileConvert::Free(ColorProfileConvert*& convert)
{
	C4DOS.Bm->ProfileConvFree(convert);
	convert = nullptr;
}

Bool ColorProfileConvert::PrepareTransform(COLORMODE srccolormode, const ColorProfile* srcprofile, COLORMODE dstcolormode, const ColorProfile* dstprofile, Bool bgr)
{
	return C4DOS.Bm->ProfileConvTransform(this, srccolormode, srcprofile, dstcolormode, dstprofile, bgr);
}

void ColorProfileConvert::Convert(const PIX* src, PIX* dst, Int32 cnt, Int32 SkipInputComponents, Int32 SkipOutputComponents) const
{
	return C4DOS.Bm->ProfileConvConvert(this, src, dst, cnt, SkipInputComponents, SkipOutputComponents);
}


maxon::Result<maxon::DataDictionary> GetImageSettingsDictionary(const BaseContainer* data, Int32 filterId)
{
	return C4DOS.Bm->GetSettingsDictionary(data, filterId);
}

maxon::Result<void> SetImageSettingsDictionary(const maxon::DataDictionary& settings, BaseContainer* data, Int32 filterId)
{
	return C4DOS.Bm->SetSettingsDictionary(settings, data, filterId);
}



#ifndef __API_INTERN__

AutoBitmap::AutoBitmap(const maxon::String& str, Float pixelRatio)
{
	bmp = BaseBitmap::Alloc();
	if (!bmp)
		return;
	if (bmp->Init(GeGetPluginResourcePath() + str) != IMAGERESULT::OK)
	{
		BaseBitmap::Free(bmp);
		return;
	}
	bmp->SetData(BASEBITMAP_DATA_GUIPIXELRATIO, pixelRatio);
}

AutoBitmap::AutoBitmap(Int32 id)
{
	bmp = InitResourceBitmap(id);
}

AutoBitmap::~AutoBitmap()
{
	BaseBitmap::Free(bmp);
}


Bool BitmapSaverPluginSupport(BitmapSaverPlugin* bp, Int flags)
{
	return bp ? (bp->GetInfo() & flags) != 0 : false;
}

Bool BitmapSaverPluginSupport(Int32 format, Int flags)
{
	BitmapSaverPlugin* plug = (BitmapSaverPlugin*)FindPlugin(format, PLUGINTYPE::BITMAPSAVER);
	return BitmapSaverPluginSupport(plug, flags);
}

Bool BitmapSaverPluginIsMovie(BitmapSaverPlugin* bp)
{
	return BitmapSaverPluginSupport(bp, PLUGINFLAG_BITMAPSAVER_MOVIE);
}

Bool BitmapSaverPluginIsMovie(Int32 format)
{
	return BitmapSaverPluginSupport(format, PLUGINFLAG_BITMAPSAVER_MOVIE);
}

#endif

