#include "lib_browser.h"
#include "lib_description.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif

//////////////////////////////////////////////////////////////////////////

static BrowserLib *lib_browser = nullptr;

static inline BrowserLib *CheckBrowserLib(Int32 offset)
{
	return (BrowserLib *) CheckLib(BROWSER_LIB_ID, offset, (C4DLibrary **) &lib_browser);
}

//////////////////////////////////////////////////////////////////////////
#define BrowserCallSR(method, error_value) \
	BrowserLib* lib = CheckBrowserLib(LIBOFFSET(BrowserLib, browser)); \
	if (!lib || !lib->browser) \
		return error_value; \
	return lib->browser->method

Bool SDKBrowser::MountPresetLibrary(const Filename& fn, UInt32 flags, SDKBrowserURL* domain)
{
	BrowserCallSR(MountPresetLibrary, false)(fn, flags, domain);
}

Bool SDKBrowser::ConvertPresetLibrary(const Filename& fn, Bool ask)
{
	BrowserCallSR(ConvertPresetLibrary, false)(fn, ask);
}



//////////////////////////////////////////////////////////////////////////

#define ReferenceObjectCall( method)	\
	BrowserLib *lib = CheckBrowserLib( LIBOFFSET( BrowserLib, reference_object.method)); \
	if (!lib || !lib->reference_object.method)	\
		return; \
	(((ReferenceObject *)this)->*lib->reference_object.method)

void	SDKReferenceObject::add_reference(void)
{
	ReferenceObjectCall(add_reference )();
}

void	SDKReferenceObject::remove_reference(void)
{
	ReferenceObjectCall(remove_reference )();
}

//////////////////////////////////////////////////////////////////////////
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
