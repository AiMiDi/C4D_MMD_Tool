/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEMATERIAL_H__
#define C4D_BASEMATERIAL_H__

#ifdef __API_INTERN__
abc def xyz
#endif

#include "operatingsystem.h"
#include "c4d_baselist.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

#define MatCall(fnc) (this->*C4DOS_Mt->fnc)

//----------------------------------------------------------------------------------------
/// This is the material base class that all materials in @C4D are derived from.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseMaterial : public BaseList2D
{
private:
	BaseMaterial();
	~BaseMaterial();

public:

	/// @name Allocation
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base material}
	/// @param[in] type								The material type: @enumerateEnum{MaterialTypes}
	/// @return												@allocReturn{base material}
	//----------------------------------------------------------------------------------------
	static BaseMaterial* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base materials}
	/// @param[in] bl									@theToDestruct{base material}
	//----------------------------------------------------------------------------------------
	static void Free(BaseMaterial*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next material in the list. Convenience version of GeListNode::GetNext() returning a @ref BaseMaterial*.
	/// @return												The next material, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{base material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetNext() { return (BaseMaterial*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous material in the list. Convenience version of GeListNode::GetPred() returning a @ref BaseMaterial*.
	/// @return												The previous material, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{base material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetPred() { return (BaseMaterial*)AtCall(GetPred) (); }

	/// @}

	/// @name Update Material
	/// @{

	//----------------------------------------------------------------------------------------
	/// Recalculates the material's thumbnail and updates its internal values.
	/// @note Recalculating the thumbnail/RTTM image is time intensive. It only needs to be done to let the user change the view. The calculations are done asynchronously.
	/// @param[in] preview						If @formatConstant{true} the preview thumbnail will be updated.
	/// @param[in] rttm								If @formatConstant{true} the real time texture map of the material will be recalculated.
	//----------------------------------------------------------------------------------------
	void Update(Bool preview, Bool rttm);

	/// @}

	/// @name Get Channel
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the channel associated with a standard %Material, such as the color channel or bump channel.
	/// @warning Only works with standard materials of type @ref Mmaterial. For plugin materials this method does nothing and return @formatConstant{nullptr}.
	/// @param[in] id									The channel type: @enumerateEnum{CHANNEL}
	/// @return												The requested channel, or @formatConstant{nullptr} if there is no such channel or if the material is not a standard %Material.
	//----------------------------------------------------------------------------------------
	BaseChannel* GetChannel(Int32 id) { return C4DOS_Mt->GetChannel(this, id); }

	/// @}

	/// @name Textures
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the material textures, loading any files required.
	/// @param[in] irs								A struct with information about the upcoming material rendering. @callerOwnsPointed{struct}
	/// @return												The result of the initialization: @enumerateEnum{INITRENDERRESULT}
	//----------------------------------------------------------------------------------------
	INITRENDERRESULT InitTextures(const InitRenderStruct &irs) { return MatCall(InitTextures)(irs); }

	//-------------------------------------------------------------------------------------------------
	/// Unlocks all textures used by the material.
	//-------------------------------------------------------------------------------------------------
	void UnlockTextures() { MatCall(UnlockTextures)(); }

	/// @}

	/// @name Calculation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calls the displacement routine of a material with associated barycentric weights.
	/// @note The passed VolumeData structure must be fully initialized and must contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	/// @param[in] weights						Use @formatConstant{nullptr}. @markPrivate
	//----------------------------------------------------------------------------------------
	void Displace(VolumeData* sd, const RayPolyWeight *weights) { MatCall(Displace) (sd, weights); }

	//----------------------------------------------------------------------------------------
	/// Calls the bump routine of a material. For plugin materials this is MaterialData::ChangeNormal().\n
	/// The call changes BaseVolumeData::bumpn.
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @warning Normalization is not done by the routine.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	//----------------------------------------------------------------------------------------
	void ChangeNormal(VolumeData* sd) { MatCall(ChangeNormal) (sd); }

	//----------------------------------------------------------------------------------------
	/// Computes the surface properties of the material. For plugin materials this is MaterialData::CalcSurface().\n
	/// The call changes BaseVolumeData::col, BaseVolumeData::trans, BaseVolumeData::refl, BaseVolumeData::tray, BaseVolumeData::rray and/or BaseVolumeData::alpha (depending on the parameters).
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	//----------------------------------------------------------------------------------------
	void CalcSurface(VolumeData* sd) { MatCall(CalcSurface) (sd); }

	//----------------------------------------------------------------------------------------
	/// Computes the transparency properties of the material. For plugin materials this is MaterialData::CalcTransparency().\n
	/// The call changes BaseVolumeData::trans.
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	//----------------------------------------------------------------------------------------
	void CalcTransparency(VolumeData* sd) { MatCall(CalcTransparency) (sd); }

	//----------------------------------------------------------------------------------------
	/// Computes the alpha properties of the material. For plugin materials this is MaterialData::CalcAlpha().\n
	/// The call changes BaseVolumeData::alpha.
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	//----------------------------------------------------------------------------------------
	void CalcAlpha(VolumeData* sd) { MatCall(CalcAlpha) (sd); }

	//----------------------------------------------------------------------------------------
	/// Computes the color of a volumetric ray in the material. For plugin materials this is MaterialData::CalcVolumetric().\n
	/// The call changes VolumeData::col and/or VolumeData::trans.
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	//----------------------------------------------------------------------------------------
	void CalcVolumetric(VolumeData* sd) { MatCall(CalcVolumetric) (sd); }

	//----------------------------------------------------------------------------------------
	/// If (and only if) (GetRenderInfo() & @ref VOLUMEINFO::INITCALCULATION) is @formatConstant{true}, then call this function, with the right @formatParam{type}, before any of the calculation functions is called.
	/// @note The passed VolumeData structure must be fully initialized and contain a render instance. This can only be achieved by copying/initializing from an existing VolumeData.
	/// @param[in] sd									A volume data to use and modify. @callerOwnsPointed{VolumeData}
	/// @param[in] type								Set the calculation @formatParam{type} according to the method to call. See the default call order of MaterialData::InitCalculation().
	//----------------------------------------------------------------------------------------
	void InitCalculation(VolumeData* sd, INITCALCULATION type) { MatCall(InitCalculation) (sd, type); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Check if the materials are identical.
	/// @note Only the name of the compared materials can be different.
	/// @param[in] snd								The material to compare with.
	/// @return												@trueIfOtherwiseFalse{the materials contents are the same}
	//----------------------------------------------------------------------------------------
	Bool Compare(BaseMaterial* snd);

	//----------------------------------------------------------------------------------------
	/// Retrieves the preview picture of the material.
	/// @param[in] flags							0 for the material editor preview, 1 for the viewport preview.
	/// @return												The preview picture. Guaranteed to be valid, i.e. not @formatConstant{nullptr}.
	/// @note To check if the preview has been calculated successfully, calling GetBw() on the returned bitmap should give a value superior than @em 0.
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetPreview(Int32 flags);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	RayIllumination* GetRayIllumination() { return MatCall(GetRayIllumination)(); }

	//----------------------------------------------------------------------------------------
	/// Gets an average color for the material, based on the material preview.
	/// @param[in] channel						An optional specific channel to get the average for: @enumerateEnum{CHANNEL}
	/// @return												The average color.
	//----------------------------------------------------------------------------------------
	Vector GetAverageColor(Int32 channel = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Retrieves information about what the material requires from the raytracer and what it will return.
	/// @return												The return values are: @enumerateEnum{VOLUMEINFO}
	//----------------------------------------------------------------------------------------
	VOLUMEINFO GetRenderInfo() { return MatCall(GetRenderInfo) (); }

	//----------------------------------------------------------------------------------------
	/// Checks if the material supports viewport transparency.
	/// @return												@trueIfOtherwiseFalse{the material support viewport transparency}
	//----------------------------------------------------------------------------------------
	Bool HasEditorTransparency() { return MatCall(HasEditorTransparency) (); }

	//----------------------------------------------------------------------------------------
	/// Initializes the preview image for the editor.
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool InitEditorPreviewImage(Int32 exponent, BaseDocument *doc, BaseThread *th, Int32 doccolorspace, Bool linearworkflow) { return MatCall(InitEditorPreviewImage)(exponent, doc, th, doccolorspace, linearworkflow); }

	//----------------------------------------------------------------------------------------
	/// Initializes the preview image for the editor into a given BaseBitmap
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool InitEditorPreviewImage(BaseBitmap *bmp, BaseDocument* doc, BaseThread* th, Int32 doccolorspace, Bool linearworkflow) const { return MatCall(InitEditorPreviewImage2)(bmp, doc, th, doccolorspace, linearworkflow); }

	/// @}
};

class ReflectionLayer;

//-------------------------------------------------------------------------------------------------
/// The material with the @ref Mmaterial type.
/// @addAllocFreeAutoAllocNote
/// @see Mmaterial.h for container IDs.
//-------------------------------------------------------------------------------------------------
class Material : public BaseMaterial
{
private:
	Material();
	~Material();

public:

	/// @name Allocation
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{material}
	/// @return												@allocReturn{material}
	//----------------------------------------------------------------------------------------
	static Material* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{materials}
	/// @param[in] bl									@theToDestruct{material}
	//----------------------------------------------------------------------------------------
	static void Free(Material*& bl);

	/// @}

	/// @name Get/Set Channel State
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the state of a channel (if it is enabled or disabled).
	/// @param[in] channel						The channel type: @enumerateEnum{CHANNEL}
	/// @return												@trueIfOtherwiseFalse{the channel is enabled for this material}
	//----------------------------------------------------------------------------------------
	Bool GetChannelState(Int32 channel) { return C4DOS_Mt->GetChannelState(this, channel); }

	//----------------------------------------------------------------------------------------
	/// Sets the state of a channel (if it is enabled or disabled).
	/// @param[in] channel						The type of the channel to enable or disable: @enumerateEnum{CHANNEL}
	/// @param[in] state							@trueOtherwiseFalse{to enable the given @formatParam{channel}}
	//----------------------------------------------------------------------------------------
	void SetChannelState(Int32 channel, Bool state) { C4DOS_Mt->SetChannelState(this, channel, state); }

	/// @}

	/// @name Reflection/Specular Layer Access
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a reflection/specular layer.
	/// @since R16
	/// @return												The added reflection/specular layer. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	ReflectionLayer* AddReflectionLayer() { return C4DOS_Mt->AddReflectionLayer(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a reflection/specular layer by ID.
	/// @since R16
	/// @param[in] id									The layer ID.
	/// @return												The reflection/specular layer. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	ReflectionLayer* GetReflectionLayerID(Int32 id) { return C4DOS_Mt->GetReflectionLayerID(this, id); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a reflection/specular layer by index.
	/// @since R16
	/// @param[in] index							The layer index.
	/// @return												The reflection/specular layer. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	ReflectionLayer* GetReflectionLayerIndex(Int32 index) { return C4DOS_Mt->GetReflectionLayerIndex(this, index); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the transparency layer.
	/// @since R16
	/// @return												The transparency layer, or @formatConstant{nullptr} if not available. @cinemaOwnsPointed{layer}
	//----------------------------------------------------------------------------------------
	ReflectionLayer* GetReflectionLayerTrans() { return C4DOS_Mt->GetReflectionLayerTrans(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of reflection/specular layers.
	/// @since R16
	/// @return												The reflection/specular layers' count.
	//----------------------------------------------------------------------------------------
	Int32 GetReflectionLayerCount() { return C4DOS_Mt->GetReflectionLayerCount(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of reflection/specular layers. Transparency layers can be optionally included in the count.
	/// @since R22
	/// @param[in] includeTransparencyLayers	Specifies if transparency layers should be included in the count.
	/// @return												The reflection/specular layers' count.
	//----------------------------------------------------------------------------------------
	Int32 GetReflectionLayerCount(Bool includeTransparencyLayers) { return C4DOS_Mt->GetReflectionLayerCount2(this, includeTransparencyLayers); }

	//----------------------------------------------------------------------------------------
	/// Removes a reflection/specular layer by ID.
	/// @since R16
	/// @param[in] id									The layer ID.
	//----------------------------------------------------------------------------------------
	void RemoveReflectionLayerID(Int32 id) { C4DOS_Mt->RemoveReflectionLayerID(this, id); }

	//----------------------------------------------------------------------------------------
	/// Removes a reflection/specular layer by index.
	/// @since R16
	/// @param[in] index							The layer index.
	//----------------------------------------------------------------------------------------
	void RemoveReflectionLayerIndex(Int32 index) { C4DOS_Mt->RemoveReflectionLayerIndex(this, index); }

	//----------------------------------------------------------------------------------------
	/// Deletes all reflection/specular layers.
	/// @since R16
	//----------------------------------------------------------------------------------------
	void RemoveReflectionAllLayers() { C4DOS_Mt->RemoveReflectionAllLayers(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves all the reflection/specular shaders.
	/// @since R16
	/// @param[out] shaders						Assigned all the reflection/specular shaders. @cinemaOwnsPointed{shaders}
	//----------------------------------------------------------------------------------------
	void GetAllReflectionShaders(maxon::BaseArray<BaseShader*>& shaders) { C4DOS_Mt->GetAllReflectionShaders(this, shaders); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the indices to the primary reflection and specular layers (can be -1 for empty).
	/// @since R16
	/// @param[out] reflection_layer	The most significant reflection layer.
	/// @param[out] specular_layer		The most significant specular layer.
	//----------------------------------------------------------------------------------------
	void GetReflectionPrimaryLayers(Int32 &reflection_layer, Int32 &specular_layer) { C4DOS_Mt->GetReflectionPrimaryLayers(this, reflection_layer, specular_layer); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	static Bool RenderViewportImage(Material* material, BaseDocument* baseDocument, Int32 sizeExponent, Int32 xMin, Int32 yMin, Int32 xMax, Int32 yMax, BaseThread* parentThread, BaseBitmap& bitmap) { return C4DOS_Mt->RenderViewportImage(material, baseDocument, sizeExponent, xMin, yMin, xMax, yMax, parentThread, bitmap); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	static void ComputeFresnelMetal(Int32 fresnelMetal, Vector& fresnelIOR, Vector& fresnelK) { C4DOS_Mt->ComputeFresnelMetal(fresnelMetal, fresnelIOR, fresnelK); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	static Float ComputeFresnelDielectric(Int32 fresnelPreset) { return C4DOS_Mt->ComputeFresnelDielectric(fresnelPreset); }

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// The node-based material with the @ref Mbase type.
/// This class is a collection of accessors to node-related functionality that are grouped for clarity purposes.
/// Note that any BaseMaterial can be elevated to a NodeMaterial, no special construction is needed.
//-------------------------------------------------------------------------------------------------
class NodeMaterial : public BaseMaterial
{
private:
	NodeMaterial();
	~NodeMaterial();

public:

	//-------------------------------------------------------------------------------------------------
	/// Checks whether the node space under the provided id was instantiated for the material.
	/// @param[in] spaceId									The id of the node space.
	/// @return															Returns true if the node space exists, false otherwise.
	//-------------------------------------------------------------------------------------------------
	Bool HasSpace(const maxon::Id& spaceId) const { return C4DOS_Mt->HasSpace(*this, spaceId); }

	//-------------------------------------------------------------------------------------------------
	/// Returns the node path to the material end node.
	/// @param[in] spaceId									The id of the node space.
	/// @param[out] result									The path to the material end node.
	/// @return															OK on success, or IllegalStateError if the material does not have this space.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<void> GetMaterialNodePath(const maxon::Id& spaceId, maxon::NodePath& result) const { return C4DOS_Mt->GetMaterialNodePath(*this, spaceId, result); }

	//-------------------------------------------------------------------------------------------------
	/// Returns the node path to the solo node.
	/// @param[in] spaceId									The id of the node space.
	/// @param[out] result									The path to the solo node, empty if nothing was soloed.
	/// @return															OK on success, or IllegalStateError if the material does not have this space.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<void> GetSoloNodePath(const maxon::Id& spaceId, maxon::NodePath& result) const { return C4DOS_Mt->GetSoloNodePath(*this, spaceId, result); }

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding BaseList element for a GraphNode.
	/// @param[in] spaceId									The id of the node space.
	/// @param[in] nodePath									Absolute Path to the Node.
	/// @return															BaseList2D element. The return value can be nullptr if there's no corresponding element, or if it refers to an inner node.
	//----------------------------------------------------------------------------------------
	maxon::Result<const BaseList2D*> GetBaseListForNode(const maxon::Id& spaceId, const maxon::NodePath& nodePath) { return C4DOS_Mt->GetBaseListForNode(*this, spaceId, nodePath); }

	//----------------------------------------------------------------------------------------
	/// Calculates the DescID for a given port.
	/// @param[in] spaceId									The id of the node space.
	/// @param[in] node											The node that owns the port.
	/// @param[in] port											The port.
	/// @param[out] result									The description ID of the port.
	/// @return															OK on success. If no description representation exists an error will be returned.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> GetDescIDForNodePort(const maxon::Id& spaceId, const maxon::GraphNode& node, const maxon::GraphNode& port, DescID& result) const { return C4DOS_Mt->GetDescIDForNodePort(*this, spaceId, node, port, result);	}

	//-------------------------------------------------------------------------------------------------
	/// Determines the paths pointing to directories that are used to reference images by relative path in a particular BaseDocument.
	/// @param[in] secondaryPath									(Optional) allows to provide the DOCUMENT_SECONDARYPATH.
	/// @param[in] documentPath										The path of the BaseDocument.
	/// @param[out] result												The set of paths in which the images may be located.
	/// @return																		OK on success, or OutOfMemoryError if the allocation failed.
	///
	/// Generally, the usage is as follows:
	/// @code
	/// maxon::BaseArray<maxon::Url> textureSearchPaths;
	/// BaseDocument* doc = GetActiveDocument();
	/// maxon::Url docpath = doc ? maxon::MaxonConvert(doc->GetDocumentPath(), maxon::MAXONCONVERTMODE::NONE) : maxon::Url();
	/// NodeMaterial::GetTextureSearchPaths(maxon::Url(), docpath, textureSearchPaths) iferr_return;
	/// @endcode
	///
	/// If needed, secondaryPath may be determined as follows:
	/// @code
	/// maxon::Url secondaryPath = maxon::MaxonConvert(doc->GetDataInstanceRef().GetFilename(DOCUMENT_SECONDARYPATH), maxon::MAXONCONVERTMODE::NONE);
	/// @endcode
	//-------------------------------------------------------------------------------------------------
	static maxon::Result<void> GetTextureSearchPaths(const maxon::Url& secondaryPath, const maxon::Url& documentPath, maxon::BaseArray<maxon::Url>& result) { return C4DOS_Mt->GetTextureSearchPaths(secondaryPath, documentPath, result); }

	//-------------------------------------------------------------------------------------------------
	/// Returns the material owner of the provided graph.
	/// Please note that the returned BaseMaterial is only safe for access in the usual places of the API. You must avoid
	/// to perform read or write access to it in an arbitrary worker thread.
	/// @param[in] graph										The node graph of the owner.
	/// @return															Returns the owner of the node graph, null if unknown or on failure to retrieve.
	//-------------------------------------------------------------------------------------------------
	static BaseMaterial* GetMaterial(const maxon::nodes::NodesGraphModelRef& graph) { return C4DOS_Mt->GetMaterial(graph); }

	//-------------------------------------------------------------------------------------------------
	/// Returns the node graph for the provided node space id.
	/// @param[in] spaceId									The id of the node space.
	/// @return															Returns the node graph, or IllegalStateError if the material does not have this space.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<const maxon::nodes::NodesGraphModelRef&> GetGraph(const maxon::Id& spaceId) const { return C4DOS_Mt->GetGraph(*this, spaceId); }

	//-------------------------------------------------------------------------------------------------
	/// Creates a node graph for the provided node space identifier if a graph does not already exist.
	/// @param[in] spaceId									The id of the node space.
	/// @return															OK on success, or error on failure of graph creation.
	//-------------------------------------------------------------------------------------------------
	[[deprecated("Use CreateDefaultGraph or CreateEmptyGraph.")]] maxon::Result<void> AddGraph(const maxon::Id& spaceId) { return C4DOS_Mt->AddGraph(*this, spaceId); }

	//-------------------------------------------------------------------------------------------------
	/// Creates a node graph populated with default nodes for the provided node space identifier if a graph does not already exist.
	/// @param[in] spaceId									The id of the node space.
	/// @return															OK on success, or error on failure of graph creation.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<void> CreateDefaultGraph(const maxon::Id& spaceId) { return C4DOS_Mt->CreateDefaultGraph(*this, spaceId); }

	//-------------------------------------------------------------------------------------------------
	/// Creates an empty node graph for the provided node space identifier if a graph does not already exist.
	/// @param[in] spaceId									The id of the node space.
	/// @return															OK on success, or error on failure of graph creation.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<void> CreateEmptyGraph(const maxon::Id& spaceId) { return C4DOS_Mt->CreateEmptyGraph(*this, spaceId); }

	//-------------------------------------------------------------------------------------------------
	/// Removes a node graph for the provided node space id if there is a graph.
	/// @param[in] spaceId									The id of the node space.
	/// @return															OK on success, or error if removal fails.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<void> RemoveGraph(const maxon::Id& spaceId) { return C4DOS_Mt->RemoveGraph(*this, spaceId); }

	//----------------------------------------------------------------------------------------
	/// Returns the BaseList2D element with the given uuid.
	/// @param[in] spaceId						The id of the node space.
	/// @param[in] uuid								Uuid to find.
	/// @return												BaseList2D object on success.
	maxon::Result<BaseList2D*> UuidToBaseList2D(const maxon::Id& spaceId, const maxon::Uuid& uuid) const { return C4DOS_Mt->UuidToBaseList2D(*this, spaceId, uuid); }

	//----------------------------------------------------------------------------------------
	/// Returns the BaseList2D element with the given uuid using an externally provided link resolve mechanism.
	/// @param[in] spaceId						The id of the node space.
	/// @param[in] uuid								Uuid to find.
	/// @param[in] linkResolveFunc		Function to resolve the BaseLink.
	/// @return												BaseList2D object on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<BaseList2D*> UuidToBaseList2DResolveLink(const maxon::Id& spaceId, const maxon::Uuid& uuid, const maxon::NodeMaterialLinkResolveFunc& linkResolveFunc) { return C4DOS_Mt->UuidToBaseList2DResolveLink(*this, spaceId, uuid, linkResolveFunc); }

	//----------------------------------------------------------------------------------------
	/// Returns the uuid of the given BaseList2D object.
	/// @param[in] spaceId						The id of the node space.
	/// @param[in] object							BaseList2D object to find.
	/// @return												Uuid on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<maxon::Uuid> BaseList2DToUuid(const maxon::Id& spaceId, BaseList2D* object) const { return C4DOS_Mt->BaseList2DToUuid(*this, spaceId, object); }
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASEMATERIAL_H__
