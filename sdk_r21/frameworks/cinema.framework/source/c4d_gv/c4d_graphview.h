/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_GRAPHVIEW_H__
#define C4D_GRAPHVIEW_H__

#include "maxon/sortedarray.h"
#include "c4d_basebitmap.h"
#include "c4d_basecontainer.h"
#include "c4d_baselist.h"
#include "c4d_customdatatypeplugin.h"
#include "c4d_general.h"
#include "c4d_graphview_def.h"
#include "c4d_gui.h"
#include "c4d_memory.h"
#include "c4d_nodeplugin.h"
#include "c4d_resource.h"
#include "ge_autoptr.h"

class GeDialog;
class GeUserArea;
class BaseBitmap;
class GvNodeMaster;
class GvOperatorData;
class GvNode;
class GvPort;
class GvNodeGUI;
class GvShape;
class GvRun;
class GvCalc;
class GvQuery;
class GvInit;
class GvValue;
class GvWorld;
class GvCalcTable;
class GvCalcTime;
class GvPortList;
struct GvPortListEntry;

struct GvCopyBuffer;
struct OPERATORPLUGIN;

class BaseDrawHelp;


/// @addtogroup group_graphview Graph View
/// @{

//----------------------------------------------------------------------------------------
/// Represents a port entry in GvPortList.
//----------------------------------------------------------------------------------------
struct GvPortListEntry
{
	Int32 id;			///< The port ID.

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] t_id								The initial port ID.
	//----------------------------------------------------------------------------------------
	explicit GvPortListEntry(Int32 t_id) : id(t_id) {}
};

//----------------------------------------------------------------------------------------
/// Manages a list of GvPortListEntry representing ports on a GvNode.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class GvPortList
{
	private:
		GvPortList();
		~GvPortList();

	public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{port list}
	/// @return												@allocReturn{port list}
	//----------------------------------------------------------------------------------------
		static GvPortList* Alloc() { return (GvPortList*)C4DOS.Gv->portlist->Alloc(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{port lists}
	/// @param[in,out] list						@theToDestruct{port lists}
	//----------------------------------------------------------------------------------------
		static void Free(GvPortList* &list) { C4DOS.Gv->portlist->Free((iGvPortList*&)list); }

		/// @}

	/// @name List
	/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the number of port entries.
		/// @return												The number of entries.
		//----------------------------------------------------------------------------------------
		Int32 GetCount(void) const { return (((iGvPortList*)this)->*C4DOS.Gv->portlist->GetCount)(); }

		//----------------------------------------------------------------------------------------
		/// Appends an entry to the end of the list.
		/// @param[in] e									The entry to append. The list takes over the ownership of the pointed entry.
		/// @return												@trueIfOtherwiseFalse{the port was appended}
		//----------------------------------------------------------------------------------------
		Bool Append(GvPortListEntry *e) { return (((iGvPortList*)this)->*C4DOS.Gv->portlist->Append)(e); }

		//----------------------------------------------------------------------------------------
		/// Removes the entry given by @formatParam{e}.
		/// @note @formatParam{e} is compared by pointer, so it must be either the pointer originally given to Append() or one returned from GetIndex().
		/// @param[in] e									The entry to remove. If the removal succeed, the ownership is transfered to the caller.
		/// @return												@trueIfOtherwiseFalse{the entry was found and removed}
		//----------------------------------------------------------------------------------------
		Bool Remove(GvPortListEntry *e) { return (((iGvPortList*)this)->*C4DOS.Gv->portlist->Remove)(e); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an entry by index.
		/// @param[in] i									The entry index: @em 0 <= i < GetCount().
		/// @return												The retrieved entry. @theOwnsPointed{list,entry}
		//----------------------------------------------------------------------------------------
		GvPortListEntry* GetIndex(Int32 i) const { return (((iGvPortList*)this)->*C4DOS.Gv->portlist->GetIndex)(i); }

		//----------------------------------------------------------------------------------------
		/// Clears the list.
		//----------------------------------------------------------------------------------------
		void FlushAll(void) { (((iGvPortList*)this)->*C4DOS.Gv->portlist->FlushAll)(); }

		/// @}
};

//----------------------------------------------------------------------------------------
/// Stores calculation time related information. Cannot be instantiated.
//----------------------------------------------------------------------------------------
class GvCalcTime
{
	private:
		GvCalcTime();
		~GvCalcTime();

	public:
		Bool			init;								///< @formatConstant{true} if this is the first call.
		Bool			init_time;					///< @formatConstant{true} if @ref time == @ref start is reached.
		Bool			time_changed;				///< @formatConstant{true} if @ref time has changed since the previous call.
		Bool			loop_changed;				///< @formatConstant{true} if @ref loop_start or @ref loop_end has changed since the previous call.
		Bool			length_changed;			///< @formatConstant{true} if @ref start or @ref end has changed since the previous call.
		BaseTime	time;								///< Equivalent to BaseDocument::GetTime().
		BaseTime	delta;							///< Delta time since @ref previous.
		BaseTime	start;							///< Equivalent to BaseDocument::GetMinTime().
		BaseTime	end;								///< Equivalent to BaseDocument::GetMaxTime().
		BaseTime	loop_start;					///< Equivalent to BaseDocument::GetLoopMinTime().
		BaseTime	loop_end;						///< Equivalent to BaseDocument::GetLoopMaxTime().
		BaseTime	previous;						///< The time value of the previous call.
		Int32			fps;								///< Equivalent to BaseDocument::GetFps().
};

//----------------------------------------------------------------------------------------
/// Stores information about the current calculation. Cannot be instantiated.
/// Use GvNodeMaster::GetCalc() to get an instance.
//----------------------------------------------------------------------------------------
class GvCalc
{
	private:
		GvCalc();
		~GvCalc();

	public:
		GvCalcTime		time;						///< The calculation time parameters.
		Int32					cpu_count;			///< The CPU count.
		UInt32				flags;					///< The calculation flags: @enumerateEnum{GvCalcFlags}
		BaseDocument*	document;				///< The current document.
		GvNodeMaster*	master;					///< The node master.
		UInt32				counter;				///< The counter. Incremented for each calculation call.
		BaseThread*		thread;					///< The current thread.
};

//----------------------------------------------------------------------------------------
/// Structure for GvNodeMaster::InitCalculation().
/// @note Cannot be instantiated manually. Has to be allocated with GvNodeMaster::AllocInit() and destroyed with GvNodeMaster::FreeInit().
//----------------------------------------------------------------------------------------
class GvInit
{
	private:
		GvInit();
		~GvInit();

	public:
		Int32				cpu_count;			///< The CPU count. Should always be set to @em 1.
		GvCalcFlags	flags;					///< The calculation flags: @enumerateEnum{GvCalcFlags}

	public:
		//----------------------------------------------------------------------------------------
		/// Sets the error flag. Remember to return false if this flag is set.
		/// @note GvInit::SetError() is not used very often, as in GvOperatorData::InitCalculation() there is a GvRun instead with its own GvRun::SetError().
		/// @param[in] error							The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		void SetError(GvCalcError error) { C4DOS.Gv->init->SetError(this, error); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the error flag.
		/// @return												The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		GvCalcError GetError(void) { return C4DOS.Gv->init->GetError(this); }
};

//----------------------------------------------------------------------------------------
/// Calculation interface for a port main ID. Used by the convenience functions, for example GvBuildValuesTable().
/// @note Cannot be instantiated. Use GvNode::AllocCalculationHandler() to allocate it and GvNode::FreeCalculationHandler() to destroy it.
//----------------------------------------------------------------------------------------
class GvValue
{
	private:
		GvValue();
		~GvValue();

	public:
		//----------------------------------------------------------------------------------------
		/// Calculates all ports of the value. This is the recommended method for calculating ports. After a port has been calculated you can get the value with the various functions in GvPort.
		/// @note This function is not equivalent to GvPort::Calculate().
		/// @param[in] node								The node that the ports of this value belongs to. @callerOwnsPointed{node}
		/// @param[in] io									Currently not used.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] c									The calculation helper. @callerOwnsPointed{calculation helper}
		/// @param[in] index							The port index or @ref GV_MULTIPLE_PORTS to calculate all ports: @em 0 <= @formatParam{index} < NrOfPorts()
		/// @param[in] time								If not @formatConstant{nullptr} animation tracks of the node are evaluated before the calculation.
		/// @return												@trueIfOtherwiseFalse{the value was calculated}
		//----------------------------------------------------------------------------------------
		Bool Calculate(GvNode *node, GvPortIO io, GvRun *r, GvCalc *c, Int32 index = 0, BaseTime *time = nullptr) { return C4DOS.Gv->value->Calculate(this, node, io, r, c, index, time); }

		//----------------------------------------------------------------------------------------
		/// Checks if any port of the value is connected. This is equivalent to a @c || over all <tt>GetPort(index)->GvPort::IsIncomingConnected()</tt>.
		/// @param[in] index							The port index: @em 0 <= @formatParam{index} < NrOfPorts()
		/// @return												@trueIfOtherwiseFalse{the port is connected}
		//----------------------------------------------------------------------------------------
		Bool IsConnected(Int32 index) { return C4DOS.Gv->value->IsConnected(this, index); }

		//----------------------------------------------------------------------------------------
		/// Checks if there are any ports in the value.
		/// @return												@trueIfOtherwiseFalse{if NrOfPorts() > 0}
		//----------------------------------------------------------------------------------------
		Bool IsPort(void) { return C4DOS.Gv->value->IsPort(this); }

		//----------------------------------------------------------------------------------------
		/// The number of ports in this value.
		/// @return												The port count.
		//----------------------------------------------------------------------------------------
		Int32 NrOfPorts(void) { return C4DOS.Gv->value->NrOfPorts(this); }

		//----------------------------------------------------------------------------------------
		/// The value ID of the managed ports. For all @em 0 <= @formatParam{index} < NrOfPorts() this is equal to <tt>GetPort(index)->GvPort::GetValueType GetValueType()</tt>. (Well defined since all ports are of the same type in a GvValue.)
		/// @return												The value ID.
		//----------------------------------------------------------------------------------------
		GvValueID GetValueID(void) { return C4DOS.Gv->value->GetValueID(this); }

		//----------------------------------------------------------------------------------------
		/// The main ID of the managed ports. For all @em 0 <= @formatParam{index} < NrOfPorts() this is equal to <tt>GetPort(index)->GvPort::GetMainID GetMainID()</tt>. (Well defined since all ports are of the same type in a GvValue.)
		/// @return												The main ID.
		//----------------------------------------------------------------------------------------
		Int32 GetMainID() { return C4DOS.Gv->value->GetMainID(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a port by index.
		/// @param[in] index							The port index: @em 0 <= @formatParam{index} < NrOfPorts()
		/// @return												The retrieved port. @theOwnsPointed{node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetPort(Int32 index = 0) { return C4DOS.Gv->value->GetPort(this, index); }
};

//----------------------------------------------------------------------------------------
/// Structure for GvNodeMaster::QueryCalculation().
/// @note Cannot be instantiated manually. Has to be allocated with GvNodeMaster::AllocQuery() and destroyed with GvNodeMaster::FreeQuery().
//----------------------------------------------------------------------------------------
class GvQuery
{
	private:
		GvQuery();
		~GvQuery();

	public:
		//----------------------------------------------------------------------------------------
		/// Gets the calculation flags.
		/// @return												The calculation flags: @enumerateEnum{GvCalcFlags}
		//----------------------------------------------------------------------------------------
		GvCalcFlags GetFlags(void) { return C4DOS.Gv->query->GetFlags(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the calculation flags.
		/// @param[in] flags							The calculation flags: @enumerateEnum{GvCalcFlags}
		//----------------------------------------------------------------------------------------
		void SetFlags(GvCalcFlags flags) { C4DOS.Gv->query->SetFlags(this, flags); }

		//----------------------------------------------------------------------------------------
		/// Gets the error flag.
		/// @return												The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		GvCalcError GetError(void) { return C4DOS.Gv->query->GetError(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the error flag.
		/// @param[in] error							The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		void SetError(GvCalcError error) { C4DOS.Gv->query->SetError(this, error); }
};

//----------------------------------------------------------------------------------------
/// Contains helper functions for controlling node evaluation. Cannot be instantiated.
//----------------------------------------------------------------------------------------
class GvRun
{
	private:
		GvRun();
		~GvRun();

	public:
		//----------------------------------------------------------------------------------------
		/// Attaches a calculation table.
		/// @param[in] t									The calculation table to attach. @callerOwnsPointed{table}
		//----------------------------------------------------------------------------------------
		void SetCalculationTable(GvCalcTable *t) { C4DOS.Gv->run->SetCalculationTable(this, t); }

		//----------------------------------------------------------------------------------------
		/// Marks a node to be calculated with the next CalculateTable(). A node is only added once. Equivalent to GvCalcTable::AddNodeToTable().
		/// @param[in] node								The node to add. @callerOwnsPointed{node}
		/// @param[in] force_add					@formatConstant{true} to disable checks for recursion and iteration. Should never be used under normal circumstances.
		/// @return												@trueIfOtherwiseFalse{the node was added to the calculation table}
		//----------------------------------------------------------------------------------------
		Bool AddNodeToCalculationTable(GvNode *node, Bool force_add = false) { return C4DOS.Gv->run->AddNodeToCalculationTable(this, node, force_add); }

		//----------------------------------------------------------------------------------------
		/// Calculates all nodes added to the calculation table.
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												@trueIfOtherwiseFalse{the table was calculated}
		//----------------------------------------------------------------------------------------
		Bool CalculateTable(GvCalc *calc) { return C4DOS.Gv->run->CalculateTable(this, calc); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the ID of the calculated CPU.
		/// @return												The CPU ID. Normally @em 0.
		//----------------------------------------------------------------------------------------
		Int32 GetCpuID(void) { return C4DOS.Gv->run->GetCpuID(this); }

		//----------------------------------------------------------------------------------------
		/// Increments the run ID. Used to check if a port is already calculated.
		//----------------------------------------------------------------------------------------
		void IncrementID(void) { C4DOS.Gv->run->IncrementID(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the error flag.
		/// @param[in] error							The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		void SetError(GvCalcError error) { C4DOS.Gv->run->SetError(this, error); }

		//----------------------------------------------------------------------------------------
		/// Gets the error flag.
		/// @return												The error flag: @enumerateEnum{GvError}
		//----------------------------------------------------------------------------------------
		GvCalcError GetError(void) { return C4DOS.Gv->run->GetError(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the failure state.
		/// @param[in] state							The failure state: @enumerateEnum{GvCalcState}
		//----------------------------------------------------------------------------------------
		void SetState(GvCalcState state) { C4DOS.Gv->run->SetState(this, state); }

		//----------------------------------------------------------------------------------------
		/// Gets the failure state.
		/// @return												The failure state: @enumerateEnum{GvCalcState}
		//----------------------------------------------------------------------------------------
		GvCalcState GetState(void) { return C4DOS.Gv->run->GetState(this); }

		//----------------------------------------------------------------------------------------
		/// Checks if the current calculation is an iteration (a recalculation of a part of the graph).
		/// @return												@trueIfOtherwiseFalse{this is an iteration path}
		//----------------------------------------------------------------------------------------
		Bool IsIterationPath(void) { return C4DOS.Gv->run->IsIterationPath(this); }
};

//----------------------------------------------------------------------------------------
/// Used for iterator nodes. Cannot be instantiated.
//----------------------------------------------------------------------------------------
class GvCalcTable
{
	private:
		GvCalcTable();
		~GvCalcTable();

	public:
		//----------------------------------------------------------------------------------------
		/// Marks a node to be calculated with the next GvRun::CalculateTable(). A node is only added once.
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] node								The node to add. @callerOwnsPointed{node}
		/// @return												@trueIfOtherwiseFalse{the node was added}
		//----------------------------------------------------------------------------------------
		Bool AddNodeToTable(GvRun *run, GvNode *node) { return C4DOS.Gv->table->AddNodeToTable(this, run, node); }

		//----------------------------------------------------------------------------------------
		/// Clears the table without destroying it.
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		//----------------------------------------------------------------------------------------
		void ResetTable(GvRun *run) { C4DOS.Gv->table->ResetTable(this, run); }

		//----------------------------------------------------------------------------------------
		/// Get the number of nodes added to the table.
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @return												The node count.
		//----------------------------------------------------------------------------------------
		Int32 GetTableCount(GvRun *run) { return C4DOS.Gv->table->GetTableCount(this, run); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a node in the table by index.
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] id									The node index: @em 0 <= @formatParam{id} < id GetTableCount()
		/// @return												The retrieved node.
		//----------------------------------------------------------------------------------------
		GvNode* GetTableNode(GvRun *run, Int32 id) { return C4DOS.Gv->table->GetTableNode(this, run, id); }
};


//----------------------------------------------------------------------------------------
/// The GvNode is a double BaseList2D node. Internally it has an operator that corresponds to GvOperatorData. Use GetOperatorContainer() to access most parameters.\n
/// Cannot be instantiated. Call GvNodeMaster::CreateNode() to create nodes.
//----------------------------------------------------------------------------------------
class GvNode : public BaseList2D
{
	private:
		GvNode();
		~GvNode();

	public:
		/// @name Navigation
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the next GV node in the list. Convenience version of GeListNode::GetNext().
		/// @return												The next GV node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		GvNode* GetNext(void) { return (GvNode*)AtCall(GetNext)(); }

		//----------------------------------------------------------------------------------------
		/// Gets the previous GV node in the list. Convenience version of GeListNode::GetPred().
		/// @return												The previous GV node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		GvNode* GetPred(void) { return (GvNode*)AtCall(GetPred)(); }

		//----------------------------------------------------------------------------------------
		/// Gets the parent node of the GV node. Convenience version of GeListNode::GetUp().
		/// @return												The parent node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		GvNode* GetUp(void) { return (GvNode*)AtCall(GetUp)(); }

		//----------------------------------------------------------------------------------------
		/// Gets the first child node of the GV node. Convenience version of GeListNode::GetDown().
		/// @return												The first child node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		GvNode* GetDown(void) { return (GvNode*)AtCall(GetDown)(); }

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Redraws the GV node.
		//----------------------------------------------------------------------------------------
		void Redraw(void) { C4DOS.Gv->node->Redraw(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the title of the GV node.
		/// @return												The title.
		//----------------------------------------------------------------------------------------
		const String GetTitle() { return C4DOS.Gv->node->GetTitle(this, 0); }

		//----------------------------------------------------------------------------------------
		/// Sets the title of the GV node.
		/// @param[in] title							The title to set.
		//----------------------------------------------------------------------------------------
		void SetTitle(const maxon::String &title) { C4DOS.Gv->node->SetTitle(this, title, 0); }

		//----------------------------------------------------------------------------------------
		/// Creates the internal operator.
		/// @note Mainly this means that ports are added and that GvOperatorData::iCreateOperator() is called.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool CreateOperator() { return C4DOS.Gv->node->CreateOperator(this, 0); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the node master that the GV node belongs to.
		/// @return												The node master of this node. @cinemaOwnsPointed{node master}
		//----------------------------------------------------------------------------------------
		GvNodeMaster* GetNodeMaster(void) { return C4DOS.Gv->node->GetNodeMaster(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the operator data for the GV node.
		/// @return												The operator data, or @formatConstant{nullptr}. @theOwnsPointed{node,operator data}
		//----------------------------------------------------------------------------------------
		GvOperatorData* GetOperatorData(void) { return C4DOS.Gv->node->GetOperatorData(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the operator ID for the GV node.
		/// @return												The operator ID.
		//----------------------------------------------------------------------------------------
		Int32 GetOperatorID(void) { return C4DOS.Gv->node->GetOperatorID(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the owner ID of the GV node.
		/// @return												The owner ID. Here are the predefined IDs: @enumerateEnum{ID_GV_OWNER}
		//----------------------------------------------------------------------------------------
		Int32 GetOwnerID(void) { return C4DOS.Gv->node->GetOwnerID(this); }

		//----------------------------------------------------------------------------------------
		/// Checks if the GV node is a group node.
		/// @note To access the content of a group node use the standard GeListNode navigation methods.
		/// @return												@trueIfOtherwiseFalse{the GV node is a group node}
		//----------------------------------------------------------------------------------------
		Bool IsGroupNode(void) { return C4DOS.Gv->node->IsGroupNode(this); }

		/// @}

		/// @name Port
		/// @{

		//----------------------------------------------------------------------------------------
		/// Adds a port to the GV node and returns a pointer to it.
		/// @param[in] io									The IO mode of the port to create: @enumerateEnum{GvPortIO}
		/// @param[in] id									The ID of the port to create.
		/// @param[in] flags							The port flags: @enumerateEnum{GvPortFlags}
		/// @param[in] message						If @formatConstant{true} the operator receives a message when the port is added.
		/// @return												The created port, or @formatConstant{nullptr} if failed. @theOwnsPointed{node,port}
		//----------------------------------------------------------------------------------------
		GvPort* AddPort(GvPortIO io, Int32 id, GvPortFlags flags = GV_PORT_FLAG_IS_VISIBLE, Bool message = false) { return C4DOS.Gv->node->AddPort(this, io, id, flags, message); }

		//----------------------------------------------------------------------------------------
		/// Checks if it is OK to add a port to the GV node. Used to check if a call to AddPort() would succeed.
		/// @param[in] io									The IO mode of the port to create: @enumerateEnum{GvPortIO}
		/// @param[in] id									The ID of the port to create.
		/// @return												@trueIfOtherwiseFalse{it is OK to add the port}
		//----------------------------------------------------------------------------------------
		Bool AddPortIsOK(GvPortIO io, Int32 id) { return C4DOS.Gv->node->AddPortIsOK(this, io, id); }

		//----------------------------------------------------------------------------------------
		/// Changes the type of a port of the GV node. Used to manage dynamic data ports.
		/// @param[in] port								A port of the GV node. @callerOwnsPointed{port}
		/// @param[in] id									The port ID.
		/// @return												@trueIfOtherwiseFalse{the port type was set}
		//----------------------------------------------------------------------------------------
		Bool SetPortType(GvPort *port, Int32 id) { return C4DOS.Gv->node->SetPortType(this, port, id); }

		//----------------------------------------------------------------------------------------
		/// Changes the type of the port. Used to manage dynamic data ports.
		/// @param[in] id									The port ID.
		/// @return												@trueIfOtherwiseFalse{the port type was reset}
		//----------------------------------------------------------------------------------------
		Bool ResetPortType(Int32 id) { return C4DOS.Gv->node->ResetPortType(this, id); }

		//----------------------------------------------------------------------------------------
		/// Removes a port from the GV node.
		/// @param[in] port								A port of the GV node to remove. @callerOwnsPointed{port}
		/// @param[in] message						If @formatConstant{true} the operator receives a message when the port is removed.
		//----------------------------------------------------------------------------------------
		void RemovePort(GvPort *port, Bool message = true) { C4DOS.Gv->node->RemovePort(this, port, message); }

		//----------------------------------------------------------------------------------------
		/// Checks if it is OK to remove a port from this node. Used to check if a call to RemovePort() would succeed.
		/// @param[in] port								A port of the GV node to remove. @callerOwnsPointed{port}
		/// @return												@trueIfOtherwiseFalse{it is OK to remove the port}
		//----------------------------------------------------------------------------------------
		Bool RemovePortIsOK(GvPort *port) { return C4DOS.Gv->node->RemovePortIsOK(this, port); }

		//----------------------------------------------------------------------------------------
		/// Removes all unused ports from the GV node.
		/// @param[in] message						If @formatConstant{true} the operator receives a message when ports are removed.
		//----------------------------------------------------------------------------------------
		void RemoveUnusedPorts(Bool message = true) { C4DOS.Gv->node->RemoveUnusedPorts(this, message); }

		//----------------------------------------------------------------------------------------
		/// Adds a connection between the @formatParam{source_port} of @formatParam{source_node} and @formatParam{dest_port} of @formatParam{dest_node}.
		/// @note Has to be called for the destination node of a connection.
		/// @note Does not check if the connection is valid. Always combine it with a call to GvNodeMaster::IsConnectionValid():
		/// @code
		/// if (nm->IsConnectionValid(source_node, source_port, dest_node, dest_port,
		/// 													source_node_out, source_port_out, dest_node_out, dest_port_out))
		/// {
		/// 	AddConnection(source_node_out, source_port_out, dest_node_out, dest_port_out);
		/// }
		/// @endcode
		/// @param[in] source_node				The source node. @callerOwnsPointed{node}
		/// @param[in] source_port				The source port. @callerOwnsPointed{port}
		/// @param[in] dest_node					The destination node. @callerOwnsPointed{node}
		/// @param[in] dest_port					The destination port. @callerOwnsPointed{port}
		/// @return												The @formatParam{dest_port}, or @formatConstant{nullptr} if the operation failed.
		//----------------------------------------------------------------------------------------
		GvPort* AddConnection(GvNode *source_node, GvPort *source_port, GvNode *dest_node, GvPort *dest_port) { return C4DOS.Gv->node->AddConnection(this, source_node, source_port, dest_node, dest_port); }

		//----------------------------------------------------------------------------------------
		/// Removes all connections from all ports of the GV node.
		//----------------------------------------------------------------------------------------
		void RemoveConnections(void) {	C4DOS.Gv->node->RemoveNodeConnections(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the list of port for the GV node.
		/// @param[in] port								Only retrieve ports with the passed IO mode: @enumerateEnum{GvPortIO}
		/// @param[out] portlist					Filled with the ports from the node.
		//----------------------------------------------------------------------------------------
		void GetPortList(GvPortIO port, GvPortList &portlist) { C4DOS.Gv->node->GetPortList(this, port, portlist, 0); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the description for a port of the GV node.
		/// @param[in] port								The port IO mode: @enumerateEnum{GvPortIO}
		/// @param[in] id									The port ID.
		/// @param[out] pd								Filled with the port description. @callerOwnsPointed{GvPortDescription}
		/// @return												@trueIfOtherwiseFalse{the port description was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetPortDescription(GvPortIO port, Int32 id, GvPortDescription *pd) { return C4DOS.Gv->node->GetPortDescription(this, port, id, pd, 0); }

		//----------------------------------------------------------------------------------------
		/// Gets the number of input ports of the GV node.
		/// @return												The number of input ports.
		//----------------------------------------------------------------------------------------
		Int32 GetInPortCount(void) { return C4DOS.Gv->node->GetInPortCount(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the number of output ports of the GV node.
		/// @return												The number of output ports.
		//----------------------------------------------------------------------------------------
		Int32 GetOutPortCount(void) { return C4DOS.Gv->node->GetOutPortCount(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the input port at @formatParam{index}.
		/// @param[in] index							The input port index: @em 0 <= @formatParam{index} < GetInPortCount()
		/// @return												The retrieved input port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetInPort(Int32 index) { return C4DOS.Gv->node->GetInPort(this, index); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the output port at @formatParam{index}.
		/// @param[in] index							The output port index: @em 0 <= @formatParam{index} < GetOutPortCount()
		/// @return												The retrieved output port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetOutPort(Int32 index) { return C4DOS.Gv->node->GetOutPort(this, index); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an input port by main ID. The first port found is returned.
		/// @param[in] id									The port main ID.
		/// @return												The retrieved input port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetInPortFirstMainID(Int32 id) { return C4DOS.Gv->node->GetInPortFirstMainID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an output port by main ID. The first port found is returned.
		/// @param[in] id									The port main ID.
		/// @return												The retrieved output port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetOutPortFirstMainID(Int32 id) { return C4DOS.Gv->node->GetOutPortFirstMainID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an input port by main ID. The first port found with @formatParam{index} greater or equal than @formatParam{start} is returned.
		/// @param[in] id									The port main ID.
		/// @param[in,out] start					The start index: @em 0 <= @formatParam{start} <= GetInPortCount(). Assigned a suitable value for consecutive calls, i.e. the next index.
		/// @return												The retrieved input port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetInPortMainID(Int32 id, Int32 &start) { return C4DOS.Gv->node->GetInPortMainID(this, id, start); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an output port by main ID. The first port found with @formatParam{index} greater or equal than @formatParam{start} is returned.
		/// @param[in] id									The port main ID.
		/// @param[in,out] start					The start index: @em 0 <= @formatParam{start} <= GetInPortCount(). Assigned a suitable value for consecutive calls, i.e. the next index.
		/// @return												The retrieved output port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetOutPortMainID(Int32 id, Int32 &start) { return C4DOS.Gv->node->GetOutPortMainID(this, id, start); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an input port by sub ID.
		/// @param[in] id									The port sub ID.
		/// @return												The retrieved input port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetInPortSubID(Int32 id) { return C4DOS.Gv->node->GetInPortSubID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an output port by sub ID.
		/// @param[in] id									The port sub ID.
		/// @return												The retrieved output port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetOutPortSubID(Int32 id) { return C4DOS.Gv->node->GetOutPortSubID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a port by sub ID.
		/// @param[in] sub_id							The port sub ID.
		/// @return												The retrieved port, or @formatConstant{nullptr} if failed. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* GetPort(Int32 sub_id) { return C4DOS.Gv->node->GetPort(this, sub_id); }

		//----------------------------------------------------------------------------------------
		/// Gets the index of a port by sub ID.
		/// @param[in] sub_id							The port sub ID.
		/// @return												The port index.
		//----------------------------------------------------------------------------------------
		Int32 GetPortIndex(Int32 sub_id) { return C4DOS.Gv->node->GetPortIndex(this, sub_id); }

		/// @}

		/// @name Calculate
		/// @{

		//----------------------------------------------------------------------------------------
		/// Calculates an input port by index. Equivalent to <tt>GetInPort(port_index)->GvPort::Calculate(this, run, calc)</tt>.
		/// @warning CalculateInPortIndex() should normally not be used. Use GvValue::Calculate() instead.
		/// @param[in] port_index					The port index: @em 0 <= @formatParam{start} <= GetInPortCount()
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												The calculated port, or @formatConstant{nullptr}. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* CalculateInPortIndex(Int32 port_index, GvRun *run, GvCalc *calc) { return C4DOS.Gv->node->NodeCalculateInPortIndex(this, port_index, run, calc); }

		//----------------------------------------------------------------------------------------
		/// Calculates an output port by index. Equivalent to <tt>GetOutPort(port_index)->GvPort::Calculate(this, run, calc)</tt>.
		/// @warning CalculateOutPortIndex() should normally not be used. Use GvValue::Calculate() instead.
		/// @param[in] port_index					The port index: @em 0 <= @formatParam{start} <= GetOutPortCount()
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												The calculated port, or @formatConstant{nullptr}. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* CalculateOutPortIndex(Int32 port_index, GvRun *run, GvCalc *calc) { return C4DOS.Gv->node->NodeCalculateOutPortIndex(this, port_index, run, calc); }

		//----------------------------------------------------------------------------------------
		/// Calculates an input port.
		/// @warning CalculateInPort() should normally not be used. Use GvValue::Calculate() instead.
		/// @param[in] port								The input port to calculate. @callerOwnsPointed{port}
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												The calculated port, or @formatConstant{nullptr}. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* CalculateInPort(GvPort *port, GvRun *run, GvCalc *calc) { return C4DOS.Gv->node->NodeCalculateInPort(this, port, run, calc); }

		//----------------------------------------------------------------------------------------
		/// Calculates an output port.
		/// @warning CalculateOutPort() should normally not be used. Use GvValue::Calculate() instead.
		/// @param[in] port								The output port to calculate. @callerOwnsPointed{port}
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												The calculated port, or @formatConstant{nullptr}. @theOwnsPointed{GV node,port}
		//----------------------------------------------------------------------------------------
		GvPort* CalculateOutPort(GvPort *port, GvRun *run, GvCalc *calc) { return C4DOS.Gv->node->NodeCalculateOutPort(this, port, run, calc); }

		//----------------------------------------------------------------------------------------
		/// Equivalents to GvPort::SetRecalculate() for each output port of the GV node.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] force_set					Forces all nodes to be set to be recalculated, even if they seem to be valid.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetRecalculate(GvRun *r, Bool force_set = false) { return C4DOS.Gv->node->SetRecalculate(this, r, force_set); }

		/// @}

		/// @name Operator Container
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves a pointer to the internal operator's container. This means that the container can be changed directly.
		/// @return												The operator's container. @theOwnsPointed{GV node,container}
		//----------------------------------------------------------------------------------------
		BaseContainer* GetOpContainerInstance(void) { return C4DOS.Gv->node->GetOpContainerInstance(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a copy of the internal operator's container.
		/// @return												A copy of the operator's container.
		//----------------------------------------------------------------------------------------
		BaseContainer GetOperatorContainer(void) { return C4DOS.Gv->node->GetOperatorContainer(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the internal operator's container.
		/// @param[in] bc									The container to set for the operator.
		//----------------------------------------------------------------------------------------
		void SetOperatorContainer(const BaseContainer &bc) { C4DOS.Gv->node->SetOperatorContainer(this, bc); }

		/// @}

		/// @name Operator Information/Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the detailed text of the operator.
		/// @return												The detailed text.
		//----------------------------------------------------------------------------------------
		const String OperatorGetDetailedText(void) { return C4DOS.Gv->node->OperatorGetDetailedText(this); }

		//----------------------------------------------------------------------------------------
		/// Gets error strings for the operator.
		/// @param[in] error							The error.
		/// @return												The error string.
		//----------------------------------------------------------------------------------------
		const String OperatorGetErrorString(Int32 error) { return C4DOS.Gv->node->OperatorGetErrorString(this, error); }

		//----------------------------------------------------------------------------------------
		/// Sets data in the operator.
		/// @see GvOperatorData::SetData.
		/// @param[in] type								The data type: @enumerateEnum{GvDataType}
		/// @param[in] data								The data pointer. The format depends on @formatParam{type}. @callerOwnsPointed{data}
		/// @param[in] mode								The set data mode: @enumerateEnum{GvOpSetDataMode}
		/// @return												@trueIfOtherwiseFalse{the data was set}
		//----------------------------------------------------------------------------------------
		Bool OperatorSetData(GvDataType type, void *data, GvOpSetDataMode mode) { return C4DOS.Gv->node->OperatorSetData(this, type, data, mode); }

		//----------------------------------------------------------------------------------------
		/// Checks if a call to OperatorSetData() is allowed.
		/// @param[in] type								The data type: @enumerateEnum{GvDataType}
		/// @param[in] data								The data pointer. The format depends on @formatParam{type}. @callerOwnsPointed{data}
		/// @param[in] mode								The set data mode: @enumerateEnum{GvOpSetDataMode}
		/// @return												@trueIfOtherwiseFalse{the data can be set}
		//----------------------------------------------------------------------------------------
		Bool OperatorIsSetDataAllowed(GvDataType type, void *data, GvOpSetDataMode mode) { return C4DOS.Gv->node->OperatorIsSetDataAllowed(this, type, data, mode); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the operator icon.
		/// @param[in] dat								Filled with the operator icon data.
		//----------------------------------------------------------------------------------------
		void OperatorGetIcon(IconData &dat) { C4DOS.Gv->node->OperatorGetIcon(this, dat); }

		/// @}

		/// @name Node State
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the selection state of the GV node.
		/// @return												The selection state.
		//----------------------------------------------------------------------------------------
		Bool GetSelectState(void) { return C4DOS.Gv->node->GetSelectState(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the failure state of the GV node.
		/// @return												The failure state.
		//----------------------------------------------------------------------------------------
		Bool GetFailureState(void) { return C4DOS.Gv->node->GetFailureState(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the disabled state of the GV node.
		/// @return												The disabled state.
		//----------------------------------------------------------------------------------------
		Bool GetDisabledState(void) { return C4DOS.Gv->node->GetDisabledState(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the open state of the GV node.
		/// @return												The open state.
		//----------------------------------------------------------------------------------------
		Bool GetOpenState(void) { return C4DOS.Gv->node->GetOpenState(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the open state of the GV node.
		/// @param[in] state							The open state.
		//----------------------------------------------------------------------------------------
		void SetOpenState(Bool state) { C4DOS.Gv->node->SetOpenState(this, state); }

		//----------------------------------------------------------------------------------------
		/// Gets the lock state of the GV node.
		/// @return												The lock state.
		//----------------------------------------------------------------------------------------
		Bool GetLockState(void) { return C4DOS.Gv->node->GetLockState(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the lock state of the GV node.
		/// @param[in] state							The lock state.
		//----------------------------------------------------------------------------------------
		void SetLockState(Bool state) { C4DOS.Gv->node->SetLockState(this, state); }

		//----------------------------------------------------------------------------------------
		/// Gets the show port name state of the GV node.
		/// @return												The show port name state.
		//----------------------------------------------------------------------------------------
		Bool GetShowPortNamesState(void) { return C4DOS.Gv->node->GetShowPortNamesState(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the show port name state of the GV node.
		/// @param[in] state							The show port name state.
		//----------------------------------------------------------------------------------------
		void SetShowPortNamesState(Bool state) { C4DOS.Gv->node->SetShowPortNamesState(this, state); }

		/// @}

		/// @name Calculation Handler
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a calculation handler for the ports of a main ID of the GV node.\n
		/// Free the allocated handler with FreeCalculationHandler().
		/// @param[in] main_id						The main ID.
		/// @param[in] calc								The calculation helper. @callerOwnsPointed{calculation helper}
		/// @param[in] run								The run helper. @callerOwnsPointed{run helper}
		/// @param[in] singleport					The port index if the handler should be for a specific port. Otherwise pass @ref GV_MULTIPLE_PORTS.
		/// @return												The allocated handler, or @formatConstant{nullptr} if failed.
		//----------------------------------------------------------------------------------------
		GvValue* AllocCalculationHandler(Int32 main_id, GvCalc *calc, GvRun *run, Int32 singleport) { return C4DOS.Gv->node->AllocCalculationHandler(this, main_id, calc, run, singleport); }

		//----------------------------------------------------------------------------------------
		/// Frees calculation handlers allocated with AllocCalculationHandler().
		/// @param[in,out] value					The calculation handler to free. Set to @formatConstant{nullptr} afterwards.
		//----------------------------------------------------------------------------------------
		void FreeCalculationHandler(GvValue *&value) { C4DOS.Gv->node->FreeCalculationHandler(this, value); }

		/// @}

		/// @name Calculate
		/// @{

		//----------------------------------------------------------------------------------------
		/// Convenience function to do calculation with unknown data.\n
		/// Retrieves the handler for @formatParam{value_id} and then calls @c GV_VALUE_HANDLER::Calculate(userdata, @formatParam{value_id}, @formatParam{data1}, @formatParam{data2}, @formatParam{dest}, 0, @formatParam{calculation}, @formatParam{parm1}).
		/// @see GvPort::CalculateRawData() for a similar functionality for ports.
		/// @param[in] value_id						Determines the type of the data parameters.
		/// @param[in] data1							The first data. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] data2							The second data. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[out] dest							The destination. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] calculation				The calculation to perform: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							An additional parameter.
		/// @return												@trueIfOtherwiseFalse{the result of the calculation was @ref GV_CALC_ERR_NONE}
		//----------------------------------------------------------------------------------------
		Bool CalculateRawData(GvValueID value_id, const void* const data1, const void* const data2, void *dest, GvValueFlags calculation, Float parm1) { return C4DOS.Gv->node->CalculateRawData(this, value_id, data1, data2, dest, calculation, parm1); }

		/// @}
};

//----------------------------------------------------------------------------------------
/// There are three kinds of port IDs:
/// - Main: The type of the port, for example @ref GV_FORMULA_INPUT in @em GVformula.
/// - Sub: A unique ID for each instance of multiple ports with the same Main ID. Assigned when the port is created.
/// - %User: A place to store an ID for custom management. @C4D ignores this value.
///
/// Cannot be instantiated. Call GvNode::AddPort() to create a port.
//----------------------------------------------------------------------------------------
class GvPort
{
	private:
		GvPort();
		~GvPort();

	public:
		/// @name Connections
		/// @{

		//----------------------------------------------------------------------------------------
		/// Removes the incoming connection.
		//----------------------------------------------------------------------------------------
		void RemoveConnection(void) { C4DOS.Gv->port->RemoveConnection(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the number of connections, including both the incoming and outgoing connections.
		/// @return												The number of connections.
		//----------------------------------------------------------------------------------------
		Int32 GetNrOfConnections(void) { return C4DOS.Gv->port->GetNrOfConnections(this); }

		//----------------------------------------------------------------------------------------
		/// Removes all outgoing connections.
		//----------------------------------------------------------------------------------------
		void RemovePortConnections(void) { C4DOS.Gv->port->RemovePortConnections(this); }

		//----------------------------------------------------------------------------------------
		/// Checks if there is an incoming connection.
		/// @return												@trueIfOtherwiseFalse{there is an incoming connection to the port}
		//----------------------------------------------------------------------------------------
		Bool IsIncomingConnected(void) { return C4DOS.Gv->port->IsIncomingConnected(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the destination of the incoming connection.
		/// @param[out] node							Assigned the incoming destination node.
		/// @param[out] port							Assigned the incoming destination port.
		/// @return												@trueIfOtherwiseFalse{the incoming destination was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetIncomingDestination(GvNode *&node, GvPort *&port) { return C4DOS.Gv->port->GetIncomingDestination(this, node, port); }

		//----------------------------------------------------------------------------------------
		/// Gets the source of the incoming connection.
		/// @param[out] node							Assigned the incoming source node.
		/// @param[out] port							Assigned the incoming source port.
		/// @return												@trueIfOtherwiseFalse{the incoming source was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetIncomingSource(GvNode *&node, GvPort *&port) { return C4DOS.Gv->port->GetIncomingSource(this, node, port); }

		/// @}

		/// @name Port IDs
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the IO mode for the port.
		/// @return												The IO mode: @enumerateEnum{GvPortIO}
		//----------------------------------------------------------------------------------------
		GvPortIO GetIO(void) { return C4DOS.Gv->port->GetIO(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the main ID of the port.
		/// @param[in] id									The main ID to set.
		//----------------------------------------------------------------------------------------
		void SetMainID(Int32 id) { C4DOS.Gv->port->SetMainID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Gets the main ID of the port.
		/// @return												The main ID.
		//----------------------------------------------------------------------------------------
		Int32 GetMainID(void) { return C4DOS.Gv->port->GetMainID(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the sub ID of the port.
		/// @return												The sub ID.
		//----------------------------------------------------------------------------------------
		Int32 GetSubID(void) { return C4DOS.Gv->port->GetSubID(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the user ID of the port.
		/// @param[in] id									The user ID to set.
		//----------------------------------------------------------------------------------------
		void SetUserID(Int32 id) { C4DOS.Gv->port->SetUserID(this, id); }

		//----------------------------------------------------------------------------------------
		/// Gets the user ID of the port.
		/// @return												The user ID.
		//----------------------------------------------------------------------------------------
		Int32 GetUserID(void) { return C4DOS.Gv->port->GetUserID(this); }

		/// @}

		/// @name ValueType/Visible/Valid
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the value type of the port.
		/// @return												The value type.
		//----------------------------------------------------------------------------------------
		GvValueID GetValueType(void) { return C4DOS.Gv->port->GetValueType(this); }

		//----------------------------------------------------------------------------------------
		/// Hides or shows the port.
		/// @param[in] v									@formatConstant{true} if the port should be visible and @formatConstant{false} if it should be hidden.
		//----------------------------------------------------------------------------------------
		void SetVisible(Bool v) { C4DOS.Gv->port->SetVisible(this, v); }

		//----------------------------------------------------------------------------------------
		/// Checks if the port is hidden or visible.
		/// @return												@formatConstant{true} if the port is visible and @formatConstant{false} if it is hidden.
		//----------------------------------------------------------------------------------------
		Bool GetVisible(void) { return C4DOS.Gv->port->GetVisible(this); }

		//----------------------------------------------------------------------------------------
		/// Reports this port as valid or invalid during a run.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] v									@trueIfOtherwiseFalse{the port is valid}
		//----------------------------------------------------------------------------------------
		void SetValid(GvRun *r, Bool v) { C4DOS.Gv->port->SetValid(this, r, v); }

		//----------------------------------------------------------------------------------------
		/// Checks if the port is valid during a run.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the port is valid}
		//----------------------------------------------------------------------------------------
		Bool GetValid(GvRun *r) { return C4DOS.Gv->port->GetValid(this, r); }

		/// @}

		/// @name Calculate
		/// @{

		//----------------------------------------------------------------------------------------
		/// Reports that this port has been calculated in this run.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		//----------------------------------------------------------------------------------------
		void SetCalculated(GvRun *r) { C4DOS.Gv->port->SetCalculated(this, r); }

		//----------------------------------------------------------------------------------------
		/// Calculates the port.
		/// @note Calculate() should normally not be used. Use GvValue::Calculate() instead.
		/// @param[in] bn									The node that the ports belongs to. @callerOwnsPointed{node}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] c									The calculation helper. @callerOwnsPointed{calculation helper}
		/// @return												The calculated port.
		//----------------------------------------------------------------------------------------
		GvPort* Calculate(GvNode *bn, GvRun *r, GvCalc *c) { return C4DOS.Gv->port->Calculate(this, bn, r, c); }

		//----------------------------------------------------------------------------------------
		/// Marks all outgoing port connections for recalculation. This will also call GvOperatorData::SetRecalculate().
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] force_set					Forces all nodes to be recalculated, even if they seem to be valid.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetRecalculate(GvRun *r, Bool force_set = false) { return C4DOS.Gv->port->SetRecalculate(this, r, force_set); }

		/// @}

		/// @name Get Value
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves a boolean value from the port.
		/// @param[out] b									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetBool(Bool *b, GvRun *r) { return C4DOS.Gv->port->GetBool(this, b, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an integer value from the port.
		/// @param[out] i									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetInteger(Int32 *i, GvRun *r) { return C4DOS.Gv->port->GetInteger(this, i, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a float value from the port.
		/// @param[out] f									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetFloat(Float *f, GvRun *r) { return C4DOS.Gv->port->GetFloat(this, f, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a vector value from the port.
		/// @param[out] v									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetVector(Vector *v, GvRun *r) { return C4DOS.Gv->port->GetVector(this, v, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a normal vector value from the port.
		/// @param[out] n									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetNormal(Vector *n, GvRun *r) { return C4DOS.Gv->port->GetNormal(this, n, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a matrix value from the port.
		/// @param[out] m									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetMatrix(Matrix *m, GvRun *r) { return C4DOS.Gv->port->GetMatrix(this, m, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a time value from the port.
		/// @param[out] t									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetTime(BaseTime *t, GvRun *r) { return C4DOS.Gv->port->GetTime(this, t, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves a string value from the port.
		/// @param[out] s									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetString(String *s, GvRun *r) { return C4DOS.Gv->port->GetString(this, s, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an object value from the port.
		/// @param[out] o									Assigned the port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetObject(BaseList2D *&o, GvRun *r) { return C4DOS.Gv->port->GetObject(this, o, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the data from the port.
		/// @param[out] d									Assigned the port value. @theOwnsPointed{port,data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{type}.
		/// @param[in] type								Determines the type of @formatParam{d}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetData(void *d, GvValueID type, GvRun *r) { return C4DOS.Gv->port->GetData(this, d, type, r); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the data pointer from the port.
		/// @param[out] d									Assigned a pointer to the port data. @theOwnsPointed{port,data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{type}.
		/// @param[in] type								Determines the type of @formatParam{d}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetDataInstance(const void *&d, GvValueID type, GvRun *r) { return C4DOS.Gv->port->GetDataInstance(this, d, type, r); }

		/// @}

		/// @name Set Value
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets a boolean value in the port.
		/// @param[in] b									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetBool(Bool b, GvRun *r) { return C4DOS.Gv->port->SetBool(this, b, r); }

		//----------------------------------------------------------------------------------------
		/// Sets an integer value in the port.
		/// @param[in] i									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetInteger(Int32 i, GvRun *r) { return C4DOS.Gv->port->SetInteger(this, i, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a float value in the port.
		/// @param[in] f									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetFloat(Float f, GvRun *r) { return C4DOS.Gv->port->SetFloat(this, f, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a vector value in the port.
		/// @param[in] v									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetVector(const Vector &v, GvRun *r) { return C4DOS.Gv->port->SetVector(this, v, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a matrix value in the port.
		/// @param[in] m									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetMatrix(const Matrix &m, GvRun *r) { return C4DOS.Gv->port->SetMatrix(this, m, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a normal vector value in the port.
		/// @param[in] n									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetNormal(const Vector &n, GvRun *r) { return C4DOS.Gv->port->SetNormal(this, n, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a time value in the port.
		/// @param[in] t									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetTime(const BaseTime &t, GvRun *r) { return C4DOS.Gv->port->SetTime(this, t, r); }

		//----------------------------------------------------------------------------------------
		/// Sets a string value in the port.
		/// @param[in] s									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetString(const maxon::String &s, GvRun *r) { return C4DOS.Gv->port->SetString(this, s, r); }

		//----------------------------------------------------------------------------------------
		/// Sets an object value in the port.
		/// @param[in] o									The new port value.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetObject(const BaseList2D* o, GvRun *r) { return C4DOS.Gv->port->SetObject(this, o, r); }

		//----------------------------------------------------------------------------------------
		/// Sets the data in the port.
		/// @param[in] d									The new port value. @theOwnsPointed{port,data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{type}.
		/// @param[in] type								Determines the type of @formatParam{d}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the value was set}
		//----------------------------------------------------------------------------------------
		Bool SetData(const void* d, GvValueID type, GvRun *r) { return C4DOS.Gv->port->SetData(this, d, type, r); }

		//----------------------------------------------------------------------------------------
		/// Gets the name of the port.
		/// @param[in] node								The node the ports belongs to. @callerOwnsPointed{node}
		/// @return												The port name.
		//----------------------------------------------------------------------------------------
		const String GetName(GvNode *node) { return C4DOS.Gv->port->GetName(this, node); }

		//----------------------------------------------------------------------------------------
		/// Sets the name of the port.
		/// @param[in] name								The new port name.
		//----------------------------------------------------------------------------------------
		void SetName(const maxon::String &name) { C4DOS.Gv->port->SetName(this, name); }

		/// @}

		/// @name Copy Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// Copies the data from the @formatParam{source} port.
		/// @param[in] source							The source port. @callerOwnsPointed{port}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the data was copied}
		//----------------------------------------------------------------------------------------
		Bool CopyPortData(GvPort *source, GvRun *r) { return C4DOS.Gv->port->CopyPortData(this, source, r); }

		//----------------------------------------------------------------------------------------
		/// Copies the raw @c void* data from @formatParam{source}.
		/// @param[in] source							The source data. @callerOwnsPointed{data}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @return												@trueIfOtherwiseFalse{the raw data was copied}
		//----------------------------------------------------------------------------------------
		Bool CopyRawData(void *source, GvRun *r) { return C4DOS.Gv->port->CopyRawData(this, source, r); }

		/// @}

		/// @name Calculate Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// Convenience function to do calculation with unknown data.\n
		/// Uses the port's value handler to call @c GV_VALUE_HANDLER::Calculate(userdata, value_id, portdata, @formatParam{data}, @formatParam{dest}, 0, @formatParam{calculation}, @formatParam{parm1}), where @c portdata is the data of the port.\n
		/// For example, the result operator does:
		/// @code
		/// if (!v1->GetPort()->CalculateRawData(nullptr, &result, r, GV_CALC_STR))
		/// 	return false;
		/// @endcode
		/// @param[in] data								The second data. This port data is used as first data. @callerOwnsPointed{data}
		/// @param[out] dest							The destination. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calculation				The calculation to perform: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							An additional parameter.
		/// @return												@trueIfOtherwiseFalse{the result is @ref GV_CALC_ERR_NONE} If there is an error GvRun::SetError() is called.
		//----------------------------------------------------------------------------------------
		Bool CalculateRawData(void *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1 = 0.0_f) { return C4DOS.Gv->port->CalculateRawData(this, data, dest, r, calculation, parm1); }

		//----------------------------------------------------------------------------------------
		/// Convenience function to do calculation with unknown data.\n
		/// Uses the port's value handler to call @c GV_VALUE_HANDLER::Calculate(userdata, value_id, @formatParam{data1}, @formatParam{data2}, @formatParam{dest}, 0, @formatParam{calculation}, @formatParam{parm1}).
		/// @param[in] data1							The first data. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] data2							The second data. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[out] dest							The destination. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calculation				The calculation to perform: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							An additional parameter.
		/// @return												@trueIfOtherwiseFalse{the result is @ref GV_CALC_ERR_NONE} If there is an error GvRun::SetError() is called.
		//----------------------------------------------------------------------------------------
		Bool CalculateRawRawData(void *data1, void *data2, void *dest, GvRun *r, GvValueFlags calculation, Float parm1 = 0.0_f) { return C4DOS.Gv->port->CalculateRawRawData(this, data1, data2, dest, r, calculation, parm1); }

		//----------------------------------------------------------------------------------------
		/// Convenience function to do calculation with unknown data.\n
		/// Uses the port's value handler to call @c GV_VALUE_HANDLER::Calculate(userdata, value_id, portdata1, portdata2, @formatParam{dest}, 0, @formatParam{calculation}, @formatParam{parm1}), where @c portdata1 is the data of the port and @c portdata2 is the data of the @formatParam{data} port.
		/// @param[in] data								The port with the second data. This port data is used as first data. @callerOwnsPointed{port}
		/// @param[out] dest							The destination. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calculation				The calculation to perform: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							An additional parameter.
		/// @return												@trueIfOtherwiseFalse{the result is @ref GV_CALC_ERR_NONE} If there is an error GvRun::SetError() is called.
		//----------------------------------------------------------------------------------------
		Bool CalculatePortData(GvPort *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1 = 0.0_f) { return C4DOS.Gv->port->CalculatePortData(this, data, dest, r, calculation, parm1); }

		//----------------------------------------------------------------------------------------
		/// Convenience function to do calculation with unknown data.\n
		/// Uses the port's value handler to call @c GV_VALUE_HANDLER::Calculate(userdata, value_id, data, portdata, @formatParam{dest}, 0, @formatParam{calculation}, @formatParam{parm1}), where @c portdata is the data of the port.
		/// @param[in] data								The first data. This port data is used as second data. @callerOwnsPointed{data}
		/// @param[out] dest							The destination. @callerOwnsPointed{data}\n
		/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] calculation				The calculation to perform: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							An additional parameter.
		/// @return												@trueIfOtherwiseFalse{the result is @ref GV_CALC_ERR_NONE} If there is an error GvRun::SetError() is called.
		//----------------------------------------------------------------------------------------
		Bool CalculateRawDataRev(void *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1 = 0.0_f) { return C4DOS.Gv->port->CalculateRawDataRev(this, data, dest, r, calculation, parm1); }

		/// @}

		/// @name Get/Set Tag/Material/Instance/Object
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves an indexed tag value from the port.
		/// @param[out] t									Assigned the retrieved tag if successful.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[out] index							Assigned the index of the data, if not @formatConstant{nullptr}. Used by iterators to specify the index of the retrieved data.
		/// @return												@trueIfOtherwiseFalse{the tag was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetTag(BaseList2D *&t, GvRun *r, Int32 *index = nullptr) { return C4DOS.Gv->port->GetTag(this, t, r, index); }

		//----------------------------------------------------------------------------------------
		/// Sets an indexed tag value in the port.
		/// @param[in] t									The tag to set. @callerOwnsPointed{tag}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] index							The data index. Used by iterators.
		/// @return												@trueIfOtherwiseFalse{the tag was set}
		//----------------------------------------------------------------------------------------
		Bool SetTag(const BaseList2D* const t, GvRun *r, Int32 index = 0) { return C4DOS.Gv->port->SetTag(this, t, r, index); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an indexed material value from the port.
		/// @param[out] m									Assigned the retrieved material if successful.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[out] index							Assigned the index of the data, if not @formatConstant{nullptr}. Used by iterators to specify the index of the retrieved data.
		/// @return												@trueIfOtherwiseFalse{the material was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetMaterial(BaseList2D *&m, GvRun *r, Int32 *index = nullptr) { return C4DOS.Gv->port->GetMaterial(this, m, r, index); }

		//----------------------------------------------------------------------------------------
		/// Sets an indexed material value in the port.
		/// @param[in] m									The material to set. @callerOwnsPointed{material}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] index							The data index. Used by iterators.
		/// @return												@trueIfOtherwiseFalse{the material was set}
		//----------------------------------------------------------------------------------------
		Bool SetMaterial(const BaseList2D* const m, GvRun *r, Int32 index = 0) { return C4DOS.Gv->port->SetMaterial(this, m, r, index); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an indexed instance value from the port.
		/// @param[out] i									Assigned the retrieved instance if successful.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[out] index							Assigned the index of the data, if not @formatConstant{nullptr}. Used by iterators to specify the index of the retrieved data.
		/// @return												@trueIfOtherwiseFalse{the instance was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetInstance(BaseList2D *&i, GvRun *r, Int32 *index = nullptr) { return C4DOS.Gv->port->GetInstance(this, i, r, index); }

		//----------------------------------------------------------------------------------------
		/// Sets an indexed instance value in the port.
		/// @param[in] i									The instance to set. @callerOwnsPointed{instance}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] index							The data index. Used by iterators.
		/// @return												@trueIfOtherwiseFalse{the instance was set}
		//----------------------------------------------------------------------------------------
		Bool SetInstance(const BaseList2D* const i, GvRun *r, Int32 index = 0) { return C4DOS.Gv->port->SetInstance(this, i, r, index); }

		//----------------------------------------------------------------------------------------
		/// Retrieves an indexed object value from the port.
		/// @param[out] o									Assigned the retrieved object if successful.
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[out] index							Assigned the index of the data, if not @formatConstant{nullptr}. Used by iterators to specify the index of the retrieved data.
		/// @return												@trueIfOtherwiseFalse{the object was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetObjectWithIndex(BaseList2D *&o, GvRun *r, Int32 *index = nullptr) { return C4DOS.Gv->port->GetObjectWithIndex(this, o, r, index); }

		//----------------------------------------------------------------------------------------
		/// Sets an indexed object value in the port.
		/// @param[in] o									The object to set. @callerOwnsPointed{object}
		/// @param[in] r									The run helper. @callerOwnsPointed{run helper}
		/// @param[in] index							The data index. Used by iterators.
		/// @return												@trueIfOtherwiseFalse{the object was set}
		//----------------------------------------------------------------------------------------
		Bool SetObjectWithIndex(const BaseList2D* const o, GvRun *r, Int32 index = 0) { return C4DOS.Gv->port->SetObjectWithIndex(this, o, r, index); }

		/// @}

		/// @name Outgoing/Destination Information
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves information about the outgoing destinations.
		/// @param[in] index							The destination index: @em 0 <= @formatParam{index} < GetNrOfConnections()-(IsIncomingConnected() ? @em 1 : @em 0)
		/// @return												The destination information, or @formatConstant{nullptr}. @cinemaOwnsPointed{GvDestination}
		//----------------------------------------------------------------------------------------
		GvDestination* GetOutgoing(Int32 index) { return C4DOS.Gv->port->GetOutgoing(this, index); }

		/// @}

		/// @name User Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// @markInternal
		/// @since R17.032
		//----------------------------------------------------------------------------------------
		GeData* GetUserData() { return C4DOS.Gv->port->GetUserData(this); }

		//----------------------------------------------------------------------------------------
		/// @markInternal
		/// @since R17.032
		//----------------------------------------------------------------------------------------
		void SetUserData(const GeData& data) { C4DOS.Gv->port->SetUserData(this, data); }

		/// @}
};

//----------------------------------------------------------------------------------------
/// The GV node master class handles a collection of GV nodes and calculates them.\n
/// Normally you do not need to create it yourself, but this can be done with GvWorld::AllocNodeMaster() and GvWorld::FreeNodeMaster().\n
/// The node master sends these message to its parent: @enumerateEnum{GvMessage}
//----------------------------------------------------------------------------------------
class GvNodeMaster : public BaseList2D
{
	private:
		GvNodeMaster();
		~GvNodeMaster();

	public:
		/// @name Alloc/Free/Create
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a GV node without inserting it. Use FreeNode() to free the node.
		/// @note It is recommended to use CreateNode() instead.
		/// @param[in] id									The GV node ID, for example @ref ID_OPERATOR_OBJECT or a custom ID.
		/// @return												The allocated GV node, or @formatConstant{nullptr}. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		GvNode* AllocNode(Int32 id) { return C4DOS.Gv->master->AllocNode(this, id); }

		//----------------------------------------------------------------------------------------
		/// Frees GV nodes allocated with AllocNode().
		/// @param[in,out] node						@theToDestruct{GV node}
		//----------------------------------------------------------------------------------------
		void FreeNode(GvNode *&node) { C4DOS.Gv->master->FreeNode(this, node); }

		//----------------------------------------------------------------------------------------
		/// Creates a node and inserts it.
		/// @param[in] parent							The parent node. GetRoot() to insert a top node.
		/// @param[in] id									The GV node ID, for example @ref ID_OPERATOR_OBJECT or a custom ID.
		/// @param[in] insert							The insertion point.
		/// @param[in] x									The X position.
		/// @param[in] y									The Y position.
		/// @return												The created GV node, or @formatConstant{nullptr}. @theOwnsPointed{master,node}
		//----------------------------------------------------------------------------------------
		GvNode* CreateNode(GvNode *parent, Int32 id, GvNode *insert = nullptr, Int32 x = -1, Int32 y = -1) { return C4DOS.Gv->master->CreateNode(this, parent, id, insert, x, y); }

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves the root node.
		/// @return												The root node. @theOwnsPointed{master,node}
		//----------------------------------------------------------------------------------------
		GvNode* GetRoot(void) { return C4DOS.Gv->master->GetRoot(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the owner of the node master.
		/// @return												The owner. @cinemaOwnsPointed{owner}
		//----------------------------------------------------------------------------------------
		BaseList2D* GetOwner(void) { return C4DOS.Gv->master->GetOwner(this); }

		//----------------------------------------------------------------------------------------
		/// Has to be called to make sure that the connection is valid before attempting a GvNode::AddConnection().
		/// @note Swaps the nodes and the ports to ensure that always source is the output and dest the input. Use the _out parameters with GvNode::AddConnection() if the connection is allowed.
		/// @param[in] source_node				The source node input. @callerOwnsPointed{node}
		/// @param[in] source_port				The source port input. @callerOwnsPointed{node}
		/// @param[in] dest_node					The destination node input. @callerOwnsPointed{node}
		/// @param[in] dest_port					The destination port input. @callerOwnsPointed{node}
		/// @param[in] source_node_out		The source node output. @callerOwnsPointed{node}
		/// @param[in] source_port_out		The source port output. @callerOwnsPointed{node}
		/// @param[in] dest_node_out			The destination node output. @callerOwnsPointed{node}
		/// @param[in] dest_port_out			The destination port output. @callerOwnsPointed{node}
		/// @return												@trueIfOtherwiseFalse{the connection is allowed}
		//----------------------------------------------------------------------------------------
		Bool IsConnectionValid(GvNode *source_node, GvPort *source_port, GvNode *dest_node, GvPort *dest_port, GvNode *&source_node_out, GvPort *&source_port_out, GvNode *&dest_node_out, GvPort *&dest_port_out) { return C4DOS.Gv->master->IsConnectionValid(this, source_node, source_port, dest_node, dest_port, source_node_out, source_port_out, dest_node_out, dest_port_out); }

		/// @}

		/// @name Insert/Hierarchy Node
		/// @{

		//----------------------------------------------------------------------------------------
		/// Inserts a node first in the node list of an @em Xgroup.
		/// @note Equivalent to GeListNode::InsertUnder(), but with additional checks that @formatParam{parent} is a group node, and that @formatParam{node} is removed.
		/// @param[in] parent							The parent GV node. Must be a group node owned by the node master.
		/// @param[in] node								The GV node to insert. The master takes over the ownership of the pointed node.
		/// @return												@trueIfOtherwiseFalse{the node was inserted}
		//----------------------------------------------------------------------------------------
		Bool InsertFirst(GvNode* parent, GvNode* node) { return C4DOS.Gv->master->InsertFirst(this, parent, node); }

		//----------------------------------------------------------------------------------------
		/// Inserts a node last in the node list of an @em Xgroup.
		/// @note Equivalent to GeListNode::InsertUnderLast(), but with additional checks that @formatParam{parent} is a group node, and that @formatParam{node} is removed.
		/// @param[in] parent							The parent GV node. Must be a group node owned by the node master.
		/// @param[in] node								The GV node to insert. The master takes over the ownership of the pointed node.
		/// @return												@trueIfOtherwiseFalse{the node was inserted}
		//----------------------------------------------------------------------------------------
		Bool InsertLast(GvNode* parent, GvNode* node) { return C4DOS.Gv->master->InsertLast(this, parent, node); }

		//----------------------------------------------------------------------------------------
		/// Performs a hierarchy operation.
		/// @note Equivalent to the standard GeListNode calls, but with additional checks.
		/// @param[in] insert							The insertion point. Must be owned by the node master.
		/// @param[in] node								The GV node to perform the operation on. The master takes over the ownership of the pointed object.
		/// @param[in] mode								The insertion mode: @enumerateEnum{GvInsertMode}
		/// @return												@trueIfOtherwiseFalse{the hierarchy was set}
		//----------------------------------------------------------------------------------------
		Bool SetHierarchy(GvNode *insert, GvNode *node, GvInsertMode mode = GV_INSERT_AFTER) { return C4DOS.Gv->master->SetHierarchy(this, insert, node, mode); }

		/// @}

		/// @name Calculation
		/// @{

		//----------------------------------------------------------------------------------------
		/// Checks if it is OK to begin a calculation.
		/// @param[in] query							The GV query object. @callerOwnsPointed{GvQuery}
		/// @param[in] thread							The thread to use for break checks. @callerOwnsPointed{thread}
		/// @return												The result of the check.
		//----------------------------------------------------------------------------------------
		GvCalcError QueryCalculation(GvQuery *query, BaseThread *thread) { return C4DOS.Gv->master->QueryCalculation(this, query, thread); }

		//----------------------------------------------------------------------------------------
		/// Tells the nodes to allocate resources for a calculation. Must be called before Calculate(). Call FreeCalculation() afterwards.
		/// @param[in] init								The GV init object. @callerOwnsPointed{GvInit}
		/// @param[in] thread							The thread to use for break checks. @callerOwnsPointed{thread}
		/// @return												The result of the initialization.
		//----------------------------------------------------------------------------------------
		GvCalcError InitCalculation(GvInit *init, BaseThread *thread) { return C4DOS.Gv->master->InitCalculation(this, init, thread); }

		//----------------------------------------------------------------------------------------
		/// Starts a calculation.
		/// @param[in] cpu_id							The CPU ID. Normally @em 0.
		/// @return												The result of the calculation.
		//----------------------------------------------------------------------------------------
		GvCalcError Calculate(Int32 cpu_id) { return C4DOS.Gv->master->Calculate(this, cpu_id); }

		//----------------------------------------------------------------------------------------
		/// Sets all operators' ports connected to the output ports of @formatParam{node} to invalid, to enable an iterator loop path.
		/// @param[in] master							Not used. The method always uses the @c this pointer instead.
		/// @param[in] node								The GV node to recalculate. @callerOwnsPointed{node}
		/// @param[in] cpu_id							The CPU ID. Normally @em 0.
		/// @return												The result of the recalculation.
		//----------------------------------------------------------------------------------------
		GvCalcError Recalculate(GvNodeMaster *master, GvNode *node, Int32 cpu_id) { return C4DOS.Gv->master->Recalculate(this, node, cpu_id); }

		//----------------------------------------------------------------------------------------
		/// Frees resources allocated by the GV nodes for calculation.
		//----------------------------------------------------------------------------------------
		void FreeCalculation(void) { C4DOS.Gv->master->FreeCalculation(this); }

		//----------------------------------------------------------------------------------------
		/// Equivalent to calling QueryCalculation(), InitCalculation(), Calculate() and FreeCalculation() with some error checks.
		/// @note This is the recommended way to execute XPresso. Use Execute2() to pass flags for the execution.
		/// @param[in] thread							The thread to use for break checks. @callerOwnsPointed{thread}
		/// @return												The result of the execution.
		//----------------------------------------------------------------------------------------
		GvCalcError Execute(BaseThread *thread) { return C4DOS.Gv->master->Execute(this, thread); }

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Similar to GeListNode::GetBranchInfo().
		//----------------------------------------------------------------------------------------
		Int32 GetBranchInfo(BranchInfo *info, Int32 max, GETBRANCHINFO flags) { return C4DOS.Gv->master->GetBranchInfo(this, info, max); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the current run helper.
		/// @return												The run helper. @callerOwnsPointed{GvRun}
		//----------------------------------------------------------------------------------------
		GvRun* GetRun(void) { return C4DOS.Gv->master->GetRun(this); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the current calculation helper.
		/// @return												The calculation helper. @callerOwnsPointed{GvRun}
		//----------------------------------------------------------------------------------------
		GvCalc* GetCalc(void) { return C4DOS.Gv->master->GetCalc(this); }

		//----------------------------------------------------------------------------------------
		/// Returns the inverse of GetRoot()->GetDisabledState(), or @formatConstant{false} if there is no root.
		/// @return												@trueIfOtherwiseFalse{the node master is enabled}
		//----------------------------------------------------------------------------------------
		Bool IsEnabled(void) { return C4DOS.Gv->master->IsEnabled(this); }

		/// @}

		/// @name Query
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a GV query object. Must be freed with FreeQuery().
		/// @return												The allocated query object. @callerOwnsPointed{GvQuery}
		//----------------------------------------------------------------------------------------
		GvQuery* AllocQuery(void) { return C4DOS.Gv->master->AllocQuery(this); }

		//----------------------------------------------------------------------------------------
		/// Frees GV query objects allocated with AllocQuery().
		/// @param[in,out] query					@theToDestruct{query object}
		//----------------------------------------------------------------------------------------
		void FreeQuery(GvQuery *&query) { C4DOS.Gv->master->FreeQuery(this, query); }

		/// @}

		/// @name Init
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a GV init object. Must be freed with FreeInit().
		/// @return												The allocated GV init object. @callerOwnsPointed{GvInit}
		//----------------------------------------------------------------------------------------
		GvInit* AllocInit(void) { return C4DOS.Gv->master->AllocInit(this); }

		//----------------------------------------------------------------------------------------
		/// Frees GV init objects allocated with AllocInit().
		/// @param[in,out] init						@theToDestruct{GV init object}
		//----------------------------------------------------------------------------------------
		void FreeInit(GvInit *&init) { C4DOS.Gv->master->FreeInit(this, init); }

		/// @}

		/// @name User Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// Registers a user data pointer with the node master. The user data pointers are only stored for the current session.
		/// @param[in] data								The initial value of the user data.
		/// @return												The ID of the registered pointer.
		//----------------------------------------------------------------------------------------
		GvUserDataID RegisterUserData(void *data = nullptr) { return C4DOS.Gv->master->RegisterUserData(this, data); }

		//----------------------------------------------------------------------------------------
		/// Sets the user data pointer.
		/// @param[in] id									The user data ID.
		/// @param[in] data								The new user data.
		//----------------------------------------------------------------------------------------
		void SetUserData(GvUserDataID id, void *data) { C4DOS.Gv->master->SetUserData(this, id, data); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the user data pointer.
		/// @param[in] id									The user data ID.
		/// @return												The user data pointer.
		//----------------------------------------------------------------------------------------
		void* GetUserData(GvUserDataID id) { return C4DOS.Gv->master->GetUserData(this, id); }

		/// @}

		/// @name Calculation Table
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates an allocation table. The allocated table must be freed with FreeCalculationTable().
		/// @param[in] cpu_count					The CPU count. Normally @em 1.
		/// @param[in] sort								If @formatConstant{true} the table is sorted to reflect the hierarchy.
		/// @param[in] nr_of_preallocated_entries	The space is preallocated for this many entries. The table will still grow if necessary.
		/// @param[in] iteration					@formatConstant{true} if this is an iteration path.
		/// @return												The allocated calculation table. @callerOwnsPointed{table}
		//----------------------------------------------------------------------------------------
		GvCalcTable* AllocCalculationTable(Int32 cpu_count, Bool sort = true, Int32 nr_of_preallocated_entries = 16, Bool iteration = false) { return C4DOS.Gv->master->AllocCalculationTable(this, cpu_count, sort, nr_of_preallocated_entries, iteration); }

		//----------------------------------------------------------------------------------------
		/// Frees calculation tables allocated with AllocCalculationTable().
		/// @param[in] table							@theToDestruct{table}
		//----------------------------------------------------------------------------------------
		void FreeCalculationTable(GvCalcTable *&table) { C4DOS.Gv->master->FreeCalculationTable(this, table); }

		/// @}

		/// @name Draw List
		/// @{

		//----------------------------------------------------------------------------------------
		/// Adds a node the internal list of nodes that need GvOperatorData::SceneDraw() called during the next internal draw.
		/// @param[in] bn									The node to add. @callerOwnsPointed{node}
		/// @param[in] data								This should either be @formatConstant{nullptr} or point to a data pointer.\n
		/// 															The function allocates a memory block of @formatParam{data_size} bytes and stores a pointer to it in @formatParam{data}.\n
		/// 															Store custom data in this memory block that GvOperatorData::SceneDraw() use.\n
		/// 															@callerOwnsPointed{data} @theOwnsPointed{node master,data}
		/// @param[in] data_size					The size of @formatParam{data} in bytes. Stored and passed to the draw list call.
		/// @return												@trueIfOtherwiseFalse{the node was added to the draw list}
		//----------------------------------------------------------------------------------------
		Bool AddToDrawList(GvNode *bn, void **data = nullptr, Int32 data_size = 0) { return C4DOS.Gv->master->AddToDrawList(this, bn, data, data_size); }

		/// @}

		/// @name Copy Buffer
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a copy buffer. Must be freed with FreeCopyBuffer(). Paste the buffer with PasteFromBuffer().
		/// @param[in] first							The optional first node of the hierarchy to be copied. @callerOwnsPointed{node}
		/// @param[in] copy_selected			If @formatConstant{true} (default) the selected objects are copied.
		/// @return												The allocated copy buffer. @callerOwnsPointed{buffer}
		//----------------------------------------------------------------------------------------
		GvCopyBuffer* GetCopyBuffer(GvNode *first = nullptr, Bool copy_selected = true) { return C4DOS.Gv->master->GetCopyBuffer(this, first, copy_selected); }

		//----------------------------------------------------------------------------------------
		/// Frees copy buffers allocated with GetCopyBuffer().
		/// @param[in] buffer							@theToDestruct{buffer}
		//----------------------------------------------------------------------------------------
		void FreeCopyBuffer(GvCopyBuffer *&buffer) { C4DOS.Gv->master->FreeCopyBuffer(this, buffer); }

		//----------------------------------------------------------------------------------------
		/// Pastes the contents of a copy buffer created with GetCopyBuffer().
		/// @param[in] buffer							The buffer to paste.
		/// @param[in] mode								The insert mode: @enumerateEnum{GvInsertMode}
		/// @param[out] dest							An optional destination node. @callerOwnsPointed{node}
		/// @param[out] x									An optional destination X coordinate.
		/// @param[out] y									An optional destination Y coordinate.
		/// @param[in] center							If @formatParam{true} the pasted nodes are centered.
		/// @param[in] info								Internal parameter. Must always be @formatConstant{nullptr}.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool PasteFromBuffer(GvCopyBuffer &buffer, GvInsertMode mode = GV_INSERT_UNDER, GvNode *dest = nullptr, Int32 x = GV_INVALID_POS_VALUE, Int32 y = GV_INVALID_POS_VALUE, Bool center = false, void *info = nullptr) { return C4DOS.Gv->master->PasteFromBuffer(this, buffer, mode, dest, x, y, center, info); }

		/// @}

		/// @name Preferences
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the preferences for the node master.
		/// @param[in] bc									The new preferences. Use these container IDs: @enumerateEnum{GvMasterConfigIDs}
		//----------------------------------------------------------------------------------------
		void SetPrefs(const BaseContainer &bc) { C4DOS.Gv->master->MasterSetPrefs(this, bc); }

		//----------------------------------------------------------------------------------------
		/// Gets the preferences for the node master.
		/// @param[out] bc								Filled with the current preferences. Use these container IDs: @enumerateEnum{GvMasterConfigIDs}
		//----------------------------------------------------------------------------------------
		void GetPrefs(BaseContainer &bc) { C4DOS.Gv->master->MasterGetPrefs(this, bc); }

		/// @}

		/// @name Undo
		/// @{

		//----------------------------------------------------------------------------------------
		/// Adds changes made in the node master to the undo list.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool AddUndo(void) { return C4DOS.Gv->master->AddUndo(this); }

		/// @}

		/// @name Execute2
		/// @{

		//----------------------------------------------------------------------------------------
		/// Equivalent to Execute() but additional @formatParam{flags} are used for the calculation.
		/// @param[in] thread							The thread to use for break checks. @callerOwnsPointed{thread}
		/// @param[in] flags							The calculation flags: @enumerateEnum{GvCalcFlags}
		/// @return												The result of the execution.
		//----------------------------------------------------------------------------------------
		GvCalcError Execute2(BaseThread *thread, GvCalcFlags flags) { return C4DOS.Gv->master->Execute2(this, thread, flags); }

		/// @}
};

//----------------------------------------------------------------------------------------
/// GV node GUI helper class. Cannot be instantiated.
//----------------------------------------------------------------------------------------
class GvNodeGUI
{
	private:
		GvNodeGUI();
		~GvNodeGUI();

	public:
		/// @name Attach/Detach
		/// @{

		//----------------------------------------------------------------------------------------
		/// Attaches the node GUI to @formatParam{dialog} and @formatParam{master}.
		/// @note Normally you do not need to call this function.
		/// @param[in] dialog							A dialog. @callerOwnsPointed{dialog}
		/// @param[in] master							A node master. @callerOwnsPointed{node master}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Attach(GeDialog *dialog, GvNodeMaster *master) { return C4DOS.Gv->gui->GuiAttach(this, dialog, master); }

		//----------------------------------------------------------------------------------------
		/// Detaches the node GUI.
		/// @note Normally you do not need to call this function.
		//----------------------------------------------------------------------------------------
		void Detach(void) { C4DOS.Gv->gui->GuiDetach(this); }

		/// @}

		/// @name User Area Events
		/// @{

		//----------------------------------------------------------------------------------------
		/// Handles mouse down messages routed from the user area.
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @param[in] chn								The channel.
		/// @param[in] qa									The qualifiers.
		/// @param[in] msg								The message container.
		//----------------------------------------------------------------------------------------
		void MouseDown(Int32 x, Int32 y, Int32 chn, Int32 qa, const BaseContainer &msg) { C4DOS.Gv->gui->GuiMouseDown(this, x, y, chn, qa, msg); }

		//----------------------------------------------------------------------------------------
		/// Handles messages routed from the user area.
		/// @param[in] msg								The message container.
		/// @param[in] result							A container to place results in.
		/// @return												@trueIfOtherwiseFalse{the message was handled}
		//----------------------------------------------------------------------------------------
		Int32 Message(const BaseContainer &msg, BaseContainer &result) { return C4DOS.Gv->gui->GuiMessage(this, msg, result); }

		//----------------------------------------------------------------------------------------
		/// Handles commands routed from the user area.
		/// @param[in] id									The command ID.
		/// @return												The command result.
		//----------------------------------------------------------------------------------------
		Int32 Command(Int32 id) { return C4DOS.Gv->gui->GuiCommand(this, id); }

		/// @}

		/// @name Draw/Redraw
		/// @{

		//----------------------------------------------------------------------------------------
		/// Draws the window content. Called by GeUserArea::DrawMsg().
		//----------------------------------------------------------------------------------------
		void Draw(void) { C4DOS.Gv->gui->GuiDraw(this); }

		//----------------------------------------------------------------------------------------
		/// Redraws the node GUI and calls all draw hooks attached to the node master. Called by GvNodeMaster.
		//----------------------------------------------------------------------------------------
		void Redraw(void) { C4DOS.Gv->gui->GuiRedraw(this); }

		/// @}

		/// @name Get User Area/Node Master/Dialog
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the user area for the node GUI.
		/// @return												The user area. @theOwnsPointed{node GUI,user area}
		//----------------------------------------------------------------------------------------
		GeUserArea* GetUserArea(void) { return C4DOS.Gv->gui->GuiGetUserArea(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the node master for the node GUI.
		/// @return												The node master. @theOwnsPointed{node GUI,node master}
		//----------------------------------------------------------------------------------------
		GvNodeMaster* GetMaster(void) { return C4DOS.Gv->gui->GuiGetMaster(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the dialog for the node GUI.
		/// @return												The dialog. @theOwnsPointed{node GUI,dialog}
		//----------------------------------------------------------------------------------------
		GeDialog* GetDialog(void) { return C4DOS.Gv->gui->GuiGetDialog(this); }

		/// @}

		/// @name Select/Focus
		/// @{

		//----------------------------------------------------------------------------------------
		/// Selects all nodes.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] select_state				The selection state.
		/// @param[in] add_to_selection		If @formatConstant{true} the node is added to the selection.
		//----------------------------------------------------------------------------------------
		void SelectAllNodes(GvNode *node, Bool select_state, Bool add_to_selection = false) { C4DOS.Gv->gui->GuiSelectAllNodes(this, node, select_state, add_to_selection); }

		//----------------------------------------------------------------------------------------
		/// Removes all selected nodes.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		void RemoveAllSelectedNodes(GvNode *node) { C4DOS.Gv->gui->GuiRemoveAllSelectedNodes(this, node); }

		//----------------------------------------------------------------------------------------
		/// Selects a node.
		/// @param[in] node								The node to select. @callerOwnsPointed{node}
		/// @param[in] select_state				The selection state.
		/// @param[in] add_to_selection		If @formatConstant{true} the node is added to the selection.
		/// @param[in] send_message				If @formatConstant{true} a message is sent about the selection.
		//----------------------------------------------------------------------------------------
		void SelectNode(GvNode *node, Bool select_state, Bool add_to_selection = false, Bool send_message = true) { C4DOS.Gv->gui->GuiSelectNode(this, node, select_state, add_to_selection, send_message); }

		//----------------------------------------------------------------------------------------
		/// Disables or enables a node.
		/// @param[in] node								The node to disable or enable. @callerOwnsPointed{node}
		/// @param[in] disable_state			@formatConstant{true} means disabled, @formatConstant{false} means enabled.
		//----------------------------------------------------------------------------------------
		void DisableSelected(GvNode *node, Bool disable_state) { C4DOS.Gv->gui->GuiDisableSelected(this, node, disable_state); }

		//----------------------------------------------------------------------------------------
		/// Sets the focus to @formatParam{node}.
		/// @param[in] node								The node to focus. @callerOwnsPointed{node}
		/// @param[in] activate						@formatConstant{true} to activate the node, @formatConstant{false} to deactivate.
		//----------------------------------------------------------------------------------------
		void SetFocus(GvNode *node, Bool activate) { C4DOS.Gv->gui->GuiSetFocus(this, node, activate); }

		/// @}

		/// @name Get Node at Position
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the node at the global position (@formatParam{x}, @formatParam{y}).
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												The found node, or @formatConstant{nullptr} if there was no match. @theOwnsPointed{node GUI,node}
		//----------------------------------------------------------------------------------------
		GvNode* GetNodeGlobal(Int32 x, Int32 y) { return C4DOS.Gv->gui->GuiGetNodeGlobal(this, x, y); }

		//----------------------------------------------------------------------------------------
		/// Gets the node at the local position (@formatParam{x}, @formatParam{y}).
		/// @param[in] node								The node for the local coordinates. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												The found node, or @formatConstant{nullptr} if there was no match. @theOwnsPointed{node GUI,node}
		//----------------------------------------------------------------------------------------
		GvNode* GetNodeLocal(GvNode *node, Int32 x, Int32 y) { return C4DOS.Gv->gui->GuiGetNodeLocal(this, node, x, y); }

		/// @}

		/// @name Check in Node Position
		/// @{

		//----------------------------------------------------------------------------------------
		/// Checks if the position (@formatParam{x}, @formatParam{y}) is inside the body of @formatParam{node}.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the position is in the body}
		//----------------------------------------------------------------------------------------
		Bool IsInNodeBody(GvNode *node, Int32 x, Int32 y) { return C4DOS.Gv->gui->GuiIsInNodeBody(this, node, x, y); }

		//----------------------------------------------------------------------------------------
		/// Checks if the position (@formatParam{x}, @formatParam{y}) is inside the head of @formatParam{node}.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the position is in the head}
		//----------------------------------------------------------------------------------------
		Bool IsInNodeHead(GvNode *node, Int32 x, Int32 y) { return C4DOS.Gv->gui->GuiIsInNodeHead(this, node, x, y); }

		/// @}

		/// @name Preferences
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the preferences for the node GUI.
		/// @param[in] bc									The new preferences. Use these container IDs: @enumerateEnum{GvGuiConfigIDs}
		//----------------------------------------------------------------------------------------
		void SetPrefs(const BaseContainer &bc) { C4DOS.Gv->gui->GuiSetPrefs(this, bc); }

		//----------------------------------------------------------------------------------------
		/// Gets the preferences for the node GUI.
		/// @param[out] bc								Filled with the current preferences. Use these container IDs: @enumerateEnum{GvGuiConfigIDs}
		//----------------------------------------------------------------------------------------
		void GetPrefs(BaseContainer &bc) { C4DOS.Gv->gui->GuiGetPrefs(this, bc); }

		/// @}

		/// @name Set Node Position/Size
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the global position of @formatParam{node} to (@formatParam{x}, @formatParam{y}).
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @param[in] center							If @formatConstant{true} the node is centered.
		//----------------------------------------------------------------------------------------
		void SetNodePosGlobal(GvNode *node, Int32 x, Int32 y, Bool center = false) { C4DOS.Gv->gui->GuiSetNodePosGlobal(this, node, x, y, center); }

		//----------------------------------------------------------------------------------------
		/// Sets the position of @formatParam{node} to (@formatParam{x}, @formatParam{y}).
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		//----------------------------------------------------------------------------------------
		void SetNodePos(GvNode *node, Int32 x, Int32 y) { C4DOS.Gv->gui->GuiSetNodePos(this, node, x, y); }

		//----------------------------------------------------------------------------------------
		/// Sets the size of @formatParam{node}.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[in] width							The width.
		/// @param[in] height							The height.
		//----------------------------------------------------------------------------------------
		void SetNodeSize(GvNode *node, Int32 width, Int32 height) { C4DOS.Gv->gui->GuiSetNodeSize(this, node, width, height); }

		//----------------------------------------------------------------------------------------
		/// Optimizes the size of @formatParam{node}.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		void OptimizeNode(GvNode *node) { C4DOS.Gv->gui->GuiOptimizeNode(this, node); }

		/// @}

		/// @name Node Utilities
		/// @{

		//----------------------------------------------------------------------------------------
		/// Shows all nodes.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		void ShowAllNodes(GvNode *node) { C4DOS.Gv->gui->GuiShowAllNodes(this, node); }

		//----------------------------------------------------------------------------------------
		/// Centers nodes.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		void CenterNodes(GvNode *node) { C4DOS.Gv->gui->GuiCenterNodes(this, node); }

		//----------------------------------------------------------------------------------------
		/// Aligns all nodes to the upper left.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		void AlignNodesToUpperLeft(GvNode *node) { C4DOS.Gv->gui->GuiAlignNodesToUpperLeft(this, node); }

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the zoom of @formatParam{node}.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @param[out] zoom							This value is multiplied by the zoom factor.
		//----------------------------------------------------------------------------------------
		void GetZoom(GvNode *node, Float &zoom) { C4DOS.Gv->gui->GuiGetZoom(this, node, zoom); }

		//----------------------------------------------------------------------------------------
		/// Initializes the node GUI shapes.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool InitShapes(void) { return C4DOS.Gv->gui->GuiInitShapes(this); }

		//----------------------------------------------------------------------------------------
		/// Opens the context menu of node.
		/// @param[in] node								The node. @callerOwnsPointed{node}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool NodeContextMenu(GvNode *node) { return C4DOS.Gv->gui->GuiNodeContextMenu(this, node); }

		/// @}
};

//----------------------------------------------------------------------------------------
/// The GV world class. Cannot be instantiated. To retrieve the global instance call GvGetWorld().
//----------------------------------------------------------------------------------------
class GvWorld
{
	private:
		GvWorld();
		~GvWorld();

	public:
		/// @name Alloc/Free Node Master
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a node master. Must be freed with FreeNodeMaster().
		/// @note This function is normally not needed. Use XPressoTag::Alloc() instead.
		/// @param[in] object							The parent object for the node master. @callerOwnsPointed{object}
		/// @param[in] add_to_list				Add this master to the global list of masters. To have a private master, set this to @formatConstant{false}.
		/// @param[in] send_messages			If @formatConstant{true} messages are sent to object for example when nodes are added.
		/// @return												The allocated node master. @callerOwnsPointed{node master}
		//----------------------------------------------------------------------------------------
		GvNodeMaster* AllocNodeMaster(BaseList2D *object, Bool add_to_list = true, Bool send_messages = true) { return C4DOS.Gv->world->AllocNodeMaster(this, object, add_to_list, send_messages); }

		//----------------------------------------------------------------------------------------
		/// Frees node masters allocated with AllocNodeMaster().
		/// @param[in,out] master					@theToDestruct{node master}
		//----------------------------------------------------------------------------------------
		void FreeNodeMaster(GvNodeMaster *&master) { C4DOS.Gv->world->FreeNodeMaster(this, master); }

		/// @}

		/// @name Alloc/Free Node GUI
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a node GUI. Must be freed with FreeNodeGUI().
		/// @note This function is normally not needed.
		/// @param[in] shape							The GV shape. @callerOwnsPointed{shape}
		/// @param[in] group							The group shape. @callerOwnsPointed{group shape}
		/// @param[in] user_area_id				The user area ID.
		/// @return												The allocated node GUI. @callerOwnsPointed{node GUI}
		//----------------------------------------------------------------------------------------
		GvNodeGUI* AllocNodeGUI(GvShape *shape, GvShape *group, Int32 user_area_id) { return C4DOS.Gv->world->AllocNodeGUI(this, shape, group, user_area_id); }

		//----------------------------------------------------------------------------------------
		/// Frees node GUIs allocated with AllocNodeGUI().
		/// @param[in,out] gui						@theToDestruct{node GUI}
		//----------------------------------------------------------------------------------------
		void FreeNodeGUI(GvNodeGUI *&gui) { C4DOS.Gv->world->FreeNodeGUI(this, gui); }

		/// @}

		/// @name Alloc/Free Shape
		/// @{

		//----------------------------------------------------------------------------------------
		/// Allocates a shape. Must be freed with FreeShape().
		/// @note A shape defines the layout of the nodes and the click behavior. It is completely private, but maybe in future versions it will be possible to use different shapes.
		/// @return												The allocated shape. @callerOwnsPointed{shape}
		//----------------------------------------------------------------------------------------
		GvShape* AllocShape(void) { return C4DOS.Gv->world->AllocShape(this); }

		//----------------------------------------------------------------------------------------
		/// Allocates a group shape. Must be freed with FreeShape().
		/// @note A shape defines the layout of the nodes and the click behavior. It is completely private, but maybe in future versions it will be possible to use different shapes.
		/// @return												The allocated group shape. @callerOwnsPointed{group shape}
		//----------------------------------------------------------------------------------------
		GvShape* AllocGroupShape(void) { return C4DOS.Gv->world->AllocGroupShape(this); }

		//----------------------------------------------------------------------------------------
		/// Frees shapes allocated with AllocShape() or AllocGroupShape().
		/// @param[in,out] shape					@theToDestruct{shape}
		//----------------------------------------------------------------------------------------
		void FreeShape(GvShape *&shape) { C4DOS.Gv->world->FreeShape(this, shape); }

		/// @}

		/// @name Hook
		/// @{

		//----------------------------------------------------------------------------------------
		/// Registers a hook. See GvHook for more information.
		/// @param[in] hook								The hook to register.
		/// @param[in] user								The user data pointer for the hook. Passed to the hook functions. @callerOwnsPointed{data}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool RegisterHook(const GvHook &hook, void *user) { return C4DOS.Gv->world->RegisterHook(this, hook, user); }

		//----------------------------------------------------------------------------------------
		/// Attaches a callback to a hook. The callback function is evaluated with GetHookInstance().
		/// @param[in] hook_id						The hook ID.
		/// @param[in] callback						The callback to register.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool AttachHook(Int32 hook_id, GvHookCallback callback) { return C4DOS.Gv->world->AttachHook(this, hook_id, callback); }

		//----------------------------------------------------------------------------------------
		/// Detaches a callback attached with AttachHook(). This makes GetHookInstance() return @formatConstant{nullptr} for @formatParam{hook_id}.
		/// @param[in] hook_id						The hook ID.
		//----------------------------------------------------------------------------------------
		void DetachHook(Int32 hook_id) { C4DOS.Gv->world->DetachHook(this, hook_id); }

		//----------------------------------------------------------------------------------------
		/// Returns @c (*callback)(@formatParam{doc}, @formatParam{hook_id}) for callbacks registered with AttachHook().
		/// @param[in] doc								The document. @callerOwnsPointed{document}
		/// @param[in] hook_id						The hook ID.
		/// @return												The callback return, or @formatConstant{nullptr} if no callback was attached.
		//----------------------------------------------------------------------------------------
		BaseList2D* GetHookInstance(BaseDocument *doc, Int32 hook_id) { return C4DOS.Gv->world->GetHookInstance(this, doc, hook_id); }

		/// @}

		/// @name Send Message
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sends a message to all hooks with the given @formatParam{owner_id} set in GvHook::owner_id.
		/// @param[in] doc								The document. @callerOwnsPointed{document}
		/// @param[in] master							The node master. @callerOwnsPointed{node master}
		/// @param[in] data								The message data.
		/// @param[in] owner_id						The owner ID.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SendHookMessage(BaseDocument *doc, GvNodeMaster *master, GvMessHook &data, Int32 owner_id) { return C4DOS.Gv->world->SendHookMessage(this, doc, master, data, owner_id); }

		//----------------------------------------------------------------------------------------
		/// Sends a message to all nodes, i.e. calls NodeData::Message() for all GvOperatorData.
		/// @param[in] doc								The document. @callerOwnsPointed{document}
		/// @param[in] message_id					The message ID.
		/// @param[in] data								The message data. @callerOwnsPointed{data}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SendOperatorMessage(BaseDocument *doc, Int32 message_id, void *data) { return C4DOS.Gv->world->SendOperatorMessage(this, doc, message_id, data); }

		/// @}

		/// @name Dialog
		/// @{

		//----------------------------------------------------------------------------------------
		/// Opens the XPresso dialog for a specific node master.
		/// @param[in] id									The plugin ID. See GeDialog::Open().
		/// @param[in] master							The node master to open the dialog for. @callerOwnsPointed{node master}
		/// @return												@trueIfOtherwiseFalse{the dialog was opened}
		//----------------------------------------------------------------------------------------
		Bool OpenDialog(Int32 id, GvNodeMaster *master) { return C4DOS.Gv->world->OpenDialog(this, id, master); }

		//----------------------------------------------------------------------------------------
		/// Closes a dialog opened with OpenDialog().
		/// @param[in] id									The plugin ID that the dialog was opened with.
		//----------------------------------------------------------------------------------------
		void CloseDialog(Int32 id) { C4DOS.Gv->world->CloseDialog(this, id); }

		/// @}

		/// @name Redraw
		/// @{

		//----------------------------------------------------------------------------------------
		/// Redraws all opened dialogs.
		/// @note Currently there can only be one dialog, so this is for future extensions.
		//----------------------------------------------------------------------------------------
		void RedrawAll(void) { C4DOS.Gv->world->RedrawAll(this); }

		//----------------------------------------------------------------------------------------
		/// Redraws a node master.
		/// @param[in] master							The node master to redraw. @callerOwnsPointed{node master}
		//----------------------------------------------------------------------------------------
		void RedrawMaster(GvNodeMaster *master) { C4DOS.Gv->world->RedrawMaster(this, master); }

		//----------------------------------------------------------------------------------------
		/// Attaches a node to a node master.
		/// @param[in] master							The node master to attach the node to. @callerOwnsPointed{node master}
		/// @param[in] node								The node to attach. @callerOwnsPointed{node}
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the node was attached}
		//----------------------------------------------------------------------------------------
		Bool AttachNode(GvNodeMaster *master, GvNode *node, Int32 x, Int32 y) { return C4DOS.Gv->world->AttachNode(this, master, node, x, y); }

		/// @}

		/// @name Get String/Float/Integer
		/// @{

		//----------------------------------------------------------------------------------------
		/// Opens a dialog where the user can enter a string value.
		/// @param[in] title							The dialog title.
		/// @param[in] default_value			The default value.
		/// @return												The string entered by the user.
		//----------------------------------------------------------------------------------------
		const String GetString(const maxon::String &title, const maxon::String &default_value) { return C4DOS.Gv->world->GetString(this, title, default_value); }

		//----------------------------------------------------------------------------------------
		/// Opens a dialog where the user can enter a float value.
		/// @param[in] title							The dialog title.
		/// @param[in] default_value			The default value.
		/// @return												The float entered by the user.
		//----------------------------------------------------------------------------------------
		Float GetFloat(const maxon::String &title, Float default_value) { return C4DOS.Gv->world->GetFloat(this, title, default_value); }

		//----------------------------------------------------------------------------------------
		/// Opens a dialog where the user can enter an integer value.
		/// @param[in] title							The dialog title.
		/// @param[in] default_value			The default value.
		/// @return												The integer entered by the user.
		//----------------------------------------------------------------------------------------
		Int32 GetInteger(const maxon::String &title, Int32 default_value) { return C4DOS.Gv->world->GetInteger(this, title, default_value); }

		/// @}

		/// @name Data Types Information
		/// @{

		//----------------------------------------------------------------------------------------
		/// Fills @formatParam{bc} with a menu description of all data types, suitable for e.g. ShowPopupMenu().\n
		/// The @formatParam{index} container is a translation between the menu ID and the @ref GvDataID of the data types.\n
		/// Optionally the set of data types can be restricted to only those that allows a set of calculation @formatParam{flags}.
		/// @param[in] bc									Filled with the menu entries.
		/// @param[in] index							Filled with a translation table between menu ID and @ref GvDataID.
		/// @param[in] first_menu_id			The first menu item ID. You can pass @ref FIRST_POPUP_ID.
		/// @param[in] first_sub_id				The first sub menu item ID. Use something slightly larger than @formatParam{first_menu_id}, for example @ref FIRST_POPUP_ID + @em 1000.
		/// @param[in] show_undefined_type	If @formatParam{true} the data type "Undefined" is included where needed.
		/// @param[in] flags							If set, only data types that can handle these calculations are retrieved: @enumerateEnum{GvValueFlags}
		/// @return												The number of data types found.
		//----------------------------------------------------------------------------------------
		Int32 GetDataTypesMenu(BaseContainer &bc, BaseContainer &index, Int32 first_menu_id, Int32 first_sub_id, Bool show_undefined_type = false, GvValueFlags flags = GV_CALC_NOP) { return C4DOS.Gv->world->GetDataTypesMenu(this, bc, index, first_menu_id, first_sub_id, show_undefined_type, flags); }

		//----------------------------------------------------------------------------------------
		/// Fills @formatParam{bc} with a description of all data types, as String values with the name of the data type and an ID with the corresponding @ref GvDataID.\n
		/// Optionally the set of data types can be restricted to only those that allows a set of calculation @formatParam{flags}.
		/// @param[in] bc									Filled with the data types.
		/// @param[in] options						The data options: @enumerateEnum{GvDataOptions}
		/// @param[in] flags							If set, only data types that can handle these calculations are retrieved: @enumerateEnum{GvValueFlags}
		/// @return												The number of data types found.
		//----------------------------------------------------------------------------------------
		Int32 GetDataTypes(BaseContainer &bc, GvDataOptions options = GV_DATA_OPTIONS_NONE, GvValueFlags flags = GV_CALC_NOP) { return C4DOS.Gv->world->GetDataTypes(this, bc, options, flags); }

		//----------------------------------------------------------------------------------------
		/// Retrieves the complete data types table.
		/// @param[out] info							Set to point to an array of length @formatParam{count} with the currently registered data types. @theOwnsPointed{GV world,array}
		/// @param[out] count							Assigned the number of elements in the retrieved @formatParam{info} table.
		/// @return												@trueIfOtherwiseFalse{the table was retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetDataTypesTable(GvDataInfo *&info, Int32 &count) { return C4DOS.Gv->world->GetDataTypesTable(this, info, count); }

		//----------------------------------------------------------------------------------------
		/// Gets the index of the given data type in the data type table returned by GetDataTypesTable().
		/// @param[in] id									The ID of the data type to look for.
		/// @return												The index of the data type.
		//----------------------------------------------------------------------------------------
		Int32 GetDataTypeIndex(GvDataID id) { return C4DOS.Gv->world->GetDataTypeIndex(this, id); }

		//----------------------------------------------------------------------------------------
		/// Gets the data type information for a data type.
		/// @param[in] id									The data type ID.
		/// @return												The data type information. @theOwnsPointed{GV world,information}
		//----------------------------------------------------------------------------------------
		GvDataInfo* GetDataTypeInfo(GvDataID id) { return C4DOS.Gv->world->GetDataTypeInfo(this, id); }

		//----------------------------------------------------------------------------------------
		/// Fills @formatParam{bc} with a description of the data types with IDs in @formatParam{ids}, just as GetDataTypes().
		/// @param[in] bc									Filled with the data type names.
		/// @param[in] ids								A zero terminated array of data type IDs. @callerOwnsPointed{array}
		/// @return												The number of data types found.
		//----------------------------------------------------------------------------------------
		Int32 GetDataTypeNames(BaseContainer &bc, GvDataID *ids) { return C4DOS.Gv->world->GetDataTypeNames(this, bc, ids); }

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Gets the default operator icon for an operator @formatParam{type}.
		/// @param[in] type								The operator type: @enumerateEnum{GvOperatorType}
		/// @return												The default operator icon. @theOwnsPointed{GV world,bitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* GetDefaultOperatorIcon(GvOperatorType type) { return C4DOS.Gv->world->GetDefaultOperatorIcon(this, type); }

		//----------------------------------------------------------------------------------------
		/// Returns the GV node master.
		/// @param[in] id									The node GUI index. Currently not used, should be set to @em 0. This is for future extensions.
		/// @return												The node master. @theOwnsPointed{GV world,node master}
		//----------------------------------------------------------------------------------------
		GvNodeMaster* GetMaster(Int32 id) { return C4DOS.Gv->world->GetMaster(this, id); }

		//----------------------------------------------------------------------------------------
		/// Gets the node GUI for a node master.
		/// @note Return @formatConstant{nullptr} if the XPresso window has not been opened yet.
		/// @param[in] master							The node master to get the GUI for. @callerOwnsPointed{node master}
		/// @param[in] nr									The node GUI index. Currently not used, should be set to @em 0. This is for future extensions.
		/// @return												The node GUI for master. @theOwnsPointed{GV world,node GUI}
		//----------------------------------------------------------------------------------------
		GvNodeGUI* GetMasterGUI(GvNodeMaster *master, UInt32 nr = 0) { return C4DOS.Gv->world->GetMasterGUI(this, master, nr); }

		//----------------------------------------------------------------------------------------
		/// Gets a unique ID. The generated ID is unique within the GvWorld during the session only.
		/// @return												The generated unique ID for the session.
		//----------------------------------------------------------------------------------------
		UInt32 GetUniqueID(void) { return C4DOS.Gv->world->GetUniqueID(this); }

		//----------------------------------------------------------------------------------------
		/// Sets a flag that forces nodes to compute for the rest of the current scene evaluation even if the time since the last evaluation has not changed.
		/// @since R16.050
		//----------------------------------------------------------------------------------------
		void SetForceUpdate(void) { return C4DOS.Gv->world->SetForceUpdate(this); }

		/// @}

		/// @name Preferences
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the preferences for the GV world.
		/// @param[in] bc									The new preferences. Use these container IDs: @enumerateEnum{GvWorldConfigIDs}
		//----------------------------------------------------------------------------------------
		void SetPrefs(const BaseContainer &bc) { C4DOS.Gv->world->WorldSetPrefs(this, bc); }

		//----------------------------------------------------------------------------------------
		/// Gets the preferences for the GV world.
		/// @param[out] bc								Filled with the current preferences. Use these container IDs: @enumerateEnum{GvWorldConfigIDs}
		//----------------------------------------------------------------------------------------
		void GetPrefs(BaseContainer &bc) { C4DOS.Gv->world->WorldGetPrefs(this, bc); }

		/// @}
};


//----------------------------------------------------------------------------------------
/// Retrieves the GV world.
/// @return												The GV world. @cinemaOwnsPointed{GV world}
//----------------------------------------------------------------------------------------
GvWorld* GvGetWorld(void);

//----------------------------------------------------------------------------------------
/// Gets an empty string, just like String() would do.
/// @return												An empty string.
//----------------------------------------------------------------------------------------
const String GvGetEmptyString(void);

//----------------------------------------------------------------------------------------
/// Returns an error string for display in for example the status bar. The format is currently <i>Status: &lt;command&gt; error!</i>, where @b error is determined by @formatParam{err}.
/// @param[in] command						The command string.
/// @param[in] err								The error ID. Either a @ref GvError value, in which case an appropriate error string is loaded, or another number that is passed through String::IntToString().
/// @return												The error string.
//----------------------------------------------------------------------------------------
const String GvGetErrorString(const maxon::String &command, Int32 err);

//----------------------------------------------------------------------------------------
/// Gets the port list from the information in info.
/// @param[in] info								The port description. @callerOwnsPointed{port description}
/// @param[in] port								The port IO mode: @enumerateEnum{GvPortIO}
/// @param[out] portlist					Entries are added to this list.
//----------------------------------------------------------------------------------------
void GvGetPortList(GvPortsDescInfo *info, GvPortIO port, GvPortList &portlist);

//----------------------------------------------------------------------------------------
/// Fills @formatParam{pd} with information from @formatParam{info} for the specified port.
/// @param[in] info								The port description. @callerOwnsPointed{port description}
/// @param[in] port								The port IO mode: @enumerateEnum{GvPortIO}
/// @param[in] id									The port ID.
/// @param[out] pd								Filled with the port information about port @formatParam{id} from @formatParam{info}.
/// @return												@trueIfOtherwiseFalse{succesful}
//----------------------------------------------------------------------------------------
Bool GvGetPortDescription(GvPortsDescInfo *info, GvPortIO port, Int32 id, GvPortDescription *pd);

//----------------------------------------------------------------------------------------
/// Fills info with data type information. Free the structure with GvFreePortDescInfo().
/// @param[in] info								The port description to fill. @callerOwnsPointed{port description}
/// @param[in] default_flag				The default flag for the GvPortDescInfo::flags array.
/// @param[in] first_id						The first ID for the GvPortDescInfo::ids array. All data type IDs are offset by this amount.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvGetAllDataTypes(GvPortDescInfo *info, UInt32 default_flag, Int32 first_id);

//----------------------------------------------------------------------------------------
/// Frees port description structures allocated with GvGetAllDataTypes().
/// @param[out] info							The port description to free.
//----------------------------------------------------------------------------------------
void GvFreePortDescInfo(GvPortDescInfo *info);


//----------------------------------------------------------------------------------------
/// Registers an operator class. See @ref GV_OPCLASS_HANDLER for more information.
/// @param[in] data								The handler structure. @callerOwnsPointed{structure}\n
/// 															Make sure that the passed structure has a long enough life time. The easiest way is to use a static or global variable.
/// @param[in] struct_size				The size of the structure passed to @formatParam{data}, i.e. @c sizeof(*@formatParam{data}).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvRegisterOpClassType(GV_OPCLASS_HANDLER *data, Int32 struct_size);

//----------------------------------------------------------------------------------------
/// Registers an operator group. See @ref GV_OPGROUP_HANDLER for more information.
/// @param[in] data								The handler structure. @callerOwnsPointed{structure}\n
/// 															Make sure that the passed structure has a long enough life time. The easiest way is to use a static or global variable.
/// @param[in] struct_size				The size of the structure passed to @formatParam{data}, i.e. @c sizeof(*@formatParam{data}).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvRegisterOpGroupType(GV_OPGROUP_HANDLER *data, Int32 struct_size);

//----------------------------------------------------------------------------------------
/// Registers a value type. See @ref GV_VALUE_HANDLER for more information.
/// @param[in] data								The handler structure. @callerOwnsPointed{structure}\n
/// 															Make sure that the passed structure has a long enough life time. The easiest way is to use a static or global variable.
/// @param[in] struct_size				The size of the structure passed to @formatParam{data}, i.e. @c sizeof(*@formatParam{data}).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvRegisterValueType(GV_VALUE_HANDLER *data, Int32 struct_size);

//----------------------------------------------------------------------------------------
/// Registers a data type. See @ref GV_DATA_HANDLER for more information.
/// @param[in] data								The handler structure. @callerOwnsPointed{structure}\n
/// 															Make sure that the passed structure has a long enough life time. The easiest way is to use a static or global variable.
/// @param[in] struct_size				The size of the structure passed to @formatParam{data}, i.e. @c sizeof(*@formatParam{data}).
/// @param[in] symbol							The data type symbol. @callerOwnsPointed{character buffer}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvRegisterDataType(GV_DATA_HANDLER *data, Int32 struct_size, const char *symbol = nullptr);

//----------------------------------------------------------------------------------------
/// Registers a value group type. See @ref GV_VALGROUP_HANDLER for more information.
/// @param[in] data								The handler structure. @callerOwnsPointed{structure}\n
/// 															Make sure that the passed structure has a long enough life time. The easiest way is to use a static or global variable.
/// @param[in] struct_size				The size of the structure passed to @formatParam{data}, i.e. @c sizeof(*@formatParam{data}).
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvRegisterValGroupType(GV_VALGROUP_HANDLER *data, Int32 struct_size);

//----------------------------------------------------------------------------------------
/// Finds a registered operator class by ID.
/// @param[in] id									The operator class ID to find.
/// @return												The found class handler, or @formatConstant{nullptr}. @cinemaOwnsPointed{class handler}
//----------------------------------------------------------------------------------------
GV_OPCLASS_HANDLER* GvFindRegisteredOpClass(GvOpClassID id);

//----------------------------------------------------------------------------------------
/// Finds a registered operator group by ID.
/// @param[in] id									The operator group ID to find.
/// @return												The found group handler, or @formatConstant{nullptr}. @cinemaOwnsPointed{group handler}
//----------------------------------------------------------------------------------------
GV_OPGROUP_HANDLER* GvFindRegisteredOpGroup(GvOpGroupID id);


//----------------------------------------------------------------------------------------
/// Gets the detailed text for an operator, containing @formatParam{bn}->@link GvNode::GetTitle GetTitle()@endlink and @formatParam{op}->@link GvOperatorData::GetText GetText()@endlink.
/// @param[in] op									The operator to get the text for. @callerOwnsPointed{GvOperatorData}
/// @param[in] bn									The node to get the title for. @callerOwnsPointed{GvNode}
/// @return												The operator detailed text.
//----------------------------------------------------------------------------------------
const String				GvGetOperatorDetailedText(GvOperatorData *op, GvNode *bn);

//----------------------------------------------------------------------------------------
/// Gets the title for an operator, containing either @formatParam{bn}->@link GvNode::GetTitle GetTitle()@endlink or @c GeLoadString(string_id) if the title is empty.
/// @param[in] bn									The node to get the title for. @callerOwnsPointed{GvNode}
/// @param[in] string_id					The string ID to load if the title is empty.
/// @return												The operator title.
//----------------------------------------------------------------------------------------
const String GvGetOperatorTitle(GvNode *bn, Int32 string_id);


//----------------------------------------------------------------------------------------
/// Frees value tables allocated with the direct versions of the GvBuildValuesTable() functions.
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] ports							TODO: (Sdkteam) describe
//----------------------------------------------------------------------------------------
void GvFreeValuesTable(GvNode *bn, maxon::BaseArray<GvValue*>& ports);

//----------------------------------------------------------------------------------------
/// Frees value tables allocated with the GvValuesInfo versions of the GvBuildValuesTable() functions.
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] info							The values info structure to free. The freed pointers are set to @formatConstant{nullptr}.
//----------------------------------------------------------------------------------------
void GvFreeValuesTable(GvNode *bn, GvValuesInfo &info);

//----------------------------------------------------------------------------------------
/// Builds an input values table for @formatParam{bn} for the specified @formatParam{ids}.\n
/// Use GvCalculateInValuesTable() to calculate the values, and then get the values from @formatParam{ports}.\n
/// Free the values table with GvFreeValuesTable().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[in] ports							TODO: (Sdkteam) describe
/// @param[in] c									The current calculation helper. @callerOwnsPointed{calculation helper}
/// @param[in] r									The current run helper. @callerOwnsPointed{run helper}
/// @param[in] ids								A zero terminated array of port IDs or one of these constants: @enumerateEnum{GV_PORTS}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvBuildInValuesTable(GvNode *bn, maxon::BaseArray<GvValue*>& ports, GvCalc *c, GvRun *r, Int32 *ids);

//----------------------------------------------------------------------------------------
/// Builds an output values table for @formatParam{bn}. Then set the values in ports. Free the values table with GvFreeValuesTable().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] ports							TODO: (Sdkteam) describe
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvBuildOutPortsTable(GvNode *bn, maxon::BaseArray<GvPort*>& ports);

//----------------------------------------------------------------------------------------
/// A combination of GvBuildInValuesTable() and GvBuildOutPortsTable().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] in_ports					TODO: (Sdkteam) describe
/// @param[out] out_ports					TODO: (Sdkteam) describe
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvBuildValuesTable(GvNode *bn, maxon::BaseArray<GvPort*>& in_ports, maxon::BaseArray<GvPort*>& out_ports);

//----------------------------------------------------------------------------------------
/// Calls GvValue::Calculate() for all input ports in @formatParam{info}.
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[in] run								The current run helper. @callerOwnsPointed{run helper}
/// @param[in] calc								The current calculation helper. @callerOwnsPointed{calculation helper}
/// @param[out] info							The values information structure with the value tables to calculate.
/// @param[in] singleport					The port index. @ref GV_MULTIPLE_PORTS (default) calculates all ports.
/// @param[in] time								If not @formatConstant{nullptr} animation tracks of the node at @formatParam{time} are evaluated before the calculation.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GvCalculateInValuesTable(GvNode *bn, GvRun *run, GvCalc *calc, GvValuesInfo &info, Int32 singleport = GV_MULTIPLE_PORTS, BaseTime *time = nullptr);


inline Bool GvBuildInValuesTable(GvNode *bn, GvValuesInfo &info, GvCalc *c, GvRun *r, GvIdTablePtr ids)
{
	return GvBuildInValuesTable(bn, info.in_values, c, r, ids);
}

inline Bool GvBuildOutValuesTable(GvNode *bn, GvValuesInfo &info)
{
	return GvBuildOutPortsTable(bn, info.out_ports);
}

inline Bool GvBuildValuesTable(GvNode *bn, GvValuesInfo &info, GvCalc *c, GvRun *r, GvIdTablePtr input_ids)
{
	if (!GvBuildInValuesTable(bn, info, c, r, input_ids)) return false;
	if (!GvBuildOutValuesTable(bn, info)) return false;
	return true;
}


//----------------------------------------------------------------------------------------
/// Gets data info for an element in the operator container of @formatParam{bn}.
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[in] id									The container ID.
/// @return												The data type information. @theOwnsPointed{GV world,GvDataInfo}
//----------------------------------------------------------------------------------------
inline GvDataInfo* GvGetDataInfo(GvNode *bn, Int32 id)
{
	BaseContainer *bc = bn->GetOpContainerInstance(); if (!bc) return nullptr;
	return GvGetWorld()->GetDataTypeInfo(bc->GetInt32(id));
}

//----------------------------------------------------------------------------------------
/// Checks if there is a data info available for an element in the operator container of @formatParam{bn}.
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[in] id									The container ID.
/// @return												@trueIfOtherwiseFalse{there is a data info}
//----------------------------------------------------------------------------------------
inline Bool GvCheckDataInfo(GvNode *bn, Int32 id)
{
	BaseContainer *bc = bn->GetOpContainerInstance(); if (!bc) return false;
	return GvGetWorld()->GetDataTypeInfo(bc->GetInt32(id)) != nullptr;
}

//----------------------------------------------------------------------------------------
/// Allocates a dynamic data structure suitable for an element in the operator container of @formatParam{bn}.\n
/// Free the allocated @formatParam{data} with GvFreeDynamicData().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] data							The dynamic data to allocate.
/// @param[in] c									The current calculation helper. @callerOwnsPointed{calculation helper}
/// @param[in] id									The container ID.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool GvAllocDynamicData(GvNode *bn, GvDynamicData &data, GvCalc *c, Int32 id)
{
	data.cpu_count = c->cpu_count;
	data.info = GvGetDataInfo(bn, id);
	return (data.info && data.cpu_count) ? data.info->value_handler->Alloc(data.info->value_handler->userdata, data.data, data.cpu_count) : false;
}

//----------------------------------------------------------------------------------------
/// Frees the dynamic data in @formatParam{data}.
/// @param[in,out] data						The dynamic data to free. The associated pointers are set to @formatConstant{nullptr}.
//----------------------------------------------------------------------------------------
inline void GvFreeDynamicData(GvDynamicData &data)
{
	if (data.data)
	{
		data.info->value_handler->Free(data.info->value_handler->userdata, data.data, data.cpu_count);
		data.data = nullptr;
	}
	data.info = nullptr;
	data.cpu_count = 0;
}

//----------------------------------------------------------------------------------------
/// Clears the dynamic data in @formatParam{data}, i.e. performs a @ref GV_CALC_CLR calculation. This version of the function clears the data for the CPU specified by @formatParam{r}->@link GvRun::GetCpuID GetCpuID()@endlink.
/// @param[in,out] data						The dynamic data to clear.
/// @param[in] r									The current run helper. @callerOwnsPointed{run helper}
//----------------------------------------------------------------------------------------
inline void GvClearDynamicData(GvDynamicData &data, GvRun *r)
{
	data.info->value_handler->Calculate(data.info->value_handler->userdata, data.info->value_handler->value_id, nullptr, nullptr, data.data, r->GetCpuID(), GV_CALC_CLR, 0.0);
}

//----------------------------------------------------------------------------------------
/// Clears the dynamic data in @formatParam{data}, i.e. performs a @ref GV_CALC_CLR calculation. This version of the function clears the data for all CPUs.
/// @param[in,out] data						The dynamic data to clear.
//----------------------------------------------------------------------------------------
inline void GvClearDynamicData(GvDynamicData &data)
{
	Int32 i;
	for (i = 0; i < data.cpu_count; ++i)
	{
		data.info->value_handler->Calculate(data.info->value_handler->userdata, data.info->value_handler->value_id, nullptr, nullptr, data.data, i, GV_CALC_CLR, 0.0);
	}
}

//----------------------------------------------------------------------------------------
/// A combination of GvAllocDynamicData() and GvClearDynamicData().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] data							The dynamic data to allocate and clear.
/// @param[in] c									The current calculation helper. @callerOwnsPointed{calculation helper}
/// @param[in] id									The container ID.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool GvAllocDynamicDataClear(GvNode *bn, GvDynamicData &data, GvCalc *c, Int32 id)
{
	if (! GvAllocDynamicData(bn, data, c, id)) return false;
	GvClearDynamicData(data);
	return true;
}

//----------------------------------------------------------------------------------------
/// Allocates a dynamic @formatParam{data} structure suitable for for the data type described in @formatParam{info}. Free the allocated data with GvFreeDynamicData().
/// @param[in] bn									The node. @callerOwnsPointed{GvNode}
/// @param[out] data							The dynamic data to allocate.
/// @param[in] info								Data type specification.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool GvAllocDynamicData(GvNode *bn, GvDynamicData &data, GvDataInfo *info)
{
	data.cpu_count = 1;
	data.info = info;
	return (data.info) ? data.info->value_handler->Alloc(data.info->value_handler->userdata, data.data, data.cpu_count) : false;
}


//----------------------------------------------------------------------------------------
/// Sets data in @formatParam{bc} at @formatParam{container_id}.
/// @param[in] data								The data to set. @callerOwnsPointed{data}\n
/// 															Points to GV data. The layout of the pointed data is determined by @formatParam{value_id}.
/// @param[in] value_id						Determines the type of @formatParam{data}.
/// @param[in] bc									The container to set the value in.
/// @param[in] container_id				The container ID to set.
/// @param[in] cpu_id							The CPU ID.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool GvSetDataInContainer(const void* const data, GvValueID value_id, BaseContainer &bc, Int32 container_id, Int32 cpu_id = 0)
{
	CUSTOMDATATYPEPLUGIN* pl = FindCustomDataTypePlugin(value_id); if (!pl) return false;
	GeData ge_data; CallCustomDataType(pl, ConvertGvToGeData)(data, cpu_id, ge_data);
	bc.SetData(container_id, ge_data);
	return true;
}

//----------------------------------------------------------------------------------------
/// A safe cast from GeListNode to GvNode.
/// @param[in] bn									The list node to cast. @callerOwnsPointed{node}
/// @return												The cast node pointer.
//----------------------------------------------------------------------------------------
inline GvNode* GetNode(GeListNode *bn) { DebugAssert(bn->GetType() == ID_GV_NODEDATA || bn->GetType() == ID_GV_GROUPDATA); return (GvNode*)bn; }


/// @}

#endif // C4D_GRAPHVIEW_H__
