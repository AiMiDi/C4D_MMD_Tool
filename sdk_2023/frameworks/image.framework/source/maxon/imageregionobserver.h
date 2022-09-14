#ifndef IMAGEREGIONOBSERVER_H__
#define IMAGEREGIONOBSERVER_H__

#include "maxon/interfacebase.h"
#include "maxon/fid.h"
#include "maxon/vector2d.h"
#include "maxon/range.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This interface defines the notifiers to observe regional image changes.
//----------------------------------------------------------------------------------------
class ImageRegionObserverRef;
class ImageRegionObserverInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ImageRegionObserverInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.imageregionobserver");

public:

	//----------------------------------------------------------------------------------------
	/// Notifies about the connection to an image observable. This marks the beginning of the observation.
	/// @param[in] dimensions					The image size.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> OnConnect(const IntVector2d& dimensions);

	//----------------------------------------------------------------------------------------
	/// Notifies about the resize of the observed image.
	/// @param[in] dimensions					The new image size.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void OnResize(const IntVector2d& dimensions);

	//----------------------------------------------------------------------------------------
	/// Notifies about a regional invalidation of the observed image.
	/// @param[in] dirtyRegion				The pixel area that has been invalidated.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void OnRegionDirty(const Range<IntVector2d>& dirtyRegion);

	//----------------------------------------------------------------------------------------
	/// Notifies about the disconnection from the observed image. This marks the end of the observation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void OnDisconnect();
};

//----------------------------------------------------------------------------------------
/// This class defines a registrar of observers to regional image changes.
//----------------------------------------------------------------------------------------
class ImageRegionObservableRef;
class ImageRegionObservableInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ImageRegionObservableInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.imageregionobservable");

public:

	//----------------------------------------------------------------------------------------
	/// Registers an observer for regional image changes. 
	/// @param[in] observerId					The identifier of the observer. Does not have to be unique.
	/// @param[in] observer						The observer to register.
	/// @return												The registration ticket on success. Releasing the return value results in de-registration of the observer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericData> RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer);
};

//----------------------------------------------------------------------------------------
/// This class offers the dispatch of changes to image regions and image size to all registered observers.
///
/// The usage of observable and observers is the following:
/// @code
/// // We construct the observable.
/// maxon::ImageRegionObservableHandlerRef handler = maxon::ImageRegionObservableHandlerInterface::Create(maxon::IntVector2d(imageWidth, imageHeight)) iferr_return;
/// maxon::ImageRegionObservableRef registrar = handler.GetObservable() iferr_return;
/// 
/// // We construct and register the observer, see 'maxon/imageregionobserver_helpers.h'
/// maxon::ImageRegionTilesObserverRef observer = maxon::ImageRegionSingleTileObserverClass().Create() iferr_return;
/// observer.Init(observerTileSize) iferr_return;
/// maxon::GenericData observerRegistration = registrar.RegisterObserver(Id("my tiles observer"), observer) iferr_return;
/// 
/// // We fetch the initial, completely invalidated, state.
/// maxon::ImageRegionTilesObserverInterface::DirtyState fullImageState;
/// observer.GetAndResetDirtyState(fullImageState) iferr_return;
/// 
/// // We dispatch a notification about a change in a 2x2 pixel region.
/// const maxon::Range<maxon::IntVector2d> fourPixels = maxon::Range<maxon::IntVector2d>(maxon::IntVector2d(0, 0), maxon::IntVector2d(1, 1));
/// handler.MarkDirty(fourPixels) iferr_return;
/// 
/// // We fetch and consume the four changed pixels. Depending on the tile boundaries, 
/// // they may be scattered over four adjacent tiles, e.g. with an observerTileSize = 1
/// maxon::ImageRegionTilesObserverInterface::DirtyState fourPixelsState;
/// observer.GetAndResetDirtyState(fourPixelsState) iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------
class ImageRegionObservableHandlerRef;
class ImageRegionObservableHandlerInterface : public ImageRegionObservableInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(ImageRegionObservableHandlerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.imageregionobservablehandler");

public:
	//----------------------------------------------------------------------------------------
	/// Constructs . 
	/// @param[in] dimensions					The image size.
	/// @return												A valid observable on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ImageRegionObservableHandlerRef> Create(const IntVector2d& dimensions);

	//----------------------------------------------------------------------------------------
	/// Dispatches a notification about a change to the image size. 
	/// @param[in] dimensions					The new image size.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ResizeImage(const IntVector2d& dimensions);

	//----------------------------------------------------------------------------------------
	/// Dispatches a notification about a regional invalidation of the observed image.
	/// @param[in] dirtyRegion				The pixel area that has been invalidated.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> MarkDirty(const Range<IntVector2d>& dirtyRegion);
		
	//----------------------------------------------------------------------------------------
	/// Returns a reference to the registrar of observers.
	/// @return												A valid registrar on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ImageRegionObservableRef> GetObservable();
};

#include "imageregionobserver1.hxx"
#include "imageregionobserver2.hxx"

} // namespace maxon

#endif // IMAGEREGIONOBSERVER_H__
