#pragma once

#include <cstdint>
#include <string>
#include <Windows.h>

enum class Color : std::uint16_t
{
	Bright = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	Yellow = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	Purple = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
	Red = FOREGROUND_RED | FOREGROUND_INTENSITY,
	Cyan = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	Green = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	Blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Default = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,
};

template <Color color = Color::Default, class ...ArgsT>
void __forceinline Log(const std::string& format, bool newLine = true, ArgsT &&...args)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdOut, (uint16_t)color);

	fprintf(
		stdout,
		format.c_str(),
		std::forward<ArgsT>(args)...
	);

	if (newLine)
		std::cout << '\n';

	SetConsoleTextAttribute(hStdOut, (uint16_t)Color::Default);
}
