#include "c4d_memory.h"
#include "c4d_general.h"
#include "c4d_filterplugin.h"
#include "c4d_resource.h"

Int32 BitmapLoaderData::GetSaver(void)
{
	return 0;
}

IMAGERESULT BitmapLoaderData::ExtractSound(BitmapLoaderAnimatedData* bd, BaseSound* snd)
{
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapLoaderData::HasSound(BitmapLoaderAnimatedData* bd)
{
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapLoaderData::LoadAnimated(BitmapLoaderAnimatedData* bd, BITMAPLOADERACTION action, BaseBitmap* bm, Int32 frame)
{
	return IMAGERESULT::OK;
}

Bool BitmapLoaderData::GetInformation(const Filename& name, Int32* frames, Float* fps)
{
	return false;
}

Bool BitmapSaverData::Edit(BaseContainer* data)
{
	return true;
}

Int32 BitmapSaverData::GetMaxAlphas(BaseContainer* data)
{
	return 0;
}

Int32 BitmapSaverData::GetMaxResolution(Bool layers)
{
	return 32000;
}

void BitmapSaverData::CorrectResolution(const BaseContainer* settings, Int32 videoWidth, Int32 videoHeight, Int32& videoWidthPadded, Int32& videoHeightPadded)
{
	videoWidthPadded = videoWidth;
	videoHeightPadded = videoHeight;
}

IMAGERESULT BitmapSaverData::Write(PluginMovieData* md, BaseBitmap* bm)
{
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapSaverData::Save(const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits)
{
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapSaverData::Open(PluginMovieData*& md, const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits, Int32 fps)
{
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapSaverData::Close(PluginMovieData*& md)
{
	md = nullptr;
	return IMAGERESULT::NOTEXISTING;
}

IMAGERESULT BitmapSaverData::AddSound(PluginMovieData* md, BaseSound* snd)
{
	return IMAGERESULT::NOTEXISTING;
}

Bool RegisterBitmapLoaderPlugin(Int32 id, const maxon::String& str, Int32 info, BitmapLoaderData* dat)
{
	if (!dat)
		return false;

	BITMAPLOADERPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.Destructor	= &BaseData::Destructor;
	np.info	= info;
	np.adr	= dat;
	np.Identify	= &BitmapLoaderData::Identify;
	np.Load	= &BitmapLoaderData::Load;
	np.GetSaver	= &BitmapLoaderData::GetSaver;
	np.GetInformation	=	&BitmapLoaderData::GetInformation;
	np.LoadAnimated = &BitmapLoaderData::LoadAnimated;
	np.ExtractSound = &BitmapLoaderData::ExtractSound;
	np.HasSound	= &BitmapLoaderData::HasSound;
	return GeRegisterPlugin(PLUGINTYPE::BITMAPLOADER, id, str, &np, sizeof(np));
}

Bool RegisterBitmapSaverPlugin(Int32 id, const maxon::String& str, Int32 info, BitmapSaverData* dat, const maxon::String& suffix)
{
	if (!dat)
		return false;

	BITMAPSAVERPLUGIN np;
	ClearMem(&np, sizeof(np));
	np.Destructor	= &BaseData::Destructor;
	np.info	= info;
	np.adr	= dat;
	np.suffix	= (String*)&suffix;
	np.Save	= &BitmapSaverData::Save;
	np.GetMaxAlphas = &BitmapSaverData::GetMaxAlphas;
	np.Edit	 = &BitmapSaverData::Edit;
	np.Open	 = &BitmapSaverData::Open;
	np.Write = &BitmapSaverData::Write;
	np.Close = &BitmapSaverData::Close;
	np.AddSound = &BitmapSaverData::AddSound;
	np.GetMaxResolution = &BitmapSaverData::GetMaxResolution;
	np.CorrectResolution = &BitmapSaverData::CorrectResolution;
	return GeRegisterPlugin(PLUGINTYPE::BITMAPSAVER, id, str, &np, sizeof(np));
}

Bool RegisterSceneLoaderPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	SCENELOADERPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillNodePlugin(&np, info, g, nullptr, 0);
	np.Identify	= &SceneLoaderData::Identify;
	np.Load	= &SceneLoaderData::Load;
	return GeRegisterPlugin(PLUGINTYPE::SCENELOADER, id, str, &np, sizeof(np));
}

Bool RegisterSceneSaverPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, const maxon::String& suffix)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	SCENESAVERPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillNodePlugin(&np, info, g, nullptr, 0);
	np.suffix	= (String*)&suffix;
	np.Save	= &SceneSaverData::Save;
	return GeRegisterPlugin(PLUGINTYPE::SCENESAVER, id, str, &np, sizeof(np));
}
