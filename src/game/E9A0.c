#include "common.h"
#include "globals.h"

typedef struct {
    s32 unk0;
    char pad4[0x8];
    UnkStruct16 *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} AnimStruct;

typedef struct VT_E9A0 {
    char pad0[0x10];
    s16 offset10;
    char pad12[2];
    void (*func14)(s32, s32);
    s16 offset18;
    char pad1A[2];
    s32 (*func1C)(s32);
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
} VT_E9A0;

typedef struct Item_E9A0 {
    char pad0[8];
    VT_E9A0 *vt;
} Item_E9A0;

typedef struct Container_E9A0 {
    s32 count;
    Item_E9A0 *items[10];
    s32 unk2C;
    VT_E9A0 *vt30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
} Container_E9A0;

extern char D_80019F08[];
extern char D_80019ED0[];
extern char D_80019790[];
extern char D_800197B8[];
extern char D_80040204[];
extern char D_800401F0[];
extern char D_80040234[];
extern char D_80040244[];
extern char D_800402E4[];
extern char D_80048054[];
extern char D_80040320[];
extern char D_80019870[];
extern char D_80019888[];
extern char D_80019DD8[];
extern char D_80019F40[];

extern s32 func_800303BC(s32);
extern s32 func_80026AA0(s32, void*);
extern s32 func_80025F44(s32, void*, void*, void*);
extern s32 func_80026F5C(s32, void*);
extern s32 func_80025330(s32);
extern void* func_800256CC(s32, s32, s32, s32);
extern s32 FileSys__LoadFile(void*, void*, s32, void*);
extern void func_80024CC4(s32, s32);
extern void func_800258B0(void*, s32);
extern void func_80025954(UnkStruct16*);
extern s32 func_8002990C(void);
extern void AudioSys__UnkFunc01(void*, s32, s32, s32);
extern s32 AudioSys__UnkFunc09(s32);

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

void func_8002780C(Container_E9A0 *arg0, s32 arg1) {
    s32 i;
    VT_E9A0 *vt = arg0->vt30;
    Item_E9A0 *item;
    VT_E9A0 *vt2;

    vt->func24((s32)arg0 + (s32)vt->offset20);
    if (arg0->count > 0) {
        i = 0;
        do {
            item = arg0->items[i];
            vt2 = item->vt;
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

void func_800278F8(Container_E9A0* self) {
    if (self->unk38 >= func_80025EBC(0x335)) {
        self->unk34 = 0;
    }
    if (self->unk34 != 0) {
        if (func_8002990C() != 0) {
            VT_E9A0* vt = self->vt30;
            vt->func2C((s32)self + (s32)vt->offset28, 1);
        }
    }
    if (self->count > 0) {
        s32 i = 0;
        do {
            Item_E9A0* item = self->items[i];
            VT_E9A0* vt = item->vt;
            vt->func14((s32)item + (s32)vt->offset10, self->unk2C);
            i++;
        } while (i < self->count);
    }
    {
        s32 t = self->unk38;
        if (t < 0xBB8) {
            self->unk38 = t + 1;
        }
    }
}

typedef struct {
    s32 f0;
    s32 f4;
} Local79E4;

s32 func_800279E4(Container_E9A0* self) {
    s32 result;
    s32 i;

    if (self->unk2C == 0) {
        if (func_8002990C() != 0) {
            Local79E4 local;
            Local79E4* p = &local;
            self->unk2C = 1;
            p->f0 = 0;
            p->f4 = 0;
            AudioSys__UnkFunc01(p, 1, 0x40, -1);
        }
        if (self->unk2C == 0) {
            result = 1;
            goto loop;
        }
    }
    if (AudioSys__UnkFunc09(1) != 0) {
        result = 1;
        goto loop;
    }
    return 1;
loop:
    for (i = 0; i < self->count; i++) {
        s32 r = 0;
        if (result != 0) {
            Item_E9A0* item = self->items[i];
            VT_E9A0* vt = item->vt;
            r = vt->func1C((s32)item + (s32)vt->offset18) != 0;
        }
        result = r;
    }
    return result;
}
