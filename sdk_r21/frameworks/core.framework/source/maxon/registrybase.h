#ifndef REGISTRYBASE_H__
#define REGISTRYBASE_H__

#include "maxon/module.h"
#include "maxon/foreach.h"
#include "maxon/datatypelib.h"
#include "maxon/genericdata.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

/// @cond INTERNAL

//----------------------------------------------------------------------------------------
/// RegistryEntryIteratorInterface is used internally by Registry::Iterator.
/// It should not be used directly.
//----------------------------------------------------------------------------------------
class RegistryEntryIteratorInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RegistryEntryIteratorInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.registryentryiterator");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] iterator						TODO: (Ole) please document.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void Free(const RegistryEntryIteratorInterface* iterator);

	MAXON_METHOD Bool HasValue() const;

	MAXON_METHOD void MoveToNext();

	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD ConstDataPtr GetEntry() const;
};

//----------------------------------------------------------------------------------------
/// RegistryInterface is used internally by Registry.
/// It should not be used directly.
//----------------------------------------------------------------------------------------
class RegistryInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RegistryInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.registry");

public:
	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD UInt GetStamp() const;

	MAXON_METHOD const DataType& GetDataType() const;

	//----------------------------------------------------------------------------------------
	/// Adds an observer to this registry which is informed about addition or removal of entries.
	/// @param[in] observer						A callback to receive the notifications.
	/// @return												An object to which the lifetime of the added observer is bound. You have to keep
	///																this alive as long as the observer shall be informed by the registry.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericData> AddObserver(Delegate<void(const Id& eid, const ConstDataPtr& value, Bool inserted)>&& observer, Bool notifyDuringRegistration) const;

	//----------------------------------------------------------------------------------------
	/// Finds the registry with the given identifier. If no such registry exists, returns nullptr.
	/// @param[in] registry						Id of the registry to find.
	/// @return												Found registry, or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const RegistryInterface* Find(const Id& registry);


	//----------------------------------------------------------------------------------------
	/// Registers an entry at the registry under the given identifier.
	/// If an entry already exists for the identifier, nothing happens, and an IllegalStateError is returned.
	/// For an RAII-like registration with automatic removal use Register instead.
	/// @param[in] registry						Pointer to the registry, may be nullptr in which case an IllegalArgumentError is returned.
	/// @param[in] eid								Identifier within this registry.
	/// @param[in] value							Value to register.
	/// @param[in] module							The module which initiates the call. When the module is freed, the entry will be freed too.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module);

	//----------------------------------------------------------------------------------------
	/// Removes the entry identified by eid from registry.
	/// If no such entry exists, nothing happens.
	/// @param[in] registry						Pointer to the registry, may be nullptr in which case an IllegalArgumentError is returned.
	/// @param[in] eid								Identifier of the entry to be removed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> EraseEntry(const RegistryInterface* registry, const Id& eid);

	//----------------------------------------------------------------------------------------
	/// Registers an entry at the registry under the given identifier.
	/// If an entry already exists for the identifier, nothing happens, and an IllegalStateError is returned.
	/// The entry will be removed when the lifetime of the object wrapped in the return value ends.
	/// @param[in] registry						Pointer to the registry, may be nullptr in which case an IllegalArgumentError is returned.
	/// @param[in] eid								Identifier within this registry.
	/// @param[in] value							Value to register.
	/// @return												An object to which the lifetime of the added entry is bound. You have to keep
	///																this alive as long as the entry shall remain in the registry.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GenericData> Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value);

	static MAXON_METHOD ConstDataPtr FindEntryValue(const RegistryInterface* registry, const Id& eid);

	static MAXON_METHOD RegistryEntryIteratorInterface* PrivateCreateIterator(const RegistryInterface* registry);

	static MAXON_FUNCTION ResultPtr<RegistryEntryIteratorInterface> CreateIterator(const RegistryInterface* registry)
	{
		return PrivateCreateIterator(registry);
	}
};


class RegistryReference
{
public:
	RegistryReference(LiteralId&& rid, TranslationUnit* unit, EntityBase::FLAGS flags) : _super(EntityBase::TYPE::REGISTRY, std::move(rid), unit, flags)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns referenced registry. This is only valid after a successful initialization.
	/// @return												The registry.
	//----------------------------------------------------------------------------------------
	const RegistryInterface* GetRegistry() const
	{
		return _registry;
	}

private:
	EntityReference _super; ///< EntityReference base object.
	const RegistryInterface* _registry; ///< The registry.
	friend class ObjectModel;
};


/// @endcond

//----------------------------------------------------------------------------------------
/// A Registry manages a set of entries of the same type.
/// E.g., all classes are registered at the registry Classes, while
/// all data types are registered at DataTypes.
///
/// Registries are declared by the macro MAXON_REGISTRY as derived classes
/// of Registry with the template parameter R being the derived class.
/// For the entries all types are supported which are supported by Data.
///
/// Each registry is identified by a unique identifier.
///
/// @tparam T											Type of the values which are stored at the registry. Has to be supported by Data.
/// @tparam R											Registry class (created by the macro MAXON_REGISTRY).
//----------------------------------------------------------------------------------------
template <typename T, typename R> class Registry
{
public:
	using Dependencies = Tuple<>;
	static const EntityBase::FLAGS ENTRY_FLAGS = EntityBase::FLAGS::NONE;

	using EntryType = T; ///< The type of entries stored at this registry.

	class IteratorBase
	{
	public:
		inline const T* operator ->() const;

		const T& operator *() const
		{
			return *this->operator ->();
		}

	protected:
		UniqueRef<RegistryEntryIteratorInterface> _iterator;
	};

	class IdIteratorBase : public IteratorBase
	{
	public:
		Tuple<const Id&, const T&> operator *() const
		{
			return Tuple<const Id&, const T&>(this->_iterator->GetId(), *this->operator ->());
		}
	};

	//----------------------------------------------------------------------------------------
	/// An Iterator is returned by GetEntries() to iterate over all registered entries
	/// of an registry. If allows only uni-directional iteration and supports the
	/// foreach-protocol.
	//----------------------------------------------------------------------------------------
	template <typename IT> class IteratorTemplate : public ForEachIterator<IteratorTemplate<IT>, IT>
	{
	public:
		IteratorTemplate() { }
		IteratorTemplate(IteratorTemplate&& src) { this->_iterator = std::move(src._iterator); }

		void operator ++()
		{
			if (this->_iterator)
				this->_iterator->MoveToNext();
		}

		void operator ++(int)
		{
			operator ++();
		}

		explicit operator Bool() const
		{
			return this->_iterator && this->_iterator->HasValue();
		}

		const Id& GetId() const
		{
			return this->_iterator->GetId();
		}

	private:
		explicit IteratorTemplate(RegistryEntryIteratorInterface* it) { this->_iterator = it; }

		MAXON_DISALLOW_COPY_AND_ASSIGN(IteratorTemplate);

		friend class Registry;
	};

	using Iterator = IteratorTemplate<IteratorBase>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator over all entries registered at this registry.
	/// Because the iterator supports the foreach-protocol, you can write
	/// @code
	/// for (const Class<ExecutionRef>& execCls : ExecutionJobs::GetEntries())
	/// {
	///   ...
	/// }
	/// @endcode
	/// If you are also interested in the Id of the entry, you have to use the
	/// iterator returned by GetEntriesWithId().
	/// @return												Iterator over all entries.
	//----------------------------------------------------------------------------------------
	static Iterator GetEntries()
	{
		return Iterator(RegistryInterface::PrivateCreateIterator(R::GetRegistry()));
	}

	using IdIterator = IteratorTemplate<IdIteratorBase>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator over all entries registered at this registry.
	/// Each entry is returned as a pair of the Id and the entry itself.
	/// Because the iterator supports the foreach-protocol, you can write
	/// @code
	/// for (const auto& entry : ExecutionJobs::GetEntriesWithId())
	/// {
	///   const Id& eid = entry.GetKey();
	///   const Class<ExecutionRef>& execCls = entry.GetValue();
	///   ...
	/// }
	/// @endcode
	/// @return												Iterator over all registry entries (i.e., id-entry-pairs).
	//----------------------------------------------------------------------------------------
	static IdIterator GetEntriesWithId()
	{
		return IdIterator(RegistryInterface::PrivateCreateIterator(R::GetRegistry()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the registry entry registered at this registry under the given identifier.
	/// If no entry exists for the given identifier, nullptr is returned.
	/// @param[in] eid								Identifier within this registry.
	/// @return												Registered entry, or nullptr.
	//----------------------------------------------------------------------------------------
	static const T* Find(const Id& eid)
	{
		ConstDataPtr d = RegistryInterface::FindEntryValue(R::GetRegistry(), eid);
		return reinterpret_cast<const T*>(d.GetPtr(R::GetDataType()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the entry registered at this registry under the given identifier.
	/// If no entry exists for the given identifier, a null-value reference is returned.
	/// @param[in] eid								Identifier within this registry.
	/// @return												Registered entry, or a null-value reference.
	//----------------------------------------------------------------------------------------
	static const T& Get(const Id& eid)
	{
		const T* v = Find(eid);
		return v ? *v : maxon::NullValue<const T&>();
	}

	//----------------------------------------------------------------------------------------
	/// Registers an entry at this registry under the given identifier.
	/// If an entry already exists for the identifier, nothing happens, and an IllegalStateError is returned.
	/// @param[in] eid								Identifier within this registry.
	/// @param[in] object							Value to register.
	/// @param[in] module							The module which initiates the call. When the module is freed, the entry will be freed too.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static Result<void> Insert(const Id& eid, const T& object, const ModuleInfo* module)
	{
		return RegistryInterface::InsertEntry(R::GetRegistry(), eid, ConstDataPtr(R::GetDataType(), reinterpret_cast<const Generic*>(&object)), module);
	}

	/// @copydoc Insert
	static Result<void> Insert(const Id& eid, T&& object, const ModuleInfo* module)
	{
		return RegistryInterface::InsertEntry(R::GetRegistry(), eid, MoveDataPtr(R::GetDataType(), reinterpret_cast<Generic*>(&object)), module);
	}

	// Clang bug requires us to add this function which uses move semantics for object, but with T& as parameter type.
	// It is used by the MAXON_REGISTRY macro, which otherwise would have to write std::move(object) which would lead
	// to an error if T is incomplete or is a template specialization which depends on an incomplete type.
	static Result<void> PrivateInsert(const Id& eid, T& object, const ModuleInfo* module)
	{
		return RegistryInterface::InsertEntry(R::GetRegistry(), eid, MoveDataPtr(R::GetDataType(), reinterpret_cast<Generic*>(&object)), module);
	}

	//----------------------------------------------------------------------------------------
	/// Registers an entry at this registry under the given identifier.
	/// If an entry already exists for the identifier, nothing happens, and an IllegalStateError is returned.
	/// The entry will be removed when the lifetime of the object wrapped in the return value ends.
	/// @param[in] eid								Identifier within this registry.
	/// @param[in] object							Value to register.
	/// @return												An object to which the lifetime of the added entry is bound. You have to keep
	///																this alive as long as the entry shall remain in the registry.
	//----------------------------------------------------------------------------------------
	static Result<GenericData> Register(const Id& eid, const T& object)
	{
		return RegistryInterface::Register(R::GetRegistry(), eid, ConstDataPtr(R::GetDataType(), reinterpret_cast<const Generic*>(&object)));
	}

	/// @copydoc Register
	static Result<GenericData> Register(const Id& eid, T&& object)
	{
		return RegistryInterface::Register(R::GetRegistry(), eid, ConstDataPtr(R::GetDataType(), reinterpret_cast<const Generic*>(&object)));
	}

	// see PrivateInsert
	static Result<GenericData> PrivateRegister(const Id& eid, T& object)
	{
		return RegistryInterface::Register(R::GetRegistry(), eid, MoveDataPtr(R::GetDataType(), reinterpret_cast<Generic*>(&object)));
	}

	//----------------------------------------------------------------------------------------
	/// Removes the entry identified by eid from this registry.
	/// If no such entry exists, nothing happens.
	/// @param[in] eid								Identifier of the entry to be removed.
	//----------------------------------------------------------------------------------------
	static Result<Bool> Erase(const Id& eid)
	{
		return RegistryInterface::EraseEntry(R::GetRegistry(), eid);
	}
};

//----------------------------------------------------------------------------------------
/// Declares a registry for entries of the given type.
/// Registries serve as a registry of entries, i.e., values of a common registry-specific type.
/// E.g., all classes are registered at registry Classes, while all data types are registered at DataTypes.
/// More information about registries is given in @ref extensions.
///
/// The macro defines a namespace of the given Name within the current namespace. This allows
/// to add MAXON_DECLARATIONs to the namespace for registry entries which shall be made public in
/// header files, however it is not mandatory to publish registry entries in header files:
/// @code
/// MAXON_REGISTRY(FileFormat, FileFormats, "net.maxon.registry.fileformats");
///
/// namespace FileFormats
/// {
/// 	MAXON_DECLARATION(FileFormat, MaxonDocumentBinary, "net.maxon.fileformat.maxondocumentbinary");
/// 	MAXON_DECLARATION(FileFormat, MaxonDocumentJson, "net.maxon.fileformat.maxondocumentjson");
/// 	MAXON_DECLARATION(FileFormat, MaxonDocumentXml, "net.maxon.fileformat.maxondocumentxml");
/// }
/// @endcode
/// The naming convention for registries is to use the plural of
/// the kind of objects which will be registered at the registry
/// (for example @c DataTypes, @c IoHandlers) or, if classes are registered
/// at the registry, the kind of objects of those classes with a "Classes" suffix
/// (for example @c DataCompressionClasses, @c UnitTestClasses).
///
/// The following example declares a registry IoHandlers at which entries of type IoHandler
/// can be registered.
///
/// @param[in] T									Type of the values which are stored at the registry. Has to be supported by Data.
/// @param[in] Name								Name of the registry within the current namespace.
/// @param[in] id									Unique identifier of the registry.
/// @param[in] ...								Optional parameter of the form MAXON_REGISTRY_DEPENDENCIES(Reg1, Reg2, ...) to specify other registries on which this registry shall depend.
//----------------------------------------------------------------------------------------
#define MAXON_REGISTRY(T, Name, id, ...) \
	namespace Name \
	{ \
		using EntryType = T; \
		class Registry : public maxon::Registry<T, Registry> \
		{ \
		public: \
			__VA_ARGS__ \
			static inline maxon::Id GetId() { return maxon::Id(id); } \
			static const maxon::RegistryInterface* GetRegistry() { return _reference.GetRegistry(); } \
			static const maxon::DataType& GetDataType(); \
		private: \
			static maxon::RegistryReference _reference; \
		}; \
		using MaxonRegistry = Registry; \
		\
		inline Registry::Iterator GetEntries() { return Registry::GetEntries(); } \
		inline Registry::IdIterator GetEntriesWithId() { return Registry::GetEntriesWithId(); } \
		inline T const* Find(const maxon::Id& eid) { return Registry::Find(eid); } \
		inline T const& Get(const maxon::Id& eid) { return Registry::Get(eid); } \
		MAXON_ATTRIBUTE_FORCE_INLINE maxon::Result<void> Insert(const maxon::Id& eid, T const& object, const maxon::ModuleInfo* module = &PRIVATE_MAXON_MODULE) { return Registry::Insert(eid, object, module); } /* force inline so that correct PRIVATE_MAXON_MODULE is always used */ \
		MAXON_ATTRIBUTE_FORCE_INLINE maxon::Result<void> Insert(const maxon::Id& eid, T&& object, const maxon::ModuleInfo* module = &PRIVATE_MAXON_MODULE) { return Registry::PrivateInsert(eid, object, module); } \
		inline maxon::Result<maxon::GenericData> Register(const maxon::Id& eid, T const& object) { return Registry::Register(eid, object); } \
		inline maxon::Result<maxon::GenericData> Register(const maxon::Id& eid, T&& object) { return Registry::PrivateRegister(eid, object); } \
		inline maxon::Result<void> Erase(const maxon::Id& eid) { return Registry::Erase(eid); } \
	}

#define PRIVATE_MAXON_REGISTRY_DEPENDENCY(x, i, a) x::Registry

#define MAXON_REGISTRY_DEPENDENCIES(...) using Dependencies = maxon::Tuple<MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_REGISTRY_DEPENDENCY, , , __VA_ARGS__)>; static const maxon::EntityBase::FLAGS ENTRY_FLAGS = maxon::EntityBase::FLAGS::AT_REGISTRY_WITH_DEPENDENCIES;

#include "registrybase1.hxx"
#include "registrybase2.hxx"

/// @}

template <typename REG, typename DEPS> class RegistryModuleDefinition;

template <typename REG, typename... DEPS> class RegistryModuleDefinition<REG, Tuple<DEPS...>>
{
public:
	RegistryModuleDefinition() : _super(EntityBase::TYPE::REGISTRY_MODULE, REG::GetId(), nullptr, nullptr, EntityBase::FLAGS::NONE), _dependencyCount(sizeof...(DEPS))
	{
		MAXON_ASSERT_STANDARD_LAYOUT(RegistryModuleDefinition);
#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_GCC)
		Id deps[] = {DEPS::GetId()...};
		for (Int i = 0; i < Int(sizeof...(DEPS)); ++i)
		{
			_dependencies[i] = deps[i];
		}
#endif
	}

private:
	EntityDefinition _super; ///< Base definition object.
	const Int _dependencyCount;
#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_GCC)
	Id _dependencies[sizeof...(DEPS)];
#else
	Id _dependencies[sizeof...(DEPS)] = {DEPS::GetId()...};
#endif
	friend class ObjectModel;
};

#define PRIVATE_MAXON_REGISTRY_DEFINE_DEPENDENCIES(R) static maxon::RegistryModuleDefinition<R::Registry, R::Registry::Dependencies> g_registryModuleDefinition_##R;

class RegistryDefinition
{
public:
	template <typename REG> explicit RegistryDefinition(REG*, TranslationUnit* unit) : _super(EntityBase::TYPE::REGISTRY, REG::GetId(), unit, nullptr, REG::ENTRY_FLAGS), _type(&REG::GetDataType)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the registry. This is only valid after a successful initialization.
	/// @return												The registry.
	//----------------------------------------------------------------------------------------
	const RegistryInterface* GetRegistry() const
	{
		return _registry;
	}

private:
	EntityDefinition _super; ///< Base definition object.
	const DataType& (*_type)(); ///< Returns the datatype of the registry.
	const RegistryInterface* _registry;
	friend class ObjectModel;
	friend class RegistryImpl;
};

#define PRIVATE_MAXON_REGISTRY_DEFINE(R) static maxon::RegistryDefinition g_registryDefinition_##R((R::Registry*) nullptr, &maxon::g_translationUnit);

} // namespace maxon


#endif // REGISTRYBASE_H__
