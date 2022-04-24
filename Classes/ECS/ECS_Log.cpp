#include "ECS_Log.h"

#include "spdlog/sinks/basic_file_sink.h"

USING_NS_CC;

std::shared_ptr<spdlog::logger> ECS_Log::s_logger;

bool ECS_Log::init()
{
	auto logPath = FileUtils::getInstance()->getWritablePath();

	s_logger = spdlog::basic_logger_mt("AOG", logPath + "logs/aog.log");

	cocos2d::log(logPath.c_str());

	spdlog::set_default_logger(s_logger);
	s_logger->set_level(spdlog::level::trace);

	return true;
}

void ECS_Log::shutdown()
{
	spdlog::shutdown();
}
