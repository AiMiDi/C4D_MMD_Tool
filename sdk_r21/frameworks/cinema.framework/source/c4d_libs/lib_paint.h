/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_PAINT_H__
#define LIB_PAINT_H__

#include "c4d_library.h"
#include "c4d_memory.h"

/// @addtogroup group_paintlibrary Paint
/// @ingroup group_library
/// @{
/// @since R16

/// Paint library ID.
#define C4D_PAINT_LIBRARY_ID	1031402

//----------------------------------------------------------------------------------------
/// Functions to access Texture Views.
//----------------------------------------------------------------------------------------
struct PaintManager
{
	//----------------------------------------------------------------------------------------
	/// Gets the number of opened Texture Views.
	/// @return												The number of opened Texture Views.
	//----------------------------------------------------------------------------------------
	Int32 GetViewCount();

	//----------------------------------------------------------------------------------------
	/// Gets the array of unique Texture View IDs.
	/// @return												The array of Texture View IDs.
	//----------------------------------------------------------------------------------------
	maxon::BaseArray<Int32>* GetViewIds();

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the Texture View that currently has focus (if any).
	/// @return												The ID of the Texture View which has focus, NOTOK if none found.
	//----------------------------------------------------------------------------------------
	Int32 GetActiveViewId();

	//----------------------------------------------------------------------------------------
	/// Removes focus from Texture View which currently has focus.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ResetActiveView();

	//----------------------------------------------------------------------------------------
	/// Gets the flag indicating if the Texture View in focus updates with selection changes.
	/// @return												@trueIfOtherwiseFalse{context updates are enabled}
	//----------------------------------------------------------------------------------------
	Bool GetAllowSelectUpdate();

	//----------------------------------------------------------------------------------------
	/// Sets the flag indicating if the Texture View in focus updates with selection changes.
	/// @param[in] _allowSelectUpdate	Pass @formatConstant{true} to enable context updates.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetAllowSelectUpdate(Bool _allowSelectUpdate);
};

//----------------------------------------------------------------------------------------
/// Represents a Texture View.
//----------------------------------------------------------------------------------------
class PaintView
{
private:
	PaintView();
	~PaintView();

public:

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{PaintView instances}
	/// @param[in] p									@theToDestruct{PaintView instance}
	//----------------------------------------------------------------------------------------
	static void Free(PaintView *&p);

	//----------------------------------------------------------------------------------------
	/// Gets the "UV Mesh > Show UV Mesh" option status for the view.
	/// @param[out] showMesh					Assigned @trueIfOtherwiseFalse{enabled}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetShowMesh(Bool& showMesh);

	//----------------------------------------------------------------------------------------
	/// Sets the "UV Mesh > Show UV Mesh" option status for the view.
	/// @param[in] showMesh						@formatConstant{true} to enable the option.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetShowMesh(Bool showMesh);

	//----------------------------------------------------------------------------------------
	/// Updates the view context with the current selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetContextFromSelection();

	//----------------------------------------------------------------------------------------
	/// Applies the "View > Fit to Screen" feature.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FitToScreen();
};

class iPaintManager;
class iPaintView;

//----------------------------------------------------------------------------------------
/// Gets the current paint manager.
/// @return												The current paint manager.
//----------------------------------------------------------------------------------------
PaintManager* GetPaintManager();

//----------------------------------------------------------------------------------------
/// Gets a paint view.
/// @param[in] paintManager				The paint manager to get the view for.
/// @param[in] viewId							The paint view ID.
/// @return												The paint view. See PaintManager::GetViewIds and PaintManager::GetActiveViewId.
//----------------------------------------------------------------------------------------
PaintView* GetPaintView(PaintManager* paintManager, Int32 viewId);

//----------------------------------------------------------------------------------------
/// Paint Settings for @BP3D channels.
//----------------------------------------------------------------------------------------
class BPPaintSettings
{
public:

private:
	BPPaintSettings();
	~BPPaintSettings();
};

//----------------------------------------------------------------------------------------
/// Color settings.
//----------------------------------------------------------------------------------------
class BPSingleColorSettings : public BPPaintSettings
{
public:

	//----------------------------------------------------------------------------------------
	/// Sets the RGB color and intensity value for the color. The intensity value is internally multiplied against the RGB value.\n
	/// An RGB value of @em (0.5,0.5,0.5) is Grey. If the RGB value is @em (1.0,1.0,1.0) and the intensity value is @em 0.5 then the resulting color is Grey @em (0.5,0.5,0.5).
	/// @param[in] rgb								The RGB color.
	/// @param[in] i									The intensity value.
	//----------------------------------------------------------------------------------------
	void SetRGB(const Vector &rgb, Float i);

	//----------------------------------------------------------------------------------------
	/// Gets the RGB color and intensity value for the color. The intensity value is internally multiplied against the RGB value.\n
	/// An RGB value of @em (0.5,0.5,0.5) is Grey. If the RGB value is @em (1.0,1.0,1.0) and the intensity value is 0.5 then the resulting color is Grey @em (0.5,0.5,0.5).
	/// @param[out] rgb								The RGB color.
	/// @param[out] i									The intensity value.
	//----------------------------------------------------------------------------------------
	void GetRGB(Vector &rgb, Float &i);

private:
	BPSingleColorSettings();
	~BPSingleColorSettings();
};


//----------------------------------------------------------------------------------------
/// Color Settings for a @BP3D channel.
//----------------------------------------------------------------------------------------
class BPColorSettings : public BPPaintSettings
{
public:

	//----------------------------------------------------------------------------------------
	/// Gets the color settings for a specific channel.
	/// @param[in] channelid					The ID of the channel to retrieve the color information for e.g. @ref CHANNEL_COLOR.
	/// @return												The color settings.
	//----------------------------------------------------------------------------------------
	BPSingleColorSettings *GetChannel(Int32 channelid);

private:
	BPColorSettings();
	~BPColorSettings();
};


//----------------------------------------------------------------------------------------
/// Functions to get access to the selected @BP3D channel color settings.
//----------------------------------------------------------------------------------------
struct BPColorSettingsHelpers
{
	//----------------------------------------------------------------------------------------
	/// Gets the color settings, for the foreground or background color, of a @BP3D Channel.
	/// @param[in] bg									Pass @formatConstant{true} to get the background color settings or @formatConstant{false} for the foreground color settings.
	/// @return												The color settings for the global background or foreground.
	//----------------------------------------------------------------------------------------
	static BPColorSettings *GetColorSettings(Bool bg);

	//----------------------------------------------------------------------------------------
	/// Gets the settings, for the foreground or background color, of a specific @BP3D Channel.
	/// @param[in] bg									Pass @formatConstant{true} to get the background color settings or @formatConstant{false} for the foreground color settings.
	/// @param[in] channelid					The channel to get the color settings for e.g. @ref CHANNEL_COLOR.
	/// @return												The color settings for the global background or foreground.
	//----------------------------------------------------------------------------------------
	static BPSingleColorSettings *GetChannelColorSettings(Bool bg, Int32 channelid);

	//----------------------------------------------------------------------------------------
	/// Gets the settings for the currently selected channel in @BP3D. If GetMultiMode() is on and there are multiple channels selected then it is possible to specify the channel.
	/// @param[in] bg									Pass @formatConstant{true} to get the background color settings or @formatConstant{false} for the foreground color settings.\n
	/// 															Special exception, set to @ref NOTOK to use the selected background color.
	/// @param[in] channelid					The specific channel to get the color settings for, e.g. @ref CHANNEL_COLOR, if GetMultiMode() is enabled and there are multiple channels selected.
	/// @return												The color settings for the global background or foreground.
	//----------------------------------------------------------------------------------------
	static BPSingleColorSettings *GetSelectedSingleColorSettings(Bool bg, Int32 *channelid = nullptr);

	//----------------------------------------------------------------------------------------
	/// Sets which channel is selected.
	/// @param[in] bg									Pass @formatConstant{true} to get the background color settings or @formatConstant{false} for the foreground color settings.\n
	/// 															Special exception, set to @ref NOTOK to use the selected background color.
	/// @param[in] channelid					The specific channel to get the color settings for, e.g. @ref CHANNEL_COLOR.
	//----------------------------------------------------------------------------------------
	static void SetSelectedColorSettings(Bool bg, Int32 channelid);

	//----------------------------------------------------------------------------------------
	/// Gets which channel is selected/enabled. If GetMultiMode() is on then multiple channels could be enabled for painting.
	/// @param[in] channelid					The ID of the channel e.g. @ref CHANNEL_COLOR.
	/// @return												@trueIfOtherwiseFalse{the channel is enabled}
	//----------------------------------------------------------------------------------------
	static Bool GetGlobalChannelEnabling(Int32 channelid);

	//----------------------------------------------------------------------------------------
	/// Sets which channel is selected/enabled. If GetMultiMode() is @formatConstant{true} then it is possible to enable multiple channels for painting.
	/// @param[in] channelid					The ID of the channel to enable e.g. @ref CHANNEL_COLOR.
	/// @param[in] enable							Pass @formatConstant{true} to enable the channel or @formatConstant{false} to disable it.
	//----------------------------------------------------------------------------------------
	static void SetGlobalChannelEnabling(Int32 channelid, Bool enable);

	//----------------------------------------------------------------------------------------
	/// If GetMultiMode() is enabled then multiple channels can be selected/enabled in @BP3D.
	/// @return												The state of the MultiMode switch.
	//----------------------------------------------------------------------------------------
	static Bool GetMultiMode();

	//----------------------------------------------------------------------------------------
	/// Sets the state of the MultiMode switch in @BP3D. If GetMultiMode() is enabled then multiple channels can be selected/enabled in @BP3D.
	/// @param[in] multi							Pass @formatConstant{true} to enable or @formatConstant{false} to disable the MultiMode switch.
	//----------------------------------------------------------------------------------------
	static void SetMultiMode(Bool multi);

	//----------------------------------------------------------------------------------------
	/// Toggles the Foreground and Background colors.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool ToggleFgBg(void);

	//----------------------------------------------------------------------------------------
	/// Gets the active color preset.
	/// @return												The paint settings for the color preset.
	//----------------------------------------------------------------------------------------
	static BPPaintSettings *GetActiveColorPreset();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static void SetActiveColorPreset(BPPaintSettings *set);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static Bool SaveColorSettings(BPPaintSettings *set);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static Bool DefineColorPreset(PaintTexture *tex, PaintLayerBmp *layer, PaintLayerBmp *mask, BPSingleColorSettings *color, Bool wallpaper);
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct PaintLibrary : public C4DLibrary
{
	PaintManager*							(*GetPaintManager)();
	PaintView*								(*GetPaintView)(PaintManager* paintManager, Int32 viewId);

	// iPaintManager methods
	Int32											(iPaintManager::*GetViewCount)();
	maxon::BaseArray<Int32>*	(iPaintManager::*GetViewIds)();
	Int32											(iPaintManager::*GetActiveViewId)();
	Bool											(iPaintManager::*ResetActiveView)();
	Bool											(iPaintManager::*GetAllowSelectUpdate)();
	Bool											(iPaintManager::*SetAllowSelectUpdate)(Bool _allowSelectUpdate);

	// iPaintView methods
	void											(*Free)(iPaintView *&p);
	Bool											(iPaintView::*GetShowMesh)(Bool &showMesh);
	Bool											(iPaintView::*SetShowMesh)(Bool showMesh);
	Bool											(iPaintView::*SetContextFromSelection)();
	Bool											(iPaintView::*FitToScreen)();

	// BPSingleColorSettings
	void											(*bpsinglecolorsettingsSetRGB)(BPSingleColorSettings *settings, const Vector &rgb, Float i);
	void											(*bpsinglecolorsettingsGetRGB)(BPSingleColorSettings *settings, Vector &v, Float &h);

	// BPColorSettings
	BPSingleColorSettings*		(*bpcolorsettingsGetChannel)(BPColorSettings* settings, Int32 channelid);

	// BPColorSettingsHelpers
	BPColorSettings*					(*bpcolorsettingshelpersGetColorSettings)(Bool bg);
	BPSingleColorSettings*		(*bpcolorsettingshelpersGetChannelColorSettings)(Bool bg, Int32 channelid);
	BPSingleColorSettings*		(*bpcolorsettingshelpersGetSelectedSingleColorSettings)(Int32 bg, Int32 *channelid);
	void											(*bpcolorsettingshelpersSetSelectedColorSettings)(Bool bg, Int32 channelid);
	Bool											(*bpcolorsettingshelpersGetGlobalChannelEnabling)(Int32 channelid);
	void											(*bpcolorsettingshelpersSetGlobalChannelEnabling)(Int32 channelid, Bool enable);
	Bool											(*bpcolorsettingshelpersGetMultiMode)(void);
	void											(*bpcolorsettingshelpersSetMultiMode)(Bool multi);
	Bool											(*bpcolorsettingshelpersToggleFgBg)(void);
	BPPaintSettings*					(*bpcolorsettingshelpersGetActiveColorPreset)();
	void											(*bpcolorsettingshelpersSetActiveColorPreset)(BPPaintSettings *set);
	Bool											(*bpcolorsettingshelpersSaveColorSettings)(BPPaintSettings *set);
	Bool											(*bpcolorsettingshelpersDefineColorPreset)(PaintTexture *tex, PaintLayerBmp *layer, PaintLayerBmp *mask, BPSingleColorSettings *color, Bool wallpaper);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_PAINT_H__
