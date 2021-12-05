#if 1
class CPyRef;

struct CPyInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CPyInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CPyInterface::Hxx1
{
	using ReferenceClass = CPyRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CPyInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Creates a CPyRef reference by a given NativePyObject from a Python 2.7 virtual machine. GIL must be held. 
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyRef CreateRef27(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a CPyRef reference by a given NativePyObject from a Python 3.6 virtual machine. GIL must be held. 
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyRef CreateRef36(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a CPyRef reference by a given NativePyObject. GIL must be held. The library version is detected by using the library, is slightly slower than CreateRef27 or CreateRef36.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyRef CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a immutable CPyConstRef reference by a given NativePyObject. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyConstRef CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a temporary CPyTempRef reference by a given NativePyObject. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @return												Returns a new wrapper reference.
		static inline CPyTempRef CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject);
/// Returns the library pointer with which the instance got initialized.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const CPythonLibraryInterface*>, const CPythonLibraryInterface*>::type GetLibrary() const;
/// Returns the type object of the wrapped NativePyObject. GIL must be held.
/// @return												Type reference.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeRef>, CPyTypeRef>::type GetTypeRef() const;
/// Returns the internal NativePyObject with which the instance got initialized. No reference
/// count change is performed.
/// @return												Internal NativePyObject
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type GetPyObject() const;
/// Returns the internal NativePyObject cast to a target type. GIL must be held. No check is performed if the cast
/// is valid or not. No reference count change is performed.
/// @return												Internal NativePyObject casted.
		template <typename T = NativePyObject> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type Get() const;
	};
	/// Intermediate helper class for CPyInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyRef, true>::type&() const { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyRef, false>::type&() { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
/// Initializes the wrapper reference. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject) const;
/// Increments the reference count. Instance must be already initialized. GIL must be held.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Incref() const;
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Decref() const;
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
/// @return												Reference count.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type GetRefCount() const;
/// Returns the internal NativePyObject with which the instance got initialized. Objects reference count
/// needs to be decremented if not used anymore. The wrapper reference becomes invalid, no
/// other function should be called, and it should be deleted soon as possible. GIL must be held.
/// @return												Internal NativePyObject
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type Disconnect() const;
/// Returns the internal NativePyObject cast to a target type. No check is performed if the cast
/// is valid or not. Reference count is incremented before function returns. The wrapper reference
/// stays valid. GIL must be held.
/// @return												Internal NativePyObject casted.
		template <typename T = NativePyObject> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T*>, T*>::type GetAndIncref() const;
	};
	/// Intermediate helper class for CPyInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyRef, false>::type&() { return reinterpret_cast<const CPyRef&>(this->GetBaseRef()); }
/// Initializes the wrapper reference. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Increments the reference count. Instance must be already initialized. GIL must be held.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Incref();
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Decref();
/// Decrements the reference count. Instance must be already initialized. GIL must be held.
/// @return												Reference count.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type GetRefCount();
/// Returns the internal NativePyObject with which the instance got initialized. Objects reference count
/// needs to be decremented if not used anymore. The wrapper reference becomes invalid, no
/// other function should be called, and it should be deleted soon as possible. GIL must be held.
/// @return												Internal NativePyObject
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type Disconnect();
/// Returns the internal NativePyObject cast to a target type. No check is performed if the cast
/// is valid or not. Reference count is incremented before function returns. The wrapper reference
/// stays valid. GIL must be held.
/// @return												Internal NativePyObject casted.
		template <typename T = NativePyObject> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T*, maxon::Result<T*>>::type GetAndIncref();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CPyInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyInterface, maxon::StrongRefHandler, CPyRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyInterface, maxon::StrongRefHandler, CPyRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class CPyTypeRef;

struct CPyTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyTypeInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(CPyTypeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CPyTypeInterface::Hxx1
{
	using ReferenceClass = CPyTypeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for CPyTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Creates a type reference by a given NativePyObject. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyTypeRef CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
/// Creates a immutable type reference by a given NativePyObject. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyTypeConstRef CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	};
	/// Intermediate helper class for CPyTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTypeRef, true>::type&() const { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTypeRef, false>::type&() { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CPyTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyTypeRef, false>::type&() { return reinterpret_cast<const CPyTypeRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CPyTypeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyTypeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyTypeInterface, maxon::StrongRefHandler, CPyTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyTypeInterface, maxon::StrongRefHandler, CPyTypeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class CPyFrameRef;

struct CPyFrameInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyFrameInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(CPyFrameInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CPyFrameInterface::Hxx1
{
	using ReferenceClass = CPyFrameRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for CPyFrameInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Creates a frame reference by a given NativePyObject. GIL must be held.
/// @param[in] lib								The NativePyObject's library origin.
/// @param[in] refType						Ref count handler information.
/// @return												Returns a new wrapper reference.
		static inline CPyFrameRef CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyFrameRef>, CPyFrameRef>::type GetBack() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type GetCode() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLastInstruction() const;
	};
	/// Intermediate helper class for CPyFrameInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyFrameRef, true>::type&() const { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyFrameRef, false>::type&() { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CPyFrameInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyFrameRef, false>::type&() { return reinterpret_cast<const CPyFrameRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CPyFrameInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyFrameRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyFrameInterface, maxon::StrongRefHandler, CPyFrameRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyFrameInterface, maxon::StrongRefHandler, CPyFrameRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class CPyTracebackRef;

struct CPyTracebackInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyTracebackInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(CPyTracebackInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CPyTracebackInterface::Hxx1
{
	using ReferenceClass = CPyTracebackRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for CPyTracebackInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
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
	/// Intermediate helper class for CPyTracebackInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTracebackRef, true>::type&() const { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyTracebackRef, false>::type&() { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CPyTracebackInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyTracebackRef, false>::type&() { return reinterpret_cast<const CPyTracebackRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CPyTracebackInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyTracebackRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyTracebackInterface, maxon::StrongRefHandler, CPyTracebackRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyTracebackInterface, maxon::StrongRefHandler, CPyTracebackRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class CPyCodeRef;

struct CPyCodeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPyCodeInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(CPyCodeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CPyCodeInterface::Hxx1
{
	using ReferenceClass = CPyCodeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for CPyCodeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline CPyCodeRef CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type GetFilename() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type GetName() const;
	};
	/// Intermediate helper class for CPyCodeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyCodeRef, true>::type&() const { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPyCodeRef, false>::type&() { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CPyCodeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPyCodeRef, false>::type&() { return reinterpret_cast<const CPyCodeRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CPyCodeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CPyCodeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyCodeInterface, maxon::StrongRefHandler, CPyCodeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CPyCodeInterface, maxon::StrongRefHandler, CPyCodeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyClassRef;

struct MPyClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyClassInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyClassInterface::Hxx1
{
	using ReferenceClass = MPyClassRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyClassRef CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	};
	/// Intermediate helper class for MPyClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyClassRef, true>::type&() const { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyClassRef, false>::type&() { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MPyClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyClassRef, false>::type&() { return reinterpret_cast<const MPyClassRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyClassInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyClassRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyClassInterface, maxon::StrongRefHandler, MPyClassRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyClassInterface, maxon::StrongRefHandler, MPyClassRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyMemberRef;

struct MPyMemberInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyMemberInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyMemberInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyMemberInterface::Hxx1
{
	using ReferenceClass = MPyMemberRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyMemberInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyMemberRef CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	};
	/// Intermediate helper class for MPyMemberInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyMemberRef, true>::type&() const { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyMemberRef, false>::type&() { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MPyMemberInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyMemberRef, false>::type&() { return reinterpret_cast<const MPyMemberRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyMemberInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyMemberRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyMemberInterface, maxon::StrongRefHandler, MPyMemberRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyMemberInterface, maxon::StrongRefHandler, MPyMemberRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyFunctionRef;

struct MPyFunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyFunctionInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyFunctionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyFunctionInterface::Hxx1
{
	using ReferenceClass = MPyFunctionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyFunctionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyFunctionRef CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	};
	/// Intermediate helper class for MPyFunctionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyFunctionRef, true>::type&() const { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyFunctionRef, false>::type&() { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const reflection::Function*>, const reflection::Function*>::type GetFunction() const;
	};
	/// Intermediate helper class for MPyFunctionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyFunctionRef, false>::type&() { return reinterpret_cast<const MPyFunctionRef&>(this->GetBaseRef()); }
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const reflection::Function*, maxon::Result<const reflection::Function*>>::type GetFunction();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyFunctionInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyFunctionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyFunctionInterface, maxon::StrongRefHandler, MPyFunctionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyFunctionInterface, maxon::StrongRefHandler, MPyFunctionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyDataTypeRef;

struct MPyDataTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyDataTypeInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyDataTypeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyDataTypeInterface::Hxx1
{
	using ReferenceClass = MPyDataTypeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyDataTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyDataTypeRef CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetType() const;
	};
	/// Intermediate helper class for MPyDataTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataTypeRef, true>::type&() const { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyDataTypeRef, false>::type&() { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MPyDataTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyDataTypeRef, false>::type&() { return reinterpret_cast<const MPyDataTypeRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyDataTypeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyDataTypeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataTypeInterface, maxon::StrongRefHandler, MPyDataTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataTypeInterface, maxon::StrongRefHandler, MPyDataTypeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyDataRef;

struct MPyDataInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyDataInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyDataInterface::Hxx1
{
	using ReferenceClass = MPyDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyDataInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyDataRef CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetType() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetMappingType() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Data*>, const Data*>::type GetData() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type PrivateGetPtr() const;
	};
	/// Intermediate helper class for MPyDataInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
	/// Intermediate helper class for MPyDataInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyDataRef, false>::type&() { return reinterpret_cast<const MPyDataRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyDataInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyDataRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataInterface, maxon::StrongRefHandler, MPyDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyDataInterface, maxon::StrongRefHandler, MPyDataRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

class MPyCallerContextRef;

struct MPyCallerContextInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MPyCallerContextInterface>::value || CPyInterface::HasBase::template Check<I>::value; static I* Cast(MPyCallerContextInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MPyCallerContextInterface::Hxx1
{
	using ReferenceClass = MPyCallerContextRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CPyInterface>;
	/// Intermediate helper class for MPyCallerContextInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline MPyCallerContextRef CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	};
	/// Intermediate helper class for MPyCallerContextInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyCallerContextRef, true>::type&() const { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MPyCallerContextRef, false>::type&() { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MPyCallerContextInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MPyCallerContextRef, false>::type&() { return reinterpret_cast<const MPyCallerContextRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CPyInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MPyCallerContextInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MPyCallerContextRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyCallerContextInterface, maxon::StrongRefHandler, MPyCallerContextRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MPyCallerContextInterface, maxon::StrongRefHandler, MPyCallerContextRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#endif
