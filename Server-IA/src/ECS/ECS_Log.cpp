#include "ECS_Log.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> ECS_Log::s_fileL;
std::shared_ptr<spdlog::logger> ECS_Log::s_consoleL;

bool ECS_Log::init()
{
	s_fileL = spdlog::basic_logger_mt("SERVER-IA", "logs/Server-IA.log");

	spdlog::set_default_logger(s_fileL);
	s_fileL->set_level(spdlog::level::trace);

	s_consoleL = spdlog::stdout_color_mt("console");
	s_consoleL->set_level(spdlog::level::trace);

	return s_fileL != nullptr;
}

void ECS_Log::shutdown()
{
	//ECS_Log::s_fileL->debug("[ECS_Log] shutdown() s_fileLogger count: {}", s_fileL.use_count());
	//ECS_Log::s_fileL->debug("[ECS_Log] shutdown() s_fileLogger address: {:p}", (void*)&s_fileL);
	s_fileL->flush();

	spdlog::shutdown();
}
