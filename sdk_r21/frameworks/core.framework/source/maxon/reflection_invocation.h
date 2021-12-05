#ifndef REFLECTION_INVOCATION_H__
#define REFLECTION_INVOCATION_H__

#include "maxon/datatypebase.h"
#include "maxon/basearray.h"
#include "maxon/abitype.h"

namespace maxon
{

namespace reflection
{

class ParameterType;

class Argument
{
public:
	Argument() : _pointerValue(nullptr)
	{
	}

	Result<void> MoveFrom(const ParameterType& type, Data& data, BaseArray<Data>& storage);

	Result<Data> ToData(const ParameterType& type) const;

	static Result<Argument> FromData(const ParameterType& type, Data& data, BaseArray<Data>& storage);


	template <typename T> static Argument ByReference(T&& value)
	{
		return Argument((Generic*)&value);
	}

	template <typename T, typename = typename std::enable_if<!std::is_scalar<T>::value>::type> static Argument ByValue(T& value)
	{
		return Argument((Generic*) &value);
	}

	template <typename T, typename = typename std::enable_if<std::is_scalar<T>::value>::type> static Argument ByValue(T value)
	{
		return Argument((typename ABIParamType<T>::type) value);
	}


	template <typename T, typename = typename std::enable_if<!std::is_scalar<T>::value>::type> static Argument For(typename std::remove_reference<T>::type& value)
	{
		return Argument((Generic*)&value);
	}

	template <typename T, typename = typename std::enable_if<std::is_scalar<T>::value>::type> static Argument For(T value)
	{
		return Argument((typename ABIParamType<T>::type) value);
	}


	template <typename T> typename std::conditional<std::is_scalar<T>::value || std::is_reference<T>::value, T, T&&>::type Get() const
	{
		return GetHelper<T>::Get(this);
	}

	Generic* PrivateGetPointerValuePointer()
	{
		return (Generic*)&_pointerValue;
	}

	Generic* PrivateGetPointerValue()
	{
		return _pointerValue;
	}

	template <typename T, typename CHECK = void> struct GetHelper
	{
		static T&& Get(const Argument* a)
		{
			return std::move(*reinterpret_cast<T*>(a->_pointerValue));
		}
	};

private:
	explicit Argument(Char x) : _charValue(x) { }
	explicit Argument(Int16 x) : _int16Value(x) { }
	explicit Argument(Int32 x) : _int32Value(x) { }
	explicit Argument(Int64 x) : _int64Value(x) { }
	explicit Argument(Float32 x) : _float32Value(x) { }
	explicit Argument(Float64 x) : _float64Value(x) { }
	explicit Argument(Generic* x) : _pointerValue(x) { }

	union
	{
		Char _charValue;
		Int16 _int16Value;
		Int32 _int32Value;
		Int64 _int64Value;
		Float32 _float32Value;
		Float64 _float64Value;
		Generic* _pointerValue;
	};
};

template <> inline Float32 Argument::Get<Float32>() const { return _float32Value; }
template <> inline Float64 Argument::Get<Float64>() const { return _float64Value; }

#ifdef MAXON_COMPILER_CLANG
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
#elif defined(MAXON_COMPILER_GCC)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#elif defined(MAXON_COMPILER_MSVC)
	#pragma warning(disable:4312)
#endif

template <typename T> struct Argument::GetHelper<T, typename std::enable_if<std::is_scalar<T>::value>::type>
{
	static T Get(const Argument* a)
	{
		switch (SIZEOF(T))
		{
			case 1:
				return (T) a->_charValue;
			case 2:
				return (T) a->_int16Value;
			case 4:
				return (T) a->_int32Value;
			case 8:
			default:
				return (T) a->_int64Value;
		}
	}
};

#ifdef MAXON_COMPILER_CLANG
	#pragma clang diagnostic pop
#elif defined(MAXON_COMPILER_GCC)
	#pragma GCC diagnostic pop
#elif defined(MAXON_COMPILER_MSVC)
	#pragma warning(default:4312)
#endif

template <typename T> struct Argument::GetHelper<T, typename std::enable_if<std::is_reference<T>::value>::type>
{
	static T Get(const Argument* a)
	{
		return std::move(*(typename std::remove_reference<T>::type*) a->_pointerValue);
	}
};


using DelegateFunctionPointer = void (*) (const DelegateBase&, void*, const Block<Argument>&);


template <typename T, typename... ARGS> struct InvocationBase
{
	static void Invoke(const void* fn, void* result, const Block<const void* const>& arguments);
};

#define MAXON_INVOCATION_BASE_HELPER1(x, i, a) x
#define MAXON_INVOCATION_BASE_HELPER2(x, i, a) , typename x
#define MAXON_INVOCATION_BASE_HELPER3(x, i, a) typename x
#define MAXON_INVOCATION_BASE_HELPER4(x, i, a) , x
#define MAXON_INVOCATION_BASE_HELPER5(x, i, a) arguments[i].Get<x>()
#define MAXON_INVOCATION_BASE_HELPER6(x, i, a) , arguments[i].Get<x>()

#define MAXON_INVOCATION_BASE(N, ...) \
	template <typename T MAXON_MAKE_LIST(MAXON_INVOCATION_BASE_HELPER2, , , , __VA_ARGS__)> struct InvocationBase<T MAXON_MAKE_LIST(MAXON_INVOCATION_BASE_HELPER4, , , , __VA_ARGS__)> \
	{ \
		static void Invoke(const void* fn, void* result, const Block<Argument>& arguments) \
		{ \
			PRIVATE_MAXON_WARN_MUTE_UNUSED (*(T*) result = ((T(*)(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER1, , , __VA_ARGS__))) fn)(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER5, , , __VA_ARGS__))); \
		} \
		static void InvokeDelegate(const DelegateBase& fn, void* result, const Block<Argument>& arguments) \
		{ \
			using Type = Delegate<T(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER1, , , __VA_ARGS__))>; \
			PRIVATE_MAXON_WARN_MUTE_UNUSED (*(T*) result = fn.GetStubPointer<typename Type::StubPtrType>()(fn.GetStaticFunctionPointer<void*>() MAXON_MAKE_LIST(MAXON_INVOCATION_BASE_HELPER6, , , , __VA_ARGS__))); \
		} \
	}; \
	template <MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER3, , , __VA_ARGS__)> struct InvocationBase<void MAXON_MAKE_LIST(MAXON_INVOCATION_BASE_HELPER4, , , , __VA_ARGS__)> \
	{ \
		static void Invoke(const void* fn, void* result, const Block<Argument>& arguments) \
		{ \
			((void(*)(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER1, , , __VA_ARGS__))) fn)(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER5, , , __VA_ARGS__)); \
		} \
		static void InvokeDelegate(const DelegateBase& fn, void* result, const Block<Argument>& arguments) \
		{ \
			using Type = Delegate<void(MAXON_MAKE_COMMA_LIST(MAXON_INVOCATION_BASE_HELPER1, , , __VA_ARGS__))>; \
			fn.GetStubPointer<typename Type::StubPtrType>()(fn.GetStaticFunctionPointer<void*>() MAXON_MAKE_LIST(MAXON_INVOCATION_BASE_HELPER6, , , , __VA_ARGS__)); \
		} \
	}

MAXON_INVOCATION_BASE(0);
MAXON_INVOCATION_BASE(1, A1);
MAXON_INVOCATION_BASE(2, A1, A2);
MAXON_INVOCATION_BASE(3, A1, A2, A3);
MAXON_INVOCATION_BASE(4, A1, A2, A3, A4);
MAXON_INVOCATION_BASE(5, A1, A2, A3, A4, A5);
MAXON_INVOCATION_BASE(6, A1, A2, A3, A4, A5, A6);
MAXON_INVOCATION_BASE(7, A1, A2, A3, A4, A5, A6, A7);
MAXON_INVOCATION_BASE(8, A1, A2, A3, A4, A5, A6, A7, A8);
MAXON_INVOCATION_BASE(9, A1, A2, A3, A4, A5, A6, A7, A8, A9);
MAXON_INVOCATION_BASE(10, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
MAXON_INVOCATION_BASE(11, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
MAXON_INVOCATION_BASE(12, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
MAXON_INVOCATION_BASE(13, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
MAXON_INVOCATION_BASE(14, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
MAXON_INVOCATION_BASE(15, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15);
MAXON_INVOCATION_BASE(16, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16);

template <typename T, typename... ARGS> struct Invocation : public InvocationBase<typename ABIReturnType<T>::type, typename ABIParamType<ARGS>::type...>
{
};


struct DelegateInvocation
{
public:
	DelegateInvocation(void* result, const Block<Argument>& args) : _result(result), _args(args)
	{
	}

	template <typename T> T& GetResult() const
	{
		return *reinterpret_cast<T*>(_result);
	}

	template <typename T> auto GetArgument(Int index) const -> decltype(Argument().Get<T>())
	{
		return _args[index].Get<T>();
	}

	Int GetArgumentCount() const
	{
		return _args.GetCount();
	}

	Block<Argument> GetArguments() const
	{
		return _args;
	}

private:
	void* _result;
	Block<Argument> _args;
};

using DelegateHandler = Delegate<void(const DelegateDataType& type, const DelegateInvocation& invocation)>;

struct DelegateHandlerData
{
	// DelegateDataType is incomplete at this point, therefore use its base class DataType
	DataType type;
	DelegateHandler handler;

#if defined(MAXON_COMPILER_INTEL)
	DelegateHandlerData() = default;
	DelegateHandlerData(DelegateHandlerData&& src) : MAXON_MOVE_MEMBERS(type, handler) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(DelegateHandlerData);
	DelegateHandlerData(const DataType& t, DelegateHandler&& h) : type(t), handler(std::move(h)) { }
#endif

	Result<void> CopyFrom(const DelegateHandlerData& src)
	{
		type = src.type;
		return handler.CopyFrom(src.handler);
	}
};


template <typename R, typename... ARGS> struct DelegateHandlerHelper
{
	static R Invoke(void* h, ARGS... args)
	{
		R result;
		reflection::Argument a[] = {reflection::Argument::For<ARGS>(args)...};
		DelegateHandlerData* d = (DelegateHandlerData*) h;
		d->handler(reinterpret_cast<const DelegateDataType&>(d->type), DelegateInvocation(&result, a));
		return result;
	}
};

template <typename... ARGS> struct DelegateHandlerHelper<void, ARGS...>
{
	static void Invoke(void* h, ARGS... args)
	{
		reflection::Argument a[] = {reflection::Argument::For<ARGS>(args)...};
		DelegateHandlerData* d = (DelegateHandlerData*) h;
		d->handler(reinterpret_cast<const DelegateDataType&>(d->type), DelegateInvocation(nullptr, a));
	}
};

template <typename R> struct DelegateHandlerHelper<R>
{
	static R Invoke(void* h)
	{
		R result;
		DelegateHandlerData* d = (DelegateHandlerData*) h;
		d->handler(reinterpret_cast<const DelegateDataType&>(d->type), DelegateInvocation(&result, Block<reflection::Argument>()));
		return result;
	}
};

template <> struct DelegateHandlerHelper<void>
{
	static void Invoke(void* h)
	{
		DelegateHandlerData* d = (DelegateHandlerData*) h;
		d->handler(reinterpret_cast<const DelegateDataType&>(d->type), DelegateInvocation(nullptr, Block<reflection::Argument>()));
	}
};


}

}

#endif // REFLECTION_INVOCATION_H__
