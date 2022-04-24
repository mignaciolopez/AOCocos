#pragma once

#include "spdlog/spdlog.h"

#include <memory>

#include "cocos2d.h"

class ECS_Log
{
public:
	static bool init();
	static void shutdown();

	static std::shared_ptr<spdlog::logger> s_logger;
};