#ifndef LAYERSET_H__
#define LAYERSET_H__

#include "maxon/hashmap.h"
#include "maxon/vector.h"

namespace maxon
{

enum class LAYERSETMODE
{
	LAYERS,					///< Layers / layer Sets.
	LAYERMASKS,			///< Layer masks.
	ALPHAS,					///< Alpha channels.
	LAYERALPHA,			///< Layer alpha.
	DISABLED				///< Disabled.
} MAXON_ENUM_LIST(LAYERSETMODE);

struct LayerSetCompare
{
	static UInt64 GetHashCode(const String& value)
	{
		return value.ToUpper().GetHashCode();
	}

	static Bool IsEqual(const String& value1, const String& value2)
	{
		return value1.Compare(value2, STRINGCOMPARISON::CASEINSENSITIVE) == COMPARERESULT::EQUAL;
	}
};

//----------------------------------------------------------------------------------------
/// Class to choose layers or alphas from an image.
//----------------------------------------------------------------------------------------
class LayerSetInterface
{
	MAXON_INTERFACE_NONVIRTUAL(LayerSetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.layerset");

public:
	using LayerHash = HashSet<String, LayerSetCompare>;

	//----------------------------------------------------------------------------------------
	/// Sets the selected layers.
	/// @param[in] layers							The layers to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSelectedLayers(const LayerHash& layers);

	//----------------------------------------------------------------------------------------
	/// Gets the selected layers.
	/// @return												The layers.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const LayerHash& GetSelectedLayers() const;

	//----------------------------------------------------------------------------------------
	/// Sets the selected image.
	/// @param[in] image							The image to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetSelectedImage(const String& image);

	//----------------------------------------------------------------------------------------
	/// Gets the selected image.
	/// @return												The image.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetSelectedImage() const;

	//----------------------------------------------------------------------------------------
	/// Sets the mode.
	/// @param[in] mode								The mode to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMode(LAYERSETMODE mode);

	//----------------------------------------------------------------------------------------
	/// Gets the mode.
	/// @return												The mode.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD LAYERSETMODE GetMode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the alpha calculation mode.
	/// @param[in] calcAlpha					The mode to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetCalculateAlpha(Bool calcAlpha);

	//----------------------------------------------------------------------------------------
	/// Gets the alpha calculation mode.
	/// @return												The mode.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetCalculateAlpha() const;

	//----------------------------------------------------------------------------------------
	/// Compares this LayerSet with another one if both are identical.
	/// @param[in] other							The other LayerSet to compare this object to.
	/// @return												True if the object is identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const LayerSetInterface* other) const;

	MAXON_METHOD UInt GetHashCode() const;

	MAXON_FUNCTION void FlushLayers()
	{
		SetSelectedLayers(LayerHash()) iferr_cannot_fail("");
	}

	MAXON_FUNCTION Bool HasLayerSelection() const
	{
		return GetSelectedLayers().IsPopulated();
	}

	MAXON_FUNCTION Bool IsLayerEnabled(const String& name) const
	{
		return GetSelectedLayers().Find(name) != nullptr;
	}

	MAXON_FUNCTION Bool HasMultiImageSelection() const
	{
		return GetSelectedImage().IsPopulated();
	}

	MAXON_FUNCTION Bool IsMultiImageEnabled(const String& name) const
	{
		return LayerSetCompare::IsEqual(GetSelectedImage(), name);
	}

	MAXON_FUNCTION Result<void> RemoveLayer(const String& layer)
	{
		iferr_scope;
		LayerHash h;
		h.CopyFrom(GetSelectedLayers()) iferr_return;
		h.Erase(layer) iferr_return;
		return SetSelectedLayers(h);
	}

	MAXON_FUNCTION Result<void> AddLayer(const String& layer)
	{
		iferr_scope;
		LayerHash h;
		h.CopyFrom(GetSelectedLayers()) iferr_return;
		h.Insert(layer) iferr_return;
		return SetSelectedLayers(h);
	}

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};


// include autogenerated headerfile here
#include "layerset1.hxx"
#include "layerset2.hxx"

}

#endif // LAYERSET_H__
