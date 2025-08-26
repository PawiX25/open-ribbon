#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

#define NULL (0)

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define PADDING(n, s) \
    u8 n[s]

#endif /* COMMON_H */
