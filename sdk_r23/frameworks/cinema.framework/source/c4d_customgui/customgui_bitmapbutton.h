/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_BITMAPBUTTON_H__
#define CUSTOMGUI_BITMAPBUTTON_H__

#ifdef _INTERNAL_BITMAPBUTTON_
	#define _INTERNAL_BASECUSTOM_
#endif

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_customdatatype.h"
#include "lib_description.h"
#include "maxon/delegate.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// Bitmap button custom GUI ID.
#define CUSTOMGUI_BITMAPBUTTON			1000479

/// Bitmap button custom data ID.
#define CUSTOMDATATYPE_BITMAPBUTTON	1001053

/// @addtogroup BITMAPBUTTON_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define BITMAPBUTTON_BORDER								'brdr'			///< ::Int32 Border type: @enumerateEnum{BORDER}
																											///< @note Used for the pressed button state if ::BITMAPBUTTON_OUTBORDER is set.
#define BITMAPBUTTON_BUTTON								'butt'			///< ::Bool Clickable button.
																											///< @note To detect when the button is pressed in a description check if the ::DESCFLAGS_SET::USERINTERACTION flag is set in the NodeData::SetDParameter() call.
#define BITMAPBUTTON_TOGGLE								'togg'			///< ::Bool Toggle button, like a checkbox.
#define BITMAPBUTTON_IGNORE_BITMAP_WIDTH	'ignw'			///< ::Bool Ignore bitmap width.
#define BITMAPBUTTON_IGNORE_BITMAP_HEIGHT	'ignh'			///< ::Bool Ignore bitmap height.
#define BITMAPBUTTON_DRAWPOPUPBUTTON			'popu'			///< ::Bool Draw popup button.
#define BITMAPBUTTON_TOOLTIP							'ttip'			///< String Tooltip string.
																											///< @note Only work if @ref BITMAPBUTTON_BUTTON is @formatConstant{true}.\n
																											///< To format the bitmap's button tooltip text use the "<b>" and "<br>" HTML tags. This is used internally to format the tooltip text for the palettes buttons. For example:
																											///< @code
																											///  bc.SetString(BITMAPBUTTON_TOOLTIP, "<b>Bold Text</b><br>New line");
																											///  @endcode
#define BITMAPBUTTON_ICONID1							'ico1'			///< ::Int32 Registered icon bitmap ID. @em On state for toggle buttons.
#define BITMAPBUTTON_ICONID2							'ico2'			///< ::Int32 Registered icon bitmap ID. @em Off state for toggle buttons.
#define BITMAPBUTTON_FORCE_SIZE						'size'			///< ::Int32 Forces the width and height of the icon in pixels if value is greater than 0.
#define BITMAPBUTTON_FORCE_SIZE_Y					'sizy'			///< ::Int32 Additionally forces the y size of the bitmap button. FORCE_SIZE is used for y size when not specified.
#define BITMAPBUTTON_SPECIAL							'spec'			///< @markPrivate
#define BITMAPBUTTON_NOBORDERDRAW					'nbrd'			///< ::Bool Disable border drawing.
#define BITMAPBUTTON_OUTBORDER						'obrd'			///< ::Int32 Out border type: @enumerateEnum{BORDER}
																											///< @note Used if ::BITMAPBUTTON_BUTTON is set.
#define BITMAPBUTTON_BACKCOLOR						'bkcl'			///< ::Int32 Background color: @enumerateEnum{COLOR}
#define BITMAPBUTTON_MIRROR								'mirr'			///< ::Bool Mirror the button in an Arabic interface.
#define BITMAPBUTTON_STRING								'strg'			///< String Adds a string in bold font at left of the icon.
#define BITMAPBUTTON_DISABLE_FADING				'nofd'			///< Bool Disables the mouse over fadding effect.

/// @}

class BaseList2D;

//----------------------------------------------------------------------------------------
/// Bitmap button data type (@ref CUSTOMDATATYPE_BITMAPBUTTON) for BitmapButtonCustomGui.
/// @note Used to get a bitmap button in the Attribute Manager. Specify an object, @ref op, that provides an icon through the @ref MSG_DESCRIPTION_GETBITMAP message.
//----------------------------------------------------------------------------------------
class BitmapButtonStruct : public CustomDataType
{
	public:
		//----------------------------------------------------------------------------------------
		/// Default constructor.
		//----------------------------------------------------------------------------------------
		BitmapButtonStruct() { op = nullptr; dirty = reserved = 0; }

		//----------------------------------------------------------------------------------------
		/// Creates a bitmap button data.
		/// @param[in] t_op								The object to send ::MSG_DESCRIPTION_GETBITMAP to.
		/// @param[in] t_id								The ID for the DescriptionGetBitmap::id field.
		/// @param[in] t_dirty						The dirty flag. Internally used to detect changes. If this flag changes on parameter set, a new MSG_DESCRIPTION_GETBITMAP will be emitted.
		//----------------------------------------------------------------------------------------
		BitmapButtonStruct(BaseList2D *t_op, const DescID &t_id, Int32 t_dirty) { op = t_op; _id = t_id; dirty = t_dirty; reserved = 0; }

		BaseList2D *op;			///< The object to send ::MSG_DESCRIPTION_GETBITMAP to.
		DescID _id;					///< The ID for the DescriptionGetBitmap::id field.
		Int32 dirty;				///< The dirty flag. Not used by the implementation. Use this to know when the image needs to be updated.
		Int32 reserved;			///< @markInternal
};

//----------------------------------------------------------------------------------------
/// Callback for BitmapButtonCustomGui, registered with BitmapButtonCustomGui::SetCallback().
//----------------------------------------------------------------------------------------
struct BitmapButtonCallback
{

	BitmapButtonCallback& operator = (const BitmapButtonCallback& other)
	{
		data = other.data;
		ShowPopup = other.ShowPopup;
		delegate.CopyFrom(other.delegate) iferr_ignore("there can be no error handling here");
		return *this;
	}
	void* data = nullptr;			///< Custom data.

	//----------------------------------------------------------------------------------------
	/// Callback called when the user presses the bitmap button. Can be used to bring up a popup menu.
	//----------------------------------------------------------------------------------------
	void (*ShowPopup)(void* data) = nullptr;

	maxon::Delegate<void(void* data)> delegate;
};

//----------------------------------------------------------------------------------------
/// Bitmap button custom GUI (@ref CUSTOMGUI_BITMAPBUTTON).\n
/// Here are the settings: @enumerateEnum{BITMAPBUTTON_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class BitmapButtonCustomGui : public BaseCustomGui<CUSTOMGUI_BITMAPBUTTON>
{
	private:
		BitmapButtonCustomGui();
		~BitmapButtonCustomGui();

	public:
		/// @name Set Image
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the image from a BaseBitmap.
		/// @param[in] bmp								The bitmap image.
		/// @param[in] copybmp						If @formatConstant{true} the bitmap is copied. If @formatConstant{false}, the bitmap pointer is only assigned but caller is still the ownership of it, so it must make sure the bitmap is available during all the BitmapButtonCustomGui life.
		/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetImage(BaseBitmap *bmp, Bool copybmp, Bool secondstate = false);

		//----------------------------------------------------------------------------------------
		/// Sets the image from a Filename.
		/// @param[in] name								The filename for the image to load.
		/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetImage(const Filename &name, Bool secondstate = false);

		//----------------------------------------------------------------------------------------
		/// Sets the image from an IconData.
		/// @warning The icon bitmap is copied.
		/// @param[in] bmp								The icon data. @callerOwnsPointed{icon data}
		/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetImage(IconData *bmp, Bool secondstate = false);

		//----------------------------------------------------------------------------------------
		/// Sets the image from an icon ID.
		/// @warning The icon bitmap is copied.
		/// @param[in] icon_id						The icon ID.
		/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetImage(Int32 icon_id, Bool secondstate = false);

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the toggle state of the button.
		/// @param[in] set								The new toggle state.
		//----------------------------------------------------------------------------------------
		void SetToggleState(Bool set);

		//----------------------------------------------------------------------------------------
		/// Stores an atom array that can be dragged from the button by the user. This is only possible for non-button mode (::BITMAPBUTTON_BUTTON is @formatConstant{false}).
		/// @param[in] bl									The atom array to store. The array is not copied. @callerOwnsPointed{array}
		//----------------------------------------------------------------------------------------
		void SetDragArray(const AtomArray *bl);

		//----------------------------------------------------------------------------------------
		/// Registers a callback with the bitmap button. Called when the button is pressed.
		/// @param[in] cb									The callback to register.
		//----------------------------------------------------------------------------------------
		void SetCallback(const BitmapButtonCallback &cb);

		//----------------------------------------------------------------------------------------
		/// Sets the command ID for the bitmap button.
		/// @note Enables drag and drop of the command into tool bars and menu managers. Used e.g. in the Script Manager.
		/// @param[in] cmdid							The command ID.
		//----------------------------------------------------------------------------------------
		void SetCommandDragId(Int32 cmdid);

		//----------------------------------------------------------------------------------------
		/// Gets the maximum width of the user area that the Bitmap is being drawn into, allowing you to size the bitmap prior to setting.
		///
		/// @return												The maximum width.
		//----------------------------------------------------------------------------------------
		Int32 GetMaxWidth() const;
		/// @}
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_BITMAPBUTTON_
	class CINEWARE_SINGLEINHERITANCE iBitmapButtonCustomGui : public iBaseCustomGui
	{
		iBitmapButtonCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iBitmapButtonCustomGui;
#endif

struct BitmapButtonLib : public BaseCustomGuiLib
{
	Bool		(iBitmapButtonCustomGui::*SetImageA				)(BaseBitmap *bmp, Bool copybmp, Bool secondstate);
	Bool		(iBitmapButtonCustomGui::*SetImageB				)(const Filename &name, Bool secondstate);
	void		(iBitmapButtonCustomGui::*SetToggleState	)(Bool set);
	void		(iBitmapButtonCustomGui::*SetDragArray		)(const AtomArray *bl);
	void		(iBitmapButtonCustomGui::*SetCallback			)(const BitmapButtonCallback &cb);
	Bool		(iBitmapButtonCustomGui::*SetImageC				)(IconData *bmp, Bool secondstate);
	void		(iBitmapButtonCustomGui::*SetCommandDragId)(Int32 cmdid);
	Int32		(iBitmapButtonCustomGui::*GetMaxWidth)() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // CUSTOMGUI_BITMAPBUTTON_H__
