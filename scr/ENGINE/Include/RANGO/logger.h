#pragma once 
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include "Base.h"
namespace RANGO {
class Log{
public:
    Log();
    ~Log();
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()    {return s_CoreLogger;}
private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger; 

};
}
#define CORE_TRACE(...)  ::RANGO::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)   ::RANGO::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)   ::RANGO::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)  ::RANGO::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...)  ::RANGO::Log::GetCoreLogger()->critical(__VA_ARGS__)

