#if 1
class OutOfMemoryError;

struct OutOfMemoryErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, OutOfMemoryErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(OutOfMemoryErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct OutOfMemoryErrorObjectPrivateHelper;
struct OutOfMemoryErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = OutOfMemoryErrorObjectPrivateHelper;
	using ReferenceClass = OutOfMemoryError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for OutOfMemoryErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for OutOfMemoryErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for OutOfMemoryErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() const { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class OutOfMemoryErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<OutOfMemoryError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class OutOfMemoryErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// OutOfMemoryError is the reference class of OutOfMemoryErrorInterface.
///
/// An OutOfMemoryError indicates that a memory allocation failed.
class OutOfMemoryError : public OutOfMemoryErrorInterface::Hxx1::Reference
{
public:
	friend class OutOfMemoryErrorObject;
	friend class maxon::ResultBase<OutOfMemoryError>;
	OutOfMemoryError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(OutOfMemoryError, typename OutOfMemoryErrorInterface::Hxx1::Reference);
	template <typename D> OutOfMemoryError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<OutOfMemoryError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> OutOfMemoryError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<OutOfMemoryError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	OutOfMemoryError() = default;
};

MAXON_DECLARATION(OutOfMemoryError, OutOfMemoryErrorObject, "net.maxon.error.outofmemory");
class FunctionNotImplementedError;

struct FunctionNotImplementedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionNotImplementedErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(FunctionNotImplementedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FunctionNotImplementedErrorObjectPrivateHelper;
struct FunctionNotImplementedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = FunctionNotImplementedErrorObjectPrivateHelper;
	using ReferenceClass = FunctionNotImplementedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for FunctionNotImplementedErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FunctionNotImplementedErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FunctionNotImplementedErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() const { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FunctionNotImplementedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<FunctionNotImplementedError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FunctionNotImplementedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FunctionNotImplementedError is the reference class of FunctionNotImplementedErrorInterface.
///
/// A FunctionNotImplementedError indicates that a function has been invoked
/// which did not contain a suitable implementation.
/// This error type creates the full call stack so that you can see where the call came from.
class FunctionNotImplementedError : public FunctionNotImplementedErrorInterface::Hxx1::Reference
{
public:
	friend class FunctionNotImplementedErrorObject;
	friend class maxon::ResultBase<FunctionNotImplementedError>;
	FunctionNotImplementedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FunctionNotImplementedError, typename FunctionNotImplementedErrorInterface::Hxx1::Reference);
	template <typename D> FunctionNotImplementedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<FunctionNotImplementedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> FunctionNotImplementedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<FunctionNotImplementedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	FunctionNotImplementedError() = default;
};

MAXON_DECLARATION(FunctionNotImplementedError, FunctionNotImplementedErrorObject, "net.maxon.error.functionnotimplemented");
class UnresolvedError;

struct UnresolvedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnresolvedErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnresolvedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnresolvedErrorObjectPrivateHelper;
struct UnresolvedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnresolvedErrorObjectPrivateHelper;
	using ReferenceClass = UnresolvedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnresolvedErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnresolvedErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnresolvedErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() const { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnresolvedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnresolvedError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnresolvedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnresolvedError is the reference class of UnresolvedErrorInterface.
///
/// An UnresolvedError indicates that an interface or declaration was accessed for which
/// there is no definition.
class UnresolvedError : public UnresolvedErrorInterface::Hxx1::Reference
{
public:
	friend class UnresolvedErrorObject;
	friend class maxon::ResultBase<UnresolvedError>;
	UnresolvedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnresolvedError, typename UnresolvedErrorInterface::Hxx1::Reference);
	template <typename D> UnresolvedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnresolvedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnresolvedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnresolvedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnresolvedError() = default;
};

MAXON_DECLARATION(UnresolvedError, UnresolvedErrorObject, "net.maxon.error.unresolved");
class UnsupportedOperationError;

struct UnsupportedOperationErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedOperationErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnsupportedOperationErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnsupportedOperationErrorObjectPrivateHelper;
struct UnsupportedOperationErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnsupportedOperationErrorObjectPrivateHelper;
	using ReferenceClass = UnsupportedOperationError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnsupportedOperationErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnsupportedOperationErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnsupportedOperationErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() const { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnsupportedOperationErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedOperationError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnsupportedOperationErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnsupportedOperationError is the reference class of UnsupportedOperationErrorInterface.
///
/// An UnsupportedOperationError indicates that the intended operation is
/// not supported by the implementation (for example, the attempt to modify a read-only dictionary).
class UnsupportedOperationError : public UnsupportedOperationErrorInterface::Hxx1::Reference
{
public:
	friend class UnsupportedOperationErrorObject;
	friend class maxon::ResultBase<UnsupportedOperationError>;
	UnsupportedOperationError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedOperationError, typename UnsupportedOperationErrorInterface::Hxx1::Reference);
	template <typename D> UnsupportedOperationError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedOperationError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedOperationError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedOperationError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedOperationError() = default;
};

MAXON_DECLARATION(UnsupportedOperationError, UnsupportedOperationErrorObject, "net.maxon.error.unsupportedoperation");
class ThreadCancelledError;

struct ThreadCancelledErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ThreadCancelledErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(ThreadCancelledErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ThreadCancelledErrorObjectPrivateHelper;
struct ThreadCancelledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ThreadCancelledErrorObjectPrivateHelper;
	using ReferenceClass = ThreadCancelledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() const { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ThreadCancelledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ThreadCancelledError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ThreadCancelledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ThreadCancelledError is the reference class of ThreadCancelledErrorInterface.
///
/// A ThreadCancelledError is returned if a function terminated because the thread has been stopped from outside.
class ThreadCancelledError : public ThreadCancelledErrorInterface::Hxx1::Reference
{
public:
	friend class ThreadCancelledErrorObject;
	friend class maxon::ResultBase<ThreadCancelledError>;
	ThreadCancelledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ThreadCancelledError, typename ThreadCancelledErrorInterface::Hxx1::Reference);
	template <typename D> ThreadCancelledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ThreadCancelledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ThreadCancelledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ThreadCancelledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ThreadCancelledError() = default;
};

MAXON_DECLARATION(ThreadCancelledError, ThreadCancelledErrorObject, "net.maxon.error.threadcancelled");
class IllegalArgumentError;

struct IllegalArgumentErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalArgumentErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(IllegalArgumentErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IllegalArgumentErrorObjectPrivateHelper;
struct IllegalArgumentErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = IllegalArgumentErrorObjectPrivateHelper;
	using ReferenceClass = IllegalArgumentError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for IllegalArgumentErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for IllegalArgumentErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for IllegalArgumentErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() const { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IllegalArgumentErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<IllegalArgumentError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IllegalArgumentErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IllegalArgumentError is the reference class of IllegalArgumentErrorInterface.
///
/// An IllegalArgumentError is returned if an illegal argument was passed to a function parameter.
class IllegalArgumentError : public IllegalArgumentErrorInterface::Hxx1::Reference
{
public:
	friend class IllegalArgumentErrorObject;
	friend class maxon::ResultBase<IllegalArgumentError>;
	IllegalArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalArgumentError, typename IllegalArgumentErrorInterface::Hxx1::Reference);
	template <typename D> IllegalArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalArgumentError() = default;
};

MAXON_DECLARATION(IllegalArgumentError, IllegalArgumentErrorObject, "net.maxon.error.illegalargument");
class UnsupportedArgumentError;

struct UnsupportedArgumentErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedArgumentErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnsupportedArgumentErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnsupportedArgumentErrorObjectPrivateHelper;
struct UnsupportedArgumentErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnsupportedArgumentErrorObjectPrivateHelper;
	using ReferenceClass = UnsupportedArgumentError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnsupportedArgumentErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnsupportedArgumentErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnsupportedArgumentErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() const { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnsupportedArgumentErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedArgumentError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnsupportedArgumentErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnsupportedArgumentError is the reference class of UnsupportedArgumentErrorInterface.
///
/// An UnsupportedArgumentError indicates that a generally valid argument was passed to a function parameter,
/// but the function implementation doesn't support that argument. An example is the
/// conversion of a value to a destination type where the particular combination of value
/// and destination type is not supported by the converter.
class UnsupportedArgumentError : public UnsupportedArgumentErrorInterface::Hxx1::Reference
{
public:
	friend class UnsupportedArgumentErrorObject;
	friend class maxon::ResultBase<UnsupportedArgumentError>;
	UnsupportedArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedArgumentError, typename UnsupportedArgumentErrorInterface::Hxx1::Reference);
	template <typename D> UnsupportedArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedArgumentError() = default;
};

MAXON_DECLARATION(UnsupportedArgumentError, UnsupportedArgumentErrorObject, "net.maxon.error.unsupportedargument");
class NullptrError;

struct NullptrErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NullptrErrorInterface>::value || IllegalArgumentErrorInterface::HasBase::template Check<I>::value; static I* Cast(NullptrErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct NullptrErrorObjectPrivateHelper;
struct NullptrErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = NullptrErrorObjectPrivateHelper;
	using ReferenceClass = NullptrError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<IllegalArgumentErrorInterface>;
	/// Intermediate helper class for NullptrErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for NullptrErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for NullptrErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() const { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class NullptrErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NullptrError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class NullptrErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NullptrErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NullptrErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// NullptrError is the reference class of NullptrErrorInterface.
///
/// A NullptrError is returned if an (illegal) nullptr was passed to a function.
class NullptrError : public NullptrErrorInterface::Hxx1::Reference
{
public:
	friend class NullptrErrorObject;
	friend class maxon::ResultBase<NullptrError>;
	NullptrError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NullptrError, typename NullptrErrorInterface::Hxx1::Reference);
	template <typename D> NullptrError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<NullptrError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> NullptrError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<NullptrError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	NullptrError() = default;
};

MAXON_DECLARATION(NullptrError, NullptrErrorObject, "net.maxon.error.nullptr");
class IllegalStateError;

struct IllegalStateErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalStateErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(IllegalStateErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IllegalStateErrorObjectPrivateHelper;
struct IllegalStateErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = IllegalStateErrorObjectPrivateHelper;
	using ReferenceClass = IllegalStateError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for IllegalStateErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for IllegalStateErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for IllegalStateErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() const { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IllegalStateErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<IllegalStateError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IllegalStateErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IllegalStateError is the reference class of IllegalStateErrorInterface.
///
/// An IllegalStateError indicates that a function has been invoked on an object and the object
/// hasn't been in a state which allows the proper execution of the function.
class IllegalStateError : public IllegalStateErrorInterface::Hxx1::Reference
{
public:
	friend class IllegalStateErrorObject;
	friend class maxon::ResultBase<IllegalStateError>;
	IllegalStateError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalStateError, typename IllegalStateErrorInterface::Hxx1::Reference);
	template <typename D> IllegalStateError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalStateError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalStateError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalStateError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalStateError() = default;
};

MAXON_DECLARATION(IllegalStateError, IllegalStateErrorObject, "net.maxon.error.illegalstate");
class UnknownError;

struct UnknownErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnknownErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnknownErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnknownErrorObjectPrivateHelper;
struct UnknownErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnknownErrorObjectPrivateHelper;
	using ReferenceClass = UnknownError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnknownErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnknownErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnknownErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() const { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnknownErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnknownError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnknownErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnknownError is the reference class of UnknownErrorInterface.
///
/// An UnknownError is returned in places where no specific error was defined.
class UnknownError : public UnknownErrorInterface::Hxx1::Reference
{
public:
	friend class UnknownErrorObject;
	friend class maxon::ResultBase<UnknownError>;
	UnknownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnknownError, typename UnknownErrorInterface::Hxx1::Reference);
	template <typename D> UnknownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnknownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnknownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnknownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnknownError() = default;
};

MAXON_DECLARATION(UnknownError, UnknownErrorObject, "net.maxon.error.unknown");
class ShutdownError;

struct ShutdownErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ShutdownErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(ShutdownErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ShutdownErrorObjectPrivateHelper;
struct ShutdownErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ShutdownErrorObjectPrivateHelper;
	using ReferenceClass = ShutdownError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ShutdownErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ShutdownErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ShutdownErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() const { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ShutdownErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ShutdownError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ShutdownErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ShutdownError is the reference class of ShutdownErrorInterface.
///
/// A ShutdownError is returned when errors are being used while the object system is being shut down.
class ShutdownError : public ShutdownErrorInterface::Hxx1::Reference
{
public:
	friend class ShutdownErrorObject;
	friend class maxon::ResultBase<ShutdownError>;
	ShutdownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ShutdownError, typename ShutdownErrorInterface::Hxx1::Reference);
	template <typename D> ShutdownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ShutdownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ShutdownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ShutdownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ShutdownError() = default;
};

MAXON_DECLARATION(ShutdownError, ShutdownErrorObject, "net.maxon.error.shutdown");
class UnexpectedError;

struct UnexpectedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnexpectedErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnexpectedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnexpectedErrorObjectPrivateHelper;
struct UnexpectedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnexpectedErrorObjectPrivateHelper;
	using ReferenceClass = UnexpectedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnexpectedErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnexpectedErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnexpectedErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() const { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnexpectedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnexpectedError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnexpectedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnexpectedError is the reference class of UnexpectedErrorInterface.
///
/// An UnexpectedError is returned when something unexpected happens within a function.
/// This typically indicates a bug in the function (or in one of the other functions which
/// are invoked by the function).
class UnexpectedError : public UnexpectedErrorInterface::Hxx1::Reference
{
public:
	friend class UnexpectedErrorObject;
	friend class maxon::ResultBase<UnexpectedError>;
	UnexpectedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnexpectedError, typename UnexpectedErrorInterface::Hxx1::Reference);
	template <typename D> UnexpectedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnexpectedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnexpectedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnexpectedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnexpectedError() = default;
};

MAXON_DECLARATION(UnexpectedError, UnexpectedErrorObject, "net.maxon.error.unexpected");
class DisabledError;

struct DisabledErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DisabledErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(DisabledErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DisabledErrorObjectPrivateHelper;
struct DisabledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = DisabledErrorObjectPrivateHelper;
	using ReferenceClass = DisabledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for DisabledErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DisabledErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DisabledErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DisabledError, false>::type&() const { return reinterpret_cast<const DisabledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DisabledError, false>::type&() { return reinterpret_cast<const DisabledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DisabledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<DisabledError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DisabledErrorInterface, maxon::StrongCOWRefHandler, DisabledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DisabledErrorInterface, maxon::StrongCOWRefHandler, DisabledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DisabledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DisabledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DisabledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DisabledError is the reference class of DisabledErrorInterface.
///
/// A DisabledError is returned by a registration function to tell that the registration is disabled.
/// The system won't show a warning message for such an error.
class DisabledError : public DisabledErrorInterface::Hxx1::Reference
{
public:
	friend class DisabledErrorObject;
	friend class maxon::ResultBase<DisabledError>;
	DisabledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DisabledError, typename DisabledErrorInterface::Hxx1::Reference);
	template <typename D> DisabledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<DisabledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> DisabledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<DisabledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	DisabledError() = default;
};

MAXON_DECLARATION(DisabledError, DisabledErrorObject, "net.maxon.error.disabled");
class ErrnoError;

struct ErrnoErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ErrnoErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(ErrnoErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ErrnoErrorObjectPrivateHelper;
struct ErrnoErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ErrnoErrorObjectPrivateHelper;
	using ReferenceClass = ErrnoError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the errno error code stored in this error.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetErrorCode() const;
	};
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Sets the errno error code. This error must be returned from the errno system variable.
/// The error can output the human readable string of the errno error.
/// @param[in] errorCode					Error code of errno system variable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetErrorCode(Int errorCode) const;
	};
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ErrnoError, false>::type&() const { return reinterpret_cast<const ErrnoError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ErrnoError, false>::type&() { return reinterpret_cast<const ErrnoError&>(this->GetBaseRef()); }

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
/// Sets the errno error code. This error must be returned from the errno system variable.
/// The error can output the human readable string of the errno error.
/// @param[in] errorCode					Error code of errno system variable.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetErrorCode(Int errorCode);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ErrnoErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ErrnoError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ErrnoErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ErrnoError is the reference class of ErrnoErrorInterface.
///
/// Error that contains a errno error state.
/// This error is returned if the error code contains the value of the 'errno' variable at the point when the error occurred.
/// The GetMessage functions retrieves the error text from the system using strerror().
class ErrnoError : public ErrnoErrorInterface::Hxx1::Reference
{
public:
	friend class ErrnoErrorObject;
	friend class maxon::ResultBase<ErrnoError>;
	ErrnoError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ErrnoError, typename ErrnoErrorInterface::Hxx1::Reference);
	template <typename D> ErrnoError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ErrnoError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ErrnoError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ErrnoError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ErrnoError() = default;
};

MAXON_DECLARATION(ErrnoError, ErrnoErrorObject, "net.maxon.error.errno");
class UnregisteredDataTypeError;

struct UnregisteredDataTypeErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnregisteredDataTypeErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnregisteredDataTypeErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnregisteredDataTypeErrorObjectPrivateHelper;
struct UnregisteredDataTypeErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnregisteredDataTypeErrorObjectPrivateHelper;
	using ReferenceClass = UnregisteredDataTypeError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() const { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnregisteredDataTypeErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnregisteredDataTypeError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnregisteredDataTypeErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnregisteredDataTypeError is the reference class of UnregisteredDataTypeErrorInterface.
///
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
class UnregisteredDataTypeError : public UnregisteredDataTypeErrorInterface::Hxx1::Reference
{
public:
	friend class UnregisteredDataTypeErrorObject;
	friend class maxon::ResultBase<UnregisteredDataTypeError>;
	UnregisteredDataTypeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnregisteredDataTypeError, typename UnregisteredDataTypeErrorInterface::Hxx1::Reference);
	template <typename D> UnregisteredDataTypeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnregisteredDataTypeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnregisteredDataTypeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnregisteredDataTypeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnregisteredDataTypeError() = default;
};

MAXON_DECLARATION(UnregisteredDataTypeError, UnregisteredDataTypeErrorObject, "net.maxon.error.unregistereddatatype");
class AggregatedError;

struct AggregatedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, AggregatedErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(AggregatedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct AggregatedErrorObjectPrivateHelper;
struct AggregatedErrorInterface::Hxx1
{
	class NonConstRef;
	using ErrObj = AggregatedErrorObjectPrivateHelper;
	using ReferenceClass = AggregatedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the number of errors in this AggregatedError.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCount() const;
/// Returns the error at the given index.
/// @param[in] index							Index of the error. Index must be >= 0 and < GetCount().
/// @return												Error stored at this index.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type GetError(Int index) const;
	};
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type AddError(const Error& error) const;
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type AddError(Error&& error) const;
	};
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, AggregatedError, false>::type&() const { return reinterpret_cast<const AggregatedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, AggregatedError, false>::type&() { return reinterpret_cast<const AggregatedError&>(this->GetBaseRef()); }
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type AddError(const Error& error);
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type AddError(Error&& error);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class AggregatedErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<AggregatedError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class AggregatedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#endif
