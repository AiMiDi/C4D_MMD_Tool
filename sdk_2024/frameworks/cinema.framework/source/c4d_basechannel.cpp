#include "operatingsystem.h"
#include "c4d_basechannel.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BaseShader* BaseShader::Alloc(Int32 type)
{
	return C4DOS_Ba->PsAlloc(type);
}

void BaseShader::Free(BaseShader*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

BaseChannel* BaseChannel::Alloc()
{
	return C4DOS_Ba->Alloc();
}

void BaseChannel::Free(BaseChannel*& bc)
{
	if (!bc)
		return;
	C4DOS_Ba->Free(bc);
	bc = nullptr;
}

Bool BaseChannel::Attach(GeListNode* element)
{
	return C4DOS_Ba->Attach(this, element);
}

Bool BaseChannel::Compare(BaseChannel* dst)
{
	return C4DOS_Ba->Compare(this, dst);
}

INITRENDERRESULT BaseChannel::InitTexture(const InitRenderStruct& irs)
{
	return C4DOS_Ba->InitTexture(this, irs);
}

void BaseChannel::FreeTexture()
{
	C4DOS_Ba->FreeTexture(this);
}

BaseContainer BaseChannel::GetData()
{
	BaseContainer bc;
	C4DOS_Ba->GetData(this, &bc);
	return bc;
}

void BaseChannel::SetData(const BaseContainer& ct)
{
	C4DOS_Ba->SetData(this, &ct);
}

Int32 BaseChannel::GetShaderID()
{
	return C4DOS_Ba->GetPluginID(this);
}

BaseShader* BaseChannel::GetShader()
{
	return C4DOS_Ba->GetPluginShader(this);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
