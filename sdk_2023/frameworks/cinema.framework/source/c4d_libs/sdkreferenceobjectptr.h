#ifdef REFERENCEOBJECTPTR_H__

#define SDKReferenceObjectPtr		ReferenceObjectPtr

#else

#ifndef SDKREFERENCEOBJECTPTR_H__
#define SDKREFERENCEOBJECTPTR_H__

#include <stddef.h>

//----------------------------------------------------------------------------------------
/// Base class for the SDKReferenceObjectPtr class. Holds the interface pointer.
//----------------------------------------------------------------------------------------
class SDKReferenceObjectBasePtr
{
protected:
	SDKReferenceObject	*itf;			///< The interface pointer.
};


//----------------------------------------------------------------------------------------
/// Reference Object Pointer template for automatic destruction of unused objects.
/// @note Simultaneous access to a SDKReferenceObjectPtr from different threads must be synchronized because the assignment operators are not atomic.
//----------------------------------------------------------------------------------------
template <class ObjectInterface> class SDKReferenceObjectPtr : public SDKReferenceObjectBasePtr
{
public:

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr()
	{
		itf = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Constructs a reference object with reference data from an existing object.
	/// @param[in] src								The source reference object containing an interface pointer.
	//----------------------------------------------------------------------------------------
	inline SDKReferenceObjectPtr(const SDKReferenceObjectPtr &src)
	{
		if (src.itf)
			src.itf->add_reference();					// There is an additional reference to the interface
		itf = src.itf;											// Get pointer
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Constructs a reference object with reference data from an existing object.
	/// @note This constructor is for assignment from a different type of SDKReferenceObjectPtr without use of additional pointer casts
	/// @param[in] src								The source reference object (of a different type) containing an interface pointer.
	//----------------------------------------------------------------------------------------
	inline SDKReferenceObjectPtr(const SDKReferenceObjectBasePtr &src)
	{
		if (((SDKReferenceObjectPtr&) src).itf)
			((SDKReferenceObjectPtr&) src).itf->add_reference();					// There is an additional reference to the interface
		itf = ((SDKReferenceObjectPtr&) src).itf;												// Get pointer
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a @formatConstant{nullptr} interface.
	/// @param[in] zero								Pass @em 0.
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr(int zero)
	{
		itf = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a reference object with an interface/class pointer.
	/// @param[in] src_itf						The interface/class pointer.
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr(const ObjectInterface *src_itf)
	{
		if (src_itf)
			((ObjectInterface *) src_itf)->add_reference();				// There is an additional reference to the interface

		itf = (ObjectInterface *) src_itf;
	}

	//----------------------------------------------------------------------------------------
	/// Destructs the reference object, removes reference to the interface.
	//----------------------------------------------------------------------------------------
	~SDKReferenceObjectPtr()
	{
		if (itf)
			itf->remove_reference();					// Remove reference to the interface

		itf = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the reference pointer.
	/// @return												The pointer to the interface.
	//----------------------------------------------------------------------------------------
	inline ObjectInterface	*GetPtr(void) const
	{
		return ((ObjectInterface *) itf);
	}

	//----------------------------------------------------------------------------------------
	/// Removes a references.
	/// @param[in] zero								Pass @em 0.
	/// @return												@c *this
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr& operator =(int zero)
	{
		SDKReferenceObject	*old_itf;

		old_itf = itf;
		itf = (ObjectInterface *) 0;						// Assign the new pointer

		if (old_itf)
			old_itf->remove_reference();					// Remove reference to the object

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Assigns a reference to an already initialized reference object.
	/// @param[in] src								A reference object containing an interface pointer.
	/// @return												@c *this
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr& operator =(const SDKReferenceObjectPtr &src)
	{
		SDKReferenceObject	*old_itf;

		old_itf = itf;
		itf = src.itf;													// Assign the new pointer

		if (itf)
			itf->add_reference();									// Add another reference to the new object
		if (old_itf)
			old_itf->remove_reference();					// Remove reference to the previous object

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Assigns a reference to an already initialized reference object.
	/// @note This operator is for assignment from a different type of SDKReferenceObjectPtr without use of additional pointer casts.
	/// @param[in] src								A reference object (of a different type) containing an interface pointer
	/// @return												@c *this
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr&	operator =(const SDKReferenceObjectBasePtr &src)
	{
		SDKReferenceObject	*old_itf;

		old_itf = itf;
		itf = ((SDKReferenceObjectPtr&) src).itf;					// Assign the new pointer

		if (itf)
			itf->add_reference();														// Add another reference to the new object
		if (old_itf)
			old_itf->remove_reference();										// Remove reference to the previous object

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Assigns a reference to an already initialized reference object.
	/// @param[in] src_itf						An interface pointer.
	/// @return												@c *this
	//----------------------------------------------------------------------------------------
	SDKReferenceObjectPtr&	operator =(ObjectInterface *src_itf)
	{
		SDKReferenceObject	*old_itf;

		old_itf = itf;
		itf = src_itf;													// Assign the new pointer

		if (src_itf)
			src_itf->add_reference();							// Add another reference to the new object
		if (old_itf)
			old_itf->remove_reference();					// Remove reference to the previous object

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the reference pointer.
	/// @return												The pointer to the interface.
	//----------------------------------------------------------------------------------------
	inline operator ObjectInterface*(void) const
	{
		return ((ObjectInterface *) itf);
	}

	//----------------------------------------------------------------------------------------
	/// Overrides the @c -> operator. Makes the SDKReferenceObjectPtr looks like a real pointer.
	/// @return												The pointer to the interface.
	//----------------------------------------------------------------------------------------
	inline ObjectInterface	*operator->(void) const
	{
		return ((ObjectInterface *) itf);
	}

	//----------------------------------------------------------------------------------------
	/// Compares the reference and the given object pointer.
	/// @param[in] x									An object pointer.
	/// @return												@trueIfOtherwiseFalse{the reference and the given object pointer are equal}
	//----------------------------------------------------------------------------------------
	inline Bool operator ==(ObjectInterface *x) const
	{
		return ((ObjectInterface *) itf == x);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if an interface has been assigned.
	/// @return												@trueIfOtherwiseFalse{the interface pointer is not @formatConstant{nullptr}}
	//----------------------------------------------------------------------------------------
	inline Bool IsNull(void) const
	{
		return itf == nullptr;
	}
};

#endif // SDKREFERENCEOBJECTPTR_H__

#endif
