/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_UNITSCALE_H__
#define CUSTOMGUI_UNITSCALE_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "customgui_base.h"

/// Unit scale custom GUI ID.
#define CUSTOMGUI_UNITSCALE								200000274

/// Unit scale custom data type ID.
#define CUSTOMDATATYPE_UNITSCALE					200000275

/// @addtogroup UNITSCALE_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define UNITSCALE_SCALE							1			///< ::Float The unit scale.
#define UNITSCALE_UNIT							2			///< ::Int32 The unit: @enumerateEnum{DOCUMENT_UNIT}
/// @}

/// @addtogroup DOCUMENT_UNIT
/// @ingroup group_enumeration
/// @{
/// Document units.
enum class DOCUMENT_UNIT
{
	UNDEFINED						= 0,			///< Undefined.
	KM									= 1,			///< Kilometer.
	M										= 2,			///< Meter.
	CM									= 3,			///< Centimeter.
	MM									= 4,			///< Millimeter.
	MICRO								= 5,			///< Micrometer.
	NM									= 6,			///< Nanometer.
	MILE								= 7,			///< Mile.
	YARD								= 8,			///< Yard.
	FOOT								= 9,			///< Foot.
	INCH								= 10			///< Inch.
} MAXON_ENUM_LIST(DOCUMENT_UNIT);
/// @}

/// @addtogroup HIDE_UNIT
/// @ingroup group_enumeration
/// @{
/// Hide Document units.
enum HIDE_UNIT
{
	KM = 2001,			///< Bool Hide Kilometer.
	M = 2002,				///< Bool Hide Meter.
	CM = 2003,			///< Bool Hide Centimeter.
	MM = 2004,			///< Bool Hide Millimeter.
	MICRO = 2005,		///< Bool Hide Micrometer.
	NM = 2006,			///< Bool Hide Nanometer.
	MILE = 2007,		///< Bool Hide Mile.
	YARD = 2008,		///< Bool Hide Yard.
	FOOT = 2009,		///< Bool Hide Foot.
	INCH = 2010			///< Bool Hide Inch.
};
/// @}

//----------------------------------------------------------------------------------------
/// Unit scale custom GUI (@ref CUSTOMGUI_UNITSCALE) for UnitScaleData.\n
/// Here are the settings: @enumerateEnum{UNITSCALE_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class UnitScaleCustomGui : public BaseCustomGui<CUSTOMGUI_UNITSCALE>
{
private:
	UnitScaleCustomGui();
	~UnitScaleCustomGui();
public:
	//----------------------------------------------------------------------------------------
	/// Sets the unit scale value.
	/// @param[in] data								The new value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetValue(const UnitScaleData *data);

	//----------------------------------------------------------------------------------------
	/// Retrieves the unit scale value.
	/// @param[out] data							Filled with the value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetValue(UnitScaleData *data) const;
};

//----------------------------------------------------------------------------------------
/// Unit scale custom data type (@ref CUSTOMDATATYPE_UNITSCALE) for UnitScaleCustomGui.\n
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class UnitScaleData : public CustomDataType
{
private:
	UnitScaleData();
	~UnitScaleData();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{unit scale data}
	/// @return												@allocReturn{unit scale data}
	//----------------------------------------------------------------------------------------
	static UnitScaleData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{unit scale data}
	/// @param[in,out] data						@theToDestruct{unit scale data}
	//----------------------------------------------------------------------------------------
	static void Free(UnitScaleData *&data);

	/// @}

	/// @name Unit/Scale
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the values for the unit scale data.
	/// @param[in] scale							The unit scale.
	/// @param[in] unit								The unit.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetUnitScale(Float scale, DOCUMENT_UNIT unit);

	//----------------------------------------------------------------------------------------
	/// Gets the values of the unit scale data.
	/// @param[out] scale							Assigned the unit scale.
	/// @param[out] unit							Assigned the unit.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetUnitScale(Float &scale, DOCUMENT_UNIT &unit) const;

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if the unit scale data are equal.
	/// @param[in] b									A unit scale data.
	/// @return												@trueIfOtherwiseFalse{the unit scale data are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const UnitScaleData& b) const;

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if the unit scale data are different.
	/// @param[in] b									A unit scale data.
	/// @return												@trueIfOtherwiseFalse{the unit scale data are different}
	//----------------------------------------------------------------------------------------
	Bool operator != (const UnitScaleData& b) const;

	/// @}
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iUnitScaleCustomGui : public iBaseCustomGui
	{
		iUnitScaleCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iUnitScaleData {};
#else
	class iUnitScaleCustomGui;
	class iUnitScaleData;
#endif

struct UnitScaleCustomGuiLib : public BaseCustomGuiLib
{
	Bool						(iUnitScaleCustomGui::*SetValue)(const UnitScaleData *data);
	Bool						(iUnitScaleCustomGui::*GetValue)(UnitScaleData *data) const;
	Bool						(iUnitScaleData::*SetUnitScale)(Float scale, DOCUMENT_UNIT unit);
	Bool						(iUnitScaleData::*GetUnitScale)(Float &scale, DOCUMENT_UNIT &unit) const;
	Bool						(iUnitScaleData::*UnitScaleEqual)(const iUnitScaleData &b) const;
	UnitScaleData*	(*iUnitScaleData_Alloc)();
	void						(*iUnitScaleData_Free)(UnitScaleData *&data);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_UNITSCALE_H__
