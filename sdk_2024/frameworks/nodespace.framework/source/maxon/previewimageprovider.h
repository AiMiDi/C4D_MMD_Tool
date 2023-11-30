#ifndef PREVIEWIMAGEPROVIDER_H__
#define PREVIEWIMAGEPROVIDER_H__

// TODO: (Maik) Improve the nodes API the following:
// - Refactor the 'SUBJECT': Possibly expect a clone + nodepath to be provided from the outside. 
//   This would make viewport and GUI provider handling more consistent.
// - Replace the tuple (iterationIndex, iterationCount) with a 'Bool needsMoreIterations'. This information is sufficient for task management. 
//   Progress handling should be done differently anyway.
// - Make Pause/Resume more consistent (which happens to all other tasks when the gradient bar is requested).
//   This may require an AtomicInt to query cancellation or pause.
// - Change data of SamplesFloat32Ref from 'StrongRef' to 'StrongCOWRef'

#include "maxon/job.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"
#include "maxon/delegate.h"
#include "maxon/timevalue.h"
#include "maxon/datadictionary.h"
#include "maxon/range.h"
#include "maxon/graph.h"

namespace maxon
{

namespace nodes
{

namespace PREVIEW
{

	//----------------------------------------------------------------------------------------
	/// STAGE defines the state of a preview image result. 
	//----------------------------------------------------------------------------------------
	enum class STAGE
	{
		//----------------------------------------------------------------------------------------
		/// Indicates that the preview computation is still in progress. The result is not final.
		//----------------------------------------------------------------------------------------
		CALCULATING,

		//----------------------------------------------------------------------------------------
		/// Indicates that the preview computation was terminated with an error.
		//----------------------------------------------------------------------------------------
		ERROR,

		//----------------------------------------------------------------------------------------
		/// Indicates that the preview computation finished successfully.
		//----------------------------------------------------------------------------------------
		FINISHED,

		//----------------------------------------------------------------------------------------
		/// Indicates that the preview computation was interrupted.
		//----------------------------------------------------------------------------------------
		THREADCANCELLED,
	} MAXON_ENUM_LIST(STAGE);

	//----------------------------------------------------------------------------------------
	/// IMAGESIZE defines the size of the node preview in the GUI. 
	//----------------------------------------------------------------------------------------
	enum class IMAGESIZE
	{
		DEFAULT = 2000,			///< Use system default.
		SMALL,							///< Small.
		MEDIUM,							///< Medium.
		BIG,								///< Big.
		LARGE								///< Large.
	} MAXON_ENUM_LIST(IMAGESIZE);

	//----------------------------------------------------------------------------------------
	/// IMAGESIZE_PIX defines the size of the square node preview in the GUI in pixels.
	//----------------------------------------------------------------------------------------
	namespace IMAGESIZE_PIX
	{
		static const Int32 SMALL = 60;
		static const Int32 MEDIUM = 90;
		static const Int32 BIG = 120;
		static const Int32 LARGE = 150;
	}

	//----------------------------------------------------------------------------------------
	/// SCENETYPE defines the choice for the 3D scene to be used in a node preview.
	/// This property only applies to nodes of an Id that as been assigned to
	/// maxon::nodes::NODESPACE::MATERIALPREVIEWIDS .
	///
	/// The files used by the Standard Space are located in the resource folder '$C4D/resource/modules/c4d_xtensions/preview_scenes/'.
	/// Note that this list should be kept in sync with MatPreviewType defined in customgui_matpreview.h .
	//----------------------------------------------------------------------------------------
	enum class SCENETYPE
	{
		MatPreviewDefault = 999,					///< Default (may be a user preference).
		MatPreviewFlat2D = 1000,					///< Flat 2D
		MatPreviewCube,										///< Cube.
		MatPreviewPlane,									///< Plane.
		MatPreviewCylinder,								///< Cylinder.
		MatPreviewTorus,									///< Torus.
		MatPreviewPlaneBack,							///< Plane Backlight.
		MatPreviewSphere,									///< Sphere.
		MatPreview2Torus,									///< Double Torus.
		MatPreviewRoundedCube,						///< Rounded Cube.
		MatPreviewKnot,										///< Knot.
		MatPreviewMultipleObjects,				///< Multiple Objects.
		MatPreviewCandle,									///< Candle.
		MatPreviewCloth,									///< Cloth.
		MatPreviewGem,										///< Gem.
		MatPreviewObjectAnim,							///< Animated Object.
		MatPreviewObject,									///< Object.
		MatPreviewUser = 1050							///< %User.
	} MAXON_ENUM_LIST(SCENETYPE);

	//----------------------------------------------------------------------------------------
	/// Node preview type and size.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(IMAGESIZE, ImageSize, "imagesize");
	MAXON_ATTRIBUTE(SCENETYPE, SceneType, "scenetype");

	//----------------------------------------------------------------------------------------
	/// The timestamp allows manual control over triggering a preview request on value change.
	/// 
	/// The preview thumbnails of a particular node can be forced to update as following:
	/// @code
	/// maxon::GraphTransaction transaction = graph.BeginTransaction() iferr_return;
	/// const Int currentTimestamp = node.GetValue(maxon::nodes::PREVIEW::Timestamp).GetValueOrDefault() iferr_return;
	/// node.SetValue(maxon::nodes::PREVIEW::Timestamp, currentTimestamp + 1) iferr_return;
	/// transaction.Commit() iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Int, Timestamp, "timestamp");

} // namespace PREVIEW

//----------------------------------------------------------------------------------------
/// Convenience definitions for the immutable preview image.
//----------------------------------------------------------------------------------------
using SampleFloat32 = Vec4<Float32>;
using SamplesFloat32 = BaseArray<SampleFloat32>;
using SamplesFloat32Ref = StrongRef<SamplesFloat32>;
using SamplesFloat32ConstRef = StrongRef<const SamplesFloat32>;
class PreviewImageProviderRef;

namespace PREVIEWIMAGEREQUEST
{
	///----------------------------------------------------------------------------------------
	/// Enum used to specify the scaling policy for baking or exporting textures
	/// ALSO DEFINED IN exchange.framework/source/maxon/material/materialexport.h
	///----------------------------------------------------------------------------------------
	enum class TextureResize
	{
		ALWAYS = 0,	///< Legacy behaviour. Textures should be up- and downscaled to the requested texture dimensions.
		OFF = 1,	///< Textures should be passed with their native resolution.
		DONT_ENLARGE = 2,	///< Textures should only be downscaled to the requested texture dimensions.
	} MAXON_ENUM_LIST(TextureResize);

	//----------------------------------------------------------------------------------------
	/// Defines the requested preview size in pixels.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(IntVector2d, TEXTURESIZE, "net.maxon.nodes.previewimagerequest.texturesize");

	//----------------------------------------------------------------------------------------
	/// Defines the requested texture scaling policy.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(TextureResize, TEXTURE_RESIZE, "net.maxon.nodes.previewimagerequest.textureresize");

	//----------------------------------------------------------------------------------------
	/// Defines whether a request was made for a flipped version.
	///
	/// Note that this attribute is managed internally and the flip is performed automatically on the provided SamplesFloat32ConstRef buffer.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Bool, FLIPVERTICALLY, "net.maxon.nodes.previewimagerequest.flipvertically");

	//----------------------------------------------------------------------------------------
	/// Constraints the iterative refinement from 1*1 to w*h sized results. 
	/// 0: only one iteration with size w*h is performed
	/// 1: iterations from 1*1 to w*h are performed. The progression is effectively doubling with each iteration. Taken samples are re-used during refinement
	/// n: the first iteration has at least size a*b, where a,b = [1,n]. It is guaranteed that the lowest iteration has at most n samples in the largest dimension. Note it may have only 1 sample in the other dimension.
	/// 
	/// In order to query whether a provider should provide progressive results, or not (because the requester is waiting for the final results), it is sufficient to check this:
	/// @code
	/// const maxon::Bool renderProgressively = request.Get<maxon::UInt32>(maxon::nodes::PREVIEWIMAGEREQUEST::PROGRESSIONTHRESHOLD, maxon::UInt32(1)) != maxon::UInt32(0);
	/// @endcode
	///
	/// Please note that a provider does not have to follow the above-outlined range handling. The progression can be freely defined.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Int, PROGRESSIONTHRESHOLD, "net.maxon.nodes.previewimagerequest.progressionthreshold");

	//----------------------------------------------------------------------------------------
	/// For 2D previews defines the horizontal range to be sampled. A full range is defined by URANGE = [0.0, 1.0].
	/// Currently, this is only used by the gradient bar preview. All other previews are expected to be previewed in full.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Range<Float>, URANGE, "net.maxon.nodes.previewimagerequest.urange");

	//----------------------------------------------------------------------------------------
	/// For 2D previews defines the vertical range to be sampled. A full range is defined by VRANGE = [0.0, 1.0].
	/// Currently, this is only used by the gradient bar preview. All other previews are expected to be previewed in full.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Range<Float>, VRANGE, "net.maxon.nodes.previewimagerequest.vrange");

	//----------------------------------------------------------------------------------------
	/// The type of the 3D scene.
	///
	/// It is only defined for 3d previews, i.e. when the SUBJECT has a maxon::Id that was added to
	/// maxon::nodes::NODESPACE::MATERIALPREVIEWIDS .
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(PREVIEW::SCENETYPE, SCENETYPE, "net.maxon.nodes.previewimagerequest.scenetype");

	//----------------------------------------------------------------------------------------
	/// SUBJECT points to the node requested for preview.
	/// Specifically, it may either directly point to the output (sampling) port of the node, or
	/// it may point to the node itself, accompanied with a set of TEXTUREIDS.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(GraphNode, SUBJECT, "net.maxon.nodes.previewimagerequest.subject");

	//----------------------------------------------------------------------------------------
	/// The set of attributes requested for preview, e.g. by the viewport. The expected result is a stack of textures.
	/// For example, one entry may hold the value maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::SPECULAR_COLOR
	/// to indicate a request to bake specular color.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Id>, TEXTUREIDS, "net.maxon.nodes.previewimagerequest.textureids");

	//----------------------------------------------------------------------------------------
	/// Defines the instance of a PreviewImageProviderRef that is used to compute the preview.
	/// Generally, it is expected to be populated in calls to
	/// MaterialExchangeInterface::ConfigureTextureProviderRequest(), and
	/// NodeSpaceDataInterface::ConfigurePreviewImageRequestFunc()
	///
	/// This attribute effectively defines a instantiation factory for your preview baker.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Class<PreviewImageProviderRef>, PROVIDER, "net.maxon.nodes.previewimagerequest.provider");

	//----------------------------------------------------------------------------------------
	/// INTENT gives and indication of the intention for preview query of a particular subject.
	/// Most previews are used by the viewport in form of a texture stack or by 2D GUI components in form of (shared) thumbnail images.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(maxon::InternedId, INTENT, "net.maxon.nodes.previewimagerequest.intent");
	MAXON_ATTRIBUTE(void, INTENT_NODE2D, "net.maxon.nodes.previewimagerequest.intent_node2d");														///< Used for previews in node editor, attribute manager, material manager.
	MAXON_ATTRIBUTE(void, INTENT_MATERIALEXCHANGE, "net.maxon.nodes.previewimagerequest.intent_materialexchange");				///< Used for material preview in viewport and material export.
	MAXON_ATTRIBUTE(void, INTENT_GRADIENTBAR, "net.maxon.nodes.previewimagerequest.intent_gradientbar");									///< Used for gradient preview bar in attribute manager (overlayed by knots and other gizmos).
	MAXON_ATTRIBUTE(void, INTENT_GRADIENTAVERAGE, "net.maxon.nodes.previewimagerequest.intent_gradientaverage");					///< Used for gradient knot creation to determine knot color.

} // namespace PREVIEWIMAGEREQUEST

//----------------------------------------------------------------------------------------
/// Defines a result image. Instances that have been returned (c.f. TakeOutput) are expected to be 
/// immutable to allow safe shared ownership of the pixel data.
//----------------------------------------------------------------------------------------
struct PreviewImageProviderOutputImage
{
	//----------------------------------------------------------------------------------------
	/// The image size in width and height. Its product has to match the size of @_samplesFloat32Linear, i.e.
	/// _imageSize.x * _imageSize.y = _samplesFloat32Linear->GetCount().
	//----------------------------------------------------------------------------------------
	IntVector2d _imageSize;

	//----------------------------------------------------------------------------------------
	/// The pixel data of the result preview image in linear color space.
	/// Pixels are defined as (r, g, b, a) values in row-major order.
	/// It is expected to give away ownership to the underlying data, avoiding any read or write access to it after return.
	//----------------------------------------------------------------------------------------
	SamplesFloat32ConstRef _samplesFloat32Linear;

	//----------------------------------------------------------------------------------------
	/// Defines whether this preview result is final for the current state of the subject within the the node graph.
	/// A final state can then be used for cache revival later on and may be waited for by blocking preview request calls, e.g.
	/// coming from the HW Renderer or from viewport with an enabled "Animate Preview" setting for the respective node material.
	//----------------------------------------------------------------------------------------
	Bool _isFinal = true;
};

MAXON_DATATYPE(PreviewImageProviderOutputImage, "net.maxon.nodes.datatype.previewimageprovideroutputimage");

//----------------------------------------------------------------------------------------
/// Defines the current preview image result. It is possible to define differently resoluted
/// intermediate results, e.g. providing progressively upscaled and temporarily accumulated
/// renderings to listeners such PreviewImageRequest instances.
/// In case multiple images have been requested, it is valid to return only some entries, or multiple
/// entries in different states. However, updating the 'stack' in lockstep may be the safest approach. For example:
/// First Iteration:  [roughness,  64 x  64], [alpha,  64 x  64]
/// Second iteration: [roughness, 128 x 128], [alpha, 128 x 128]
///
//----------------------------------------------------------------------------------------
struct PreviewImageProviderOutput
{
	//----------------------------------------------------------------------------------------
	/// The index of the current preview iteration. A valid value in is range [0, n - 1] where
	/// n is the total number of iterations @_iterationCount.
	/// The final iteration has the value n - 1;
	///
	/// This parameter must be set properly, but is subject to removal in the future.
	//----------------------------------------------------------------------------------------
	Int _currentIterationIndex = -1;

	//----------------------------------------------------------------------------------------
	/// The total number of n iterations. A valid value is in range [1, n].
	/// The iteration count may vary and dynamically increase during computation.
	///
	/// This parameter must be set properly, but is subject to removal in the future.
	//----------------------------------------------------------------------------------------
	Int _iterationCount = -1;

	//----------------------------------------------------------------------------------------
	/// Defines whether the preview result computation has finished and there's no need for further iterations.
	/// In the case of handling multiple preview images in lockstep, this approach is recommended:
	/// @code
	/// const maxon::Bool isFinal = (previewImageResolutionsPyramid.GetCount() - _lastFinishedPreviewImageResolutionsPyramidIndex) <= 1;
	/// @endcode
	//----------------------------------------------------------------------------------------
	Bool _isFinal = true;

	//----------------------------------------------------------------------------------------
	/// This container allows the attachment of generic data to the requesting component.
	//----------------------------------------------------------------------------------------
	DataDictionary _metadata;

	//----------------------------------------------------------------------------------------
	/// Sets a result image under the provided key. For viewport support it is expected to store under the requested maxon::Id's from PREVIEWIMAGEREQUEST::TEXTUREIDS. 
	/// @param[in] key				The key under which the image is stored.
	/// @param[in] image			The (immutable) preview image.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	template <typename KEY>
	Result<void> SetArrayResult(const KEY& key, const PreviewImageProviderOutputImage& image)
	{
		iferr_scope;
		_results.Set(key, image) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Sets a result image under the default key. This storage location is read by GUI components where no image stacks are requested.
	/// @param[in] image			The (immutable) preview image.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	Result<void>SetResult(const PreviewImageProviderOutputImage& image)
	{
		iferr_scope;
		_results.Set(Id(), image) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the container for all preview images. It can be assumed that entries are of type
	/// Tuple<KEY=maxon::Data, VALUE=maxon::nodes::PreviewImageProviderOutputImage> where KEY is often, but not always of type maxon::Id.
	/// @return								The preview image container.
	//----------------------------------------------------------------------------------------
	const DataDictionary& GetResults() const
	{
		return _results;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the preview image stored under the default key.
	/// @return								The preview image..
	//----------------------------------------------------------------------------------------
	const PreviewImageProviderOutputImage GetResult() const
	{
		return _results.Get(Id(), PreviewImageProviderOutputImage());
	}

private:

	//----------------------------------------------------------------------------------------
	/// This container holds all result images.
	//----------------------------------------------------------------------------------------
	DataDictionary _results;

};

class PreviewImageProviderRef;

//----------------------------------------------------------------------------------------
/// PreviewImageProvider interface implements the provision of an preview image stream of a node in
/// a particular state.
/// This interface is closely coupled to the NodeSpaceInterface which defines the type of PreviewImageProvider
/// that is instantiated when a preview on a node is requested. The request may have different intends including
/// but not limited to:
/// - the thumbnail in the material manager,
/// - the thumbnails in the attribute manager and node editor,
/// - the gradient bar in the gradient node,
/// - textures for the viewport, as well as
/// - (future) bake requests for caching an material export.
///
/// Generally it can be expected that PreviewImageProvider instances are created by a dedicated JobQueue
/// that manages and prioritizes the preview computations in a round-robin manner where multiple previews
/// are active in parallel. The amount of active instances is limited to ensure fluid user interaction.
/// Hence, it is not recommended to model dependencies such as wait conditions between PreviewImageProvider instances.
///
/// Due to the asynchronous nature of the scheduling mechanism it is not safe to access the active BaseDocument
/// from a PreviewImageProvider.
/// 
/// User interactions such as dragging a slider will lead to a continuous instantiation and cancellation
/// of PreviewImageProviders. Note that cancellation of an outdated state is not blocking the instantiation
/// of the more recent state. Consequently, it is recommended to regularly react to cancellation within the 
/// ComputeIteration function to avoid overflowing of already cancelled instances.
/// 
//----------------------------------------------------------------------------------------
class PreviewImageProviderInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(PreviewImageProviderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.previewimageprovider");

public:

	//----------------------------------------------------------------------------------------
	/// Called to initialize the provider by safely extracting all data from the @p request.
	/// Please see the attributes in maxon::nodes::PREVIEWIMAGEREQUEST for data extraction.
	/// Safety is achieved by making this call blocking with respect to changes in the node graph
	/// and the parallel round-robin based scheduling manager.
	/// It is therefore recommended to keep this method light-weight and perform heavier computations
	/// during the first call to @ComputeIteration.
	/// @param[in] request			The request containing information about how to bake or render which node.
	/// @param[in] numThreads		The recommended maximum number of threads to use during @ComputeIteration.
	/// @return									OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Initialize(const DataDictionaryObjectRef& request, Int numThreads);

	//----------------------------------------------------------------------------------------
	/// Called asynchronously to indicate the desire to proceed with node preview computation.
	/// The execution of this function blocks one spot in the parallel round-robin based scheduling manager.
	/// The asynchronous nature of this call makes this unsafe to access the original node graph.
	/// Instead, a copy should be made during @Initialize.
	///
	/// It is guaranteed the the time windows of calls to @Initialize, @ComputeIteration, @GetOutput
	/// never overlap. Iterations are called one after another, with possible breaks in between
	/// to switch computation efforts to other previews.
	///
	/// Note that ComputeIteration may be again after being cancelled in a prior call, fulfilling
	/// the use case of pause and resume.
	/// @param[in] parentThread		Query the caller for cancellation state.
	/// @return										OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ComputeIteration(const JobRef& parentThread); 

	//----------------------------------------------------------------------------------------
	/// Called when performing a successful iteration. The caller assumes shared ownership of immutable data.
	/// It is therefore prohibited to change the contents of the attaches SamplesFloat32Linear buffers after return.
	/// In case progressively refined results are provided, we recommend to copy over data from previous
	/// iterations that have been returned earlier.
	/// @return										The preview image result that is dispatched to listeners.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<PreviewImageProviderOutput> TakeOutput();
};

#include "previewimageprovider1.hxx"

#include "previewimageprovider2.hxx"

} // namespace nodes
} // namespace maxon

#endif // PREVIEWIMAGEPROVIDER_H__
