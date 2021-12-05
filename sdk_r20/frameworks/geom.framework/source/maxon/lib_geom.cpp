#include "lib_geom.h"

namespace maxon
{

Float GetAngle2D(const Vector2d& direction1, const Vector2d& direction2)
{
	Float theta1 = ATan2(direction1.x, direction1.y);
	Float theta2 = ATan2(direction2.x, direction2.y);
	Float dTheta = theta2 - theta1;
	while (dTheta > PI)
		dTheta -= PI2;
	while (dTheta < -PI)
		dTheta += PI2;

	return dTheta;
}

Float InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp)
{
	Float val = (point - segmentPoint1).GetLength() * Inverse((segmentPoint2 - segmentPoint1).GetLength());
	if (clamp)
		return Clamp01(val);
	return val;
}

Float InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp)
{
	return InterpolatePointOnSegment(Vector(segmentPoint1), Vector(segmentPoint2), Vector(point), clamp);
}

Bool CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector &normal, Int iterMax)
{
	normal		= Vector();
	centroid	= Vector();
	Int	count = pointCloud.GetCount();

	if (count <= 2)
		return false;

	for (const auto& it : pointCloud)
	{
		centroid += it;
	}
	centroid = centroid * Inverse((Float)count);

	Matrix xMatrix;
	for (const auto& it : pointCloud)
	{
		xMatrix.sqmat.v1 += Vector((it.x - centroid.x) * (it.x - centroid.x), (it.x - centroid.x) * (it.y - centroid.y),  (it.x - centroid.x) * ((it.z - centroid.z)));
		xMatrix.sqmat.v2 += Vector((it.y - centroid.y) * (it.x - centroid.x), (it.y - centroid.y) * (it.y - centroid.y),  (it.y - centroid.y) * ((it.z - centroid.z)));
		xMatrix.sqmat.v3 += Vector((it.z - centroid.z) * (it.x - centroid.x), (it.z - centroid.z) * (it.y - centroid.y),  (it.z - centroid.z) * ((it.z - centroid.z)));
	}

	Matrix	iXmat = ~xMatrix;
	Int32		iter = 0;
	Vector	vec = Vector(1.0, 1.0, 1.0);
	Vector	vec2 = (iXmat * vec) / (iXmat * vec).GetLength();
	while (!vec.IsEqual(vec2, DEFAULT_LINEAR_EPSILON) && iter < iterMax)
	{
		iter++;
		vec = vec2;
		vec2 = (iXmat * vec) / (iXmat * vec).GetLength();
		normal = vec2;
	}

	normal.Normalize();
	return true;
}

Result<BaseArray<Vector2d>> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated)
{
	iferr_scope;

	Vector orthVec1 = points[0] - points[1];
	Vector orthVec2 = Cross(normal, orthVec1);

	orthVec1.Normalize();
	orthVec2.Normalize();

	BaseArray<Vector2d> points2D;
	points2D.Resize((Int32)points.GetCount(), COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) iferr_return;

	for (Int32 pointIndex = 0; pointIndex < points.GetCount(); pointIndex++)
	{
		points2D[pointIndex] = Vector2d(Dot(points[pointIndex], orthVec1), Dot(points[pointIndex], orthVec2));
	}

	// degenerated cases check
	if (checkDegenerated)
	{
		for (Int32 pointIndex = 0; pointIndex < points.GetCount(); pointIndex++)
		{
			if ((points2D[pointIndex] - points2D[MAXON_UNLIKELY(pointIndex == points.GetCount() - 1) ? 0 : pointIndex + 1]).GetSquaredLength() == 0)
			{
				// degenerated case the projection produce conincident vertices

				// calcuate the center
				Vector center;
				for (Int32 pointIndexA = 0; pointIndexA < points.GetCount(); pointIndexA++)
				{
					center += points[pointIndexA];
				}

				center *= Inverse((Float)points.GetCount());

				// find a good cooplanar point to define the second axis
				Vector otherPoint;
				for (Int32 pointIndexA = 0; pointIndexA < points.GetCount(); pointIndexA++)
				{
					const Vector& flat = points[pointIndexA] - (normal * Dot(points[pointIndexA] - center, normal));
					if (flat != center)
					{
						orthVec1 =   flat - center;
						orthVec2 = Cross(normal, orthVec1);
						orthVec1.Normalize();
						orthVec2.Normalize();
						break;
					}
				}

				// project points in 2d
				for (Int32 pointIndexA = 0; pointIndexA < points.GetCount(); pointIndexA++)
				{
					points2D[pointIndexA] = Vector2d(Dot(points[pointIndexA], orthVec1), Dot(points[pointIndexA], orthVec2));
				}
				break;
			}
		}
	}

	return std::move(points2D);
}

Float CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c)
{
	Vector edge1 = a - b;
	Vector edge2 = c - b;
	Vector normal = Cross(edge2, edge1);
	return  normal.GetLength() / 2;
}

Float CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d)
{
	Vector edge1 = a - b;
	Vector edge2 = c - b;
	Vector normal = Cross(edge2, edge1);
	Float firstArea = normal.GetLength() / 2;
	edge1 = b - c;
	edge2 = d - c;
	normal = Cross(edge2, edge1);
	return firstArea + (normal.GetLength() / 2);
}

Float CalculateOutlineArea(const Block<const Vector>& outlinePoints)
{
	iferr_scope_handler
	{
		DiagnosticOutput("@", err);
		return 0.0;
	};

	Int32 l = 0;
	Vector v1, v2;
	Int pointCount = outlinePoints.GetCount();

	if (pointCount < 3)
		return 0.0;

	maxon::BaseArray<Vector>dPoints;
	dPoints.Resize(pointCount) iferr_return;
	Matrix m;
	if (!CalculateBestFitPlane(dPoints, m.off, m.sqmat.v3))
		return false;

	for (l = 0; l < pointCount; l++)
	{
		dPoints[l] = outlinePoints[l] - (m.sqmat.v3 * Dot(outlinePoints[l] - m.off, m.sqmat.v3));
	}

	m.sqmat.v1 = !(dPoints[1] - dPoints[0]);
	m.sqmat.v2 = !Cross(m.sqmat.v1, m.sqmat.v3);
	m = ~m;

	Float mult1 = 0.0;
	Float mult2 = 0.0;
	for (l = 0; l < pointCount; l++)
	{
		v1 = m * dPoints[l];
		v2 = m * dPoints[(l == pointCount - 1) ? 0 : l + 1];

		mult1 += v1.x * v2.y;
		mult2 += v1.y * v2.x;
	}

	return Abs((mult1 - mult2) * 0.5);
}

Vector CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& loop, Bool normalized)
{
	Vector normal = Vector(0.0_f);

	Int endPoint = loop.GetCount();

	for (Int pointIndex = 0; pointIndex < endPoint; pointIndex++)
	{
		Int nextPoint = pointIndex == endPoint - 1 ? 0 : pointIndex + 1;

		const Vector& point1 = points[loop[pointIndex]];
		const Vector& point2 = points[loop[nextPoint]];

		normal.x += (point1.y - point2.y) * (point1.z + point2.z);
		normal.y += (point1.z - point2.z) * (point1.x + point2.x);
		normal.z += (point1.x - point2.x) * (point1.y + point2.y);
	}

	if (normalized)
	{
		normal.Normalize();
	}

	return normal;
}

Vector CalculateOutlineNormal(const Block<const Vector>& points, Bool normalized)
{
	Vector normal = Vector(0.0_f);

	Int endPoint = points.GetCount();

	for (Int pointIndex = 0; pointIndex < endPoint; pointIndex++)
	{
		Int nextPoint = pointIndex == endPoint - 1 ? 0 : pointIndex + 1;

		const Vector& point1 = points[pointIndex];
		const Vector& point2 = points[nextPoint];

		normal.x += (point1.y - point2.y) * (point1.z + point2.z);
		normal.y += (point1.z - point2.z) * (point1.x + point2.x);
		normal.z += (point1.x - point2.x) * (point1.y + point2.y);
	}

	if (normalized)
	{
		normal.Normalize();
	}

	return normal;
}

Bool IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up)
{
	Vector norm = !(Cross(!(next - vertex), !(vertex - pred)));
	if ((!next).IsEqual(!pred, DEFAULT_LINEAR_EPSILON) || (!next).IsEqual(-!pred, DEFAULT_LINEAR_EPSILON))
		return true;
	Float dotP = Dot(norm, up);
	return dotP > 0.0;
}

static Float PointLineDistanceSqrClip(const Vector& v1, const Vector& v2, const Vector& vp)
{
	Vector v3 = v2 - v1;
	Float	 t	= v3.GetSquaredLength();
	if (t != 0.0)
		t = -Dot(v3, (v1 - vp)) / t;

	v3 = vp - (v1 + t * v3);
	return v3.GetSquaredLength();
}

static Bool IsTriangleCollapsed(const Vector& v1, const Vector& v2, const Vector& v3, Float tolerance)
{
	return PointLineDistanceSqrClip(v1, v2, v3) <= tolerance;
}

Result<BaseArray<Float>> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline)
{
	iferr_scope;

	BaseArray<Float> weights;

	Int outlineCount = outline.GetCount();

	BaseArray<Vector> s;
	BaseArray<Float> 	r;
	BaseArray<Float> 	a;
	BaseArray<Float>	d;
	BaseArray<Float>	t;

	for (const Vector& it : outline)
	{
		s.Append(it - point) iferr_return;
	}

	r.Resize(outlineCount) iferr_return;
	a.Resize(outlineCount) iferr_return;
	d.Resize(outlineCount) iferr_return;
	t.Resize(outlineCount) iferr_return;

	Int nextIndex = NOTOK;
	for (Int i = 0; i < outlineCount; ++i)
	{
		nextIndex = MAXON_UNLIKELY(i == outlineCount - 1) ? 0 : i + 1;

		if (PointInSegment(point, outline[i], outline[nextIndex], 0.0001))
		{
			weights.Resize(outlineCount, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) iferr_return;
			weights[nextIndex] = InterpolatePointOnSegment(outline[i], outline[nextIndex], point);
			weights[i] = 1.0 - weights[nextIndex];

			return std::move(weights);
		}

		r[i] = s[i].GetLength();
		a[i] = CalculateTriangleArea(outline[i], outline[nextIndex], point);
		d[i] = Dot(s[i], s[nextIndex]);
	}

	for (Int i = 0; i < outlineCount - 1; ++i)
		t[i] = a[i] * Inverse(r[i] * r[i + 1] + d[i]);

	t[outlineCount - 1] = a[outlineCount - 1] * Inverse(r[outlineCount - 1] * r[0] + d[outlineCount - 1]);

	weights.Resize(outlineCount, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE | COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED) iferr_return;

	weights[0] = (t[outlineCount - 1] + t[0]) * Inverse(r[0]);

	for (Int i = 1; i < outlineCount - 1; ++i)
		weights[i] = (t[i - 1] + t[i]) * Inverse(r[i]);

	weights[outlineCount - 1] = (t[outlineCount - 2] + t[outlineCount - 1]) * Inverse(r[outlineCount - 1]);

	return std::move(weights);
}

Bool IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred)
{
	return IsVertexConvex(Vector(vertex), Vector(next), Vector(pred));
}

Vector2d CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
{
	Vector v0 = c - a;
	Vector v1 = b - a;
	Vector v2 = point - a;

	Float dot00 = Dot(v0, v0);
	Float dot01 = Dot(v0, v1);
	Float dot02 = Dot(v0, v2);
	Float dot11 = Dot(v1, v1);
	Float dot12 = Dot(v1, v2);

	Float invDenom = Inverse(dot00 * dot11 - dot01 * dot01);
	return Vector2d((dot11 * dot02 - dot01 * dot12) * invDenom, (dot00 * dot12 - dot01 * dot02) * invDenom);
}

Vector CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
{
	Vector v0 = b - a, v1 = c - a, v2 = point - a;
	Float d00 = Dot(v0, v0);
	Float d01 = Dot(v0, v1);
	Float d11 = Dot(v1, v1);
	Float d20 = Dot(v2, v0);
	Float d21 = Dot(v2, v1);
	Float denom = d00 * d11 - d01 * d01;
	Float invDenom = Inverse(denom);
	Float v = (d11 * d20 - d01 * d21) * invDenom;
	Float w = (d00 * d21 - d01 * d20) * invDenom;
	Float u = 1.0f - v - w;
	return Vector(u, v, w);
}

Bool PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
{
	Vector2d res = CalculateBarycentricCoordinate(point, a, b, c);
	return res.x >= 0.0 && res.y >= 0.0 && res.x + res.y <= 1.0;
}

Bool PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c)
{
	Vector2d va(b - a), vb(c - a), vr(point - a);
	Float nnz = va.x * vb.y - va.y * vb.x;
	if (nnz == 0.0)
		return false;
	Float par_u = (vr.x * vb.y - vr.y * vb.x) * nnz;
	Float par_v = (va.x * vr.y - va.y * vr.x) * nnz;
	Float dot = nnz * nnz;
	Bool ok = par_u >= 0.0 && par_v >= 0.0 && par_u + par_v < dot;
	return ok;
}

static Float IsLeftValue(Vector2d p0, Vector2d p1, Vector2d p2)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x -  p0.x) * (p1.y - p0.y);
}

static Int32 IsLeft(Vector2d p0, Vector2d p1, Vector2d p2)
{
	Float value = IsLeftValue(p0, p1, p2);

	if (value > 0.0)
		return 1;
	else if (value < 0.0)
		return -1;

	return 0;
}

Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline)
{
	Int wn = 0;
	Int	nextIndex = 0;
	for (Int i = 0; i < outline.GetCount(); ++i)
	{
		nextIndex = MAXON_UNLIKELY(i == outline.GetCount() - 1) ? 0 : i + 1;
		if (outline[i].y <= point.y)
		{
			if (outline[nextIndex].y > point.y)
			{
				if (IsLeft(outline[i], outline[nextIndex], point) > 0)
					++wn;
			}
		}
		else
		{
			if (outline[nextIndex].y <= point.y)
			{
				if (IsLeft(outline[i], outline[nextIndex], point) < 0)
					--wn;
			}
		}
	}
	return wn;
}

Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit)
{
	edgeHit = maxon::InvalidArrayIndex;
	Int 		wn = 0;
	Int			nextIndex = 0;
	Float 	isLeftValue = 0.0;
	for (Int i = 0; i < outline.GetCount(); ++i)
	{
		nextIndex = MAXON_UNLIKELY(i == outline.GetCount() - 1) ? 0 : i + 1;
		if (outline[i].y <= point.y)
		{
			if (outline[nextIndex].y > point.y)
			{
				isLeftValue = IsLeftValue(outline[i], outline[nextIndex], point);
				if (isLeftValue > 0.0)
				{
					++wn;
				}
				else if (isLeftValue == 0.0)
				{
					edgeHit = i;
					return 1;
				}
			}
		}
		else
		{
			if (outline[nextIndex].y <= point.y)
			{
				isLeftValue = IsLeftValue(outline[i], outline[nextIndex], point);
				if (isLeftValue < 0.0)
				{
					--wn;
				}
				else if (isLeftValue == 0.0)
				{
					edgeHit = i;
					return 1;
				}
			}
		}
	}
	return wn;
}

Bool PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline)
{
	iferr_scope_handler
	{
		err.DbgStop();
		return false;
	};

	Int 			nextIndex = InvalidArrayIndex;
	Int				count = outline.GetCount();
	Vector2d 	currentPoint;
	Vector2d 	nextPoint;
	Vector2d	rayStart = Vector2d(point.x, point.y);
	Vector2d	rayPoint = rayStart + Vector2d(10000.0, 0.0);
	Vector2d	intersection;
	Int32 		intersectionCount = 0;
	Vector2d	edgeDirection;

	Bool equalToCurrent = false;
	Bool equalToNext = false;

	// if an intersecation happens on a vertex will be counted twice, store here the index to avoid this.
	BaseArray<UChar> vertexIntersection;
	vertexIntersection.Resize(count) iferr_return;

	for (Int i = 0; i < count; ++i)
	{
		currentPoint = outline[i];

		if (rayStart.IsEqual(currentPoint, DEFAULT_LINEAR_EPSILON))
			return false;

		if (i == count - 1)
			nextIndex = 0;
		else
			nextIndex = i + 1;

		nextPoint = outline[nextIndex];

		if (IntersectsSegments2D(currentPoint, nextPoint, rayStart, rayPoint, intersection, DEFAULT_LINEAR_EPSILON))
		{
			finally
			{
				equalToCurrent = false;
				equalToNext = false;
			};

			equalToCurrent = intersection.IsEqual(currentPoint, DEFAULT_LINEAR_EPSILON);
			if (equalToCurrent)
			{
				if (vertexIntersection[i]&1)
				{
					continue;
				}
				else
				{
					vertexIntersection[i] = 1;
					intersectionCount++;
					continue;
				}
			}

			equalToNext = intersection.IsEqual(nextPoint, DEFAULT_LINEAR_EPSILON);
			if (equalToNext)
			{
				if (vertexIntersection[nextIndex]&1)
				{
					continue;
				}
				else
				{
					vertexIntersection[nextIndex] = 1;
					intersectionCount++;
					continue;
				}
			}

			intersectionCount++;
		}
		else if ((currentPoint - Vector2d(point.x, point.y)).GetNormalized().IsEqual(Vector2d(1.0, 0.0), DEFAULT_LINEAR_EPSILON))
		{
			if (vertexIntersection[i]&1)
			{
				continue;
			}
			else
			{
				vertexIntersection[i] = 1;
				intersectionCount++;
				continue;
			}
		}
	}

	if (Modulo(intersectionCount, Int32(2)) != 0)
		return true;

	return false;
}

Vector CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2)
{
	Vector ray;
	Vector hand;
	Vector crossV;
	Vector crossV2;
	Vector wV1 = v1;
	Vector wV2 = v2;

	if (w1 != 0.0)
		wV1 = v1 / w1;

	if (w2 != 0.0)
		wV2 = v2 / w2;

	if ((!wV1).IsEqual(!wV2, DEFAULT_LINEAR_EPSILON))
	{
		ray = !Cross(wV2, up);
	}
	else if ((!wV1).IsEqual(-!wV2, DEFAULT_LINEAR_EPSILON))
	{
		ray =  !Cross(wV2, up);
	}
	else
	{
		if (w1 == 1.0 &&  w2 == 1.0)
		{
			Vector e1 = Cross(v1, up);
			Vector e2 = -Cross(v2, up);

			ray =  !(e1 + e2);
			if (ray.IsEqual(Vector(0), DEFAULT_LINEAR_EPSILON))
				ray = e1;
			else if (!IsVertexConvex(Vector(), !e1, !e2, up))
				ray = -1 * ray;

			return ray;
		}
		else
		{
			ray =  !(wV1 + wV2);
			if (!IsVertexConvex(Vector(), !wV1, !wV2, up))
				ray = -1 * ray;
		}
	}

	hand = !Cross(ray, up);
	crossV = !Cross(wV1, wV2);
	crossV2 = !Cross(up, wV1);
	// if up and ray are coplanar use one side to calculate bisector
	if (hand.IsEqual(Vector(0), DEFAULT_LINEAR_EPSILON))
		hand = !wV1;
	else
		ray =	!Cross(hand, up);

	return ray;
}

Bool CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance)
{
	Vector side1 = a - b;
	Vector side2 = b - c;
	Vector side3 = c - a;

	Float lSide1 = side1.GetLength();
	Float lSide2 = side2.GetLength();
	Float lSide3 = side3.GetLength();

	if (lSide1 < tolerance || lSide2 < tolerance || lSide3  < tolerance)
		return false; // triangle is collapsed

	Float crossLen = Cross(side1, side2).GetLength(),
	divisor = 2.0 * (crossLen * crossLen);

	if (divisor < tolerance)
		return false; // 3 points are collinear

	rad = (lSide1 * lSide2 * lSide3) / (2.0 * crossLen);

	Float u  = ((lSide2 * lSide2) * Dot(side1, (a - c))) / divisor;
	Float v  = (Dot((a - c), (a - c)) * Dot((b - a), side2)) / divisor;
	Float w  = ((lSide1 * lSide1) * Dot((c - a), (c - b))) / divisor;

	center = a * u + b * v + c * w;

	return true;
}

Bool SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2)
{
	Vector2d a = segment1Point2 - segment1Point1;
	Vector2d b = segment2Point1 - segment2Point2;
	Vector2d c = segment1Point1 - segment2Point1;

	Float alphaNumerator = b.y * c.x - b.x * c.y;
	Float alphaDenominator = a.y * b.x - a.x * b.y;
	Float betaNumerator = a.x * c.y - a.y * c.x;
	Float betaDenominator = a.y * b.x - a.x * b.y;

	Bool doIntersect = true;

	if (alphaDenominator == 0 || betaDenominator == 0)
	{
		doIntersect = false;
	}
	else
	{
		if (alphaDenominator > 0)
		{
			if (alphaNumerator < 0 || alphaNumerator > alphaDenominator)
				doIntersect = false;
		}
		else if (alphaNumerator > 0 || alphaNumerator < alphaDenominator)
		{
			doIntersect = false;
		}

		if (doIntersect && betaDenominator > 0)
		{
			if (betaNumerator < 0 || betaNumerator > betaDenominator)
				doIntersect = false;
		}
		else if (betaNumerator > 0 || betaNumerator < betaDenominator)
		{
			doIntersect = false;
		}
	}

	return doIntersect;
}

Bool IntersectsSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance)
{
	intersectionPoint = Vector2d();
	Vector2d b = segment1Point2 - segment1Point1;
	Vector2d d = segment2Point2 - segment2Point1;
	Float bDotDPerp = b.x * d.y - b.y * d.x;

	// if b dot d == 0, it means the lines are parallel so have infinite intersection points
	if (bDotDPerp == 0.0)
		return false;

	Vector2d c = segment2Point1 - segment1Point1;
	Float t = (c.x * d.y - c.y * d.x) / bDotDPerp;
	if (t < -tolerance || t > 1.0 + tolerance)
		return false;

	Float u = (c.x * b.y - c.y * b.x) / bDotDPerp;
	if (u < -tolerance || u > 1.0 + tolerance)
		return false;

	intersectionPoint = segment1Point1 + t * b;

	return true;
}

Vector LineLineDistance(const Vector& line1Point, const Vector& line1Dir , const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance)
{
	Vector  w = line1Point - line2Point;
	Float		a = Dot(line1Dir, line1Dir); // Always 1 if dir is normalized
	Float		b = Dot(line1Dir, line2Dir); // The angle between the two lines
	Float		c = Dot(line2Dir, line2Dir); // Always 1 if dir2 is normalized
	Float		dif = a * c - b * b;

	if (dif < tolerance)
	{
		param1 = 0.0;
		param2 = 0.0;
		parallel = true;
		return w;
	}

	parallel = false;
	Float d = Dot(line1Dir, w);
	Float e = Dot(line2Dir, w);
	Float sc = (b * e - c * d) / dif;
	Float tc = (a * e - b * d) / dif;

	param1 = sc;
	param2 = tc;

	return w + (sc * line1Dir) - (tc * line2Dir);
}

Bool PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance)
{
	if (segmentPoint1.IsEqual(segmentPoint2, tolerance))
		return false;

	Float crossProduct = (point.y - segmentPoint1.y) * (segmentPoint2.x - segmentPoint1.x) - (point.x - segmentPoint1.x) * (segmentPoint2.y - segmentPoint1.y);
	if (Abs(crossProduct) > tolerance)
		return false;
	Float dotProduct = (point.x - segmentPoint1.x) * (segmentPoint2.x - segmentPoint1.x) + (point.y - segmentPoint1.y) * (segmentPoint2.y - segmentPoint1.y);
	if (dotProduct < 0.0)
		return false;

	Float squaredLengthBA = (segmentPoint2 - segmentPoint1).GetSquaredLength();
	if (dotProduct > squaredLengthBA)
		return false;

	return true;
}


Bool PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance)
{
	Vector segment = segmentPoint2 - segmentPoint1;
	Vector ray1 = point - segmentPoint1;
	Vector ray2 = point - segmentPoint2;
	if (Abs(Cross(ray1, segment).GetLength()) < tolerance)
	{
		Float param1 = Dot(ray1, segment);
		Float param2 = Dot(ray2, segment);
		if (param1 >= 0.0 && param2 <= 0.0)
			return true;
	}
	return false;
}

Bool PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance)
{
	Vector tets = (point - halfLineOrigin).GetNormalized();
	if (tets.IsEqual(halfLineDir, tolerance))
		return true;
	return false;
}

Bool IntersectLines(const Vector& l1p0, const Vector& l1dir, const Vector& l2p0, const Vector& l2dir, Vector& ipoint, Float tolerance)
{
	Float		param1, param2;
	Bool		isparalel;
	Vector	dist = LineLineDistance(l1p0, l1dir, l2p0, l2dir, isparalel, param1, param2, tolerance);

	if (dist.GetLength() < tolerance && !isparalel)
	{
		ipoint = l1p0 + l1dir * param1;
		return true;
	}
	return false;
}

Bool IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance)
{
	Vector segmentLineDir = !(segmentPoint1 - segmentPoint2);
	Vector lineIntersection;

	if (IntersectLines(linePoint, lineDir, segmentPoint1, segmentLineDir, lineIntersection, tolerance))
	{
		if (PointInSegment(lineIntersection, segmentPoint1, segmentPoint2, tolerance * 10))
		{
			intersectionPoint = lineIntersection;
			return true;
		}
	}
	return false;
}

Bool IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance)
{
	Vector l1Dir = !(segment1Point2 - segment1Point1);
	Vector l2Dir = !(segment2Point2 - segment2Point1);
	Vector lineIntersection;

	if (IntersectLines(segment1Point1, l1Dir, segment2Point1, l2Dir, lineIntersection, tolerance))
	{
		if (PointInSegment(lineIntersection, segment1Point1, segment1Point2, tolerance * 10) && PointInSegment(lineIntersection, segment2Point1, segment2Point2, tolerance * 10))
		{
			intersectionPoint = lineIntersection;
			return true;
		}
	}
	return false;
}

Bool IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance)
{
	Vector lineIntersection;
	if (IntersectLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, lineIntersection, tolerance))
	{
		if (PointInHalfLine(lineIntersection, halfLine1Origin, halfLine1Dir, tolerance) && PointInHalfLine(lineIntersection, halfLine2Origin, halfLine2Dir, tolerance))
		{
			intersectionPoint = lineIntersection;
			return true;
		}
	}
	return false;
}

Bool IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance)
{
	Vector lineIntersection;
	if (IntersectLines(linePoint, lineDir, halfLineOrigin, halfLineDir, lineIntersection, tolerance))
	{
		if (PointInHalfLine(lineIntersection, halfLineOrigin, halfLineDir, tolerance))
		{
			intersectionPoint = lineIntersection;
			return true;
		}
	}
	return false;
}

Bool IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance)
{
	Vector lineIntersection;
	if (IntersectLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, lineIntersection, tolerance))
	{
		if (PointInHalfLine(lineIntersection, halfLineOrigin, halfLineDir, tolerance) && PointInSegment(lineIntersection, segmentPoint1, segmentPoint2, tolerance * 10))
		{
			intersectionPoint = lineIntersection;
			return true;
		}
	}
	return false;
}

Bool IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance)
{
	Vector	u = Cross(plane1Normal, plane2Normal);
	Float		ax = (u.x >= 0 ? u.x : -u.x);
	Float		ay = (u.y >= 0 ? u.y : -u.y);
	Float		az = (u.z >= 0 ? u.z : -u.z);

	if ((ax + ay + az) < tolerance)  // parellel or disjointed
		return false;

	Int32  maxc;
	if (ax > ay)
	{
		if (ax > az)
			maxc = 1;
		else
			maxc = 3;
	}
	else
	{
		if (ay > az)
			maxc = 2;
		else
			maxc = 3;
	}

	Vector   ip;
	Float		 d1, d2;
	d1 = -Dot(plane1Normal, plane1Point);
	d2 = -Dot(plane2Normal, plane2Point);

	switch (maxc)
	{
		case 1:
			ip.x = 0;
			ip.y = (d2 * plane1Normal.z - d1 * plane2Normal.z) / u.x;
			ip.z = (d1 * plane2Normal.y - d2 * plane1Point.y) / u.x;
			break;
		case 2:
			ip.x = (d1 * plane2Normal.z - d2 * plane1Normal.z) / u.y;
			ip.y = 0;
			ip.z = (d2 * plane1Normal.x - d1 * plane2Normal.x) / u.y;
			break;
		case 3:
			ip.x = (d2 * plane1Normal.y - d1 * plane2Normal.y) / u.z;
			ip.y = (d1 * plane2Normal.x - d2 * plane1Normal.x) / u.z;
			ip.z = 0;
			break;
	}
	resLinePoint = ip;
	resLineDirection = u;
	return true;
}

Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
{
	Vector	lineSecondPoint = linePoint + lineDir;
	Vector	u = lineSecondPoint - linePoint;
	Vector	w = linePoint - planePoint;

	Float d = Dot(planeNormal, u);
	Float n = -Dot(planeNormal, w);

	if (Abs(d) <= tolerance)
		return false;

	Float param = n * Inverse(d);

	intersectionPoint = linePoint + (lineDir * param);
	return true;
}

Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance)
{
	param = 0;
	samePlane = false;
	Vector	lineSecondPoint = linePoint + lineDir;
	Vector	u = lineSecondPoint - linePoint;
	Vector	w = linePoint - planePoint;

	Float d = Dot(planeNormal, u);
	Float n = -Dot(planeNormal, w);

	if (Abs(d) <= tolerance) // handle special cases
	{
		if (n == 0.0)
			samePlane = true; // line lies in triangle plane
		return false;
	}

	param = n * Inverse(d);

	intersectionPoint = linePoint + (lineDir * param);
	return true;
}

Bool IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
{
	Float param = 0.0;
	Bool samePlane = false;
	if (IntersectLinePlane(segmentPoint1, segmentPoint2 - segmentPoint1, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance))
	{
		if (param < 0.0 || param > 1.0)
			return false;
		return  true;
	}
	return false;
}

Bool IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
{
	Float param = 0.0;
	Bool samePlane = false;
	if (IntersectLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance))
	{
		if (param < 0.0)
			return false;
		return  true;
	}
	return false;
}

Bool IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance)
{
	Float 	param = 0.0;
	Bool 		samePlane = false;
	Vector	side1 = !(b - a);
	Vector 	side2 = !(c - a);
	Vector 	normal = !Cross(side1, side2);
	if (normal.IsZero())
		return false;

	if (IsTriangleCollapsed(a, b, c, tolerance))
		return false;

	if (IntersectLinePlane(linePoint, lineDir, a, normal, intersectionPoint, param, samePlane, tolerance))
	{
		Vector2d bCoords = CalculateBarycentricCoordinate(intersectionPoint, a, b, c);
		if (barycCoords)
			*barycCoords = bCoords;
		return bCoords.x >= 0.0 && bCoords.y >= 0.0 && bCoords.x + bCoords.y <= 1.0;
	}

	return false;
}

Bool IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance)
{
	if (IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, nullptr, tolerance))
		return true;
	return IntersectLineTriangle(linePoint, lineDir, a, c, d, intersectionPoint, nullptr, tolerance);
}

Bool IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance)
{
	Vector	side1 = !(b - a);
	Vector 	side2 = !(c - a);
	Vector 	normal = !Cross(side1, side2);
	if (normal.IsZero())
		return false;

	if (IsTriangleCollapsed(a, b, c, tolerance))
		return false;

	if (IntersectHalfLinePlane(halfLineOrigin, halfLineDir, a, normal, intersectionPoint, tolerance))
	{
		Vector2d bCoords = CalculateBarycentricCoordinate(intersectionPoint, a, b, c);
		if (barycCoords)
			*barycCoords = bCoords;
		return bCoords.x >= 0.0 && bCoords.y >= 0.0 && bCoords.x + bCoords.y <= 1.0;
	}

	return false;
}

Bool IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance)
{
	if (IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, nullptr, tolerance))
		return true;
	return IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, c, d, intersectionPoint, nullptr, tolerance);
}

static void CalculateSK(const Vector& rayStart, const Vector& rayEnd, Vector& S, IntVector& K)
{
	// calculate dimension where the ray direction is maximal
	Vector raydir = rayEnd - rayStart;
	K[2] = 0;
	if (Abs(raydir[1]) > Abs(raydir[K[2]]))
		K[2] = 1;
	if (Abs(raydir[2]) > Abs(raydir[K[2]]))
		K[2] = 2;

	K[0] = K[2] + 1;
	if (K[0] == 3)
		K[0] = 0;
	K[1] = K[0] + 1;
	if (K[1] == 3)
		K[1] = 0;

	// swap K[0] and K[1] dimension to preserve winding direction of triangles
	if (raydir[K[2]] < 0.0)
	{
		Int helper = K[0];
		K[0] = K[1];
		K[1] = helper;
	}

	// calculate shear constants
	S = Vector(raydir[K[0]] / raydir[K[2]], raydir[K[1]] / raydir[K[2]], 1.0 / raydir[K[2]]);
}

static Bool TestIfLineConnectingTwoPointsIntersectsTriangleWaterTight(const Vector& point, const Vector& a, const Vector& b, const Vector& c, const Vector& S, const IntVector& k, Vector& uvw, Float& lambda)
{
	// calculate vertices relative to ray origin
	const Vector A = a - point;
	const Vector B = b - point;
	const Vector C = c - point;

	// perform shear and scale of vertices
	const Float Ax = A[k[0]] - S[0] * A[k[2]];
	const Float Ay = A[k[1]] - S[1] * A[k[2]];
	const Float Bx = B[k[0]] - S[0] * B[k[2]];
	const Float By = B[k[1]] - S[1] * B[k[2]];
	const Float Cx = C[k[0]] - S[0] * C[k[2]];
	const Float Cy = C[k[1]] - S[1] * C[k[2]];

	// calculate scaled barycentric coordinates
	Float U = Cx * By - Cy * Bx;
	Float V = Ax * Cy - Ay * Cx;
	Float W = Bx * Ay - By * Ax;

	if ((U < 0.0 || V < 0.0 || W < 0.0) && (U > 0.0 || V > 0.0 || W > 0.0))
		return false;

	// Calculate determinant
	Float det = U + V + W;
	if (det == 0.0)
		return false;

	// Calculate scaled z-coordinates of vertices and use them to calculate the hit distance
	const Float Az = S[2] * A[k[2]];
	const Float Bz = S[2] * B[k[2]];
	const Float Cz = S[2] * C[k[2]];
	const Float T = U * Az + V * Bz + W * Cz;

	const Float rcpDet = 1.0 / det;
	uvw[0] = U * rcpDet;
	uvw[1] = V * rcpDet;
	uvw[2] = W * rcpDet;
	lambda = T * rcpDet;

	return true;
}

Bool IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance)
{
	Vector 		uvw;
	Vector 		S;
	IntVector K;
	Float 		lambda = 0.0;

	if (IsTriangleCollapsed(a, b, c, tolerance))
		return false;

	CalculateSK(segmentPoint1, segmentPoint2, S, K);
	if (TestIfLineConnectingTwoPointsIntersectsTriangleWaterTight(segmentPoint1, a, b, c, S, K, uvw, lambda) && lambda >= 0 && lambda <= 1)
	{
		intersectionPoint = segmentPoint1 + ((segmentPoint2 - segmentPoint1) * lambda);
		if (barycCoords)
			*barycCoords = uvw;
		return uvw.x >= -tolerance && uvw.y >= -tolerance && uvw.z >= -tolerance && uvw.x <= 1 + tolerance && uvw.y <= 1 + tolerance && uvw.z <= 1 + tolerance;
	}

	return false;
}

Bool TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance)
{
	Vector intersectionPoint;
	if (IntersectSegmentTriangle(t1a, t1b, t2a, t2b, t2c, intersectionPoint, nullptr, tolerance) || IntersectSegmentTriangle(t1b, t1c, t2a, t2b, t2c, intersectionPoint, nullptr, tolerance) || IntersectSegmentTriangle(t1c, t1a, t2a, t2b, t2c, intersectionPoint, nullptr, tolerance))
		return true;
	return false;
}
	
static void _CalcT(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Float& t1, Float& t2, Bool first = true)
{
	Vector ba = b - a, cd = c - d;

	Float den = -2 * ba.y * cd.x + 2 * cd.y * ba.x;
	if (den == 0.0)	// special case
	{
		if (first)
			_CalcT(Vector(a.x - 1e-6_f, a.y - 1e-6_f, a.z - 1e-6_f),
				Vector(b.x + 1e-6_f, b.y + 1e-6_f, b.z + 1e-6_f),
				Vector(c.x - 1e-6_f, c.y - 1e-6_f, c.z - 1e-6_f),
				Vector(d.x + 1e-6_f, d.y + 1e-6_f, d.z + 1e-6_f), p, t1, t2, false);
		return;
	}
	else
	{
		den = 1.0 / den;
	}

	Float disc = Sqr((-p.y + d.y) * ba.x) + Sqr((d.x - p.x) * ba.y) +
	(-(2 * (-p.y + d.y)) * (d.x - p.x) * ba.y - (2 * (-p.y + d.y)) * (a.y - p.y) * cd.x - (2 * ((2 * a.y - p.y - d.y) * p.x + (2 * d.x - a.x) * p.y + d.y * a.x - 2 * a.y * d.x)) * cd.y) * ba.x +
	(((2 * p.y + 2 * a.y - 4 * d.y) * p.x + (2 * d.x - 4 * a.x) * p.y - 2 * a.y * d.x + 4 * d.y * a.x) * cd.x - 2 * cd.y * (d.x-p.x) * (a.x-p.x)) * ba.y + Sqr((-a.y + p.y) * cd.x + cd.y * (a.x - p.x));

	if (disc < -1e-4)
	{
		t1 = t2 = 0.0;
		return;
	}
	else if (disc < 0.0)
	{
		disc = 0.0;
	}

	disc = Sqrt(disc);

	Float nomb = (-d.y + p.y) * ba.x + (d.x - p.x) * ba.y + (a.y - p.y) * cd.x + (-a.x + p.x) * cd.y;
	Float nom = disc + nomb;

	t1 = Clamp01(nom * den);

	nom = nomb - disc;

	t2 = Clamp01(nom * den);
}

static Float CalcT(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Bool first = true)
{
	Float dpxy1 = MAXVALUE_FLOAT, dpzy1 = MAXVALUE_FLOAT, dpxz1 = MAXVALUE_FLOAT;
	Float dpxy2 = MAXVALUE_FLOAT, dpzy2 = MAXVALUE_FLOAT, dpxz2 = MAXVALUE_FLOAT;
	Vector p1, p2;

	Float xyt1, xyt2;

	_CalcT(Vector(a.x, a.y, 0.0_f), Vector(b.x, b.y, 0.0_f), Vector(c.x, c.y, 0.0_f),
		Vector(d.x, d.y, 0.0_f), Vector(p.x, p.y, 0.0_f), xyt1, xyt2);

	if (xyt1 > -1e-3 && xyt1 < 1.001)
	{
		p1 = (b - a) * xyt1 + a;
		p2 = (c-d) * xyt1 + d;
		dpxy1 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpxy1 < 1e-5)
			return xyt1;
	}

	if (xyt2 > -1e-3 && xyt2 < 1.001)
	{
		p1 = (b - a) * xyt2 + a;
		p2 = (c - d) * xyt2 + d;
		dpxy2 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpxy2 < 1e-5)
			return xyt2;
	}

	Float zyt1, zyt2;

	_CalcT(Vector(a.z, a.y, 0.0_f), Vector(b.z, b.y, 0.0_f),
		Vector(c.z, c.y, 0.0_f), Vector(d.z, d.y, 0.0_f), Vector(p.z, p.y, 0.0_f), zyt1, zyt2);

	if (zyt1 > -1e-3_f && zyt1 < 1.001_f)
	{
		p1 = (b - a) * zyt1 + a;
		p2 = (c - d) * zyt1 + d;
		dpzy1 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpzy1 < 1e-5_f)
			return zyt1;
	}

	if (zyt2 > -1e-3_f && zyt2 < 1.001_f)
	{
		p1 = (b-a)*zyt2+a;
		p2 = (c-d)*zyt2+d;
		dpzy2 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpzy2 < 1e-5)
			return zyt2;
	}

	Float xzt1, xzt2;

	_CalcT(Vector(a.x, a.z, 0.0_f), Vector(b.x, b.z, 0.0_f), Vector(c.x, c.z, 0.0_f), Vector(d.x, d.z, 0.0_f), Vector(p.x, p.z, 0.0_f), xzt1, xzt2);

	if (xzt1 > -1e-3_f && xzt1 < 1.001_f)
	{
		p1 = (b - a) * xzt1 + a;
		p2 = (c - d) * xzt1 + d;
		dpxz1 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpxz1 < 1e-5_f)
			return xzt1;
	}

	if (xzt2 > -1e-3_f && xzt2 < 1.001_f)
	{
		p1 = (b - a) * xzt2 + a;
		p2 = (c - d) * xzt2 + d;
		dpxz2 = Abs(Sqr(Dot((p2 - p1), (p - p1))) - ((p2 - p1).GetSquaredLength() * (p - p1).GetSquaredLength()));
		if (dpxz2 < 1e-5_f)
			return xzt2;
	}

	if (dpxy2 < dpxy1)
	{
		Swap(dpxy2, dpxy1);
		Swap(xyt1, xyt2);
	}
	if (dpzy2 < dpzy1)
	{
		Swap(dpzy2, dpzy1);
		Swap(zyt1, zyt2);
	}
	if (dpxz2 < dpxz1)
	{
		Swap(dpxz2, dpxz1);
		Swap(xzt1, xzt2);
	}

	if (dpxy1 < dpzy1 && dpxy1 < dpxz1)
		return xyt1;
	else if (dpzy1 < dpxy1 && dpzy1 < dpxz1)
		return zyt1;

	return xzt1;
}

static void CalcST(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Float& s, Float& t)
{
	s = CalcT(a, b, c, d, p);

	Vector p1 = Blend(a, b, s), p2 = Blend(d, c, s);
	Vector v = (p2-p1);
	Float vl = v.GetSquaredLength();
	if (vl == 0.0)
	{
		t = 0.0;
		return;
	}

	t = Dot((p - p1), v) / vl;
}

Bool CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance)
{
	s = MINVALUE_FLOAT;
	t = MINVALUE_FLOAT;

	if (!isQuad)
	{
		Vector2d res = CalculateBarycentricCoordinate(point, pa, pb, pc);
		s = res.x;
		t = res.y;
	}
	else
	{
		CalcST(Vector(pa.x, pa.y, 0.0), Vector(pb.x, pb.y, 0.0), Vector(pc.x, pc.y, 0.0), Vector(pd.x, pd.y, 0.0), Vector(point.x, point.y, 0.0), s, t);
	}

	return (s >= 0.0 && s <= 1.0 + tolerance) && (t >= 0.0 && t <= 1 + tolerance);
}

Vector BilinearInterpolate(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& p3, const Float s, const Float t)
{
	return Vector(t* (s * p2 + (1 - s) * p3) + (1 - t) * (s * p1 + (1 - s) * p0));
}

inline Float Cross(const Vector2d& a, const Vector2d& b)
{
	return a.x*b.y - a.y*b.x;
}
inline Bool InRange(const Float val, const Float range_min, const Float range_max, const Float tol)
{
	return ((val + tol) >= range_min) && ((val - tol) <= range_max);
}
inline Bool Equals(const Float a, const Float b, const Float tolerance)
{
	return (a == b) ||
		((a <= (b + tolerance)) &&
		(a >= (b - tolerance)));
}

void InverseBilinarInterpolate2D(const Vector2d& va, const Vector2d& vb, const Vector2d& vc, const Vector2d& vd, const Vector2d& p, Vector2d& bilinarVariables)
{
	Float du1 = 0.0_f;
	Float du2 = 0.0_f;
	Float dv1 = 0.0_f;
	Float dv2 = 0.0_f;
	Float du = 0.0_f;
	Float dv = 0.0_f;

	Float a = va.x - vb.x + vc.x - vd.x;
	Float b = vb.x - va.x;
	Float c = vd.x - va.x;
	Float d = va.x;

	Float e = va.y - vb.y + vc.y - vd.y;
	Float f = vb.y - va.y;
	Float g = vd.y - va.y;
	Float h = va.y;

	Float area = a * f - b * e;
	if ((area != 0.0_f) && !((a == 0.0_f) && (c == 0.0_f)))
	{
		Float B = e * p.x - a * p.y + a * h - d * e + c * f - b * g;
		Float C = g * p.x - c * p.y + c * h - d * g;

		Float sqrt_term = B*B - 4 * area * C;
		if (sqrt_term < 0)
			sqrt_term = 0;

		sqrt_term = sqrt(sqrt_term);

		du1 = (-B + sqrt_term) / (2 * area);
		du2 = (-B - sqrt_term) / (2 * area);

		dv1 = (p.x - b * du1 - d) / (a * du1 + c);
		dv2 = (p.x - b * du2 - d) / (a * du2 + c);
	}
	else
	{
		Float D = a*g - c*e;
		if ((D != 0.0_f) && !((e == 0.0_f) && (f == 0.0_f)))
		{
			Float E = e * p.x - a * p.y + a * h - d * e - c * f + b * g;
			Float F = f * p.x - b * p.y + b * h - d * f;

			Float sqrt_term = E * E - 4 * D * F;
			if (sqrt_term < 0)
				sqrt_term = 0;

			sqrt_term = sqrt(sqrt_term);

			dv1 = (-E + sqrt_term) / (2 * D);
			dv2 = (-E - sqrt_term) / (2 * D);

			du1 = (p.y - g*dv1 - h) / (e*dv1 + f);
			du2 = (p.y - g*dv2 - h) / (e*dv2 + f);
		}
		else
		{
			// Quad is a parallelogram.
			// ap is a linear combination of ab and ad.
			//
			Vector2d ap = p - va;
			Vector2d ab = vb - va;
			Vector2d ad = vd - va;

			Float det = ab.x * ad.y - ab.y * ad.x;
			if (det != 0.)
			{
				// Determinant will be 0 only if ab and ad are co-directional.  Should not happen.
				du1 = (ap.x * ad.y - ap.y * ad.x) / det;
				dv1 = (ap.y * ab.x - ap.x * ab.y) / det;

				du2 = du1;
				dv2 = dv1;
			}
			else
			{
				// ab and ad are co-directional.  In case this happens, the logical answer will be that
				// du and dv are the same.
				Float length = ab.GetLength();
				if (length > 0.0)
				{
					du1 = dv1 = du2 = dv2 = ap.GetLength() / length;
				}
				// else du1 = dv1 = du2 = dv2 = 0.0;  // Already initialized as such.
			}
		}
	}

	// 1e-4 is an arbitrary rounding limit.  This limit may need to be adjusted.
	const Float lower_limit = -1e-4_f;
	const Float upper_limit = 1.0001_f;
	if ((lower_limit <= du1) && (du1 <= upper_limit) && (lower_limit <= dv1) && (dv1 <= upper_limit))
	{
		du = du1;
		dv = dv1;
	}
	else if ((lower_limit <= du2) && (du2 <= upper_limit) && (lower_limit <= dv2) && (dv2 <= upper_limit))
	{
		du = du2;
		dv = dv2;
	}
	else
	{
		// Fallback case.  Take the du/dv pair where du is nearest to the [0,1] range.
		// If 'p' is on the quad border, then this will take care of accuracy issues outside of the
		// rounding limit above.  This provides a better guess than returning zero values.
		Float distDu1 = (du1 < 0.0_f) ? -du1 : du1 - 1.0_f;
		Float distDu2 = (du2 < 0.0_f) ? -du2 : du2 - 1.0_f;

		if (distDu1 <= distDu2)
		{
			du = du1;
			dv = dv1;
		}
		else
		{
			du = du2;
			dv = dv2;
		}
	}
	if (du < 0.0_f)
		du = 0.0_f;

	if (dv < 0.0_f)
		dv = 0.0_f;

	if (du > 1.0_f)
		du = 1.0_f;

	if (dv > 1.0_f)
		dv = 1.0_f;

	bilinarVariables = Vector2d(du, dv);
}

void InverseBilinarInterpolate2DNewton(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d, const Vector2d& p, Int32 iterations, Vector2d& bilinarVariables)
{
	Float ss = 0.5_f;
	Float tt = 0.5_f;
	Float r1 = 0.0_f;
	Float r2 = 0.0_f;

	for (Int32 k = 0; k < iterations; k++)
	{
		r1 = a.x * (1 - ss) * (1 - tt) + b.x * ss * (1 - tt) + c.x * ss * tt + d.x * (1 - ss) * tt - p.x;
		r2 = a.y * (1 - ss) * (1 - tt) + b.y * ss * (1 - tt) + c.y * ss * tt + d.y * (1 - ss) * tt - p.y;

		Float j11 = -a.x * (1 - tt) + b.x * (1 - tt) + c.x * tt - d.x * tt;
		Float j21 = -a.y * (1 - tt) + b.y * (1 - tt) + c.y * tt - d.y * tt;
		Float j12 = -a.x * (1 - ss) - b.x * ss + c.x * ss + d.x * (1 - ss);
		Float j22 = -a.y * (1 - ss) - b.y * ss + c.y * ss + d.y * (1 - ss);
		Float determinant = j11 * j22 - j12 * j21;

		if (MAXON_UNLIKELY(Abs(determinant) < 1e-12_f))
			return;

		Float inverseDeterminant = 1.0_f / determinant;

		ss = ss - inverseDeterminant * (j22 * r1 - j12 * r2);
		tt = tt - inverseDeterminant * (-j21 * r1 + j11 * r2);

		ss = Min(Max(ss, 0.0_f), 1.0_f);
		tt = Min(Max(tt, 0.0_f), 1.0_f);
	}

	bilinarVariables = Vector2d(ss, tt);
}

inline void ProjectPoints2D(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Vector2d& a2d, Vector2d& b2d, Vector2d& c2d, Vector2d& d2d, Vector2d& p2d)
{
	Vector edge1 = b - a;
	Vector edge2 = c - a;
	Vector edge4 = d - c;

	Vector n1 = Cross(edge1, edge2);
	Vector n2 = Cross(edge4, -edge2);
	Vector dir = (n1 + n2) * 0.5_f;

	// find the 2 dominant axis for projection
	Int32 coord1 = 0;
	Int32 coord2 = 1;

	if (Abs(dir.x) > Abs(dir.y) && Abs(dir.x) > Abs(dir.z))
	{
		coord1 = 1;
		coord2 = 2;
	}
	else if (Abs(dir.y) > Abs(dir.x) && Abs(dir.y) > Abs(dir.z))
	{
		coord1 = 0;
		coord2 = 2;
	}
	else if (Abs(dir.z) > Abs(dir.x) && Abs(dir.z) > Abs(dir.y))
	{
		coord1 = 0;
		coord2 = 1;
	}

	// project the points in the dominant axis direction
	a2d = Vector2d(a[coord1], a[coord2]);
	b2d = Vector2d(b[coord1], b[coord2]);
	c2d = Vector2d(c[coord1], c[coord2]);
	d2d = Vector2d(d[coord1], d[coord2]);
	p2d = Vector2d(p[coord1], p[coord2]);
}

void InverseBilinarInterpolate(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Vector2d& bilinarVariables)
{
	// project the points in the dominant axis direction
	Vector2d a2d;
	Vector2d b2d;
	Vector2d c2d;
	Vector2d d2d;
	Vector2d p2d;

	ProjectPoints2D(a, b, c, d, p, a2d, b2d, c2d, d2d, p2d);

	// calculate the bilinear interpolation in 2d
	InverseBilinarInterpolate2D(a2d, b2d, c2d, d2d, p2d, bilinarVariables);
}

void InverseBilinarInterpolateNewton(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& p, Int32 iterations, Vector2d& bilinarVariables)
{
	// project the points in the dominant axis direction
	Vector2d a2d;
	Vector2d b2d;
	Vector2d c2d;
	Vector2d d2d;
	Vector2d p2d;

	ProjectPoints2D(a, b, c, d, p, a2d, b2d, c2d, d2d, p2d);

	// calculate the bilinear interpolation in 2d with newton method
	InverseBilinarInterpolate2DNewton(a2d, b2d, c2d, d2d, p2d, iterations, bilinarVariables);
}

} // namespace maxon
