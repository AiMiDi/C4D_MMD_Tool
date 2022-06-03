#include "maxon/general_math.h"
#include "maxon/NURBSMath.h"


namespace maxon
{


namespace detail
{

Vector4d HomogeneousToNormal(const Vector4d& p)
{
	if (MAXON_UNLIKELY(p.w == 0.0))
		return p;

	Vector4d r;
	Float w = Inverse(p.w);

	r.x = p.x * w;
	r.y = p.y * w;
	r.z = p.z * w;
	r.w = p.w;

	return r;
}

Vector4d NormalToHomogeneous(const Vector4d& p)
{
	Vector4d r;

	r.x = p.x * p.w;
	r.y = p.y * p.w;
	r.z = p.z * p.w;
	r.w = p.w;

	return r;
}

}

} // namespace maxon
