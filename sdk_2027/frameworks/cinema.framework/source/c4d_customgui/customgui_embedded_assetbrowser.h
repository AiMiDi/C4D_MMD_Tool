/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_EMBEDDED_ASSETBROWSER_H__
#define CUSTOMGUI_EMBEDDED_ASSETBROWSER_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

namespace cinema
{

/// Filename breadcrumb custom GUI ID.
#define CUSTOMGUI_EMBEDDED_ASSETBROWSER			1068182

/// @addtogroup EMBEDDED_ASSETBROWSER
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define CUSTOMGUI_ASSETBROWSER_DEFAULT_CATEGORY		10000 ///< maxon::Id -> String - selected start category
#define CUSTOMGUI_ASSETBROWSER_POPUPFLAGS					10001 ///< maxon::ASSETPOPUPOPTIONS -> Int32
#define CUSTOMGUI_ASSETBROWSER_MASTERFILTERSTRING 10002 ///< maxon::String - master filter string for asset browser
/// @}

//----------------------------------------------------------------------------------------
/// Filename breadcrumb custom GUI (@ref CUSTOMGUI_EMBEDDED_ASSETBROWSER).\n
/// Here are the settings: @enumerateEnum{EMBEDDED_ASSETBROWSER}
//----------------------------------------------------------------------------------------
class EmbeddedAssetBrowserCustomGui : public BaseCustomGui<CUSTOMGUI_EMBEDDED_ASSETBROWSER>
{
		EmbeddedAssetBrowserCustomGui();
		~EmbeddedAssetBrowserCustomGui();

	public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
#ifndef _INTERNAL_DEF_
	class iEmbeddedAssetBrowserCustomGui : public iBaseCustomGui
	{
		iEmbeddedAssetBrowserCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iEmbeddedAssetBrowserCustomGui;
#endif

struct CustomGuiEmbeddedAssetBrowserLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema


#endif // CUSTOMGUI_EMBEDDED_ASSETBROWSER_H__
