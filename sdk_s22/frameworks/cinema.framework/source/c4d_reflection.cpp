#include "c4d_reflection.h"

ReflectionLayer::ReflectionLayer() : _layerDataID(0), _parent(nullptr) { }

Int32 ReflectionLayer::GetLayerID() const
{
	return _parent ? C4DOS.Mt->ReflectionLayerGetLayerID(_parent, this) : NOTOK;
}

Int32 ReflectionLayer::GetDataID() const
{
	return REFLECTION_LAYER_LAYER_DATA + REFLECTION_LAYER_LAYER_SIZE * _layerDataID;
}

String ReflectionLayer::GetName() const
{
	return _parent ? C4DOS.Mt->ReflectionLayerGetName(_parent, this) : "";
}

void ReflectionLayer::SetName(const maxon::String& name)
{
	if (_parent)
		C4DOS.Mt->ReflectionLayerSetName(_parent, this, name);
}

Int32 ReflectionLayer::GetFlags() const
{
	return _parent ? C4DOS.Mt->ReflectionLayerGetFlags(_parent, this) : 0;
}

void ReflectionLayer::SetFlags(Int32 flags)
{
	if (_parent)
		C4DOS.Mt->ReflectionLayerSetFlags(_parent, this, flags);
}
