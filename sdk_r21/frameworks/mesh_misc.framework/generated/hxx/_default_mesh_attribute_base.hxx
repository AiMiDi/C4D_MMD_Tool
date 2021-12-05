// This file contains default implementations for the interfaces of mesh_attribute_base.h. They are intended for copy&paste usage only.

class MyCustomDataTagDisplayImpl : public maxon::Component<MyCustomDataTagDisplayImpl, CustomDataTagDisplayInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(BaseTag* tag)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void FreeDisplayControl(BaseTag* tag)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void Reset()
	{
		return maxon::PrivateLogNullptrError();
	}

};

class MyMeshAttributeClassImpl : public maxon::Component<MyMeshAttributeClassImpl, MeshAttributeClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetDataType() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetDefaultValue(void* data) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool AtrLessThen(const void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool AtrIsEqual(const void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD void AtrAdd(void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void AtrSubstract(void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void AtrMultiply(void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void AtrMultiply(void* data, Float value) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void AtrDivide(void* data1, const void* data2) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void AtrDivide(void* data, Float value) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String AtrToString(const void* data, const FormatStatement* formatStatement) const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyCustomDataTagClassImpl : public maxon::Component<MyCustomDataTagClassImpl, CustomDataTagClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int32 GetTagPluginId() const
	{
		return 0;
	}

	MAXON_METHOD const String& GetTagPluginName() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const String& GetResourceId() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int32 GetTagPluginLevel() const
	{
		return 0;
	}

	MAXON_METHOD Id GetDisplayClassId() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool IsSdsCompatible(Int32& floatSize) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> Read(void* data, HyperFile* hf, Int32 level) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Write(const void* data, HyperFile* hf) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const
	{
		return 0;
	}

	MAXON_METHOD Int32 GetTagPluginFlags() const
	{
		return 0;
	}

};
