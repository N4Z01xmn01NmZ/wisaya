#pragma once
#ifndef WSYDEF_H
#define WSYDEF_H

/**
 * @brief Platform detection macros
 * 
 */

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    /* Windows x64 */
    #define WSY_PLATFORM_WINDOWS 1
    #ifndef _WIN64
        /* Windows x86 */
        #error "Does not support x86 builds!"
    #endif
/* Android is based on linux kernel
 * it has __linux__ defined */
#elif defined(__linux__) || defined(__gnu_linux__)
    #if defined(__ANDROID__)
        /* Android */
        #define WSY_PLATFORM_ANDROID 1
        #error "Does not support android!"
    #else
        /* Linux OS */
        #define WSY_PLATFORM_LINUX 1
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_IPHONE == 1
        #define WSY_PLATFORM_IOS 1
        #if TARGET_IPHONE_SIMULATOR == 1
            #define WSY_PLATFORM_IOS_SIMULATOR 1
            #error "Does not support IOS simulator!"
        #elif TARGET_OS_MACCATALYST == 1
            #define WSY_PLATFORM_MACCATALYST 1
            #error "Does not support mac catalyst!"
        #endif
        #error "Does not support IOS!"
    #elif TARGET_OS_MAC == 1
        #define WSY_PLATFORM_MACOS 1
        #error "Does not support macOS!"
    #else
        #error "Unknown Apple platform!"
    #endif
/* Catch anything uncaught above */
#elif defined(__unix__)
    #define WSY_PLATFORM_UNIX 1
    #error "Does not support unix compiler!"
#elif defined(_POSIX_VERSION)
    #define WSY_PLATFORM_POSIX 1
    #error "Does not support posix compiler!"
#else
    #error "Target unknown!"
#endif

/**
 * @brief DLL export macros
 * 
 */

#ifdef WSY_DLL_EXPORT
    #ifdef _MSC_VER
        #define WSYAPI __declspec(dllexport)
    #else
        #define WSYAPI __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define WSYAPI __declspec(dllimport)
    #else
        #define WSYAPI
    #endif
#endif // WSY_DLL_EXPORT

#endif // WSYDEF_H
