#ifndef NODEERRORS_H__
#define NODEERRORS_H__

#include "maxon/objectbase.h"

namespace maxon
{

class AssetLink;
template <typename T>
class Range;

namespace nodes
{
class TemplateArguments MAXON_FORWARD("maxon/nodetemplate.h");

//----------------------------------------------------------------------------------------
/// @brief Base error class for nodes.
/// It overrides the GetMessage and FormatMessage methods to forward the calls to the
/// error's cause if one is exists (since most node error are wrapper classes).
//----------------------------------------------------------------------------------------
class NodeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(NodeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.baseerror", MAXON_IMPLEMENTATION_MODULE("net.maxon.nodes"));

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
protected:

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] msg								Error message.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const String& msg)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetMessage(msg);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const Error& cause)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetCause(cause);
	}

	);	// MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS
};

//----------------------------------------------------------------------------------------
/// Return this error if the template arguments received by a node are not compatible with 
/// what the node expects. This will allow the NodeSystem to keep the node in the graph
/// and make a second pass to reinstantiate the failed node with the proper template arguments.
/// @note Only when the #keepNode flag is true will the erroneous node be kept for a second attempt.
//----------------------------------------------------------------------------------------
class NodeTemplateArgumentErrorInterface : MAXON_INTERFACE_BASES(NodeErrorInterface)
{
	MAXON_INTERFACE(NodeTemplateArgumentErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.templateargumenterror", MAXON_IMPLEMENTATION_MODULE("net.maxon.nodes"));

public:

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(

protected:
	
	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] args								The arguments the led to the error.
	/// @param[in] msg								Detailed error message.
	/// @param[in] keepNode						If false, node insertion is canceled, node is removed from graph.
	///																If true, node will be left in graph with current connections, reinstantiation pass will
	///																take place to select proper template instance.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const TemplateArguments& args, const String& msg, Bool keepNode = false)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetArgs(args);
		e.SetMessage(msg);
		e.SetKeepNode(keepNode);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] args								The arguments the led to the error.
	/// @param[in] keepNode						If false, node insertion is canceled, node is removed from graph.
	///																If true, node will be left in graph with current connections, reinstantiation pass will
	///																take place to select proper template instance.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const TemplateArguments& args, Bool keepNode = false)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetArgs(args);
		e.SetKeepNode(keepNode);
	}

	);

	//----------------------------------------------------------------------------------------
	/// Set arguments that led to the error.
	/// @param[in] args								Arguments to set in the error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetArgs(const TemplateArguments& args);

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding arguments.
	/// @return												The arguments related to this error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const TemplateArguments& GetArgs() const;

	//----------------------------------------------------------------------------------------
	/// Enable flag to maintain the node in the graph for reinstantiation attempt.
	/// @param[in] keepNode						True to keep the erroneous node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetKeepNode(Bool keepNode);

	//----------------------------------------------------------------------------------------
	/// Read keep node flag.
	/// @see SetKeepNode.
	/// @return												True if keep node is active.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetKeepNode() const;

};

//----------------------------------------------------------------------------------------
/// @brief Error used to level up node graph execution errors and messages to the GraphModelInterface level.
/// Can be found on GraphNode where an execution error originated and it's outer groups.
/// Errors and messages of the NodeExecutionError type are accessible through ExecutionError/ExecutionMessage attributes.
/// NodeExecutionError usually wrap a lower level error.
//----------------------------------------------------------------------------------------
class NodeExecutionErrorInterface : MAXON_INTERFACE_BASES(NodeErrorInterface)
{
	MAXON_INTERFACE(NodeExecutionErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.executionerror", MAXON_IMPLEMENTATION_MODULE("net.maxon.nodes"));

public:

	//----------------------------------------------------------------------------------------
	/// @brief Set the frame range to which this error applies.
	/// @param[in] frames							The frame index range (zero based), or just Range{-1} if it applies to all frames.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetFrames(const Range<Int>& frames);

	//----------------------------------------------------------------------------------------
	/// @brief Set the frame to which this error applies.
	/// @param[in] frame							The frame index (zero based).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetFrame(Int frame);

	//----------------------------------------------------------------------------------------
	/// @brief Reads the frames to which this error applies.
	/// @return												The frame indexes.
	//----------------------------------------------------------------------------------------
	// @MAXON_ANNOTATION{default=GetZeroRef<Range<Int>>()}
	MAXON_METHOD const Range<Int>& GetFrames() const;

};

//----------------------------------------------------------------------------------------
/// @brief Return this error during node instantiation if a required asset is missing.
/// Ideally, the error should be given informations on the missing asset for debugging.
//----------------------------------------------------------------------------------------
class MissingNodeAssetErrorInterface : MAXON_INTERFACE_BASES(NodeErrorInterface)
{
	MAXON_INTERFACE(MissingNodeAssetErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.missingasseterror", MAXON_IMPLEMENTATION_MODULE("net.maxon.nodes"));

public:

	/// @brief Returns the missing asset informations.
	MAXON_METHOD const AssetLink& GetAssetLink() const;

	/// @brief Sets the missing asset informations.
	MAXON_METHOD void SetAssetLink(const AssetLink& missingAsset);

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(

protected:

	//----------------------------------------------------------------------------------------
	/// @brief Constructs a new @CLASS for the given source location and arguments.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] missingAsset				The unresolved AssetLink.
	/// @param[in] msg								The custom error message. Optional, one could call SetMessageDelegate instead.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const AssetLink& missingAsset, const String& msg = String{})
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::Get();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetAssetLink(missingAsset);
		e.SetMessage(msg);
	}

	);			// MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS

};

} // namespace nodes

#include "nodeerrors1.hxx"
#include "nodeerrors2.hxx"

} // namespace maxon


#endif // NODEERRORS_H__
