#include "maxon/utilities/detect_win_macros.h"

#ifndef OBJECTBASE_H__
#define OBJECTBASE_H__

#include "maxon/registrybase.h"
#include "maxon/string.h"
#include "maxon/delegate.h"

#define MAXON_LARGE_VTABLE
#define MAXON_COMPONENT_HASHTABLE

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

/// @cond INTERNAL

class DataSerializeReaderRef;
class DataSerializeWriterRef;
class DataSerializeInterface;
class DataDictionary;
class LanguageRef;

class FactoryInterface;
template <typename SIG> class Factory;
template <typename FACTORY, typename SUPER> class FactoryFunctions;

//----------------------------------------------------------------------------------------
/// ComponentInfo is used by ClassInfo to store component-specific information.
//----------------------------------------------------------------------------------------
class ComponentInfo
{
public:
	ComponentInfo() = default;
	~ComponentInfo();

	ComponentInfo(ComponentInfo&&) = default;
	ComponentInfo& operator =(ComponentInfo&&) = default;

	explicit ComponentInfo(const ComponentDescriptor* cd);

	const ComponentDescriptor* _descriptor = nullptr; ///< The component descriptor to which this info belongs.
	Int32 _offset = 0; ///< The offset of the component object within an object's memory.
	Int32 _index = 0; ///< The index of the component within the class (order of addition).
	Int32 _baseIndex = 0; ///< The index of the base component.
	Bool _sharedProxy = false; ///< True for a proxy component which shares its handler with a previous proxy component.
	Pointer<const Generic> _supervtable; ///< Pointer to the super-vtable which stores the method pointers of the class before the component was added.
	Pointer<const Generic> _classProxyHandler; ///< For a class proxy component this points to the proxy handler.

	MAXON_DISALLOW_COPY_AND_ASSIGN(ComponentInfo);
};


// Method tables consist of a sequence of entries, one for each method. The entries have the following layout and follow each other without padding inbetween.
struct MTableEntry
{
	void* ptr; // The function pointer.
	Int offset; // The component offset.
};


//----------------------------------------------------------------------------------------
/// InterfaceInfo is used by ClassInfo to store interface-specific information.
//----------------------------------------------------------------------------------------
class InterfaceInfo
{
public:
#ifdef MAXON_LARGE_VTABLE
	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the vtable for the interface. The vtable contains a method pointer for each interface method.
	/// @return												Pointer to the vtable of the interface.
	//----------------------------------------------------------------------------------------
	MTableEntry* GetMTable()
	{
		return reinterpret_cast<MTableEntry*>(this + 1);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the vtable for the interface. The vtable contains a method pointer for each interface method.
	/// @return												Pointer to the vtable of the interface.
	//----------------------------------------------------------------------------------------
	const MTableEntry* GetMTable() const
	{
		return reinterpret_cast<const MTableEntry*>(this + 1);
	}

#define PRIVATE_MAXON_VTABLE_AT(offset, object) reinterpret_cast<const maxon::MTableEntry*>((const char*) object->_classInfo + offset + 1)

	Bool _valid; ///< Is the info valid, i.e., is the interface implemented by the class?

	Bool PrivateIsValid() const
	{
		return _valid;
	}
#else
	MTableEntry* GetMTable()
	{
		return reinterpret_cast<MTableEntry*>((char*) this + _vtableOffset);
	}

	const MTableEntry* GetMTable() const
	{
		return reinterpret_cast<const MTableEntry*>((const char*) this + _vtableOffset);
	}

#define PRIVATE_MAXON_VTABLE_AT(offset, object) reinterpret_cast<const maxon::InterfaceInfo*>((const char*) object->_classInfo + offset)->GetMTable()

	UInt32 _vtableOffset;

	Bool PrivateIsValid() const
	{
		return _vtableOffset;
	}
#endif
};


//----------------------------------------------------------------------------------------
/// ClassInfo stores interface- and component-related information for a class.
/// There is one ClassInfo object for each ClassInterface object.
///
/// For each implemented interface of the class, the InterfaceInfo can be obtained by GetInterfaceInfo.
/// For each component of the class, the ComponentInfo is retured by GetComponentInfo.
//----------------------------------------------------------------------------------------
class ClassInfo
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the component info for the given component descriptor. The component info has to be present
	/// in the ClassInfo, i.e., a corresponding component has to be added before by AddComponent().
	/// @param[in] d									Component descriptor for which the info shall be obtained. There has to be an info for the descriptor, otherwise the behaviour is undefined.
	/// @return												Corresponding component info.
	//----------------------------------------------------------------------------------------
	const ComponentInfo& PrivateGetComponentInfo(const ComponentDescriptor& d) const;

	static const ComponentInfo& PrivateGetClassProxyComponentInfo(const ObjectInterface* o, const ComponentDescriptor& d, const GenericComponent* comp);

	//----------------------------------------------------------------------------------------
	/// Returns the component info for the given component descriptor. If the component identified by the descriptor
	/// hasn't been added before to the ClassInfo, the result is nullptr.
	/// @param[in] d									Component descriptor for which the info shall be obtained.
	/// @return												Corresponding component info, or nullptr if this doesn't exist in this ClassInfo.
	//----------------------------------------------------------------------------------------
	const ComponentInfo* GetComponentInfo(const ComponentDescriptor& d) const;

	//----------------------------------------------------------------------------------------
	/// Returns the interface info for the interface at the given offset.
	/// Each interface is assigned a distinct offset, which holds for all classes which implement the interface.
	/// @param[in] offset							Interface-specific offset of the InterfaceInfo within the memory of the ClassInfo.
	/// @return												InterfaceInfo for the interface.
	//----------------------------------------------------------------------------------------
	const InterfaceInfo* GetInterfaceInfo(Int offset) const
	{
		DebugAssert((UInt) offset < (UInt) _size);
		return (const InterfaceInfo*) ((char*) this + offset);
	}

protected:
	ClassInfo(const ClassInfoBase& base, Int size);
	~ClassInfo();

public:
	static const UInt HASH_TABLE_SIZE = 389; ///< Hash table size. We can use a prime number here as the time-critical modulo operations are performed at compile-time (if optimizations are enabled).
#ifndef MAXON_TARGET_DEBUG
private:
#endif
	const ClassInfoBase _base;
	const Int _size; ///< Total size of this ClassInfo. This includes the additional memory for the interface table which is located behind the ClassInfo data.
	const Char* _offsetToInfo; ///< Maps from the offset of a component to the component info.
#ifdef MAXON_COMPONENT_HASHTABLE
	ComponentInfo* _componentInfos[HASH_TABLE_SIZE]; ///< Hash table for the component infos, points into a ComponentInfo array which is sorted by hash code.
#endif
	const Char* _classAndComponents; ///< A string which contains the class id followed by a parenthesized list of all components ids (only needed to assist in debugging).

	friend class ClassImpl;
	friend class ClassInterface;
	friend class ObjectInterface;
	friend class ObjectModel;
};


struct CombinedMTableRoot
{
	using Marker = void;

	template <typename I> using FindInterface = void;

	static Bool Init(CombinedMTableRoot* this_, const ClassInfo* info)
	{
		return true;
	}
};

struct VirtualInterfaceVersion;

enum class METHOD_FLAGS : UChar
{
	NONE = 0,
	FORCE_SUPERCALL = 1
} MAXON_ENUM_FLAGS(METHOD_FLAGS);

//----------------------------------------------------------------------------------------
/// InterfaceReference is an EntityReference object which declares a virtual interface.
/// It is created by MAXON_INTERFACE together with code generated by the source processor.
//----------------------------------------------------------------------------------------
class InterfaceReference
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs the InterfaceReference object and adds it to the reference list of the current translation unit.
	/// The MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE macro in the register.cpp file of the current module invokes this constructor.
	/// @param[in] iidWithoutHash			Unique interface identifier without hash suffix.
	/// @param[in] sourceName					Qualified name as used in the source code. This may contain a version namespace.
	/// @param[in] baseInterfaces			Nullptr-terminated array of base interfaces of this interface.
	/// @param[in] methodIds					Pointer to the module's method id table for this interface.
	/// @param[in] methodFlags				Pointer to the method flags for this interface.
	/// @param[in] unit								The translation unit containing the reference.
	/// @param[in] refType						The reference type of the interface (one of the REFERENCE flags of EntityBase::FLAGS).
	//----------------------------------------------------------------------------------------
	InterfaceReference(const Char* iidWithoutHash, const Char* sourceName, const InterfaceReference* const* baseInterfaces, const Char* methodIds, const METHOD_FLAGS* methodFlags, TranslationUnit* unit, EntityBase::FLAGS refType);

	//----------------------------------------------------------------------------------------
	/// Constructs the InterfaceReference object and adds it to the reference list of the current translation unit.
	/// This is used for the special case of an interface with a single base interface to save some bytes of code in the binaries.
	/// The MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE macro in the register.cpp file of the current module invokes this constructor.
	/// @param[in] iidWithoutHash			Unique interface identifier without hash suffix.
	/// @param[in] sourceName					Qualified name as used in the source code. This may contain a version namespace.
	/// @param[in] baseInterface			Single base interface of this interface.
	/// @param[in] methodIds					Pointer to the module's method id table for this interface.
	/// @param[in] methodFlags				Pointer to the method flags for this interface.
	/// @param[in] unit								The translation unit containing the reference.
	/// @param[in] refType						The reference type of the interface (one of the REFERENCE flags of EntityBase::FLAGS).
	//----------------------------------------------------------------------------------------
	InterfaceReference(const Char* iidWithoutHash, const Char* sourceName, const InterfaceReference* baseInterface, const Char* methodIds, const METHOD_FLAGS* methodFlags, TranslationUnit* unit, EntityBase::FLAGS refType);

	//----------------------------------------------------------------------------------------
	/// Returns the unique identifier of the interface. This includes a hash code suffix
	/// @return												Identifier of the interface.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const
	{
		return _super.GetBase().GetId();
	}

	/// @copydoc EntityBase::GetFlags
	EntityBase::FLAGS GetFlags() const
	{
		return _super.GetBase().GetFlags();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the interface without hash code suffix. Different versions of the
	/// interface share this id.
	/// @return												Identifier of the interface without hash code suffix.
	//----------------------------------------------------------------------------------------
	const Id& GetIdWithoutHash() const
	{
		return _idWithoutHash;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the DataType of this interface.
	///
	/// The function may only be called after a successful initialization of the interface.
	/// @return												Runtime data type of this interface.
	//----------------------------------------------------------------------------------------
	const DataType& GetDataType() const
	{
		return _type;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a const reference to the null value of the reference class. This is only valid after a successful initialization.
	/// @return												Const reference to the null value (to be cast into the reference class).
	//----------------------------------------------------------------------------------------
	const Generic* const& GetNullValue() const
	{
		return _nullValue;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the interface reference has been initialized successfully. This means that the reference has been resolved
	/// to an implementation which itself has been initialized successfully, so that it can be used.
	/// @return												True if reference and corresponding implementation have been initialized successfully.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return _super.IsInitialized();
	}

	Bool IsBaseOfOrEqual(const InterfaceReference* other) const;

	const InterfaceDefinition* GetDefinition() const
	{
		return (const InterfaceDefinition*) _super.GetDefinition();
	}

	template <typename I> Bool Is() const
	{
		return *this == I::_interface;
	}

	template <typename I> Bool IsBaseOfOrEqual() const
	{
		return IsBaseOfOrEqual(&I::_interface);
	}

	Block<const InterfaceReference* const> GetBases() const;

	Bool operator ==(const InterfaceReference& other) const
	{
		DebugAssert(_super.GetDefinition() && other._super.GetDefinition());
		return _super.GetDefinition() == other._super.GetDefinition();
	}

	Bool operator !=(const InterfaceReference& other) const
	{
		return !this->operator ==(other);
	}

	Int GetInfoOffset() const
	{
		return _infoOffset;
	}

	String ToString(const FormatStatement* fs = nullptr) const
	{
		return String(_sourceName);
	}

	const Char* GetSourceName() const
	{
		return _sourceName;
	}

	const Char* GetMethodIds() const
	{
		return _methodIds;
	}

	const EntityReference& GetReference() const
	{
		return _super;
	}

	METHOD_FLAGS GetMethodFlags(Int index) const
	{
		return (GetFlags() & EntityBase::FLAGS::EXTENDED) ? _methodFlags[index] : METHOD_FLAGS::NONE;
	}

#ifndef MAXON_TARGET_DEBUG
private:
#endif

	EntityReference _super; ///< EntityReference base object.

	Int _infoOffset; ///< Offset of the InterfaceInfo for this interface within the interface table of ClassInfo objects.
	DataType _type; ///< Pointer to the DataType of this interface.
	const void* const _basesPtr; ///< If SINGLE_BASE flag is set, then this points to a single base interface (as a InterfaceReference*), otherwise to a nullptr-terminated array of base interfaces of this interface.
	const Char* const _methodIds; ///< Pointer to the method id table of the current module for the interface. The table is a null-terminated sequence of null-terminated strings.
	Id _idWithoutHash; ///< The id of this interface without the hash suffix.
	const Char* _sourceName; ///< The qualified name of the interface as used in the source code. It may contain a version namespace.
	const VirtualInterfaceVersion* _version; ///< Pointer to an internal object which is shared by all VirtualInterfaceReferences of the same version.
	Int _depth; ///< The depth of the interface in the interface hierarchy. Object has depth 0, all other interfaces have the maximal depth of their bases plus one.

	const Generic* _nullValue; ///< Pointer to the null value of the implementation (may be nullptr).

	const METHOD_FLAGS* const _methodFlags; ///< Pointer to a block of method flags. Added for S24, only valid if the EXTENDED flag is set.
	void* _reserved;

	friend class ObjectModel;
	friend class InterfaceDefinition;
	friend class VirtualInterfaceInfo;
	friend struct VirtualInterfaceVersion;
	friend class ClassImpl;
};


//----------------------------------------------------------------------------------------
/// NonvirtualMTableReference is an EntityReference object which is used for the nonvirtual method table of interfaces with single implementation.
/// It is created by MAXON_INTERFACE together with code generated by the source processor.
//----------------------------------------------------------------------------------------
class NonvirtualMTableReference
{
public:
	using Initializer = Bool(void*, const ClassInfo*);

	//----------------------------------------------------------------------------------------
	/// Constructs the NonvirtualMTableReference object and adds it to the reference list of the current translation unit.
	/// @param[in] iid								Interface identifier without hash code suffix.
	/// @param[in] nonvirtual					Pointer to the nonvirtual method table of the interface.
	/// @param[in] mtableInit					Function to initialize the method table.
	/// @param[in] unit								The translation unit containing the reference.
	//----------------------------------------------------------------------------------------
	NonvirtualMTableReference(const Char* iid, void* nonvirtual, Initializer* mtableInit, TranslationUnit* unit);

	//----------------------------------------------------------------------------------------
	/// Returns the unique identifier of the interface.
	/// @return												Identifier of the interface.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const
	{
		return _super.GetBase().GetId();
	}

	const EntityReference& GetReference() const
	{
		return _super;
	}

#ifndef MAXON_TARGET_DEBUG
private:
#endif

	EntityReference _super; ///< EntityReference base object.

	void* _nonvirtualTable; ///< Pointer to the method table of the current module for interfaces with single implementation.
	Initializer* _mtableInit; ///< The initializer for the method table for interfaces with single implementation.

	friend class ObjectModel;
};


class InterfaceDefinition
{
public:
	InterfaceDefinition(const InterfaceReference& ref, TranslationUnit* unit, EntityBase::FLAGS flags, const Char* cppName);

	const EntityBase& GetBase() const
	{
		return _super.GetBase();
	}

	inline const Char* GetCppName() const
	{
		return _cppName;
	};

private:
	EntityDefinition _super;
	Int							 _infoOffset;
	const Char*			 _cppName = nullptr;

	friend class InterfaceReference;
	friend class ObjectInterface;
	friend class ObjectModel;
	friend class ClassImpl;
};

class PrivateSuperCallBase
{
public:
	template <typename MTABLE> const MTABLE& Get(const MTABLE& mtable)
	{
		return mtable;
	}

	static PrivateSuperCallBase _instance;

	PrivateSuperCallBase(const ComponentDescriptor& component, const InterfaceReference& intf, Int method);

private:
	PrivateSuperCallBase() = default;

	const InterfaceReference* const _interface = nullptr;
	const Int _method = 0;
	const PrivateSuperCallBase* const _next = nullptr;

	friend class ObjectModel;
	friend class ClassImpl;
	friend class VirtualInterfaceInfo;
};

/// @endcond


//----------------------------------------------------------------------------------------
/// ComponentDescriptor describes a component implementation (created by MAXON_COMPONENT
/// and MAXON_COMPONENT_ONLY_REGISTER) at runtime.
/// It is an EntityDefinition object, the component descriptor can be published as an object via MAXON_DECLARATION.
//----------------------------------------------------------------------------------------
class ComponentDescriptor
{
public:
	// Only needed for MAXON_DECLARATION to initialize a null value.
	ComponentDescriptor();

	~ComponentDescriptor();

	//----------------------------------------------------------------------------------------
	/// Constructs the ComponentDescriptor object and adds it to the definition list of the current translation unit.
	/// Class C is used as implementation class of the component.
	/// @param[in] ctype							Dummy parameter, this is only needed to determine template parameter C.
	/// @param[in] cid								The unique component identifier.
	/// @param[in] unit								The translation unit containing the component implementation.
	/// @param[in] file								Source file name.
	/// @param[in] flags							PROXY may be set here.
	/// @param[in] registry						Dummy parameter to pass the registry.
	/// @tparam C											Implementation class of the component.
	//----------------------------------------------------------------------------------------
	template <typename C, typename REG> ComponentDescriptor(C* ctype, LiteralId&& cid, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags, REG* registry)
		: ComponentDescriptor(std::move(cid), unit, file, flags | C::COMPONENT_FLAGS | C::COMPONENT_FLAGS_EXTRA)
	{
		Construct<C>();
		static_assert(STD_IS_REPLACEMENT(same, C, typename C::ComponentClass), "Component class C has to match the first template parameter of its base class Component<C, ...>.");
		static_assert(STD_IS_REPLACEMENT(same, REG, ::MaxonRegistry) || STD_IS_REPLACEMENT(same, typename REG::EntryType, ComponentDescriptor), "Can't register a component descriptor at a registry with an entry type different from ComponentDescriptor.");
		_registry = REG::GetId();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the component identifier of this descriptor.
	/// @return												Unique identifier.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const
	{
		return _super.GetBase().GetId();
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the component descriptor. This is invoked by the object system after all other
	/// entity objects on which the component depends have been initialized. If the descriptor has been initialized already,
	/// or if such a previous attempt failed, no further initialization is done.
	/// All references to the descriptor object (given by MAXON_DECLARATION) will be initialized, too.
	/// @param[in] cause							Identifier of another entity which caused the initialization of this descriptor. This is only for informative purpose.
	/// @return												Success of initialization.
	//----------------------------------------------------------------------------------------
	Result<void> Initialize(const Id& cause) const
	{
		return const_cast<ComponentDescriptor*>(this)->_super.GetBase().Initialize(cause);
	}

	static const ComponentDescriptor& NullValue()
	{
		return GetZeroRef<ComponentDescriptor>();
	}

	String ToString(const FormatStatement* fs = nullptr) const
	{
		return GetId().ToString(fs);
	}

	const EntityDefinition& GetDefinition() const
	{
		return _super;
	}

	Result<void> (*GetDescribeIO() const) (const DataSerializeInterface&)
	{
		return _describeIO;
	}

	const ComponentDescriptor* GetClassProxy() const
	{
		return _classProxy;
	}

	const Block<const InterfaceReference* const>& GetInterfaces() const
	{
		return _interfaces;
	}

	EntityBase::FLAGS GetFlags() const
	{
		return _super.GetBase().GetFlags();
	}

	Int GetSize() const
	{
		return _size;
	}

private:
	ComponentDescriptor(Bool dummy, const ComponentDescriptor& base);

	ComponentDescriptor(LiteralId&& cid, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Used by the constructors to initialize function pointers and other implementation-specific values
	/// from the component implementation class C.
	/// @tparam C											Implementation class of the component.
	//----------------------------------------------------------------------------------------
	template <typename C> void Construct()
	{
		_construct = (void (*) (void*)) &C::_Wrapper::PrivateWrapperConstruct;
		_destruct = (void(*)(void*)) &C::_Wrapper::PrivateWrapperDestruct;
		_init = (Result<void> (*) (void*)) &C::_Wrapper::PrivateWrapperInit;
		_free = (void (*) (void*)) &C::_Wrapper::PrivateWrapperFree;
		_copyFrom = (Result<void> (*) (void*, const void*)) &C::_Wrapper::PrivateWrapperCopyFrom;
		_constructMTable = &C::PrivateConstructMTable;
		_simpleMTableSize = std::is_empty<typename C::PrivateSimpleInterface::MTable>::value ? 0 : SIZEOF(typename C::PrivateSimpleInterface::MTable);
		_initImplementation = &C::_Wrapper::PrivateWrapperInitImplementation;
		_freeImplementation = &C::_Wrapper::PrivateWrapperFreeImplementation;
		_describeIO = &C::_Wrapper::PrivateWrapperDescribeIO;
		_interfaces = C::InterfacesBlock::value;

		if (SIZEOF(C) == SIZEOF(void*))
		{
			_size = 0;
			_alignment = 1;
		}
		else
		{
			_size = SIZEOF(C);
			_alignment = alignof(C);
		}
		_superMTableSize = SIZEOF(typename C::PrivateSuperMTable);
#ifdef MAXON_TARGET_DEBUG
		_hashCode = LIMIT<UInt>::MAX / 2; // will be set later
#endif
		_selfPtrOffset = C::PrivateGetSelfPtrOffset();
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(ComponentDescriptor)

#ifdef MAXON_TARGET_DEBUG
public:
#endif
	/// Base definition object.
	EntityDefinition _super;

	/// Constructor of component.
	void (*_construct) (void* component);

	/// Destructor of component.
	void (*_destruct) (void* component);

	/// Pointer for InitComponent function.
	Result<void> (*_init) (void* component);

	/// Pointer for FreeComponent function.
	void (*_free) (void* component);

	/// Pointer for CopyFrom function.
	Result<void> (*_copyFrom) (void* destComp, const void* srcObject);

	/// Pointer for ConstructMTable function of component implementation class.
	Bool (*_constructMTable) (ClassInfo* info, Int offset, void* supervtable);

	/// Pointer for InitImplementation function of component implementation class.
	Result<void> (*_initImplementation) ();

	/// Pointer for FreeImplementation function of component implementation class.
	void (*_freeImplementation) ();

	/// This function is used to describe the component for I/O operations.
	Result<void> (*_describeIO) (const DataSerializeInterface&);

	/// The list of implemented interfaces (excluding base interfaces).
	Block<const InterfaceReference* const> _interfaces;

	/// Size of component object data.
	Int _size;

	/// Alignment of component object data.
	Int _alignment;

	/// Size of super-vtable of component.
	Int _superMTableSize;

	/// Hash code of component descriptor. This will be less than ClassInfo::HASH_TABLE_SIZE.
	UInt _hashCode;

	/// Offset of the self pointer within the component.
	Int _selfPtrOffset;

	/// Size of the simple method table if this component implements a simple virtual interface, 0 otherwise.
	Int _simpleMTableSize;

	/// Id of a registry at which this component descriptor shall be registered.
	Id _registry;

	/// For a proxy component, this points to the corresponding class proxy component.
	const ComponentDescriptor* _classProxy = nullptr;

	/// Pointer to internal information about the set of implemented methods.
	void* _implementedMethods = nullptr;

	/// Singly-linked list of super calls which are needed by this component.
	mutable const PrivateSuperCallBase* _supercalls;
	// Note: This must not be initialized with nullptr here: Zero-initialization happens at first for global objects anyways,
	// and _supercalls will be overwritten by PrivateSuperCallBase constructors in unspecified order.

	friend class ObjectModel;
	friend class ObjectInterface;
	friend class PrivateSuperCallBase;
	friend class ClassInfo;
	friend class ClassImpl;
	friend class VirtualInterfaceInfo;
	friend struct VirtualInterfaceVersion;
};

template <typename T, Int COUNTER> class IsComplete<Class<T>, COUNTER> : public std::true_type
{
};

template <typename R> class Class;

template <typename TO, typename FROM> using Out = std::is_constructible<TO, FROM>;

namespace details
{
template <typename REF> struct ClassGetNonConst
{
	using type = typename REF::NonConst;
};

template <> struct ClassGetNonConst<ObjectRef>
{
	using type = ObjectRef;
};

template <typename I1, typename I2> using DisableComparison = typename std::enable_if<!(maxon::HasBaseDetector<I1, I2>::value || maxon::HasBaseDetector<I2, I1>::value)>;
}

//----------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------
class ClassInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ClassInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.class");
	MAXON_GENERIC((Out) typename REF = ObjectRef);

public:
	/// An object class is of one of the kinds defined by this enum.
	enum class KIND
	{
		NORMAL,				///< A normal object class.
		SINGLETON,		///< A singleton object class, i.e., a class with exactly one instance. The instance can be obtained with Create().
		ABSTRACT			///< An abstract object class. Create() will return an UnsupportedOperationError.
	} MAXON_ENUM_LIST_CLASS(KIND);

	//----------------------------------------------------------------------------------------
	/// Allocates a new ClassInterface object with a given identifier.
	/// The new class doesn't contain any components, you have to add them afterwards by AddComponent()
	/// or AddComponents(), and to finally invoke Finalize to complete the class.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @param[in] cid								Unique identifier for the class.
	/// @param[in] kind								Use KIND::SINGLETON for a singleton class or KIND::ABSTRACT for an abstract class.
	/// @return												Pointer to a new ClassInterface object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ClassInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const Id& cid, KIND kind = KIND::NORMAL);

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this object class. Class identifiers are unique
	/// and should follow the naming convention
	/// TODO: (Ole).
	/// @return												Class identifier.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the kind of this object class, see KIND.
	/// @return												Kind of this object class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD KIND GetKind() const;

	//----------------------------------------------------------------------------------------
	/// Returns a list of all class components. The components are in order of registration.
	/// @return												Reference to the list of components.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const ComponentInfo* const> GetComponents() const;

	//----------------------------------------------------------------------------------------
	/// Adds a component to this class. The class must not yet have been finalized (by invocation of Finalize()).
	/// The added component will overwrite the vtables of the interfaces it implements (see InterfaceInfo),
	/// but the previous values are stored (in the _supervtable member of ComponentInfo) and used
	/// by the Super function of the component implementation.
	/// @param[in] component					Component to add.
	/// @return												OK on success. In the case of an error, the class hasn't been changed.
	/// @see AddComponents
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddComponent(const ComponentDescriptor& component);

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD void RemoveLastComponent();

	//----------------------------------------------------------------------------------------
	/// Adds all components of class cls to this class.
	/// This class must not yet have been finalized (by invocation of Finalize()).
	/// The addition is done in the same order as for the original class. Afterwards, cls can be seen as a base class of this class.
	/// @param[in] cls								Implementation class of the component to add.
	/// @return												OK on success. In the case of an error, the class shouldn't be used.
	/// @see AddComponent
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddComponents(const Class<>& cls);

	//----------------------------------------------------------------------------------------
	/// Finalizes this class so that it can be used afterwards. The class has to be built before by AddComponent().
	/// Some internal data will be set-up for the class so that it is ready for use. If you don't invoke
	/// Finalize(), it will be done implicitly when an object of the class is instantiated for the first time.
	/// @return												OK on success. If an error occurred, the class shouldn't be used.
	/// @see AddComponent
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Finalize();

	//----------------------------------------------------------------------------------------
	/// Returns true if the class has been finalized successfully before.
	/// @return												True if the class is finalized.
	/// @see Finalize
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsFinalized() const;

	//----------------------------------------------------------------------------------------
	/// Returns a block of all interfaces which this class implements. For each interface,
	/// the block will also contain its base interfaces. The interfaces will be sorted
	/// according to their depth and, at second level, to their ids.
	/// @return												Block of all implemented interfaces.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Block<const InterfaceReference* const>& GetImplementedInterfaces() const;

	//----------------------------------------------------------------------------------------
	/// Returns the data type corresponding to the set of implemented interfaces of this class.
	/// For an abstract class this will return nullptr.
	/// @return												Data type of this class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetDataType() const;

	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<typename maxon::details::ClassGetNonConst<REF>::type> Create() const;

	//----------------------------------------------------------------------------------------
	/// Constructs a new instance of this class. This will invoke the constructors of each
	/// component in the order of addition, and then the InitComponent functions of each component.
	/// When one of the InitComponent functions fails with an error, FreeComponent will be invoked on the
	/// previous (already initialized) components, the component destructors will be invoked,
	/// the memory will by freed, and CreatePointer() returns the error.
	///
	/// For an abstract class, this will always return an UnsupportedOperationError.
	///
	/// The reference counter of the returned object will be zero.
	///
	/// @return												Pointer to the new instance, or an error if the allocation or initialization failed.
	/// @warning This function must not be used for a singleton class, use Create() instead.
	///
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ObjectInterface*> CreatePointer() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the class implements the interface iref. This means that
	/// this class contains a component implementing the interface.
	/// @param[in] iref								An interface.
	/// @return												True if this class implements the interface, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool Implements(const InterfaceReference& iref) const
	{
		return GetValidInterfaceInfo(GetInfo(), iref.GetInfoOffset()) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the class implements the interface I. This means that
	/// this class contains a component implementing the interface.
	/// @tparam I											An interface.
	/// @return												True if this class implements the interface I, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename I> MAXON_FUNCTION Bool Implements() const
	{
		return Implements(I::_interface);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this class is a subclass of #other, i.e., if this class has all components of #other.
	/// @param[in] other							Another class.
	/// @return												True if this class is a subclass of #other, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsSubclassOf(const Class<>& other) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result. The representation consists of the class identifier prefixed by "class ".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the meta data of this class. Usually that's a null reference, but one can set up the meta data
	/// either by InitMetaData() or by adding a function CreateClassMetaData() to the component which is
	/// used to setup a class:
	/// @code
	/// class MyComponent : public Component<MyComponent, MyInterface>
	/// {
	/// 	MAXON_COMPONENT();
	/// public:
	/// 	...
	/// 	static Result<DataDictionary> CreateClassMetaData()
	/// 	{
	/// 		iferr_scope;
	/// 		DataDictionary dict;
	/// 		... // setup dict
	/// 		return dict;
	/// 	}
	/// };
	///
	/// MAXON_COMPONENT_CLASS_REGISTER(MyComponent, "net.maxon.class.myclass");
	/// @endcode
	/// @return												The meta data of this class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataDictionary& GetMetaData() const;

	//----------------------------------------------------------------------------------------
	/// Initializes the meta data (to be returned by GetMetaData()) for this class. You can also
	/// setup the meta data by a function CreateClassMetaData() in a component, see GetMetaData().
	/// @param[in] data								The meta data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InitMetaData(DataDictionary&& data);

	void PrivateInitMetaData(ResultOk<void>&& data)
	{
	}

	template <typename T> void PrivateInitMetaData(Result<T>&& data)
	{
		InitMetaData(std::move(data.GetValue()));
	}

	//----------------------------------------------------------------------------------------
	/// Deletes an instance of a class. This is automatically invoked if the reference count of the instance reaches zero.
	/// @param[in] object							Instance to delete, must not be nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void DeleteInstance(const ObjectInterface* object);

	//----------------------------------------------------------------------------------------
	/// Destructs an instance of a class. This is automatically invoked if the reference count of the instance reaches zero.
	/// @param[in] object							Instance to destruct, must not be nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void DestructInstance(const ObjectInterface* object);

protected:
	//----------------------------------------------------------------------------------------
	/// Copies the component data of objects. This is invoked by ObjectInterface::CopyFrom.
	/// @param[out] dest							Destination object, may be nullptr.
	/// @param[in] src								Source object, may be nullptr.
	/// @return												OK on success. This will report a NullptrError if any of the arguments is nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CopyInstance(ObjectInterface* dest, const ObjectInterface* src);

	//----------------------------------------------------------------------------------------
	/// Returns the ClassInfo object of this class. This is only needed internally.
	/// @return												ClassInfo object of this class. Will never be nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ClassInfo* GetInfo() const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the MTable for the interface having the specified offset.
	/// The memory for the MTable is allocated if necessary.
	/// @param[in] info								ClassInfo object.
	/// @param[in] i									The interface for which the method table shall be obtained.
	/// @return												Pointer to the MTable of the interface, or nullptr if the MTable allocation failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i);

	//----------------------------------------------------------------------------------------
	/// Returns the InterfaceInfo for the interface having the specified offset.
	/// @param[in] info								ClassInfo object of the class in question.
	/// @param[in] offset							Offset of the interface within the interface table.
	/// @return												InterfaceInfo object, or nullptr if the class doesn't implement the interface.
	//----------------------------------------------------------------------------------------
	static inline const InterfaceInfo* GetValidInterfaceInfo(const ClassInfo* info, Int offset)
	{
		if ((UInt) offset >= (UInt) info->_size)
		{
			return nullptr;
		}
		const InterfaceInfo* i = info->GetInterfaceInfo(offset);
		return i->PrivateIsValid() ? i : nullptr;
	}

	MAXON_METHOD Result<Int> AddProxyComponent(const ComponentDescriptor& component, Bool shared);

	friend class ObjectInterface;
	friend class ObjectModel;
	friend class ComponentDescriptor;
	friend class reflection::ProxyImpl;
	template <typename, typename, Bool> friend struct CombinedMTableBase;
	template <typename, typename, typename, typename...> friend class ComponentWithBase;
};



//----------------------------------------------------------------------------------------
/// This macro has to be used for the declaration of a virtual interface to specify
/// the base interfaces. If no specific base interface shall be used, ObjectInterface has to be used.
/// @code
/// class IoHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
/// {
/// 	MAXON_INTERFACE(IoHandlerInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.iohandler");
/// 	...
/// };
/// class InputStreamInterface : MAXON_INTERFACE_BASES(BaseStreamInterface)
/// {
/// 	MAXON_INTERFACE(InputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.inputstream");
/// 	...
/// };
/// @endcode
/// @see MAXON_INTERFACE
//----------------------------------------------------------------------------------------
#define MAXON_INTERFACE_BASES(...) public maxon::ObjectInterface


//----------------------------------------------------------------------------------------
/// MAXON_INTERFACE_SINGLE_IMPLEMENTATION indicates for a virtual interface that there will be
/// exactly one implementation of the interface which allows for more efficient method calls.
/// The method calls will be as efficient as for a non-virtual interface, so in general
/// there is no need to use non-virtual interfaces at all.
/// @code
/// class DimensionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
/// {
/// 	MAXON_INTERFACE(DimensionInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.dimension");
/// 	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
/// 	...
/// };
/// @endcode
/// At runtime it is an error if there is not exactly one registered component which implements
/// the interface.
/// @see MAXON_INTERFACE
//----------------------------------------------------------------------------------------
#define MAXON_INTERFACE_SINGLE_IMPLEMENTATION public: static const maxon::EntityBase::FLAGS INTERFACE_FLAGS = maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION; static maxon::NonvirtualMTableReference _nonvirtualMTable; private:


#define MAXON_INTERFACE_INSTANTIATION(INSTANTIATION, ID, ...)

//----------------------------------------------------------------------------------------
/// MAXON_INTERFACE marks a class declaration as a virtual interface declaration. Virtual
/// interfaces specify a set of methods (tagged by MAXON_METHOD), and they can have
/// several base interfaces (specified by MAXON_INTERFACE_BASES).
///
/// Each interface can be implemented by several components (see MAXON_COMPONENT).
/// A set of components make a class (see ClassInterface), and the interface's methods can then be invoked
/// on an object of a class which has a suitable component.
///
/// @ref vinterfaces describes the declaration and implementation of virtual interfaces in detail.
/// An example is the declaration of InputStreamInterface:
/// @code
/// class InputStreamInterface : MAXON_INTERFACE_BASES(BaseStreamInterface)
/// {
/// 	MAXON_INTERFACE(InputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.inputstream");
/// public:
/// 	MAXON_METHOD Result<Int> ReadEOS(const Block<Byte>& data);
///   ...
/// };
/// @endcode
/// There are also non-virtual interfaces (see MAXON_INTERFACE_NONVIRTUAL). Those only allow a single implementation
/// of the interface for the whole application, while virtual interfaces allow several implementations
/// with the right one being selected by the class of the object on which a method is invoked. In general
/// one should prefer virtual interfaces, if needed you can use MAXON_INTERFACE_SINGLE_IMPLEMENTATION
/// to improve the performance of a method call.
///
/// @param[in] Name								Name of the interface (has to be the same as the surrounding class name).
/// @param[in] REFKIND						One of MAXON_REFERENCE_NORMAL, MAXON_REFERENCE_CONST, MAXON_REFERENCE_COPY_ON_WRITE, MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE.
/// @param[in] ID									The unique identifier of the interface.
/// @see @ref vinterfaces
/// @see MAXON_COMPONENT
/// @see MAXON_METHOD
/// @see MAXON_FUNCTION
/// @see MAXON_INTERFACE_SINGLE_IMPLEMENTATION
/// @see MAXON_INTERFACE_NONVIRTUAL
///
/// @note
/// The base class of a virtual interface in the sense of C++ will always be ObjectInterface.
/// Thus, the interface hierarchy isn't reflected by the C++ class hierarchy.
/// But it is taken into account by the Ptr, ConstPtr and reference classes of virtual interfaces.
///
/// @note The macro itself leaves incomplete code which is completed by the source processor.
/// So you have to place the macro in a header file, because the source processor only scans
/// header files, and you have to include the generated hxx files in the header file.
/// MAXON_INTERFACE must be placed somewhere before the \#include of the first hxx file.
//----------------------------------------------------------------------------------------
#define MAXON_INTERFACE(Name, REFKIND, ID) \
	public: \
		using Interface = Name; \
		static maxon::Id GetInterfaceId() { return maxon::Id(ID); } \
		using IsAllocType = std::true_type; \
		static Name* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const Name& src) { auto r = src.Clone(); return (r == maxon::FAILED) ? nullptr : static_cast<Name*>(r.GetValue()); } \
		static maxon::InterfaceReference _interface; \
		static maxon::NonvirtualInterfaceReference _staticInterface; \
		struct MTable; \
		struct HasBaseDetector; \
		struct Hxx1; \
		struct Hxx2; \
		class ProxyComponent; \
		struct InterfaceMarker; \
		template <typename ST> struct ReferenceFunctions : public maxon::SFINAEHelper<Hxx1, ST>::type::template ReferenceFunctionsHelper<ST> { }; \
		class Reference; \
		using Ptr = maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<Name, maxon::PointerHandler, void>>>>; \
		using ConstPtr = maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const Name, maxon::PointerHandler, void>>>>; \
		inline Ptr GetPtr(); \
		inline ConstPtr GetPtr() const; \
		template <typename DUMMY> static inline maxon::Int PrivateInstantiateNullValueHelper(); \
		static const maxon::EntityBase::FLAGS REFERENCE_KIND = PRIVATE_##REFKIND##_FLAGS; \
		static maxon::InterfaceReference* PrivateGetInterface() { return &_interface; } \
	protected: \
		~Name(); \
	private: \
		static Name* Alloc(MAXON_SOURCE_LOCATION_DECLARATION) { MAXON_ASSERT_STANDARD_LAYOUT(Name); return maxon::details::VirtualCreate<Name>::Create(); } \
		static maxon::Int GetInfoOffset() { return _interface.GetInfoOffset(); } \
		friend class maxon::ClassInterface; \
		friend class maxon::ComponentDescriptor; \
		friend class maxon::StrongCOWRefHandler; \
		Name(); \
		Name(const Name&); \
		void operator =(const Name&); \
		void PrivateCheckClass() { MAXON_CHECK_CLASS(Name); }

/// @cond INTERNAL

namespace details
{
template <typename I, typename = I*(*)()> struct VirtualCreate
{
	static inline I* Create()
	{
		if (STD_IS_REPLACEMENT(same, const I*, decltype(I::NullValuePtr())))
		{
			const I* ptr = (const I*) I::NullValuePtr();
			if (ptr)
				return I::Alloc(MAXON_SOURCE_LOCATION, *ptr);
		}
		return nullptr;
	}
};

template <typename I> struct VirtualCreate<I, decltype(&I::Create)>
{
	static inline I* Create()
	{
		return I::Create();
	}
};

template <typename C> struct ComponentAndWrapper : public C, public C::_Wrapper
{
};
}

// Workaround for MSVC compiler bug:
// "fatal error C1001 : An internal error has occurred in the compiler. (compiler file 'f:\dd\vctools\compiler\cxxfe\sl\p1\c\pm.c', line 724) To work around this problem, try simplifying or changing the program near the locations listed above."
#ifdef MAXON_COMPILER_MSVC // 20180718 - last check with msvc 2017 - 15.7.5

namespace details
{

using ImplementsHelperMemberType = DummyParamType && (*)(Char, DummyReturnType&);
#define PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Name) static maxon::DummyParamType&& Name(maxon::Char, maxon::DummyReturnType&)

template <ImplementsHelperMemberType> class ImplementsHelper;

#define PRIVATE_MAXON_IMPLEMENTS_CHECK(Method) \
	template <typename C> static std::false_type Check##Method(maxon::details::ImplementsHelper<&C::Method>*); \
	template <typename C> static std::true_type Check##Method(...)

}

#define PRIVATE_MAXON_IMPLEMENTS(C, Interface, Method) decltype(Interface::MTable::Check##Method<maxon::details::ComponentAndWrapper<C>>(nullptr))::value

#else

#define PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Name) static const maxon::Char Name

#define PRIVATE_MAXON_IMPLEMENTS_CHECK(Method) \
	template <typename C> static std::false_type Check##Method(decltype(&C::Method)); \
	template <typename C> static std::true_type Check##Method(...)

// As soon as C::Method is inside the decltype this becomes an unevaluated expression and the compiler won't complain about C::Method not being defined (because C::Method is forward declared).
#define PRIVATE_MAXON_IMPLEMENTS(C, Interface, Method) decltype(Interface::MTable::Check##Method<maxon::details::ComponentAndWrapper<C>>((const maxon::Char*) nullptr))::value

#endif

template <typename ST> class SelfPtrBase : public ReferenceBaseCtorDtor<typename ST::type, ST::type::Handler::KIND & (VALUEKIND::POINTER | VALUEKIND::DEEP_CONSTNESS | VALUEKIND::ZERO_INITIALIZED)>
{
public:
	SelfPtrBase() = default;
	SelfPtrBase(const SelfPtrBase&) = delete;
	SelfPtrBase& operator =(const SelfPtrBase&) = delete;

	SelfPtrBase& MakeWritable(Bool resetOnError = true) { return *this; }
};


class ComponentRoot;

//----------------------------------------------------------------------------------------
/// ObjectSuper is used internally as base class of ObjectInterface.
//----------------------------------------------------------------------------------------
class ObjectSuper
{
public:
	const ClassInfo* const _classInfo; ///< Pointer to the ClassInfo of this ObjectInterface. This is used to dispatch method invocations.

	const ComponentRoot* _components[10];

protected:
	explicit ObjectSuper(const ClassInfo* tbl) : _classInfo(tbl) { }
};


template <typename INTERFACE, typename SUPER, Bool INTERFACE_EXISTS> struct CombinedMTableBase : public SUPER
{
	template <typename I> using FindInterface = typename std::conditional<STD_IS_REPLACEMENT(same, I, INTERFACE), CombinedMTableBase, typename SUPER::template FindInterface<I>>::type;
	typename INTERFACE::MTable mtable;

	static Bool Init(CombinedMTableBase* this_, ClassInfo* info)
	{
		if (!SUPER::Init(this_, info))
			return false;
		typename INTERFACE::MTable* t = reinterpret_cast<typename INTERFACE::MTable*>(ClassInterface::GetOrCreateMTable(info, INTERFACE::_interface));
		if (!t)
			return false;
		this_->mtable = *t;
		return true;
	}

	template <typename I> const typename I::MTable& GetMTable() const volatile MAXON_IF_TARGET_DEBUG({ DebugStop(); return GetZeroRef<typename I::MTable>(); }, );

	template <typename I, typename = typename FindInterface<I>::Marker> const typename I::MTable& GetMTable() const
	{
		return static_cast<const FindInterface<I>*>(this)->mtable;
	}
};

template <typename INTERFACE, typename SUPER> struct CombinedMTableBase<INTERFACE, SUPER, true> : public SUPER
{
};

// MSVC 2017 workaround for bugreport: https://gcc.godbolt.org/z/sqJWLw
// CombinedMTableBase has been introduced as a workaround for endless compile time.
template <typename INTERFACE, typename SUPER> struct CombinedMTable : public CombinedMTableBase<INTERFACE, SUPER, !STD_IS_REPLACEMENT(void, typename SUPER::template FindInterface<INTERFACE>)>
{
};

template <typename INTERFACE, typename SUPER> class PrivateComponentBase : public SUPER
{
public:
	using Interface = INTERFACE;
	using Super = SUPER;
	template <typename S> using ReferenceFunctions = typename Interface::template ReferenceFunctions<typename SUPER::template ReferenceFunctions<S>>;
	using Ptr = maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<Interface, maxon::ComponentPointerHandler, PrivateComponentBase>>>>;
	using ConstPtr = maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const Interface, maxon::ComponentPointerHandler, PrivateComponentBase>>>>;
	using SelfPtr = maxon::SelfPtrBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<Interface, maxon::SelfPointerHandler, PrivateComponentBase>>>>;
	template <typename T> struct ComponentHasBase
	{
		static const maxon::Bool value = Interface::HasBaseDetector::template Check<T>::value || SUPER::template ComponentHasBase<T>::value;
	};
	template <typename S> using CombinedMTable = typename Interface::MTable::template CombinedMTable<typename SUPER::template CombinedMTable<S>>;
	template <typename S> struct Wrapper : public Interface::Hxx2::template CWrapper<typename SUPER::template Wrapper<S>>
	{
		static maxon::Bool InitMTables(maxon::ClassInfo* info, maxon::Int offset) { return SUPER::template Wrapper<S>::InitMTables(info, offset) && Interface::MTable::template InitWithBases<Wrapper>(info, offset); }
	};
};


MAXON_MEMBERFUNCTION_DETECTOR(Create);


template <typename IMPL, Bool DEFINE_CREATE = !HasCreate<IMPL>::value && STD_IS_REPLACEMENT(base_of, ComponentRoot, IMPL)> struct StaticHelper : public IMPL
{
	using Implementation = IMPL;

	static Result<const Generic*> _PrivateInitImplementation()
	{
		return nullptr;
	}

	static void _PrivateFreeImplementation()
	{
	}
};

template <typename IMPL> struct StaticHelper<IMPL, true> : public IMPL
{
	using Implementation = StaticHelper;

	static Result<const Generic*> _PrivateInitImplementation()
	{
		return nullptr;
	}

	static void _PrivateFreeImplementation()
	{
	}

	template <typename... ARGS> static Result<typename IMPL::Ref> Create(ARGS&&... args)
	{
		return IMPL::CreateInit(std::forward<ARGS>(args)...);
	}
};

/// @endcond


//----------------------------------------------------------------------------------------
/// ObjectInterface is the root of the interface hierarchy of the MAXON API. As a C++ class, each virtual interface
/// is directly derived from ObjectInterface, but as an interface a virtual interface may have an arbitrary number
/// of base interfaces, all of which have ObjectInterface as direct or indirect base interface. The
/// interface hierarchy is reflected by the Ptr, ConstPtr and reference classes of the interfaces:
/// They have conversion operators to all base interfaces, and they contain functions
/// for all methods of the interface and its base interfaces.
///
/// ObjectInterface provides some general inheritance-related functions such as GetClass() and IsInstanceOf(),
/// data-related functions such as Clone() and CopyFrom(), and virtual methods such as ToString()
/// which are required for each object.
///
/// All ObjectInterface instances are reference-counted. Within the declaration of an interface you may
/// choose the reference behaviour on invocation of a non-const method (normal, const, copy-on-write).
//----------------------------------------------------------------------------------------
class ObjectInterface : protected ObjectSuper
{
	MAXON_INTERFACE(ObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.object");

public:
	using BaseInterface = ObjectInterface; // only needed for the implementation of static methods by MAXON_IMPLEMENTATION

	struct PrivateSuperMTable
	{
		template <typename I> const typename I::MTable& GetMTable() const MAXON_IF_TARGET_DEBUG({ DebugStop(); return GetZeroRef<typename I::MTable>(); }, );
	};

	static const EntityBase::FLAGS INTERFACE_FLAGS = EntityBase::FLAGS::NONE;

	static std::nullptr_t NullValuePtr() { return nullptr; }

	//----------------------------------------------------------------------------------------
	/// Returns the class of this object. Each object holds a strong reference on its class.
	/// @return												Class of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=INTERFACE}
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE = ObjectInterface> MAXON_FUNCTION const maxon::Class<typename INTERFACE::Hxx1::ReferenceClass>& GetClass() const
	{
		return reinterpret_cast<const maxon::Class<typename INTERFACE::Hxx1::ReferenceClass>&>(_classInfo->_base._class);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the class information of this object.
	/// @return												Class information of this object.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const ClassInfo* GetClassInfo() const
	{
		return _classInfo;
	}

	template <typename REF> const ComponentInfo& GetComponentInfoOfSuper(const REF* sptr, OverloadRank0) const MAXON_IF_TARGET_DEBUG({ DebugStop(); return GetZeroRef<ComponentInfo>(); }, );

	template <typename REF, typename = typename REF::Component::ComponentClass> const ComponentInfo& GetComponentInfoOfSuper(const REF* sptr, OverloadRank1) const
	{
		DebugAssert((STD_IS_REPLACEMENT(same, typename REF::Handler, SuperPointerHandler)));
		if (SIZEOF(typename REF::Component) == SIZEOF(void*))
		{
			return _classInfo->PrivateGetComponentInfo(REF::Component::GetDescriptor());
		}
		else
		{
			const ComponentInfo* i = reinterpret_cast<const ComponentInfo* const&>(_classInfo->_offsetToInfo[((const char*) sptr - (const char*) this) - REF::Component::PrivateGetSelfPtrOffset()]);
			return *i;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Tests if this object has the same class as another object obj.
	/// @param[in] obj								Another object.
	/// @return												True if both objects have the same class.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool HasSameClass(const ObjectInterface* obj) const
	{
		return obj && (_classInfo == obj->_classInfo);
	}

	//----------------------------------------------------------------------------------------
	/// Copies the data from a source object to this object. This object needs to have
	/// a matching component for each component of the source (there may be additional components).
	/// Copying is done per component by the CopyFrom function of components.
	/// @param[in] src								Source object.
	/// @return												OK on success (for each component of #src there is a matching component in this object, and copying the component data succeeded).
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const ObjectInterface* src)
	{
		return ClassInterface::CopyInstance(this, src);
	}

	//----------------------------------------------------------------------------------------
	/// Clones this object. The result is a new object of the same class where each component is a copy of the
	/// corresponding component of this object (as implemented by the CopyFrom function of components).
	/// @return												Clone of this object.
	//----------------------------------------------------------------------------------------
	Result<ObjectInterface*> Clone() const;

	//----------------------------------------------------------------------------------------
	/// Clones this object. The result is a reference to a new object of the same class where each component is a copy of the
	/// corresponding component of this object (as implemented by the CopyFrom function of components).
	/// @return												Clone of this object.
	/// @MAXON_ANNOTATION{refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS> MAXON_FUNCTION Result<REFCLASS> Clone() const
	{
		iferr_scope;
		ObjectInterface* o = Clone() iferr_return;
		return REFCLASS(static_cast<typename REFCLASS::ReferencedType*>(o));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this object is an instance of the given interface @p I. This is the case if the class
	/// of this object has a component which implements @p I.
	/// @tparam I											The interface to check.
	/// @return												True if this object is an instance of #I, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename I> MAXON_FUNCTION Bool IsInstanceOf() const
	{
		return ClassInterface::GetValidInterfaceInfo(_classInfo, GetReferencedType<I, I>::type::_interface.GetInfoOffset()) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this object is an instance of the given data type. This is the case if the
	/// @p type is an object type and if the class of this object implements each interface
	/// of the object type.
	/// @param[in] type								The data type to check.
	/// @return												True if this object is an instance of #type, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsInstanceOf(const DataType& type) const
	{
		return type && (Bool)(type->GetValueKind() & (VALUEKIND::VIRTUAL_INTERFACE | VALUEKIND::OBJECT_REF)) && PrivateIsInstanceOf(type);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result. By default, this is the name of the class, followed by \@, followed by the hexadecimal memory address of this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the object. This method is invoked implicitly when a new object is created (after @c InitComponent has been invoked for each component).
	/// When the initialization fails, the new object is deleted immediately.
	/// @param[in] argument						Unused for now.
	/// @return												Success of initialization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitObject(const void* argument);

	//----------------------------------------------------------------------------------------
	/// Handles a generic message. The supported messages are defined by the class of the object.
	/// The default implementation returns UnsupportedOperationError.
	/// @param[in] message						The message identifier.
	/// @param[in] argument						A message-specific argument.
	/// @return												Success of message handling.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> HandleMessage(const InternedId& message, void* argument);

	//----------------------------------------------------------------------------------------
	/// Handles a generic message. The supported messages are defined by the class of the object.
	/// The default implementation returns UnsupportedOperationError.
	/// @param[in] message						The message identifier.
	/// @param[in] argument						A message-specific argument.
	/// @return												Success of message handling.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> HandleConstMessage(const InternedId& message, void* argument) const;

	//----------------------------------------------------------------------------------------
	/// Compares this and #other for equality.
	/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
	/// @param[in] other							Another object.
	/// @return												True if both object are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const maxon::ObjectInterface* other) const; // maxon:: prefix needed as workaround for MSVC name lookup bug

	//----------------------------------------------------------------------------------------
	/// Compares this and #other.
	/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
	/// @param[in] other							Another object.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const maxon::ObjectInterface* other) const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for this object.
	/// @return												Hash code for this object.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION HashInt GetHashCode() const { return GetHashCodeImpl(); } // we use refclass=false to allow the reference class to decide whether to use the hash code of the pointer or the pointee

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for this object.
	/// If you implement this method in a component, make sure to incorporate the result of the super implementation in the result.
	/// @return												Hash code for this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD HashInt GetHashCodeImpl() const;

	MAXON_METHOD HashValue GetHashValueImpl() const;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator ==(std::nullptr_t) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), nullptr); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator !=(std::nullptr_t) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), nullptr); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator ==(const ObjectInterface* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator !=(const ObjectInterface* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator ==(ObjectInterface* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(Bool operator !=(ObjectInterface* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(template <typename T> Bool operator ==(T* ref) const { return RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(template <typename T> Bool operator !=(T* ref) const { return !RefCompare<MAXON_IS_COW_KIND(S::Handler::KIND), true>::template IsEqual<const ObjectInterface*, const ObjectInterface*>(this->GetPointer(), ref); });
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(
		// Disallow == comparison between unrelated reference classes.
		template <typename R, typename = typename maxon::details::DisableComparison<typename S::PrivateReferencedType, typename R::ReferencedType>::type> Bool operator ==(const R& ref) const = delete;
	);
	MAXON_ADD_TO_CONST_REFERENCE_CLASS(
		// Disallow != comparison between unrelated reference classes.
		template <typename R, typename = typename maxon::details::DisableComparison<typename S::PrivateReferencedType, typename R::ReferencedType>::type> Bool operator !=(const R& ref) const = delete;
	);

	// same as IsInstanceOf, but it is assumed that type is a valid object type
	Bool PrivateIsInstanceOf(const DataType& type) const;

	static void PrivateFreeInstance(ObjectInterface* o);

protected:
	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Forwards to ClassInterface::GetOrCreateMTable to make the latter accessible to all interfaces
	/// without their being a friend of ClassInterface.
	/// Returns a pointer to the MTable for the interface having the specified offset.
	/// The memory for the MTable is allocated if necessary.
	/// @param[in] info								The ClassInfo from which the method table shall be obtained.
	/// @param[in] i									The interface for which the method table shall be obtained.
	/// @return												Pointer to the MTable of the interface, or nullptr if the MTable allocation failed.
	//----------------------------------------------------------------------------------------
	static void* PrivateGetOrCreateMTable(ClassInfo* info, const InterfaceReference& i)
	{
		return ClassInterface::GetOrCreateMTable(info, i);
	}

	/// @endcond

	void RemoveReference() const
	{
		if (MAXON_UNLIKELY(System::GetReferenceCounter(this).Dec() == true))
			PrivateFreeInstance(const_cast<ObjectInterface*>(this));
	}

private:
	explicit ObjectInterface(const ClassInfo* tbl) : ObjectSuper(tbl) { }

	static void PrivateDestructInstance(ObjectInterface* o);

	template <typename> friend class ComponentWrapper;
	friend class StrongRefHandler;
	friend class ClassImpl;
};


namespace details
{

template <typename T> class RemoveForwardRef
{
public:
	using type = T;
};

template <typename T> class RemoveForwardRef<ForwardRef<T>>
{
public:
	using type = T;
};

template <typename R, typename SRC, Bool = IsObjectReferenceClass<R>::value && IsObjectReferenceClass<SRC>::value> struct CastHelper;

template <typename R, typename SRC> struct CastHelper<R, SRC, true>
{
	using S = typename RemoveForwardRef<typename std::decay<SRC>::type>::type;
	static const Bool SELF = STD_IS_REPLACEMENT(base_of, SelfPointerHandler, typename S::Handler);
	static_assert(SELF ? !(R::Handler::KIND & VALUEKIND::UNIQUE_REFERENCE)
								: (R::Handler::KIND & VALUEKIND::POINTER) ? true
								: !((R::Handler::KIND ^ S::Handler::KIND) & VALUEKIND::PTR_MASK),
								"Can't cast between references with different reference semantics.");
	static_assert(STD_IS_REPLACEMENT(const, typename R::ReferencedType) >= STD_IS_REPLACEMENT(const, typename S::ReferencedType),
								"Can't cast from a reference to a const object to a reference to a non-const object.");
	using type = typename std::conditional<STD_IS_REPLACEMENT(reference, SRC), const R&, R>::type;
	using AssertCastType = typename std::conditional<SELF, type, typename Substitute<SRC, R>::type>::type;
};

}

//----------------------------------------------------------------------------------------
/// Casts an object reference to an object reference of another interface type. In a debug configuration, it is checked
/// if the referenced object is really an instance of the interface, while there is no check
/// in a release configuration. No new reference is created, so the reference counter won't change.
/// @param[in] ref								Object reference to cast.
/// @tparam R											Reference class to cast to. This must be a reference class of a virtual interface.
/// @return												Casted reference.
//----------------------------------------------------------------------------------------
template <typename R, typename SRC, typename RESULT = typename maxon::details::CastHelper<R, SRC>::AssertCastType> inline RESULT AssertCast(SRC&& ref)
{
	DebugAssert(!ref.GetPointer() || ref.GetPointer()->template IsInstanceOf<typename R::ReferencedType>());
#ifdef MAXON_COMPILER_INTEL
	// add memory fence for intel compiler 16.0 bug which reorders refcounting operations after this call
	CompilerOptimizationBarrier();
#endif
	return reinterpret_cast<RESULT&&>(ref);
}

//----------------------------------------------------------------------------------------
/// Casts an object reference to an object reference of another interface type. If the cast would be invalid
/// because the referenced object isn't an instance of the interface, a null reference is returned.
/// No new reference is created, so the reference counter won't change.
/// @param[in] ref								Object reference to cast.
/// @tparam R											Reference class to cast to. This must be a reference class of a virtual interface.
/// @return												Casted reference.
//----------------------------------------------------------------------------------------
template <typename R, typename SRC, typename RESULT = typename maxon::details::CastHelper<R, SRC>::type> inline RESULT Cast(SRC&& ref)
{
	if (ref.GetPointer() && ref.GetPointer()->template IsInstanceOf<typename R::ReferencedType>())
	{
#ifdef MAXON_COMPILER_INTEL
		// add memory fence for intel compiler 16.0 bug which reorders refcounting operations after this call
		CompilerOptimizationBarrier();
#endif
		return reinterpret_cast<RESULT&&>(ref);
	}
	else
	{
		return NullValue<RESULT>();
	}
}


//----------------------------------------------------------------------------------------
/// Casts a Result containing an object reference to a Result containing the same object reference,
/// but having another reference class. If the cast would be invalid
/// because the referenced object isn't an instance of the interface of the desired reference class, the
/// reference within the returned Result will be set to nullptr.
/// @param[in] src								Result to cast.
/// @tparam R											Reference class to cast to. This must be a reference class of a virtual interface.
/// @return												Casted Result.
//----------------------------------------------------------------------------------------
template <typename R, typename SRC, typename RESULT = typename maxon::details::CastHelper<R, SRC>::type> inline Result<RESULT> Cast(Result<SRC>&& src)
{
	if (src == OK && src.GetValue().GetPointer() && !src.GetValue().GetPointer()->template IsInstanceOf<typename R::ReferencedType>())
	{
		src = Result<SRC>();
	}
	return std::move(reinterpret_cast<Result<RESULT>&>(src));
}


//----------------------------------------------------------------------------------------
/// Casts a Result containing an object reference to a Result containing the same object reference,
/// but having another reference class. In a debug configuration, it is checked
/// if the referenced object is really an instance of the interface, while there is no check
/// in a release configuration. No new reference is created, so the reference counter won't change.
/// @param[in] src								Result to cast.
/// @tparam R											Reference class to cast to. This must be a reference class of a virtual interface.
/// @return												Casted Result.
//----------------------------------------------------------------------------------------
template <typename R, typename SRC, typename RESULT = typename maxon::details::CastHelper<R, SRC>::type> inline Result<RESULT> AssertCast(Result<SRC>&& src)
{
#ifdef MAXON_TARGET_DEBUG
	if (src == OK && src.GetValue().GetPointer() && !src.GetValue().GetPointer()->template IsInstanceOf<typename R::ReferencedType>())
	{
		DebugStop("Unexpected type.");
	}
#endif
	return std::move(reinterpret_cast<Result<RESULT>&>(src));
}


/// @cond INTERNAL

#ifdef MAXON_TARGET_DEBUG
	#define PRIVATE_MAXON_VTABLE(T, object) (*(const T::MTable*) PRIVATE_MAXON_VTABLE_AT(T::_interface._infoOffset, object))
#else
	#define PRIVATE_MAXON_VTABLE(T, object) (*(const T::MTable*) PRIVATE_MAXON_VTABLE_AT(T::_interface.GetInfoOffset(), object))
#endif


template <typename COMPONENT, typename INTERFACE, Int OFFSET, typename HANDLER> class PrivateSuperCall : public PrivateSuperCallBase
{
};

template <typename COMPONENT, typename INTERFACE, Int OFFSET> class PrivateSuperCall<COMPONENT, INTERFACE, OFFSET, SuperPointerHandler>
{
public:
	static PrivateSuperCallBase _instance;
};

template <typename COMPONENT, typename INTERFACE, Int OFFSET> PrivateSuperCallBase PrivateSuperCall<COMPONENT, INTERFACE, OFFSET, SuperPointerHandler>::_instance(COMPONENT::GetDescriptor(), INTERFACE::_interface, OFFSET);


#define PRIVATE_MAXON_SUPERMTABLE(T, object, function) maxon::PrivateSuperCall<typename S::Component, T, offsetof(T::MTable, _##function) / SIZEOF(maxon::MTableEntry), typename S::Handler>::_instance.Get(((const typename S::Component::PrivateSuperMTable*) object->GetComponentInfoOfSuper(this, OVERLOAD_MAX_RANK)._supervtable.GetPointer())->template GetMTable<T>())

#ifndef MAXON_COMPONENT_HASHTABLE
	#define PRIVATE_MAXON_COMPONENT_INFO(object, C) (((const maxon::ObjectSuper*) object)->_classInfo->PrivateGetComponentInfo(C::_descriptor))
#elif defined(MAXON_TARGET_DEBUG)
	#define PRIVATE_MAXON_COMPONENT_INFO(object, C) \
		((((const maxon::ObjectSuper*) object)->_classInfo->_componentInfos[C::_descriptor._hashCode]->_descriptor == &C::_descriptor) \
		 ? *(((const maxon::ObjectSuper*) object)->_classInfo->_componentInfos[C::_descriptor._hashCode]) \
		 : (((const maxon::ObjectSuper*) object)->_classInfo->PrivateGetComponentInfo(C::_descriptor)))
#else
	#define PRIVATE_MAXON_COMPONENT_INFO(object, C) (((const maxon::ObjectSuper*) object)->_classInfo->PrivateGetComponentInfo(C::_descriptor))
#endif

/// @endcond


// TODO: (Ole) 5 is just for xcode debug every compiler needs an own value
static const Int STACKTRACE_SKIP = 1;

class MachineRef;

//----------------------------------------------------------------------------------------
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
///
/// @see @CLANGDUMMY @ref errors
//----------------------------------------------------------------------------------------
class ErrorInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.error");
public:
	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
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
	/// Constructs a new @CLASS for the given source location and message. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but location and message can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] msg								Error message.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const String& msg)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
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
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetMessage(msg);
		e.SetCause(cause);
	}
	);

	MAXON_ADD_TO_CONST_REFERENCE_CLASS(
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
		DebugOutput(OUTPUT::DIAGNOSTIC, static_cast<const typename S::ReferenceClass*>(this)->ToString()); DebugStop(); return this->PrivateGetRefMember();
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
		CriticalOutput(static_cast<const typename S::ReferenceClass*>(this)->ToString()); return this->PrivateGetRefMember();
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
		DiagnosticOutput(static_cast<const typename S::ReferenceClass*>(this)->ToString()); return this->PrivateGetRefMember();
	}
	);

	//----------------------------------------------------------------------------------------
	/// Returns the file location where the error was created.
	/// @return												Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const SourceLocation& GetLocation() const;

	//----------------------------------------------------------------------------------------
	/// Sets the file location where the error was created.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetLocation(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Returns the stack trace of this error. This may be empty.
	/// @return												Error stack trace.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<void* const> GetStackTrace() const;

	//----------------------------------------------------------------------------------------
	/// Sets the stack trace of this error.
	/// @param[in] trace							Error stack trace to use for this error.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetStackTrace(const Block<void* const>& trace);

	//----------------------------------------------------------------------------------------
	/// Sets the stack trace of this error to the current stack trace. The skip parameter
	/// allows to skip the topmost stack frames, which are typically insignificant
	/// as they include the SetStackTrace invocation itself.
	/// @param[in] skip								Number of stack frames to skip. A reasonable value may
	/// 															depend on the compiler and its settings and also on the
	/// 															context (e.g., whether the compiler inlined functions
	/// 															at the specific call site or not).
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void SetStackTrace(Int skip = STACKTRACE_SKIP);

	//----------------------------------------------------------------------------------------
	/// Returns the message of this error.
	/// @return												Error message.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetMessage() const;

	//----------------------------------------------------------------------------------------
	/// Sets the message of this error.
	/// @param[in] message						Error message to use for this error.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMessage(const String& message);

	//----------------------------------------------------------------------------------------
	/// A PartFormatter may be called by FormatMessage() to customize formatting of error message parts
	/// such as data types.
	/// @param[in] language						The language to use, may be left empty.
	/// @param[in] part								The part of an error message to format.
	/// @return												Formatted human-readable string representation of part.
	//----------------------------------------------------------------------------------------
	using PartFormatter = Delegate<String(const LanguageRef& language, const ConstDataPtr& part)>;

	//----------------------------------------------------------------------------------------
	/// Formats the message using the given language and formatter. The default implementation
	/// uses the delegate set by SetMessageDelegate or just GetMessage() if no such delegate has been set.
	/// This method can be overridden to support more human-friendly messages. The implementation may use the partFormatter to
	/// allow for customization of the formatting of certain parts of the error message.
	/// @param[in] language						The language to use, may be left empty.
	/// @param[in] partFormatter			A delegate which is used to format parts of the message such as data types, can be null.
	/// @return												Formatted human-readable message.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const;

	//----------------------------------------------------------------------------------------
	/// Sets a message delegate for this error. You can use the delegate instead of a fixed String message
	/// if you want to customize the message for different languages or allow for more human-friendly
	/// formatting of parts of the message.
	/// @param[in] message						Error message delegate to use for this error.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMessageDelegate(Delegate<String(const LanguageRef& language, const ErrorInterface::PartFormatter& fmt)>&& message);

	//----------------------------------------------------------------------------------------
	/// Formats part using the given formatter and language.
	/// If the formatter is a null object, GlobalToString is used to convert part into a String.
	/// @param[in] language						The language to use, may be left empty.
	/// @param[in] fmt								The part formatter to use, can be null.
	/// @param[in] part								The part of an error message to format.
	/// @return												Formatted human-readable string representation of part.
	//----------------------------------------------------------------------------------------
	template <typename T> static MAXON_FUNCTION String FormatPart(const LanguageRef& language, const ErrorInterface::PartFormatter& fmt, const T& part)
	{
		return fmt ? fmt(language, ConstDataPtr(part)) : GlobalToString(part, nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the cause of this error. A cause is itself an error of which the
	/// current error is a subsequent error.
	/// @return												Cause of this error, this will be a null reference in most cases.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Error& GetCause() const;

	//----------------------------------------------------------------------------------------
	/// Sets the cause of this error. A cause is itself an error of which the
	/// current error is a subsequent error.
	/// @param[in] cause							Cause to use for this error.
	///
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetCause(const Error& cause);

	//----------------------------------------------------------------------------------------
	/// Returns the machine that caused this error.
	/// @param[out] machine						Receives the machine that caused this error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetMachine(MachineRef& machine) const;

	//----------------------------------------------------------------------------------------
	/// Sets the machine that caused this error.
	/// @param[in] machine						Machine that caused this error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMachine(const MachineRef& machine);

	MAXON_METHOD Int PrivateGetCode() const;

	/// @MAXON_ANNOTATION{returnsThis,noResult}
	MAXON_METHOD void PrivateSetCode(Int code);

	MAXON_METHOD void PrivateSetPreallocation(ThreadReferencedError preallocation) const;
	MAXON_METHOD ThreadReferencedError PrivateGetPreallocation() const;
	MAXON_METHOD void PrivateSetDebugError(const Error& cause) const;
};


#include "objectbase1.hxx"


//----------------------------------------------------------------------------------------
/// Each class automatically registers itself at the Classes registry. With
/// @code
/// Class<MyType> cls = Classes::Get<MyType>("com.foo.class.bar");
/// @endcode
/// you can look for the class with identifier "com.foo.class.bar". @c MyType is the expected reference type
/// of instances of the class.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Class<>, Classes, "net.maxon.registry.classes");

namespace Classes
{
	template <typename R> inline const Class<R>& Get(const Id& cls)
	{
		return reinterpret_cast<const Class<R>&>(Registry::Get(cls));
	}
}

using ClassTransformer = Delegate<Result<void>(ClassInterface*)>;

MAXON_REGISTRY(ClassTransformer, ClassTransformers, "net.maxon.registry.classtransformers");


#include "objectbase2.hxx"


/// @cond INTERNAL

//----------------------------------------------------------------------------------------
/// ComponentWrapper is the root class of template chains of Component::Wrapper.
/// It is used to wrap non-static component functions in static functions,
/// pointers to which are standardized.
///
/// @tparam C											Component implementation class.
//----------------------------------------------------------------------------------------
template <typename C> class ComponentWrapper
{
public:
	using Implementation = C;

	static Bool InitMTables(ClassInfo* info, Int offset) { return true; }

private:
	//----------------------------------------------------------------------------------------
	/// @param[in] component					Buffer for component implementation (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void PrivateWrapperConstruct(C* component)
	{
		new (component) C; // with C() MSVC zero-initializes one byte if C is an empty class
	}

	static void PrivateWrapperDestruct(const C* component)
	{
		component->C::~C(); // use C::~C to prevent virtual call
	}

	static Result<void> PrivateWrapperInit(C* component)
	{
		component->PrivateInitBaseSelf(component->self, OVERLOAD_MAX_RANK);
		return component->InitComponent();
	}

	static void PrivateWrapperFree(C* component)
	{
		component->FreeComponent();
	}

	static Result<void> PrivateWrapperCopyFrom(C* dest, const C* src)
	{
		return dest->CopyFrom(*src);
	}

	static Result<void> PrivateWrapperInitImplementation()
	{
		return C::InitImplementation();
	}

	static void PrivateWrapperFreeImplementation()
	{
		C::FreeImplementation();
	}

	static Result<void> PrivateWrapperDescribeIO(const DataSerializeInterface& dsi)
	{
		return C::DescribeIO(dsi);
	}

	friend class ComponentDescriptor;
};


/// @endcond

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT marks a C++ class declaration as a component implementation. Component
/// implementations implement a set of virtual interfaces (see MAXON_INTERFACE),
/// and a set of components in turn defines a class (see ClassInterface).
/// @ref vinterfaces describes the component implementation in detail.
///
/// The basic usage is illustrated by the following example:
/// @code
/// class IoFileOutputStream : public Component<IoFileOutputStream, OutputStreamInterface>
/// {
/// 	MAXON_COMPONENT(NORMAL, OutputStreamBaseClass);
/// public:
/// 	MAXON_METHOD Result<void> Write(const Block<const Byte>& data)
/// 	{
/// 	  ...
/// 	}
/// 	...
/// };
///
/// MAXON_COMPONENT_CLASS_REGISTER(IoFileOutputStream, "net.maxon.class.iofileoutputstream");
/// @endcode
/// The component implementation class has to be publicly derived from the Component class template.
/// The argument to the first template parameter of Component has to repeat the class, the further
/// arguments list the implemented interfaces.
///
/// Optionally you can specify arguments to MAXON_COMPONENT. The KIND argument has to be one of
/// - NORMAL: The normal case. If you don't need to specify base components, you can simply omit this and just write MAXON_COMPONENT().
/// - ABSTRACT: The class defined by MAXON_COMPONENT_CLASS_REGISTER will be an abstract class.
///   Doesn't make sense in combination with MAXON_COMPONENT_ONLY_REGISTER or MAXON_COMPONENT_OBJECT_REGISTER.
/// - SINGLETON: The class defined by MAXON_COMPONENT_CLASS_REGISTER or MAXON_COMPONENT_OBJECT_REGISTER
///   will be a singleton class.
///   Doesn't make sense in combination with MAXON_COMPONENT_ONLY_REGISTER.
/// - FINAL: The component will be marked as final. This means that it is not allowed to add further components
///   to an object class after this component. So you can be sure that no method which is implemented by the final
///   component will be overridden by another component.
/// - FINAL_SINGLETON: Combination of FINAL and SINGLETON.
///   Doesn't make sense in combination with MAXON_COMPONENT_ONLY_REGISTER.
///
/// After the KIND argument you can list base components or base classes. This only makes sense if the component
/// is registered with MAXON_COMPONENT_CLASS_REGISTER or MAXON_COMPONENT_OBJECT_REGISTER: Those macros also
/// define an object class which will contain the component. If you specify base components or base classes,
/// they will be added automatically to the object class before the component itself is added.
///
/// Don't forget to add MAXON_COMPONENT_ONLY_REGISTER, MAXON_COMPONENT_CLASS_REGISTER or
/// MAXON_COMPONENT_OBJECT_REGISTER below the implementation class.
///
/// @param[in] KIND								Either leave empty, or use one of NORMAL, ABSTRACT, SINGLETON, FINAL, FINAL_SINGLETON.
/// @param[in] ...								Optionally you can specify base components or base classes for the object class
/// 															which is defined by MAXON_COMPONENT_CLASS_REGISTER or MAXON_COMPONENT_OBJECT_REGISTER.
/// @see @ref vinterfaces
/// @see MAXON_INTERFACE
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT(KIND, ...) \
	public: \
		static const maxon::Class<>& PrivateGetClass(); \
		static const maxon::ComponentDescriptor _descriptor; \
		template <typename C> friend class maxon::ComponentWrapper; \
		PRIVATE_MAXON_COMPONENT_KIND##KIND \
		PRIVATE_MAXON_COMPONENT_BASES_A(MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__) \
	private:

#define PRIVATE_MAXON_COMPONENT_KIND
#define PRIVATE_MAXON_COMPONENT_KINDNORMAL
#define PRIVATE_MAXON_COMPONENT_KINDABSTRACT static const maxon::ClassInterface::KIND CLASS_KIND = maxon::ClassInterface::KIND::ABSTRACT;
#define PRIVATE_MAXON_COMPONENT_KINDSINGLETON static const maxon::ClassInterface::KIND CLASS_KIND = maxon::ClassInterface::KIND::SINGLETON;
#define PRIVATE_MAXON_COMPONENT_KINDFINAL static const maxon::EntityBase::FLAGS COMPONENT_FLAGS_EXTRA = maxon::EntityBase::FLAGS::FINAL;
#define PRIVATE_MAXON_COMPONENT_KINDFINAL_SINGLETON static const maxon::ClassInterface::KIND CLASS_KIND = maxon::ClassInterface::KIND::SINGLETON; static const maxon::EntityBase::FLAGS COMPONENT_FLAGS_EXTRA = maxon::EntityBase::FLAGS::FINAL;

#define PRIVATE_MAXON_COMPONENT_BASES_A(POPULATED, ...) PRIVATE_MAXON_COMPONENT_BASES_B(POPULATED, __VA_ARGS__)
#define PRIVATE_MAXON_COMPONENT_BASES_B(POPULATED, ...) PRIVATE_MAXON_COMPONENT_BASES_C(POPULATED, __VA_ARGS__)

#define PRIVATE_MAXON_COMPONENT_BASES_C(POPULATED, ...) MAXON_EXPAND(PRIVATE_MAXON_COMPONENT_BASES_##POPULATED(__VA_ARGS__))

#define PRIVATE_MAXON_COMPONENT_BASES_0(...)

namespace details
{
inline Result<void> AddComponentToClass(ClassInterface& cls, const ComponentDescriptor& comp)
{
	return cls.AddComponent(comp);
}

template <typename C> inline Result<void> AddComponentToClass(ClassInterface& cls, const Declaration<ComponentDescriptor, C>& comp)
{
	return cls.AddComponent(comp());
}

inline Result<void> AddComponentToClass(ClassInterface& cls, const Class<>& comp)
{
	return cls.AddComponents(comp);
}

template <typename T, typename C> inline Result<void> AddComponentToClass(ClassInterface& cls, const Declaration<Class<T>, C>& comp)
{
	return cls.AddComponents(comp());
}

}

#define PRIVATE_MAXON_COMPONENT_BASES_HELPER(x, i, a) maxon::details::AddComponentToClass(cls, x) iferr_return;

#define PRIVATE_MAXON_COMPONENT_BASES_1(...) \
	static maxon::Result<void> ConfigureClass(maxon::ClassInterface& cls) \
	{ \
		iferr_scope; \
		MAXON_MAKE_LIST(PRIVATE_MAXON_COMPONENT_BASES_HELPER,,,, __VA_ARGS__) \
		return maxon::OK; \
	}


#define PRIVATE_MAXON_COMPONENT_ID(...) maxon::LiteralId(false, MAXON_SECONDARG(__VA_ARGS__, __VA_ARGS__))
#define PRIVATE_MAXON_COMPONENT_REGISTRY(...) MAXON_FOURTHARG(__VA_ARGS__, , MAXON_FIRSTARG(__VA_ARGS__), maxon::details::ComponentIdentifierMetaData<std::decay<decltype(__VA_ARGS__)>::type>)::Registry
#define PRIVATE_MAXON_COMPONENT_TYPE(DEF, ...) maxon::details::ComponentIdentifierMetaData<std::decay<decltype(MAXON_SECONDARG(__VA_ARGS__, __VA_ARGS__))>::type, MAXON_FOURTHARG(__VA_ARGS__, , MAXON_FIRSTARG(__VA_ARGS__)::EntryType, DEF)>::type

#define PRIVATE_MAXON_COMPONENT_EXTRA_FLAGS

#define PRIVATE_MAXON_COMPONENT_REGISTER(C, TEMPLATE, TYPENAME, FLAGS, UNIT, REGISTRY, ...) \
	PRIVATE_MAXON_REGISTER_CHECK("MAXON_COMPONENT_ONLY_REGISTER"); \
	TEMPLATE const maxon::ComponentDescriptor C::_descriptor((TYPENAME C*) nullptr, PRIVATE_MAXON_COMPONENT_ID(__VA_ARGS__), UNIT, __FILE__, (FLAGS) PRIVATE_MAXON_COMPONENT_EXTRA_FLAGS, (REGISTRY*) nullptr)


#define MAXON_COMPONENT_SIMPLE(I) \
	public: \
		using PrivateSimpleInterface = I; \
		using PrivateComponentWithBase::Get; \
		static ComponentClass* Get(typename I::BaseInterface* object) { return PrivateComponentWithBase::GetNonNull(reinterpret_cast<maxon::ObjectInterface*>(object)); } \
		static const ComponentClass* Get(const typename I::BaseInterface* object) { return PrivateComponentWithBase::GetNonNull(reinterpret_cast<const maxon::ObjectInterface*>(object)); } \
	private:


namespace details
{

template <typename T, typename DEF = void> struct ComponentIdentifierMetaData
{
	using type = typename T::Type;
	using Registry = typename T::Registry;
};

template <typename DEF> struct ComponentIdentifierMetaData<const Char*, DEF>
{
	using type = DEF;
	using Registry = ::MaxonRegistry;
};

template <typename DEF> struct ComponentIdentifierMetaData<LiteralId, DEF>
{
	using type = DEF;
	using Registry = ::MaxonRegistry;
};

template <typename DEF> struct ComponentIdentifierMetaData<Id, DEF>
{
	using type = DEF;
	using Registry = ::MaxonRegistry;
};

}

#define PRIVATE_MAXON_CLASS_REGISTER(C, TEMPLATE, REGISTRY, TYPE, ...) \
	PRIVATE_MAXON_COMPONENT_REGISTER(C, TEMPLATE,, maxon::EntityBase::FLAGS::NONE, &maxon::g_translationUnit, ::MaxonRegistry, __VA_ARGS__); \
	static maxon::ObjectDefinition g_class_##C(PRIVATE_MAXON_COMPONENT_ID(__VA_ARGS__), &C::PrivateConstructClass<TYPE>, (REGISTRY*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
	TEMPLATE const maxon::Class<>& C::PrivateGetClass() \
	{ \
		const void* generic = g_class_##C.PrivateGet(); \
		return generic ? *reinterpret_cast<const maxon::Class<>*>(generic) : maxon::GetZeroRef<maxon::Class<>>(); \
 }

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_ONLY_REGISTER registers a component. Usually you also want to register
/// an object class using the component, then you have to use the macros MAXON_COMPONENT_CLASS_REGISTER
/// or MAXON_COMPONENT_OBJECT_REGISTER instead.
/// @code
/// class WrappedStreamImpl : public Component<WrappedStreamImpl, WrappedStreamInterface>
/// {
/// 	MAXON_COMPONENT();
/// 	...
/// };
///
/// MAXON_COMPONENT_ONLY_REGISTER(WrappedStreamImpl, WrappedStreamComponent);
/// @endcode
/// For the identifier there are three possibilities:
/// - To define the component which shall be addressed by a MAXON_DECLARATION from a header file,
///   you use the name of that MAXON_DECLARATION:<br>
///		<tt>MAXON_COMPONENT_ONLY_REGISTER(WrappedStreamImpl, WrappedStreamComponent);</tt>
/// - You can register the component using a unique identifier, this is typically only used for adapter components:<br>
///   <tt>MAXON_COMPONENT_ONLY_REGISTER(OutdatedTestAdapter21, "net.maxon.component.outdatedtestadapter21");</tt>
/// - You can specify the name of a registry and a unique identifier. In this case the component will also be added
///   to the registry:<br>
///   <tt>MAXON_COMPONENT_ONLY_REGISTER(SomeComponentImpl, MyComponents, "net.maxon.test.somecomponent");</tt>
///
/// @param[in] C									Name of the implementation class.
/// @param[in] ...								Here you have to specify either one or two arguments (similar to MAXON_DECLARATION_REGISTER):
/// 															- If you use a single argument, this has to be the unique identifier to use for the component,
/// 															or the name of a MAXON_DECLARATION if the component shall be the matching definition.
/// 															- If you use two arguments, the first has to name a registry and the second the identifier to use for the component.
/// 															The component will also be added to the registry.
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_ONLY_REGISTER(C, ...) PRIVATE_MAXON_COMPONENT_REGISTER(C,,, maxon::EntityBase::FLAGS::NONE, &maxon::g_translationUnit, PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__), __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_ONLY_REGISTER_TEMPLATE has to be used instead of MAXON_COMPONENT_ONLY_REGISTER
/// if the component class is a template specialization.
/// @see MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_ONLY_REGISTER_TEMPLATE(C, ...) PRIVATE_MAXON_COMPONENT_REGISTER(C, template <>,, maxon::EntityBase::FLAGS::NONE, &maxon::g_translationUnit, PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__), __VA_ARGS__)


//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_CLASS_REGISTER registers a component and also creates an object class
/// which uses the component. This is the usual way to register a component because in most
/// cases you also want to have an object class.
///
/// The object class consists of the base components and base classes (if any) which you have specified
/// in the MAXON_COMPONENT macro, and then the component itself. You can obtain the object class
/// by the GetClass() function of the component implementation class. The object class will also be registered
/// using the identifier given as argument to the macro.
///
/// The identifier is given in the ... argument. There are three possibilities:
/// - You can register the object class using a unique identifier:<br>
///   <tt>MAXON_COMPONENT_CLASS_REGISTER(IoFileOutputStream, "net.maxon.class.iofileoutputstream");</tt>
/// - You can use the name of a MAXON_DECLARATION from a header file if the object class shall be the matching definition
///   for the declaration:<br>
///		<tt>MAXON_COMPONENT_CLASS_REGISTER(IoFileHandler, IoHandlerObjectFileClass);</tt><br>
///   If the MAXON_DECLARATION is within a registry namespace, the object class will also be added to the corresponding registry.
/// - You can specify the name of a registry and a unique identifier. In this case the object class will also be added
///   to the registry:<br>
///   <tt>MAXON_COMPONENT_CLASS_REGISTER(NodesLoopTest, UnitTestClasses, "net.maxon.node.unittest.loop");</tt>
///
/// The component will be registered using the same identifier as the object class.
/// A complete example for the first variant is
/// @code
/// class IoFileOutputStream : public Component<IoFileOutputStream, OutputStreamInterface>
/// {
/// 	MAXON_COMPONENT(NORMAL, OutputStreamBaseClass);
/// public:
/// 	...
/// };
///
/// MAXON_COMPONENT_CLASS_REGISTER(IoFileOutputStream, "net.maxon.class.iofileoutputstream");
/// @endcode
///
/// @param[in] C									Name of the implementation class.
/// @param[in] ...								Here you have to specify either one or two arguments (similar to MAXON_DECLARATION_REGISTER):
/// 															- If you use a single argument, this has to be the unique identifier to use for the registration,
/// 															or the name of a MAXON_DECLARATION if the object class shall be the matching definition.
/// 															- If you use two arguments, the first has to name a registry and the second the identifier to use for the registration.
/// 															The object class will also be added to the registry.
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_CLASS_REGISTER(C, ...) PRIVATE_MAXON_CLASS_REGISTER(C,, PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__), PRIVATE_MAXON_COMPONENT_TYPE(maxon::Class<>, __VA_ARGS__), __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE has to be used instead of MAXON_COMPONENT_CLASS_REGISTER
/// if the component class is a template specialization. Example:
/// @code
/// template <typename INTERFACE, typename OUTPUT> class OutStreamConverter : public Component<OutStreamConverter<INTERFACE, OUTPUT>, INTERFACE>
/// {
/// 	MAXON_COMPONENT(NORMAL, DataDictionaryObjectClass);
/// 	...
/// };
///
/// using OutputStreamConverterFromOutputStream = OutStreamConverter<OutputStreamInterface, OutputStreamRef>;
///
/// MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE(OutputStreamConverterFromOutputStream, "net.maxon.class.outputstreamconverterfromoutputstream");
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE(C, ...) PRIVATE_MAXON_CLASS_REGISTER(C, template<>, PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__), PRIVATE_MAXON_COMPONENT_TYPE(maxon::Class<>, __VA_ARGS__), __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_OBJECT_REGISTER registers a component, creates an object class
/// which uses the component and finally creates an instance of the object class. The instance
/// is registered under the given identifier.
///
/// As for MAXON_COMPONENT_CLASS_REGISTER,
/// the object class consists of the base components and base classes (if any) which you have specified
/// in the MAXON_COMPONENT macro, and then the component itself. You can obtain the object class
/// by the GetClass() function of the component implementation class. In addition to MAXON_COMPONENT_CLASS_REGISTER
/// this macro also creates an instance of the object class (using Create() on the class).
/// This instance will be registered using the identifier given as argument to the macro.
/// So you use this macro e.g. for registries like IoHandlers with entries of type IoHandler,
/// while you use MAXON_COMPONENT_CLASS_REGISTER for registries like UnitTestClasses with entries
/// of type Class<UnitTestRef>.
///
/// The identifier is given in the ... argument. There are three possibilities:
/// - You can use the name of a MAXON_DECLARATION from a header file if the instance shall be the matching definition
///   for the declaration:<br>
///		<tt>MAXON_COMPONENT_OBJECT_REGISTER(FileFormatHandlerGenericFileImpl, FileFormatHandlers::GenericFile);</tt><br>
///   If the MAXON_DECLARATION is within a registry namespace, the instance will also be added to the corresponding registry.
/// - You can specify the name of a registry and a unique identifier. In this case the instance will also be added
///   to the registry:<br>
///   <tt>MAXON_COMPONENT_OBJECT_REGISTER(IoStdinHandler, IoHandlers, "net.maxon.iohandler.stdin");</tt>
/// - You can register the instance using a unique identifier, but this is rarely used for MAXON_COMPONENT_OBJECT_REGISTER:<br>
///   <tt>MAXON_COMPONENT_OBJECT_REGISTER(MyComponentClass, "com.foo.myobject");</tt>
///
/// The component and object class will be registered using the same identifier as the created object itself.
/// A complete example is
/// @code
/// class IoStdinHandler : public Component<IoStdinHandler, IoHandlerInterface>
/// {
/// 	MAXON_COMPONENT(NORMAL, IoHandlerObjectBaseClass);
///		...
/// };
///
/// MAXON_COMPONENT_OBJECT_REGISTER(IoStdinHandler, IoHandlers, "net.maxon.iohandler.stdin");
/// @endcode
///
/// @param[in] C									Name of the implementation class.
/// @param[in] ...								Here you have to specify either one or two arguments (similar to MAXON_DECLARATION_REGISTER):
/// 															- If you use a single argument, this has to be the name of the MAXON_DECLARATION for which the object shall be the matching definition,
/// 															or a unique identifier to use for the registration.
/// 															- If you use two arguments, the first has to name a registry and the second the identifier to use for the registration.
/// 															The object will also be added to the registry.
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_OBJECT_REGISTER(C, ...) PRIVATE_MAXON_CLASS_REGISTER(C,, ::MaxonRegistry, maxon::Class<>, __VA_ARGS__) \
	static maxon::ObjectDefinition g_object_##C(PRIVATE_MAXON_COMPONENT_ID(__VA_ARGS__), &C::PrivateCreateInstance<PRIVATE_MAXON_COMPONENT_TYPE(typename C::Interface::Hxx1::ReferenceClass, __VA_ARGS__)>, (PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__)*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \

//----------------------------------------------------------------------------------------
/// MAXON_COMPONENT_OBJECT_REGISTER_TEMPLATE has to be used instead of MAXON_COMPONENT_OBJECT_REGISTER
/// if the component class is a template specialization.
/// @see MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE
//----------------------------------------------------------------------------------------
#define MAXON_COMPONENT_OBJECT_REGISTER_TEMPLATE(C, ...) PRIVATE_MAXON_CLASS_REGISTER(C, template<>, ::MaxonRegistry, maxon::Class<>, __VA_ARGS__) \
	static maxon::ObjectDefinition g_object_##C(PRIVATE_MAXON_COMPONENT_ID(__VA_ARGS__), &C::PrivateCreateInstance<PRIVATE_MAXON_COMPONENT_TYPE(typename C::Interface::Hxx1::ReferenceClass, __VA_ARGS__)>, (PRIVATE_MAXON_COMPONENT_REGISTRY(__VA_ARGS__)*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \


//----------------------------------------------------------------------------------------
/// ComponentRoot is the base class of all components (see MAXON_COMPONENT). Usually you don't have
/// to take care of this because the Component template automatically sets ComponentRoot as base class.
/// But if you use ComponentWithBase instead, you have to make sure that the base class you use
/// for that template derives from ComponentRoot.
///
/// @see MAXON_COMPONENT
/// @see ComponentWithBase
//----------------------------------------------------------------------------------------
class ComponentRoot MAXON_IF_TARGET_DEBUG(: public EmptyVirtualClass,)
{
public:
	// The following members provide default implementations of component functions which you can override in your own component classes.

	//----------------------------------------------------------------------------------------
	/// Gets called once on start-up when the component implementation is registered.
	/// You can override this function to do static initialization for the component.
	//----------------------------------------------------------------------------------------
	static Result<void> InitImplementation()
	{
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Gets called once on shutdown when the component implementation is freed.
	/// You can override this function to do static deinitialization for the component.
	//----------------------------------------------------------------------------------------
	static void FreeImplementation()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Gets called right after a new object has been constructed. You can override this function in a component
	/// class to initialize the component. Unlike the constructor this function can return an error. Also
	/// all components have been constructed when this function gets called, so you can call methods
	/// or access other components. But keep in mind that only super components have been initialized.
	//----------------------------------------------------------------------------------------
	Result<void> InitComponent()
	{
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Gets called before an object gets destructed. You can override this function in a component
	/// class to free the component at a point of time where the whole object is still valid,
	/// so you can call methods or access other components which is not allowed in the destructor.
	/// But keep in mind that later components might already have done clean-up in their FreeComponent
	/// functions.
	//----------------------------------------------------------------------------------------
	void FreeComponent()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Gets called when an object is copied. You have to implement this function if your
	/// component is non-empty and shall support copying.
	//----------------------------------------------------------------------------------------
	template <typename C> Result<void> CopyFrom(const C& src)
	{
		if (SIZEOF(C) == (STD_IS_REPLACEMENT(empty, ComponentRoot) ? SIZEOF(void*) : SIZEOF(ComponentRoot) + SIZEOF(void*)))
		{
			return OK;
		}
		else if (STD_IS_REPLACEMENT(copy_assignable, C))
		{
			using AssignType = typename std::conditional<STD_IS_REPLACEMENT(copy_assignable, C), C, ComponentRoot>::type;
			static_cast<AssignType&>(*this) = static_cast<const AssignType&>(src);
			return OK;
		}
		else
		{
			CriticalOutput("Component @ has members, but CopyFrom is not implemented!", C::GetDescriptor().GetId());
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		}
	}

	static Result<void> DescribeIO(const DataSerializeInterface&)
	{
		return OK;
	}

	// The following members of ComponentRoot are needed internally by templates for virtual interfaces and their reference classes.

	using PrivateSuperMTable = ObjectInterface::PrivateSuperMTable;
	static const Bool PROXY = false;
	static const Bool ADAPTER = false;
	static const Bool COMPONENT_HELPER = false;
	static const EntityBase::FLAGS COMPONENT_FLAGS = EntityBase::FLAGS::NONE;
	static const EntityBase::FLAGS COMPONENT_FLAGS_EXTRA = EntityBase::FLAGS::NONE;

	template <typename ST> using ReferenceFunctions = ST;
	template <typename T> using ComponentHasBase = std::false_type;
	template <typename S> using Wrapper = S;
	template <typename S> using CombinedMTable = S;

	struct PrivateSimpleInterface
	{
		using MTable = PrivateSimpleInterface;
		using Hxx2 = PrivateSimpleInterface;
		template <typename> using Wrapper = PrivateSimpleInterface;
		template <typename> void Init() { }
	};

	static Int PrivateGetSelfPtrOffset() { return LIMIT<Int>::MIN; }

	static ResultOk<void> ConfigureClass(ClassInterface& cls) { return OK; }

	static ResultOk<void> CreateClassMetaData() { return OK; }

	static const ClassInterface::KIND CLASS_KIND = ClassInterface::KIND::NORMAL;
};


class AdapterRoot : public ComponentRoot
{
public:
	static const Bool ADAPTER = true;
	static const EntityBase::FLAGS COMPONENT_FLAGS = EntityBase::FLAGS::ADAPTER;
};

template <typename BASE, typename... INTERFACES> class ComponentHelper;

#define MAXON_STATIC_REGISTER(C, ...) \
	static maxon::NonvirtualInterfaceImplementation C##_implementation((maxon::StaticHelper<C>*) nullptr, #C, nullptr, C::PrivateInterface::_staticInterface, (maxon::NonvirtualInterfaceReference::MTableInitializer) &C::PrivateInterface::Hxx2::StaticMTable::Init<C::PrivateInterface::Hxx2::CWrapper<maxon::StaticHelper<C>>>, C::PrivateInterface::REFERENCE_KIND | maxon::EntityBase::FLAGS(__VA_ARGS__), &maxon::g_translationUnit, __FILE__)


struct PrivateSelfHelperBase
{
	static const Int self = 0;
};

template <typename BASE, typename> struct PrivateSelfHelper : public BASE, public PrivateSelfHelperBase
{
};

template <typename BASE> class ComponentHelper<BASE> : public BASE
{
public:
	template <typename SELF> void PrivateInitBaseSelf(SELF& s, OverloadRank0)
	{
		this->self.GetBaseRef() = s;
	}

	template <typename SELF, Int = PrivateSelfHelper<BASE, SELF>::self> void PrivateInitBaseSelf(SELF& s, OverloadRank1)
	{
	}

	using type = ComponentHelper;
};

template <typename BASE, typename I, typename... REST> class ComponentHelper<BASE, I, REST...>
{
public:
	using type = typename I::MTable::template CompBase<typename ComponentHelper<BASE, REST...>::type>;
};

// base class Block only needed for Intel compiler workaround
template <typename... INTERFACES> struct InterfacesBlock : public Block<const InterfaceReference* const>
{
	static const InterfaceReference* const value[sizeof...(INTERFACES)];
};


template <typename... INTERFACES> const InterfaceReference* const InterfacesBlock<INTERFACES...>::value[sizeof...(INTERFACES)] = { INTERFACES::PrivateGetInterface()... };

template <typename C, typename BASE, typename INTERFACE, typename... INTERFACES> class ComponentWithBase : public ComponentHelper<BASE, INTERFACE, INTERFACES...>::type
{
public:
	using PrivateSuper = typename ComponentHelper<BASE, INTERFACE, INTERFACES...>::type;
	using PrivateComponentWithBase = ComponentWithBase;

	static_assert(STD_IS_REPLACEMENT(base_of, ComponentRoot, BASE), "Component base classes have to derive from ComponentRoot.");
	static_assert(!BASE::COMPONENT_HELPER, "The base class of a component must not be a component itself.");

	static C* Get(maxon::ObjectInterface* object)
	{
		return MAXON_LIKELY(object != nullptr) ? (C*) ((char*) object + PRIVATE_MAXON_COMPONENT_INFO(object, C)._offset) : nullptr;
	}

	static const C* Get(const ObjectInterface* object)
	{
		return MAXON_LIKELY(object != nullptr) ? (const C*) ((const char*) object + PRIVATE_MAXON_COMPONENT_INFO(object, C)._offset) : nullptr;
	}

	static C* GetNonNull(maxon::ObjectInterface* object)
	{
		return (C*) ((char*) object + PRIVATE_MAXON_COMPONENT_INFO(object, C)._offset);
	}

	static const C* GetNonNull(const ObjectInterface* object)
	{
		return (const C*) ((const char*) object + PRIVATE_MAXON_COMPONENT_INFO(object, C)._offset);
	}

	static C* GetOrNull(ObjectInterface* object)
	{
		if (MAXON_UNLIKELY(object == nullptr))
			return nullptr;
		const ComponentInfo* ci = ((const ObjectSuper*) object)->_classInfo->GetComponentInfo(C::_descriptor);
		return MAXON_LIKELY(ci != nullptr) ? (C*) ((char*) object + ci->_offset) : nullptr;
	}

	static const C* GetOrNull(const ObjectInterface* object)
	{
		if (MAXON_UNLIKELY(object == nullptr))
			return nullptr;
		const ComponentInfo* ci = ((const ObjectSuper*) object)->_classInfo->GetComponentInfo(C::_descriptor);
		return MAXON_LIKELY(ci != nullptr) ? (const C*) ((const char*) object + ci->_offset) : nullptr;
	}

	using Interface = INTERFACE;
	using PrivateInterface = INTERFACE;
	using Ref = typename INTERFACE::Hxx1::ReferenceClass;

	template <typename... ARGS> static Result<typename Ref::NonConst> CreateInit(ARGS&&... args)
	{
		Result<typename Ref::NonConst> res = GetClass().Create();
		if (res == OK)
		{
			Result<void> r = Get(const_cast<INTERFACE*>(static_cast<const INTERFACE*>(res.GetValue().GetPointer())))->Init(std::forward<ARGS>(args)...);
			if (r == FAILED)
				return r.GetErrorStorage();
		}
		return res;
	}

	union
	{
		typename std::conditional<ComponentWithBase::ADAPTER, const ObjectInterface*, typename ComponentWithBase::SelfPtr>::type self;
		SelfPtrBase<typename std::conditional<ComponentWithBase::ADAPTER, INTERFACE, ComponentWithBase>::type::template ReferenceFunctions<RefBaseFunctions<DirectRef<INTERFACE, SuperPointerHandler, SuperPtrComponentInfo<C, ComponentWithBase>>>>> super;
	};

	// If the base class is copy-assignable, then ComponentWithBase is copy-assignable too. However the self pointer isn't copied, that's as needed by ObjectInterface::CopyFrom.
	ComponentWithBase& operator =(const typename std::conditional<STD_IS_REPLACEMENT(copy_assignable, PrivateSuper), ComponentWithBase, DummyParamType>::type& src)
	{
		static_cast<PrivateSuper&>(*this) = static_cast<const PrivateSuper&>(src);
		return *this;
	}

	static Int PrivateGetSelfPtrOffset()
	{
		return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(C, self);
	}

	using ComponentClass = C;
	using _Wrapper = typename ComponentWithBase::template Wrapper<maxon::ComponentWrapper<C>>;
	using PrivateSuperMTable = typename ComponentWithBase::template CombinedMTable<maxon::CombinedMTableRoot>;

	static const Class<typename INTERFACE::Hxx1::ReferenceClass>& GetClass()
	{
		return reinterpret_cast<const Class<typename INTERFACE::Hxx1::ReferenceClass>&>(C::PrivateGetClass());
	}

	static const ComponentDescriptor& GetDescriptor()
	{
		return C::_descriptor;
	}

	static Bool PrivateConstructMTable(ClassInfo* info, Int offset, void* supervtable)
	{
		if (supervtable)
		{
			reinterpret_cast<typename C::PrivateSimpleInterface::MTable*>(reinterpret_cast<maxon::Char*>(info) + SIZEOF(maxon::ClassInterface*))[-1].template Init<typename C::PrivateSimpleInterface::Hxx2::template Wrapper<C>>();
		}
		return (!supervtable || PrivateSuperMTable::Init((PrivateSuperMTable*) supervtable, info))
			&& std::conditional<ComponentWithBase::ADAPTER, typename ComponentWithBase::Super::template Wrapper<maxon::ComponentWrapper<C>>, _Wrapper>::type::InitMTables(info, offset);
	}

	template <typename CLS> static Result<CLS> PrivateConstructClass(MAXON_SOURCE_LOCATION_DECLARATION, Id& cid)
	{
		ClassInterface* c = ClassInterface::Alloc(MAXON_SOURCE_LOCATION_FORWARD, cid, C::CLASS_KIND);
		if (!c)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		Class<typename INTERFACE::Hxx1::ReferenceClass> cls{c};
		Result<void> r = C::ConfigureClass(*c);
		if (r == OK)
		{
			r = c->AddComponent(C::GetDescriptor());
		}
		if (r == OK)
		{
			auto meta = C::CreateClassMetaData();
			if (meta == OK)
			{
				c->PrivateInitMetaData(std::move(meta));
			}
			else
			{
				r = meta;
			}
		}
		if (r == OK)
		{
			r = c->Finalize();
		}
		if (r == FAILED)
			cls = nullptr;
		return Result<CLS>(std::move(cls), r);
	}

	template <typename T> static Result<T> PrivateCreateInstance(MAXON_SOURCE_LOCATION_DECLARATION, Id& cid)
	{
		return C::GetClass().Create();
	}

	using InterfacesBlock = maxon::InterfacesBlock<INTERFACE, INTERFACES...>;
};


template <typename C, typename... INTERFACES> using Component = ComponentWithBase<C, ComponentRoot, INTERFACES...>;

template <typename FROM, typename C, typename... INTERFACES> using AdapterComponent = ComponentWithBase<C, AdapterRoot, FROM, INTERFACES...>;

template <typename... INTERFACES> using SelfPtr = typename ComponentHelper<ComponentRoot, INTERFACES...>::type::SelfPtr;


// Because the initialization of explicit instantiations is unordered, g_translationUnit might not have been initialized when MAXON_INTERFACE_REGISTER_VIRTUAL is done for interface template instantiations.
// Therefore call TranslationUnit::PrivateInitModule to ensure a valid ModuleInfo pointer for g_translationUnit.
#define PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(...) ((MAXON_EXPAND(MAXON_VA_NARGS(__VA_ARGS__)) > 0) ? maxon::g_translationUnit.PrivateInitModule(&PRIVATE_MAXON_MODULE) : &maxon::g_translationUnit)

#define PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(I, POSTFIX, TARGS, TEMPL, IID, NAME, ...) \
	TEMPL static const maxon::InterfaceReference* g_baseInterfaces_##POSTFIX[] = {__VA_ARGS__}; \
	TEMPL maxon::InterfaceReference I::_interface(IID, NAME, g_baseInterfaces_##POSTFIX TARGS, I::MTable::_ids, I::MTable::_flags, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL), I::REFERENCE_KIND | I::INTERFACE_FLAGS)

#define PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_IMPL(I, POSTFIX, TARGS, TEMPL, IID, NAME, ...) \
	TEMPL static const maxon::InterfaceReference* g_baseInterfaces_##POSTFIX[] = {__VA_ARGS__}; \
	TEMPL maxon::InterfaceReference I::_interface(IID, NAME, g_baseInterfaces_##POSTFIX TARGS, I::MTable::_ids, I::MTable::_flags, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL), I::REFERENCE_KIND | I::INTERFACE_FLAGS); \
	TEMPL maxon::NonvirtualMTableReference I::_nonvirtualMTable(IID, &I::MTable::NVMTable::_instance, (maxon::NonvirtualMTableReference::Initializer*) &I::MTable::template CombinedMTable<maxon::CombinedMTableRoot>::Init, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL))

#define PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(I, TEMPL, IID, NAME, BASE) \
	TEMPL maxon::InterfaceReference I::_interface(IID, NAME, BASE, I::MTable::_ids, I::MTable::_flags, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL), I::REFERENCE_KIND | I::INTERFACE_FLAGS)

#define PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE_SINGLE_IMPL(I, TEMPL, IID, NAME, BASE) \
	TEMPL maxon::InterfaceReference I::_interface(IID, NAME, BASE, I::MTable::_ids, I::MTable::_flags, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL), I::REFERENCE_KIND | I::INTERFACE_FLAGS); \
	TEMPL maxon::NonvirtualMTableReference I::_nonvirtualMTable(IID, &I::MTable::NVMTable::_instance, (maxon::NonvirtualMTableReference::Initializer*) &I::MTable::template CombinedMTable<maxon::CombinedMTableRoot>::Init, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL))

#define PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(I, TEMPL, IID) \
	TEMPL typename I::Hxx2::StaticMTable I::Hxx2::StaticMTable::_instance; \
	TEMPL typename I::Hxx2::StaticMTable I::Hxx2::StaticMTable::_unresolvedInstance; \
	TEMPL maxon::NonvirtualInterfaceReference I::_staticInterface(IID, (maxon::MTableBase*) &I::Hxx2::StaticMTable::_instance, (maxon::MTableBase*) &I::Hxx2::StaticMTable::_unresolvedInstance, I::Hxx2::StaticMTable::_ids, sizeof(typename I::Hxx2::StaticMTable) / sizeof(void*), (maxon::NonvirtualInterfaceReference::UnresolvedInitializer) &I::Hxx2::StaticMTable::InitUnresolved, PRIVATE_MAXON_INITIALIZED_TRANSLATION_UNIT(TEMPL), maxon::EntityBase::FLAGS::REFERENCE_NONE)

namespace details
{
#ifdef MAXON_TARGET_MACOS
static_assert(STD_IS_REPLACEMENT(trivially_copyable, Result<void>) && (SIZEOF(Result<void>) == SIZEOF(Int)), "Result<void> can't be passed in a register!");
#endif

template <typename T> class NullReturnType
{
public:
	static const NULL_RETURN_TYPE value = STD_IS_REPLACEMENT(void, T) ? NULL_RETURN_TYPE::VOID_ZERO
		: (STD_IS_REPLACEMENT(integral, T) || STD_IS_REPLACEMENT(pointer, T)) ? NULL_RETURN_TYPE::INTEGRAL_ZERO
		: STD_IS_REPLACEMENT(floating_point, T) ? (STD_IS_REPLACEMENT(same, const float, const T) ? NULL_RETURN_TYPE::FLOAT_ZERO : NULL_RETURN_TYPE::DOUBLE_ZERO)
#ifdef MAXON_TARGET_MACOS
		// Result<void> is passed in a register
		: STD_IS_REPLACEMENT(same, T, Result<void>) ? NULL_RETURN_TYPE::INTEGRAL_ZERO
#endif
		: (STD_IS_REPLACEMENT(lvalue_reference, T) && STD_IS_REPLACEMENT(const, typename std::remove_reference<T>::type)
			 && GetDirectlyReferencedType<typename std::remove_reference<T>::type>::value) ? NULL_RETURN_TYPE::POINTER_TO_ZERO
		: NULL_RETURN_TYPE::OTHER;
};
}

constexpr inline const Char* GetFunctionName(const Char* funcName)
{
	Int lastColon = 0;
	for (Int i = 0; funcName[i]; i++)
	{
		if (funcName[i] == ':')
			lastColon = i + 1;
	}
	return &funcName[lastColon];
}

/// This macro returns the function name of the current member or global function.
#define MAXON_FUNCTIONNAME maxon::Id(maxon::GetFunctionName(__FUNCTION__))

/// @}

} // namespace maxon

//----------------------------------------------------------------------------------------
/// Debug helper, writing "cstr(err)" in the watch window will display the error as readable test.
//----------------------------------------------------------------------------------------
const maxon::Char* cstr(const maxon::Error& err);
const maxon::Char* cstr(const maxon::ErrorPtr& err);
const maxon::Char* cstr(const maxon::ThreadReferencedError& err);

#endif // OBJECTBASE_H__
