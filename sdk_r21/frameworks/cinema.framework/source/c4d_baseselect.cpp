#include "operatingsystem.h"
#include "c4d_baseselect.h"

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

BaseSelect* BaseSelect::Alloc(void)
{
	return C4DOS.Bs->Alloc();
}

void BaseSelect::Free(BaseSelect*& bs)
{
	C4DOS.Bs->Free(bs);
	bs = nullptr;
}

Int32 BaseSelect::GetCount(void) const
{
	return C4DOS.Bs->GetCount(this);
}

Int32 BaseSelect::GetSegments(void) const
{
	return C4DOS.Bs->GetSegments(this);
}

Bool BaseSelect::Select(Int32 num)
{
	return C4DOS.Bs->Select(this, num);
}

Bool BaseSelect::SelectAll(Int32 min, Int32 max, Bool deselectAll)
{
	return C4DOS.Bs->SelectAll(this, min, max, deselectAll);
}

Bool BaseSelect::Deselect(Int32 num)
{
	return C4DOS.Bs->Deselect(this, num);
}

Bool BaseSelect::DeselectAll(void)
{
	return C4DOS.Bs->DeselectAll(this);
}

Bool BaseSelect::Toggle(Int32 num)
{
	return C4DOS.Bs->Toggle(this, num);
}

Bool BaseSelect::ToggleAll(Int32 min, Int32 max)
{
	return C4DOS.Bs->ToggleAll(this, min, max);
}

Bool BaseSelect::GetRange(Int32 seg, Int32 maxElements, Int32* a, Int32* b) const
{
	return C4DOS.Bs->GetRange(this, seg, maxElements, a, b);
}

Bool BaseSelect::CopyTo(BaseSelect* dest) const
{
	return C4DOS.Bs->CopyTo(this, dest);
}

Bool BaseSelect::Merge(const BaseSelect* src)
{
	return C4DOS.Bs->Merge(this, src);
}

Bool BaseSelect::Deselect(const BaseSelect* src)
{
	return C4DOS.Bs->DeselectBS(this, src);
}

Bool BaseSelect::Cross(const BaseSelect* src)
{
	return C4DOS.Bs->Cross(this, src);
}

BaseSelect* BaseSelect::GetClone(void) const
{
	return C4DOS.Bs->GetClone(this);
}

Bool BaseSelect::FromArray(UChar* selection, Int32 count)
{
	return C4DOS.Bs->FromArray(this, selection, count);
}

UChar* BaseSelect::ToArray(Int32 count) const
{
	return C4DOS.Bs->ToArray(this, count);
}

Bool BaseSelect::ToBitSet(Int32 count, maxon::BaseBitSet<maxon::DefaultAllocator>& bitSet) const
{
	return C4DOS.Bs->ToBitSet(this, count, bitSet);
}

void BaseSelect::Write(HyperFile* hf)
{
	// level
	hf->WriteInt32(0);

	Int32 i, a, b;
	Int32 cnt = GetSegments();
	hf->WriteInt32(cnt);
	for (i = 0; i < cnt; i++)
	{
		GetRange(i, LIMIT<Int32>::MAX, &a, &b);
		hf->WriteInt32(a);
		hf->WriteInt32(b);
	}
}

Bool BaseSelect::Read(HyperFile* hf)
{
	Int32 level;

	hf->ReadInt32(&level);

	if (level >= 0)
	{
		DeselectAll();

		Int32 i, cnt, a, b;
		hf->ReadInt32(&cnt);
		if (cnt)
		{
			for (i = 0; i < cnt; i++)
			{
				hf->ReadInt32(&a);
				hf->ReadInt32(&b);
				for (; a <= b; a++)
				{
					Select(a);
				}
			}
		}
	}
	return true;
}

EdgeBaseSelect* EdgeBaseSelect::Alloc()
{
	return C4DOS.Bs->AllocEdgeBaseSelect();
}

void EdgeBaseSelect::Free(EdgeBaseSelect*& bs)
{
	C4DOS.Bs->FreeEdgeBaseSelect(bs);
	bs = nullptr;
}

Bool EdgeBaseSelect::FromArrayCompact(const UChar *selection, Int32 count)
{
	return C4DOS.Bs->FromArrayCompact(this, selection, count);
}

UChar* EdgeBaseSelect::ToArrayCompact(Int32 count) const
{
	return C4DOS.Bs->ToArrayCompact(this, count);
}
