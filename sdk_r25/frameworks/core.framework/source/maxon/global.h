#ifndef GLOBAL_H__
#define GLOBAL_H__

#include "maxon/module.h"

namespace maxon
{

namespace details
{

//----------------------------------------------------------------------------------------
/// GlobalBase is the base class of Global.
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

template <typename T> class Global : public T
{
public:
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
