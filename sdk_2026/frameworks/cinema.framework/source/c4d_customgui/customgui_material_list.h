/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_MATERIAL_LIST_H__
#define CUSTOMGUI_MATERIAL_LIST_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

namespace cinema
{

/// Material List custom GUI ID.
#define CUSTOMGUI_MATERIAL_LIST	1065058

/// Material List custom data type ID.
#define CUSTOMDATATYPE_MATERIAL_LIST	1065059

//----------------------------------------------------------------------------------------
/// Material List custom GUI (@ref CUSTOMGUI_MATERIAL_LIST)\n
/// Here are the settings: @enumerateEnum{MATERIAL_LIST_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class MaterialListGui : public BaseCustomGui<CUSTOMGUI_MATERIAL_LIST>
{
private:
	MaterialListGui();
	~MaterialListGui();
public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_MATERIAL_LIST_DEF_
	class iMaterialListGui
	{
	};
#else
	class iMaterialListGui;
#endif

struct CustomGuiMaterialListLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_MATERIAL_LIST_H__

