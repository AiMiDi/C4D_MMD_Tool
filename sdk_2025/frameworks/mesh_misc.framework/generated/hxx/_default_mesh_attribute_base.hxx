// This file contains default implementations for the interfaces of mesh_attribute_base.h. They are intended for copy&paste usage only.

class MyCustomDataTagDisplayImpl : public maxon::Component<MyCustomDataTagDisplayImpl, CustomDataTagDisplayInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(cinema::BaseTag* tag)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Draw(cinema::BaseTag* tag, cinema::BaseObject* op, cinema::BaseDraw* bd, cinema::BaseDrawHelp* bh)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> DisplayControl(const cinema::BaseTag* tag, cinema::BaseDocument* doc, cinema::BaseObject* op, cinema::BaseDraw* bd, cinema::BaseDrawHelp* bh, cinema::ControlDisplayStruct& cds) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> InitDisplayControl(cinema::BaseTag* tag, cinema::BaseDocument* doc, cinema::BaseDraw* bd, const cinema::AtomArray* active)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void FreeDisplayControl(cinema::BaseTag* tag)
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
		return HXXRET3(NULLIMPL, const DataType&);
	}

	MAXON_METHOD const DataType& GetUnderlyingDataType() const
	{
		return HXXRET3(NULLIMPL, const DataType&);
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
		return HXXRET3(NULLIMPL, String);
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
		return HXXRET3(NULLIMPL, const String&);
	}

	MAXON_METHOD const String& GetResourceId() const
	{
		return HXXRET3(NULLIMPL, const String&);
	}

	MAXON_METHOD Int32 GetTagPluginLevel() const
	{
		return 0;
	}

	MAXON_METHOD Id GetDisplayClassId() const
	{
		return HXXRET3(NULLIMPL, Id);
	}

	MAXON_METHOD Bool IsSdsCompatible(Int32& floatSize) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> Read(void* data, cinema::HyperFile* hf, Int32 level) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Write(const void* data, cinema::HyperFile* hf) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const
	{
		return 0;
	}

	MAXON_METHOD Int32 GetTagPluginFlags() const
	{
		return 0;
	}

	MAXON_METHOD Bool Message(cinema::GeListNode* node, Int32 type, void* data) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
