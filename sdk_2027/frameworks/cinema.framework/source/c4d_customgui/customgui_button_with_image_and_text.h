#ifndef CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT_H__
#define CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT_H__

#include "c4d_customgui/customgui_base.h"
#include "lib_description.h"

namespace cinema
{
constexpr const Int32 CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT = 1069153;

#ifdef INTERNAL_BUTTON_WITH_IMAGE_AND_TEXT__
	class iButtonWithImageAndTextCustomGui;
#else
	class CINEWARE_SINGLEINHERITANCE iButtonWithImageAndTextCustomGui : public iBaseCustomGui
	{
		iButtonWithImageAndTextCustomGui(const BaseContainer& settings, CUSTOMGUIPLUGIN* plugin) : iBaseCustomGui(settings, plugin) {}
	};
#endif

/// Library structure — extends BaseCustomGuiLib with SetActive/IsActive.
struct ButtonWithImageAndTextLib : public BaseCustomGuiLib
{
	void (iButtonWithImageAndTextCustomGui::*SetActive)(Bool active);
	Bool (iButtonWithImageAndTextCustomGui::*IsActive)() const;
};

class ButtonWithImageAndTextCustomGui : public BaseCustomGui<CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT>
{
	ButtonWithImageAndTextCustomGui();
	~ButtonWithImageAndTextCustomGui();

public:
	/// Sets the active (selected/highlighted) state of the button.
	/// \param[in] active		true to mark the button as active, false to deactivate.
	inline void SetActive(Bool active)
	{
		static ButtonWithImageAndTextLib* cache = nullptr;
		ButtonWithImageAndTextLib* lib = CheckLib<ButtonWithImageAndTextLib>(
			CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT,
			LIBOFFSET(ButtonWithImageAndTextLib, SetActive),
			cache);
		if (!lib || !lib->SetActive)
			return;
		(reinterpret_cast<iButtonWithImageAndTextCustomGui*>(this)->*lib->SetActive)(active);
	}

	/// Returns whether the button is currently in the active (selected) state.
	inline Bool IsActive() const
	{
		static ButtonWithImageAndTextLib* cache = nullptr;
		ButtonWithImageAndTextLib* lib = CheckLib<ButtonWithImageAndTextLib>(
			CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT,
			LIBOFFSET(ButtonWithImageAndTextLib, IsActive),
			cache);
		if (!lib || !lib->IsActive)
			return false;
		return (reinterpret_cast<const iButtonWithImageAndTextCustomGui*>(this)->*lib->IsActive)();
	}
};

} // namespace cinema

#endif // CUSTOMGUI_BUTTON_WITH_IMAGE_AND_TEXT_H__
