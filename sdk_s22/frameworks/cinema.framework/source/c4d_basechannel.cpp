#include "operatingsystem.h"
#include "c4d_basechannel.h"

BaseShader* BaseShader::Alloc(Int32 type)
{
	return C4DOS.Ba->PsAlloc(type);
}

void BaseShader::Free(BaseShader*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

BaseChannel* BaseChannel::Alloc(void)
{
	return C4DOS.Ba->Alloc();
}

void BaseChannel::Free(BaseChannel*& bc)
{
	if (!bc)
		return;
	C4DOS.Ba->Free(bc);
	bc = nullptr;
}

Bool BaseChannel::Attach(GeListNode* element)
{
	return C4DOS.Ba->Attach(this, element);
}

Bool BaseChannel::Compare(BaseChannel* dst)
{
	return C4DOS.Ba->Compare(this, dst);
}

INITRENDERRESULT BaseChannel::InitTexture(const InitRenderStruct& irs)
{
	return C4DOS.Ba->InitTexture(this, irs);
}

void BaseChannel::FreeTexture(void)
{
	C4DOS.Ba->FreeTexture(this);
}

BaseContainer BaseChannel::GetData(void)
{
	BaseContainer bc;
	C4DOS.Ba->GetData(this, &bc);
	return bc;
}

void BaseChannel::SetData(const BaseContainer& ct)
{
	C4DOS.Ba->SetData(this, &ct);
}

Int32 BaseChannel::GetShaderID(void)
{
	return C4DOS.Ba->GetPluginID(this);
}

BaseShader* BaseChannel::GetShader(void)
{
	return C4DOS.Ba->GetPluginShader(this);
}
