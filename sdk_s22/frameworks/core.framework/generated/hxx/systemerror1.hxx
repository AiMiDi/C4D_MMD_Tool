#if 1
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#ifdef __OBJC__
#else
#endif
#else
#endif
class SystemError;

struct SystemErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SystemErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(SystemErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct SystemErrorObjectPrivateHelper;
struct SystemErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = SystemErrorObjectPrivateHelper;
	using ReferenceClass = SystemError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the system error code stored in this error.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetErrorCode() const;
	};
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Sets the system error code. This error must be returned from the Windows GetLastError().
/// The error can output the human readable string of the Windows GetLastError() error.
/// @param[in] errorCode					Error code of the system variable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetErrorCode(Int errorCode) const;
	};
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemError, false>::type&() const { return reinterpret_cast<const SystemError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemError, false>::type&() { return reinterpret_cast<const SystemError&>(this->GetBaseRef()); }

protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, Int errorCode)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetErrorCode(errorCode);
	}
	
		public:
/// Sets the system error code. This error must be returned from the Windows GetLastError().
/// The error can output the human readable string of the Windows GetLastError() error.
/// @param[in] errorCode					Error code of the system variable.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetErrorCode(Int errorCode);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class SystemErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<SystemError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemErrorInterface, maxon::StrongCOWRefHandler, SystemError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemErrorInterface, maxon::StrongCOWRefHandler, SystemError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class SystemErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// SystemError is the reference class of SystemErrorInterface.
///
/// System dependent error (Win only).
/// This error is returned if the error code contains the value of GetLastError() at the point when the error occured.
/// The GetMessage functions retrieves the error text from the windows system using FormatMessage.
class SystemError : public SystemErrorInterface::Hxx1::Reference
{
public:
	friend class SystemErrorObject;
	friend class maxon::ResultBase<SystemError>;
	SystemError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SystemError, typename SystemErrorInterface::Hxx1::Reference);
	template <typename D> SystemError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<SystemError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> SystemError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<SystemError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	SystemError() = default;
};

MAXON_DECLARATION(SystemError, SystemErrorObject, "net.maxon.error.system");
class NSSystemError;

struct NSSystemErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NSSystemErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(NSSystemErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct NSSystemErrorObjectPrivateHelper;
struct NSSystemErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = NSSystemErrorObjectPrivateHelper;
	using ReferenceClass = NSSystemError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the encapsulated NSError.
/// @return												NSError pointer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<NSError*>, NSError*>::type GetNSError() const;
	};
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Sets the encapsulated NSError.
/// @param[in] osError						NSError to set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetNSError(NSError* osError) const;
	};
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NSSystemError, false>::type&() const { return reinterpret_cast<const NSSystemError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NSSystemError, false>::type&() { return reinterpret_cast<const NSSystemError&>(this->GetBaseRef()); }

protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, NSError* osError)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError(osError);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, NSError* osError, const String& message)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError(osError);
		e.SetMessage(message);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, CFErrorRef osError)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError((NSError*) osError);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, CFErrorRef osError, const String& message)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError((NSError*) osError);
		e.SetMessage(message);
	}
	
		public:
/// Sets the encapsulated NSError.
/// @param[in] osError						NSError to set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetNSError(NSError* osError);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class NSSystemErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NSSystemError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const NSSystemErrorInterface, maxon::StrongCOWRefHandler, NSSystemError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const NSSystemErrorInterface, maxon::StrongCOWRefHandler, NSSystemError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class NSSystemErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NSSystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NSSystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// NSSystemError is the reference class of NSSystemErrorInterface.
///
/// System dependent error (macOS and iOS only).
/// This error is returned if the OS returned an NSError.
class NSSystemError : public NSSystemErrorInterface::Hxx1::Reference
{
public:
	friend class NSSystemErrorObject;
	friend class maxon::ResultBase<NSSystemError>;
	NSSystemError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NSSystemError, typename NSSystemErrorInterface::Hxx1::Reference);
	template <typename D> NSSystemError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<NSSystemError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> NSSystemError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<NSSystemError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	NSSystemError() = default;
};

MAXON_DECLARATION(NSSystemError, NSSystemErrorObject, "net.maxon.error.nsystem");
#endif
