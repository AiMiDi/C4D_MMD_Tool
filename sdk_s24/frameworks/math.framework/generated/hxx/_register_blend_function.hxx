#if 1
namespace maxon
{
	const maxon::Char* const BlendFunctionInterface::MTable::_ids = 
		"MapValue@41dbd00062220997\0" // Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue)
	"";
	const maxon::METHOD_FLAGS BlendFunctionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BlendFunctionInterface, , "net.maxon.interface.blendfunction", "maxon.BlendFunctionInterface", (ObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(BlendFunctions);
	namespace BlendFunctions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Linear, , "net.maxon.blendfunction.linear");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInQuad, , "net.maxon.blendfunction.easeinquad");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutQuad, , "net.maxon.blendfunction.easeoutquad");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutQuad, , "net.maxon.blendfunction.easeinoutquad");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInQuad, , "net.maxon.blendfunction.easeoutinquad");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInCubic, , "net.maxon.blendfunction.easeincubic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutCubic, , "net.maxon.blendfunction.easeoutcubic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutCubic, , "net.maxon.blendfunction.easeinoutcubic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInCubic, , "net.maxon.blendfunction.easeoutincubic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInQuart, , "net.maxon.blendfunction.easeinquart");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutQuart, , "net.maxon.blendfunction.easeoutquart");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutQuart, , "net.maxon.blendfunction.easeinoutquart");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInQuart, , "net.maxon.blendfunction.easeoutinquart");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInQuint, , "net.maxon.blendfunction.easeinquint");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutQuint, , "net.maxon.blendfunction.easeoutquint");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutQuint, , "net.maxon.blendfunction.easeinoutquint");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInQuint, , "net.maxon.blendfunction.easeoutinquint");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInSext, , "net.maxon.blendfunction.easeinsext");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutSext, , "net.maxon.blendfunction.easeoutsext");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutSext, , "net.maxon.blendfunction.easeinoutsext");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInSext, , "net.maxon.blendfunction.easeoutinsext");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInSine, , "net.maxon.blendfunction.easeinsine");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutSine, , "net.maxon.blendfunction.easeoutsine");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutSine, , "net.maxon.blendfunction.easeinoutsine");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInSine, , "net.maxon.blendfunction.easeoutinsine");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInExpo, , "net.maxon.blendfunction.easeinexpo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutExpo, , "net.maxon.blendfunction.easeoutexpo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutExpo, , "net.maxon.blendfunction.easeinoutexpo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInExpo, , "net.maxon.blendfunction.easeoutinexpo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInCirc, , "net.maxon.blendfunction.easeincirc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutCirc, , "net.maxon.blendfunction.easeoutcirc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutCirc, , "net.maxon.blendfunction.easeinoutcirc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInCirc, , "net.maxon.blendfunction.easeoutincirc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInElastic, , "net.maxon.blendfunction.easeinelastic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutElastic, , "net.maxon.blendfunction.easeoutelastic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutElastic, , "net.maxon.blendfunction.easeinoutelastic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInElastic, , "net.maxon.blendfunction.easeoutinelastic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInBack, , "net.maxon.blendfunction.easeinback");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutBack, , "net.maxon.blendfunction.easeoutback");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutBack, , "net.maxon.blendfunction.easeinoutback");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInBack, , "net.maxon.blendfunction.easeoutinback");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInBounce, , "net.maxon.blendfunction.easeinbounce");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutBounce, , "net.maxon.blendfunction.easeoutbounce");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseInOutBounce, , "net.maxon.blendfunction.easeinoutbounce");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(EaseOutInBounce, , "net.maxon.blendfunction.easeoutinbounce");
	}
}
#endif
