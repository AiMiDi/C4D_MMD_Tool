#ifndef VARIADIC_PORT_H__
#define VARIADIC_PORT_H__

#include "maxon/micronodes_ports.h"

namespace maxon::corenodes
{

//----------------------------------------------------------------------------------------
/// VariadicPort manages ports with a dynamic number of instances.
/// The usage is documented at MicroNodeInterface::AddVariadicPort.
//----------------------------------------------------------------------------------------
template <typename T, Bool OUTPUT_PORT, Bool WRITE> class VariadicPort
{
public:
	using PortIdType = typename std::conditional<OUTPUT_PORT, MicroNodePtr<>, InPortId>::type;
	static constexpr MicroNode::TYPE PORT_TYPE = OUTPUT_PORT ? MicroNode::TYPE::VARIABLE : MicroNode::TYPE::VIRTUAL_INPUT_PORT;

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const CString& prefix, Int count, Int base, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;
		VariadicPort ports;
		ports.Init(node, prefix, (count < 0) ? 1 : count, (count < 0) ? -1 : base, flags) iferr_return;
		return ports;
	}

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const CString& prefix, const Data& arg, const DataType& type = GetDataType<T>(), MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;
		VariadicPort ports;
		const Array<VariadicInstance>* const array = arg.GetPtr<Array<VariadicInstance>>();
		if (array)
		{
			ports.Init(node, prefix, *array, flags, type) iferr_return;
		}
		else
		{
			Int count = arg.Get(Int(-1));
			ports.Init(node, prefix, (count < 0) ? 1 : count, (count < 0) ? -1 : 0, flags, type) iferr_return;
		}
		return ports;
	}

	static Result<VariadicPort> Create(MicroNodeGroupInterface* node, const Block<const Member>& members, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;
		VariadicPort ports;
		ports.Init(node, members, flags) iferr_return;
		return ports;
	}

	Result<void> Init(MicroNodeGroupInterface* node, const Block<const Member>& members, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;

		BufferedBaseArray<Member, 10> copyMembers;
		copyMembers.CopyFrom(members) iferr_return;

		// Can't accept duplicate member ids,	since PrivateCreatePort will return an existing one thus
		// we'll and up with an uninitialized port that will crash on use.
		Int duplicateFound = -1;
		for (Int index = 0; index < copyMembers.GetCount(); ++index)
		{
			// We check for duplicates only for named ports, others will get a numeral id "_X" by default and won't cause duplicates.
			if (copyMembers[index].name.IsPopulated())
			{
				Int index2 = 0;
				for (; index2 < copyMembers.GetCount(); ++index2)
				{
					if (index != index2 && copyMembers[index].name == copyMembers[index2].name)
					{
						duplicateFound = index2;
						copyMembers[index2].name = InternedId::Create(copyMembers[index2].name.ToCString() + DataTypeLib::GetNumberedId(index2).ToCString()) iferr_return;
					}
				}
			}
		}
		if (duplicateFound >= 0)
		{
			// Set an error on port, returning an error here could fail loading scenes, that's bad.
			corenodes::CoreNodeInterface::ErrorList errors = ArrayFactory::NewBaseArray<corenodes::CoreNodeInterface::ErrorList::ValueType>() iferr_return;
			IllegalArgumentError memberError{MAXON_SOURCE_LOCATION};
			memberError.SetMessageDelegate([dupMemberName = copyMembers[duplicateFound].name] (const LanguageRef& lang, const ErrorInterface::PartFormatter& fmt) -> String
				{
					return FormatString("Member @ has duplicates in the member list.", ErrorInterface::FormatPart(lang, fmt, dupMemberName));
				});
			errors.Append(ToTuple(PortId(OUTPUT_PORT ? PORT_DIR::OUTPUT : PORT_DIR::INPUT, copyMembers[duplicateFound].name), memberError)) iferr_return;

			node->SetValue(corenodes::CoreNodeInterface::Errors, errors) iferr_return;
		}

		_prefix = "empty"_cs;
		_template = false;
		_ports.Resize(copyMembers.GetCount()) iferr_return;
		for (Int i = 0; i < copyMembers.GetCount(); ++i)
		{
			const DataType& portType = copyMembers[i].type;
			const Id& memberName = copyMembers[i].name;
			const Id& name = memberName.IsPopulated() ? memberName : DataTypeLib::GetNumberedId(i);
			MicroNodePtr<> ptr = node->PrivateCreatePort(name, PORT_TYPE, flags, portType, true) iferr_return;
			Assign(_ports[i], ptr, node, name);
		}
		_group = node;
		return OK;
	}

	Result<void> Init(MicroNodeGroupInterface* node, const CString& prefix, Int count, Int base, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, const DataType& type = GetDataType<T>())
	{
		iferr_scope;
		_prefix = prefix;
		_template = base < 0;
		DebugAssert(!_template || count == 1);
		_ports.Resize(count) iferr_return;
		for (Int i = 0; i < count; ++i)
		{
			CString str = prefix;
			str.AppendChar(g_variadicPortIdSeparator) iferr_return;
			if (!_template)
			{
				if (flags & MicroNode::FLAGS::UNDERSCORE_NUMBER_PREFIX)
				{
					str.AppendChar('_') iferr_return;
				}
				str.AppendInt(base + i);
			}
			Id portId;
			portId.Init(std::move(str)) iferr_return;
			MicroNodePtr<> ptr = node->PrivateCreatePort(portId, PORT_TYPE, flags, type, true) iferr_return;
			Assign(_ports[i], ptr, node, portId);
		}
		_group = node;
		return OK;
	}

	template <typename SUFFIXES> Result<void> Init(MicroNodeGroupInterface* node, const CString& prefix, const SUFFIXES& suffixes, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, const DataType& type = GetDataType<T>())
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
				str.AppendChar(g_variadicPortIdSeparator) iferr_return;
				str.Append(s.first.ToBlock()) iferr_return;
				portId.Init(std::move(str)) iferr_return;
			}
			else
			{
				portId = s.first;
			}
			MicroNodePtr<> ptr = node->PrivateCreatePort(portId, PORT_TYPE, flags, type, true) iferr_return;
			Assign(_ports[idx++], ptr, node, portId);
		}
		_group = node;
		return OK;
	}

	Result<void> SetType(Int index, const DataType& type)
	{
		static_assert(STD_IS_REPLACEMENT(same, typename std::decay<T>::type, Generic), "SetType can only be used for a VariadicPort with Generic type.");
		return _group.GetPointer()->PrivateGetPort(_ports[index], type, WIRETYPE::NONE);
	}

	template <typename PORTS> class Ports
	{
	public:
		using ValueType = T;
		using PortOps = corenodes::details::PortOps<corenodes::details::PortArrayAccess<T, typename PORTS::Ports::Access>, WRITE>;

		PortOps operator [](Int index) const
		{
			DebugAssert(UInt(index) < UInt(_count));
			return PortOps(_ports->PrivateGetPortsAccess().GetBaseData(), ACCESS_INDEX(Int(_base) + index));
		}

		class Iterator
		{
		public:
			Bool operator !=(const Iterator& other) const
			{
				return _index != other._index;
			}

			PortOps operator *() const
			{
				return PortOps(_ports->PrivateGetPortsAccess().GetBaseData(), ACCESS_INDEX(_index));
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

		Access() = default;

		explicit Access(ACCESS_INDEX b, Int cnt = 0) : _base(b), _count(cnt)
		{
		}

		Int GetCount() const
		{
			return _count;
		}

		template <typename PORTS> Ports<PORTS> operator ()(PORTS& ports) const
		{
			static_assert((PORTS::Ports::MODE & (PORTS_MODE::DIRECT | PORTS_MODE::VARIADIC)) != PORTS_MODE::DIRECT,
										"Variadic ports can only be used in a batch when the micronode is marked with Variadic<>.");
			return {_base, _count, &ports};
		}

	private:
		ACCESS_INDEX _base = ACCESS_INDEX::UNUSED;
		Int _count = 0;
	};

	template <typename MNI> Result<void> ConnectMicroNode(MicroNodePtr<MNI> node, Access MNI::* a, PORT_MODE mode = PORT_MODE::NONE, WIRETYPE wtype = WIRETYPE::DEFAULT)
	{
		iferr_scope;
		if ((mode & ~PORT_MODE::MODIFIERS) == PORT_MODE::NONE)
		{
			if constexpr (OUTPUT_PORT != WRITE)
			{
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "The PORT_MODE has to be given when OUTPUT_PORT != WRITE."_s);
			}
			mode |= OUTPUT_PORT ? PORT_MODE::OUTPUT : PORT_MODE::INPUT;
		}
		else
		{
			CheckArgument(!(mode & PORT_MODE::INPUT_PORT_FLAG) == OUTPUT_PORT);
			if constexpr (WRITE)
			{
				CheckArgument(mode & PORT_MODE::OUTPUT_FLAG);
			}
			else if constexpr (OUTPUT_PORT)
			{
				CheckArgument(mode & PORT_MODE::INPUT_FLAG);
			}
			else
			{
				CheckArgument((mode & ~(PORT_MODE::MODIFIERS | PORT_MODE::FINAL_FLAG)) == PORT_MODE::INPUT);
			}
		}
		MicroNode::Base& mni = node.GetPointer()->GetImplementation().ToBase();
		const Int base = Int(mni._nextFreeAccessIndex);
		Int count = 0;
		if (!_template)
		{
			for (auto it = Iterable::IndexIterator(_ports); it; ++it)
			{
				const ACCESS_INDEX idx = ACCESS_INDEX(base + it.GetIndex());
				if constexpr (OUTPUT_PORT)
				{
					node.GetPointer()->PrivateConnectPort(*it, idx, mode) iferr_return;
				}
				else
				{
					node.Export(*it, wtype | (WIRETYPE(mode) & WIRETYPE::MODE_MASK), idx) iferr_return;
				}
			}
			count = _ports.GetCount();
			mni._nextFreeAccessIndex = ACCESS_INDEX(base + count);
		}
		if (!OUTPUT_PORT && count == 0)
		{
			// No variadic ports at all. We create a helper port which has to be connected to some domain,
			// otherwise we'd have a micro node without incoming connections.
			CString name;
			name.AppendChar(g_internalPortPrefix) iferr_return;
			name.Append(_prefix) iferr_return;
			name.AppendChar(g_variadicPortIdSeparator) iferr_return;
			name.AppendChar('*') iferr_return;
			const Id nameId = Id::Create(std::move(name)) iferr_return;
			node.Export(InPortId(nameId), wtype) iferr_return;
		}
		static_cast<MNI&>(mni.ToMicroNode()).*a = Access(ACCESS_INDEX(base), count);
		return OK;
	}

	BaseArray<PortIdType>& GetPorts()
	{
		return _ports;
	}

	Int GetCount() const
	{
		return _ports.GetCount();
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
	BaseArray<PortIdType> _ports;
	Bool _template = true;
	CString _prefix;
};

}

#endif // VARIADIC_PORT_H__
