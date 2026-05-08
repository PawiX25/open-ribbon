#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800271A0);

void func_80027340(UnkStruct16* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk18 += arg0->unk1C;
        return;
    }
    if (arg0->unk18 != 0) {
        arg0->unk18 += arg0->unk1C;
        if (arg0->unk18 == 0) {
            arg0->unk1C = 1;
        }
    }
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_80027394);

typedef struct {
    s32 unk0;
    char pad4[0x8];
    UnkStruct16 *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} AnimStruct;

extern void func_80025954(UnkStruct16*);

void func_800274EC(AnimStruct* arg0, s32 arg1) {
    if (arg0->unk0 == 0) {
        arg0->unk18 = 0;
        arg0->unk1C = 1;
    }
    arg0->unk0++;
    if (arg0->unk0 > arg0->unk14) {
        func_80027340((UnkStruct16*)arg0, arg1);
        arg0->unkC->unk18 = 0;
        if (arg0->unk18 == 0) {
            func_80025954(arg0->unkC);
        }
    }
}

s32 func_80027570(void) {
    return 1;
}

void func_80027578(UnkStruct12* arg0) {
    arg0->unk0 = arg0->unk14 - 1;
}

void func_8002758C(UnkStruct14* arg0) {
    UnkStruct15* temp_v0;

    temp_v0 = arg0->unkC;
    arg0->unk0 = 0;
    temp_v0->unk10 = 0;
    UnkFunc01(temp_v0, 0x8000);
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800275BC);

typedef struct VT_2780C {
    char pad0[0x20];
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
} VT_2780C;

typedef struct Item_2780C {
    char pad8[8];
    void *vt;
} Item_2780C;

typedef struct Container_2780C {
    s32 count;
    Item_2780C *items[10];
    s32 unk2C;
    VT_2780C *vt;
    s32 unk34;
    s32 unk38;
} Container_2780C;

extern s32 func_80025EBC(s32);

void func_8002780C(Container_2780C *arg0, s32 arg1) {
    s32 i;
    VT_2780C *vt = arg0->vt;
    vt->func24((s32)arg0 + (s32)vt->offset20);
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_2780C *item = arg0->items[i];
            VT_2780C *vt2 = (VT_2780C*)item->vt;
            vt2->func2C((s32)item + (s32)vt2->offset28, arg1);
            i++;
        } while (i < arg0->count);
    }
    arg0->unk38 = func_80025EBC(0x335);
}

s32 func_800278BC(UnkStruct13* arg0) {
    return func_80025EBC(0x335) < arg0->unk38;
}

void func_800278EC(UnkStruct11* arg0) {
    arg0->unk2C = 1;
}

extern s32 func_8002990C(void);

void func_800278F8(Container_2780C *arg0) {
    s32 i;
    if (func_80025EBC(0x335) > arg0->unk38) {
        arg0->unk34 = 0;
    }
    if (arg0->unk34 != 0) {
        if (func_8002990C() != 0) {
            VT_2780C *vt = arg0->vt;
            vt->func2C((s32)arg0 + (s32)vt->offset28, 1);
        }
    }
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_2780C *item = arg0->items[i];
            VT_28E74 *vt2 = (VT_28E74*)item->vt;
            vt2->func14((s32)item + (s32)vt2->offset10, arg0->unk2C);
            i++;
        } while (i < arg0->count);
    }
    if (arg0->unk38 < 0xBB8) {
        arg0->unk38 = arg0->unk38 + 1;
    }
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800279E4);
