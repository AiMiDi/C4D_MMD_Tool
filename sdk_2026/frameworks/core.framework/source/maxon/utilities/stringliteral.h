#ifndef STRINGLITERAL_H__
#define STRINGLITERAL_H__

namespace maxon
{

#if __cplusplus >= 202002L

/// this helper files can be used to use c++20 string literals in 2 different ways:
/// 1. for const char[]: StringLiteral(__FILE__)
/// 2. for const char*: StringLiteral<GetStringLengthWith0(MAXON_FILE)>(MAXON_FILE, true)

consteval size_t GetStringLengthWith0(const char* str)
{
	size_t i;
	for (i = 0; str[i] != 0; i++)
	{
	}
	return i + 1; // add \0 character
}

template <size_t N>
struct StringLiteral
{
	static constexpr size_t SIZE = N;

	// stylecheck.explicit=false
	constexpr StringLiteral(const char (&str)[N])
	{
		for (size_t i = 0; i < N; i++)
			value[i] = str[i];
	}

	constexpr StringLiteral(const char* str, bool)
	{
		for (size_t i = 0; i < N; i++)
			value[i] = str[i];
	}
	// stylecheck.explicit=true

	char value[N];
};

template <size_t N> StringLiteral(const char (&str)[N]) -> StringLiteral<N>; // fix -Wctad-maybe-unsupported warning

#endif

}

#endif // STRINGLITERAL_H__
