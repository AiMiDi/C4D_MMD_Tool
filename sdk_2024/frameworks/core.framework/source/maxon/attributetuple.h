#ifndef ATTRIBUTETUPLE_H__
#define ATTRIBUTETUPLE_H__

#include "maxon/datatype.h"


namespace maxon
{

template <Bool OPT, Int CNT> class AttributeTupleBase
{
protected:
	constexpr MAXON_ATTRIBUTE_FORCE_INLINE void SetUsed(Int idx, Bool used)
	{
		_used[idx] = used;
	}
	constexpr MAXON_ATTRIBUTE_FORCE_INLINE Bool IsUsed(Int idx) const
	{
		return _used[idx];
	}
protected:
	Bool _used[CNT] = {};
};

template <Int CNT> class AttributeTupleBase<false, CNT>
{
protected:
	constexpr MAXON_ATTRIBUTE_FORCE_INLINE void SetUsed(Int idx, Bool used)
	{
	}
	constexpr MAXON_ATTRIBUTE_FORCE_INLINE Bool IsUsed(Int idx) const
	{
		return true;
	}
};

template <Bool OPT, typename... ARGS> class AttributeTuple : protected AttributeTupleBase<OPT, sizeof...(ARGS)>
{
public:
	using Super = AttributeTupleBase<OPT, sizeof...(ARGS)>;
	using TYPE = NamedTuple<typename std::remove_const<ARGS>::type...>;

	AttributeTuple() = default;

	template <typename... INITTUPLE> MAXON_ATTRIBUTE_FORCE_INLINE explicit AttributeTuple(INITTUPLE&&... args)
	{
		InitImpl(std::forward<INITTUPLE>(args)...);
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE typename ARG::FidType& operator[](const ARG&)
	{
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		Super::SetUsed(idx, true);
		return TupleGet<idx>(_tuple);
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE const typename ARG::FidType& operator[](const ARG&) const
	{
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		return TupleGet<idx>(_tuple);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ConstDataPtr operator[](const InternedId& id) const
	{
		const Tuple<Int, Int, const DataType*> member = TYPE::FindIndexOffsetAndTypeByHash(id);
		if (member.third)
		{
			return ConstDataPtr(*member.third, reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_tuple) + member.second));
		}
		return ConstDataPtr();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ConstDataPtr operator[](const ConstDataPtr& key) const
	{
		const InternedId* iid = key.GetPtr<InternedId>();
		if (iid)
		{
			const Tuple<Int, Int, const DataType*> member = TYPE::FindIndexOffsetAndTypeByHash(*iid);
			if (member.third)
			{
				return ConstDataPtr(*member.third, reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_tuple) + member.second));
			}
		}
		return DataPtr();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE DataPtr operator[](const ConstDataPtr& key)
	{
		const InternedId* iid = key.GetPtr<InternedId>();
		if (iid)
		{
			const Tuple<Int, Int, const DataType*> member = TYPE::FindIndexOffsetAndTypeByHash(*iid);
			if (member.third)
			{
				Super::SetUsed(member.first, true);
				return DataPtr(*member.third, reinterpret_cast<Generic*>(reinterpret_cast<Char*>(&_tuple) + member.second));
			}
		}
		return DataPtr();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ConstDataPtr operator[](ForwardingDataPtr&& key) const
	{
		const InternedId* iid = key.data.GetPtr<InternedId>();
		if (iid)
		{
			const Tuple<Int, Int, const DataType*> member = TYPE::FindIndexOffsetAndTypeByHash(*iid);
			if (member.third)
			{
				return ConstDataPtr(*member.third, reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_tuple) + member.second));
			}
		}
		return DataPtr();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE DataPtr operator[](ForwardingDataPtr&& key)
	{
		const InternedId* iid = key.data.GetPtr<InternedId>();
		if (iid)
		{
			const Tuple<Int, Int, const DataType*> member = TYPE::FindIndexOffsetAndTypeByHash(*iid);
			if (member.third)
			{
				Super::SetUsed(member.first, true);
				return DataPtr(*member.third, reinterpret_cast<Generic*>(reinterpret_cast<Char*>(&_tuple) + member.second));
			}
		}
		return DataPtr();
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE Result<const typename ARG::FidType&> Get(const ARG&) const
	{
		iferr_scope;
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		if (!Super::IsUsed(idx))
			return IllegalStateError(MAXON_SOURCE_LOCATION);
		return TupleGet<idx>(_tuple);
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE const typename ARG::FidType& Get(const ARG&, const typename ARG::FidType& defaultValue) const
	{
		iferr_scope;
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		if (!Super::IsUsed(idx))
			return defaultValue;
		return TupleGet<idx>(_tuple);
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Set(const ARG&, const typename ARG::FidType& value)
	{
		iferr_scope;
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		TupleGet<idx>(_tuple) = value;
		Super::SetUsed(idx, true);
		return OK;
	}

	template <typename ARG> MAXON_ATTRIBUTE_FORCE_INLINE void Set(const ARG&, typename ARG::FidType&& value)
	{
		iferr_scope;
		constexpr Int idx = TYPE::template IndexOf<ARG>::value;
		static_assert(idx >= 0);
		TupleGet<idx>(_tuple) = std::move(value);
		Super::SetUsed(idx, true);
	}

private:
	template <typename ID, typename VALUE, typename... MOREARGS>
	void InitImpl(const ID& id, VALUE&& value, MOREARGS&&... moreArgs)
	{
		(*this)[id] = std::forward<VALUE>(value);
		InitImpl(std::forward<MOREARGS>(moreArgs)...);
	}

	constexpr void InitImpl()
	{
	}

private:
	typename TYPE::TupleType _tuple;
};


}

#endif // ATTRIBUTETUPLE_H__
