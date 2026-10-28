#pragma once

// P3/t56：刚体稳定身份的纯逻辑解析（不依赖 C4D 类型，产品与离线夹具共用同一份分支）。
// 缺陷 A 的根因是产品用 GetInt32 读一个字符串参数（RIGID_INDEX 由 mmd_rigid_manager.cpp:449
// 以 String::IntToString 写入）→ 恒读 0 → 身份全重复 → 写回整帧被拒。
// 这里只做「文本/整数 → PMX 刚体下标」；非法值一律返回 -1，由调用方 fail-closed。

#include <cerrno>
#include <cstdint>
#include <cstdlib>

// R20 的 Maxon Source Processor 不认识 C++17 嵌套命名空间简写，必须用经典嵌套写法。
namespace cmt
{
	namespace physics
	{

//! 解析字符串形态的身份（真实写入形态，DA_STRING）。
//! 空串、非纯数字、负数、溢出都返回 -1。
//! 注意用 strtoll：Windows 上 long 是 32 位，"99999999999" 会让 strtol 饱和成 LONG_MAX
//! 并只置 ERANGE——那样会把溢出值当成合法身份 2147483647。
inline std::int32_t ParseRigidIdentityText(const char* const text)
{
	if (!text || text[0] == '\0')
		return -1;

	errno = 0;
	char* end = nullptr;
	const long long value = std::strtoll(text, &end, 10);
	if (!end || *end != '\0' || errno == ERANGE)
		return -1;
	if (value < 0 || value > 0x7FFFFFFFLL)
		return -1;
	return static_cast<std::int32_t>(value);
}

//! 解析整数形态的身份（兼容形态，DA_LONG）。负数返回 -1。
inline std::int32_t ParseRigidIdentityLong(const long long value)
{
	if (value < 0 || value > 0x7FFFFFFFLL)
		return -1;
	return static_cast<std::int32_t>(value);
}

	}
} // namespace cmt::physics
