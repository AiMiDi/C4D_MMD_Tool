#include "maxon/object.h"
#include "maxon/hashmap.h"
#include "maxon/cstdliballocator.h"
#include "maxon/stacktrace.h"
#include "maxon/weakrefservices.h"

namespace maxon
{

static_assert(std::is_trivially_destructible<TranslationUnit>::value, "TranslationUnit has to be trivially destructible.");
static_assert(std::is_trivially_destructible<EntityReference>::value, "EntityReference has to be trivially destructible.");
static_assert(std::is_trivially_destructible<EntityDefinition>::value, "EntityDefinition has to be trivially destructible.");
static_assert(std::is_trivially_destructible<EntityUse>::value, "EntityUse has to be trivially destructible.");

Binary g_maxon;
MAXON_ASSERT_STANDARD_LAYOUT(Binary);


class CharTriple
{
public:
	CharTriple(const Char* a, const Char* b, const Char* c) : _a(a), _b(b), _c(c) { }

	UInt GetHashCode() const
	{
		return (CStringCompare::GetHashCode(_a) * 31 + CStringCompare::GetHashCode(_b)) * 31 + CStringCompare::GetHashCode(_c);
	}

	Bool operator ==(const CharTriple& other) const
	{
		return (strcmp(_a, other._a) == 0) && (strcmp(_b, other._b) == 0) && (strcmp(_c, other._c) == 0);
	}

private:
	const Char* _a;
	const Char* _b;
	const Char* _c;

	friend class ConcatenatedIdData;
};

class ConcatenatedIdData;

class ConcatenatedIdMap : public HashMap<CharTriple, ConcatenatedIdData, DefaultCompare, HashMapKeyValuePair, CStdLibAllocator, true>
{
public:
	ConcatenatedIdMap() : HashMap<CharTriple, ConcatenatedIdData, DefaultCompare, HashMapKeyValuePair, CStdLibAllocator, true>(0)
	{
		SetCapacityHint(4000) iferr_ignore("It's just a hint");
	}
};

class ConcatenatedIdData
{
	// TODO: (Ole) remove GetConcatenated
	static const Int MAX_LENGTH = 1000;
public:
	explicit ConcatenatedIdData(const CharTriple& triple)
	{
		CriticalAssert((int)(strlen(triple._a) + strlen(triple._b) + strlen(triple._c)) < MAX_LENGTH);
		strcpy(_buffer, triple._a);
		strcat(_buffer, triple._b);
		strcat(_buffer, triple._c);
		MAXON_WARN_MUTE_UNUSED _id.Init(_buffer, false);
	}

	const Id& GetId()
	{
		return _id;
	}

	static Result<void> ConstructHashMapEntry(void* ptr, UInt hash, const CharTriple& key)
	{
		new (ptr) ConcatenatedIdMap::Entry(hash, key, key);
		return OK;
	}

	static Int GetHashMapEntrySize(const CharTriple& key)
	{
		return SIZEOF(ConcatenatedIdMap::Entry);
	}

private:
	Id _id;
	Char _buffer[MAX_LENGTH];
};


const Id& Id::GetConcatenated(const Char* a, const Char* b, const Char* c)
{
	DebugAssert(a && b && c);
	static ConcatenatedIdMap g_concatenatedIds;
	auto e = g_concatenatedIds.InsertCtor(CharTriple(a, b, c), *(ConcatenatedIdData*) 1).UncheckedGetValue();
	CriticalAssert(e);
	return e->GetValue().GetId();
}


InternedIdInitializer::InternedIdInitializer(InternedId* iid, const Char* str, ModuleInfo* info) : _id(iid), _str(str), _nextOfModule(info->_internedIds)
{
	info->_internedIds = this;
}


EntityBase::EntityBase(TYPE type, LiteralId&& idValue, TranslationUnit* unit, FLAGS flags) : _id(DONT_INITIALIZE)
{
	if ((!(flags & FLAGS::CLASS_PROXY) && (flags & ~FLAGS::ON_CONSTRUCTION_MASK))
			|| (unit && !idValue.GetCString() && type != TYPE::INVALID_0 && !(flags & (FLAGS::HIDDEN | FLAGS::PROXY))))
	{
		// Cannot use DebugAssert here because this checks for g_isDebuggerPresent and g_enableDebugBreak,
		// but these variables haven't been initialized yet (we are in the very early phase of global constructor invocation).
		__debugbreak();
	}
	if ((type == TYPE::INTERFACE) || (flags & FLAGS::CLASS_PROXY))
	{
		// A InterfaceDefinition is allocated with NewObj, so its memory isn't zero-initialized at first. Same for class proxies.
		_flags = FLAGS::NONE;
	}
	else if (_nextInitialized || _unit || _type != TYPE::INVALID_0)
	{
		// Otherwise, check that zero-initialization has happened. But we can't check _id or _flags because they may already have been modified.
		__debugbreak();
	}
	if ((type != TYPE::MODULE) || !(flags & FLAGS::DEFINITION) || !_id.GetCString()) // id of ModuleInfo may have been set already by register.h, then don't override it
	{
		// The _id must not use reference counting because destructors aren't called for EntityBase
		if (idValue.UsesRefCountedCString())
			__debugbreak();
		new (&_id) LiteralId(std::move(idValue));
	}
	_type = type;
	_unit = unit;
	_nextInitialized = nullptr;
	_flags |= flags | FLAGS::CONSTRUCTED;
}

Result<void> EntityBase::Initialize(const Id& cause) const
{
	CriticalAssert(g_maxon.GetInitializer());
	return (*g_maxon.GetInitializer())(const_cast<EntityBase*>(this), cause);
}


static const Char* GetFilename(const Char* file)
{
	const Char* s = strrchr(file, '/');
	if (s)
		return s + 1;
	s = strrchr(file, '\\');
	if (s)
		return s + 1;
	return file;
}

TranslationUnit::TranslationUnit(const ModuleInfo* module, const Char* file, EntityBase::FLAGS flags)
	: _super(EntityBase::TYPE::TRANSLATION_UNIT, Id(GetFilename(file)), this, flags | EntityBase::FLAGS::DEFINITION), _module(module)
{
	_nextOfModule = module->_units;
	const_cast<ModuleInfo*>(module)->_units = this;
	_groupIndex = -1;
	_sccData.Reset();
}

const Id& TranslationUnit::GetModuleId() const
{
	return _module->GetBase().GetId();
}

void TranslationUnit::AddDefinition(EntityDefinition* def)
{
	(_lastDefinition ? _lastDefinition->_nextOfUnit : _definitions) = def;
	_lastDefinition = def;
	_super._flags |= def->GetBase().GetFlags() & EntityBase::FLAGS::ADAPTER;
}

EntityDefinition::EntityDefinition(EntityBase::TYPE type, LiteralId&& idValue, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags)
	: _super(type, std::move(idValue), unit, flags | EntityBase::FLAGS::DEFINITION), _nextOfUnit(nullptr), _references(nullptr), _moduleReference(nullptr)
{
	if (unit)
	{
		unit->AddDefinition(this);
#ifndef __BASE_FILE__
		if (file)
		{
			reinterpret_cast<Id&>(unit->_super._id) = Id(GetFilename(file));
		}
#endif
	}
}

EntityDefinition::EntityDefinition(const EntityReference& reference, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags)
	: EntityDefinition(reference.GetBase().GetType(), LiteralId(reference.GetBase()._id), unit, file, flags | EntityBase::FLAGS::DEFINITION)
{
	_moduleReference = &reference;
}

namespace details
{

InitializationFunctions::InitializationFunctions(const Char* file, Result<void> (*init) (), void (*free) (), TranslationUnit* unit)
	: _super(EntityBase::TYPE::INITIALIZATION, Id(GetFilename(file)), unit, file), _init(init), _free(free)
{
}

GlobalBase::GlobalBase(const Char* name, Result<void> (*init) (GlobalBase* global), void (*free) (GlobalBase* global), TranslationUnit* unit)
	: _super(EntityBase::TYPE::GLOBAL, Id(GetFilename(name)), unit, nullptr, EntityBase::FLAGS::HIDDEN), _init(init), _free(free)
{
}

}


ModuleInfo::ModuleInfo(const Char* idValue, TranslationUnit* unit, EntityBase::FLAGS flags) : _super(EntityBase::TYPE::MODULE, Id(idValue), unit, nullptr, flags), _next(g_maxon._modules), _binary(&g_maxon)
{
	g_maxon._modules = this;
}

Block<const Id> ModuleInfo::GetUsedFrameworks() const
{
	return ToBlock(_usedFrameworks, _usedFrameworksCount);
}

const ModuleInfo* Binary::FindFramework(const Id& fid) const
{
	MAXON_ASSERT_STANDARD_LAYOUT(Binary);
	static_assert(offsetof(Binary, _abiVersion) == 0, "_abiVersion has to be first member of Binary.");
	for (const ModuleInfo* i = _modules; i; i = i->_next)
	{
		if (i->IsFramework() && (i->GetBase().GetId() == fid))
			return i;
	}
	return nullptr;
}

EntityReference::EntityReference(EntityBase::TYPE type, LiteralId&& idValue, TranslationUnit* unit, EntityBase::FLAGS flags)
	: _super(type, std::move(idValue), unit, flags)
{
	_nextOfModule = unit->GetModule()->_references;
	const_cast<ModuleInfo*>(unit->GetModule())->_references = this;
	_nextOfDefinition = nullptr;
	_definition = nullptr;
}

EntityReference::EntityReference(EntityBase::TYPE type, const Char* idValue, TranslationUnit* unit, EntityBase::FLAGS flags)
	: _super(type, Id(idValue), unit, flags)
{
	_nextOfModule = unit->GetModule()->_references;
	const_cast<ModuleInfo*>(unit->GetModule())->_references = this;
	_nextOfDefinition = nullptr;
	_definition = nullptr;
}

void TranslationUnit::AddUse(EntityUse* use)
{
	use->_nextOfUnit = _uses;
	_uses = use;
}

EntityUse::EntityUse(const EntityReference& ref, TranslationUnit* unit, const Char* header, Bool weak)
{
	Construct(nullptr, unit, header, nullptr, &ref, weak);
}

EntityUse::EntityUse(const Char* idValue, TranslationUnit* unit, EntityDefinition* def)
{
	Construct(idValue, unit, nullptr, def, nullptr, false);
}

void EntityUse::Construct(const Char* idValue, TranslationUnit* unit, const Char* header, EntityDefinition* def, const EntityReference* ref, Bool weak)
{
	// Check that exactly one of idValue and ref is given.
	if ((idValue != nullptr) == (ref != nullptr))
	{
		// Cannot use DebugAssert here because this checks for g_isDebuggerPresent and g_enableDebugBreak,
		// but these variables haven't been initialized yet (we are in the very early phase of global constructor invocation).
		__debugbreak();
	}
	unit->AddUse(this);
	_definition = def;
	_origDefinition = def;
	_reference = const_cast<EntityReference*>(ref);
	_header = header;
	_id = idValue;
	_weak = weak;
}

const Char* EntityUse::GetId() const
{
	if (_id)
		return _id;
	else
		return _reference->GetBase().GetId().GetCString();
}

EntityBase::TYPE EntityUse::GetType() const
{
	if (_id)
		return _origDefinition ? EntityBase::TYPE::DEPENDENCY : EntityBase::TYPE::MODULE;
	else
		return _reference->GetBase().GetType();
}

// called by the MAXON_INTERFACE_REGISTER macro from the register.cpp file's includes
NonvirtualInterfaceReference::NonvirtualInterfaceReference(const Char* iid, MTableBase* mtable, MTableBase* unresolvedMTable, const Char* methodIds, Int methodCount, UnresolvedInitializer initUnresolved, MTableInitializer nullResolve, TranslationUnit* unit, EntityBase::FLAGS refType)
	: _super(EntityBase::TYPE::NONVIRTUAL_INTERFACE, iid, unit, nullResolve ? refType | EntityBase::FLAGS::NULL_AS_DEFAULT : refType)
{
	_initUnresolved = initUnresolved;
	_mtable = mtable;
	_unresolvedMTable = unresolvedMTable;
	_methodIds = methodIds;
	_methodCount = methodCount;
	_nullResolve = nullResolve;
	_nullValue = nullptr;
}

// called by the MAXON_INTERFACE_REGISTER macro from the register.cpp file's includes
NonvirtualInterfaceReference::NonvirtualInterfaceReference(const Char* iid, MTableBase* mtable, MTableBase* unresolvedMTable, const Char* methodIds, Int methodCount, UnresolvedInitializer initUnresolved, TranslationUnit* unit, EntityBase::FLAGS refType)
	: _super(EntityBase::TYPE::NONVIRTUAL_INTERFACE, iid, unit, refType)
{
	_initUnresolved = initUnresolved;
	_mtable = mtable;
	_unresolvedMTable = unresolvedMTable;
	_methodIds = methodIds;
	_methodCount = methodCount;
	_nullResolve = nullptr;
	_nullValue = nullptr;
}

// called by an interface's Unresolved class while its mtable has not been resolved yet
// if the table can be initialized properly this will return true
// if false is returned the calling method of the Unresolved class will return the appropriate null value (false in case of a Bool or nullptr for any kind of pointer)
Bool NonvirtualInterfaceReference::PrivateResolve(NonvirtualInterfaceReference* this_, Bool showMessage)
{
	Result<void> r;
	if (this_->_super.GetDefinition() && ((r = this_->_super.GetDefinition()->GetBase().Initialize(this_->_super.GetBase().GetId())) == OK))
	{
		return true;
	}
	if (this_->_nullResolve)
	{
		this_->_nullResolve(this_->_mtable);
		return true;
	}
	if (showMessage)
	{
		// do not use @ as format string because this will crash when shutting down.
		OutputWithFlags(OUTPUT::DIAGNOSTIC | OUTPUT::NOLINEBREAK, "Method invocation of unresolvable interface ");
		DiagnosticOutput(this_->_super.GetBase().GetId().GetCString());
		CriticalStop();
	}
	return false;
}

InterfaceReference::InterfaceReference(const Char* iidWithoutHash, const Char* sourceName, const InterfaceReference* const* baseInterfaces, const Char* methodIds, TranslationUnit* unit, EntityBase::FLAGS refType)
	: _super(EntityBase::TYPE::INTERFACE, iidWithoutHash, unit, refType), _infoOffset(LIMIT<Int>::MIN), _type(), _basesPtr(baseInterfaces), _methodIds(methodIds), _idWithoutHash(iidWithoutHash), _sourceName(sourceName), _version(nullptr), _depth(-1)
{
}

InterfaceReference::InterfaceReference(const Char* iidWithoutHash, const Char* sourceName, const InterfaceReference* baseInterface, const Char* methodIds, TranslationUnit* unit, EntityBase::FLAGS refType)
	: InterfaceReference(iidWithoutHash, sourceName, (const InterfaceReference* const*) baseInterface, methodIds, unit, refType | EntityBase::FLAGS::SINGLE_BASE)
{
}

Block<const InterfaceReference* const> InterfaceReference::GetBases() const
{
	if (_super.GetBase().GetFlags() & EntityBase::FLAGS::SINGLE_BASE)
	{
		return {(const InterfaceReference* const*) &_basesPtr, 1};
	}
	else
	{
		Int cnt = 0;
		for (const InterfaceReference* const* i = (const InterfaceReference* const*) _basesPtr; *i; ++i, ++cnt)
		{
		}
		return {(const InterfaceReference* const*) _basesPtr, cnt};
	}
}

Bool InterfaceReference::IsBaseOfOrEqual(const InterfaceReference* other) const
{
	if (*this == *other)
		return true;
	for (const InterfaceReference* i : other->GetBases())
	{
		if (IsBaseOfOrEqual(i))
			return true;
	}
	return false;
}

InterfaceDefinition::InterfaceDefinition(const InterfaceReference& ref, TranslationUnit* unit, EntityBase::FLAGS flags) : _super(ref._super, unit, nullptr, flags), _infoOffset(LIMIT<Int>::MIN)
{
}

NonvirtualMTableReference::NonvirtualMTableReference(const Char* iid, void* nonvirtual, Initializer* mtableInit, TranslationUnit* unit)
	: _super(EntityBase::TYPE::INTERFACE_NVMTABLE, iid, unit, EntityBase::FLAGS::NONE), _nonvirtualTable(nonvirtual), _mtableInit(mtableInit)
{
}

ComponentDescriptor::ComponentDescriptor() : _super(EntityBase::TYPE::COMPONENT, Id(), nullptr, nullptr)
{
}

ComponentDescriptor::~ComponentDescriptor()
{
}

ComponentDescriptor::ComponentDescriptor(LiteralId&& cid, TranslationUnit* unit, const Char* file, EntityBase::FLAGS flags)
	: _super(EntityBase::TYPE::COMPONENT, std::move(cid), unit, file, flags), _implementedMethods(nullptr)
{
}


const ComponentInfo& ClassInfo::PrivateGetComponentInfo(const ComponentDescriptor& d) const
{
	DebugAssert(!(d.GetFlags() & EntityBase::FLAGS::CLASS_PROXY));
#ifdef MAXON_COMPONENT_HASHTABLE
	for (const ComponentInfo* e = _componentInfos[d._hashCode]; ; ++e)
	{
		if (MAXON_LIKELY(&d == e->_descriptor))
		{
			return *e;
		}
	}
#else
	for (auto it = _infoArray.Begin(); ; ++it)
	{
		if (it->_descriptor == &d)
			return *it;
	}
#endif
}

const ComponentInfo* ClassInfo::GetComponentInfo(const ComponentDescriptor& d) const
{
	DebugAssert(!(d.GetFlags() & EntityBase::FLAGS::CLASS_PROXY));
#ifdef MAXON_COMPONENT_HASHTABLE
	for (const ComponentInfo* e = _componentInfos[d._hashCode]; MAXON_LIKELY(e->_descriptor && (e->_descriptor->_hashCode == d._hashCode)); ++e)
	{
		if (MAXON_LIKELY(&d == e->_descriptor))
		{
			return e;
		}
	}
#else
	for (auto it = _infoArray.Begin(), end = _infoArray.End(); it != end; ++it)
	{
		if (it->_descriptor == &d)
			return it.GetPtr();
	}
#endif
	return nullptr;
}

Result<ObjectInterface*> ObjectInterface::Clone() const
{
	iferr_scope;
	iferr (ObjectInterface* c = GetClass().GetPointer()->CreatePointer())
		return err;
	iferr (c->CopyFrom(this))
	{
		ClassInterface::DeleteInstance(c);
		return err;
	}
	Result<void> result;
	if (IllegalArgumentError e = result.GetError<IllegalArgumentError>())
	{
	}
	else
	{
		result iferr_return;
	}
	return c;
}


void ObjectInterface::DestructInstance(ObjectInterface* o)
{
#ifdef MAXON_TARGET_DEBUG
		// #killedObjectCheck: mark the object killed so that the detection assert will signal a problem.
	System::GetReferenceCounter(o).SetRelaxed(UInt(-1));
#endif
	ClassInterface::DestructInstance(o);
}

Bool ObjectInterface::PrivateIsInstanceOf(const DataType& type) const
{
	DataTypePtr tp = type;
	if (tp->GetValueKind() & VALUEKIND::OBJECT_REF)
  	tp = tp->GetElementType();

	const InterfaceDefinition* const* interfaces = tp->GetInterfaces();
	const InterfaceDefinition* def = nullptr;
	while ((def = *(interfaces++)) != nullptr)
	{
		if (!ClassInterface::GetValidInterfaceInfo(_classInfo, def->_infoOffset))
			return false;
	}
	return true;
}

void ObjectDefinition::AddClassExtension(const void* ptr)
{
	// Return if the component only (and no class object) was to be registered.
	if (ptr == nullptr)
		return;

	const Class<>& cls = reinterpret_cast<const Class<>&>(ptr);
	MAXON_WARN_MUTE_UNUSED RegistryInterface::InsertEntry(Classes::Registry::GetRegistry(), _super.GetBase().GetId(), ConstDataPtr(cls), nullptr);
}

void ObjectDefinition::RemoveClassExtension()
{
	Classes::Erase(_super.GetBase().GetId()) iferr_ignore("Allocation failure on shutdown.");
}

// 32-byte-aligned block of 1024 zero bytes. Typically, string constants are stored in write-protected memory.
// This helps to find bugs which would overwrite g_zeroMemory.
const void* g_zeroMemory = Align("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
																 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", // reserve extra 32 bytes for alignment
																 32);

Char g_writableMemory[1024];

namespace details
{

class ForceEvaluation
{
public:
	static Int sum;
};

Int ForceEvaluation::sum;

const FinallyFactory FinallyFactory::instance = FinallyFactory();

}

#ifdef MAXON_TARGET_DEBUG
void PrivateLogNullptrError()
{
	PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);
}
Bool PrivateLogNullptrError(Bool result)
{
	PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);
	return result;
}
#endif

ThreadReferencedError PrivateGetNullReturnError(NULL_RETURN_REASON reason)
{
	// In debug a new error object is created to simplify debugging (it can be observed via System::SetDebugErrorObserver).
#ifdef MAXON_TARGET_DEBUG
	Error e;
	switch (reason)
	{
		case NULL_RETURN_REASON::NULLPTR:
		{
			e = NullptrError(MAXON_SOURCE_LOCATION, "NULL_RETURN_REASON::NULLPTR"_s);
			break;
		}
		case NULL_RETURN_REASON::MAKE_WRITABLE_FAILED:
		{
			e = NullptrError(MAXON_SOURCE_LOCATION, "NULL_RETURN_REASON::MAKE_WRITABLE_FAILED"_s);
			break;
		}
		case NULL_RETURN_REASON::NULLIMPL:
		{
			e = FunctionNotImplementedError(MAXON_SOURCE_LOCATION, "NULL_RETURN_REASON::NULLIMPL"_s);
			break;
		}
		case NULL_RETURN_REASON::UNRESOLVED:
		{
			e = UnresolvedError(MAXON_SOURCE_LOCATION, "NULL_RETURN_REASON::UNRESOLVED"_s);
			break;
		}
		default:
		{
			CriticalStop("reason not supported by PrivateGetNullReturnError.");
			e = NullptrError(MAXON_SOURCE_LOCATION);
			break;
		}
	}
	return ThreadReferencedError::CreateFromReferencedError(System::SetCurrentError(e));
#else
	switch (reason)
	{
		case NULL_RETURN_REASON::NULLPTR:
		{
			const Error& nullptrError = NullptrErrorObject();
			return ThreadReferencedError::CreateFromReferencedError(&nullptrError);
		}
		case NULL_RETURN_REASON::MAKE_WRITABLE_FAILED:
		{
			const Error& nullptrError = NullptrErrorObject();
			return ThreadReferencedError::CreateFromReferencedError(&nullptrError);
		}
		case NULL_RETURN_REASON::NULLIMPL:
		{
			const Error& abstractError = FunctionNotImplementedErrorObject();
			return ThreadReferencedError::CreateFromReferencedError(&abstractError);
		}
		case NULL_RETURN_REASON::UNRESOLVED:
		{
			const Error& unresolvedError = UnresolvedErrorObject();
			return ThreadReferencedError::CreateFromReferencedError(&unresolvedError);
		}
		default:
		{
			CriticalStop("reason not supported by PrivateGetNullReturnError.");
			const Error& nullptrError = NullptrErrorObject();
			return ThreadReferencedError::CreateFromReferencedError(&nullptrError);
		}
	}
#endif
}

void ErrorInterface::SetStackTrace(Int skip)
{
	void* trace[20];
	Int n = StackTrace::GetBacktrace(skip, trace);
	SetStackTrace(ToBlock(trace, n));
}

const Error* PrivateSystemSetCurrentError(const Error& error)
{
	return System::SetCurrentError(error);
}

const Error* PrivateSystemSetCurrentError(Error&& error)
{
	return System::SetCurrentError(std::move(error));
}

void PrivateSetError(Error& dest, const Error* src)
{
	dest = src ? *src : Error();
}

void* PrivateSystemAlloc(Int size)
{
	return System::Alloc(size, MAXON_SOURCE_LOCATION);
}

void PrivateSystemFree(void* m)
{
	System::Free(m);
}

const Error* CreateErrorPtr(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type)
{
	switch (type)
	{
		case ERROR_TYPE::OUT_OF_MEMORY:
		{
			OutOfMemoryError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		case ERROR_TYPE::NULLPTR:
		{
			NullptrError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		case ERROR_TYPE::ILLEGAL_ARGUMENT:
		{
			IllegalArgumentError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		case ERROR_TYPE::ILLEGAL_STATE:
		{
			IllegalStateError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		case ERROR_TYPE::NOT_IMPLEMENTED:
		{
			FunctionNotImplementedError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		case ERROR_TYPE::UNRESOLVED:
		{
			UnresolvedError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
		default:
		{
			UnknownError e(MAXON_SOURCE_LOCATION_FORWARD);
			return System::SetCurrentError(reinterpret_cast<Error&&>(e));
		}
	}
}


PrivateSuperCallBase PrivateSuperCallBase::_instance;

PrivateSuperCallBase::PrivateSuperCallBase(const ComponentDescriptor& component, const InterfaceReference& intf, Int method) : _interface(&intf), _method(method), _next(component._supercalls)
{
	component._supercalls = this;
}

namespace details
{

static void SystemFreeDummy(const void* ptr)
{
	if (ptr)
		__debugbreak();
}

static void WeakRefServicesRemoveWeakReferenceDummy(WeakRefBase&)
{
}

static void DataTypeLibPrivateHandleUnreferencedTypeDummy(DataTypeImpl*)
{
}

class InitSystemFree
{
public:
	InitSystemFree()
	{
		// Prevent crashes in global destructors when a dll is unloaded before the System::Free pointer is made valid.
		// Then all pointers passed to System:Free are nullptr anyhow, so a dummy function is sufficient.
		System::MTable::_instance._System_Free = &SystemFreeDummy;
		// Same for WeakRefServices::RemoveWeakReference and DataTypeLib::PrivateHandleUnreferencedType
		WeakRefServices::MTable::_instance._WeakRefServices_RemoveWeakReference = &WeakRefServicesRemoveWeakReferenceDummy;
		DataTypeLib::MTable::_instance._DataTypeLib_PrivateHandleUnreferencedType = &DataTypeLibPrivateHandleUnreferencedTypeDummy;
	}
};

static InitSystemFree g_initSystemFree;

}

} // namespace maxon
