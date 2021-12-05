#ifndef FID_H__
#define FID_H__


#include "maxon/module.h"
#include "maxon/datatype.h"

inline maxon::Id PrivateGetDatabaseScope()
{
	return maxon::Id();
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
template <typename T, typename KEYTYPE> class FId
{
	const KEYTYPE _id;
public:
	using FidType = T;

	explicit FId(const KEYTYPE& iid, ModuleInfo* = nullptr) : _id(iid) { }

	const KEYTYPE& Get() const { return _id; }

	operator const KEYTYPE&() const { return _id; }
};

// specialization for InternedId, this is constructed with a c-string and automatically initializes the InternedId during module initialization
template <typename T> class FId<T, InternedId> : public InternedId
{
	InternedIdInitializer _initializer;
public:
	using FidType = T;

	explicit FId(const Char* str, ModuleInfo* module) : _initializer(this, str, module) { }

	const InternedId& Get() const
	{
		return *this;
	}

	Member GetMember() const
	{
		return Member(GetDataType<T, GET_DATATYPE_POLICY::NO_DECAY | GET_DATATYPE_POLICY::ALLOW_BASEARRAY>(), *this);
	}
};

MAXON_MEMBERTYPE_DETECTOR(IsFidClass, FidType, std::false_type);

// PrivateGetFIdKeyType is used to treat a char literal like "abc" in MAXON_ATTRIBUTE macros as an InternedId
template <typename T> class PrivateGetFIdKeyType
{
public:
	using type = T;
};

template <size_t N> class PrivateGetFIdKeyType<const char(&)[N]>
{
public:
	using type = InternedId;
};

//----------------------------------------------------------------------------------------
/// Defines a resource id with type. E.g. FID(1000, Real) allows to set this type directly into a DataDictionary.
/// The Set()/Get() of the DataDictionary then is type checked.
//----------------------------------------------------------------------------------------
#define FID(IID, TYPE) FId<TYPE, decltype(IID)>(IID)

#define RESOURCE_DEFINE(ID, VAL) ValueType ID = VAL;

#define RESOURCE_DEFAULT(...)		using HasDefault = std::true_type; ValueType DEFAULTVALUE = __VA_ARGS__; ///< defines the default value

#define MAXON_RESOURCE_DATABASE_SCOPE(id) inline constexpr maxon::LiteralId GetId() { return maxon::LiteralId(id); } inline maxon::Id PrivateGetDatabaseScope() { return maxon::Id(id); }

//----------------------------------------------------------------------------------------
/// special datatype for groups.
//----------------------------------------------------------------------------------------
using Group = void;

#define PRIVATE_RESOURCE_ID_CLASS(UID, IID, TYPE, BODY, ...)                                                                             \
	class UID##_PrivateAttribute : public maxon::FId<TYPE, maxon::PrivateGetFIdKeyType<decltype(IID)>::type>                               \
	{                                                                                                                                      \
	public:                                                                                                                                \
		using ValueType = TYPE;                                                                                                              \
		UID##_PrivateAttribute() : maxon::FId<ValueType, maxon::PrivateGetFIdKeyType<decltype(IID)>::type>(IID, &PRIVATE_MAXON_MODULE)       \
		{                                                                                                                                    \
		}                                                                                                                                    \
		maxon::Id GetDatabaseScope() const                                                                                                   \
		{                                                                                                                                    \
			return PrivateGetDatabaseScope();                                                                                                  \
		}                                                                                                                                    \
		static const UID##_PrivateAttribute& GetInstance() BODY																																							 \
		template <typename T, typename SUPER> struct AddMember : public SUPER																																 \
		{																																																																		 \
			T UID;																																																														 \
			static maxon::Int PrivateGetOffset() { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(AddMember, UID); }																 \
		};																																																																	 \
		struct HASHCODE;                                                                                                                     \
		__VA_ARGS__                                                                                                                          \
	};

#define PRIVATE_RESOURCE_ID_DECL(STORAGE, UID)                                                                                           \
	class UID##_PrivateAttribute; STORAGE UID##_PrivateAttribute UID;

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
#define MAXON_ATTRIBUTE(TYPE, NAME, RID, ...) PRIVATE_RESOURCE_ID_DECL(extern, NAME) PRIVATE_RESOURCE_ID_CLASS(NAME, RID, TYPE, { return NAME; }, __VA_ARGS__)

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
#define MAXON_ATTRIBUTE_CLASS(TYPE, NAME, RID, ...) PRIVATE_RESOURCE_ID_DECL(static, NAME) PRIVATE_RESOURCE_ID_CLASS(NAME, RID, TYPE, { return NAME; }, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Declares a resource id with type in the current namespace. Unlike the other MAXON_ATTRIBUTE macros,
/// this macro has to be used in a cpp file. E.g.,
/// @code
/// MAXON_ATTRIBUTE_LOCAL(IoMemoryRef, URL_MEMORY_REF, 'memo');
/// @endcode
/// declares a resource id @c URL_MEMORY_REF in the current namespace which uses 'memo' as its key in dictionaries and has values of type @c IoMemoryRef.
/// You have to make sure that you don't use different resource ids with equal key in the same dictionary.
/// TODO: (Anybody) naming convention.
/// @param[in] TYPE								The type of the values of this resource id.
/// @param[in] NAME								The C++ name of the resource id. A static member variable of that name will be added to the current class.
/// @param[in] RID								The resource id to be used as key in dictionaries. This can be of any type which is supported by DataType.
/// 															A c-string literal will be treated as an InternedId.
/// @param[in] ...								Further information about the resource.
//----------------------------------------------------------------------------------------
#define MAXON_ATTRIBUTE_LOCAL(TYPE, NAME, RID, ...) PRIVATE_RESOURCE_ID_CLASS(NAME, RID, TYPE, ;, __VA_ARGS__) PRIVATE_RESOURCE_ID_DECL(static, NAME) \
	const NAME##_PrivateAttribute& NAME##_PrivateAttribute::GetInstance() { return NAME; }


// used internally for ID_SWITCH macro
class PrivateIdSwitch
{
public:
	MAXON_IMPLICIT PrivateIdSwitch(const InternedId& iid) : _id(&iid), _matched(false) { }

	MAXON_IMPLICIT PrivateIdSwitch(const InternedId* iid) : _id(iid), _matched(false) { }

	MAXON_IMPLICIT PrivateIdSwitch(const ConstDataPtr& key) : _id(key.GetPtr<InternedId>()), _matched(false) { }

	MAXON_IMPLICIT PrivateIdSwitch(const ForwardingDataPtr& key) : _id(key.data.GetPtr<InternedId>()), _matched(false) { }

	operator UInt() const
	{
		return _id ? _id->GetHashCode() : 0;
	}

	template <typename T> Bool Check(const FId<T, InternedId>& key)
	{
		if (_matched)
		{
			return true;
		}
		if (_id && (*_id == key))
		{
			_matched = true;
			return true;
		}
		return false;
	}

private:
	const InternedId* const _id; // the InternedId of the switch expression
	Bool _matched; // will be set to true when a case expression matches the switch expression, this is needed to support fallthroughs
};


//----------------------------------------------------------------------------------------
/// ID_SWITCH and ID_CASE allow to use InternedId values in a switch statement. #ID_SWITCH has to
/// wrap the switch expression, it supports switch expressions of type InternedId, pointer to InternedId
/// or ConstDataPtr. Each case label has to be wrapped by #ID_CASE, this supports ids that are
/// declared by MAXON_ATTRIBUTE, #CLASS_RESOURCE_ID, #RESOURCE_AUTOID or #CLASS_RESOURCE_AUTOID.
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
		maxon::PrivateIdSwitch privateSwitchId = key
#else
	#define ID_SWITCH(key) \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		maxon::PrivateIdSwitch privateSwitchId = key \
		MAXON_WARNING_POP
#endif

#define PRIVATE_ID_CASE(key, line) key##_PrivateAttribute::HASHCODE::value: if (privateSwitchId.Check(key)) goto MAXON_CONCAT(lbl, line); break; MAXON_CONCAT(lbl, line)

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
/// 	template <typename T = void, typename KEY> typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type Get(KEY&& key)
/// 	{
/// 		using TT = typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type;
/// 		_dict.GetData(ConvertKeyToDataPtr<ConstDataPtr, TT>(std::forward<KEY>(key)));
/// 		return TT();
/// 	}
/// };
/// @endcode
//----------------------------------------------------------------------------------------
template <typename RESTRICT, Bool ONLYFID, typename KEY>
inline typename std::enable_if<!IsFidClass<KEY>::value, typename std::conditional<std::is_reference<KEY>::value || std::is_const<KEY>::value, ConstDataPtr, MoveDataPtr>::type>::type ConvertKeyToDataPtr(KEY&& key)
{
	static_assert(!ONLYFID, "Only Fid are allowed here. Please use the correct FId type.");
	// Not a FId argument
	return typename std::conditional<std::is_reference<KEY>::value || std::is_const<KEY>::value, ConstDataPtr, MoveDataPtr>::type(std::forward<KEY>(key));
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
