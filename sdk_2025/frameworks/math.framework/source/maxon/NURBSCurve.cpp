#include "maxon/general_math.h"
#include "NURBSCurve.h"
#include "NURBSMath.h"

namespace maxon
{


void NURBSTests::TestFunc()
{
	NURBSCurve<-1> testCurveDynamic;
	testCurveDynamic.Init(10, 3) iferr_ignore("test code");

	NURBSCurve<2> testCurveStatic;
	testCurveStatic.Init(5) iferr_ignore("test code");


	Vector points[]{ Vector{0.0, 200.0, 0.0},  Vector{80.0, 175.0, 0.0}, Vector{125.0, 125.0, 0.0}, Vector{175.0, 80.0, 200.0}, Vector{200.0, 0.0, 0.0} };
	testCurveStatic.ChangePoints(Block<Vector>{&points[0], 4}) iferr_ignore("test code");

	Block<Vector4d> outPoints;
	Int index;
	Tie(outPoints, index) = testCurveStatic.AddControlPoint(0.4_f) iferr_ignore("test code");

	DebugOutput(OUTPUT::DIAGNOSTIC, "@, @, @, @, @, @"_s, outPoints[0], outPoints[1], outPoints[2], outPoints[3], outPoints[4]);

	testCurveDynamic.EvaluateAt(0) iferr_ignore("test code");
	testCurveDynamic.DeriveAt(0) iferr_ignore("test code");
	testCurveStatic.EvaluateAt(0) iferr_ignore("test code");
	testCurveStatic.DeriveAt(0) iferr_ignore("test code");

	NURBSCurveWithContinuity<3> myCurve;

	NURBSCurve<5> testCurveHigherStaticDegree;
	//testCurveHigherStaticDegree.Init(testCurveStatic) iferr_ignore("test code");

	NURBSCurve<-1> testCurveHigherDynamicDegree;
	//testCurveHigherDynamicDegree.Init(5, testCurveStatic) iferr_ignore("test code");

}

} // namespace maxon
