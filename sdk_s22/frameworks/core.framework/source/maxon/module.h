#ifndef MODULE_H__
#define MODULE_H__

#include "maxon/entity.h"
#include "maxon/datatypebase.h"
#include "maxon/block.h"


struct MaxonRegistry // has to be in global namespace as a globally visible default
{
	using EntryType = void;
	using Dependencies = maxon::Tuple<>;

	static maxon::Id GetId() { return maxon::Id(); }
};

namespace maxon
{

class ProfilingPoint;

/// @addtogroup SYSTEM
/// @{



// used internally to initialize interned ids defined with MAXON_INTERNED_ID or MAXON_INTERNED_ID_LOCAL
class InternedIdInitializer
{
public:
	InternedIdInitializer(InternedId* iid, const Char* str, ModuleInfo* info);

private:
	InternedId* _id; ///< The interned id to initialize.
	const Char* _str; ///< The value for initialization.
	InternedIdInitializer* _nextOfModule; ///< Next in singly linked list of initializers of the current module.

	friend class ObjectModel;
};

namespace reflection
{
struct ContainerInfo;
class ProxyImpl;
};

class DataTypeCache;

//----------------------------------------------------------------------------------------
/// MAXON_INTERNED_ID is used in a header file to define a global interned id as in
/// @code
/// MAXON_INTERNED_ID("net.maxon.xyz", xyz);
/// @endcode
/// @c xyz then refers to an InternedId with value @c "net.maxon.xyz". You can use this, e.g.,
/// for id-based maps where you need fast id comparisons: With interned ids, it suffices to
/// just compare the Id pointers.
/// @param[in] IID								C-string to use for the id.
/// @param[in] NAME								Name of the global InternedId object to declare.
/// @see MAXON_INTERNED_ID_LOCAL
//----------------------------------------------------------------------------------------
#define MAXON_INTERNED_ID(IID, NAME) extern maxon::InternedId NAME

//----------------------------------------------------------------------------------------
/// MAXON_INTERNED_ID_LOCAL is used in a cpp file to define an InternedId as in
/// @code
/// MAXON_INTERNED_ID_LOCAL("net.maxon.xyz", xyz);
/// @endcode
/// @c xyz then refers to an InternedId with value @c "net.maxon.xyz". You can use this, e.g.,
/// for id-based maps where you need fast id comparisons: With interned ids, it suffices to
/// just compare the Id pointers.
/// @param[in] IID								C-string to use for the id.
/// @param[in] NAME								Name of the InternedId object to declare.
/// @see MAXON_INTERNED_ID
/// @note The same NAME must not be used within more then one cpp file of a binary.
//----------------------------------------------------------------------------------------
#define MAXON_INTERNED_ID_LOCAL(IID, NAME) maxon::InternedId NAME; static maxon::InternedIdInitializer g_iid_##NAME(&NAME, IID, &PRIVATE_MAXON_MODULE)
// note: we don't use static for NAME because then we'd have internal linkage, and this would prevent the usage as argument for a non-type template parameter

/// @cond INTERNAL


//----------------------------------------------------------------------------------------
/// A Binary represents the current binary file. Such a file contains one or more modules.
//----------------------------------------------------------------------------------------
class Binary
{
public:
	//----------------------------------------------------------------------------------------
  /// Typedef for the initializer function provided by the object system.
#ifndef MAXON_COMPILER_CLANG	// circumvent clang bug that creates false positives
	/// @param[in] entity							Entity object which shall be initialized.
	/// @param[in] cause							Identifier of another entity which requests the initialization of this entity object. This is only for informative purpose.
	/// @return												Success of initialization.
#endif
	//----------------------------------------------------------------------------------------
  using Initializer = Result<void>(*)(EntityBase* entity, const Id& cause);
  
	//----------------------------------------------------------------------------------------
	/// Returns the ABI version of the MAXON API which was used for compilation of this binary.
	/// Only binaries with equal version can be loaded together.
	/// @return												MAXON API version of this binary.
	//----------------------------------------------------------------------------------------
	Int GetABIVersion() const
	{
		return _abiVersion;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the head of a singly linked list of all modules of this binary.
	/// @return												List of all modules.
	//----------------------------------------------------------------------------------------
	const ModuleInfo* GetModules() const
	{
		return _modules;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the name of this binary. Usually this is derived from the installation path.
	/// @return												Name of binary.
	//----------------------------------------------------------------------------------------
	const Id& GetName() const
	{
		return _name;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the Url of this binary. May be a null Url.
	/// @return												Url of binary.
	//----------------------------------------------------------------------------------------
	const Url& GetUrl() const
	{
		return reinterpret_cast<const Url&>(_url);
	}

	//----------------------------------------------------------------------------------------
  /// Returns the initializer function. This function is provided by the object system when the module is loaded.
	/// @return												Initializer function from the object system.
	//----------------------------------------------------------------------------------------
  Initializer GetInitializer() const
  {
    return _initializer;
  }

	const ModuleInfo* FindFramework(const Id& fid) const;

private:
	// The ABI version when this binary was compiled. Only binaries with matching ABI versions can work together.
	// _version has to be the first member of Binary, and Binary must have standard-layout.
	const Int _abiVersion = MAXON_API_ABI_VERSION;

	// Points to a singly linked list of ModuleInfo objects of this binary.
	// We must not initialize this with nullptr: This will be done anyhow as Binary is used as a global object,
	// and _modules might get overwritten before the constructor of Binary gets called.
	const ModuleInfo* _modules;

	// The name of the binary, typically derived from its installation path.
	Id _name;

	// The Url of the binary. A strong Url reference, but we have to use void* here because url.h can't be included.
	const void* _url = nullptr;

  Initializer _initializer; ///< Initializer function. This will be set by the object system.

	NamedTupleMembers* _namedTupleMembers; ///< Linked list of NamedTupleMembers, needed for their destruction at program end.

	Int _reserved[4];

	friend class ModuleInfo;
	friend class ObjectModel;
	friend class DataTypeLibImpl;
};

//----------------------------------------------------------------------------------------
/// The global Binary object which describes the current binary.
/// This is exported from the binary as entry point for the module loader.
//----------------------------------------------------------------------------------------
extern "C" MAXON_ATTRIBUTE_DLL_PUBLIC Binary g_maxon;


//----------------------------------------------------------------------------------------
/// ModuleInfo collects information about a single module. All modules of a single binary
/// are linked via their _next pointer (accessible through GetNext()),
/// the first module is given by g_maxon.GetModules().
//----------------------------------------------------------------------------------------
class ModuleInfo
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a ModuleInfo object. This constructor is needed only internally for the special
	/// core and framework modules.
	/// @param[in] idValue						Unique module identifier.
	/// @param[in] unit								The translation unit containing the ModuleInfo object.
	/// @param[in] flags							The CORE and FRAMEWORK flags may be set to tell if this is the core module or a framework module.
	//----------------------------------------------------------------------------------------
	ModuleInfo(const Char* idValue, TranslationUnit* unit, EntityBase::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Returns true if this is the core module which contains the startup code.
	/// @return												Is this the core module?
	//----------------------------------------------------------------------------------------
	Bool IsCore() const
	{
		return (Bool)(_super.GetBase().GetFlags() & EntityBase::FLAGS::CORE);
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this is a framework module. Each binary has one framework module
	/// for each linked framework.
	/// @return												Is this a framework module?
	//----------------------------------------------------------------------------------------
	Bool IsFramework() const
	{
		return (Bool)(_super.GetBase().GetFlags() & EntityBase::FLAGS::FRAMEWORK);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the base object which stores general entity information about the ModuleInfo.
	/// Ideally, this would be done by having EntityBase as base class, but then ModuleInfo wouldn't be a standard-layout class.
	/// @return												EntityBase object of this ModuleInfo.
	//----------------------------------------------------------------------------------------
	const EntityBase& GetBase() const
	{
		return _super.GetBase();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the head of a singly linked list of all translation units of this module.
	/// @return												List of translation units of this module.
	//----------------------------------------------------------------------------------------
	const TranslationUnit* GetTranslationUnits() const
	{
		return _units;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the head of a singly linked list of all profiling points of this module.
	/// @return												List of profiling points of this module.
	//----------------------------------------------------------------------------------------
	const ProfilingPoint* GetProfilingPoints() const
	{
		return _profilingPoints;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the next ModuleInfo in the singly linked list of all such infos of a binary.
	/// @return												Next module of the same binary.
	//----------------------------------------------------------------------------------------
	const ModuleInfo* GetNext() const
	{
		return _next;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the Binary which contains this module.
	/// @return												Binary of this module.
	//----------------------------------------------------------------------------------------
	const Binary& GetBinary() const
	{
		return *_binary;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this module is in the same binary as the @p other module.
	/// @return												Are both module in the same binary?
	//----------------------------------------------------------------------------------------
	Bool IsInSameBinary(const ModuleInfo* other) const
	{
		return _binary == other->_binary;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifiers of all used frameworks of this module. This matches the
	/// list in projectdefinition.txt of the module plus the indirectly used frameworks.
	/// @return												Identifiers of directly or indirectly used frameworks of this module.
	//----------------------------------------------------------------------------------------
	Block<const Id> GetUsedFrameworks() const;

private:
	struct InternalData;

	EntityDefinition _super; ///< Base EntityDefinition object.

	TranslationUnit* _units; ///< Head of singly linked list of translation units of this module.
	EntityReference* _references; ///< Head of singly linked list of references of this module.
	InternedIdInitializer* _internedIds; ///< Head of singly linked list of interned id initializers of this module.
	ProfilingPoint* _profilingPoints; ///< Head of singly linked list of profiling points of this module.
	const reflection::ContainerInfo* _containerInfos; ///< Head of singly linked list of ContainerInfos of this module.
	const DataTypeCache* _dataTypeCaches; ///< Head of singly linked list of DataTypeCaches of this module.
	const Id* _usedFrameworks; ///< List of all frameworks which are used by this module.
	Int _usedFrameworksCount; ///< Number of elements in _usedFrameworks.
	const void* _code; ///< Pointer to code generated at runtime.
	const ModuleInfo* _next; ///< Next in singly linked list of modules of the current binary.
	const Binary* const _binary; ///< Pointer to the binary which contains this module.
  InternalData* _internalData; ///< Internal data for this module.
	mutable SCCData _sccData;

	Int _reserved[4];

	friend class TranslationUnit;
	friend class EntityReference;
	friend class ProfilingPoint;
	friend class InternedIdInitializer;
	friend class ObjectModel;
	friend class SetUsedFrameworks;
	friend class DataTypeCache;
	friend class Binary;
	friend struct reflection::ContainerInfo;

	template <typename, typename, typename, typename, typename> friend class StronglyConnectedComponents;
};


class ComponentDescriptor;
class ClassInterface;
template <typename R = ObjectRef> class Class;


template <typename D, TranslationUnit& UNIT, UInt64 UNIT_HASH, Bool WEAK> class DeclarationUse : public EntityUse
{
public:
	DeclarationUse() : EntityUse(D::DeclarationHelper::GetInstance().GetReference(), &UNIT, D::DeclarationHelper::HEADER, WEAK)
	{
		static_assert(sizeof(*this) == sizeof(EntityUse), "");
	}

	static DeclarationUse _instance;

	const typename D::Type& NullValueImpl() { return maxon::NullValue<const typename D::Type&>(); }

	static const typename D::Type& NullValue() { return reinterpret_cast<DeclarationUse<D, UNIT, UNIT_HASH, WEAK>&>(_instance).NullValueImpl(); }
};

template <typename D, TranslationUnit& UNIT, UInt64 UNIT_HASH, Bool WEAK> DeclarationUse<D, UNIT, UNIT_HASH, WEAK> DeclarationUse<D, UNIT, UNIT_HASH, WEAK>::_instance;

namespace details
{

template <typename T> struct EntityType
{
	static const EntityBase::TYPE value = EntityBase::TYPE::DECLARATION;
};

template <> struct EntityType<ComponentDescriptor>
{
	static const EntityBase::TYPE value = EntityBase::TYPE::COMPONENT;
};

template <typename T> struct EntityType<Class<T>>
{
	static const EntityBase::TYPE value = EntityBase::TYPE::CLASS;
};

}

//----------------------------------------------------------------------------------------
/// A Declaration is an EntityReference which declares a published object or a component descriptor.
/// A Declaration is created by MAXON_DECLARATION and also indirectly by MAXON_DATATYPE.
///
/// @tparam T											Type of the published object.
/// @tparam C											Helper class defined by MAXON_DECLARATION which contains some type aliases and static functions.
/// @see ObjectDefinition
//----------------------------------------------------------------------------------------
template <typename T, typename C> class Declaration
{
public:
	using Type = T;
	using DeclarationHelper = C;
	using Registry = typename C::Registry;

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this reference.
	/// @return												Unique identifier.
	//----------------------------------------------------------------------------------------
	static constexpr LiteralId GetId()
	{
		return C::GetId();
	}

	static const Declaration& GetInstance()
	{
		return C::GetInstance();
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the Declaration and adds it to the reference list of the current translation unit.
	/// @param[in] iid								Identifier of the published object.
	/// @param[in] unit								The translation unit containing the object reference.
	//----------------------------------------------------------------------------------------
	Declaration(LiteralId&& iid, TranslationUnit* unit) : _super(maxon::details::EntityType<T>::value, std::move(iid), unit), _object(nullptr)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the Declaration and adds it to the reference list of the current translation unit.
	/// @param[in] iid								Identifier of the published object.
	/// @param[in] unit								The translation unit containing the object reference.
	//----------------------------------------------------------------------------------------
	Declaration(const Char* iid, TranslationUnit* unit) : _super(maxon::details::EntityType<T>::value, iid, unit), _object(nullptr)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the object referred to by this Declaration. If the reference hasn't been initialized yet,
	/// the initialization of the corresponding definition and its references is triggered.
	/// The usage of operator() creates a strong dependency of the calling source file on the definition of the object.
	/// @return												The referenced object (or a reference to the null value if the initialization failed).
	/// @see WeakGet
	//----------------------------------------------------------------------------------------
	template <TranslationUnit& UNIT = g_translationUnit, UInt64 UNIT_HASH = g_translationUnitHash> const T& operator ()() const
	{
		if (MAXON_LIKELY(_object))
		{
			return *_object;
		}
		else
		{
      DebugAssert(g_maxon.GetInitializer());
      (*g_maxon.GetInitializer())(const_cast<EntityBase*>(&_super.GetDefinition()->GetBase()), _super.GetBase().GetId()) iferr_ignore("_object checked afterwards.");
			if (MAXON_LIKELY(_object))
			{
				return *_object;
			}
			return std::conditional<C::DEPENDENCIES_ENABLED, DeclarationUse<Declaration, UNIT, UNIT_HASH, false>, Declaration>::type::NullValue();
		}
	}

	// TODO: (Ole) Documentation
	const T& GetWithoutDependency() const
	{
		return *_object;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the object referred to by this reference, or a null value if no definition exists
	/// for this declaration. If the reference hasn't been initialized yet and a definition exists,
	/// the initialization of the corresponding definition and its references is triggered.
	///
	/// Unlike operator(), the usage of WeakGet() only creates a weak dependency of the calling source file on the definition of the object.
	/// This means that a definition need not exist. In this case, a null value is returned.
	/// @return												The referenced object (or a reference to the null value if no matching definition exists or if the initialization failed).
	/// @see Get
	//----------------------------------------------------------------------------------------
	template <TranslationUnit& UNIT = g_translationUnit, UInt64 UNIT_HASH = g_translationUnitHash> Result<const T&> WeakGet() const
	{
		static_assert(C::DEPENDENCIES_ENABLED, "WeakGet() can only be invoked when dependencies are enabled. Check for correct use of MAXON_DEPENDENCY_ENABLE.");
		if (MAXON_LIKELY(_object))
		{
			return *_object;
		}
		else
		{
			DebugAssert(g_maxon.GetInitializer());
			Result<void> res = (*g_maxon.GetInitializer())(const_cast<EntityBase*>(&_super.GetDefinition()->GetBase()), _super.GetBase().GetId());
			if (res == FAILED)
				return res.GetErrorStorage();
			if (MAXON_LIKELY(_object))
			{
				return *_object;
			}
			DebugStop();
			return DeclarationUse<Declaration, UNIT, UNIT_HASH, true>::NullValue();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the object reference has been initialized successfully. This means that the reference has been resolved
	/// to an object definition which itself has been initialized successfully, so that it can be used.
	/// @return												True if reference and corresponding definition have been initialized successfully.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return _super.IsInitialized();
	}

	const EntityReference& GetReference() const
	{
		return _super;
	}

private:
	EntityReference _super; ///< EntityReference base object.
	const T* _object; ///< Pointer to the referenced object. This is set by the object system when the reference is initialized.

	static const T& NullValue()
	{
		return maxon::NullValue<const T&>();
	}

	friend class ObjectModel;
};


//----------------------------------------------------------------------------------------
/// An ObjectDefinition is an EntityDefinition which defines a published object. Published objects are defined in several ways:
/// - MAXON_DECLARATION_REGISTER directly defines an object. Usually there is a corresponding MAXON_DECLARATION.
/// - MAXON_DATATYPE_REGISTER defines a DataType object for a MAXON_DATATYPE declaration.
/// - MAXON_COMPONENT_CLASS_REGISTER defines an object class, MAXON_COMPONENT_OBJECT_REGISTER additionally an instance of the object class.
///
/// Also a component (MAXON_COMPONENT_ONLY_REGISTER) introduces a published object, but internally this is represented by a ComponentDescriptor
/// instead of an ObjectDefinition.
//----------------------------------------------------------------------------------------
class ObjectDefinition
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs the ObjectDefinition and adds it to the definition list of the current translation unit.
	/// This constructor is used by MAXON_DECLARATION_REGISTER and MAXON_COMPONENT_ONLY_REGISTER.
	/// @param[in] iid								Identifier of the published object.
	/// @param[in] init								Initialization function to create the published object.
	/// @param[in] dummy							Dummy parameter to allow overload resolution to select the correct overload.
	/// @param[in] unit								The translation unit containing the definition.
	/// @param[in] file								Source file name.
	/// @tparam T											Type of the published object.
	//----------------------------------------------------------------------------------------
	template <typename T> ObjectDefinition(LiteralId&& iid, Result<T> (*init) (MAXON_SOURCE_LOCATION_DECLARATION, Id&), ::MaxonRegistry* dummy, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags)
		: _super(maxon::details::EntityType<T>::value, std::move(iid), unit, file, flags),
		_init((void*) init), _initDefinition(&InitObject<T>), _freeDefinition(&FreeObject<T>)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the ObjectDefinition and adds it to the definition list of the current translation unit.
	/// This constructor is used by MAXON_DECLARATION_REGISTER and MAXON_DATATYPE_REGISTER.
	/// @param[in] iid								Identifier of the published object.
	/// @param[in] init								Initialization function to create the published object.
	/// @param[in] dummy							Dummy parameter, this is only needed to determine template parameter REG.
	/// @param[in] unit								The translation unit containing the definition.
	/// @param[in] file								Source file name.
	/// @tparam T											Type of the published object.
	/// @tparam REG										Type of the registry.
	//----------------------------------------------------------------------------------------
	template <typename T, typename REG> ObjectDefinition(LiteralId&& iid, Result<T> (*init) (MAXON_SOURCE_LOCATION_DECLARATION, Id&), REG* dummy, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags)
		: _super(maxon::details::EntityType<T>::value, std::move(iid), unit, file, flags),
			_init((void*) init), _initDefinition(&InitRegistryEntry<T, REG>), _freeDefinition(&FreeRegistryEntry<T, REG>), _registry(REG::GetId())
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the object. If the object has not yet been initialized, this is done at first.
	/// @return												Pointer to the object, or nullptr if the initialization failed.
	//----------------------------------------------------------------------------------------
	const void* PrivateGet()
	{
		if (_object.GetType())
			return _object.PrivateGetPtr();
		Result<void> r = _super.GetBase().Initialize(Id::NullValue());
		return (r == FAILED) ? nullptr : _object.PrivateGetPtr();
	}

	const Data& GetData() const
	{
		return _object;
	}

	template <UInt N> static LiteralId MakeId(const Char (&str)[N])
	{
		return LiteralId(str);
	}

	static LiteralId&& MakeId(LiteralId&& i)
	{
		return std::move(i);
	}

	static LiteralId MakeId()
	{
		return LiteralId();
	}

private:
	//----------------------------------------------------------------------------------------
	/// Initializes the object on request of the object system. This invokes #_init and stores the result in #_object.
	/// @return												Success of initialization.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<void> InitObject(ObjectDefinition* this_)
	{
		this_->_objectId = this_->_super.GetBase().GetId();
		// The called function is allowed to modify _objectId.
		Result<T> r = ((Result<T> (*) (MAXON_SOURCE_LOCATION_DECLARATION, Id&)) this_->_init)(MAXON_SOURCE_LOCATION_NAME(T), this_->_objectId);
		if (r == FAILED)
			return r.GetErrorStorage();
		Result<void> r2 = this_->_object.Set(std::move(r.UncheckedGetValue()));
		if (r2 == FAILED)
			return r2.GetErrorStorage();

		// Special handling for ClassInterface: Register extension.
		if (STD_IS_REPLACEMENT(same, const typename Dereference<T>::type, const ClassInterface))
		{
			this_->AddClassExtension(Dereference<T>::GetPointer(*(T*) this_->_object.PrivateGetPtr()));
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Frees the object on request of the object system.
	//----------------------------------------------------------------------------------------
	template <typename T> static void FreeObject(ObjectDefinition* this_)
	{
		this_->_object.Reset();
		if (STD_IS_REPLACEMENT(same, const typename Dereference<T>::type, const ClassInterface))
		{
			this_->RemoveClassExtension();
		}
		this_->_objectId.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the object on request of the object system. This invokes #_init, stores the result in #_object and registers
	/// the object as an extension.
	/// @return												Success of initialization.
	//----------------------------------------------------------------------------------------
	template <typename T, typename REG> static Result<void> InitRegistryEntry(ObjectDefinition* this_)
	{
		Result<void> r = InitObject<T>(this_);
		if (r == FAILED)
			return r;
		return REG::Insert(this_->_objectId, *this_->_object.GetPtr<T>(), nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Frees the object on request of the object system. At first this removes the object from the registry.
	//----------------------------------------------------------------------------------------
	template <typename T, typename REG> static void FreeRegistryEntry(ObjectDefinition* this_)
	{
		REG::Erase(this_->_objectId) iferr_ignore("Allocation failure on shutdown.");
		FreeObject<T>(this_);
	}

	void AddClassExtension(const void* ptr);
	void RemoveClassExtension();

	EntityDefinition _super; ///< EntityDefinition base object.
	void* _init; ///< The init function to create the object.
	Result<void> (*_initDefinition) (ObjectDefinition*); ///< Pointer to either InitObject() or InitRegistryEntry().
	void (*_freeDefinition) (ObjectDefinition*); ///< Pointer to either FreeObject() or FreeRegistryEntry().
	Data _object; ///< The object is stored in this Data object.
	Id _objectId; ///< The actual identifier if this object definition defines a registry entry (may be set by InitObject).
	Id _registry; ///< Id of a registry at which this object definition is registered.

	friend class ObjectModel;
};

/// @endcond


//----------------------------------------------------------------------------------------
/// MAXON_DEPENDENCY_ON_MODULE adds a dependency of the current module on the specified module.
/// Use this if you want to make sure that the specified module has been initialized before this
/// module is initialized. Normally a proper module initialization order is already ensured
/// by the @ref auto_dep  "automatic dependencies", so you need this only in rare cases of
/// dependencies that go beyond what automatic dependencies can detect.
/// @param[in] module							Module on which the current module shall depend.
/// @see @ref manual_dep
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_ON_MODULE(module) static maxon::EntityUse MAXON_CONCAT(s_up, __LINE__) (module, &maxon::g_translationUnit, nullptr);

class ObjectModel;

namespace details
{

//----------------------------------------------------------------------------------------
/// An InitializationFunctions object is created by the macro MAXON_INITIALIZATION. It is a local entity definition without references or uses
/// which invokes initialization and shutdown functions as part of the initialization and shutdown of the current translation unit.
/// The identifier is given by the source file name and needn't be unique. There may be several InitializationFunctions objects per source file.
//----------------------------------------------------------------------------------------
class InitializationFunctions
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs the InitializationFunctions object and adds it to the definition list of the current translation unit.
	/// @param[in] file								Name of the current source file, will be used for the entity identifier.
	/// @param[in] init								Initialization function, may be nullptr.
	/// @param[in] free								Shutdown function, may be nullptr.
	/// @param[in] unit								The translation unit containing the object.
	//----------------------------------------------------------------------------------------
	InitializationFunctions(const Char* file, Result<void> (*init) (), void (*free) (), TranslationUnit* unit);

private:
	EntityDefinition _super; ///< Base definition object.
	Result<void> (* const _init) (); ///< Initialization function.
	void (* const _free) (); ///< Shutdown function.

	friend class maxon::ObjectModel;
};

}

#ifdef MAXON_DEPENDENCY_ENABLE

//----------------------------------------------------------------------------------------
/// MAXON_INITIALIZATION adds a pair of initialization/shutdown functions to the current translation unit.
/// Those functions are invoked as part of the initialization and shutdown of the translation unit.
/// - The first function is the initialization function, it may be nullptr or a lambda. It has to take no arguments and return Result<void>.
/// - The second function is the shutdown function, it may be nullptr or a lambda. It has to take no arguments and return void.
///
/// You can use MAXON_INITIALIZATION as often as you want per translation unit.
/// Example:
/// @code
/// static Result<void> Initialize()
/// {
/// 	return ...
/// }
///
/// static void Free()
/// {
///   ...
/// }
///
/// MAXON_INITIALIZATION(Initialize, Free);
/// @endcode
/// @note
/// Technically both functions aren't passed as macro arguments to the macro, but to a function call of a helper class which is prepared by the macro.
/// This allows to add breakpoints when lambdas are used as arguments.
//----------------------------------------------------------------------------------------
#define MAXON_INITIALIZATION PRIVATE_MAXON_INITIALIZATION_A(MAXON_CONCAT(__LINE__, MAXON_CONCAT(_, __COUNTER__)))

#define PRIVATE_MAXON_INITIALIZATION_A(ID) PRIVATE_MAXON_INITIALIZATION_B(ID)
#define PRIVATE_MAXON_INITIALIZATION_B(ID) PRIVATE_MAXON_INITIALIZATION_C(ID)

#define PRIVATE_MAXON_INITIALIZATION_C(ID) \
	static struct MAXON_CONCAT(PrivateInitialization_, ID) : public maxon::details::InitializationFunctions \
	{ \
		MAXON_CONCAT(PrivateInitialization_, ID)(maxon::Result<void> (*init) (), void (*free) ()) : maxon::details::InitializationFunctions(__FILE__, init, free, &maxon::g_translationUnit) { } \
	} MAXON_CONCAT(s_initialization_, ID)

#else

#define MAXON_INITIALIZATION(...) static_assert(false, "You may only use MAXON_INITIALIZATION in a framework cpp file if you add #define MAXON_DEPENDENCY_ENABLE as its first line (before any includes).")

#endif


//----------------------------------------------------------------------------------------
/// MAXON_DECLARATION declares a published object with a unique identifier. You can use this macro in a header file,
/// then the object can be used by including the header file. Also a dependency of the including source file
/// on the definition of the object is set up, but only when the declarations is actually used within the source file
/// (see Declaration::operator()). See @ref published_objects for more details.
///
/// The object itself has to be defined in another source file. There are several kinds of published objects,
/// each is defined in a different way:
/// - General objects are defined by MAXON_DECLARATION_REGISTER.
///   @code
///   // header file
///   MAXON_DECLARATION(Dimension, Length, "net.maxon.dimension.length");
///
///		// source file defining the object
///		MAXON_DECLARATION_REGISTER(Dimensions::Length)
///		{
///			return g_baseDimensions[Int(BASE_DIMENSION::LENGTH)];
///		}
///
///   // source file using the component
///   const Dimension& len = Dimensions::Length();
///   @endcode
/// - Classes can be defined as above, but typically they are defined by MAXON_COMPONENT_CLASS_REGISTER.
///   @code
///   // header file
///   MAXON_DECLARATION(Class<InputStreamRef>, InputStreamBaseClass, "net.maxon.class.inputstreambase");
///
///   // source file defining the class (it has to define the C++ class IoBaseInputStreamImpl)
///   MAXON_COMPONENT_CLASS_REGISTER(IoBaseInputStreamImpl, InputStreamBaseClass);
///
///   // source file using the class
///   const Class<InputStreamRef>& cls = InputStreamBaseClass();
///   @endcode
/// - Component descriptors are defined by MAXON_COMPONENT_ONLY_REGISTER:
///   @code
///   // header file
///   MAXON_DECLARATION(ComponentDescriptor, RPCComponent, "net.maxon.rpc.component.rpc");
///
///   // source file defining the component
///   MAXON_COMPONENT_ONLY_REGISTER(RPCComponentImpl, RPCComponent);
///
///   // source file using the component
///   const ComponentDescriptor& desc = RPCComponent();
///   @endcode
///
/// The macro creates a global C++ object with the given Name. It has Declaration as base class,
/// and the referenced object of the given Type is obtained by writing Name().
/// Name.GetId() returns the unique identifier.
///
/// @param[in] Type								Type of the object. This can be any type which is supported by Data,
/// 															or ComponentDescriptor for published components.
/// @param[in] Name								Name of the object within the current namespace.
/// @param[in] id									Unique identifier of the object.
///
/// @see @ref object_declaration
/// @note This macro can only be used at namespace scope. For a class scope, you have to use MAXON_DECLARATION_CLASS.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION(T, Name, id) \
	PRIVATE_MAXON_DECLARATION(T, Name, id, ;, extern); \
const Name##PrivateHelper::DeclarationType& Name##PrivateHelper::GetInstance() { return Name; }


//----------------------------------------------------------------------------------------
/// MAXON_DECLARATION_CLASS has to be used instead of MAXON_DECLARATION if the declaration shall happen
/// at class scope instead of namespace scope. Other than that, both macros do the same.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_CLASS(T, Name, id) \
	PRIVATE_MAXON_DECLARATION(T, Name, id, { return Name; }, static)


#define PRIVATE_MAXON_DECLARATION(T, Name, id, getInstanceBody, storage) \
	struct Name##PrivateHelper \
	{ \
		using DeclarationType = maxon::Declaration<T, Name##PrivateHelper>; \
		using Registry = MaxonRegistry; \
		static constexpr maxon::LiteralId GetId() { return maxon::LiteralId(false, id); } \
		static inline const DeclarationType& GetInstance() getInstanceBody \
		static constexpr const maxon::Char* const HEADER = __FILE__; \
		static const maxon::Bool DEPENDENCIES_ENABLED = MAXON_CONCAT(MAXON_DEPENDENCY_ENABLE, true); \
	}; \
	storage Name##PrivateHelper::DeclarationType Name


#define PRIVATE_MAXON_DECLARATION_REGISTER_1(cnt, Name) \
	PRIVATE_MAXON_REGISTER_CHECK("MAXON_DECLARATION_REGISTER"); \
	static maxon::Result<decltype(Name)::Type> Private_InitObj##cnt (MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id&); \
	static maxon::ObjectDefinition g_obj##cnt(decltype(Name)::GetId(), &Private_InitObj##cnt, (decltype(Name)::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
	static maxon::Result<decltype(Name)::Type> Private_InitObj##cnt (MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id& objectId)

#define PRIVATE_MAXON_DECLARATION_REGISTER_2(cnt, REGISTRY, Name) \
	PRIVATE_MAXON_REGISTER_CHECK("MAXON_DECLARATION_REGISTER"); \
	static maxon::Result<REGISTRY::EntryType> Private_InitObj##cnt (MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id&); \
	static maxon::ObjectDefinition g_obj##cnt(maxon::ObjectDefinition::MakeId(Name), &Private_InitObj##cnt, (REGISTRY::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::HIDDEN); \
	static maxon::Result<REGISTRY::EntryType> Private_InitObj##cnt (MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id& objectId)

#define PRIVATE_MAXON_DECLARATION_REGISTER_A(N, CNT, ...) PRIVATE_MAXON_DECLARATION_REGISTER_B(N, CNT, __VA_ARGS__)
#define PRIVATE_MAXON_DECLARATION_REGISTER_B(N, CNT, ...) PRIVATE_MAXON_DECLARATION_REGISTER_C(N, CNT, __VA_ARGS__)
#define PRIVATE_MAXON_DECLARATION_REGISTER_C(N, CNT, ...) MAXON_EXPAND(PRIVATE_MAXON_DECLARATION_REGISTER_##N(CNT, __VA_ARGS__))


//----------------------------------------------------------------------------------------
/// MAXON_DECLARATION_REGISTER defines a published object which has been declared in a header file by MAXON_DECLARATION.
/// This macro has to be in a source file of a single module.
/// The macro has to be followed by a code block which initializes the object. To be able to do so, the block
/// receives a parameter named @c objectId which contains the public Id of the object (this is the same as <tt>Name.GetId()</tt>),
/// and it has to return the initialized object or an error (the return type of the code block is a @c Result).
///
/// The identifier is given in the ... argument. There are three possibilities:
/// - You can use the name of a MAXON_DECLARATION from a header file if you want to define its value:<br>
///		<tt>MAXON_DECLARATION_REGISTER(Dimensions::Length)</tt><br>
///   If the MAXON_DECLARATION is within a registry namespace, the object will also be added to the corresponding registry.
/// - You can specify the name of a registry and a unique identifier. In this case the object will be added
///   to the registry:<br>
///   <tt>MAXON_DECLARATION_REGISTER(ExecutionJobs, "net.maxon.execution.unittests")</tt>
/// - You can register the object using a unique identifier, but this is rarely used:<br>
///   <tt>MAXON_DECLARATION_REGISTER("com.foo.myobject")</tt>
///
/// Example:
/// @code
///	MAXON_DECLARATION_REGISTER(Dimensions::Length)
///	{
///		return g_baseDimensions[Int(BASE_DIMENSION::LENGTH)];
///	}
/// @endcode
/// See MAXON_DECLARATION for a complete example showing also the header file part.
/// @param[in] ...								Here you have to specify either one or two arguments:
/// 															- If you use a single argument, this has to be the name of the MAXON_DECLARATION which shall be defined,
/// 															or a unique identifier to use for the registration,
/// 															- If you use two arguments, the first has to name a registry and the second the identifier to use for the registration.
/// 															The object will then be added to the registry.
/// @see @ref object_definition
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_REGISTER(...) PRIVATE_MAXON_DECLARATION_REGISTER_A(MAXON_VA_NARGS(__VA_ARGS__), __COUNTER__, __VA_ARGS__)


// Used internally in register.h and for MAXON_DATATYPE_LOCAL
#define PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Name, prefix, id) \
	prefix Name##PrivateHelper::DeclarationType prefix Name(maxon::LiteralId(false, id), &maxon::g_translationUnit);


#ifdef MAXON_DEPENDENCY_ENABLE
//----------------------------------------------------------------------------------------
/// MAXON_DEPENDENCY_REGISTER is used in conjunction with MAXON_DEPENDENCY to establish additional dependencies
/// between source files within the same module. Each source file which has or includes a MAXON_DEPENDENCY with some Name depends on the
/// single source file which has a corresponding MAXON_DEPENDENCY_REGISTER (with the same Name). This means
/// that the object system will initialize the source file with the registration before all depending source files.
/// Example:
/// @code
/// // use this in dependent source or header files
/// MAXON_DEPENDENCY(configuration);
///
/// // use this in a single source file
/// MAXON_DEPENDENCY_REGISTER(configuration);
/// @endcode
///
/// @param[in] Name								Name of the dependency. This has to be unique within the current namespace.
/// @see @ref manual_dep
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_REGISTER(Name) \
	maxon::EntityDefinition g_dependency_##Name(maxon::EntityBase::TYPE::DEPENDENCY, maxon::LiteralId(#Name), &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::HIDDEN);
#endif

#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
//----------------------------------------------------------------------------------------
/// MAXON_DEPENDENCY is used in conjunction with MAXON_DEPENDENCY_REGISTER. It has to be in the same
/// namespace as the corresponding MAXON_DEPENDENCY_REGISTER.
///
/// @param[in] Name								Name of the dependency.
/// @see MAXON_DEPENDENCY_REGISTER
/// @see @ref manual_dep
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY(Name) \
	extern maxon::EntityDefinition g_dependency_##Name; \
	static maxon::EntityUse s_ud_##Name("." #Name, &maxon::g_translationUnit, &g_dependency_##Name);

#else
#define MAXON_DEPENDENCY(Name)
#endif

/// @}

} // namespace maxon

#endif // MODULE_H__
