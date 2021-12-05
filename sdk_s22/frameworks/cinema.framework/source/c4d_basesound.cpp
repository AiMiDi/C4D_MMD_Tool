#include "c4d_basesound.h"

BaseSound* BaseSound::GetClone(void)
{
	return C4DOS.Bu->GetClone(this);
}

Bool BaseSound::CopyTo(BaseSound* dest)
{
	return C4DOS.Bu->CopyTo(this, dest);
}

Bool BaseSound::Init(Int sample_cnt, Float frequency, Int32 channel_cnt)
{
	return C4DOS.Bu->Init(this, sample_cnt, frequency, channel_cnt);
}

void BaseSound::FlushAll(void)
{
	C4DOS.Bu->FlushAll(this);
}

Bool BaseSound::Load(const Filename& fn)
{
	return C4DOS.Bu->Load(this, &fn);
}

Bool BaseSound::Save(const Filename& fn)
{
	return C4DOS.Bu->Save(this, &fn);
}

void BaseSound::GetSoundInfo(GeSndInfo* info) const
{
	C4DOS.Bu->GetSoundInfo((BaseSound*) this, info);
}

Bool BaseSound::ReadIt(HyperFile* hf, Int32 level)
{
	return C4DOS.Bu->ReadIt(this, hf, level);
}

Bool BaseSound::WriteIt(HyperFile* hf)
{
	return C4DOS.Bu->WriteIt(this, hf);
}

BaseSound* BaseSound::GetClonePart(const BaseTime& start,	const BaseTime& stop,	Bool reverse)
{
	return C4DOS.Bu->GetClonePart(this, start, stop, reverse);
}

void BaseSound::GetSampleEx(Int32 i, SDataEx* data)
{
	C4DOS.Bu->GetSampleEx(this, i, data);
}

void BaseSound::SetSampleEx(Int32 i, const SDataEx& data)
{
	C4DOS.Bu->SetSampleEx(this, i, (SDataEx*)&data);
}

BaseBitmap* BaseSound::GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop)
{
	return C4DOS.Bu->GetBitmap(this, width, height, start, stop);
}

BaseBitmap* BaseSound::GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop, const Vector& draw_col, const Vector& back_col)
{
	return C4DOS.Bu->GetBitmap2(this, width, height, start, stop, draw_col, back_col);
}

GeListHead* BaseSound::GetMarkerRoot(void)
{
	return C4DOS.Bu->GetMarkerRoot(this);
}

BaseSound* BaseSound::Alloc(void)
{
	return C4DOS.Bu->Alloc();
}

void BaseSound::Free(BaseSound*& bs)
{
	C4DOS.Bu->Free(bs);
	bs = nullptr;
}
