/**
 * @file large_bit_mask.h
 * @author Luong The Hai (hailuongthe2000@gmail.com)
 * @brief Header file for library
 * @version 0.1
 * @date 2024-12-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _LARGE_BIT_MASK_H_
#define _LARGE_BIT_MASK_H_

#if defined(_WIN32)
    #if defined(BUILD_LIBTYPE_SHARED)
        #if defined(__TINYC__)
            #define __declspec(x) __attribute__((x))
        #endif
        #define EXTENDAPI __declspec(dllexport)     // We are building the library as a Win32 shared library (.dll)
    #elif defined(USE_LIBTYPE_SHARED)
        #define EXTENDAPI __declspec(dllimport)     // We are using the library as a Win32 shared library (.dll)
    #endif
#endif

#ifndef EXTENDAPI
    #define EXTENDAPI       // Functions defined as 'extern' by default (implicit specifiers)
#endif

#ifdef RUN_TEST
    #define STATIC_FUNCTION EXTENDAPI
#else
    #define STATIC_FUNCTION static
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" 
{
#endif //__cplusplus

/**
 * @brief single bit mask type
 * 
 */
typedef unsigned char bit_t;

/**
 * @brief bit mask type
 * 
 */
typedef bit_t* bitmask_t;

/**
 * @example main.c
 * Example for large bit mask library
 */

/**
 * @brief Get the Capacity Size object
 * 
 * @param allocateBits allocated bits for bit mask 
 * @return size_t total bytes needed
 */
STATIC_FUNCTION size_t getCapacitySize(size_t allocateBits);

/**
 * @brief initialize bit mask
 * 
 * @param allocatedBits allocated bits for bit mask
 * @param totalSize [out] total size of bit mask in bytes
 * @return bitmask_t the pointer of bit mask
 */
EXTENDAPI bitmask_t initBitMask(size_t allocatedBits, size_t* totalSize);

/**
 * @brief clean bit mask
 * 
 * @param bitmask the pointer of bit mask need cleaning
 */
EXTENDAPI void cleanBitMask(bitmask_t bitmask);

/**
 * @brief Set bit value for specific position
 * 
 * @param bitmask bit mask
 * @param capacityBytes total bytes of bit mask
 * @param position the specific position
 * @param value value of the position
 * @return int return 1 if successfully. Otherwise, 0
 */
EXTENDAPI int setBit(bitmask_t bitmask, size_t capacityBytes, size_t position, bit_t value);

/**
 * @brief get the value of bit
 * 
 * @param bitmask bit mask
 * @param capacityBytes total bytes of bitmask
 * @param position the position of bit
 * @return bit_t the value of bit, if the return value is 0xff, get bit is invalid
 */
EXTENDAPI bit_t getBit(bitmask_t bitmask, size_t capacityBytes, size_t position);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!_LARGE_BIT_MASK_H_