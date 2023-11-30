#ifndef CORENODES_ERRORS_H__
#define CORENODES_ERRORS_H__

#include "maxon/objectbase.h"
#include "maxon/valuereceiver.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This namespace contains the API of the nodes framework.
//----------------------------------------------------------------------------------------
namespace corenodes
{

class CoreNodeGroupRef;
class MicroNodeGroupRef;
class PortId;

using PortError = Tuple<PortId, Error>;						// Partly duplicated from corenodes.h.

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
	/// Not mandatory, it's just to allow supplying two DataType.
	// ---------------------------------------------------------------------
	MAXON_METHOD void	SetTargetDataType(const DataType& type);

	// ---------------------------------------------------------------------
	/// Returns the target DataType.
	/// @see SetTargetDataType.
	// ---------------------------------------------------------------------
	MAXON_METHOD DataType GetTargetDataType() const;

};

//----------------------------------------------------------------------------------------
/// The CoreNodeErrorHelper publishes helper functions to simplify CoreNode error handling.
//----------------------------------------------------------------------------------------
class CoreNodeErrorHelper
{
	MAXON_INTERFACE_NONVIRTUAL(CoreNodeErrorHelper, MAXON_REFERENCE_STATIC, "net.maxon.interface.corenodes.errorhelper");

public:

	//----------------------------------------------------------------------------------------
	/// Adds a new error to the port's error list. Current errors will remain.
	/// @param[in] group							The group which owns the port #portId.
	/// @param[in] portId							The port where to add the error.
	/// @param[in] newError						The error to add.
	/// @return												OK on success. Error result if group or port are not valid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddPortError(const MicroNodeGroupRef& group, const PortId& portId, Error&& newError);

	/// @copydoc AddPortError
	static MAXON_METHOD Result<void> AddPortError(const CoreNodeGroupRef& group, const PortId& portId, Error&& newError);

	//----------------------------------------------------------------------------------------
	/// Sets a new error to the port's error list. Current errors will be lost.
	/// @param[in] group							The group which owns the port #portId.
	/// @param[in] portId							The port where to set the error.
	/// @param[in] newError						The error to set.
	/// @return												OK on success. Error result if group or port are not valid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetPortError(const MicroNodeGroupRef& group, const PortId& portId, Error&& newError);

	/// @copydoc SetPortError
	static MAXON_METHOD Result<void> SetPortError(const CoreNodeGroupRef& group, const PortId& portId, Error&& newError);

	//----------------------------------------------------------------------------------------
	/// Clears the port's error list.
	/// @param[in] group							The group which owns the port #portId.
	/// @param[in] portId							The port where to reset the error list.
	/// @return												OK on success. Error result if group or port are not valid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ResetPortErrors(const MicroNodeGroupRef& group, const PortId& portId);

	/// @copydoc ResetPortErrors
	static MAXON_METHOD Result<void> ResetPortErrors(const CoreNodeGroupRef& group, const PortId& portId);

	//----------------------------------------------------------------------------------------
	/// Reads the port's error list. Those errors make nodes and ports appear with an error state in the node editor.
	/// @param[in] group							The group which owns the port #portId.
	/// @param[in] portId							The port where to read the error list.
	/// @param[out] receiver					A ValueReceiver for the port's errors.
	/// @return												Result of the receiver. Error result if group or port are not valid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> GetPortErrors(const MicroNodeGroupRef& group, const PortId& portId, const ValueReceiver<const PortError&>& receiver);

	/// @copydoc GetPortErrors
	static MAXON_METHOD Result<Bool> GetPortErrors(const CoreNodeGroupRef& group, const PortId& portId, const ValueReceiver<const PortError&>& receiver);

};

} // namespace corenodes

#include "corenodes_errors1.hxx"
#include "corenodes_errors2.hxx"

} // namespace maxon


#endif // CORENODES_ERRORS_H__
