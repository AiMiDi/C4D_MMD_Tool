#ifndef SHAREDREF_H__
#define SHAREDREF_H__

#include "maxon/apibase.h"


namespace maxon
{


//----------------------------------------------------------------------------------------
/// Reference counted object for SharedRef<>
//----------------------------------------------------------------------------------------
template <typename REFCLASS> class SharedObject
{
public:
	template <typename ST> struct ReferenceFunctions { using type = typename ST::type; };
	static const EntityBase::FLAGS REFERENCE_KIND = EntityBase::FLAGS::REFERENCE_NORMAL;

	REFCLASS& GetWrapped()
	{
		return _ref;
	}

	void SetWrapped(REFCLASS&& ref)
	{
		_ref = std::move(ref);
	}

private:
	REFCLASS _ref;
};

template <typename WRAPPER, typename REFCLASS> class SharedRefBase : public WRAPPER::template ReferenceFunctions<DirectRef<WRAPPER, StrongRefHandler, void>>::type
{
public:
	static_assert(WRAPPER::REFERENCE_KIND == EntityBase::FLAGS::REFERENCE_NORMAL, "The wrapper interface for a shared reference must have normal reference semantics (MAXON_REFERENCE_NORMAL).");
	static const Bool HAS_ERROR = false;

	const ThreadReferencedError& GetErrorStorage() const
	{
		return *(const ThreadReferencedError*) this;
	}

	using Ref = REFCLASS;

	using ReferenceClass = typename Ref::ReferenceClass;
	using Handler = typename Ref::Handler;
	using ReferencedType = typename Ref::ReferencedType;
	static const Bool DIRECT_REF = false;

	WRAPPER* GetWrapper() const
	{
		return _ref.GetPointer();
	}

	ReferencedType* GetPointer() const
	{
		auto ptr = _ref.GetPointer();
		return ptr ? (ReferencedType*) ptr->GetWrapped().GetPointer() : nullptr;
	}

	ResultRef<typename std::remove_const<ReferencedType>::type> MakeWritable(Bool resetOnError = true)
	{
		static_assert(MAXON_IS_COW_KIND(Handler::KIND), "MakeWritable must not be invoked for non-COW references.");
		auto ptr = _ref.GetPointer();
		return ptr ? reinterpret_cast<typename std::remove_const<ReferencedType>::type*>(ptr->GetWrapped().MakeWritable(resetOnError)) : nullptr;
	}

protected:
	StrongRef<WRAPPER> _ref;
};

template <typename WRAPPER> class SharedRefHelper
{
public:
	template <typename REFCLASS> static WRAPPER* CreateWrapper(const REFCLASS& ref)
	{
		return ref.CreateWrapper();
	}

	template <typename REF> using Rebind = WRAPPER;
};

template <typename REFCLASS> class SharedRefHelper<SharedObject<REFCLASS>>
{
public:
	static SharedObject<REFCLASS>* CreateWrapper(const REFCLASS& ref)
	{
		return NewObj(SharedObject<REFCLASS>);
	}

	template <typename REF> using Rebind = SharedObject<REF>;
};

//----------------------------------------------------------------------------------------
/// SharedRef encapsulates a REFCLASS (e.g. String, Url, ImageLayer, ImageTexture...) to access it from multiple SharedRefs.
/// With this technique it is possible to store COW objects in structures and allow the modification of the objects
/// from outside.
//----------------------------------------------------------------------------------------
template <typename REFCLASS, typename WRAPPER = SharedObject<REFCLASS>> class SharedRef : public REFCLASS::ReferencedType::template ReferenceFunctions<RefBaseFunctions<SharedRefBase<WRAPPER, REFCLASS>>>::type
{
public:
	//----------------------------------------------------------------------------------------
	/// Creates a new SharedRef object from the REFCLASS object.
	//----------------------------------------------------------------------------------------
	Result<void> Create(const REFCLASS& ref)
	{
		iferr_scope;
		WRAPPER* w = SharedRefHelper<WRAPPER>::CreateWrapper(ref) iferr_return;
		REFCLASS r = ref;
		w->SetWrapped(std::move(r));
		this->_ref = w;
		return OK;
	}
	//----------------------------------------------------------------------------------------
	/// Creates a new SharedRef object from the REFCLASS object.
	//----------------------------------------------------------------------------------------
	Result<void> Create(REFCLASS&& ref)
	{
		iferr_scope;
		WRAPPER* w = SharedRefHelper<WRAPPER>::CreateWrapper(ref) iferr_return;
		w->SetWrapped(std::move(ref));
		this->_ref = w;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Acquire access to the REFCLASS object.
	//----------------------------------------------------------------------------------------
	const REFCLASS& GetRef() const
	{
		// TODO: (Ole/Tilo) return a dummy value which returns a error on MakeWritable()
		return this->_ref ? reinterpret_cast<const REFCLASS&>(this->_ref->GetWrapped()) : REFCLASS::DummyValue();
	}

	//----------------------------------------------------------------------------------------
	/// Acquire access to the REFCLASS object.
	//----------------------------------------------------------------------------------------
	REFCLASS& GetRef()
	{
		return const_cast<REFCLASS&>(static_cast<const SharedRef*>(this)->GetRef());
	}

	//----------------------------------------------------------------------------------------
	/// Casts the SharedRef into another compatible object.
	/// e.g.:
	/// @code
	/// ImageBaseSharedRef i = _imageTexture.AddChildren(imageLayer, nullptr) iferr_return;
	/// entry->_loadingLayer = i.Cast<ImageLayer>() iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename REFCLASSOUT> const SharedRef<REFCLASSOUT, typename SharedRefHelper<WRAPPER>::template Rebind<REFCLASSOUT>>& Cast() const
	{
		using RefOut = SharedRef<REFCLASSOUT, typename SharedRefHelper<WRAPPER>::template Rebind<REFCLASSOUT>>;
		if (this->_ref)
		{
			const REFCLASS& r = this->_ref->GetWrapped();
			if (!r.GetPointer() || r.GetPointer()->template IsInstanceOf<typename REFCLASSOUT::ReferencedType>())
			{
				return *reinterpret_cast<const RefOut*>(this);
			}
		}
		return GetZeroRef<RefOut>();
	}

	explicit operator Bool() const
	{
		return Bool(this->_ref);
	}

	auto PrivateGetRef() const -> const decltype(this->_ref)&
	{
		return this->_ref;
	}

	auto PrivateGetRef() -> decltype(this->_ref)&
	{
		return this->_ref;
	}

private:
	WRAPPER* GetWrapper() const;
};

}

#endif // SHAREDREF_H__
