#ifndef WSYASSERT_H
#define WSYASSERT_H

#pragma once

#include "wsydef.h"

#ifdef WSY_ASSERT_ENABLE
    #include <wisaya/core/logger.hpp>

    #define WSY_ASSERT_IMPL_REPORT(type, expr, fmt, ...) { if(expr) {} else { WSY##type##ERROR(fmt, __VA_ARGS__); WSY_DEBUGBREAK(); } }

    #include <filesystem>

    #define WSY_ASSERT_IMPL_MSG(type, expr, ...) WSY_ASSERT_IMPL_REPORT(type, expr, "Assertion failure: {0}", __VA_ARGS__)
    #define WSY_ASSERT_IMPL_NO_MSG(type, expr) WSY_ASSERT_IMPL_REPORT(type, expr, "Assertion '{0}' failed at {1}:{2}", #expr, std::filesystem::path(__FILE__).filename().string(), __LINE__)
    
    #define WSY_ASSERT_IMPL_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
    #define WSY_ASSERT_IMPL_GET_MACRO(...) WSY_EXPAND_MACRO( WSY_ASSERT_IMPL_GET_MACRO_NAME(__VA_ARGS__, WSY_ASSERT_IMPL_MSG, WSY_ASSERT_IMPL_NO_MSG) )
    
    #define WSY_ASSERT(...) WSY_EXPAND_MACRO( WSY_ASSERT_IMPL_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
    #define WSY_CORE_ASSERT(...) WSY_EXPAND_MACRO( WSY_ASSERT_IMPL_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
    #define WSY_ASSERT(...)
    #define WSY_CORE_ASSERT(...)
#endif // WSY_ASSERT_ENABLE

#endif // WSYASSERT_H
