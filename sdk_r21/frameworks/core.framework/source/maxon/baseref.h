#ifndef BASEREF_H__
#define BASEREF_H__

#include "maxon/apibase.h"
#include "maxon/atomictypes.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(push)
	#pragma warning(disable:4180) // applying const to a function type generates this warning as this has no meaning; but BaseRef will do so if T is a function type
#endif

// Weak references
struct WeakRefBase;
template <typename REFERENCE> class WeakRef;

// Memory management
namespace details
{
template <typename T> StrongReferenceCounter& PrivateGetReferenceCounter(const T* obj);
template <typename T> void PrivateFreeWithDestructor(const T* obj);
void PrivateAddWeakReference(WeakRefBase& weakRef, const void* target);
template <typename T, typename... ARGS> inline ResultPtr<T> NewObjWithLocation(MAXON_SOURCE_LOCATION_DECLARATION, ARGS&&... args);
}



//----------------------------------------------------------------------------------------
/// This is a general template for references of any kind. The characteristic feature
/// of it is that special actions are triggered whenever the reference is set, cleared, changed or destructed.
/// For example, a reference to a reference-counted object has to increase the reference count of the pointee
/// when the pointer is set, and to decrease the count when the reference is cleared. Another example of reference
/// is a unique reference which simply frees the pointee when it is cleared or destructed.
///
/// BaseRef delegates the specific behaviour to static members of the template parameter HANDLER. There are several
/// implementations available to be used as HANDLER:
/// - StrongRefHandler is used for objects which have a reference counter (used by StrongRef).
/// - StrongCOWRefHandler has an additional copy-on-write semantics. I.e., if the pointee is referenced more than once,
///   a copy is made before the pointee is modified through the BaseRef (used by StrongCOWRef).
/// - UniqueRefHandler uses DeleteObj to release the memory, so the object's destructor is invoked (used by UniqueRef).
/// - PointerHandler lets the BaseRef behave like an ordinary C++ pointer, so nothing is done when the pointer is changed (used by Pointer).
///
/// So if you want to have a reference to an object of type MyType with reference counting and copy-on-write semantics,
/// you could use BaseRef<MyType, StrongCOWRefHandler> which is equivalent to StrongCOWRef<MyType>.
///
/// @tparam T											Type of the referenced object.
/// @tparam HANDLER								Base class for BaseRef. This implements the specific behaviour whenever a reference is changed to point to another object, see above.
///
/// @note <B>BaseRef is neither atomic nor thread-safe.</B>.
/// - After a BaseRef is guaranteed not to change anymore multiple threads can safely read from it concurrently.
/// - Reading and writing on the same BaseRef from different threads will <B>crash</B> (the reference to an object might
/// have been released by a writing thread before a reading thread was able to add a reference).
/// - Writing to the same BaseRef from different threads will also <B>crash</B> because this implies a read operation
/// (a write has to read the old value to release the reference to the previous object).
/// - If you really have to read and write from multiple threads you could use the ThreadSafeRef class.
//----------------------------------------------------------------------------------------
template <typename T, typename HANDLER> class BaseRef
{
public:
	//----------------------------------------------------------------------------------------
	/// A type alias for the type the BaseRef points to.
	//----------------------------------------------------------------------------------------
	using ReferencedType = T;
	using ConstReferencedType = typename ConstIf<T, Bool(HANDLER::KIND & VALUEKIND::DEEP_CONSTNESS)>::type;
	using DirectlyReferencedType = T;
	using SelfType = BaseRef<T, HANDLER>;
	static const Bool DIRECT_REF = true;

	template <typename D> using IsGenericBaseOf = std::true_type;
	static std::false_type GenericVarianceCheck(const void*);

	using Handler = HANDLER;

	//----------------------------------------------------------------------------------------
	/// Returns the internal pointer of the BaseRef. You can also use operator-> to access members of the pointee directly through the BaseRef.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	T* GetPointer() { return _object; }

	//----------------------------------------------------------------------------------------
	/// Returns the internal pointer of the BaseRef. You can also use operator-> to access members of the pointee directly through the BaseRef.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	ConstReferencedType* GetPointer() const { return _object; }

	//----------------------------------------------------------------------------------------
	/// Allows direct access to the members of the pointee. You have to check for a nullptr before.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	T* operator ->() { return _object; }

	//----------------------------------------------------------------------------------------
	/// Allows direct access to the members of the pointee. You have to check for a nullptr before.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	ConstReferencedType* operator ->() const { return _object; }

	//----------------------------------------------------------------------------------------
	/// Dereferences the BaseRef. This yields the pointee as a reference. You have to check for a nullptr before.
	/// @return												Pointee as a reference.
	//----------------------------------------------------------------------------------------
	T& operator *() { return *_object; }

	//----------------------------------------------------------------------------------------
	/// Dereferences the BaseRef. This yields the pointee as a reference. You have to check for a nullptr before.
	/// @return												Pointee as a reference.
	//----------------------------------------------------------------------------------------
	ConstReferencedType& operator *() const { return *_object; }

	//----------------------------------------------------------------------------------------
	/// User-defined conversion to T*, unpacking the internal pointer.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	operator T*() { return _object; }

	//----------------------------------------------------------------------------------------
	/// User-defined conversion to T*, unpacking the internal pointer.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	operator ConstReferencedType*() const { return _object; }

	//----------------------------------------------------------------------------------------
	/// Checks if the pointer is valid (i.e., not a nullptr).
	/// @return												True if the internal pointer is not a nullptr.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const { return _object != nullptr; }

	explicit operator Bool() { return _object != nullptr; }

	//----------------------------------------------------------------------------------------
	/// Makes the pointee writable. Depending on the argument for the template parameter HANDLER, this may just return the original pointer,
	/// or it may replace the pointer by a new one pointing to a copy of the original pointee, and return the new pointer. The latter
	/// is the case for copy-on-write semantics if there is more than one reference to the pointee.
	/// @param[in] resetOnError				If true (the default), the reference will be reset when the copy fails. If false, the reference will stay the same, but the function returns nullptr.
	/// @return												Internal pointer, which might be a new pointer pointing to a copy of the original pointee, or nullptr if the copy failed.
	//----------------------------------------------------------------------------------------
	ResultRef<typename std::remove_const<T>::type> MakeWritable(Bool resetOnError = true)
	{
		return HANDLER::MakeWritable(*this, resetOnError);
	}

	T& GetOrNull() const
	{
		static_assert(MAXON_IS_COW_KIND(HANDLER::KIND), "GetOrNull is only supported for copy-on-write references.");
		return _object ? *_object : maxon::NullValue<const T&>();
	}

	BaseRef() : _object(nullptr)
	{
	}

	MAXON_IMPLICIT BaseRef(std::nullptr_t) = delete;

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseRef, initializing the pointer with the given argument.
	/// @param[in] o									Pointer with which the BaseRef is initialized, may be nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT BaseRef(T* o) : _object(o)
	{
		if (_object)
			HANDLER::AddReference(_object);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseRef with a pointer forwarded from a memory allocation. The template 
	/// parameter is used to avoid unnecessary conversion from ResultPtr<X> to ResultPtr<const X>.
	/// @param[in] o									Pointer with which the BaseRef is initialized, may be nullptr on OutOfMemory.
	//----------------------------------------------------------------------------------------
	template <typename PTR> explicit BaseRef(ForwardResultPtr<PTR> o) : _object(o.GetPointer())
	{
		if (_object)
			HANDLER::InitialReference(_object);
	}	

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseRef with a pointer forwarded from a memory allocation. To prevent 
	/// accidental assignment from an allocation without error handling a dummy parameter has
	/// to be passed as well.
	/// @param[in] o									Pointer with which the BaseRef is initialized, may be nullptr on OutOfMemory.
	//----------------------------------------------------------------------------------------
	explicit BaseRef(ResultPtr<T> o, Int) : _object(o.GetPointer())
	{
		if (_object)
			HANDLER::InitialReference(_object);
	}	

	//----------------------------------------------------------------------------------------
	/// Creates the referenced type.
	/// @param[in] args								Arguments for the construcor.
	/// @tparam ARGS									Parameter types.
	/// @return												OK on success, FAILED only for OutOfMemoryerror.
	//----------------------------------------------------------------------------------------
	template <typename... ARGS> static MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<BaseRef> Create(ARGS&&... args)
	{
		// We force inlining so that MAXON_SOURCE_LOCATION is more likely to use the current g_translationUnit.
		return BaseRef(maxon::details::NewObjWithLocation<T>(MAXON_SOURCE_LOCATION, std::forward<ARGS>(args)...), 0);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseRef, initializing the pointer with the pointer of another BaseRef.
	/// @param[in] src								Another BaseRef whose internal pointer will be used to initialize this BaseRef.
	//----------------------------------------------------------------------------------------
	BaseRef(const BaseRef& src) : _object(src._object)
	{
		static_assert(!(HANDLER::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(HANDLER::KIND & VALUEKIND::DEEP_CONSTNESS), "Can't copy a BaseRef with deep constness.");
		if (_object)
			HANDLER::AddReference(_object);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseRef, initializing the pointer with the pointer of another reference object.
	/// @param[in] src								A reference object whose internal pointer will be used to initialize this BaseRef.
	//----------------------------------------------------------------------------------------
	template <typename REF, typename = typename std::enable_if<!std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> MAXON_IMPLICIT BaseRef(const REF& src) : _object(maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer()))
	{
		static_assert(!(HANDLER::KIND & REF::Handler::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::UNIQUE_REFERENCE) && ((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::STRONG_MASK)),
									"Can't copy a BaseRef between unique and strong ownership.");
		if (_object)
			HANDLER::AddReference(_object);
	}

	// We have to repeat the constructor for the case of a non-const REF with deep constness (because then the referenced type of a const REF is const).
	// We could also use a universal reference REF&& here to cover all cases, but the handling of move and copy case differs too much so the duplication is easier.
	template <typename REF, typename = typename std::enable_if<!std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> MAXON_IMPLICIT BaseRef(REF& src) : _object(maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer()))
	{
		static_assert(!(HANDLER::KIND & REF::Handler::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::UNIQUE_REFERENCE) && ((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::STRONG_MASK)),
									"Can't copy a BaseRef between unique and strong ownership.");
		if (_object)
			HANDLER::AddReference(_object);
	}

	//----------------------------------------------------------------------------------------
	/// Lets the BaseRef point to another object. This performs the necessary operations for removing the reference to the
	/// current pointee and adding the reference to the new pointee.
	/// @param[in] src								New pointer, may be nullptr.
	//----------------------------------------------------------------------------------------
	BaseRef& operator =(T* src)
	{
		if (src != _object)
		{
			HANDLER::ChangeTarget(_object, src);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the internal pointer to nullptr, which includes the proper release of the reference.
	//----------------------------------------------------------------------------------------
	BaseRef& operator =(std::nullptr_t src)
	{
		HANDLER::ChangeTarget(_object, (T*)0);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Lets the BaseRef point to the object of another BaseRef. This performs the necessary operations for removing the reference to the
	/// current pointee and adding the reference to the new pointee.
	/// @param[in] src								BaseRef of which the pointer will be used.
	//----------------------------------------------------------------------------------------
	BaseRef& operator =(const BaseRef& src)
	{
		static_assert(!(HANDLER::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(HANDLER::KIND & VALUEKIND::DEEP_CONSTNESS), "Can't copy a BaseRef with deep constness.");
		return this->operator =(src._object);
	}

	//----------------------------------------------------------------------------------------
	/// Lets the BaseRef point to the object of another reference object. This performs the necessary operations for removing the reference to the
	/// current pointee and adding the reference to the new pointee.
	/// @param[in] src								Another reference of which the pointer will be used.
	//----------------------------------------------------------------------------------------
	template <typename REF, typename = typename std::enable_if<!std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> BaseRef& operator =(const REF& src)
	{
		static_assert(!(HANDLER::KIND & REF::Handler::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::UNIQUE_REFERENCE) && ((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::STRONG_MASK)),
									"Can't copy a BaseRef between unique and strong ownership.");
		return this->operator =(maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer()));
	}

	// Duplication for non-const REF, see above for the constructor.
	template <typename REF, typename = typename std::enable_if<!std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> BaseRef& operator =(REF& src)
	{
		static_assert(!(HANDLER::KIND & REF::Handler::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a BaseRef with unique ownership.");
		static_assert(!(((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::UNIQUE_REFERENCE) && ((HANDLER::KIND | REF::Handler::KIND) & VALUEKIND::STRONG_MASK)),
									"Can't copy a BaseRef between unique and strong ownership.");
		return this->operator =(maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer()));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new BaseRef by moving the pointer from src to this. The pointer of src will be a nullptr afterwards.
	/// @param[in] src								Another BaseRef for the move.
	//----------------------------------------------------------------------------------------
	BaseRef(BaseRef&& src) : _object(src._object)
	{
		src._object = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new BaseRef by moving the pointer from src to this. The pointer of src will be a nullptr afterwards.
	/// @param[in] src								Another BaseRef for the move.
	//----------------------------------------------------------------------------------------
	template <typename REF, typename = typename std::enable_if<!std::is_const<REF>::value && !std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> MAXON_IMPLICIT BaseRef(REF&& src) : _object(maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer()))
	{
		// Note that the REF&& of this constructor isn't used as universal reference because REF::ReferencedType fails when REF is a C++ reference type.
		static_assert(!(REF::Handler::KIND & VALUEKIND::STRONG_MASK) || (HANDLER::KIND & VALUEKIND::STRONG_MASK), "Can't move a strong BaseRef to a non-strong BaseRef.");
		static_assert(GetDirectlyReferencedType<REF>::value, "Only direct references can be moved."); // Otherwise the following cast of src to BaseRef would be invalid.
		reinterpret_cast<BaseRef&>(src)._object = nullptr;

		// Only add a reference if the source object did not yet.
		if (_object && !(REF::Handler::KIND & VALUEKIND::STRONG_MASK))
			HANDLER::AddReference(_object);
	}

	//----------------------------------------------------------------------------------------
	/// Moves the internal pointer from src to this. src will be a nullptr reference afterwards.
	/// @param[in] src								BaseRef whose internal pointer shall be moved to this BaseRef.
	//----------------------------------------------------------------------------------------
	BaseRef& operator =(BaseRef&& src)
	{
		if (this != &src)
			HANDLER::MoveTarget(src._object, _object);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Moves the internal pointer from src to this. src will be a nullptr reference afterwards.
	/// Moves from BaseRef with different HANDLER as well as interface references.
	/// @param[in] src								BaseRef whose internal pointer shall be moved to this BaseRef.
	//----------------------------------------------------------------------------------------
	template <typename REF, typename = typename std::enable_if<!std::is_const<REF>::value && !std::is_base_of<BaseRef, REF>::value && maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::value>::type> BaseRef& operator =(REF&& src)
	{
		// Note: REF&& is no universal reference, see above for the constructor.
		static_assert(!(REF::Handler::KIND & VALUEKIND::STRONG_MASK) || (HANDLER::KIND & VALUEKIND::STRONG_MASK), "Can't move a strong BaseRef to a non-strong BaseRef.");
		static_assert(GetDirectlyReferencedType<REF>::value, "Only direct references can be moved."); // Otherwise the following cast of src to BaseRef would be invalid.

		if (_object)
			HANDLER::RemoveReference(_object);

		// Cannot use MoveTarget because src has a different handler and might even be an interface reference
		_object = maxon::HasErasedBase<typename REF::ReferencedType, ReferencedType>::Cast(src.GetPointer());
		reinterpret_cast<BaseRef&>(src)._object = nullptr;

		// Only add a reference if the source object did not yet.
		if (_object && !(REF::Handler::KIND & VALUEKIND::STRONG_MASK))
			HANDLER::AddReference(_object);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Destructs this BaseRef, including proper release of the reference.
	//----------------------------------------------------------------------------------------
	~BaseRef()
	{
		*this = nullptr;
	}

	using RefCompareType = RefCompare<MAXON_IS_COW_KIND(HANDLER::KIND), IsInterfaceType<T>::value>;

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are equal as determined by RefCompare.
	/// @param[in] b									Reference to compare with.
	/// @return												True when this and b are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const BaseRef& b) const { return RefCompareType::IsEqual(_object, b._object); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are not equal as determined by RefCompare.
	/// @param[in] b									Reference to compare with.
	/// @return												True when this and b are not equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const BaseRef& b) const { return !RefCompareType::IsEqual(_object, b._object); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are equal as determined by RefCompare.
	/// @param[in] b									Pointer to compare with.
	/// @return												True when this and b are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const T* b) const { return RefCompareType::IsEqual(_object, b); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are not equal as determined by RefCompare.
	/// @param[in] b									Reference to compare with.
	/// @return												True when this and b are not equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const T* b) const { return !RefCompareType::IsEqual(_object, b); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are equal as determined by RefCompare.
	/// @param[in] b									Pointer to compare with.
	/// @return												True when this and b are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(typename std::remove_const<T>::type* b) const { return RefCompareType::IsEqual(_object, b); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and b are not equal as determined by RefCompare.
	/// @param[in] b									Reference to compare with.
	/// @return												True when this and b are not equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(typename std::remove_const<T>::type* b) const { return !RefCompareType::IsEqual(_object, b); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and a null reference are equal as determined by RefCompare.
	/// @return												True when this and nullptr are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(std::nullptr_t) const { return RefCompareType::IsEqual(_object, nullptr); }

	//----------------------------------------------------------------------------------------
	/// Returns true when this and a null reference are not equal as determined by RefCompare.
	/// @return												True when this and nullptr are not equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(std::nullptr_t) const { return !RefCompareType::IsEqual(_object, nullptr); }

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the reference, see RefCompare.
	/// @return												The reference's hash code.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const { return RefCompareType::GetHashCode(_object); }

	static const BaseRef& NullValue()
	{
		return GetPtrSizedZeroRef<BaseRef>();
	}

	/// Sets the internal pointer to nullptr and returns its previous value. This moves the ownership of the object
	/// from this UniqueRef to the invoking code, so you have to take care of proper deallocation once the object
	/// isn't needed any longer.
	T* Disconnect()
	{
		static_assert(HANDLER::KIND & VALUEKIND::UNIQUE_REFERENCE, "Only supported for UniqueRef.");
		T* o = _object;
		_object = nullptr;
		return o;
	}

	//----------------------------------------------------------------------------------------
	/// Lets the BaseRef point to another freshly allocated object. This performs the necessary operations for removing the reference to the
	/// current pointee and adding the reference to the new pointee.
	/// @param[in] src								New pointer, may be nullptr.
	//----------------------------------------------------------------------------------------
	void PrivateSetTarget(ResultPtr<T> src)
	{
		HANDLER::ChangeTarget(_object, src);
	}

protected:
	T* _object;

	template <typename, typename> friend class BaseRef;

private:
	void operator +(Int) const; void operator -(Int) const; void operator -(const BaseRef&) const; // prevent pointer arithmetic on BaseRef
};

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(pop)
#endif

//----------------------------------------------------------------------------------------
/// PointerHandler has to be used as template argument for BaseRef to obtain a reference with ordinary C++-pointer-like behavior.
/// This means that no actions are performed when references are set or cleared.
/// The easiest way to make use of PointerHandler is to use the Pointer template which is a BaseRef with PointerHandler argument.
//----------------------------------------------------------------------------------------
class PointerHandler
{
public:
	//----------------------------------------------------------------------------------------
	/// Sets the initial reference to a newly allocated object (slightly more efficient than AddReference).
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void InitialReference(const T* o)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Adds a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void AddReference(T* o)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Removes a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void RemoveReference(T* o)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Changes the target of the pointer.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to the new target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, T* newTarget)
	{
		o = newTarget;
	}

	template <typename T> static void ChangeTarget(T*& o, ResultPtr<T> newTarget)
	{
		return ChangeTarget(o, newTarget.GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Moves a target from one pointer to another.
	/// @param[in] srcReference				Reference to the source object pointer.
	/// @param[in] dstReference				Reference to the destination object pointer.
	//----------------------------------------------------------------------------------------
	template <typename T> static void MoveTarget(T*& srcReference, T*& dstReference)
	{
		dstReference = srcReference;
		srcReference = nullptr;
	}

	template <typename R> static ResultRef<typename R::ReferencedType> MakeWritable(R& ref, Bool resetOnError) { return ref.GetPointer(); }

	static const VALUEKIND KIND = VALUEKIND::POINTER_FLAGS;
};


//----------------------------------------------------------------------------------------
/// The Pointer template behaves almost identical to an ordinary C++ pointer, with the exception that the default constructor
/// automatically initializes the pointer with nullptr, and the destructor automatically resets the pointer to nullptr.
/// Pointer is a template based on BaseRef with PointerHandler as template argument. As such, you can also use the helper methods
/// of BaseRef for object creation, movement etc.
//----------------------------------------------------------------------------------------
template <typename T> using Pointer = BaseRef<T, PointerHandler>;



//----------------------------------------------------------------------------------------
/// StrongRefHandler has to be used as template argument for BaseRef to obtain a reference to objects which support reference counting.
/// Whenever the pointer of such a BaseRef is set, the reference count of the pointee is increased by invocation of
/// AddReference() on the pointee. If a pointer is cleared, the reference count of the pointee is decreased by means of RemoveReference().
/// If the reference count reaches zero, the pointee releases itself.
//----------------------------------------------------------------------------------------
class StrongRefHandler
{
	// Member detection based on a proposal for C++17 (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf) fails with MSVC.
	// Therefore disable the warning MSVC gives for the old detector
	#ifdef MAXON_COMPILER_MSVC
		MAXON_WARNING_PUSH
		#pragma warning(disable:4624)	// disable false warning 'destructor was implicitely defined as deleted'
	#endif

	MAXON_MEMBERFUNCTION_DETECTOR(InitialReference);
	MAXON_MEMBERFUNCTION_DETECTOR(AddReference);
	MAXON_MEMBERFUNCTION_DETECTOR(RemoveReference);

	#ifdef MAXON_COMPILER_MSVC
		MAXON_WARNING_POP
	#endif

public:
	//----------------------------------------------------------------------------------------
	/// Sets the initial reference to a newly allocated object (slightly more efficient than AddReference).
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void InitialReference(const T* o)
	{
		InitialReferenceImpl(o, (typename HasInitialReference<T>::type*) nullptr);
	}
	
	//----------------------------------------------------------------------------------------
	/// Adds a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void AddReference(const T* o)
	{
		AddReferenceImpl(o, (typename HasAddReference<T>::type*) nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Removes a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_ATTRIBUTE_NO_INLINE static void RemoveReference(const T* o)
	{
		RemoveReferenceImpl(o, (typename HasRemoveReference<T>::type*) nullptr);
	}

	template <typename T> static void AddWeakReference(const T* o, WeakRefBase& weakRef)
	{
		AddWeakReferenceImpl(o, weakRef, (typename HasAddReference<T>::type*) nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Tries to add a strong reference. If the object is already being released this will
	/// return false.
	/// @param[in] o									Weakly referenced object (might be nullptr).
	/// @return												True if a strong reference could be added.
	//----------------------------------------------------------------------------------------
	template <typename T> static Bool CreateStrongReference(const T* o)
	{
		return CreateStrongReferenceImpl(o, (typename HasAddReference<T>::type*) nullptr);
	}

	template <typename T> static StrongReferenceCounter& GetReferenceCounter(const T* o)
	{
		return GetReferenceCounterImpl(o, (typename HasAddReference<T>::type*) nullptr);
	}

	template <typename R> static ResultRef<typename R::ReferencedType> MakeWritable(R& ref, Bool resetOnError) { return ref.GetPointer(); }

	//----------------------------------------------------------------------------------------
	/// Changes the target of the reference (removes it from the old target and adds it to the new one).
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to the new target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, T* newTarget)
	{
		T* old = o;

		if (newTarget)
			AddReference(newTarget);

		o = newTarget;

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Changes the target of the reference to a yet unreferenced object.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to a just allocated unreferenced target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, ResultMemT<T*> newTarget)
	{
		T* old = o;
		T* newPtr = newTarget.GetPointer();

		if (MAXON_LIKELY(newPtr != nullptr))
		{
			DebugAssert(GetReferenceCounter(newPtr) == 0, "Only for freshly allocated objects, not already referenced objects.");
			InitialReference(newPtr);
		}

		o = newPtr;

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Moves a target from one BaseRef to another.
	/// This is being called when a BaseRef is moved to another BaseRef using operator =(&&).
	/// @param[in] srcReference				Reference to the source object pointer.
	/// @param[in] dstReference				Reference to the destination object pointer.
	//----------------------------------------------------------------------------------------
	template <typename T> static void MoveTarget(T*& srcReference, T*& dstReference)
	{
		T* target = srcReference;
		T* oldTarget = dstReference;

		srcReference = nullptr;
		dstReference = target;

		// Remove reference to the old target of the destination.
		if (oldTarget)
			RemoveReference(oldTarget);
	}

	static const VALUEKIND KIND = Or<VALUEKIND, VALUEKIND::STRONG_REFERENCE, VALUEKIND::INT_SIZE_OR_LESS, VALUEKIND::ZERO_INITIALIZED, VALUEKIND::TRIVIALLY_EQUATABLE, VALUEKIND::REF_OR_POINTER>::value;

private:

	template <typename T> static void InitialReferenceImpl(const T* obj, std::false_type*)
	{
		maxon::details::PrivateGetReferenceCounter(obj).SetRelaxed(1);
	}

	template <typename T> static void InitialReferenceImpl(const T* obj, std::true_type*)
	{
		obj->InitialReference();
	}

	template <typename T> static void AddReferenceImpl(const T* obj, std::false_type*)
	{
		maxon::details::PrivateGetReferenceCounter(obj).Inc();
	}

	template <typename T> static void AddReferenceImpl(const T* obj, std::true_type*)
	{
		obj->AddReference();
	}

	template <typename T> static void RemoveReferenceImpl(const T* obj, std::false_type*)
	{
		if (maxon::details::PrivateGetReferenceCounter(obj).Dec())
			maxon::details::PrivateFreeWithDestructor(obj);
	}

	template <typename T> static void RemoveReferenceImpl(const T* obj, std::true_type*)
	{
		obj->RemoveReference();
	}

	template <typename T> static Bool CreateStrongReferenceImpl(const T* obj, std::false_type*)
	{
		return maxon::details::PrivateGetReferenceCounter(obj).ConditionalInc();
	}

	template <typename T> static Bool CreateStrongReferenceImpl(const T* obj, std::true_type*)
	{
		return obj->CreateStrongReference();
	}

	template <typename T> static void AddWeakReferenceImpl(const T* obj, WeakRefBase& weakRef, std::false_type*)
	{
		maxon::details::PrivateAddWeakReference(weakRef, obj);
	}

	template <typename T> static void AddWeakReferenceImpl(const T* obj, WeakRefBase& weakRef, std::true_type*)
	{
		obj->AddWeakReference(weakRef);
	}

	template <typename T> static StrongReferenceCounter& GetReferenceCounterImpl(const T* obj, std::false_type*)
	{
		return maxon::details::PrivateGetReferenceCounter(obj);
	}

	template <typename T> static StrongReferenceCounter& GetReferenceCounterImpl(const T* obj, std::true_type*)
	{
		return obj->GetReferenceCounter();
	}

};


// TODO: (Ole) improve the following during the Create refactoring
template <typename T> inline T* PrivateInitCopy(void* ptr, const T& src)
{
	if (!ptr)
		return nullptr;
	T* t = (T*) ptr;
	if (NewCopy(*t, src) == FAILED)
		DeleteObj(t);
	return t;
}

#define NewObjCopy(T, SRC) (maxon::details::NewDelete<T>::IS_ALLOC_TYPE ? maxon::details::NewDelete<T>::Cast(maxon::details::NewDelete<T>::AllocType::Alloc(maxon::SourceLocation(__FILE__, __LINE__, maxon::PrivateGetClassName<T>()), SRC)) \
														: ResultPtr<T>((T*) PrivateInitCopy(maxon::details::NewDelete<T>::AllocatorType::Alloc(maxon::details::NewDelete<T>::SIZE, maxon::SourceLocation(__FILE__, __LINE__, maxon::PrivateGetClassName<T>())), reinterpret_cast<const PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewDelete<T>::ConstructorType&>(SRC))))

//----------------------------------------------------------------------------------------
/// StrongCOWRefHandler has to be used as template argument for BaseRef to obtain a reference to objects which support reference counting,
/// and which shall have copy-on-write semantics. It shares the basic behavior of StrongRefHandler,
/// but if a modification of the object is to be made through the reference, or if BaseRef::MakeWritable() is invoked,
/// it is checked by invocation of GetReferenceCount() on the object if the reference is exclusive or not. If so,
/// the object can be modified directly, otherwise a copy is made and set as new pointee of the reference. This way the other
/// references to the original object aren't affected by the modification.
/// If the allocation of a copy fails the reference will be set to null.
//----------------------------------------------------------------------------------------
class StrongCOWRefHandler : public StrongRefHandler
{
public:
	static const VALUEKIND KIND = VALUEKIND::COW_REFERENCE | VALUEKIND::INT_SIZE_OR_LESS | VALUEKIND::ZERO_INITIALIZED | VALUEKIND::REF_OR_POINTER | VALUEKIND::VALUE;

	//----------------------------------------------------------------------------------------
	/// @param[in] resetOnError				If true (the default), the reference will be reset when the copy fails. If false, the reference will stay the same, but the function returns nullptr.
	//----------------------------------------------------------------------------------------
	template <typename R> MAXON_ATTRIBUTE_NO_INLINE static ResultRef<typename std::remove_const<typename R::ReferencedType>::type> MakeWritable(R& ref, Bool resetOnError)
	{
		using NonConstT = typename std::remove_const<typename R::ReferencedType>::type;
		NonConstT* o = const_cast<NonConstT*>(ref.GetPointer());
		if (MAXON_UNLIKELY(o == nullptr))
			o = NewObj(NonConstT).GetPointer();
		else if (MAXON_UNLIKELY(GetReferenceCounter(o).HasMultipleReferences()))
			o = NewObjCopy(NonConstT, *o).GetPointer();
		else
			return o;
		if (MAXON_LIKELY(resetOnError || o))
			ref.PrivateSetTarget(ResultPtr<typename R::ReferencedType>(o));
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};

//----------------------------------------------------------------------------------------
/// StrongACOWRefHandler has to be used as template argument for BaseRef to obtain a reference to objects which support reference counting,
/// and which shall have always-copy-on-write semantics. This is similar to the copy-on-write semantics of StrongCOWRefHandler,
/// but it also makes a copy if the reference to the pointee is exclusive.
/// If the allocation of a copy fails the reference will be set to null.
//----------------------------------------------------------------------------------------
class StrongACOWRefHandler : public StrongRefHandler
{
public:
	static const VALUEKIND KIND = (StrongCOWRefHandler::KIND & ~VALUEKIND::COW_REFERENCE) | VALUEKIND::ACOW_REFERENCE;

	//----------------------------------------------------------------------------------------
	/// @param[in] resetOnError				If true (the default), the reference will be reset when the copy fails. If false, the reference will stay the same, but the function returns nullptr.
	//----------------------------------------------------------------------------------------
	template <typename R> MAXON_ATTRIBUTE_NO_INLINE static ResultRef<typename std::remove_const<typename R::ReferencedType>::type> MakeWritable(R& ref, Bool resetOnError)
	{
		using NonConstT = typename std::remove_const<typename R::ReferencedType>::type;
		NonConstT* o = nullptr;
		if (MAXON_UNLIKELY(!ref.GetPointer()))
			o = NewObj(NonConstT).GetPointer();
		else
			o = NewObjCopy(NonConstT, *ref.GetPointer()).GetPointer();
		if (resetOnError || o)
			ref = o;
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};

/// UniqueRefHandler can be used as template argument for BaseRef to obtain a reference to an object which exclusively owns
/// the object and, thus, deletes it on destruction or reset.
/// The easiest way to make use of UniqueRefHandler is to use the UniqueRef template which is a BaseRef with UniqueRefHandler argument.
class UniqueRefHandler
{
public:
	static const VALUEKIND KIND = Or<VALUEKIND, VALUEKIND::UNIQUE_REFERENCE, VALUEKIND::TRIVIALLY_EQUATABLE, VALUEKIND::INT_SIZE_OR_LESS, VALUEKIND::ZERO_INITIALIZED, VALUEKIND::REF_OR_POINTER, VALUEKIND::DEEP_CONSTNESS>::value;

	template <typename T> static void InitialReference(const T* o) { }

	template <typename T> static void AddReference(const T* o) { }

	template <typename T> static void RemoveReference(const T* o);

	template <typename T> static void AddWeakReference(const T* o, WeakRefBase& weakRef) { maxon::details::PrivateAddWeakReference(weakRef, o); }

	template <typename T> static void ChangeTarget(T*& o, T* n)
	{
		T* old = o;

		if (n)
			AddReference(n);

		o = n;

		if (old)
			RemoveReference(old);
	}

	template <typename T> static void ChangeTarget(T*& o, ResultPtr<T> newTarget)
	{
		return ChangeTarget(o, newTarget.GetPointer());
	}

	template <typename T> static void MoveTarget(T*& srcReference, T*& dstReference)
	{
		RemoveReference(dstReference);
		dstReference = srcReference;
		srcReference = nullptr;
	}

	template <typename R> static ResultRef<typename R::ReferencedType> MakeWritable(R& ref, Bool resetOnError) { return ref.GetPointer(); }
};

//----------------------------------------------------------------------------------------
/// The UniqueRef template stores a pointer to an object (usually obtained by NewObj()), and it automatically deletes the object on destruction or reset
/// by means of DeleteObj().
/// So you don't have to take care of the rather error-prone manual deleting of objects. Note that this behavior
/// means that UniqueRef has the sole ownership on the object. You cannot have more than one UniqueRef pointing to the same Object.
/// UniqueRef is a template based on BaseRef with UniqueRefHandler as template argument. As such, you can also use the helper methods
/// of BaseRef for object creation, movement etc.
///
/// @tparam T											Type of the object the UniqueRef points to.
//----------------------------------------------------------------------------------------
template <typename T> using UniqueRef = BaseRef<T, UniqueRefHandler>;

//----------------------------------------------------------------------------------------
/// A StrongReference can point to a target object and ensures that the target object exists
/// as long as there are strong references to it. As soon as there are no more strong
/// references pointing to it the target object will be destructed.
///
/// @tparam T											Type of the target object for the strong reference.
///
/// @note The strong reference is implemented via a BaseRef.
//----------------------------------------------------------------------------------------
template <typename T> using StrongRef = BaseRef<T, StrongRefHandler>;

//----------------------------------------------------------------------------------------
/// A StrongCOWRef shares the basic behaviour of a StrongReference, but it supports
/// copy-on-write semantics: If a modification of the object is to be made through the reference
/// or if MakeWritable() is invoked, a copy of the object is made unless the reference is
/// exclusive. This ensures that other COW references to the object aren't affected by the
/// modification. If the allocation of a copy fails the reference will be set to null.
///
/// @tparam T											Type of the target object for the strong reference.
///
/// @note The strong reference is implemented via a BaseRef.
//----------------------------------------------------------------------------------------
template <typename T> using StrongCOWRef = BaseRef<const T, StrongCOWRefHandler>;

template <typename T> struct RawMem { };

template <typename T, typename H>  class BaseRef<RawMem<T>, H>
{
public:
	using ReferencedType = RawMem<T>;
	using Handler = H;

	BaseRef() { }
	MAXON_IMPLICIT BaseRef(T* m) : _mem(m)
	{
		H::AddReference(_mem);
	}
	template <typename X> BaseRef(BaseRef<X, UniqueRefHandler>&& src) : _mem(src.Disconnect())
	{
		H::AddReference(_mem);
	}
	BaseRef(BaseRef&& src) : _mem(src._mem)
	{
		src._mem = nullptr;
	}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BaseRef);
	BaseRef(const BaseRef&) = delete;
	~BaseRef()
	{
		if (_mem)
			H::RemoveReference(_mem);
	}
	BaseRef& operator =(T* src)
	{
		if (src != _mem)
			H::ChangeTarget(*(RawMem<T>**)&_mem, (RawMem<T>*) src);
		return *this;
	}
	BaseRef& operator =(std::nullptr_t src) { return this->operator =((T*) nullptr); }
	static ResultMemT<BaseRef> Create(Int cnt);

	T* GetPointer() { return _mem; }
	const T* GetPointer() const { return _mem; }
	operator T*() { return _mem; }
	operator const T*() const { return _mem; }
	T* operator ->() { return _mem; }
	const T* operator ->() const { return _mem; }
	T* Disconnect() { T* o = _mem; _mem = nullptr; return o; }
private:
	T* _mem = nullptr;
};

template <typename T> using AutoMem = UniqueRef<RawMem<T>>;

/// @}

} // namespace maxon


#endif // BASEREF_H__
