#pragma once

#include "spdlog/spdlog.h"

#include <memory>

class ECS_Log
{
public:
	static bool init();
	static void shutdown();

	static std::shared_ptr<spdlog::logger> s_fileL;
	static std::shared_ptr<spdlog::logger> s_consoleL;
};