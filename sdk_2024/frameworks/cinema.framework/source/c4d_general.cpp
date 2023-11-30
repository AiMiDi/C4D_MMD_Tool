#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_general.h"
#include "maxon/byteorder.h"
#include "maxon/utilities/sprintf_safe.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

Bool HasFullFeatureSet()
{
	VERSIONTYPE t = GeGetVersionType();
	return t == VERSIONTYPE::TEAMRENDER_CLIENT || t == VERSIONTYPE::TEAMRENDER_SERVER ||
				 t == VERSIONTYPE::CINEMA4D || t == VERSIONTYPE::COMMANDLINE ||
				 t == VERSIONTYPE::CPYTHON ||
				 t == VERSIONTYPE::CINEWARE;
}

Bool CodeEditor_Open(BaseList2D* obj, const maxon::Delegate<GeData(BaseList2D* obj, const BaseContainer& msg)>& callback, const BaseContainer& bc /*= BaseContainer()*/)
{
	return C4DOS_Ge->CodeEditor_Open(obj, callback, bc);
}

Bool ParserCache::CopyTo(ParserCache* dest)
{
	return C4DOS_Pr->CopyPCache(this, dest);
}

ParserCache* ParserCache::Alloc()
{
	return C4DOS_Pr->AllocPCache();
}

void ParserCache::Free(ParserCache*& p)
{
	C4DOS_Pr->FreePCache(p);
	p = nullptr;
}

Parser* Parser::Alloc()
{
	return C4DOS_Pr->Alloc();
}

void Parser::Free(Parser*& pr)
{
	C4DOS_Pr->Free(pr);
	pr = nullptr;
}

Bool Parser::AddVar(const maxon::String& str, Float* value, Bool case_sensitive)
{
	return C4DOS_Pr->AddVar(this, str, value, case_sensitive);
}

Bool Parser::RemoveVar(const maxon::String& s, Bool case_sensitive)
{
	return C4DOS_Pr->RemoveVar(this, s, case_sensitive);
}

Bool Parser::RemoveAllVars()
{
	return C4DOS_Pr->RemoveAllVars(this);
}

void Parser::GetParserData(ParserCache* p)
{
	return C4DOS_Pr->GetParserData(this, p);
}

Bool Parser::Init(const maxon::String& s, Int32* error, Int32 unit, Int32 angle_unit, Int32 base)
{
	return C4DOS_Pr->Init(this, s, error, unit, angle_unit, base);
}

Bool Parser::Eval(const maxon::String& str, Int32* error, Float* res, Int32 unit, Int32 angletype, Int32 basis)
{
	return C4DOS_Pr->Eval(this, str, error, res, unit, angletype, basis);
}

Bool Parser::ReEval(Float* result, Int32* error)
{
	return C4DOS_Pr->ReEval(this, result, error);
}

Bool Parser::Calculate(const ParserCache* pdat, Float* result, Int32* error)
{
	return C4DOS_Pr->Calculate(this, pdat, result, error);
}

Bool Parser::AddVarLong(const maxon::String& str, Int32* value, Bool case_sensitive)
{
	return C4DOS_Pr->AddVarLong(this, str, value, case_sensitive);
}

Bool Parser::EvalLong(const maxon::String& str, Int32* error, Int32* res, Int32 unit, Int32 basis)
{
	return C4DOS_Pr->EvalLong(this, str, error, res, unit, basis);
}

Bool Parser::ReEvalLong(Int32* result, Int32* error)
{
	return C4DOS_Pr->ReEvalLong(this, result, error);
}

Bool Parser::CalculateLong(const ParserCache* pdat, Int32* result, Int32* error)
{
	return C4DOS_Pr->CalculateLong(this, pdat, result, error);
}

Bool Parser::Reset(ParserCache* p)
{
	return C4DOS_Pr->Reset(this, p);
}

Bool Parser::GenerateShaderCode(const maxon::String& resultVariableName, maxon::String* result)
{
	return C4DOS_Pr->GenerateShaderCode(this, resultVariableName, *result);
}

Bool Parser::GenerateShaderCodeFromCache(const ParserCache* pdat, const maxon::String& resultVariableName, maxon::String* result)
{
	return C4DOS_Pr->GenerateShaderCodeFromCache(this, pdat, resultVariableName, *result);
}

void GeAddBackgroundHandler(BackgroundHandler* handler, void* tdata, Int32 typeclass, Int32 priority)
{
	C4DOS_Ge->AddBackgroundHandler(handler, tdata, typeclass, priority);
}

Bool GeRemoveBackgroundHandler(void* tdata, Int32 typeclass)
{
	return C4DOS_Ge->RemoveBackgroundHandler(tdata, typeclass);
}

Bool GeStopBackgroundThreads(Int32 typeclass, BACKGROUNDHANDLERFLAGS flags, BaseThread* thread)
{
	return C4DOS_Ge->StopBackgroundThreads(typeclass, flags, thread);
}

Bool GeCheckBackgroundThreadsRunning(Int32 typeclass, Bool all)
{
	return C4DOS_Ge->CheckBackgroundThreadsRunning(typeclass, all);
}

void GeShowMouse(Int32 v)
{
	C4DOS_Ge->ShowMouse(v);
}

Bool GeGetScreenDimensions(Int32 x, Int32 y, Bool whole_screen, Int32* sx1, Int32* sy1, Int32* sx2, Int32* sy2)
{
	return C4DOS_Ge->GetScreenDimensions(x, y, whole_screen, sx1, sy1, sx2, sy2);
}

String GeGetLineEnd()
{
	String str;
	C4DOS_Ge->GetLineEnd(&str);
	return str;
}

Int32 GeGetDefaultFPS()
{
	return C4DOS_Ge->GetDefaultFPS();
}

GEMB_R GeOutString(const maxon::String& str, GEMB flags)
{
	return C4DOS_Ge->OutString(str, flags);
}

OPERATINGSYSTEM GeGetCurrentOS()
{
	return C4DOS_Ge->GetCurrentOS();
}

BYTEORDER GeGetByteOrder()
{
	return C4DOS_Ge->GetByteOrder();
}

void GeGetGray(Int32* r, Int32* g, Int32* b)
{
	C4DOS_Ge->GetGray(r, g, b);
}

Bool GeChooseColor(Vector* col, Int32 flags)
{
	return C4DOS_Ge->ChooseColor(col, flags);
}

Bool GeChooseColorAlpha(maxon::ColorA* col, Int32 flags)
{
	return C4DOS_Ge->ChooseColorAlpha(col, flags);
}

Bool GeOpenHTML(const maxon::String& webaddress)
{
	return C4DOS_Ge->OpenHTML(webaddress);
}

Bool GeChooseFont(BaseContainer* bc)
{
	return C4DOS_Ge->ChooseFont(bc);
}

void GeGetGuiFont(maxon::OSFontDefinition& out)
{
	C4DOS_Ge->GeGetGuiFont(out);
}

void GeGetMonoFont(maxon::OSFontDefinition& out)
{
	C4DOS_Ge->GeGetMonoFont(out);
}

maxon::String GeGetUserName()
{
	return C4DOS_Ge->GetUserNameI();
}

VERSIONTYPE GeGetVersionType()
{
	return C4DOS_Ge->GetVersionType();
}

maxon::Result<void> GetGeneralLicensingInformation(maxon::String& productId, maxon::String& systemId, maxon::String& userId, maxon::String& licenseId, maxon::String& userName)
{
	return C4DOS_Ge->GetGeneralLicensingInformation(productId, systemId, userId, licenseId, userName);
}

maxon::Result<maxon::String> ExportLicenses()
{
	return C4DOS_Ge->ExportLicenses();
}

maxon::Result<void> AddLicenseItem(const maxon::InternedId& licenseItemId, Float versionNumber, Bool checkOnly, maxon::CustomLicenseItemDelegate&& licenseUpdateCallback)
{
	return C4DOS_Ge->AddLicenseItem(licenseItemId, versionNumber, checkOnly, std::move(licenseUpdateCallback));
}

maxon::Bool CheckLicenseFeature(const maxon::InternedId& featureId)
{
	return C4DOS_Ge->CheckLicenseFeature(featureId);
}

Bool GeRegisterPlugin(PLUGINTYPE type, Int32 id, const maxon::String& str, void* data, Int32 datasize)
{
	return C4DOS_Ge->RegisterPlugin(API_VERSION, type, id, str, data, datasize);
}

void GePrint(const maxon::String& str)
{
	C4DOS_Ge->Print(str);
}

void GeConsoleOut(const maxon::String& str)
{
	maxon::String s = "\x01"_s + str;
	C4DOS_Ge->Print(s);
}

void SetMousePointer(Int32 l)
{
	C4DOS_Ge->SetMousePointer(l);
}

Bool ShowBitmap(const Filename& fn)
{
	return C4DOS_Ge->ShowBitmap1(&fn);
}

Bool ShowBitmap(BaseBitmap* bm)
{
	return C4DOS_Ge->ShowBitmap2(bm);
}

void StopAllThreads()
{
	C4DOS_Ge->StopAllThreads(true, true, true);
}

void StopDrawViewsThread()
{
	C4DOS_Ge->StopAllThreads(true, false, false);
}

Bool ShutdownThreads(Bool shutdown)
{
	return C4DOS_Ge->ShutdownThreads(shutdown);
}

void StatusClear()
{
	C4DOS_Ge->StatusClear();
}

void StatusSetSpin()
{
	C4DOS_Ge->StatusSetSpin();
}

void StatusSetBar(Int32 p)
{
	C4DOS_Ge->StatusSetBar(p);
}

void StatusSetText(const maxon::String& str)
{
	C4DOS_Ge->StatusSetText(str);
}

void StatusNetClear()
{
	C4DOS_Ge->StatusNetClear();
}

void StatusSetNetLoad(STATUSNETSTATE status)
{
	C4DOS_Ge->StatusSetNetLoad(status);
}

void StatusSetNetBar(Int32 p, const GeData& dat)
{
	C4DOS_Ge->StatusSetNetBar(p, dat);
}

void StatusSetNetText(const maxon::String& str)
{
	C4DOS_Ge->StatusSetNetText(str);
}

void SpecialEventAdd(Int32 messageid, UInt p1, UInt p2)
{
	C4DOS_Ge->SpecialEventAdd(messageid, p1, p2);
}

void EventAdd(EVENT flags)
{
	C4DOS_Ge->EventAdd(flags);
}

Bool GeSyncMessage(Int32 messageid, Int32 destid, UInt p1, UInt p2)
{
	return C4DOS_Ge->SyncMessage(messageid, destid, p1, p2);
}

Bool DrawViews(DRAWFLAGS flags, BaseDraw* bd)
{
	return C4DOS_Ge->DrawViews(flags, bd);
}

Bool SendModelingCommand(Int32 command, ModelingCommandData& data)
{
	return C4DOS_Ge->SendModelingCommand(command, data);
}

maxon::Result<TexturePathList> GetGlobalTexturePaths(const Filename* docPath)
{
	return C4DOS_Ge->GetGlobalTexturePaths(docPath);
}

maxon::Result<void> SetGlobalTexturePaths(const TexturePathList& paths)
{
	return C4DOS_Ge->SetGlobalTexturePaths(paths);
}

Bool IsInSearchPath(const Filename& texfilename, const Filename& docpath)
{
	return C4DOS_Ge->IsInSearchPath(texfilename, docpath);
}

Bool GenerateTexturePath(const Filename& docpath, const Filename& srcname, const Filename& suggestedfolder, Filename* dstname, NetRenderService* service, BaseThread* bt)
{
	return C4DOS_Ge->GenerateTexturePath(docpath, srcname, suggestedfolder, dstname, service, bt);
}

void FlushTexture(const Filename& docpath, const maxon::String& name, const Filename& suggestedfolder)
{
	C4DOS_Ge->FlushTexture(&docpath, name, suggestedfolder);
}

void FlushUnusedTextures()
{
	C4DOS_Ge->FlushUnusedTextures();
}

BaseContainer* GetToolPluginData(BaseDocument* doc, Int32 id)
{
	return C4DOS_Ge->GetToolPluginData(doc, id);
}

BaseContainer* GetWorldPluginData(Int32 id)
{
	return C4DOS_Ge->GetWorldPluginData(id);
}

Bool SetWorldPluginData(Int32 id, const BaseContainer& bc, Bool add)
{
	return C4DOS_Ge->SetWorldPluginData(id, &bc, add);
}

void SaveWorldPreferences()
{
	C4DOS_Ge->SaveWorldPreferences();
}

BaseContainer GetWorldContainer()
{
	BaseContainer bc;
	C4DOS_Ge->GetWorldContainer(&bc);
	return bc;
}

BaseContainer* GetWorldContainerInstance()
{
	return C4DOS_Ge->GetWorldContainerInstance();
}

void GetAdditionalWorldContainerData(BaseContainer& bc)
{
	C4DOS_Ge->GetAdditionalWorldContainerData(bc);
}

void SetWorldContainer(const BaseContainer& bc)
{
	C4DOS_Ge->SetWorldContainer(&bc);
}

maxon::Result<maxon::BaseArray<maxon::Url>> GetRecentDocumentsList(Bool isBodyPaint)
{
	return C4DOS_Ge->GetRecentDocumentsList(isBodyPaint);
}

maxon::Id GetActiveNodeSpaceId()
{
	return C4DOS_Ge->GetActiveNodeSpaceId();
}

Vector GetViewColor(Int32 colid, Vector* defaultColor)
{
	return C4DOS_Ge->GetColor(colid, defaultColor);
}

void SetViewColor(Int32 colid, const Vector& col)
{
	C4DOS_Ge->SetViewColor(colid, col);
}

void ErrorStringDialog(CHECKVALUERANGE type, Float x, Float y, CHECKVALUEFORMAT is)
{
	C4DOS_Ge->ErrorStringDialog(type, x, y, is);
}

Bool ReadPluginInfo(Int32 pluginid, void* buffer, Int32 size)
{
	return C4DOS_Ge->ReadPluginInfo(pluginid, (Char*)buffer, size);
}

Bool WritePluginInfo(Int32 pluginid, void* buffer, Int32 size)
{
	return C4DOS_Ge->WritePluginInfo(pluginid, (Char*)buffer, size);
}

Bool ReadRegInfo(Int32 pluginid, void* buffer, Int32 size)
{
	return C4DOS_Ge->ReadPluginReg(pluginid, (Char*)buffer, size);
}

Bool WriteRegInfo(Int32 pluginid, void* buffer, Int32 size)
{
	return C4DOS_Ge->WritePluginReg(pluginid, (Char*)buffer, size);
}

Bool GeGetMovieInfo(const Filename& fn, Int32* frames, Float* fps)
{
	return C4DOS_Ge->GetMovieInfo(&fn, frames, fps);
}

Bool GeRegistryAdd(Int32 sub_id, REGISTRYTYPE main_id, void* data)
{
	return C4DOS_Ge->RegistryAdd(sub_id, main_id, data);
}

Bool GeRegistryRemove(Int32 sub_id, REGISTRYTYPE main_id)
{
	return C4DOS_Ge->RegistryRemove(sub_id, main_id);
}

Registry* GeRegistryFind(Int32 sub_id, REGISTRYTYPE main_id)
{
	// C4DOS_Ge could be nullptr if futurama part is loaded and not classic c4d
	if (C4DOS_Ge == nullptr)
		return nullptr;
	return C4DOS_Ge->RegistryFind(sub_id, main_id);
}

Registry* GeRegistryGetLast(REGISTRYTYPE main_id)
{
	return C4DOS_Ge->RegistryGetLast(main_id);
}

Registry* GeRegistryGetFirst(REGISTRYTYPE main_id)
{
	return C4DOS_Ge->RegistryGetFirst(main_id);
}

Bool GeRegistryGetAutoID(Int32* id)
{
	return C4DOS_Ge->RegistryGetAutoID(id);
}

REGISTRYTYPE Registry::GetMainID()
{
	REGISTRYTYPE main_id;
	Int32				 sub_id;
	void*				 data;
	if (!C4DOS_Ge->RegistryGetData(this, &main_id, &sub_id, &data))
		return REGISTRYTYPE::ANY;
	return main_id;
}

Int32 Registry::GetSubID()
{
	REGISTRYTYPE main_id;
	Int32				 sub_id;
	void*				 data;
	if (!C4DOS_Ge->RegistryGetData(this, &main_id, &sub_id, &data))
		return 0;
	return sub_id;
}

void* Registry::GetData()
{
	REGISTRYTYPE main_id;
	Int32				 sub_id;
	void*				 data;
	if (!C4DOS_Ge->RegistryGetData(this, &main_id, &sub_id, &data))
		return nullptr;
	return data;
}

Bool RenameDialog(String* str)
{
	return C4DOS_Ge->RenameDialog(str);
}

Bool LassoSelection::Start(GeDialog& dlg, Int32 mode, Int32 start_x, Int32 start_y, Int32 start_button, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2)
{
	return C4DOS_Cd->LSStart(this, (CBaseFrame*)dlg.Get(), mode, start_x, start_y, start_button, sx1, sy1, sx2, sy2);
}

Bool LassoSelection::Start(GeUserArea& ua, Int32 mode, Int32 start_x, Int32 start_y, Int32 start_button, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2)
{
	return C4DOS_Cd->LSStart(this, (CBaseFrame*)ua.Get(), mode, start_x, start_y, start_button, sx1, sy1, sx2, sy2);
}

Bool LassoSelection::Start(EditorWindow* win, Int32 mode, Int32 start_x, Int32 start_y, Int32 start_button, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2)
{
	return C4DOS_Cd->LSStart(this, (CBaseFrame*)win, mode, start_x, start_y, start_button, sx1, sy1, sx2, sy2);
}

Bool LassoSelection::GetRectangle(Float& x1, Float& y1, Float& x2, Float& y2)
{
	return C4DOS_Cd->LSGetRectangle(this, x1, y1, x2, y2);
}

Bool LassoSelection::CheckSingleClick()
{
	return C4DOS_Cd->LSCheckSingleClick(this);
}

Bool LassoSelection::Test(Int32 x, Int32 y)
{
	return C4DOS_Cd->LSTest(this, x, y);
}

Bool LassoSelection::TestPolygon(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd)
{
	return C4DOS_Cd->LSTestPolygon(this, pa, pb, pc, pd);
}

Int32 LassoSelection::GetMode()
{
	return C4DOS_Cd->LSGetMode(this);
}

LassoSelection* LassoSelection::Alloc()
{
	return C4DOS_Cd->LSAlloc();
}

void LassoSelection::Free(LassoSelection*& ls)
{
	C4DOS_Cd->LSFree(ls);
	ls = nullptr;
}

void FindInManager(BaseList2D* bl)
{
	C4DOS_Ge->FindInManager(bl);
}

void GeSleep(Int32 milliseconds)
{
	C4DOS_Ge->GeSleep(milliseconds);
}

Bool GeIsMainThread()
{
	return C4DOS_Ge->IsMainThread();
}

Bool GeIsMainThreadAndNoDrawThread()
{
	return C4DOS_Ge->IsMainThreadAndNoDrawThread();
}

Bool GeIsActiveToolEnabled()
{
	return C4DOS_Ge->IsActiveToolEnabled();
}

ToolPlugin* GetActiveTool()
{
	return C4DOS_Ge->GetActiveTool();
}

GeListHead* GetScriptHead(Int32 type)
{
	return C4DOS_Ge->GetScriptHead(type);
}

Bool GetCommandLineArgs(C4DPL_CommandLineArgs& args)
{
	return C4DOS_Ge->GetCommandLineArgs(args);
}

Int32 GetDynamicScriptID(BaseList2D* bl)
{
	return C4DOS_Ge->GetDynamicScriptID(bl);
}

void SetActiveScriptObject(Int32 type)
{
	C4DOS_Ge->SetActiveScriptObject(type);
}

BaseList2D* CreateNewPythonScript(String& name, const String& body)
{
	return C4DOS_Ge->CreateNewPythonScript(name, body);
}

BaseList2D* LoadPythonScript(const Filename& fn)
{
	return C4DOS_Ge->LoadPythonScript(fn);
}

Bool GeGetLanguage(Int32 index, maxon::String* extension, maxon::String* name, Bool* default_language)
{
	return C4DOS_Ge->GetLanguage(index, extension, name, default_language);
}

Filename GeFilterSetSuffix(const Filename& name, Int32 id)
{
	return C4DOS_Ge->FilterSetSuffix(name, id);
}

IDENTIFYFILE GeIdentifyFile(const Filename& name, UChar* probe, Int32 probesize, IDENTIFYFILE recognition, BasePlugin** bp)
{
	return C4DOS_Ge->IdentifyFile(name, probe, probesize, recognition, bp);
}

GeData SendCoreMessage(Int32 coreid, const BaseContainer& msg, Int32 eventid)
{
	return C4DOS_Ge->SendCoreMessage(coreid, msg, eventid);
}

String GetMacModel(const maxon::String& machinemodel)
{
	return C4DOS_Ge->GetMacModel(machinemodel);
}

BaseContainer GetMachineFeatures(MACHINEFEATURESTYPE type)
{
	GeData dat = SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_GETMACHINEFEATURES), (Int32)type);
	if (!dat.GetContainer())
		return BaseContainer();
	return *dat.GetContainer();
}

Bool GePluginMessage(Int32 id, void* data)
{
	return C4DOS_Ge->PluginMessage(id, data);
}

Bool CheckIsRunning(CHECKISRUNNING type)
{
	return C4DOS_Ge->CheckIsRunning(type);
}

String GeGetDefaultFilename(Int32 id)
{
	return C4DOS_Ge->GetDefaultFilename(id).GetString();
}

String GetObjectName(Int32 type)
{
	return C4DOS_Ge->GetObjectName(type);
}

String GetTagName(Int32 type)
{
	return C4DOS_Ge->GetTagName(type);
}

Int32 GetObjectType(const maxon::String& name)
{
	return C4DOS_Ge->GetObjectType(name);
}

Int32 GetTagType(const maxon::String& name)
{
	return C4DOS_Ge->GetTagType(name);
}

Bool GeGetMemoryStat(BaseContainer& stat)
{
	return C4DOS_Ge->GeGetMemoryStat(stat);
}


Bool PopupEditText(Int32 screenx, Int32 screeny, Int32 width, Int32 height, const maxon::String& changeme, maxon::Delegate<void(POPUPEDITTEXTCALLBACK, maxon::String&)> func)
{
	return C4DOS_Ge->PopupEditText(screenx, screeny, width, height, changeme, std::move(func));
}

void StartEditorRender(Bool active_only, Bool raybrush, Int32 x1, Int32 y1, Int32 x2, Int32 y2, BaseThread* bt, BaseDraw* bd, Bool newthread)
{
	C4DOS_Ge->StartEditorRender(active_only, raybrush, x1, y1, x2, y2, bt, bd, newthread);
}

String FormatNumber(const GeData& val, Int32 format, Int32 fps, Bool bUnit)
{
	return C4DOS_Ge->FormatNumber(val, format, fps, bUnit, nullptr);
}

GeData StringToNumber(const maxon::String& text, Int32 format, Int32 fps, const LENGTHUNIT* lengthunit)
{
	return C4DOS_Ge->StringToNumber(text, format, fps, lengthunit);
}

void GeDebugOut(const Char* s, ...)
{
#ifdef MAXON_TARGET_DEBUG
	va_list arp;
	va_start(arp, s);

	Char t[2048];

	vsprintf_safe(t, sizeof(t), s, arp);
	C4DOS_Ge->GeDebugOut("%s", t);

	va_end(arp);
#endif
}

String GeGetDegreeChar()
{
	return C4DOS_Ge->GeGetDegreeChar();
}

String GeGetPercentChar()
{
	return C4DOS_Ge->GeGetPercentChar();
}

void CallCommand(Int32 id, Int32 subid)
{
	if (!GeIsMainThreadAndNoDrawThread())
		return;
	BaseContainer msg(COREMSG_CINEMA_EXECUTEEDITORCOMMAND);
	msg.SetInt32(COREMSG_CINEMA_EXECUTEEDITORCOMMAND, id);
	msg.SetInt32(COREMSG_CINEMA_EXECUTESUBID, subid);
	SendCoreMessage(COREMSG_CINEMA, msg, 0);
}

String GetCommandName(Int32 id)
{
	if (!GeIsMainThreadAndNoDrawThread())
		return String();
	BaseContainer msg(COREMSG_CINEMA_GETCOMMANDNAME);
	msg.SetInt32(COREMSG_CINEMA_GETCOMMANDNAME, id);
	return SendCoreMessage(COREMSG_CINEMA, msg, 0).GetString();
}

String GetCommandHelp(Int32 id)
{
	if (!GeIsMainThreadAndNoDrawThread())
		return String();
	BaseContainer msg(COREMSG_CINEMA_GETCOMMANDHELP);
	msg.SetInt32(COREMSG_CINEMA_GETCOMMANDHELP, id);
	return SendCoreMessage(COREMSG_CINEMA, msg, 0).GetString();
}

Bool IsCommandEnabled(Int32 id)
{
	if (!GeIsMainThreadAndNoDrawThread())
		return false;
	BaseContainer msg(COREMSG_CINEMA_GETCOMMANDENABLED);
	msg.SetInt32(COREMSG_CINEMA_GETCOMMANDENABLED, id);
	return SendCoreMessage(COREMSG_CINEMA, msg, 0).GetInt32() != 0;
}

Bool IsCommandChecked(Int32 id)
{
	if (!GeIsMainThreadAndNoDrawThread())
		return false;
	BaseContainer msg(COREMSG_CINEMA_GETCOMMANDCHECKED);
	msg.SetInt32(COREMSG_CINEMA_GETCOMMANDCHECKED, id);
	return SendCoreMessage(COREMSG_CINEMA, msg, 0).GetInt32() != 0;
}

Bool GetSystemEnvironmentVariable(const maxon::String& varname, maxon::String& result)
{
	return C4DOS_Ge->GetSystemEnvironmentVariable(varname, result);
}

Int32 GetShortcutCount()
{
	return C4DOS_Ge->GetShortcutCount();
}

BaseContainer GetShortcut(Int32 index)
{
	return C4DOS_Ge->GetShortcut(index);
}

Bool AddShortcut(const BaseContainer& bc)
{
	return C4DOS_Ge->AddShortcut(bc);
}

Bool RemoveShortcut(Int32 index)
{
	return C4DOS_Ge->RemoveShortcut(index);
}

Bool LoadShortcutSet(const Filename& fn, Bool add)
{
	return C4DOS_Ge->LoadShortcutSet(fn, add);
}

Bool SaveShortcutSet(const Filename& fn)
{
	return C4DOS_Ge->SaveShortcutSet(fn);
}

Int32 FindShortcutsFromID(Int32 pluginid, Int32* indexarray, Int32 maxarrayelements)
{
	return C4DOS_Ge->FindShortcutsFromID(pluginid, indexarray, maxarrayelements);
}

Int32 FindShortcuts(const BaseContainer& scut, Int32* idarray, Int32 maxarrayelements)
{
	return C4DOS_Ge->FindShortcuts(scut, idarray, maxarrayelements);
}

Bool CheckCommandShortcut(Int32 id, Int32 key, Int32 qual)
{
	return C4DOS_Ge->CheckCommandShortcut(id, key, qual);
}

void InsertCreateObject(BaseDocument* doc, BaseObject* op, BaseObject* activeobj)
{
	C4DOS_Ge->InsertCreateObject(doc, op, activeobj);
}

UInt32 GeGetCinemaInfo(CINEMAINFO info)
{
	return (*C4DOS_Ge->GetCinemaInfo)(info);
}

void CopyToClipboard(const maxon::String& text)
{
	(*C4DOS_Ge->CopyToClipboard)(text);
}

void CopyToClipboard(BaseBitmap* map, Int32 ownerid)
{
	(*C4DOS_Ge->CopyToClipboardB)(map, ownerid);
}

Bool GetStringFromClipboard(String* txt)
{
	return (*C4DOS_Ge->GetStringFromClipboard)(txt);
}

Bool GetBitmapFromClipboard(BaseBitmap* map)
{
	return (*C4DOS_Ge->GetBitmapFromClipboard)(map);
}

CLIPBOARDTYPE GetClipboardType()
{
	return (*C4DOS_Ge->GetClipboardType)();
}

Int32 GetC4DClipboardOwner()
{
	return (*C4DOS_Ge->GetC4DClipboardOwner)();
}

Bool AskForAdministratorPrivileges(const maxon::String& msg, const maxon::String& caption, Bool allowsuperuser, void** token)
{
	return (*C4DOS_Ge->AskForAdministratorPrivileges)(msg, caption, allowsuperuser, token);
}

void EndAdministratorPrivileges()
{
	(*C4DOS_Ge->EndAdministratorPrivileges)();
}

void RestartApplication(const Utf16Char* param, Int32 exitcode, const Utf16Char** path)
{
	(*C4DOS_Ge->RestartApplication)(param, exitcode, path);
}

void SetExitCode(Int32 exitCode)
{
	(*C4DOS_Ge->SetExitCode)(exitCode);
}

void GeDebugOut(const maxon::String& s)
{
#ifdef MAXON_TARGET_DEBUG
	ifnoerr (maxon::BaseArray<Char> c = s.GetCString())
		GeDebugOut(c.GetFirst());
#endif
}

void GeUpdateUI()
{
	C4DOS_Ge->GeUpdateUI();
}

VIEWPORTTYPE GeGetActiveViewportType()
{
	return C4DOS_Ge->GeGetActiveViewportType();
}

const BaseBitmap* GetCursorBitmap(Int32 type, Int32& hotspotx, Int32& hotspoty)
{
	return C4DOS_Ge->GetCursorBitmap(type, hotspotx, hotspoty);
}

void MinimalViewportSettingsCommand(Int32 type)
{
	return C4DOS_Ge->MinimalViewportSettingsCommand(type);
}

Bool IsAnimationRunning(const BaseDocument* document)
{
	return C4DOS_Ge->IsAnimationRunning(document);
}

Bool IsUVToolMode(const BaseDocument* doc)
{
	return C4DOS_Ge->IsUVToolMode(doc);
}

Int32 GetFormatDepth(Int32 format, Int32 depth)
{
	return C4DOS_Ge->GetFormatDepth(format, depth);
}

ModelingCommandData::~ModelingCommandData()
{
	AtomArray::Free(result);
}

void wMotor(void* adr, Int anz)
{
	maxon::ByteOrder_UInt16<maxon::BYTEORDER::BIG>((UInt16*)adr, anz);
}

void lMotor(void* adr, Int anz)
{
	maxon::ByteOrder_UInt32<maxon::BYTEORDER::BIG>((UInt32*)adr, anz);
}

void llMotor(void* adr, Int anz)
{
	maxon::ByteOrder_UInt64<maxon::BYTEORDER::BIG>((UInt64*)adr, anz);
}

void llIntel(void* adr, Int anz)
{
	maxon::ByteOrder_UInt64<maxon::BYTEORDER::LITTLE>((UInt64*)adr, anz);
}

void lIntel(void* adr, Int anz)
{
	maxon::ByteOrder_UInt32<maxon::BYTEORDER::LITTLE>((UInt32*)adr, anz);
}

void wIntel(void* adr, Int anz)
{
	maxon::ByteOrder_UInt16<maxon::BYTEORDER::LITTLE>((UInt16*)adr, anz);
}

void llSwap(void* l, Int anz)
{
	for (UInt64* ll = (UInt64*) l; anz > 0; anz--, ll++)
		*ll = maxon::SwapUInt64(*ll);
}

void lSwap(void* l, Int anz)
{
	for (UInt32* ll = (UInt32*) l; anz > 0; anz--, ll++)
		*ll = maxon::SwapUInt32(*ll);
}

void wSwap(void* w, Int anz)
{
	for (UInt16* ll = (UInt16*) w; anz > 0; anz--, ll++)
		*ll = maxon::SwapUInt16(*ll);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
