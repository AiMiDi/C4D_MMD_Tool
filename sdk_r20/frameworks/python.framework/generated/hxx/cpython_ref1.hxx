#if 1
struct CPyInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(CPyInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CPyRef;

struct CPyInterface::ReferenceClassHelper { using type = CPyRef; };

/// Intermediate helper class for CPyInterface.
template <typename S> class CPyInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Creates a CPyRef reference by a given NativePyObject from a Python 2.7 virtual machine. GIL must be held. 
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyRef CreateRef27(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a CPyRef reference by a given NativePyObject from a Python 3.6 virtual machine. GIL must be held. 
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyRef CreateRef36(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a CPyRef reference by a given NativePyObject. GIL must be held. The library version is detected by using the library, is slightly slower than CreateRef27 or CreateRef36.
/// @param lib			The NativePyObject's library origin.
/// @param refType	Ref count handler information.
/// @return					Returns a new wrapper reference.
	static inline CPyRef CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a immutable CPyConstRef reference by a given NativePyObject. GIL must be held.
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyConstRef CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a temporary CPyTempRef reference by a given NativePyObject. GIL must be held.
/// @param lib			The NativePyObject's library origin.
/// @return						Returns a new wrapper reference.
	static inline CPyTempRef CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject);
/// Returns the library pointer with which the instance got initialized.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type GetLibrary() const;
/// Returns the type object of the wrapped NativePyObject. GIL must be held.
/// @return			Type reference.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type GetTypeRef() const;
/// Returns the internal NativePyObject with which the instance got initialized. No reference
/// count change is performed.
/// @return		Internal NativePyObject
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type GetPyObject() const;
/// Returns the internal NativePyObject casted to a target type. GIL must be held. No check is performed if the cast
/// is valid or not. No reference count change is performed.
/// @return		Internal NativePyObject casted.
	template <typename T = NativePyObject> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type Get() const;
};
#ifdef DOXYGEN
template <typename REF> class CPyInterface::ConstReferenceFunctionsImplDoxy : public CPyInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyInterface.
template <typename S> class CPyInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyRef, true>::type&() const { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyRef, false>::type&() { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
/// Initializes the wrapper reference. GIL must be held.
/// @param lib			The NativePyObject's library origin.
/// @param refType		Ref count handler information.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) const;
/// Increments the reference count. Instance must be already initialized. GIL must be held.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Incref() const;
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Decref() const;
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
/// @return			Reference count.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type GetRefCount() const;
/// Returns the internal NativePyObject with which the instance got initialized. Objects reference count
/// needs to be decremented if not used anymore. The wrapper reference becomes invalid, no
/// other function should be called, and it should be deleted soon as possible. GIL must be held.
/// @return		Internal NativePyObject
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type Disconnect() const;
/// Returns the internal NativePyObject casted to a target type. No check is performed if the cast
/// is valid or not. Reference count is incremented before function returns. The wrapper reference
/// stays valid. GIL must be held.
/// @return		Internal NativePyObject casted.
	template <typename T = NativePyObject> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type GetAndIncref() const;
};
#ifdef DOXYGEN
template <typename REF> class CPyInterface::ReferenceFunctionsImplDoxy : public CPyInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyInterface.
template <typename S> class CPyInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyRef, false>::type&() { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
/// Initializes the wrapper reference. GIL must be held.
/// @param lib			The NativePyObject's library origin.
/// @param refType		Ref count handler information.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Increments the reference count. Instance must be already initialized. GIL must be held.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Incref();
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Decref();
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
/// @return			Reference count.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type GetRefCount();
/// Returns the internal NativePyObject with which the instance got initialized. Objects reference count
/// needs to be decremented if not used anymore. The wrapper reference becomes invalid, no
/// other function should be called, and it should be deleted soon as possible. GIL must be held.
/// @return		Internal NativePyObject
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type Disconnect();
/// Returns the internal NativePyObject casted to a target type. No check is performed if the cast
/// is valid or not. Reference count is incremented before function returns. The wrapper reference
/// stays valid. GIL must be held.
/// @return		Internal NativePyObject casted.
	template <typename T = NativePyObject> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type GetAndIncref();
};
#ifdef DOXYGEN
template <typename REF> class CPyInterface::COWReferenceFunctionsImplDoxy : public CPyInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CPyInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class CPyInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyInterface, maxon::StrongRefHandler, CPyRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyInterface, maxon::StrongRefHandler, CPyRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct CPyTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyTypeInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(CPyTypeInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CPyTypeRef;

struct CPyTypeInterface::ReferenceClassHelper { using type = CPyTypeRef; };

/// Intermediate helper class for CPyTypeInterface.
template <typename S> class CPyTypeInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Creates a type reference by a given NativePyObject. GIL must be held.
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyTypeRef CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a immutable type reference by a given NativePyObject. GIL must be held.
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyTypeConstRef CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};
#ifdef DOXYGEN
template <typename REF> class CPyTypeInterface::ConstReferenceFunctionsImplDoxy : public CPyTypeInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyTypeInterface.
template <typename S> class CPyTypeInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTypeRef, true>::type&() const { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTypeRef, false>::type&() { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyTypeInterface::ReferenceFunctionsImplDoxy : public CPyTypeInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyTypeInterface.
template <typename S> class CPyTypeInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyTypeRef, false>::type&() { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyTypeInterface::COWReferenceFunctionsImplDoxy : public CPyTypeInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CPyTypeInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class CPyTypeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyTypeRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyTypeInterface, maxon::StrongRefHandler, CPyTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyTypeInterface, maxon::StrongRefHandler, CPyTypeRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct CPyFrameInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyFrameInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(CPyFrameInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CPyFrameRef;

struct CPyFrameInterface::ReferenceClassHelper { using type = CPyFrameRef; };

/// Intermediate helper class for CPyFrameInterface.
template <typename S> class CPyFrameInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Creates a frame reference by a given NativePyObject. GIL must be held.
/// @param lib				The NativePyObject's library origin.
/// @param refType		Ref count handler information.
/// @return						Returns a new wrapper reference.
	static inline CPyFrameRef CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type GetBack() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type GetCode() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLastInstruction() const;
};
#ifdef DOXYGEN
template <typename REF> class CPyFrameInterface::ConstReferenceFunctionsImplDoxy : public CPyFrameInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyFrameInterface.
template <typename S> class CPyFrameInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyFrameRef, true>::type&() const { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyFrameRef, false>::type&() { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyFrameInterface::ReferenceFunctionsImplDoxy : public CPyFrameInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyFrameInterface.
template <typename S> class CPyFrameInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyFrameRef, false>::type&() { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyFrameInterface::COWReferenceFunctionsImplDoxy : public CPyFrameInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CPyFrameInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class CPyFrameInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyFrameRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyFrameInterface, maxon::StrongRefHandler, CPyFrameRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyFrameInterface, maxon::StrongRefHandler, CPyFrameRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct CPyTracebackInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyTracebackInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(CPyTracebackInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CPyTracebackRef;

struct CPyTracebackInterface::ReferenceClassHelper { using type = CPyTracebackRef; };

/// Intermediate helper class for CPyTracebackInterface.
template <typename S> class CPyTracebackInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline CPyTracebackRef CreateTracebackRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTracebackRef>, CPyTracebackRef>::type GetNext() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLineNumber() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type GetFrameRef() const;
};
#ifdef DOXYGEN
template <typename REF> class CPyTracebackInterface::ConstReferenceFunctionsImplDoxy : public CPyTracebackInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyTracebackInterface.
template <typename S> class CPyTracebackInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTracebackRef, true>::type&() const { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTracebackRef, false>::type&() { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyTracebackInterface::ReferenceFunctionsImplDoxy : public CPyTracebackInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyTracebackInterface.
template <typename S> class CPyTracebackInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyTracebackRef, false>::type&() { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyTracebackInterface::COWReferenceFunctionsImplDoxy : public CPyTracebackInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CPyTracebackInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class CPyTracebackInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyTracebackRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyTracebackInterface, maxon::StrongRefHandler, CPyTracebackRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyTracebackInterface, maxon::StrongRefHandler, CPyTracebackRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct CPyCodeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyCodeInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(CPyCodeInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CPyCodeRef;

struct CPyCodeInterface::ReferenceClassHelper { using type = CPyCodeRef; };

/// Intermediate helper class for CPyCodeInterface.
template <typename S> class CPyCodeInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline CPyCodeRef CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type GetFilename() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type GetName() const;
};
#ifdef DOXYGEN
template <typename REF> class CPyCodeInterface::ConstReferenceFunctionsImplDoxy : public CPyCodeInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyCodeInterface.
template <typename S> class CPyCodeInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyCodeRef, true>::type&() const { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyCodeRef, false>::type&() { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyCodeInterface::ReferenceFunctionsImplDoxy : public CPyCodeInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CPyCodeInterface.
template <typename S> class CPyCodeInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyCodeRef, false>::type&() { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CPyCodeInterface::COWReferenceFunctionsImplDoxy : public CPyCodeInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CPyCodeInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class CPyCodeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyCodeRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyCodeInterface, maxon::StrongRefHandler, CPyCodeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CPyCodeInterface, maxon::StrongRefHandler, CPyCodeRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyClassInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyClassInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyClassRef;

struct MPyClassInterface::ReferenceClassHelper { using type = MPyClassRef; };

/// Intermediate helper class for MPyClassInterface.
template <typename S> class MPyClassInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyClassRef CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};
#ifdef DOXYGEN
template <typename REF> class MPyClassInterface::ConstReferenceFunctionsImplDoxy : public MPyClassInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyClassInterface.
template <typename S> class MPyClassInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyClassRef, true>::type&() const { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyClassRef, false>::type&() { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyClassInterface::ReferenceFunctionsImplDoxy : public MPyClassInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyClassInterface.
template <typename S> class MPyClassInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyClassRef, false>::type&() { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyClassInterface::COWReferenceFunctionsImplDoxy : public MPyClassInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyClassInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyClassInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyClassRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyClassInterface, maxon::StrongRefHandler, MPyClassRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyClassInterface, maxon::StrongRefHandler, MPyClassRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyMemberInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyMemberInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyMemberInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyMemberRef;

struct MPyMemberInterface::ReferenceClassHelper { using type = MPyMemberRef; };

/// Intermediate helper class for MPyMemberInterface.
template <typename S> class MPyMemberInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyMemberRef CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};
#ifdef DOXYGEN
template <typename REF> class MPyMemberInterface::ConstReferenceFunctionsImplDoxy : public MPyMemberInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyMemberInterface.
template <typename S> class MPyMemberInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyMemberRef, true>::type&() const { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyMemberRef, false>::type&() { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyMemberInterface::ReferenceFunctionsImplDoxy : public MPyMemberInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyMemberInterface.
template <typename S> class MPyMemberInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyMemberRef, false>::type&() { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyMemberInterface::COWReferenceFunctionsImplDoxy : public MPyMemberInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyMemberInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyMemberInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyMemberRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyMemberInterface, maxon::StrongRefHandler, MPyMemberRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyMemberInterface, maxon::StrongRefHandler, MPyMemberRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyFunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyFunctionInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyFunctionInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyFunctionRef;

struct MPyFunctionInterface::ReferenceClassHelper { using type = MPyFunctionRef; };

/// Intermediate helper class for MPyFunctionInterface.
template <typename S> class MPyFunctionInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyFunctionRef CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};
#ifdef DOXYGEN
template <typename REF> class MPyFunctionInterface::ConstReferenceFunctionsImplDoxy : public MPyFunctionInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyFunctionInterface.
template <typename S> class MPyFunctionInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyFunctionRef, true>::type&() const { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyFunctionRef, false>::type&() { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type GetFunction() const;
};
#ifdef DOXYGEN
template <typename REF> class MPyFunctionInterface::ReferenceFunctionsImplDoxy : public MPyFunctionInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyFunctionInterface.
template <typename S> class MPyFunctionInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyFunctionRef, false>::type&() { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type GetFunction();
};
#ifdef DOXYGEN
template <typename REF> class MPyFunctionInterface::COWReferenceFunctionsImplDoxy : public MPyFunctionInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyFunctionInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyFunctionInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyFunctionRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyFunctionInterface, maxon::StrongRefHandler, MPyFunctionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyFunctionInterface, maxon::StrongRefHandler, MPyFunctionRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyDataTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyDataTypeInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyDataTypeInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyDataTypeRef;

struct MPyDataTypeInterface::ReferenceClassHelper { using type = MPyDataTypeRef; };

/// Intermediate helper class for MPyDataTypeInterface.
template <typename S> class MPyDataTypeInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyDataTypeRef CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type GetType() const;
};
#ifdef DOXYGEN
template <typename REF> class MPyDataTypeInterface::ConstReferenceFunctionsImplDoxy : public MPyDataTypeInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyDataTypeInterface.
template <typename S> class MPyDataTypeInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataTypeRef, true>::type&() const { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataTypeRef, false>::type&() { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyDataTypeInterface::ReferenceFunctionsImplDoxy : public MPyDataTypeInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyDataTypeInterface.
template <typename S> class MPyDataTypeInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyDataTypeRef, false>::type&() { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyDataTypeInterface::COWReferenceFunctionsImplDoxy : public MPyDataTypeInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyDataTypeInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyDataTypeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyDataTypeRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataTypeInterface, maxon::StrongRefHandler, MPyDataTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataTypeInterface, maxon::StrongRefHandler, MPyDataTypeRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyDataInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyDataInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyDataInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyDataRef;

struct MPyDataInterface::ReferenceClassHelper { using type = MPyDataRef; };

/// Intermediate helper class for MPyDataInterface.
template <typename S> class MPyDataInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyDataRef CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type GetType() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type GetMappingType() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type GetData() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type PrivateGetPtr() const;
};
#ifdef DOXYGEN
template <typename REF> class MPyDataInterface::ConstReferenceFunctionsImplDoxy : public MPyDataInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyDataInterface.
template <typename S> class MPyDataInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataRef, true>::type&() const { return reinterpret_cast<const MPyDataRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataRef, false>::type&() { return reinterpret_cast<const MPyDataRef&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Data*>, Data*>::type GetData() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type PrivateGetPtr() const;
};
#ifdef DOXYGEN
template <typename REF> class MPyDataInterface::ReferenceFunctionsImplDoxy : public MPyDataInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyDataInterface.
template <typename S> class MPyDataInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyDataRef, false>::type&() { return reinterpret_cast<const MPyDataRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyDataInterface::COWReferenceFunctionsImplDoxy : public MPyDataInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyDataInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyDataInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyDataRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataInterface, maxon::StrongRefHandler, MPyDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataInterface, maxon::StrongRefHandler, MPyDataRef>>>>);
	using NonConst = Super::ReferenceClass;
};

struct MPyCallerContextInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyCallerContextInterface>::value || CPyInterface::HasBase::Check<I>::value; static I* Cast(MPyCallerContextInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class MPyCallerContextRef;

struct MPyCallerContextInterface::ReferenceClassHelper { using type = MPyCallerContextRef; };

/// Intermediate helper class for MPyCallerContextInterface.
template <typename S> class MPyCallerContextInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	static inline MPyCallerContextRef CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};
#ifdef DOXYGEN
template <typename REF> class MPyCallerContextInterface::ConstReferenceFunctionsImplDoxy : public MPyCallerContextInterface::ConstReferenceFunctionsImpl<REF>, public CPyInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyCallerContextInterface.
template <typename S> class MPyCallerContextInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyCallerContextRef, true>::type&() const { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyCallerContextRef, false>::type&() { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyCallerContextInterface::ReferenceFunctionsImplDoxy : public MPyCallerContextInterface::ReferenceFunctionsImpl<REF>, public CPyInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for MPyCallerContextInterface.
template <typename S> class MPyCallerContextInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyCallerContextRef, false>::type&() { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class MPyCallerContextInterface::COWReferenceFunctionsImplDoxy : public MPyCallerContextInterface::COWReferenceFunctionsImpl<REF>, public CPyInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct MPyCallerContextInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class MPyCallerContextInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyCallerContextRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyCallerContextInterface, maxon::StrongRefHandler, MPyCallerContextRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<MPyCallerContextInterface, maxon::StrongRefHandler, MPyCallerContextRef>>>>);
	using NonConst = Super::ReferenceClass;
};

#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#endif
