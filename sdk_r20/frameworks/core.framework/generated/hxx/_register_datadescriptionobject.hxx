#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionObjectInterface, "net.maxon.interface.datadescriptionobject", "maxon.DataDescriptionObjectInterface", , &Object::_interface);
	const maxon::Char* const DataDescriptionObjectInterface::MTable::_ids = 
		"GetObjectDescription@ccc2256f5dc4891d\0" // GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const
	"";
	template <typename DUMMY> maxon::Int DataDescriptionObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDescriptionObjectClass, , "net.maxon.class.datadescriptionobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadescriptionobject(0
	| maxon::DataDescriptionObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
