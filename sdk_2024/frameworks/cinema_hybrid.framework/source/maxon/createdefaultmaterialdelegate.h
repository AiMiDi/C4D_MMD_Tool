#ifndef CREATEDEFAULTMATERIALDELEGATE_H__
#define CREATEDEFAULTMATERIALDELEGATE_H__

#include "maxon/delegate.h"
#include "maxon/utilities/numtostring.h"

class BaseDocument;
class BaseMaterial;

namespace maxon
{

/// Allows to register a delegate which will be called when a new material of your type is created from a texture or color (for example when drag&dropping a texture file, a texture asset or a color into the Material Manager) where you must set the data into the material properly.
/// Additionally, your material will appear into the "Cinema 4D Preferences / Material / Material Manager / Default Material" dropdown.
/// Example of use:
/// @code
/// // Register Sketch & Toon material
/// Bool RegisterToonUpMat()
/// {
/// 	return RegisterMaterialPlugin(ID_TOONUP_MAT, GeLoadString(IDS_TOONUPMAT), PLUGINFLAG_MATERIAL_SHOW_IN_DEFAULT_MENU | PLUGINFLAG_HIDEPLUGINMENU | PLUGINFLAG_HIDE, ToonUpMat::Alloc, "Mtoonup"_s, TOONUP_LEVEL_ID);
/// }
///
/// // Register create material delegate
/// namespace maxon
/// {
/// MAXON_DECLARATION_REGISTER(CreateMaterialWithDataDelegates, NumToString<ID_TOONUP_MAT>::value)
/// {
/// 	CreateMaterialWithDataDelegate delegate = [](::BaseDocument* doc, const Data& textureUrlOrColor) -> ::BaseMaterial*
/// 	{
/// 		//-----------------------------------------------------------
/// 		// Create Skecth&Toon material
/// 		//-----------------------------------------------------------
///
/// 		// First try to create a user preset default material
/// 		BaseMaterial* mat = (BaseMaterial*)AssetCreationInterface::GetDefaultObject(ToSingletonBlock(ID_TOONUP_MAT), doc);
/// 		if (!mat)
/// 		{
/// 			// There is no default preset material: create a new one.
/// 			mat = BaseMaterial::Alloc(ID_TOONUP_MAT);
/// 			if (!mat)
/// 			{
/// 				CriticalStop("Hair material creation error: out of memory");
/// 				return nullptr;
/// 			}
/// 		}
///
/// 		//-----------------------------------------------------------
/// 		// Set data to material (if any)
/// 		//-----------------------------------------------------------
/// 		ifnoerr (maxon::Url url = textureUrlOrColor.Get<maxon::Url>())
/// 		{
/// 			//-----------------------------------------------------------
/// 			// Received data is a texture url: set it into the material
/// 			//-----------------------------------------------------------
///
/// 			// Activate "Texture" checkbox
/// 			mat->SetParameter(ConstDescID(DescLevel(OUTLINEMAT_COLOR_TEXTURE)), true, DESCFLAGS_SET::NONE);
///
/// 			// Set texture url
/// 			BaseContainer* bc = mat->GetDataInstance();
///
/// 			// Delete any unexpected shader (take in mind that if material is a user preset default material, it may contain some unexpected shader)
/// 			BaseShader* oldShader = (BaseShader*)bc->GetLink(OUTLINEMAT_COLOR_TEXTURE_LINK, doc, Xbase);
/// 			if (oldShader)
/// 				BaseShader::Free(oldShader);
///
/// 			BaseShader* newShader = BaseShader::Alloc(Xbitmap);
/// 			if (newShader != nullptr)
/// 			{
/// 				newShader->GetDataInstanceRef().SetFilename(BITMAPSHADER_FILENAME, MaxonConvert(url));
///
/// 				// Material takes shader ownership
/// 				mat->InsertShader(newShader);
///
/// 				// Set parameter link
/// 				mat->SetParameter(ConstDescID(DescLevel(OUTLINEMAT_COLOR_TEXTURE_LINK)), newShader, DESCFLAGS_SET::NONE);
/// 			}
/// 		}
/// 		else
/// 		{
/// 			ifnoerr (maxon::ColorA color = textureUrlOrColor.Get<maxon::ColorA>())
/// 			{
/// 				//-----------------------------------------------------------
/// 				// Received data is a color: set it into the material
/// 				//-----------------------------------------------------------
///
/// 				// Set main color
/// 				mat->SetParameter(ConstDescID(DescLevel(OUTLINEMAT_COLOR)), color.GetColor3().GetVector(), DESCFLAGS_SET::NONE);
///
/// 				// Set transparency from alpha component
/// 				mat->SetParameter(ConstDescID(DescLevel(OUTLINEMAT_OPACITY)), color.a, DESCFLAGS_SET::NONE);
/// 			}
/// 		}
///
/// 		return mat;
/// 	};
///
/// 	return delegate;
/// }
/// }
/// @endcode
using CreateMaterialWithDataDelegate = Delegate<::BaseMaterial*(::BaseDocument*, const Data& textureUrlOrColor)>;
MAXON_DATATYPE(CreateMaterialWithDataDelegate, "net.maxon.hybrid.datatype.creatematerialwithdatadelegate");
MAXON_REGISTRY(CreateMaterialWithDataDelegate, CreateMaterialWithDataDelegates, "net.maxon.hybrid.command.creatematerialwithdata");

// @deprecated Use @ref CreateMaterialWithDataDelegate instead
using CreateDefaultMaterialDelegate = Delegate<::BaseMaterial*(::BaseDocument*)>;
MAXON_DATATYPE(CreateDefaultMaterialDelegate, "net.maxon.hybrid.datatype.createdefaultmaterialdelegate");
MAXON_REGISTRY(CreateDefaultMaterialDelegate, CreateDefaultMaterialDelegates, "net.maxon.hybrid.command.createdefaultmaterials");

//----------------------------------------------------------------------------------------
/// Helper class to get/set the default material for renderers
//----------------------------------------------------------------------------------------
class RendererDefaultMaterialInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RendererDefaultMaterialInterface, MAXON_REFERENCE_STATIC, "net.maxon.rendererdefaultmaterial.interface");

public:
	//----------------------------------------------------------------------------------------
	/// Allows to define the default material (materialId) based on the current active renderer (rendererId) that is created when Cinema 4D preferences / Material / Material Manager / Default Material dropdown is set to "Auto".  @see WPREF_MATMANAGER_DEFAULT_MATERIAL_AUTO @see GetRendererDefaultMaterial
	/// If is undefined for the current active renderer, then a standard Cinema 4D material will be created instead.
	/// Example of use:
	/// @code
	/// #include "maxon/materialdelegate.h"
	///
	/// Bool RegisterPyshicalRender()
	/// {
	///	 // When "Physical Renderer" is active, the default material created will be "PBR".
	///	 maxon::SetRendererDefaultMaterial(PYSICAL_RENDERER_ID, PBR_MATERIAL_ID);
	///
	///	 return RegisterVideoPostPlugin(PYSICAL_RENDERER_ID, GeLoadString(IDS_PHYSICAL_RENDERER), PLUGINFLAG_VIDEOPOST_ISRENDERER, PhysicalRender::Alloc, "Physical render"_s, 0, VPPRIORITY_EXTERNAL);
	/// }
	/// @endcode
	/// @param[in] rendererId			The renderer ID.
	/// @param[in] materialId			The material ID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetRendererDefaultMaterial(Int32 rendererId, Int32 materialId);

	//----------------------------------------------------------------------------------------
	/// Gets the material ID that has been defined for the renderer ID. @see SetRendererDefaultMaterial
	/// @param[in] rendererId			The renderer ID to query the material ID from.
	/// @return The material ID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetRendererDefaultMaterial(Int32 rendererId);
};

#include "createdefaultmaterialdelegate1.hxx"
#include "createdefaultmaterialdelegate2.hxx"

} // namespace maxon

#endif	// CREATEDEFAULTMATERIALDELEGATE_H__
