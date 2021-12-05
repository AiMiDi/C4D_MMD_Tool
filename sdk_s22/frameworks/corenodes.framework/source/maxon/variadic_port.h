#ifndef VARIADIC_PORT_H__
#define VARIADIC_PORT_H__

#include "maxon/micronodes_ports.h"

namespace maxon::corenodes
{

//----------------------------------------------------------------------------------------
/// VariadicPort manages ports with a dynamic number of instances.
/// The usage is documented at MicroNodeInterface::AddVariadicPort.
//----------------------------------------------------------------------------------------
template <typename T, Bool OUTPUT> class VariadicPort
{
public:
	using PortId = typename std::conditional<OUTPUT, MicroNodePtr<>, InPortId>::type;
	static constexpr MicroNode::TYPE PORT_TYPE = OUTPUT ? MicroNode::TYPE::VARIABLE : MicroNode::TYPE::VIRTUAL_INPUT_PORT;

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const CString& prefix, Int count, Int base)
	{
		iferr_scope;
		VariadicPort ports;
		ports.Init(node, prefix, (count < 0) ? 1 : count, (count < 0) ? -1 : base) iferr_return;
		return std::move(ports);
	}

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const CString& prefix, const Data& arg, const DataType& type = GetPortType<T>())
	{
		iferr_scope;
		VariadicPort ports;
		if (arg.GetType() == GetDataType<Array<VariadicInstance>>())
		{
			ports.Init(node, prefix, arg.GetOrNull<Array<VariadicInstance>>(), MicroNode::FLAGS::NONE, type) iferr_return;
		}
		else
		{
			Int count = arg.Get(Int(-1));
			ports.Init(node, prefix, (count < 0) ? 1 : count, (count < 0) ? -1 : 0, MicroNode::FLAGS::NONE, type) iferr_return;
		}
		return std::move(ports);
	}

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const Block<const Member>& members)
	{
		iferr_scope;
		VariadicPort ports;
		ports.Init(node, members) iferr_return;
		return std::move(ports);
	}

	Result<void> Init(MicroNodeGroupInterface* node, const Block<const Member>& members, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;
		_prefix = "empty"_cs;
		_template = false;
		_ports.Resize(members.GetCount()) iferr_return;
		for (Int i = 0; i < members.GetCount(); ++i)
		{
			MicroNodePtr<> ptr = node->CreatePort(members[i].name, PORT_TYPE, flags, members[i].type) iferr_return;
			Assign(_ports[i], ptr, node, members[i].name);
		}
		_group = node;
		return OK;
	}

	Result<void> Init(MicroNodeGroupInterface* node, const CString& prefix, Int count, Int base, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, const DataType& type = GetPortType<T>())
	{
		iferr_scope;
		_prefix = prefix;
		_template = base < 0;
		DebugAssert(!_template || count == 1);
		_ports.Resize(count) iferr_return;
		for (Int i = 0; i < count; ++i)
		{
			CString str = prefix;
			str.AppendChar('#') iferr_return;
			if (!_template)
			{
				str.AppendInt(base + i);
			}
			Id portId;
			portId.Init(str) iferr_return;
			MicroNodePtr<> ptr = node->CreatePort(portId, PORT_TYPE, flags, type) iferr_return;
			Assign(_ports[i], ptr, node, portId);
		}
		_group = node;
		return OK;
	}

	template <typename SUFFIXES> Result<void> Init(MicroNodeGroupInterface* node, const CString& prefix, const SUFFIXES& suffixes, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, const DataType& type = GetPortType<T>())
	{
		iferr_scope;
		_prefix = prefix;
		_template = false;
		_ports.Resize(suffixes.GetCount()) iferr_return;
		Int idx = 0;
		for (const VariadicInstance& s : suffixes)
		{
			Id portId;
			if (prefix.IsPopulated())
			{
				CString str = prefix;
				str.AppendChar('#') iferr_return;
				str.Append(s.first.GetCString(), s.first.GetCStringLength()) iferr_return;
				portId.Init(str) iferr_return;
			}
			else
			{
				portId = s.first;
			}
			MicroNodePtr<> ptr = node->CreatePort(portId, PORT_TYPE, flags, type) iferr_return;
			Assign(_ports[idx++], ptr, node, portId);
		}
		_group = node;
		return OK;
	}

	Result<void> SetType(Int index, const DataType& type)
	{
		static_assert(STD_IS_REPLACEMENT(same, typename std::decay<T>::type, Generic), "SetType can only be used for a VariadicPort with Generic type.");
		return _group.GetPointer()->PrivateGetPort(corenodes::details::SourceCodePortId(), _ports[index], type, WIRETYPE::NONE);
	}

	template <typename PORTS> class Ports
	{
	public:
		corenodes::details::PortOps<T, corenodes::details::PortArrayAccess<typename PORTS::Ports::Access>, void> operator [](Int index) const
		{
			DebugAssert(UInt(index) < UInt(_count));
			return corenodes::details::PortOps<T, corenodes::details::PortArrayAccess<typename PORTS::Ports::Access>, void>(_ports->PrivateGetPortsAccess().GetBaseData(), ACCESS_INDEX(Int(_base) + index));
		}

		class Iterator
		{
		public:
			Bool operator !=(const Iterator& other) const
			{
				return _index != other._index;
			}

			corenodes::details::PortOps<T, corenodes::details::PortArrayAccess<typename PORTS::Ports::Access>, void> operator *() const
			{
				return corenodes::details::PortOps<T, corenodes::details::PortArrayAccess<typename PORTS::Ports::Access>, void>(_ports->PrivateGetPortsAccess().GetBaseData(), ACCESS_INDEX(_index));
			}

			void operator ++()
			{
				++_index;
			}

			Int _index;
			PORTS* _ports;
		};

		Iterator begin() const
		{
			return {Int(_base), _ports};
		}

		Iterator end() const
		{
			return {Int(_base) + _count, _ports};
		}

		ACCESS_INDEX _base;
		Int _count;
		PORTS* _ports;
	};

	class Access
	{
	public:
		using ValueType = T;
		using VPort = VariadicPort;

		explicit Access(ACCESS_INDEX b = ACCESS_INDEX::UNUSED, Int cnt = 0) : _base(b), _count(cnt)
		{
		}

		Int GetCount() const
		{
			return _count;
		}

		template <typename PORTS> Ports<PORTS> operator ()(PORTS& ports) const
		{
			return {_base, _count, &ports};
		}

	private:
		ACCESS_INDEX _base;
		Int _count;
	};

	template <typename MNI> Result<void> ConnectMicroNode(MicroNodePtr<MNI> node, Access MNI::* a, WIRETYPE wtype = WIRETYPE::ALL)
	{
		iferr_scope;
		MicroNode::Base& mni = node.GetPointer()->GetImplementation().ToBase();
		Int base = Int(mni._nextFreeAccessIndex);
		Int count = 0;
		if (!_template)
		{
			for (auto it = Iterable::IndexIterator(_ports); it; ++it)
			{
				if (OUTPUT)
				{
					ACCESS_INDEX idx = ACCESS_INDEX(base + it.GetIndex());
					node.Connect(idx, reinterpret_cast<const MicroNodePtr<>&>(*it), idx, WIRETYPE::DOMAIN_FLOW_PURE_VALUE) iferr_return;
				}
				else
				{
					node.Export(reinterpret_cast<const InPortId&>(*it), wtype, ACCESS_INDEX(base + it.GetIndex())) iferr_return;
				}
			}
			count = _ports.GetCount();
			mni._nextFreeAccessIndex = ACCESS_INDEX(base + count);
		}
		if (!OUTPUT && count == 0)
		{
			// No variadic ports at all. We create a helper port which has to be connected to some domain,
			// otherwise we'd have a micro node without incoming connections.
			Id name;
			name.Init("."_cs + _prefix + "#*"_cs) iferr_return;
			node.Export(InPortId(name), wtype) iferr_return;
		}
		static_cast<MNI&>(mni.ToMicroNode()).*a = Access(ACCESS_INDEX(base), count);
		return OK;
	}

	BaseArray<PortId>& GetPorts()
	{
		return _ports;
	}

private:
	static void Assign(InPortId& p, MicroNodePtr<> ptr, MicroNodeGroupInterface* node, const Id& name)
	{
		p = node->FindPortIndex(InPortId(name));
	}

	static void Assign(MicroNodePtr<>& p, MicroNodePtr<> ptr, MicroNodeGroupInterface* node, const Id& name)
	{
		p = ptr;
	}

	MicroNodeGroupRef _group;
	BaseArray<PortId> _ports;
	Bool _template = true;
	CString _prefix;
};

}

#endif // VARIADIC_PORT_H__

