#ifndef CORENODES_ERRORS_H__
#define CORENODES_ERRORS_H__

#include "maxon/objectbase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This namespace contains the API of the nodes framework.
//----------------------------------------------------------------------------------------
namespace corenodes
{

//----------------------------------------------------------------------------------------
/// Interface for corenode construction related errors.
/// You can return these errors from the Init function which sets up a core node.
//----------------------------------------------------------------------------------------
class ConstructionErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ConstructionErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.corenode.constructionerror");
};

//----------------------------------------------------------------------------------------
/// Return this error for port type related error on corenodes.
//----------------------------------------------------------------------------------------
class PortTypeConstructionErrorInterface : MAXON_INTERFACE_BASES(ConstructionErrorInterface)
{
	MAXON_INTERFACE(PortTypeConstructionErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.corenode.porttypeconstructionerror");

public:

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(

protected:
	
	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the location can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] msg								Detailed error message.
	/// @param[in] sourceType					The first DataType related to the error.
	/// @param[in] targetType					The second DataType related to the error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const String& msg, const DataType& sourceType = GetZeroRef<DataType>(), const DataType& targetType = GetZeroRef<DataType>())
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetSourceDataType(sourceType);
		e.SetTargetDataType(targetType);
		e.SetMessage(msg);
	}

	);			// MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS

	// ---------------------------------------------------------------------
	// Set the source DataType or original DataType that caused the error.
	// ---------------------------------------------------------------------
	MAXON_METHOD void	SetSourceDataType(const DataType& type);

	// ---------------------------------------------------------------------
	/// Returns the source DataType.
	/// @see SetSourceDataType.
	// ---------------------------------------------------------------------
	MAXON_METHOD DataType GetSourceDataType() const;

	// ---------------------------------------------------------------------
	/// Set the target DataType or new DataType that caused the error.
	/// Not mandatory, it's just to allow supplying ttwo DataType.
	// ---------------------------------------------------------------------
	MAXON_METHOD void	SetTargetDataType(const DataType& type);

	// ---------------------------------------------------------------------
	/// Returns the target DataType.
	/// @see SetTargetDataType.
	// ---------------------------------------------------------------------
	MAXON_METHOD DataType GetTargetDataType() const;

};

}

#include "corenodes_errors1.hxx"
#include "corenodes_errors2.hxx"

} // namespace maxon


#endif // CORENODES_ERRORS_H__
