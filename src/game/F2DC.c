#include "common.h"

#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/F2DC", Movie__Ctor);

typedef struct {
    char pad0[0x8];
    void *unk8;
} F2DC_Object;

extern u32 D_80019F40;

void func_80028A88(F2DC_Object *arg0, s32 arg1) {
    arg0->unk8 = &D_80019F40;
    if (arg1 & 1) {
        free(arg0);
    }
}

void UnkFunc01(UnkStruct00* a1, s32 a2)
{
    a1->unk18 = a2;
}
// INCLUDE_ASM("asm/game/nonmatchings/F2DC", UnkFunc01);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028AC4); // < - This retard is pointing to UnkFunc01 memory address too

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028B70);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028C1C);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028CC8);

typedef struct VT_28D6C {
    char pad[0x20];
    s16 offset20;
    void (*func24)(s32);
} VT_28D6C;

typedef struct VT_28E74 {
    char pad[0x10];
    s16 offset10;
    void (*func14)(s32, s32);
} VT_28E74;

typedef struct Item_28D6C {
    char pad[8];
    void *vt;
} Item_28D6C;

typedef struct Container_28D6C {
    s32 count;
    Item_28D6C *items[1];
} Container_28D6C;

void func_80028D6C(Container_28D6C *arg0) {
    s32 i;
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            VT_28D6C *vt = (VT_28D6C *)item->vt;
            vt->func24((s32)item + (s32)vt->offset20);
            i++;
        } while (i < arg0->count);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028DE4);

typedef struct Container_28E74 {
    s32 count;
    Item_28D6C *items[10];
    s32 unk2C;
} Container_28E74;

void func_80028E74(Container_28E74 *arg0) {
    s32 i;
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            VT_28E74 *vt = (VT_28E74 *)item->vt;
            vt->func14((s32)item + (s32)vt->offset10, arg0->unk2C);
            i++;
        } while (i < arg0->count);
    }
}

typedef struct {
    s32 count;
    void *items[10];
} Movie;

extern char D_80019790[];
extern char D_800197B8[];

void Movie__Unk02(Movie *arg0, void *arg1) {
    s32 c;

    c = arg0->count;
    if (c >= 10) {
        printf(D_80019790, D_800197B8, 0x25);
        exit(1);
    }
    arg0->items[c] = arg1;
    arg0->count = c + 1;
}

void func_80028F44(void) {}

void func_80028F4C(void) {}

int UnkFunc02() { return 1; }; // Don't ask me why does this function exists :')'

void func_80028F5C(void) {}

void func_80028F64(F2DC_Object *arg0, s32 arg1) {
    arg0->unk8 = &D_80019F40;
    if (arg1 & 1) {
        free(arg0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80028F98);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_800290DC);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_800291FC);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029210);

extern void func_800291FC(s32 arg0, s32 arg1);

void func_800293B8(void) {
    func_800291FC(0xA8F5, 0x547A);
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_800293DC);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_8002990C);

extern s32 D_80047EEC;

s32 func_80029A38(s32 arg0, s32 arg1) {
    s32 t = arg1 * arg0;
    return t / D_80047EEC;
}

extern int (*D_80048028)();
extern char D_80019FBC[]; // "out of memory\n"
extern s32 MemorySys__malloc(s32);

void func_80029A80(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019FBC);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_80029ADC(void) {}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029AE4);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029B0C);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029BE0);

extern s32 D_80047EC8;

s32 func_80029D88(s32 arg0) {
    s64 hilo = arg0 * (u64)D_80047EC8;
    s32 v0 = hilo >> 16;
    return v0 >> 16;
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029DB8);

extern void func_80029DB8(s32 *, s32, s32, s32);

void func_80029FA8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 r;
    s32 mode;
    func_80029DB8(arg0, 0, 0xF7, arg1);
    r = func_80029D88(arg2);
    if (r != 0) {
        mode = 0;
        if (r != 1) {
            mode = r;
        }
        VSync(mode);
    }
    func_80029DB8(arg0, 0xF7, 0, arg3);
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", VideoSys__LoadLogos);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_8002A7E4);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_8002A8E8);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_8002A91C);

s32* func_8002A950(s32 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    return arg0;
}

void func_8002A960(s32 *arg0, s32 flag) {
    s32 *p;
    PakFile pf;

    p = (s32*)arg0[0];
    if (p != NULL) {
        *p = *p - 1;
        if (*p == 0) {
            pf = *(PakFile *)&arg0[1];
            FileSys__DeleteFile(pf);
            free((void*)arg0[0]);
        }
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

s32 func_8002A9F8(UnkStruct08* arg0) {
    return ((u32) arg0->unk4 >> 3) & 1;
}

s32 func_8002AA0C(s32 arg0) {
    return arg0 + 8;
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_8002AA14);
