/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////
#include "lib_batchrender.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
