#include "lib_browser.h"
#include "c4d_gui.h"

//////////////////////////////////////////////////////////////////////////

BrowserLib *lib_browser = nullptr;

Bool															plugin_ptmf_valid = false;
SDKBrowserPluginInterfaceMethods	plugin_ptmf;

Bool															node_ptmf_valid = false;
SDKBrowserContentNodeMethods			node_ptmf;

static inline BrowserLib *CheckBrowserLib(Int32 offset)
{
	return (BrowserLib *) CheckLib(BROWSER_LIB_ID, offset, (C4DLibrary **) &lib_browser);
}

//////////////////////////////////////////////////////////////////////////


#define BrowserCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser)); \
	if (!lib || !lib->browser)	\
		return; \
	(((iBrowser *)this)->*lib->browser->method)

#define BrowserCallR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser)); \
	if (!lib || !lib->browser)	\
		return error_value; \
	return (((iBrowser *)this)->*lib->browser->method)

#define BrowserCallS( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser)); \
	if (!lib || !lib->browser)	\
		return; \
	lib->browser->method

#define BrowserCallSR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser)); \
	if (!lib || !lib->browser)	\
		return error_value; \
	return lib->browser->method

Bool	SDKBrowser::OpenNewBrowser(const SDKBrowserURL &path, UInt32 flags)
{
	BrowserCallSR(OpenNewBrowser, false)(path, flags);
}

Bool	SDKBrowser::OpenNewBrowserWithTitle(const SDKBrowserURL &path, const String& custom_title, UInt32 flags)
{
	BrowserCallSR(OpenNewBrowserWithTitle, false)(path, custom_title, flags);
}

SDKBrowserContentNodeRef	SDKBrowser::GetCategoryNode(Int32 where)
{
	BrowserCallSR(GetCategoryNode, 0)(where);
}

SDKBrowserIcon	*SDKBrowser::GetIcon(Int32 id, Int32 pref_wh)
{
	BrowserCallSR(GetStaticIcon, 0)(id, pref_wh);
}

SDKBrowserIcon	*SDKBrowser::GetIcon(const SDKBrowserURL &url, SDKBrowserPluginRef plugin, Int32 flags, LocalFileTime *preview_time)
{
	BrowserCallSR(GetIcon, 0)(url, plugin, flags, preview_time);
}

//----------------------------------------------------------------------------------------
// Return the pointer to a preview icon. If no preview is available the default icon for
// this type of node will be returned. The browser will cache the icon.
// Function result:		icon pointer
// node:							the node for which an icon will be returned
// pref_wh:						preferred width/height of the icon
// flags:							reserved
//----------------------------------------------------------------------------------------
SDKBrowserIcon	*SDKBrowser::GetPreviewIcon(SDKBrowserContentNodeRef node, Int32 pref_wh, Int32 flags)
{
	BrowserCallSR(GetPreviewIcon, 0)(node, pref_wh, flags);
}

SDKBrowserIcon	*SDKBrowser::CreateIcon(BaseBitmap *bm, Bool dont_free)
{
	BrowserCallSR(CreateIcon, 0)(bm, dont_free);
}

void	SDKBrowser::ReleaseIcon(SDKBrowserIcon *icon)
{
	BrowserCallS(ReleaseIcon )(icon);
}

Bool	SDKBrowser::RegisterBrowserPlugin(SDKBrowserPluginInterfaceInfo *plugin_info, UInt32 flags)
{
	SDKBrowserPluginRef	plugin;

	plugin = SDKBrowserPluginInterface::Alloc(plugin_info);
	if (plugin)
	{
		plugin_info->plugin = plugin;
		BrowserCallSR(RegisterBrowserPlugin, false)(plugin, flags);
	}
	return false;
}

Bool	SDKBrowser::UnregisterBrowserPlugin(SDKBrowserPluginInterfaceInfo *plugin_info)
{
	BrowserLib	*lib = nullptr;
	Bool	success = false;

	lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser));
	if (!lib || !lib->browser)
		return false;

	if (plugin_info)
	{
		success = lib->browser->UnregisterBrowserPlugin(plugin_info->plugin);
		SDKBrowserPluginInterface::Free(plugin_info->plugin);
	}
	return success;
}

//----------------------------------------------------------------------------------------
// Register (create) a preset database. If you want the database to appear in the CB
// you have to call MountPresetLibrary.
// Function result:		database index (< 0: error)
// name:							name of the database (for the ui)
// f:									file name and path
//----------------------------------------------------------------------------------------
Int32	SDKBrowser::RegisterPresetLibrary(const SDKBrowserURL &domain, const String &name, const Filename &f)
{
	BrowserCallSR(RegisterPresetLibrary, -1 )(domain, name, f);
}

//----------------------------------------------------------------------------------------
// Unregister (save and free the memory) a preset database. If the library is mounted
// (displayed by the CB) this will fail and return false.
// Function result:		true if successful
// db_index:					database index returned by RegisterPresetLibrary
// f:									file name and path
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::UnregisterPresetLibrary(Int32 db_index, const Filename &f)
{
	BrowserCallSR(UnregisterPresetLibrary, false)(db_index, f);
}

Int32	SDKBrowser::GetDbIndex(const SDKBrowserURL &url, UInt32 flags)
{
	BrowserCallSR(GetDbIndex, -1 )(url, flags);
}

Bool	SDKBrowser::CreatePresetNode(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, Int32 mode)
{
	BrowserCallSR(CreatePresetNode, false)(db_index, url, plugin_id, mode);
}

Bool	SDKBrowser::SetPresetSortOrder(SDKBrowserContentNodeRef *nodes, Int32 cnt)
{
	BrowserCallSR(SetSortOrder, false)(0, nodes, cnt, nullptr);
}

Bool	SDKBrowser::ExistsPreset(const SDKBrowserURL &url)
{
	BrowserCallSR(ExistsPreset, false)(url);
}

//----------------------------------------------------------------------------------------
// Load data for a preset node in a specific preset database
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// plugin_id:					id of the plugin that saved the data will be returned here
// bc:								pointer to an info basecontainer (can be 0 if you don't want to read the info container)
// data:							used to return a memory block with private node data, the memory will be owned by the caller
//										(can be 0 if you don't want to read the private node data from the preset library)
// length:						used to return the length of the private node data in bytes
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::LoadPreset(Int32 db_index, const SDKBrowserURL &url, Int32 &plugin_id, BaseContainer *bc, void **data, Int *length)
{
	BrowserCallSR(LoadPreset, false)(db_index, url, plugin_id, bc, data, length);
}

//----------------------------------------------------------------------------------------
// Save data for a preset in a specific preset database. Call SetPresetAnnotation(),
// SetPresetName(), SetPresetPreview() etc. to add metadata
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// plugin_id:					id of the plugin that saves the data (this should be the same value as SDKBrowserPluginInterface::GetPluginID())
// bc:								pointer to an info basecontainer (can be 0)
// data:							memory block with private node data (the caller owns the memory block, can be 0)
// length:						length of the private node data in bytes
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::SavePreset(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id, const BaseContainer *bc, void *data, Int length)
{
	BrowserCallSR(SavePreset, false)(db_index, url, plugin_id, bc, data, length);
}

//----------------------------------------------------------------------------------------
// Delete a preset in a specific preset database
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// plugin_id:					id of the plugin that saved the data (this should be the same value as SDKBrowserPluginInterface::GetPluginID())
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::DeletePreset(Int32 db_index, const SDKBrowserURL &url, Int32 plugin_id)
{
	BrowserCallSR(DeletePreset, false)(db_index, url, plugin_id);
}

//----------------------------------------------------------------------------------------
// Copy a preset (including all metadata). The destination url can be in a different
// database than the source. If you copy a folder preset just the folder (without children)
// will be copied.
// Function result:		true if successful
// src:								url of the source preset
// dst:								url of the destination preset
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::CopyPreset(const SDKBrowserURL &src, const SDKBrowserURL &dst)
{
	BrowserCallSR(CopyPreset, false)(src, dst);
}

//----------------------------------------------------------------------------------------
// Copy a preset (including all metadata). The destination url can be in a different
// database than the source.
// Function result:		true if successful
// src:								url of the source preset
// dst:								url of the destination preset
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::ChangePresetURL(Int32 db_index, const SDKBrowserURL &url, const SDKBrowserURL &new_url, Int32 plugin_id)
{
	BrowserCallSR(ChangePresetURL, false)(db_index, url, new_url, plugin_id);
}

//----------------------------------------------------------------------------------------
// Return the language specific name of a preset
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// language_id:				0 for the default language
// out_name:					used to return the name
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::GetPresetName(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, String &out_name)
{
	BrowserCallSR(GetPresetName, false)(db_index, url, language_id, out_name);
}

//----------------------------------------------------------------------------------------
// Set the language specific name of a preset
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// language_id:				0 for the default language
// name:							preset name in language_id
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::SetPresetName(Int32 db_index, const SDKBrowserURL &url, Int32 language_id, const String &name)
{
	BrowserCallSR(SetPresetName, false)(db_index, url, language_id, name);
}

//----------------------------------------------------------------------------------------
// Return the annotation string of a preset
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// annotation:				used to return the annotation string
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::GetPresetAnnotation(Int32 db_index, const SDKBrowserURL &url, String &annotation)
{
	BrowserCallSR(GetPresetAnnotation, false)(db_index, url, annotation);
}

//----------------------------------------------------------------------------------------
// Set the annotation string of a preset
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// annotation:				the annotation string
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::SetPresetAnnotation(Int32 db_index, const SDKBrowserURL &url, const String &annotation)
{
	BrowserCallSR(SetPresetAnnotation, false)(db_index, url, annotation);
}

//----------------------------------------------------------------------------------------
// Set the preview bitmap of a preset
// Function result:		true if successful
// db_index:					database index (returned by RegisterPresetLibrary)
// url:								url of the preset node
// mode:							PreviewReplace (replace all existing previews) or PreviewAppend (add further preview)
// preview_quality:		usually this should be SDKBrowserPreviewInfo::HighQuality
// bm:								pointer to the preview bitmap (owned by the caller)
// lft:								modification time stamp of the preset
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::SetPresetPreview(Int32 db_index, const SDKBrowserURL &url,  Int32 mode, Int32 preview_quality, BaseBitmap *bm, const LocalFileTime *lft)
{
	BrowserCallSR(SetPresetPreview, false)(db_index, url, mode, preview_quality, bm, lft);
}

BaseBitmap	*SDKBrowser::GetPresetPreview(Int32 db_index, const SDKBrowserURL &url, Int32 frame_idx)
{
	BrowserCallSR(GetPresetPreview, nullptr )(db_index, url, frame_idx);
}

Bool	SDKBrowser::GetPresetAnimationData(Int32 db_index, const SDKBrowserURL &url, Int32 *first_frame_idx, Int32 *last_frame_idx, Float *fps)
{
	BrowserCallSR(GetPresetAnimationData, false)(db_index, url, first_frame_idx, last_frame_idx, fps);
}

Bool	SDKBrowser::SetPresetAnimationData(Int32 db_index, const SDKBrowserURL &url, Int32 first_frame_idx, Int32 last_frame_idx, Float fps)
{
	BrowserCallSR(SetPresetAnimationData, false)(db_index, url, first_frame_idx, last_frame_idx, fps);
}

//----------------------------------------------------------------------------------------
// Save a BaseList2D object as preset - an already existing node with the url will be replaced
// Function result:		true if successful
// url:								url of the preset (there must a node for the directory url!)
// bl:								the baselist object
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::SavePresetObject(const SDKBrowserURL &url, BaseList2D *bl)
{
	BrowserCallSR(SavePresetObject, false)(url, bl);
}

//----------------------------------------------------------------------------------------
// Mount a preset library
// Function result:		true: preset library mounted
// nf:								library filename
// flags:							ReadOnlyPresetLibrary, SystemPresetLibrary
//----------------------------------------------------------------------------------------
Bool	SDKBrowser::MountPresetLibrary(const Filename &fn, UInt32 flags, SDKBrowserURL *domain)
{
	BrowserCallSR(MountPresetLibrary, false)(fn, flags, domain);
}

Bool	SDKBrowser::ReadNodesFromDatabase(Int32 db_index, const SDKBrowserURL &base_url, SDKBrowserContentNodeRef base_node, InsertNodeFromDataBase *callback, void *user_data)
{
	BrowserCallSR(ReadNodesFromDatabase, false)(db_index, base_url, base_node, callback, user_data);
}

//----------------------------------------------------------------------------------------
// Notification for changed node (either called for a single node or its parent node)
// Function result:		-
// node:							modified node (or parent node)
// flags:							reserved
//----------------------------------------------------------------------------------------
void	SDKBrowser::UpdateNotification(SDKBrowserContentNodeRef node, Int32 flags)
{
	BrowserCallS(UpdateNotification )(node, flags);
}

Int32	SDKBrowser::PreviewDialogMisc(SubDialog *dlg, void *&private_data, Int32 cmd, Int32 value0, Int32 value1, void *value2, void *value3)
{
	BrowserCallSR(PreviewDialogMisc, 0)(dlg, private_data, cmd, value0, value1, value2, value3);
}

//----------------------------------------------------------------------------------------
// Return the browser content node corresponding to the url
// Function result:		browser content node or 0 (path not found)
// url:								url of the node
// flags:							FindExactMatch: return only a node with an exact match for the url
//										FindBestMatch: return the nearest parent node if there is no exact match for the url
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeRef	SDKBrowser::FindNode(const SDKBrowserURL &url, Int32 flags, SDKBrowserContentNodeRef start_from)
{
	BrowserCallSR(FindNode, 0)(url, flags, start_from);
}

Bool SDKBrowser::Identify(const SDKBrowserURL &url, UInt32 flags, SDKBrowserPluginRef *plugin_out)
{
	BrowserCallSR(Identify, false)(url, flags, plugin_out);
}

// liefert das Objekt vom Typ 'id' zurueck - falls vorhanden
BaseList2D *SDKBrowser::GetDefaultObject(Int32 id, UInt32 flags)
{
	BrowserCallSR(GetDefaultObject, 0)(id, flags);
}

// fuegt Objekt 'bl' zur Default-Lib hinzu. Falls eines schon vorhanden ist, wird das ueberplaettet
Bool SDKBrowser::SetDefaultObject(BaseList2D *bl, UInt32 flags)
{
	BrowserCallSR(SetDefaultObject, false)(bl, flags);
}


//////////////////////////////////////////////////////////////////////////

SDKBrowsePresets	*SDKBrowsePresets::Alloc(Int32 db_index)
{
	BrowserCallSR(AllocPresetBrowser, 0)(db_index);
}

void	SDKBrowsePresets::Free(SDKBrowsePresets *browse_presets)
{
	BrowserCallS(FreePresetBrowser )(browse_presets);
}

//----------------------------------------------------------------------------------------
// Browse thru a preset database ...
// Function result:		true: item found
// url:								used to return the url of the preset item
// plugin_id:					used to return the id of the plugin that created the item
//----------------------------------------------------------------------------------------
Bool	SDKBrowsePresets::GetNext(SDKBrowserURL &url, Int32 &plugin_id)
{
	Int	reserved;

	BrowserCallSR(PresetBrowserGetNext, false)(this, url, plugin_id, reserved);
}

//////////////////////////////////////////////////////////////////////////

void	SDKBrowserIcon::Free(SDKBrowserIcon *icon)
{
	BrowserCallS(ReleaseIcon )(icon);
}

BaseBitmap	*SDKBrowserIcon::GetBaseBitmap(void)
{
	BrowserCallSR(GetIconBaseBitmap, nullptr )(this);
}

//////////////////////////////////////////////////////////////////////////

#define BrowserURLCallS( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser_url)); \
	if (!lib || !lib->browser_url)	\
		return; \
	(lib->browser_url->method)

#define BrowserURLCallSR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser_url)); \
	if (!lib || !lib->browser_url)	\
		return error_value; \
	return (lib->browser_url->method)

#define BrowserURLCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser_url)); \
	if (!lib || !lib->browser_url)	\
		return; \
	(((BrowserURL *)this)->*lib->browser_url->method)

#define BrowserURLCallR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, browser_url)); \
	if (!lib || !lib->browser_url)	\
		return error_value; \
	return (((BrowserURL *)this)->*lib->browser_url->method)

//----------------------------------------------------------------------------------------
// Initialize a BrowserURL
// Function result:		-
//----------------------------------------------------------------------------------------
SDKBrowserURL::SDKBrowserURL(void)
{
	BrowserURLCallS(Init )(GetPrivate());
}

//----------------------------------------------------------------------------------------
// Initialize a BrowserURL with the content of a source url
// Function result:		-
// src:								url will be copied
//----------------------------------------------------------------------------------------
SDKBrowserURL::SDKBrowserURL(const SDKBrowserURL &src)
{
	BrowserURLCallS(Init )(GetPrivate());
	lib->browser_url->Copy(GetPrivate(), src.GetPrivate());
}

//----------------------------------------------------------------------------------------
// Initialize a BrowserURL with a file name
// Function result:		-
// src:								file name
//----------------------------------------------------------------------------------------
SDKBrowserURL::SDKBrowserURL(const Filename &src)
{
	BrowserURLCallS(Init )(GetPrivate());
	lib->browser_url->SetFilename(GetPrivate(), src);
}

//----------------------------------------------------------------------------------------
// Initialize a BrowserURL with a string
// Function result:		-
// src:								string ("e.g. "file://localhost/bla.jpg")
//----------------------------------------------------------------------------------------
SDKBrowserURL::SDKBrowserURL(const maxon::String &src)
{
	BrowserURLCallS(Init )(GetPrivate());
	lib->browser_url->SetString(GetPrivate(), src);
}

SDKBrowserURL::~SDKBrowserURL(void)
{
	BrowserURLCallS(Flush )(GetPrivate());
}

const SDKBrowserURL &SDKBrowserURL::operator = (const SDKBrowserURL &src)
{
	BrowserLib *lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser_url));
	if (lib)
		lib->browser_url->Copy(GetPrivate(), src.GetPrivate());
	return *this;
}

//----------------------------------------------------------------------------------------
// Add a string to the path of a url
// Function result:		new url
// str:								additional path
//----------------------------------------------------------------------------------------
const SDKBrowserURL SDKBrowserURL::operator + (const String &str) const
{
	SDKBrowserURL	url(*this);

	BrowserLib *lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser_url));
	if (lib)
		lib->browser_url->AddString(url.GetPrivate(), str);
	return 	url;
}

//----------------------------------------------------------------------------------------
// Add a string to the path of this url
// Function result:		this url
// str:								additional path
//----------------------------------------------------------------------------------------
const SDKBrowserURL	&SDKBrowserURL::operator += (const String &str)
{
	BrowserLib *lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser_url));

	if (lib)
		lib->browser_url->AddString(GetPrivate(), str);

	return *this;
}

//----------------------------------------------------------------------------------------
// Check for equality
// Function result:		true: equal false: not equal
// url								...
//----------------------------------------------------------------------------------------
Bool	SDKBrowserURL::operator == (const SDKBrowserURL &url) const
{
	String	s1;
	String	s2;

	s1 = GetString();
	s2 = url.GetString();
	return (s1.LexCompare(s2) == 0);
}

//----------------------------------------------------------------------------------------
// Check for inequality
// Function result:		true: not equal false: equal
// url								...
//----------------------------------------------------------------------------------------
Bool	SDKBrowserURL::operator != (const SDKBrowserURL &url) const
{
	String	s1;
	String	s2;

	s1 = GetString();
	s2 = url.GetString();
	return (s1.LexCompare(s2) != 0);
}

Bool	SDKBrowserURL::IsPopulated() const
{
	BrowserURLCallR(IsPopulated, false)();
}

//----------------------------------------------------------------------------------------
// Assign a file name to the url
// Function result:		-
// src:								file name
//----------------------------------------------------------------------------------------
void	SDKBrowserURL::SetFilename(const Filename &src)
{
	BrowserURLCallS(SetFilename )(GetPrivate(), src);
}

//----------------------------------------------------------------------------------------
// Assign a string to the url
// Function result:		-
// src:								string
//----------------------------------------------------------------------------------------
void	SDKBrowserURL::SetString(const String &src)
{
	BrowserURLCallS(SetString )(GetPrivate(), src);
}

//----------------------------------------------------------------------------------------
// Return url as Filename
// Function result:		true: url represents a file false: location is not in the file system
// f:									used to return the file name
//----------------------------------------------------------------------------------------
Bool	SDKBrowserURL::GetFilename(Filename &f) const
{
	BrowserURLCallR(GetFilename, false)(f);
}

//----------------------------------------------------------------------------------------
// Return url as Filename
// Function result:		file name (empty if the location is not in the file system)
//----------------------------------------------------------------------------------------
Filename	SDKBrowserURL::GetFilename(void) const
{
	Filename	f;

	GetFilename(f);
	return f;
}

//----------------------------------------------------------------------------------------
// Return url as string (file names will be returned as "file://localhost/ ...")
// Function result:		-
// s:									used to return the url string
//----------------------------------------------------------------------------------------
void	SDKBrowserURL::GetString(String &s) const
{
	BrowserURLCall(GetString )(s);
}

//----------------------------------------------------------------------------------------
// Return url as string (file names will be returned as "file://localhost/ ...")
// Function result:		url string
//----------------------------------------------------------------------------------------
String	SDKBrowserURL::GetString(void) const
{
	String	s;

	GetString(s);
	return s;
}

//----------------------------------------------------------------------------------------
// Return the url of the parent diretory
// Function result:		url of the parent directory
//----------------------------------------------------------------------------------------
SDKBrowserURL	SDKBrowserURL::GetDirectory(void) const
{
	SDKBrowserURL	tmp;

	BrowserLib *lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser_url));
	if (!lib || !lib->browser_url)
		return tmp;
	(((BrowserURL *)this)->*lib->browser_url->GetDirectory)(*(BrowserURL *) &tmp);

	return tmp;
}

//----------------------------------------------------------------------------------------
// Return the local file name only (without the path)
// Function result:		file name string
//----------------------------------------------------------------------------------------
String			SDKBrowserURL::GetFileString(void) const
{
	BrowserURLCallR(GetFileString, "" )();
}

//----------------------------------------------------------------------------------------
// Check if the url can be represented as a Filename
// Function result:		true/false
//----------------------------------------------------------------------------------------
Bool				SDKBrowserURL::IsFilename(void) const
{
	BrowserURLCallR(IsFilename, false)();
}

//----------------------------------------------------------------------------------------
// Check if the suffix of the url is the same as the string
// Function result:		true/false
// s:									suffix string (without dot, eg. "c4d")
//----------------------------------------------------------------------------------------
Bool				SDKBrowserURL::CheckSuffix(const String &s) const
{
	BrowserURLCallR(CheckSuffix, false)(s);
}

//----------------------------------------------------------------------------------------
// Return the suffix of the url (always in lower case!)
// Function result:		suffix string (without dot, eg. "c4d")
//----------------------------------------------------------------------------------------
String			SDKBrowserURL::GetSuffix(void) const
{
	BrowserURLCallR(GetSuffix, "" )();
}

void	*SDKBrowserURL::GetPrivate(void) const
{
	return ((void *) this);
}

//////////////////////////////////////////////////////////////////////////


#define BrowserPluginInterfaceCallR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, plugin_itf)); \
	if (!lib || !lib->plugin_itf)	\
		return error_value; \
	return (((BrowserPluginInterface *)this)->*lib->plugin_itf->method)

#define BrowserPluginInterfaceCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, plugin_itf)); \
	if (!lib || !lib->plugin_itf)	\
		return; \
	(((BrowserPluginInterface *)this)->*lib->plugin_itf->method)

#define BrowserPluginInterfaceCallSR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, plugin_itf)); \
	if (!lib || !lib->plugin_itf)	\
		return error_value; \
	return (lib->plugin_itf->method)

#define BrowserPluginInterfaceCallS( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, plugin_itf)); \
	if (!lib || !lib->plugin_itf)	\
		return; \
	lib->plugin_itf->method

SDKBrowserPluginRef	SDKBrowserPluginInterface::Alloc(SDKBrowserPluginInterfaceInfo *plugin_info)
{
	if (plugin_ptmf_valid == false)
	{
		ClearMem(&plugin_ptmf, sizeof(plugin_ptmf));
		plugin_ptmf.GetPluginID = &SDKBrowserPluginInterfaceInfo::GetPluginID;
		plugin_ptmf.Identify = &SDKBrowserPluginInterfaceInfo::Identify;
		plugin_ptmf.GetTypeName = &SDKBrowserPluginInterfaceInfo::GetTypeName;
		plugin_ptmf.GetTypeNames = &SDKBrowserPluginInterfaceInfo::GetTypeNames;
		plugin_ptmf.OpenPreviewBitmap = &SDKBrowserPluginInterfaceInfo::OpenPreviewBitmap;
		plugin_ptmf.ClosePreviewBitmap = &SDKBrowserPluginInterfaceInfo::ClosePreviewBitmap;
		plugin_ptmf.GetPreviewBitmap = &SDKBrowserPluginInterfaceInfo::GetPreviewBitmap;
		plugin_ptmf.GetIcon = &SDKBrowserPluginInterfaceInfo::GetIcon;
		plugin_ptmf.OpenPreviewDialog = &SDKBrowserPluginInterfaceInfo::OpenPreviewDialog;
		plugin_ptmf.ClosePreviewDialog = &SDKBrowserPluginInterfaceInfo::ClosePreviewDialog;
		plugin_ptmf.Open = &SDKBrowserPluginInterfaceInfo::Open;
		plugin_ptmf.UpdatePreviewDialog = &SDKBrowserPluginInterfaceInfo::UpdatePreviewDialog;
		plugin_ptmf_valid = true;
	}

	BrowserPluginInterfaceCallSR(Alloc, nullptr )(plugin_info, &plugin_ptmf);
}

void	SDKBrowserPluginInterface::Free(SDKBrowserPluginRef &plugin)
{
	BrowserPluginInterfaceCallS(Free )(plugin);
	plugin = nullptr;
}

//----------------------------------------------------------------------------------------
// Return the ID of the plugin (unique ID from plugincafe.com)
// Function result:		plugin id
// plugin_name:				used to return the name (can be zero)
//----------------------------------------------------------------------------------------
Int32	SDKBrowserPluginInterface::GetPluginID(String *plugin_name) const
{
	BrowserPluginInterfaceCallR(GetPluginID, NOTOK )(plugin_name);
}

// Identify a file and return true, if the plugin is able to deal with the file
Bool	SDKBrowserPluginInterface::Identify(const SDKBrowserURL &url, UChar *probe, Int32 size, UInt32 flags)
{
	BrowserPluginInterfaceCallR(Identify, false)(url, probe, size, flags);
}

// Return the kind of data that will be handled by this plugin. For example "Image", "Scene", "Material" ...  (please note: either node or url can be zero!)
String	SDKBrowserPluginInterface::GetTypeName(const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 mode)
{
	BrowserPluginInterfaceCallR(GetTypeName, String())(node, url, mode);
}

void SDKBrowserPluginInterface::GetTypeNames(Int32 mode, maxon::BaseArray<String>& strings)
{
	BrowserPluginInterfaceCall(GetTypeNames)(mode, strings);
}

SDKBrowserPreviewData	*SDKBrowserPluginInterface::OpenPreviewBitmap(BaseThread *thread, const SDKBrowserContentNodeRef node, const SDKBrowserURL *url, SDKBrowserPreviewInfo *info)
{
	BrowserPluginInterfaceCallR(OpenPreviewBitmap, nullptr )(thread, node, url, info);
}

void	SDKBrowserPluginInterface::ClosePreviewBitmap(SDKBrowserPreviewData *data)
{
	BrowserPluginInterfaceCall(ClosePreviewBitmap )(data);
}

BaseBitmap	*SDKBrowserPluginInterface::GetPreviewBitmap(SDKBrowserPreviewData *data, Int32 w, Int32 h, Int32 quality)
{
	BrowserPluginInterfaceCallR(GetPreviewBitmap, nullptr )(data, w, h, quality);
}

// Return an icon for this kind of file (does not have to be a preview for this specific file)
SDKBrowserIcon	*SDKBrowserPluginInterface::GetIcon(const SDKBrowserURL &url, Int32 pref_wh)
{
	BrowserPluginInterfaceCallR(GetIcon, nullptr )(url, pref_wh);
}

		// Return a plugin specific preview subdialog for the content node.
SubDialog		*SDKBrowserPluginInterface::OpenPreviewDialog(SDKBrowserContentNodeRef node, Int32 tab_id)
{
	BrowserPluginInterfaceCallR(OpenPreviewDialog, nullptr )(node, tab_id);
}

// Will be called when the preview is not used anymore
Int32	SDKBrowserPluginInterface::ClosePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s)
{
	BrowserPluginInterfaceCallR(ClosePreviewDialog, PreviewTab )(node, s);
}

// Will be called to update the current preview
Int32	SDKBrowserPluginInterface::UpdatePreviewDialog(SDKBrowserContentNodeRef node, SubDialog *s)
{
	BrowserPluginInterfaceCallR(UpdatePreviewDialog, PreviewTab )(node, s);
}

// Open a content node
Bool	SDKBrowserPluginInterface::Open(SDKBrowserContentNodeRef node, const SDKBrowserURL *url, Int32 flags)
{
	BrowserPluginInterfaceCallR(Open, false)(node, url, flags);
}


//////////////////////////////////////////////////////////////////////////

SDKBrowserPluginInterfaceInfo::SDKBrowserPluginInterfaceInfo(void)
{
	plugin = nullptr;
}

// plugin is valid after plugin registration (RegisterBrowserPlugin)
SDKBrowserPluginRef	SDKBrowserPluginInterfaceInfo::GetPlugin(void) const
{
	return plugin;
}

//////////////////////////////////////////////////////////////////////////

#define ReferenceObjectCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, reference_object.method)); \
	if (!lib || !lib->reference_object.method)	\
		return; \
	(((ReferenceObject *)this)->*lib->reference_object.method)

void	SDKReferenceObject::add_reference(void)
{
	ReferenceObjectCall(add_reference )();
}

void	SDKReferenceObject::remove_reference(void)
{
	ReferenceObjectCall(remove_reference )();
}

//////////////////////////////////////////////////////////////////////////

#define RTreeNodeCallR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, rtree_node)); \
	if (!lib || !lib->rtree_node)	\
		return error_value; \
	return (((RTreeNode *)this)->*lib->rtree_node->method)

#define RTreeNodeCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, rtree_node)); \
	if (!lib || !lib->rtree_node)	\
		return; \
	(((RTreeNode *)this)->*lib->rtree_node->method)

SDKRTreeNodeRef	SDKRTreeNode::GetUp(void)
{
	RTreeNodeCallR(GetUp, 0)();
}

SDKRTreeNodeRef	SDKRTreeNode::GetDown(void)
{
	RTreeNodeCallR(GetDown, 0)();
}

SDKRTreeNodeRef	SDKRTreeNode::GetNext(void)
{
	RTreeNodeCallR(GetNext, 0)();
}

SDKRTreeNodeRef	SDKRTreeNode::GetPred(void)
{
	RTreeNodeCallR(GetPred, 0)();
}

void	SDKRTreeNode::InsertUnder(SDKRTreeNodeRef parent)
{
	RTreeNodeCall(InsertUnder )(parent);
}

void	SDKRTreeNode::Remove(void)
{
	RTreeNodeCall(Remove )();
}


//////////////////////////////////////////////////////////////////////////


#define BrowserContentNodeCallR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, content_node)); \
	if (!lib || !lib->content_node)	\
		return error_value; \
	return (((BrowserContentNode *)this)->*lib->content_node->method)

#define BrowserContentNodeCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, content_node)); \
	if (!lib || !lib->content_node)	\
		return; \
	(((BrowserContentNode *)this)->*lib->content_node->method)

#define BrowserContentNodeCallSR( method, error_value)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, content_node)); \
	if (!lib || !lib->content_node)	\
		return error_value; \
	return (lib->content_node->method)

#define BrowserContentNodeCallS( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, content_node)); \
	if (!lib || !lib->content_node)	\
		return; \
	lib->content_node->method

//----------------------------------------------------------------------------------------
// Allocate a browser node (and insert it under parent)
// Function result:		the allocated node or 0
// info:							node description object (will be owned by the browser)
// parent:						either parent node or 0 (do not insert under parent)
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeRef	SDKBrowserContentNode::Alloc(SDKBrowserContentNodeInfo *info, SDKBrowserContentNodeRef parent)
{
	SDKBrowserContentNodeRef	node;
	BrowserLib	*lib;

	if (node_ptmf_valid == false)
	{
		ClearMem(&plugin_ptmf, sizeof(plugin_ptmf));
		node_ptmf.Init = &SDKBrowserContentNodeInfo::Init;
		node_ptmf.Free = &SDKBrowserContentNodeInfo::Free;
		node_ptmf.GetTypeID = &SDKBrowserContentNodeInfo::GetTypeID;
		node_ptmf.GetPlugin = &SDKBrowserContentNodeInfo::GetPlugin;

		node_ptmf.GetName = &SDKBrowserContentNodeInfo::GetName;
		node_ptmf.GetNodeURL = &SDKBrowserContentNodeInfo::GetNodeURL;
		node_ptmf.GetNodeTime = &SDKBrowserContentNodeInfo::GetNodeTime;
		node_ptmf.GetNodeFlags = &SDKBrowserContentNodeInfo::GetNodeFlags;

		node_ptmf.GetIcon = &SDKBrowserContentNodeInfo::GetIcon;

		node_ptmf.UpdateDirectory = &SDKBrowserContentNodeInfo::UpdateDirectory;

		node_ptmf.PrivateCall = &SDKBrowserContentNodeInfo::PrivateCall;

		node_ptmf.Rename = &SDKBrowserContentNodeInfo::Rename;
		node_ptmf.MoveFrom = &SDKBrowserContentNodeInfo::MoveFrom;
		node_ptmf.CopyFrom = &SDKBrowserContentNodeInfo::CopyFrom;
		node_ptmf.Delete = &SDKBrowserContentNodeInfo::Delete;
		node_ptmf.NewFolder = &SDKBrowserContentNodeInfo::NewFolder;

		node_ptmf_valid = true;
	}

	lib = CheckBrowserLib(LIBOFFSET(BrowserLib, content_node));

	if (lib && lib->content_node)
	{
		node = lib->content_node->Alloc(info, &node_ptmf);
		if (node)
		{
			if (info->node == nullptr)															// wrong node description?
				node = (SDKBrowserContentNode *) nullptr;							// release reference
			else if (parent)
				node->InsertUnder(parent);												// insert in tree
		}
	}
	return node;
}

//----------------------------------------------------------------------------------------
// Allocate a category (folder) browser node (and insert it under parent)
// Function result:		the allocated node or 0
// name:							this name will appear in the UI (language dependent)
// local_path:				this will be used for the url (language independent)
// icon_file:					use this fiel as custom folder icon
// parent:						either parent node or 0 (do not insert under parent)
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeRef	SDKBrowserContentNode::AllocCategoryNode(const String &name, const String &local_path, const Filename &icon_file, SDKBrowserContentNodeRef parent)
{
	SDKBrowserContentNodeRef	node;
	BrowserLib *lib = CheckBrowserLib(LIBOFFSET(BrowserLib, content_node));

	if (lib && lib->content_node)
	{
		node = lib->content_node->AllocCategoryNode(name, local_path, icon_file);
		if (node && parent)
			node->InsertUnder(parent);
	}
	return node;
}

//----------------------------------------------------------------------------------------
// Remove all nodes that have been allocated by this plugin (and free their SDKBrowserContentNodeInfo objects)
// Call this before your plugin will be unloaded (PluginEnd or before)
// Function result:		-
// plugin_id:					the ID of this plugin
//----------------------------------------------------------------------------------------
void	SDKBrowserContentNode::FreeNodes(Int32 plugin_id)
{
	BrowserContentNodeCallS(FreeNodes )(plugin_id);
}

//----------------------------------------------------------------------------------------
// Return the node description object (if the node was created by this plugin)
// Function result:		node description object or 0 (node was created by another plugin)
// plugin_id:					the ID of this plugin
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeInfo	*SDKBrowserContentNode::GetNodeInfo(Int32 plugin_id) const
{
	BrowserContentNodeCallSR(GetNodeInfo, 0)(this, plugin_id);
}

//----------------------------------------------------------------------------------------
// Return the node type
// Function result:		node type
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::GetTypeID(void) const
{
	BrowserContentNodeCallR(GetTypeID, 0)();								// Type of content node
}

//----------------------------------------------------------------------------------------
// Return plugin for this node
// Function result:		plugin pointer or 0 (unknown node/file type)
// plugin_flags:			usually 0, LinkThrough or LazyIdentification
//----------------------------------------------------------------------------------------
SDKBrowserPluginRef	SDKBrowserContentNode::GetPlugin(UInt32 flags) const
{
	BrowserContentNodeCallR(GetPlugin, 0)(flags);					// Return pointer to the plugin that can deal with this file (see GetFileKind)
}

//----------------------------------------------------------------------------------------
// Return the name of the content node (used in the UI)
// Function result:		name string
//----------------------------------------------------------------------------------------
String	SDKBrowserContentNode::GetName(void) const
{
	BrowserContentNodeCallR(GetName, "" )();									// Return the name of the content node (used in the UI)
}

//----------------------------------------------------------------------------------------
// Return a description of the file type, e.g. "Image", "Web page" or "3D Scene"
// This string is used when the nodes are sorted by type
// Function result:		...
// mode:							BasicItemType, SpecificItemType
//----------------------------------------------------------------------------------------
String	SDKBrowserContentNode::GetTypeName(Int32 mode) const
{
	BrowserContentNodeCallR(GetTypeName, "" )(mode);				// Return the name of the content type
}

//----------------------------------------------------------------------------------------
// Return the url of the content node
// Function result:		reserved
// url:								used to return the url
// flags:							0 or LinkThrough
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::GetNodeURL(SDKBrowserURL &url, UInt32 flags) const
{
	BrowserContentNodeCallR(GetNodeURL, 0)(*(BrowserURL *) &url, flags);		// Return the url of the content node
}

//----------------------------------------------------------------------------------------
// Returns the creation and last modification time of a node (this will usually
// be the file times). For a directory the modification time will usually be the
// time, when a file has been added or removed.
// Function result:		true: succesful false: not available
// mode:							GE_FILETIME_MODIFIED (default if nothing else is available), GE_FILETIME_CREATED or GE_FILETIME_ACCESS
//										LinkThrough might be set as well
// out:								...
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNode::GetNodeTime(UInt32 mode, LocalFileTime *out) const
{
	BrowserContentNodeCallR(GetNodeTime, false)(mode, out);
}

//----------------------------------------------------------------------------------------
// Return node flags (Directory, ...)
// Function result:		node flags
// out_size:					used to return the file/node size
//----------------------------------------------------------------------------------------
UInt32	SDKBrowserContentNode::GetNodeFlags(Int64 *out_size) const
{
	BrowserContentNodeCallR(GetNodeFlags, 0)(out_size);		// Return a few node flags (see IsDirectory)
}

//----------------------------------------------------------------------------------------
// Get icon for this node
// Function result:		icon object
// flags:							e.g. IconPreviewBitmap (return icon with preview bitmap)
// pref_wh:						preferred width/height of the icon
//----------------------------------------------------------------------------------------
SDKBrowserIcon	*SDKBrowserContentNode::GetIcon(Int32 flags, Int32 pref_wh) const
{
	BrowserContentNodeCallR(GetIcon, 0)(flags, pref_wh);	// Return an icon for this kind of file (does not have to be a preview for this specific file)	pref_wh is the preferred icon size
}

//----------------------------------------------------------------------------------------
// Update the directory content (if this node is a folder). Usually there should be no
// need to call this function, unless you want to explore the file system ;-)
// Function result:		reserved
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::UpdateDirectory(void)
{
	BrowserContentNodeCallR(UpdateDirectory, 0)();					// ...will be called, before GetDown() is used to search for children (mainly for file system based trees)
}

//----------------------------------------------------------------------------------------
// Hook for private calls. plugin and node_type are used by the node to validate the call
// (If you call a private method for the wrong node, it will do nothing).
// Function result:		NOTOK (if not successful)
// plugin_id:					must be the same as GetPlugin()->GetPluginID()
// node_type:					must be the same as GetTypeID()
// selector:					is the private method index
// data:							is for passing parameters
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::PrivateCall(Int32 plugin_id, Int32 node_type, Int32 selector, void *data)
{
	BrowserContentNodeCallR(PrivateCall, NOTOK )(plugin_id, node_type, selector, data);		// Hook for private calls
}

//----------------------------------------------------------------------------------------
// Rename a node
// Function result:		OperationSuccessful or an error code
// mode:							CheckOperation/PerformOperation
// name:							new name (this is guaranteed to be unique!)
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::Rename(Int32 mode, const String &name)
{
	BrowserContentNodeCallR(Rename, RenameNotPermitted )(mode, name);
}

//----------------------------------------------------------------------------------------
// Create a new folder
// Function result:		OperationSuccessful or an error code
// mode:							CheckOperation/PerformOperation
// name:							new name (this is guaranteed to be unique!)
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::NewFolder(Int32 mode, const String &name, SDKBrowserContentNodeRef *folder)
{
	BrowserContentNodeCallR(NewFolder, NewFolderNotPermitted )(mode, name, folder);
}

//----------------------------------------------------------------------------------------
// Move nodes (this will be new parent)
// Function result:		OperationSuccessful or an error code
// new_child:
// mode:							CheckOperation, PrepareOperation or PerformOperation
// callback:					callback (e.g. for progress report)
// private_data:			data pointer for the callback
// thread:						the current thread or 0
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::MoveFrom(SDKBrowserContentNodeRef new_child, Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
{
	BrowserContentNodeCallR(MoveFrom, MoveNotPermitted )(new_child, mode, callback, private_data, thread);
}

//----------------------------------------------------------------------------------------
// Copy nodes (this will be new parent)
// Function result:		OperationSuccessful or an error code
// new_child:
// mode:							CheckOperation, PrepareOperation or PerformOperation
// rename:						0 or pointer to a string if new_child has to be renamed to avoid a name conflict
// callback:					callback (e.g. for progress report)
// private_data:			data pointer for the callback
// thread:						the current thread or 0
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::CopyFrom(SDKBrowserContentNodeRef new_child, Int32 mode, const String *rename, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
{
	BrowserContentNodeCallR(CopyFrom, CopyNotPermitted )(new_child, mode, rename, callback, private_data, thread);
}

//----------------------------------------------------------------------------------------
// Delete node and its children (the Flush flag will be set until all references have been released)
// Function result:		OperationSuccessful or an error code
// mode:							CheckOperation, PrepareOperation or PerformOperation
// callback:					callback (e.g. for progress report)
// private_data:			data pointer for the callback
// thread:						the current thread or 0
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::Delete(Int32 mode, CopyMoveCallback *callback, void *private_data, BaseThread *thread)
{
	BrowserContentNodeCallR(Delete, DeleteNotPermitted )(mode, callback, private_data, thread);
}

//----------------------------------------------------------------------------------------
// Return the url of the content node
// Function result:		url
// flags:							0 or LinkThrough
// idx:								reserved (set to 0)
//----------------------------------------------------------------------------------------
SDKBrowserURL	SDKBrowserContentNode::GetNodeURL(UInt32 flags, Int32 *idx) const
{
	SDKBrowserURL	url;
	Int32	result;

	result = GetNodeURL(url, flags);
	if (idx)
		*idx = result;

	return url;
}

//----------------------------------------------------------------------------------------
// Returns the Filename if applicable
// Function result:		true: is a file name false:	something else (e.g. a preset node)
// f:									used to return the Filename
// flags:							0 or LinkThrough
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNode::GetFilename(Filename &f, UInt32 flags) const
{
	SDKBrowserURL	url;

	GetNodeURL(url, flags);
	return (url.GetFilename(f));
}

//----------------------------------------------------------------------------------------
// Returns the creation and last modification time of a node (this will usually
// be the file times). For a directory the modification time will usually be the
// time, when a file has been added or removed.
// Function result:		time (all zero if not available)
// mode:							GE_FILETIME_MODIFIED (default if nothing else is available), GE_FILETIME_CREATED or GE_FILETIME_ACCESS
//										LinkThrough might be set as well
//----------------------------------------------------------------------------------------
LocalFileTime	SDKBrowserContentNode::GetNodeTime(UInt32 mode) const
{
	LocalFileTime	t;

	if (GetNodeTime(mode, &t) == false)										// not available?
		t.Init();

	return t;
}

//----------------------------------------------------------------------------------------
// Return if this is a directory (or a tree branch)
// Function result:		true: (virtual) directory false: something else (usually a file)
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNode::IsDirectory(void) const
{
	return Int(GetNodeFlags() & (Directory | VirtualDirectory)) != 0;
}

//----------------------------------------------------------------------------------------
// Return if this is a link to another node (call GetNodeURL( url, LinkTrough ) to get the destination url)
// Function result:		true: links to another node false: ...
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNode::IsLink(void) const
{
	return Int(GetNodeFlags() & Link) != 0;
}

//----------------------------------------------------------------------------------------
// Return if this node is read only
// Function result:
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNode::IsReadOnly(void) const
{
	return Int(GetNodeFlags() & ReadOnly) != 0;
}

// Return if this node is going to be flushed (if yes: you shouldn't create new database entries for it)
Bool	SDKBrowserContentNode::IsFlushed(void) const
{
	return Int(GetNodeFlags() & Flush) != 0;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseObject	*SDKBrowserContentNode::GetDefaultObject(void)
{
	BaseObject	*op;
	Int32	result;

	op = nullptr;
	result = PrivateCall(CBPluginTypeDefaults, SDKBrowserContentNode::TypePreset, 0, (void *) &op);
	if (result == NOTOK)
		op = nullptr;

	return op;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseDocument	*SDKBrowserContentNode::GetObjectPreset(void)
{
	BaseDocument	*doc;
	Int32	result;

	doc = nullptr;
	result = PrivateCall(CBPluginTypeObjectPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &doc);
	if (result == NOTOK)
		doc = nullptr;

	return doc;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseMaterial	*SDKBrowserContentNode::GetMaterialPreset(void)
{
	BaseMaterial	*mat;
	Int32	result;

	mat = nullptr;
	result = PrivateCall(CBPluginTypeMaterialPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &mat);
	if (result == NOTOK)
		mat = nullptr;

	return mat;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseTag	*SDKBrowserContentNode::GetTagPreset(void)
{
	BaseTag	*tag;
	Int32	result;

	tag = nullptr;
	result = PrivateCall(CBPluginTypeTagPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &tag);
	if (result == NOTOK)
		tag = nullptr;

	return tag;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
RenderData	*SDKBrowserContentNode::GetRenderDataPreset(void)
{
	RenderData	*rd;
	Int32	result;

	rd = nullptr;
	result = PrivateCall(CBPluginTypeRenderDataPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &rd);
	if (result == NOTOK)
		rd = nullptr;

	return rd;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseShader	*SDKBrowserContentNode::GetShaderPreset(void)
{
	BaseShader	*ps;
	Int32	result;

	ps = nullptr;
	result = PrivateCall(CBPluginTypeShaderPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &ps);
	if (result == NOTOK)
		ps = nullptr;

	return ps;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
BaseVideoPost	*SDKBrowserContentNode::GetVideoPostPreset(void)
{
	BaseVideoPost	*vp;
	Int32	result;

	vp = nullptr;
	result = PrivateCall(CBPluginTypeVideoPostPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &vp);
	if (result == NOTOK)
		vp = nullptr;

	return vp;
}

//----------------------------------------------------------------------------------------
// Function result:		the caller owns the object
//----------------------------------------------------------------------------------------
GvNode	*SDKBrowserContentNode::GetXPressoPreset(void)
{
	GvNode	*xpn;
	Int32	result;

	xpn = nullptr;
	result = PrivateCall(CBPluginTypeXPressoPreset, SDKBrowserContentNode::TypePreset, 0, (void *) &xpn);
	if (result == NOTOK)
		xpn = nullptr;

	return xpn;
}

//----------------------------------------------------------------------------------------
// Get the plugin ID for the data that is stored in the preset node
// Function result:		plugin id or 0 (unknown data type)
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNode::GetPresetSourcePluginID(void)
{
	Int32	src_plugin_id;
	Int32	result;

	src_plugin_id = 0;
	result = PrivateCall(CBPluginTypeFilePreset, SDKBrowserContentNode::TypePreset, 1, (void *) &src_plugin_id);
	if (result == NOTOK)
		src_plugin_id = 0;

	return 	src_plugin_id;
}


//////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------
// Initialize a SDKBrowserContentNodeInfo
// Function result:		-
// _plugin_id:				ID of the plugin that has created the node info
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeInfo::SDKBrowserContentNodeInfo(Int32 _plugin_id)
{
	plugin_id = _plugin_id;
	node = nullptr;																							// pointer to corresponding node
}

//----------------------------------------------------------------------------------------
// Return the corresponding node
// Function result:		SDKBrowserContentNodeRef
//----------------------------------------------------------------------------------------
SDKBrowserContentNodeRef	SDKBrowserContentNodeInfo::GetNode(void) const
{
	return ((SDKBrowserContentNode *) node);
}

//----------------------------------------------------------------------------------------
// Called by the browser during node allocation
// Function result:		true
// _node:							pointer to the browser node
//----------------------------------------------------------------------------------------
Bool	SDKBrowserContentNodeInfo::Init(void *_node)
{
	node = _node;
	return true;
}

//----------------------------------------------------------------------------------------
// Will be called by the browser before the node will be deleted
// Override this if you want to dispose of the SDKBrowserContentNodeInfo at a later time
// Function result:		-
//----------------------------------------------------------------------------------------
void		SDKBrowserContentNodeInfo::Free(void)
{
	SDKBrowserContentNodeInfo	*_this;

	_this = this;
	DeleteObj(_this);
}

//----------------------------------------------------------------------------------------
// Hook for private calls. plugin and node_type are used by the node to validate the call
// (If you call a private method for the wrong node, it will do nothing).
// Override this if you want to implement private calls
// Function result:		NOTOK (if not successful)
// pluginId:					must be the same as GetPlugin()->GetPluginID()
// node_type:					must be the same as GetTypeID()
// selector:					is the private method index
// data:							is for passing parameters
//----------------------------------------------------------------------------------------
Int32	SDKBrowserContentNodeInfo::PrivateCall(Int32 pluginId, Int32 node_type, Int32 selector, void *data)
{
	return NOTOK;
}

String	SDKBrowserContentNodeInfo::GetTypeName(Int32 mode)
{
	SDKBrowserContentNodeRef localNode;
	SDKBrowserPluginRef	plugin;

	localNode = GetNode();
	plugin = localNode->GetPlugin(LinkThrough);
	if (plugin)
		return (plugin->GetTypeName(localNode, nullptr, mode));

	return "";
}

//////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------
// Initialize a SDKBrowserContentNodeInfo
// Function result:		-
// _plugin_id:				ID of the plugin that has created the node info
//----------------------------------------------------------------------------------------
SDKBrowserPreviewDialog::SDKBrowserPreviewDialog(void)
{
	private_data = nullptr;
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogAlloc);	// allocate preview dialog
}

SDKBrowserPreviewDialog::~SDKBrowserPreviewDialog(void)
{
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogFree);	// delete preview dialog
}

void	SDKBrowserPreviewDialog::Init(SDKBrowserContentNodeRef content, Int32 tab_id)
{
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogInit, tab_id, 0, (void *) &content);
}

Bool	SDKBrowserPreviewDialog::Update(Int32 flags)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogUpdate, flags, 0, nullptr) != 0;
}

// add an extra tab (must be call before CreateLayout!)
Bool	SDKBrowserPreviewDialog::AddTab(Int32 id, const String &name)
{
	String	tmp;

	tmp = name;
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogAddTab, id, 0, &tmp) != 0;
}

// remove one of the default Tabs (PreviewTab, InfoTab or AnnotationTab)
Bool	SDKBrowserPreviewDialog::RemoveDefaultTab(Int32 id)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogRemoveDefaultTab, id) != 0;
}

// flush content of one of the default Tabs and  (PreviewTab, InfoTab or AnnotationTab)
Bool	SDKBrowserPreviewDialog::LayoutFlushTab(Int32 id)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogLayoutFlushTab, id) != 0;
}

Bool	SDKBrowserPreviewDialog::LayoutAddToTab(Int32 id)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogLayoutAddToTab, id) != 0;
}

// send LayoutChanged() for tab  (PreviewTab, InfoTab or AnnotationTab)
Bool	SDKBrowserPreviewDialog::LayoutChangedTab(Int32 id)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogLayoutChangedTab, id) != 0;
}

// return the id of the active tab
Int32	SDKBrowserPreviewDialog::GetActiveTab(void)
{
	return (SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogGetActiveTab));
}

// change the preview bitmap (preview dialog will own the BaseBitmap!)
void	SDKBrowserPreviewDialog::ChangePreviewBitmap(BaseBitmap *bm, Int32 flags)
{
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogChangePreviewBitmap, flags, 0, (void *) bm);
}

Bool SDKBrowserPreviewDialog::CreateLayout(void)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogCreateLayout) != 0;
}

Bool	SDKBrowserPreviewDialog::InitValues(void)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogInitValues) != 0;
}

Bool	SDKBrowserPreviewDialog::CoreMessage(Int32 id, const BaseContainer &msg)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogCoreMessage, id, 0, (void *) &msg) != 0;
}

Bool	SDKBrowserPreviewDialog::Command(Int32 id, const BaseContainer &msg)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogCommand, id, 0, (void *) &msg) != 0;
}

Bool	SDKBrowserPreviewDialog::AskClose(void)
{
	return SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogAskClose) != 0;
}

void	SDKBrowserPreviewDialog::Timer(const BaseContainer &msg)
{
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogTimer, 0, 0, (void *) &msg);
}

void SDKBrowserPreviewDialog::DestroyWindow(void)
{
	SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogDestroyWindow);
}

Int32	SDKBrowserPreviewDialog::Message(const BaseContainer &msg, BaseContainer &result)
{
	return (SDKBrowser::PreviewDialogMisc(this, private_data, SDKBrowserPreviewDialogMessage, 0, 0, (void *) &msg, (void *) &result));
}

namespace maxon
{

Result<BaseArray<Url>> BrowserReceiveUrls(void* dat)
{
	iferr_scope;

	BaseArray<Url>			urlArray;
	SDKBrowserDragInfo* bdi;

	bdi = (SDKBrowserDragInfo*)dat;
	if (!bdi)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);

	Int32 cnt = bdi->GetItemCount();

	for (Int32 idx = 0; idx < cnt; idx++)
	{
		SDKBrowserContentNodeRef item;
		SDKBrowserPluginRef			 plugin;
		SDKBrowserURL						 url;

		item = bdi->GetItem(idx);

		if (item->IsLink()) // is this a link to another node?
		{
			item = SDKBrowser::FindNode(item->GetNodeURL(LinkThrough)); // try to find the linked node
			if (!item)
				continue;
		}

		plugin = item->GetPlugin(); // now get the real plugin (you could have used LinkThrough on the original as well);
		url = item->GetNodeURL();

		Int32 type = 0;

		if (plugin)
			type = plugin->GetPluginID();

		if (type == CBPluginTypeFilePreset)
		{
			// preset://
			Filename fileName = url.GetString();
			Url			 u = MaxonConvert(fileName, MAXONCONVERTMODE::NONE);
			urlArray.Append(u) iferr_return;
		}
		else
		{
			// file:// etc.
			Filename fileName = url.GetFilename();
			Url			 u = MaxonConvert(fileName, MAXONCONVERTMODE::NONE);
			urlArray.Append(u) iferr_return;
		}
	}

	return std::move(urlArray);
}

}
