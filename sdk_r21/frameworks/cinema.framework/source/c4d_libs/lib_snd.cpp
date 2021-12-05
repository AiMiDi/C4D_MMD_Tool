#include "lib_snd.h"

#ifndef __API_INTERN__

static GeSndLib *library_sound = nullptr;

#include "c4d_basesound.h"
GeSndInfo::GeSndInfo(BaseSound *bs)
{
	data = nullptr;
	if (bs)
	{
		bs->GetSoundInfo(this);
	}
}

static inline GeSndLib *CheckLibSnd(Int32 offset)
{
	return (GeSndLib*)CheckLib(LIB_SND, offset, (C4DLibrary**)&library_sound);
}


GePlaySnd* GePlaySnd::Alloc()
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Alloc)); if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void GePlaySnd::Free(GePlaySnd *&data)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Free)); if (!lib || !lib->Free) return;
	lib->Free(data);
}

GePlaySnd::GePlaySnd()
{
}

Bool GePlaySnd::Open(const BaseSound *snd)
{
	const Float	start_offset = 0;
	GeSndInfo	info;

	snd->GetSoundInfo(&info);

	return Open(1, &snd, &start_offset, info.GetLength().Get());
}

Bool GePlaySnd::Open(Int32 stream_cnt, const BaseSound **streams, const Float *start_offsets, Float max_length)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Open)); if (!lib || !lib->Open) return false;
	return (this->*lib->Open)(stream_cnt, streams, start_offsets, max_length);
}

void GePlaySnd::Close()
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Close)); if (!lib || !lib->Close) return;
	(this->*lib->Close)();
}

void GePlaySnd::StartAt(Float64 start)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, StartAt)); if (!lib || !lib->StartAt) return;
	(this->*lib->StartAt)(start);
}

void GePlaySnd::Scrub(Float64 start, Float64 duration)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Scrub)); if (!lib || !lib->Scrub) return;
	(this->*lib->Scrub)(start, duration);
}

void GePlaySnd::Stop()
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, Stop)); if (!lib || !lib->Stop) return;
	(this->*lib->Stop)();
}

Bool GePlaySnd::IsPlaying()
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, IsPlaying)); if (!lib || !lib->IsPlaying) return false;
	return (this->*lib->IsPlaying)();
}

Float64 GePlaySnd::GetPositionEstimate()
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, GetPositionEstimate)); if (!lib || !lib->GetPositionEstimate) return 0.0;
	return (this->*lib->GetPositionEstimate)();
}


void	GePlaySnd::SetScale(Float64 scale)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, SetScale)); if (!lib || !lib->SetScale) return;
	(this->*lib->SetScale)(scale);
}

Float64	GePlaySnd::GetScale(void)
{
	GeSndLib *lib = CheckLibSnd(LIBOFFSET(GeSndLib, GetScale)); if (!lib || !lib->GetScale) return 0;
	return (this->*lib->GetScale)();
}

#endif
