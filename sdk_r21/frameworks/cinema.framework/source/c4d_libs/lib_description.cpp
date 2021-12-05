#include "lib_description.h"

static DescriptionLib *library_desc = nullptr;

static DescriptionLib *CheckDescriptionLib(Int32 offset)
{
	return (DescriptionLib*)CheckLib(LIBRARY_DESCRIPTIONLIB, offset, (C4DLibrary**)&library_desc);
}

Bool DescLevel::operator == (const DescLevel &d) const
{
	if (d.id != id) return false;

	// special case!
	if (d.dtype == 0 && d.id == 0 && d.creator == 0) return (dtype == 0 && id == 0 && creator == 0);
	else if (dtype == 0 && id == 0 && creator == 0) return (d.dtype == 0 && d.id == 0 && d.creator == 0);

	if (d.dtype && dtype && d.dtype != dtype) return false;
	if (d.creator && creator && d.creator != creator) return false;

	return true;
}

Bool DescLevel::operator != (const DescLevel &d) const
{
	return !(*this == d);
}

Int32 DescID::GetDepth() const
{
	Int32 i = 0;
	for (; (*this)[i].id != 0; i++) { }
	return i;
}

// checks if 'this' is part of 'cmp'
Bool DescID::IsPartOf(const DescID &cmp, Int32 *pos) const
{
	Int32 i;
	for (i = 0; (*this)[i].id != 0; i++)
	{
		// ITEM#37542 MAXON Bug-Report V11.514 [mac], comparing only the id without the type caused a crash in animation.
		if ((*this)[i] != cmp[i])
			break;
	}
	if (pos) *pos = i;
	return i > 0 && (*this)[i].id == 0;
}

Bool Description_Register(Int32 id, const String &idstr, LocalResource *res)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, Register)); if (!lib || !lib->Register) return false;
	return lib->Register(id, idstr, res);
}

#ifndef __API_INTERN__

DescID::DescID()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
}

DescID::DescID(const DescID &src)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
	*this = src;
}

DescID::DescID(const DescLevel &id1)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
	SetId(id1);
}

DescID::DescID(Int32 id1)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
	SetId(DescLevel(id1));
}

DescID::DescID(const DescLevel &id1, const DescLevel &id2)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
	SetId(id1);
	PushId(id2);
}

DescID::DescID(const DescLevel &id1, const DescLevel &id2, const DescLevel &id3)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Init)); if (!lib || !lib->DescID_Init) return;
	lib->DescID_Init(this);
	SetId(id1);
	PushId(id2);
	PushId(id3);
}

DescID::~DescID()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Free)); if (!lib || !lib->DescID_Free) return;
	lib->DescID_Free(this);
}

void DescID::SetId(const DescLevel &subid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_SetId)); if (!lib || !lib->DescID_SetId) return;
	lib->DescID_SetId(this, subid);
}

void DescID::PushId(const DescLevel &subid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_PushId)); if (!lib || !lib->DescID_PushId) return;
	lib->DescID_PushId(this, subid);
}

void DescID::PopId()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_PopId)); if (!lib || !lib->DescID_PopId) return;
	lib->DescID_PopId(this);
}

UInt DescID::GetHashCode() const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_GetHashCode)); if (!lib || !lib->DescID_GetHashCode) return 0;
	return lib->DescID_GetHashCode(this);
}

Bool DescID::Read(HyperFile *hf)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Read)); if (!lib || !lib->DescID_Read) return false;
	return lib->DescID_Read(this, hf);
}

Bool DescID::Write(HyperFile *hf)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Read)); if (!lib || !lib->DescID_Write) return false;
	return lib->DescID_Write(this, hf);
}

DescLevel fallbacklevel(0);

const DescLevel &DescID::operator[] (Int32 pos) const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_operator1)); if (!lib || !lib->DescID_operator1) return fallbacklevel;
	return lib->DescID_operator1((DescID*)this, pos);
}

const DescID DescID::operator<< (Int32 shift) const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_operator2)); if (!lib || !lib->DescID_operator2) return fallbacklevel;
	return lib->DescID_operator2((DescID*)this, shift);
}

const DescID& DescID::operator = (const DescID &id)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_CopyTo)); if (!lib || !lib->DescID_CopyTo) return *this;
	lib->DescID_CopyTo((DescID*)&id, (DescID*)this);
	return *this;
}

Bool DescID::operator == (const DescID &d) const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Compare)); if (!lib || !lib->DescID_Compare) return 0;
	return lib->DescID_Compare((DescID*)&d, (DescID*)this);
}

Bool DescID::operator != (const DescID &d) const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Compare)); if (!lib || !lib->DescID_Compare) return true;
	return !lib->DescID_Compare((DescID*)&d, (DescID*)this);
}

const DescID & DescID::operator += (const DescID &s)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_AddTo)); if (!lib || !lib->DescID_AddTo) return *this;
	lib->DescID_AddTo((DescID*)this, (DescID*)&s);
	return *this;
}


Description::Description()
{
}

Description *Description::Alloc()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, Alloc)); if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void Description::Free(Description *&description)
{
	if (!description) return;
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, Free)); if (!lib || !lib->Free) return;
	lib->Free(description);
	description = nullptr;
}

Bool Description::LoadDescription(const BCResourceObj *bc, Bool copy)
{
	if (!bc) return false;
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, LoadDescriptionBc)); if (!lib || !lib->LoadDescriptionBc) return false;
	return lib->LoadDescriptionBc(this, bc, copy);
}

Bool Description::LoadDescription(Int32 id)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, LoadDescriptionId)); if (!lib || !lib->LoadDescriptionId) return false;
	return lib->LoadDescriptionId(this, id);
}

Bool Description::LoadDescription(const String &id)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, LoadDescriptionStr)); if (!lib || !lib->LoadDescriptionStr) return false;
	return lib->LoadDescriptionStr(this, &id);
}

Bool Description::SortGroups()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, SortGroups)); if (!lib || !lib->SortGroups) return false;
	return lib->SortGroups(this);
}

const BCResourceObj* Description::GetDescription()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetDescription)); if (!lib || !lib->GetDescription) return nullptr;
	return lib->GetDescription(this);
}

const BaseContainer* Description::GetParameter(const DescID &id, BaseContainer &temp, AtomArray *ar) const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetParameter)); if (!lib || !lib->GetParameter) return nullptr;
	return lib->GetParameter(this, id, temp, ar);
}

BaseContainer* Description::GetParameterI(const DescID &id, AtomArray *ar)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetParameterI)); if (!lib || !lib->GetParameterI) return nullptr;
	return lib->GetParameterI(this, id, ar);
}

Bool Description::SetParameter(const DescID &id, const BaseContainer &param, const DescID &groupid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetParameter)); if (!lib || !lib->SetParameter) return false;
	return lib->SetParameter(this, id, param, groupid);
}

void *Description::BrowseInit()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, BrowseInit)); if (!lib || !lib->BrowseInit) return nullptr;
	return lib->BrowseInit(this);
}

Bool Description::GetNext(void *handle, const BaseContainer **bc, DescID &id, DescID &groupid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetNext)); if (!lib || !lib->GetNext) return false;
	return lib->GetNext(this, handle, bc, id, groupid);
}

void Description::BrowseFree(void *&handle)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, BrowseFree)); if (!lib || !lib->BrowseFree) return;
	lib->BrowseFree(this, handle);
}

SubDialog *Description::CreateDialogI()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, CreateDialogI)); if (!lib || !lib->CreateDialogI) return nullptr;
	return lib->CreateDialogI(this);
}

void Description::FreeDialog(SubDialog *dlg)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, FreeDialog)); if (!lib) return;
	lib->FreeDialog(this, dlg);
}

Bool Description::CreatePopupMenu(BaseContainer &menu)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, CreatePopupMenu)); if (!lib) return false;
	return lib->CreatePopupMenu(this, &menu);
}

Bool Description::GetPopupId(Int32 id, const DescID &descid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetPopupId)); if (!lib) return false;
	return lib->GetPopupId(this, id, descid);
}

const DescID* Description::GetSingleDescID()
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetSingleDescID)); if (!lib) return nullptr;
	return lib->GetSingleDescID(this);
}

void Description::SetSingleDescriptionMode(const DescID &descid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, SetSingleDescriptionMode)); if (!lib) return;
	lib->SetSingleDescriptionMode(this, descid);
}

Bool Description::GetSubDescriptionWithData(const DescID &did, const AtomArray &op, RESOURCEDATATYPEPLUGIN *resdatatypeplugin, const BaseContainer &bc, DescID *singledescid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetSubDescriptionWithData)); if (!lib) return false;
	return lib->GetSubDescriptionWithData(this, did, op, resdatatypeplugin, bc, singledescid);
}

Bool Description::CheckDescID(const DescID &searchid, const AtomArray &ops, DescID *completeid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, CheckDescID)); if (!lib) return false;
	return lib->CheckDescID(this, searchid, ops, completeid);
}

DescEntry* Description::GetFirst(const AtomArray &op)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescEntryGetFirst)); if (!lib) return nullptr;
	return lib->DescEntryGetFirst(this, op);
}

DescEntry* Description::GetNext(DescEntry *de)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescEntryGetNext)); if (!lib) return nullptr;
	return lib->DescEntryGetNext(this, de);
}

DescEntry* Description::GetDown(DescEntry *de)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescEntryGetDown)); if (!lib) return nullptr;
	return lib->DescEntryGetDown(this, de);
}

void Description::GetDescEntry(DescEntry *de, const BaseContainer **bc, DescID &descid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescEntryGetDescEntry)); if (!lib) return;
	lib->DescEntryGetDescEntry(this, de, bc, descid);
}

String DescGenerateTitle(AtomArray *arr)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescEntryGetDescEntry)); if (!lib) return String();
	return lib->DescGenerateTitle(arr);
}

const DescID operator+(const DescID &v1, const DescID &v2)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DescID_Add)); if (!lib || !lib->DescID_Add) return v1;
	return lib->DescID_Add((DescID*)&v1, (DescID*)&v2);
}

DescID DynamicDescription::Alloc(const BaseContainer &datadescription)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDAlloc)); if (!lib || !lib->DDAlloc) return DescLevel(0);
	return (this->*lib->DDAlloc)(datadescription);
}

Bool DynamicDescription::Set(const DescID &descid, const BaseContainer &datadescription, BaseList2D *bl)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDSet)); if (!lib || !lib->DDSet) return false;
	return (this->*lib->DDSet)(descid, datadescription, bl);
}

const BaseContainer* DynamicDescription::Find(const DescID &descid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDFind)); if (!lib || !lib->DDFind) return nullptr;
	return (this->*lib->DDFind)(descid);
}

Bool DynamicDescription::Remove(const DescID &descid)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDRemove)); if (!lib || !lib->DDRemove) return false;
	return (this->*lib->DDRemove)(descid);
}

Bool DynamicDescription::CopyTo(DynamicDescription *dest)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDCopyTo)); if (!lib || !lib->DDCopyTo) return false;
	return (this->*lib->DDCopyTo)(dest);
}

void* DynamicDescription::BrowseInit(void)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDBrowseInit)); if (!lib || !lib->DDBrowseInit) return nullptr;
	return (this->*lib->DDBrowseInit)();
}

Bool DynamicDescription::BrowseGetNext(void* handle, DescID *id, const BaseContainer **data)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDBrowseGetNext)); if (!lib || !lib->DDBrowseGetNext) return false;
	return (this->*lib->DDBrowseGetNext)(handle, id, data);
}

void DynamicDescription::BrowseFree(void* &handle)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, DDBrowseFree)); if (!lib || !lib->DDBrowseFree) return;
	(this->*lib->DDBrowseFree)(handle);
}

Bool DynamicDescription::FillDefaultContainer(BaseContainer &res, Int32 type, const String &name)
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, FillDefaultContainer)); if (!lib || !lib->FillDefaultContainer) return false;
	return (this->*lib->FillDefaultContainer)(res, type, name);
}

UInt32 DynamicDescription::GetDirty() const
{
	DescriptionLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionLib, GetDirty)); if (!lib || !lib->GetDirty) return 0;
	const UInt32 dirty = (this->*lib->GetDirty)();
	return dirty;
}

#endif

