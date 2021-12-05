#if 1
namespace maxon
{
	const maxon::Char* const DataDictionaryObjectInterface::MTable::_ids = 
		"SetData@57bfe708ef24ede7\0" // Result<void> SetData(ForwardingDataPtr&& key, Data&& data)
		"GetData@2eae62019803af60\0" // Result<Data> GetData(const ConstDataPtr& key) const
		"EraseData@dc4dd13ebfcb4890\0" // Result<void> EraseData(const ConstDataPtr& key)
		"Reset@6b2e10f\0" // void Reset()
		"IsEmpty@76f01901\0" // Bool IsEmpty() const
		"InitIterator@14413cecf6df8592\0" // void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDictionaryObjectInterface, , "net.maxon.interface.datadictionaryobject", "maxon.DataDictionaryObjectInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int DataDictionaryObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstIterator>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const DataDictionaryReferenceObjectInterface::MTable::_ids = 
		"Init@1678e20e45301c92\0" // Result<void> Init(DataDictionary* reference)
		"Init@bb78c22b6e6bfbd5\0" // Result<void> Init(const DataDictionary* reference)
		"GetDataContainer@4c199f6a7be99fa0\0" // const DataDictionary& GetDataContainer() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDictionaryReferenceObjectInterface, , "net.maxon.interface.datadictionaryreferenceobject", "maxon.DataDictionaryReferenceObjectInterface", (&DataDictionaryObjectInterface::_interface));
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
