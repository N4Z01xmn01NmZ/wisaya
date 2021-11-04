#pragma once
#ifndef WSYBASICTYPE_H
#define WSYBASICTYPE_H

#include <stddef.h>
#include <stdbool.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @brief Definition of basic types used in Wisaya
 * 
 */

typedef bool wsyBool;                   ///< boolean type
typedef char wsyBool8;                  ///< 8-bit boolean type
typedef int wsyBool32;                  ///< 32-bit boolean type

typedef char wsyChar;                   ///< character type
typedef unsigned char wsyUChar;         ///< unsigned character type

typedef unsigned char wsyByte;          ///< byte type
typedef signed char wsyInt8;            ///< 8-bit signed interger type
typedef unsigned char wsyUInt8;         ///< 8-bit unsigned interger type

typedef signed short wsyInt16;          ///< 16-bit signed interger type
typedef unsigned short wsyUInt16;       ///< 16-bit unsigned interger type

typedef signed int wsyInt32;            ///< 32-bit signed interger type
typedef unsigned int wsyUInt32;         ///< 32-bit unsigned interger type

typedef signed long long wsyInt64;      ///< 64-bit signed interger type
typedef unsigned long long wsyUInt64;   ///< 64-bit unsigned interger type

typedef float wsyFloat32;               ///< 32-bit floating point type
typedef double wsyFloat64;              ///< 64-bit floating point type

#ifdef  __cplusplus
}
#endif

/**
 * @brief Static assertion macros
 * 
 */

#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(wsyInt8) == 1, "Expected wsyInt8 to be 1 byte.");
STATIC_ASSERT(sizeof(wsyInt16) == 2, "Expected wsyInt16 to be 2 bytes.");
STATIC_ASSERT(sizeof(wsyInt32) == 4, "Expected wsyInt32 to be 4 bytes.");
STATIC_ASSERT(sizeof(wsyInt64) == 8, "Expected wsyInt64 to be 8 bytes.");

STATIC_ASSERT(sizeof(wsyUInt8) == 1, "Expected wsyUInt8 to be 1 byte.");
STATIC_ASSERT(sizeof(wsyUInt16) == 2, "Expected wsyUInt16 to be 2 bytes.");
STATIC_ASSERT(sizeof(wsyUInt32) == 4, "Expected wsyUInt32 to be 4 bytes.");
STATIC_ASSERT(sizeof(wsyUInt64) == 8, "Expected wsyUInt64 to be 8 bytes.");

STATIC_ASSERT(sizeof(wsyFloat32) == 4, "Expected wsyUInt64 to be 4 bytes.");
STATIC_ASSERT(sizeof(wsyFloat64) == 8, "Expected wsyUInt64 to be 8 bytes.");

#endif // WSYBASICTYPE_H