#ifndef IO_H__
#define IO_H__

#include "maxon/iostreams.h"
#include "maxon/url.h"
#include "maxon/datatype.h"

namespace maxon
{

enum class IOFORMAT
{
	DEFAULT						= 0,
	BINARY						= 1,
	BINARY_COMPRESSED = 2,
	JSON							= 3,
	XML								= 4,
	JSON_STABLE				= 5		///< This format is identical to JSON but resolves all references on writing and sorts sets and maps so the order stays stable.
													///< JSON_STABLE does not support writing of WeakRefs to COW objects.
} MAXON_ENUM_LIST(IOFORMAT);

class IoDocument
{
	MAXON_INTERFACE_NONVIRTUAL(IoDocument, MAXON_REFERENCE_NONE, "net.maxon.interface.iodocument");

public:
	static MAXON_METHOD Result<void> ReadDocument(const Url& url, const Id& id, const DataPtr& data, const DataDictionary& dict);
	static MAXON_METHOD Result<void> ReadDocument(UrlOrInputStream&& urlOrStream, const Id& id, const DataPtr&, IOFORMAT format, const DataDictionary& dict);
	static MAXON_METHOD Result<void> WriteDocument(const OutputStreamRef& stream, const Id& id, const ConstDataPtr&, IOFORMAT format, const DataDictionary& dict);
};

#include "io1.hxx"
#include "io2.hxx"

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type ReadDocument(const Url& url, const Id& id, T& object, const DataDictionary& dict = DataDictionary())
{
	auto arr = object.ToArray();
	return IoDocument::ReadDocument(url, id, DataPtr(maxon::GetDataType<ArrayInterface<typename T::ValueType>>(), (Generic*)&arr), dict);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value != COLLECTION_KIND::ARRAY && !std::is_same<T, Data>::value, Result<void>>::type ReadDocument(const Url& url, const Id& id, T& object, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::ReadDocument(url, id, DataPtr(object), dict);
}

template <typename T> inline typename std::enable_if<std::is_same<T, Data>::value, Result<void>>::type ReadDocument(const Url& url, const Id& id, T& object, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::ReadDocument(url, id, DataPtr(GetDataType<Data>(), reinterpret_cast<Generic*>(&object)), dict);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type ReadDocument(UrlOrInputStream&& urlOrStream, const Id& id, T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	auto arr = object.ToArray();
	return IoDocument::ReadDocument(std::move(urlOrStream), id, DataPtr(maxon::GetDataType<ArrayInterface<typename T::ValueType>>(), reinterpret_cast<Generic*>(&arr)), format, dict);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value != COLLECTION_KIND::ARRAY && !std::is_same<T, Data>::value, Result<void>>::type ReadDocument(UrlOrInputStream&& urlOrStream, const Id& id, T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::ReadDocument(std::move(urlOrStream), id, DataPtr(object), format, dict);
}

template <typename T> inline typename std::enable_if<std::is_same<T, Data>::value, Result<void>>::type ReadDocument(UrlOrInputStream&& urlOrStream, const Id& id, T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::ReadDocument(std::move(urlOrStream), id, DataPtr(GetDataType<Data>(), reinterpret_cast<Generic*>(&object)), format, dict);
}

template <typename T> inline Result<void> WriteDocument(const Url& url, const Id& id, const T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	iferr_scope;
	OutputStreamRef stream = url.OpenOutputStream() iferr_return;
	WriteDocument(stream, id, object, format, dict) iferr_return;
	stream.Close() iferr_return;

	return OK;
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type WriteDocument(const OutputStreamRef& stream, const Id& id, const T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	auto arr = object.ToArray();
	return IoDocument::WriteDocument(stream, id, ConstDataPtr(maxon::GetDataType<ArrayInterface<typename T::ValueType>>(), (Generic*)&arr), format, dict);
}

template <typename T> inline typename std::enable_if<std::is_same<T, Data>::value, Result<void>>::type WriteDocument(const OutputStreamRef& stream, const Id& id, const T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::WriteDocument(stream, id, ConstDataPtr(GetDataType<Data>(), reinterpret_cast<const Generic*>(&object)), format, dict);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value != COLLECTION_KIND::ARRAY && !std::is_same<T, Data>::value, Result<void>>::type WriteDocument(const OutputStreamRef& stream, const Id& id, const T& object, IOFORMAT format = IOFORMAT::DEFAULT, const DataDictionary& dict = DataDictionary())
{
	return IoDocument::WriteDocument(stream, id, ConstDataPtr(object), format, dict);
}

} // namespace maxon

#endif // IO_H__
