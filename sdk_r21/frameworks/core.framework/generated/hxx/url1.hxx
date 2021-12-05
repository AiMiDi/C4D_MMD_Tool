#if 1
namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class Url;

struct UrlInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = Url;
	/// Intermediate helper class for UrlInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using RESTRICT_DICTIONARY_PROPS = UrlInterface::RESTRICT_DICTIONARY_PROPS;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type GetScheme() const;
/// Returns an embedded Url.
/// E.g. if the Url is "zip://[file:///c:/images.zip]/image01.jpg" a call to GetEmbeddedUrl() will return "file:///c:/images.zip".
/// @return												The embedded Url or if there was none Url().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetEmbeddedUrl() const;
/// Returns the name of the last component.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call to GetName() will return "file.txt".
/// @return												The name of the last path component.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// Returns the Url of the directory.
/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetDirectory() will return "file:///c:/directory".
/// @return												The directory Url.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetDirectory() const;
/// Returns the path component of the Url. Note that this doesn't contain scheme and authority.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call will return "c:/directory/file.txt".
/// @return												The path component of the Url (with no authority and scheme).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type GetPath() const;
/// Returns a path from the Url that the current operating system (or scheme handler) can understand.
/// If the Url contains no valid scheme an error will be returned.
/// An error will also be returned if the Url contains illegal characters for the scheme,
/// e.g. backslashes on Windows in a file scheme.
/// @return												The system path.
		inline Result<String> GetSystemPath() const;
/// Returns the Url as a string. A Url has the format scheme://authority/path.
/// @return												The Url as a string.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetUrl() const;
/// Returns the authority of a Url. The authority can be a machine, server or embedded file.
/// @return												The authority of the Url. If the machine is localhost the returned Url is empty.
/// 															If it is a machine or server the scheme will be URLSCHEME_AUTHORITY.
/// 															Otherwise it defines an embedded file.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type GetAuthority() const;
/// Returns all parts of the Url system path as separated strings.
/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetComponents will return: { "C:", "directory", "file.txt" }.
/// @param[out] parts							Array with the parts of the system path. A possible authority will be returned as the first part of the array.
/// @return												OK on success.
		inline Result<void> GetComponents(const NonConstArray<String>& parts) const;
/// Returns a relative url based on the given basePath. The basePath needs to have the same scheme, authority. basepath needs to be part
/// of the path of this url.
/// @param[in] basePath						The base of the relative url.
/// @return												Returns the relative url on success.
		inline Result<Url> GetRelativeUrl(const Url& basePath) const;
/// Returns the suffix of the Url.
/// E.g. if the Url was "file:///c:/directory/file.txt" a call of GetSuffix() will return "txt".
/// @return												The suffix without dot.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetSuffix() const;
/// Checks whether the Url has the a given suffix
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of CheckSuffix("txt"_s) will return true.
/// @param[in] suffix							The suffix without dot to check against.
/// @return												True if the suffix matches.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CheckSuffix(const String& suffix) const;
/// Returns if the Url has no content. A Url is considered empty if it has no path component
/// and no authority (even if a scheme is set).
/// @return												True if the Url is empty.
///
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
/// Returns if the Url has any content. A Url is considered populated if it has a path component
/// or authority set.
/// @return												True if the Url has content.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Compares the object against 'name'.
/// Note that by default the comparison is case-sensitive, so './Test.tif' and './test.tif'
/// are not the same. To check if Urls point to the identical item use Url::IoNormalizeAndResolve instead.
/// @param[in] name								Comparison object.
/// @param[in] mode								Comparision mode.
/// @return												The comparison result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const UrlInterface* name, URLCOMPARE mode = URLCOMPARE::DEFAULT) const;
/// Returns Url attributes. See maxon::URLFLAGS for details.
/// @param[in] key								The id of the property to get. The possible values for id depend on the scheme.
/// @return												The attribute value or an error if there was none.
		inline Result<Data> GetData(const ConstDataPtr& key) const;
/// Detects the type of the object behind Url.
/// This allows to check if a file or directory exists.
/// @return												IODETECT of the given Url.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type IoDetect() const;
/// Returns a pointer to a IoConnectionInterface class of this Url.
/// @return												The pointer to the IoConnectionInterface. The return value needs to be checked against nullptr.
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type), Result<IoConnectionRef>) OpenConnection() const;
/// Returns a pointer to a InputStreamInterface class of this Url.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												The pointer to the InputStreamInterface. The return value needs to be checked against nullptr.
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type), Result<InputStreamRef>) OpenInputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
/// Returns a pointer to a OutputStreamInterface class of this Url.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												The pointer to the OutputStreamInterface. The return value needs to be checked against nullptr.
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type), Result<OutputStreamRef>) OpenOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
/// Returns a pointer to a InOutputStreamInterface class of this Url.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												The pointer to the InOutputStreamInterface. The return value needs to be checked against nullptr.
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type), Result<InOutputStreamRef>) OpenInOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
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
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type), Result<IoBrowseRef>) GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const;
/// Returns the file attributes of the object behind Url.
/// @return												IOATTRIBUTES of the file.
		inline Result<IOATTRIBUTES> IoGetAttributes() const;
/// Modify the file attributes of the object behind Url.
/// @param[in] flags							Flags to set/clear.
/// @param[in] mask								Mask with all flags to be changed.
/// @return												OK on success.
		inline Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const;
/// Returns the DateTime of the current file. The time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @return												Returns the DateTime or an error.
		inline DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type), Result<UniversalDateTime>) IoGetTime(IOTIMEMODE mode) const;
/// Modifies the DateTime of the current file. The time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @param[in] dateTime						The new datetime for the file.
/// @return												OK on success.
		inline Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const;
/// Deletes a file or directory physically on the medium.
/// @param[in] force							Set to true tries to deletes the file/directory even if the file/directory has read only flags set.
/// @param[in] recursive					Recursively deletes a directory and its content. If a file is specified this value is ignored.
/// @return												Set to true if the file/directory could be removed successfully.
		inline Result<void> IoDelete(Bool force, Bool recursive = false) const;
/// Creates a new directory. The function will return false if the directory already exists.
/// @param[in] createParents			Check if parent directory exists and if not create them recursively.
/// @param[out] createdDirs				An array that will contain all newly created subdirectories in the order in which they were created. If this parameter is nullptr it will be ignored.
/// @return												Set to true if the directory could be created successfully.
		inline Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs = nullptr) const;
/// Copies a file to a different location, the path must exist otherwise the function returns an error.
/// @param[in] destName						Destination name for the copy operation.
/// @param[in] overwrite					Set to true to allow overwriting destName file if it was already there.
/// @param[in] removeReadOnly			Set to true to remove the read only flag on the newly created copy.
/// @return												OK on success.
		inline Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) const;
/// Moves a file or directory (including hierarchy) to a different location, the path must
/// exist otherwise the function returns an error. If the destName file or directory does
/// already exist the function returns with an error.
/// Moving a file or directory on the same partition will perform without a temporary copy.
/// @param[in] destName						Destination name for the move operation.
/// @return												OK on success.
		inline Result<void> IoMove(const Url& destName) const;
/// Renames a file or directory. The newName must not be the name of an existing file
/// or directory.
/// @param[in] newName						Destination name for the move operation.
/// @return												OK on success.
		inline Result<void> IoRename(const Url& newName) const;
/// Calculates the free space on a volume. The Url must point to a volume, e.g. by browsing SCHEME_VOLUME.
/// @param[out] availableBytes		The number of available bytes on the volume.
/// @param[out] totalBytes				The total size of the volume in bytes.
/// @return												OK on success.
		inline Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const;
/// Opens or shows the file in the systems explorer (desktop/finder).
/// Under windows that would be on the desktop/explorer. Under OSX this would be the Finder.
/// Depending on the url scheme this could also open another browser.
/// @param[in] flags							Flags to define how to open that file.
/// @return												OK on success.
		inline Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const;
/// Return a normalized a url. Does not involve any Io operation and is just syntax based.
/// If nothing needs to be normalized the same path is returned.
/// @param[in] flags							Flags to define type of normalization.
/// @return												The normalized url. In case of a normalization error *this is returned.
		inline Result<Url> Normalize(NORMALIZEFLAGS flags = NORMALIZEFLAGS::SCHEME_BASED) const;
/// Return a normalized a url. If the normalized url is a link, the IoHandler can resolve it (if supported).
/// E.g. the file:/// handler resolves symbolic links, where the http:// handler does not resolve llinks.
/// @param[in] flags							Flags to define type of normalization.
/// @return												The normalized and resolved url. In case of a normalization error *this is returned.
		inline Result<Url> IoNormalize(NORMALIZEFLAGS flags = NORMALIZEFLAGS::SCHEME_BASED) const;
/// Appends a name to the Url.
		inline Result<Url> operator +(const String& s) const;
/// Appends a relative Url to the current Url.
		inline Result<Url> operator +(const Url& s) const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for UrlInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline Result<void> SetScheme(const UrlScheme& scheme) const;
/// Appends a new component to the Url.
/// E.g. if the Url is "file:///c:/directory" a call of Append("file.txt"_s) will result in "file:///c:/directory/file.txt".
/// @param[in] name								A component that will be added to the end of the Url. A separator (forward slash) will be placed between the end of the current Url and the new part.
/// 															The value must not contain any forward slashes (under Windows additionally no backslashes), otherwise nothing will be done.
/// @return												*this.
///
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Append(const String& name) const;
/// Appends a relative Url to the current one.
/// E.g. if the Url is "file:///c:/directory" a call of Append(Url("test/file.txt"_s)) will result in "file:///c:/directory/test/file.txt".
/// @param[in] relativeUrl				The relative Url that will be added. A separator (forward slash) will be placed between the end of the current Url and the new part.
/// 															relativeUrl must be a Url with URLSCHEME_RELATIVE, otherwise nothing will be done.
/// @return												*this.
///
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Append(const Url& relativeUrl) const;
/// Removes the last part of a Url.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of RemoveName() will result in "file:///c:/directory".
/// @return												OK on success. Returns an error if there is nothing to remove.
		inline Result<void> RemoveName() const;
/// Replaces and sets an embedded Url.
/// E.g. if the Url is "zip://[file:///c:/images.zip]/image01.jpg" a call to SetEmbeddedUrl("file:///c:/otherimages.zip"_s) will result in "zip://[file:///c:/otherimages.zip]/image01.jpg".
/// @param[in] url								The new embedded Url.
/// @return												OK on success.
		inline Result<void> SetEmbeddedUrl(const Url& url) const;
/// Replaces the last component of a Url. The name must not contain a forward slashes and under Windows additionally no backslashes.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetName("change.tif"_s) will result in "file:///c:/directory/change.tif".
/// @param[in] name								The new name.
/// @return												OK on success.
		inline Result<void> SetName(const String& name) const;
/// Replaces the path component of the Url. The path is stored unchanged with the exception
/// that under Windows all backslashes will be changed into forward slashes.
/// @param[in] path								The new path.
/// @return												OK on success.
		inline Result<void> SetPath(const String& path) const;
/// Stores a system path in a Url.
/// This call needs to be done after the appropriate scheme has been set.
/// If no scheme is set URLSCHEME_FILESYSTEM will be automatically set.
/// The system path may be converted to a different internal representation, e.g. split
/// into authority and path components.
/// Under Windows all backslashes will be changed into forward slashes.
/// @param[in] path								The system path.
/// @return												OK on success.
		inline Result<void> SetSystemPath(const String& path) const;
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
		inline Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) const;
/// Sets the authority of a Url. This can be a machine or server.
/// @param[in] authority					The new authority. String() can be passed for no authority / localhost.
/// 															The authority scheme will be URLSCHEME_AUTHORITY.
/// @return												OK on success.
		inline Result<void> SetAuthority(const String& authority) const;
/// Sets the authority of a Url. This can be a machine, server or embedded file. Url() can be
/// passed for no authority.
/// @param[in] authority					The new authority. Can be a machine, server or embedded file.
/// @return												OK on success.
		inline Result<void> SetAuthority(const Url& authority) const;
/// Replaces the suffix of the Url.
/// If the Url had no suffix before a dot will be added together with the suffix string.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetSuffix("jpg"_s) will result in "file:///c:/directory/file.jpg".
/// @param[in] suffix							The new suffix of the Url without dot.
/// @return												OK on success.
		inline Result<void> SetSuffix(const String& suffix) const;
/// Deletes the suffix of the Url.
/// E.g. if the Url was "file:///c:/directory/file.txt" a call will result in "file:///c:/directory/file".
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type ClearSuffix() const;
/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
/// @param[in] data								Data to be set.
/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
/// @return												OK on success.
		inline Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent = true) const;
/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
/// @param[in] data								Data to be set.
/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
/// @return												OK on success.
		inline Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent = true) const;
	};
	/// Intermediate helper class for UrlInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Url, false>::type&() const { return reinterpret_cast<const Url&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Url, false>::type&() { return reinterpret_cast<const Url&>(this->GetBaseRef()); }
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
		inline Result<void> SetScheme(const UrlScheme& scheme);
/// Appends a new component to the Url.
/// E.g. if the Url is "file:///c:/directory" a call of Append("file.txt"_s) will result in "file:///c:/directory/file.txt".
/// @param[in] name								A component that will be added to the end of the Url. A separator (forward slash) will be placed between the end of the current Url and the new part.
/// 															The value must not contain any forward slashes (under Windows additionally no backslashes), otherwise nothing will be done.
/// @return												*this.
///
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Append(const String& name);
/// Appends a relative Url to the current one.
/// E.g. if the Url is "file:///c:/directory" a call of Append(Url("test/file.txt"_s)) will result in "file:///c:/directory/test/file.txt".
/// @param[in] relativeUrl				The relative Url that will be added. A separator (forward slash) will be placed between the end of the current Url and the new part.
/// 															relativeUrl must be a Url with URLSCHEME_RELATIVE, otherwise nothing will be done.
/// @return												*this.
///
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Append(const Url& relativeUrl);
/// Removes the last part of a Url.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of RemoveName() will result in "file:///c:/directory".
/// @return												OK on success. Returns an error if there is nothing to remove.
		inline Result<void> RemoveName();
/// Replaces and sets an embedded Url.
/// E.g. if the Url is "zip://[file:///c:/images.zip]/image01.jpg" a call to SetEmbeddedUrl("file:///c:/otherimages.zip"_s) will result in "zip://[file:///c:/otherimages.zip]/image01.jpg".
/// @param[in] url								The new embedded Url.
/// @return												OK on success.
		inline Result<void> SetEmbeddedUrl(const Url& url);
/// Replaces the last component of a Url. The name must not contain a forward slashes and under Windows additionally no backslashes.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetName("change.tif"_s) will result in "file:///c:/directory/change.tif".
/// @param[in] name								The new name.
/// @return												OK on success.
		inline Result<void> SetName(const String& name);
/// Replaces the path component of the Url. The path is stored unchanged with the exception
/// that under Windows all backslashes will be changed into forward slashes.
/// @param[in] path								The new path.
/// @return												OK on success.
		inline Result<void> SetPath(const String& path);
/// Stores a system path in a Url.
/// This call needs to be done after the appropriate scheme has been set.
/// If no scheme is set URLSCHEME_FILESYSTEM will be automatically set.
/// The system path may be converted to a different internal representation, e.g. split
/// into authority and path components.
/// Under Windows all backslashes will be changed into forward slashes.
/// @param[in] path								The system path.
/// @return												OK on success.
		inline Result<void> SetSystemPath(const String& path);
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
		inline Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme);
/// Sets the authority of a Url. This can be a machine or server.
/// @param[in] authority					The new authority. String() can be passed for no authority / localhost.
/// 															The authority scheme will be URLSCHEME_AUTHORITY.
/// @return												OK on success.
		inline Result<void> SetAuthority(const String& authority);
/// Sets the authority of a Url. This can be a machine, server or embedded file. Url() can be
/// passed for no authority.
/// @param[in] authority					The new authority. Can be a machine, server or embedded file.
/// @return												OK on success.
		inline Result<void> SetAuthority(const Url& authority);
/// Replaces the suffix of the Url.
/// If the Url had no suffix before a dot will be added together with the suffix string.
/// E.g. if the Url is "file:///c:/directory/file.txt" a call of SetSuffix("jpg"_s) will result in "file:///c:/directory/file.jpg".
/// @param[in] suffix							The new suffix of the Url without dot.
/// @return												OK on success.
		inline Result<void> SetSuffix(const String& suffix);
/// Deletes the suffix of the Url.
/// E.g. if the Url was "file:///c:/directory/file.txt" a call will result in "file:///c:/directory/file".
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type ClearSuffix();
/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
/// @param[in] data								Data to be set.
/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
/// @return												OK on success.
		inline Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent = true);
/// Modifies or sets a Url attribute. See maxon::URLFLAGS for details.
/// @param[in] key								The id of the property to set. The possible values for id depend on the scheme.
/// @param[in] data								Data to be set.
/// @param[in] persistent					With the default value of true the attribute value is serialized. Use false for a transient attribute (one which shall not be serialized).
/// @return												OK on success.
		inline Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent = true);
		explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
		explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class UrlInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Url>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UrlInterface, maxon::StrongCOWRefHandler, Url>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UrlInterface, maxon::StrongCOWRefHandler, Url>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Url> Create();
};

class UrlInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UrlInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UrlInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#ifdef URLSCHEME_UNC_ENABLED
#endif
#endif
