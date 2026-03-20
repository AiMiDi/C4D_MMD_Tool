#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"

namespace io_util
{
/**
 * @brief Generic ReadData function template.
 *        Tries to call the member Read(HyperFile*) for custom types.
 * @tparam T Data type to read.
 * @param hf Pointer to HyperFile.
 * @param data Reference to data to be filled.
 * @return true if read succeeds, false otherwise.
 */
template<typename T>
bool ReadData(HyperFile* hf, T& data)
{
	return data.Read(hf);
}

/**
 * @brief Generic WriteData function template.
 *        Tries to call the member Write(HyperFile*) for custom types.
 * @tparam T Data type to write.
 * @param hf Pointer to HyperFile.
 * @param data Const reference to data to be written.
 * @return true if write succeeds, false otherwise.
 */
template<typename T>
bool WriteData(HyperFile* hf, const T& data)
{
#if API_VERSION < 2024000
	return const_cast<T&>(data).Write(hf);
#else
	return data.Write(hf);
#endif
}

/**
 * @brief Utility IO function for reading linear containers (BaseArray, PointerArray, BaseList, etc.).
 *        Reads the count, resizes the container, and reads each element using ReadData.
 * @tparam Container Container type (must support Resize(count) and operator[] access).
 * @param hf Pointer to HyperFile.
 * @param container Reference to the container to be filled.
 * @return true if all elements are read successfully, false otherwise.
 */
template<typename Container>
bool ReadLinearContainer(HyperFile* hf, Container& container)
{
	iferr_scope_handler{
		return false;
	};
	Int64 count = 0;
	if (!hf->ReadInt64(&count))
		return false;
	container.Resize(count)iferr_return;
	for (Int64 index = 0; index < count; index++)
	{
		if (!ReadData(hf, container[index]))
			return false;
	}
	return true;
}

/**
 * @brief Utility IO function for writing linear containers (BaseArray, PointerArray, BaseList, etc.).
 *        Writes the count and each element using WriteData.
 * @tparam Container Container type (must support GetCount() and range-based for).
 * @param hf Pointer to HyperFile.
 * @param container Const reference to the container to be written.
 * @return true if all elements are written successfully, false otherwise.
 */
template<typename Container>
bool WriteLinearContainer(HyperFile* hf, const Container& container)
{
	iferr_scope_handler{
		return false;
	};
	if (!hf->WriteInt64(container.GetCount()))
		return false;
	for (const auto& data : container)
	{
		if (!WriteData(hf, data))
			return false;
	}
	return true;
}

/**
 * @brief Utility IO function for reading hash maps (such as maxon::HashMap).
 *        Reads the count, then reads each key and value pair using ReadData.
 *        The key is inserted into the map, and the value is read into the corresponding entry.
 * @tparam K Key type.
 * @tparam V Value type.
 * @param hf Pointer to HyperFile.
 * @param container Reference to the HashMap to be filled.
 * @return true if all key-value pairs are read successfully, false otherwise.
 */
template<typename K, typename V>
bool ReadHashMap(HyperFile* hf, maxon::HashMap<K, V>& container)
{
	iferr_scope_handler{
		return false;
	};
	Int64 count = 0;
	if (!hf->ReadInt64(&count))
		return false;
	container.SetCapacityHint(count)iferr_return;
	for (Int64 index = 0; index < count; index++)
	{
		K key;
		if (!ReadData(hf, key))
			return false;
		V& value = container.InsertKey(std::move(key))iferr_return;
		if (!ReadData(hf, value))
			return false;
	}
	return true;
}

/**
 * @brief Utility IO function for writing hash maps (such as maxon::HashMap).
 *        Writes the count, then writes each key and value pair using WriteData.
 * @tparam K Key type.
 * @tparam V Value type.
 * @param hf Pointer to HyperFile.
 * @param container Const reference to the HashMap to be written.
 * @return true if all key-value pairs are written successfully, false otherwise.
 */
template<typename K, typename V>
bool WriteHashMap(HyperFile* hf, const maxon::HashMap<K, V>& container)
{
	iferr_scope_handler{
		return false;
	};
	if (!hf->WriteInt64(container.GetCount()))
		return false;
	for (const auto& entry : container)
	{
		if (!WriteData(hf, entry.GetKey()))
			return false;
		if (!WriteData(hf, entry.GetValue()))
			return false;
	}
	return true;
}

/**
 * @brief Writes a pointer to a BaseList2D-derived object to HyperFile.
 *        This function is only enabled if T is derived from BaseList2D.
 * @tparam T Must be derived from BaseList2D.
 * @param hf Pointer to HyperFile.
 * @param data Pointer to T to be written.
 * @return true if write succeeds, false otherwise.
 */
	template<typename T>
	bool WriteBaseList2D(HyperFile* hf, const T* data)
{
	static_assert(std::is_base_of_v<BaseList2D, T>, "T must be derived from BaseList2D");
	AutoAlloc<BaseLink> link;
	if (!link)
		return false;
	if (data)
		link->SetLink(const_cast<T*>(data));
	return link->Write(hf);
}

/**
 * @brief Reads a pointer to a BaseList2D-derived object from HyperFile.
 *        This function is only enabled if T is derived from BaseList2D.
 * @tparam T Must be derived from BaseList2D.
 * @param hf Pointer to HyperFile.
 * @param data Reference to pointer to T, will be set to the read object.
 * @return true if read succeeds, false otherwise.
 */
	template<typename T>
	bool ReadBaseList2D(HyperFile* hf, T*& data)
{
	static_assert(std::is_base_of_v<BaseList2D, T>, "T must be derived from BaseList2D");
	AutoAlloc<BaseLink> link;
	if (!link)
		return false;
	if (!link->Read(hf))
		return false;
	data = reinterpret_cast<T*>(link->ForceGetLink());
	return true;
}

/**
 * @brief Macro to specialize ReadData for types directly supported by HyperFile.
 *        Expands to a template specialization using the corresponding HyperFile::ReadXXX method.
 * @param x Type name (e.g., Int32, Float64, Vector32, etc.)
 */
#define READ_DATA_FUNC(x) template<> inline bool ReadData<x>(HyperFile* hf, x& data) { return hf->Read##x(&data); }

/**
 * @brief Macro to specialize WriteData for types directly supported by HyperFile.
 *        Expands to a template specialization using the corresponding HyperFile::WriteXXX method.
 * @param x Type name (e.g., Int32, Float64, Vector32, etc.)
 */
#define WRITE_DATA_FUNC(x) template<> inline bool WriteData<x>(HyperFile* hf, const x& data) { return hf->Write##x(data); }

// Specializations for all types directly supported by HyperFile.
READ_DATA_FUNC(Int32)
READ_DATA_FUNC(Int64)
READ_DATA_FUNC(Float32)
READ_DATA_FUNC(Float64)
READ_DATA_FUNC(Bool)
READ_DATA_FUNC(UChar)
READ_DATA_FUNC(Char)
READ_DATA_FUNC(UInt16)
READ_DATA_FUNC(Int16)
READ_DATA_FUNC(UInt32)
READ_DATA_FUNC(UInt64)
READ_DATA_FUNC(Vector32)
READ_DATA_FUNC(Vector64)
READ_DATA_FUNC(Matrix32)
READ_DATA_FUNC(Matrix64)
READ_DATA_FUNC(String)
READ_DATA_FUNC(Filename)
READ_DATA_FUNC(GeData)
template<> inline bool ReadData<BaseContainer>(HyperFile* hf, BaseContainer& data) { return hf->ReadContainer(&data, true); }
template<> inline bool ReadData<BaseTime>(HyperFile* hf, BaseTime& data) { return hf->ReadTime(&data); }
template<> inline bool ReadData<BaseTag*>(HyperFile* hf, BaseTag*& data){ return ReadBaseList2D(hf, data); }
template<> inline bool ReadData<BaseObject*>(HyperFile* hf, BaseObject*& data){ return ReadBaseList2D(hf, data); }
template<> inline bool ReadData<AutoAlloc<BaseLink>>(HyperFile* hf, AutoAlloc<BaseLink>& data)
{
	if (!data) return false;
	return data->Read(hf);
}
template<> inline bool ReadData<maxon::StrongRef<AutoAlloc<BaseLink>>>(HyperFile* hf, maxon::StrongRef<AutoAlloc<BaseLink>>& data)
{
	iferr_scope_handler{
		return false;
	};
	if (!data)
	{
		data = maxon::StrongRef<AutoAlloc<BaseLink>>::Create()iferr_return;
		if (!data)
			return false;
	}

	if (!(*data))
		return false;

	if (!(*data)->Read(hf))
		return false;
	return true;
}

WRITE_DATA_FUNC(Int32)
WRITE_DATA_FUNC(Int64)
WRITE_DATA_FUNC(Float32)
WRITE_DATA_FUNC(Float64)
WRITE_DATA_FUNC(Bool)
WRITE_DATA_FUNC(UChar)
WRITE_DATA_FUNC(Char)
WRITE_DATA_FUNC(UInt16)
WRITE_DATA_FUNC(Int16)
WRITE_DATA_FUNC(UInt32)
WRITE_DATA_FUNC(UInt64)
WRITE_DATA_FUNC(Vector32)
WRITE_DATA_FUNC(Vector64)
WRITE_DATA_FUNC(Matrix32)
WRITE_DATA_FUNC(Matrix64)
WRITE_DATA_FUNC(String)
WRITE_DATA_FUNC(Filename)
WRITE_DATA_FUNC(GeData)
template<> inline bool WriteData<BaseContainer>(HyperFile* hf, const BaseContainer& data) { return hf->WriteContainer(data); }
template<> inline bool WriteData<BaseTime>(HyperFile* hf, const BaseTime& data) { return hf->WriteTime(data); }
#if API_VERSION < 2024000
template<> inline bool WriteData<DescID>(HyperFile* hf, const DescID& data) { return const_cast<DescID&>(data).Write(hf); }
#endif
template<> inline bool WriteData<BaseTag*>(HyperFile* hf, BaseTag* const& data){ return WriteBaseList2D(hf, data); }
template<> inline bool WriteData<BaseObject*>(HyperFile* hf, BaseObject* const& data){ return WriteBaseList2D(hf, data); }
template<> inline bool WriteData<AutoAlloc<BaseLink>>(HyperFile* hf, const AutoAlloc<BaseLink>& data)
{
	if (!data) return false;
	return data->Write(hf);
}
template<> inline bool WriteData<maxon::StrongRef<AutoAlloc<BaseLink>>>(HyperFile* hf, const maxon::StrongRef<AutoAlloc<BaseLink>>& data)
{
	if (!data || !(*data))
		return false;

	if (!(*data)->Write(hf))
		return false;
	return true;
}

inline BaseObject* ResolveObjectLink(const AutoAlloc<BaseLink>& link)
{
	return link ? static_cast<BaseObject*>(link->ForceGetLink()) : nullptr;
}

}

#define IOReadField(x) if (!io_util::ReadData(hf, x)) return false
#define IOWriteField(x) if (!io_util::WriteData(hf, x)) return false
