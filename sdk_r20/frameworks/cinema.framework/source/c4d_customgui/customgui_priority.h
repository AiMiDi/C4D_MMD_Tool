/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_PRIORITY_H__
#define CUSTOMGUI_PRIORITY_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

/// Priority custom GUI ID.
#define CUSTOMGUI_PRIORITY					1009364

/// Priority custom data type ID.
#define CUSTOMGUI_PRIORITY_DATA			1009369

/// @addtogroup PRIORITY_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define PRIORITY_FLAG_NOCAMERA						1000			///< ::Bool Hide the Camera dependent checkbox.
/// @}

/// @addtogroup PRIORITYVALUE
/// @ingroup group_containerid
/// @{
#define PRIORITYVALUE_MODE								0			///< ::Int32 Mode: @enumerateEnum{CYCLE}
#define PRIORITYVALUE_PRIORITY						1			///< ::Int32 Priority.
#define PRIORITYVALUE_CAMERADEPENDENT			2			///< ::Bool Camera dependent.
/// @}

/// @addtogroup CYCLE
/// @ingroup group_enumeration
/// @{
#define CYCLE_INITIAL											0			///< Initial.
#define CYCLE_ANIMATION										1			///< Animation.
#define CYCLE_EXPRESSION									2			///< Expression.
#define CYCLE_DYNAMICS										3			///< Dynamics.
#define CYCLE_GENERATORS									4			///< Generators.
/// @}


//----------------------------------------------------------------------------------------
/// Priority custom GUI (@ref CUSTOMGUI_PRIORITY).\n
/// Here are the settings: @enumerateEnum{PRIORITY_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class PriorityCustomGui : public BaseCustomGui<CUSTOMGUI_PRIORITY>
{
private:
	PriorityCustomGui();
	~PriorityCustomGui();
public:
	//----------------------------------------------------------------------------------------
	/// Sets a priority value.
	/// @param[in] lValueID						The value ID: @enumerateEnum{PRIORITYVALUE}
	/// @param[in] data								The new value data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetValue(Int32 lValueID, const GeData &data);

	//----------------------------------------------------------------------------------------
	/// Gets a priority value.
	/// @param[in] lValueID						The value ID: @enumerateEnum{PRIORITYVALUE}
	/// @return												The value data.
	//----------------------------------------------------------------------------------------
	GeData GetValue(Int32 lValueID) const;
};

//----------------------------------------------------------------------------------------
/// Priority custom data type (@ref CUSTOMGUI_PRIORITY_DATA).
//----------------------------------------------------------------------------------------
class PriorityData : public CustomDataType
{
private:
	PriorityData();
	~PriorityData();
public:
	//----------------------------------------------------------------------------------------
	/// Sets a priority value.
	/// @param[in] lValueID						The value ID: @enumerateEnum{PRIORITYVALUE}
	/// @param[in] data								The new value data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPriorityValue(Int32 lValueID, const GeData &data);

	//----------------------------------------------------------------------------------------
	/// Gets a priority value.
	/// @param[in] lValueID						The value ID: @enumerateEnum{PRIORITYVALUE}
	/// @return												The value data.
	//----------------------------------------------------------------------------------------
	GeData GetPriorityValue(Int32 lValueID) const;
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iPriorityCustomGui : public iBaseCustomGui
	{
		iPriorityCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iPriorityData {};
#else
	class iPriorityCustomGui;
	class iPriorityData;
#endif

struct PriorityCustomGuiLib : public BaseCustomGuiLib
{
	Bool    (iPriorityCustomGui::*SetValue)(Int32 lValueID, const GeData &data);
	GeData  (iPriorityCustomGui::*GetValue)(Int32 lValueID) const;
	Bool    (iPriorityData::*SetPriorityValue)(Int32 lValueID, const GeData &data);
	GeData  (iPriorityData::*GetPriorityValue)(Int32 lValueID) const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_PRIORITY_H__
