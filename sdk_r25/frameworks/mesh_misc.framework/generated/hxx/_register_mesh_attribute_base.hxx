#if 1
namespace maxon
{
	const maxon::Char* const CustomDataTagDisplayInterface::MTable::_ids = 
		"Init@f5e3ffd9f8eb8db6\0" // Result<void> Init(BaseTag* tag)
		"Draw@a7fa5840a46cced7\0" // Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh)
		"DisplayControl@48e5391c4cc8db6f\0" // Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const
		"InitDisplayControl@ad0020bc0983ed54\0" // Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
		"FreeDisplayControl@b421ab0170026207\0" // void FreeDisplayControl(BaseTag* tag)
		"Reset@780cdac8f1a33934\0" // void Reset()
	"";
	const maxon::METHOD_FLAGS CustomDataTagDisplayInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagDisplayInterface, , "net.maxon.mesh_misc.interface.customdatatagdisplay", "maxon.CustomDataTagDisplayInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const MeshAttributeClassInterface::MTable::_ids = 
		"GetDataType@a6c0b400f1ac4207\0" // const DataType& GetDataType() const
		"InterpolateLinear@e35373c419f8aa3d\0" // void InterpolateLinear(void* data1, const void* data2, Float blend) const
		"InterpolateInOutline@f0c7b9f1b8bb603c\0" // void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
		"GetDefaultValue@ab68774493c1767a\0" // void GetDefaultValue(void* data) const
		"AtrLessThen@f2d86d20a6e6a6d8\0" // Bool AtrLessThen(const void* data1, const void* data2) const
		"AtrIsEqual@f2d86d20a6e6a6d8\0" // Bool AtrIsEqual(const void* data1, const void* data2) const
		"AtrAdd@c7bce0408a964813\0" // void AtrAdd(void* data1, const void* data2) const
		"AtrSubstract@c7bce0408a964813\0" // void AtrSubstract(void* data1, const void* data2) const
		"AtrMultiply@c7bce0408a964813\0" // void AtrMultiply(void* data1, const void* data2) const
		"AtrMultiply@93cc1c6718df8d88\0" // void AtrMultiply(void* data, Float value) const
		"AtrDivide@c7bce0408a964813\0" // void AtrDivide(void* data1, const void* data2) const
		"AtrDivide@93cc1c6718df8d88\0" // void AtrDivide(void* data, Float value) const
		"AtrToString@a76e653225bfd4b\0" // String AtrToString(const void* data, const FormatStatement* formatStatement) const
	"";
	const maxon::METHOD_FLAGS MeshAttributeClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MeshAttributeClassInterface, , "net.maxon.mesh_misc.interface.meshattributeclass", "maxon.MeshAttributeClassInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int MeshAttributeClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const CustomDataTagClassInterface::MTable::_ids = 
		"GetTagPluginId@30a3c592bf87830a\0" // Int32 GetTagPluginId() const
		"GetTagPluginName@8fd391aee7382314\0" // const String& GetTagPluginName() const
		"GetResourceId@8fd391aee7382314\0" // const String& GetResourceId() const
		"GetTagPluginLevel@30a3c592bf87830a\0" // Int32 GetTagPluginLevel() const
		"GetDisplayClassId@33636d531bf4ad19\0" // Id GetDisplayClassId() const
		"IsSdsCompatible@5f5d9c4be31c578e\0" // Bool IsSdsCompatible(Int32& floatSize) const
		"Read@5dea3f8a56708f07\0" // Result<void> Read(void* data, HyperFile* hf, Int32 level) const
		"Write@afa551e441d24410\0" // Result<void> Write(const void* data, HyperFile* hf) const
		"GetIcon@8235b9738ba11402\0" // Int32 GetIcon(Bool perPolyVertex) const
		"GetTagPluginFlags@30a3c592bf87830a\0" // Int32 GetTagPluginFlags() const
		"Message@c23974e3a290760e\0" // Bool Message(GeListNode* node, Int32 type, void* data) const
	"";
	const maxon::METHOD_FLAGS CustomDataTagClassInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagClassInterface, , "net.maxon.mesh_misc.interface.customdatattag", "maxon.CustomDataTagClassInterface", (MeshAttributeClassInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int CustomDataTagClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const String&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(CustomDataTagClasses);
	MAXON_REGISTRY_REGISTER(CustomDataTagDisplayClasses);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_MeshAttribute,, "net.maxon.mesh_misc.datatype.meshattribute");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mesh_attribute_base(0
	| maxon::MeshAttributeClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::CustomDataTagClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
