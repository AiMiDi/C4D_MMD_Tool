#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_FileUtilities(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_ReadFileToMemory)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "name\0arr\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_ReadUtfFile)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0arr\0defaultDecoding\0", 25LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_WriteUtfFile)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0arr\0encoding\0dontWriteHeader\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CompareFiles)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "file1\0file2\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CopyStream)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "from\0to\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CopyStreamProgress)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "from\0to\0progress\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CopyFileOrDirectory)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "from\0to\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CopyFileOrDirectory_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "from\0to\0archive\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_WriteDirectoryTree)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "root\0out\0filterDelegate\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_ReadDirectoryTree)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "in\0receiver\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CreateCStringOutputStream)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0maxLength\0", 6LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_CreateNullOutputStream)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_WriteArray)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "out\0buffer\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_WriteString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "out\0string\0encoding\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FileUtilities::MTable::_instance.FileUtilities_ReadString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "in\0decoding\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FileUtilities::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_FileUtilities("net.maxon.interface.fileutilities", nullptr, &RegisterReflection_FileUtilities, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
