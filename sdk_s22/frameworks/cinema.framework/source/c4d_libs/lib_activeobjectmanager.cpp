#include "lib_activeobjectmanager.h"
#include "ge_autoptr.h"
#include "c4d_baselist.h"


#define LIBID			LIBRARY_ACTIVEOBJECTMANAGER
#define AOLIB				ActiveObjectManagerLib


static AOLIB *library = nullptr;


static AOLIB *CheckLibObjectList(Int32 offset)
{
	return (AOLIB*)CheckLib(LIBID, offset, (C4DLibrary**)&library);
}


Bool ActiveObjectManager_RegisterMode(ACTIVEOBJECTMODE id, const String &text, MESSAGEHOOK *hook)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, RegisterMode)); if (!lib || !lib->RegisterMode) return false;
	return lib->RegisterMode(id, text, hook);
}

void ActiveObjectManager_SetMode(ACTIVEOBJECTMODE id, Bool openmanager)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, SetMode)); if (!lib || !lib->SetMode) return;
	lib->SetMode(id, openmanager);
}

void ActiveObjectManager_SetObjects(ACTIVEOBJECTMODE id, const AtomArray &objects, Int32 flags, const DescID &activepage)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, SetObjects)); if (!lib || !lib->SetObjects) return;
	lib->SetObjects(id, objects, flags, activepage);
}

void ActiveObjectManager_SetObject(ACTIVEOBJECTMODE id, C4DAtom *op, Int32 flags, const DescID &activepage)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, SetObjects)); if (!lib || !lib->SetObjects) return;
	AutoAlloc<AtomArray> objects; if (!objects) return;
	objects->Append(op);
	lib->SetObjects(id, objects, flags, activepage);
}

Bool ActiveObjectManager_GetObjects(ACTIVEOBJECTMODE id, AtomArray &objects)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, GetObjects)); if (!lib || !lib->GetObjects) return false;
	return lib->GetObjects(id, objects);
}

Bool ActiveObjectManager_GetModeInfo(ACTIVEOBJECTMODE id, ActiveModeInfo &info)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, GetModeInfo)); if (!lib || !lib->GetModeInfo) return false;
	return lib->GetModeInfo(id, info);
}

Int32 ActiveObjectManager_GetModeCount()
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, GetModeCount)); if (!lib || !lib->GetModeCount) return false;
	return lib->GetModeCount();
}

Bool ActiveObjectManager_GetModeInfoIdx(Int32 idx, ActiveModeInfo &info)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, GetModeInfoIdx)); if (!lib || !lib->GetModeInfoIdx) return false;
	return lib->GetModeInfoIdx(idx, info);
}

ACTIVEOBJECTMODE ActiveObjectManager_GetLastMode()
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, GetLastMode)); if (!lib || !lib->GetLastMode) return ACTIVEOBJECTMODE::NONE;
	return lib->GetLastMode();
}

void ActiveObjectManager_Open()
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, Open)); if (!lib || !lib->Open) return;
	lib->Open();
}

Bool EditObjectModal(const AtomArray &objects, const String &dlgtitle)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, EditObjectModal)); if (!lib || !lib->EditObjectModal) return false;
	return lib->EditObjectModal(objects, dlgtitle);
}

Bool EditObjectModal(C4DAtom *op, const String &dlgtitle)
{
	if (!op) return false;
	AutoAlloc<AtomArray> objects; if (!objects) return false;
	objects->Append(op);
	return EditObjectModal(objects, dlgtitle);
}

Bool EditDescription(C4DAtom *bl, const DescID &id)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, EditDescription)); if (!lib || !lib->EditDescription) return false;
	return lib->EditDescription(bl, id);
}

void AddDescription(C4DAtom* bl)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, AddDescription)); if (!lib || !lib->AddDescription) return;
	return lib->AddDescription(bl);
}

void PasteDescription(C4DAtom* bl)
{
	AOLIB *lib = CheckLibObjectList(LIBOFFSET(AOLIB, PasteDescription)); if (!lib || !lib->PasteDescription) return;
	return lib->PasteDescription(bl);
}
