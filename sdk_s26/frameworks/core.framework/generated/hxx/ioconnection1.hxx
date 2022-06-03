#if 1
class ResolveRef;

struct ResolveInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ResolveRef;
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ResolveInterface**);
/// Remove dot segments from a URI path according to RFC3986 Section 5.2.4
/// @param[in] url								Url as input.
/// @return												Resolved Url object.
		static inline Result<Url> RemoveDotSegments(const Url& url);
	};
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ResolveInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ResolveRef, true>::type&() const { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ResolveRef, false>::type&() { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ResolveInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ResolveInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ResolveRef, false>::type&() { return reinterpret_cast<const ResolveRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class ResolveInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ResolveRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ResolveInterface, maxon::StrongRefHandler, ResolveRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ResolveInterface, maxon::StrongRefHandler, ResolveRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ResolveRef is the reference class of ResolveInterface.
///
/// Static interface to access Url resolve functionality.
class ResolveRef : public ResolveInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ResolveRef, typename ResolveInterface::Hxx1::Reference);
	using ConstPtr = typename ResolveInterface::ConstPtr;
};

class IoConnectionRef;

struct IoConnectionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoConnectionInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IoConnectionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IoConnectionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoConnectionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for IoConnectionInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(IoConnectionInterface**);
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
/// Invokes the observer(s) with the url and open flags if writing a file failed to call open.
/// return true to continue calling handlers, false to stop.
		static inline maxon::ObservableRef<ObservableErrorOpenFileDelegate> ObservableErrorOpenFile();
	};
	/// Intermediate helper class for IoConnectionInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(IoConnectionInterface**);
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
/// Copies a file to a different location, the path must exist otherwise the function returns an error.
/// @param[in] destName						Destination name for the copy operation.
/// @param[in] overwrite					True to allow overwriting destName file if it was already there.
/// @param[in] removeReadOnly			True to remove the read only flag on the newly created copy.
/// @param[in] progress						Delegate to follow the progress of the copy operation. see @IoProgressDelegate for details.
/// @return												OK on success.
		inline Result<void> IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const;
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
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IoConnectionInterface**);
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
/// Copies a file to a different location, the path must exist otherwise the function returns an error.
/// @param[in] destName						Destination name for the copy operation.
/// @param[in] overwrite					True to allow overwriting destName file if it was already there.
/// @param[in] removeReadOnly			True to remove the read only flag on the newly created copy.
/// @param[in] progress						Delegate to follow the progress of the copy operation. see @IoProgressDelegate for details.
/// @return												OK on success.
		inline Result<void> IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress);
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
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class IoConnectionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<IoConnectionRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoConnectionInterface, maxon::StrongRefHandler, IoConnectionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoConnectionInterface, maxon::StrongRefHandler, IoConnectionRef>>>>);
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
	using ConstPtr = typename IoConnectionInterface::ConstPtr;
};

class IoConnectionInterface::ObservableErrorOpenFileDelegate : public maxon::Delegate<Bool(const Url&,OPENSTREAMFLAGS)>
{
public:
	using Super = maxon::Delegate<Bool(const Url&,OPENSTREAMFLAGS)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleErrorOpenFile);
	ObservableErrorOpenFileDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleErrorOpenFile<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleErrorOpenFile); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleErrorOpenFile<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllBoolUntilFalsePrivateHelper;
};

#endif
