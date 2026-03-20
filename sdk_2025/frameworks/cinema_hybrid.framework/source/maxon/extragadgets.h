#ifndef EXTRAGADGETS_H__
#define EXTRAGADGETS_H__

#include "maxon/registrybase.h"

namespace cinema
{
class GeDialog;
} // namespace cinema

namespace maxon
{
static constexpr Int32 BFM_IS_DIALOG_PINNED = 'ispi';
static constexpr Int32 BFM_GET_FOCUS_LOST_CLOSE_TIME = 'flct';

using GetStringDelegate		= Delegate<String()>;
using GetGeDialogDelegate	= Delegate<cinema::GeDialog*()>;

class ExtraGadgets
{
	MAXON_INTERFACE_NONVIRTUAL(ExtraGadgets, MAXON_REFERENCE_STATIC, "net.maxon.interface.extragadgets");

public:
	static MAXON_METHOD Bool RegisterDropdownIconGadgetCommand(Int32 iconGadgetId, Int32 popupId, Int32 defaultPopupWidth, const String& commandName, const String& commandHelp, GetGeDialogDelegate&& getPopupDelegate, GetStringDelegate&& getLabeldelegate);
};

#include "extragadgets1.hxx"
#include "extragadgets2.hxx"

} // namespace maxon

#endif // EXTRAGADGETS_H__
