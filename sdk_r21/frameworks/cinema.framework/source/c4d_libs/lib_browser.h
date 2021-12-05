/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_BROWSER_H__
#define LIB_BROWSER_H__

#include "c4d_gui.h"
#ifndef __API_INTERN__
	#include "c4d_file.h"
	#include "c4d_baseplugin.h"
#else
	#include "ge_file.h"
	#include "c4d_baseplugin.h"
#endif
#include "c4d_library.h"

/// @addtogroup group_browserlibrary Browser
/// @ingroup group_library
/// @{

#ifndef BROWSERPLUGININTERFACE_H__
class iBrowser {};
class BrowserURL {};
class ReferenceObject {};
class RTreeNode {};
class BrowserContentNode {};
class BrowserPluginInterface {};
#else
class iBrowser;
class BrowserURL;
class ReferenceObject;
class RTreeNode;
class BrowserContentNode;
class BrowserPluginInterface;
#endif

class GvNode;

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserURL BrowserURL
#else
//----------------------------------------------------------------------------------------
/// Represents a browser URL for locations in the file system (and virtual places somewhere in the browser).\n
/// For URL strings the following applies:
/// - Set a file name as @em "file://localhost/...".
/// - Set a preset location as @em "preset:// * /..." where * is the catalog name.
/// - Set a catalog location as @em "catalog:// * /..." where * is the catalog name.
///
/// @see SDKBrowserBase for base paths constants.
//----------------------------------------------------------------------------------------
class SDKBrowserURL
{
private:
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy1);
	C4D_RESERVE_PRIVATE_TYPE(UInt32, dummy2);
	C4D_RESERVE_PRIVATE_TYPE(Filename, dummy3);
	C4D_RESERVE_PRIVATE_TYPE(String, dummy4);
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy5);
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy6);
	C4D_RESERVE_PRIVATE_TYPE(void*, dummy7);

public:
		/// @name Private
		/// @{

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void *GetPrivate(void) const;

		/// @}

		/// @name Constructor/Destructor
		/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor. Constructs a SDKBrowserURL.
	//----------------------------------------------------------------------------------------
	SDKBrowserURL();

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Constructs a SDKBrowserURL with the content of the source URL in @formatParam{src}.
	/// @param[in] src								A source URL.
	//----------------------------------------------------------------------------------------
	SDKBrowserURL(const SDKBrowserURL &src);

	//----------------------------------------------------------------------------------------
	/// Constructs a SDKBrowserURL with a file name.
	/// @param[in] src								A file name.
	//----------------------------------------------------------------------------------------
	SDKBrowserURL(const Filename &src);

	//----------------------------------------------------------------------------------------
	/// Constructs a SDKBrowserURL with a string.
	/// @param[in] src								A URL string, e.g. @em "file://localhost/image.jpg".
	//----------------------------------------------------------------------------------------
	SDKBrowserURL(const maxon::String &src);

	//----------------------------------------------------------------------------------------
	/// Destructor
	//----------------------------------------------------------------------------------------
	~SDKBrowserURL(void);

		/// @}

		/// @name Operator
		/// @{

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] cs									The right-hand URL to assign.
	/// @return												The assigned left-hand URL.
	//----------------------------------------------------------------------------------------
	const SDKBrowserURL &operator = (const SDKBrowserURL &cs);

	//----------------------------------------------------------------------------------------
	/// Concatenates a string to the path of the URL and return the result.
	/// @param[in] str2								The string to add.
	/// @return												The result of the addition.
	//----------------------------------------------------------------------------------------
	const SDKBrowserURL operator + (const String &str2) const;

	//----------------------------------------------------------------------------------------
	/// Concatenates a string to the path of the URL and keep the result in the URL.
	/// @param[in] str								The string to add.
	/// @return												The result of the addition.
	//----------------------------------------------------------------------------------------
	const SDKBrowserURL &operator += (const String &str);

	//----------------------------------------------------------------------------------------
	/// Equality operator. Compares the URL with another URL.
	/// @param[in] url								The right-hand URL to compare with.
	/// @return												@trueIfOtherwiseFalse{the URLs are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const SDKBrowserURL &url) const;

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Compares the URL with another URL.
	/// @param[in] url								The right-hand URL to compare with.
	/// @return												@trueIfOtherwiseFalse{the URLs are not equal}
	//----------------------------------------------------------------------------------------
	Bool operator != (const SDKBrowserURL &url) const;

		/// @}

		/// @name Information
		/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the URL is empty.
	/// @return												@trueIfOtherwiseFalse{the URL has been set}
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the URL of the parent directory.
	/// @return												The directory for the URL.
	//----------------------------------------------------------------------------------------
	SDKBrowserURL GetDirectory(void) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the local file name only (without the path).
	/// @return												The file name string.
	//----------------------------------------------------------------------------------------
	String GetFileString(void) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the URL can be represented as a Filename.
	/// @return												@trueIfOtherwiseFalse{the URL can be represented as a Filename}
	//----------------------------------------------------------------------------------------
	Bool IsFilename(void) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the suffix of the URL is the same as the string @formatParam{s}.
	/// @param[in] s									A suffix string without the dot, e.g. @em "c4d".
	/// @return												@trueIfOtherwiseFalse{the suffix matches}
	//----------------------------------------------------------------------------------------
	Bool CheckSuffix(const String &s) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the suffix of the URL (always in lower case).
	/// @return												The suffix string without the dot, e.g. @em "c4d".
	//----------------------------------------------------------------------------------------
	String GetSuffix(void) const;

		/// @}

		/// @name Set/Get Filename/String
		/// @{

	//----------------------------------------------------------------------------------------
	/// Assigns a file name to the URL.
	/// @param[in] f									The file name to assign.
	//----------------------------------------------------------------------------------------
	void SetFilename(const Filename &f);

	//----------------------------------------------------------------------------------------
	/// Assigns a string to the URL.
	/// - Set a file name as @em "file://localhost/...".
	/// - Set a preset location as @em "preset:// * /..." where * is the catalog name.
	/// - Set a catalog location as @em "catalog:// * /..." where * is the catalog name.
	/// @param[in] s									The string to assign.
	//----------------------------------------------------------------------------------------
	void SetString(const String &s);

	//----------------------------------------------------------------------------------------
	/// Retrieves a Filename from the URL.
	/// @param[out] f									Assigned the file name if method is successful.
	/// @return												@formatConstant{true} if the URL contains a filename (or a @em "file://" string) and assign that name to @formatParam{f}.\n
	/// 															@formatConstant{false} if the URL string is a catalog location or something else in the browser tree.
	//----------------------------------------------------------------------------------------
	Bool GetFilename(Filename &f) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a Filename from the URL.
	/// @return												The URL as a file name if the URL contains a filename (or a @em "file://" string).\n
	/// 															An empty Filename if the URL does not contain a file name.
	//----------------------------------------------------------------------------------------
	Filename GetFilename(void) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the URL string content.
	/// @param[out] s									Assigned the URL string.
	//----------------------------------------------------------------------------------------
	void GetString(String &s) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the URL string content.
	/// @return												The URL string.
	//----------------------------------------------------------------------------------------
	String GetString(void) const;

		/// @}
};
#endif


#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserIcon BrowserIcon
#else
//----------------------------------------------------------------------------------------
/// Represents a browser icon.
//----------------------------------------------------------------------------------------
class SDKBrowserIcon
{
public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the bitmap for the icon.
	/// @return												The icon's bitmap.
	//----------------------------------------------------------------------------------------
	BaseBitmap *GetBaseBitmap(void);

	//----------------------------------------------------------------------------------------
	/// Frees browser icons.
	/// @param[out] icon							The browser icon to free.
	//----------------------------------------------------------------------------------------
	static void Free(SDKBrowserIcon *icon);
};
#endif

//----------------------------------------------------------------------------------------
/// Base class for the browser nodes.
//----------------------------------------------------------------------------------------
class SDKReferenceObject
{
private:
	SDKReferenceObject();
	virtual ~SDKReferenceObject();
public:
	//----------------------------------------------------------------------------------------
	/// Increments the reference count.
	//----------------------------------------------------------------------------------------
	void add_reference(void);

	//----------------------------------------------------------------------------------------
	/// Decrements the reference count.
	//----------------------------------------------------------------------------------------
	void remove_reference(void);
};

#include "sdkreferenceobjectptr.h"

class SDKRTreeNode;
/// Defines a reference object pointer to a @ref SDKRTreeNode.
typedef SDKReferenceObjectPtr<SDKRTreeNode> SDKRTreeNodeRef;

//----------------------------------------------------------------------------------------
/// Basic browser tree node.
//----------------------------------------------------------------------------------------
class SDKRTreeNode : public SDKReferenceObject
{
	SDKRTreeNode();
	~SDKRTreeNode();
public:
	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the parent node.
	/// @return												The parent node.
	//----------------------------------------------------------------------------------------
	SDKRTreeNodeRef GetUp(void);

	//----------------------------------------------------------------------------------------
	/// Gets the first child node.
	/// @return												The first child node.
	//----------------------------------------------------------------------------------------
	SDKRTreeNodeRef GetDown(void);

	//----------------------------------------------------------------------------------------
	/// Gets the next sibling node.
	/// @return												The next node.
	//----------------------------------------------------------------------------------------
	SDKRTreeNodeRef GetNext(void);

	//----------------------------------------------------------------------------------------
	/// Gets the previous sibling node.
	/// @return												The previous node.
	//----------------------------------------------------------------------------------------
	SDKRTreeNodeRef GetPred(void);

	/// @}

	/// @name Insert/Remove
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts the node under @formatParam{parent}.
	/// @param[in] parent							The parent node to insert under.
	//----------------------------------------------------------------------------------------
	void InsertUnder(SDKRTreeNodeRef parent);

	//----------------------------------------------------------------------------------------
	/// Removes the node from the tree.
	//----------------------------------------------------------------------------------------
	void Remove(void);

	/// @}
};

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserPluginRef BrowserPluginRef
#define SDKBrowserContentNodeRef BrowserContentNodeRef
#define SDKBrowserPreviewData BrowserPreviewData
#define SDKBrowserPreviewInfo BrowserPreviewInfo
#define SDKBrowserPluginInterface BrowserPluginInterface
#else
class SDKBrowserContentNode;
/// Defines a reference object pointer to a @ref SDKBrowserContentNode.
typedef SDKReferenceObjectPtr<SDKBrowserContentNode> SDKBrowserContentNodeRef;
#endif

#ifndef BROWSERPLUGININTERFACE_H__
/// @addtogroup SDKBrowserBase
/// @ingroup group_enumeration
/// @{
#define BrowserBaseFileURL		"file://localhost"			///< Base URL for files.
#define BrowserBaseCatalogURL	"catalog:/"							///< Base URL for catalogs.
#define BrowserBasePresetURL	"preset:/"							///< Base URL for presets.
#define BrowserBaseRecentURL	"recent:/"							///< Base URL for recents.
#define BrowserBaseSearchURL	"search:/"							///< Base URL for searches.
/// @}

/// @addtogroup SDKBrowserLanguage
/// @ingroup group_enumeration
/// @{
enum
{
	LanguageDefault = 0,			///< Default language.

	LanguageUS = 0x75730000,			///< English. @em 'us/0/0'
	LanguageDE = 0x64650000,			///< German. @em 'de/0/0'
	LanguageJP = 0x6a700000,			///< Japanese. @em 'jp/0/0'
	LanguageCZ = 0x637a0000,			///< Czech. @em 'cz/0/0'
	LanguageES = 0x65730000,			///< Spanish. @em 'es/0/0'
	LanguageFR = 0x66720000,			///< French. @em 'fr/0/0'
	LanguageIT = 0x69740000,			///< Italian. @em 'it/0/0'
	LanguagePL = 0x706c0000				///< Polish. @em 'pl/0/0'
};
/// @}

/// @addtogroup CBPluginType
/// @ingroup group_enumeration
/// @{
enum
{
	CBPluginTypeImage							= 1018021,			///< Image.
	CBPluginTypeMovie							= 1018022,			///< Movie.
	CBPluginTypeScene							= 1018023,			///< Scene.
	CBPluginTypeCategory					= 1018024,			///< Category.
	CBPluginTypeCatalog						= 1018025,			///< Catalog.
	CBPluginTypeUnknown						= 1018026,			///< Unknown.
	CBPluginTypeFolder						= 1018027,			///< Folder.
	CBPluginTypeMaterial					= 1018028,			///< %Material.
	CBPluginTypeDummy							= 1018029,			///< Dummy.
	CBPluginTypeDefaults					= 1018030,			///< Defaults.
	CBPluginTypeFilePreset				= 1018031,			///< File preset.
	CBPluginTypeObjectPreset			= 1018107,			///< Object preset.
	CBPluginTypeMaterialPreset		= 1018108,			///< %Material preset.
	CBPluginTypeTagPreset					= 1018109,			///< Tag preset.
	CBPluginTypeRenderDataPreset	= 1018110,			///< %Render data preset.
	CBPluginTypeShaderPreset			= 1018111,			///< Shader preset.
	CBPluginTypeVideoPostPreset		= 1018112,			///< Video post preset.
	CBPluginTypeXPressoPreset			= 1018113,			///< XPresso node preset.
	CBPluginTypePresetLibrary			= 1018760,			///< Preset library.
	CBPluginTypeCatalogFile				= 1018761,			///< Catalog file.
	CBPluginTypeScriptFile				= 1018762				///< Script file.
};
/// @}

/// Browser preview data. Currently just @c void.
typedef void SDKBrowserPreviewData;

//----------------------------------------------------------------------------------------
/// Specifies browser preview settings.
//----------------------------------------------------------------------------------------
struct SDKBrowserPreviewInfo
{
	/// @name SDKBrowserPreviewQuality
	/// @{
	enum
	{
		DefaultQuality	= 0x00,			///< Get whatever quality is available.
		LowQuality			= 0x01,			///< A low quality preview is available.
		MediumQuality		= 0x02,			///< A medium quality preview is available.
		HighQuality			= 0x04,			///< A high quality preview is available.
		MaximumQuality	= 0x08,			///< A maximum quality preview is available (high render times!).
		QualityMask			= 0x0f,			///< Mask for the quality.

		FixedSize				= 0x80000000			///< Set if the preview size is fixed (e.g. image files).
	};
	/// @}
	Int32 quality_flags;			///< Quality flags. See @em SDKBrowserPreviewQuality above.
	Int32 max_width;					///< Maximum width of the preview bitmap (or @em 0 if resolution independent).
	Int32 max_height;					///< Maximum height of the preview bitmap (or @em 0 if resolution independent)
};

class SDKBrowserPluginInterfaceInfo;
class SDKBrowserPluginInterface;
typedef SDKBrowserPluginInterface *SDKBrowserPluginRef;


//----------------------------------------------------------------------------------------
// Interface base class of a browser plugin. A wrapper for calling SDKBrowserPluginInterfaceInfo functions.
//----------------------------------------------------------------------------------------
class SDKBrowserPluginInterface
{
public:

	/// @name SDKBrowserTab
	/// @{
	enum
	{
		// Basic tabs
		PreviewTab = 0,			///< Preview tab.
		InfoTab,						///< Info tab.

		// Plugin-specific tabs
		PrivateTab0 = 65536,			///< Plugin specific tab 0.
		PrivateTab1,							///< Plugin specific tab 1.
		PrivateTab2,							///< Plugin specific tab 2.
		PrivateTab3,							///< Plugin specific tab 3.
		PrivateTab4,							///< Plugin specific tab 4.
		PrivateTab5,							///< Plugin specific tab 5.
		PrivateTab6,							///< Plugin specific tab 6.
		PrivateTab7								///< Plugin specific tab 7.
	};
	/// @}

	/// @name SDKBrowserItemType
	/// @{
	enum
	{
		BasicItemType					= 1,			///< The basic item type (i.e. image, or sound file); this string is language dependent.
		SpecificItemType			= 2,			///< More specific item type, like "JPEG image file"; this string is language dependent.
		HierarchicalItemType	= 3				///< Hierarchical item type.
	};
	/// @}

	/// @name SDKBrowserIdentification
	/// @{
	enum
	{
		SlowIdentification		= 0x01			///< You are allowed to try the best possible identification, even if it is slow.
	};
	/// @}

	/// @name SDKBrowserOpen
	/// @{
	enum
	{
		Merge		= 0x01			///< Merge nodes.
	};
	/// @}

	/// @name Alloc
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{browser plugin interface}
	/// @param[in] plugin_info				The browser plugin interface information to use for the allocation.
	/// @return												@allocReturn{browser plugin interface}
	//----------------------------------------------------------------------------------------
	static SDKBrowserPluginRef Alloc(SDKBrowserPluginInterfaceInfo *plugin_info);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{browser plugin interfaces}
	/// @param[in,out] plugin					@theToDestruct{browser plugin interface}
	//----------------------------------------------------------------------------------------
	static void Free(SDKBrowserPluginRef &plugin);

	/// @}

	/// @name Plugin ID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::GetPluginID(plugin_name) for the plugin.
	//----------------------------------------------------------------------------------------
	Int32 GetPluginID(String *plugin_name = 0) const;

	/// @}

	/// @name Identify
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::Identify(url, probe, size, flags) for the plugin.
	//----------------------------------------------------------------------------------------
	Bool Identify(const SDKBrowserURL &url, UChar *probe, Int32 size, UInt32 flags);

	/// @}

	/// @name Types
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::GetTypeName(node, url, mode) for the plugin.
	//----------------------------------------------------------------------------------------
	String GetTypeName(const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::GetTypeNames(mode, strings) for the plugin.
	//----------------------------------------------------------------------------------------
	void GetTypeNames(Int32 mode, maxon::BaseArray<String>& strings);

	/// @}

	/// @name Preview Bitmap
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::OpenPreviewBitmap(thread, node, url, info) for the plugin.
	//----------------------------------------------------------------------------------------
	SDKBrowserPreviewData *OpenPreviewBitmap(BaseThread *thread, const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, SDKBrowserPreviewInfo *info);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::ClosePreviewBitmap(data) for the plugin.
	//----------------------------------------------------------------------------------------
	void ClosePreviewBitmap(SDKBrowserPreviewData *data);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::GetPreviewBitmap(data, w, h, quality) for the plugin.
	//----------------------------------------------------------------------------------------
	BaseBitmap *GetPreviewBitmap(SDKBrowserPreviewData *data, Int32 w, Int32 h, Int32 quality);

	/// @}

	/// @name Preview Dialog
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::OpenPreviewDialog(node, tab_id) for the plugin.
	//----------------------------------------------------------------------------------------
	SubDialog *OpenPreviewDialog(SDKBrowserContentNodeRef node, Int32 tab_id);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::ClosePreviewDialog(node, s) for the plugin.
	//----------------------------------------------------------------------------------------
	Int32 ClosePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::UpdatePreviewDialog(node, s) for the plugin.
	//----------------------------------------------------------------------------------------
	Int32 UpdatePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s);

	/// @}

	/// @name Open
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::UpdatePreviewDialog(node, url, flags) for the plugin.
	//----------------------------------------------------------------------------------------
	Bool Open(SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 flags);

	/// @}

	/// @name Icon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserPluginInterfaceInfo::GetIcon(url, pref_wh) for the plugin.
	//----------------------------------------------------------------------------------------
	SDKBrowserIcon *GetIcon(const SDKBrowserURL &url, Int32 pref_wh = 0);

	/// @}

};
#endif


//----------------------------------------------------------------------------------------
/// Interface for browser plugins.
//----------------------------------------------------------------------------------------
class SDKBrowserPluginInterfaceInfo
{
	friend class SDKBrowser;

private:
	SDKBrowserPluginRef plugin;

public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	SDKBrowserPluginInterfaceInfo();

	//----------------------------------------------------------------------------------------
	/// Retrieves the corresponding plugin.
	/// @return												The browser plugin reference.
	//----------------------------------------------------------------------------------------
	SDKBrowserPluginRef GetPlugin(void) const;

	/// @name SDKBrowserTab
	/// @{
	enum
	{
		// Basic tabs
		PreviewTab = 0,			///< Preview tab.
		InfoTab,						///< Info tab.

		// Plugin-specific tabs
		PrivateTab0 = 65536,			///< Plugin specific tab 0.
		PrivateTab1,							///< Plugin specific tab 1.
		PrivateTab2,							///< Plugin specific tab 2.
		PrivateTab3,							///< Plugin specific tab 3.
		PrivateTab4,							///< Plugin specific tab 4.
		PrivateTab5,							///< Plugin specific tab 5.
		PrivateTab6,							///< Plugin specific tab 6.
		PrivateTab7								///< Plugin specific tab 7.
	};
	/// @}

	/// @name SDKBrowserItemType
	/// @{
	enum
	{
		BasicItemType					= 1,			///< The basic item type (i.e. image, or sound file); this string is language dependent.
		SpecificItemType			= 2,			///< More specific item type, like "JPEG image file"; this string is language dependent.
		HierarchicalItemType	= 3				///< Hierarchical item type.
	};
	/// @}

	/// @name SDKBrowserIdentification
	/// @{
	enum
	{
		SlowIdentification		= 0x01			///< You are allowed to try the best possible identification, even if it is slow.
	};
	/// @}

	/// @name SDKBrowserOpen
	/// @{
	enum
	{
		Merge		= 0x01			///< Merge nodes.
	};
	/// @}

	/// @name Plugin ID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the ID and name of the plugin.
	/// @param[in] plugin_name				Assigned the name of the plugin, unless the pointer is @formatConstant{nullptr}.
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetPluginID(String *plugin_name = 0) = 0;

	/// @}

	/// @name Identify
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to identify a file.
	/// @param[in] url								The file URL.
	/// @param[in] probe							The start of a small chunk of data from the start of the file for testing this file type. Usually the probe size is @em 1024 bytes.
	/// @param[in] size								The probe size.
	/// @param[in] flags							The identification flags. See @em SDKBrowserIdentification above.
	/// @return												@trueIfOtherwiseFalse{the plugin can handle the file}
	//----------------------------------------------------------------------------------------
	virtual Bool Identify(const SDKBrowserURL &url, UChar *probe, Int32 size, UInt32 flags) = 0;

	/// @}

	/// @name Types
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the kind of data that is handled by the plugin. For example "Image", "Scene", "Material" etc.
	/// @param[in] node								A browser node. Can be @formatConstant{nullptr}.
	/// @param[in] url								A URL. Can be @formatConstant{nullptr}.
	/// @param[in] mode								The mode. See @em SDKBrowserItemType above.
	/// @return												A string describing the data, according to @formatParam{mode}.
	//----------------------------------------------------------------------------------------
	virtual String GetTypeName(const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 mode) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the descriptions for all kinds of data that will be handled by the plugin.
	/// @param[in] mode								The mode. See @em SDKBrowserItemType above.
	/// @param[out] strings						Strings to fill.
	//----------------------------------------------------------------------------------------
	virtual void GetTypeNames(Int32 mode, maxon::BaseArray<String>& strings) = 0;

	/// @}

	/// @name Preview Bitmap
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to open a preview bitmap.
	/// @param[in] thread							The current thread.
	/// @param[in] node								A node.
	/// @param[in] url								A URL.
	/// @param[in] info								The preview information.
	/// @return												The preview handle.
	//----------------------------------------------------------------------------------------
	virtual SDKBrowserPreviewData *OpenPreviewBitmap(BaseThread *thread, const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, SDKBrowserPreviewInfo *info) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to close the preview bitmap in data.
	/// @param[in] data								A preview handle.
	//----------------------------------------------------------------------------------------
	virtual void ClosePreviewBitmap(SDKBrowserPreviewData *data) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the preview bitmap from a handle.
	/// @param[in] data								The preview handle.
	/// @param[in] w									The width in pixels.
	/// @param[in] h									The height in pixels.
	/// @param[in] quality						The quality. See @em SDKBrowserPreviewQuality above.
	/// @return												The preview bitmap. The caller owns the returned bitmap and has to call BaseBitmap::Free() to free it.
	//----------------------------------------------------------------------------------------
	virtual BaseBitmap *GetPreviewBitmap(SDKBrowserPreviewData *data, Int32 w, Int32 h, Int32 quality) = 0;

	/// @}

	/// @name Preview Dialog
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to retrieve a plugin specific preview sub-dialog for the content node preview.
	/// @param[in] node								A node.
	/// @param[in] tab_id							The tab ID. See @em SDKBrowserTab above.
	/// @return												The plugin preview sub-dialog. Inherit this from SDKBrowserPreviewDialog.
	//----------------------------------------------------------------------------------------
	virtual SubDialog *OpenPreviewDialog(SDKBrowserContentNodeRef node, Int32 tab_id) = 0;

	//----------------------------------------------------------------------------------------
	/// Called when the preview sub-dialog is not used anymore.
	/// @param[in] node								A node.
	/// @param[in] s									The sub-dialog to close.
	/// @return												The active tab ID. Used to open the next preview dialog in the same tab.
	//----------------------------------------------------------------------------------------
	virtual Int32 ClosePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to update the current preview sub-dialog.
	/// @param[in] node								A node.
	/// @param[in] s									The sub-dialog to update.
	/// @return												The active tab ID. Used to open the next preview dialog in the same tab.
	//----------------------------------------------------------------------------------------
	virtual Int32 UpdatePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s) = 0;

	/// @}

	/// @name Open
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to open a content node.
	/// @param[in] node								A node.
	/// @param[in] url								A URL.
	/// @param[in] flags							The flags. See @em SDKBrowserOpen above.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Open(SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 flags) = 0;

	/// @}

	/// @name Icon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to retrieve an icon for a kind of file (does not have to be a preview for this specific file).
	/// @param[in] url								A URL.
	/// @param[in] pref_wh						The preferred width/height of the icon.
	/// @return												The browser icon for @formatParam{url}. The caller owns the returned icon and has to call SDKBrowserIcon::Free() to free it.
	//----------------------------------------------------------------------------------------
	virtual SDKBrowserIcon *GetIcon(const SDKBrowserURL &url, Int32 pref_wh = 0) = 0;

	/// @}
};


//----------------------------------------------------------------------------------------
// Node info for SDK browser content nodes
//----------------------------------------------------------------------------------------
#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserContentNodeInfo BrowserContentNodeInfo
#else
//----------------------------------------------------------------------------------------
/// Callback for copy and move.
/// @param[in] private_data				The private callback data.
/// @param[in] msg								The callback message.
/// @param[in] item_cnt						The item count.
/// @param[in] item_size					The item size.
/// @param[in] reserved						Reserved.
/// @return												The result. See @em OperationResult in SDKBrowserContentNodeInfo.
//----------------------------------------------------------------------------------------
typedef Int32 CopyMoveCallback(void *private_data, Int32 msg, Int32 item_cnt, Int64 item_size, void *reserved);
#endif

//----------------------------------------------------------------------------------------
/// Plugin interface for content node plugins.
//----------------------------------------------------------------------------------------
class SDKBrowserContentNodeInfo
{
	friend class SDKBrowserContentNode;
	friend class SDKNode;

private:
	Int32	plugin_id;
	void	*node;
public:

	/// @name Constructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] plugin_id					The ID of the plugin that has created the node info.
	//----------------------------------------------------------------------------------------
	explicit SDKBrowserContentNodeInfo(Int32 plugin_id);

	//----------------------------------------------------------------------------------------
	/// Retrieves the corresponding node.
	/// @return												The node corresponding to this info.
	//----------------------------------------------------------------------------------------
	SDKBrowserContentNodeRef GetNode(void) const;

	/// @}

	/// @name Init/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called by the browser with pointer to the corresponding node.
	/// @param[in] node								Pointer to the node.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Init(void *node);

	//----------------------------------------------------------------------------------------
	/// Called by the browser before the node is deleted (overload this to dispose of the SDKBrowserContentNodeInfo at a later time).
	//----------------------------------------------------------------------------------------
	virtual void Free(void);

	/// @}

	/// @name Get
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the type of content node.
	/// @return												The content node type ID. See @em SDKBrowserNodeTypeID.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetTypeID(void) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve a plugin that can deal with the file.
	/// @param[in] flags							The flags.
	/// @return												A plugin that can deal with the file of the node.
	//----------------------------------------------------------------------------------------
	virtual SDKBrowserPluginRef GetPlugin(UInt32 flags = 0) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the name of the content node (used in the UI).
	/// @return												The name of the content node.
	//----------------------------------------------------------------------------------------
	virtual String GetName(void) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the type name of the content node.
	/// @param[in] mode								The mode. See @em SDKBrowserItemType.
	/// @return												The type name.
	//----------------------------------------------------------------------------------------
	virtual String GetTypeName(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the URL of the content node (this is the file name if the node represents a file or folder in the file system).\n
	/// If there are multiple objects in a file (e.g. presets) the return value should reflect the index.
	/// @param[out] url								Assign the URL.
	/// @param[in] flags							The flags.
	/// @return												The index, if there are multiple objects.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetNodeURL(SDKBrowserURL &url, UInt32 flags = 0) const = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the creation and last modification time of a node (this will usually be the file times).\n
	/// For a directory the modification time will usually be the time when a file has been added or removed.
	/// @param[in] mode								The mode: @enumerateEnum{GE_FILETIME}
	/// @param[out] out								Assign the time.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool GetNodeTime(UInt32 mode, LocalFileTime *out) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve some node flags.
	/// @param[in] out_size						Assign the size of the output.
	/// @return												The node flags. See @em SDKBrowserNodeFlags.
	//----------------------------------------------------------------------------------------
	virtual UInt32 GetNodeFlags(Int64 *out_size = 0) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the icon for this kind of file.
	/// @param[in] flags							The flags. See @em SDKBrowserIcon.
	/// @param[in] pref_wh						The preferred width/height of the icon.
	/// @return												The browser icon for the node. The caller owns the returned icon and has to call SDKBrowserIcon::Free() to free it.
	//----------------------------------------------------------------------------------------
	virtual SDKBrowserIcon *GetIcon(Int32 flags = 0, Int32 pref_wh = 0) = 0;

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called before GetDown() is used to search for children (mainly for file system based trees).
	/// @return												Not used.
	//----------------------------------------------------------------------------------------
	virtual Int32 UpdateDirectory(void) = 0;

	//----------------------------------------------------------------------------------------
	/// Hook for private calls. The @formatParam{plugin_id} and @formatParam{node_type} parameters should be used to validate the call, so that if a call is made to the wrong node it will do nothing.
	/// @param[in] plugin_id					Must be the same as @c GetPlugin()->GetPluginID().
	/// @param[in] node_type					Must be the same as @c GetTypeID().
	/// @param[in] selector						The private method index.
	/// @param[in] data								The private data.
	/// @return												::NOTOK if not successful.
	//----------------------------------------------------------------------------------------
	virtual Int32 PrivateCall(Int32 plugin_id, Int32 node_type, Int32 selector, void *data);

	/// @}

	/// @name SDKBrowserOperation
	/// @{
	enum
	{
		CheckOperation		= 0,							///< Check if the node (and its children) can be moved/copied/deleted (to the requested destination).
		PrepareOperation	= 1,							///< Collect information about the number of items and their size.
		PerformOperation	= 2,							///< Perform the move/copy/delete operation.

		ModeMask					= 0x0000ffff,			///< Mask.

		ModePrivateFlag1	= 0x01000000,			///< @markPrivate
		ModePrivateFlag2	= 0x02000000,			///< @markPrivate
		ModePrivateFlag3	= 0x04000000,			///< @markPrivate
		ModePrivateFlag4	= 0x08000000,			///< @markPrivate
		ModePrivateFlag5	= 0x10000000,			///< @markPrivate
		ModePrivateFlag6	= 0x20000000,			///< @markPrivate
		ModePrivateFlag7	= 0x40000000			///< @markPrivate
	};
	/// @}

	/// @name SDKBrowserOperationResult
	/// @{
	enum
	{
		OperationSuccessful				= 0,								///< Operation successful.

		RenameNotPermitted				= -2147483647,			///< Rename not permitted. @c 0x80000001
		MoveNotPermitted					= -2147483646,			///< Move not permitted. @c 0x80000002
		CopyNotPermitted					= -2147483644,			///< Copy not permitted. @c 0x80000004
		DeleteNotPermitted				= -2147483640,			///< Delete not permitted. @c 0x80000008
		NewFolderNotPermitted			= -2147483632,			///< New folder not permitted. @c 0x80000010

		RenameError								= -2147483392,			///< Rename error. @c 0x80000100
		MoveError									= -2147483136,			///< Move error. @c 0x80000200
		CopyError									= -2147482624,			///< Copy error. @c 0x80000400
		DeleteError								= -2147481600,			///< Delete error. @c 0x80000800

		UnsupportedNodeType				= -1610612736,			///< Unsupported node type. @c 0xa0000000L
		UserCancelled							= -1073741824				///< %User canceled. @c 0xc0000000L
	};
	/// @}

	/// @name Rename/NewFolder
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to rename the node.
	/// @param[in] mode								The mode. Either @ref CheckOperation or @ref PerformOperation.
	/// @param[in] name								The new name.
	/// @return												The result. See @em SDKBrowserOperationResult.
	//----------------------------------------------------------------------------------------
	virtual Int32 Rename(Int32 mode, const String &name)
	{
		return RenameNotPermitted;
	}

	//----------------------------------------------------------------------------------------
	/// Called to create a new folder.
	/// @param[in] mode								The mode. Either @ref CheckOperation or @ref PerformOperation.
	/// @param[in] name								A unique name.
	/// @param[in] folder							The node folder.
	/// @return												The result. See @em SDKBrowserOperationResult.
	//----------------------------------------------------------------------------------------
	virtual Int32 NewFolder(Int32 mode, const String &name, SDKBrowserContentNodeRef *folder = 0)
	{
		return ((Int32) (NewFolderNotPermitted));
	}

	/// @}

	/// @name Move/Copy/Delete
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to move nodes (the node will be the new parent).
	/// @param[in] new_child					The new child.
	/// @param[in] mode								The mode. See @em SDKBrowserOperation.
	/// @param[in] callback						The callback, e.g. for progress report. Only called for @ref PrepareOperation and @ref PerformOperation modes.
	/// @param[in] private_data				Private data for the callback.
	/// @param[in] thread							The thread.
	/// @return												The result. See @em SDKBrowserOperationResult.
	//----------------------------------------------------------------------------------------
	virtual Int32 MoveFrom(SDKBrowserContentNodeRef new_child, Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
	{
		return ((Int32) (MoveNotPermitted));
	}

	//----------------------------------------------------------------------------------------
	/// Called to copy nodes (the node will be the new parent).
	/// @param[in] new_child					The new child.
	/// @param[in] mode								The mode. See @em SDKBrowserOperation.
	/// @param[in] rename							Pointer to a string if @formatParam{new_child} has to be renamed to avoid a name conflict. Can be @formatConstant{nullptr}.
	/// @param[in] callback						The callback, e.g. for progress report. Only called for @ref PrepareOperation and @ref PerformOperation modes.
	/// @param[in] private_data				Private data for the callback.
	/// @param[in] thread							The thread.
	/// @return												The result. See @em SDKBrowserOperationResult.
	//----------------------------------------------------------------------------------------
	virtual Int32 CopyFrom(SDKBrowserContentNodeRef new_child, Int32 mode, const String *rename, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
	{
		return ((Int32) (CopyNotPermitted));
	}

	//----------------------------------------------------------------------------------------
	/// Called to delete the node and its children.
	/// @param[in] mode								The mode. See @em SDKBrowserOperation.
	/// @param[in] callback						The callback, e.g. for progress report. Only called for @ref PrepareOperation and @ref PerformOperation modes.
	/// @param[in] private_data				Private data for the callback.
	/// @param[in] thread							The thread.
	/// @return												The result. See @em SDKBrowserOperationResult.
	//----------------------------------------------------------------------------------------
	virtual Int32 Delete(Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
	{
		return ((Int32) (DeleteNotPermitted));
	}

	/// @}

	/// @name Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// A dummy destructor to make the compiler happy.
	//----------------------------------------------------------------------------------------
	virtual ~SDKBrowserContentNodeInfo() {}

	/// @}
};

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserContentNode BrowserContentNode
#else

/// Return the linked data, for example the "real" plugin for a linked node (in case of a catalog item).
/// @see SDKBrowserContentNode::GetNodeURL
#define LinkThrough 0x80000000


//----------------------------------------------------------------------------------------
/// Browser content node. A wrapper for calling SDKBrowserContentNodeInfo functions.
//----------------------------------------------------------------------------------------
class SDKBrowserContentNode : public SDKRTreeNode
{
private:
	SDKBrowserContentNode();
	~SDKBrowserContentNode();
public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allocates a content node.
	/// @param[in] info								The info to allocate the node for.
	/// @param[in] parent							An optional parent node.
	/// @return												The allocated content node, or @formatConstant{nullptr} if the allocation failed.
	//----------------------------------------------------------------------------------------
	static SDKBrowserContentNodeRef Alloc(SDKBrowserContentNodeInfo *info, SDKBrowserContentNodeRef parent = 0);

	//----------------------------------------------------------------------------------------
	/// Allocates a category node.
	/// @param[in] name								The category name.
	/// @param[in] local_path					The local path.
	/// @param[in] icon_file					The icon filename.
	/// @param[in] parent							An optional parent node.
	/// @return												The allocated category node, or @formatConstant{nullptr} if the allocation failed.
	//----------------------------------------------------------------------------------------
	static SDKBrowserContentNodeRef AllocCategoryNode(const String &name, const String &local_path, const Filename &icon_file = Filename(), SDKBrowserContentNodeRef parent = 0);

	//----------------------------------------------------------------------------------------
	/// Frees all SDKBrowserContentNodeInfo of the plugin and remove the nodes from the tree.
	/// @param[in] plugin_id					The node plugin ID to free.
	//----------------------------------------------------------------------------------------
	static void FreeNodes(Int32 plugin_id);

	/// @}

	/// @name SDKBrowserNodeTypeID
	/// @{
	enum
	{
		TypeUnknown = 0,			/// Unknown type.
		TypeCategory,					/// Node is a category folder.
		TypeFileSystem,				/// Node represents a file or folder in the file system.
		TypePreset,						/// Node represents some kind of setting/preset.
		TypeCatalog,					/// Node is a catalog (that might link to another node).
		TypeMaterial					/// Node is virtual material.
	};
	/// @}

	/// @name SDKBrowserNodeFlags
	/// @{
	enum
	{
		Directory					= 0x01,						///< Is a directory (or generally speaking a tree branch).
		VirtualDirectory	= 0x02,						///< Is a file that contains data that is displayed as children (e.g. a material library).
		VirtualFile				= 0x04,						///< Is a directory that is represented as a file.
		Link							= 0x08,						///< Is a link to a source node (e.g. a catalog node).
		ReadOnly					= 0x10,						///< Cannot be modified.
		Flush							= 0x40,						///< Likely to be deleted soon.
		NoPreview					= 0x80,						///< Preview for this item is not be available (unknown file format).

		PrivateFlag0			= 0x010000,				///< Private flag @em 0, free for plugins nodes to use.
		PrivateFlag1			= 0x020000,				///< Private flag @em 1, free for plugins nodes to use.
		PrivateFlag2			= 0x040000,				///< Private flag @em 2, free for plugins nodes to use.
		PrivateFlag3			= 0x080000,				///< Private flag @em 3, free for plugins nodes to use.

		TargetNotFound		= 0x20000000,			///< The file (node) linked by a catalog cannot be found.
		KeepResident			= 0x40000000			///< Keep resident.
	};
	/// @}

	/// @name SDKBrowserIconFlags
	/// @{
	enum
	{
		IconNone 					= 0x0000,			///< No icon.
		IconPreviewBitmap	= 0x8000,			///< Preview bitmap.
		IconFolderOpen		= 0x0001			///< Folder open.
	};
	/// @}

	/// @name SDKBrowserItemType
	/// @{
	enum
	{
		BasicItemType					= 1,			///< The basic item type (i.e. image, or sound file); this string is language dependent.
		SpecificItemType			= 2,			///< More specific item type, like "JPEG image file"; this string is language dependent.
		HierarchicalItemType	= 3				///< Hierarchical item type.
	};
	/// @}

	/// @name SDKBrowserPluginIdentification
	/// @{
	enum
	{
		LazyIdentification = 0x02			///< For SDKBrowserContentNode::GetPlugin() only.
	};
	/// @}

	/// @name Get
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the SDKBrowserContentNodeInfo for the node.
	/// @param[in] plugin_id					The node plugin ID.
	/// @return												The node info, or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	SDKBrowserContentNodeInfo *GetNodeInfo(Int32 plugin_id = 0) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetTypeID() for the node.
	//----------------------------------------------------------------------------------------
	Int32 GetTypeID(void) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetPlugin(flags) for the node.
	//----------------------------------------------------------------------------------------
	SDKBrowserPluginRef GetPlugin(UInt32 flags = 0) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetName() for the node.
	//----------------------------------------------------------------------------------------
	String GetName(void) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetTypeName(mode) for the node.
	//----------------------------------------------------------------------------------------
	String GetTypeName(Int32 mode) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetNodeURL(url, flags) for the node.
	//----------------------------------------------------------------------------------------
	Int32 GetNodeURL(SDKBrowserURL &url, UInt32 flags = 0) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the URL of the content node.
	/// @param[in] flags							Can be set to the optional flag @ref LinkThrough.
	/// @param[out] idx								Reserved.
	/// @return												The URL of the content node.
	//----------------------------------------------------------------------------------------
	SDKBrowserURL GetNodeURL(UInt32 flags = 0, Int32 *idx = 0) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the file name of the node, if applicable.
	/// @param[out] f									Assigned the file name of the node.
	/// @param[in] flags							Can be set to the optional flag @ref LinkThrough.
	/// @return												@formatConstant{true} if the node is a filename, @formatConstant{false} if it is something else (e.g. a preset node).
	//----------------------------------------------------------------------------------------
	Bool GetFilename(Filename &f, UInt32 flags = 0) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetNodeTime(mode, out) for the node.
	//----------------------------------------------------------------------------------------
	Bool GetNodeTime(UInt32 mode, LocalFileTime *out) const;

	//----------------------------------------------------------------------------------------
	/// Gets the node time specified by @formatParam{mode}.
	/// @param[in] mode								The mode: @enumerateEnum{GE_FILETIME}
	/// @return												The node time.
	//----------------------------------------------------------------------------------------
	LocalFileTime GetNodeTime(UInt32 mode = GE_FILETIME_MODIFIED) const;

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetNodeFlags() for the node.
	//----------------------------------------------------------------------------------------
	UInt32 GetNodeFlags(Int64 *out_size = 0) const;

	/// @}

	/// @name Checks
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the node is a directory or a tree branch.
	/// @return												@trueIfOtherwiseFalse{the node is a directory or tree branch}
	//----------------------------------------------------------------------------------------
	Bool IsDirectory(void) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the node is a link to another node. (Call GetNodeURL() with @em LinkThrough flag to get the destination URL.)
	/// @return												@trueIfOtherwiseFalse{the node is a link}
	//----------------------------------------------------------------------------------------
	Bool IsLink(void) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the node is read-only.
	/// @return												@trueIfOtherwiseFalse{the node is read-only}
	//----------------------------------------------------------------------------------------
	Bool IsReadOnly(void) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the node is going to be flushed. If so do not create new database entries for it.
	/// @return												@trueIfOtherwiseFalse{the node is about to be flushed}
	//----------------------------------------------------------------------------------------
	Bool IsFlushed(void) const;

	/// @}

	/// @name Icon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::GetIcon(state, pref_wh) for the node.
	//----------------------------------------------------------------------------------------
	SDKBrowserIcon *GetIcon(Int32 state = 0, Int32 pref_wh = 0) const;

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::UpdateDirectory() for the node.
	//----------------------------------------------------------------------------------------
	Int32 UpdateDirectory(void);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::PrivateCall(plugin_id, node_type, selector, data) for the node.
	//----------------------------------------------------------------------------------------
	Int32 PrivateCall(Int32 plugin_id, Int32 node_type, Int32 selector, void *data);

	/// @}

	/// @name Operations
	/// @{

	/// @name SDKBrowserOperation
	/// @{
	enum
	{
		CheckOperation		= 0,			///< Check if the node (and its children) can be moved/copied/deleted (to the requested destination).
		PrepareOperation	= 1,			///< Collect information about the number of items and their size.
		PerformOperation	= 2,			///< Perform the move/copy/delete operation.
	};
	/// @}

	/// @name SDKBrowserOperationResult
	/// @{
	enum
	{
		OperationSuccessful				= 0,								///< Operation successful.

		RenameNotPermitted				= -2147483647,			///< Rename not permitted. @c 0x80000001
		MoveNotPermitted					= -2147483646,			///< Move not permitted. @c 0x80000002
		CopyNotPermitted					= -2147483644,			///< Copy not permitted. @c 0x80000004
		DeleteNotPermitted				= -2147483640,			///< Delete not permitted. @c 0x80000008
		NewFolderNotPermitted			= -2147483632,			///< New folder not permitted. @c 0x80000010

		RenameError								= -2147483392,			///< Rename error. @c 0x80000100
		MoveError									= -2147483136,			///< Move error. @c 0x80000200
		CopyError									= -2147482624,			///< Copy error. @c 0x80000400
		DeleteError								= -2147481600,			///< Delete error. @c 0x80000800

		UnsupportedNodeType				= -1610612736,			///< Unsupported node type. @c 0xa0000000L
		UserCancelled							= -1073741824				///< %User canceled. @c 0xc0000000L
	};
	/// @}

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::Rename(mode, name) for the node.
	//----------------------------------------------------------------------------------------
	Int32 Rename(Int32 mode, const String &name);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::NewFolder(mode, name, folder) for the node.
	//----------------------------------------------------------------------------------------
	Int32 NewFolder(Int32 mode, const String &name, SDKBrowserContentNodeRef *folder = 0);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::MoveFrom(new_child, mode, callback, private_data, thread) for the node.
	//----------------------------------------------------------------------------------------
	Int32 MoveFrom(SDKBrowserContentNodeRef new_child, Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread = nullptr);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::CopyFrom(new_child, mode, rename, callback, private_data, thread) for the node.
	//----------------------------------------------------------------------------------------
	Int32 CopyFrom(SDKBrowserContentNodeRef new_child, Int32 mode, const String *rename, CopyMoveCallback *callback, void *private_data, BaseThread *thread = nullptr);

	//----------------------------------------------------------------------------------------
	/// Returns SDKBrowserContentNodeInfo::Delete(mode, callback, private_data, thread) for the node.
	//----------------------------------------------------------------------------------------
	Int32 Delete(Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread = nullptr);

	/// @}

	/// @name Preset
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the object of default nodes. (Wrapper for PrivateCall().)
	/// @return												The object of default nodes. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject *GetDefaultObject(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the document with presets for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The document with presets for preset nodes. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument *GetObjectPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the material for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The material for preset nodes. @callerOwnsPointed{material}
	//----------------------------------------------------------------------------------------
	BaseMaterial *GetMaterialPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the tag for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The tag for preset nodes. @callerOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	BaseTag *GetTagPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the render data for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The render data for preset nodes. @callerOwnsPointed{render data}
	//----------------------------------------------------------------------------------------
	RenderData *GetRenderDataPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the shader for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The shader for preset nodes. @callerOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader *GetShaderPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the video post for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The video post for preset nodes. @callerOwnsPointed{video post}
	//----------------------------------------------------------------------------------------
	BaseVideoPost *GetVideoPostPreset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the Xpresso node for preset nodes. (Wrapper for PrivateCall().)
	/// @return												The XPresso node for preset nodes. @callerOwnsPointed{XPresso node}
	//----------------------------------------------------------------------------------------
	GvNode *GetXPressoPreset(void);

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the preset source plugin.
	/// @return												The ID of the preset source plugin.
	//----------------------------------------------------------------------------------------
	Int32 GetPresetSourcePluginID(void);

	/// @}
};
#endif


/// Browser drag message.
#define DRAGTYPE_BROWSER 1017705

//----------------------------------------------------------------------------------------
/// Browser drag information.
/// @see GeUserArea::HandleMouseDrag
//----------------------------------------------------------------------------------------
class SDKBrowserDragInfo
{
private:
	SDKBrowserDragInfo();
	~SDKBrowserDragInfo();

public:

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of dragged items.
	/// @return												The item count.
	//----------------------------------------------------------------------------------------
	Int32 GetItemCount(void)
	{
		return no_items;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the item at index @formatParam{idx}.
	/// @param[in] idx								The item index: @em 0 <= @formatParam{idx} < GetItemCount()
	/// @return												The dragged item at index @formatParam{idx}.
	//----------------------------------------------------------------------------------------
	SDKBrowserContentNodeRef GetItem(Int32 idx)
	{
		if ((idx >= 0) && (idx < no_items))
			return items[idx];

		return (SDKBrowserContentNode *) nullptr;
	}

	Int32											no_items;				///< Number of dragged objects.
	Int32											reserved1;			///< Reserved.
	SDKBrowserContentNodeRef	*items;					///< Array of @ref SDKBrowserContentNodeRef holding the dragged objects.
	void											*reserved3;			///< Reserved.
};


/// The minimum ID for additional gadgets in the preview sub-dialog SDKBrowserPreviewDialog.
#define SDKBROWSER_MIN_GADGET_ID	1000000

//----------------------------------------------------------------------------------------
/// Inherit to create sub-dialogs for SDKBrowserPluginInterfaceInfo::OpenPreviewDialog().
//----------------------------------------------------------------------------------------
class SDKBrowserPreviewDialog : public SubDialog
{
public:

	enum
	{
		DontUpdatePreviewBitmap	= 0x1			///< For Update() if a custom preview bitmap is used.
	};

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	SDKBrowserPreviewDialog();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	virtual ~SDKBrowserPreviewDialog();

	/// @}

	/// @name Init/Update
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the content node and the active tab.
	/// @param[in] content						The active content node.
	/// @param[in] tab_id							The active tab. See @em SDKBrowserTab.
	//----------------------------------------------------------------------------------------
	void Init(SDKBrowserContentNodeRef content, Int32 tab_id);

	//----------------------------------------------------------------------------------------
	/// Updates the preview sub-dialog.
	/// @param[in] flags							Pass @ref DontUpdatePreviewBitmap if a custom preview bitmap is used.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Update(Int32 flags = 0);

	/// @}

	/// @name Tab
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds an extra tab.
	/// @note Must be called before CreateLayout().
	/// @param[in] id									The tab ID to add. See @em SDKBrowserTab.
	/// @param[in] name								The name of the new tab.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddTab(Int32 id, const String &name);

	//----------------------------------------------------------------------------------------
	/// Remove one of the default tabs (@c PreviewTab or @c InfoTab).
	/// @param[in] id									The default tab ID to remove. Pass @c PreviewTab or @c InfoTab.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool RemoveDefaultTab(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Flushes the content of one of the default tabs (@c PreviewTab or @c InfoTab).
	/// @param[in] id									The default tab ID to flush. Pass @c PreviewTab or @c InfoTab.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool LayoutFlushTab(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Sets the insertion point at the end of one of the default tabs (@c PreviewTab or @c InfoTab).
	/// @param[in] id									The default tab ID to set the insertion point to. Pass @c PreviewTab or @c InfoTab.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool LayoutAddToTab(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Calls LayoutChanged() for one of the default tabs (@c PreviewTab or @c InfoTab).
	/// @param[in] id									The default tab ID to call LayoutChanged() for. Pass @c PreviewTab or @c InfoTab.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool LayoutChangedTab(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Retrieves the ID of the active tab.
	/// @return												The active tab. See @em SDKBrowserTab.
	//----------------------------------------------------------------------------------------
	Int32 GetActiveTab(void);

	/// @}

	/// @name Preview Bitmap
	/// @{

	//----------------------------------------------------------------------------------------
	/// Changes the preview bitmap.
	/// @param[in] bm									The new bitmap.
	/// @param[in] flags							The flags.
	//----------------------------------------------------------------------------------------
	void ChangePreviewBitmap(BaseBitmap *bm, Int32 flags = 0);

	/// @}

	/// @name GeDialog Overrides
	/// @{

	virtual Bool CreateLayout(void);
	virtual Bool InitValues(void);
	virtual Bool CoreMessage(Int32 id, const BaseContainer &msg);
	virtual Bool Command(Int32 id, const BaseContainer &msg);
	virtual Bool AskClose(void);
	virtual void Timer(const BaseContainer &msg);
	virtual void DestroyWindow(void);
	virtual Int32 Message(const BaseContainer &msg, BaseContainer &result);

	/// @}

private:
	void *private_data;
};


#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowsePresets BrowseURL
#else

//----------------------------------------------------------------------------------------
/// Browse presets.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SDKBrowsePresets
{
private:
	SDKBrowsePresets();
	~SDKBrowsePresets();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{preset browser}
	/// @param[in] db_index						The ID of the preset library to browse.
	/// @return												@allocReturn{preset browser}
	//----------------------------------------------------------------------------------------
	static SDKBrowsePresets *Alloc(Int32 db_index);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{reset browsers}
	/// @param[in,out] browse_presets	@theToDestruct{preset browser}
	//----------------------------------------------------------------------------------------
	static void Free(SDKBrowsePresets *browse_presets);

	//----------------------------------------------------------------------------------------
	/// Retrieves the next preset.
	/// @param[out] url								Assigned the URL of the preset.
	/// @param[out] plugin_id					Assigned the ID of the plugin that created the preset.
	/// @return												@trueIfOtherwiseFalse{a new preset was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetNext(SDKBrowserURL &url, Int32 &plugin_id);
};

#endif

/// @markPrivate
enum
{
	SDKBrowserPreviewDialogAlloc = 0,
	SDKBrowserPreviewDialogFree,
	SDKBrowserPreviewDialogInit,
	SDKBrowserPreviewDialogAddTab,
	SDKBrowserPreviewDialogRemoveDefaultTab,
	SDKBrowserPreviewDialogLayoutFlushTab,
	SDKBrowserPreviewDialogLayoutAddToTab,
	SDKBrowserPreviewDialogLayoutChangedTab,
	SDKBrowserPreviewDialogGetActiveTab,
	SDKBrowserPreviewDialogChangePreviewBitmap,
	SDKBrowserPreviewDialogCreateLayout,
	SDKBrowserPreviewDialogInitValues,
	SDKBrowserPreviewDialogCoreMessage,
	SDKBrowserPreviewDialogCommandNotifyEx,
	SDKBrowserPreviewDialogCommand,
	SDKBrowserPreviewDialogAskClose,
	SDKBrowserPreviewDialogTimer,
	SDKBrowserPreviewDialogDestroyWindow,
	SDKBrowserPreviewDialogMessage,
	SDKBrowserPreviewDialogUpdate
};

//----------------------------------------------------------------------------------------
/// The main browser library class.
//----------------------------------------------------------------------------------------
class SDKBrowser
{
private:

	SDKBrowser();
	~SDKBrowser();

public:
	/// @name SDKBrowserCategory
	/// @{
	enum
	{
		CategoryPresetNodes		= 0,			///< Preset category.
		CategoryCatalogNodes	= 1,			///< Catalog category.
		CategoryDriveNodes		= 2,			///< Drive category.
		CategoryRecentNodes		= 3,			///< Recent category.
		CategorySearchNodes		= 4,			///< Search category.

		ddumdumdimdum
	};
	/// @}

	/// @name SDKBrowserFind
	/// @{
	enum
	{
		FindExactMatch				= 1,			///< Find exact match.
		FindBestMatch					= 2,			///< Find best match.
		ForceDirectoryUpdate	= 4				///< Force directory update.
	};
	/// @}

	/// @name SDKBrowserFileSystemTypes
	/// @{
	enum
	{
		Computer = 0,				///< Computer.
		Drive,							///< Drive.
		DriveCD,						///< CD drive.
		Folder,							///< Folder.
		FolderOpen,					///< Open folder.
		FolderPresets,			///< Presets folder.
		FolderCatalogs,			///< Catalogs folder.
		FolderSearch,				///< Search folder.
		Document,						///< Document folder.
		ThreeDFile,					///< 3D file.
		ImageFile,					///< Image file.
		MovieFile,					///< Movie file.
		Preset							///< Preset.
	};
	/// @}

	/// @name SDKBrowserPresetDb
	/// @{
	enum
	{
		UserPresetDb		= 1,			///< %User preset library database index.
		InvalidPresetDb	= -1			///< Invalid database index.
	};
	/// @}

	/// @name SDKBrowserPresetLibrary
	/// @{
	enum
	{
		ReadOnlyPresetLibrary	= 1,			///< Disable write operations to the preset library (regardless of the file system settings).
		SystemPresetLibrary		= 2,			///< System preset library.
		IgnoreROPresetLibrary	= 4				///< Ignore a read-only flag in the preset library and makes it writable.
	};
	/// @}

	/// @name SDKBrowserPreview
	/// @{
	enum
	{
		PreviewReplace	= 0,			///< Previews are replaced.
		PreviewAppend		= 1				///< Previews are appended.
	};
	/// @}

	/// @name InsertNodeFromDataBase Callback
	/// @{

	//----------------------------------------------------------------------------------------
	/// Node insertion callback.
	/// @param[in] parent							The parent node.
	/// @param[in] existing_node			An existing node.
	/// @param[in] url								The URL.
	/// @param[in] name								The name.
	/// @param[in] flags							The flags.
	/// @param[in] db_index						The database index.
	/// @param[in] user_data					The callback user data.
	/// @return												A content node.
	//----------------------------------------------------------------------------------------
	typedef SDKBrowserContentNodeRef InsertNodeFromDataBase(SDKBrowserContentNodeRef parent, SDKBrowserContentNodeRef existing_node, const SDKBrowserURL &url, const String &name, UInt32 flags, Int32 db_index, void *user_data);

	/// @}

	/// @name Open New Browser
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens a new browser at @formatParam{path}.
	/// @param[in] path								The path to open.
	/// @param[in] flags							The flags.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool OpenNewBrowser(const SDKBrowserURL &path, UInt32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Opens a new browser at @formatParam{path} with a custom title.
	/// @param[in] path								The path to open.
	/// @param[in] custom_title				The custom title.
	/// @param[in] flags							The flags.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool OpenNewBrowserWithTitle(const SDKBrowserURL &path, const String& custom_title = String(), UInt32 flags = 0);

	/// @}

	/// @name Category Node
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a category node.
	/// @param[in] where							The category. See @em SDKBrowserCategory.
	/// @return												The category node, or @formatConstant{nullptr} if it could not be found.
	//----------------------------------------------------------------------------------------
	static SDKBrowserContentNodeRef GetCategoryNode(Int32 where);

	/// @}

	/// @name Icon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets an icon by ID.
	/// @param[in] id									The icon ID.
	/// @param[in] pref_wh						The preferred width/height of the icon.
	/// @return												The icon.
	//----------------------------------------------------------------------------------------
	static SDKBrowserIcon *GetIcon(Int32 id, Int32 pref_wh = 0);

	//----------------------------------------------------------------------------------------
	/// Gets an icon by URL and plugin ID.
	/// @param[in] url								A URL to get the icon for.
	/// @param[in] plugin							A corresponding plugin ID.
	/// @param[in] flags							Reserved.
	/// @param[in] preview_time				An optional preview time.
	/// @return												The icon.
	//----------------------------------------------------------------------------------------
	static SDKBrowserIcon *GetIcon(const SDKBrowserURL &url, SDKBrowserPluginRef plugin = 0, Int32 flags = 0, LocalFileTime *preview_time = 0);

	//----------------------------------------------------------------------------------------
	/// Retrieves the pointer to a preview icon. If no preview is available the default icon for the type of node will be returned. The browser will cache the icon.
	/// @param[in] content						The node for which an icon will be returned.
	/// @param[in] pref_wh						The preferred width/height of the icon.
	/// @param[in] flags							The flags. See @em SDKBrowserIconFlags.
	/// @return												The icon.
	//----------------------------------------------------------------------------------------
	static SDKBrowserIcon *GetPreviewIcon(SDKBrowserContentNodeRef content, Int32 pref_wh, Int32 flags = SDKBrowserContentNode::IconPreviewBitmap);

	//----------------------------------------------------------------------------------------
	/// Creates an icon from a bitmap.
	/// @param[in] bm									The bitmap to create the icon from.
	/// @param[in] dont_free					@formatConstant{true} if the icon bitmap should not be freed.
	/// @return												The icon.
	//----------------------------------------------------------------------------------------
	static SDKBrowserIcon *CreateIcon(BaseBitmap *bm, Bool dont_free);

	//----------------------------------------------------------------------------------------
	/// Releases @formatParam{icon}.
	/// @param[in,out] icon						The icon to release.
	//----------------------------------------------------------------------------------------
	static void ReleaseIcon(SDKBrowserIcon *icon);

	/// @}

	/// @name Register Browser Plugin
	/// @{

	//----------------------------------------------------------------------------------------
	/// Registers the browser plugin in @formatParam{plugin_info}.
	/// @param[in] plugin_info				The browser plugin to register.
	/// @param[in] flags							The flags.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool RegisterBrowserPlugin(SDKBrowserPluginInterfaceInfo *plugin_info, UInt32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Unregisters the browser plugin in @formatParam{plugin_info}.
	/// @param[in] plugin_info				The browser plugin to unregister.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool UnregisterBrowserPlugin(SDKBrowserPluginInterfaceInfo *plugin_info);

	/// @}

	/// @name Register Preset Library
	/// @{

	//----------------------------------------------------------------------------------------
	/// Registers a preset library.
	/// @param[in] domain							The preset domain.
	/// @param[in] name								The name of the database.
	/// @param[in] f									The file name and path.
	/// @return												The database index of the registered preset library, or < @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	static Int32 RegisterPresetLibrary(const SDKBrowserURL &domain, const String &name, const Filename &f);

	//----------------------------------------------------------------------------------------
	/// Unregisters a preset library.
	/// @param[in] db_index						The database index. Use @ref UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] f									The file name and path.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool UnregisterPresetLibrary(Int32 db_index, const Filename &f);

	/// @}

	/// @name Database Index
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the database index of @formatParam{url}.
	/// @param[in] url								The URL to get the database index for.
	/// @param[in] flags							The flags.
	/// @return												The database index, or @ref InvalidPresetDb if @formatParam{url} does not belong to any preset database.
	//----------------------------------------------------------------------------------------
	static Int32 GetDbIndex(const SDKBrowserURL &url, UInt32 flags = 0);

	/// @}

	/// @name Preset
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if a preset exists.
	/// @param[in] url								The URL of the preset.
	/// @return												@trueIfOtherwiseFalse{a preset exists at @formatParam{url}}
	//----------------------------------------------------------------------------------------
	static Bool ExistsPreset(const SDKBrowserURL &url);

	//----------------------------------------------------------------------------------------
	/// Loads data for a preset node in a specific preset database.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[out] plugin_id					Assigned The ID of the plugin that saved the data.
	/// @param[out] bc								Assigned an information container. Can be @formatConstant{nullptr}.
	/// @param[out] data							Assigned a memory block with private node data. The memory will be owned by the caller. Can be @formatConstant{nullptr}.
	/// @param[out] length						Assigned the length of the private node data in bytes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool LoadPreset(Int32 db_index, const SDKBrowserURL &url, Int32 &plugin_id, BaseContainer *bc, void **data, Int *length);

	//----------------------------------------------------------------------------------------
	/// Saves data for a preset node in a specific preset database.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] plugin_id					The ID of the plugin that saves the data. (This should be the same value as SDKBrowserPluginInterface::GetPluginID().)
	/// @param[in] bc									Pointer to an information container. Can be @formatConstant{nullptr}.
	/// @param[in] data								Memory block with private node data. The caller owns the memory block. Can be @formatConstant{nullptr}.
	/// @param[in] length							The length of the private node data in bytes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SavePreset(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, const BaseContainer *bc, void *data, Int length);

	//----------------------------------------------------------------------------------------
	/// Deletes data for a preset node in a specific preset database.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] plugin_id					The ID of the plugin that saves the data. (This should be the same value as SDKBrowserPluginInterface::GetPluginID().)
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool DeletePreset(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id);

	//----------------------------------------------------------------------------------------
	/// Copies presets.
	/// @param[in] src								The URL of the source preset.
	/// @param[in] dst								The URL of the destination preset.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool CopyPreset(const SDKBrowserURL &src, const SDKBrowserURL &dst);

	//----------------------------------------------------------------------------------------
	/// Retrieves the language specific name of a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] language_id				The language ID. @ref LanguageDefault for the default language. See @em SDKBrowserLanguage.
	/// @param[out] out_name					Assigned the preset name.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool GetPresetName(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, String &out_name);

	//----------------------------------------------------------------------------------------
	/// Sets the language specific name of a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] language_id				The language ID. @ref LanguageDefault for the default language. See @em SDKBrowserLanguage.
	/// @param[in] name								The new name..
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetPresetName(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, const String &name);

	//----------------------------------------------------------------------------------------
	/// Changes the preset URL.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] new_url						The new URL.
	/// @param[in] plugin_id					The ID of the plugin that saved the data (this should be the same value as SDKBrowserPluginInterface::GetPluginID()).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool ChangePresetURL(Int32 db_index, const SDKBrowserURL &url, const SDKBrowserURL &new_url, Int32 plugin_id);

	//----------------------------------------------------------------------------------------
	/// Retrieves the annotation string of a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[out] annotation				Assigned the annotation.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool GetPresetAnnotation(Int32 db_index, const SDKBrowserURL &url, String &annotation);

	//----------------------------------------------------------------------------------------
	/// Sets the annotation string of a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] annotation					The new annotation.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetPresetAnnotation(Int32 db_index, const SDKBrowserURL &url, const String &annotation);

	//----------------------------------------------------------------------------------------
	/// Sets the preview bitmap of a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] mode								The mode. See @em SDKBrowserPreview.
	/// @param[in] preview_quality		The new preview quality. See @em SDKBrowserPreviewQuality.
	/// @param[in] bm									The preview bitmap. Copied.
	/// @param[in] lft								The preview time. Copied.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetPresetPreview(Int32 db_index, const SDKBrowserURL &url, Int32 mode, Int32 preview_quality, BaseBitmap *bm, const LocalFileTime *lft);

	//----------------------------------------------------------------------------------------
	/// Gets the preview bitmap for a preset.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] frame_idx					The frame index, for movie clip previews.
	/// @return												The preview bitmap.
	//----------------------------------------------------------------------------------------
	static BaseBitmap *GetPresetPreview(Int32 db_index, const SDKBrowserURL &url, Int32 frame_idx);

	//----------------------------------------------------------------------------------------
	/// Retrieves the animation data for an animated preset preview.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[out] first_frame_idx		Assigned the number of the first frame.
	/// @param[out] last_frame_idx		Assigned the number of the last frame.
	/// @param[out] fps								Assigned the frames per second.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool GetPresetAnimationData(Int32 db_index, const SDKBrowserURL &url, Int32 *first_frame_idx, Int32 *last_frame_idx, Float *fps);

	//----------------------------------------------------------------------------------------
	/// Sets the animation data for an animated preset preview.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL of the preset node.
	/// @param[in] first_frame_idx		The number of the first frame.
	/// @param[in] last_frame_idx			The number of the last frame.
	/// @param[in] fps								Assigned the frames per second.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetPresetAnimationData(Int32 db_index, const SDKBrowserURL &url, Int32 first_frame_idx, Int32 last_frame_idx, Float fps);

	//----------------------------------------------------------------------------------------
	/// Saves a BaseList2D object as preset. An already existing node with the @formatParam{url} will be replaced.
	/// @param[in] url								The URL of the preset node. There must be an existing node for the URL!
	/// @param[in] bl									The base list object.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SavePresetObject(const SDKBrowserURL &url, BaseList2D *bl);

	//----------------------------------------------------------------------------------------
	/// Reads nodes from a database.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] base_url						The base URL.
	/// @param[in] base_node					The base node.
	/// @param[in] callback						The callback.
	/// @param[in] user_data					The user data for the callback.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool ReadNodesFromDatabase(Int32 db_index, const SDKBrowserURL &base_url, SDKBrowserContentNodeRef base_node, InsertNodeFromDataBase *callback, void *user_data);

	//----------------------------------------------------------------------------------------
	/// Creates a new preset node.
	/// @param[in] db_index						The database index. Use @em UserPresetDb for the user preset library, or a value from GetDbIndex() or RegisterPresetLibrary().
	/// @param[in] url								The URL to create the preset node for.
	/// @param[in] plugin_id					The ID of the plugin for the preset node (this should be the same value as SDKBrowserPluginInterface::GetPluginID()).
	/// @param[in] mode								The preset mode.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool CreatePresetNode(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, Int32 mode = 0);

	//----------------------------------------------------------------------------------------
	/// Used to define a custom preset order for a directory.\n
	/// When iterating through the nodes in a directory the content browser will return them in the order that is specified in the array @formatParam{nodes}.\n
	/// @BP3D for example uses this function to change the order of the brush presets.
	/// @param[in] nodes							The nodes array.
	/// @param[in] cnt								The length of the @formatParam{nodes} array.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetPresetSortOrder(SDKBrowserContentNodeRef *nodes, Int32 cnt);

	//----------------------------------------------------------------------------------------
	/// Mounts a preset library.
	/// @param[in] fn									The file name of the library to load.
	/// @param[in] flags							The flags. See @em SDKBrowserPresetLibrary.
	/// @param[out] domain						Assigned the domain of the preset, can be @formatConstant{nullptr}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool MountPresetLibrary(const Filename &fn, UInt32 flags, SDKBrowserURL *domain = nullptr);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Tells the browser about changes in @formatParam{node}.
	/// @param[in] node								The modified node (or parent node).
	/// @param[in] flags							Reserved.
	//----------------------------------------------------------------------------------------
	static void UpdateNotification(SDKBrowserContentNodeRef node, Int32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static Int32 PreviewDialogMisc(SubDialog *dlg, void *&private_data, Int32 cmd, Int32 value0 = 0, Int32 value1 = 0, void *value2 = 0, void *value3 = 0);

	//----------------------------------------------------------------------------------------
	/// Retrieves the browser content node corresponding to @formatParam{url}.
	/// @param[in] url								The URL of the node.
	/// @param[in] flags							The flags. See @em SDKBrowserFind.
	/// @param[in] start_from					An optional start node.
	/// @return												The found node, or @formatConstant{nullptr} if no node was found.
	//----------------------------------------------------------------------------------------
	static SDKBrowserContentNodeRef FindNode(const SDKBrowserURL &url, Int32 flags = FindExactMatch, SDKBrowserContentNodeRef start_from = 0);

	//----------------------------------------------------------------------------------------
	/// Identifies @formatParam{url}.
	/// @param[in] url								The URL to identify.
	/// @param[in] flags							The flags.
	/// @param[in] plugin_out					Assigned the corresponding plugin, if found.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool Identify(const SDKBrowserURL &url, UInt32 flags, SDKBrowserPluginRef *plugin_out);

	/// @}

	/// @name Default Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a default object of type @formatParam{id} if available.
	/// @param[in] id									The object type.
	/// @param[in] flags							The flags.
	/// @return												A clone of the default object. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	static BaseList2D *GetDefaultObject(Int32 id, UInt32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Sets a default object for the type of @formatParam{bl}, overwriting older default library objects for this type.
	/// @param[in] bl									The new default object. The object is cloned. @callerOwnsPointed{object}
	/// @param[in] flags							The flags.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetDefaultObject(BaseList2D *bl, UInt32 flags = 0);

	/// @}
};

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Returns a array of urls for the dragobject of type DRAGTYPE_BROWSER.
/// @param[in] dat								Drag object of the drag and drop type DRAGTYPE_BROWSER.
/// @return												Array with Urls on success.
//----------------------------------------------------------------------------------------
Result<BaseArray<Url>> BrowserReceiveUrls(void* dat);

}

/// Content Browser library ID.
#define BROWSER_LIB_ID 1017645

/// @}


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct BrowserMethods
{
	Bool 						(*OpenNewBrowser)(const SDKBrowserURL &url, UInt32 flags);
	SDKBrowserContentNodeRef	(*GetCategoryNode)(Int32 where);

	SDKBrowserIcon	*(*GetStaticIcon)(Int32 id, Int32 pref_wh);
	SDKBrowserIcon	*(*GetIcon)(const SDKBrowserURL &url, SDKBrowserPluginRef plugin, Int32 flags, LocalFileTime *preview_time);
	SDKBrowserIcon	*(*GetPreviewIcon)(SDKBrowserContentNodeRef content, Int32 pref_wh, Int32 flags);
	SDKBrowserIcon	*(*CreateIcon)(BaseBitmap *bm, Bool dont_free);
	void						(*ReleaseIcon)(SDKBrowserIcon* icon);

	Int32						(*RegisterPresetLibrary)(const SDKBrowserURL &domain, const String &name, const Filename &f);
	Bool						(*UnregisterPresetLibrary)(Int32 db_index, const Filename &f);
	Bool						(*LoadPreset)(Int32 db_index, const SDKBrowserURL &url, Int32 &plugin_id, BaseContainer *bc, void **data, Int *length);
	Bool						(*SavePreset)(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, const BaseContainer *bc, void *data, Int length);
	Bool						(*DeletePreset)(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id);
	SDKBrowsePresets	*(*AllocPresetBrowser)(Int32 db_index);
	void						(*FreePresetBrowser)(SDKBrowsePresets *browse_presets);
	Bool						(*PresetBrowserGetNext)(SDKBrowsePresets *browse_presets, SDKBrowserURL &url, Int32 &plugin_id, Int &id);

	void						(*UpdateNotification)(SDKBrowserContentNodeRef node, Int32 flags);
	Int32						(*PreviewDialogMisc)(SubDialog *dlg, void *&private_data, Int32 cmd, Int32 value0, Int32 value1, void *value2, void *value3);

	SDKBrowserContentNodeRef	(*FindNode)(const SDKBrowserURL &url, Int32 flags, SDKBrowserContentNodeRef start_from);

	Bool						(*RegisterBrowserPlugin)(SDKBrowserPluginRef plugin, UInt32 flags);
	Bool						(*UnregisterBrowserPlugin)(SDKBrowserPluginRef plugin);

	Bool 						(*Identify)(const SDKBrowserURL &url, UInt32 flags, SDKBrowserPluginRef *plugin_out);

	BaseList2D 			*(*GetDefaultObject)(Int32 id, UInt32 flags);
	Bool 						(*SetDefaultObject)(BaseList2D *bl, UInt32 flags);

	Bool						(*ReadNodesFromDatabase)(Int32 db_index, const SDKBrowserURL &base_url, SDKBrowserContentNodeRef base_node, SDKBrowser::InsertNodeFromDataBase *callback, void *user_data);

	Bool						(*GetPresetName)(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, String &out_name);
	Bool						(*SetPresetName)(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, const String &name);
	Bool						(*GetPresetAnnotation)(Int32 db_index, const SDKBrowserURL &url, String &annotation);
	Bool						(*SetPresetAnnotation)(Int32 db_index, const SDKBrowserURL &url, const String &annotation);
	Bool						(*SavePresetObject)(const SDKBrowserURL &url, BaseList2D *bl);
	Bool						(*ChangePresetURL)(Int32 db_index, const SDKBrowserURL &url, const SDKBrowserURL &new_url, Int32 plugin_id);
	Int32						(*GetDbIndex)(const SDKBrowserURL &url, UInt32 flags);
	Bool						(*CreatePresetNode)(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, Int32 mode);

	BaseBitmap			*(*GetIconBaseBitmap)(SDKBrowserIcon* icon);
	Bool						(*SetPresetPreview)(Int32 db_index, const SDKBrowserURL &url, Int32 mode, Int32 preview_quality, BaseBitmap *bm, const LocalFileTime *lft);

	Bool						(*MountPresetLibrary)(const Filename &fn, UInt32 flags, SDKBrowserURL *domain);
	Bool						(*CopyPreset)(const SDKBrowserURL &src, const SDKBrowserURL &dst);
	Bool						(*SetSortOrder)(Int32 mode, SDKBrowserContentNodeRef *nodes, Int32 cnt, void *reserved);
	Bool						(*ExistsPreset)(const SDKBrowserURL &url);

	BaseBitmap			*(*GetPresetPreview)(Int32 db_index, const SDKBrowserURL &url, Int32 frame_idx);
	Bool						(*GetPresetAnimationData)(Int32 db_index, const SDKBrowserURL &url, Int32 *first_frame_idx, Int32 *last_frame_idx, Float *fps);
	Bool						(*SetPresetAnimationData)(Int32 db_index, const SDKBrowserURL &url, Int32 first_frame_idx, Int32 last_frame_idx, Float fps);

	Bool						(*OpenNewBrowserWithTitle)(const SDKBrowserURL &path, const String& custom_title, UInt32 flags);
	void						*reserved[64 - 41];	// reserved pointers
};

//////////////////////////////////////////////////////////////////////////

struct BrowserURLMethods
{
	void			(*Init)(void *priv);
	void			(*Flush)(void *priv);
	void			(*Copy)(void *priv, void *src);
	void			(*AddString)(void *priv, const String &src);
	void			(*SetFilename)(void *priv, const Filename &src);
	void			(*SetString)(void *priv, const String &src);
	Bool			(BrowserURL::*GetFilename)(Filename &f) const;
	void			(BrowserURL::*GetString)(String &s) const;
	void			(BrowserURL::*GetDirectory)(BrowserURL &priv) const;
	String		(BrowserURL::*GetFileString)(void) const;
	Bool			(BrowserURL::*IsFilename)(void) const;
	Bool			(BrowserURL::*CheckSuffix)(const String &s) const;
	String		(BrowserURL::*GetSuffix)(void) const;
	Bool			(BrowserURL::*IsPopulated)() const;

	void			*reserved[(32 - 14)];	// reserved pointers
};

//////////////////////////////////////////////////////////////////////////

struct ReferenceObjectMethods
{
	void	(ReferenceObject::*add_reference)(void);
	void	(ReferenceObject::*remove_reference)(void);
	void	*reserved[6 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////

struct RTreeNodeMethods
{
	SDKReferenceObjectPtr<RTreeNode>	(RTreeNode::*GetUp)(void) const;
	SDKReferenceObjectPtr<RTreeNode>	(RTreeNode::*GetDown)(void) const;
	SDKReferenceObjectPtr<RTreeNode>	(RTreeNode::*GetNext)(void) const;
	SDKReferenceObjectPtr<RTreeNode>	(RTreeNode::*GetPred)(void) const;

	void		(RTreeNode::*InsertUnder)(SDKReferenceObjectPtr<RTreeNode> parent);
	void		(RTreeNode::*Remove)(void);

	void		*reserved[10 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};


//////////////////////////////////////////////////////////////////////////

struct SDKBrowserContentNodeMethods
{
	Bool								(SDKBrowserContentNodeInfo::*Init)(void *node);
	void								(SDKBrowserContentNodeInfo::*Free)(void);
	Int32								(SDKBrowserContentNodeInfo::*GetTypeID)(void);
	SDKBrowserPluginRef	(SDKBrowserContentNodeInfo::*GetPlugin)(UInt32 flags);

	String							(SDKBrowserContentNodeInfo::*GetName)(void);
	Int32								(SDKBrowserContentNodeInfo::*GetNodeURL)(SDKBrowserURL &url, UInt32 flags) const;
	Bool								(SDKBrowserContentNodeInfo::*GetNodeTime)(UInt32 mode, LocalFileTime *out);
	UInt32								(SDKBrowserContentNodeInfo::*GetNodeFlags)(Int64 *out_size);

	SDKBrowserIcon			*(SDKBrowserContentNodeInfo::*GetIcon)(Int32 flags, Int32 pref_wh);

	Int32								(SDKBrowserContentNodeInfo::*UpdateDirectory)(void);

	Int32								(SDKBrowserContentNodeInfo::*PrivateCall)(Int32 plugin_id, Int32 node_type, Int32 selector, void *data);

	Int32								(SDKBrowserContentNodeInfo::*Rename)(Int32 mode, const String &name);
	Int32								(SDKBrowserContentNodeInfo::*NewFolder)(Int32 mode, const String &name, SDKBrowserContentNodeRef *folder);
	Int32								(SDKBrowserContentNodeInfo::*MoveFrom)(SDKBrowserContentNodeRef new_child, Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread);
	Int32								(SDKBrowserContentNodeInfo::*CopyFrom)(SDKBrowserContentNodeRef new_child, Int32 mode, const String *rename, CopyMoveCallback *callback, void *private_data, BaseThread *thread);
	Int32								(SDKBrowserContentNodeInfo::*Delete)(Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread);

	String							(SDKBrowserContentNodeInfo::*GetTypeName)(Int32 mode) const;

	void								*reserved[15 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////

struct BrowserContentNodeMethods
{
	SDKBrowserContentNodeRef			(*Alloc)(SDKBrowserContentNodeInfo *node_info, SDKBrowserContentNodeMethods *node_ptmf);
	SDKBrowserContentNodeRef			(*AllocCategoryNode)(const String &name, const String &local_path, const Filename &icon_file);
	void													(*FreeNodes)(Int32 plugin_id);

	SDKBrowserContentNodeInfo			*(*GetNodeInfo)(const SDKBrowserContentNode *node, Int32 plugin_id);

	Int32													(BrowserContentNode::*GetTypeID)(void) const;
	SDKBrowserPluginRef						(BrowserContentNode::*GetPlugin)(UInt32 flags) const;

	String												(BrowserContentNode::*GetName)(void) const;
	Int32													(BrowserContentNode::*GetNodeURL)(BrowserURL &url, UInt32 flags) const;
	Bool													(BrowserContentNode::*GetNodeTime)(UInt32 mode, LocalFileTime *out) const;
	UInt32													(BrowserContentNode::*GetNodeFlags)(Int64 *out_size) const;

	SDKBrowserIcon								*(BrowserContentNode::*GetIcon)(Int32 flags, Int32 pref_wh) const;

	Int32													(BrowserContentNode::*UpdateDirectory)(void) const;
	Int32													(BrowserContentNode::*PrivateCall)(Int32 plugin_id, Int32 node_type, Int32 selector, void *data);	// Hook for private calls

	Int32													(BrowserContentNode::*Rename)(Int32 mode, const String &name);
	Int32													(BrowserContentNode::*NewFolder)(Int32 mode, const String &name, SDKBrowserContentNodeRef *folder);
	Int32													(BrowserContentNode::*MoveFrom)(SDKBrowserContentNodeRef new_child, Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread);
	Int32													(BrowserContentNode::*CopyFrom)(SDKBrowserContentNodeRef new_child, Int32 mode, const String *rename, CopyMoveCallback *callback, void *private_data, BaseThread *thread);
	Int32													(BrowserContentNode::*Delete)(Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread);

	String												(BrowserContentNode::*GetTypeName)(Int32 mode) const;

	void													*reserved[13 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////

struct SDKBrowserPluginInterfaceMethods
{
	Int32									(SDKBrowserPluginInterfaceInfo::*GetPluginID)(String *plugin_name);
	Bool									(SDKBrowserPluginInterfaceInfo::*Identify)(const SDKBrowserURL &url, UChar *probe, Int32 size, UInt32 flags);
	String								(SDKBrowserPluginInterfaceInfo::*GetTypeName)(const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 mode);
	void									(SDKBrowserPluginInterfaceInfo::*GetTypeNames)(Int32 mode, maxon::BaseArray<String>& strings);

	SDKBrowserPreviewData	*(SDKBrowserPluginInterfaceInfo::*OpenPreviewBitmap)(BaseThread *thread, const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, SDKBrowserPreviewInfo *info);
	void									(SDKBrowserPluginInterfaceInfo::*ClosePreviewBitmap)(SDKBrowserPreviewData *data);
	BaseBitmap						*(SDKBrowserPluginInterfaceInfo::*GetPreviewBitmap)(SDKBrowserPreviewData *data, Int32 w, Int32 h, Int32 quality);

	SDKBrowserIcon				*(SDKBrowserPluginInterfaceInfo::*GetIcon)(const SDKBrowserURL &url, Int32 pref_wh);

	SubDialog							*(SDKBrowserPluginInterfaceInfo::*OpenPreviewDialog)(SDKBrowserContentNodeRef node, Int32 tab_id);
	Int32									(SDKBrowserPluginInterfaceInfo::*ClosePreviewDialog)(SDKBrowserContentNodeRef node, SubDialog *s);
	Bool									(SDKBrowserPluginInterfaceInfo::*Open)(SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 flags);
	Int32									(SDKBrowserPluginInterfaceInfo::*UpdatePreviewDialog)(SDKBrowserContentNodeRef node, SubDialog *s);

	void									*reserved[20 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////

struct BrowserPluginInterfaceMethods
{
	SDKBrowserPluginRef			(*Alloc)(SDKBrowserPluginInterfaceInfo *plugin_info, SDKBrowserPluginInterfaceMethods *plugin_ptmf);
	void										(*Free)(SDKBrowserPluginRef plugin);

	Int32										(BrowserPluginInterface::*GetPluginID)(String *plugin_name);

	Bool										(BrowserPluginInterface::*Identify)(const SDKBrowserURL &url, UChar *probe, Int32 size, UInt32 flags);
	String									(BrowserPluginInterface::*GetTypeName)(const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 mode);
	void										(BrowserPluginInterface::*GetTypeNames)(Int32 mode, maxon::BaseArray<String>& strings);

	SDKBrowserPreviewData		*(BrowserPluginInterface::*OpenPreviewBitmap)(BaseThread *thread, const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, SDKBrowserPreviewInfo *info);
	void										(BrowserPluginInterface::*ClosePreviewBitmap)(SDKBrowserPreviewData *data);
	BaseBitmap							*(BrowserPluginInterface::*GetPreviewBitmap)(SDKBrowserPreviewData *data, Int32 w, Int32 h, Int32 quality);

	SDKBrowserIcon					*(BrowserPluginInterface::*GetIcon)(const SDKBrowserURL &url, Int32 pref_wh);

	SubDialog								*(BrowserPluginInterface::*OpenPreviewDialog)(SDKBrowserContentNodeRef content, Int32 tab_id);
	Int32										(BrowserPluginInterface::*ClosePreviewDialog)(SDKBrowserContentNodeRef content, SubDialog *s);
	Bool										(BrowserPluginInterface::*Open)(SDKBrowserContentNodeRef content, const SDKBrowserURL *url, Int32 flags);
	Int32										(BrowserPluginInterface::*UpdatePreviewDialog)(SDKBrowserContentNodeRef node, SubDialog *s);

	void										*reserved[18 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////

struct BrowserLib : public C4DLibrary
{
	ReferenceObjectMethods reference_object;
	BrowserMethods *browser;
	BrowserURLMethods *browser_url;
	RTreeNodeMethods *rtree_node;
	BrowserContentNodeMethods *content_node;
	BrowserPluginInterfaceMethods *plugin_itf;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_BROWSER_H__
