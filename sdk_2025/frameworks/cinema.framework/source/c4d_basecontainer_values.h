/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASECONTAINER_VALUES_H__
#define C4D_BASECONTAINER_VALUES_H__

#ifdef __API_INTERN__
	#include "basecontainer.h"
#else
	#include "ge_math.h"
	#include "c4d_basecontainer.h"
	#include "c4d_baselist.h"
	#include "c4d_string.h"
	#include "c4d_file.h"
	#include "c4d_gedata.h"
#endif

#include <functional>

namespace cinema
{

template <typename CONTAINERTYPE> struct ExtractData
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		static_assert(maxon::AlwaysFalse<RES>::value);
	}
};

template <> struct ExtractData<GeData>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, GeData& res)
	{
		data->CopyData(&res, nullptr);
	}
};

template <> struct ExtractData<Bool>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetBool();
	}
};

template <> struct ExtractData<Int32>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetInt32();
	}
};

template <> struct ExtractData<Int64>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetInt64();
	}
};

template <> struct ExtractData<Float>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetFloat();
	}
};

template <> struct ExtractData<Vector>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetVector();
	}
};

template <> struct ExtractData<Matrix>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetMatrix();
	}
};

template <> struct ExtractData<maxon::String>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetString();
	}
};

template <> struct ExtractData<String>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetString();
	}
};

template <> struct ExtractData<Filename>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = (RES)data->GetFilename();
	}
};

template <> struct ExtractData<CustomDataType>
{
	template <typename RES> static MAXON_ATTRIBUTE_FORCE_INLINE void Get(const GeData* data, RES& res)
	{
		res = data->GetCustomDataType<typename std::remove_const<typename std::remove_pointer<RES>::type>::type>();
	}
};

template <> struct ExtractData<const BaseLink*>
{
	template <typename RES> static inline void Get(const GeData* data, RES& res)
	{
#ifdef __API_INTERN__
		res = data->GetAliasLink();
#else
		res = data->GetBaseLink();
#endif
	}
};



/// Helper struct for indirect data storage with BaseContainer::GetValues()
template <Int32 VALUE, typename TYPE> struct [[nodiscard]] VI
{
	static const Int32 ids = VALUE;

private:
	maxon::Opt<typename maxon::ByValueParam<TYPE>::type> _val;
	const GeData* _data = nullptr;

public:
	MAXON_ATTRIBUTE_FORCE_INLINE void CheckValue()
	{
		if (_data)
		{
			ExtractData<TYPE>::Get(_data, _val);
			_data = nullptr;
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool SetData(const GeData* d)
	{
		_data = d;
		return false;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool HasValue()
	{
		CheckValue();
		return _val.HasValue();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE const TYPE& GetOrDefault()
	{
		CheckValue();
		return _val.GetOrDefault();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE TYPE GetValueOr(TYPE&& defaultValue)
	{
		CheckValue();
		return _val.GetValueOr(std::move(defaultValue));
	}

	MAXON_ATTRIBUTE_FORCE_INLINE const TYPE& GetValueOr(const TYPE& defaultValue)
	{
		CheckValue();
		return _val.GetValueOr(defaultValue);
	}
};

/// Helper struct for direct data storage with BaseContainer::GetValues()
template <Int32 VALUE, typename CONTAINERTYPE, Bool SETTODEFAULTIFNOTFOUND = true, typename RESTYPE = CONTAINERTYPE> struct [[nodiscard]] VD
{
	static const Int32 ids = VALUE;

private:
	RESTYPE& _val;

public:
	MAXON_ATTRIBUTE_FORCE_INLINE explicit constexpr VD(RESTYPE& res)
		: _val(res)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool SetData(const GeData* d)
	{
		if (d)
		{
			ExtractData<CONTAINERTYPE>::template Get<RESTYPE>(d, _val);
		}
		else if constexpr (SETTODEFAULTIFNOTFOUND)
		{
			_val = RESTYPE{};
		}
		return false;
	}
};

// Class to manage active state and data handling for templates
template <Int32 VALUE, typename CONTAINERTYPE, Bool SETTODEFAULTIFNOTFOUND, typename RESTYPE, typename FUNC>
struct [[nodiscard]] VDAPrivate
{
	static const Int32 ids = VALUE;

private:
	RESTYPE& _val;
	FUNC _isActiveFunc; // Callable object (can hold lambdas, function pointers, etc.)

public:
	// Constructor when a callable is provided (e.g., lambda, functor, etc.)
	MAXON_ATTRIBUTE_FORCE_INLINE explicit constexpr VDAPrivate(RESTYPE& res, FUNC&& isActiveFunc)
		: _val(res),
			_isActiveFunc(std::move(isActiveFunc)) // Forward the callable
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool SetData(const GeData* d)
	{
		// Check whether _isActiveFunc returns true
		if (_isActiveFunc())
		{
			if (d)
			{
				ExtractData<CONTAINERTYPE>::template Get<RESTYPE>(d, _val);
			}
			else if constexpr (SETTODEFAULTIFNOTFOUND)
			{
				_val = RESTYPE{}; // Reset value to a default
			}
		}
		return false;
	}
};

template <Int32 VALUE, typename CONTAINERTYPE, Bool SETTODEFAULTIFNOTFOUND = true, typename RESTYPE = CONTAINERTYPE, typename FUNC>
VDAPrivate<VALUE, CONTAINERTYPE, SETTODEFAULTIFNOTFOUND, RESTYPE, FUNC> VDA(RESTYPE& res, FUNC&& isActiveFunc)
{
	return VDAPrivate<VALUE, CONTAINERTYPE, SETTODEFAULTIFNOTFOUND, RESTYPE, FUNC>(res, std::move(isActiveFunc));
}

/// Helper struct for direct link storage with BaseContainer::GetValues()
template <Int32 VALUE, typename TYPE, Bool SETTODEFAULTIFNOTFOUND = true> struct [[nodiscard]] VLINK
{
	static const Int32 ids = VALUE;

private:
	TYPE& _val;
	const BaseDocument* _doc;
	Int32 _type;
	Bool _isActive;

public:
	explicit constexpr VLINK(TYPE& res, const BaseDocument* doc, Int32 type, Bool isActive = true)
		: _val(res),
			_doc(doc),
			_type(type),
			_isActive(isActive)
	{
	}

	Bool SetData(const GeData* d)
	{
		if (d && _isActive)
		{
			const BaseLink* link;
			ExtractData<const BaseLink*>::Get(d, link);
			if (link)
				_val = (TYPE)link->GetLink(_doc, _type);
			else
				_val = {};
		}
		else if constexpr (SETTODEFAULTIFNOTFOUND)
		{
			if (!_isActive)
				_val = {};
		}
		return false;
	}
};


} // namespace cinema

#endif // C4D_BASECONTAINER_VALUES_H__
