#ifndef DATADESCRIPTIONDEFINITION_INCLUDE_H__
#define DATADESCRIPTIONDEFINITION_INCLUDE_H__

#include "maxon/basearray.h"

namespace maxon
{

class RenameList
{
public:
	RenameList(const RenameList* parent = nullptr) : _parent(parent)
	{
	}

	Result<void> Add(const CString& from, const CString& to)
	{
		Pattern f = ToPattern(from);
		Pattern t = ToPattern(to);
		if (f.third != t.third)
		{
			DiagnosticOutput("* found on only one side: @ -> @", from, to);
			return OK;
		}
		return _list.Append({ f, t });
	}

	Result<InternedId> Rename(const InternedId& original) const
	{
		iferr_scope;
		InternedId id = original;
		// Apply all RenameLists one after another
		for (const RenameList* rl = this; rl; rl = rl->_parent)
		{
			for (const auto& t : rl->_list)
			{
				if (t.first.third)
				{
					// rule is "first.first*first.second -> second.first*second.second"
					CString str = id.Get().ToCString();
					if (str.StartsWith(t.first.first) && str.EndsWith(t.first.second))
					{
						id.Init(t.second.first + str.GetPart(t.first.first.GetLength(), StringEnd(-t.first.second.GetLength())) + t.second.second) iferr_return;
						break;
					}
				}
				else if (id.ToBlock() == t.first.first.GetInternalData())
				{
					// rule is "first.first -> second.first"
					id.Init(t.second.first) iferr_return;
					break;
				}
			}
		}
		if (id == original)
			id.Reset();
		return id;
	}

private:
	// for a pattern without * first is the complete pattern and the Bool is false
	// otherwise we have first*second and the Bool is true
	using Pattern = Tuple<CString, CString, Bool>;

	static Pattern ToPattern(const CString& str)
	{
		Int p = str.FindIndex('*');
		return (p < 0) ? Pattern{ str, CString(), false } : Pattern{ str.GetLeftPart(p), str.GetRightPart(p + 1), true };
	}

	BaseArray<Tuple<Pattern, Pattern>> _list;
	const RenameList* const _parent;
};

struct IncludeHelper
{
	IncludeHelper() = default;

	IncludeHelper(const IncludeHelper& parent) : _includeRenameList(&parent._includeRenameList)
	{
	}

	Bool									_ignoreExportFlag = false;
	RenameList						_includeRenameList;
	HashSet<Id>						_includeFilterAttributes;
	Tuple<Id, InternedId> _includedFromId;
	InternedId						_groupId;

	Result<void> PrepareInclude(const DataDescriptionEntry& props, const InternedId& groupId, const Tuple<Id, InternedId>& includedFromId,
		const HashSet<Id>& includeFilterAttributes);

	Result<Bool> IsFiltered(const InternedId& id) const;

	Result<void> Rename(const Id& category, const InternedId& id, DataDescriptionEntry& props) const;
};

Result<void> IncludeHelper::PrepareInclude(const DataDescriptionEntry& props, const InternedId& groupId,
	const Tuple<Id, InternedId>& includedFromId, const HashSet<Id>& includeFilterAttributes)
{
	iferr_scope;

	Id includeSymbolId = props.Get(DESCRIPTION::DATA::BASE::INCLUDE, Id());

	InternedId identifier = props.Get(DESCRIPTION::BASE::IDENTIFIER) iferr_return;

	_groupId = props.Get(DESCRIPTION::UI::BASE::GROUPID, InternedId());
	if (_groupId.IsEmpty())
		_groupId = groupId;

	BaseArray<Id> includeRename = props.Get(DESCRIPTION::DATA::BASE::INCLUDERENAME, BaseArray<Id>());
	BaseArray<Id> includeFilter = props.Get(DESCRIPTION::DATA::BASE::INCLUDEFILTER, BaseArray<Id>());

	// build translation table for renaming of ids
	for (const Id& rename : includeRename)
	{
		CString						 line = rename.ToCString();
		BaseArray<CString> parts;
		line.Split("->"_cs, true, parts) iferr_return;
		if (parts.GetCount() != 2)
			continue;

		_includeRenameList.Add(parts[0], parts[1]) iferr_return;
	}

	_ignoreExportFlag = props.Get(DESCRIPTION::DATA::BASE::GENERATEIGNOREHEADER, false);

	if (includedFromId.Get<0>().IsPopulated())
	{
		_includedFromId = includedFromId;
	}
	else
	{
		_includedFromId = Tuple<Id, InternedId>(includeSymbolId, std::move(identifier));
	}

	_includeFilterAttributes.AppendAll(includeFilterAttributes) iferr_return;
	for (const Id& e : includeFilter)
	{
		if (includeFilterAttributes.IsEmpty())
		{
			_includeFilterAttributes.Append(e) iferr_return;
		}
		else if (includeFilterAttributes.Contains(e))
		{
			_includeFilterAttributes.Append(e) iferr_return;
		}
	}

	return OK;
}

Result<maxon::Bool> IncludeHelper::IsFiltered(const InternedId& id) const
{
	iferr_scope;

	if (_includeFilterAttributes.IsPopulated())
	{
		InternedId checkid = id;

		// collect the filtered strings for enums
		String cid = id.ToString(nullptr);
		Int		 idx = cid.FindIndex('#');
		if (idx != InvalidArrayIndex)
		{
			cid.Erase(idx, StringEnd()) iferr_return;
			checkid.Init(cid) iferr_return;
		}

		if (!_includeFilterAttributes.Contains(checkid))
			return true;
	}
	return false;
}

Result<void> IncludeHelper::Rename(const Id& category, const InternedId& id, DataDescriptionEntry& props) const
{
	iferr_scope;

	InternedId renameValue = _includeRenameList.Rename(id) iferr_return;
	if (renameValue.IsPopulated())
	{
		props.Set(DESCRIPTION::BASE::IDENTIFIER, std::move(renameValue)) iferr_return;
	}

	// preset members need be renamed as well.
	ifnoerr (BaseArray<Tuple<InternedId, InternedId>> presetMembers = props.Get<BaseArray<Tuple<InternedId, InternedId>>>(DESCRIPTION::UI::BASE::PRESETMEMBERS))
	{
		for (Tuple<InternedId, InternedId>& m : presetMembers)
		{
			InternedId rv = _includeRenameList.Rename(m.Get<1>()) iferr_return;
			if (rv.IsPopulated())
			{
				m.Get<1>() = std::move(rv);
			}
		}
		props.Set(DESCRIPTION::UI::BASE::PRESETMEMBERS, std::move(presetMembers)) iferr_return;
	}

	// PARENTFOLDERID need be renamed as well.
	ifnoerr (InternedId parentFolderId = props.Get(DESCRIPTION::UI::BASE::PARENTFOLDERID))
	{
		InternedId rv = _includeRenameList.Rename(parentFolderId) iferr_return;
		if (rv.IsPopulated())
		{
			props.Set(DESCRIPTION::UI::BASE::PARENTFOLDERID, std::move(rv)) iferr_return;
		}
	}

	if (category == DATADESCRIPTION_CATEGORY_UI && _groupId.IsPopulated())
	{
		// Set groupId from include command if there is no such id yet.
		InternedId gid = props.Get(DESCRIPTION::UI::BASE::GROUPID, InternedId());
		if (gid.IsEmpty())
		{
			props.Set(DESCRIPTION::UI::BASE::GROUPID, _groupId) iferr_return;
		}
	}
	return OK;
}

}
#endif // DATADESCRIPTIONDEFINITION_INCLUDE_H__
