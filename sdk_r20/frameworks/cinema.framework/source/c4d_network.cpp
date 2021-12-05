#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "operatingsystem.h"
#include "c4d_network.h"

#define NetCall(fnc)	(*C4DOS.Ne->fnc)
#define IpCall(fnc)		(this->*C4DOS.Ne->fnc)

void NetworkIpConnection::GetRemoteAddr(NetworkIpAddrPort& addr) const
{
	IpCall(GetRemoteAddr)(addr);
}

void NetworkIpConnection::GetHostAddr(NetworkIpAddrPort& addr) const
{
	IpCall(GetHostAddr)(addr);
}

Bool WriteIpAddr(const NetworkIpAddr& addr, HyperFile* hf)
{
	return NetCall(WriteIpAddr)(addr, hf);
}

Bool ReadIpAddr(NetworkIpAddr& addr, HyperFile* hf)
{
	return NetCall(ReadIpAddr)(addr, hf);
}

Bool WriteIpAddrPort(const NetworkIpAddrPort& addr, HyperFile* hf)
{
	return NetCall(WriteIpAddrPort)(addr, hf);
}

Bool ReadIpAddrPort(NetworkIpAddrPort& addr, HyperFile* hf)
{
	return NetCall(ReadIpAddrPort)(addr, hf);
}

NetworkIpConnection*	OpenListener(const NetworkIpAddrPort& adr, BaseThread* thread, Int sessionTimeout, Bool useNagleAlgorithm, Int* ferr)
{
	return NetCall(IpOpenListener) (adr, thread, sessionTimeout, useNagleAlgorithm, ferr);
}

NetworkIpConnection* OpenListener(const maxon::String& adr, BaseThread* thread, Int sessionTimeout, Bool useNagleAlgorithm, Int* ferr)
{
	return NetCall(IpOpenListenerString) (adr, thread, sessionTimeout, useNagleAlgorithm, ferr);
}

NetworkIpConnection*	OpenWaitForIncoming(NetworkIpConnection* listener, BaseThread* connection, Int* error)
{
	return NetCall(IpWaitForIncoming) (listener, connection, error);
}

NetworkIpConnection* OpenOutgoing(const NetworkIpAddrPort& adr, BaseThread* thread, Int connectTimeout, Int sessionTimeout, Bool useNagleAlgorithm, Int* error)
{
	return NetCall(IpOpenOutgoing) (adr, thread, connectTimeout, sessionTimeout, useNagleAlgorithm, error);
}

NetworkIpConnection* OpenOutgoing(const maxon::String& adr, BaseThread* thread, Int connectTimeout, Int sessionTimeout, Bool useNagleAlgorithm, Int* error)
{
	return NetCall(IpOpenOutgoingString) (adr, thread, connectTimeout, sessionTimeout, useNagleAlgorithm, error);
}

void CloseConnection(NetworkIpConnection*& ipc)
{
	if (ipc)
		NetCall(IpCloseConnection) (ipc);
	ipc = nullptr;
}

void KillConnection(NetworkIpConnection*& ipc)
{
	NetCall(IpKillConnection) (ipc);
}

Int BytesInInputBuffer(NetworkIpConnection* ipc)
{
	return NetCall(IpBytesInInputBuffer) (ipc);
}

Int RecvBytes(NetworkIpConnection* ipc, void* buf, Int size)
{
	return NetCall(IpReadBytes) (ipc, buf, size);
}

Int SendBytes(NetworkIpConnection* ipc, const void* buf, Int size)
{
	return NetCall(IpSendBytes) (ipc, (void*)buf, size);
}
