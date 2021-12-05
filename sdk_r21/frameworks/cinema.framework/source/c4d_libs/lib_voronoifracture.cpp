#include "lib_voronoifracture.h"

//---------------------------------------------------------------
/// Simple class example
//---------------------------------------------------------------

VoronoiFractureLibrary* lib_voronoifracture = nullptr;

static VoronoiFractureLibrary *CheckVoronoiFractureLib(Int32 offset)
{
	return (VoronoiFractureLibrary*)CheckLib(VORONOIFRACTURELIB, offset, (C4DLibrary**)&lib_voronoifracture);
}


#define VoronoiFractureLibCall(b) 		VoronoiFractureLibrary *lib = CheckVoronoiFractureLib(LIBOFFSET(VoronoiFractureLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((iVoronoiFracture*)this)->*lib->b)

#define VoronoiFractureLibCallR(a, b) VoronoiFractureLibrary *lib = CheckVoronoiFractureLib(LIBOFFSET(VoronoiFractureLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((iVoronoiFracture*)this)->*lib->b)

VoronoiFracture* VoronoiFracture::Alloc()
{
	VoronoiFractureLibrary *lib = CheckVoronoiFractureLib(LIBOFFSET(VoronoiFractureLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void VoronoiFracture::Free(VoronoiFracture *&p)
{
	if (!p)
		return;

	VoronoiFractureLibrary *lib = CheckVoronoiFractureLib(LIBOFFSET(VoronoiFractureLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}

Int32 VoronoiFracture::GetSourcesCount()
{
	VoronoiFractureLibCallR(NOTOK, GetSourcesCount)();
}

BaseObject* VoronoiFracture::GetSource(const Int32 index)
{
	VoronoiFractureLibCallR(nullptr, GetSource)(index);
}

BaseObject* VoronoiFracture::GetSourceByType(const Int32 type, const Int32 startIndex, Int32* const index)
{
	VoronoiFractureLibCallR(nullptr, GetSourceByType)(type, startIndex, index);
}

Bool VoronoiFracture::RemoveSource(const Int32 index)
{
	VoronoiFractureLibCallR(false, RemoveSource)(index);
}

BaseObject* VoronoiFracture::AddPointGenerator(const Int32 type, const Int32 shaderType, Int32* const index)
{
	VoronoiFractureLibCallR(nullptr, AddPointGenerator)(type, shaderType, index);
}

Bool VoronoiFracture::AddSceneObject(BaseObject* object, Int32* const index)
{
	VoronoiFractureLibCallR(false, AddSceneObject)(object, index);
}

void VoronoiFracture::ClearSources()
{
	VoronoiFractureLibCall(ClearSources)();
}

BaseContainer* VoronoiFracture::GetSourceSettingsContainerForIndex(const Int32 index)
{
	VoronoiFractureLibCallR(nullptr, GetSourceSettingsContainerForIndex)(index);
}

BaseContainer* VoronoiFracture::GetSourceSettingsContainerForObject(BaseObject* object)
{
	VoronoiFractureLibCallR(nullptr, GetSourceSettingsContainerForObject)(object);
}
