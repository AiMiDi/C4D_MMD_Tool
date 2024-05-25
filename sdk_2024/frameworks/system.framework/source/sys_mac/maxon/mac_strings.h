#ifndef MAC_STRINGS_H__
#define MAC_STRINGS_H__

#include <CoreFoundation/CoreFoundation.h>
#include "maxon/string.h"
#include "maxon/mac_cfhelpers.h"

#ifdef __OBJC__
	#import <Foundation/NSString.h>
#endif

namespace maxon
{

// for iOS and Mac OS

#ifdef __OBJC__
	//----------------------------------------------------------------------------------------
	/// Converts a String to NSString.
	/// @param[in] in									String object.
	/// @return											ARC-managed NSString* (can contain nullptr).
	//----------------------------------------------------------------------------------------
	NSString* ToNSStringARC(const String& in);

	//----------------------------------------------------------------------------------------
	/// Converts a CString to NSString.
	/// @param[in] in									CString object.
	/// @return											ARC-managed NSString* (can contain nullptr).
	//----------------------------------------------------------------------------------------
	NSString* ToNSStringARC(const CString& in);

	//----------------------------------------------------------------------------------------
	/// Converts a String to NSString.
	/// @param[in] in									String object.
	/// @return												NSStrongRef (can contain nullptr).
	//----------------------------------------------------------------------------------------
	NSStrongRef<NSString> ToNSString(const String& in);

	//----------------------------------------------------------------------------------------
	/// Converts a CString to NSString.
	/// @param[in] in									CString object.
	/// @return												NSStrongRef (can contain nullptr).
	//----------------------------------------------------------------------------------------
	NSStrongRef<NSString> ToNSString(const CString& in);

	//----------------------------------------------------------------------------------------
	/// Converts a NSString to String.
	/// @param[in] in									Pointer to NSString (can be nullptr).
	/// @return												String object.
	//----------------------------------------------------------------------------------------
	String NSToString(const NSString* in);
#endif

//----------------------------------------------------------------------------------------
/// Converts a String to CFStringRef.
/// @param[in] in									String object.
/// @return												CFStrongRef (can contain nullptr).
//----------------------------------------------------------------------------------------
CFStrongRef<CFStringRef> ToCFString(const String& in);

//----------------------------------------------------------------------------------------
/// Converts a CString to CFStringRef.
/// @param[in] in									CString object.
/// @return												CFStrongRef (can contain nullptr).
//----------------------------------------------------------------------------------------
CFStrongRef<CFStringRef> ToCFString(const CString& in);

//----------------------------------------------------------------------------------------
/// Converts a CFStringRef to String.
/// @param[in] in									CFStringRef (can be nullptr).
/// @return												String object.
//----------------------------------------------------------------------------------------
String CFToString(const CFStringRef in);

CFStringRef CreateCFString(const String& in);

} // namespace maxon

#endif // MAC_STRINGS_H__
