#ifndef NETWORK_IOSERVICE_H__
#define NETWORK_IOSERVICE_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/timer.h"

#include "network_types.h"

#include "maxon/conditionvariable_dep.h"


namespace maxon
{

using AioBuffer = BaseArray<Char>;

class AioStatusInterface;
class AioStatusRef;

class AioReaderInterface;
class AioReaderRef;

class AioWriterInterface;
class AioWriterRef;

class AioServiceInterface;
class AioServiceRef;

//----------------------------------------------------------------------------------------
/// This class is used to wait on the status of one or more asynchronous I/O operations.
//----------------------------------------------------------------------------------------
class AioStatusInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AioStatusInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.aiostatus");

public:
	static MAXON_METHOD AioStatusInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Waits until all of the depending operations are completed, or until an optional timeout is reached.
	/// After wait returns, the AioStatus can be re-used.
	///
	/// @param[in] timeout						See ConditionVariable::Wait();.
	/// @param[in] mode								See ConditionVariable::Wait();.
	/// @return												True if all operations succeeded, false on timeout, or the aggregated error(s) if one or more operations failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Wait(const TimeValue& timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT);

	//----------------------------------------------------------------------------------------
	/// Adds a new dependency Wait() has to wait for.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ConditionVariableDependency AddDependency();

	//----------------------------------------------------------------------------------------
	/// Adds an error to the aggregated result of Wait().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PushError(const Error& error);
};

//----------------------------------------------------------------------------------------
/// A reader that can receive asynchronous read notifications from an AioService.
//----------------------------------------------------------------------------------------
class AioReaderInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AioReaderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.aioreader");

public:
	//----------------------------------------------------------------------------------------
	/// Event callback to signal when a non-blocking read operation is (likely) possible.
	/// This function is never called concurrently.
	///
	/// @param[in] sockfd							The socket handle ready for reading.
	/// @param[in] result							An error if an operation registered by this reader failed.
	/// @return												An error if handling the event failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> NotifyForRead(SocketT sockfd, Result<void> result);
};

//----------------------------------------------------------------------------------------
/// A writer that can receive asynchronous write notifications from an AioService.
//----------------------------------------------------------------------------------------
class AioWriterInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AioWriterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.aiowriter");

public:
	//----------------------------------------------------------------------------------------
	/// Event callback to signal when a non-blocking write operation is (likely) possible.
	/// This function is never called concurrently.
	///
	/// @param[in] sockfd							The socket handle ready for writing.
	/// @param[in] result							An error if an operation registered by this reader failed.
	/// @return												An error if handling the event failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> NotifyForWrite(SocketT sockfd, Result<void> result);
};

//----------------------------------------------------------------------------------------
/// An AioService instance enables asynchronous network I/O for multiple writers/readers.
/// Its purpose is to wait on potentially blocking I/O operations in a separate worker thread.
/// Writers/readers can register at the AioService with a specific socket handle. They will
/// receive notifications when I/O on these sockets is ready.
/// Notifications happen through calls of the respective notification functions from the worker thread.
/// The actual I/O work is implemented in these notification functions.
///
/// AioService can demultiplex multiple I/O requests from a single-thread.
/// The advantage of this scheme is that it's not necessary to spin up one thread for every
/// blocking operation.
//----------------------------------------------------------------------------------------
class AioServiceInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AioServiceInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.aioservice");

public:
	static MAXON_METHOD AioServiceInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Registers a socket for reading. The given reader will be notified through its
	/// NotifyForRead function as soon as there's data available.
	/// This AioService instance will take shared ownership of the reader while it is registered.
	/// The socket is expected to remain valid until the reader is unregistered.
	/// If the registration succeeded, a unique registration ID is returned. It can be passed to
	/// UnregisterReader to remove the registration.
	///
	/// THREADSAFE.
	///
	/// @param[in] sockfd							The socket handle selected for reading.
	/// @param[in] reader							The reader to be notified when data is available.
	/// @return												A unique registration ID, or error if registration failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RegisterReader(SocketT sockfd, const AioReaderRef& reader);

	//----------------------------------------------------------------------------------------
	/// Unregisters a previously registered socket for reading, identified by the registration ID
	/// previously returned by the corresponding call to RegisterReader. If no reader with the
	/// given ID was found, the function has no effect.
	///
	/// THREADSAFE.
	///
	/// @param[in] id									A registration ID previously returned by RegisterReader.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void UnregisterReader(Int id);

	//----------------------------------------------------------------------------------------
	/// Analogously defined to RegisterReader, but for writer sockets instead of readers.
	/// The notification function is NotifyForWrite.
	///
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RegisterWriter(SocketT sockfd, const AioWriterRef& writer);

	//----------------------------------------------------------------------------------------
	/// Analogously defined to UnregisterReader, but for writer sockets instead of readers.
	///
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void UnregisterWriter(Int id);

	//----------------------------------------------------------------------------------------
	/// Starts this service. This will usually start at least one background thread to service I/O
	/// requests through notifications.
	///
	/// @return												OK, or error if the service was already started or an internal error occurred.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// Stops the service. If the service was already stopped, the function has no effect.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Stop();

	//----------------------------------------------------------------------------------------
	/// Stops the service and waits until the underlying I/O threads are shut down.
	/// If the service was already stopped, the function has no effect and returns immediately.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void StopAndWait();
};

#include "network_ioservice1.hxx"
#include "network_ioservice2.hxx"

} // namespace maxon

#endif // NETWORK_IOSERVICE_H__
