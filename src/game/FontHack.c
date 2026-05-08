#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

// NOTE: -G0 override for this file

FAInstance FontHack_Instance = {0, 0};
char D_80047EDC[2] = "\n\n";

s32* func_8001E658(s32 *start, s32 *end, s32 *target, s32 _unused) {
    s32 v = *target;
    while (start < end) {
        if (*start == v) return start;
        start++;
    }
    return end;
}

// FontHack::Dtor
void FontHack__Dtor()
{
    FontHack__UnkFunc00(&FontHack_Instance, 2);
    if (((s32) (vsync.unk8 - (s32)vsync.cb) >> 2) != 0)
        MemorySys__free(vsync.cb);
}

// *FontHack::Ctor
extern s32 D_80047EC0;
extern s32 D_80047EC4;
extern s32 D_80047EC8;
extern s32 D_80047ECC;

void FontHack__Ctor(void) {
    vsync.cb = NULL;
    D_80047EC0 = 0;
    D_80047EC4 = 0;
    D_80047EC8 = 0;
    D_80047ECC = 0;
    vsync.tail = NULL;
    vsync.unk8 = 0;
    func_8002AEC0(&FontHack_Instance, (s32*)FntFlush);
}
