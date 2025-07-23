#ifndef ENTITY_H__
#define ENTITY_H__

#include "maxon/apibase.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

/// @cond INTERNAL

class InterfaceReference;

//----------------------------------------------------------------------------------------
/// An EntityDefinition exists once per entity in the whole program (see EntityBase). For example, a non-virtual interface
/// (declared by MAXON_INTERFACE_NONVIRTUAL) is defined by MAXON_IMPLEMENTATION and
/// MAXON_IMPLEMENTATION_REGISTER, these macros implicitly create an entity definition object.
///
/// The set of all entity definitions of a translation unit can be accessed as a linked list
/// using TranslationUnit::GetDefinitions.
///
/// The classes NonvirtualInterfaceImplementation, ObjectDefinition, ModuleInfo, InitializationFunctions etc. should be considered as subclasses of
/// EntityDefinition, although they just have an EntityDefinition object as their first member. This is
/// needed for technical reasons, because if they were real subclasses, they wouldn't be standard-layout classes in the
/// sense of C++, and there would be no guarantee that they have the same layout among different compilers.
///
/// @see EntityBase
//----------------------------------------------------------------------------------------
class EntityDefinition
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs the entity definition object and adds it to the definition list of the current translation unit.
	/// @param[in] type								Entity type.
	/// @param[in] idValue						Entity identifier (usually unique, see EntityBase).
	/// @param[in] unit								The translation unit containing the definition.
	/// @param[in] file								Source file name.
	/// @param[in] flags							Property flags for the entity object.
	//----------------------------------------------------------------------------------------
	EntityDefinition(EntityBase::TYPE type, LiteralId&& idValue, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags = EntityBase::FLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Constructs the entity definition object and adds it to the definition list of the current translation unit.
	/// @param[in] reference					The corresponding entity reference of the module which contains the definition.
	/// @param[in] unit								The translation unit containing the definition.
	/// @param[in] file								Source file name.
	/// @param[in] flags							Property flags for the entity object.
	//----------------------------------------------------------------------------------------
	EntityDefinition(const EntityReference& reference, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Tells if the entity definition is enabled. Entity definitions can be enabled/disabled by the configuration database.
	/// If a definition is disabled, then also all other definitions which depend on the disabled definition cannot be used.
	/// However, IsEnabled() returns true for them, i.e., IsEnabled is false only for the directly disabled definitions.
	/// @return												Is this definition enabled?
	//----------------------------------------------------------------------------------------
	Bool IsEnabled() const
	{
		return (_super.GetFlags() & EntityBase::FLAGS::DISABLED) == EntityBase::FLAGS::NONE;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the base object which stores general entity information about this EntityDefinition.
	/// Ideally, this would be done by having EntityBase as superclass, but then EntityDefinition wouldn't be a standard-layout class.
	/// @return												Base object of this entity definition.
	//----------------------------------------------------------------------------------------
	const EntityBase& GetBase() const
	{
		return _super;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the next definition in the singly linked list of all definitions of a translation unit.
	/// @return												Next definition of the translation unit.
	//----------------------------------------------------------------------------------------
	const EntityDefinition* GetNextOfUnit() const
	{
		return _nextOfUnit;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the entity definition object to its initial state. The initial state is the state right after the C++ initialization
	/// of non-local variables has completed. This function is invoked on shutdown of a module or the whole application
	/// to allow for a later re-initialization.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_super.Reset();
		_references = nullptr;
	}

	const EntityReference* GetModuleReference() const
	{
		return _moduleReference;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the head of a singly linked list of references to this definition.
	/// @return												First reference of this definition.
	//----------------------------------------------------------------------------------------
	const EntityReference* GetReferences() const
	{
		return _references;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(EntityDefinition);

	EntityBase _super; ///< Base object with general entity information.

	EntityDefinition* _nextOfUnit; ///< Next in singly linked list of definitions of unit.
	EntityReference* _references; ///< Head of singly linked list of references to this definition.
	const EntityReference* _moduleReference; ///< Reference of the definition's module to the definition.

	friend class TranslationUnit;
	friend class ObjectModel;

	friend const InterfaceReference* GetVirtualInterfaceReference(const Id& iid); // TODO: (Ole) only needed temporarily
};

//----------------------------------------------------------------------------------------
/// An EntityReference exists once per module, it is a reference to an EntityDefinition which is resolved
/// by the object system. For example, a non-virtual interface declared by MAXON_INTERFACE_NONVIRTUAL leads
/// to an EntityReference which is resolved to the corresponding implementation. EntityReference
/// objects are global objects, they are defined implicitly by various macros (such as MAXON_INTERFACE_NONVIRTUAL)
/// and the file register.cpp which is automatically created by the source processor.
///
/// The set of all entity references of a module is managed by the module as a linked list.
///
/// The classes NonvirtualInterfaceReference, Declaration etc. should be considered as subclasses of
/// EntityReference, although they just have an EntityReference object as their first member. This is
/// needed for technical reasons, because if they were real subclasses, they wouldn't be standard-layout classes in the
/// sense of C++, and there would be no guarantee that they have the same layout among different compilers.
//----------------------------------------------------------------------------------------
class EntityReference
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an entity reference and adds it to the reference list of the current ModuleInfo (moduleInfo._references).
	/// @param[in] type								Entity type.
	/// @param[in] idValue						Entity identifier (usually unique, see EntityBase).
	/// @param[in] unit								The translation unit containing the reference.
	/// @param[in] flags							Property flags for the entity object.
	//----------------------------------------------------------------------------------------
	EntityReference(EntityBase::TYPE type, LiteralId&& idValue, TranslationUnit* unit, EntityBase::FLAGS flags = EntityBase::FLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Constructs an entity reference and adds it to the reference list of the current ModuleInfo (moduleInfo._references).
	/// @param[in] type								Entity type.
	/// @param[in] idValue						Entity identifier (usually unique, see EntityBase).
	/// @param[in] unit								The translation unit containing the reference.
	/// @param[in] module							The module containing the reference.
	//----------------------------------------------------------------------------------------
	EntityReference(EntityBase::TYPE type, LiteralId&& idValue, TranslationUnit* unit, ModuleInfo* module);

	//----------------------------------------------------------------------------------------
	/// Constructs an entity reference and adds it to the reference list of the current ModuleInfo (moduleInfo._references).
	/// @param[in] type								Entity type.
	/// @param[in] idValue						Entity identifier (usually unique, see EntityBase).
	/// @param[in] unit								The translation unit containing the reference.
	/// @param[in] flags							Property flags for the entity object.
	//----------------------------------------------------------------------------------------
	EntityReference(EntityBase::TYPE type, const Char* idValue, TranslationUnit* unit, EntityBase::FLAGS flags = EntityBase::FLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Returns true if the reference has been initialized successfully. This means that the reference has been resolved
	/// to a definition which itself has been initialized successfully, so that it can be used.
	/// @return												True if reference and corresponding definition have been initialized successfully.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return ((_super.GetFlags() & EntityBase::FLAGS::INITIALIZED) != EntityBase::FLAGS::NONE)
			&& _definition && ((_definition->GetBase().GetFlags() & EntityBase::FLAGS::INITIALIZED) != EntityBase::FLAGS::NONE);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the base object which stores general entity information about this EntityReference.
	/// Ideally, this would be done by having EntityBase as superclass, but then EntityReference wouldn't be a standard-layout class.
	/// @return												Base object of this EntityReference.
	//----------------------------------------------------------------------------------------
	const EntityBase& GetBase() const
	{
		return _super;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the entity definition to which this reference resolves. If this reference has not yet been resolved,
	/// or could not be resolved, the result is nullptr.
	/// @return												Resolved EntityDefinition, or nullptr.
	//----------------------------------------------------------------------------------------
	const EntityDefinition* GetDefinition() const
	{
		return _definition;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the entity reference object to its initial state. The initial state is the state right after the C++ initialization
	/// of non-local variables has completed. This function is invoked on shutdown of a module or the whole application
	/// to allow for a later re-initialization.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_super.Reset();
		_nextOfDefinition = nullptr;
		_definition = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the next module in the list
	//----------------------------------------------------------------------------------------
	const EntityReference* GetNextOfModule() const
	{
		return _nextOfModule;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(EntityReference);

	const void* InitializeDeclaration(const void* def) const;

	EntityBase _super; ///< Base object with general entity information.

	EntityReference* _nextOfModule; ///< Next in singly linked list of references of the module.
	EntityReference* _nextOfDefinition; ///< Next in singly linked list of references of the definition to which this reference points.
	EntityDefinition* _definition; ///< The resolved definition, or nullptr.

	friend class ObjectModel;
	template <typename T, typename C> friend class Declaration;
};

class NonvirtualInterfaceReference;
class NonvirtualMTableReference;


//----------------------------------------------------------------------------------------
/// EntityUse objects are implicitly created as static objects for each included entity reference, i.e., they exist
/// once per included reference per cpp source file. For example, if a file with a MAXON_INTERFACE_NONVIRTUAL is included,
/// this will create an EntityUse object for that interface. EntityUse objects are used by the object system
/// to determine which entities are needed by a source file (TranslationUnit), so that an initialization order
/// can be computed which respects dependencies.
//----------------------------------------------------------------------------------------
class EntityUse
{
public:
	// Constructs an EntityUse for a reference, see Construct.
	EntityUse(const EntityReference& ref, TranslationUnit* unit, const Char* header, Bool weak);

	// Constructs an EntityUse for MAXON_DEPENDENCY or MAXON_DEPENDENCY_ON_MODULE, see Construct.
	EntityUse(const Char* idValue, TranslationUnit* unit, EntityDefinition* def, Bool weak);

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the target entity of this use.
	/// @return												Entity identifier.
	//----------------------------------------------------------------------------------------
	const Char* GetId() const;

	EntityBase::TYPE GetType() const;

	//----------------------------------------------------------------------------------------
	/// Resets the EntityUse object to its initial state. The initial state is the state right after the C++ initialization
	/// of non-local variables has completed. This function is invoked on shutdown of a module or the whole application
	/// to allow for a later re-initialization.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_definition = _origDefinition;
	}

private:
	//----------------------------------------------------------------------------------------
	/// Constructs an EntityUse for the given entity and adds it to the list of uses of the current translation unit.
	/// @param[in] idValue						Entity identifier (only needed for MAXON_DEPENDENCY and MAXON_DEPENDENCY_ON_MODULE).
	/// @param[in] unit								The translation unit containing the use.
	/// @param[in] header							The header file (including namespace directories) in which the entity is declared, can be nullptr. This is needed for MAXON_DEPENDENCY_WEAK.
	/// @param[in] def								Only needed for MAXON_DEPENDENCY: The corresponding entity definition. Otherwise nullptr.
	/// @param[in] ref								The used entity reference, may be nullptr.
	/// @param[in] weak								True if this use shall establish only a weak dependency.
	//----------------------------------------------------------------------------------------
	void Construct(const Char* idValue, TranslationUnit* unit, const Char* header, EntityDefinition* def, const EntityReference* ref, Bool weak);

	EntityUse* _nextOfUnit; ///< Next in singly linked list of entity uses of the current translation unit.
	EntityDefinition* _definition; ///< Definition whose use is indicated by this EntityUse. May be nullptr initially, will be resolved later.
	EntityDefinition* _origDefinition; ///< Original value of _definition right after the constructor has finished.
	EntityReference* _reference; ///< Reference to which this use belongs.
	const Char* _header; ///< The header file (including namespace directories) in which the entity is declared, may be nullptr. MAXON_DEPENDENCY_WEAK uses this information.
	const Char* _id; ///< Entity identifier.
	Bool _weak; ///< True if this EntityUse stands for a weak dependency.

	friend class TranslationUnit;
	friend class ObjectModel;
};


//----------------------------------------------------------------------------------------
/// A WeakUse object marks an @#include or an EntityReference of the current cpp source file (translation unit) as optional.
/// @see MAXON_DEPENDENCY_WEAK
//----------------------------------------------------------------------------------------
class WeakUse
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a WeakUse for the given header file name and adds it to the list of weak uses of the current translation unit.
	/// @param[in] unit								The translation unit containing the weak use.
	/// @param[in] header							The header file name (including namespace directories) whose declared entities shall be considered as weak dependencies for the current translation unit.
	//----------------------------------------------------------------------------------------
	WeakUse(TranslationUnit* unit, const Char* header) : _header(header), _reference(nullptr)
	{
		unit->AddWeakUse(this);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a WeakUse for the given header file name and adds it to the list of weak uses of the current translation unit.
	/// @param[in] unit								The translation unit containing the weak use.
	/// @param[in] reference					The header file name (including namespace directories) whose declared entities shall be considered as weak dependencies for the current translation unit.
	//----------------------------------------------------------------------------------------
	WeakUse(TranslationUnit* unit, const EntityReference& reference) : _header(nullptr), _reference(&reference)
	{
		unit->AddWeakUse(this);
	}

private:
	const WeakUse* _nextOfUnit; ///< Next in singly linked list of weak uses of the current translation unit.
	const Char* const _header; ///< Header file name (including namespace directories) which shall be considered a weak dependency.
	const EntityReference* const _reference; ///< Entity reference which shall be a weak dependency.

	friend class TranslationUnit;
	friend class ObjectModel;
};

void TranslationUnit::AddWeakUse(WeakUse* use)
{
	use->_nextOfUnit = _weakUses;
	_weakUses = use;
}

/// @endcond


//----------------------------------------------------------------------------------------
/// This macro can be used to reduce a dependency on a header file or entity to a weak dependency.
///
/// By default, all entities included from a header file are strong dependencies for the current translation unit (cpp file).
/// This means that they have to be available in order for the current translation unit to work.
/// With MAXON_DEPENDENCY_WEAK you can weaken this so that the current translation unit can
/// be initialized even if the weakly referenced entities could not be resolved or initialized.
///
/// You have to check in your own code if the weakly referenced entities are actually available when you need them.
///
/// This example shows how to set up a weak dependency for an interface:
/// @code
/// #include "maxon/llvm.h"
///
/// // This marks all entities included from "maxon/llvm.h" as weak dependencies.
/// MAXON_DEPENDENCY_WEAK("maxon/llvm.h");
///
/// // Alternatively, you can mark a specific entity as weak dependency.
/// MAXON_DEPENDENCY_WEAK(LlvmModuleInterface::_interface);
///
/// ...
/// if (LlvmModuleInterface::_interface.IsInitialized())		// Before using LlvmModuleInterface, check if it is available.
/// {
///   ... LlvmModuleInterface can be used, do something with it ...
/// }
/// @endcode
///
/// This example shows how to set up a weak dependency for a MAXON_DECLARATION:
/// @code
/// #include "maxon/mediasession_stream.h"
/// MAXON_DEPENDENCY_WEAK(MediaStreamExifDataClass);
///
/// ...
/// if (MediaStreamExifDataClass.IsInitialized())
/// {
///   ...
/// }
/// @endcode
/// @param[in] headerOrEntity			This can be either the name of a header file whose declared entities shall be weak dependencies for the current translation unit
/// 															(use the file name, prefixed by its namespace directories such as <tt>"maxon/llvm.h"</tt>)
/// 															or it can be a single entity such as LlvmModuleInterface::_interface or MediaStreamExifDataClass.
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_WEAK(headerOrEntity) static maxon::WeakUse MAXON_CONCAT(s_weakUse_, __COUNTER__)(&maxon::g_translationUnit, headerOrEntity)


template <typename T, T... VALUES> struct FixedSizeArrayWrapperType
{
	static const T value[sizeof...(VALUES)];
};

template <typename T, T... VALUES> const T FixedSizeArrayWrapperType<T, VALUES...>::value[sizeof...(VALUES)] = {VALUES...};

template <typename D, typename INDICES> struct PrivateFixedSizeArrayBuilder;

template <typename D, size_t... INDEX> struct PrivateFixedSizeArrayBuilder<D, std::index_sequence<INDEX...>>
{
	using type = FixedSizeArrayWrapperType<Char, D::PrivateImplementationModule[INDEX]...>;
};

template <TranslationUnit& UNIT, UInt64 UNIT_HASH, Bool WEAK, typename NAME> const maxon::EntityUse g_PrivateDependencyOnModule{NAME::value, &UNIT, nullptr, WEAK};


//----------------------------------------------------------------------------------------
/// MAXON_DEPENDENCY_ON_MODULE adds a dependency of the current module on the specified module.
/// Use this if you want to make sure that the specified module has been initialized before this
/// module is initialized. Normally a proper module initialization order is already ensured
/// by the @ref auto_dep "automatic dependencies", so you need this only in rare cases of
/// dependencies that go beyond what automatic dependencies can detect.
/// @code
/// // Adding dependency from current module to "net.maxon.nodes".
/// MAXON_DEPENDENCY_ON_MODULE("net.maxon.nodes");
/// @endcode
/// @param[in] module							Module on which the current module shall depend (remember not to append ".module" as it is not part of the Id).
/// @see @ref manual_dep
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_ON_MODULE(module) PRIVATE_MAXON_DEPENDENCY_ON_MODULE_A(module, __COUNTER__)

#define PRIVATE_MAXON_DEPENDENCY_ON_MODULE_A(module, id) PRIVATE_MAXON_DEPENDENCY_ON_MODULE_B(module, id)
#define PRIVATE_MAXON_DEPENDENCY_ON_MODULE_B(module, id) PRIVATE_MAXON_DEPENDENCY_ON_MODULE_C(module, id)
#define PRIVATE_MAXON_DEPENDENCY_ON_MODULE_C(module, id) \
	namespace { struct PrivateModuleDependency##id { static constexpr const maxon::Char PrivateImplementationModule[] = module; }; } \
	inline const maxon::EntityUse* const s_moddep_##id \
	= &maxon::g_PrivateDependencyOnModule<maxon::g_translationUnit, maxon::g_translationUnitHash, false, maxon::PrivateFixedSizeArrayBuilder<PrivateModuleDependency##id, std::make_index_sequence<SIZEOF(module)>>::type>;


//----------------------------------------------------------------------------------------
/// This macro can be added to an interface or object declaration to tell in which module
/// the corresponding definition is made. This is an optional information and helps to reduce
/// the size of binaries:
/// - Without that information, each cpp file which includes the declaration's header file
///   registers an own dependency on the definition.
/// - With MAXON_IMPLEMENTATION_MODULE, only a dependency on the module is registered, and that's
///   shared for all declarations within a cpp file.
/// Use this with care: Dependency tracking becomes less precise, and a failure of the initialization
/// of the definition doesn't automatically deactivate dependent cpp files.
/// So you should only make use of it for declarations whose definitions will never fail,
/// and also only if the declarations are expected to be included in a lot of cpp files
/// so that there's a significant reduction of binary sizes.
///
/// The usage of the macro for a non-virtual interface looks as follows:
/// @code
/// class DataDictionaryInterface
/// {
/// 	MAXON_INTERFACE_NONVIRTUAL(DataDictionaryInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.datadictionary", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));
/// 	...
/// };
/// @endcode
/// The corresponding implementation (MAXON_IMPLEMENTATION) has to be in the module "net.maxon.kernel".
///
/// For a virtual interface the usage is similar:
/// @code
/// class InputStreamInterface : MAXON_INTERFACE_BASES(BaseStreamInterface)
/// {
/// 	MAXON_INTERFACE(InputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.inputstream", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));
/// 	...
/// };
/// @endcode
/// However, this doesn't restrict implementations of the interface -- a virtual interface can have an arbitrary number of implementations, spread over several modules.
/// It only tells that the bare interface is registered as part of the "net.maxon.kernel" module,
/// namely via the FrameworkRegistration setting in projectdefinition.txt.
/// If a virtual interface has static methods, their implementation (MAXON_STATIC_REGISTER) has to be in the specified module.
///
/// For a declaration, write
/// @code
/// MAXON_DECLARATION(Class<UnitTestRef>, UnitTestBaseClass, "net.maxon.class.unittestbase", MAXON_IMPLEMENTATION_MODULE("net.maxon.misc"));
/// @endcode
/// and place the corresponding definition (MAXON_DECLARATION_REGISTER) in the specified module. You can also apply the macro to a datatype declaration:
/// @code
/// MAXON_DATATYPE(Id, "net.maxon.datatype.id", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));
/// @endcode

/// @param[in] module							Identifier of the module which defines the entity.
//----------------------------------------------------------------------------------------
#define MAXON_IMPLEMENTATION_MODULE(module) public: static constexpr const maxon::Char PrivateImplementationModule[] = module; private:


/// @}

} // namespace maxon

#endif // ENTITY_H__
