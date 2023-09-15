#ifndef MATERIALIMPORT_H__
#define MATERIALIMPORT_H__

#include "maxon/material/materialparameter.h"

// TODO: (Maik) consider adding a collection of supported material types to MaterialImportDescription and mapping helper functionality.

class BaseMaterial;
class BaseDocument;
namespace maxon
{

namespace material
{

namespace IMPORT
{
	namespace CONFIG
	{
		//----------------------------------------------------------------------------------------
		/// Defines the type of NodeMaterialImport to be instantiated for a node-based material.
		/// This parameter is only consumed by the Maxon-owned import class for Mmaterial.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(Id, NODESPACEID, "nodeSpaceId");
	} // namespace CONFIG
} // namespace IMPORT

//----------------------------------------------------------------------------------------
/// A MaterialImport defines an import factory of a custom-defined material derived from BaseMaterial.
/// The importer may be called on user-triggered file import operations. An import 
/// instance is created for every single material import operation and provided with the parsed
/// material data, e.g. the parameter values that were parsed from FbxProperty types.
/// 
/// The importers are expected to be registered in MaterialImporters under a user-readable name
/// may be used in user dialogs.
///
/// An importer can be used in the following manner:
/// @code
/// maxon::DataDictionary importConfig;
/// importConfig.Set(maxon::material::IMPORT::CONFIG::NODESPACEID, C4DOS.Ge->GetActiveNodeSpaceId()) iferr_return;
/// 
/// // We create an almost default standard surface configuration.
/// maxon::material::MaterialExchangeData materialData;
/// materialData._materialTypeId = maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::GetId();
/// materialData._parameters = maxon::material::ParameterStorageInterface::LoadDefaults(materialData._materialTypeId) iferr_return;
/// maxon::material::ParameterStorageInterface::Insert(materialData._parameters, maxon::MATERIAL::PORTBUNDLE::STANDARDSURFACE::BASE_COLOR, maxon::Color(1, 0, 1), true, 0) iferr_return;
/// 
/// maxon::material::MaterialImportRef importer = importerClass.Create() iferr_return;
/// BaseMaterial* newMaterial = importer.CreateMaterial(materialData, baseDocument, importConfig) iferr_return;
/// CheckState(newMaterial != nullptr);
/// if (newMaterial->GetDocument() == nullptr)
/// {
/// 	baseDocument.InsertMaterial(newMaterial, nullptr, true);
/// }
/// @endcode
/// 
/// Please note that an importer may not be able to handle the provided type of material and return an error.
//----------------------------------------------------------------------------------------
class MaterialImportInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
MAXON_INTERFACE(MaterialImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.material.interface.materialimport");

public:

	//----------------------------------------------------------------------------------------
	/// Creates a material based on the provided material data. Configuration and destination BaseDocument are provided for context.
	/// The implementation is free to decide whether to insert the returned material into the document, or not.
	///
	/// @param[in] materialData		The material data to import from.
	/// @param[in] baseDocument		The destination scene of the creation.
	/// @param[in] config					The import configuration.
	/// @return										The created material on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseMaterial*> CreateMaterial(const MaterialExchangeData& materialData, BaseDocument& baseDocument, const DataDictionary& config);
};

#include "materialimport1.hxx"

//----------------------------------------------------------------------------------------
/// MaterialImportDescription defines the identifier / signature of an importer within the registry.
/// It defines the factory for instantiation and a user-readable name.
/// 
/// For example, a registration may look the following:
/// @code
/// static maxon::GenericData g_myMaterialImport;
/// maxon::Result<void> MyImport::Register()
/// {
/// 	iferr_scope;
/// 
/// 	maxon::material::MaterialImportDescription importDescription;
/// 	importDescription._name = "My Material"_s;
/// 	importDescription._class = MyImport::GetClass();
/// 	g_myMaterialImport = maxon::material::MaterialImporters::Register(MyImport::GetDescriptor().GetId(), std::move(importDescription)) iferr_return;
/// 	return maxon::OK;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct MaterialImportDescription
{
	String _name; // The user-readable name of the material import.
	Class<MaterialImportRef> _class; // The factory to instantiate the import.
};
MAXON_DATATYPE(MaterialImportDescription, "net.maxon.material.datatype.materialimportdescription");

//----------------------------------------------------------------------------------------
/// MaterialImporters holds the descriptions of all registered material importers.
/// 
/// The registry can be linearly searched the following:
/// @code
/// for (const maxon::material::MaterialImportDescription& importer : maxon::material::MaterialImporters::GetEntries())
/// {
///		DiagnosticOutput("Material Import Named '@'", importer._name);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(MaterialImportDescription, MaterialImporters, "net.maxon.material.registry.materialimporters");

//----------------------------------------------------------------------------------------
/// The declaration of the type of material import fulfilling BaseMaterial::IsInstanceOf(Mmaterial) && BaseMaterial::IsNodeBased()
/// This importer consumes maxon::material::IMPORT::CONFIG::NODESPACEID.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(MaterialImportRef, NodeMaterialImporter, "net.maxon.material.materialimport.nodematerial");

#include "materialimport2.hxx"

} // namespace material

} // namespace maxon

#endif // MATERIALIMPORT_H__