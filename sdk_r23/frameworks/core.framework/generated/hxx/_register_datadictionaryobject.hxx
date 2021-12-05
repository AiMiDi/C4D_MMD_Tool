#if 1
namespace maxon
{
	const maxon::Char* const DataDictionaryObjectInterface::MTable::_ids = 
		"SetData@5ad8bc0e8a8c4eb4\0" // Result<void> SetData(ForwardingDataPtr&& key, Data&& data)
		"GetData@2650f729e23305a1\0" // Result<Data> GetData(const ConstDataPtr& key) const
		"EraseData@c5d3e89b5a93d41f\0" // Result<void> EraseData(const ConstDataPtr& key)
		"Reset@780cdac8f1a33934\0" // void Reset()
		"IsEmpty@12e73654e6d65520\0" // Bool IsEmpty() const
		"InitIterator@f436aec054ec7c6b\0" // void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDictionaryObjectInterface, , "net.maxon.interface.datadictionaryobject", "maxon.DataDictionaryObjectInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int DataDictionaryObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstIterator>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const DataDictionaryReferenceObjectInterface::MTable::_ids = 
		"Init@ae389ff61cac2b3d\0" // Result<void> Init(DataDictionary* reference)
		"Init@c224a0815c2665b6\0" // Result<void> Init(const DataDictionary* reference)
		"GetDataContainer@45764542c49e9ee3\0" // const DataDictionary& GetDataContainer() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDictionaryReferenceObjectInterface, , "net.maxon.interface.datadictionaryreferenceobject", "maxon.DataDictionaryReferenceObjectInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int DataDictionaryReferenceObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const DataDictionary&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDictionaryObjectEmptyClass, , "net.maxon.class.datadictionaryobjectempty");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDictionaryObjectClass, , "net.maxon.class.datadictionaryobject");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDictionaryObjectLockedClass, , "net.maxon.class.datadictionaryobjectlocked");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDictionaryObjectSyncedClass, , "net.maxon.class.datadictionaryobjectsynced");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDictionaryObjectReferenceClass, , "net.maxon.class.datadictionaryobjectreference");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadictionaryobject(0
	| maxon::DataDictionaryObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::DataDictionaryReferenceObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
