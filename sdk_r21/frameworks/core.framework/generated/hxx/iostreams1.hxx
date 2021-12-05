#if 1
class IoError;

struct IoErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(IoErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IoErrorObjectPrivateHelper;
struct IoErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = IoErrorObjectPrivateHelper;
	using ReferenceClass = IoError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for IoErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the corresponding url.
/// @return												The url stored in the Error.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type GetUrl() const;
	};
	/// Intermediate helper class for IoErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// SetUrl allows to set the corresponding url.
/// @param[in] url								Url to set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetUrl(const Url& url) const;
	};
	/// Intermediate helper class for IoErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IoError, false>::type&() const { return reinterpret_cast<const IoError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IoError, false>::type&() { return reinterpret_cast<const IoError&>(this->GetBaseRef()); }

protected:
	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the location can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] url								The Url at which the error happened.
	/// @param[in] msg								Error message.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const Url& url, const String& msg, const Error& cause = GetPtrSizedZeroRef<Error>())
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetUrl(url);
		e.SetMessage(msg);
		e.SetCause(cause);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] url								The Url at which the error happened.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const Url& url, const Error& cause)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetUrl(url);
		e.SetCause(cause);
	}
	
		public:
/// SetUrl allows to set the corresponding url.
/// @param[in] url								Url to set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetUrl(const Url& url);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IoErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<IoError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IoErrorInterface, maxon::StrongCOWRefHandler, IoError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IoErrorInterface, maxon::StrongCOWRefHandler, IoError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IoErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IoError is the reference class of IoErrorInterface.
///
/// Error of the category I/O.
class IoError : public IoErrorInterface::Hxx1::Reference
{
public:
	friend class IoErrorObject;
	friend class maxon::ResultBase<IoError>;
	IoError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoError, typename IoErrorInterface::Hxx1::Reference);
	template <typename D> IoError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IoError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IoError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IoError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IoError() = default;
};

MAXON_DECLARATION(IoError, IoErrorObject, "net.maxon.error.io");
class FileFormatError;

struct FileFormatErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatErrorInterface>::value || IoErrorInterface::HasBase::template Check<I>::value; static I* Cast(FileFormatErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FileFormatErrorObjectPrivateHelper;
struct FileFormatErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = FileFormatErrorObjectPrivateHelper;
	using ReferenceClass = FileFormatError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<IoErrorInterface>;
	/// Intermediate helper class for FileFormatErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FileFormatErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FileFormatErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FileFormatError, false>::type&() const { return reinterpret_cast<const FileFormatError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FileFormatError, false>::type&() { return reinterpret_cast<const FileFormatError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename IoErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename IoErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename IoErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FileFormatErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<FileFormatError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatErrorInterface, maxon::StrongCOWRefHandler, FileFormatError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatErrorInterface, maxon::StrongCOWRefHandler, FileFormatError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FileFormatErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FileFormatError is the reference class of FileFormatErrorInterface.
///
/// An FileFormatError indicates a file format structural error.
/// It can be returned if reading a file format detects unexpected tokens or identifiers.
/// It indicates that the url that was read is corrupted.
class FileFormatError : public FileFormatErrorInterface::Hxx1::Reference
{
public:
	friend class FileFormatErrorObject;
	friend class maxon::ResultBase<FileFormatError>;
	FileFormatError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatError, typename FileFormatErrorInterface::Hxx1::Reference);
	template <typename D> FileFormatError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<FileFormatError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> FileFormatError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<FileFormatError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	FileFormatError() = default;
};

MAXON_DECLARATION(FileFormatError, FileFormatErrorObject, "net.maxon.error.fileformat");
namespace STREAMFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMFLAGS
#define PRIVATE_MAXON_GUARD_maxon_STREAMFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class UnknownFileSizeError;

struct UnknownFileSizeErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnknownFileSizeErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnknownFileSizeErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnknownFileSizeErrorObjectPrivateHelper;
struct UnknownFileSizeErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnknownFileSizeErrorObjectPrivateHelper;
	using ReferenceClass = UnknownFileSizeError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnknownFileSizeErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnknownFileSizeErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnknownFileSizeErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownFileSizeError, false>::type&() const { return reinterpret_cast<const UnknownFileSizeError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownFileSizeError, false>::type&() { return reinterpret_cast<const UnknownFileSizeError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnknownFileSizeErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnknownFileSizeError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownFileSizeErrorInterface, maxon::StrongCOWRefHandler, UnknownFileSizeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownFileSizeErrorInterface, maxon::StrongCOWRefHandler, UnknownFileSizeError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnknownFileSizeErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownFileSizeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownFileSizeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnknownFileSizeError is the reference class of UnknownFileSizeErrorInterface.
///
/// A UnknownFileSizeError indicates that the file size is unknown (not available). This might
/// happen for example when using a pipe.
class UnknownFileSizeError : public UnknownFileSizeErrorInterface::Hxx1::Reference
{
public:
	friend class UnknownFileSizeErrorObject;
	friend class maxon::ResultBase<UnknownFileSizeError>;
	UnknownFileSizeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnknownFileSizeError, typename UnknownFileSizeErrorInterface::Hxx1::Reference);
	template <typename D> UnknownFileSizeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnknownFileSizeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnknownFileSizeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnknownFileSizeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnknownFileSizeError() = default;
};

MAXON_DECLARATION(UnknownFileSizeError, UnknownFileSizeErrorObject, "net.maxon.error.unknownfilesize");
class BaseStreamRef;

struct BaseStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BaseStreamInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(BaseStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct BaseStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BaseStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for BaseStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the length of the stream/file. Be aware that some streams cannot return the file size (e.g. http streams with gzip+chunked transfer encoding).
/// With this example code you can handle both cases correctly. In most cases it's better to not use GetStreamLength() and better use ReadEOS() to read as much as available.
/// @code
/// iferr (Int size = stream.GetStreamLength())
/// {
///   if (!err.IsInstanceOf<UnknownFileSizeError>())
///     return err;
///   ... handle unknown size case ...
/// }
/// else
/// {
///   ... handle known size case ...
/// }
/// @endcode
/// @return												Returns the length in bytes. UnknownFileSizeError is returned if the size is unknown.
		inline Result<Int64> GetStreamLength() const;
/// Returns the current stream position. This is the position where the next bytes will be read to or written from.
/// @return												The current stream position.
		inline Result<Int64> GetPosition() const;
/// Returns if the stream supports Seek(). Please note that seeking in stream may effect performance because the caches will be flushed.
/// @return												True if the output stream supports Seek().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SeekSupported() const;
	};
	/// Intermediate helper class for BaseStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BaseStreamRef, true>::type&() const { return reinterpret_cast<const BaseStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BaseStreamRef, false>::type&() { return reinterpret_cast<const BaseStreamRef&>(this->GetBaseRef()); }
/// Closes the stream.
/// @return												OK on success.
		inline Result<void> Close() const;

	//----------------------------------------------------------------------------------------
	/// Resets this reference to nullptr and closes the stream if this is the last reference to the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ResetMaybeClose()
	{
		Result<void> res = OK;
		if (this->GetPointer())
		{
			if (System::GetReferenceCounter(this->GetPointer()) == 1)
				res = this->Close();
			this->ResetPointer();
		}
		return res;
	}
	
		public:
/// Sets the read/write position to this absolute position from the beginning of the stream.
/// For InputStreamInterface: If you want to Seek() forward Skip() is the preferred method to call from the performance perspective.
/// @param[in] position						Position to jump to within the stream.
/// @return												OK on success.
		inline Result<void> Seek(Int64 position) const;
/// The stream may disable buffering when this routine is called (if it supports it).
/// This method is typically used when the buffering is done from the outside.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type DisableBuffering() const;
	};
	/// Intermediate helper class for BaseStreamInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BaseStreamRef, false>::type&() { return reinterpret_cast<const BaseStreamRef&>(this->GetBaseRef()); }
/// Closes the stream.
/// @return												OK on success.
		inline Result<void> Close();
/// Sets the read/write position to this absolute position from the beginning of the stream.
/// For InputStreamInterface: If you want to Seek() forward Skip() is the preferred method to call from the performance perspective.
/// @param[in] position						Position to jump to within the stream.
/// @return												OK on success.
		inline Result<void> Seek(Int64 position);
/// The stream may disable buffering when this routine is called (if it supports it).
/// This method is typically used when the buffering is done from the outside.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type DisableBuffering();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class BaseStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<BaseStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<BaseStreamInterface, maxon::StrongRefHandler, BaseStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<BaseStreamInterface, maxon::StrongRefHandler, BaseStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// BaseStreamRef is the reference class of BaseStreamInterface.
///
/// Interface is the base interface for all stream interfaces.
/// It contains the general functions to work with streams (e.g. error handling).
class BaseStreamRef : public BaseStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BaseStreamRef, typename BaseStreamInterface::Hxx1::Reference);
};

class InputStreamRef;

struct InputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, InputStreamInterface>::value || BaseStreamInterface::HasBase::template Check<I>::value; static I* Cast(InputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct InputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = InputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<BaseStreamInterface>;
	/// Intermediate helper class for InputStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns an estimate of the number of bytes that can be read (or skipped over) from
/// this input stream without blocking by the next invocation of a method for this input stream.
/// @return												Available number of bytes to read/skip.
		inline Result<Int64> BytesAvailable() const;
	};
	/// Intermediate helper class for InputStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InputStreamRef, true>::type&() const { return reinterpret_cast<const InputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InputStreamRef, false>::type&() { return reinterpret_cast<const InputStreamRef&>(this->GetBaseRef()); }
/// Reads all bytes up to len bytes of data from the input stream into an array of bytes.
/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[out] data							Buffer which receives the read bytes.
/// @return												OK if all bytes could be read.
		inline Result<void> Read(const Block<Byte>& data) const;
/// Reads up to len bytes of data from the input stream into an array of bytes.
/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[out] data							Buffer which receives the read bytes.
/// @return												Number of bytes that has been read. If less bytes read than requested the end of the stream has been reached.
		inline Result<Int> ReadEOS(const Block<Byte>& data) const;
/// Skips over and discards n bytes of data from this input stream. If you want to Seek() forward Skip is the preferred method to call from the performance perspective.
/// @param[in] bytes							Number of bytes to skip from the current position.
/// @return												OK on success.
		inline Result<void> Skip(Int64 bytes) const;
	};
	/// Intermediate helper class for InputStreamInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, InputStreamRef, false>::type&() { return reinterpret_cast<const InputStreamRef&>(this->GetBaseRef()); }
/// Reads all bytes up to len bytes of data from the input stream into an array of bytes.
/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[out] data							Buffer which receives the read bytes.
/// @return												OK if all bytes could be read.
		inline Result<void> Read(const Block<Byte>& data);
/// Reads up to len bytes of data from the input stream into an array of bytes.
/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[out] data							Buffer which receives the read bytes.
/// @return												Number of bytes that has been read. If less bytes read than requested the end of the stream has been reached.
		inline Result<Int> ReadEOS(const Block<Byte>& data);
/// Skips over and discards n bytes of data from this input stream. If you want to Seek() forward Skip is the preferred method to call from the performance perspective.
/// @param[in] bytes							Number of bytes to skip from the current position.
/// @return												OK on success.
		inline Result<void> Skip(Int64 bytes);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class InputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<InputStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<InputStreamInterface, maxon::StrongRefHandler, InputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<InputStreamInterface, maxon::StrongRefHandler, InputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// InputStreamRef is the reference class of InputStreamInterface.
///
/// Interface for input streams. It allows to read data from streams.
/// This interface needs to be implemented for each protocol.
class InputStreamRef : public InputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(InputStreamRef, typename InputStreamInterface::Hxx1::Reference);
};

class OutputStreamRef;

struct OutputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, OutputStreamInterface>::value || BaseStreamInterface::HasBase::template Check<I>::value; static I* Cast(OutputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct OutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = OutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<BaseStreamInterface>;
	/// Intermediate helper class for OutputStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for OutputStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, OutputStreamRef, true>::type&() const { return reinterpret_cast<const OutputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, OutputStreamRef, false>::type&() { return reinterpret_cast<const OutputStreamRef&>(this->GetBaseRef()); }
/// Write bytes to the stream.
/// 'bytes' is of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[in] data								Data that should be written to the stream.
/// @return												True if all bytes are written to the stream.
		inline Result<void> Write(const Block<const Byte>& data) const;
/// Flushes the output stream and forces any buffered output bytes to be written.
/// @return												True is the operation succeeded.
		inline Result<void> Flush() const;
	};
	/// Intermediate helper class for OutputStreamInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, OutputStreamRef, false>::type&() { return reinterpret_cast<const OutputStreamRef&>(this->GetBaseRef()); }
/// Write bytes to the stream.
/// 'bytes' is of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
/// @param[in] data								Data that should be written to the stream.
/// @return												True if all bytes are written to the stream.
		inline Result<void> Write(const Block<const Byte>& data);
/// Flushes the output stream and forces any buffered output bytes to be written.
/// @return												True is the operation succeeded.
		inline Result<void> Flush();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename BaseStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class OutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<OutputStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<OutputStreamInterface, maxon::StrongRefHandler, OutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<OutputStreamInterface, maxon::StrongRefHandler, OutputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// OutputStreamRef is the reference class of OutputStreamInterface.
///
/// Creates an OutputStreamInterface class to write bytes into streams
class OutputStreamRef : public OutputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(OutputStreamRef, typename OutputStreamInterface::Hxx1::Reference);
};

class InOutputStreamRef;

struct InOutputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, InOutputStreamInterface>::value || InputStreamInterface::HasBase::template Check<I>::value || OutputStreamInterface::HasBase::template Check<I>::value; static I* Cast(InOutputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct InOutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = InOutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<InputStreamInterface, OutputStreamInterface>;
	/// Intermediate helper class for InOutputStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for InOutputStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InOutputStreamRef, true>::type&() const { return reinterpret_cast<const InOutputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InOutputStreamRef, false>::type&() { return reinterpret_cast<const InOutputStreamRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for InOutputStreamInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, InOutputStreamRef, false>::type&() { return reinterpret_cast<const InOutputStreamRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename OutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<typename InputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename OutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<typename InputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename OutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<typename InputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class InOutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<InOutputStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<InOutputStreamInterface, maxon::StrongRefHandler, InOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<InOutputStreamInterface, maxon::StrongRefHandler, InOutputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// InOutputStreamRef is the reference class of InOutputStreamInterface.
///
/// Creates an InOutputStreamInterface class to read/write bytes from/into streams.
/// This interface combines both InputStreamInterface and OutputStreamInterface.
class InOutputStreamRef : public InOutputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(InOutputStreamRef, typename InOutputStreamInterface::Hxx1::Reference);
};

#endif
