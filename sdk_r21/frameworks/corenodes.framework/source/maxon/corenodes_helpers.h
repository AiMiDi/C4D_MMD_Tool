#ifndef CORENODES_HELPERS_H__
#define CORENODES_HELPERS_H__

#include "maxon/graph_basics.h"
#include "maxon/factory.h"

#ifdef DOMAIN
	#undef DOMAIN // normally defined by math.h to indicate a domain error which can be reported by matherr()
#endif

namespace maxon
{

namespace corenodes
{

//----------------------------------------------------------------------------------------
/// When a port or micro node is connected to a micro node, the access index tells at which index
/// the MicroNode receives the connection's transported value within the Ports/Batch parameter
/// of the Process method. For indices exceeding INDEX_3 just cast from Int to ACCESS_INDEX.
/// There are also some built-in micro nodes with several parameter connections, they use the
/// access index to identify which connection controls which parameter. Each access index
/// (other than UNUSED) may be used by at most one connection of a micro node.
//----------------------------------------------------------------------------------------
enum class ACCESS_INDEX : Int
{
	UNUSED = -1,	///< The value isn't part of the Ports/Batch parameter of the Process method.
	INDEX_0 = 0,	///< The value is accessed at index 0.
	INDEX_1 = 1,	///< The value is accessed at index 1.
	INDEX_2 = 2,	///< The value is accessed at index 2.
	INDEX_3 = 3		///< The value is accessed at index 3.
} MAXON_ENUM_LIST(ACCESS_INDEX);


//----------------------------------------------------------------------------------------
/// Core nodes and micro nodes instances and their ports can be connected by wires.
/// The wires are given as a set of WIRETYPE flags.
//----------------------------------------------------------------------------------------
enum class WIRETYPE
{
	NONE = 0,

	// A FLOW wire represents the flow of execution. Typically there is a parallel DOMAIN wire and a parallel VALUE wire.
	FLOW = 0x0001,

	// A DOMAIN wire adds the domain of the source to the domain of the target. This is always set in parallel to a FLOW or STATE wire unless the target is a list or group node.
	DOMAIN = 0x0002,

	// can be set in parallel to FLOW or DOMAIN, this enforces a nesting in the execution tree
	HIERARCHY = 0x0004,

	// A VALUE wire transports the value of its source to its target. Usually this is in parallel to a FLOW wire so that it represents data flow.
	// But when the flow of execution wants to read a value which has been set by a different flow, then there is only a VALUE wire from that value.
	PURE_VALUE = 0x0008,

	STATE_VALUE = 0x0010,

	VALUE = PURE_VALUE | STATE_VALUE,

	DOMAIN_FLOW = DOMAIN | FLOW,
	DOMAIN_FLOW_VALUE = DOMAIN | FLOW | VALUE,
	DOMAIN_FLOW_PURE_VALUE = DOMAIN | FLOW | PURE_VALUE,

	LIFETIME = 0x0020,
	DEEPLY_SEQUENCED = 0x0040,
	SEQUENCED = 0x0080,

	DOMAIN_FLOW_SEQUENCED = DOMAIN_FLOW | SEQUENCED | DEEPLY_SEQUENCED,
	DOMAIN_FLOW_VALUE_SEQUENCED = DOMAIN_FLOW_VALUE | SEQUENCED | DEEPLY_SEQUENCED,
	DOMAIN_FLOW_PURE_VALUE_SEQUENCED = DOMAIN_FLOW_PURE_VALUE | SEQUENCED | DEEPLY_SEQUENCED,

	DOMAIN_FLOW_SEQUENCED_LIFETIME = DOMAIN_FLOW_SEQUENCED | LIFETIME,
	DOMAIN_FLOW_VALUE_SEQUENCED_LIFETIME = DOMAIN_FLOW_VALUE_SEQUENCED | LIFETIME,
	DOMAIN_FLOW_PURE_VALUE_SEQUENCED_LIFETIME = DOMAIN_FLOW_PURE_VALUE_SEQUENCED | LIFETIME,

	INDUCED_SEQUENCED = 0x0100,
	PASSTHROUGH = 0x00200, // can be set in parallel to VALUE or STATE from an input port to an output port
	STATE = 0x0400,
	ALIAS = 0x0800,
	MARK = 0x1000, // internally used to mark specific wires
	RECURSION = 0x2000,
	MEMBER_ALIAS = 0x4000,
	LAZY = 0x8000, // in parallel to VALUE
	TRG_MARK = 0x10000,
	FLAG_MASK = LAZY | TRG_MARK,

	PORT = 0x10000000, // not used for concrete wires, but as flag in IS_SOURCE_OF and IS_TARGET_OF to indicate that the micro node has wires to ports

	ACCESS_TEST = VALUE | STATE,

	DEPENDENCY_TEST = FLOW | DEEPLY_SEQUENCED | INDUCED_SEQUENCED | VALUE | SEQUENCED,

	ALL = 0x7fffffff & ~FLAG_MASK
} MAXON_ENUM_FLAGS(WIRETYPE);


enum class PORT_FLAGS
{
	NONE = 0,
	INPUT_WITHOUT_VALUE = 1,
	OUTPUT_UNUSED = 2
} MAXON_ENUM_FLAGS(PORT_FLAGS);


//----------------------------------------------------------------------------------------
/// A PortId identifies a port of a core node or micro node (see CoreNodeBaseInterface).
/// It can be given either by a port name or by a port index. The subclasses InPortId
/// and OutPortId have to be used unless the code shall be generic in the port direction.
//----------------------------------------------------------------------------------------
class PortId
{
public:
	//----------------------------------------------------------------------------------------
	/// Checks if this PortId is given by an Int index.
	/// @return												True if this PortId is given by an index, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsIndex() const
	{
		return _indexDir >= 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this PortId is given by a name.
	/// @return												True if this PortId is given by a name, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsName() const
	{
		return UInt(_indexDir) >= UInt(-2);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this PortId has a name or an index. Note that in the case of a name
	/// it doesn't check if the name itself is non-empty.
	/// @return												True if this PortId has a name or an index, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _indexDir >= -2;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this PortId has neither a name nor an index.
	/// @return												True if this PortId has neither a name nor an index, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _indexDir < -2;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the port index. This function must not be called if this PortId is given by a name.
	/// @return												The port index stored in this PortId.
	//----------------------------------------------------------------------------------------
	Int GetIndex() const
	{
		DebugAssert(IsIndex());
		return _indexDir >> 1;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the port name. This function must not be called if this PortId is given by an index.
	/// @return												The port name stored in this PortId.
	//----------------------------------------------------------------------------------------
	const Id& GetName() const
	{
		DebugAssert(IsName());
		return _name;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the direction of this PortId. PORT_DIR::INPUT stands for input ports,
	/// PORT_DIR::OUTPUT for output ports.
	/// @return												The port direction.
	//----------------------------------------------------------------------------------------
	PORT_DIR GetDirection() const
	{
		return PORT_DIR(_indexDir & 1);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new PortId given by a port name.
	/// @param[in] dir								The port direction.
	/// @param[in] name								The port name to use for the PortId.
	//----------------------------------------------------------------------------------------
	PortId(PORT_DIR dir, const Id& name) : _indexDir(Int(dir) - 2), _name(name)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new PortId given by a port index.
	/// @param[in] dir								The port direction.
	/// @param[in] index							The port index to use for the PortId.
	//----------------------------------------------------------------------------------------
	PortId(PORT_DIR dir, Int index) : _indexDir(Int(dir) + (index << 1))
	{
		DebugAssert(index >= 0);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an empty PortId of the given direction.
	/// @param[in] dir								The port direction.
	//----------------------------------------------------------------------------------------
	explicit PortId(PORT_DIR dir) : _indexDir(Int(dir) - 4)
	{
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs) const;

protected:
	Int _indexDir = -3; // Bit 0 set: output port, remaining bits>>1: index. If index is -1 there is no index, use _name to identify port. If _indexDir is less than -2, the PortId is empty.
	Id _name;
};


//----------------------------------------------------------------------------------------
/// An InPortId identifies an input port of a core node or micro node (see CoreNodeBaseInterface).
/// It can be given either by a port name or by a port index.
//----------------------------------------------------------------------------------------
class InPortId : public PortId
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an empty InPortId (without name or index).
	//----------------------------------------------------------------------------------------
	InPortId() : PortId(PORT_DIR::INPUT)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new InPortId given by a port name.
	/// @param[in] name								The port name to use for the InPortId.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT InPortId(const Id& name) : PortId(PORT_DIR::INPUT, name)
	{
		MAXON_ASSERT_STANDARD_LAYOUT(InPortId);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new InPortId given by a port index.
	/// @param[in] index							The port index to use for the InPortId.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT InPortId(Int index) : PortId(PORT_DIR::INPUT, index)
	{
	}

	static const InPortId& NullValue()
	{
		return _nullValue;
	}

private:
	// we have to provide a null value because the null value has some non-zero bytes
	static const InPortId _nullValue;
};


//----------------------------------------------------------------------------------------
/// An OutPortId identifies an output port of a core node or micro node (see CoreNodeBaseInterface).
/// It can be given either by a port name or by a port index.
//----------------------------------------------------------------------------------------
class OutPortId : public PortId
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an empty OutPortId (without name or index).
	//----------------------------------------------------------------------------------------
	OutPortId() : PortId(PORT_DIR::OUTPUT)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new OutPortId given by a port name.
	/// @param[in] name								The port name to use for the OutPortId.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT OutPortId(const Id& name) : PortId(PORT_DIR::OUTPUT, name)
	{
		MAXON_ASSERT_STANDARD_LAYOUT(OutPortId);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new OutPortId given by a port index.
	/// @param[in] index							The port index to use for the OutPortId.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT OutPortId(Int index) : PortId(PORT_DIR::OUTPUT, index)
	{
	}

	static const OutPortId& NullValue()
	{
		return _nullValue;
	}

private:
	// we have to provide a null value because the null value has some non-zero bytes
	static const OutPortId _nullValue;
};


//----------------------------------------------------------------------------------------
/// IdBuilder can be used to build identifiers for instantiations of generic core nodes.
/// For example the generic multiplication core node "net.maxon.corenode.mul" has instantiations
/// for several data types such as "net.maxon.corenode.mul<int64>" for the type Int64.
/// The id of the instantiation can be obtained with an IdBuilder by writing
/// @c{IdBuilder("net.maxon.corenode.mul").Append<Int>()} as in this example code:
/// @code{corenodes_idbuilder_for_add}
//! CoreNodeInstancePtr mul = g.AddChild(Id(), IdBuilder("net.maxon.corenode.mul").Append<Int>()) iferr_return;
/// @endcode
/// The constructor and Append functions of IdBuilder don't return errors, a potential
/// out-of-memory error is postponed to the final call of ToId() or ToCString().
//----------------------------------------------------------------------------------------
class IdBuilder
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a new IdBuilder where base is the part of the id before the instantiation suffix.
	/// @param[in] base								The base identifier for this IdBuilder.
	//----------------------------------------------------------------------------------------
	explicit IdBuilder(const Char* base)
	{
		AppendString(base);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new IdBuilder where base is the part of the id before the instantiation suffix.
	/// @param[in] base								The base identifier for this IdBuilder.
	//----------------------------------------------------------------------------------------
	explicit IdBuilder(const LiteralId& base)
	{
		AppendString(base.GetCString());
	}

	//----------------------------------------------------------------------------------------
	/// Appends the identifier of type to the instantiation suffix of this IdBuilder.
	/// Angular brackets and commas are appended as needed.
	/// @param[in] type								The type to append.
	/// @return												This IdBuilder.
	//----------------------------------------------------------------------------------------
	IdBuilder&& Append(const DataType& type);

	//----------------------------------------------------------------------------------------
	/// Appends the identifiers of the given types to the instantiation suffix of this IdBuilder.
	/// Angular brackets and commas are appended as needed.
	/// @tparam T											The types to append.
	/// @return												This IdBuilder.
	//----------------------------------------------------------------------------------------
	template <typename... T> IdBuilder&& Append()
	{
		return AppendImpl(GetDataType<T>()...);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the constructed identifier of this IdBuilder as an Id. If an error happened during
	/// consruction, this is reported by the call to this function.
	/// @return												The constructed identifier.
	//----------------------------------------------------------------------------------------
	Result<Id> ToId() const
	{
		iferr_scope;
		Id i;
		i.Init(_name) iferr_return;
		return i;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the constructed identifier of this IdBuilder as a CString. If an error happened during
	/// consruction, this is reported by the call to this function.
	/// @return												The constructed identifier.
	//----------------------------------------------------------------------------------------
	Result<CString> ToCString() const
	{
		if (_name.IsEmpty())
			return OutOfMemoryError(MAXON_SOURCE_LOCATION);
		return _name;
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* formatStatement) const
	{
		return String(_name);
	}

private:
	friend class IdOrBuilder;

	IdBuilder() = default;

	IdBuilder&& AppendImpl()
	{
		return std::move(*this);
	}

	template <typename... T> IdBuilder&& AppendImpl(const DataType& type, T... types)
	{
		Append(type);
		return AppendImpl(types...);
	}

	void AppendString(const Char* str);

	void AppendChar(Char ch);

	CString _name;
};


//----------------------------------------------------------------------------------------
/// This helper class wraps an Id or an IdBuilder (with implicit conversion constructors)
/// and is used for the CoreNodeGroupInterface::Add methods to allow both types as arguments.
//----------------------------------------------------------------------------------------
class IdOrBuilder
{
public:
	//----------------------------------------------------------------------------------------
	/// Implicitly constructs an IdOrBuilder from an Id.
	/// @param[in] nodeId							The Id to wrap.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT IdOrBuilder(const Id& nodeId) : _id(nodeId)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Implicitly constructs an IdOrBuilder from a LiteralId.
	/// @param[in] nodeId							The Id to wrap.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT IdOrBuilder(const LiteralId& nodeId) : _id(nodeId)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Implicitly constructs an IdOrBuilder from an IdBuilder.
	/// @param[in] builder						The IdBuilder to wrap.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT IdOrBuilder(IdBuilder&& builder) : _builder(std::move(builder))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns the wrapped identifier as an Id.
	/// @return												The wrapped identifier.
	//----------------------------------------------------------------------------------------
	Result<Id> GetId() const
	{
		iferr_scope;
		if (_id.IsPopulated())
			return _id;
		const CString& str = _builder.ToCString() iferr_return;
		Id x;
		x.Init(str) iferr_return;
		return x;
	}

private:
	Id _id;
	IdBuilder _builder;
};

}

} // namespace maxon

#endif // CORENODES_HELPERS_H__
