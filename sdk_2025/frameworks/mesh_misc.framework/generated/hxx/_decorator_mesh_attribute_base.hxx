// This file contains decorator implementations for the interfaces of mesh_attribute_base.h. They are intended for copy&paste usage only.

class CustomDataTagDisplayDecoratorImpl : public maxon::Component<CustomDataTagDisplayDecoratorImpl, CustomDataTagDisplayInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(cinema::BaseTag* tag)
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).Init(tag);
	}

	MAXON_METHOD Result<void> Draw(cinema::BaseTag* tag, cinema::BaseObject* op, cinema::BaseDraw* bd, cinema::BaseDrawHelp* bh)
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).Draw(tag, op, bd, bh);
	}

	MAXON_METHOD Result<void> DisplayControl(const cinema::BaseTag* tag, cinema::BaseDocument* doc, cinema::BaseObject* op, cinema::BaseDraw* bd, cinema::BaseDrawHelp* bh, cinema::ControlDisplayStruct& cds) const
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).DisplayControl(tag, doc, op, bd, bh, cds);
	}

	MAXON_METHOD Result<void> InitDisplayControl(cinema::BaseTag* tag, cinema::BaseDocument* doc, cinema::BaseDraw* bd, const cinema::AtomArray* active)
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).InitDisplayControl(tag, doc, bd, active);
	}

	MAXON_METHOD void FreeDisplayControl(cinema::BaseTag* tag)
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).FreeDisplayControl(tag);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::Cast<CustomDataTagDisplayRef>(self.GetDecoratedObject()).Reset();
	}

};

class MeshAttributeClassDecoratorImpl : public maxon::Component<MeshAttributeClassDecoratorImpl, MeshAttributeClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetDataType() const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).GetDataType();
	}

	MAXON_METHOD const DataType& GetUnderlyingDataType() const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).GetUnderlyingDataType();
	}

	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).InterpolateLinear(data1, data2, blend);
	}

	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).InterpolateInOutline(data, outline, weights);
	}

	MAXON_METHOD void GetDefaultValue(void* data) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).GetDefaultValue(data);
	}

	MAXON_METHOD Bool AtrLessThen(const void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrLessThen(data1, data2);
	}

	MAXON_METHOD Bool AtrIsEqual(const void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrIsEqual(data1, data2);
	}

	MAXON_METHOD void AtrAdd(void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrAdd(data1, data2);
	}

	MAXON_METHOD void AtrSubstract(void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrSubstract(data1, data2);
	}

	MAXON_METHOD void AtrMultiply(void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrMultiply(data1, data2);
	}

	MAXON_METHOD void AtrMultiply(void* data, Float value) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrMultiply(data, value);
	}

	MAXON_METHOD void AtrDivide(void* data1, const void* data2) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrDivide(data1, data2);
	}

	MAXON_METHOD void AtrDivide(void* data, Float value) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrDivide(data, value);
	}

	MAXON_METHOD String AtrToString(const void* data, const FormatStatement* formatStatement) const
	{
		return maxon::Cast<MeshAttributeClass>(self.GetDecoratedObject()).AtrToString(data, formatStatement);
	}

};

class CustomDataTagClassDecoratorImpl : public maxon::Component<CustomDataTagClassDecoratorImpl, CustomDataTagClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int32 GetTagPluginId() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetTagPluginId();
	}

	MAXON_METHOD const String& GetTagPluginName() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetTagPluginName();
	}

	MAXON_METHOD const String& GetResourceId() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetResourceId();
	}

	MAXON_METHOD Int32 GetTagPluginLevel() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetTagPluginLevel();
	}

	MAXON_METHOD Id GetDisplayClassId() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetDisplayClassId();
	}

	MAXON_METHOD Bool IsSdsCompatible(Int32& floatSize) const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).IsSdsCompatible(floatSize);
	}

	MAXON_METHOD Result<void> Read(void* data, cinema::HyperFile* hf, Int32 level) const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).Read(data, hf, level);
	}

	MAXON_METHOD Result<void> Write(const void* data, cinema::HyperFile* hf) const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).Write(data, hf);
	}

	MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetIcon(perPolyVertex);
	}

	MAXON_METHOD Int32 GetTagPluginFlags() const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).GetTagPluginFlags();
	}

	MAXON_METHOD Bool Message(cinema::GeListNode* node, Int32 type, void* data) const
	{
		return maxon::Cast<CustomDataTagClass>(self.GetDecoratedObject()).Message(node, type, data);
	}

};
