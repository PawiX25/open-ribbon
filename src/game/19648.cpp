extern "C" {
#include "common.h"

#if 0

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct03; // size unknown

typedef struct {
    s32 pad0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    s32 unk24;
    UnkStruct03 unk28;
} UnkStruct04; // size 0x30?

typedef struct {
    u8  pad0[0x180];
    u16 unk180;
    u16 unk182;
    u8  pad184[0x26];
    s16 unk1AA;
    u8  pad1AC[0x4];
    s16 unk1B0;
    u16 unk1B2;
    s16 unk1B4;
    s16 unk1B6;
    u16 unk1B8;
    s16 unk1BA;
} UnkStruct06;

extern UnkStruct06 *D_80042B28;

INCLUDE_ASM("asm/game/nonmatchings/19648", func_80031E48);
#else
INCLUDE_ASM("asm/game/nonmatchings/19648", func_80031E48);
#endif

}
