#include "maxon/mediasession_output.h"
#include "maxon/mediasession_input.h"
#include "maxon/crashreportproperty.h"



namespace maxon
{

Result<MediaSessionRef> MediaSessionImport(const Url& fileName, const TimeValue& targetTime, MEDIASESSIONFLAGS flags,
	const MediaOutputRef& outputConverter, const MediaOutputSelectionHandler& selectionHandler,
	const MediaSessionProgressCallback& progressCallback, const FileFormatHandler& preferredHandler)
{
	iferr_scope;

	// setup media session crash variables.
	CrashReportProperty geMediaSessionImport("MediaSessionImport", fileName);
	CrashReportProperty geMediaSessionImportTime("MediaSessionImportTime", targetTime);
	CrashReportProperty geMediaSessionImportRunOnlyAnalyze("MediaSessionImportFlags", flags);
	MediaSessionRef session;
	Bool secondRun = false;

	FileFormatDetectionInterface::DetectedCallback checkHandler;

	checkHandler.CopyFrom([&session, &selectionHandler, &outputConverter, &targetTime, flags, &secondRun, &progressCallback, preferredHandler]
		(const Url& url, const FileFormatHandler& handler) -> Result<Bool>
		{
			iferr_scope_handler
			{
				session = nullptr;
				return err;
			};

			if (secondRun && handler == preferredHandler)
				return false;

			MediaInputRef loaderRef = handler.CreateHandler<MediaInputRef>(url) iferr_return;

			outputConverter.ResetConverter() iferr_return;
			outputConverter.SetSelectionHandler(selectionHandler) iferr_return;

			session = MediaSessionObject().Create() iferr_return;
			session.ConnectMediaConverter(loaderRef, outputConverter) iferr_return;

			if (progressCallback)
			{
				MediaSessionProgressRef progress = session.GetProgress();
				progress.InitProgress(Milliseconds(250.0), Milliseconds(100.0)) iferr_return;
				progress.ObservableProgressNotification().AddObserver(progressCallback, JobQueueRef()) iferr_return;
			}

			// evaluate the MediaSession to load the data into the buffer
			session.Convert(targetTime, flags) iferr_return;

			return true;
		}) iferr_return;

	BaseArray<FileFormatHandler> fileFormats;
	Bool res = false;

	if (preferredHandler)
	{
		res = checkHandler(fileName, preferredHandler) iferr_return;
		if (res)
		{
			fileFormats.Append(preferredHandler) iferr_return;
		}
		else
		{
			secondRun = true;
		}
	}

	if (!res)
	{
		fileFormats = FileFormatDetectionInterface::DetectAll<MediaInputRef>(fileName, checkHandler) iferr_return;
	}

	// default error;
	if (fileFormats.IsEmpty() || !session)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Image @ is not of a supported type.", fileName));

	return session;
}

} // namespace maxon
