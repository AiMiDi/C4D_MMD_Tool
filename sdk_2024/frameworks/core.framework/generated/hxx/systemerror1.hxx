#if 1
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#ifdef __OBJC__
#else
#endif
#else
#endif
class SystemError;

struct SystemErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SystemErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(SystemErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct SystemErrorObject_PrivateHelper;
struct SystemErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = SystemErrorObject_PrivateHelper;
	using ReferenceClass = SystemError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(SystemErrorInterface**);
/// Returns the system error code stored in this error.
		inline HXXADDRET2(Int) GetErrorCode() const;
	};
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(SystemErrorInterface**);
/// Sets the system error code. This error must be returned from the Windows GetLastError().
/// The error can output the human readable string of the Windows GetLastError() error.
/// @param[in] errorCode					Error code of the system variable.
		inline HXXADDRET2(void) SetErrorCode(Int errorCode) const;
	};
	/// Intermediate helper class for SystemErrorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(SystemErrorInterface**);
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
		inline HXXADDRET1(void) SetErrorCode(Int errorCode);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class SystemErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<SystemError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const SystemErrorInterface, maxon::StrongCOWRefHandler, SystemError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const SystemErrorInterface, maxon::StrongCOWRefHandler, SystemError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class SystemErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct NSSystemErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NSSystemErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(NSSystemErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct NSSystemErrorObject_PrivateHelper;
struct NSSystemErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = NSSystemErrorObject_PrivateHelper;
	using ReferenceClass = NSSystemError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NSSystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(NSSystemErrorInterface**);
/// Returns the encapsulated NSError.
/// @return												NSError pointer.
		inline HXXADDRET2(NSError*) GetNSError() const;
	};
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NSSystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(NSSystemErrorInterface**);
/// Sets the encapsulated NSError.
/// @param[in] osError						NSError to set.
		inline HXXADDRET2(void) SetNSError(NSError* osError) const;
/// Sets the encapsulated CFError.
/// @param[in] osError						CFError to set.
		inline HXXADDRET2(void) SetCFError(CFErrorRef osError) const;
	};
	/// Intermediate helper class for NSSystemErrorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NSSystemErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(NSSystemErrorInterface**);
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
		e.SetCFError(osError);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, CFErrorRef osError, const String& message)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetCFError(osError);
		e.SetMessage(message);
	}
	
		public:
/// Sets the encapsulated NSError.
/// @param[in] osError						NSError to set.
		inline HXXADDRET1(void) SetNSError(NSError* osError);
/// Sets the encapsulated CFError.
/// @param[in] osError						CFError to set.
		inline HXXADDRET1(void) SetCFError(CFErrorRef osError);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class NSSystemErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<NSSystemError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const NSSystemErrorInterface, maxon::StrongCOWRefHandler, NSSystemError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const NSSystemErrorInterface, maxon::StrongCOWRefHandler, NSSystemError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class NSSystemErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NSSystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NSSystemErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
