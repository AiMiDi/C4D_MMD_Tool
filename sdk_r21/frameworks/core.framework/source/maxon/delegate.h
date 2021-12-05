#ifndef DELEGATE_H__
#define DELEGATE_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Delegate base class which can be used for DataType
//----------------------------------------------------------------------------------------
class DelegateBase
{
protected:
	enum class CALLBACKMODE
	{
		ALLOC = 0,								///< Allocates memory for an object.
		DESTRUCT_AND_RELEASE = 1,	///< Destructs the object to which dst points and releases the memory.
		COPY = 2,									///< Copies the object from src to dst and returns the size on success (0 on failure).
		MOVE_AND_DESTRUCT = 3			///< Moves the object from src to dst and returns the size (only used for internal storage, cannot fail).
	} MAXON_ENUM_ORDERED_LIST_CLASS(CALLBACKMODE);

	using Callback = Int (*)(DelegateBase* dst, const DelegateBase* src, CALLBACKMODE mode);

public:
	DelegateBase()
	{
		static_assert(sizeof(DelegateBase) == 64, "Size of DelegateBase must not change.");
	}

	~DelegateBase()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate using object, stub and utility callback pointer.
	/// @tparam STUBPTR								The stub pointer type.
	/// @param[in] objectPtr					Self pointer of the object. Might be nullptr if the method has been inlined into the stub.
	/// @param[in] stubPtr						Stub method pointer (which forward the call to the callable).
	/// @param[in] callback						Utility callback which handles copy, move and destruction of the object. Nullptr for a static function.
	//----------------------------------------------------------------------------------------
	template <typename STUBPTR> DelegateBase(void* objectPtr, STUBPTR stubPtr, Callback callback) : _objectPtr(objectPtr), _stubPtr(reinterpret_cast<void (*)()>(stubPtr)), _callback(callback)
	{
	}

	/// Assign when T is not a Delegate, but a function pointer, ptmf or a PTMFWrapper<OBJECT*, RESULT (OBJECT::*)(ARGS...)>.
	template <typename FN, typename STUBPTR> DelegateBase(FN&& fn, STUBPTR stub, Callback callback) : _objectPtr(&_storage[0]), _stubPtr(reinterpret_cast<void (*)()>(stub)), _callback(callback)
	{
		using FunctorType = typename std::decay<FN>::type;

		static_assert(SIZEOF(FunctorType) <= SIZEOF(_storage), "Callable is too big to fit into internal storage. Use CopyFrom");

		new (&_storage[0]) FunctorType(std::forward<FN>(fn));
	}

	DelegateBase(const DelegateBase&) = delete;

	DelegateBase(DelegateBase&& src) : _objectPtr(src._objectPtr), _stubPtr(src._stubPtr), _callback(src._callback)
	{
		if (_callback)
		{
			_callback(this, &src, CALLBACKMODE::MOVE_AND_DESTRUCT);
		}

		src._objectPtr = nullptr;
		src._stubPtr = nullptr;
		src._callback = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(DelegateBase);

	void Reset()
	{
		// Destruct the object and free the memory.
		if (_callback)
			_callback(this, nullptr, CALLBACKMODE::DESTRUCT_AND_RELEASE);

		_objectPtr = nullptr;
		_stubPtr = nullptr;
		_callback = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] src								Source delegate.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	ResultMem CopyFrom(const DelegateBase& src)
	{
		Reset();

		_objectPtr = src._objectPtr;
		_stubPtr = src._stubPtr;
		_callback = src._callback;

		if (_callback == nullptr)
			return OK;

		// Copy the object and allocate memory if necessary.
		return ResultMem(_callback(this, &src, CALLBACKMODE::COPY) != 0);
	}

	/// Assign when T is not a Delegate, but a function pointer, ptmf or a PTMFWrapper<OBJECT*, RESULT (OBJECT::*)(ARGS...)>.
	template <typename FN, typename STUBPTR> ResultMem CopyFrom(FN&& f, STUBPTR stub, Callback callback)
	{
		using FunctorType = typename std::decay<FN>::type;

		Reset();

		_stubPtr = reinterpret_cast<void (*)()>(stub);
		_callback = callback;

		if (SIZEOF(FunctorType) <= SIZEOF(_storage))
		{
			_objectPtr = &_storage[0];
		}
		else
		{
			// Allocate storage for the object.
			if (_callback(this, nullptr, CALLBACKMODE::ALLOC) == 0)
				return FAILED;
		}

		new (_objectPtr) FunctorType(std::forward<FN>(f));

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copies or moves #object into the Delegate and sets #stub as the handler for delegate calls.
	/// #stub will receive a pointer to the object held by the Delegate in its first parameter.
	/// @param[in] object							The object to move or copy.
	/// @param[in] stub								The call handler.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename OBJ, typename STUBPTR> ResultMem CopyFrom(OBJ&& object, STUBPTR stub)
	{
		return CopyFrom(std::forward<OBJ>(object), stub, UtilityStub<typename std::decay<OBJ>::type>);
	}


	Bool IsEmpty() const
	{
		return _stubPtr == nullptr;
	}

	Bool IsPopulated() const
	{
		return _stubPtr != nullptr;
	}

	Bool IsStaticFunctionPointer() const
	{
		return _callback == nullptr;
	}

	template <typename FUNCTIONPTR> FUNCTIONPTR GetStaticFunctionPointer() const
	{
		return reinterpret_cast<FUNCTIONPTR>(_objectPtr);
	}

	template <typename STUBPTR> STUBPTR GetStubPointer() const
	{
		return reinterpret_cast<STUBPTR>(_stubPtr);
	}

protected:
	// Return the utility stub for references (BaseRef).
	template <typename REF> static Callback GetReferenceUtilityStub(void*)
	{
		return &ReferenceUtilityStub<REF>;
	}

	// A reference with pointer semantics doesn't need a utility stub.
	template <typename REF> static Callback GetReferenceUtilityStub(PointerHandler*)
	{
		return nullptr;
	}

	/// A dummy stub for inlined PTMF which does nothing.
	static Int PTMFUtilityStub(DelegateBase* dst, const DelegateBase* src, CALLBACKMODE mode)
	{
		return 1;
	}

	/// Destructs, copies or moves an object with operator ()().
	template <typename T> static Int UtilityStub(DelegateBase* dst, const DelegateBase* src, CALLBACKMODE mode); // definition can be found in defaultallocator.h

	/// Destructs, copies or moves a reference with operator ()(). This treats _storage[0] as if it was not just a pointer, but a REFERENCE.
	template <typename REFERENCE> static Int ReferenceUtilityStub(DelegateBase* dst, const DelegateBase* src, CALLBACKMODE mode)
	{
		switch (mode)
		{
			case CALLBACKMODE::ALLOC:
			{
				// You cannot allocate storage for the reference.
				DebugStop("Wrong CALLBACKMODE.");
				return 0;
			}
			case CALLBACKMODE::DESTRUCT_AND_RELEASE:
			{
				// Release a reference to the object.
				reinterpret_cast<REFERENCE&>(dst->_storage[0]).~REFERENCE();
				break;
			}
			case CALLBACKMODE::COPY:
			{
				// Add a reference to the object.
				new (&dst->_storage[0]) REFERENCE(reinterpret_cast<const REFERENCE&>(src->_storage[0]));
				break;
			}
			case CALLBACKMODE::MOVE_AND_DESTRUCT:
			{
				// Just copy the pointer. There is no need to null it in src.
				dst->_storage[0] = src->_storage[0];
				return 0;
			}
		}

		return -1; // A negative value indicates that no memory is required.
	}

	// DelegateBase must always fit into 64 bytes.
#ifdef MAXON_TARGET_64BIT
	void* _storage[5];
#else
	void* _storage[13];
#endif
	void* _objectPtr = nullptr;
	void (*_stubPtr)() = nullptr;
	Callback _callback = nullptr;

};

template <typename T> class Delegate;

namespace details
{

template <typename> struct MethodDelegateType;

template <typename RESULT, typename OBJECT, typename... ARGS> struct MethodDelegateType<RESULT (*)(OBJECT*, ARGS...)>
{
	using type = Delegate<RESULT(ARGS...)>;
	using object = OBJECT;
};

template <typename I, typename = typename I::NonvirtualInterfaceMarker> inline const void* MethodDelegateMTable(const void*)
{
	return &I::MTable::_instance;
}

template <typename I, typename = typename I::InterfaceMarker> inline const void* MethodDelegateMTable(const ObjectInterface* object)
{
	return static_cast<typename SFINAEHelper<const ObjectInterface*, I>::type>(object)->GetClassInfo()->GetInterfaceInfo(I::_interface.GetInfoOffset())->GetMTable();
}

template <typename I, typename METHOD, typename T> inline typename MethodDelegateType<METHOD>::type GetMethodDelegate(T&& object, Int offset)
{
	using ReferencedType = typename GetDirectlyReferencedTypeCheckConstAndPtr<T>::type;
	if ((const ReferencedType*) object)
	{
		return typename MethodDelegateType<METHOD>::type(std::forward<T>(object), *(METHOD*) ((const Char*) MethodDelegateMTable<I>((const ReferencedType*) object) + offset));
	}
	else if (std::is_const<typename MethodDelegateType<METHOD>::object>::value)
	{
		// For a null object and a const method, we use the NullValuePtr() of the interface.
		const ReferencedType* nullValue = ReferencedType::NullValuePtr();
		if (nullValue)
		{
			// We use the delegate with pointer semantics as the null value of an interface is already owned by the interface.
			return typename MethodDelegateType<METHOD>::type(const_cast<ReferencedType*>(nullValue), *(METHOD*) ((const Char*) MethodDelegateMTable<I>(nullValue) + offset));
		}
	}
	DebugStop("Can't create a Delegate for a null object.");
	return typename MethodDelegateType<METHOD>::type();
}

template <typename REF> struct MethodDelegateThisType
{
	using RefType = typename std::remove_reference<REF>::type;
	using ReferencedType = typename GetDirectlyReferencedTypeCheckConstAndPtr<RefType>::type;
	static const Bool VIRTUAL = std::is_base_of<ObjectInterface, ReferencedType>::value;
	using type = typename std::conditional<VIRTUAL, typename InheritConst<GenericComponent, ReferencedType>::type, ReferencedType>::type;
	using Handler = typename GetHandler<RefType, PointerHandler>::type;
	using BaseRefType = BaseRef<ReferencedType, Handler>;
};

}

#define MAXON_METHOD_DELEGATE(obj, interface, method) \
	maxon::details::GetMethodDelegate<interface, decltype(interface::MTable::_##interface##_##method)>(obj, offsetof(interface::MTable, _##interface##_##method))

//----------------------------------------------------------------------------------------
/// @tparam RESULT								Return value type of the callable.
//----------------------------------------------------------------------------------------
template <typename RESULT, typename... ARGS> class Delegate<RESULT(ARGS...)> : public DelegateBase
{
public:
	using StubPtrType = RESULT (*)(void*, ARGS...);

private:
	Delegate(void* o, StubPtrType m, Callback c) : DelegateBase(o, m, c)
	{
	}

public:
	using ResultValueType = RESULT;

	static const Delegate& NullValueRef() {return GetZeroRef<Delegate>(); }

	Delegate() = default;

	Delegate(const Delegate&) = delete;

	Delegate(Delegate&& src) = default;

	MAXON_IMPLICIT Delegate(const std::nullptr_t) : Delegate() { }

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate for a function pointer. This is less efficient than Delegate::Create<METHODE_NAME>()
	/// because it requires an extra indirect function pointer jump (the method can't be inlined).
	//----------------------------------------------------------------------------------------
	explicit Delegate(RESULT (*functionPtr)(ARGS...)) : DelegateBase(reinterpret_cast<void*>(functionPtr), &FunctionIndirectStub<RESULT (*)(ARGS...)>, nullptr)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate for a virtual member function of an object.
	/// @note The caller retains ownership of the object referenced by `objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] objectPtr					Self pointer of the object.
	/// @param[in] methodPtr					Pointer to the member function.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> Delegate(OBJECT* objectPtr, RESULT (OBJECT::* methodPtr)(ARGS...))
	{
		ConstructFrom(PTMFWrapper<OBJECT>(objectPtr, methodPtr));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate for a const virtual member function of an object.
	/// @note The caller retains ownership of the object referenced by `objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] objectPtr					Self pointer of the object.
	/// @param[in] methodPtr					Pointer to the const member function.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> Delegate(const OBJECT* objectPtr, RESULT (OBJECT::* methodPtr)(ARGS...) const)
	{
		ConstructFrom(PTMFWrapper<OBJECT>(objectPtr, methodPtr));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate for a virtual member function of an object.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] object							Reference of the object.
	/// @param[in] methodPtr					Pointer to the member function.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> Delegate(OBJECT& object, RESULT (OBJECT::* methodPtr)(ARGS...))
	{
		ConstructFrom(PTMFWrapper<OBJECT>(&object, methodPtr));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate for a const virtual member function of a const object.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] object							Reference of the const object.
	/// @param[in] methodPtr					Pointer to the const member function.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> Delegate(const OBJECT& object, RESULT (OBJECT::* methodPtr)(ARGS...) const)
	{
		ConstructFrom(PTMFWrapper<OBJECT>(&object, methodPtr));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate which binds the first argument of a non-member function to an object.
	/// The delegate holds a reference to the object of the type REF. If this is a pointer or
	/// a reference with pointer semantics you have to ensure that the object lives at least as long
	/// as the delegate.
	/// @tparam REF										The reference type of the object.
	/// @param[in] reference					The object reference.
	/// @param[in] methodPtr					Pointer to the function.
	//----------------------------------------------------------------------------------------
	template <typename REF, typename OBJECT> Delegate(REF&& reference, RESULT (*const &methodPtr)(OBJECT*, ARGS...))
		: DelegateBase((void*) nullptr, (StubPtrType) methodPtr, GetReferenceUtilityStub<typename maxon::details::MethodDelegateThisType<REF>::BaseRefType>((typename maxon::details::MethodDelegateThisType<REF>::Handler*) nullptr))
	{
		using MDThisType = maxon::details::MethodDelegateThisType<REF>;
		static_assert(std::is_const<OBJECT>::value || !std::is_const<typename MDThisType::type>::value, "Cannot bind a non-const method to a const object.");
		static_assert(MDThisType::VIRTUAL == std::is_same<const OBJECT, const GenericComponent>::value && (MDThisType::VIRTUAL || std::is_base_of<OBJECT, typename MDThisType::type>::value), "The type of the method object must be a base of the type of the object.");
		// Set _storage[0] here and not in the constructor of DelegateBase to obtain the correct reference semantics.
		new (&this->_storage[0]) typename std::decay<REF>::type(std::forward<REF>(reference));
		_objectPtr = this->_storage[0];
		// For virtual interfaces handle the offset between object and component pointer: _objectPtr has to be the component pointer.
		if (MDThisType::VIRTUAL)
			reinterpret_cast<GenericComponent*&>(_objectPtr) += *reinterpret_cast<const Int*>(&methodPtr + 1);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a delegate when T is not a Delegate, but a function pointer, ptmf or a PTMFWrapper<OBJECT*, RESULT (OBJECT::*)(ARGS...)>.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename = typename std::enable_if<!std::is_convertible<Delegate, typename std::decay<FN>::type>::value && (GetCollectionKind<FN>::value == COLLECTION_KIND::NONE)>::type>
	MAXON_IMPLICIT Delegate(FN&& fn) // Collections have to be disabled, too, because otherwise this constructor would fight with the conversion function from collections to ValueReceiver.
	{
		ConstructFrom(std::forward<FN>(fn));
	}

	//----------------------------------------------------------------------------------------
	/// A delegate cannot be copied without error checks because this might involve memory allocations.
	/// @note Use CopyFrom().
	//----------------------------------------------------------------------------------------
	Delegate& operator =(const Delegate&) = delete;

	//----------------------------------------------------------------------------------------
	/// Copies a delegate.
	/// @param[in] src								Source delegate.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	ResultMem CopyFrom(const Delegate& src)
	{
		return DelegateBase::CopyFrom(src);
	}

	//----------------------------------------------------------------------------------------
	/// Resets the delegate.
	/// @return												Always true.
	//----------------------------------------------------------------------------------------
	ResultMem CopyFrom(const std::nullptr_t)
	{
		Reset();
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copies the function pointer.
	/// @param[in] functionPtr				Static function pointer
	/// @return												Always true.
	//----------------------------------------------------------------------------------------
	ResultMem CopyFrom(RESULT (*functionPtr)(ARGS...))
	{
		Reset();
		new (this) Delegate(functionPtr);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copies or moves fn into the Delegate and allocates memory if necessary.
	/// @tparam FN										The callable type.
	/// @param[in] fn									Callable.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename = typename std::enable_if<!std::is_convertible<Delegate, typename std::decay<FN>::type>::value>::type>
	ResultMem CopyFrom(FN&& fn)
	{
		using FunctorType = typename std::decay<FN>::type;

		return DelegateBase::CopyFrom(std::forward<FN>(fn), FunctorStub<FunctorType>, UtilityStub<FunctorType>);
	}

	//----------------------------------------------------------------------------------------
	/// Copies or moves #object into the Delegate and sets #stub as the handler for delegate calls.
	/// #stub will receive a pointer to the object held by the Delegate in its first parameter.
	/// @tparam OBJ										The object type.
	/// @param[in] object							The object to move or copy.
	/// @param[in] stub								The call handler.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename OBJ>
	ResultMem CopyFrom(OBJ&& object, StubPtrType stub)
	{
		return DelegateBase::CopyFrom(std::forward<OBJ>(object), stub);
	}

	Delegate& operator =(Delegate&&) = default;

	Delegate& operator =(const std::nullptr_t)
	{
		Reset();
		return *this;
	}

	Delegate& operator =(RESULT(*const functionPtr)(ARGS...))
	{
		return *this = Delegate(functionPtr);
	}

	/// Assign when T is not a Delegate, but a function pointer, ptmf or a PTMFWrapper<OBJECT*, RESULT (OBJECT::*)(ARGS...)>.
	template <typename FN, typename = typename std::enable_if<!std::is_convertible<Delegate, typename std::decay<FN>::type>::value>::type>
	Delegate& operator =(FN&& fn)
	{
		Reset();
		ConstructFrom(std::forward<FN>(fn));

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a static member function (direct call).
	/// This is the most efficient delegate because the stub can inline the function (or at
	/// least make a direct jump).
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <RESULT (*FUNCTION)(ARGS...)> static ResultOk<Delegate> Create()
	{
		// In this case the compiler might create two versions of FUNCTION, one inlined into FunctionStub and one without the extra parameter.
		// Since this case is mainly for very short methods with minimum latency it only should result in modest amounts of code.
		return Delegate(reinterpret_cast<void*>(FUNCTION), FunctionStub<FUNCTION>, nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns delegate for a function pointer. Less efficient than using Delegate::Create<T>()
	/// because this requires an extra indirect function pointer jump.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	static ResultOk<Delegate> Create(RESULT (*functionPtr)(ARGS...))
	{
		return Delegate(functionPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for an object with a callable, usually a lambda. The object is copied
	/// (or moved if possible). If the allocation fails an error is returned.
	/// @tparam FN										The callable object type.
	/// @param[in] fn									Callable.
	/// @return												Returns a Delegate on success.
	//----------------------------------------------------------------------------------------
	template <typename FN> static Result<Delegate> Create(FN&& fn)
	{
		iferr_scope;
		Delegate d;
		d.CopyFrom(std::forward<FN>(fn)) iferr_return;
		return std::move(d);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a static member function (direct call).
	/// This is the most efficient delegate because the stub can inline the function (or at
	/// least make a direct jump).
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <RESULT (*FUNCTION)(ARGS...)> static Delegate CreateByReference()
	{
		// In this case the compiler might create two versions of FUNCTION, one inlined into FunctionStub and one without the extra parameter.
		// Since this case is mainly for very short methods with minimum latency it only should result in modest amounts of code.
		return Delegate(reinterpret_cast<void*>(FUNCTION), FunctionStub<FUNCTION>, nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns delegate for a function pointer. Less efficient than using Delegate::Create<T>()
	/// because this requires an extra indirect function pointer jump.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	static Delegate CreateByReference(RESULT (*functionPtr)(ARGS...))
	{
		return Delegate(functionPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a virtual member function.
	/// @note The caller retains ownership of the object referenced by #objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @tparam METHOD_PTR						The virtual member function type (which can be resolved to a specific function pointer).
	/// @param[in] objectPtr					Self pointer of the object.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT, RESULT (OBJECT::* METHOD_PTR)(ARGS...)> static Delegate CreateByReference(OBJECT* objectPtr)
	{
		return Delegate(objectPtr, MethodStub<OBJECT, METHOD_PTR>, PTMFUtilityStub);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a const virtual member function.
	/// @note The caller retains ownership of the object referenced by #objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @tparam METHOD_PTR						The const virtual member function type (which can be resolved to a specific function pointer).
	/// @param[in] objectPtr					Self pointer of the object.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT, RESULT (OBJECT::* METHOD_PTR)(ARGS...) const> static Delegate CreateByReference(const OBJECT* objectPtr)
	{
		return Delegate(const_cast<OBJECT*>(objectPtr), ConstMethodStub<OBJECT, METHOD_PTR>, PTMFUtilityStub);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a virtual member function.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @tparam METHOD_PTR						The virtual member function type (which can be resolved to a specific function pointer).
	/// @param[in] object							Reference of the object.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT, RESULT (OBJECT::* METHOD_PTR)(ARGS...)> static Delegate CreateByReference(OBJECT& object)
	{
		return Delegate(&object, MethodStub<OBJECT, METHOD_PTR>, PTMFUtilityStub);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a const virtual member function.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @tparam METHOD_PTR						The virtual member function type (which can be resolved to a specific function pointer).
	/// @param[in] object							Reference of the object.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT, RESULT (OBJECT::* METHOD_PTR)(ARGS...) const> static Delegate CreateByReference(const OBJECT& object)
	{
		return Delegate(const_cast<OBJECT*>(&object), ConstMethodStub<OBJECT, METHOD_PTR>, PTMFUtilityStub);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a virtual member function.
	/// @note The caller retains ownership of the object referenced by #objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] objectPtr					Self pointer of the object.
	/// @param[in] methodPtr					Pointer to the member function.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> static Delegate CreateByReference(OBJECT* objectPtr, RESULT (OBJECT::* methodPtr)(ARGS...))
	{
		return Delegate(objectPtr, methodPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a const virtual member function.
	/// @note The caller retains ownership of the object referenced by #objectPtr and and must
	/// not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] objectPtr					Self pointer of the object.
	/// @param[in] methodPtr					Pointer to the const member function.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> static Delegate CreateByReference(const OBJECT* objectPtr, RESULT (OBJECT::* methodPtr)(ARGS...) const)
	{
		return Delegate(objectPtr, methodPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a virtual member function.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] object							Reference of the object.
	/// @param[in] methodPtr					Pointer to the member function.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> static Delegate CreateByReference(OBJECT& object, RESULT (OBJECT::* methodPtr)(ARGS...))
	{
		return Delegate(object, methodPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for a const virtual member function.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam OBJECT								The object type.
	/// @param[in] object							Reference of the const object.
	/// @param[in] methodPtr					Pointer to the const member function.
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename OBJECT> static Delegate CreateByReference(const OBJECT& object, RESULT (OBJECT::* methodPtr)(ARGS...) const)
	{
		return Delegate(object, methodPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a delegate for an object with a callable.
	/// @note The caller retains ownership of #object and must not release it before the Delegate is destructed.
	/// @tparam FN										The callable object type.
	/// @param[in] fn									Callable
	/// @return												Always succeeds and returns a Delegate.
	//----------------------------------------------------------------------------------------
	template <typename FN> static Delegate CreateByReference(FN&& fn)
	{
		Delegate d;
		return std::move(d.ConstructFrom(ObjectPointerWrapper<typename std::remove_reference<FN>::type>(&fn)));
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void Swap(Delegate& other) { std::swap(*this, other); }

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator ==(const Delegate& rhs) const
	{
		return (_objectPtr == rhs._objectPtr) && (_stubPtr == rhs._stubPtr);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator !=(const Delegate& rhs) const
	{
		return !operator ==(rhs);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <(const Delegate& rhs) const
	{
		return (_objectPtr < rhs._objectPtr) || ((_objectPtr == rhs._objectPtr) && (_stubPtr < rhs._stubPtr));
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator ==(const std::nullptr_t) const
	{
		return !_stubPtr;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator !=(const std::nullptr_t) const
	{
		return _stubPtr != nullptr;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const { return _stubPtr != nullptr; }

	//----------------------------------------------------------------------------------------
	/// Forwards the call (invokes the stub function for a callable).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE RESULT operator ()(ARGS... args) const
	{
		StubPtrType stub = StubPtrType(_stubPtr);
		return stub(_objectPtr, std::forward<ARGS>(args)...);
	}

private:
	template <typename OBJECT> struct PTMFWrapper
	{
		using ObjectPtr = OBJECT*;
		using MethodPtr = RESULT (OBJECT::*)(ARGS...);
		using ConstObjectPtr = const OBJECT*;
		using ConstMethodPtr = RESULT (OBJECT::*)(ARGS...) const;

		PTMFWrapper(ObjectPtr objectPtr, MethodPtr methodPtr) : _objectPtr(objectPtr), _methodPtr(methodPtr)
		{
		}
		PTMFWrapper(ConstObjectPtr objectPtr, ConstMethodPtr methodPtr) : _objectPtr(const_cast<ObjectPtr>(objectPtr)), _methodPtr(reinterpret_cast<MethodPtr>(methodPtr))
		{
		}
		MAXON_ATTRIBUTE_FORCE_INLINE RESULT operator ()(ARGS&&... args)
		{
			return (_objectPtr->*_methodPtr)(std::forward<ARGS>(args)...);
		}
	private:
		ObjectPtr _objectPtr;
		MethodPtr _methodPtr;
	};

	template <typename OBJECT> struct ObjectPointerWrapper
	{
		explicit ObjectPointerWrapper(OBJECT* objectPtr) : _objectPtr(objectPtr)
		{
		}
		MAXON_ATTRIBUTE_FORCE_INLINE RESULT operator ()(ARGS&&... args)
		{
			return _objectPtr->operator ()(std::forward<ARGS>(args)...);
		}
	private:
		OBJECT* _objectPtr;
	};

	/// Constructs the delegate when T is not a Delegate, but a function pointer, ptmf or a PTMFWrapper<OBJECT*, RESULT (OBJECT::*)(ARGS...)>.
	template <typename FN> Delegate& ConstructFrom(FN&& fn)
	{
		using FunctorType = typename std::decay<FN>::type;

		new (this) DelegateBase(std::forward<FN>(fn), FunctorStub<FunctorType>, UtilityStub<FunctorType>);
		return *this;
	}

	/// Invokes a C style function via direct call (inlines it if possible).
	template <RESULT (*FUNCTION)(ARGS...)> static MAXON_ATTRIBUTE_FORCE_INLINE RESULT FunctionStub(void*, ARGS... args)
	{
		// In this case the compiler can inline FUNCTION_PTR and therefore eliminate the extra indirect jump.
		return FUNCTION(std::forward<ARGS>(args)...);
	}

	/// Invokes a C style function via indirect function pointer call.
	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE RESULT FunctionIndirectStub(void* functionPtr, ARGS... args)
	{
		T fn = reinterpret_cast<T>(functionPtr);
		return fn(std::forward<ARGS>(args)...);
	}

	/// Invokes a virtual member function.
	template <typename OBJECT, RESULT (OBJECT::*METHOD_PTR)(ARGS...)> static MAXON_ATTRIBUTE_FORCE_INLINE RESULT MethodStub(void* objectPtr, ARGS... args)
	{
		return (static_cast<OBJECT*>(objectPtr)->*METHOD_PTR)(std::forward<ARGS>(args)...);
	}

	/// Invokes a const virtual member function.
	template <typename OBJECT, RESULT (OBJECT::*METHOD_PTR)(ARGS...) const> static MAXON_ATTRIBUTE_FORCE_INLINE RESULT ConstMethodStub(void* objectPtr, ARGS... args)
	{
		return (static_cast<const OBJECT*>(objectPtr)->*METHOD_PTR)(std::forward<ARGS>(args)...);
	}

	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE RESULT FunctorStub(void* objectPtr, ARGS... args)
	{
		return (*static_cast<T*>(objectPtr))(std::forward<ARGS>(args)...);
	}
};


//----------------------------------------------------------------------------------------
/// ValueReceiver is a type alias for a Delegate which receives values of the given type(s) T and
/// returns Result<Bool>. ValueReceiver can be used as parameter type of a function which
/// shall generate a number of values of type T in succession. The function will call the
/// receiver once for each such value, and the receiver has the chance to cancel the supply
/// of further values by returning false.
///
/// For example a generator function which yields all positive numbers to a ValueReceiver
/// looks like
/// @code
/// Result<void> GetPositiveNumbers(const ValueReceiver<Int>& receiver)
/// {
/// 	iferr_scope;
/// 	for (Int i = 1; ; ++i)
/// 	{
/// 		Bool b = receiver(i) iferr_return;
/// 		if (!b)
/// 			return OK;
/// 	}
/// }
/// @endcode
/// All arrays and sets have conversion functions to a ValueReceiver which appends
/// the supplied value to them. So if you want to write a function which shall return a number
/// of values of type T by adding them to a caller-provided array, you can use a ValueReceiver
/// instead of an array for the function parameter. This will not only allow arrays, but arbitrary
/// functions which can even cancel the function if no further values are needed.
///
/// @tparam T											Types of values produced by the generator function.
//----------------------------------------------------------------------------------------
template <typename... T> using ValueReceiver = Delegate<Result<Bool>(T...)>;

#define yield_scope maxon::Result<maxon::Bool> yieldResult_
#define yield_return % yieldResult_; do { if ((yieldResult_ == maxon::FAILED) || !yieldResult_.GetValue()) return yieldResult_; } while (false)

inline void operator %(const Result<Bool>& res, Result<Bool>& yieldResult)
{
	yieldResult = res;
}

inline void operator %(const Result<void>& res, Result<Bool>& yieldResult)
{
	yieldResult = Result<Bool>(true, res);
}

template <typename TO, typename... TO_REST, typename FROM, typename... FROM_REST, Bool SAFE> struct GenericCastMemberTrait<ParameterPack<TO, TO_REST...>, ParameterPack<FROM, FROM_REST...>, SAFE>
{
	static constexpr Bool value = GenericCastMemberTrait<TO, FROM, SAFE>::value && GenericCastMemberTrait<ParameterPack<TO_REST...>, ParameterPack<FROM_REST...>, SAFE>::value;
};

template <typename RESULT_TO, typename... ARGS_TO, typename RESULT_FROM, typename... ARGS_FROM, Bool SAFE> struct GenericCastMemberTrait<Delegate<RESULT_TO(ARGS_TO...)>, Delegate<RESULT_FROM(ARGS_FROM...)>, SAFE>
{
	static constexpr Bool value = GenericCastMemberTrait<RESULT_TO, RESULT_FROM, SAFE>::value && GenericCastMemberTrait<ParameterPack<ARGS_FROM...>, ParameterPack<ARGS_TO...>, SAFE>::value;
};

} // namespace maxon

#endif // DELEGATE_H__
