extern "C" {
#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>
}

// NOTE: -G0 override for this file

extern "C" {
FAInstance FontHack_Instance = {0, 0};
char D_80047EDC[2] = {'\n', '\n'};
}

struct random_access_iterator_tag {};

extern "C" s32* func_8001E658(s32* first, s32* last, s32* value, random_access_iterator_tag)
{
    s32 trip_count = (last - first) >> 2;
    for (; trip_count > 0; --trip_count) {
        if (*first == *value)
            return first;
        ++first;
        if (*first == *value)
            return first;
        ++first;
        if (*first == *value)
            return first;
        ++first;
        if (*first == *value)
            return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*first == *value)
            return first;
        ++first;
    case 2:
        if (*first == *value)
            return first;
        ++first;
    case 1:
        if (*first == *value)
            return first;
        ++first;
    case 0:
    default:
        return last;
    }
}

// FontHack::Dtor
extern "C" void FontHack__Dtor()
{
    FontHack__UnkFunc00(&FontHack_Instance, 2);
    if (((s32) (vsync.unk8 - (s32)vsync.cb) >> 2) != 0)
        MemorySys__free(vsync.cb);
}

// *FontHack::Ctor
INCLUDE_ASM("asm/game/nonmatchings/FontHack", FontHack__Ctor);
