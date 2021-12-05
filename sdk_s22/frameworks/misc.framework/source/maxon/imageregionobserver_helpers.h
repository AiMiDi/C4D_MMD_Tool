#ifndef IMAGEREGIONOBSERVER_HELPERS_H__
#define IMAGEREGIONOBSERVER_HELPERS_H__

#include "imageregionobserver.h"
#include "maxon/hashmap.h"
#include "maxon/lazyinitthreaded.h"

namespace maxon
{
//----------------------------------------------------------------------------------------
/// This interface extends the notifiers about regional image changes with accessors to the tile-based tracking data structure.
//----------------------------------------------------------------------------------------
class ImageRegionTilesObserverInterface : MAXON_INTERFACE_BASES(ImageRegionObserverInterface)
{
	MAXON_INTERFACE(ImageRegionTilesObserverInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.imageregionobserver.tiles");

public:

	//----------------------------------------------------------------------------------------
	/// Initializes the tile-based change tracking data structure. Each tile contains an AABB. The number of tiles is determined
	/// as numTiles = ceil(imageWidth / tileSize) * ceil(imageHeight / tileSize).
	/// We recommend reasonable power-of-two values such as 64, 128, 256, 512 or 1024.
	/// @param[in] tileSize								The size of a tile in pixels.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Int tileSize);

	//----------------------------------------------------------------------------------------
	/// Defines the state of regional image changes as a collection of non-overlapping AABBs.
	//----------------------------------------------------------------------------------------
	struct DirtyState
	{
		Int _timestamp = -1; /// The current monotonically increasing timestamp.
		IntVector2d _dimensions; /// The current image dimensions.
		BufferedBaseArray<Range<IntVector2d>, 1> _dirtyTiles; /// The collection of changed image regions.
	};

	//----------------------------------------------------------------------------------------
	/// Returns and resets the accumulated region changes in form of a set of non-overlapping tiles.
	/// @param[out] dirtyState						The state to overwrite.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetAndResetDirtyState(DirtyState& dirtyState);
};

//----------------------------------------------------------------------------------------
/// This class is a convenience wrapper to manage the lifetime of and access to long-living observers.
/// It is only recommended to be used if smarter observer lifetime management is not feasible.
/// It can be easily placed into or along-side image data owning classes.
/// Observers are lazily registered on first fetch to avoid overhead if they are not used for a particular instance.
//----------------------------------------------------------------------------------------
class ImageRegionObserverStorage
{
	//----------------------------------------------------------------------------------------
	/// The pair of observer and its registration to the observable.
	//----------------------------------------------------------------------------------------
	struct StoredObserver
	{
		ImageRegionObserverRef _observer; /// the observer.
		GenericData _observerRegistration; /// the registration of the observer.
	};

public:

	//----------------------------------------------------------------------------------------
	/// Returns an observer that has added under a particular id.
	/// The first call to the method will trigger the lazy registration of all added observers.
	/// @return														A valid observer reference, or error.
	//----------------------------------------------------------------------------------------
	template<typename T_ObserverRef>
	Result<T_ObserverRef> GetObserver(const Id& observerId) const
	{
		iferr_scope;

		CheckState(_isInitialized == true);

		_lazyRegistration.Init(
			[&]() -> Result<void>
			{
				iferr_scope;
				for (auto& storedObserverEntry : _observers)
				{
					const Id& storedObserverId = storedObserverEntry.GetKey();
					StoredObserver& storedObserver = storedObserverEntry.GetValue();
					if (storedObserver._observerRegistration.IsEmpty() == true)
					{
						storedObserver._observerRegistration = _observableHandler.RegisterObserver(storedObserverId, storedObserver._observer) iferr_return;
					}
				}
				return OK;
			}, LazyInitThreaded::OPTIONS::NONE) iferr_return;

		auto observerEntry = _observers.Find(observerId);
		CheckState(observerEntry != nullptr);
		T_ObserverRef observer = Cast<T_ObserverRef>(observerEntry->GetValue()._observer);
		CheckState(observer != nullptr);
		return observer;
	}

	//----------------------------------------------------------------------------------------
	/// Gives access to adding an observer under a unique id.
	/// @param[in] observerId							The identifier of the observer. This identifier must be unique.
	/// @param[in] observer								The observer to add.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	using AddObserverFunc = Delegate<Result<void>(const Id & observerId, const ImageRegionObserverRef& observer)>;

	//----------------------------------------------------------------------------------------
	/// Gives access to the addition of an observer collection.
	/// @param[in] addObserver						The add function for an observer.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	using InitializeObserversFunc = Delegate<Result<void>(const AddObserverFunc& addObserver)>;

	//----------------------------------------------------------------------------------------
	/// Initializes the observable and creates a collection of long-living observers.
	/// @param[in] initializeObservers		The function that adds the observers.
	/// @param[in] lazyRegistration				Determines whether the added observers should be lazily registered, or immediately.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Initialize(const InitializeObserversFunc& initializeObservers, Bool lazyRegistration)
	{
		iferr_scope;
		CheckArgument(_isInitialized == false);
		CheckArgument(initializeObservers.IsPopulated() == true);

		_observableHandler = ImageRegionObservableHandlerInterface::Create(IntVector2d(0, 0)) iferr_return;
		_isInitialized = true;

		AddObserverFunc addObserverFunc = [&](const Id& observerId, const ImageRegionObserverRef& observer) -> Result<void>
		{
			iferr_scope;
			CheckState(observer != nullptr);
			CheckState(_observers.Contains(observerId) == false);

			StoredObserver storedObserver;
			storedObserver._observer = observer;
			if (lazyRegistration == false)
			{
				storedObserver._observerRegistration = _observableHandler.RegisterObserver(observerId, storedObserver._observer) iferr_return;
			}
			_observers.Insert(observerId, std::move(storedObserver)) iferr_return;
			return OK;
		};
		initializeObservers(addObserverFunc) iferr_return;

		if (lazyRegistration == false)
		{
			_lazyRegistration.Init([]() -> Result<void> {return OK; }, LazyInitThreaded::OPTIONS::NONE) iferr_return;
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the handler to the observable, giving access to the registrar of observers and notification dispatch.
	/// @return														The observable.
	//----------------------------------------------------------------------------------------
	const ImageRegionObservableHandlerRef& GetObservableHandler() const
	{
		return _observableHandler;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the observer storage is initialized.
	/// @return														True if initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return _isInitialized;
	}

private:

	Bool _isInitialized = false; /// the initialization state.
	mutable LazyInitThreaded _lazyRegistration; /// the lazy execute-once registration function.
	mutable HashMap<Id, StoredObserver> _observers; /// the collection of managed observers.
	ImageRegionObservableHandlerRef _observableHandler; /// the observable.
};

#include "imageregionobserver_helpers1.hxx"

//----------------------------------------------------------------------------------------
/// Performs a per-tile AABB tracking of changes. The class is thread-safe for conditions where
/// production and consumption of region changes are performed on different threads.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<ImageRegionTilesObserverRef>, ImageRegionSingleTileObserverClass, "net.maxon.class.imageregionobserver.tiles");

#include "imageregionobserver_helpers2.hxx"

} // namespace maxon

#endif // IMAGEREGIONOBSERVER_HELPERS_H__