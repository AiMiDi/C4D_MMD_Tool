#if 1
struct OutOfMemoryErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, OutOfMemoryErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(OutOfMemoryErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class OutOfMemoryError;

struct OutOfMemoryErrorObjectPrivateHelper;
struct OutOfMemoryErrorInterface::ReferenceClassHelper { using type = OutOfMemoryError; using object = OutOfMemoryErrorObjectPrivateHelper; };

/// Intermediate helper class for OutOfMemoryErrorInterface.
template <typename S> class OutOfMemoryErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class OutOfMemoryErrorInterface::ConstReferenceFunctionsImplDoxy : public OutOfMemoryErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for OutOfMemoryErrorInterface.
template <typename S> class OutOfMemoryErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class OutOfMemoryErrorInterface::ReferenceFunctionsImplDoxy : public OutOfMemoryErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for OutOfMemoryErrorInterface.
template <typename S> class OutOfMemoryErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() const { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class OutOfMemoryErrorInterface::COWReferenceFunctionsImplDoxy : public OutOfMemoryErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct OutOfMemoryErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class OutOfMemoryErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<OutOfMemoryError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>);
	using NonConst = NonConstRef;
};

class OutOfMemoryErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// OutOfMemoryError is the reference class of OutOfMemoryErrorInterface.
///
/// An OutOfMemoryError indicates that a memory allocation failed.
class OutOfMemoryError : public OutOfMemoryErrorInterface::Reference
{
public:
	friend class OutOfMemoryErrorObject;
	friend class maxon::ResultBase<OutOfMemoryError>;
	OutOfMemoryError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(OutOfMemoryError, Reference);
	template <typename D> OutOfMemoryError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<OutOfMemoryError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> OutOfMemoryError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<OutOfMemoryError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	OutOfMemoryError() = default;
};

MAXON_DECLARATION(OutOfMemoryError, OutOfMemoryErrorObject, "net.maxon.error.outofmemory");
struct FunctionNotImplementedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionNotImplementedErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(FunctionNotImplementedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class FunctionNotImplementedError;

struct FunctionNotImplementedErrorObjectPrivateHelper;
struct FunctionNotImplementedErrorInterface::ReferenceClassHelper { using type = FunctionNotImplementedError; using object = FunctionNotImplementedErrorObjectPrivateHelper; };

/// Intermediate helper class for FunctionNotImplementedErrorInterface.
template <typename S> class FunctionNotImplementedErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FunctionNotImplementedErrorInterface::ConstReferenceFunctionsImplDoxy : public FunctionNotImplementedErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FunctionNotImplementedErrorInterface.
template <typename S> class FunctionNotImplementedErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FunctionNotImplementedErrorInterface::ReferenceFunctionsImplDoxy : public FunctionNotImplementedErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FunctionNotImplementedErrorInterface.
template <typename S> class FunctionNotImplementedErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() const { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class FunctionNotImplementedErrorInterface::COWReferenceFunctionsImplDoxy : public FunctionNotImplementedErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FunctionNotImplementedErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class FunctionNotImplementedErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<FunctionNotImplementedError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>);
	using NonConst = NonConstRef;
};

class FunctionNotImplementedErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// FunctionNotImplementedError is the reference class of FunctionNotImplementedErrorInterface.
///
/// A FunctionNotImplementedError indicates that a function has been invoked
/// which did not contain a suitable implementation.
/// This error type creates the full call stack so that you can see where the call came from.
class FunctionNotImplementedError : public FunctionNotImplementedErrorInterface::Reference
{
public:
	friend class FunctionNotImplementedErrorObject;
	friend class maxon::ResultBase<FunctionNotImplementedError>;
	FunctionNotImplementedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FunctionNotImplementedError, Reference);
	template <typename D> FunctionNotImplementedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<FunctionNotImplementedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> FunctionNotImplementedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<FunctionNotImplementedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	FunctionNotImplementedError() = default;
};

MAXON_DECLARATION(FunctionNotImplementedError, FunctionNotImplementedErrorObject, "net.maxon.error.functionnotimplemented");
struct UnresolvedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnresolvedErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnresolvedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnresolvedError;

struct UnresolvedErrorObjectPrivateHelper;
struct UnresolvedErrorInterface::ReferenceClassHelper { using type = UnresolvedError; using object = UnresolvedErrorObjectPrivateHelper; };

/// Intermediate helper class for UnresolvedErrorInterface.
template <typename S> class UnresolvedErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnresolvedErrorInterface::ConstReferenceFunctionsImplDoxy : public UnresolvedErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnresolvedErrorInterface.
template <typename S> class UnresolvedErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnresolvedErrorInterface::ReferenceFunctionsImplDoxy : public UnresolvedErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnresolvedErrorInterface.
template <typename S> class UnresolvedErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() const { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnresolvedErrorInterface::COWReferenceFunctionsImplDoxy : public UnresolvedErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnresolvedErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnresolvedErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnresolvedError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>);
	using NonConst = NonConstRef;
};

class UnresolvedErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnresolvedError is the reference class of UnresolvedErrorInterface.
///
/// An UnresolvedError indicates that an interface or declaration was accessed for which
/// there is no definition.
class UnresolvedError : public UnresolvedErrorInterface::Reference
{
public:
	friend class UnresolvedErrorObject;
	friend class maxon::ResultBase<UnresolvedError>;
	UnresolvedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnresolvedError, Reference);
	template <typename D> UnresolvedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnresolvedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnresolvedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnresolvedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnresolvedError() = default;
};

MAXON_DECLARATION(UnresolvedError, UnresolvedErrorObject, "net.maxon.error.unresolved");
struct UnsupportedOperationErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedOperationErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnsupportedOperationErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnsupportedOperationError;

struct UnsupportedOperationErrorObjectPrivateHelper;
struct UnsupportedOperationErrorInterface::ReferenceClassHelper { using type = UnsupportedOperationError; using object = UnsupportedOperationErrorObjectPrivateHelper; };

/// Intermediate helper class for UnsupportedOperationErrorInterface.
template <typename S> class UnsupportedOperationErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedOperationErrorInterface::ConstReferenceFunctionsImplDoxy : public UnsupportedOperationErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnsupportedOperationErrorInterface.
template <typename S> class UnsupportedOperationErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedOperationErrorInterface::ReferenceFunctionsImplDoxy : public UnsupportedOperationErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnsupportedOperationErrorInterface.
template <typename S> class UnsupportedOperationErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() const { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedOperationErrorInterface::COWReferenceFunctionsImplDoxy : public UnsupportedOperationErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnsupportedOperationErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnsupportedOperationErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedOperationError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>);
	using NonConst = NonConstRef;
};

class UnsupportedOperationErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnsupportedOperationError is the reference class of UnsupportedOperationErrorInterface.
///
/// An UnsupportedOperationError indicates that the intended operation is
/// not supported by the implementation (for example, the attempt to modify a read-only dictionary).
class UnsupportedOperationError : public UnsupportedOperationErrorInterface::Reference
{
public:
	friend class UnsupportedOperationErrorObject;
	friend class maxon::ResultBase<UnsupportedOperationError>;
	UnsupportedOperationError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedOperationError, Reference);
	template <typename D> UnsupportedOperationError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedOperationError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedOperationError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedOperationError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedOperationError() = default;
};

MAXON_DECLARATION(UnsupportedOperationError, UnsupportedOperationErrorObject, "net.maxon.error.unsupportedoperation");
struct ThreadCancelledErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ThreadCancelledErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(ThreadCancelledErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class ThreadCancelledError;

struct ThreadCancelledErrorObjectPrivateHelper;
struct ThreadCancelledErrorInterface::ReferenceClassHelper { using type = ThreadCancelledError; using object = ThreadCancelledErrorObjectPrivateHelper; };

/// Intermediate helper class for ThreadCancelledErrorInterface.
template <typename S> class ThreadCancelledErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ThreadCancelledErrorInterface::ConstReferenceFunctionsImplDoxy : public ThreadCancelledErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ThreadCancelledErrorInterface.
template <typename S> class ThreadCancelledErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ThreadCancelledErrorInterface::ReferenceFunctionsImplDoxy : public ThreadCancelledErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ThreadCancelledErrorInterface.
template <typename S> class ThreadCancelledErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() const { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class ThreadCancelledErrorInterface::COWReferenceFunctionsImplDoxy : public ThreadCancelledErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct ThreadCancelledErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class ThreadCancelledErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ThreadCancelledError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>);
	using NonConst = NonConstRef;
};

class ThreadCancelledErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// ThreadCancelledError is the reference class of ThreadCancelledErrorInterface.
///
/// A ThreadCancelledError is returned if a function terminated because the thread has been stopped from outside.
class ThreadCancelledError : public ThreadCancelledErrorInterface::Reference
{
public:
	friend class ThreadCancelledErrorObject;
	friend class maxon::ResultBase<ThreadCancelledError>;
	ThreadCancelledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ThreadCancelledError, Reference);
	template <typename D> ThreadCancelledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ThreadCancelledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ThreadCancelledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ThreadCancelledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ThreadCancelledError() = default;
};

MAXON_DECLARATION(ThreadCancelledError, ThreadCancelledErrorObject, "net.maxon.error.threadcancelled");
struct IllegalArgumentErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalArgumentErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(IllegalArgumentErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class IllegalArgumentError;

struct IllegalArgumentErrorObjectPrivateHelper;
struct IllegalArgumentErrorInterface::ReferenceClassHelper { using type = IllegalArgumentError; using object = IllegalArgumentErrorObjectPrivateHelper; };

/// Intermediate helper class for IllegalArgumentErrorInterface.
template <typename S> class IllegalArgumentErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IllegalArgumentErrorInterface::ConstReferenceFunctionsImplDoxy : public IllegalArgumentErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IllegalArgumentErrorInterface.
template <typename S> class IllegalArgumentErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IllegalArgumentErrorInterface::ReferenceFunctionsImplDoxy : public IllegalArgumentErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IllegalArgumentErrorInterface.
template <typename S> class IllegalArgumentErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() const { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class IllegalArgumentErrorInterface::COWReferenceFunctionsImplDoxy : public IllegalArgumentErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct IllegalArgumentErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class IllegalArgumentErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<IllegalArgumentError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>);
	using NonConst = NonConstRef;
};

class IllegalArgumentErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// IllegalArgumentError is the reference class of IllegalArgumentErrorInterface.
///
/// An IllegalArgumentError is returned if an illegal argument was passed to a function parameter.
class IllegalArgumentError : public IllegalArgumentErrorInterface::Reference
{
public:
	friend class IllegalArgumentErrorObject;
	friend class maxon::ResultBase<IllegalArgumentError>;
	IllegalArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalArgumentError, Reference);
	template <typename D> IllegalArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalArgumentError() = default;
};

MAXON_DECLARATION(IllegalArgumentError, IllegalArgumentErrorObject, "net.maxon.error.illegalargument");
struct UnsupportedArgumentErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedArgumentErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnsupportedArgumentErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnsupportedArgumentError;

struct UnsupportedArgumentErrorObjectPrivateHelper;
struct UnsupportedArgumentErrorInterface::ReferenceClassHelper { using type = UnsupportedArgumentError; using object = UnsupportedArgumentErrorObjectPrivateHelper; };

/// Intermediate helper class for UnsupportedArgumentErrorInterface.
template <typename S> class UnsupportedArgumentErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedArgumentErrorInterface::ConstReferenceFunctionsImplDoxy : public UnsupportedArgumentErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnsupportedArgumentErrorInterface.
template <typename S> class UnsupportedArgumentErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedArgumentErrorInterface::ReferenceFunctionsImplDoxy : public UnsupportedArgumentErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnsupportedArgumentErrorInterface.
template <typename S> class UnsupportedArgumentErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() const { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnsupportedArgumentErrorInterface::COWReferenceFunctionsImplDoxy : public UnsupportedArgumentErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnsupportedArgumentErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnsupportedArgumentErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedArgumentError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>);
	using NonConst = NonConstRef;
};

class UnsupportedArgumentErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnsupportedArgumentError is the reference class of UnsupportedArgumentErrorInterface.
///
/// An UnsupportedArgumentError indicates that a generally valid argument was passed to a function parameter,
/// but the function implementation doesn't support that argument. An example is the
/// conversion of a value to a destination type where the particular combination of value
/// and destination type is not supported by the converter.
class UnsupportedArgumentError : public UnsupportedArgumentErrorInterface::Reference
{
public:
	friend class UnsupportedArgumentErrorObject;
	friend class maxon::ResultBase<UnsupportedArgumentError>;
	UnsupportedArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedArgumentError, Reference);
	template <typename D> UnsupportedArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedArgumentError() = default;
};

MAXON_DECLARATION(UnsupportedArgumentError, UnsupportedArgumentErrorObject, "net.maxon.error.unsupportedargument");
struct NullptrErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NullptrErrorInterface>::value || IllegalArgumentErrorInterface::HasBase::Check<I>::value; static I* Cast(NullptrErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class NullptrError;

struct NullptrErrorObjectPrivateHelper;
struct NullptrErrorInterface::ReferenceClassHelper { using type = NullptrError; using object = NullptrErrorObjectPrivateHelper; };

/// Intermediate helper class for NullptrErrorInterface.
template <typename S> class NullptrErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class NullptrErrorInterface::ConstReferenceFunctionsImplDoxy : public NullptrErrorInterface::ConstReferenceFunctionsImpl<REF>, public IllegalArgumentErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for NullptrErrorInterface.
template <typename S> class NullptrErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class NullptrErrorInterface::ReferenceFunctionsImplDoxy : public NullptrErrorInterface::ReferenceFunctionsImpl<REF>, public IllegalArgumentErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for NullptrErrorInterface.
template <typename S> class NullptrErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() const { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class NullptrErrorInterface::COWReferenceFunctionsImplDoxy : public NullptrErrorInterface::COWReferenceFunctionsImpl<REF>, public IllegalArgumentErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct NullptrErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename IllegalArgumentErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class NullptrErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NullptrError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>);
	using NonConst = NonConstRef;
};

class NullptrErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<NullptrErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<NullptrErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// NullptrError is the reference class of NullptrErrorInterface.
///
/// A NullptrError is returned if an (illegal) nullptr was passed to a function.
class NullptrError : public NullptrErrorInterface::Reference
{
public:
	friend class NullptrErrorObject;
	friend class maxon::ResultBase<NullptrError>;
	NullptrError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NullptrError, Reference);
	template <typename D> NullptrError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<NullptrError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> NullptrError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<NullptrError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	NullptrError() = default;
};

MAXON_DECLARATION(NullptrError, NullptrErrorObject, "net.maxon.error.nullptr");
struct IllegalStateErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalStateErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(IllegalStateErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class IllegalStateError;

struct IllegalStateErrorObjectPrivateHelper;
struct IllegalStateErrorInterface::ReferenceClassHelper { using type = IllegalStateError; using object = IllegalStateErrorObjectPrivateHelper; };

/// Intermediate helper class for IllegalStateErrorInterface.
template <typename S> class IllegalStateErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IllegalStateErrorInterface::ConstReferenceFunctionsImplDoxy : public IllegalStateErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IllegalStateErrorInterface.
template <typename S> class IllegalStateErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IllegalStateErrorInterface::ReferenceFunctionsImplDoxy : public IllegalStateErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IllegalStateErrorInterface.
template <typename S> class IllegalStateErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() const { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class IllegalStateErrorInterface::COWReferenceFunctionsImplDoxy : public IllegalStateErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct IllegalStateErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class IllegalStateErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<IllegalStateError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>);
	using NonConst = NonConstRef;
};

class IllegalStateErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// IllegalStateError is the reference class of IllegalStateErrorInterface.
///
/// An IllegalStateError indicates that a function has been invoked on an object and the object
/// hasn't been in a state which allows the proper execution of the function.
class IllegalStateError : public IllegalStateErrorInterface::Reference
{
public:
	friend class IllegalStateErrorObject;
	friend class maxon::ResultBase<IllegalStateError>;
	IllegalStateError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalStateError, Reference);
	template <typename D> IllegalStateError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalStateError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalStateError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalStateError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalStateError() = default;
};

MAXON_DECLARATION(IllegalStateError, IllegalStateErrorObject, "net.maxon.error.illegalstate");
struct UnknownErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnknownErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnknownErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnknownError;

struct UnknownErrorObjectPrivateHelper;
struct UnknownErrorInterface::ReferenceClassHelper { using type = UnknownError; using object = UnknownErrorObjectPrivateHelper; };

/// Intermediate helper class for UnknownErrorInterface.
template <typename S> class UnknownErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnknownErrorInterface::ConstReferenceFunctionsImplDoxy : public UnknownErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnknownErrorInterface.
template <typename S> class UnknownErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnknownErrorInterface::ReferenceFunctionsImplDoxy : public UnknownErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnknownErrorInterface.
template <typename S> class UnknownErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() const { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnknownErrorInterface::COWReferenceFunctionsImplDoxy : public UnknownErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnknownErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnknownErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnknownError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>);
	using NonConst = NonConstRef;
};

class UnknownErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnknownError is the reference class of UnknownErrorInterface.
///
/// An UnknownError is returned in places where no specific error was defined.
class UnknownError : public UnknownErrorInterface::Reference
{
public:
	friend class UnknownErrorObject;
	friend class maxon::ResultBase<UnknownError>;
	UnknownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnknownError, Reference);
	template <typename D> UnknownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnknownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnknownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnknownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnknownError() = default;
};

MAXON_DECLARATION(UnknownError, UnknownErrorObject, "net.maxon.error.unknown");
struct ShutdownErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ShutdownErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(ShutdownErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class ShutdownError;

struct ShutdownErrorObjectPrivateHelper;
struct ShutdownErrorInterface::ReferenceClassHelper { using type = ShutdownError; using object = ShutdownErrorObjectPrivateHelper; };

/// Intermediate helper class for ShutdownErrorInterface.
template <typename S> class ShutdownErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ShutdownErrorInterface::ConstReferenceFunctionsImplDoxy : public ShutdownErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ShutdownErrorInterface.
template <typename S> class ShutdownErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ShutdownErrorInterface::ReferenceFunctionsImplDoxy : public ShutdownErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ShutdownErrorInterface.
template <typename S> class ShutdownErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() const { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class ShutdownErrorInterface::COWReferenceFunctionsImplDoxy : public ShutdownErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct ShutdownErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class ShutdownErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ShutdownError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>);
	using NonConst = NonConstRef;
};

class ShutdownErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// ShutdownError is the reference class of ShutdownErrorInterface.
///
/// A ShutdownError is returned when errors are being used while the object system is being shut down.
class ShutdownError : public ShutdownErrorInterface::Reference
{
public:
	friend class ShutdownErrorObject;
	friend class maxon::ResultBase<ShutdownError>;
	ShutdownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ShutdownError, Reference);
	template <typename D> ShutdownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ShutdownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ShutdownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ShutdownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ShutdownError() = default;
};

MAXON_DECLARATION(ShutdownError, ShutdownErrorObject, "net.maxon.error.shutdown");
struct UnexpectedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnexpectedErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnexpectedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnexpectedError;

struct UnexpectedErrorObjectPrivateHelper;
struct UnexpectedErrorInterface::ReferenceClassHelper { using type = UnexpectedError; using object = UnexpectedErrorObjectPrivateHelper; };

/// Intermediate helper class for UnexpectedErrorInterface.
template <typename S> class UnexpectedErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnexpectedErrorInterface::ConstReferenceFunctionsImplDoxy : public UnexpectedErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnexpectedErrorInterface.
template <typename S> class UnexpectedErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnexpectedErrorInterface::ReferenceFunctionsImplDoxy : public UnexpectedErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnexpectedErrorInterface.
template <typename S> class UnexpectedErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() const { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnexpectedErrorInterface::COWReferenceFunctionsImplDoxy : public UnexpectedErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnexpectedErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnexpectedErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnexpectedError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>);
	using NonConst = NonConstRef;
};

class UnexpectedErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnexpectedError is the reference class of UnexpectedErrorInterface.
///
/// An UnexpectedError is returned when something unexpected happens within a function.
/// This typically indicates a bug in the function (or in one of the other functions which
/// are invoked by the function).
class UnexpectedError : public UnexpectedErrorInterface::Reference
{
public:
	friend class UnexpectedErrorObject;
	friend class maxon::ResultBase<UnexpectedError>;
	UnexpectedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnexpectedError, Reference);
	template <typename D> UnexpectedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnexpectedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnexpectedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnexpectedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnexpectedError() = default;
};

MAXON_DECLARATION(UnexpectedError, UnexpectedErrorObject, "net.maxon.error.unexpected");
struct ErrnoErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ErrnoErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(ErrnoErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class ErrnoError;

struct ErrnoErrorObjectPrivateHelper;
struct ErrnoErrorInterface::ReferenceClassHelper { using type = ErrnoError; using object = ErrnoErrorObjectPrivateHelper; };

/// Intermediate helper class for ErrnoErrorInterface.
template <typename S> class ErrnoErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns the errno error code stored in this error.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetErrorCode() const;
};
#ifdef DOXYGEN
template <typename REF> class ErrnoErrorInterface::ConstReferenceFunctionsImplDoxy : public ErrnoErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ErrnoErrorInterface.
template <typename S> class ErrnoErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
#ifdef DOXYGEN
template <typename REF> class ErrnoErrorInterface::ReferenceFunctionsImplDoxy : public ErrnoErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ErrnoErrorInterface.
template <typename S> class ErrnoErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
		*static_cast<typename S::DirectlyReferencedType::ReferenceClassHelper::type*>(this) = S::DirectlyReferencedType::ReferenceClassHelper::object::GetInstance()();
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
#ifdef DOXYGEN
template <typename REF> class ErrnoErrorInterface::COWReferenceFunctionsImplDoxy : public ErrnoErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct ErrnoErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class ErrnoErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ErrnoError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>);
	using NonConst = NonConstRef;
};

class ErrnoErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// ErrnoError is the reference class of ErrnoErrorInterface.
///
/// Error that contains a errno error state.
/// This error is returned if the error code contains the value of the 'errno' variable at the point when the error occurred.
/// The GetMessage functions retrieves the error text from the system using strerror().
class ErrnoError : public ErrnoErrorInterface::Reference
{
public:
	friend class ErrnoErrorObject;
	friend class maxon::ResultBase<ErrnoError>;
	ErrnoError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ErrnoError, Reference);
	template <typename D> ErrnoError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ErrnoError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ErrnoError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ErrnoError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ErrnoError() = default;
};

MAXON_DECLARATION(ErrnoError, ErrnoErrorObject, "net.maxon.error.errno");
struct UnregisteredDataTypeErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnregisteredDataTypeErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(UnregisteredDataTypeErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class UnregisteredDataTypeError;

struct UnregisteredDataTypeErrorObjectPrivateHelper;
struct UnregisteredDataTypeErrorInterface::ReferenceClassHelper { using type = UnregisteredDataTypeError; using object = UnregisteredDataTypeErrorObjectPrivateHelper; };

/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
template <typename S> class UnregisteredDataTypeErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnregisteredDataTypeErrorInterface::ConstReferenceFunctionsImplDoxy : public UnregisteredDataTypeErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
template <typename S> class UnregisteredDataTypeErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnregisteredDataTypeErrorInterface::ReferenceFunctionsImplDoxy : public UnregisteredDataTypeErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
template <typename S> class UnregisteredDataTypeErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() const { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class UnregisteredDataTypeErrorInterface::COWReferenceFunctionsImplDoxy : public UnregisteredDataTypeErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct UnregisteredDataTypeErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class UnregisteredDataTypeErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnregisteredDataTypeError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>);
	using NonConst = NonConstRef;
};

class UnregisteredDataTypeErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// UnregisteredDataTypeError is the reference class of UnregisteredDataTypeErrorInterface.
///
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
class UnregisteredDataTypeError : public UnregisteredDataTypeErrorInterface::Reference
{
public:
	friend class UnregisteredDataTypeErrorObject;
	friend class maxon::ResultBase<UnregisteredDataTypeError>;
	UnregisteredDataTypeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnregisteredDataTypeError, Reference);
	template <typename D> UnregisteredDataTypeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnregisteredDataTypeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnregisteredDataTypeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnregisteredDataTypeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnregisteredDataTypeError() = default;
};

MAXON_DECLARATION(UnregisteredDataTypeError, UnregisteredDataTypeErrorObject, "net.maxon.error.unregistereddatatype");
struct AggregatedErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, AggregatedErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(AggregatedErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class AggregatedError;

struct AggregatedErrorObjectPrivateHelper;
struct AggregatedErrorInterface::ReferenceClassHelper { using type = AggregatedError; using object = AggregatedErrorObjectPrivateHelper; };

/// Intermediate helper class for AggregatedErrorInterface.
template <typename S> class AggregatedErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
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
#ifdef DOXYGEN
template <typename REF> class AggregatedErrorInterface::ConstReferenceFunctionsImplDoxy : public AggregatedErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for AggregatedErrorInterface.
template <typename S> class AggregatedErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
#ifdef DOXYGEN
template <typename REF> class AggregatedErrorInterface::ReferenceFunctionsImplDoxy : public AggregatedErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for AggregatedErrorInterface.
template <typename S> class AggregatedErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
#ifdef DOXYGEN
template <typename REF> class AggregatedErrorInterface::COWReferenceFunctionsImplDoxy : public AggregatedErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct AggregatedErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class AggregatedErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<AggregatedError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>);
	using NonConst = NonConstRef;
};

class AggregatedErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

#ifdef MAXON_COMPILER_MSVC
#else
#endif
#endif
