#include "utils.hpp"

void Utils::OutputLogo()
{
	Log<Color::Red>(R"(                 _ _           _             )");
	Log<Color::Red>(R"(                | | |         | |            )");
	Log<Color::Red>(R"(  __  _____ ___ | | | ___  ___| |_ ___  _ __ )");
	Log<Color::Red>(R"(  \ \/ / __/ _ \| | |/ _ \/ __| __/ _ \| '__|)");
	Log<Color::Red>(R"(   >  < (_| (_) | | |  __/ (__| || (_) | |   )");
	Log<Color::Red>(R"(  /_/\_\___\___/|_|_|\___|\___|\__\___/|_|   )");

	Log<Color::Red>("\n      Author: ", false);
	Log<Color::Default>("github.com/EternalRift\n");
}

void Utils::Output(const std::string& msg, bool newLine)
{
	Log<Color::Default>("  [", false);
	Log<Color::Red>("#", false);
	Log<Color::Default>("] ", false);

	Log<Color::Default>(msg, newLine);
}

void SetConsoleCursor(bool shown)
{
	HANDLE out{ GetStdHandle(STD_OUTPUT_HANDLE) };

	// Store the cursor information
	//
	CONSOLE_CURSOR_INFO cursor_info{};

	GetConsoleCursorInfo(out, &cursor_info);

	// Set the cursor visibility
	//
	cursor_info.bVisible = shown;

	SetConsoleCursorInfo(out, &cursor_info);
}

void Utils::HideScrollbar()
{
	HANDLE out{ GetStdHandle(STD_OUTPUT_HANDLE) };

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(out, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;

	SetConsoleScreenBufferSize(out, csbi.dwSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}

void Utils::InitializeConsole()
{
	SetConsoleTitle("xcollector 1.0");

	HANDLE out{ GetStdHandle(STD_OUTPUT_HANDLE) };

	DWORD dwMode{ 0 }; GetConsoleMode(out, &dwMode);

	SetConsoleMode(out,
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	SetConsoleCursor(false); HideScrollbar();
}
