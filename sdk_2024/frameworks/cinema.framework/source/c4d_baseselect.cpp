#include "operatingsystem.h"
#include "c4d_baseselect.h"

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BaseSelect* BaseSelect::Alloc()
{
	return C4DOS_Bs->Alloc();
}

void BaseSelect::Free(BaseSelect*& bs)
{
	C4DOS_Bs->Free(bs);
	bs = nullptr;
}

void BaseSelect::Write(HyperFile* hf) const
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
	return C4DOS_Bs->AllocEdgeBaseSelect();
}

void EdgeBaseSelect::Free(EdgeBaseSelect*& bs)
{
	C4DOS_Bs->FreeEdgeBaseSelect(bs);
	bs = nullptr;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
