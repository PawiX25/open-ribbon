#include "common.h"

#include "globals.h"

typedef struct VT_28AC4 {
    char pad0[8];
    s16 offset8;
    char padA[2];
    void (*funcC)(s32, s32);
} VT_28AC4;

typedef struct VT_28CC8 {
    char pad0[0x20];
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
} VT_28CC8;

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

typedef struct VT_28DE4 {
    char pad[0x18];
    s16 offset18;
    char pad1A[2];
    void *(*func1C)(s32);
} VT_28DE4;

typedef struct Item_28D6C {
    char pad[8];
    void *vt;
} Item_28D6C;

typedef struct Container_28D6C {
    s32 count;
    Item_28D6C *items[1];
} Container_28D6C;

typedef struct Container_28CC8 {
    s32 count;
    Item_28D6C *items[10];
    char pad28[4];
    VT_28CC8 *vtmain;
} Container_28CC8;

typedef struct Bounds_290DC {
    s32 maxX;
    s32 maxY;
} Bounds_290DC;

typedef struct Pos_290DC {
    s32 x;
    s32 y;
    Bounds_290DC *bounds;
} Pos_290DC;

extern void func_80025DC0(s32 *, s32);
extern void func_80029FA8(s32 *, s32, s32, s32);
extern s32 D_800480AC;
extern s32 D_800480B0;

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

extern u32 D_80019F08;

void func_80028AC4(Container_28CC8 *arg0, s32 flag) {
    s32 i;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            if (item != NULL) {
                VT_28AC4 *vt = (VT_28AC4*)item->vt;
                vt->funcC((s32)item + (s32)vt->offset8, 3);
            }
            i++;
        } while (i < arg0->count);
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

void func_80028B70(Container_28CC8 *arg0, s32 flag) {
    s32 i;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            if (item != NULL) {
                VT_28AC4 *vt = (VT_28AC4*)item->vt;
                vt->funcC((s32)item + (s32)vt->offset8, 3);
            }
            i++;
        } while (i < arg0->count);
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

void func_80028C1C(Container_28CC8 *arg0, s32 flag) {
    s32 i;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            if (item != NULL) {
                VT_28AC4 *vt = (VT_28AC4*)item->vt;
                vt->funcC((s32)item + (s32)vt->offset8, 3);
            }
            i++;
        } while (i < arg0->count);
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

typedef struct VT_28AC4 {
    char pad0[8];
    s16 offset8;
    char padA[2];
    void (*funcC)(s32, s32);
} VT_28AC4;

typedef struct VT_28CC8 {
    char pad0[0x20];
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
} VT_28CC8;

typedef struct Container_28CC8 {
    s32 count;
    Item_28D6C *items[10];
    char pad28[4];
    VT_28CC8 *vtmain;
} Container_28CC8;

void func_80028CC8(Container_28CC8 *arg0, s32 arg1) {
    s32 i;
    VT_28CC8 *vt = arg0->vtmain;
    vt->func24((s32)arg0 + (s32)vt->offset20);
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28D6C *item = arg0->items[i];
            VT_28CC8 *vt2 = (VT_28CC8*)item->vt;
            vt2->func2C((s32)item + (s32)vt2->offset28, arg1);
            i++;
        } while (i < arg0->count);
    }
}

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

typedef struct VT_28DE4 {
    char pad[0x18];
    s16 offset18;
    char pad1A[2];
    void *(*func1C)(s32);
} VT_28DE4;

s32 func_80028DE4(Container_28D6C *arg0) {
    s32 ok = 1;
    s32 i;
    s32 r;
    if (arg0->count > 0) {
        i = 0;
        do {
            r = 0;
            if (ok != 0) {
                Item_28D6C *item = arg0->items[i];
                VT_28DE4 *vt = (VT_28DE4*)item->vt;
                void *ret = vt->func1C((s32)item + (s32)vt->offset18);
                r = (ret != 0) ? 1 : 0;
            }
            ok = r;
            i++;
        } while (i < arg0->count);
    }
    return ok;
}

typedef struct Container_28E74 {
    s32 count;
    Item_28D6C *items[10];
    char pad28[4];
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

void func_80028F98(s32 idx, Pos_290DC *p, s32 dx, s32 dy) {
    while (1) {
        func_800290DC(p, dx, dy, 1, 1);
        {
            Bounds_290DC *b = p->bounds;
            s32 maxX = b->maxX;
            s32 i;
            s32 *table = (s32*)((char*)b + 8);
            s32 *new_entry = (s32*)((char*)table + (p->y * maxX + p->x) * 4);
            s32 expected = ((s32*)((char*)&p->y + idx * 4))[0];     // hmm
            (void)expected;
            // Hmm complex - skip detail; just give it a try
            if (*new_entry == ((s32*)((char*)b + 8))[idx + p->x]) {
                continue;
            }
            if (p->x == maxX - 1 && dx == -1) {
                func_800290DC(p, 1, dy, 1, 1);
                return;
            }
            if (dx != 0 && dy == 1) {
                func_800290DC(p, -1, dy, 1, 1);
                return;
            }
            if (p->y == b->maxY - 1 && dy == -1) {
                func_800290DC(p, dx, 1, 1, 1);
                return;
            }
            if (dy != 0 && dx == 1) {
                func_800290DC(p, dx, -1, 1, 1);
                return;
            }
            return;
        }
    }
}

typedef struct Bounds_290DC {
    s32 maxX;
    s32 maxY;
} Bounds_290DC;

typedef struct Pos_290DC {
    s32 x;
    s32 y;
    Bounds_290DC *bounds;
} Pos_290DC;

void func_800290DC(Pos_290DC *p, s32 dx, s32 dy, s32 wrapY, s32 wrapX) {
    s32 nx = p->x + dx;
    s32 ny = p->y + dy;
    p->x = nx;
    p->y = ny;
    if (wrapX) {
        if (nx < 0) p->x = p->bounds->maxX - 1;
        if (p->x >= p->bounds->maxX) p->x = 0;
    } else {
        if (nx < 0) p->x = 0;
        if (p->x >= p->bounds->maxX) p->x = p->bounds->maxX - 1;
    }
    if (wrapY) {
        if (p->y < 0) p->y = p->bounds->maxY - 1;
        if (p->y >= p->bounds->maxY) p->y = 0;
    } else {
        if (p->y < 0) p->y = 0;
        if (p->y >= p->bounds->maxY) p->y = p->bounds->maxY - 1;
    }
}

extern s32 D_80048098;
extern s32 D_8004809C;
extern s32 D_800480A8;

void func_800291FC(s32 a0, s32 a1) {
    D_80048098 = a0;
    D_8004809C = a1;
    D_800480A8 = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029210);

extern void func_800291FC(s32 arg0, s32 arg1);

void func_800293B8(void) {
    func_800291FC(0xA8F5, 0x547A);
}

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_800293DC);

extern char D_800480A0[];
extern void func_80029ADC(s32 *);
extern void func_80029A80(s32);
extern u16 func_8002B0D4(void);
extern u16 func_8002B0F8(void);
extern s32* func_800207D0(s32 *);

s32 func_8002990C(void) {
    char *p = D_800480A0;
    s32 fd[3];
    s32 buf16[8];
    s32 len;
    char *new_buf;
    s32 byte_count;
    s32 *r;
    u16 v0, v1;
    fd[0] = 0;
    fd[1] = 0;
    fd[2] = 0;
    len = func_80035C6C(p) + 1;
    if ((u32)len > (u32)-2) {
        func_80029ADC(fd);
    } else if (len == 0) {
        new_buf = NULL;
        fd[0] = (s32)new_buf;
        fd[1] = (s32)new_buf;
        fd[2] = (s32)((char*)new_buf + len);
    } else {
        new_buf = (char*)MemorySys__malloc(len);
        if (new_buf == NULL) {
            new_buf = (char*)func_80029A80(len);
        }
        fd[0] = (s32)new_buf;
        fd[1] = (s32)new_buf;
        fd[2] = (s32)(new_buf + len);
    }
    byte_count = (s32)((char*)D_800480A0 - p);     // not used
    func_80030BF4((void*)fd[0], p, byte_count);
    fd[1] = fd[0] + byte_count;
    *(s8*)fd[1] = 0;
    r = func_800207D0(fd);
    *((s8*)buf16) = ((s8*)r)[0x12];
    *((s8*)buf16 + 1) = ((s8*)r)[0x13];
    {
        u16 mask_in = *(u16*)buf16;
        u16 m1;
        u16 m2;
        m1 = mask_in & func_8002B0D4();
        if (m1) return 1;
        m2 = (*(u16*)buf16) & func_8002B0F8();
        if (m2) return 2;
        return 0;
    }
}

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

extern s32 D_80040834;
extern s32 D_80042968;

void func_80029AE4(void) {
    s32 *p = &D_80040834;
    s32 v = D_80042968;
    D_80048098 = 0;
    D_8004809C = 0;
    p[1] = 0;
    p[2] = 0;
    p[0] = v;
}

extern void func_80030644(void *, s32, s32);
extern void func_8002D268(s32 *, s32 *);

void func_80029B0C(s32 *arg0, s32 arg1) {
    s32 i;
    s32 cond_a;
    s32 buf1[4];
    s32 buf2[4];
    s32 *p = (s32*)((char*)arg0 + 8);
    cond_a = (((u32)arg0[1] >> 3) & 1) == 0 ? 1 : 0;
    for (i = cond_a; i < 2; i++) {
        if (arg1 != 0 || cond_a != 1) {
            func_80030644(buf1, 0, 8);
            *(u16*)((s8*)buf2 + 8) = ((u16*)p)[2];
            *(u16*)((s8*)buf2 + 10) = ((u16*)p)[3];
            *(u16*)((s8*)buf2 + 12) = ((u16*)p)[4];
            *(u16*)((s8*)buf2 + 14) = ((u16*)p)[5];
            {
                u32 t0 = *(u32*)((s8*)buf2 + 8);
                u32 t1 = *(u32*)((s8*)buf2 + 12);
                *(u32*)buf1 = t0;
                *(u32*)((s8*)buf1 + 4) = t1;
            }
            func_8002D268(buf1, (s32*)((char*)p + 0xC));
        }
        p = (s32*)((char*)p + p[0]);
    }
}

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

void func_8002A7E4(void) {
    s32 *p;
    s32 *items;
    s32 cnt;
    s32 *end;
    s32 *cur;
    p = (s32*)D_800480AC;
    if (p != NULL) {
        items = (s32*)p[1];
        if (items != NULL) {
            cnt = ((s32*)items)[-2];
            end = (s32*)((char*)items + cnt * 0x18);
            if (items != end) {
                cur = (s32*)((char*)end - 0x18);
                do {
                    func_8002A960(cur, 2);
                    items = (s32*)p[1];
                    cur = (s32*)((char*)cur - 0x18);
                } while (items != cur);
            }
            delete((void*)((char*)items - 8));
        }
        free(p);
    }
    p = (s32*)D_800480B0;
    if (p != NULL) {
        items = (s32*)p[1];
        if (items != NULL) {
            cnt = ((s32*)items)[-2];
            end = (s32*)((char*)items + cnt * 0x18);
            if (items != end) {
                cur = (s32*)((char*)end - 0x18);
                do {
                    func_8002A960(cur, 2);
                    items = (s32*)p[1];
                    cur = (s32*)((char*)cur - 0x18);
                } while (items != cur);
            }
            delete((void*)((char*)items - 8));
        }
        free(p);
    }
}

extern s32 D_800480AC;

void func_8002A8E8(s32 a0, s32 a1, s32 a2) {
    func_80029FA8((s32*)D_800480AC, a0, a1, a2);
}

extern s32 D_800480B0;

void func_8002A91C(s32 a0, s32 a1, s32 a2) {
    func_80029FA8((s32*)D_800480B0, a0, a1, a2);
}

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

extern s32 D_800480B4;
extern void VideoSys__Flip(s32);
extern void func_80025954(s32 *);

void func_8002AA14(void) {
    s32 *p;
    VideoSys__Flip(1);
    p = (s32*)D_800480B4;
    func_80025DC0((s32*)((char*)p + 0x3C), 0);
    func_80025954((s32*)((char*)p + 0x4));
}
