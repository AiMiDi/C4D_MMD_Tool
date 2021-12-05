/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////
#include "lib_pictureviewer.h"

PictureViewLibrary* picture_viewer_lib_cache = nullptr;

static PictureViewLibrary* CheckPictureViewLib(Int32 offset)
{
	return (PictureViewLibrary*)CheckLib(C4D_PICTUREVIEWER_LIBRARY_ID, offset, (C4DLibrary**)&picture_viewer_lib_cache);
}

PictureViewer* CreatePictureViewer(Int32 type)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, CreatePictureViewer));
	if (!lib || !lib->CreatePictureViewer) return nullptr;

	return (PictureViewer*)lib->CreatePictureViewer(type);
}

Bool PictureViewer::Open()
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, Open));
	if (!lib || !lib->Open) return false;
	return (((iPictureViewer*)this)->*(lib->Open))();
}

Bool PictureViewer::ShowFile(const Filename &File)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, ShowFile));
	if (!lib || !lib->ShowFile) return false;
	return (((iPictureViewer*)this)->*(lib->ShowFile))(File);
}

Bool PictureViewer::ShowImage(BaseBitmap *Bmp, const String &Name)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, ShowImage));
	if (!lib || !lib->ShowImage) return false;
	return (((iPictureViewer*)this)->*(lib->ShowImage))(Bmp, Name);
}

Bool PictureViewer::AddSound(GeListNode *pNode, const BaseTime &from, const BaseTime &to, BaseSound *sound)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, AddSound));
	if (!lib || !lib->AddSound) return false;
	return (((iPictureViewer*)this)->*(lib->AddSound))(pNode, from, to, sound);
}

GeListNode* PictureViewer::OpenRendering(const String &Name, Float Fps, Int32 lStart, Int32 lEnd, BaseContainer* bcrender)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, OpenRendering));
	if (!lib || !lib->OpenRendering) return nullptr;
	return (((iPictureViewer*)this)->*(lib->OpenRendering))(Name, Fps, lStart, lEnd, bcrender);
}

void PictureViewer::SetIsNet(GeListNode *pNode, Bool isNet)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, SetIsNet));
	if (!lib || !lib->SetIsNet) return;
	return (((iPictureViewer*)this)->*(lib->SetIsNet))(pNode, isNet);
}

Bool PictureViewer::Message(Int32 id, void *t_data)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, Message));
	if (!lib || !lib->Message) return false;
	return (((iPictureViewer*)this)->*(lib->Message))(id, t_data);
}


GeListNode *PictureViewer::BeginRendering(GeListNode *pNode, BaseBitmap *Bmp, const String &Name, const BaseTime &Time, Int32 Frame, const Filename &savename, Bool fully_saved, const Filename &dispname, Int32 lStream, STEREOTYPE lStereoType)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, BeginRendering));
	if (!lib || !lib->BeginRendering) return nullptr;
	return (((iPictureViewer*)this)->*(lib->BeginRendering))(pNode, Bmp, Name, Time, Frame, savename, fully_saved, dispname, lStream, lStereoType);
}

Bool PictureViewer::OverwriteBitmap(GeListNode *node, BaseBitmap* bmp, STEREOTYPE stereotype, Int32 lLastStream)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, OverwriteBitmap));
	if (!lib || !lib->OverwriteBitmap) return false;
	return (((iPictureViewer*)this)->*(lib->OverwriteBitmap))(node, bmp, stereotype, lLastStream);
}

Bool PictureViewer::EndRendering(GeListNode *beginNode, PVFRAME_FINISH finish, Bool incomplete, PVFinalizeImage *callback, void *userdata)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, EndRendering));
	if (!lib || !lib->EndRendering) return false;
	return (((iPictureViewer*)this)->*(lib->EndRendering))(beginNode, finish, incomplete, callback, userdata);
}

Bool PictureViewer::CloseRendering(GeListNode *&pNode)
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, CloseRendering));
	if (!lib || !lib->CloseRendering) return false;
	return (((iPictureViewer*)this)->*(lib->CloseRendering))(pNode);
}

Bool PictureViewer::CheckHDMemory()
{
	PictureViewLibrary *lib = CheckPictureViewLib(LIBOFFSET(PictureViewLibrary, CheckHDMemory));
	if (!lib || !lib->CheckHDMemory) return false;
	return (((iPictureViewer*)this)->*(lib->CheckHDMemory))();
}
