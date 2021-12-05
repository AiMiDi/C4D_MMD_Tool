#ifndef MAC_URL_H__
#define MAC_URL_H__

#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFURL.h>

#include "maxon/error.h"
#include "maxon/mac_cfhelpers.h"

#ifdef __OBJC__
	#import <Foundation/NSURL.h>
  #import <Foundation/NSUserDefaults.h>
  #import <Foundation/NSPathUtilities.h>
  #import <Foundation/NSFileManager.h>
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Converts a Url to CFURLRef.
/// @param[in] fn									Url object.
/// @return												CFURLRef (can be nullptr). Make sure to delete CfRelease(cfUrl) to free the object.
//----------------------------------------------------------------------------------------
Result<CFAutoReference<CFURLRef>> ToCFURL(const Url& fn);

Result<Url> CFURLToUrl(const CFURLRef fn);

Result<Url> GetPreferencesPath(Bool localUser);
Result<Url> GetApplicationSupportPath(Bool localUser);

#ifdef __OBJC__
//----------------------------------------------------------------------------------------
/// Converts a Url to a CFURLRef.
/// @param[in] fn									Url object.
/// @return												NSAutoReference on success.
//----------------------------------------------------------------------------------------
Result<NSAutoReference<NSURL>> ToNSURL(const Url& fn);

Result<Url> NSURLToUrl(const NSURL* fn);

NSString* FindOrCreateDirectory(NSSearchPathDirectory searchPathDirectory, NSSearchPathDomainMask domainMask, NSString* appendComponent);
#endif

}

#endif // MAC_URL_H__
