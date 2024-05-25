#ifndef URL_H__
#define URL_H__

#include "maxon/ioenums.h"
#include "maxon/array.h"
#include "maxon/timevalue.h"

namespace maxon
{

/// @addtogroup IO
/// @{

class AssetRepositoryRef;

class IoConnectionRef MAXON_FORWARD("maxon/ioconnection.h");

class InputStreamRef MAXON_FORWARD("maxon/iostreams.h");
class OutputStreamRef MAXON_FORWARD("maxon/iostreams.h");
class InOutputStreamRef MAXON_FORWARD("maxon/iostreams.h");

class IoBrowseRef MAXON_FORWARD("maxon/iobrowse.h");
class UniversalDateTime MAXON_FORWARD("maxon/datetime.h");

class NetworkIpAddrPort;
class DataDictionary;

template <typename STREAM> class UrlOrStream;
using UrlOrInputStream = UrlOrStream<InputStreamRef>;
using UrlOrOutputStream = UrlOrStream<OutputStreamRef>;

//----------------------------------------------------------------------------------------
/// Parameters for UrlInterface::SetData(), UrlInterface::GetData().
//----------------------------------------------------------------------------------------
namespace URLFLAGS
{
	MAXON_ATTRIBUTE(Bool, UNBUFFERED_FILE, "net.maxon.url.unbuffered_file");						///< Set to true, if file should be unbuffered.

	MAXON_ATTRIBUTE(TimeValue, NETWORK_CONNECTTIMEOUT, "net.maxon.url.network_connecttimeout");			///< Connection time out for network connections.
	MAXON_ATTRIBUTE(TimeValue, NETWORK_SESSIONTIMEOUT, "net.maxon.url.network_sessiontimeout");			///< Session time out for network connections.

	MAXON_ATTRIBUTE(String, USERNAME, "net.maxon.url.username");          ///< User name for the the url. RFC3986 (7.5) says Url producers should not provide a URL that contains a username or password that is intended to be secret. URIs are frequently displayed by browsers, stored in clear text bookmarks, and logged by user agent history and intermediary applications (proxies). However, this feature is still used and that's why this is supported.
	MAXON_ATTRIBUTE(String, USERPASSWORD, "net.maxon.url.userpassword");					///< Password for the url. RFC3986 (7.5) says Url producers should not provide a URL that contains a username or password that is intended to be secret. URIs are frequently displayed by browsers, stored in clear text bookmarks, and logged by user agent history and intermediary applications (proxies). However, this feature is still used and that's why this is supported.
	
	MAXON_ATTRIBUTE(String, QUERY, "net.maxon.url.query");					///< Serves to identify a resource within the scope of the url scheme e.g. "date=today" or "subject=Topic"
	MAXON_ATTRIBUTE(Bool, QUERY_IS_ENCODED, "net.maxon.url.queryisencoded"); ///< True if the query is already encoded. In that case url.GetUrlEncoded() returns the string as raw string

	MAXON_ATTRIBUTE(String, FRAGMENT, "net.maxon.url.fragment");					///< Holds additional identifying information that provides direction to a secondary resource, e.g., a 	section heading (in an article) identified by the remainder of the URI. When the primary resource is an HTML document, the fragment is often an id attribute of a specific element and web browsers will make sure this element is visible. For example for MIME text/html pages such as http://www.example.org/foo.html#bar the fragment refers to the element with id="bar".

	MAXON_ATTRIBUTE(Bool, CACHE_IN_RAM, "net.maxon.url.cache_in_ram");						///< URLSCHEME_CACHE, If true, the cache is created in the RAM, otherwise in the machines temp directory on harddrive
	MAXON_ATTRIBUTE(DelegateBase, FTPS_FINGERPRINT, "net.maxon.url.ftps_fingerprint");		///< URLSCHEME_FTPS, Optional callback Bool(const String& fingerprint) which is triggered when the connection was established. Return true if the fingerprint is valid, otherwise return false to abort the connection.

	MAXON_ATTRIBUTE(URLCOMPARE, PRIVATE_FORCECOMPAREMODE, "net.maxon.url.private_forcecomparemode");
	MAXON_ATTRIBUTE(Bool, CLEARDATA, "net.maxon.url.cleardata");
}

//----------------------------------------------------------------------------------------
///
//----------------------------------------------------------------------------------------
enum class GETBROWSEITERATORFLAGS
{
	NONE = 0,					///< No flags specified.
	NOERRORONOPEN = 1 << 0,		///< Will return no error when opening a non existing directory but will return an empty browse handler with no entries.
	RESOLVEPATHS = 1 << 1,		///< Attempts to resolve paths by invoking @ref maxon::UrlInterface::IoNormalize "IoNormalize" on them. Non-resolvable paths will not halt iteration and instead be passed through.
} MAXON_ENUM_FLAGS(GETBROWSEITERATORFLAGS);

//----------------------------------------------------------------------------------------
/// See ConvertToUiName()
//----------------------------------------------------------------------------------------
enum class CONVERTTOUINAMEFLAGS
{
	NONE = 0,									///< Default: returns directory + name.
	NAMEONLY = 1 << 0,				///< Returns only the name without directory + optional version.
	DIRECTORYONLY = 1 << 1,		///< Returns only the directory without name.
	ADDVERSION = 1 << 2,			///< Adds the version in front of the suffix.
	CLEARSUFFIX = 1 << 3,			///< Remove the suffix from the name.
	DONTADDDATABASE = 1 << 4,	///< Don't add the Database name in brackets behind the name.
} MAXON_ENUM_FLAGS(CONVERTTOUINAMEFLAGS);

//----------------------------------------------------------------------------------------
/// @brief Provides a type alias used by @ref maxon::Url scheme defintions.
/// @details Schemes exposed in @ref url.h :
///
///  %Scheme | %Description 
/// - | -
/// @ref maxon::URLSCHEME_FILESYSTEM        | @copybrief maxon::URLSCHEME_FILESYSTEM
/// @ref maxon::URLSCHEME_RELATIVE          | @copybrief maxon::URLSCHEME_RELATIVE
/// @ref maxon::URLSCHEME_NETWORK           | @copybrief maxon::URLSCHEME_NETWORK
/// @ref maxon::URLSCHEME_STORAGE           | @copybrief maxon::URLSCHEME_STORAGE
/// @ref maxon::URLSCHEME_VOLUME            | @copybrief maxon::URLSCHEME_VOLUME
/// @ref maxon::URLSCHEME_ZIPFILE           | @copybrief maxon::URLSCHEME_ZIPFILE
/// @ref maxon::URLSCHEME_GZIPFILE          | @copybrief maxon::URLSCHEME_ZIPFILE
/// @ref maxon::URLSCHEME_APK_ASSET         | @copybrief maxon::URLSCHEME_APK_ASSET
/// @ref maxon::URLSCHEME_CRYPTOFILE        | @copybrief maxon::URLSCHEME_CRYPTOFILE
/// @ref maxon::URLSCHEME_CACHE             | @copybrief maxon::URLSCHEME_CACHE
/// @ref maxon::URLSCHEME_MEMORY            | @copybrief maxon::URLSCHEME_MEMORY
/// @ref maxon::URLSCHEME_TCP               | @copybrief maxon::URLSCHEME_TCP
/// @ref maxon::URLSCHEME_WS                | @copybrief maxon::URLSCHEME_WS
/// @ref maxon::URLSCHEME_WSS               | @copybrief maxon::URLSCHEME_WSS
/// @ref maxon::URLSCHEME_FTP               | @copybrief maxon::URLSCHEME_FTP
/// @ref maxon::URLSCHEME_SFTP              | @copybrief maxon::URLSCHEME_SFTP
/// @ref maxon::URLSCHEME_HTTP              | @copybrief maxon::URLSCHEME_HTTP
/// @ref maxon::URLSCHEME_HTTPS             | @copybrief maxon::URLSCHEME_HTTPS
/// @ref maxon::URLSCHEME_PERFORCE          | @copybrief maxon::URLSCHEME_PERFORCE
/// @ref maxon::URLSCHEME_AUTHORITY         | @copybrief maxon::URLSCHEME_AUTHORITY
/// @ref maxon::URLSCHEME_HANDLER           | @copybrief maxon::URLSCHEME_HANDLER
/// @ref maxon::URLSCHEME_PIPE              | @copybrief maxon::URLSCHEME_PIPE
/// @ref maxon::URLSCHEME_STDERR            | @copybrief maxon::URLSCHEME_STDERR
/// @ref maxon::URLSCHEME_STDIN             | @copybrief maxon::URLSCHEME_STDIN
/// @ref maxon::URLSCHEME_STDOUT            | @copybrief maxon::URLSCHEME_STDOUT
///
/// Unexposed or outside of @ref url.h exposed schemes:
///
///  %Scheme | %Description 
/// - | -
/// @ref maxon::URLSCHEME_UNCFILESYSTEM     | Scheme identifier for Uniform Naming Convention (UNC) network resource access. Currently not exposed, uses the identifier `"unc"`. 
/// @ref maxon::URLSCHEME_MEMORYFILESTRUCT  | Scheme identifier for memory file streams. Currently not exposed, uses the identifier `"mfs"`. 
/// @ref maxon::URLSCHEME_RAMDISK           | @copybrief maxon::URLSCHEME_RAMDISK. Currently only exposed in @ref ramdisk.h .
/// @ref maxon::URLSCHEME_ASSET             | @copybrief maxon::URLSCHEME_ASSET. Currently only exposed in @ref assets.h .
/// @ref maxon::URLSCHEME_ASSETDB           | @copybrief maxon::URLSCHEME_ASSETDB. Currently only exposed in @ref assets.h .
/// @ref maxon::URLSCHEME_META              | @copybrief maxon::URLSCHEME_META. Currently only exposed in @ref assets.h .
/// @ref maxon::URLSCHEME_METASQ            | @copybrief maxon::URLSCHEME_METASQ. Currently only exposed in @ref assets.h .
//----------------------------------------------------------------------------------------
using UrlScheme = Id;

//----------------------------------------------------------------------------------------
/// Interface class for Urls.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class UrlInterface
{
	MAXON_INTERFACE_NONVIRTUAL(UrlInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.url");

public:
	using RESTRICT_DICTIONARY_PROPS = URLFLAGS::RESTRICT;

	//----------------------------------------------------------------------------------------
	/// Gets the UrlScheme of the Url. Is guarantueed to be lowercase (canonical form for urls) if scheme was automatically determined through SetUrl, otherwise as set.
	///
	/// <BLOCKQUOTE> Urls consist of three parts: a <B>scheme</B>, an <B>authority</B> and a <B>path</B>.
	/// The readable text-representation is "scheme://authority/path".
	///
	/// The <B>scheme</B> defines which handler is used, e.g. "http" for web-based connections or "file" for the regular file system.
	///
	/// The <B>authority</B> defines the machine, which can be empty for "localhost", a network drive or a webserver.
	/// It can also refer to an embedded file, e.g. a ZIP. To distinguish that case the readable text representation
	/// contains brackets: "scheme://[authority]/path". Nesting is possible repeatedly.
	///
	/// Finally the <B>path</B> component defines the unique location of a file or directory on the target machine.
	/// In most schemes paths are a combination of the directory path and file path, but the path could also be a network query or database entry.
	/// Path components are always separated by a forward slash and the forward slash is a reserved character that cannot be used for names. </BLOCKQUOTE>
	/// @return												Returns the UrlScheme for the Url (e.g. "file", "http"). If no scheme is set the returned value is UrlScheme().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const UrlScheme& GetScheme() const;

	//----------------------------------------------------------------------------------------
	/// Sets the scheme of the Url. Path and authority will stay unchanged.
	///
	/// <BLOCKQUOTE> Urls consist of three parts: a <B>scheme</B>, an <B>authority</B> and a <B>path</B>.
	/// The readable text-representation is "scheme://authority/path".
	///
	/// The <B>scheme</B> defines which handler is used, e.g. "http" for web-based connections or "file" for the regular file system.
	///
	/// The <B>authority</B> defines the machine, which can be empty for "localhost", a network drive or a webserver.
	/// It can also refer to an embedded file, e.g. a ZIP. To distinguish that case the readable text representation
	/// contains brackets: "scheme://[authority]/path". Nesting is possible repeatedly.
	///
	/// Finally the <B>path</B> component defines the unique location of a file or directory on the target machine.
	/// In most schemes paths are a combination of the directory path and file path, but the path could also be a network query or database entry.
	/// Path components are always separated by a forward slash and the forward slash is a reserved character that cannot be used for names. </BLOCKQUOTE>
	/// @param[in] scheme							The new scheme UrlScheme Id e.g. URLSCHEME_FILESYSTEM, URLSCHEME_ZIPFILE or URLSCHEME_MEMORY. Should always be lowercase because no normalization is applied here.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetScheme(const UrlScheme& scheme);

	//----------------------------------------------------------------------------------------
	/// Appends a new component to the Url.
	/// E.g. if the Url is "file:///c:/directory" a call of Append("file.txt"_s) will result in "file:///c:/directory/file.txt".
	/// @param[in] name								A component that will be added to the end of the Url. A separator (forward slash) will be placed between the end of the current Url and the new part.
	/// 															The value must not contain any forward slashes (under Windows additionally no backslashes), otherwise nothing will be done.
	/// @return												*this.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Append(const String& name);

	//----------------------------------------------------------------------------------------
	/// Appends a relative Url to the current one.
	/// E.g. if the Url is "file:///c:/directory" a call of Append(Url("test/file.txt"_s)) will result in "file:///c:/directory/test/file.txt".
	/// @param[in] relativeUrl				The relative Url that will be added. A separator (forward slash) will be placed between the end of the current Url and the new part.
	/// 															relativeUrl must be a Url with URLSCHEME_RELATIVE, otherwise nothing will be done.
	/// @return												*this.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Append(const Url& relativeUrl);

	//----------------------------------------------------------------------------------------
	/// Removes the last part of a Url.
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call of RemoveName() will result in "file:///c:/directory".
	/// @return												OK on success. Returns an error if there is nothing to remove.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveName();

	//----------------------------------------------------------------------------------------
	/// Returns an embedded Url.
	/// E.g. if the Url is "zip://[file:///c:/images.zip]/image01.jpg" a call to GetEmbeddedUrl() will return "file:///c:/images.zip".
	/// @return												The embedded Url or if there was none Url().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetEmbeddedUrl() const;

	//----------------------------------------------------------------------------------------
	/// Replaces and sets an embedded Url.
	/// E.g. if the Url is "zip://[file:///c:/images.zip]/image01.jpg" a call to SetEmbeddedUrl("file:///c:/otherimages.zip"_s) will result in "zip://[file:///c:/otherimages.zip]/image01.jpg".
	/// @param[in] url								The new embedded Url.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetEmbeddedUrl(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns the name of the last component.
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call to GetName() will return "file.txt".
	/// @return												The name of the last path component.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Replaces the last component of a Url. The name must not contain a forward slashes and under Windows additionally no backslashes.
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetName("change.tif"_s) will result in "file:///c:/directory/change.tif".
	/// @param[in] name								The new name.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetName(const String& name);

	//----------------------------------------------------------------------------------------
	/// Returns the Url of the directory. If the Url is empty the directory is empty as well.
	/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetDirectory() will return "file:///c:/directory".
	/// @return												The directory Url.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetDirectory() const;

	//----------------------------------------------------------------------------------------
	/// Replaces the path component of the Url. The path is stored unchanged with the exception
	/// that under Windows all backslashes will be changed into forward slashes (unless
	/// convertWindowsBackslashes is set to false).
	/// @param[in] path								The new path.
	/// @param[in] convertWindowsBackslashes	True to convert backslashes under windows (the default).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetPath(const String& path, Bool convertWindowsBackslashes = true);

	//----------------------------------------------------------------------------------------
	/// Returns the path component of the Url. Note that this doesn't contain scheme and authority.
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call will return "c:/directory/file.txt".
	/// @return												The path component of the Url (with no authority and scheme).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetPath() const;

	//----------------------------------------------------------------------------------------
	/// Stores a system path in a Url.
	/// This call needs to be done after the appropriate scheme has been set.
	/// If no scheme is set URLSCHEME_FILESYSTEM will be automatically set.
	/// The system path may be converted to a different internal representation, e.g. split
	/// into authority and path components.
	/// Under Windows all backslashes will be changed into forward slashes.
	/// @param[in] path								The system path.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSystemPath(const String& path);

	//----------------------------------------------------------------------------------------
	/// Returns a path from the Url that the current operating system (or scheme handler) can understand.
	/// If the Url contains no valid scheme an error will be returned.
	/// An error will also be returned if the Url contains illegal characters for the scheme,
	/// e.g. backslashes on Windows in a file scheme.
	/// @return												The system path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetSystemPath() const;

	//----------------------------------------------------------------------------------------
	/// Sets the Url. The scheme is detected automatically and converted to the canonical lowercase version (as described in rfc3986#3.1).
	/// If a scheme isn't found and enableDefaultFallbackScheme is false the function returns an IllegalArgumentError,
	/// otherwise URLSCHEME_FILESYSTEM will be assumed (or URLSCHEME_RELATIVE if 'urlString' starts with
	/// no drive letter).
	/// Please note that Urls only use forward slashes as delimiter, backslashes are considered
	/// to be a part of names and not a delimiter.
	/// '?' will be considered as the start of URLFLAGS::QUERY parameters. Everything behin the '?' will be placed in that property.
	/// Use url.Get(URLFLAGS::QUERY) to get the query parameters.
	/// @param[in] urlString					The new Url to be set.
	/// @param[in] enableDefaultFallbackScheme	If false and no scheme is set an error will be returned.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme);

	//----------------------------------------------------------------------------------------
	/// Returns the Url as a string. A Url has the format scheme://authority/path.
	/// @return												The Url as a string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Returns the Url as a string with proper url encoding. A Url has the format scheme://authority/path.
	/// @return												The Url as a string. All spaces and special characters are url encoded. E.g. ' ' becomes '%20'.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetUrlEncoded() const;

	//----------------------------------------------------------------------------------------
	/// Sets the authority of a Url. This can be a machine or server.
	/// @param[in] authority					The new authority. String() can be passed for no authority / localhost.
	/// 															The authority scheme will be URLSCHEME_AUTHORITY.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetAuthority(const String& authority);

	//----------------------------------------------------------------------------------------
	/// Sets the authority of a Url. This can be a machine, server or embedded file. Url() can be
	/// passed for no authority.
	/// @param[in] authority					The new authority. Can be a machine, server or embedded file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetAuthority(const Url& authority);

	//----------------------------------------------------------------------------------------
	/// Returns the authority of a Url. The authority can be a machine, server or embedded file.
	/// @return												The authority of the Url. If the machine is localhost the returned Url is empty.
	/// 															If it is a machine or server the scheme will be URLSCHEME_AUTHORITY.
	/// 															Otherwise it defines an embedded file.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetAuthority() const;

	//----------------------------------------------------------------------------------------
	/// Returns all parts of the Url system path as separated strings.
	/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetComponents will return: { "C:", "directory", "file.txt" }.
	/// @param[out] parts							Array with the parts of the system path. A possible authority will be returned as the first part of the array.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetComponents(const NonConstArray<String>& parts) const;

	//----------------------------------------------------------------------------------------
	/// Returns a relative url based on the given basePath. The basePath needs to have the same scheme, authority. basepath needs to be part
	/// of the path of this url.
	/// @param[in] basePath						The base of the relative url.
	/// @return												Returns the relative url on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetRelativeUrl(const Url& basePath) const;

	//----------------------------------------------------------------------------------------
	/// Returns the suffix of the Url.
	/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetSuffix() will return "txt".
	/// @return												The suffix without dot.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetSuffix() const;

	//----------------------------------------------------------------------------------------
	/// Checks whether the Url has the a given suffix
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call of CheckSuffix("txt"_s) will return true.
	/// @param[in] suffix							The suffix without dot to check against.
	/// @return												True if the suffix matches.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CheckSuffix(const String& suffix) const;

	//----------------------------------------------------------------------------------------
	/// Replaces the suffix of the Url.
	/// If the Url had no suffix before a dot will be added together with the suffix string.
	/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetSuffix("jpg"_s) will result in "file:///c:/directory/file.jpg".
	/// @param[in] suffix							The new suffix of the Url without dot.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSuffix(const String& suffix);

	//----------------------------------------------------------------------------------------
	/// Deletes the suffix of the Url.
	/// E.g. if the Url was "file:///c:/directory/file.txt" a call will result in "file:///c:/directory/file".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ClearSuffix();

	//----------------------------------------------------------------------------------------
	/// Returns if the Url has no content. A Url is considered empty if it has no path component
	/// and no authority (even if a scheme is set).
	/// @return												True if the Url is empty.
	///
	/// @MAXON_ANNOTATION{default=true}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEmpty() const;

	//----------------------------------------------------------------------------------------
	/// Returns if the Url has any content. A Url is considered populated if it has a path component
	/// or authority set.
	/// @return												True if the Url has content.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsPopulated() const
	{
		return !IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Compares the object against 'name'.
	/// Note that by default the comparison is case-sensitive, so './Test.tif' and './test.tif'
	/// are not the same. To check if Urls point to the identical item use Url::IoNormalizeAndResolve instead.
	/// @param[in] name								Comparison object.
	/// @param[in] mode								Comparision mode.
	/// @return												The comparison result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const UrlInterface* name, URLCOMPARE mode = URLCOMPARE::DEFAULT) const;

	//----------------------------------------------------------------------------------------
	/// Returns Url attributes. See maxon::URLFLAGS for details.
	/// @param[in] key								The id of the property to get. The possible values for id depend on the scheme.
	/// @return												The attribute value or an error if there was none.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetData(const ConstDataPtr& key) const;

	//----------------------------------------------------------------------------------------
	/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
	/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
	/// @param[in] data								Data to be set.
	/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent = true);

	//----------------------------------------------------------------------------------------
	/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
	/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
	/// @param[in] data								Data to be set.
	/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent = true);

	//----------------------------------------------------------------------------------------
	/// EraseData removes data from the data dictionary
	/// @param[in] key								The id of the property to erase. The possible values for id depend on the scheme.
	/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EraseData(ForwardingDataPtr&& key, Bool persistent = true);

	//----------------------------------------------------------------------------------------
	/// Detects the type of the object behind Url.
	/// This allows to check if a file or directory exists.
	/// @return												IODETECT of the given Url.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION IODETECT IoDetect() const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to a IoConnectionInterface class of this Url.
	/// @return												The pointer to the IoConnectionInterface. The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<IoConnectionRef> OpenConnection() const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to a InputStreamInterface class of this Url.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												The pointer to the InputStreamInterface. The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to a OutputStreamInterface class of this Url.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												The pointer to the OutputStreamInterface. The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to a InOutputStreamInterface class of this Url.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												The pointer to the InOutputStreamInterface. The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Returns a IoBrowseIterator to browse through all children of an Url.<br>
	/// Example 1: If you want to catch all errors like opening the directory and error when going next file.
	/// @code
	/// Url path(URLSCHEME_FILESYSTEM);
	/// path.SetPath("h:/testdir"_s);
	/// for (const auto& it : path.GetBrowseIterator(GETBROWSEITERATORFLAGS::NONE))
	/// {
	///   // it's essential that error checking happens here at this point.
	///   // this error can be opening the directory as well as browsing to the next file.
	///   const IoBrowseRef& browseRef = (it) iferr_return;
	/// 	// do anything like browseRef.GetCurrentPath();
	/// }
	/// @endcode
	/// @param[in] flags							See GETBROWSEITERATORFLAGS.
	/// @return												IoBrowseIterator object.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Returns the file attributes of the object behind the Url.
	/// @return												IOATTRIBUTES of the file.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<IOATTRIBUTES> IoGetAttributes() const;

	//----------------------------------------------------------------------------------------
	/// Modifies the file attributes of the object behind the Url.
	/// @param[in] flags							Flags to set/clear.
	/// @param[in] mask								Mask with all flags to be changed.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const;

	//----------------------------------------------------------------------------------------
	/// Returns the DateTime of the current file. The time is in local time.
	/// @param[in] mode								IOTIMEMODE of the requested time.
	/// @return												Returns the DateTime or an error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;

	//----------------------------------------------------------------------------------------
	/// @brief Attempts to modify the DateTime of the current file. 
	/// @details The time is in local time.
	/// @param[in] mode								IOTIMEMODE of the requested time.
	/// @param[in] dateTime						The new datetime for the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const;

	//----------------------------------------------------------------------------------------
	/// @brief Attempts to deletes a file or directory physically on the medium.
	/// @param[in] force							Set to true tries to deletes the file/directory even if the file/directory has read only flags set.
	/// @param[in] recursive					Recursively deletes a directory and its content. If a file is specified this value is ignored.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoDelete(Bool force, Bool recursive = false) const;

	//----------------------------------------------------------------------------------------
	/// @brief Attempts to physically create the non-existing directories in the directory path expressed by the Url.
	/// @details Will return an `IoError` when the full path does already exist, is the empty path, or the user lacks access rights.
	/// @param[in] createParents 	Check if parent directory exists and if not create them recursively.
	/// @param[out] createdDirs	 	An array that will contain all newly created subdirectories in the order in which they were created. If this parameter is nullptr it will be ignored.
	/// @return						OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// @brief Attempts to copy a file to a different location.
	/// @details The path must exist otherwise the function returns an error.
	/// @param[in] destName						Destination name for the copy operation.
	/// @param[in] overwrite					Set to true to allow overwriting destName file if it was already there.
	/// @param[in] removeReadOnly			Set to true to remove the read only flag on the newly created copy.
	/// @param[in] progress						Progress delegate.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress = IoProgressDelegate()) const;

	//----------------------------------------------------------------------------------------
	/// Moves a file or directory (including hierarchy) to a different location, the path must
	/// exist otherwise the function returns an error. If the destName file or directory does
	/// already exist the function returns with an error.
	/// Moving a file or directory on the same partition will perform without a temporary copy.
	/// @param[in] destName						Destination name for the move operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoMove(const Url& destName) const;

	//----------------------------------------------------------------------------------------
	/// Renames a file or directory. The newName must not be the name of an existing file
	/// or directory.
	/// @param[in] newName						Destination name for the move operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoRename(const Url& newName) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the free space on a volume. The Url must point to a volume, e.g. by browsing SCHEME_VOLUME.
	/// @param[out] availableBytes		The number of available bytes on the volume.
	/// @param[out] totalBytes				The total size of the volume in bytes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const;

	//----------------------------------------------------------------------------------------
	/// Opens or shows the file in the systems explorer (desktop/finder).
	/// Under windows that would be on the desktop/explorer. Under OSX this would be the Finder.
	/// Depending on the url scheme this could also open another browser.
	/// @param[in] flags							Flags to define how to open that file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Return a normalized a url. Does not involve any Io operation and is just syntax based.
	/// If nothing needs to be normalized the same path is returned.
	/// @param[in] flags							Flags to define type of normalization.
	/// @return												The normalized url. In case of a normalization error *this is returned.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Url> Normalize(NORMALIZEFLAGS flags = NORMALIZEFLAGS::SCHEME_BASED) const;

	//----------------------------------------------------------------------------------------
	/// Return a normalized a url. If the normalized url is a link, the IoHandler can resolve it (if supported).
	/// E.g. the file:/// handler resolves symbolic links, where the http:// handler does not resolve llinks.
	/// @param[in] flags							Flags to define type of normalization.
	/// @return												The normalized and resolved url. In case of a normalization error *this is returned.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Url> IoNormalize(NORMALIZEFLAGS flags = NORMALIZEFLAGS::SCHEME_BASED) const;

	//----------------------------------------------------------------------------------------
	/// Appends a name to the Url.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Url> operator +(const String& s) const;

	//----------------------------------------------------------------------------------------
	/// Appends a relative Url to the current Url.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Url> operator +(const Url& s) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CString ToCString() const;

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);

	/// @copydoc DefaultDoc::GetHashCode
	MAXON_FUNCTION HashInt GetHashCode() const;

	/// @copydoc DefaultDoc::GetUniqueHashCode
	MAXON_FUNCTION UniqueHash GetUniqueHashCode() const;

	//----------------------------------------------------------------------------------------
	/// ConvertToUiNameWithRepository converts the url into a humans readable string.
	/// Implementations can use this function to convert string.
	/// e.g. Assets can build a nice human readable url string.
	/// @param[in] flags							Flags for the conversion, see CONVERTTOUINAMEFLAGS.
	/// @param[in] lookupRepository		AssetRespoitory to search in.
	/// @return                       String on success.
	//---------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> ConvertToUiName(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const;

	//----------------------------------------------------------------------------------------
	/// ConvertFromUiName converts a string into a url.
	/// @param[in] str								String to convert.
	/// @param[in] lookupRepository		AssetRespoitory to search in.
	/// @return                       Url on success. Please note that the url might be translated into another scheme (e.g. assetdb:// -> asset://).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository);
};

// include auto-generated header file here
#include "url1.hxx"

//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for the default scheme implementation.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_HANDLER = LiteralId("handler");

//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for generic file system access.
/// @details Supports all stream types and directory browsing.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_FILESYSTEM = LiteralId("file");

#undef URLSCHEME_UNC_ENABLED // disabled because nobody uses it
#ifdef URLSCHEME_UNC_ENABLED
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Uniform Naming Convention (UNC) network resource access.
/// @details Currently disabled.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_UNCFILESYSTEM = LiteralId("unc");
#endif

//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for storing authority information within the type @ref maxon::Url.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_AUTHORITY = LiteralId("authority");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for relative @ref maxon::Url "Urls" which can be resolved with @ref maxon::Url::IoNormalize.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_RELATIVE = LiteralId("relative");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling local drive access of a system.
/// @details The volumes of a system can be iterated with @code for (const auto& it : maxon::Url(maxon::URLSCHEME_VOLUME).GetBrowseIterator(maxon::GETBROWSEITERATORFLAGS::NONE)) {} @endcode
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_VOLUME = LiteralId("volume");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling network drive access of a system.
/// @details The network drives of a system can be iterated with @code for (const auto& it : maxon::Url(maxon::URLSCHEME_NETWORK).GetBrowseIterator(maxon::GETBROWSEITERATORFLAGS::NONE)) {} @endcode
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_NETWORK = LiteralId("network");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling storage device access on a system.
/// @details The storage devices of a system can be iterated with @code for (const auto& it : maxon::Url(maxon::URLSCHEME_STORAGE).GetBrowseIterator(maxon::GETBROWSEITERATORFLAGS::NONE)) {} @endcode
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_STORAGE = LiteralId("storage");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling zip archive access.
/// @details Supports directory browsing and InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_ZIPFILE = LiteralId("zip");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling gzip archive access.
/// @details Supports directory browsing and InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_GZIPFILE = LiteralId("gzip");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling memory files.
/// @details Supports InputStreams and OutputStreams. Please use @ref maxon::IoMemoryInterface for initialization.
/// @see UrlScheme
/// @see IoMemoryInterface
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_MEMORY = LiteralId("memory");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Transmission Control Protocol (TCP) connections.
/// @details Supports all stream types and can be initialized in the following manners: 
/// @code 
/// maxon::Url streamName(maxon::URLSCHEME_TCP); 
/// streamName.SetAuthority("127.0.0.1:12345"_s);
/// @endcode
/// @code 
/// maxon::Url streamName(URLSCHEME_TCP); 
/// streamName.SetData(maxon::URLFLAGS::TCP_NETWORKCONNECTIONREF, incomingConnection);
/// @endcode
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_TCP = LiteralId("tcp");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for WebSocket connections.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_WS = LiteralId("webSocket");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for SSL encrypted WebSocket connections.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_WSS = LiteralId("webSocketSecure");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Hypertext Transfer Protocol (HTTP) connections.
/// @details Supports only InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_HTTP = LiteralId("http");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Hypertext Transfer Protocol Secure (HTTPS) connections.
/// @details Supports only InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_HTTPS = LiteralId("https");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for File Transfer Protocol (FTP) connections.
/// @details Supports InputStreams, OutputStreams and browsing.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_FTP = LiteralId("ftp");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Secure/SSH File Transfer Protocol (SFTP) connections.
/// @details Supports InputStreams, OutputStreams and browsing.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_SFTP = LiteralId("sftp");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for Perforce access.
/// @details Supports browsing depots and InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_PERFORCE = LiteralId("perforce");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for en- and decryption streams.
/// @details Supports InputStreams, OutputStreams and InOutputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_CRYPTOFILE = LiteralId("crypto");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for handling temporary file systems to accelerate file IO.
/// @details Supports InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_CACHE = LiteralId("cache");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for inter-process communication. 
/// @details One endpoint must passed to the started process, the other one can be used for reading and writing. Supports only InOutputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_PIPE = LiteralId("pipe");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for redirecting outputs to `stdout`.
/// @details Supports only OutputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_STDOUT = LiteralId("stdout");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for redirecting outputs to `stderr`.
/// @details Supports only OutputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_STDERR = LiteralId("stderr");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for redirecting inputs to `stdin`.
/// @details Supports only InputStreams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_STDIN = LiteralId("stdin");
//----------------------------------------------------------------------------------------
/// @brief Scheme identifier for the Android Package (apk) file format.
/// @details This scheme is only supported on Android.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_APK_ASSET = LiteralId("apkasset");
//----------------------------------------------------------------------------------------
/// Identifier for the "mfs" file scheme for @ref MemoryFileStruct streams.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_MEMORYFILESTRUCT = LiteralId("mfs");
//----------------------------------------------------------------------------------------
/// Identifier for the "ramdisk" scheme for virtual file systems in RAM.
/// @see UrlScheme
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_RAMDISK = LiteralId("ramdisk");

//----------------------------------------------------------------------------------------
/// Class to handle Urls.
///
/// Urls consist of three parts: a <B>scheme</B>, an <B>authority</B> and a <B>path</B>.
/// The readable text-representation is "scheme://authority/path".
///
/// The <B>scheme</B> defines which handler is used, e.g. "http" for web-based connections or "file" for the regular file system.
///
/// The <B>authority</B> defines the machine, which can be empty for "localhost", a network drive or a webserver.
/// It can also refer to an embedded file, e.g. a ZIP. To distinguish that case the readable text representation
/// contains brackets: "scheme://[authority]/path". Nesting is possible repeatedly.
///
/// Finally the <B>path</B> component defines the unique location of a file or directory on the target machine.
/// In most schemes paths are a combination of the directory path and file path, but the path could also be a network query or database entry.
/// Path components are always separated by a forward slash and the forward slash is a reserved character that cannot be used for names.
///
/// Urls are always case-sensitive, independent of the used scheme handler.
///
/// Under Windows the backslash is automatically replaced and converted to a forward slash when you use SetPath or SetSystemPath. Note that
/// backslashes passed to SetUrl or Url() will not be converted.
///
/// One note about constructing Url paths: if you use Append or + there is a big difference whether you add a
/// String or a Url. If you add a String you can only add a single name component. With a relative Url you can
/// add multiple path components at once (however this must be a relative Url, any other type will fail).
/// E.g. allowed is
/// Url a = Url("file:///HD"_s) + "test"_s + "image.tif"_s;
/// Url b = Url("file:///HD"_s) + Url("test/image.tif"_s);
/// whereas this will fail:
/// Url a = Url("file:///HD"_s) + "test/image.tif"_s;
/// Url a = Url("file:///HD"_s) + Url("file:///test"_s);
///
///
/// Here an overview over different types of Urls:
///
/// - Url("file:///c:/test/image.tif"_s) - this is a regular Windows file
///   equivalent to Url("c:\test\image.tif"_s) or Url("c:/test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_FILE
/// 	GetAuthority() returns an empty Url with UrlScheme()
/// 	GetPath() returns "c:/test/image.tif"
/// 	GetSystemPath() returns "c:/test/image.tif"
///
/// - Url("file:///HD/test/image.tif"_s) - this is a regular OS X or Linux file
///   equivalent to Url("/HD/test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_FILE
/// 	GetAuthority() returns an empty Url with UrlScheme()
/// 	GetPath() returns "HD/test/image.tif"
/// 	GetSystemPath() returns "/HD/test/image.tif"
///
/// - Url("file://qnap/test/image.tif"_s) - this is a file on a Windows network drive
///   equivalent to Url("\\qnap\test\image.tif"_s) or Url("//qnap/test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_FILE
/// 	GetAuthority() returns a Url with URLSCHEME_AUTHORITY and path "qnap"
/// 	GetPath() returns "test/image.tif";
/// 	GetSystemPath() returns "//qnap/test/image.tif";
///
/// - Url("ftp://192.168.0.1/test/image.tif"_s) - this is a regular ftp file
///   equivalent to Url(URLSCHEME_FTP, Url(URLSCHEME_AUTHORITY, Url(), "192.168.0.1"_s), "test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_FTP
/// 	GetAuthority() returns a Url with URLSCHEME_FTP and authority "192.168.0.1"
/// 	GetPath() returns "test/image.tif";
/// 	GetSystemPath() returns "test/image.tif";
///
/// - Url("zip://[http://192.168.0.1:1234/archive.zip]/test/image.tif"_s) - this is a file embedded in a ZIP archive on a Web server.
///   equivalent to Url(URLSCHEME_ZIP, Url("http://192.168.0.1:1234/archive.zip"_s), "test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_FILE
/// 	GetAuthority() returns the embedded zip file - a Url with URLSCHEME_HTTP, Authority 192.168.0.1:1234 and path "archive.zip"
/// 	GetPath() returns "test/image.tif"
/// 	GetSystemPath() returns "test/image.tif"
///
/// - Url("test/image.tif"_s) - this is relative path
///   equivalent to Url("./test/image.tif"_s)
/// 	GetScheme() returns URLSCHEME_RELATIVE
/// 	GetAuthority() returns an empty Url with UrlScheme()
/// 	GetPath() returns "test/image.tif"
/// 	GetSystemPath() returns "test/image.tif"
///
///
/// If the Url class is used, it should always be clear what the object can be - a file, a directory, a path (file or directory) or a relative path. Therefore
/// the naming convention is very strict and refers to <a href="http://tools.ietf.org/html/rfc1738">RFC1738</a>. The path component of a Url typically consists of a
/// directory and a name. Name is the term for a simple filename like test.abc or picture.png. Its placed at the end of a Url. A directory is a set of strings, split
/// by the forward slash-delimiter, in which other directories are kept, e.g. \/Users/%MyUser/Desktop. Path is the combination of directory and name.
///
/// Following this convention helps the maintainers and users of a function to keep track of what is accepted. If the Url parameter name of a saving function contains for example <i>path</i> it's always clear
/// that the function needs the directory and a name. If the user is allowed to pass everything to the function (a file or directory) the documentation should clarify that (and if the behavior
/// differs from what is passed it must also be documented).
/// Examples:
///
/// @code
/// void DeleteItem(Url targetFile);			// Accepts a file like file:///Users/MyUser/Desktop/test.jpg, but no directory.
/// void DeleteItem(Url targetDir);				// Accepts a directory like file:///Users/MyUser/Desktop, but no file.
/// void DeleteItem(Url targetPath);			// Accepts a file or directory.
/// void DeleteItem(String targetName);		// Accepts a name like test.png. Names cannot be stored in Urls. The documentation of the function should contain information on where the file needs to be locaeted.
/// void DeleteItem(Url relativePath);		// Accepts a path like ./test/test.png. The documentation of the function should contain information on how the relative path is evaluated.
/// Url GetFile();												// Returns e.g. file:///Users/MyUser/Desktop/test.jpg.
/// Url GetDirectory();										// Returns e.g. file:///Users/MyUser/Desktop
/// String GetName();											// Returns e.g. file.jpg
/// Url GetPath();												// Returns a file or directory.
/// @endcode
///
///
/// Functions starting with "Io" operate directly on the object behind the Url (e.g. a file or directory).
///
/// @MAXON_ANNOTATION{reflection}
//----------------------------------------------------------------------------------------
class Url : public UrlInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Url, Reference);

	//----------------------------------------------------------------------------------------
	/// UrlScheme constructor.
	/// @param[in] scheme							Creates an Url and sets a scheme (e.g. URLSCHEME_FILE or URLSCHEME_HTTP).
	//----------------------------------------------------------------------------------------
	explicit Url(const UrlScheme& scheme)
	{
		SetScheme(scheme) iferr_ignore("Errors are ignored for convenience");
	}

	//----------------------------------------------------------------------------------------
	/// Url constructor from a String. Identical to SetUrl(urlString, true).
	/// @param[in] urlString					A valid Url, e.g. "file:///H:/test.txt".
	/// 															If no scheme is specified URLSCHEME_FILESYSTEM will be assumed and the
	/// 															regular file system syntax can be passed.
	/// 															If no scheme is specified and the urlString starts with no drive letter or slash
	/// 															URLSCHEME_RELATIVE will be assumed.
	//----------------------------------------------------------------------------------------
	explicit Url(const String& urlString)
	{
		SetUrl(urlString, true) iferr_ignore("Errors are ignored for convenience");
	}

	//----------------------------------------------------------------------------------------
	/// Url constructor from a CString. Identical to SetUrl(urlString, true).
	/// @param[in] urlString					A valid Url, e.g. "file:///H:/test.txt".
	/// 															If no scheme is specified URLSCHEME_FILESYSTEM will be assumed and the
	/// 															regular file system syntax can be passed.
	/// 															If no scheme is specified and the urlString starts with no drive letter or slash
	/// 															URLSCHEME_RELATIVE will be assumed.
	//----------------------------------------------------------------------------------------
	explicit Url(const CString& urlString)
	{
		SetUrl(String{urlString}, true) iferr_ignore("Errors are ignored for convenience");
	}

	//----------------------------------------------------------------------------------------
	/// Url constructor with scheme, authority and path.
	/// @param[in] scheme							The scheme that will be set. Should always be lowercase because no normalization is applied here.
	/// @param[in] authority					The authority that will be set. Can be an empty Url().
	/// @param[in] path								The path that will be set.
	//----------------------------------------------------------------------------------------
	explicit Url(const UrlScheme& scheme, const Url& authority, const String& path)
	{
		SetScheme(scheme) iferr_ignore("Errors are ignored for convenience");
		SetPath(path) iferr_ignore("Errors are ignored for convenience");
		SetAuthority(authority) iferr_ignore("Errors are ignored for convenience");
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found an error will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly together with the result type "dict.Get<String>(Int32(5))".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												Data converted to the right type on success.
	//----------------------------------------------------------------------------------------
	template <typename T = void, typename KEY = void>
	Result<typename std::conditional<STD_IS_REPLACEMENT(void, T), typename IsFidClass<KEY>::type, T>::type> Get(KEY&& key) const
	{
		using TT = typename std::conditional<STD_IS_REPLACEMENT(void, T), typename IsFidClass<KEY>::type, T>::type;
		iferr (Data data = Super::GetData(ConvertKeyToDataPtr<IsDerived<URLFLAGS::RESTRICT>, true>(std::forward<KEY>(key))))
			return err;
		iferr (auto&& res = data.template Get<TT>())
			return err;
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		return std::move(res);
		MAXON_WARNING_POP
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found the given default value will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] defaultValue				Default value which should be returned if the key cannot be found.
	/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY> T Get(KEY&& key, const T& defaultValue) const
	{
		iferr (Data data = Super::GetData(ConvertKeyToDataPtr<IsDerived<URLFLAGS::RESTRICT>, true>(std::forward<KEY>(key))))
			return defaultValue;
		iferr (auto&& res = data.template Get<T>())
			return defaultValue;
		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Set data under a specific id. this function is template to allow implicit Set calls for each data type.
	/// This functions offers 2 possible calls. First using an FId "dict.Set(MAXCHINEINFO::COMPUTERNAME, "data"_s)" or second using any type directly "dict.Set(Int32(5), "data"_s)".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] data								Data to be stored in the dictionary.
	/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY> Result<void> Set(KEY&& key, T&& data, Bool persistent = true)
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value && !STD_IS_REPLACEMENT(same, typename IsFidClass<KEY>::type, Data), typename maxon::Substitute<T, typename IsFidClass<KEY>::type>::type, void>::type;
		Data tmp;
		iferr (tmp.SetImpl<TT>(std::forward<T>(data), OVERLOAD_MAX_RANK))
			return err;
		return Super::SetData(ConvertKeyToDataPtr<IsDerived<URLFLAGS::RESTRICT>, true>(std::forward<KEY>(key)), std::move(tmp), persistent);
	}
};

//----------------------------------------------------------------------------------------
/// This helper class template can be used for function parameters where the function needs to get a stream,
/// but for convenience also passing a Url as argument to the parameter shall be allowed. In other words, a function
/// @code
/// Result<void> LoadSomething(UrlOrInputStream&& input);
/// @endcode
/// can be invoked by passing either a Url or an InputStreamRef to the parameter. It even allows to pass
/// Result<Url> or Result<InputStreamRef>, then the error, if any, will be stored within UrlOrStream and returned
/// by the call to GetStream.
///
/// In the implementation of a function with a UrlOrStream parameter,
/// GetStream has to be called to obtain the stream, and finally Close to close the stream (but this will only be done
/// if the stream was obtained from a Url):
/// @code
/// Result<void> LoadSomething(UrlOrInputStream&& input)
/// {
///   iferr_scope;
///   InputStreamRef& s = input.GetStream() iferr_return;
///   // load data from s;
///   input.Close() iferr_return; // important: write input.Close(), not s.Close()
///   return OK;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
template <typename STREAM> class UrlOrStream
{
public:
	UrlOrStream() = default;

	MAXON_IMPLICIT UrlOrStream(const Url& url, OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) : _url(url), _flags(flags)
	{
	}

	MAXON_IMPLICIT UrlOrStream(const STREAM& stream) : _stream(stream)
	{
	}

	MAXON_IMPLICIT UrlOrStream(const Result<Url>& url, OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE)
	{
		_url = url.GetValueAndError(const_cast<ThreadReferencedError&>(_error.GetErrorStorage()));
		_flags = flags;
	}

	MAXON_IMPLICIT UrlOrStream(const Result<STREAM>& stream)
	{
		_stream = stream.GetValueAndError(const_cast<ThreadReferencedError&>(_error.GetErrorStorage()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the stream to use. If this UrlOrStream was constructed with a Url and a stream hasn't yet
	/// been opened, a new stream is opened.
	/// @return												The stream to use.
	//----------------------------------------------------------------------------------------
	Result<STREAM&> GetStream();

	const Url& GetUrl() const { return _url; }

	//----------------------------------------------------------------------------------------
	/// Close the underlying stream if is has been opened by this UrlOrStream. You have to call this function
	/// at the end of the code which has obtained the stream by GetStream(). The stream is closed only
	/// if this UrlOrStream was constructed by a Url, but not if is was constructed by a stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Close();

private:
	Url							_url;
	ObjectRef				_stream; // we use Object here, otherwise we'd get compilation errors when iostreams.h isn't included
	Result<void>		_error;
	OPENSTREAMFLAGS _flags = OPENSTREAMFLAGS::NONE;
};

// include auto-generated header file here
#include "url2.hxx"

inline Result<Url> UrlInterface::operator +(const String& s) const
{
	Url n(this);
	iferr (n.Append(s))
		return err;
	return std::move(n);
}

inline Result<Url> UrlInterface::operator +(const Url& s) const
{
	Url n(this);
	iferr (n.Append(s))
		return err;
	return std::move(n);
}

using UrlIoShowInOSDelegate = Delegate<Result<Bool>(const Url& url, IOSHOWINOSFLAGS flags)>;

MAXON_REGISTRY(UrlIoShowInOSDelegate, UrlIoShowInOSRegistry, "net.maxon.registry.urlioshowinos");

/// @}

} // namespace maxon

#endif // URL_H__
