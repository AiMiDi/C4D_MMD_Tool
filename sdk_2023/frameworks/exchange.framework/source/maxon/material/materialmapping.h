#ifndef MATERIALMAPPING_H__
#define MATERIALMAPPING_H__

#include "maxon/material/materialparameter.h"

namespace maxon
{

namespace material
{

//----------------------------------------------------------------------------------------
/// Struct used to reduce the boilerplate and parameters needed in inserting material mapping
/// //----------------------------------------------------------------------------------------
struct MaterialMapperParameterInsertWrapper
{
	const DataDictionary		 source;
	const DataDictionary		 sourceDefaults;
	DataDictionary&					 resultParameters;
	HashMap<Id, InternedId>& expectedTextures;
};

/// Static function to reduce the boilerplate needed when inserting materials in the material exchange 
/// Used in conjunction with the struct defined above
/// for Example SimpleAttributeInsert<>(wrappedParams, MATERIAL::PORTBUNDLE::REDSHIFT::EMISSION_COLOR, MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::EMISSIVE, Color(1, 1, 1)) iferr_return;
template <typename SOURCE_MATERIAL_ATTRIBUTE, typename TARGET_MATERIAL_ATTRIBUTE, typename T>
static Result<void> SimpleAttributeInsert(MaterialMapperParameterInsertWrapper& wrappedParams, const SOURCE_MATERIAL_ATTRIBUTE fromMaterial, const TARGET_MATERIAL_ATTRIBUTE toMaterial, const T fallbackValue)
{
	iferr_scope;

	TypedConstantParameter<T> extractedValue = ParameterStorageInterface::GetOrDefault<T>(wrappedParams.source, wrappedParams.sourceDefaults, fromMaterial) iferr_return;

	if (extractedValue._isConstant == false)
	{
		extractedValue._value = T(fallbackValue);

		wrappedParams.expectedTextures.Insert(fromMaterial, toMaterial) iferr_return;
	}
	ParameterStorageInterface::Insert(wrappedParams.resultParameters, toMaterial, extractedValue._value, extractedValue._isConstant, extractedValue._dynamicTimestamp) iferr_return;
	return OK;
}
//----------------------------------------------------------------------------------------
/// A MaterialMapping defines a transformation between two types of materials, for example
/// maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL -> maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE
///
/// A mapping should be registered to maxon::material::MaterialMappers to allow discovery and use by thirds.
/// Please note that a material mapping is a lossy operation for anything but trivial scenarios.
///
/// It remains up to the implementor to decide whether arithmetic transformations should only be performed
/// for the constant values, or also for texture buffers and image references, e.g. the
/// transformation of glossiness -> roughness.
///
/// The resulting data should be considered of "better than nothing" quality.
///
/// The mapping execution is a multi-stage operation. In the first stage, the entire source material
/// is provided, but may exclude textures.
/// Here, the mapping is expected to provide the collection of parameters that are actually read
/// from the source and somehow influence the target material data.
/// In the second stage, the textures for all parameters of interest are provided.
///
/// This approach avoids creating all textures before passing the data into an (incomplete) mapper
/// that only processes some of these textures.
///
/// This class may be of limited interest to third party extension as the maxon::material::MaterialExportInterface
/// will ensure that (non-chained) mapping operations take place if needed.
//----------------------------------------------------------------------------------------
class MaterialMappingRef;
class MaterialMappingInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(MaterialMappingInterface, MAXON_REFERENCE_NORMAL, "net.maxon.material.interface.materialmapping");

public:
	//----------------------------------------------------------------------------------------
	/// The first stage provides the constant-valued parameters of a material, omitting
	/// the provision of textures. The returned collection of source parameters defines which
	/// textures can be handled in the second stage.
	///
	/// Note that time-taking baking processes may take place between the two stages.
	/// @param[in] sourceParameters		The constant-valued source parameters.
	/// @return												The parameters of further interest.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashSet<Id>> PassOne(const DataDictionary& sourceParameters);

	//----------------------------------------------------------------------------------------
	/// The second stage provides the textures of non-constant parameters that have been marked
	/// of further interest by returning their Ids in the first stage.
	///
	/// This stage is expected to provide the complete target material data.
	/// Note that time-taking baking processes may take place between the two stages.
	/// @param[in] sourceTextures			The textures of the source material (texture buffers, image references, substance references).
	/// @return												The target material data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MaterialExchangeData> PassTwo(const HashMap<Id, Data>& sourceTextures);
};

#include "materialmapping1.hxx"

//----------------------------------------------------------------------------------------
/// MaterialMappingDescription defines the identifier / signature of a mapper within the registry.
/// It defines the expected source and target material type and a factory for instantiation.
///
/// For example, a registration may look the following:
/// @code
/// static GenericData g_myMappingRegistration;
/// maxon::Result<void> MyMapping::Register()
/// {
/// 	iferr_scope;
///
/// 	maxon::material::MaterialMappingDescription description;
/// 	description._source = maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::GetId();
/// 	description._target = maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::GetId();
/// 	description._class = GetClass();
/// 	g_myMappingRegistration = maxon::material::MaterialMappers::Register(GetDescriptor().GetId(), std::move(description)) iferr_return;
/// 	return maxon::OK;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct MaterialMappingDescription
{
	Id												_source; // The id of the material source type.
	Id												_target; // The id of the material target type.
	Class<MaterialMappingRef> _class;	 // The factory to instantiate the mapper.
};
MAXON_DATATYPE(MaterialMappingDescription, "net.maxon.material.datatype.materialmappingdescription");

//----------------------------------------------------------------------------------------
/// MaterialMappers holds the descriptions of all registered mappings.
///
/// The registry can be linearly searched for a matching mapping the following:
/// @code
/// for (const maxon::material::MaterialMappingDescription& mapping : maxon::material::MaterialMappers::GetEntries())
/// {
/// 	if (mapping._source != mySourceType)
/// 		continue;
/// 	if (mapping._target != myTargetType)
/// 		continue;
/// 	return mapping._class.Create();
/// }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(MaterialMappingDescription, MaterialMappers, "net.maxon.material.registry.materialmappers");



#include "materialmapping2.hxx"

} // namespace material

} // namespace maxon

#endif // MATERIALMAPPING_H__
