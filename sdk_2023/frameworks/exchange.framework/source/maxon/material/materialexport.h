#ifndef MATERIALEXPORT_H__
#define MATERIALEXPORT_H__

#include "maxon/material/materialmapping.h"

class BaseMaterial;

namespace maxon
{

namespace material
{

//----------------------------------------------------------------------------------------
/// Defines a priority / level of support for a material type by the caller of the export.
//----------------------------------------------------------------------------------------
enum class MaterialTypeSupport
{
	DIRECT, // The caller of the export indicates direct support.
	MAPPED // The caller of the export has no support, but an appropriate mapping can transform to a directly supported type.
} MAXON_ENUM_LIST(MaterialTypeSupport);
using MaterialTypesMap = HashMap<Id, MaterialTypeSupport>;
MAXON_DATATYPE(MaterialTypesMap, "net.maxon.material.datatype.materialtypesmap");

namespace EXPORT
{
	enum class TextureSupport
	{
		NONE = 0, ///< Indicates support for no kind of data in MaterialExchangeData::_textures.
		TEXTUREBUFFER = 1, ///< Indicates that data of type TextureBuffer can be consumed by the caller.
		IMAGEREFERENCE = 2, ///< Indicates that data of type ImageReference can be consumed by the caller.
		SUBSTANCEREFERENCE = 4, ///< Indicates that data of type SubstanceReference can be consumed by the caller.
		ALL = TEXTUREBUFFER | IMAGEREFERENCE | SUBSTANCEREFERENCE
	} MAXON_ENUM_FLAGS(TextureSupport);

	namespace CONFIG
	{
		//----------------------------------------------------------------------------------------
		/// Defines which node space of a node-based material should be exported.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(Id, NODESPACEID, "spaceId");

		//----------------------------------------------------------------------------------------
		/// The set of material types that the export issuer can handle.
		/// Each entry is a tuple of (material type, priority).
		/// Exporters may be presented with an extended list of directly-configured material types
		/// and a collection of types that are achievable through MaterialMapping operations.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(MaterialTypesMap, MATERIALTYPESWITHSUPPORT, "materialTypes");

		//----------------------------------------------------------------------------------------
		/// The recommended dimensions of textures. Note that exporters may ignore the value
		/// and prefer returning textures and baked texture buffers in native resolution.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(IntVector2d, TEXTUREDIMENSIONS, "textureDimensions");

		//----------------------------------------------------------------------------------------
		/// Specifies the level of texture support by the caller of the export operation.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(TextureSupport, TEXTURESUPPORT, "textureSupport");

	} // namespace CONFIG
} // namespace EXPORT


//----------------------------------------------------------------------------------------
/// A MaterialExport defines the data provider of custom-defined material derived from BaseMaterial
/// for material export operations.
/// 
/// The exporter may be called on user-triggered file export operations. An export 
/// instance is created for every single material export operation and provided with the 
/// reference to the BaseMaterial. The exporter defines a file format-agnostic collection
/// of material parameters. It may provide texture-based representations through baking operations.
/// 
/// Within the MaterialExport implementation, please consider monitoring the thread cancellation state when executing time-taking baking operations
/// to remain reactive when users abort an export.
///
/// The usage through the static helper function is the following:
/// @code
/// const maxon::Id activeNodeSpaceId = C4DOS.Ge->GetActiveNodeSpaceId();
/// const maxon::IntVector2d textureBakingResolution = maxon::IntVector2d(1024, 1024);
/// maxon::DataDictionary exportConfig;
/// maxon::material::MaterialTypesMap materialTypes;
/// materialTypes.Insert(maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::GetId(), maxon::material::MaterialTypeSupport::DIRECT) iferr_return;
/// exportConfig.Set(maxon::material::EXPORT::CONFIG::MATERIALTYPESWITHSUPPORT, std::move(materialTypes)) iferr_return;
/// exportConfig.Set(maxon::material::EXPORT::CONFIG::NODESPACEID, activeNodeSpaceId) iferr_return;
/// exportConfig.Set(maxon::material::EXPORT::CONFIG::TEXTUREDIMENSIONS, textureBakingResolution) iferr_return;
/// const maxon::material::MaterialExchangeData materialData = maxon::material::MaterialExportInterface::Export(baseMaterial, exportConfig) iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------
class MaterialExportRef;
class MaterialExportInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(MaterialExportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.material.interface.materialexport");

public:

	//----------------------------------------------------------------------------------------
	/// Helper function that perform a lookup of a matching entry in the MaterialExporters registry.
	/// After instantiation of the compatible exporter, the multi-stage process is interleaved with
	/// data handover to a compatible MaterialMapping instance if required. Note that mappings are not chained.
	/// @param[in] baseMaterial				The material to be exported.
	/// @param[in] config							The export configuration.
	/// @return												The exported material data on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<MaterialExchangeData> Export(const BaseMaterial& baseMaterial, const DataDictionary& config);

	//----------------------------------------------------------------------------------------
	/// Initialized the export operation by providing the BaseMaterial and export configuration.
	/// @param[in] baseMaterial				The material to be exported.
	/// @param[in] config							The export configuration.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Initialize(const BaseMaterial& baseMaterial, const DataDictionary& config);

	//----------------------------------------------------------------------------------------
	/// Returns the constant-values parameters along with markings of whether they require texture representation
	/// in order to request texture baking in the GetTextures() stage.
	/// Returned parameters are expected to be of type maxon::material::PackedConstantParameter().
	/// @return												The material parameters on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Id, DataDictionary>> GetParameters();

	//----------------------------------------------------------------------------------------
	/// Creates textures for the provided parameters.
	/// The textures may be texture buffers, image references or substance references.
	/// @param[in] texturedChannels		The parameters for which textures are requested.
	/// @return												The textures on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashMap<Id, Data>> GetTextures(const HashSet<Id>& texturedChannels);
};

#include "materialexport1.hxx"

//----------------------------------------------------------------------------------------
/// MaterialExportDescription defines the identifier / signature of an exporter within the registry.
/// It defines the factory for instantiation and a compatible material type.
/// 
/// For example, a registration may look the following:
/// @code
/// static maxon::GenericData g_myMaterialExport;
/// maxon::Result<void> MyExport::Register()
/// {
/// 	iferr_scope;
/// 
/// 	maxon::material::MaterialExportDescription exportDescription;
/// 	exportDescription._type = MY_MAT_ID;
/// 	exportDescription._class = MyExport::GetClass();
/// 	g_myMaterialExport = maxon::material::MaterialImporters::Register(MyExport::GetDescriptor().GetId(), std::move(exportDescription)) iferr_return;
/// 	return maxon::OK;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct MaterialExportDescription
{
	Int32 _type = -1; // The compatible material type fulfilling BaseMaterial::IsInstanceOf(_type), e.g. Mmaterial for the Maxon-owned material.
	Class<MaterialExportRef> _class; // The factory to instantiate the export.
};
MAXON_DATATYPE(MaterialExportDescription, "net.maxon.material.datatype.materialexportdescription");


//----------------------------------------------------------------------------------------
/// MaterialExporters holds the descriptions of all registered material exporters.
/// 
/// The registry can be linearly searched the following:
/// @code
/// for (const maxon::material::MaterialExportDescription& exporter : maxon::material::MaterialExporters::GetEntries())
/// {
///		DiagnosticOutput("Material Export For Type '@'", exporter._type);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(MaterialExportDescription, MaterialExporters, "net.maxon.material.registry.materialexporters");

#include "materialexport2.hxx"

} // namespace material

} // namespace maxon

#endif // MATERIALEXPORT_H__
