#include "c4d_basesound.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BaseSound* BaseSound::GetClone()
{
	return C4DOS_Bu->GetClone(this);
}

Bool BaseSound::CopyTo(BaseSound* dest)
{
	return C4DOS_Bu->CopyTo(this, dest);
}

Bool BaseSound::Init(Int sample_cnt, Float frequency, Int32 channel_cnt)
{
	return C4DOS_Bu->Init(this, sample_cnt, frequency, channel_cnt);
}

void BaseSound::FlushAll()
{
	C4DOS_Bu->FlushAll(this);
}

Bool BaseSound::Load(const Filename& fn)
{
	return C4DOS_Bu->Load(this, &fn);
}

Bool BaseSound::Save(const Filename& fn)
{
	return C4DOS_Bu->Save(this, &fn);
}

void BaseSound::GetSoundInfo(GeSndInfo* info) const
{
	C4DOS_Bu->GetSoundInfo((BaseSound*) this, info);
}

Bool BaseSound::ReadIt(HyperFile* hf, Int32 level)
{
	return C4DOS_Bu->ReadIt(this, hf, level);
}

Bool BaseSound::WriteIt(HyperFile* hf) const
{
	return C4DOS_Bu->WriteIt(this, hf);
}

BaseSound* BaseSound::GetClonePart(const BaseTime& start,	const BaseTime& stop,	Bool reverse)
{
	return C4DOS_Bu->GetClonePart(this, start, stop, reverse);
}

void BaseSound::GetSampleEx(Int32 i, SDataEx* data)
{
	C4DOS_Bu->GetSampleEx(this, i, data);
}

void BaseSound::SetSampleEx(Int32 i, const SDataEx& data)
{
	C4DOS_Bu->SetSampleEx(this, i, (SDataEx*)&data);
}

BaseBitmap* BaseSound::GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop)
{
	return C4DOS_Bu->GetBitmap(this, width, height, start, stop);
}

BaseBitmap* BaseSound::GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop, const Vector& draw_col, const Vector& back_col)
{
	return C4DOS_Bu->GetBitmap2(this, width, height, start, stop, draw_col, back_col);
}

GeListHead* BaseSound::GetMarkerRoot()
{
	return C4DOS_Bu->GetMarkerRoot(this);
}

BaseSound* BaseSound::Alloc()
{
	return C4DOS_Bu->Alloc();
}

void BaseSound::Free(BaseSound*& bs)
{
	C4DOS_Bu->Free(bs);
	bs = nullptr;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
