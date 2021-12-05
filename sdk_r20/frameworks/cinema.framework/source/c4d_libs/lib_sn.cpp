#include "lib_sn.h"
#include "c4d_string.h"
#include "c4d_gui.h"

SNLib *lib_sn = nullptr;

static SNLib *CheckSnLib(Int32 offset)
{
	return (SNLib*)CheckLib(LIBRARY_SN, offset, (C4DLibrary**)&lib_sn);
}


Bool SN_Register(Int32 id, SNHook *snhook)
{
	SNLib *lib = CheckSnLib(LIBOFFSET(SNLib, SN_Register));
	if (!lib || !lib->SN_Register) return false;
	return (*lib->SN_Register)(id, snhook);
}

SNHook *SN_FindHook(Int32 id)
{
	SNLib *lib = CheckSnLib(LIBOFFSET(SNLib, SN_FindHook));
	if (!lib || !lib->SN_FindHook) return nullptr;
	return (*lib->SN_FindHook)(id);
}



static Int32 iSN_Check(SNHook *snhook, const String &c4dsn, const String &sn, Int32 regdate, Int32 curdate)
{
	if (!snhook) return 0;
	return ((SNHookClass*)(snhook->thisptr))->SNCheck(c4dsn, sn, regdate, curdate);
}

static const String& iSN_GetTitle(SNHook *snhook)
{
	if (!snhook) return *C4DOS.St->Default;
	return ((SNHookClass*)(snhook->thisptr))->GetTitle();
}

static const Char* iSN_GetClipID(SNHook *snhook)
{
	if (!snhook) return nullptr;
	return ((SNHookClass*)(snhook->thisptr))->GetClipID();
}


SNHookClass::SNHookClass()
{
	hook.thisptr			= this;
	hook.SN_Check			= iSN_Check;
	hook.SN_GetTitle	= iSN_GetTitle;
	hook.SN_GetClipID = iSN_GetClipID;
}

Bool SNHookClass::Register(Int32 id, Int32 flags)
{
	hook.flags = flags;
	return SN_Register(id, &hook);
}

Int32 SNHookClass::SNCheck(const String &c4dsn, const String &sn, Int32 regdate, Int32 curdate)
{
	return SN_WRONGNUMBER;
}

const String& SNHookClass::GetTitle()
{
	return *C4DOS.St->Default;
}

const Char* SNHookClass::GetClipID()
{
	return nullptr;
}
