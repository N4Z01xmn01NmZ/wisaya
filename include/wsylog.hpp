#ifndef WSYLOG_H
#define WSYLOG_H

#pragma once

#include <wsydef.hpp>

#ifndef WSY_CONFIG_RELEASE
    #include <wisaya/core/WAppLog.hpp>
    
    // ENGINE log macros
    #define WSY_CORE_TRACE(...)    ::Wisaya::WAppLog::GetCoreLogger()->trace(__VA_ARGS__)
    #define WSY_CORE_INFO(...)     ::Wisaya::WAppLog::GetCoreLogger()->info(__VA_ARGS__)
    #define WSY_CORE_WARN(...)     ::Wisaya::WAppLog::GetCoreLogger()->warn(__VA_ARGS__)
    #define WSY_CORE_ERROR(...)    ::Wisaya::WAppLog::GetCoreLogger()->error(__VA_ARGS__)
    #define WSY_CORE_CRITICAL(...) ::Wisaya::WAppLog::GetCoreLogger()->critical(__VA_ARGS__)

    // CLIENT log macros
    #define WSY_TRACE(...)    ::Wisaya::WAppLog::GetClientLogger()->trace(__VA_ARGS__)
    #define WSY_INFO(...)     ::Wisaya::WAppLog::GetClientLogger()->info(__VA_ARGS__)
    #define WSY_WARN(...)     ::Wisaya::WAppLog::GetClientLogger()->warn(__VA_ARGS__)
    #define WSY_ERROR(...)    ::Wisaya::WAppLog::GetClientLogger()->error(__VA_ARGS__)
    #define WSY_CRITICAL(...) ::Wisaya::WAppLog::GetClientLogger()->critical(__VA_ARGS__)
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