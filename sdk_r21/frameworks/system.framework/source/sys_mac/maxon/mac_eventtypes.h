#ifndef MAC_EVENTTYPES_H__
#define MAC_EVENTTYPES_H__

#ifdef MAXON_TARGET_MACOS
#import <AppKit/NSevent.h>

// Starting with 10.12 the naming scheme for the event types has changed.
#if (__MAC_OS_X_VERSION_MAX_ALLOWED < 101200)

static const NSEventType NSEventTypeLeftMouseDown = NSLeftMouseDown;
static const NSEventType NSEventTypeLeftMouseUp = NSLeftMouseUp;
static const NSEventType NSEventTypeRightMouseDown = NSRightMouseDown;
static const NSEventType NSEventTypeRightMouseUp = NSRightMouseUp;
static const NSEventType NSEventTypeMouseMoved = NSMouseMoved;
static const NSEventType NSEventTypeLeftMouseDragged = NSLeftMouseDragged;
static const NSEventType NSEventTypeRightMouseDragged = NSRightMouseDragged;
static const NSEventType NSEventTypeMouseEntered = NSMouseEntered;
static const NSEventType NSEventTypeMouseExited = NSMouseExited;
static const NSEventType NSEventTypeKeyDown = NSKeyDown;
static const NSEventType NSEventTypeKeyUp = NSKeyUp;
static const NSEventType NSEventTypeFlagsChanged = NSFlagsChanged;
static const NSEventType NSEventTypeAppKitDefined = NSAppKitDefined;
static const NSEventType NSEventTypeSystemDefined = NSSystemDefined;
static const NSEventType NSEventTypeApplicationDefined = NSApplicationDefined;
static const NSEventType NSEventTypePeriodic = NSPeriodic;
static const NSEventType NSEventTypeCursorUpdate = NSCursorUpdate;
static const NSEventType NSEventTypeScrollWheel = NSScrollWheel;
static const NSEventType NSEventTypeTabletPoint = NSTabletPoint;
static const NSEventType NSEventTypeTabletProximity = NSTabletProximity;
static const NSEventType NSEventTypeOtherMouseDown = NSOtherMouseDown;
static const NSEventType NSEventTypeOtherMouseUp = NSOtherMouseUp;
static const NSEventType NSEventTypeOtherMouseDragged = NSOtherMouseDragged;

#endif
#endif

#endif // MAC_EVENTTYPES_H__
