/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_BASE_H__
#define CUSTOMGUI_BASE_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_baseplugin.h"

struct BaseCustomGuiLib;

/// @defgroup CUSTOMGUISETTINGS Custom GUI Settings

/// @addtogroup BASE_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
/// The general settings for a custom GUI.
#define CUSTOMGUI_LAYOUTMODE					'laym'			///< ::Int32 The layout mode: @enumerateEnum{LAYOUTMODE}
#define CUSTOMGUI_DEFAULTEDITHEIGHT		'defh'			///< ::Int32 Default edit height.
#define CUSTOMGUI_SAVEDLAYOUTDATA			'slda'			///< BaseContainer Saved layout data.
/// @}

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class _BaseCustomGui
{
	private:
		_BaseCustomGui();
		~_BaseCustomGui();

	public:

		Int32 GetWidth(Int32 plugid);
		Int32 GetHeight(Int32 plugid);
		void Redraw(Int32 plugid);
		Bool LayoutChanged(Int32 plugid);
		Bool Activate(Int32 plugid);
		Bool SetDefaultForResEdit(Int32 plugid);
		Bool SetData(Int32 plugid, const TriState<GeData> &tristate);
		TriState<GeData> GetData(Int32 plugid);
		void SetLayoutMode(Int32 plugid, Int32 mode);
		Int32 GetLayoutMode(Int32 plugid);
		Bool SupportLayoutSwitch(Int32 plugid);
};

//----------------------------------------------------------------------------------------
/// The base class for custom GUIs.
//----------------------------------------------------------------------------------------
template <Int32 plugid> class BaseCustomGui : public _BaseCustomGui
{
	private:
		BaseCustomGui();
		~BaseCustomGui();

	public:

		//----------------------------------------------------------------------------------------
		/// Retrieves the width of the custom GUI in pixels.
		/// @return												The width.
		//----------------------------------------------------------------------------------------
		Int32 GetWidth() { return _BaseCustomGui::GetWidth(plugid); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the height of the custom GUI in pixels.
		/// @return												The height.
		//----------------------------------------------------------------------------------------
		Int32 GetHeight() { return _BaseCustomGui::GetHeight(plugid); }

		//----------------------------------------------------------------------------------------
		/// Redraws the custom GUI.
		//----------------------------------------------------------------------------------------
		void Redraw() { _BaseCustomGui::Redraw(plugid); }

		//----------------------------------------------------------------------------------------
		/// Tells the custom GUI that the layout has changed.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool LayoutChanged() { return _BaseCustomGui::LayoutChanged(plugid); }

		//----------------------------------------------------------------------------------------
		/// Activates the custom GUI.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Activate() { return _BaseCustomGui::Activate(plugid); }

		//----------------------------------------------------------------------------------------
		/// Sets the custom GUI to the resource editor defaults.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetDefaultForResEdit() { return _BaseCustomGui::SetDefaultForResEdit(plugid); }

		//----------------------------------------------------------------------------------------
		/// Sets the custom GUI data.
		/// @param[in] tristate						The new data.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetData(const TriState<GeData> &tristate) { return _BaseCustomGui::SetData(plugid, tristate); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the custom GUI data.
		/// @return												The current data.
		//----------------------------------------------------------------------------------------
		TriState<GeData> GetData() { return _BaseCustomGui::GetData(plugid); }

		//----------------------------------------------------------------------------------------
		/// Sets the layout @formatParam{mode}.
		/// @param[in] mode								The new layout mode: @enumerateEnum{LAYOUTMODE}
		//----------------------------------------------------------------------------------------
		void SetLayoutMode(Int32 mode) { _BaseCustomGui::SetLayoutMode(plugid, mode); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the layout mode.
		/// @return												The current layout mode: @enumerateEnum{LAYOUTMODE}
		//----------------------------------------------------------------------------------------
		Int32 GetLayoutMode() { return _BaseCustomGui::GetLayoutMode(plugid); }

		//----------------------------------------------------------------------------------------
		/// Checks if the custom GUI supports layout switching.
		/// @return												@trueIfOtherwiseFalse{the layout switch is supported}
		//----------------------------------------------------------------------------------------
		Bool SupportLayoutSwitch() { return _BaseCustomGui::SupportLayoutSwitch(plugid);	}
};

//----------------------------------------------------------------------------------------
/// Fills the custom GUI library structure @formatParam{lib} with the default implementations.
/// @see CustomGuiData.
/// @param[in] lib								The custom GUI library structure to fill.
//----------------------------------------------------------------------------------------
void FillBaseCustomGui(BaseCustomGuiLib &lib);

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_BASECUSTOM_
	class iBaseCustomGui : public iCustomGui
	{
		public:
			iBaseCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iCustomGui(settings, plugin) { }
			virtual Bool SetObjects(const AtomArray &ar);
	};
#else
	class iBaseCustomGui : public iCustomGui
	{
		public:
			iBaseCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iCustomGui(settings, plugin) { }
			virtual Bool SetObjects(const AtomArray &ar);
	};
#endif

struct BaseCustomGuiLib : public C4DLibrary
{
	void							(iBaseCustomGui::*Redraw							)();
	Bool							(iBaseCustomGui::*LayoutChanged				)();
	Int32							(iBaseCustomGui::*GetWidth						)();
	Int32							(iBaseCustomGui::*GetHeight						)();
	Bool							(iBaseCustomGui::*Activate						)();
	Bool							(iBaseCustomGui::*SetDefaultForResEdit)();
	Bool							(iBaseCustomGui::*SetData							)(const TriState<GeData> &tristate);
	TriState<GeData>	(iBaseCustomGui::*GetData							)();
	void							(iBaseCustomGui::*SetLayoutMode				)(Int32 mode);
	Int32							(iBaseCustomGui::*GetLayoutMode)			();
	Bool							(iBaseCustomGui::*SupportLayoutSwitch	)();
	Bool							(iBaseCustomGui::*SetObjects)					(const AtomArray &ar);

	void* reserved[(32-12)*C4DPL_MEMBERMULTIPLIER];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_BASE_H__
