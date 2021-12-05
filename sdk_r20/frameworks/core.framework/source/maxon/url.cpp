#include "maxon/url.h"
#include "maxon/iohandler.h"
#include "maxon/ioconnection.h"

namespace maxon
{

UInt UrlInterface::GetHashCode() const
{
	UInt hash = GetPath().GetHashCode();
	hash = 31 * hash + GetScheme().GetHashCode();

	const UrlScheme& scheme = GetAuthority().GetScheme();
	if (scheme != UrlScheme())
		hash = 31 * hash + GetAuthority().GetHashCode();

	return hash;
}

Result<IoConnectionRef> UrlInterface::OpenConnection() const
{
	IoHandler handler = IoHandlerInterface::GetHandlerForScheme(GetScheme());
	if (handler)
		return handler.OpenConnection(this);
	return IoConnectionRef();
}

Result<OutputStreamRef> UrlInterface::OpenOutputStream(OPENSTREAMFLAGS flags) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;
	auto outputstream = connection.OpenOutputStream(flags) iferr_return;

	return outputstream;
}

Result<InputStreamRef> UrlInterface::OpenInputStream(OPENSTREAMFLAGS flags) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;
	auto inputstream = connection.OpenInputStream(flags) iferr_return;

	return inputstream;
}

Result<InOutputStreamRef> UrlInterface::OpenInOutputStream(OPENSTREAMFLAGS flags) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;
	auto outputstream = connection.OpenInOutputStream(flags) iferr_return;

	return outputstream;
}

Result<IoBrowseRef> UrlInterface::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;
	auto browseRef = connection.GetBrowseIterator(flags) iferr_return;

	return browseRef;
}

IODETECT UrlInterface::IoDetect() const
{
	iferr (auto connection = OpenConnection())
	{
		// DiagnosticOutput("@", err);
		return IODETECT::ERRORSTATE;
	}

	return connection.IoDetect();
}

Result<Url> UrlInterface::Normalize(NORMALIZEFLAGS flags) const
{
	iferr_scope;

	Url tmp;
	IoHandler handler = IoHandlerInterface::GetHandlerForScheme(GetScheme());
	if (!handler)
	{
		// The default handler doesn't implement Normalize, nor IoNormalize, so
		// we get this handler to directly call IoBaseHandler::Normalize which
		// contains the default behaviour for this function
		handler = IoHandlerInterface::GetHandlerForScheme(Id("handler"));
	}

	if (handler)
	{
		tmp = handler.Normalize(this, flags) iferr_return;
	}
	else
	{
		tmp = this;
	}

	return tmp;
}

Result<Url> UrlInterface::IoNormalize(NORMALIZEFLAGS flags) const
{
	iferr_scope;

	Url tmp;
	IoHandler handler = IoHandlerInterface::GetHandlerForScheme(GetScheme());
	if (!handler)
	{
		// The default handler doesn't implement Normalize, nor IoNormalize, so
		// we get this handler to directly call IoBaseHandler::IoNormalize which
		// contains the default behaviour for this function
		handler = IoHandlerInterface::GetHandlerForScheme(Id("handler"));
	}

	if (handler)
	{
		tmp = handler.IoNormalize(this, flags) iferr_return;
	}
	else
	{
		tmp = this;
	}

	return tmp;
}

Result<IOATTRIBUTES> UrlInterface::IoGetAttributes() const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;

	return connection.IoGetAttributes();
}

Result<void> UrlInterface::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;

	return connection.IoSetAttributes(flags, mask);
}

Result<UniversalDateTime> UrlInterface::IoGetTime(IOTIMEMODE mode) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;

	return connection.IoGetTime(mode);
}

Result<void> UrlInterface::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const
{
	iferr_scope;

	auto connection = OpenConnection() iferr_return;

	return connection.IoSetTime(mode, dateTime);
}

struct NameAndFlags
{
	NameAndFlags(const Url& name, Bool isDirectory) : _name(name), _isDirectory(isDirectory) { }

	Url		_name;
	Bool	_isDirectory;
};

static Result<void> DeleteDirectoryRecursively(const Url& dir, Bool force)
{
	iferr_scope;

	// safety, don't delete root
	if (dir.IsEmpty() || dir.GetDirectory().IsEmpty())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "input path is empty"_s);

	BaseArray<NameAndFlags> arr;

	// browse whole level before deletion is started
	// If the directory is empty, an error is returned, but it is no error.
	for (const auto& it : dir.GetBrowseIterator(GETBROWSEITERATORFLAGS::NOERRORONOPEN))
	{
		const IoBrowseRef& browseiterator = (it) iferr_return;
		Bool isDirectory = (browseiterator.IoGetFlags() & IOBROWSEFLAGS::IS_DIRECTORY) && !(browseiterator.IoGetFlags() & IOBROWSEFLAGS::IS_LINK);
		arr.Append(NameAndFlags(browseiterator.GetCurrentPath(), isDirectory)) iferr_return;
	}

	for (Int i = 0; i < arr.GetCount(); i++)
	{
		if (arr[i]._isDirectory)
		{
			DeleteDirectoryRecursively(arr[i]._name, force) iferr_return;
		}
		else
		{
			arr[i]._name.IoDelete(force) iferr_return;
		}
	}

	return dir.IoDelete(force);
}

Result<void> UrlInterface::IoDelete(Bool force, Bool recursive) const
{
	if (recursive)
	{
		IODETECT state = IoDetect();

		if (state == IODETECT::DIRECTORY)
			return DeleteDirectoryRecursively(this, force);
	}

	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoDelete(force);
}

Result<void> UrlInterface::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const
{
	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoCreateDirectory(createParents, createdDirs);
}

Result<void> UrlInterface::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) const
{
	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoCopyFile(destName, overwrite, removeReadOnly);
}

Result<void> UrlInterface::IoMove(const Url& destName) const
{
	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoMove(destName);
}

Result<void> UrlInterface::IoRename(const Url& newName) const
{
	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoRename(newName);
}

Result<void> UrlInterface::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
{
	availableBytes = totalBytes = 0;

	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoGetFreeVolumeSpace(availableBytes, totalBytes);
}

Result<void> UrlInterface::IoShowInOS(IOSHOWINOSFLAGS flags) const
{
	iferr (auto connection = OpenConnection())
		return err;

	return connection.IoShowInOS(flags);
}

template <> Result<InputStreamRef&> UrlOrInputStream::GetStream()
{
	iferr_scope;
	_error iferr_return;
	if (_url.IsPopulated() && !_stream)
	{
		_stream = _url.OpenInputStream(_flags) iferr_return;
	}
	CheckState(_stream);
	return reinterpret_cast<InputStreamRef&>(_stream);
}

template <> Result<OutputStreamRef&> UrlOrOutputStream::GetStream()
{
	iferr_scope;
	_error iferr_return;
	if (_url.IsPopulated() && !_stream)
	{
		_stream = _url.OpenOutputStream(_flags) iferr_return;
	}
	CheckState(_stream);
	return reinterpret_cast<OutputStreamRef&>(_stream);
}

template <typename STREAM> Result<void> UrlOrStream<STREAM>::Close()
{
	return (_url.IsPopulated() && _stream) ? reinterpret_cast<BaseStreamRef&>(_stream).Close() : OK;
}

template class UrlOrStream<InputStreamRef>;
template class UrlOrStream<OutputStreamRef>;

} // namespace maxon
