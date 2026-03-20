/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////
#include "lib_batchrender.h"

namespace cinema
{

BatchRenderLibrary* batchrender_lib_cache = nullptr;

static BatchRenderLibrary* CheckBatchRenderLib(Int32 offset)
{
	return CheckLib<BatchRenderLibrary>(C4D_BATCHRENDER_LIBRARY_ID, offset, batchrender_lib_cache);
}

BatchRender* GetBatchRender()
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetBatchRender));
	if (!lib || !lib->GetBatchRender) return nullptr;
	return (BatchRender*)lib->GetBatchRender();
}

Bool BatchRender::Open()
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, Open));
	if (!lib || !lib->Open) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->Open))();
}

Bool BatchRender::AddFile(const Filename &File, Int32 number)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, AddFile));
	if (!lib || !lib->AddFile) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->AddFile))(File, number);
}

Bool BatchRender::DelFile(const Filename &File)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, DelFile));
	if (!lib || !lib->DelFile) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->DelFile))(File);
}

Int32 BatchRender::GetElementCount()
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetElementCount));
	if (!lib || !lib->GetElementCount) return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetElementCount))();
}

Bool BatchRender::SetNetError(Int32 n, const String& machineName, const String& errorString, Bool isWarning)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetNetError));
	if (!lib || !lib->SetNetError) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->SetNetErrorEx))(n, machineName, errorString, isWarning);
}

Bool BatchRender::SetNetError(const C4DUuid& uuid, const String& machineName, const String& errorString, Bool isWarning)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetNetError));
	if (!lib || !lib->SetNetError) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->SetNetError))(uuid, machineName, errorString, isWarning);
}

Filename BatchRender::GetElement(Int32 n)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetElement));
	if (!lib || !lib->GetElement) return Filename();
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetElement))(n);
}

void BatchRender::EnableElement(Int32 n, Bool bSet)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, EnableElement));
	if (!lib || !lib->EnableElement) return;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->EnableElement))(n, bSet);
}

Bool BatchRender::GetEnableElement(Int32 n)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetEnableElement));
	if (!lib || !lib->GetEnableElement) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetEnableElement))(n);
}

Int32 BatchRender::GetElementStatus(Int32 n)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetElementStatus));
	if (!lib || !lib->GetElementStatus) return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetElementStatus))(n);
}

Bool BatchRender::IsRendering()
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, IsRendering));
	if (!lib || !lib->IsRendering) return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->IsRendering))();
}

void BatchRender::SetRendering(Int32 set)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetRendering));
	if (!lib || !lib->SetRendering) return;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->SetRendering))(set);
}

void BatchRender::GetJsonJobs(PyList* list)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetJsonJobs));
	if (!lib || !lib->GetJsonJobs) return;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetJsonJobs))(list);
}

BaseBitmap* BatchRender::GetFrameBitmap(const C4DUuid& nodeUuid, const C4DUuid& frameUuid)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetFrameBitmap));
	if (!lib || !lib->GetFrameBitmap) return nullptr;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetFrameBitmap))(nodeUuid, frameUuid);
}

void BatchRender::SetUseNet(Int32 n, Bool on)
{
	BatchRenderLibrary *lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetUseNet));
	if (!lib || !lib->SetUseNet) return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetUseNet))(n, on);
}

Bool BatchRender::GetTextureError()
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetTextureError));
	if (!lib || !lib->GetTextureError)
		return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetTextureError))();
}

void BatchRender::SetTextureError(Bool state)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetTextureError));
	if (!lib || !lib->SetTextureError)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetTextureError))(state);
}

Bool BatchRender::GetCheckTexture()
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetCheckTexture));
	if (!lib || !lib->GetCheckTexture)
		return false;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetCheckTexture))();
}

void BatchRender::SetCheckTexture(Bool state)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetCheckTexture));
	if (!lib || !lib->SetCheckTexture)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetCheckTexture))(state);
}

Int32 BatchRender::GetRenderSettingsCount(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetRenderSettingsCount));
	if (!lib || !lib->GetRenderSettingsCount)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetRenderSettingsCount))(n);
}

void BatchRender::GetAllRenderSettingsNames(Int32 n, maxon::BaseArray<String>& names)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetAllRenderSettingsNames));
	if (!lib || !lib->GetAllRenderSettingsNames)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->GetAllRenderSettingsNames))(n, names);
}

Int32 BatchRender::GetActiveRenderSettingsIndex(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveRenderSettingsIndex));
	if (!lib || !lib->GetActiveRenderSettingsIndex)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveRenderSettingsIndex))(n);
}

String BatchRender::GetActiveRenderSettingsName(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveRenderSettingsName));
	if (!lib || !lib->GetActiveRenderSettingsName)
		return {};
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveRenderSettingsName))(n);
}

void BatchRender::SetActiveRenderSettingsIndex(Int32 n, Int32 index)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetActiveRenderSettingsIndex));
	if (!lib || !lib->SetActiveRenderSettingsIndex)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetActiveRenderSettingsIndex))(n, index);
}

Int32 BatchRender::GetTakeCount(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetTakeCount));
	if (!lib || !lib->GetTakeCount)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetTakeCount))(n);
}

void BatchRender::GetAllTakeNames(Int32 n, maxon::BaseArray<String>& names)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetAllTakeNames));
	if (!lib || !lib->GetAllTakeNames)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->GetAllTakeNames))(n, names);
}

Int32 BatchRender::GetActiveTakeIndex(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveTakeIndex));
	if (!lib || !lib->GetActiveTakeIndex)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveTakeIndex))(n);
}

String BatchRender::GetActiveTakeName(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveTakeName));
	if (!lib || !lib->GetActiveTakeName)
		return {};
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveTakeName))(n);
}

void BatchRender::SetActiveTakeIndex(Int32 n, Int32 index, Bool takeOnly)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetActiveTakeIndex));
	if (!lib || !lib->SetActiveTakeIndex)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetActiveTakeIndex))(n, index, takeOnly);
}

Int32 BatchRender::GetCameraCount(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetCameraCount));
	if (!lib || !lib->GetCameraCount)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetCameraCount))(n);
}

void BatchRender::GetAllCameraNames(Int32 n, maxon::BaseArray<String>& names)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetAllCameraNames));
	if (!lib || !lib->GetAllCameraNames)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->GetAllCameraNames))(n, names);
}

Int32 BatchRender::GetActiveCameraIndex(Int32 n)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveCameraIndex));
	if (!lib || !lib->GetActiveCameraIndex)
		return NOTOK;
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveCameraIndex))(n);
}

String BatchRender::GetActiveCameraName(Int32 n, Bool filename)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, GetActiveCameraName));
	if (!lib || !lib->GetActiveCameraName)
		return {};
	return (reinterpret_cast<iBatchRender*>(this)->*(lib->GetActiveCameraName))(n, filename);
}

void BatchRender::SetActiveCameraIndex(Int32 n, Int32 index)
{
	BatchRenderLibrary* lib = CheckBatchRenderLib(LIBOFFSET(BatchRenderLibrary, SetActiveCameraIndex));
	if (!lib || !lib->SetActiveCameraIndex)
		return;
	(reinterpret_cast<iBatchRender*>(this)->*(lib->SetActiveCameraIndex))(n, index);
}

} // namespace cinema
