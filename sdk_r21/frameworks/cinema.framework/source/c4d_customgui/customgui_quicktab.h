/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_QUICKTAB_H__
#define CUSTOMGUI_QUICKTAB_H__

#ifdef _INTERNAL_QUICKTAB_
	#define _INTERNAL_BASECUSTOM_
#endif

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Quicktab custom GUI ID.
#define CUSTOMGUI_QUICKTAB				1000495

/// @addtogroup QUICKTAB_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define QUICKTAB_BAR							C4D_FOUR_BYTE(0,'b','a','r')	///< ::Int32 Bar mode (0=off, 1=on, 2=non-bold). Set @formatConstant{true} for group title bars.
#define QUICKTAB_BARTITLE					'btit'			///< String Title for bar mode.
#define QUICKTAB_SHOWSINGLE				'ssgl'			///< ::Bool Show single items.
#define QUICKTAB_SPRINGINGFOLDERS	'sprn'			///< ::Bool Allow springing folders (activate quicktabs on drag and drop).
#define QUICKTAB_SEPARATOR				'sepa'			///< ::Bool Draw separator.
#define QUICKTAB_BARSUBGROUP			'subg'			///< ::Bool Handle as subgroup. Like bar mode, but with fold arrow icon. Implies @ref QUICKTAB_BAR. Call @link QuickTabCustomGui::IsSelected@endlink(0) to get fold state.
#define QUICKTAB_BARLAYERCOLOR		'lycl'			///< ::Bool Show layer color.
#define QUICKTAB_NOLINEBREAK			'nobk'			///< ::Bool No line break for tabs inside scroll groups.
#define QUICKTAB_BGCOLOR					'bgco'			///< ::Vector or ::Int32 Color RGB or ID.
#define QUICKTAB_NOMULTISELECT		'noml'			///< ::Bool No multiple tab selection.
#define QUICKTAB_ALTERNATIVECOLOR 'altc'			///< ::Int32 Use an alternative color (color ID from color preferences).
/// @}

//----------------------------------------------------------------------------------------
/// Quicktab custom GUI (@ref CUSTOMGUI_QUICKTAB).\n
/// Here are the settings: @enumerateEnum{QUICKTAB_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class QuickTabCustomGui : public BaseCustomGui<CUSTOMGUI_QUICKTAB>
{
		QuickTabCustomGui();
		~QuickTabCustomGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Removes all the strings/tabs.
		//----------------------------------------------------------------------------------------
		void ClearStrings();

		//----------------------------------------------------------------------------------------
		/// Appends a string/tab.
		/// @param[in] id									The string ID.
		/// @param[in] str								The string to append.
		/// @param[in] checked						The initial selection state.
		//----------------------------------------------------------------------------------------
		void AppendString(Int32 id, const maxon::String &str, Bool checked);

		//----------------------------------------------------------------------------------------
		/// Call this after appending strings/tabs.
		//----------------------------------------------------------------------------------------
		void DoLayoutChange();

		//----------------------------------------------------------------------------------------
		/// Checks if a string/tab is selected.
		/// @param[in] id									The string ID.
		/// @return												@trueIfOtherwiseFalse{string @formatParam{id} is selected}
		//----------------------------------------------------------------------------------------
		Bool IsSelected(Int32 id);

		//----------------------------------------------------------------------------------------
		/// Sets the text color of string @formatParam{id}.
		/// @param[in] id									The string ID.
		/// @param[in] col								The color. See @em c4d_colors.h.
		//----------------------------------------------------------------------------------------
		void SetTextColor(Int32 id, Int32 col);

		//----------------------------------------------------------------------------------------
		/// Sets the selected state text color of string @formatParam{id}.
		/// @since R19
		/// @param[in] id									The string ID.
		/// @param[in] col								The color. See @em c4d_colors.h.
		//----------------------------------------------------------------------------------------
		void SetTextColorSelected(Int32 id, Int32 col);

		//----------------------------------------------------------------------------------------
		/// Sets the selected state background color of string @formatParam{id}.
		/// @since R19
		/// @param[in] id									The string ID.
		/// @param[in] col								The color. See @em c4d_colors.h.
		//----------------------------------------------------------------------------------------
		void SetBackgroundColorSelected(Int32 id, Int32 col);

		//----------------------------------------------------------------------------------------
		/// Sets the layer color of string @formatParam{id}.
		/// @param[in] id									The string ID.
		/// @param[in] show								@formatConstant{true} to show the layer color.
		/// @param[in] col								The color. See c4d_colors.h.
		//----------------------------------------------------------------------------------------
		void SetLayerColor(Int32 id, Bool show, const Vector &col);

		//----------------------------------------------------------------------------------------
		/// Changes the selection state of string @formatParam{id}.
		/// @param[in] id									The string ID.
		/// @param[in] b									The new selection state.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Select(Int32 id, Bool b);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_QUICKTAB_
	class iQuickTabCustomGui : public iBaseCustomGui
	{
		iQuickTabCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iQuickTabCustomGui;
#endif

struct QuickTabLib : public BaseCustomGuiLib
{
	void		(iQuickTabCustomGui::*ClearStrings									)();
	void		(iQuickTabCustomGui::*AppendString									)(Int32 id, const maxon::String &str, Bool checked);
	void		(iQuickTabCustomGui::*DoLayoutChange								)();
	Bool		(iQuickTabCustomGui::*IsSelected										)(Int32 id);
	void		(iQuickTabCustomGui::*SetTextColor									)(Int32 id, Int32 col);
	Bool		(iQuickTabCustomGui::*Select												)(Int32 id, Bool b);
	void		(iQuickTabCustomGui::*SetLayerColor)(Int32 id, Bool show, const Vector &col);
	void		(iQuickTabCustomGui::*SetTextColorSelected)(Int32 id, Int32 col);
	void		(iQuickTabCustomGui::*SetBackgroundColorSelected)(Int32 id, Int32 col);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_QUICKTAB_H__
