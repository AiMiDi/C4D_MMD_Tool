#ifndef NODEERRORS_H__
#define NODEERRORS_H__

#include "maxon/objectbase.h"
#include "maxon/portattributes.h"
#include "maxon/nodetemplate.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This namespace contains the API of the nodes framework.
//----------------------------------------------------------------------------------------
namespace nodes
{

//----------------------------------------------------------------------------------------
/// Error of the node category.
//----------------------------------------------------------------------------------------
class NodeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(NodeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.baseerror");
};

//----------------------------------------------------------------------------------------
/// Return this error if the template arguments received by a node are not compatible with 
/// what the node expects. This will allow the NodeSystem to keep the node in the graph
/// and make a second pass to reinstantiate the failed node with the proper template arguments.
/// @note Only when the #keepNode flag is true will the erroneous node be kept for a second attempt.
//----------------------------------------------------------------------------------------
class NodeTemplateArgumentErrorInterface : MAXON_INTERFACE_BASES(NodeErrorInterface)
{
	MAXON_INTERFACE(NodeTemplateArgumentErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.node.templateargumenterror");

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
	/// @param[in] args								The arguments the led to the error. TemplateArguments will be built from DataDictionary.
	/// @param[in] msg								Detailed error message.
	/// @param[in] keepNode						If false, node insertion is canceled, node is removed from graph.
	///																If true, node will be left in graph with current connections, reinstantiation pass will
	///																take place to select proper template instance.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const DataDictionary& args, const String& msg, Bool keepNode = false)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetArgs(TemplateArguments(args));
		e.SetMessage(msg);
		e.SetKeepNode(keepNode);
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
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
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
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetArgs(args);
		e.SetKeepNode(keepNode);
	}

	);

	//----------------------------------------------------------------------------------------
	/// Set arguments that led to the error.
	/// @param[in] args							Arguments to set in the error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetArgs(const TemplateArguments& args);

		//----------------------------------------------------------------------------------------
	/// Set arguments that led to the error.
	/// @param[in] args							Arguments to set in the error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void SetArgs(const DataDictionary& args)
	{
		SetArgs(TemplateArguments{args});
	}

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding arguments.
	/// @return											The arguments related to this error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const TemplateArguments& GetArgs() const;

	//----------------------------------------------------------------------------------------
	/// Enable flag to maintain the node in the graph for reinstantiation attempt.
	/// @param[in] keepNode					True to keep the erroneous node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetKeepNode(Bool keepNode);

	//----------------------------------------------------------------------------------------
	/// Read keep node flag.
	/// @see SetKeepNode.
	/// @return											True if keep node is active.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetKeepNode() const;

};

}

#include "nodeerrors1.hxx"
#include "nodeerrors2.hxx"

} // namespace maxon


#endif // NODEERRORS_H__
