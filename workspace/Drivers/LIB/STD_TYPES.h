/*
 * STD_TYPES.h
 *
 *  Created on: 23 Jul 2026
 *      Author: LOQ
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

// 8 bits
typedef unsigned char u8;
typedef signed char s8;

// 16 bits
typedef unsigned short int u16;
typedef signed short int s16;

// 32 bits
typedef unsigned long int u32;
typedef signed long int s32;

// 64 bits
typedef unsigned long long int u64;

// floating points
typedef float f32;
typedef double f64;

#ifndef NULLX
#define NULL  ((void*)0)
#endif

#endif /* LIB_STD_TYPES_H_ */
