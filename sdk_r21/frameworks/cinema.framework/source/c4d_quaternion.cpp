#include "c4d_quaternion.h"
#include "c4d_tools.h"

void Quaternion::SetHPB(const Vector64& hpb)
{
	Quaternion qh, qp, qb;

	qh.SetAxis(Vector64(0, 1, 0), hpb.x);
	qp.SetAxis(Vector64(1, 0, 0), hpb.y);
	qb.SetAxis(Vector64(0, 0, 1), hpb.z);

	*this = QMul(qb, QMul(qp, qh));
}

Quaternion QAdd(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion r;

	r.w = q1.w + q2.w;
	r.v = q1.v + q2.v;
	return r;
}

Quaternion QSub(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion r;

	r.w = q1.w - q2.w;
	r.v = q1.v - q2.v;
	return r;
}

Quaternion QMul(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion r;

	r.w = (q1.w * q2.w) - Dot(q1.v, q2.v);
	r.v = q1.w * q2.v + q2.w * q1.v + Cross(q1.v, q2.v);
	return r;
}

Quaternion QMul(const Quaternion& q, Float64 s)
{
	Quaternion r = q;

	r.w *= s;
	r.v *= s;

	return r;
}


Quaternion QInvert(const Quaternion& q)
{
	Quaternion r;

	r.w = -q.w;
	r.v = q.v;

	return r;
}

Float64 QDot(const Quaternion& q1, const Quaternion& q2)
{
	return q1.w * q2.w + Dot(q1.v, q2.v);
}

Quaternion QDeriv(const Quaternion& q, const Vector64& w)
{
	Quaternion r;

	r.w = 0.5 * Dot(-q.v, w);
	r.v.x = 0.5 * (q.w * w.x - q.v.z * w.y + q.v.y * w.z);
	r.v.y = 0.5 * (q.v.z * w.x + q.w * w.y - q.v.x * w.z);
	r.v.z = 0.5 * (-q.v.y * w.x + q.v.x * w.y + q.w * w.z);

	return r;
}


Quaternion QNorm(const Quaternion& q)
{
	Quaternion r;
	Float64		 len;

	len = Sqrt(q.w * q.w + Dot(q.v, q.v));
	if (len == 0.0)
		return q;

	r.w = q.w / len;
	r.v = q.v / len;

	return r;
}

Quaternion QSlerp(const Quaternion& q1, const Quaternion& q2, const Float64 alfa)
{
	Float64		 sum, teta, beta1, beta2;
	Quaternion q, qd = q2;

	sum = q1.w * q2.w + Dot(q1.v, q2.v);

	if (sum < 0.0)
	{
		sum	 = -sum;
		qd.v = -qd.v;
		qd.w = -qd.w;
	}

	if (1.0 - sum > EPSILON5)
	{
		teta = ACos(sum);
		Float64 sn = 1.0 / Sin(teta);
		beta1 = Sin((1.0 - alfa) * teta) * sn;
		beta2 = Sin(alfa * teta) * sn;
	}
	else
	{
		beta1 = 1.0 - alfa;
		beta2 = alfa;
	}

	q.w = beta1 * q1.w + beta2 * qd.w;
	q.v.x = beta1 * q1.v.x + beta2 * qd.v.x;
	q.v.y = beta1 * q1.v.y + beta2 * qd.v.y;
	q.v.z = beta1 * q1.v.z + beta2 * qd.v.z;

	return q;
}

// q0 = i-1, q1 = i, q2 = i+1, q3 = i+2
Quaternion QSquad(const Quaternion& q0, const Quaternion& q1, const Quaternion& q2, const Quaternion& q3, Float64 t)
{
	Float64 k = 2.0 * (1.0 - t) * t;
	return QSlerp(QSlerp(q0, q3, t), QSlerp(q1, q2, t), k);
}

Quaternion QLogN(const Quaternion& q)
{
	Float64		 theta, scale;
	Quaternion qq;
	scale = Sqrt(Dot(q.v, q.v));
	theta = Float64(ATan2(scale, q.w));
	if (scale > 0.0)
		scale = theta / scale;
	qq.v *= scale;
	qq.w	= 0.0;
	return qq;
}

// Exp: exponentiate quaternion (where q.w==0)
Quaternion QExpQ(const Quaternion& q)
{
	Float64		 theta, scale;
	Quaternion qq;
	theta = Sqrt(Dot(q.v, q.v));
	scale = 1.0;
	if (theta > 0.0)
		scale = Sin(theta) / theta;
	qq.v *= scale;
	qq.w	= Cos(theta);
	return qq;
}

static Quaternion QTangent(const Quaternion& qn_m1, const Quaternion& qn, const Quaternion& qn_p1)
{
	Quaternion t1, t2;

	t1 = QMul(QInvert(qn), qn_p1);
	t2 = QMul(QInvert(qn), qn_m1);

	t1 = QLogN(t1);
	t2 = QLogN(t2);

	t1.v = (t1.v + t2.v) * (-0.25);
	t1.w = 0.0;


	//	t1 = QAdd(t1,t2);
	//	t1 = QMul(t1,-0.25);

	t1 = QExpQ(t1);
	t2 = QMul(qn, t1);
	return t2;
}

Quaternion QSpline(const Quaternion& qn_m1, const Quaternion& qn, const Quaternion& qn_p1, const Quaternion& qn_p2, Float64 t)
{
	Quaternion an, an_p1;

	an = QTangent(qn_m1, qn, qn_p1);
	an_p1 = QTangent(qn, qn_p1, qn_p2);

	return QSquad(qn, an, an_p1, qn_p1, t);
}

static Float64 Interpolate(const Float64 x, const Float64 p0, const Float64 p1, const Float64 p2)
{
	Float64 c0, c1, c2, c3; // cubic coefficients

	c3 = -0.5*p0 + 1.5*p1 - p2;
	c2 = p0 - 2.5*p1 + 1.5*p2;
	c1 = (p2 - p0)*0.5;
	c0 = p1;

	return ((c3*x + c2)*x + c1)*x + c0;
}

static Vector64 Interpolate(const Float64 x, const Vector64 &p0, const Vector64 &p1, const Vector64 &p2)
{
	Vector64 c0, c1, c2, c3; // cubic coefficients

	c3 = -0.5*p0 + 1.5*p1 - p2;
	c2 = p0 - 2.5*p1 + 1.5*p2;
	c1 = (p2 - p0)*0.5;
	c0 = p1;

	return ((c3*x + c2)*x + c1)*x + c0;
}

Quaternion QSmoothCubic(const Quaternion& qn_m1, const Quaternion& qn, const Quaternion& qn_p1, Float64 t)
{
	Quaternion result;

	Float fff = Smoothstep(0.0, 1.0, t);

	result.v = Interpolate(t, qn_m1.v, qn.v, qn_p1.v);
	result.w = Interpolate(fff, qn_m1.w, qn.w, qn_p1.w);

	return result;
}

Quaternion QBlend(const Quaternion& q1, const Quaternion& q2, const Float64 r)
{
	Float64 w1 = 1.0 - r;
	Float64 w2 = r;
	Float64 qq = q1.w * q2.w + Dot(q1.v, q2.v);
	Float64 z	 = Sqrt((w1 - w2) * (w1 - w2) + 4.0 * w1 * w2 * qq * qq);
	Float64 f1 = Sqrt(w1 * (w1 - w2 + z) / (z * (w1 + w2 + z)));
	Float64 f2 = Sqrt(w2 * (w2 - w1 + z) / (z * (w1 + w2 + z)));

	Quaternion qm;
	if (qq < 0.0)
		qm = QSub(QMul(q1, f1), QMul(q2, f2));
	else
		qm = QAdd(QMul(q1, f1), QMul(q2, f2));

	return QNorm(qm);
}

static Vector64 LGetHPB(const Vector64& v1, const Vector64& v2, const Vector64& v3)
{
	Vector64 rot;
	Float64	 l = Sqrt(v3.x * v3.x + v3.z * v3.z);

	if (l < 0.00001)
	{
		rot.x = 0.0;
		rot.z = ACos(Dot(Vector64(1.0, 0.0, 0.0), !v1));

		if (v3.y > 0.0)
		{
			rot.y = PI05;
			if (v1.z < 0.0)
				rot.z = PI2 - rot.z;
		}
		else
		{
			rot.y = -PI05;
			if (v1.z > 0.0)
				rot.z = PI2 - rot.z;
		}
	}
	else
	{
		if (v3.z > 0.0)
			rot.x = -ASin(v3.x / l);
		else
			rot.x = PI + ASin(v3.x / l);

		if (rot.x < 0.0)
			rot.x += PI2;
		rot.y = ATan(v3.y / l);
		rot.z = ACos(Dot(Vector64(Cos(rot.x), 0.0, Sin(rot.x)), !v1));
		if (v1.y > 0.0)
			rot.z = PI2 - rot.z;
	}

	if (rot.z > PI)
		rot.z = rot.z - PI2;
	return rot;
}

Vector64 Matrix64ToHPB(const Matrix64& m)
{
	return LGetHPB(m.sqmat.v1, m.sqmat.v2, m.sqmat.v3);
}

// ****************************************
inline void LSinCos(Float64 w, Float64& sn, Float64& cn) { sn = Sin(w); cn = Cos(w); }

Matrix64 LHPBToMatrix(const Vector64& w)
{
	Float64 cn, sn, ck, sk, cs, ss, cosksinn, sinksinn;

	LSinCos(w.x, ss, cs);
	LSinCos(w.y, sn, cn);
	LSinCos(w.z, sk, ck);

	cosksinn = ck * sn;
	sinksinn = sk * sn;

	return Matrix64(Vector64(0.0),
					 Vector64(ck * cs - sinksinn * ss, -sk * cn, ck * ss + sinksinn * cs),
					 Vector64(sk * cs + cosksinn * ss, ck * cn, sk * ss - cosksinn * cs),
					 Vector64(-cn * ss, sn, cn * cs));
}
