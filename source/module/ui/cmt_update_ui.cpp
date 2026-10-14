#include "cmt_update_ui.h"
#include "cmt_update_manager.h"
#include "plugin_resource.h"
#include <c4d_symbols.h>
#include "c4d_libs/lib_prefs.h"
#include "description/PCMTUpdate.h"

namespace
{
String Text(Int32 id) { return GeLoadString(id); }

String UpdateStatus()
{
	const auto& manager = CMTUpdateManager::GetInstance();
	String text = manager.Installed().empty() ? Text(IDS_CMT_UPDATE_UNKNOWN) : String(manager.Installed().c_str());
	text += " -> ";
	if (manager.GetStatus() == CMTUpdateManager::Status::Checking) text += Text(IDS_CMT_UPDATE_CHECKING);
	else if (manager.GetStatus() == CMTUpdateManager::Status::Failed) text += Text(IDS_CMT_UPDATE_FAILED);
	else if (!manager.Latest().empty())
	{
		text += String(manager.Latest().c_str());
	}
	else text += Text(IDS_CMT_UPDATE_NOT_CHECKED);
	return text;
}

class UpdateReminderDialog final : public GeDialog
{
	std::string displayedVersion_;
	Bool CreateLayout() override
	{
		SetTitle(Text(IDS_CMT_UPDATE_TITLE));
		GroupBegin(10, BFH_SCALEFIT | BFV_SCALEFIT, 1, 0, String(), 0);
		GroupBorderSpace(16, 12, 16, 12);
		AddStaticText(11, BFH_SCALEFIT, SizePix(520), SizePix(24), String(), 0);
		AddMultiLineEditText(12, BFH_SCALEFIT | BFV_SCALEFIT, SizePix(520), SizePix(300),
			DR_MULTILINE_READONLY | DR_MULTILINE_WORDWRAP);
		GroupBegin(13, BFH_RIGHT, 3, 0, String(), 0);
		AddButton(14, BFH_FIT, 0, 0, Text(IDS_CMT_UPDATE_OPEN));
		AddButton(15, BFH_FIT, 0, 0, Text(IDS_CMT_UPDATE_LATER));
		AddButton(16, BFH_FIT, 0, 0, Text(IDS_CMT_UPDATE_IGNORE));
		GroupEnd();
		GroupEnd();
		return true;
	}
	Bool InitValues() override
	{
		const auto& manager = CMTUpdateManager::GetInstance();
		displayedVersion_ = manager.Latest();
		String heading = Text(IDS_CMT_UPDATE_AVAILABLE);
		heading += " ";
		heading += String(manager.Latest().c_str());
		heading += "   (";
		heading += Text(IDS_CMT_UPDATE_INSTALLED);
		heading += " ";
		heading += String(manager.Installed().c_str());
		heading += ")";
		SetString(11, heading);
		const bool chinese = Text(IDS_CMT_UPDATE_LANGUAGE_CODE) == String("zh-CN");
		auto notes = cmt_update::LocalizedNotes(manager.Notes(), chinese);
		if (chinese) notes = cmt_update::WrapCjkNotes(notes);
		SetString(12, notes.empty() ? Text(IDS_CMT_UPDATE_NO_NOTES) : String(notes.c_str(), STRINGENCODING::UTF8));
		return true;
	}
	Bool Command(Int32 id, const BaseContainer&) override
	{
		if (id == 14) { GeOpenHTML(String(cmt_update::PageForVersion(displayedVersion_).c_str())); return Close(); }
		if (id == 15) return Close();
		if (id == 16) { CMTUpdateManager::GetInstance().IgnoreVersion(displayedVersion_); return Close(); }
		return true;
	}
};

// C4D's GUI API is unavailable during DLL static initialization.
// Allocate on the main-thread timer and destroy while the host is still alive.
UpdateReminderDialog* reminder = nullptr;

class UpdateMessage final : public MessageData
{
	Int32 GetTimer() override { return 1000; }
	Bool CoreMessage(Int32 id, const BaseContainer&) override
	{
		if (id != MSG_TIMER) return true;
		auto& manager = CMTUpdateManager::GetInstance();
		const auto before = manager.GetStatus();
		manager.Poll();
		if (before != manager.GetStatus()) EventAdd();
		if ((!reminder || !reminder->IsOpen()) && manager.TakeNotification())
		{
			if (!reminder) reminder = NewObjClear(UpdateReminderDialog);
			if (reminder) reminder->Open(DLG_TYPE::ASYNC, g_cmt_command_id, -1, -1, 560, 400, 2);
		}
		return true;
	}
};

class UpdatePreferences final : public PrefsDialogObject
{
public:
	static NodeData* Alloc() { return NewObjClear(UpdatePreferences); }
	SDK2024_GetDParameterOverride;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& value, DESCFLAGS_SET& flags) override;
	SDK2024_GetDEnablingOverride;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
};

SDK2024_GetDParameter(UpdatePreferences)
{
	const auto& manager = CMTUpdateManager::GetInstance();
	if (id[0].id == CMT_UPDATE_AUTOMATIC) t_data = GeData(manager.Automatic());
	else if (id[0].id == CMT_UPDATE_STATUS) t_data = GeData(UpdateStatus());
	else return PrefsDialogObject::GetDParameter(node, id, t_data, flags);
	flags |= DESCFLAGS_GET::PARAM_GET;
	return true;
}

Bool UpdatePreferences::SetDParameter(GeListNode* node, const DescID& id, const GeData& value, DESCFLAGS_SET& flags)
{
	if (id[0].id != CMT_UPDATE_AUTOMATIC) return PrefsDialogObject::SetDParameter(node, id, value, flags);
	CMTUpdateManager::GetInstance().SetAutomatic(value.GetBool());
	flags |= DESCFLAGS_SET::PARAM_SET;
	return true;
}

SDK2024_GetDEnabling(UpdatePreferences)
{
	if (id[0].id == CMT_UPDATE_STATUS) return false;
	if (id[0].id == CMT_UPDATE_CHECK) return CMTUpdateManager::GetInstance().GetStatus() != CMTUpdateManager::Status::Checking;
	return PrefsDialogObject::GetDEnabling(node, id, t_data, flags, itemdesc);
}

Bool UpdatePreferences::Message(GeListNode* node, Int32 type, void* data)
{
	if (type == MSG_DESCRIPTION_COMMAND && data)
	{
		const auto* command = static_cast<DescriptionCommand*>(data);
		if (command->_descId[0].id == CMT_UPDATE_CHECK) { CMTUpdateManager::GetInstance().Check(true); EventAdd(); return true; }
		if (command->_descId[0].id == CMT_UPDATE_OPEN) return CMTUpdateManager::GetInstance().OpenReleasePage();
	}
	return PrefsDialogObject::Message(node, type, data);
}
}

Bool RegisterCMTUpdateUI()
{
	if (!PrefsDialogObject::Register(g_cmt_update_preferences_id, UpdatePreferences::Alloc,
		"MMD Tools"_s, "PCMTUpdate"_s, 0, 0)) return false;
	return RegisterMessagePlugin(g_cmt_update_message_id, "MMD Tools Update"_s, 0, NewObjClear(UpdateMessage));
}

void CloseCMTUpdateUI()
{
	if (!reminder) return;
	if (reminder->IsOpen()) reminder->Close();
	DeleteObj(reminder);
}
