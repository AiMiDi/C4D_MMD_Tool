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

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(EntityReference);

	EntityBase _super; ///< Base object with general entity information.

	EntityReference* _nextOfModule; ///< Next in singly linked list of references of the module.
	EntityReference* _nextOfDefinition; ///< Next in singly linked list of references of the definition to which this reference points.
	EntityDefinition* _definition; ///< The resolved definition, or nullptr.

	friend class ObjectModel;
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
	EntityUse(const Char* idValue, TranslationUnit* unit, EntityDefinition* def);

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
/// An OptionalUse object marks an @#include of the current cpp source file (translation unit) as optional.
/// @see MAXON_DEPENDENCY_WEAK
//----------------------------------------------------------------------------------------
class OptionalUse
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an OptionalUse for the given header file name and adds it to the list of optional uses of the current translation unit.
	/// @param[in] unit								The translation unit containing the optional use.
	/// @param[in] header							The header file name (including namespace directories) whose declared entities shall be considered as optional for the current translation unit.
	//----------------------------------------------------------------------------------------
	OptionalUse(TranslationUnit* unit, const Char* header) : _header(header)
	{
		unit->AddOptionalUse(this);
	}

private:
	const OptionalUse* _nextOfUnit; ///< Next in singly linked list of optional uses of the current translation unit.
	const Char* _header; ///< Header file name (including namespace directories) which shall be considered optional.

	friend class TranslationUnit;
	friend class ObjectModel;
};

void TranslationUnit::AddOptionalUse(OptionalUse* use)
{
	use->_nextOfUnit = _optionalUses;
	_optionalUses = use;
}

/// @endcond


//----------------------------------------------------------------------------------------
/// This macro specifies that the entities included from the given header file shall be considered as optional for the current translation unit.
/// This means that they need not be available in order for the current translation unit to work, so that the current translation unit can
/// be initialized even if some of the entities from the included header file could not be resolved or initialized.
/// You have to make sure in your own code to check if the optional entities are actually available when you need them. Example:
/// @code
/// #include "maxon/llvm.h"
/// MAXON_DEPENDENCY_WEAK("maxon/llvm.h");
/// ...
/// if (LlvmModuleInterface::_interface.IsInitialized())
/// {
///   ... LlvmModuleInterface can be used, do something with it ...
/// }
/// @endcode
/// @param[in] header							The header file whose declared entities shall be considered as optional for the current translation unit.
/// 															This has to be the file name, prefixed by its namespace directories such as <tt>"maxon/llvm.h"</tt>.
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_WEAK(header) static maxon::OptionalUse MAXON_CONCAT(s_optionalUse_, __COUNTER__)(&maxon::g_translationUnit, header)

/// @}

} // namespace maxon

#endif // ENTITY_H__
