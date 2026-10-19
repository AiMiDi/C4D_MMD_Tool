#ifndef EXTRAGADGETS_H__
#define EXTRAGADGETS_H__

#include "maxon/registrybase.h"
#include "maxon/datadictionary.h"
#include "maxon/vector.h"

namespace cinema
{
class GeDialog;
} // namespace cinema

namespace maxon
{
static constexpr Int32 BFM_IS_DIALOG_PINNED           = 'ispi';
static constexpr Int32 BFM_GET_FOCUS_LOST_CLOSE_TIME  = 'flct';

using GetActiveChildDelegate = Delegate<Data()>;
using GetGeDialogDelegate    = Delegate<cinema::GeDialog*()>;
using GetIconIdDelegate      = Delegate<Int32()>;
using StringArray            = BaseArray<String>;

using OnButtonPressDelegate  = Delegate<void()>;
using GetColorDelegate       = Delegate<maxon::Vector()>;
using ButtonRequiresUpdate   = Delegate<Bool()>;

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
enum class DRAWENTRYTYPE
{
	ICON = 0,
	STRING = 1,
	BUTTON = 2,
	LINE = 3,
};

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
namespace EXTRAGADGET
{
	namespace PROPERTIES
	{
		MAXON_ATTRIBUTE(Int32, POPUP_ID, "net.maxon.command.extragadget.properties.popupid");
		MAXON_ATTRIBUTE(Int32, ICON_GADGET_POPUP_ID, "net.maxon.command.extragadget.properties.icongadgetpopupid");

		MAXON_ATTRIBUTE(Int32, DEFAULT_WIDTH, "net.maxon.command.extragadget.properties.defaultwidth");
		MAXON_ATTRIBUTE(String, COMMAND_NAME, "net.maxon.command.extragadget.properties.commandname");
		MAXON_ATTRIBUTE(String, COMMAND_HELP, "net.maxon.command.extragadget.properties.commandhelp");
		MAXON_ATTRIBUTE(StringArray, CHILDREN_STRINGS, "net.maxon.command.extragadget.properties.childrenstrings");
		MAXON_ATTRIBUTE(DelegateBase, GET_ACTIVE_DIALOG_DELEGATE, "net.maxon.command.extragadget.properties.getActiveDialogDelegate");
		MAXON_ATTRIBUTE(DelegateBase, DISPLAY_CUSTOM_STRING_DELEGATE, "net.maxon.command.extragadget.icongadget.entry.displayCustomStringDelegate");
		
		MAXON_ATTRIBUTE(maxon::Array<DataDictionary>, DRAW_ARRAY, "net.maxon.command.extragadget.icongadget.iconArray");
	}

	namespace DRAW_ENTRY
	{
		MAXON_ATTRIBUTE(DRAWENTRYTYPE, TYPE, "net.maxon.command.extragadget.icongadget.entry.type");
		MAXON_ATTRIBUTE(Int32, MARGIN_LEFT, "net.maxon.command.extragadget.icongadget.entry.marginleft", RESOURCE_DEFAULT(6));
		MAXON_ATTRIBUTE(Int32, ENDMARGIN, "net.maxon.command.extragadget.icongadget.entry.endmargin", RESOURCE_DEFAULT(6));

		namespace ICON
		{
			MAXON_ATTRIBUTE(Int32, ID, "net.maxon.command.extragadget.icongadget.entry.icon.id");
			MAXON_ATTRIBUTE(Int32, SIZE, "net.maxon.command.extragadget.icongadget.entry.icon.size", RESOURCE_DEFAULT(16));
		}

		namespace BUTTON
		{
			MAXON_ATTRIBUTE(Int32, ID, "net.maxon.command.extragadget.icongadget.entry.button.id");
			MAXON_ATTRIBUTE(Int32, SIZE, "net.maxon.command.extragadget.icongadget.entry.button.size", RESOURCE_DEFAULT(16));
			MAXON_ATTRIBUTE(DelegateBase, BUTTON_PRESS, "net.maxon.command.extragadget.icongadget.entry.onInteractionDelegate");
			MAXON_ATTRIBUTE(DelegateBase, GET_COLOR, "net.maxon.command.extragadget.icongadget.entry.getActiveState");
			MAXON_ATTRIBUTE(DelegateBase, REQUIRES_UPDATE, "net.maxon.command.extragadget.icongadget.entry.requiresUpdate");
		}

		namespace LINE
		{
			MAXON_ATTRIBUTE(Float, LINEWIDTH, "net.maxon.command.extragadget.icongadget.entry.width", RESOURCE_DEFAULT(1.0));
			MAXON_ATTRIBUTE(Vector, COLOR, "net.maxon.command.extragadget.icongadget.entry.color", RESOURCE_DEFAULT(Vector(1.0)));
		}
	}
}

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ExtraGadgets
{
	MAXON_INTERFACE_NONVIRTUAL(ExtraGadgets, MAXON_REFERENCE_STATIC, "net.maxon.interface.extragadgets");

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal getActiveChildDelegate can return either the child index as Data<Int> or the child string as Data<String>.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool RegisterDropdownIconGadgetCommand(Int32 iconGadgetId, Int32 popupId, Int32 defaultPopupWidth, const String& commandName, const String& commandHelp, GetGeDialogDelegate&& getPopupDelegate, GetActiveChildDelegate&& getActiveChildDelegate, StringArray&& childrenStrings);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool RegisterIconGadgetCommand(DataDictionary&& dict);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD maxon::Result<void> SetIconIdDelegateToDropdownIconGadget(Int32 iconGadgetId, const GetIconIdDelegate& getIconIdDelegate);
};

#include "extragadgets1.hxx"
#include "extragadgets2.hxx"

} // namespace maxon

#endif // EXTRAGADGETS_H__
