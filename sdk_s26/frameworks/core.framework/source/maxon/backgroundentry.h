#ifndef BACKGROUNDENTRY_H__
#define BACKGROUNDENTRY_H__

#include "maxon/array.h"
#include "maxon/datetime.h"
#include "maxon/progress.h"
#include "maxon/object.h"
#include "maxon/observable.h"
#include "maxon/url.h"
#include "maxon/weakref.h"


namespace maxon
{

class BackgroundProgressRef;
class BackgroundEntryRef;

//----------------------------------------------------------------------------------------
/// BackgroundEntryInterface provides informations about a background entry. It's the base class for BackgroundProgressInterface.
//----------------------------------------------------------------------------------------
class BackgroundEntryInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(BackgroundEntryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.backgroundentry");

public:
	enum class STATE
	{
		NONE = 0,
		SUCCEEDED = 1 << 0, ///< Background Task succeeded
		CANCELED = 1 << 1,	///< Background Task was canceled
		WARNING = 1 << 2,		///< Background Task has warnings
		ERROR = 1 << 3,			///< Background Task has errors
	} MAXON_ENUM_FLAGS_CLASS(STATE);

	//----------------------------------------------------------------------------------------
	/// GetName returns the name of the entry.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// GetStartTime returns the time when the entry has been created (so it is the start time).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UniversalDateTime GetStartTime() const;

	//----------------------------------------------------------------------------------------
	/// GetDuration returns the duration of the entry.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeValue GetDuration() const;

	//----------------------------------------------------------------------------------------
	/// GetState returns the overall state of the entry. The highest level (e.g. error) defines the state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD STATE GetState();

	//----------------------------------------------------------------------------------------
	/// GetStates iterates over all state entries and calls the value receiver for each.
	/// @param[in] state							ValueReceiver which is called for every entry in the list. Return false to stop the iteration immediately.
	/// @return                       The return value of the ValueReceiver. True if all values were iterated and the callback did not stop the iteration.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const;

	//----------------------------------------------------------------------------------------
	/// GetStateCount description.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetStateCount() const;

	//----------------------------------------------------------------------------------------
	/// AddState adds a new state message to the entry.
	/// @param[in] state							see STATE.
	/// @param[in] message						Text of the message.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddState(STATE state, const String& message);
};

//----------------------------------------------------------------------------------------
/// Interface to announce background entries with progress management.
//----------------------------------------------------------------------------------------
class BackgroundProgressInterface : MAXON_INTERFACE_BASES(ProgressInterface, BackgroundEntryInterface)
{
	MAXON_INTERFACE(BackgroundProgressInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.backgroundprogress");

public:
	enum class STATECHANGE
	{
		ACTIVE_ADDED,						 ///< an active entry was added
		ACTIVE_REMOVED,					 ///< an active entry was removed
		HISTORY_ADDED,					 ///< a history entry was added
		HISTORY_REMOVED,				 ///< a history entry was removed
		CANCELDELEGATE_CHANGED,  ///< cancel delegate changed
	} MAXON_ENUM_LIST_CLASS(STATECHANGE);

	//----------------------------------------------------------------------------------------
	/// GetMaster returns the master instance of this implementation. this instance is used to visualize entries in the task manager.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BackgroundProgressRef GetMaster();

	//----------------------------------------------------------------------------------------
	/// AddActiveEntry adds a new active entry to the list. The object is stored only as WeakRef. So you take the ownership.
	/// Important: The last reference to the object will remove the object from the active list.
	/// @param[in] title							Text with the human readable name of the action.
	/// @param[in] sendToHistory			True if the entry should be moved to the history list after it's done.
	/// @return                       New BackgroundProgressRef entry on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory = true);

	//----------------------------------------------------------------------------------------
	/// RemoveActiveEntry removes the entry from the active list and moves it to the history.
	/// You can use this before the the last reference dies.
	/// @param[in] entry							Entry to remove from the active list.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry);

	//----------------------------------------------------------------------------------------
	/// GetActiveEntries calls the ValueReceiver for each active entry.
	/// @param[in] entry							Delegate which is called for every entry in the list.
	/// @return                       Result of the delegate.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const;

	//----------------------------------------------------------------------------------------
	/// GetActiveCount returns the number of active elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetActiveCount() const;

	//----------------------------------------------------------------------------------------
	/// GetHistoryEntries calls the ValueReceiver for each history entry.
	/// @param[in] entry							Delegate which is called for every entry in the list.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const;

	//----------------------------------------------------------------------------------------
	/// GetHistoryCount returns the number of history entries.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetHistoryCount() const;

	//----------------------------------------------------------------------------------------
	/// RemoveHistoryEntry removes the given entry from the history
	/// @param[in] entry							Entry to remove.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry);

	//----------------------------------------------------------------------------------------
	/// ClearHistory removes all history entries.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ClearHistory();

	//----------------------------------------------------------------------------------------
	/// ObservableStateChanged observable is called if the object adds or removes entries.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableStateChanged, (STATECHANGE state, const BackgroundEntryRef& entry), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableTotalProgressNotification observable is called if the overall progress of one of the elements changed.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTotalProgressNotification, (const BackgroundProgressRef& ref, Float percent), ObservableCombinerRunAllComponent);
};

//----------------------------------------------------------------------------------------
/// DataType which is added to the url (URLFLAGS::BACKGROUNDJOB) when calling a c4d scene filter/loader
/// maxon::Url url = MaxonConvert(name, MAXONCONVERTMODE::NONE);
/// maxon::BackgroundEntryTuple backgroundJob = url.Get(maxon::URLFLAGS::BACKGROUNDJOB, maxon::BackgroundEntryTuple());
/// maxon::BackgroundProgressRef job = backgroundJob.first;
/// if (job)
/// {
/// 	// add the master
/// 	backgroundJob.second = job.AddProgressJob(1.0, String()) iferr_return;
/// }
//----------------------------------------------------------------------------------------
using BackgroundEntryTuple = Tuple<WeakRef<BackgroundProgressRef>, Int>;

MAXON_DATATYPE(BackgroundEntryTuple, "net.maxon.datatyoe.backgroundentrytuple");

namespace URLFLAGS
{
	MAXON_ATTRIBUTE(BackgroundEntryTuple, BACKGROUNDJOB, "net.maxon.url.backgroundjob"); ///< Passes the background job through the url
}

#include "backgroundentry1.hxx"
#include "backgroundentry2.hxx"

} // namespace maxon



#endif // BACKGROUNDENTRY_H__
