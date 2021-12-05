/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_HYPERLINK_H__
#define CUSTOMGUI_HYPERLINK_H__

#ifdef _INTERNAL_HYPERLINK_STATIC_
	#define _INTERNAL_BASECUSTOM_
#endif

#include "customgui_base.h"
#include "c4d_customguidata.h"
#include "c4d_basecontainer.h"
#include "c4d_customdatatype.h"

/// Hyper link custom GUI ID.
#define CUSTOMGUI_HYPER_LINK_STATIC				1009180

/// Hyper link data type ID.
#define CUSTOMDATATYPE_HYPER_LINK_STATIC	1009617

/// @addtogroup HYPERLINK_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define HYPERLINK_LINK_TEXT			'hllt'			///< String the static text.
#define HYPERLINK_LINK_DEST			'hlld'			///< String Link destination.
#define HYPERLINK_IS_LINK				'hlil'			///< ::Bool @formatConstant{true} for hyperlinks, static text otherwise.
#define HYPERLINK_ALIGN_LEFT		'hlal'			///< ::Bool Align left.
#define HYPERLINK_ALIGN_RIGHT		'hlar'			///< ::Bool Align right.
#define HYPERLINK_NO_UNDERLINE	'hlnl'			///< ::Bool No underline.
/// @}

//----------------------------------------------------------------------------------------
/// Hyper link custom data (@ref CUSTOMDATATYPE_HYPER_LINK_STATIC) for use with HyperLinkCustomGui.
//----------------------------------------------------------------------------------------
class HyperLinkData : public CustomDataType
{
private:
	HyperLinkData();
	~HyperLinkData();

public:
	//----------------------------------------------------------------------------------------
	/// Sets the strings.
	/// @param[in] pStrLink						The new link string or @formatConstant{nullptr}.
	/// @param[in] pStrText						The new text string or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	void SetStrings(const maxon::String* pStrLink, const maxon::String* pStrText);

	//----------------------------------------------------------------------------------------
	/// Gets the strings.
	/// @param[out] pStrLink					Assigned the text string if not @formatConstant{nullptr}.
	/// @param[out] pStrText					Assigned the link string if not @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	void GetStrings(maxon::String* pStrLink, maxon::String* pStrText);
};

//----------------------------------------------------------------------------------------
/// Hyper link custom GUI (@ref CUSTOMGUI_HYPER_LINK_STATIC) for use with HyperLinkData.\n
/// Here are the settings: @enumerateEnum{HYPERLINK_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class HyperLinkCustomGui : public BaseCustomGui<CUSTOMGUI_HYPER_LINK_STATIC>
{
	private:
		HyperLinkCustomGui();
		~HyperLinkCustomGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Sets the strings.
		/// @param[in] pStrLink						The new link string or @formatConstant{nullptr}.
		/// @param[in] pStrText						The new text string or @formatConstant{nullptr}.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetLinkString(const maxon::String* pStrLink, const maxon::String *pStrText);

	//----------------------------------------------------------------------------------------
	/// Gets the strings.
	/// @param[out] pStrLink					Assigned the text string if not @formatConstant{nullptr}.
	/// @param[out] pStrText					Assigned the link string if not @formatConstant{nullptr}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
		Bool GetLinkString(maxon::String* pStrLink, maxon::String *pStrText);

		//----------------------------------------------------------------------------------------
		/// @markPrivate Sets the strings but only redraw, no layout change.
		/// @param[out] pStrLink					Assigned the text string if not @formatConstant{nullptr}.
		/// @param[out] pStrText					Assigned the link string if not @formatConstant{nullptr}.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetLinkStringThreaded(const maxon::String* pStrLink, const maxon::String *pStrText);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_HYPERLINK_STATIC_
	class iHyperLinkCustomGui : public iBaseCustomGui
	{
		iHyperLinkCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iHyperLinkData;
#else
	class iHyperLinkCustomGui;
	class iHyperLinkData;
#endif

struct HyperLinkStaticLib : public BaseCustomGuiLib
{
	Bool		(iHyperLinkCustomGui::*SetLinkString)(const maxon::String* pStrLink, const maxon::String *pStrText);
	Bool		(iHyperLinkCustomGui::*GetLinkString)(maxon::String* pStrLink, maxon::String *pStrText);
	void		(iHyperLinkData::*SetStrings)(const maxon::String* pStrLink, const maxon::String* pStrText);
	void		(iHyperLinkData::*GetStrings)(maxon::String* pStrLink, maxon::String* pStrText);
	Bool		(iHyperLinkCustomGui::*SetLinkStringThreaded)(const maxon::String* pStrLink, const maxon::String *pStrText);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_HYPERLINK_H__
