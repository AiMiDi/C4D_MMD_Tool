#include "maxon/nodesgraph_helpers.h"

#include "maxon/nodes_all.h"
#include "maxon/nodesgraph.h"

namespace maxon
{

namespace nodes
{

const Data* TemplateArguments::GetImpl(const NodePath& path, KIND kind) const
{
	const Data* d = nullptr;
	if (_args.GetPointer())
	{
		d = _args.GetPointer()->PrivateGetData(ConstDataPtr(ToTuple(path, kind | KIND::DEDUCED)));
		if (!d)
		{
			d = _args.GetPointer()->PrivateGetData(ConstDataPtr(ToTuple(path, kind | KIND::EXPLICIT)));
			if (!d)
			{
				d = _args.GetPointer()->PrivateGetData(ConstDataPtr(ToTuple(path, kind)));
			}
		}
	}
	return d;
}

Result<void> TemplateArguments::Add(const TemplateArguments& args)
{
	iferr_scope;
	for (const auto& a : args._args)
	{
		_args.SetData(ConstDataPtr(a.first), a.second) iferr_return;
	}
	return OK;
}

Bool InstantiationTrace::ContainsImpl(const NodeTemplate& t, const TemplateArguments* args, const void* extra) const
{
	for (const InstantiationTrace* i = this; i; i = i->_parent)
	{
		if (i->_template == t && (!args || i->_arguments == *args) && i->_extra == extra)
		{
			// There already is an equal instantiation.
			return true;
		}
	}
	return false;
}

Bool InstantiationTrace::ContainsImpl(const Id& t, const TemplateArguments* args, const void* extra) const
{
	for (const InstantiationTrace* i = this; i; i = i->_parent)
	{
		if (i->_template.GetId() == t && (!args || i->_arguments == *args) && i->_extra == extra)
		{
			// There already is an equal instantiation.
			return true;
		}
	}
	return false;
}

template <typename S> Result<MutableRoot> NodeSystemInterface::Hxx1::COWReferenceFunctionsImpl<S>::BeginModification(Bool keepCurrent)
{
	if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError())
		return this->GetErrorStorage();
	if (MAXON_UNLIKELY(!this->GetPointer()))
		return PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);
	NodeSystem sys;
	if (keepCurrent)
	{
		sys = this->GetPointer();
	}
	NodeSystemInterface* w = this->MakeWritable(false).GetPointer();
	if (MAXON_UNLIKELY(!w))
		return PrivateGetNullReturnError(NULL_RETURN_REASON::MAKE_WRITABLE_FAILED);
	iferr (w->BeginModificationImpl())
		return err;
	Swap(sys, this->PrivateGetRefMember());
	return MutableRoot(std::move(sys));
}

template Result<MutableRoot> NodeSystem::ReferenceBaseSuper::BeginModification(Bool);
template Result<MutableRoot> Result<NodeSystem>::Base::BeginModification(Bool);

template <typename S> Result<MutableRoot> NodeSystemInterface::Hxx1::COWReferenceFunctionsImpl<S>::BeginInstantiationModification(const NodeTemplate& templ)
{
	iferr_scope;
	if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError())
		return this->GetErrorStorage();
	const NodeSystemInterface* ptr = this->GetPointer();
	if (MAXON_UNLIKELY(!ptr))
		return PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);

	TemplateArguments args = ptr->GetArguments();
	AssetRepositoryRef repo = ptr->GetTemplateLookupRepository();
	MutableRoot root = BeginModification(false) iferr_return;
	root.GetNodeSystem().GetPointer()->SetTemplate(repo, templ, args, false) iferr_return;
	return root;
}

template Result<MutableRoot> NodeSystem::ReferenceBaseSuper::BeginInstantiationModification(const NodeTemplate&);
template Result<MutableRoot> Result<NodeSystem>::Base::BeginInstantiationModification(const NodeTemplate&);

template <typename S> Result<MutableRoot> NodeSystemInterface::Hxx1::COWReferenceFunctionsImpl<S>::BeginSubstitutionModification(const AssetRepositoryRef& lookup, const NodeTemplate& original, const TemplateArguments& args)
{
	iferr_scope;
	if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError())
		return this->GetErrorStorage();
	const NodeSystemInterface* ptr = this->GetPointer();
	if (MAXON_UNLIKELY(!ptr || !original))
		return PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);

	MutableRoot root = BeginModification(false) iferr_return;
	root.GetNodeSystem().GetPointer()->SetTemplate(lookup, original, args, true) iferr_return;
	return root;
}

template Result<MutableRoot> NodeSystem::ReferenceBaseSuper::BeginSubstitutionModification(const AssetRepositoryRef& lookup, const NodeTemplate& original, const TemplateArguments& args);
template Result<MutableRoot> Result<NodeSystem>::Base::BeginSubstitutionModification(const AssetRepositoryRef& lookup, const NodeTemplate& original, const TemplateArguments& args);

Result<NodeSystem> NodeTemplateInterface::Instantiate(const InstantiationTrace& parent, Result<TemplateArguments>&& args) const
{
	if (args == FAILED)
		return args.GetErrorStorage();
	return Instantiate(parent, args.GetValue());
}

Result<NodeSystem> NodeTemplateInterface::Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const TemplateArguments& args) const
{
	if (!cls)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);
	return Instantiate(InstantiationTrace(cls, repo), args);
}

Result<NodeSystem> NodeTemplateInterface::Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const DataDictionary& additionalContext, const TemplateArguments& args) const
{
	if (!cls)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);
	return Instantiate(InstantiationTrace(cls, repo, additionalContext), args);
}

Result<void> GNode::InitFromPath(const NodeSystem& system, const NodePath& path, NODE_KIND check)
{
	return NodesLib::PrivateInitFromPath(*this, system, path, check);
}

Result<void> MutableGNode::InitFromPath(NodeSystemInterface* system, const NodePath& path, NODE_KIND check)
{
	return NodesLib::PrivateInitFromPath(*this, system, path, check);
}

String GNodeBase::ToString(const FormatStatement* fs) const
{
	return NodesLib::PrivateGNodeToString(*this, fs);
}


Result<NodeSystem> MutableRoot::EndModification(Opt<ChangeList&> list, NodeSystem::FINALIZE_FLAGS finalize)
{
	iferr_scope;
	Validate(list) iferr_return;
	_node.Reset();
	_system->EndModificationImpl(list, finalize) iferr_return;
	return std::move(reinterpret_cast<NodeSystem&>(_system));
}

MutableRoot::~MutableRoot()
{
	reinterpret_cast<NodeSystem&>(_system) = nullptr;
}

Result<MutableNode> MutableRoot::AddChild(const Id& child, const Result<NodeSystem>& base, Opt<ChangeList&> list) const
{
	iferr_scope;
	CheckState(_system);
	const NodeSystem& b = base iferr_return;
	return maxon::nodes::details::ConstructGNodeResult<MutableNode>(_system, _system->AddChild(child, b, list));
}

Result<MutableNode> MutableRoot::AddChild(const Id& child, const Result<NodeTemplate>& base, const TemplateArguments& args, const AssetRepositoryRef& lookup, Opt<ChangeList&> list) const
{
	iferr_scope;
	CheckState(_system);
	const NodeTemplate& templ = base iferr_return;
	NodeSystem b = templ.Instantiate(_system->GetNodeSystemClass(), lookup ? lookup : templ.GetRepository(), args) iferr_return;
	return maxon::nodes::details::ConstructGNodeResult<MutableNode>(_system, _system->AddChild(child, b, list));
}

Result<ChangeList> MutableRoot::ReplaceBase(const NodeSystem& base, Opt<ChangeList&> list) const
{
	iferr_scope;
	CheckState(_system);
	return _system->ReplaceBase(base, list);
}

Result<ChangeList> MutableRoot::ReplaceChild(const InternedId& child, const NodeSystem& base, Opt<ChangeList&> list) const
{
	iferr_scope;
	CheckState(_system);
	return _system->ReplaceChildren(ToSingletonBlock(Tuple<InternedId, NodeSystem>{child, base}), list);
}

Result<void> MutableRoot::Validate(Opt<ChangeList&> list) const
{
	iferr_scope;
	CheckState(_system);
	return _system->Validate(list);
}

Result<void> MutableRoot::SetTemplate(const InstantiationTrace& trace, const NodeTemplate& templ, const TemplateArguments& args) const
{
	iferr_scope;
	CheckState(_system);
	return _system->SetTemplate(trace.GetLookupRepository(), templ, args, true);
}

Result<void> MutableRoot::SetDerivationHandler(const NodeSystemDerivationHandler& handler) const
{
	iferr_scope;
	CheckState(_system);
	return _system->SetDerivationHandler(handler);
}

template <typename BASE> Result<MutablePort> MutablePortListFunctions<BASE>::AddPort(const Id& portId, GNODE_FLAGS flags) const
{
	PRIVATE_MAXON_NODEFN_PROLOGUE;
	return maxon::nodes::details::ConstructGNodeResult<typename SFINAEHelper<MutablePort, BASE>::type>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->AddChild(this->GetHandle(), portId, flags, nullptr));
}

template <typename BASE> Result<MutablePort> MutablePortListFunctions<BASE>::AddPort(const Id& portId, Opt<ChangeList&> list) const
{
	PRIVATE_MAXON_NODEFN_PROLOGUE;
	return maxon::nodes::details::ConstructGNodeResult<typename SFINAEHelper<MutablePort, BASE>::type>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->AddChild(this->GetHandle(), portId, GNODE_FLAGS::NONE, list));
}

template <typename BASE> Result<MutablePort> MutablePortListFunctions<BASE>::FindOrAddPort(const Id& portId, Opt<ChangeList&> list) const
{
	PRIVATE_MAXON_NODEFN_PROLOGUE;
	InternedId iid;
	iid.Init(portId) iferr_return;
	GNodeHandle i = this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), iid, NODE_KIND::PORT_MASK) iferr_return;
	if (!i)
	{
		i = this->GetNodeSystem().GetPointer()->AddChild(this->GetHandle(), portId, GNODE_FLAGS::NONE, list) iferr_return;
	}
	return typename SFINAEHelper<MutablePort, BASE>::type(this->GetNodeSystem(), i);
}

template class MutablePortListFunctions<MutableGNodeBase>;
template class MutablePortListFunctions<maxon::nodes::details::GNodeResultBase<ResultBase<MutablePortList>>>;
template class MutablePortListFunctions<maxon::nodes::details::GNodeResultBase<ResultBase<MutablePort>>>;

template <typename BASE> Result<void> MutablePortFunctions<BASE>::Connect(Result<MutablePort>&& target, Wires modes, Opt<ChangeList&> list) const
{
	if (target == FAILED)
		return target.GetErrorStorage();
	PRIVATE_MAXON_NODEFN_PROLOGUE;
	CheckArgumentDebugStop(target.GetValue().GetNodeSystem().GetPointer() == this->GetNodeSystem().GetPointer());
	return this->GetNodeSystem().GetPointer()->Connect(this->GetHandle(), target.GetValue().GetHandle(), modes, list);
}

template <typename BASE> Result<Bool> MutablePortFunctions<BASE>::SetConnectionValue(const MutablePort& target, CONNECTION_POSITION position, const InternedId& attr, ForwardingDataPtr&& value, Opt<ChangeList&> list) const
{
	PRIVATE_MAXON_NODEFN_PROLOGUE;
	return this->GetNodeSystem().GetPointer()->SetConnectionValue(this->GetHandle(), target.GetHandle(), position, attr, std::move(value), list);
}

template class MutablePortFunctions<MutableGNodeBase>;
template class MutablePortFunctions<maxon::nodes::details::GNodeResultBase<ResultBase<MutablePort>>>;

Result<GraphNode> NodesGraphModelInterface::AddChild(const Id& child, const NodeTemplate& templ, const TemplateArguments& args)
{
	iferr_scope;
	NodeSystem sys = templ.Instantiate(GetNodeSystem().GetNodeSystemClass(), GetLookupRepository(), args) iferr_return;
	return AddChild(child, sys);
}

}

} // namespace maxon
