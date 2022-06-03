#if 1
namespace py
{
#ifdef MAXON_TARGET_WINDOWS
#endif
	class PythonError;

	struct PythonErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PythonErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PythonErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
	struct PythonErrorObjectPrivateHelper;
	struct PythonErrorInterface::Hxx1
	{
		class Reference;
		class NonConstRef;
		using ErrObj = PythonErrorObjectPrivateHelper;
		using ReferenceClass = PythonError;
		template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
		/// Intermediate helper class for PythonErrorInterface.
		template <typename S> class COWFn : public S
		{
		public:
			COWFn() = default;
			using PrivateBaseClass = S;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static COWFn PrivateLookupFn(PythonErrorInterface**);
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonError, false>::type&() const { return reinterpret_cast<const PythonError&>(this->GetBaseRef()); }
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonError, false>::type&() { return reinterpret_cast<const PythonError&>(this->GetBaseRef()); }
		};
		template <typename ST> struct FnHelper : public std::conditional<
		maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
		COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
		typename ErrorInterface::Hxx1::template FnHelper<ST>::type
		> { };
	};
	class PythonErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
	public COWFnDoxy<PythonError>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonErrorInterface, maxon::StrongCOWRefHandler, PythonError>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonErrorInterface, maxon::StrongCOWRefHandler, PythonError>>>>);
		using NonConst = Hxx1::NonConstRef;
	};

	class PythonErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
	public FnDoxy<NonConstRef>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
	};

	/// PythonError is the reference class of PythonErrorInterface.
	///
/// A PythonError indicates that the last Python call failed. If the error has a cause,
/// it is an AggregatedError, which is a collection of PythonTracebackErrors.
/// If a function returns this error, the exception indicator in Python and remains until
/// it is manually cleared or if a function explicitly describes the meaning of this error differently.
	class PythonError : public PythonErrorInterface::Hxx1::Reference
	{
	public:
	friend class PythonErrorObject;
	friend class maxon::ResultBase<PythonError>;
	PythonError(maxon::ERROR_OK) { }
		PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PythonError, typename PythonErrorInterface::Hxx1::Reference);
		template <typename D> PythonError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<PythonError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
		template <typename ARG1, typename... ARGS> PythonError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<PythonError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
	private:
		PythonError() = default;
	};

	MAXON_DECLARATION(PythonError, PythonErrorObject, "net.maxon.python.error.python");
	class PythonTracebackError;

	struct PythonTracebackErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PythonTracebackErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PythonTracebackErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
	struct PythonTracebackErrorObjectPrivateHelper;
	struct PythonTracebackErrorInterface::Hxx1
	{
		class Reference;
		class NonConstRef;
		using ErrObj = PythonTracebackErrorObjectPrivateHelper;
		using ReferenceClass = PythonTracebackError;
		template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
		/// Intermediate helper class for PythonTracebackErrorInterface.
		template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
		{
		public:
			ConstFn() = default;
			using PrivateBaseClass = S;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static ConstFn PrivateLookupFn(PythonTracebackErrorInterface**);
/// Returns the path of the traceback entry.
/// @return												Path.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type GetUrl() const;
/// Returns line of the traceback entry.
/// @return												Line number..
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLineNumber() const;
		};
		/// Intermediate helper class for PythonTracebackErrorInterface.
		template <typename S> class Fn : public ConstFn<S>
		{
		public:
			Fn() = default;
			using PrivateBaseClass = ConstFn<S>;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static Fn PrivateLookupFn(PythonTracebackErrorInterface**);
/// Sets the url of the traceback entry.
/// @param[in] url								Path.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetUrl(const Url& url) const;
/// Sets the line of the traceback entry.
/// @param[in] line								Line number.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetLineNumber(Int line) const;
		};
		/// Intermediate helper class for PythonTracebackErrorInterface.
		template <typename S> class COWFn : public ConstFn<S>
		{
		public:
			COWFn() = default;
			using PrivateBaseClass = ConstFn<S>;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static COWFn PrivateLookupFn(PythonTracebackErrorInterface**);
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonTracebackError, false>::type&() const { return reinterpret_cast<const PythonTracebackError&>(this->GetBaseRef()); }
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonTracebackError, false>::type&() { return reinterpret_cast<const PythonTracebackError&>(this->GetBaseRef()); }
/// Sets the url of the traceback entry.
/// @param[in] url								Path.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetUrl(const Url& url);
/// Sets the line of the traceback entry.
/// @param[in] line								Line number.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetLineNumber(Int line);
		};
		template <typename ST> struct FnHelper : public std::conditional<
		maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
		COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
		typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>>::type
		> { };
	};
	class PythonTracebackErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
	public COWFnDoxy<PythonTracebackError>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonTracebackErrorInterface, maxon::StrongCOWRefHandler, PythonTracebackError>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonTracebackErrorInterface, maxon::StrongCOWRefHandler, PythonTracebackError>>>>);
		using NonConst = Hxx1::NonConstRef;
	};

	class PythonTracebackErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
	public FnDoxy<NonConstRef>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonTracebackErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonTracebackErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
	};

	/// PythonTracebackError is the reference class of PythonTracebackErrorInterface.
	///
/// A PythonTracebackError is always part of an AgrregatedError which is further the cause in a PythonError. This error is never a top-level error.
/// Contains information about the traceback if an exception.
	class PythonTracebackError : public PythonTracebackErrorInterface::Hxx1::Reference
	{
	public:
	friend class PythonTracebackErrorObject;
	friend class maxon::ResultBase<PythonTracebackError>;
	PythonTracebackError(maxon::ERROR_OK) { }
		PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PythonTracebackError, typename PythonTracebackErrorInterface::Hxx1::Reference);
		template <typename D> PythonTracebackError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<PythonTracebackError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
		template <typename ARG1, typename... ARGS> PythonTracebackError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<PythonTracebackError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
	private:
		PythonTracebackError() = default;
	};

	MAXON_DECLARATION(PythonTracebackError, PythonTracebackErrorObject, "net.maxon.python.error.pythontraceback");
	class PythonSystemExitError;

	struct PythonSystemExitErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PythonSystemExitErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PythonSystemExitErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
	struct PythonSystemExitErrorObjectPrivateHelper;
	struct PythonSystemExitErrorInterface::Hxx1
	{
		class Reference;
		class NonConstRef;
		using ErrObj = PythonSystemExitErrorObjectPrivateHelper;
		using ReferenceClass = PythonSystemExitError;
		template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
		/// Intermediate helper class for PythonSystemExitErrorInterface.
		template <typename S> class COWFn : public S
		{
		public:
			COWFn() = default;
			using PrivateBaseClass = S;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static COWFn PrivateLookupFn(PythonSystemExitErrorInterface**);
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonSystemExitError, false>::type&() const { return reinterpret_cast<const PythonSystemExitError&>(this->GetBaseRef()); }
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PythonSystemExitError, false>::type&() { return reinterpret_cast<const PythonSystemExitError&>(this->GetBaseRef()); }
		};
		template <typename ST> struct FnHelper : public std::conditional<
		maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
		COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
		typename ErrorInterface::Hxx1::template FnHelper<ST>::type
		> { };
	};
	class PythonSystemExitErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
	public COWFnDoxy<PythonSystemExitError>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonSystemExitErrorInterface, maxon::StrongCOWRefHandler, PythonSystemExitError>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PythonSystemExitErrorInterface, maxon::StrongCOWRefHandler, PythonSystemExitError>>>>);
		using NonConst = Hxx1::NonConstRef;
	};

	class PythonSystemExitErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
	public FnDoxy<NonConstRef>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonSystemExitErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PythonSystemExitErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
	};

	/// PythonSystemExitError is the reference class of PythonSystemExitErrorInterface.
	///
/// A PythonSystemExitError is thrown if the previous function executed sys.exit. Only thrown in VirtualMachineInterface::Execute(String)
	class PythonSystemExitError : public PythonSystemExitErrorInterface::Hxx1::Reference
	{
	public:
	friend class PythonSystemExitErrorObject;
	friend class maxon::ResultBase<PythonSystemExitError>;
	PythonSystemExitError(maxon::ERROR_OK) { }
		PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PythonSystemExitError, typename PythonSystemExitErrorInterface::Hxx1::Reference);
		template <typename D> PythonSystemExitError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<PythonSystemExitError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
		template <typename ARG1, typename... ARGS> PythonSystemExitError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<PythonSystemExitError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
	private:
		PythonSystemExitError() = default;
	};

	MAXON_DECLARATION(PythonSystemExitError, PythonSystemExitErrorObject, "net.maxon.python.error.pythonsystem");
	class CPythonLibraryRef;

	struct CPythonLibraryInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CPythonLibraryInterface>::value || LibraryInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CPythonLibraryInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
	struct CPythonLibraryInterface::Hxx1
	{
		class Reference;
		using ReferenceClass = CPythonLibraryRef;
		template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LibraryInterface>;
		/// Intermediate helper class for CPythonLibraryInterface.
		template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
		{
		public:
			ConstFn() = default;
			using PrivateBaseClass = S;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static ConstFn PrivateLookupFn(CPythonLibraryInterface**);
			using TYPE_CONVERSION_TUPLE = CPythonLibraryInterface::TYPE_CONVERSION_TUPLE;
			static inline Result<PYSTARTOPERATION> ParseCommandLine(BaseArray<String>* args = nullptr, Data* res = nullptr, PYTHONFLAG* flags = nullptr);
/// Meta information of Python library.
/// 
/// @return												Meta information object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const PythonDll&>, const PythonDll&>::type GetDll() const;
/// Returns the current GIL state.
/// 
/// @return												Current GIL state.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<GILSTATE>, GILSTATE>::type GetGilState() const;
/// Increments the reference count for object o. The object must not be nullptr. GIL must be held.
/// See https://docs.python.org/3/c-api/refcounting.html#c.Py_INCREF for more information.
/// 
/// @param[in] o									Object to increment its reference count from.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_Incref(NativePyObject* o) const;
/// Decrements the reference count for object o. The object must not be nullptr. GIL must be held.
/// See https://docs.python.org/3/c-api/refcounting.html#c.Py_DECREF for more information.
/// 
/// @param[in] o									Object to decrement its reference count from.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_Decref(NativePyObject* o) const;
/// Increments the reference count for object o. If the object is nullptr, the call has no effect. GIL must be held.
/// See https://docs.python.org/3/c-api/refcounting.html#c.Py_XINCREF for more information.
/// 
/// @param[in] o									Object to decrement its reference count from.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_SafeIncref(NativePyObject* o) const;
/// Decrements the reference count for object o. If the object is nullptr, the call has no effect. GIL must be held.
/// See https://docs.python.org/3/c-api/refcounting.html#c.Py_XDECREF for more information.
/// 
/// @param[in] o									Object to decrement its reference count from.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_SafeDecref(NativePyObject* o) const;
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_SafeClear(T*& o) const;
/// Returns a None object. GIL must be held.
/// 
/// @return												None object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPy_None() const;
/// Returns a False object. GIL must be held.
/// 
/// @return												False object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPy_True() const;
/// Returns a True object. GIL must be held.
/// 
/// @return												True object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPy_False() const;
/// Returns the not implemented value object. GIL must be held.
/// 
/// @return												NotImplemented (is not the same as NotImplementedError)
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPy_NotImplemented() const;
/// Create a capsule encapsulating a given pointer. The pointer argument may not be nullptr. GIL must be held.
/// 
/// @param[in] pointer						Pointer to encapsulate.
/// @param[in] name								Name of the capsule.
/// @param[in] destructor					Function pointer which gets called on destruction of the capsule.
/// @return												capsule object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyCapsule_New(void* pointer, const Char* name, CPyCapsule_Destructor* destructor) const;
/// Creates a new immutable tuple. The tuple must be initialized right after it got created by using CPyTuple_SetItem. GIL must be held.
/// 
/// @param[in] size								Size of the new tuple.
/// @return												New tuple or empty object if if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyTuple_New(UInt size) const;
/// Converts a given string to a string object. GIL must be held.
/// 
/// @param[in] str								String constant.
/// @return												String object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyUnicode_FromString(const Char* str) const;
/// Gets the iterator of an object. Equivalent to iter(o). GIL must be held.
/// 
/// @param[in] o									Object to get the iterator from/
/// @return												Iterator object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_GetIter(const CPyRef& o) const;
/// Iterate next in an iterator. Equivalent to next(it)
/// 
/// @param[in] it									Iterator object.
/// @return												Next object or empty object if the exception indicator is set. If the last element got reached, StopIteration is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyIter_Next(const CPyRef& it) const;
/// Creates a new empty dictionary. GIL must be held.
/// 
/// @return												Dictionary object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_New() const;
/// Sets an item to a dictionary at a given key.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								String key.
/// @param[in] item								Item to set.
/// @return												True on sucess, or false if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const;
/// Checks if the given object is a dict. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a dict.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_Check(const CPyRef& o) const;
/// Checks if a type has a certain feature.
/// 
/// @param[in] type								Type object.
/// @param[in] f									Feature value.
/// @return												True if the type supports this feature or false if not.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const;
/// Performs a quick subtype check. 
/// 
/// @param[in] type								Type object.
/// @param[in] f									Subtype value.
/// @return												True if the type is of the given subtype or false if not.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const;
/// Returns the builtins of Python
/// 
/// @return												Builtins.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyEval_GetBuiltins() const;
/// Executes a given code object in the given globals, and locals dictionary.
/// 
/// @param[in] code								Code object to execute.
/// @param[in] globals						Global scope.
/// @param[in] locals							Local scope.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const;
/// static helper functions
			static inline Result<void> GetUrl(DEFAULTRUNTIME pythonPath, Url& pythonLibrary, Url& pythonHome);
/// Checks if the given object is a DataType capsule. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a DataType capsule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type MPyDataType_CheckExact(const CPyRef& o) const;
/// Returns the internal DataType pointer of a DataType capsule. GIL must be held.
/// 
/// @param[in] o									DataType capsule.
/// @return												DataType pointer or nullptr.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type MPyDataType_GetDataType(const MPyDataTypeRef& o) const;
/// Checks if the given object is a Data capsule. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a DataType capsule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type MPyData_CheckExact(const CPyRef& o) const;
/// Creates a scope dictionary which has all built-in modules preset.
/// 
/// @return          New dictionary object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CreateGlobalDictionary() const;
/// Same As CPyReference3 but preferred
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<CPyRef>>, Class<CPyRef>>::type GetCPyRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<CPyTypeRef>>, Class<CPyTypeRef>>::type GetCPyTypeRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<CPyFrameRef>>, Class<CPyFrameRef>>::type GetCPyFrameRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<CPyTracebackRef>>, Class<CPyTracebackRef>>::type GetCPyTracebackRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<CPyCodeRef>>, Class<CPyCodeRef>>::type GetCPyCodeRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyClassRef>>, Class<MPyClassRef>>::type GetMPyClassRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyMemberRef>>, Class<MPyMemberRef>>::type GetMPyMemberRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyFunctionRef>>, Class<MPyFunctionRef>>::type GetMPyFunctionRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyHashMapRef>>, Class<MPyHashMapRef>>::type GetMPyHashMapRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyDataTypeRef>>, Class<MPyDataTypeRef>>::type GetMPyDataTypeRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyDataRef>>, Class<MPyDataRef>>::type GetMPyDataRefClass() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Class<MPyCallerContextRef>>, Class<MPyCallerContextRef>>::type GetMPyCallerContextRefClass() const;
		};
		/// Intermediate helper class for CPythonLibraryInterface.
		template <typename S> class Fn : public ConstFn<S>
		{
		public:
			Fn() = default;
			using PrivateBaseClass = ConstFn<S>;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static Fn PrivateLookupFn(CPythonLibraryInterface**);
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPythonLibraryRef, true>::type&() const { return reinterpret_cast<const CPythonLibraryRef&>(this->GetBaseRef()); }
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CPythonLibraryRef, false>::type&() { return reinterpret_cast<const CPythonLibraryRef&>(this->GetBaseRef()); }
/// Initializes a new library object. Must not be called on the pre-allocated Python instances!
/// 
/// @param[in] librarypath				Path to the Python library.
/// @param[in] createSubLibrary		True to create a sub-interpreter.
/// @return												OK on success.
			inline Result<void> Init(const Url& librarypath, Bool createSubLibrary) const;
/// Initializes all types after proper initialization. Must not be called on the pre-allocated Python instances!
/// 
/// @return												OK on success.
			inline Result<void> InitTypes() const;
/// Initializes all builtin modules after initialization. Must not be called on the pre-allocated Python instances!
/// 
/// @return												OK on success.
			inline Result<void> InitBuiltinModules() const;
/// Initializes Python. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_Initialize() const;
/// Finalizes Python. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPy_Finalize() const;
/// Initialize a Python module by the information passed in the module definition. GIL must be held.
/// 
/// @param[in] module							Information about the builtin module.
/// @return												Reference 
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyModule_Create(const ModuleDefinition& module) const;
/// Free all resources and internals of Python.  Must not be called on the pre-allocated Python instances!
/// @param[in] shutdownEngine			Delegate which must execute Py_Finalize. GIL got released.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Free(const Delegate<void()>& shutdownEngine) const;
/// Should be used whenever the native Python API requires a FILE pointer.
/// Whenever a Python library function takes a FILE pointer it must be guaranteed that a valid FILE object is passed.
/// When Python is for instance compiled with VS2012 and the host application is compiled with VS2013 the FILE object must not be mixed
/// between runtimes (msvcr110.dll != msvcr120.dll). The FILE object must always be from the same runtime.
/// PythonLibrary::FopenNative() and PythonLibrary::fclose() guarantee that always the correct FILE structure is created.
/// 
/// @param[in] name								Name object of fopen(name, ...)
/// @param[in] mode								File mode, like fopen(..., "rb");
/// @return												File object or nullptr on failure.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<FILE_native*>, FILE_native*>::type FopenNative(const Char* name, const Char* mode) const;
/// Returns a Python error with an AggregatedError which is aggreated with PythonTracebackErrors.
/// 
/// @param[in] restoreError				True to keep the exception indicator untouched, or False to keep the exception indicator.
/// @return												PythonError.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Error>, Error>::type LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError) const;
/// Register a proxy component for virtual-, and non-virtual interfaces and adds the object to the Classes registry.
/// Used internally by the Python counterpart of MAXON_COMPONENT_OBJECT_REGISTER and MAXON_COMPONENT_CLASS_REGISTER to register a Python type.
/// GIL must be held.
/// 
/// @param[in] type								Python type which represents the implementation.
/// @param[in] registryId					Optional ID to which registry the object should be published to, can be empty.
/// @param[in] baseAndInterfaceIds	Definition object with information about the baseclasses and interfaces the type implements.
/// @param[in] cid								ID of the object, e.g. "net.maxon.iohandler.gzip"
/// @param[in] printErrors				True if the error of a failed Python function should be printed to the console, otherwise false.
/// 															If false, all exceptions within the overwritten functions must be handled for exceptions properly.
/// @param[in] kind								KIND type of the class.
/// @param[in] loc								Location information where the object got registered from.
/// @param[in] createObject				True to create and publish a new instance in the registry instead of the class.
/// 															True for MAXON_COMPONENT_OBJECT_REGISTER, and false for MAXON_COMPONENT_CLASS_REGISTER.
/// @param[in] dtOfObject					Necessary information of which type the ObjectRef instance is.
/// @return												MPyDataRef of the new class object.
			inline Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject) const;
/// Returns true when Python has been initialized, otherwise False.
/// 
/// @return												True or False.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPy_IsInitialized() const;
/// Return the version of this Python interpreter. The value is available to Python code as sys.version.
/// 
/// @return												Version string.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPy_GetVersion() const;
/// Return the platform identifier for the current platform. The value is available to Python code as sys.platform.
/// 
/// @return												Platform string.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPy_GetPlatform() const;
/// Return the official copyright string The value is available to Python code as sys.copyright.
/// 
/// @return												Copright string.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPy_GetCopyright() const;
/// Return an indication of the compiler used to build the current Python version.
/// The value is available to Python code as part of the variable sys.version.
/// 
/// @return												Copright string.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPy_GetCompiler() const;
/// Return information about the sequence number and build date and time of the current
/// Python interpreter instance. The value is available to Python code as part of the variable sys.version.
/// 
/// @return												Build info.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPy_GetBuildInfo() const;
/// This function should be called before Py_Initialize() is called for the first time.
/// @param[in] name								Name for the current program.
			inline Result<void> CPy_SetProgramName(const String& name) const;
/// Set the default "home" directory, that is, the location of the standard Python libraries.
/// @param[in] name								Name for the current program.
			inline Result<void> CPy_SetPythonHome(const Url& name) const;
/// Return the program name set with Py_SetProgramName(), or the default.
/// @return												Program name.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type CPy_GetProgramName() const;
/// Return the default "home", that is, the value set by a previous call to Py_SetPythonHome().
/// @return												Python home.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type CPy_GetPythonHome() const;
/// Executes a Python module by its name. GIL must be held.
/// 
/// @param[in] name								Name of the module.
/// @return												True on success, otherwise false. Exception indicator is cleared before function returns.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type ExecuteModule(const String& name) const;
/// Private. Create caller context object which contains a pointer to this object. The context gets passed to all
/// C-functions as the first self parameter. This is used in PrivateExtractCPythonLibrary{XX} to achieve the convenient
/// wrapping method for C++ functions. GIL must be held.
/// 
/// @return												New caller context.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyCallerContextRef>, MPyCallerContextRef>::type CPyCallerContext_New() const;
/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] fp									File pointer where to read the source from.
/// @param[in] filename						Path of the file.
/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags) const;
/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] url								Url where the source is read from.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags) const;
/// Executes the Python source code from a source string. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] code								Python source code.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags) const;
/// Execute Python source code from fp in the context specified by the objects globals and locals with the compiler flags specified by flags.
/// locals must be a dictionary; locals can be any object that implements the mapping protocol. The parameter start specifies the start token that should be used to parse the source code.If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
///
/// @param[in] fp									File pointer where to read the source from.
/// @param[in] filename						Path of the file.
/// @param[in] start							Key start like PY_FILE_INPUT
/// @param[in] globals						Dict object.
/// @param[in] locals							Any object that implements the mapping protocol.
/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyObject*>, NativePyObject*>::type CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags) const;
/// Enters the interactive loop of the Python interpreter. If an exception occurrs, it stays in the loop. Only a sys.exit() will
/// exit the function with OK. Raises exceptions only for internal errors. GIL must be held.
/// 
/// @param[in] fp									File stream of the input stream, normally stdin.
/// @param[in] filename						Name of the interactive loop.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												OK on success, and sys.exit().
			inline Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags) const;
/// Ensure that the current thread is ready to call the Python C API regardless of the current state of Python, or of the global interpreter lock.
/// See https://docs.python.org/3/c-api/init.html#c.PyGILState_Ensure for more information.
/// @return												GIL state.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<PYGILSTATE>, PYGILSTATE>::type CPyGilState_Ensure() const;
/// Release any resources previously acquired. After this call, Python's state will be the same as it was prior to the corresponding CPyGILState_Ensure() call. GIL must be held.
/// See https://docs.python.org/3/c-api/init.html#c.PyGILState_Release for more information.
/// 
/// @param[in] state							GIL state.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyGilState_Release(PYGILSTATE state) const;
/// Returns the current thread state object.
/// 
/// @return												Thread state object or nullptr if no thread state object is available.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyThreadState*>, NativePyThreadState*>::type CPyGILState_GetThisThreadState() const;
/// Swap the current thread state with the passed one. 
///
/// @param state    Thread State to swap with.
/// @return         Old thread state.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyThreadState*>, NativePyThreadState*>::type CPyThreadState_Swap(NativePyThreadState* state) const;
/// Get the dictionary of the current thread state.
///
/// @return         Dict of the current thread state.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyThreadState_GetDict() const;
/// Parse and compile a given Python source code returning the resulting code object. GIL must be held.
/// 
/// @param[in] code								Python source code.
/// @param[in] filename						Filename of the code object and might appear in the traceback or SyntaxError exception messages.
/// @param[in] start							Start token.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyCodeRef>, CPyCodeRef>::type CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags = nullptr) const;
/// Runs the garbage collector of Python. GIL must be held.
/// 
/// @return												Number of items collected
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type CPyGC_Collect() const;
/// Returns the line number of a code object with a given instruction.
/// 
/// @param[in] codeObject					Code object.
/// @param[in] x									Instruction in bytes.
/// @return												Line number or -1 on failure.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x) const;
/// Returns the internal DataType capsule of a maxon.DataType object. GIL must be held.
/// 
/// @param[in] obj								Object of type maxon.DataType.
/// @return												DataType capsule. Can be safely casted to MPyDataType
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type UnpackDataType(const CPyRef& obj) const;
/// Returns the internal Data capsule of a maxon.Data object. GIL must be held.
/// 
/// @param[in] obj								Object of type maxon.Data.
/// @return												Data capsule. Can be safely casted to MPyData
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type UnpackData(const CPyRef& obj) const;
/// Print a standard traceback to sys.stderr and clear the error indicator. Call this function only when the error indicator is set (Otherwise it will cause a fatal error!).  GIL must be held.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_Print() const;
/// Clears the error indicator of Python. If the error indicator is not set, the call has no effect. GIL must be held.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_Clear() const;
/// Checks if the error indicator is set. GIL must be held.
/// 
/// @param[out] type							Private. Exception type.
/// @return												True if the error indicator is set, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyErr_Occurred(CPyRef* type = nullptr) const;
/// Sets the error indicator. GIL must be held.
/// 
/// @param[in] errorType					Exception type object.
/// @param[in] errorString				Human readbale exception message.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyErr_SetString(const CPyRef& errorType, const Char* errorString = nullptr) const;
/// Sets the error indicator with a filename and errno. GIL must be held.
///
/// @param[in] errorType					Exception type object.
/// @param[in] errorNumber				Error indicator.
/// @param[in] filename						Filename object.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename) const;
/// Sets the error indicator. GIL must be held.
///
/// @param[in] errorType					Exception type object.
/// @param[in] errorNumber				Error indicator.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber) const;
/// Sets the error indicator. GIL must be held.
/// 
/// @param[in] errorType					Exception type object.
/// @param[in] errorString				Human readbale exception message.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyErr_SetString(const CPyRef& errorType, const String& errorString) const;
/// Sets the error indicator without a message. GIL must be held.
///
/// @param[in] errorType					Exception type object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_SetNone(const CPyRef& errorType) const;
/// Retrieve the error indicator into three variables whose addresses are passed. If the error indicator is not set, all three objects are empty.
/// 
/// @param[out] type							Exception type.
/// @param[out] value							Exception value.
/// @param[out] traceback					Traceback object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback) const;
/// Normalizes the objects, retrieved by CPyErr_Fetched.
/// See https://docs.python.org/3/c-api/exceptions.html#c.PyErr_NormalizeException for more information.
///
/// @param[out] type							Exception type.
/// @param[out] value							Exception value.
/// @param[out] traceback					Traceback object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback) const;
/// Restores the exception which got retrieved by CPyErr_Fetch.
/// 
/// @param[in] type								Exception type.
/// @param[in] value							Exception value.
/// @param[in] traceback					Traceback object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback) const;
/// Checks if the current set exception is of a given exception.
/// 
/// @param[in] exc								A given object.
/// @return												True when equal, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyErr_ExceptionMatches(const CPyRef& exc) const;
/// Checks if the given object is an exception. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is an exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyExceptionClass_Check(const CPyRef& o) const;
/// Set the pointer of the capsule. GIL must be held.
/// 
/// @param[in] capsule						Capsule object.
/// @param[in] pointer						Set, or overwrite the pointer of the capsule.
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer) const;
/// Retrieve the pointer stored in the capsule. On failure, returns nullptr. GIL must be held.
/// 
/// @param[in] capsule						Capsule to extract the pointer from.
/// @param[in] name								Name of the capsule. On mismatch, the function returns nullptr.
/// @return												Pointer from capsule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name) const;
/// Retrieve the context stored in the capsule, which was set by CPyCapsule_SetContext. On failure, returns nullptr. GIL must be held.
/// 
/// @param[in] capsule						Capsule to extract the context from.
/// @return												Pointer to the capsule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type CPyCapsule_GetContext(const CPyRef& capsule) const;
/// Set a context pointer to a capsule. GIL must be held.
/// 
/// @param[in] capsule						Set, or overwrite the pointer of the capsule.
/// @return												Context pointer.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyCapsule_SetContext(const CPyRef& capsule, void* context) const;
/// Checks if the given object is a capsule. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a capsule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyCapsule_CheckExact(const CPyRef& o) const;
/// Checks if the given object is a traceback. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a traceback.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyTraceBack_Check(const CPyRef& o) const;
/// Checks if the given object is a class. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a class.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyClass_Check(const CPyRef& o) const;
/// Returns the size of a tuple. GIL must be held. GIL must be held.
/// 
/// @return												Size of the tuple, or -1 if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type CPyTuple_Size(const CPyRef& tuple) const;
/// Retrieves an item of a tuple by its index. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
/// @return												Element of the item at the given index, or empty object if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyTuple_GetItem(const CPyRef& tuple, UInt index) const;
/// Sets an item in a tuple at a given index. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
/// @param[in] item								Item to set.
/// @return												True on success. Returns false if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item) const;
/// Retrieves a slice object from a given slice range. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] from								Start index (including the object at this given index).
/// @param[in] to									End index (excluding the object at this given index).
/// @return												Slice objector empty object if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to) const;
/// Checks if a given object is a tuple. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @return												True if o is a tuple.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyTuple_CheckExact(const CPyRef& tuple) const;
/// Checks if a given object has a specific attribute name. Equivalent to getattr(o, "name"). GIL must be held.
/// 
/// @param[in] o									Object to Checks the attribute for.
/// @param[in] attrName						Name of the attribute.
/// @return												True on match, otherwise False.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_HasAttrString(const CPyRef& o, const Char* attrName) const;
/// Sets the value of the attribute named attrName, for object o, to the value item. GIL must be held.
/// 
/// @param[in] o									Object which will get the attribute.
/// @param[in] name								Name of the attribute.
/// @param[in] item								Value of the attribute.
/// @return												True on success, otherwise False if the exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item) const;
/// Gets the attribute of an object by an attribute name. GIL must be held.
/// 
/// @param[in] o									Object to get the attribute from.
/// @param[in] name								Name of the attribute.
/// @return												Attribute on success or empty object if attribute could not be found and exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_GetAttrString(const CPyRef& o, const Char* name) const;
/// Calls an object with optional argument list or a keyword dictionary. GIL must be held.
/// 
/// @param[in] callable_object		Object to call.
/// @param[in] tupleArg						Argument list. Can be empty.
/// @param[in] kw									Dictionary list. Can be empty.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw) const;
/// Computes a string representation of an object. Equivalent to str(o). GIL must be held.
/// 
/// @param[in] o									Object to stringify.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_Str(const CPyRef& o) const;
/// Computes a string representation of an object. Equivalent to repr(o). GIL must be held.
/// 
/// @param[in] o									Object to stringify.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_Repr(const CPyRef& o) const;
/// Gets the internal dictionary of an object. Equivalent to dir(o). GIL must be held.
/// 
/// @param[in] o									Object to get the dictionary from..
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_Dir(const CPyRef& o) const;
/// Rich compares two objects with each other and returns its result. Equivalent to "o1 op o2". GIL must be held.
/// 
/// @param[in] o1									Left operand.
/// @param[in] o2									Right operand.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid) const;
/// Computes the hash of an object. Equivalent to hash(o). GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												The hash or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type CPyObject_Hash(const CPyRef& o) const;
/// Returns true if the object is considered to be true, and false otherwise. This is equivalent to the Python expression 'not not o'. GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												True if the object is true, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_IsTrue(const CPyRef& o) const;
/// Returns false if the object is considered to be true, and true otherwise. This is equivalent to the Python expression 'not o'. GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												True if the object is true, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_Not(const CPyRef& o) const;
/// Checks if a given object is a callable. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is callable.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyCallable_Check(const CPyRef& o) const;
/// Returns the length of an object. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												Length or -1 if the exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type CPyObject_Length(const CPyRef& o) const;
/// Gets the item of an object. Equivalent to getitem(o). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] key								Key object.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_GetItem(const CPyRef& o, const CPyRef& key) const;
/// Gets the item of an object by an index. Equivalent to getitem(o, intValue). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] index							Int key.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_GetItemInt(const CPyRef& o, Int index) const;
/// Gets the item of an object by a string. Equivalent to getitem(o, strValue). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] index							String key.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_GetItemString(const CPyRef& o, const Char* index) const;
/// Deletes an item of an object by a given key.
/// 
/// @param[in] o									Object.
/// @param[in] key								Object key.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_DelItem(const CPyRef& o, const CPyRef& key) const;
/// Sets an item to an object at a given key. Equivalent to o[key]. GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] key								String key.
/// @param[in] item								Object item.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item) const;
/// Check if a given object is of a certain type.
/// 
/// @param[in] object							Object to check.
/// @param[in] type								Type object.
/// @return												True on match, otherwise False.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type) const;
/// Calls an object. Equivalent to o(). GIL must be held.
/// 
/// @param[in] o									Object to call.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_CallFunction(const CPyRef& o) const;
/// Retrieves an object from the sys module by its name. GIL must be held.
/// 
/// @param[in] name								Name of the object.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPySys_GetObject(const Char* name) const;
/// Sets an object to the sys module. GIL must be held.
/// 
/// @param[in] name								Name of the object.
/// @param[in] o									Object to set.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPySys_SetObject(const Char* name, const CPyRef& o) const;
/// Sets an array of paths to sys.path. GIL must be held.
///
/// @param[in] paths              Array of paths to set. None of the elements must be empty.
/// @return                       OK on success or error, if the exception indicator got set.
			inline Result<void> CPy_SetPath(const BaseArray<Url>& paths) const;
/// Sets an array of paths to sys.path. GIL must be held.
/// 
/// @param[in] paths							Array of paths to set. None of the elements must be empty.
/// @param[in] add								Mode of the operation.
/// @return												OK on success or error, if the exception indicator got set.
			inline Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add) const;
/// Sets the arguments to sys.argv.
/// 
/// @param[in] args								New arguments.
/// @param[in] updatepath					Bool to update sys.path, otherwise false.
/// @return												OK on success or error, if the exception indicator got set.
			inline Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath) const;
/// Returns an array of URLs which are in sys.path.
/// 
/// @return												Array of Url objects.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Url>>, BaseArray<Url>>::type CPySys_GetPath() const;
/// Adds a directory to sys.path and process its .pth files.
/// 
/// @param[in] siteDir						Directory to add.
/// @return												OK on success.
			inline Result<void> CPySite_AddSiteDir(const Url& siteDir) const;
/// Checks if the given object is a str or a subtype of StringType. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a str.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyUnicode_Check(const CPyRef& o) const;
/// Converts a given block to a string object. GIL must be held.
/// 
/// @param[in] block							Char block.
/// @return												String object or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyUnicode_FromStringAndSize(const Block<const Char>& block) const;
/// Converts a string object to a string. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												String or error if the exception indicator got set.
			inline Result<String> CPyUnicode_AsString(const CPyRef& str) const;
/// Retrieves the pointer to a chary array of a string object. The char array is alive as long as the string object
/// is alive. Until the string object gets deleted, the char array will be deleted too. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												Pointer to char array, or nullptr if the the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type CPyUnicode_AsCString(const CPyRef& str) const;
/// Gets the size of a string. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												Length or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type CPyUnicode_GetLength(const CPyRef& str) const;
/// Gets the item of a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError) const;
/// Gets the item of a dictionary by a given key string. 
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key string.
/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError) const;
/// Sets an item to a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @param[in] item								Value item.
/// @return               True on sucess, or false if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item) const;
/// Deletes an item from a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_DelItem(const CPyRef& dict, const CPyRef& key) const;
/// Determines if #dict contains the key #p.
/// 
/// @param[in] dict Dict object.
/// @param[in] key Key object.
/// @return True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CONTAINS>, CONTAINS>::type CPyDict_Contains(const CPyRef& dict, const CPyRef& key) const;
/// Removes all elements from the dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyDict_Clear(const CPyRef& dict) const;
/// Goes to the next element in the dictionary, starting from a given index.
/// 
/// @param[in] dict								Dict object.
/// @param[in,out] pos						Index start and gets incremented by one when the function leaves.
/// @param[in] key								Key object.
/// @param[in] value							Value object.
/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value) const;
/// Gets all keys of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of keys.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_Keys(const CPyRef& dict) const;
/// Gets all values of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of values.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_Values(const CPyRef& dict) const;
/// Gets all items of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of items.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_Items(const CPyRef& dict) const;
/// Return the number of items in the dictionary. This is equivalent to len(p) on a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												Number of items.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type CPyDict_Size(const CPyRef& dict) const;
/// Gets a copy of a given dictionary. Does not make a deepcopy. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												Number of items.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyDict_Copy(const CPyRef& dict) const;
/// Creates a new list of a certain size. GIL must be held.
/// 
/// @param[in] size								Size of the list.
/// @return												New list object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyList_New(UInt size) const;
/// Checks if a list is a list. No subtype check is performed. GIL must be held.
/// 
/// @param[in] list Object to check.
/// @return True if the object is a list, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_CheckExact(const CPyRef& list) const;
/// Clears a list.
/// 
/// @param[in] list The list to clear.
/// @return True if the list has been cleared successfully, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_Clear(const CPyRef& list) const;
/// Evaluates the length of a list and is equivalent to <tt>len(list)</tt>.
/// 
/// @param[in] list The list to evaluate.
/// @return The length of #list.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type CPyList_Size(const CPyRef& list) const;
/// Returns the object at #index in a list and is equivalent to <tt>list[index]</tt>..
/// 
/// @param[in] list The list to retrieve the object from.
/// @param[in] index The index of the object to retrieve.
/// @return The object at #index in #list.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyList_GetItem(const CPyRef& list, UInt index) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item) const;
/// Appends an object to a list and is equivalent to <tt>list.append(item).</tt>.
/// 
/// @param[in, out] list The list to append #item to.
/// @param[in] item The item to append.
/// @return True if #item has been successfully appended, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_Append(const CPyRef& list, const CPyRef& item) const;
/// Returns a slice of a list and is equivalent to <tt>list[from, to]</tt>.
/// 
/// @param[in] list The list to return a slice from.
/// @param[in] from The starting index of the slice.
/// @param[in] to The ending index of the slice.
/// @return The Python slice object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyList_GetSlice(const CPyRef& list, UInt from, UInt to) const;
/// Sets a slice of a list and is equivalent to <tt>list[from, to] = item</tt>.
/// 
/// @param[in] list The list to set a slice in.
/// @param[in] from The starting index of the slice.
/// @param[in] to The ending index of the slice.
/// @param[in] item The value of the slice, must be a list or NULL.
/// @return True if #item has been successfully sliced in, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item) const;
/// Sorts a list and is equivalent to <tt>list.sort()</tt>.
/// 
/// @param[in] list The list to sort.
/// @return True if #list has been successfully sorted, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_Sort(const CPyRef& list) const;
/// Reverses a list and is equivalent to <tt>list.reverse()</tt>.
/// 
/// @param[in] list The list to reverse.
/// @return True if #list has been successfully reversed, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyList_Reverse(const CPyRef& list) const;
/// Returns a new Python tuple containing the content of #list and is equivalent to <tt>tuple(list)</tt>.
/// 
/// @param[in] list The list to convert.
/// @return The content of #list as a Python tuple.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyList_AsTuple(const CPyRef& list) const;
/// Remove the entry in dictionary p which has a key specified by the string key. If key is not in the dictionary, a KeyError is raised.
/// 
/// @param[in] p Dict object.
/// @param[in] key Key object.
/// @return True on success, otherwise false.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyDict_DelItemString(const CPyRef& p, const Char* key) const;
/// Checks if the given object is a module. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a module.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyModule_Check(const CPyRef& o) const;
/// Add the given object within the module dictionary with the specified name as key. GIL must be held.
/// @note if a PyTypeObject is passed, then this type should be already ready otherwise IllegalArgumentError will be returned.
/// 
/// @param[in] module							The module object.
/// @param[in] name								The name of the type (only the last part not the full qualified name).
/// @param[in] value							The object to be inserted.
/// @return												@trueIfOtherwiseFalse{value object is correctly added}.
			inline Result<Bool> CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value) const;
/// Add the given Type Object and make it Ready within the module dictionary. GIL must be held.
/// @note The name used will be set by the value of CPyType_Name (last qualifier of tp_name).
/// 
/// @param[in] module							The module object.
/// @param[in] value							The type object to be inserted.
/// @return												@trueIfOtherwiseFalse{value object is correctly added}.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyModule_AddType(const CPyRef& module, const CPyTypeRef& value) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyModule_GetDict(const CPyRef& module) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value) const;
/// import
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyImport_ImportModule(const Char* name) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyImport_GetImporter(const CPyRef& path) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyImport_GetModuleDict() const;
/// Checks if the given object is a type. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a type.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyType_Check(const CPyRef& o) const;
/// Checks if a type is really a subclass, __subclasscheck__() is not called. An object is not a subtype of its own class. Use CPyObject_IsSubtype instead. GIL must be held.
/// 
/// @param[in] a									Base type.
/// @param[in] b									Subtype type.
/// @return												Returns true if a is a subtype of b.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b) const;
/// Returns the name of a given type.
/// 
/// @param[in] type								Type object.
/// @return												Name of the type or error if the exception indicator got set.
			inline Result<String> CPyType_GetName(const CPyTypeRef& type) const;
/// Initializes a type.
/// 
/// @param[in] type								Type object to initialize. 
/// @return												True on success.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyType_Ready(CPyTypeRef& type) const;
/// Release the global interpreter lock 
/// 
/// @return												Previous state object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<NativePyThreadState*>, NativePyThreadState*>::type CPyEval_SaveThread() const;
/// Restores a given thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyEval_RestoreThread(NativePyThreadState* state) const;
/// Checks if multi-threading for Python is enabled.
/// 
/// @return												True if available.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyEval_ThreadsInitialized() const;
/// Private. Initializes multi-threading for the Python library. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyEval_InitThreads() const;
/// Acquires the GIL for a thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyEval_AcquireThread(NativePyThreadState* state) const;
/// Releases the GIL for a thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CPyEval_ReleaseThread(NativePyThreadState* state) const;
/// Checks if the given object is a float. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a float.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyFloat_Check(const CPyRef& o) const;
/// Creates a float object from a Float32.
///
/// @param[in] value							Float32 value.
/// @return												bool object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyFloat_FromFloat32(Float32 value) const;
/// Creates a float object from a Float64.
///
/// @param[in] value							Float64 value.
/// @return												bool object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyFloat_FromFloat64(Float64 value) const;
/// Converts a float object to Float64.
/// 
/// @param[in] o									Object to convert.
/// @return												Result or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float64>, Float64>::type CPyFloat_AsFloat64(const CPyRef& o) const;
/// Converts an object to a floating type.
/// 
/// @tparam T											Floating type.
/// @param[in] o									Object to convert.
/// @return												Result value.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type CPyFloat_As(const CPyRef& o) const;
/// Converts an object from a Float32 value.
/// 
/// @param[in] o									Float value.
/// @return												Float object.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyFloat_From(std::enable_if_t<STD_IS_REPLACEMENT(same,T,Float32), Float32> o) const;
/// Converts an object from a Float64 value.
/// 
/// @param[in] o									Float value.
/// @return												Float object.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyFloat_From(std::enable_if_t<STD_IS_REPLACEMENT(same,T,Float64), Float64> o) const;
/// Checks if the given object is an int or a subtype of PyLong_Type. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a 
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyLong_Check(const CPyRef& o) const;
/// Creates a bool object from a Bool.
///
/// @param[in] value							Bool value.
/// @return												bool object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyBool_FromBool(Bool value) const;
/// Creates an int object from a Int16 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromInt16(Int16 value) const;
/// Creates an int object from a UInt16 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromUInt16(UInt16 value) const;
/// Creates an int object from a Int32 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromInt32(Int32 value) const;
/// Creates an int object from a UInt32 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromUInt32(UInt32 value) const;
/// Creates an int object from a Int64 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromInt64(Int64 value) const;
/// Creates an int object from a UInt64 value. GIL must be held.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_FromUInt64(UInt64 value) const;
/// Converts an object to an Int16 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type CPyLong_AsInt16(const CPyRef& o) const;
/// Converts an object to an UInt16 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type CPyLong_AsUInt16(const CPyRef& o) const;
/// Converts an object to an Int32 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type CPyLong_AsInt32(const CPyRef& o) const;
/// Converts an object to an UInt32 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type CPyLong_AsUInt32(const CPyRef& o) const;
/// Converts an object to an Int64 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type CPyLong_AsInt64(const CPyRef& o) const;
/// Converts an object to an UInt64 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type CPyLong_AsUInt64(const CPyRef& o) const;
/// Converts an object to type T. GIL must be held.
/// 
/// @tparam T											Integral type.
/// @param[in] o									Object to convert.
/// @return												Result value.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type CPyLong_As(const CPyRef& o) const;
/// Converts an object from an Int32 value. GIL must be held.
/// 
/// @param[in] o									Int value.
/// @return												Int object.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_From(std::enable_if_t<std::is_same<T, Int32>::value, Int32> o) const;
/// Converts an object from an Int64 value. GIL must be held.
/// 
/// @param[in] o									Int64 value.
/// @return												Int object.
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyLong_From(std::enable_if_t<std::is_same<T, Int64>::value, Int64> o) const;
/// Checks if the given object is a numeric object. GIL must be held.
/// 
/// @param[in] o									Object to check.
/// @return												True if an object is a numeric value.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CPyNumber_Check(const CPyRef& o) const;
/// Creates a function capsule that encapsulates a reflection::Function pointer.
/// 
/// @param[in] func								Function pointer to encapsulate.
/// @return												New function capsule or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyFunctionRef>, MPyFunctionRef>::type MPyFunction_New(const reflection::Function* func) const;
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @param[in] map								HashMap<Data, Data> reference to encapsulate. A copy will be done.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyHashMapRef>, MPyHashMapRef>::type MPyHashMap_New(const HashMap<Data, Data>& map) const;
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @param[in] map								HashMap<Data, Data> reference to encapsulate.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyHashMapRef>, MPyHashMapRef>::type MPyHashMap_New(HashMap<Data, Data>&& map) const;
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @tparam KEY										Type of the Key. The type should be convertible to a Data.
/// @tparam VALUE									Type of the Value. The type should be convertible to a Data.
/// @param[in] map								HashMap<KEY, VALUE> reference to encapsulate. A copy will be done.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			template <typename KEY, typename VALUE> inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyHashMapRef>, MPyHashMapRef>::type MPyHashMap_New(HashMap<KEY, VALUE>& map) const;
/// Creates a member capsule that encapsulates a reflection::Member pointer.
/// 
/// @param[in] member							Member pointer to encapsulate.
/// @return												New member capsule or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyMemberRef>, MPyMemberRef>::type MPyMember_New(const reflection::Member* member) const;
/// Set a custom memory allocator. See https://docs.python.org/3/c-api/memory.html#c.PyMem_SetAllocator
			inline Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator) const;
/// Creates a class capsule that encapsulates a reflection::Member pointer.
/// 
/// @param[in] cls								Class pointer to encapsulate.
/// @return												New class capsule or empty object if the exception indicator got set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyClassRef>, MPyClassRef>::type MPyClass_New(const reflection::Class* cls) const;
/// Returns a mutable pointer to a DebugFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												DebugFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_DebugFlag() const;
/// Returns a mutable pointer to a VerboseFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												VerboseFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_VerboseFlag() const;
/// Returns a mutable pointer to a InteractiveFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												InteractiveFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_InteractiveFlag() const;
/// Returns a mutable pointer to a InspectFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												InspectFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_InspectFlag() const;
/// Returns a mutable pointer to a OptimizeFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												OptimizeFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_OptimizeFlag() const;
/// Returns a mutable pointer to a NoSiteFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												NoSiteFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_NoSiteFlag() const;
/// Returns a mutable pointer to a BytesWarningFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												BytesWarningFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_BytesWarningFlag() const;
/// Returns a mutable pointer to a FrozenFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												FrozenFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_FrozenFlag() const;
/// Returns a mutable pointer to a IgnoreEnvironmentFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												IgnoreEnvironmentFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_IgnoreEnvironmentFlag() const;
/// Returns a mutable pointer to a DontWriteBytecodeFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												DontWriteBytecodeFlag flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_DontWriteBytecodeFlag() const;
/// Returns a mutable pointer to a NoUserSiteDirectory. Can be nullptr if the flag is not available in this Python version.
///
/// @return												NoUserSiteDirectory flag
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32*>, Int32*>::type CPy_NoUserSiteDirectory() const;
/// Returns the BaseException.
///
/// @return												The BaseException exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_BaseException() const;
/// Returns the Exception.
///
/// @return												The Exception exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_Exception() const;
/// Returns the StopIteration.
///
/// @return												The StopIteration exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_StopIteration() const;
/// Returns the GeneratorExit.
///
/// @return												The GeneratorExit exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_GeneratorExit() const;
/// Returns the StandardError.
///
/// @return												The StandardError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_StandardError() const;
/// Returns the ArithmeticError.
///
/// @return												The ArithmeticError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ArithmeticError() const;
/// Returns the LookupError.
///
/// @return												The LookupError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_LookupError() const;
/// Returns the AssertionError.
///
/// @return												The AssertionError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_AssertionError() const;
/// Returns the AttributeError.
///
/// @return												The AttributeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_AttributeError() const;
/// Returns the EOFError.
///
/// @return												The EOFError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_EOFError() const;
/// Returns the FloatingPointError.
///
/// @return												The FloatingPointError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_FloatingPointError() const;
/// Returns the EnvironmentError.
///
/// @return												The EnvironmentError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_EnvironmentError() const;
/// Returns the IOError.
///
/// @return												The IOError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_IOError() const;
/// Returns the OSError.
///
/// @return												The OSError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_OSError() const;
/// Returns the ImportError.
///
/// @return												The ImportError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ImportError() const;
/// Returns the IndexError.
///
/// @return												The IndexError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_IndexError() const;
/// Returns the KeyError.
///
/// @return												The KeyError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_KeyError() const;
/// Returns the KeyboardInterrupt.
///
/// @return												The KeyboardInterrupt exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_KeyboardInterrupt() const;
/// Returns the MemoryError.
///
/// @return												The MemoryError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_MemoryError() const;
/// Returns the NameError.
///
/// @return												The NameError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_NameError() const;
/// Returns the OverflowError.
///
/// @return												The OverflowError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_OverflowError() const;
/// Returns the RuntimeError.
///
/// @return												The RuntimeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_RuntimeError() const;
/// Returns the NotImplementedError.
///
/// @return												The NotImplementedError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_NotImplementedError() const;
/// Returns the SyntaxError.
///
/// @return												The SyntaxError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_SyntaxError() const;
/// Returns the IndentationError.
///
/// @return												The IndentationError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_IndentationError() const;
/// Returns the TabError.
///
/// @return												The TabError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_TabError() const;
/// Returns the ReferenceError.
///
/// @return												The ReferenceError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ReferenceError() const;
/// Returns the SystemError.
///
/// @return												The SystemError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_SystemError() const;
/// Returns the SystemExit.
///
/// @return												The SystemExit exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_SystemExit() const;
/// Returns the TypeError.
///
/// @return												The TypeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_TypeError() const;
/// Returns the UnboundLocalError.
///
/// @return												The UnboundLocalError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnboundLocalError() const;
/// Returns the UnicodeError.
///
/// @return												The UnicodeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnicodeError() const;
/// Returns the UnicodeEncodeError.
///
/// @return												The UnicodeEncodeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnicodeEncodeError() const;
/// Returns the UnicodeDecodeError.
///
/// @return												The UnicodeDecodeError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnicodeDecodeError() const;
/// Returns the UnicodeTranslateError.
///
/// @return												The UnicodeTranslateError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnicodeTranslateError() const;
/// Returns the ValueError.
///
/// @return												The ValueError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ValueError() const;
/// Returns the ZeroDivisionError.
///
/// @return												The ZeroDivisionError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ZeroDivisionError() const;
/// Returns the WindowsError.
///
/// @return												The WindowsError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_WindowsError() const;
/// Returns the BufferError.
///
/// @return												The BufferError exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_BufferError() const;
/// Returns the MemoryErrorInst.
///
/// @return												The MemoryErrorInst exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_MemoryErrorInst() const;
/// Returns the Warning.
///
/// @return												The Warning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_Warning() const;
/// Returns the UserWarning.
///
/// @return												The UserWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UserWarning() const;
/// Returns the DeprecationWarning.
///
/// @return												The DeprecationWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_DeprecationWarning() const;
/// Returns the PendingDeprecationWarning.
///
/// @return												The PendingDeprecationWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_PendingDeprecationWarning() const;
/// Returns the SyntaxWarning.
///
/// @return												The SyntaxWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_SyntaxWarning() const;
/// Returns the RuntimeWarning.
///
/// @return												The RuntimeWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_RuntimeWarning() const;
/// Returns the FutureWarning.
///
/// @return												The FutureWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_FutureWarning() const;
/// Returns the ImportWarning.
///
/// @return												The ImportWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_ImportWarning() const;
/// Returns the UnicodeWarning.
///
/// @return												The UnicodeWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_UnicodeWarning() const;
/// Returns the BytesWarning.
///
/// @return												The BytesWarning exception.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyConstRef>, CPyConstRef>::type CPyExc_BytesWarning() const;
/// Returns the CPyNullItype of CPyNullImporter.
/// @return												Type of CPyNullImporter.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyNullImporter_Type() const;
/// Returns the Ctype of CPySuper.
/// @return												Type of CPySuper.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPySuper_Type() const;
/// Returns the type of CPyBool.
/// @return												Type of CPyBool.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyBool_Type() const;
/// Returns the CPtype of CPyObject.
/// @return												Type of CPyObject.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyObject_Type() const;
/// Returns the CPtype of CPyModule.
/// @return												Type of CPyModule.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyModule_Type() const;
/// Returns the CPtype of CPyUnicode.
/// @return												Type of CPyUnicode.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyUnicode_Type() const;
/// Returns the type of CPyLong.
/// @return												Type of CPyLong.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyLong_Type() const;
/// Returns the Ctype of CPyFloat.
/// @return												Type of CPyFloat.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyFloat_Type() const;
/// Returns the Ctype of CPyTuple.
/// @return												Type of CPyTuple.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyTuple_Type() const;
/// Returns the type of CPyList.
/// @return												Type of CPyList.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyList_Type() const;
/// Returns the type of CPyDict.
/// @return												Type of CPyDict.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyDict_Type() const;
/// Returns the Ctype of CPyClass.
/// @return												Type of CPyClass.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyClass_Type() const;
/// Returns the CPyTrtype of CPyTraceBack.
/// @return												Type of CPyTraceBack.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyTraceBack_Type() const;
/// Returns the Ctype of CPySlice.
/// @return												Type of CPySlice.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPySlice_Type() const;
/// Returns the type of CPyType.
/// @return												Type of CPyType.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyType_Type() const;
/// Returns the CPyMemtype of CPyMemoryView.
/// @return												Type of CPyMemoryView.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyMemoryView_Type() const;
/// Converts a string with a specific encoding and stores the content for the lifetime of the Python interpreters runtime.
/// Some functions in Python need a string that stays alive for the duration of the Pythons interpreter.
///
/// @param[in] str								String to convert.
/// @param[in] encoding						Encoding to use.
/// @return												Pointer to the first array of the string sequence. Can be casted to the corresponding code unit type.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<const PyChar*>, const PyChar*>::type ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size = nullptr) const;
/// Private.
			inline Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type) const;
/// Registers a lambda for back- and forth conversions of certain DataTypes.
/// 
/// @param[in] dt									DataType the converters can handle.
/// @param[in] f1									Lambda or function to convert a Python object to a Data object.
/// @param[in] f2									Lambda or function which converts a Data object to a Python object.
/// @return												OK on success.
			inline Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2) const;
			template <typename T> inline Result<void> RegisterBuiltinConverter(const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<T>& f2) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetSpecialPath(SPECIALPATH anonymous_param_1) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type MPyDataCapsule_Type() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyData_Type() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyTypeConstRef>, CPyTypeConstRef>::type CPyCapsule_Type() const;
/// Private.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type PrivateGetCurrentCallerContext() const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type MPyDataType_ToMapperInstance(const CPyRef& capsule) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type MPyData_ToMapperInstance(const MPyDataRef& capsule) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule) const;
			inline Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type) const;
			inline Result<CPyRef> GetAssociatedDataType(const DataType& dt) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<DelegatePyObject_FromData<>*>, DelegatePyObject_FromData<>*>::type GetConverterPyObject_FromData(const DataType& dt) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyDataRef>, MPyDataRef>::type MPyData_New(Data& data) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyDataRef>, MPyDataRef>::type MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt = DataType::NullValue()) const;
/// Creates a DataType capsule. GIL must be held.
/// 
/// @param dt         Pointer of DataType to capsule.
/// @return           New DataType capsule or empty object if exception indicator is set.
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<MPyDataTypeRef>, MPyDataTypeRef>::type MPyDataType_New(const DataType& dt) const;
			inline Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n = nullptr) const;
			inline Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions() const;
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::enable_if<STD_IS_REPLACEMENT(same,T,DataType), ResultPtr<DataType>>::type>, typename std::enable_if<STD_IS_REPLACEMENT(same,T,DataType), ResultPtr<DataType>>::type>::type ParseArgument(const CPyRef& args, Int32 argIndex, Bool isOptional = false) const;
			template <typename T> inline Result<T> ParseRef(const CPyRef& args, Int32 argIndex, Bool isOptional = false) const;
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::enable_if<STD_IS_REPLACEMENT(reference,T)||STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>, typename std::enable_if<STD_IS_REPLACEMENT(reference,T)||STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false) const;
/// if T is not NativePyObject*
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::enable_if<!STD_IS_REPLACEMENT(reference,T)&&!STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>, typename std::enable_if<!STD_IS_REPLACEMENT(reference,T)&&!STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false) const;
			inline Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone = false) const;
			template <typename T> inline Result<T> ParseGeneric(const CPythonLibraryRef& pylib, const CPyRef& args, Int32 argIndex, DataType& dt, Bool unpackData) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetError(const Error& err) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetError(const ErrorPtr& err) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type MaxonConvertAuto(const CPyRef& capsule) const;
			inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected = nullptr, Int* count = nullptr) const;
			inline Result<BaseArray<SourceLocation>> GetCurrentTraceback() const;
			template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<CPyRef>, CPyRef>::type Enum_ToMapperInstance(T enumm) const;
		};
		/// Intermediate helper class for CPythonLibraryInterface.
		template <typename S> class COWFn : public ConstFn<S>
		{
		public:
			COWFn() = default;
			using PrivateBaseClass = ConstFn<S>;
			using PrivateBaseClass::PrivateBaseClass;
			using PrivateBaseClass::PrivateLookupFn;
			static COWFn PrivateLookupFn(CPythonLibraryInterface**);
			operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CPythonLibraryRef, false>::type&() { return reinterpret_cast<const CPythonLibraryRef&>(this->GetBaseRef()); }
/// Initializes a new library object. Must not be called on the pre-allocated Python instances!
/// 
/// @param[in] librarypath				Path to the Python library.
/// @param[in] createSubLibrary		True to create a sub-interpreter.
/// @return												OK on success.
			inline Result<void> Init(const Url& librarypath, Bool createSubLibrary);
/// Initializes all types after proper initialization. Must not be called on the pre-allocated Python instances!
/// 
/// @return												OK on success.
			inline Result<void> InitTypes();
/// Initializes all builtin modules after initialization. Must not be called on the pre-allocated Python instances!
/// 
/// @return												OK on success.
			inline Result<void> InitBuiltinModules();
/// Initializes Python. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPy_Initialize();
/// Finalizes Python. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPy_Finalize();
/// Initialize a Python module by the information passed in the module definition. GIL must be held.
/// 
/// @param[in] module							Information about the builtin module.
/// @return												Reference 
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyModule_Create(const ModuleDefinition& module);
/// Free all resources and internals of Python.  Must not be called on the pre-allocated Python instances!
/// @param[in] shutdownEngine			Delegate which must execute Py_Finalize. GIL got released.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Free(const Delegate<void()>& shutdownEngine);
/// Should be used whenever the native Python API requires a FILE pointer.
/// Whenever a Python library function takes a FILE pointer it must be guaranteed that a valid FILE object is passed.
/// When Python is for instance compiled with VS2012 and the host application is compiled with VS2013 the FILE object must not be mixed
/// between runtimes (msvcr110.dll != msvcr120.dll). The FILE object must always be from the same runtime.
/// PythonLibrary::FopenNative() and PythonLibrary::fclose() guarantee that always the correct FILE structure is created.
/// 
/// @param[in] name								Name object of fopen(name, ...)
/// @param[in] mode								File mode, like fopen(..., "rb");
/// @return												File object or nullptr on failure.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), FILE_native*, maxon::Result<FILE_native*>>::type FopenNative(const Char* name, const Char* mode);
/// Returns a Python error with an AggregatedError which is aggreated with PythonTracebackErrors.
/// 
/// @param[in] restoreError				True to keep the exception indicator untouched, or False to keep the exception indicator.
/// @return												PythonError.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Error, maxon::Result<Error>>::type LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError);
/// Register a proxy component for virtual-, and non-virtual interfaces and adds the object to the Classes registry.
/// Used internally by the Python counterpart of MAXON_COMPONENT_OBJECT_REGISTER and MAXON_COMPONENT_CLASS_REGISTER to register a Python type.
/// GIL must be held.
/// 
/// @param[in] type								Python type which represents the implementation.
/// @param[in] registryId					Optional ID to which registry the object should be published to, can be empty.
/// @param[in] baseAndInterfaceIds	Definition object with information about the baseclasses and interfaces the type implements.
/// @param[in] cid								ID of the object, e.g. "net.maxon.iohandler.gzip"
/// @param[in] printErrors				True if the error of a failed Python function should be printed to the console, otherwise false.
/// 															If false, all exceptions within the overwritten functions must be handled for exceptions properly.
/// @param[in] kind								KIND type of the class.
/// @param[in] loc								Location information where the object got registered from.
/// @param[in] createObject				True to create and publish a new instance in the registry instead of the class.
/// 															True for MAXON_COMPONENT_OBJECT_REGISTER, and false for MAXON_COMPONENT_CLASS_REGISTER.
/// @param[in] dtOfObject					Necessary information of which type the ObjectRef instance is.
/// @return												MPyDataRef of the new class object.
			inline Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject);
/// Returns true when Python has been initialized, otherwise False.
/// 
/// @return												True or False.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPy_IsInitialized();
/// Return the version of this Python interpreter. The value is available to Python code as sys.version.
/// 
/// @return												Version string.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPy_GetVersion();
/// Return the platform identifier for the current platform. The value is available to Python code as sys.platform.
/// 
/// @return												Platform string.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPy_GetPlatform();
/// Return the official copyright string The value is available to Python code as sys.copyright.
/// 
/// @return												Copright string.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPy_GetCopyright();
/// Return an indication of the compiler used to build the current Python version.
/// The value is available to Python code as part of the variable sys.version.
/// 
/// @return												Copright string.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPy_GetCompiler();
/// Return information about the sequence number and build date and time of the current
/// Python interpreter instance. The value is available to Python code as part of the variable sys.version.
/// 
/// @return												Build info.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPy_GetBuildInfo();
/// This function should be called before Py_Initialize() is called for the first time.
/// @param[in] name								Name for the current program.
			inline Result<void> CPy_SetProgramName(const String& name);
/// Set the default "home" directory, that is, the location of the standard Python libraries.
/// @param[in] name								Name for the current program.
			inline Result<void> CPy_SetPythonHome(const Url& name);
/// Return the program name set with Py_SetProgramName(), or the default.
/// @return												Program name.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type CPy_GetProgramName();
/// Return the default "home", that is, the value set by a previous call to Py_SetPythonHome().
/// @return												Python home.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type CPy_GetPythonHome();
/// Executes a Python module by its name. GIL must be held.
/// 
/// @param[in] name								Name of the module.
/// @return												True on success, otherwise false. Exception indicator is cleared before function returns.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type ExecuteModule(const String& name);
/// Private. Create caller context object which contains a pointer to this object. The context gets passed to all
/// C-functions as the first self parameter. This is used in PrivateExtractCPythonLibrary{XX} to achieve the convenient
/// wrapping method for C++ functions. GIL must be held.
/// 
/// @return												New caller context.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyCallerContextRef, maxon::Result<MPyCallerContextRef>>::type CPyCallerContext_New();
/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] fp									File pointer where to read the source from.
/// @param[in] filename						Path of the file.
/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags);
/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] url								Url where the source is read from.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags);
/// Executes the Python source code from a source string. If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
/// 
/// @param[in] code								Python source code.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags);
/// Execute Python source code from fp in the context specified by the objects globals and locals with the compiler flags specified by flags.
/// locals must be a dictionary; locals can be any object that implements the mapping protocol. The parameter start specifies the start token that should be used to parse the source code.If the function fails,
/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
///
/// @param[in] fp									File pointer where to read the source from.
/// @param[in] filename						Path of the file.
/// @param[in] start							Key start like PY_FILE_INPUT
/// @param[in] globals						Dict object.
/// @param[in] locals							Any object that implements the mapping protocol.
/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyObject*, maxon::Result<NativePyObject*>>::type CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags);
/// Enters the interactive loop of the Python interpreter. If an exception occurrs, it stays in the loop. Only a sys.exit() will
/// exit the function with OK. Raises exceptions only for internal errors. GIL must be held.
/// 
/// @param[in] fp									File stream of the input stream, normally stdin.
/// @param[in] filename						Name of the interactive loop.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
/// @return												OK on success, and sys.exit().
			inline Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags);
/// Ensure that the current thread is ready to call the Python C API regardless of the current state of Python, or of the global interpreter lock.
/// See https://docs.python.org/3/c-api/init.html#c.PyGILState_Ensure for more information.
/// @return												GIL state.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), PYGILSTATE, maxon::Result<PYGILSTATE>>::type CPyGilState_Ensure();
/// Release any resources previously acquired. After this call, Python's state will be the same as it was prior to the corresponding CPyGILState_Ensure() call. GIL must be held.
/// See https://docs.python.org/3/c-api/init.html#c.PyGILState_Release for more information.
/// 
/// @param[in] state							GIL state.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyGilState_Release(PYGILSTATE state);
/// Returns the current thread state object.
/// 
/// @return												Thread state object or nullptr if no thread state object is available.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyThreadState*, maxon::Result<NativePyThreadState*>>::type CPyGILState_GetThisThreadState();
/// Swap the current thread state with the passed one. 
///
/// @param state    Thread State to swap with.
/// @return         Old thread state.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyThreadState*, maxon::Result<NativePyThreadState*>>::type CPyThreadState_Swap(NativePyThreadState* state);
/// Get the dictionary of the current thread state.
///
/// @return         Dict of the current thread state.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyThreadState_GetDict();
/// Parse and compile a given Python source code returning the resulting code object. GIL must be held.
/// 
/// @param[in] code								Python source code.
/// @param[in] filename						Filename of the code object and might appear in the traceback or SyntaxError exception messages.
/// @param[in] start							Start token.
/// @param[in] flags							Optional compiler flags. Can be nullptr.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyCodeRef, maxon::Result<CPyCodeRef>>::type CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags = nullptr);
/// Runs the garbage collector of Python. GIL must be held.
/// 
/// @return												Number of items collected
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type CPyGC_Collect();
/// Returns the line number of a code object with a given instruction.
/// 
/// @param[in] codeObject					Code object.
/// @param[in] x									Instruction in bytes.
/// @return												Line number or -1 on failure.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32, maxon::Result<Int32>>::type CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x);
/// Returns the internal DataType capsule of a maxon.DataType object. GIL must be held.
/// 
/// @param[in] obj								Object of type maxon.DataType.
/// @return												DataType capsule. Can be safely casted to MPyDataType
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type UnpackDataType(const CPyRef& obj);
/// Returns the internal Data capsule of a maxon.Data object. GIL must be held.
/// 
/// @param[in] obj								Object of type maxon.Data.
/// @return												Data capsule. Can be safely casted to MPyData
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type UnpackData(const CPyRef& obj);
/// Print a standard traceback to sys.stderr and clear the error indicator. Call this function only when the error indicator is set (Otherwise it will cause a fatal error!).  GIL must be held.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_Print();
/// Clears the error indicator of Python. If the error indicator is not set, the call has no effect. GIL must be held.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_Clear();
/// Checks if the error indicator is set. GIL must be held.
/// 
/// @param[out] type							Private. Exception type.
/// @return												True if the error indicator is set, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyErr_Occurred(CPyRef* type = nullptr);
/// Sets the error indicator. GIL must be held.
/// 
/// @param[in] errorType					Exception type object.
/// @param[in] errorString				Human readbale exception message.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyErr_SetString(const CPyRef& errorType, const Char* errorString = nullptr);
/// Sets the error indicator with a filename and errno. GIL must be held.
///
/// @param[in] errorType					Exception type object.
/// @param[in] errorNumber				Error indicator.
/// @param[in] filename						Filename object.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename);
/// Sets the error indicator. GIL must be held.
///
/// @param[in] errorType					Exception type object.
/// @param[in] errorNumber				Error indicator.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber);
/// Sets the error indicator. GIL must be held.
/// 
/// @param[in] errorType					Exception type object.
/// @param[in] errorString				Human readbale exception message.
/// @return												Always returns an empty CPyRef object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyErr_SetString(const CPyRef& errorType, const String& errorString);
/// Sets the error indicator without a message. GIL must be held.
///
/// @param[in] errorType					Exception type object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_SetNone(const CPyRef& errorType);
/// Retrieve the error indicator into three variables whose addresses are passed. If the error indicator is not set, all three objects are empty.
/// 
/// @param[out] type							Exception type.
/// @param[out] value							Exception value.
/// @param[out] traceback					Traceback object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback);
/// Normalizes the objects, retrieved by CPyErr_Fetched.
/// See https://docs.python.org/3/c-api/exceptions.html#c.PyErr_NormalizeException for more information.
///
/// @param[out] type							Exception type.
/// @param[out] value							Exception value.
/// @param[out] traceback					Traceback object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback);
/// Restores the exception which got retrieved by CPyErr_Fetch.
/// 
/// @param[in] type								Exception type.
/// @param[in] value							Exception value.
/// @param[in] traceback					Traceback object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback);
/// Checks if the current set exception is of a given exception.
/// 
/// @param[in] exc								A given object.
/// @return												True when equal, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyErr_ExceptionMatches(const CPyRef& exc);
/// Checks if the given object is an exception. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is an exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyExceptionClass_Check(const CPyRef& o);
/// Set the pointer of the capsule. GIL must be held.
/// 
/// @param[in] capsule						Capsule object.
/// @param[in] pointer						Set, or overwrite the pointer of the capsule.
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer);
/// Retrieve the pointer stored in the capsule. On failure, returns nullptr. GIL must be held.
/// 
/// @param[in] capsule						Capsule to extract the pointer from.
/// @param[in] name								Name of the capsule. On mismatch, the function returns nullptr.
/// @return												Pointer from capsule.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void*, maxon::Result<void*>>::type CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name);
/// Retrieve the context stored in the capsule, which was set by CPyCapsule_SetContext. On failure, returns nullptr. GIL must be held.
/// 
/// @param[in] capsule						Capsule to extract the context from.
/// @return												Pointer to the capsule.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void*, maxon::Result<void*>>::type CPyCapsule_GetContext(const CPyRef& capsule);
/// Set a context pointer to a capsule. GIL must be held.
/// 
/// @param[in] capsule						Set, or overwrite the pointer of the capsule.
/// @return												Context pointer.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyCapsule_SetContext(const CPyRef& capsule, void* context);
/// Checks if the given object is a capsule. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a capsule.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyCapsule_CheckExact(const CPyRef& o);
/// Checks if the given object is a traceback. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a traceback.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyTraceBack_Check(const CPyRef& o);
/// Checks if the given object is a class. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a class.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyClass_Check(const CPyRef& o);
/// Returns the size of a tuple. GIL must be held. GIL must be held.
/// 
/// @return												Size of the tuple, or -1 if exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), UInt, maxon::Result<UInt>>::type CPyTuple_Size(const CPyRef& tuple);
/// Retrieves an item of a tuple by its index. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
/// @return												Element of the item at the given index, or empty object if exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyTuple_GetItem(const CPyRef& tuple, UInt index);
/// Sets an item in a tuple at a given index. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
/// @param[in] item								Item to set.
/// @return												True on success. Returns false if exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item);
/// Retrieves a slice object from a given slice range. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @param[in] from								Start index (including the object at this given index).
/// @param[in] to									End index (excluding the object at this given index).
/// @return												Slice objector empty object if exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to);
/// Checks if a given object is a tuple. GIL must be held.
/// 
/// @param[in] tuple							Tuple object.
/// @return												True if o is a tuple.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyTuple_CheckExact(const CPyRef& tuple);
/// Checks if a given object has a specific attribute name. Equivalent to getattr(o, "name"). GIL must be held.
/// 
/// @param[in] o									Object to Checks the attribute for.
/// @param[in] attrName						Name of the attribute.
/// @return												True on match, otherwise False.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_HasAttrString(const CPyRef& o, const Char* attrName);
/// Sets the value of the attribute named attrName, for object o, to the value item. GIL must be held.
/// 
/// @param[in] o									Object which will get the attribute.
/// @param[in] name								Name of the attribute.
/// @param[in] item								Value of the attribute.
/// @return												True on success, otherwise False if the exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item);
/// Gets the attribute of an object by an attribute name. GIL must be held.
/// 
/// @param[in] o									Object to get the attribute from.
/// @param[in] name								Name of the attribute.
/// @return												Attribute on success or empty object if attribute could not be found and exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_GetAttrString(const CPyRef& o, const Char* name);
/// Calls an object with optional argument list or a keyword dictionary. GIL must be held.
/// 
/// @param[in] callable_object		Object to call.
/// @param[in] tupleArg						Argument list. Can be empty.
/// @param[in] kw									Dictionary list. Can be empty.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw);
/// Computes a string representation of an object. Equivalent to str(o). GIL must be held.
/// 
/// @param[in] o									Object to stringify.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_Str(const CPyRef& o);
/// Computes a string representation of an object. Equivalent to repr(o). GIL must be held.
/// 
/// @param[in] o									Object to stringify.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_Repr(const CPyRef& o);
/// Gets the internal dictionary of an object. Equivalent to dir(o). GIL must be held.
/// 
/// @param[in] o									Object to get the dictionary from..
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_Dir(const CPyRef& o);
/// Rich compares two objects with each other and returns its result. Equivalent to "o1 op o2". GIL must be held.
/// 
/// @param[in] o1									Left operand.
/// @param[in] o2									Right operand.
/// @return												Result or empty object if the call failed and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid);
/// Computes the hash of an object. Equivalent to hash(o). GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												The hash or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type CPyObject_Hash(const CPyRef& o);
/// Returns true if the object is considered to be true, and false otherwise. This is equivalent to the Python expression 'not not o'. GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												True if the object is true, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_IsTrue(const CPyRef& o);
/// Returns false if the object is considered to be true, and true otherwise. This is equivalent to the Python expression 'not o'. GIL must be held.
/// 
/// @param[in] o									Left operand.
/// @return												True if the object is true, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_Not(const CPyRef& o);
/// Checks if a given object is a callable. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is callable.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyCallable_Check(const CPyRef& o);
/// Returns the length of an object. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												Length or -1 if the exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type CPyObject_Length(const CPyRef& o);
/// Gets the item of an object. Equivalent to getitem(o). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] key								Key object.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_GetItem(const CPyRef& o, const CPyRef& key);
/// Gets the item of an object by an index. Equivalent to getitem(o, intValue). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] index							Int key.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_GetItemInt(const CPyRef& o, Int index);
/// Gets the item of an object by a string. Equivalent to getitem(o, strValue). GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] index							String key.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_GetItemString(const CPyRef& o, const Char* index);
/// Deletes an item of an object by a given key.
/// 
/// @param[in] o									Object.
/// @param[in] key								Object key.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_DelItem(const CPyRef& o, const CPyRef& key);
/// Sets an item to an object at a given key. Equivalent to o[key]. GIL must be held.
/// 
/// @param[in] o									Object.
/// @param[in] key								String key.
/// @param[in] item								Object item.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item);
/// Check if a given object is of a certain type.
/// 
/// @param[in] object							Object to check.
/// @param[in] type								Type object.
/// @return												True on match, otherwise False.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type);
/// Calls an object. Equivalent to o(). GIL must be held.
/// 
/// @param[in] o									Object to call.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_CallFunction(const CPyRef& o);
/// Retrieves an object from the sys module by its name. GIL must be held.
/// 
/// @param[in] name								Name of the object.
/// @return												Result object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPySys_GetObject(const Char* name);
/// Sets an object to the sys module. GIL must be held.
/// 
/// @param[in] name								Name of the object.
/// @param[in] o									Object to set.
/// @return												True on success, or false if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPySys_SetObject(const Char* name, const CPyRef& o);
/// Sets an array of paths to sys.path. GIL must be held.
///
/// @param[in] paths              Array of paths to set. None of the elements must be empty.
/// @return                       OK on success or error, if the exception indicator got set.
			inline Result<void> CPy_SetPath(const BaseArray<Url>& paths);
/// Sets an array of paths to sys.path. GIL must be held.
/// 
/// @param[in] paths							Array of paths to set. None of the elements must be empty.
/// @param[in] add								Mode of the operation.
/// @return												OK on success or error, if the exception indicator got set.
			inline Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add);
/// Sets the arguments to sys.argv.
/// 
/// @param[in] args								New arguments.
/// @param[in] updatepath					Bool to update sys.path, otherwise false.
/// @return												OK on success or error, if the exception indicator got set.
			inline Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath);
/// Returns an array of URLs which are in sys.path.
/// 
/// @return												Array of Url objects.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<Url>, maxon::Result<BaseArray<Url>>>::type CPySys_GetPath();
/// Adds a directory to sys.path and process its .pth files.
/// 
/// @param[in] siteDir						Directory to add.
/// @return												OK on success.
			inline Result<void> CPySite_AddSiteDir(const Url& siteDir);
/// Checks if the given object is a str or a subtype of StringType. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a str.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyUnicode_Check(const CPyRef& o);
/// Converts a given block to a string object. GIL must be held.
/// 
/// @param[in] block							Char block.
/// @return												String object or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyUnicode_FromStringAndSize(const Block<const Char>& block);
/// Converts a string object to a string. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												String or error if the exception indicator got set.
			inline Result<String> CPyUnicode_AsString(const CPyRef& str);
/// Retrieves the pointer to a chary array of a string object. The char array is alive as long as the string object
/// is alive. Until the string object gets deleted, the char array will be deleted too. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												Pointer to char array, or nullptr if the the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const Char*, maxon::Result<const Char*>>::type CPyUnicode_AsCString(const CPyRef& str);
/// Gets the size of a string. GIL must be held.
/// 
/// @param[in] str								String object.
/// @return												Length or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type CPyUnicode_GetLength(const CPyRef& str);
/// Gets the item of a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError);
/// Gets the item of a dictionary by a given key string. 
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key string.
/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError);
/// Sets an item to a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @param[in] item								Value item.
/// @return               True on sucess, or false if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item);
/// Deletes an item from a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @param[in] key								Key object.
/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyDict_DelItem(const CPyRef& dict, const CPyRef& key);
/// Determines if #dict contains the key #p.
/// 
/// @param[in] dict Dict object.
/// @param[in] key Key object.
/// @return True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CONTAINS, maxon::Result<CONTAINS>>::type CPyDict_Contains(const CPyRef& dict, const CPyRef& key);
/// Removes all elements from the dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyDict_Clear(const CPyRef& dict);
/// Goes to the next element in the dictionary, starting from a given index.
/// 
/// @param[in] dict								Dict object.
/// @param[in,out] pos						Index start and gets incremented by one when the function leaves.
/// @param[in] key								Key object.
/// @param[in] value							Value object.
/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value);
/// Gets all keys of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of keys.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_Keys(const CPyRef& dict);
/// Gets all values of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of values.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_Values(const CPyRef& dict);
/// Gets all items of a dictionary in a list. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												List of items.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_Items(const CPyRef& dict);
/// Return the number of items in the dictionary. This is equivalent to len(p) on a dictionary. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												Number of items.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type CPyDict_Size(const CPyRef& dict);
/// Gets a copy of a given dictionary. Does not make a deepcopy. GIL must be held.
/// 
/// @param[in] dict								Dict object.
/// @return												Number of items.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyDict_Copy(const CPyRef& dict);
/// Creates a new list of a certain size. GIL must be held.
/// 
/// @param[in] size								Size of the list.
/// @return												New list object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyList_New(UInt size);
/// Checks if a list is a list. No subtype check is performed. GIL must be held.
/// 
/// @param[in] list Object to check.
/// @return True if the object is a list, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_CheckExact(const CPyRef& list);
/// Clears a list.
/// 
/// @param[in] list The list to clear.
/// @return True if the list has been cleared successfully, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_Clear(const CPyRef& list);
/// Evaluates the length of a list and is equivalent to <tt>len(list)</tt>.
/// 
/// @param[in] list The list to evaluate.
/// @return The length of #list.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type CPyList_Size(const CPyRef& list);
/// Returns the object at #index in a list and is equivalent to <tt>list[index]</tt>..
/// 
/// @param[in] list The list to retrieve the object from.
/// @param[in] index The index of the object to retrieve.
/// @return The object at #index in #list.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyList_GetItem(const CPyRef& list, UInt index);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item);
/// Appends an object to a list and is equivalent to <tt>list.append(item).</tt>.
/// 
/// @param[in, out] list The list to append #item to.
/// @param[in] item The item to append.
/// @return True if #item has been successfully appended, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_Append(const CPyRef& list, const CPyRef& item);
/// Returns a slice of a list and is equivalent to <tt>list[from, to]</tt>.
/// 
/// @param[in] list The list to return a slice from.
/// @param[in] from The starting index of the slice.
/// @param[in] to The ending index of the slice.
/// @return The Python slice object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyList_GetSlice(const CPyRef& list, UInt from, UInt to);
/// Sets a slice of a list and is equivalent to <tt>list[from, to] = item</tt>.
/// 
/// @param[in] list The list to set a slice in.
/// @param[in] from The starting index of the slice.
/// @param[in] to The ending index of the slice.
/// @param[in] item The value of the slice, must be a list or NULL.
/// @return True if #item has been successfully sliced in, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item);
/// Sorts a list and is equivalent to <tt>list.sort()</tt>.
/// 
/// @param[in] list The list to sort.
/// @return True if #list has been successfully sorted, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_Sort(const CPyRef& list);
/// Reverses a list and is equivalent to <tt>list.reverse()</tt>.
/// 
/// @param[in] list The list to reverse.
/// @return True if #list has been successfully reversed, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyList_Reverse(const CPyRef& list);
/// Returns a new Python tuple containing the content of #list and is equivalent to <tt>tuple(list)</tt>.
/// 
/// @param[in] list The list to convert.
/// @return The content of #list as a Python tuple.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyList_AsTuple(const CPyRef& list);
/// Remove the entry in dictionary p which has a key specified by the string key. If key is not in the dictionary, a KeyError is raised.
/// 
/// @param[in] p Dict object.
/// @param[in] key Key object.
/// @return True on success, otherwise false.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyDict_DelItemString(const CPyRef& p, const Char* key);
/// Checks if the given object is a module. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a module.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyModule_Check(const CPyRef& o);
/// Add the given object within the module dictionary with the specified name as key. GIL must be held.
/// @note if a PyTypeObject is passed, then this type should be already ready otherwise IllegalArgumentError will be returned.
/// 
/// @param[in] module							The module object.
/// @param[in] name								The name of the type (only the last part not the full qualified name).
/// @param[in] value							The object to be inserted.
/// @return												@trueIfOtherwiseFalse{value object is correctly added}.
			inline Result<Bool> CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value);
/// Add the given Type Object and make it Ready within the module dictionary. GIL must be held.
/// @note The name used will be set by the value of CPyType_Name (last qualifier of tp_name).
/// 
/// @param[in] module							The module object.
/// @param[in] value							The type object to be inserted.
/// @return												@trueIfOtherwiseFalse{value object is correctly added}.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyModule_AddType(const CPyRef& module, const CPyTypeRef& value);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyModule_GetDict(const CPyRef& module);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value);
/// import
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyImport_ImportModule(const Char* name);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyImport_GetImporter(const CPyRef& path);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyImport_GetModuleDict();
/// Checks if the given object is a type. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a type.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyType_Check(const CPyRef& o);
/// Checks if a type is really a subclass, __subclasscheck__() is not called. An object is not a subtype of its own class. Use CPyObject_IsSubtype instead. GIL must be held.
/// 
/// @param[in] a									Base type.
/// @param[in] b									Subtype type.
/// @return												Returns true if a is a subtype of b.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b);
/// Returns the name of a given type.
/// 
/// @param[in] type								Type object.
/// @return												Name of the type or error if the exception indicator got set.
			inline Result<String> CPyType_GetName(const CPyTypeRef& type);
/// Initializes a type.
/// 
/// @param[in] type								Type object to initialize. 
/// @return												True on success.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyType_Ready(CPyTypeRef& type);
/// Release the global interpreter lock 
/// 
/// @return												Previous state object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), NativePyThreadState*, maxon::Result<NativePyThreadState*>>::type CPyEval_SaveThread();
/// Restores a given thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyEval_RestoreThread(NativePyThreadState* state);
/// Checks if multi-threading for Python is enabled.
/// 
/// @return												True if available.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyEval_ThreadsInitialized();
/// Private. Initializes multi-threading for the Python library. Must not be called on the pre-allocated Python instances!
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyEval_InitThreads();
/// Acquires the GIL for a thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyEval_AcquireThread(NativePyThreadState* state);
/// Releases the GIL for a thread state object.
/// 
/// @param[in] state							Thread state object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CPyEval_ReleaseThread(NativePyThreadState* state);
/// Checks if the given object is a float. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a float.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyFloat_Check(const CPyRef& o);
/// Creates a float object from a Float32.
///
/// @param[in] value							Float32 value.
/// @return												bool object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyFloat_FromFloat32(Float32 value);
/// Creates a float object from a Float64.
///
/// @param[in] value							Float64 value.
/// @return												bool object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyFloat_FromFloat64(Float64 value);
/// Converts a float object to Float64.
/// 
/// @param[in] o									Object to convert.
/// @return												Result or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Float64, maxon::Result<Float64>>::type CPyFloat_AsFloat64(const CPyRef& o);
/// Converts an object to a floating type.
/// 
/// @tparam T											Floating type.
/// @param[in] o									Object to convert.
/// @return												Result value.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T, maxon::Result<T>>::type CPyFloat_As(const CPyRef& o);
/// Converts an object from a Float32 value.
/// 
/// @param[in] o									Float value.
/// @return												Float object.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyFloat_From(std::enable_if_t<STD_IS_REPLACEMENT(same,T,Float32), Float32> o);
/// Converts an object from a Float64 value.
/// 
/// @param[in] o									Float value.
/// @return												Float object.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyFloat_From(std::enable_if_t<STD_IS_REPLACEMENT(same,T,Float64), Float64> o);
/// Checks if the given object is an int or a subtype of PyLong_Type. GIL must be held.
/// 
/// @param[in] o									A given object.
/// @return												True if o is a 
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyLong_Check(const CPyRef& o);
/// Creates a bool object from a Bool.
///
/// @param[in] value							Bool value.
/// @return												bool object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyBool_FromBool(Bool value);
/// Creates an int object from a Int16 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromInt16(Int16 value);
/// Creates an int object from a UInt16 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromUInt16(UInt16 value);
/// Creates an int object from a Int32 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromInt32(Int32 value);
/// Creates an int object from a UInt32 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromUInt32(UInt32 value);
/// Creates an int object from a Int64 value.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromInt64(Int64 value);
/// Creates an int object from a UInt64 value. GIL must be held.
///
/// @param[in] value							Int value.
/// @return												Int object.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_FromUInt64(UInt64 value);
/// Converts an object to an Int16 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int16, maxon::Result<Int16>>::type CPyLong_AsInt16(const CPyRef& o);
/// Converts an object to an UInt16 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), UInt16, maxon::Result<UInt16>>::type CPyLong_AsUInt16(const CPyRef& o);
/// Converts an object to an Int32 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32, maxon::Result<Int32>>::type CPyLong_AsInt32(const CPyRef& o);
/// Converts an object to an UInt32 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), UInt32, maxon::Result<UInt32>>::type CPyLong_AsUInt32(const CPyRef& o);
/// Converts an object to an Int64 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int64, maxon::Result<Int64>>::type CPyLong_AsInt64(const CPyRef& o);
/// Converts an object to an UInt64 value. GIL must be held.
///
/// @param[in] o									Object to convert.
/// @return												Integer value, or -1 if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), UInt64, maxon::Result<UInt64>>::type CPyLong_AsUInt64(const CPyRef& o);
/// Converts an object to type T. GIL must be held.
/// 
/// @tparam T											Integral type.
/// @param[in] o									Object to convert.
/// @return												Result value.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), T, maxon::Result<T>>::type CPyLong_As(const CPyRef& o);
/// Converts an object from an Int32 value. GIL must be held.
/// 
/// @param[in] o									Int value.
/// @return												Int object.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_From(std::enable_if_t<std::is_same<T, Int32>::value, Int32> o);
/// Converts an object from an Int64 value. GIL must be held.
/// 
/// @param[in] o									Int64 value.
/// @return												Int object.
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyLong_From(std::enable_if_t<std::is_same<T, Int64>::value, Int64> o);
/// Checks if the given object is a numeric object. GIL must be held.
/// 
/// @param[in] o									Object to check.
/// @return												True if an object is a numeric value.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type CPyNumber_Check(const CPyRef& o);
/// Creates a function capsule that encapsulates a reflection::Function pointer.
/// 
/// @param[in] func								Function pointer to encapsulate.
/// @return												New function capsule or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyFunctionRef, maxon::Result<MPyFunctionRef>>::type MPyFunction_New(const reflection::Function* func);
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @param[in] map								HashMap<Data, Data> reference to encapsulate. A copy will be done.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyHashMapRef, maxon::Result<MPyHashMapRef>>::type MPyHashMap_New(const HashMap<Data, Data>& map);
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @param[in] map								HashMap<Data, Data> reference to encapsulate.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyHashMapRef, maxon::Result<MPyHashMapRef>>::type MPyHashMap_New(HashMap<Data, Data>&& map);
/// Creates a HashMap capsule that encapsulates a HashMap<Data, Data> pointer.
/// 
/// @tparam KEY										Type of the Key. The type should be convertible to a Data.
/// @tparam VALUE									Type of the Value. The type should be convertible to a Data.
/// @param[in] map								HashMap<KEY, VALUE> reference to encapsulate. A copy will be done.
/// @return												New HashMap capsule or empty object if the exception indicator got set.
			template <typename KEY, typename VALUE> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyHashMapRef, maxon::Result<MPyHashMapRef>>::type MPyHashMap_New(HashMap<KEY, VALUE>& map);
/// Creates a member capsule that encapsulates a reflection::Member pointer.
/// 
/// @param[in] member							Member pointer to encapsulate.
/// @return												New member capsule or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyMemberRef, maxon::Result<MPyMemberRef>>::type MPyMember_New(const reflection::Member* member);
/// Set a custom memory allocator. See https://docs.python.org/3/c-api/memory.html#c.PyMem_SetAllocator
			inline Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator);
/// Creates a class capsule that encapsulates a reflection::Member pointer.
/// 
/// @param[in] cls								Class pointer to encapsulate.
/// @return												New class capsule or empty object if the exception indicator got set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyClassRef, maxon::Result<MPyClassRef>>::type MPyClass_New(const reflection::Class* cls);
/// Returns a mutable pointer to a DebugFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												DebugFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_DebugFlag();
/// Returns a mutable pointer to a VerboseFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												VerboseFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_VerboseFlag();
/// Returns a mutable pointer to a InteractiveFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												InteractiveFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_InteractiveFlag();
/// Returns a mutable pointer to a InspectFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												InspectFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_InspectFlag();
/// Returns a mutable pointer to a OptimizeFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												OptimizeFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_OptimizeFlag();
/// Returns a mutable pointer to a NoSiteFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												NoSiteFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_NoSiteFlag();
/// Returns a mutable pointer to a BytesWarningFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												BytesWarningFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_BytesWarningFlag();
/// Returns a mutable pointer to a FrozenFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												FrozenFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_FrozenFlag();
/// Returns a mutable pointer to a IgnoreEnvironmentFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												IgnoreEnvironmentFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_IgnoreEnvironmentFlag();
/// Returns a mutable pointer to a DontWriteBytecodeFlag. Can be nullptr if the flag is not available in this Python version.
///
/// @return												DontWriteBytecodeFlag flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_DontWriteBytecodeFlag();
/// Returns a mutable pointer to a NoUserSiteDirectory. Can be nullptr if the flag is not available in this Python version.
///
/// @return												NoUserSiteDirectory flag
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int32*, maxon::Result<Int32*>>::type CPy_NoUserSiteDirectory();
/// Returns the BaseException.
///
/// @return												The BaseException exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_BaseException();
/// Returns the Exception.
///
/// @return												The Exception exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_Exception();
/// Returns the StopIteration.
///
/// @return												The StopIteration exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_StopIteration();
/// Returns the GeneratorExit.
///
/// @return												The GeneratorExit exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_GeneratorExit();
/// Returns the StandardError.
///
/// @return												The StandardError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_StandardError();
/// Returns the ArithmeticError.
///
/// @return												The ArithmeticError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ArithmeticError();
/// Returns the LookupError.
///
/// @return												The LookupError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_LookupError();
/// Returns the AssertionError.
///
/// @return												The AssertionError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_AssertionError();
/// Returns the AttributeError.
///
/// @return												The AttributeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_AttributeError();
/// Returns the EOFError.
///
/// @return												The EOFError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_EOFError();
/// Returns the FloatingPointError.
///
/// @return												The FloatingPointError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_FloatingPointError();
/// Returns the EnvironmentError.
///
/// @return												The EnvironmentError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_EnvironmentError();
/// Returns the IOError.
///
/// @return												The IOError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_IOError();
/// Returns the OSError.
///
/// @return												The OSError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_OSError();
/// Returns the ImportError.
///
/// @return												The ImportError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ImportError();
/// Returns the IndexError.
///
/// @return												The IndexError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_IndexError();
/// Returns the KeyError.
///
/// @return												The KeyError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_KeyError();
/// Returns the KeyboardInterrupt.
///
/// @return												The KeyboardInterrupt exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_KeyboardInterrupt();
/// Returns the MemoryError.
///
/// @return												The MemoryError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_MemoryError();
/// Returns the NameError.
///
/// @return												The NameError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_NameError();
/// Returns the OverflowError.
///
/// @return												The OverflowError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_OverflowError();
/// Returns the RuntimeError.
///
/// @return												The RuntimeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_RuntimeError();
/// Returns the NotImplementedError.
///
/// @return												The NotImplementedError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_NotImplementedError();
/// Returns the SyntaxError.
///
/// @return												The SyntaxError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_SyntaxError();
/// Returns the IndentationError.
///
/// @return												The IndentationError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_IndentationError();
/// Returns the TabError.
///
/// @return												The TabError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_TabError();
/// Returns the ReferenceError.
///
/// @return												The ReferenceError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ReferenceError();
/// Returns the SystemError.
///
/// @return												The SystemError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_SystemError();
/// Returns the SystemExit.
///
/// @return												The SystemExit exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_SystemExit();
/// Returns the TypeError.
///
/// @return												The TypeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_TypeError();
/// Returns the UnboundLocalError.
///
/// @return												The UnboundLocalError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnboundLocalError();
/// Returns the UnicodeError.
///
/// @return												The UnicodeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnicodeError();
/// Returns the UnicodeEncodeError.
///
/// @return												The UnicodeEncodeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnicodeEncodeError();
/// Returns the UnicodeDecodeError.
///
/// @return												The UnicodeDecodeError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnicodeDecodeError();
/// Returns the UnicodeTranslateError.
///
/// @return												The UnicodeTranslateError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnicodeTranslateError();
/// Returns the ValueError.
///
/// @return												The ValueError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ValueError();
/// Returns the ZeroDivisionError.
///
/// @return												The ZeroDivisionError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ZeroDivisionError();
/// Returns the WindowsError.
///
/// @return												The WindowsError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_WindowsError();
/// Returns the BufferError.
///
/// @return												The BufferError exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_BufferError();
/// Returns the MemoryErrorInst.
///
/// @return												The MemoryErrorInst exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_MemoryErrorInst();
/// Returns the Warning.
///
/// @return												The Warning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_Warning();
/// Returns the UserWarning.
///
/// @return												The UserWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UserWarning();
/// Returns the DeprecationWarning.
///
/// @return												The DeprecationWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_DeprecationWarning();
/// Returns the PendingDeprecationWarning.
///
/// @return												The PendingDeprecationWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_PendingDeprecationWarning();
/// Returns the SyntaxWarning.
///
/// @return												The SyntaxWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_SyntaxWarning();
/// Returns the RuntimeWarning.
///
/// @return												The RuntimeWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_RuntimeWarning();
/// Returns the FutureWarning.
///
/// @return												The FutureWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_FutureWarning();
/// Returns the ImportWarning.
///
/// @return												The ImportWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_ImportWarning();
/// Returns the UnicodeWarning.
///
/// @return												The UnicodeWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_UnicodeWarning();
/// Returns the BytesWarning.
///
/// @return												The BytesWarning exception.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyConstRef, maxon::Result<CPyConstRef>>::type CPyExc_BytesWarning();
/// Returns the CPyNullItype of CPyNullImporter.
/// @return												Type of CPyNullImporter.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyNullImporter_Type();
/// Returns the Ctype of CPySuper.
/// @return												Type of CPySuper.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPySuper_Type();
/// Returns the type of CPyBool.
/// @return												Type of CPyBool.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyBool_Type();
/// Returns the CPtype of CPyObject.
/// @return												Type of CPyObject.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyObject_Type();
/// Returns the CPtype of CPyModule.
/// @return												Type of CPyModule.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyModule_Type();
/// Returns the CPtype of CPyUnicode.
/// @return												Type of CPyUnicode.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyUnicode_Type();
/// Returns the type of CPyLong.
/// @return												Type of CPyLong.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyLong_Type();
/// Returns the Ctype of CPyFloat.
/// @return												Type of CPyFloat.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyFloat_Type();
/// Returns the Ctype of CPyTuple.
/// @return												Type of CPyTuple.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyTuple_Type();
/// Returns the type of CPyList.
/// @return												Type of CPyList.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyList_Type();
/// Returns the type of CPyDict.
/// @return												Type of CPyDict.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyDict_Type();
/// Returns the Ctype of CPyClass.
/// @return												Type of CPyClass.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyClass_Type();
/// Returns the CPyTrtype of CPyTraceBack.
/// @return												Type of CPyTraceBack.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyTraceBack_Type();
/// Returns the Ctype of CPySlice.
/// @return												Type of CPySlice.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPySlice_Type();
/// Returns the type of CPyType.
/// @return												Type of CPyType.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyType_Type();
/// Returns the CPyMemtype of CPyMemoryView.
/// @return												Type of CPyMemoryView.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyMemoryView_Type();
/// Converts a string with a specific encoding and stores the content for the lifetime of the Python interpreters runtime.
/// Some functions in Python need a string that stays alive for the duration of the Pythons interpreter.
///
/// @param[in] str								String to convert.
/// @param[in] encoding						Encoding to use.
/// @return												Pointer to the first array of the string sequence. Can be casted to the corresponding code unit type.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), const PyChar*, maxon::Result<const PyChar*>>::type ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size = nullptr);
/// Private.
			inline Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type);
/// Registers a lambda for back- and forth conversions of certain DataTypes.
/// 
/// @param[in] dt									DataType the converters can handle.
/// @param[in] f1									Lambda or function to convert a Python object to a Data object.
/// @param[in] f2									Lambda or function which converts a Data object to a Python object.
/// @return												OK on success.
			inline Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2);
			template <typename T> inline Result<void> RegisterBuiltinConverter(const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<T>& f2);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Url, maxon::Result<Url>>::type GetSpecialPath(SPECIALPATH anonymous_param_1);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type MPyDataCapsule_Type();
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyData_Type();
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyTypeConstRef, maxon::Result<CPyTypeConstRef>>::type CPyCapsule_Type();
/// Private.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type PrivateGetCurrentCallerContext();
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type MPyDataType_ToMapperInstance(const CPyRef& capsule);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type MPyData_ToMapperInstance(const MPyDataRef& capsule);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule);
			inline Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type);
			inline Result<CPyRef> GetAssociatedDataType(const DataType& dt);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), DelegatePyObject_FromData<>*, maxon::Result<DelegatePyObject_FromData<>*>>::type GetConverterPyObject_FromData(const DataType& dt);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyDataRef, maxon::Result<MPyDataRef>>::type MPyData_New(Data& data);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyDataRef, maxon::Result<MPyDataRef>>::type MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt = DataType::NullValue());
/// Creates a DataType capsule. GIL must be held.
/// 
/// @param dt         Pointer of DataType to capsule.
/// @return           New DataType capsule or empty object if exception indicator is set.
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), MPyDataTypeRef, maxon::Result<MPyDataTypeRef>>::type MPyDataType_New(const DataType& dt);
			inline Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n = nullptr);
			inline Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions();
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename std::enable_if<STD_IS_REPLACEMENT(same,T,DataType), ResultPtr<DataType>>::type, maxon::Result<typename std::enable_if<STD_IS_REPLACEMENT(same,T,DataType), ResultPtr<DataType>>::type>>::type ParseArgument(const CPyRef& args, Int32 argIndex, Bool isOptional = false);
			template <typename T> inline Result<T> ParseRef(const CPyRef& args, Int32 argIndex, Bool isOptional = false);
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename std::enable_if<STD_IS_REPLACEMENT(reference,T)||STD_IS_REPLACEMENT(pointer,T), Result<T>>::type, maxon::Result<typename std::enable_if<STD_IS_REPLACEMENT(reference,T)||STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false);
/// if T is not NativePyObject*
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename std::enable_if<!STD_IS_REPLACEMENT(reference,T)&&!STD_IS_REPLACEMENT(pointer,T), Result<T>>::type, maxon::Result<typename std::enable_if<!STD_IS_REPLACEMENT(reference,T)&&!STD_IS_REPLACEMENT(pointer,T), Result<T>>::type>>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false);
			inline Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone = false);
			template <typename T> inline Result<T> ParseGeneric(const CPythonLibraryRef& pylib, const CPyRef& args, Int32 argIndex, DataType& dt, Bool unpackData);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetError(const Error& err);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetError(const ErrorPtr& err);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type MaxonConvertAuto(const CPyRef& capsule);
			inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected = nullptr, Int* count = nullptr);
			inline Result<BaseArray<SourceLocation>> GetCurrentTraceback();
			template <typename T> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), CPyRef, maxon::Result<CPyRef>>::type Enum_ToMapperInstance(T enumm);
		};
		template <typename ST> struct FnHelper : public std::conditional<
		maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
		COWFn<typename LibraryInterface::Hxx1::template FnHelper<ST>::type>,
		typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename LibraryInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename LibraryInterface::Hxx1::template FnHelper<ST>::type>>::type
		> { };
	};
	class CPythonLibraryInterface::Hxx1::Reference :
#ifdef DOXYGEN
	public FnDoxy<CPythonLibraryRef>
#else
	public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CPythonLibraryInterface, maxon::StrongRefHandler, CPythonLibraryRef>>>>
#endif
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CPythonLibraryInterface, maxon::StrongRefHandler, CPythonLibraryRef>>>>);
		using NonConst = typename Super::ReferenceClass;
	};

	/// CPythonLibraryRef is the reference class of CPythonLibraryInterface.
	class CPythonLibraryRef : public CPythonLibraryInterface::Hxx1::Reference
	{
	public:
		MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CPythonLibraryRef, typename CPythonLibraryInterface::Hxx1::Reference);
		using ConstPtr = typename CPythonLibraryInterface::ConstPtr;
	};

	constexpr inline const maxon::Char* DT_NativePyObject_CppName() { return "maxon::py::NativePyObject"; }
	namespace specialtype
	{
		constexpr inline const maxon::Char* DT_Tuple_CppName() { return "maxon::py::specialtype::Tuple"; }
		constexpr inline const maxon::Char* DT_Slice_CppName() { return "maxon::py::specialtype::Slice"; }
		constexpr inline const maxon::Char* DT_BaseArray_CppName() { return "maxon::py::specialtype::BaseArray"; }
	}
}
class PyModuleRef;

struct PyModuleInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PyModuleInterface>::value || LibraryInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PyModuleInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct PyModuleInterface::Hxx1
{
	class Reference;
	using ReferenceClass = PyModuleRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LibraryInterface>;
	/// Intermediate helper class for PyModuleInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(PyModuleInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PyModuleRef, true>::type&() const { return reinterpret_cast<const PyModuleRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PyModuleRef, false>::type&() { return reinterpret_cast<const PyModuleRef&>(this->GetBaseRef()); }
		inline Result<void> GetFunctions3(BaseArray<NativePyCFunctionTable>& functions) const;
		inline Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants) const;
	};
	/// Intermediate helper class for PyModuleInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(PyModuleInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, PyModuleRef, false>::type&() { return reinterpret_cast<const PyModuleRef&>(this->GetBaseRef()); }
		inline Result<void> GetFunctions3(BaseArray<NativePyCFunctionTable>& functions);
		inline Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename LibraryInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename LibraryInterface::Hxx1::template FnHelper<ST>::type, Fn<typename LibraryInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class PyModuleInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<PyModuleRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PyModuleInterface, maxon::StrongRefHandler, PyModuleRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PyModuleInterface, maxon::StrongRefHandler, PyModuleRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// PyModuleRef is the reference class of PyModuleInterface.
class PyModuleRef : public PyModuleInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PyModuleRef, typename PyModuleInterface::Hxx1::Reference);
	using ConstPtr = typename PyModuleInterface::ConstPtr;
};

#ifndef MAXON_COMPILER_GCC
#else
#endif
#endif
