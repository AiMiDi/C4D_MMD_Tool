#ifndef BLEND_FUNCTION_H__
#define BLEND_FUNCTION_H__

#include "maxon/objectbase.h"
#include "maxon/datatypebase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Blend function class.
/// The registry BlendFunctions allow to iterate over all available blend functions.
//----------------------------------------------------------------------------------------
class BlendFunctionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(BlendFunctionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.blendfunction")

public:
	//----------------------------------------------------------------------------------------
	/// Maps a value for a given x value based on the given startValue and endValue.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue);
};



#include "blend_function1.hxx"

//----------------------------------------------------------------------------------------
/// BlendFunctions offers a registry to extend blend functions
/// e.g. for the BlendAnimationInterface.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(BlendFunctionRef, BlendFunctions, "net.maxon.registry.blendfunction");

//----------------------------------------------------------------------------------------
/// BlendFunctions offers a registry to extend blend functions
/// e.g. for the BlendAnimationInterface.
//----------------------------------------------------------------------------------------
namespace BlendFunctions
{
	MAXON_DECLARATION(BlendFunctionRef, Linear, "net.maxon.blendfunction.linear");

	MAXON_DECLARATION(BlendFunctionRef, EaseInQuad, "net.maxon.blendfunction.easeinquad");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutQuad, "net.maxon.blendfunction.easeoutquad");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutQuad, "net.maxon.blendfunction.easeinoutquad");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInQuad, "net.maxon.blendfunction.easeoutinquad");

	MAXON_DECLARATION(BlendFunctionRef, EaseInCubic, "net.maxon.blendfunction.easeincubic");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutCubic, "net.maxon.blendfunction.easeoutcubic");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutCubic, "net.maxon.blendfunction.easeinoutcubic");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInCubic, "net.maxon.blendfunction.easeoutincubic");

	MAXON_DECLARATION(BlendFunctionRef, EaseInQuart, "net.maxon.blendfunction.easeinquart");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutQuart, "net.maxon.blendfunction.easeoutquart");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutQuart, "net.maxon.blendfunction.easeinoutquart");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInQuart, "net.maxon.blendfunction.easeoutinquart");

	MAXON_DECLARATION(BlendFunctionRef, EaseInQuint, "net.maxon.blendfunction.easeinquint");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutQuint, "net.maxon.blendfunction.easeoutquint");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutQuint, "net.maxon.blendfunction.easeinoutquint");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInQuint, "net.maxon.blendfunction.easeoutinquint");

	MAXON_DECLARATION(BlendFunctionRef, EaseInSext, "net.maxon.blendfunction.easeinsext");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutSext, "net.maxon.blendfunction.easeoutsext");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutSext, "net.maxon.blendfunction.easeinoutsext");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInSext, "net.maxon.blendfunction.easeoutinsext");

	MAXON_DECLARATION(BlendFunctionRef, EaseInSine, "net.maxon.blendfunction.easeinsine");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutSine, "net.maxon.blendfunction.easeoutsine");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutSine, "net.maxon.blendfunction.easeinoutsine");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInSine, "net.maxon.blendfunction.easeoutinsine");

	MAXON_DECLARATION(BlendFunctionRef, EaseInExpo, "net.maxon.blendfunction.easeinexpo");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutExpo, "net.maxon.blendfunction.easeoutexpo");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutExpo, "net.maxon.blendfunction.easeinoutexpo");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInExpo, "net.maxon.blendfunction.easeoutinexpo");

	MAXON_DECLARATION(BlendFunctionRef, EaseInCirc, "net.maxon.blendfunction.easeincirc");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutCirc, "net.maxon.blendfunction.easeoutcirc");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutCirc, "net.maxon.blendfunction.easeinoutcirc");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInCirc, "net.maxon.blendfunction.easeoutincirc");

	MAXON_DECLARATION(BlendFunctionRef, EaseInElastic, "net.maxon.blendfunction.easeinelastic");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutElastic, "net.maxon.blendfunction.easeoutelastic");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutElastic, "net.maxon.blendfunction.easeinoutelastic");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInElastic, "net.maxon.blendfunction.easeoutinelastic");

	MAXON_DECLARATION(BlendFunctionRef, EaseInBack, "net.maxon.blendfunction.easeinback");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutBack, "net.maxon.blendfunction.easeoutback");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutBack, "net.maxon.blendfunction.easeinoutback");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInBack, "net.maxon.blendfunction.easeoutinback");

	MAXON_DECLARATION(BlendFunctionRef, EaseInBounce, "net.maxon.blendfunction.easeinbounce");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutBounce, "net.maxon.blendfunction.easeoutbounce");
	MAXON_DECLARATION(BlendFunctionRef, EaseInOutBounce, "net.maxon.blendfunction.easeinoutbounce");
	MAXON_DECLARATION(BlendFunctionRef, EaseOutInBounce, "net.maxon.blendfunction.easeoutinbounce");
}

#include "blend_function2.hxx"

}


#endif // BLEND_FUNCTION_H__
