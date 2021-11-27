#pragma once

#include <iostream>
#include <filesystem>
#include <thread>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <regex>
#include <limits>
#include <algorithm>
#include <execution>
#include <future>
#include "progress.hpp"
#include "logger.hpp"

#undef max

using namespace nlohmann;
namespace fs = std::filesystem;

namespace Constants
{
	inline std::string Api = "https://osucollector.com/api/collections/%s/beatmapsv2?perPage=5000&sortBy=beatmapset.artist&orderBy=asc";
	inline const std::string BeatConnect = "https://beatconnect.io/b/%s/";

	// Console colors (portable)
	//
	inline const char* White = "\033[0m";
	inline const char* Black = "\x1B[30m";
	inline const char* Green = "\x1B[32m";
	inline const char* Orange = "\x1B[33m";
	inline const char* Blue = "\x1B[36;1m";
	inline const char* Purple = "\033[35m";
	inline const char* Red = "\x1B[31m";
	inline const char* Clear = "\033c";
}

namespace Utils
{
	void OutputLogo();
	void Output(const std::string& msg, bool newLine = false);
	void HideScrollbar();
	void InitializeConsole();
}