#ifndef MXANALYTICS_H__
#define MXANALYTICS_H__

#include "maxon/object.h"

namespace maxon
{
enum class CINEWAREUSAGETYPE : UInt64
{
	UNUSED = 0, // Cineware was started but was not used in any way

	LOADED = (1 << 0), // A c4d file was loaded.
	SAVED  = (1 << 1), // A document was saved as c4d file.

	IMPORTED = (1 << 2), // A non c4d file (either 3D format, image or other) was loaded.
	EXPORTED = (1 << 3), // A document was exported as an external file format.

	RENDERED_STANDARD = (1 << 4), // A rendering was started using the Standard renderer.
	RENDERED_PHYSICAL = (1 << 5), // A rendering was started using the Physical renderer.
	RENDERED_REDSHIFT = (1 << 6), // A rendering was started using Redshift.
	RENDERED_HARDWARE = (1 << 7), // A rendering was started using Preview Hardware renderer.
	RENDERED_OTHER = (1 << 8),		// A rendering was started using a third party renderer.

} MAXON_ENUM_FLAGS(CINEWAREUSAGETYPE);

//----------------------------------------------------------------------------------------
/// Provides functionality for metrics.
//----------------------------------------------------------------------------------------
class MxAnalyticsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(MxAnalyticsInterface, MAXON_REFERENCE_STATIC, "net.maxon.interface.mxanalytics");

public:
	//----------------------------------------------------------------------------------------
	/// Checks whether the MxAnalytics system has been initialized or not.
	/// @return								@trueIfOtherwiseFalse(MxAnalytics system has been initialized).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsMxAnalyticsInitialized();

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event.
	/// @param[in] identifier				Identifier - must not be empty!
	/// @param[in] key							Key - must not be empty!
	/// @param[in] value						Value.
	/// @param[in] omitEmpty				Omit key with empty value.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendEvent(const String& identifier, const String& key, const String& value, Bool omitEmpty = false);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event.
	/// @param[in] identifier				Identifier - must not be empty!.
	/// @param[in] keyValuePairs		Datadictionary of key + value string pairs - keys must not be empty!
	/// @param[in] omitEmpty				Omit keys with empty values.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendEvent(const String& identifier, const DataDictionary& keyValuePairs, Bool omitEmpty = false);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if an app was launched.
	/// @param[in] name							Name of the app.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendAppUsedEvent(const String& name);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a plugin was used.
	/// @param[in] name							Name of the plugin.
	/// @param[in] host							Name of the plugin host.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendPluginUsedEvent(const String& name, const String& host = "Cinema 4D"_s);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a preset was used.
	/// @param[in] name							Name of the preset.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendPresetUsedEvent(const String& name);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a tool was used.
	/// @param[in] name							Name of the tool.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendToolUsedEvent(const String& name);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a feature was used.
	/// @param[in] name							Name of the feature.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendFeatureUsedEvent(const String& name);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a frame was rendered.
	/// @param[in] batchSize				Batch size.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendFrameIncrementEvent(const Int32& batchSize);

	//----------------------------------------------------------------------------------------
	/// Sends / stores an MxAnalytics event if a rendering was finished.
	/// @param[in] name							Name of the event.
	/// @return								OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MxAnalyticsSendFrameSubmitEvent(const String& name);

	//----------------------------------------------------------------------------------------
	/// Marks the session as active usage of Cineware.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void MxAnalyticsSetCinewareUsage(maxon::CINEWAREUSAGETYPE usage);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void MxAnalyticsInit(const String& mainProductId, const String& selectedProductId, const String& licenseId, Bool isBetaAccount, Bool isProduction, const String& userId, Bool optedIn, Bool trialOptedIn, const String& language);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void MxAnalyticsEndCineware();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void MxAnalyticsEnd();
};

// include autogenerated headerfile here
#include "mxanalytics1.hxx"
#include "mxanalytics2.hxx"
}

#endif // MXANALYTICS_H__
