#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagDisplayInterface, "net.maxon.mesh_misc.interface.customdatatagdisplay", "maxon.CustomDataTagDisplayInterface", , &Object::_interface);
	const maxon::Char* const CustomDataTagDisplayInterface::MTable::_ids = 
		"Init@a498e163d7ddcef9\0" // Init(BaseTag* tag)
		"Draw@de8c5f804c421778\0" // Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh)
		"DisplayControl@173f8bfb6029a6ca\0" // DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
		"InitDisplayControl@181f400b9bf14db7\0" // InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
		"FreeDisplayControl@323b47dda782a470\0" // FreeDisplayControl(BaseTag* tag)
		"Reset@6b2e10f\0" // Reset()
	"";
	template <typename DUMMY> maxon::Int CustomDataTagDisplayInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MeshAttributeClassInterface, "net.maxon.mesh_misc.interface.meshattributeclass", "maxon.MeshAttributeClassInterface", , &Object::_interface);
	const maxon::Char* const MeshAttributeClassInterface::MTable::_ids = 
		"GetDataType@f6200306f4b33440\0" // GetDataType() const
		"InterpolateLinear@b1eba430d3102cd6\0" // InterpolateLinear(void* data1, const void* data2, Float blend) const
		"InterpolateInOutline@4f6ccea97351f1c1\0" // InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
		"GetDefaultValue@1625bfafc6cdbb3\0" // GetDefaultValue(void* data) const
		"AtrLessThen@f3108c6d608d9d4d\0" // AtrLessThen(const void* data1, const void* data2) const
		"AtrIsEqual@f3108c6d608d9d4d\0" // AtrIsEqual(const void* data1, const void* data2) const
		"AtrAdd@beb1af8325117966\0" // AtrAdd(void* data1, const void* data2) const
		"AtrSubstract@beb1af8325117966\0" // AtrSubstract(void* data1, const void* data2) const
		"AtrMultiply@beb1af8325117966\0" // AtrMultiply(void* data1, const void* data2) const
		"AtrMultiply@a3f119528619e163\0" // AtrMultiply(void* data, Float value) const
		"AtrDivide@beb1af8325117966\0" // AtrDivide(void* data1, const void* data2) const
		"AtrDivide@a3f119528619e163\0" // AtrDivide(void* data, Float value) const
		"AtrToString@7f3bcad2be999d06\0" // AtrToString(const void* data, const FormatStatement* formatStatement) const
	"";
	template <typename DUMMY> maxon::Int MeshAttributeClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CustomDataTagClassInterface, "net.maxon.mesh_misc.interface.customdatattag", "maxon.CustomDataTagClassInterface", , &MeshAttributeClassInterface::_interface);
	const maxon::Char* const CustomDataTagClassInterface::MTable::_ids = 
		"GetTagPluginId@fd7d68f65\0" // GetTagPluginId() const
		"GetTagPluginName@27f2c2db0d16c8cf\0" // GetTagPluginName() const
		"GetResourceId@27f2c2db0d16c8cf\0" // GetResourceId() const
		"GetTagPluginLevel@fd7d68f65\0" // GetTagPluginLevel() const
		"GetDisplayClassId@22aaf2\0" // GetDisplayClassId() const
		"IsSdsCompatible@1893bc560f4cb749\0" // IsSdsCompatible(Int32& floatSize) const
		"Read@c404050e0b8bca88\0" // Read(void* data, HyperFile* hf, Int32 level) const
		"Write@3c9446580a72728d\0" // Write(const void* data, HyperFile* hf) const
		"GetIcon@df421be22b341b\0" // GetIcon(Bool perPolyVertex) const
	"";
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
	| maxon::CustomDataTagDisplayInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::MeshAttributeClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::CustomDataTagClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
