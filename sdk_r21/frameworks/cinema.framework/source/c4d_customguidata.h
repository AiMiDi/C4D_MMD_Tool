/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CUSTOMGUIDATA_H__
#define C4D_CUSTOMGUIDATA_H__

#include "c4d_basedata.h"

class String;
class BaseContainer;
class BaseDocument;
class BaseBitmap;
struct CUSTOMGUIPLUGIN;

class CDialog;

/// @addtogroup CUSTOMGUI_SUPPORT
/// @ingroup group_enumeration
/// @{
#define CUSTOMGUI_SUPPORT_LAYOUTSWITCH	(1 << 0)		///< Supports layout switching.
#define CUSTOMGUI_SUPPORT_LAYOUTDATA		(1 << 1)		///< Supports layout data. If set, the custom GUI saves and restores data to a BaseContainer when the GUI is rebuilt.\n
																										///< For example imagine the following: the user adds a gradient needle. The number of GUI elements changes (sub-descriptions are shown) and the dialog needs to be rebuilt.\n
																										///< In order that the GUI does not lose its settings (e.g. which needle was active etc.) it can store its data to a BaseContainer under its description ID.\n
																										///< Some excerpts from the gradient custom GUI:
																										/// @code
																										/// iGradientCustomGui::iGradientCustomGui(const BaseContainer &settings,CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings,plugin)
																										/// {
																										/// 	Bool col = settings.GetBool(GRADIENTPROPERTY_ALPHA_WITH_COLOR);
																										/// 	Bool alpha = settings.GetBool(GRADIENTPROPERTY_ALPHA);
																										///
																										/// 	editcolor = !settings.GetBool(GRADIENTPROPERTY_NOEDITCOLOR);
																										///
																										/// 	if (col && alpha)
																										/// 		area.mode=GRADIENTMODE_COLORALPHA;
																										/// 	else if (alpha)
																										/// 		area.mode=GRADIENTMODE_ALPHA;
																										/// 	else
																										/// 		area.mode=GRADIENTMODE_COLOR;
																										///
																										/// 	m_bIsTristate = false;
																										/// 	area.m_pParent = nullptr;
																										///
																										/// 	const BaseContainer *data = settings.GetContainerInstance(CUSTOMGUI_SAVEDLAYOUTDATA);
																										/// 	if (data)
																										/// 	{
																										/// 		area.editalpha			= data->GetInt32(1);
																										/// 		area.displayresult	= data->GetInt32(2);
																										/// 		area.active_knot		= data->GetInt32(3);
																										/// 		area.active_bias		= data->GetInt32(4);
																										/// 	}
																										/// }
																										///
																										/// Int32 iGradientCustomGui::Message(const BaseContainer &msg,BaseContainer &result)
																										/// {
																										/// 	switch (msg.GetId())
																										/// 	{
																										/// 		case BFM_GETCUSTOMGUILAYOUTDATA:
																										/// 		result = BaseContainer(1);
																										/// 		result.SetInt32(1,area.editalpha);
																										/// 		result.SetInt32(2,area.displayresult);
																										/// 		result.SetInt32(3,area.active_knot);
																										/// 		result.SetInt32(4,area.active_bias);
																										/// 		return true;
																										///
																										/// 	...
																										/// 	}
																										/// }
																										/// @endcode
#define CUSTOMGUI_DISALLOW_TAKESOVERRIDE	(1 << 2)	///< Disallows Takes override e.g. the GUI does not hold real data but just react to the node changes (e.g. %Material Preview). @since R17.032
/// @}

/// Calculates the size of arrays.
#define CUSTOMGUIARRAY_SIZE(A) (sizeof(A) / sizeof(A[0]))

/// @addtogroup CUSTOMTYPE
/// @ingroup group_enumeration
/// @{
enum class CUSTOMTYPE
{
	END,			///< End marker.
	FLAG,			///< Bool data. (Either the property is there or not.)
	LONG,			///< ::Int32 data.
	REAL,			///< ::Float data.
	STRING,		///< String data. (An ID from the string table.)
	VECTOR,		///< ::Vector data.

	HIDE_ID = (1 << 30)
} MAXON_ENUM_LIST(CUSTOMTYPE);
/// @}

/// Hides the property in the %User Data manager (e.g. compatibility option).
#define CUSTOMTYPE_HIDE_ID (1 << 30)

//----------------------------------------------------------------------------------------
/// A resource file property.\n
/// Usually used in an array like:
/// @code
/// CustomProperty g_LinkBoxProps[] =
/// {
/// 	{ CUSTOMTYPE::FLAG, LINKBOX_HIDE_ICON, "HIDE_ICON" },
/// 	{ CUSTOMTYPE::END, 0, "" }
/// };
/// @endcode
/// @note Such arrays must be terminated with a @ref CUSTOMTYPE::END entry.
//----------------------------------------------------------------------------------------
struct CustomProperty
{
	CUSTOMTYPE	type;			///< The entry type: @enumerateEnum{CUSTOMTYPE}
	Int32				id;				///< The custom property ID.\n
												///< Use @ref CUSTOMTYPE::HIDE_ID to hide this property in the AM %User Data manager (e.g. compatibility option).
	const Char*	ident;		///< The string identifier.
};

//----------------------------------------------------------------------------------------
/// A data class for creating custom GUIs for data types. These can be used in descriptions for the Attribute Manager.\n
/// Use RegisterCustomGuiPlugin() to register the custom GUI plugin.
/// @note Even if a library is not created it is needed to call InstallLibrary() for a dummy library during registration:
/// @code
/// Bool RegisterExampleDataTypeGui(void)
/// {
/// 	static BaseCustomGuiLib mylib;
/// 	ClearMem(&mylib, sizeof(mylib));
/// 	FillBaseCustomGui(mylib);
/// 	if (!InstallLibrary(MYCUSTOMGUI_ID, &mylib, 1000, sizeof(mylib)))
/// 		return false;
///
/// 	return RegisterCustomGuiPlugin("My Custom GUI", 0, NewObj(MyCustomGui));
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class CustomGuiData : public BaseData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID of the custom GUI.
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetId() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to allocate a sub-dialog for the custom GUI.\n
	/// Normally this method override should look like this:
	/// @code
	/// virtual CDialog* Alloc(const BaseContainer& settings)
	/// {
	/// 	T* dlg = NewObj(T(settings, GetPlugin()));
	/// 	if (!dlg)
	/// 		return nullptr;
	///
	/// 	CDialog *cdlg = dlg->Get();
	/// 	if (!cdlg)
	/// 		return nullptr;
	///
	/// 	return cdlg;
	/// }
	/// @endcode
	/// In the above code @c T stands for a type derived from iCustomGui.
	/// @param[in] settings						The settings for the GUI. (Using the IDs defined by GetProperties().)
	/// @return												The allocated sub-dialog.
	//----------------------------------------------------------------------------------------
	virtual CDialog* Alloc(const BaseContainer& settings) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to free sub-dialogs allocated by Alloc().\n
	/// Normally this method override should look like this:
	/// @code
	/// virtual void Free(CDialog *dlg, void *userdata)
	/// {
	/// 	if (!dlg || !userdata)
	/// 		return;
	/// 	T* sub = static_cast<T*>(userdata);
	/// 	DeleteObj(sub);
	/// }
	/// @endcode
	/// In the above code @c T stands for a type derived from iCustomGui.
	/// @param[in,out] dlg						The sub-dialog to free.
	/// @param[in] userdata						The user data.
	//----------------------------------------------------------------------------------------
	virtual void Free(CDialog* dlg, void* userdata) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the symbol to use in resource files, for example @em "GRADIENT".
	/// @note Only 7-bit ASCII characters are allowed, hence the @em Char type.
	/// @return												A pointer to a global <tt>const Char*</tt> string with the resource symbol.
	//----------------------------------------------------------------------------------------
	virtual const Char* GetResourceSym() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the properties that the custom GUI accepts in resource files.
	/// @see CustomProperty.
	/// @return												A pointer to a global array of CustomProperty elements, ended with a @ref CUSTOMTYPE::END property:
	/// @code
	/// CustomProperty bitmapbuttonprops[] =
	/// {
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BORDER, "BORDER" },
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BUTTON, "BUTTON" },
	/// 	{ CUSTOMTYPE::END, 0, nullptr }
	/// };
	/// @endcode
	//----------------------------------------------------------------------------------------
	virtual CustomProperty* GetProperties();

	//----------------------------------------------------------------------------------------
	/// Called to return the IDs of compatible data types for the custom GUI.
	/// @see CustomDataTypeClass::GetConversionsFrom.
	/// @param[out] table							Set this to point to a global array with the IDs of compatible data types for the custom GUI.
	/// @return												The length of the array pointed by table, or @em 0 if @formatParam{table} has not been set.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetResourceDataType(Int32*& table);

	//----------------------------------------------------------------------------------------
	/// Gets the plugin structure for the custom GUI.
	/// @return												The custom GUI plugin structure. @cinemaOwnsPointed{plugin structure}
	//----------------------------------------------------------------------------------------
	CUSTOMGUIPLUGIN* GetPlugin();
};

//----------------------------------------------------------------------------------------
/// Registers a custom GUI plugin.
/// @note It is currently not possible to register a custom GUI for ::Bool or BaseTime.
/// @param[in] str								The name of the plugin.
/// @param[in] info								The custom GUI plugin info flags: @enumerateEnum{CUSTOMGUI_SUPPORT} @enumerateEnum{PLUGINFLAG}
/// @param[in] dat								An instance for the custom GUI plugin. @C4D takes over the ownership of the pointed data instance.
/// @return												@trueIfOtherwiseFalse{the custom GUI plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterCustomGuiPlugin(const maxon::String& str, Int32 info, CustomGuiData* dat);

#endif // C4D_CUSTOMGUIDATA_H__
