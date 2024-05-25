#ifndef FID_H__
#define FID_H__


#include "maxon/module.h"
#include "maxon/datatype.h"

constexpr inline maxon::LiteralId PrivateGetDatabaseScope()
{
	return maxon::LiteralId();
}

namespace maxon
{

//----------------------------------------------------------------------------------------
/// FId class for ids with datatype type. this makes Set/Get functions type safe.
/// use FID and DEFINE_ID macros to use in the code. e.g. FID(1000,Float64) or MAXON_ATTRIBUTE(Float64, MYID_RADIUS, 1000)
/// you can use:
/// @code
/// template <typename KEY, typename DATA> MAXON_FUNCTION typename std::enable_if<!IsFidClass<KEY>::value, Result<void>>::type Set(KEY&& key, DATA&& data)
/// template <typename T> MAXON_FUNCTION Result<void> Set(FId<T> key, T&& data)
/// template <typename T> MAXON_FUNCTION Result<void> Set(FId<T> key, const T& data)
/// @endcode
/// to define template functions that are allow specialization of Fid<T>
/// @tparam T											Data type for this id.
//----------------------------------------------------------------------------------------
template <typename T, typename KEYTYPE, typename HELPER = void> class FId
{
	const KEYTYPE _id;
public:
	using FidType = T;

	explicit constexpr FId(const KEYTYPE& iid) : _id(iid) { }

	const KEYTYPE& Get() const { return _id; }

	operator const KEYTYPE&() const { return _id; }

	// This is a dummy.
	static constexpr LiteralId PrivateGetLiteralId(const KEYTYPE&)
	{
		return LiteralId();
	}

	// This is a dummy.
	Bool operator ==(const InternedId& other) const
	{
		return other.operator ==(PrivateGetLiteralId(_id));
	}

	// This is a dummy.
	Bool operator !=(const InternedId& other) const
	{
		return other.operator !=(PrivateGetLiteralId(_id));
	}
};


struct FidBase { };

class AttributeInternedId
{
public:
	MAXON_ATTRIBUTE_NO_INLINE explicit AttributeInternedId(const char* sym) : _initializer(reinterpret_cast<InternedId*>(&_id), sym)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE const InternedId& Get() const
	{
		return reinterpret_cast<const InternedId&>(_id);
	}

private:
	const Id* _id = nullptr;
	InternedIdInitializer _initializer;
};

template <typename HELPER> const AttributeInternedId g_attributeInternedId(HELPER::GetId().GetCString());


// specialization for InternedId, this is constructed with a c-string and automatically initializes the InternedId during module initialization
template <typename T, typename HELPER> class FId<T, InternedId, HELPER> : public FidBase
{
public:
	using FidType = T;

	explicit constexpr FId(const Char*)
	{
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE const InternedId& Get()
	{
		return g_attributeInternedId<HELPER>.Get();
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE const Id& GetId()
	{
		return Get();
	}

	static const DataType& GetType()
	{
		return GetDataType<T>();
	}

	static Member GetMember()
	{
		return Member(GetDataType<T>(), Get());
	}

	operator const InternedId&() const
	{
		return Get();
	}

	// Explicit to avoid ambiguous conversions when methods accept InternedId or Id.
	explicit operator const Id&() const
	{
		return Get();
	}

	operator Member() const
	{
		return GetMember();
	}

	template <size_t N> static constexpr LiteralId PrivateGetLiteralId(const char(&str)[N])
	{
		return LiteralId(str);
	}
	
	static HashInt GetHashCode()
	{
		return Get().GetHashCode();
	}

	/// @copydoc DefaultDoc::GetUniqueHashCode
	static const UniqueHash& GetUniqueHashCode()
	{
		return Get().GetUniqueHashCode();
	}
	
	static const Char* GetCString()
	{
		return Get().GetCString();
	}

	static Int GetCStringLength()
	{
		return Get().GetCStringLength();
	}

	static String ToString(const FormatStatement* formatStatement = nullptr)
	{
		return Get().ToString(formatStatement);
	}
	
	Bool operator ==(const InternedId& other) const
	{
		return Get().GetPointer() == other.GetPointer();
	}

	Bool operator !=(const InternedId& other) const
	{
		return Get().GetPointer() != other.GetPointer();
	}

	Bool operator <(const InternedId& other) const
	{
		if (other.GetPointer() == nullptr)
			return false;
		const InternedId& iid = Get();
		if (iid.GetPointer() == nullptr)
			return true;

		// Compare the Id, not the pointer. This is important for stable file output in text files.
		return *iid.GetPointer() < *other.GetPointer();
	}
};

MAXON_MEMBERTYPE_DETECTOR(IsFidClass, FidType, std::false_type);

// PrivateFIdBase is used to treat a char literal like "abc" in MAXON_ATTRIBUTE macros as an InternedId
template <typename T, typename KEY, typename HELPER> class PrivateFIdBase
{
public:
	using type = FId<T, KEY>;
};

template <typename T, size_t N, typename HELPER> class PrivateFIdBase<T, const char(&)[N], HELPER>
{
public:
	using type = FId<T, InternedId, HELPER>;
};

//----------------------------------------------------------------------------------------
/// Defines a resource id with type. E.g. FID(1000, Real) allows to set this type directly into a DataDictionary.
/// The Set()/Get() of the DataDictionary then is type checked.
//----------------------------------------------------------------------------------------
#define FID(IID, TYPE) FId<TYPE, decltype(IID)>(IID)

#define RESOURCE_DEFINE(ID, VAL) static constexpr auto ID = VAL;

#define RESOURCE_DEFAULT(...)		using HasDefault = std::true_type; static ValueType DEFAULTVALUE() { return __VA_ARGS__; } ///< defines the default value

#define MAXON_RESOURCE_DATABASE_SCOPE(id) constexpr inline maxon::LiteralId GetId() { return maxon::LiteralId(id); } constexpr inline maxon::LiteralId PrivateGetDatabaseScope() { return maxon::LiteralId(id); }

//----------------------------------------------------------------------------------------
/// special datatype for groups.
//----------------------------------------------------------------------------------------
using Group = void;

#define PRIVATE_RESOURCE_ID_CLASS(UID, IID, TYPE, STORAGE, ...)                                                                             \
	class UID##_PrivateHelper : public maxon::PrivateFIdBase<TYPE, decltype(IID), UID##_PrivateHelper>::type                               \
	{                                                                                                                                      \
	public:                                                                                                                                \
		using ValueType = TYPE;                                                                                                              \
		constexpr UID##_PrivateHelper() : maxon::PrivateFIdBase<TYPE, decltype(IID), UID##_PrivateHelper>::type(IID)       \
		{                                                                                                                                    \
		}                                                                                                                                    \
		static constexpr maxon::LiteralId GetDatabaseScope()                                                                                                   \
		{                                                                                                                                    \
			return PrivateGetDatabaseScope();                                                                                                  \
		}                                                                                                                                    \
		template <typename T, typename SUPER> struct AddMember : public SUPER																																 \
		{																																																																		 \
			typename T::template Member<AddMember> UID;																																												 \
			static constexpr maxon::Int PrivateGetOffset() { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(AddMember, UID); }																 \
		};																																																																	 \
		static constexpr maxon::LiteralId GetId() { return UID##_PrivateHelper::PrivateGetLiteralId(IID); }                              \
		__VA_ARGS__                                                                                                                          \
	}; STORAGE UID##_PrivateHelper UID = UID##_PrivateHelper()

//----------------------------------------------------------------------------------------
/// Declares a resource id with type in the current namespace. E.g.,
/// @code
/// MAXON_ATTRIBUTE(Vector32, COLOR, 1000);
/// @endcode
/// declares a resource id @c COLOR in the current namespace which uses 1000 as its key in dictionaries and has values of type @c Vector32.
/// You have to make sure that you don't use different resource ids with equal key in the same dictionary.
/// TODO: (Anybody) naming convention.
/// @param[in] TYPE								The type of the values of this resource id.
/// @param[in] NAME								The C++ name of the resource id. A global variable of that name will be added to the current namespace.
/// @param[in] RID								The resource id to be used as key in dictionaries. This can be of any type which is supported by DataType.
/// 															A c-string literal will be treated as an InternedId.
/// @param[in] ...								Further information about the resource.
/// @note The macro itself leaves incomplete code which is completed by the source processor.
/// So you have to place the macro in a header file, because the source processor only scans
/// header files, and you have to include the generated hxx files in the header file.
//----------------------------------------------------------------------------------------
#define MAXON_ATTRIBUTE(TYPE, NAME, RID, ...) PRIVATE_RESOURCE_ID_CLASS(NAME, RID, TYPE, constexpr, __VA_ARGS__)

#define decltype_nonconst(...) typename std::remove_const<decltype(__VA_ARGS__)>::type

//----------------------------------------------------------------------------------------
/// Declares a resource id with type as a class member in the current class. E.g.,
/// @code
/// MAXON_ATTRIBUTE_CLASS(Bool, WideningConversion, "widening");
/// @endcode
/// declares a resource id @c WideningConversion in the current class which uses "widening" as its key in dictionaries and has values of type @c Bool.
/// You have to make sure that you don't use different resource ids with equal key in the same dictionary.
/// TODO: (Anybody) naming convention.
/// @param[in] TYPE								The type of the values of this resource id.
/// @param[in] NAME								The C++ name of the resource id. A static member variable of that name will be added to the current class.
/// @param[in] RID								The resource id to be used as key in dictionaries. This can be of any type which is supported by DataType.
/// 															A c-string literal will be treated as an InternedId.
/// @param[in] ...								Further information about the resource.
/// @note The macro itself leaves incomplete code which is completed by the source processor.
/// So you have to place the macro in a header file, because the source processor only scans
/// header files, and you have to include the generated hxx files in the header file.
//----------------------------------------------------------------------------------------
#define MAXON_ATTRIBUTE_CLASS(TYPE, NAME, RID, ...) PRIVATE_RESOURCE_ID_CLASS(NAME, RID, TYPE, static inline const, __VA_ARGS__)


namespace details
{

// used internally for ID_SWITCH macro

class InternedIdSwitch
{
public:
	explicit InternedIdSwitch(const InternedId& iid) : _id(iid.GetPointer()) { }
	explicit InternedIdSwitch(const InternedId* iid) : _id(iid ? iid->GetPointer() : nullptr) { }

	Bool IsInterned() const
	{
		return true;
	}

	const Id* GetId() const
	{
		return _id;
	}

private:
	const Id* const _id; // the InternedId of the switch expression
};

class IdSwitch
{
public:
	explicit IdSwitch(const Id& id) : _id(id) { }

	Bool IsInterned() const
	{
		return false;
	}

	const Id* GetId() const
	{
		return &_id;
	}

private:
	Id _id; // the Id of the switch expression
};

class DataIdSwitch
{
public:
	explicit DataIdSwitch(const ConstDataPtr& key)
	{
		const InternedId* iid = key.GetPtr<InternedId>();
		if (iid)
		{
			_id = iid->GetPointer();
			_interned = true;
		}
		else
		{
			_id = key.GetPtr<Id>();
			_interned = false;
		}
	}
	
	Bool IsInterned() const
	{
		return _interned;
	}

	const Id* GetId() const
	{
		return _id;
	}

private:
	const Id* _id; // the Id of the switch expression
	Bool _interned; // true if _id is an InternedId
};

template <typename BASE> class IdSwitchCheck : public BASE
{
public:
	MAXON_IMPLICIT IdSwitchCheck(BASE&& base) : BASE(std::move(base)) { }

	operator UInt() const
	{
		return this->GetId() ? this->GetId()->GetHashCode() : 0;
	}

	Bool Check(const InternedId& key)
	{
		if (_matched)
		{
			return true;
		}
		if (this->IsInterned() ? this->GetId() == key.GetPointer() : this->GetId() && *this->GetId() == key)
		{
			_matched = true;
			return true;
		}
		return false;
	}

	template <typename T, typename H> Bool Check(const FId<T, InternedId, H>& key)
	{
		return Check(key.Get());
	}

	template <typename T, typename C> Bool Check(const DeclarationWrapper<T, C>& key)
	{
		if (_matched)
		{
			return true;
		}
		if (this->GetId() && *this->GetId() == C::DeclarationHelper::GetId())
		{
			_matched = true;
			return true;
		}
		return false;
	}

private:
	Bool _matched = false; // will be set to true when a case expression matches the switch expression, this is needed to support fallthroughs
};

inline IdSwitchCheck<InternedIdSwitch> GetIdSwitch(const InternedId& iid, OverloadRank2) { return InternedIdSwitch(iid); }
inline IdSwitchCheck<InternedIdSwitch> GetIdSwitch(const InternedId* iid, OverloadRank2) { return InternedIdSwitch(iid); }

inline IdSwitchCheck<IdSwitch> GetIdSwitch(const Id& id, OverloadRank1) { return IdSwitch(id); }

inline IdSwitchCheck<DataIdSwitch> GetIdSwitch(const ConstDataPtr& data, OverloadRank0) { return DataIdSwitch(data); }
inline IdSwitchCheck<DataIdSwitch> GetIdSwitch(const ForwardingDataPtr& data, OverloadRank0) { return DataIdSwitch(data.data); }

}

//----------------------------------------------------------------------------------------
/// ID_SWITCH and ID_CASE allow to use Id or InternedId values in a switch statement. #ID_SWITCH has to
/// wrap the switch expression, it supports switch expressions of type Id, InternedId, pointer to InternedId
/// or ConstDataPtr/ForwardingDataPtr. Each case label has to be wrapped by #ID_CASE, this supports ids that are
/// declared by MAXON_INTERNED_ID, MAXON_DECLARATION or MAXON_ATTRIBUTE.
/// Example:
/// @code
/// switch (ID_SWITCH(key))
/// {
/// 	case ID_CASE(STREAMFLAGS::HTTP_REMOTEADDRESS):
/// 		return Data(_httpFile.GetRemoteAddr());
/// 		break;
/// 	case ID_CASE(STREAMFLAGS::HTTP_HEADER):
/// 		return Data(_httpFile.GetHeader());
/// 		break;
/// }
/// @endcode
/// @param[in] key								The key to be used for the switch expression.
/// @note These macros also support fallthroughs and multiple values for a single case block.
/// Nesting of switch statements will most likely cause a warning about a shadowed local variable
/// because each ID_SWITCH macro declares a local variable of name @c privateSwitchId in the scope of the switch statement.
/// @note You will get a compile-time error in the rare case that two ids have the same hashcode. In this case
/// you can't use a switch statement, you have to use if statements instead.
//----------------------------------------------------------------------------------------
#ifdef MAXON_COMPILER_GCC
	// GCC does not support pragma here.
	#define ID_SWITCH(key) \
		auto privateSwitchId = maxon::details::GetIdSwitch(key, OVERLOAD_MAX_RANK)
#else
	#define ID_SWITCH(key) \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		auto privateSwitchId = maxon::details::GetIdSwitch(key, OVERLOAD_MAX_RANK) \
		MAXON_WARNING_POP
#endif

#define PRIVATE_ID_CASE(key, line) key##_PrivateHelper::GetId().GetHashCode(): if (privateSwitchId.Check(key)) goto MAXON_CONCAT(lbl, line); break; MAXON_CONCAT(lbl, line)

//----------------------------------------------------------------------------------------
/// ID_SWITCH and ID_CASE allow to use InternedId values in a switch statement, see #ID_SWITCH.
/// @param[in] key								The key to be used for the case.
//----------------------------------------------------------------------------------------
#define ID_CASE(key) MAXON_EXPAND(PRIVATE_ID_CASE(key, __LINE__))


//----------------------------------------------------------------------------------------
/// The ConvertKeyToDataPtr helper functions are used for functions which need to separate an template argument T&& between d FId<T, KEYTYPE> and a real datatype.
/// e.g. DataDictionary::Get accepts 2 versions, one thing is the key itself, the other is FId with the keytype and the datatype.
/// the implementation is now easy.
/// @code
/// class X
/// {
/// 	DataDictionary _dict;
/// public:
/// 	template <typename T, typename KEY> void Set(KEY&& key, T&& data)
/// 	{
/// 		_dict.SetData(ConvertKeyToDataPtr<DataPtr, typename std::decay<T>::type>(std::forward<KEY>(key)), Data(std::forward<T>(data)));
/// 	}
/// 	template <typename T = void, typename KEY> typename std::conditional<STD_IS_REPLACEMENT(void, T), typename IsFidClass<KEY>::type, T>::type Get(KEY&& key)
/// 	{
/// 		using TT = typename std::conditional<STD_IS_REPLACEMENT(void, T), typename IsFidClass<KEY>::type, T>::type;
/// 		_dict.GetData(ConvertKeyToDataPtr<ConstDataPtr, TT>(std::forward<KEY>(key)));
/// 		return TT();
/// 	}
/// };
/// @endcode
//----------------------------------------------------------------------------------------
template <typename RESTRICT, Bool ONLYFID, typename KEY>
inline typename std::enable_if<!IsFidClass<KEY>::value, typename std::conditional<STD_IS_REPLACEMENT(reference, KEY) || STD_IS_REPLACEMENT(const, KEY), ConstDataPtr, MoveDataPtr>::type>::type ConvertKeyToDataPtr(KEY&& key)
{
	static_assert(!ONLYFID, "Only Fid are allowed here. Please use the correct FId type.");
	// Not a FId argument
	return typename std::conditional<STD_IS_REPLACEMENT(reference, KEY) || STD_IS_REPLACEMENT(const, KEY), ConstDataPtr, MoveDataPtr>::type(std::forward<KEY>(key));
}

template <typename RESTRICT, Bool ONLYFID, typename KEY>
inline typename std::enable_if<IsFidClass<KEY>::value, ConstDataPtr>::type ConvertKeyToDataPtr(KEY&& key)
{
	static_assert(RESTRICT::template Check<decltype(TestRestriction(key, OVERLOAD_MAX_RANK))>::value, "Fid is restricted to a namespace. Please use FId from the restricted namespace only.");
	// This is a FId argument
	return ConstDataPtr(key.Get());
}


class RESTRICT { };
template <typename T> RESTRICT TestRestriction(T y, OverloadRank0);

MAXON_MEMBERTYPE_DETECTOR(GetRestrict, RESTRICT_DICTIONARY_PROPS, maxon::RESTRICT);

}


#endif // FID_H__
