#ifndef WSYLOG_H
#define WSYLOG_H

#pragma once

#include <wsydef.hpp>

#ifndef WSY_CONFIG_RELEASE
    #include <wisaya/core/logger.hpp>
    
    // ENGINE log macros
    #define WSY_CORE_TRACE(...)    ::Wisaya::Logger::GetCoreLogger()->trace(__VA_ARGS__)
    #define WSY_CORE_INFO(...)     ::Wisaya::Logger::GetCoreLogger()->info(__VA_ARGS__)
    #define WSY_CORE_WARN(...)     ::Wisaya::Logger::GetCoreLogger()->warn(__VA_ARGS__)
    #define WSY_CORE_ERROR(...)    ::Wisaya::Logger::GetCoreLogger()->error(__VA_ARGS__)
    #define WSY_CORE_CRITICAL(...) ::Wisaya::Logger::GetCoreLogger()->critical(__VA_ARGS__)

    // CLIENT log macros
    #define WSY_TRACE(...)    ::Wisaya::Logger::GetClientLogger()->trace(__VA_ARGS__)
    #define WSY_INFO(...)     ::Wisaya::Logger::GetClientLogger()->info(__VA_ARGS__)
    #define WSY_WARN(...)     ::Wisaya::Logger::GetClientLogger()->warn(__VA_ARGS__)
    #define WSY_ERROR(...)    ::Wisaya::Logger::GetClientLogger()->error(__VA_ARGS__)
    #define WSY_CRITICAL(...) ::Wisaya::Logger::GetClientLogger()->critical(__VA_ARGS__)
#else
    // ENGINE log macros
    #define WSY_CORE_TRACE(...)
    #define WSY_CORE_INFO(...)
    #define WSY_CORE_WARN(...)
    #define WSY_CORE_ERROR(...)
    #define WSY_CORE_CRITICAL(...)

    // CLIENT log macros
    #define WSY_TRACE(...)
    #define WSY_INFO(...)
    #define WSY_WARN(...)
    #define WSY_ERROR(...)
    #define WSY_CRITICAL(...)
#endif

#endif // WSYLOG_H