#ifndef TOASTMESSAGE_H__
#define TOASTMESSAGE_H__

#include "maxon/object.h"

namespace maxon
{
//----------------------------------------------------------------------------------------
/// Formatter used to produce the display text of a toast message.
/// Always invoked with the current coalesced occurrence count, even for the very first
/// occurrence (@formatParam{count} = @em 1), so there is a single source of truth for the
/// displayed text.
/// @param[in] count						The number of times this toast message has been triggered while still visible/coalescing.
/// @return											A populated string containing the text to display.
///															Returning an error, or an empty string,
///															prevents the toast popup from being shown.
//----------------------------------------------------------------------------------------
using ToastMessageFormatter = Delegate<Result<String>(Int count)>;

//----------------------------------------------------------------------------------------
/// Delegate invoked when the user presses the action button of a toast message.
/// If several occurrences have been coalesced into a single toast, only the most recently
/// registered delegate is retained and fired.
/// @return												@ref OK on success, or an error if the action could not be performed.
//----------------------------------------------------------------------------------------
using ToastActionDelegate = Delegate<Result<void>()>;

//----------------------------------------------------------------------------------------
/// Represents a toast message that can be shown to the user.
/// A toast message is a small, transient notification typically anchored to the main
/// application window, displaying a short text and an optional action button.
///
/// Instances of this interface act as a stable identity for @em coalescing: if @ref Show
/// is called again on the @em same instance (or on a copy of the same reference) while the
/// previous toast triggered by it is still visible, the two occurrences are merged into a
/// single toast instead of showing two separate ones. The occurrence count passed to the
/// @ref ToastMessageFormatter reflects how many times @ref Show has been called for this
/// instance since the toast was last dismissed.
/// @note Instantiating this interface does not show anything by itself; nothing is
/// displayed until @ref Show is called.
/// @note To keep coalescing several related calls together, retain the same
/// @ref ToastMessageRef and call @ref Show on it repeatedly, rather than creating a new
/// reference for every occurrence.
//----------------------------------------------------------------------------------------
class ToastMessageInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ToastMessageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.toastmessage");

public:
	//----------------------------------------------------------------------------------------
	/// Sets the formatter used to compute the displayed text of the toast message.
	/// This must be set before calling @ref Show, since the text of the toast (for any
	/// occurrence count) is always derived from this formatter.
	/// @param[in] formatter					The formatter to use. @callerOwnsPointed{the moved-from delegate}
	/// @return												@ref OK on success, or an error if the formatter is invalid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetMessageFormatter(ToastMessageFormatter&& formatter);

	//----------------------------------------------------------------------------------------
	/// Sets the text and delegate of the toast message's action button.
	/// Setting an action button is optional; if never called, the toast is shown without one.
	/// If this toast is coalesced with a later occurrence, the action button text and
	/// delegate set by the most recent call are the ones retained and used.
	/// @param[in] actionButtonText		The text of the action button.
	/// @param[in] actionButtonDelegate	The delegate invoked when the action button is pressed. @callerOwnsPointed{the moved-from delegate}
	/// @return												@ref OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetActionButton(const String& actionButtonText, ToastActionDelegate&& actionButtonDelegate);

	/// The type of icon to show in the toast message.
	enum class ICON_TYPE
	{
		NONE,    ///< No icon is shown.
		WARNING, ///< A warning message.
		ERROR    ///< An error message.
	} MAXON_ENUM_LIST_CLASS(ICON_TYPE);

	//----------------------------------------------------------------------------------------
	/// Sets the type of icon shown alongside the toast message.
	/// Setting an icon is optional; if never called, the toast is shown without one (@ref ICON_TYPE::NONE).
	/// If this toast is coalesced with a later occurrence, the icon type set by the most recent
	/// call is the one retained and used.
	/// @param[in] iconType						The icon type to display. See @ref ICON_TYPE.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIconType(ICON_TYPE iconType);

	//----------------------------------------------------------------------------------------
	/// Shows the toast message.
	/// If a toast previously shown by this same instance is still visible, this occurrence
	/// is coalesced into it: the occurrence count is incremented, the message text is
	/// recomputed via the formatter set with @ref SetMessageFormatter, and the toast's
	/// visible-time is extended. Otherwise, a new toast is shown with an occurrence count of @em 1.
	/// @note @ref SetMessageFormatter must have been called with a valid formatter before this is called.
	/// @return												@ref OK on success, or an error if the toast could not be shown (for
	/// 															example, if no message formatter has been set).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Show();
};

#include "toastmessage1.hxx"

//----------------------------------------------------------------------------------------
/// The class used to allocate @ref ToastMessageRef instances.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<ToastMessageRef>, ToastMessageClass, "net.maxon.class.toastmessage");

#include "toastmessage2.hxx"

} // namespace maxon

#endif // TOASTMESSAGE_H__
