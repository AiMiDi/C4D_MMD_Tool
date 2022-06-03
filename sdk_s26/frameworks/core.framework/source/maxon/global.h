#ifndef GLOBAL_H__
#define GLOBAL_H__

#include "maxon/module.h"

namespace maxon
{

namespace details
{

//----------------------------------------------------------------------------------------
/// GlobalBase is used as member of Global.
//----------------------------------------------------------------------------------------
class GlobalBase
{
public:
	GlobalBase(const Char* name, Result<void> (*init) (GlobalBase* global), void (*free) (GlobalBase* global), TranslationUnit* unit);

private:
	EntityDefinition _super; ///< Base definition object.
	Result<void> (* const _init) (GlobalBase* global); ///< Initialization function.
	void (* const _free) (GlobalBase* global); ///< Shutdown function.

	friend class maxon::ObjectModel;
};

}

#ifdef MAXON_DEPENDENCY_ENABLE

//----------------------------------------------------------------------------------------
/// Global<T> can be used for global objects where initialization and freeing shall be
/// done as part of startup and shutdown of the Maxon API. For example if you have a global
///	String object
///	@code
///	String g_string;
///	@endcode
///	the constructor and destructor of that object are called on module initialization and
///	release. That's a problem, because module release happens after shutdown of the Maxon API,
///	so the String get's released too late. You can use MAXON_INITIALIZATION
///	@code
///	static String g_string;
///	static void FreeString()
///	{
///		g_string = nullptr;
///	}
///	MAXON_INITIALIZATION(nullptr, FreeString);
///	@endcode
/// to ensure release at the proper time, but it's easier to use Global<T>:
///	@code
///	static Global<String> g_string;
///	@endcode
/// Global<T> has T as base class, so usually you can pass the global object whereever
/// a T is expected. If necessary, there's the Get() function which casts to the base class T.
///
///	A Global<T> can be initialized to a non-default value in three ways:
///	- Either immediately at construction (during
///	  module initialization) with a value of type T, but that requires that the value can be
///	  computed at this early point of time.
///	- Or by using the constructor with an init function/lambda without parameters which returns Result<T>:
///		@code
///		static Global<NodeTemplate> g_multransformNode{[]() -> Result<NodeTemplate> { return ...; }};
///		@endcode
///		This function gets called by the Maxon API during startup.
///	- Or by an initialization function:
///		@code
///		static Global<NodeTemplate> g_multransformNode;
///		static Result<void> InitNode()
///		{
///			iferr_scope;
///			g_multransformNode = ... iferr_return;
///			return OK;
///		}
///		MAXON_INITIALIZATION(InitNode, nullptr);
///		@endcode
///
///	You should prefer the second way over the third. There's also the GlobalWithInit class template
///	which can be used if T has a member function Init.
//----------------------------------------------------------------------------------------
template <typename T> class Global : public T
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a Global<T> object with default value.
	//----------------------------------------------------------------------------------------
	explicit Global(TranslationUnit& unit = g_translationUnit)
		: _privateSuper(
#ifdef __BASE_FILE__
			__BASE_FILE__,
#else
			"global",
#endif
			nullptr, &PrivateGlobalFree, &unit)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a Global<T> object with the given initial value.
	/// Note that this gets executed at module initialization which is earlier than Maxon API startup.
	/// @param[in] init								Initial value for the base class T.
	//----------------------------------------------------------------------------------------
	explicit Global(T&& init, TranslationUnit& unit = g_translationUnit)
		: T(std::move(init)), _privateSuper(
#ifdef __BASE_FILE__
			__BASE_FILE__,
#else
			"global",
#endif
			nullptr, &PrivateGlobalFree, &unit)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a Global<T> object where the given initializer function is called
	/// during Maxon API startup to determine the initial value.
	/// @param[in] init								Initializer function value for the base class T.
	///																It has to be a parameterless function or lambda
	///																with return type Result<T> or ResultOk<T>.
	//----------------------------------------------------------------------------------------
	template <typename INIT> explicit Global(INIT&& init, TranslationUnit& unit = g_translationUnit)
		: _privateSuper(
#ifdef __BASE_FILE__
			__BASE_FILE__,
#else
			"global",
#endif
			&PrivateGlobalInit<INIT>, &PrivateGlobalFree, &unit)
	{
#ifndef MAXON_COMPILER_INTEL // Intel isn't able to compiler +init for some reason.
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_UNUSED_VARIABLES
		// The following line asserts that the lambda has no capture.
		auto* unused = +init;
		MAXON_WARNING_POP
#endif
	}

	T& operator =(const T& src)
	{
		return this->T::operator =(src);
	}

	T& operator =(T&& src)
	{
		return this->T::operator =(std::move(src));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying T value of this Global<T> object. Usually you don't need this
	/// function because Global<T> has T as direct base class, but there are cases where it's necessary.
	/// @return												Underlying value of type T.
	//----------------------------------------------------------------------------------------
	T& Get()
	{
		return *this;
	}

protected:
	Global(Result<void> (*init) (maxon::details::GlobalBase* global), TranslationUnit* unit)
		: _privateSuper(
#ifdef __BASE_FILE__
			__BASE_FILE__,
#else
			"global",
#endif
			init, &PrivateGlobalFree, unit)
	{
	}

	template <typename INIT> static Result<void> PrivateGlobalInit(maxon::details::GlobalBase* global)
	{
		iferr_scope;
		*PrivateGlobalGet(global) = (*reinterpret_cast<const typename std::decay<INIT>::type*>(global))() iferr_return;
		return OK;
	}

	static Global* PrivateGlobalGet(maxon::details::GlobalBase* global)
	{
		return reinterpret_cast<Global*>(reinterpret_cast<Char*>(global) - MAXON_OFFSETOF_NON_STANDARD_LAYOUT(Global, _privateSuper));
	}

	static void PrivateGlobalFree(maxon::details::GlobalBase* global)
	{
		T* obj = PrivateGlobalGet(global);
		obj->T::~T();
		new (obj) T();
	}

	maxon::details::GlobalBase _privateSuper;
};

//----------------------------------------------------------------------------------------
/// GlobalWithInit<T> can be used for global objects when their type T has a member function
/// named Init to initialize the object during startup of the Maxon API. Example:
///	@code
///	struct MyTranslationMap : public HashMap<Id, Id>
///	{
///		Result<void> Init()
///		{
///			iferr_scope;
///			... // fill the map
///			return OK;
///		}
///	};
///	static GlobalWithInit<MyTranslationMap> g_translation;
///	@endcode
///	So Init() is more or less like a constructor which gets executed automatically,
///	and the Maxon API makes sure that the execution happens at the right time.
///
///	The destructor of T is called automatically during shutdown of the Maxon API.
///	You could use MAXON_INITIALIZATION instead, but that's less clean:
///	@code
///	static HashMap<Id, Id> g_translation;
///
///	static Result<void> InitTranslation()
///	{
///		iferr_scope;
///		... // fill the g_translation map
///		return OK;
///	}
///	static void FreeTranslation()
///	{
///		g_translation.Reset();
///	}
///	MAXON_INITIALIZATION(InitTranslation, FreeTranslation);
///	@endcode
//----------------------------------------------------------------------------------------
template <typename T> class GlobalWithInit : public Global<T>
{
public:
	explicit GlobalWithInit(TranslationUnit& unit = g_translationUnit) : Global<T>(&Init, &unit)
	{
	}

	T& operator =(const T& src)
	{
		return this->T::operator =(src);
	}

	T& operator =(T&& src)
	{
		return this->T::operator =(std::move(src));
	}

private:
	static Result<void> Init(maxon::details::GlobalBase* global)
	{
		T* obj = GlobalWithInit::PrivateGlobalGet(global);
		Result<void> res = obj->Init();
		if (res == FAILED)
		{
			obj->T::~T();
			new (obj) T();
		}
		return res;
	}
};

#endif

}

#endif // GLOBAL_H__
