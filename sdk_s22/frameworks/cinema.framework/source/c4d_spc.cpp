
#include "c4d_general.h"
#include "c4d_spc.h"

LatLongRange::LatLongRange(const LatLongRange& src) : _latMin(src._latMin), _latMax(src._latMax), _longMin(src._longMin), _longMax(src._longMax){}

LatLongRange& LatLongRange::operator =(const LatLongRange& that)
{
	if (&that == this)
		return *this;

	_latMin  = that._latMin;
	_latMax  = that._latMax;
	_longMin = that._longMin;
	_longMax = that._longMax;

	return *this;
}

void LatLongRange::SetFullRange()
{
	_latMin  = -PI05;
	_latMax  =  PI05;
	_longMin = -PI;
	_longMax =  PI;
}

Bool LatLongRange::InRange(Float lt, Float lg) const
{
	return (_latMin <= lt) && (lt <= _latMax) && (_longMin <= lg) && (lg <= _longMax);
}

SpcInfo::SpcInfo()
{
}

SpcInfo::SpcInfo(const SpcInfo& src) : _range(src._range), _crange(src._crange), _fitFrame(src._fitFrame), _stereoMode(src._stereoMode), _mapping(src._mapping),
																			 _layout(src._layout), _nw(src._nw), _nh(src._nh), _xmin(src._xmin), _ymin(src._ymin), _xmax(src._xmax), _ymax(src._ymax),
                                       _eyeSeparation(src._eyeSeparation), _focalDistance(src._focalDistance), _eyeNeckDistance(src._eyeNeckDistance),
                                       _smoothTop(src._smoothTop), _smoothBottom(src._smoothBottom), _topAngle(src._topAngle), _bottomAngle(src._bottomAngle),
                                       _topExp(src._topExp), _bottomExp(src._bottomExp)
{
}


SpcInfo& SpcInfo::operator =(const SpcInfo& that)
{
	if (&that == this)
		return *this;

	_range         = that._range;
	_crange        = that._crange;
	_fitFrame      = that._fitFrame;
	_stereoMode    = that._stereoMode;
	_layout        = that._layout;
	_mapping       = that._mapping;
	_eyeSeparation = that._eyeSeparation;
	_focalDistance = that._focalDistance;
	_eyeNeckDistance = that._eyeNeckDistance;
	_smoothTop     = that._smoothTop;
	_smoothBottom  = that._smoothBottom;
	_topAngle      = that._topAngle;
	_bottomAngle   = that._bottomAngle;
	_topExp        = that._topExp;
	_bottomExp     = that._bottomExp;
	_nw            = that._nw;
	_nh            = that._nh;
	_xmin          = that._xmin;
	_ymin          = that._ymin;
	_xmax          = that._xmax;
	_ymax          = that._ymax;

	return *this;
}

Bool SpcInfo::IsEnabled() const
{
	return HasFullFeatureSet();
}
