#ifndef PREVIEWIMAGESUBSCRIPTION_H__
#define PREVIEWIMAGESUBSCRIPTION_H__

#include "maxon/previewimageprovider.h"

// For the time being, the implementation of this interface requires access to some old data types inside a hybrid module.
// We make sure this interface can be conveniently used regardless:
#ifdef __API_INTERN__
#undef MAXON_DEPENDENCY_ENABLE
#endif

namespace maxon
{

// Please include "maxon/gfx_image.h" in order to access to the data type of the preview result.
class ImageTextureRef;

namespace nodes
{

namespace PREVIEWIMAGESUBSCRIPTION
{

} // namespace PREVIEWIMAGESUBSCRIPTION

	//----------------------------------------------------------------------------------------
	/// This delegate defines the informer about preview image results for an observed node as
	/// visible in the node previews of the attribute manager as well as the material node editor.
	/// The preview computations are performed as asynchronous streams and dispatched
	/// to all registered PreviewImageSubscriptionResultFunc delegates.
	/// Because the call to PreviewImageSubscriptionResultFunc is blocking for preview computations
	/// it is recommended to keep its implementation light-weight and hand over heavier computations
	/// to another job.
	///
	/// Generally, a change in the observed node will trigger such a state transition:
	/// CALCULATING -> CALCULATING -> CALCULATING -> FINISHED | THREADCANCELLED | ERROR
	/// The amount of CALCULATING steps depends on how the executed PreviewImageProvider
	/// handles progressive results.
	///
	/// The provided image may be null on error, cancellation or at first calculation @stage.
	/// Is it prohibited to modify the provided image in any way. Shared ownership with other
	/// observers must be assumed.
	/// @param[in] stage						The state of the preview result.
	/// @param[in] image						The preview image result, may be null.
	//----------------------------------------------------------------------------------------
using PreviewImageSubscriptionResultFunc = Delegate<void(PREVIEW::STAGE stage, const ImageTextureRef& image)>;

//----------------------------------------------------------------------------------------
/// The PreviewImageSubscription interface implements the stream-based provision of preview images of a node
/// that undergoes continuous state changes.
/// This mechanism is used by the node previews in the attribute manager and node editor.
/// The preview resolution and the evaluated output port of the observed @SUBJECT are
/// internally managed to be in sync with the user choices made in the attribute manager or node editor.
/// Changes to these attributes will trigger the provision of new preview images.
/// Value changes to the node itself or its input dependencies will trigger new updates as well, 
/// including user-interaction based edits to parameters and animation-driven changes.
/// 
/// The preview images are blended against the background checkerboard according to the
/// settings for WPREF_ALPHA_GRID_COLOR at startup time for Cinema4d, and provided in linear color space.
///
/// Internally, this interface accesses a cache shared among all instances of PreviewImageSubscription.
/// For efficiency reasons, PreviewImageSubscription instances that reference the same subject
/// are grouped together and informed one after another with identical results, avoiding to create identical preview images multiple times.
/// The preview image stream is created by instantiation of PreviewImageRequest.
///
/// The internal image cache entries are cleared after a delay of 60 seconds if no matching PreviewImageSubscription instances references it anymore.
/// For example, this avoids recreating preview images when browsing through hierarchies in the attribute manager, 
/// or when closing and re-opening the node editor.
///
/// We recommend to pay close attention to the lifetime of PreviewImageSubscription and destroy and create them only
/// when presenting preview images to the user. Letting a PreviewImageSubscription go out-of-scope leads to automatic
/// unsubscription. Please note that the provided PreviewImageSubscriptionResultFunc may be called after destruction the PreviewImageSubscription instance
/// for a brief time window. We recommend to safe-guard for this circumstance appropriately.
///
/// This high-level abstraction provides very limited parameters and is therefore simple to setup:
/// @code
/// maxon::StrongRef<MyGuiClass> instance = this;
/// maxon::WeakRef<maxon::StrongRef<MyGuiClass>> weakInstance = instance;
/// 
/// maxon::nodes::PreviewImageSubscriptionResultFunc resultFunction;
/// resultFunction.CopyFrom(
/// 	[weakInstance](maxon::nodes::PREVIEWIMAGESUBSCRIPTION::STAGE stage, const maxon::ImageTextureRef& previewRef)
/// 	{
/// 		DiagnosticOutput("New preview image available!");
/// 
/// 		maxon::StrongRef<MyGuiClass> instance = weakInstance;
/// 		if (instance != nullptr)
/// 		{
/// 			instance->SetPreviewImage(previewImage);
/// 		}
/// 	}) iferr_return;
///
/// maxon::nodes::PreviewImageSubscriptionRef previewSubscription = maxon::nodes::PreviewImageSubscriptionInterface::Create() iferr_return;
/// _previewSubscription = previewSubscription;
/// _previewSubscription.Activate(myGraphNode, std::move(resultFunction)) iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------

class PreviewImageSubscriptionRef;
class PreviewImageSubscriptionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(PreviewImageSubscriptionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.previewimagesubscription");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
public:

	//----------------------------------------------------------------------------------------
	/// Create a subscription.
	/// @return											The subscription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PreviewImageSubscriptionRef> Create();

	//----------------------------------------------------------------------------------------
	/// Submit the subscription request for a chosen node. The provided @p resultFunction may be called immediately, so make
	/// sure to not hold problematic locks.
	/// Releasing the reference PreviewImageSubscription results in automatic unsubscription.
	/// @param[in] node							The node for which previews should be provided.
	/// @param[in] resultFunction		The delegate for preview image provision.
	/// @return											OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Activate(const GraphNode& node, PreviewImageSubscriptionResultFunc&& resultFunction);

};

#include "previewimagesubscription1.hxx"

#include "previewimagesubscription2.hxx"

} // namespace nodes
} // namespace maxon

#ifdef __API_INTERN__
#define MAXON_DEPENDENCY_ENABLE
#endif

#endif // PREVIEWIMAGESUBSCRIPTION_H__
