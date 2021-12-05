#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "operatingsystem.h"
#include "c4d_thread.h"

static void XThreadMain(void* data)
{
	((C4DThread*)data)->Main();
}

static Bool XThreadTest(void* data)
{
	return ((C4DThread*)data)->TestDBreak();
}

static const Char* XThreadName(void* data)
{
	return ((C4DThread*)data)->GetThreadName();
}

C4DThread::C4DThread(void)
{
	weak = false;
	bt = C4DOS.Bt->Alloc(XThreadMain, XThreadTest, this, XThreadName);
}

C4DThread::~C4DThread(void)
{
	if (!weak)
		C4DOS.Bt->Free(bt);
}

Bool C4DThread::Start(THREADMODE mode, THREADPRIORITYEX priority)
{
	if (!bt)
		return false;
	return C4DOS.Bt->Start(bt, mode, priority, nullptr);
}

void C4DThread::End(Bool wait)
{
	if (bt)
		C4DOS.Bt->End(bt, wait);
}

void C4DThread::Wait(Bool checkevents)
{
	if (bt)
		C4DOS.Bt->Wait(bt, checkevents);
}
