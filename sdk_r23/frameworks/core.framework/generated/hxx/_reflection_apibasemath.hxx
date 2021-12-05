#if 1
#ifndef APIBASE_H__
#endif
namespace maxon
{
#ifdef MAXON_TARGET_SINGLEPRECISION
#else
#endif
#ifndef NOTOK
#endif
#ifdef MAXON_TARGET_ANDROID
#endif
#ifndef SIZEOF
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_maxon_ASin_74320eb4909490b4(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] = {
			maxon::reflection::GetFunctionInfo("net.maxon.ASin" "@74320eb4909490b4", maxon::reflection::Member::KIND::FUNCTION, "val\0", 0LL, (Float64(*)(Float64)) &ASin)
				};
		return callback(cls, nullptr, maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_maxon_ASin_74320eb4909490b4(nullptr, nullptr, &RegisterReflection_maxon_ASin_74320eb4909490b4, &PRIVATE_MAXON_MODULE);
#endif
}
namespace maxon
{
#if 1
#else
#endif
}
#endif
