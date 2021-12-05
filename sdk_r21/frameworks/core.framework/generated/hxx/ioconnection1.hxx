#if 1
class ResolveRef;

struct ResolveInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ResolveRef;
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Remove dot segments from a URI path according to RFC3986 Section 5.2.4
/// @param[in] url								Url as input.
/// @return												Resolved Url object.
		static inline Result<Url> RemoveDotSegments(const Url& url);
	};
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ResolveRef, true>::type&() const { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ResolveRef, false>::type&() { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ResolveRef, false>::type&() { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class ResolveInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ResolveRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ResolveInterface, maxon::StrongRefHandler, ResolveRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ResolveInterface, maxon::StrongRefHandler, ResolveRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ResolveRef is the reference class of ResolveInterface.
///
/// Static interface to access Url resolve functionality.
class ResolveRef : public ResolveInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ResolveRef, typename ResolveInterface::Hxx1::Reference);
};

class IoConnectionRef;

struct IoConnectionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoConnectionInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(IoConnectionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IoConnectionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoConnectionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for IoConnectionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the corresponding Url connected to the IoConnectionRef.
/// @return												Returns the name of the connection.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type GetUrl() const;
/// Detects the type of the Url.
/// This allows to check if a file or directory exists.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type IoDetect() const;
/// Returns the file attributes.
/// @return												IOATTRIBUTES of the files.
		inline Result<IOATTRIBUTES> IoGetAttributes() const;
/// Returns the DateTime of the current file. the time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @return												Returns the DateTime or an error.
		inline Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;
/// Calculates the free space on a volume. The Url can point to a volume or directory.
/// @param[out] availableBytes		The number of available bytes on the volume.
/// @param[out] totalBytes				The total size of the volume in bytes.
/// @return												OK on success.
		inline Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const;
/// Opens or shows the file in the systems explorer (desktop/finder).
/// Under windows that would be on the desktop/explorer. Under OSX this would be the Finder.
/// Depending on the url scheme this could also open another browser.
/// @param[in] flags							Flags to define how to show/open that file.
/// @return												OK on success.
		inline Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const;
	};
	/// Intermediate helper class for IoConnectionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoConnectionRef, true>::type&() const { return reinterpret_cast<const IoConnectionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoConnectionRef, false>::type&() { return reinterpret_cast<const IoConnectionRef&>(this->GetBaseRef()); }
/// Returns a IoBrowseInterface class to browse through all children of an Url.
/// The return value needs to be checked against nullptr.
/// @param[in] flags							See GETBROWSEITERATORFLAGS.
/// @return												IoBrowseInterface.
		inline Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const;
/// Opens an InputStreamRef for the given connection. With this kind of streams it's only possible to read from it.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												A pointer to the input stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
/// Opens an OutputStreamRef for the given connection. With this kind of streams it's only possible to write to it.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												Pointer to the output stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
/// Opens an InOutputStreamRef which can read/write for the given connection.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												Pointer to the inoutputstream. The pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE) const;
/// Returns length of the content.
/// @return												The effective size in bytes of the IoConnectionInterface (e.g. filesize).
		inline Result<Int64> GetContentLength() const;
/// Modify the file attributes.
/// @param[in] flags							Flags to set/clear.
/// @param[in] mask								Mask with all flags to be changed.
/// @return												OK on success.
		inline Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const;
/// Modifies the DateTime of the current file. the time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @param[in] dateTime						New datetime for the file.
/// @return												True is the operation was successful.
		inline Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const;
/// Deletes the file physically on the medium.
/// @param[in] force							True tries to deletes the file/directory even if the file/directory has read only flags set.
/// @return												True if the file/directory could be removed successfully.
		inline Result<void> IoDelete(Bool force) const;
/// Creates a new directory. The function returns false if the directory already exists.
/// @param[in] createParents			Check if parent directory exists and if not create them recursively.
/// @param[out] createdDirs				An array that will contain all newly created subdirectories in the order in which they were created. If this parameter is nullptr it will be ignored.
/// @return												True if the directory could be created successfully.
		inline Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs = nullptr) const;
/// Copies a file to a different location, the path must exist otherwise the function returns an error.
/// @param[in] destName						Destination name for the copy operation.
/// @param[in] overwrite					True to allow overwriting destName file if it was already there.
/// @param[in] removeReadOnly			True to remove the read only flag on the newly created copy.
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
	};
	/// Intermediate helper class for IoConnectionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoConnectionRef, false>::type&() { return reinterpret_cast<const IoConnectionRef&>(this->GetBaseRef()); }
/// Returns a IoBrowseInterface class to browse through all children of an Url.
/// The return value needs to be checked against nullptr.
/// @param[in] flags							See GETBROWSEITERATORFLAGS.
/// @return												IoBrowseInterface.
		inline Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags);
/// Opens an InputStreamRef for the given connection. With this kind of streams it's only possible to read from it.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												A pointer to the input stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);
/// Opens an OutputStreamRef for the given connection. With this kind of streams it's only possible to write to it.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												Pointer to the output stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);
/// Opens an InOutputStreamRef which can read/write for the given connection.
/// @param[in] flags							See OPENSTREAMFLAGS for details.
/// @return												Pointer to the inoutputstream. The pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
		inline Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);
/// Returns length of the content.
/// @return												The effective size in bytes of the IoConnectionInterface (e.g. filesize).
		inline Result<Int64> GetContentLength();
/// Modify the file attributes.
/// @param[in] flags							Flags to set/clear.
/// @param[in] mask								Mask with all flags to be changed.
/// @return												OK on success.
		inline Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask);
/// Modifies the DateTime of the current file. the time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @param[in] dateTime						New datetime for the file.
/// @return												True is the operation was successful.
		inline Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime);
/// Deletes the file physically on the medium.
/// @param[in] force							True tries to deletes the file/directory even if the file/directory has read only flags set.
/// @return												True if the file/directory could be removed successfully.
		inline Result<void> IoDelete(Bool force);
/// Creates a new directory. The function returns false if the directory already exists.
/// @param[in] createParents			Check if parent directory exists and if not create them recursively.
/// @param[out] createdDirs				An array that will contain all newly created subdirectories in the order in which they were created. If this parameter is nullptr it will be ignored.
/// @return												True if the directory could be created successfully.
		inline Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs = nullptr);
/// Copies a file to a different location, the path must exist otherwise the function returns an error.
/// @param[in] destName						Destination name for the copy operation.
/// @param[in] overwrite					True to allow overwriting destName file if it was already there.
/// @param[in] removeReadOnly			True to remove the read only flag on the newly created copy.
/// @return												OK on success.
		inline Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly);
/// Moves a file or directory (including hierarchy) to a different location, the path must
/// exist otherwise the function returns an error. If the destName file or directory does
/// already exist the function returns with an error.
/// Moving a file or directory on the same partition will perform without a temporary copy.
/// @param[in] destName						Destination name for the move operation.
/// @return												OK on success.
		inline Result<void> IoMove(const Url& destName);
/// Renames a file or directory. The newName must not be the name of an existing file
/// or directory.
/// @param[in] newName						Destination name for the move operation.
/// @return												OK on success.
		inline Result<void> IoRename(const Url& newName);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IoConnectionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoConnectionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoConnectionInterface, maxon::StrongRefHandler, IoConnectionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoConnectionInterface, maxon::StrongRefHandler, IoConnectionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// IoConnectionRef is the reference class of IoConnectionInterface.
///
/// The connection interface a given Url.
/// This connection needs to be implemented for each protocol. @see UrlScheme.
class IoConnectionRef : public IoConnectionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoConnectionRef, typename IoConnectionInterface::Hxx1::Reference);
};

#endif
