#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Fita {
	
	class FITA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define FI_CORE_TRACE(...) ::Fita::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FI_CORE_INFO(...)  ::Fita::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FI_CORE_WARN(...)  ::Fita::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FI_CORE_ERROR(...) ::Fita::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FI_CORE_FATAL(...) ::Fita::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FI_TRACE(...) ::Fita::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FI_INFO(...)  ::Fita::Log::GetClientLogger()->info(__VA_ARGS__)
#define FI_WARN(...)  ::Fita::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FI_ERROR(...) ::Fita::Log::GetClientLogger()->error(__VA_ARGS__)
#define FI_FATAL(...) ::Fita::Log::GetClientLogger()->fatal(__VA_ARGS__)