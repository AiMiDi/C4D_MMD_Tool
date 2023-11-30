#ifndef MATERIALPARAMETER_H__
#define MATERIALPARAMETER_H__

#include "maxon/datadictionary.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"
#include "maxon/url.h"
#include "maxon/gfx_image.h"
#include "maxon/gfx_image_pixelformat.h"

namespace maxon
{

namespace material
{

//----------------------------------------------------------------------------------------
/// Defines an image to represent a material parameter. 
//----------------------------------------------------------------------------------------
struct TextureBuffer
{
	//----------------------------------------------------------------------------------------
	/// The pixel data of the image in linear color space.
	/// Pixels are defined as (r, g, b, a) values in row-major order.
	//----------------------------------------------------------------------------------------
	StrongCOWRef<BaseArray<Vector4d32>> _pixels;

	//----------------------------------------------------------------------------------------
	/// The image size in width and height. Its product has to match the size of @_pixels, i.e.
	/// _dimensions.x * _dimensions.y = _pixels->GetCount().
	//----------------------------------------------------------------------------------------
	IntVector2d _dimensions;

	//----------------------------------------------------------------------------------------
	/// Checks whether a pixel array has been assigned to the texture buffer.
	/// @return												True if there's a pixel array, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _pixels.GetPointer() != nullptr;
	}
};
MAXON_DATATYPE(TextureBuffer, "net.maxon.material.datatype.texturebuffer");

//----------------------------------------------------------------------------------------
/// Defines a reference to an image file to represent a material parameter. 
//----------------------------------------------------------------------------------------
struct ImageReference
{
	//----------------------------------------------------------------------------------------
	/// The absolute path to an image file. 
	/// An absolute path allows us to interpret this image reference without knowing about
	/// the embedding into a particular BaseDocument. A relative path can be constructed with
	/// respect to the BaseDocument::GetDocumentPath().
	//----------------------------------------------------------------------------------------
	Url _absolutePath;

	//----------------------------------------------------------------------------------------
	/// Checks whether an absolute path has been assigned to the image reference.
	/// @return												True if the absolute path is populated.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _absolutePath.IsPopulated();
	}
};
MAXON_DATATYPE(ImageReference, "net.maxon.material.datatype.imagereference");

//----------------------------------------------------------------------------------------
/// Defines a reference to a substance asset (.sbsar) to represent a material parameter.
/// This object does not have ownership over an asset and instead loosely couples with
/// assets as they are available through the API defined in "lib_substance.h".
//----------------------------------------------------------------------------------------
struct SubstanceReference
{
	//----------------------------------------------------------------------------------------
	/// The absolute path to a substance file (.sbsar). 
	/// An absolute path allows us to interpret this reference to a substance asset without knowing about
	/// the embedding into a particular BaseDocument. A relative path can be constructed with
	/// respect to the BaseDocument::GetDocumentPath().
	//----------------------------------------------------------------------------------------
	Url _absolutePath;

	//----------------------------------------------------------------------------------------
	/// The name of the substance according to the C4D Substance API, e.g.
	/// @code
	/// _assetName = static_cast<BaseList2D*>((substanceAsset))->GetName();
	/// @endcode
	//----------------------------------------------------------------------------------------
	String _assetName;

	//----------------------------------------------------------------------------------------
	/// The name of the substance output according to the GetSubstanceOutput query of the C4D Substance API.
	//----------------------------------------------------------------------------------------
	String _outputChannelName;

	//----------------------------------------------------------------------------------------
	/// Checks whether an absolute path has been assigned to the substance reference.
	/// @return												True if the absolute path is populated.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _absolutePath.IsPopulated();
	}
};
MAXON_DATATYPE(SubstanceReference, "net.maxon.material.datatype.substancereference");

//----------------------------------------------------------------------------------------
/// Defines a collection of material parameters. The data independent of an embedding into a
/// BaseMaterial or BaseDocument and can be freely passed around.
//----------------------------------------------------------------------------------------
struct MaterialExchangeData
{
	//----------------------------------------------------------------------------------------
	/// Defines the type of material. Each material type is associated with a set of parameters.
	/// These types are usually defined by, but not limited to, port bundles in the resource editor.
	/// Common types include:
	/// maxon::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT (older material type in FBX files),
	/// maxon::MATERIAL::PORTBUNDLE::FBXSURFACEPHONG  (older material type FBX files),
	/// maxon::MATERIAL::PORTBUNDLE::GLTF,
	/// maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE (modeled after open standard, WIP w.r.t. constituents of shading normal, e.g. bump and displacement),
	/// maxon::NODESPACE::EXCHANGE::PORTBUNDLE::USDPREVIEWSURFACE (connects node materials with usd preview material).
	/// maxon::NODESPACE::EXCHANGE::PORTBUNDLE::VIEWPORTMATERIAL (connects node materials with the viewport).
	//----------------------------------------------------------------------------------------
	Id _materialTypeId;

	//----------------------------------------------------------------------------------------
	/// Contains the constant values for the material. It is expected that every entry is defined as a
	/// (key = maxon::InternedId, value = maxon::material::PackedConstantParameter) tuple.
	/// We refer to the methods Insert() and Extract() of maxon::material::ParameterStorageInterface for convenient access.
	//----------------------------------------------------------------------------------------
	DataDictionary _parameters;

	//----------------------------------------------------------------------------------------
	/// Contains the non-constant values for the material. In addition to the constant value, every parameter
	/// maybe driven by a more complex data set, such as a texture buffer or a reference to an image or a substance, i.e.
	/// maxon::material::TextureBuffer,
	/// maxon::material::ImageReference,
	/// maxon::material::SubstanceReference.
	//----------------------------------------------------------------------------------------
	HashMap<Id, Data> _textures;
};
using MaterialExchangeDataRef = StrongRef<MaterialExchangeData>;

//----------------------------------------------------------------------------------------
/// Defines a type-agnostic material parameter that is used to opaquely pass data along the ParameterStorageInterface with DataDictionary objects.
/// This class only holds a single value and no texture, but it may indicate the need for a texture representation.
//----------------------------------------------------------------------------------------
struct PackedConstantParameter
{
	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty parameter.
	//----------------------------------------------------------------------------------------
	PackedConstantParameter() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor a parameter with the opaque provided data. 
	//----------------------------------------------------------------------------------------
	explicit PackedConstantParameter(Data&& value, Bool isConstant, UInt dynamicTimestamp) :
		_value(std::move(value)), _isConstant(isConstant), _dynamicTimestamp(dynamicTimestamp)
	{

	}

	Result<void> CopyFrom(const PackedConstantParameter& src)
	{
		iferr_scope;
		_value.CopyFrom(src._value) iferr_return;
		_isConstant = src._isConstant;
		_dynamicTimestamp = src._dynamicTimestamp;
		return OK;
	}

	Data _value;								 // The opaque default / constant value.
	Bool _isConstant = true;		 // Defines whether the parameter is constant and only requires a single value for representation.
	UInt _dynamicTimestamp = 0;	 // The timestamp of the dynamic texture-driven parameter.
};
MAXON_DATATYPE(PackedConstantParameter, "net.maxon.material.datatype.packedconstantparameter");

//----------------------------------------------------------------------------------------
/// Defines a material parameter that is used to communicated via the ParameterStorageInterface.
/// This class only holds a single value and no texture, but it may indicate the need for a texture representation.
//----------------------------------------------------------------------------------------
template <typename TYPE>
struct TypedConstantParameter
{
	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty parameter.
	//----------------------------------------------------------------------------------------
	TypedConstantParameter() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor a parameter with the provided typed data. 
	//----------------------------------------------------------------------------------------
	TypedConstantParameter(TYPE&& value, Bool isConstant, UInt dynamicTimestamp, const InternedId& id) :
		_value(std::move(value)), _isConstant(isConstant), _dynamicTimestamp(dynamicTimestamp), _id(id)
	{

	}

	TYPE _value = TYPE();					// The default / constant value.
	Bool _isConstant = true;			// Defines whether the parameter is constant and only requires a single value for representation.
	UInt _dynamicTimestamp = 0;		// The timestamp of the dynamic texture-driven parameter.
	InternedId _id;								// The id of the parameter.
};

class ParameterStorageInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ParameterStorageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.material.interface.parameterstorage");

public:


	//----------------------------------------------------------------------------------------
	/// Extracts / gets an typed parameter from a DataDictionaryInterface object with type check between the requested value type and the attribute's type.
	/// @tparam TYPE									The value type of the parameter.
	/// @tparam KEY										The type of the key attribute.
	/// @param[in] parameters					The DataDictionary holding the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @return												The typed parameter on success.
	//----------------------------------------------------------------------------------------
	template <typename TYPE, typename KEY>
	static Result<TypedConstantParameter<TYPE>> Extract(const DataDictionaryInterface& parameters, KEY&& id)
	{
		iferr_scope;

		using TT = typename std::conditional<IsFidClass<KEY>::value && !std::is_same<typename IsFidClass<KEY>::type, Data>::value, typename maxon::Substitute<TYPE, typename IsFidClass<KEY>::type>::type, TYPE>::type;

		const Data* parameterDataPtr = parameters.PrivateGetData(ConstDataPtr(InternedId(id)));
		CheckState(parameterDataPtr != nullptr);

		if (parameterDataPtr->GetType() == GetDataType<PackedConstantParameter>())
		{
			const PackedConstantParameter& packedParameter = parameterDataPtr->Get<PackedConstantParameter>() iferr_return;
			iferr (TT value = packedParameter._value.Get<TT>())
			{
				DebugStop("Couldn't get value of type '@' from parameter '@' with value '@'. Error: @",
					maxon::GetDataType<TT>(), id, packedParameter._value.GetType(), err.ToString());
				return err;
			}
			const Bool isConstant = packedParameter._isConstant;
			const UInt dynamicTimestamp = packedParameter._dynamicTimestamp;
			TypedConstantParameter<TT> parameter = TypedConstantParameter<TT>(std::move(value), isConstant, dynamicTimestamp, id);
			return parameter;
		}

		return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid TypedConstantParameter"_s);
	}

	//----------------------------------------------------------------------------------------
	/// Extracts / gets an typed parameter from a DataDictionary with type check between the requested value type and the attribute's type.
	/// @tparam TYPE									The value type of the parameter.
	/// @tparam KEY										The type of the key attribute.
	/// @param[in] parameters					The DataDictionary holding the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @return												The typed parameter on success.
	/// For example, a base color can be extracted the following:
	/// @code
	/// maxon::nodes::TypedConstantParameter<Color> baseColor = maxon::nodes::ParameterStorageInterface::Extract<Color>(parameters, maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::BASE_COLOR) iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename TYPE, typename KEY>
	static Result<TypedConstantParameter<TYPE>> Extract(const DataDictionary& parameters, KEY&& id)
	{
		iferr_scope;
		const DataDictionaryInterface* parametersPtr = parameters.GetPointer();
		CheckState(parametersPtr != nullptr);
		return Extract<TYPE>(*parametersPtr, id);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a typed parameter into the provided DataDictionary with type check between the provided value and the attribute's type.
	/// @tparam KEY										The type of the key attribute.
	/// @param[out] parameters				The DataDictionary to hold on the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @param[in] value							The typed constant / default value of the parameter.
	/// @param[in] isConstant					True if the parameter is constant (and requires no texture-driven representation).
	/// @param[in] dynamicTimestamp		The timestamp of the texture-driven representation.
	/// @return												OK on success.
	/// For example, a red base color can be inserted the following:
	/// @code
	/// maxon::nodes::ParameterStorageInterface::Insert(parameters, maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::BASE_COLOR, Color(1, 0, 0), true, 0) iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY>
	static Result<void> Insert(DataDictionary& parameters, KEY&& id, T&& value, Bool isConstant, UInt dynamicTimestamp)
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value && !STD_IS_REPLACEMENT(same, typename IsFidClass<KEY>::type, Data), typename maxon::Substitute<T, typename IsFidClass<KEY>::type>::type, void>::type;
		Data dataValue;
		iferr (dataValue.SetImpl<TT>(std::forward<T>(value), OVERLOAD_MAX_RANK))
			return err;
		Data packedParameter;
		iferr (packedParameter.Set(PackedConstantParameter(std::move(dataValue), isConstant, dynamicTimestamp)))
			return err;
		return parameters.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(id)), std::move(packedParameter));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts an opaque parameter into the provided DataDictionary.
	/// @tparam KEY										The type of the key attribute.
	/// @param[out] parameters				The DataDictionary to hold on the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @param[in] dataValue					The opaque constant / default value of the parameter.
	/// @param[in] isConstant					True if the parameter is constant (and requires no texture-driven representation).
	/// @param[in] dynamicTimestamp		The timestamp of the texture-driven representation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename KEY>
	static Result<void> InsertData(DataDictionary& parameters, KEY&& id, Data&& dataValue, Bool isConstant, UInt dynamicTimestamp)
	{
		Data packedParameter;
		iferr (packedParameter.Set(PackedConstantParameter(std::move(dataValue), isConstant, dynamicTimestamp)))
			return err;
		return parameters.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(id)), std::move(packedParameter));
	}

	//----------------------------------------------------------------------------------------
	/// Loads and parses the data description of material and inserts the defined default values into a DataDictionary.
	/// This method caches once-loaded description for performance.
	/// @param[in] materialType			The (bundle) type of the material representation.
	/// @return											The parameter set on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> LoadDefaults(const Id& materialType);

	//----------------------------------------------------------------------------------------
	/// Creates an image for a F32 RGBA texture buffer with matching dimensions. The pixel format can be chosen freely, allowing
	/// a lossy reduction of the bit depth.
	///
	/// @param[in] textureBuffer			The parameter's attribute id.
	/// @param[in] pixelFormat				The opaque constant / default value of the parameter.
	/// @return												The image on success.
	/// 
	/// For example, a texture buffer can be saved to disk the following:
	/// @code
	/// maxon::ImageTextureRef bakedImage = maxon::material::ParameterStorageInterface::CreateImageTexture(textureBuffer, maxon::PixelFormats::RGBA::F32()) iferr_return;
	/// maxon::Url imageOutputPath = maxon::Url("C:/Temp/bakedImage"_s);
	/// imageOutputPath.SetSuffix("tif"_s) iferr_return;
	/// const maxon::MediaOutputUrlRef destination = maxon::ImageSaverClasses::Tif().Create() iferr_return;
	/// maxon::MediaSessionRef imageExportSession = maxon::MediaSessionObject().Create() iferr_return;
	/// bakedImage.Save(imageOutputPath, destination, maxon::MEDIASESSIONFLAGS::RUNONLYANALYZE, &imageExportSession) iferr_return;
	/// imageExportSession.Convert(TimeValue(), maxon::MEDIASESSIONFLAGS::NONE) iferr_return;
	/// imageExportSession.Close() iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ImageTextureRef> CreateImageTexture(const TextureBuffer& textureBuffer, const PixelFormat& pixelFormat);


	//----------------------------------------------------------------------------------------
	/// Saves a collection of material constants and texture buffers to a file directory. The constants are converted to strings and saved into a "constants.json" file.
	/// Texture buffers are saved to F32 RGBA Tif files named according to the Ids.
	/// This function is particularly helpful for debugging purposes.
	///
	/// @param[in] data								The material data containing constant values and texture buffers.
	/// @param[in] outputDirectory		The output directory to populate with JSON and Tif files.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SaveMaterialExchangeData(const MaterialExchangeData& data, const Url& outputDirectory);

	//----------------------------------------------------------------------------------------
	/// Convenience function to extract a typed parameter under #id from the provided #parameters container if contained. Otherwise, #defaultParameters will be queried.
	/// @tparam KEY										The type of the key attribute.
	/// @param[in] parameters					The DataDictionary that is expected to hold the parameter.
	/// @param[in] defaultParameters	The DataDictionary that is expected to hold the default parameter as a fallback.
	/// @return												The parameter on success.
	///
	/// This helper function makes it easier to write code that is robust against producers that only populate some parameters of the material.
	/// If a parameter is missing, it is reasonable to fall back to a default.
	/// The usage is the following:
	/// @code
	/// const maxon::DataDictionary defaultParameters = maxon::material::ParameterStorageInterface::LoadDefaults(maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::GetId()) iferr_return;
	/// const maxon::material::TypedConstantParameter<Color> baseColor = maxon::material::ParameterStorageInterface::GetOrDefault(parameters, defaultParameters, maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::BASE_COLOR) iferr_return;
	/// const maxon::Color baseColorValue = baseColor._value;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename TYPE, typename KEY>
	static Result<TypedConstantParameter<TYPE>> GetOrDefault(const DataDictionary& parameters, const DataDictionary& defaultParameters, KEY&& id)
	{
		iferr_scope;

		ifnoerr (TypedConstantParameter<TYPE> typedParameter = ParameterStorageInterface::Extract<TYPE>(parameters, id))
		{
			// We have found a parameter.
			return typedParameter;
		}
		else
		{
			// There's no parameter set, we query the defaults.
			TypedConstantParameter<TYPE> defaultTypedParameter = ParameterStorageInterface::Extract<TYPE>(defaultParameters, id) iferr_return;
			DebugAssert(defaultTypedParameter._isConstant == true);
			return defaultTypedParameter;
		}
	}
};

#include "materialparameter1.hxx"
#include "materialparameter2.hxx"

} // namespace material
} // namespace maxon

#endif // MATERIALPARAMETER_H__
