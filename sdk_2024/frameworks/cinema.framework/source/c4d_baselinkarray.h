/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASELINKARRAY_H__
#define C4D_BASELINKARRAY_H__

#ifdef __API_INTERN__
	#include "c4d_alias.h"
	#include "objectarray.h"
#else
	#include "c4d_baselist.h"
#endif

#include "ge_autoptr.h"
#include "maxon/basearray.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

//----------------------------------------------------------------------------------------
/// A helper class to handle BaseLink instances.
//----------------------------------------------------------------------------------------
class BaseLinkArray : protected maxon::BaseArray<BaseLink*>
{
	using SUPER = maxon::BaseArray<BaseLink*>;

public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~BaseLinkArray()
	{
		FlushAll();
	}

	using SUPER::operator[];
	using SUPER::IsEmpty;
	using SUPER::Begin;
	using SUPER::End;

	//----------------------------------------------------------------------------------------
	/// Frees all the base links in the array.
	//----------------------------------------------------------------------------------------
	void FlushAll()
	{
		BaseLink* c; Int32 i;

		for (i = 0; i < GetCount(); ++i)
		{
			c = (*this)[i];
			if (!c)
				continue;
			BaseLink::Free(c);
		}
		SUPER::Reset();
	}

	Int32 GetCount() const 
	{
		return (Int32)SUPER::GetCount();
	}
	/// @}

	/// @name Get link/atom/baselist
	/// @{

	//----------------------------------------------------------------------------------------
	/// Searches for a specific @formatParam{bl} in the array and returns its index.
	/// @param[in] bl									The atom to find. @callerOwnsPointed{atom}
	/// @param[in] doc								The document for @formatParam{bl}. @callerOwnsPointed{document}
	/// @return												The BaseLink's index in the array, or @ref NOTOK if it was not found.
	//----------------------------------------------------------------------------------------
	Int32 Find(const C4DAtomGoal* bl, const BaseDocument* doc) const
	{
		Int32 i;
		for (i = 0; i < GetCount(); i++)
		{
			const BaseLink* l = (*this)[i];
			if (!l)
				continue;
			const C4DAtomGoal* b = l->GetLink(doc);
			if (!b)
				continue;
			if (b == bl)
				return i;
		}
		return NOTOK;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the base link at index @formatParam{i}.
	/// @param[in] i									The index of the base link to get. 0 <= @formatParam{i} < GetCount()
	/// @return												The base link. The array owns the pointed base link.
	//----------------------------------------------------------------------------------------
	BaseLink* GetIndexLink(Int32 i) const
	{
		if (i < 0 || i >= GetCount())
			return nullptr;

		return (*this)[i];
	}

	//----------------------------------------------------------------------------------------
	/// Gets the atom at index @formatParam{i}.
	/// @param[in] i									The index of the atom to get. 0 <= @formatParam{i} < GetCount()
	/// @param[in] doc								The document for the atom. @callerOwnsPointed{document}
	/// @return												The atom. The array owns the pointed atom.
	//----------------------------------------------------------------------------------------
	const C4DAtomGoal* GetIndex(Int32 i, const BaseDocument* doc) const
	{
		if (i < 0 || i >= GetCount())
			return nullptr;

		const BaseLink* l = (*this)[i];
		if (!l)
			return nullptr;
		return l->GetLinkAtom(doc);
	}

	/// @copydoc GetIndex
	C4DAtomGoal* GetIndex(Int32 i, BaseDocument* doc) const
	{
		return const_cast<C4DAtomGoal*>(GetIndex(i, static_cast<const BaseDocument*>(doc)));
	}

	C4DAtomGoal* GetIndex(Int32 i, std::nullptr_t doc) const
	{
		return const_cast<C4DAtomGoal*>(GetIndex(i, static_cast<const BaseDocument*>(nullptr)));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the base list at index @formatParam{i}.
	/// @param[in] i									The index of the base list to get. 0 <= @formatParam{i} < GetCount()
	/// @param[in] doc								The document for the base list. @callerOwnsPointed{document}
	/// @param[in] instanceof					Checked against C4DAtom::IsInstanceOf(). Pass @ref NOTOK to ignore this test. Default to @ref Tbaselist2d.
	/// @return												The base list. The array owns the pointed base list.
	//----------------------------------------------------------------------------------------
	const BaseList2D* GetIndexBl(Int32 i, const BaseDocument* doc, Int32 instanceof = Tbaselist2d) const
	{
		if (i < 0 || i >= GetCount())
			return nullptr;

		BaseLink* l = (*this)[i];
		if (!l)
			return nullptr;
		return static_cast<const BaseList2D*>(l->GetLinkAtom(doc, instanceof));
	}

	/// @copydoc GetIndexBl
	BaseList2D* GetIndexBl(Int32 i, BaseDocument* doc, Int32 instanceof = Tbaselist2d) const
	{
		return const_cast<BaseList2D*>(GetIndexBl(i, static_cast<const BaseDocument*>(doc), instanceof));
	}

	/// @}

	/// @name Append/Remove
	/// @{

	//----------------------------------------------------------------------------------------
	/// Appends an atom to the array.
	/// @param[in] bl									The atom to append. @callerOwnsPointed{atom}
	/// @return												@trueIfOtherwiseFalse{the base link was successfully added to the array}
	//----------------------------------------------------------------------------------------
	Bool Append(const C4DAtomGoal* bl)
	{
		BaseLink* l = BaseLink::Alloc();
		if (!l)
			return false;
		l->SetLink(bl);
		iferr (maxon::BaseArray<BaseLink*>::Append(l))
			return false;
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Removes and frees the base link at position @formatParam{n}.
	/// @param[in] n									The position of the base link to remove. 0 <= @formatParam{n} < GetCount()
	/// @return												@trueIfOtherwiseFalse{the base link was successfully removed}
	//----------------------------------------------------------------------------------------
	Bool Remove(Int32 n)
	{
		if (n < 0 || n >= GetCount())
			return false;

		BaseLink* l = (*this)[n];
		if (l)
			BaseLink::Free(l);

		iferr (Erase(n))
			DebugStop();

		return true;
	}

	/// @}

	/// @name Convert to/from AtomArray
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets an atom array with the base links of the array.
	/// @param[in] doc								The document to get the base links. @callerOwnsPointed{document}
	/// @param[in] res								Is added the base links of the array.
	//----------------------------------------------------------------------------------------
	void GetAtomArray(BaseDocument* doc, AtomArray& res) const
	{
		Int32 i, cnt = (Int32)GetCount();
		for (i = 0; i < cnt; i++)
		{
			C4DAtomGoal* bl = GetIndex(i, doc);
			if (bl)
				res.Append(bl);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the base link array from an atom array.
	/// @param[in] ar									The source atom array.
	//----------------------------------------------------------------------------------------
	void FromAtomArray(const AtomArray& ar)
	{
		FlushAll();
		Int32 i, cnt = ar.GetCount();
		for (i = 0; i < cnt; i++)
		{
			Append(static_cast<C4DAtomGoal*>(ar.GetIndex(i)));
		}
	}
	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of valid base links in the array.
	/// @param[in] doc								The document to check the base links. @callerOwnsPointed{document}
	/// @return												The number of valid base links in the array.
	//----------------------------------------------------------------------------------------
	Int32 GetRealCount(const BaseDocument* doc) const
	{
		Int32 realcnt = 0;
		Int32 i, cnt = (Int32)GetCount();
		for (i = 0; i < cnt; i++)
		{
			const C4DAtomGoal* bl = GetIndex(i, doc);
			if (bl)
				realcnt++;
		}
		return realcnt;
	}

	/// @}
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASELINKARRAY_H__
