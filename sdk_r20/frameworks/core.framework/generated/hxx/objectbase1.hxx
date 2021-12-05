#if 1
/// @cond INTERNAL

#ifdef MAXON_LARGE_VTABLE
#else
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
#ifdef MAXON_COMPONENT_HASHTABLE
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
/// @endcond

#ifdef MAXON_TARGET_DEBUG
#endif
class GenericClass;

struct ClassInterface::ReferenceClassHelper { using type = GenericClass; };

/// Intermediate helper class for ClassInterface.
template <typename S> class ClassInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	using KIND = ClassInterface::KIND;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericClass, false>::type&() const { return reinterpret_cast<const GenericClass&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericClass, false>::type&() { return reinterpret_cast<const GenericClass&>(this->GetBaseRef()); }
/// Returns the identifier of this object class. Class identifiers are unique
/// and should follow the naming convention
/// TODO: (Ole).
/// @return												Class identifier.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetId() const;
/// Returns the kind of this object class, see KIND.
/// @return												Kind of this object class.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type GetKind() const;
/// Returns a list of all class components. The components are in order of registration.
/// @return												Reference to the list of components.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type GetComponents() const;
/// Returns true if the class has been finalized successfully before.
/// @return												True if the class is finalized.
/// @see Finalize
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsFinalized() const;
/// Returns a block of all interfaces which this class implements. For each interface,
/// the block will also contain its base interfaces. The interfaces will be sorted
/// according to their depth and, at second level, to their ids.
/// @return												Block of all implemented interfaces.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type GetImplementedInterfaces() const;
/// Returns the data type corresponding to the set of implemented interfaces of this class.
/// For an abstract class this will return nullptr.
/// @return												Data type of this class.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type GetDataType() const;
/// Constructs a new instance of this class. This will invoke the constructors of each
/// component in the order of addition, and then the InitComponent functions of each component.
/// When one of the InitComponent functions fails with an error, FreeComponent will be invoked on the
/// previous (already initialized) components, the component destructors will be invoked,
/// the memory will by freed, and Create() returns the error.
///
/// For a singleton class, this doesn't create a new instance, but returns the singleton instance of this class.
/// This instance is automatically created on finalization of the class.
///
/// For an abstract class, this will always return an UnsupportedOperationError.
///
/// @return												Reference to new instance, or an error if the allocation or initialization failed.
	inline Result<ObjectRef> CreateRef() const;
/// Constructs a new instance of this class. This will invoke the constructors of each
/// component in the order of addition, and then the InitComponent functions of each component.
/// When one of the InitComponent functions fails with an error, FreeComponent will be invoked on the
/// previous (already initialized) components, the component destructors will be invoked,
/// the memory will by freed, and Create() returns the error.
///
/// For a singleton class, this doesn't create a new instance, but returns the singleton instance of this class.
/// This instance is automatically created on finalization.
///
/// For an abstract class, this will always return an UnsupportedOperationError.
///
/// @return												Reference to new instance, or an error if the allocation or initialization failed.
///
	inline Result<typename maxon::details::ClassCreateType<typename S::ReferenceClass>::type> Create() const;
/// Returns true if the class implements the interface iref. This means that
/// this class contains a component implementing the interface.
/// @param[in] iref								Interface.
/// @return												True if this class implements the interface.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Implements(const InterfaceReference& iref) const;
/// Returns true if the class implements the interface I. This means that
/// this class contains a component implementing the interface.
/// @tparam I											Interface.
/// @return												True if this class implements the interface I.
	template <typename I> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Implements() const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result. The representation consists of the class identifier prefixed by "class ".
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Deletes an instance of a class. This is automatically invoked if the reference count of the instance reaches zero.
/// @param[in] object							Instance to delete, must not be nullptr.
	static inline void DeleteInstance(const Object* object);
/// Destructs an instance of a class. This is automatically invoked if the reference count of the instance reaches zero.
/// @param[in] object							Instance to destruct, must not be nullptr.
	static inline void DestructInstance(const Object* object);
};
#ifdef DOXYGEN
template <typename REF> class ClassInterface::ConstReferenceFunctionsImplDoxy : public ClassInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ClassInterface.
template <typename S> class ClassInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
/// Adds a component to this class. The class must not yet have been finalized (by invocation of Finalize()).
/// The added component will overwrite the vtables of the interfaces it implements (see InterfaceInfo),
/// but the previous values are stored (in the _supervtable member of ComponentInfo) and used
/// by the Super function of the component implementation.
/// @param[in] component					Component to add.
/// @return												OK on success. In the case of an error, the class hasn't been changed.
/// @see AddComponents
	inline Result<void> AddComponent(const ComponentDescriptor& component) const;
/// Adds all components of class cls to this class.
/// This class must not yet have been finalized (by invocation of Finalize()).
/// The addition is done in the same order as for the original class. Afterwards, cls can be seen as a base class of this class.
/// @param[in] cls								Implementation class of the component to add.
/// @return												OK on success. In the case of an error, the class shouldn't be used.
/// @see AddComponent
	inline Result<void> AddComponents(const GenericClass& cls) const;
/// Finalizes this class so that it can be used afterwards. The class has to be built before by AddComponent().
/// Some internal data will be set-up for the class so that it is ready for use. If you don't invoke
/// Finalize(), it will be done implicitly when an object of the class is instantiated for the first time.
/// @return												OK on success. If an error occurred, the class shouldn't be used.
/// @see AddComponent
	inline Result<void> Finalize() const;
};
#ifdef DOXYGEN
template <typename REF> class ClassInterface::ReferenceFunctionsImplDoxy : public ClassInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ClassInterface.
template <typename S> class ClassInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ClassInterface::COWReferenceFunctionsImplDoxy : public ClassInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct ClassInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class ClassInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<GenericClass>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ClassInterface, maxon::StrongRefHandler, GenericClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ClassInterface, maxon::StrongRefHandler, GenericClass>>>>);
	using NonConst = NonConstRef;
/// Allocates a new ClassInterface object with a given identifier.
/// The new class doesn't contain any components, you have to add them afterwards by AddComponent()
/// or AddComponents(), and to finally invoke Finalize to complete the class.
/// @param[in] cid								Unique identifier for the class.
/// @param[in] kind								Use KIND::SINGLETON for a singleton class or KIND::ABSTRACT for an abstract class.
/// @return												@c true on success, @c false if allocation or initialization failed.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<GenericClass> Create(const Id& cid, KIND kind = KIND::NORMAL);
};

class ClassInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GenericClass is the reference class of ClassInterface.
///
/// A ClassInterface object represents an object class at runtime, see @ref vinterfaces.
/// Such an object class can be published by MAXON_DECLARATION, and it is then typically defined
/// by MAXON_COMPONENT_CLASS_REGISTER.
///
/// A class consists of several components (see ComponentDescriptor), each of which may
/// implement several virtual interfaces (declared by MAXON_INTERFACE). The class itself
/// then implements all interfaces of all of its components. Information about components
/// and interfaces can be obtained from the ClassInfo object returned by GetClassInfo().
///
/// After allocation of a class, you have to add the components of which it shall consist
/// via AddComponent() or AddComponents(). Afterwards, you can invoke Finalize() to make the class
/// ready for use. From then on, only const methods may be invoked on a class. If you use
/// GenericClass or Class to access a class, this is automatically guaranteed as
/// those are const references. If you don't invoke Finalize(), this will be done implicitly
/// when the first instance of the class is allocated.
///
/// The MAXON_COMPONENT_CLASS_REGISTER and MAXON_COMPONENT_OBJECT_REGISTER macros greatly
/// simplify the setup of a class.
///
/// ClassInterface objects are automatically registered at the Classes registry,
/// so with
/// @code
/// Class<MyType> cls = Classes::Get<MyType>("com.foo.class.bar");
/// @endcode
/// you can look for the class with identifier "com.foo.class.bar". @c MyType is the expected reference type
/// of instances of the class.
///
class GenericClass : public ClassInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericClass, Reference);
};

/// @cond INTERNAL

#ifdef MAXON_COMPILER_MSVC
#else
#endif
#if defined(MAXON_COMPILER_MSVC) && (MAXON_COMPILER_MSVC < 1910)
#else
#endif
/// @endcond

/// @cond INTERNAL

/// @endcond

struct Object::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, Object>::value || std::is_same<I, maxon::Object>::value; static I* Cast(Object* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class ObjectRef;

struct Object::ReferenceClassHelper { using type = ObjectRef; };

/// Intermediate helper class for Object.
template <typename S> class Object::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns the class of this object. Each Object holds a strong reference on its class.
/// @return												Class of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>, const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>::type GetClass() const;
/// Returns the class information of this object.
/// @return												Class information of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type GetClassInfo() const;
/// Tests if this Object has the same class as another Object obj.
/// @param[in] obj								Another Object.
/// @return												True if both objects have the same class.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasSameClass(const Object* obj) const;
/// Clones this Object. The result is a reference to a new object of the same class where each component is a copy of the
/// corresponding component of this object (as implemented by the CopyFrom function of components).
/// @return												Clone of this object.
	inline Result<typename S::ReferenceClass> Clone() const;
/// Checks if this object is an instance of the given interface @p I. This is the case if the class
/// of this object has a component which implements @p I.
/// @return												True if this object is an instance of @p I.
	template <typename I> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsInstanceOf() const;
/// Checks if this object is an instance of the given data type. This is the case if the
/// @p type is an object type and if the class of this object implements each interface
/// of the object type.
/// @return												True if this object is an instance of @p type.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsInstanceOf(const DataType* type) const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result. By default, this is the name of the class, followed by \@, followed by the hexadecimal memory address of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Compares this and #other for equality.
/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
/// @param[in] other							Another object.
/// @return												True if both object are equal, false otherwise.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const maxon::Object* other) const;
/// Compares this and #other.
/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
/// @param[in] other							Another object.
/// @return												Result of the comparison.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const maxon::Object* other) const;
/// Returns a hash code for this object.
/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
/// @return												Hash code for this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type GetHashCodeImpl() const;
Bool operator ==(std::nullptr_t) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), nullptr); }
	public:
Bool operator !=(std::nullptr_t) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), nullptr); }
	public:
Bool operator ==(const Object* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
Bool operator !=(const Object* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
Bool operator ==(Object* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
Bool operator !=(Object* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
template <typename T> Bool operator ==(T* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
template <typename T> Bool operator !=(T* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const Object*, const Object*>(this->GetPointer(), ref); }
	public:
/// @cond INTERNAL

/// @endcond

};
#ifdef DOXYGEN
template <typename REF> class Object::ConstReferenceFunctionsImplDoxy : public Object::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for Object.
template <typename S> class Object::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObjectRef, true>::type&() const { return reinterpret_cast<const ObjectRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObjectRef, false>::type&() { return reinterpret_cast<const ObjectRef&>(this->GetBaseRef()); }
/// Initializes the object. This method is invoked implicitly when a new object is created (after @c InitComponent has been invoked for each component).
/// When the initialization fails, the new object is deleted immediately.
/// @return												Success of initialization.
	inline Result<void> InitObject() const;
/// @cond INTERNAL

/// @endcond

};
#ifdef DOXYGEN
template <typename REF> class Object::ReferenceFunctionsImplDoxy : public Object::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for Object.
template <typename S> class Object::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ObjectRef, false>::type&() { return reinterpret_cast<const ObjectRef&>(this->GetBaseRef()); }
/// Initializes the object. This method is invoked implicitly when a new object is created (after @c InitComponent has been invoked for each component).
/// When the initialization fails, the new object is deleted immediately.
/// @return												Success of initialization.
	inline Result<void> InitObject();
/// @cond INTERNAL

/// @endcond

};
#ifdef DOXYGEN
template <typename REF> class Object::COWReferenceFunctionsImplDoxy : public Object::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct Object::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class Object::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ObjectRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<Object, maxon::StrongRefHandler, ObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<Object, maxon::StrongRefHandler, ObjectRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// ObjectRef is the reference class of Object.
///
/// Object is the root of the interface hierarchy of the MAXON API. As a C++ class, each virtual interface
/// is directly derived from Object, but as an interface a virtual interface may have an arbitrary number
/// of base interfaces, all of which have Object as direct or indirect base interface. The
/// interface hierarchy is reflected by the Ptr, ConstPtr and reference classes of the interfaces:
/// They have conversion operators to all base interfaces, and they contain functions
/// for all methods of the interface and its base interfaces.
///
/// Object provides some general inheritance-related functions such as GetClass() and IsInstanceOf(),
/// data-related functions such as Clone() and CopyFrom(), and virtual methods such as ToString()
/// which are required for each Object.
///
/// All Object instances are reference-counted. Within the declaration of an interface you may
/// choose the reference behaviour on invocation of a non-const method (normal, const, copy-on-write).
class ObjectRef : public Object::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ObjectRef, Reference);
};

/// @cond INTERNAL

#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifndef MAXON_COMPONENT_HASHTABLE
#elif defined(MAXON_TARGET_DEBUG)
#else
#endif
/// @endcond

struct ErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ErrorInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(ErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class Error;

struct ErrorInterface::ReferenceClassHelper { using type = Error; };

/// Intermediate helper class for ErrorInterface.
template <typename S> class ErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;

	//----------------------------------------------------------------------------------------
	/// In debug configuration, outputs the message of this error and stops the debugger with a DebugStop().
	/// Does nothing in release configuration.
	/// The function returns this error itself, so it can be chained with a previous error creation:
	/// @code
	/// iferr_throw(FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DbgStop());
	/// return FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DbgStop();
	/// @endcode
	///
	/// @return												This @CLASS (to allow method chaining).
	//----------------------------------------------------------------------------------------
	RefMemberType<S> DbgStop()
	{
		DebugOutput(OUTPUT::DIAGNOSTIC, static_cast<const typename S::ReferenceClass*>(this)->ToString(nullptr)); DebugStop(); return this->PrivateGetRefMember();
	}

	//----------------------------------------------------------------------------------------
	/// Outputs the message of this error and stops the debugger with a CriticalStop().
	/// The function returns this error itself, so it can be chained with a previous error creation:
	/// @code
	/// iferr_throw(FunctionNotImplementedError(MAXON_SOURCE_LOCATION).CritStop());
	/// return FunctionNotImplementedError(MAXON_SOURCE_LOCATION).CritStop();
	/// @endcode
	///
	/// @return												This @CLASS (to allow method chaining).
	//----------------------------------------------------------------------------------------
	RefMemberType<S> CritStop()
	{
		CriticalOutput(static_cast<const typename S::ReferenceClass*>(this)->ToString(nullptr)); return this->PrivateGetRefMember();
	}

	//----------------------------------------------------------------------------------------
	/// Outputs the message of this error.
	/// The function returns this error itself, so it can be chained with a previous error creation:
	/// @code
	/// iferr_throw(FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DiagOutput());
	/// return FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DiagOutput();
	/// @endcode
	///
	/// @return												This @CLASS (to allow method chaining).
	//----------------------------------------------------------------------------------------
	RefMemberType<S> DiagOutput()
	{
		DiagnosticOutput(static_cast<const typename S::ReferenceClass*>(this)->ToString(nullptr)); return this->PrivateGetRefMember();
	}
	
	public:
/// Returns the file location where the error was created.
/// @return												Location (file and line) of the error creation.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type GetLocation() const;
/// Returns the stack trace of this error. This may be empty.
/// @return												Error stack trace.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type GetStackTrace() const;
/// Returns the message of this error.
/// @return												Error message.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetMessage() const;
/// Returns the cause of this error. A cause is itself an error of which the
/// current error is a subsequent error.
/// @return												Cause of this error, this will be a null reference in most cases.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type GetCause() const;
/// Returns the machine that caused this error.
/// @param[out] machine						Receives the machine that caused this error.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetMachine(MachineRef& machine) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type PrivateGetCode() const;
};
#ifdef DOXYGEN
template <typename REF> class ErrorInterface::ConstReferenceFunctionsImplDoxy : public ErrorInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ErrorInterface.
template <typename S> class ErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
/// Sets the file location where the error was created.
/// @param[in] allocLocation			Location (file and line) of the error creation.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) SetLocation(const maxon::SourceLocation& allocLocation) const;
/// Sets the stack trace of this error.
/// @param[in] trace							Error stack trace to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) SetStackTrace(const Block<void* const>& trace) const;
/// Sets the stack trace of this error to the current stack trace. The skip parameter
/// allows to skip the topmost stack frames, which are typically insignificant
/// as they include the SetStackTrace invocation itself.
/// @param[in] skip								Number of stack frames to skip. A reasonable value may
/// 															depend on the compiler and its settings and also on the
/// 															context (e.g., whether the compiler inlined functions
/// 															at the specific call site or not).
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) SetStackTrace(Int skip = STACKTRACE_SKIP) const;
/// Sets the message of this error.
/// @param[in] message						Error message to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) SetMessage(const String& message) const;
/// Sets the cause of this error. A cause is itself an error of which the
/// current error is a subsequent error.
/// @param[in] cause							Cause to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) SetCause(const Error& cause) const;
/// Sets the machine that caused this error.
/// @param[in] machine						Machine that caused this error.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetMachine(const MachineRef& machine) const;
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) PrivateSetCode(Int code) const;
};
#ifdef DOXYGEN
template <typename REF> class ErrorInterface::ReferenceFunctionsImplDoxy : public ErrorInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for ErrorInterface.
template <typename S> class ErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Error, false>::type&() const { return reinterpret_cast<const Error&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Error, false>::type&() { return reinterpret_cast<const Error&>(this->GetBaseRef()); }

protected:
	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the location can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::ReferenceClassHelper::type*>(this) = S::DirectlyReferencedType::ReferenceClassHelper::object::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location and message. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but location and message can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] msg								Error message.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const String& msg)
	{
		*static_cast<typename S::DirectlyReferencedType::ReferenceClassHelper::type*>(this) = S::DirectlyReferencedType::ReferenceClassHelper::object::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetMessage(msg);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but location, message and cause can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] msg								Error message.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const String& msg, const Error& cause)
	{
		*static_cast<typename S::DirectlyReferencedType::ReferenceClassHelper::type*>(this) = S::DirectlyReferencedType::ReferenceClassHelper::object::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetMessage(msg);
		e.SetCause(cause);
	}
	
	public:
/// Sets the file location where the error was created.
/// @param[in] allocLocation			Location (file and line) of the error creation.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) SetLocation(const maxon::SourceLocation& allocLocation);
/// Sets the stack trace of this error.
/// @param[in] trace							Error stack trace to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) SetStackTrace(const Block<void* const>& trace);
/// Sets the stack trace of this error to the current stack trace. The skip parameter
/// allows to skip the topmost stack frames, which are typically insignificant
/// as they include the SetStackTrace invocation itself.
/// @param[in] skip								Number of stack frames to skip. A reasonable value may
/// 															depend on the compiler and its settings and also on the
/// 															context (e.g., whether the compiler inlined functions
/// 															at the specific call site or not).
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) SetStackTrace(Int skip = STACKTRACE_SKIP);
/// Sets the message of this error.
/// @param[in] message						Error message to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) SetMessage(const String& message);
/// Sets the cause of this error. A cause is itself an error of which the
/// current error is a subsequent error.
/// @param[in] cause							Cause to use for this error.
///
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) SetCause(const Error& cause);
/// Sets the machine that caused this error.
/// @param[in] machine						Machine that caused this error.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetMachine(const MachineRef& machine);
	inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) PrivateSetCode(Int code);
};
#ifdef DOXYGEN
template <typename REF> class ErrorInterface::COWReferenceFunctionsImplDoxy : public ErrorInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct ErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class ErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Error>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ErrorInterface, maxon::StrongCOWRefHandler, Error>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ErrorInterface, maxon::StrongCOWRefHandler, Error>>>>);
	using NonConst = NonConstRef;
};

class ErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// Error is the reference class of ErrorInterface.
///
/// ErrorInterface is the base interface for errors. ErrorInterface itself cannot be
/// instantiated, but there are several derived interfaces to indicate specific error
/// conditions such as OutOfMemoryError, NullptrError or IllegalStateError.
///
/// An error typically contains file and line information (GetLocation())
/// and a message (GetMessage()). It may also have a stack trace (GetStackTrace())
/// and a cause (GetCause()), which is another error which caused this error.
///
/// Normally, errors shouldn't be used directly for return types of functions.
/// Instead, you should use <tt>Result<T></tt> which can hold a result value and an error.
/// The macros #iferr and #iferr_return support Result to facilitate error handling.
///
/// Errors are typically created in statements like
/// @code
/// return IllegalStateError(MAXON_SOURCE_LOCATION, "Object already contained in hierarchy."_s);
/// @endcode
/// The usage of MAXON_SOURCE_LOCATION ensures that file and line information is set correctly in the error.
/// The message is optional, and you can also pass a cause as third argument to the constructor.
/// Some error classes may add specific constructors with additional arguments. But errors
/// also support method chaining if you want so set additional values like the stack trace:
/// @code
/// return IllegalStateError(MAXON_SOURCE_LOCATION).SetMessage("Object already contained in hierarchy."_s).SetStackTrace();
/// @endcode
/// To trigger a DebugStop() or CriticalStop() on creation of an error, add DbgStop() or
/// CritStop() at the end of the creation as in
/// @code
/// return IllegalStateError(MAXON_SOURCE_LOCATION).CritStop();
/// @endcode
///
/// The ToString implementation of errors supports the following format statements:
/// - "NoStack" to suppress the output of the call stack.
/// - "NoLocation" to suppress the output of the code location.
/// - "NoCause" to suppress the output of the cause error.
/// - "NoMachine" to suppress the output of the machine. The machine is only printed out if it's not the local machine.
/// - "Class" to print error class.
/// @see @CLANGDUMMY @ref errors
class Error : public ErrorInterface::Reference
{
public:
	Error(maxon::ERROR_OK) { }
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Error, Reference);
};

/// @cond INTERNAL

/// @endcond

#if !defined(MAXON_API) || defined(DOXYGEN)
#endif
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#ifndef MAXON_COMPILER_INTEL
#endif
#endif
