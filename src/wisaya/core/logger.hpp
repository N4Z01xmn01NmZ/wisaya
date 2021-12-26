#pragma once

#include <wsydef.hpp>
#include <wsymemory.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Wisaya {

    class WSYAPI Logger
    {
    public:
        Logger() = default;
        ~Logger() = default;

        static void Initialize();
        static void Shutdown();

        static shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
        static shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    private:
        static shared_ptr<spdlog::logger> s_CoreLogger;
        static shared_ptr<spdlog::logger> s_ClientLogger;
    };

} // namespace Wisaya
