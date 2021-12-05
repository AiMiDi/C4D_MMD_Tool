#if 1
namespace maxon
{
	const maxon::Char* const CustomDataTagDisplayInterface::MTable::_ids = 
		"Init@a498e163d7ddcef9\0" // Result<void> Init(BaseTag* tag)
		"Draw@de8c5f804c421778\0" // Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh)
		"DisplayControl@173f8bfb6029a6ca\0" // Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
		"InitDisplayControl@181f400b9bf14db7\0" // Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
		"FreeDisplayControl@323b47dda782a470\0" // void FreeDisplayControl(BaseTag* tag)
		"Reset@6b2e10f\0" // void Reset()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagDisplayInterface, , "net.maxon.mesh_misc.interface.customdatatagdisplay", "maxon.CustomDataTagDisplayInterface", (&ObjectInterface::_interface));
	const maxon::Char* const MeshAttributeClassInterface::MTable::_ids = 
		"GetDataType@f6200306f4b3253c\0" // const DataType& GetDataType() const
		"InterpolateLinear@b1eba430d3102cd6\0" // void InterpolateLinear(void* data1, const void* data2, Float blend) const
		"InterpolateInOutline@4f6ccea97351f1c1\0" // void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
		"GetDefaultValue@1625bfafc6cdbb3\0" // void GetDefaultValue(void* data) const
		"AtrLessThen@f3108c6d608d9d4d\0" // Bool AtrLessThen(const void* data1, const void* data2) const
		"AtrIsEqual@f3108c6d608d9d4d\0" // Bool AtrIsEqual(const void* data1, const void* data2) const
		"AtrAdd@beb1af8325117966\0" // void AtrAdd(void* data1, const void* data2) const
		"AtrSubstract@beb1af8325117966\0" // void AtrSubstract(void* data1, const void* data2) const
		"AtrMultiply@beb1af8325117966\0" // void AtrMultiply(void* data1, const void* data2) const
		"AtrMultiply@a3f119528619e163\0" // void AtrMultiply(void* data, Float value) const
		"AtrDivide@beb1af8325117966\0" // void AtrDivide(void* data1, const void* data2) const
		"AtrDivide@a3f119528619e163\0" // void AtrDivide(void* data, Float value) const
		"AtrToString@7f3bcad2be999d06\0" // String AtrToString(const void* data, const FormatStatement* formatStatement) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MeshAttributeClassInterface, , "net.maxon.mesh_misc.interface.meshattributeclass", "maxon.MeshAttributeClassInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int MeshAttributeClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const CustomDataTagClassInterface::MTable::_ids = 
		"GetTagPluginId@fd7d68f65\0" // Int32 GetTagPluginId() const
		"GetTagPluginName@27f2c2db0d16c8cf\0" // const String& GetTagPluginName() const
		"GetResourceId@27f2c2db0d16c8cf\0" // const String& GetResourceId() const
		"GetTagPluginLevel@fd7d68f65\0" // Int32 GetTagPluginLevel() const
		"GetDisplayClassId@22aaf2\0" // Id GetDisplayClassId() const
		"IsSdsCompatible@1893bc560f4cb749\0" // Bool IsSdsCompatible(Int32& floatSize) const
		"Read@c404050e0b8bca88\0" // Result<void> Read(void* data, HyperFile* hf, Int32 level) const
		"Write@3c9446580a72728d\0" // Result<void> Write(const void* data, HyperFile* hf) const
		"GetIcon@df421be22b341b\0" // Int32 GetIcon(Bool perPolyVertex) const
		"GetTagPluginFlags@fd7d68f65\0" // Int32 GetTagPluginFlags() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagClassInterface, , "net.maxon.mesh_misc.interface.customdatattag", "maxon.CustomDataTagClassInterface", (&MeshAttributeClassInterface::_interface));
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
