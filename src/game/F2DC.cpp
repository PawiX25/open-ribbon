extern "C" void deletefn(void*) __asm__("delete");
#define delete deletefn

extern "C" {
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

extern u32 D_80019F08;

typedef struct Item_28CC8 Item_28CC8;
typedef struct VT_28CC8 VT_28CC8;
typedef struct Container_28CC8 Container_28CC8;

struct Item_28CC8 {
    char pad[8];
    void *vt;
};

struct VT_28CC8 {
    char pad0[0x20];
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
};

struct Container_28CC8 {
    s32 count;
    Item_28CC8 *items[10];
    char pad2C[4];
    VT_28CC8 *vtmain;
};

typedef struct VT_28AC4 {
    char pad0[8];
    s16 offset8;
    char padA[2];
    void (*funcC)(s32, s32);
} VT_28AC4;

void func_80028AC4(Container_28CC8 *arg0, s32 flag) {
    s32 i = 0;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        do {
            Item_28CC8 *item = arg0->items[i];
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
    s32 i = 0;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        do {
            Item_28CC8 *item = arg0->items[i];
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
    s32 i = 0;
    arg0->vtmain = (VT_28CC8*)&D_80019F08;
    if (arg0->count > 0) {
        do {
            Item_28CC8 *item = arg0->items[i];
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

void func_80028CC8(Container_28CC8 *arg0, s32 arg1) {
    s32 i;
    VT_28CC8 *vt = arg0->vtmain;
    vt->func24((s32)arg0 + (s32)vt->offset20);
    if (arg0->count > 0) {
        i = 0;
        do {
            Item_28CC8 *item = arg0->items[i];
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

typedef struct {
    char pad0[0x18];
    s16 unk18;
    char pad1A[2];
    s32 (*unk1C)(void*);
} F8DE4VTable;

typedef struct {
    char pad0[8];
    F8DE4VTable* unk8;
} F8DE4Obj;

typedef struct {
    s32 unk0;
    F8DE4Obj* unk4[1];
} F8DE4Self;

s32 func_80028DE4(F8DE4Self* self) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < self->unk0; i++) {
        s32 r = 0;
        if (result != 0) {
            F8DE4Obj* obj = self->unk4[i];
            F8DE4VTable* vt = obj->unk8;
            r = vt->unk1C((char*)obj + vt->unk18) != 0;
        }
        result = r;
    }
    return result;
}

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

typedef struct {
    s32 w;
    s32 h;
    s32* cells;
} GridBounds;

typedef struct {
    s32 x;
    s32 y;
    GridBounds* b;
} GridCursor;

void func_800290DC(GridCursor* c, s32 dx, s32 dy, s32 wrapY, s32 wrapX);

void func_80028F98(s32 startIdx, GridCursor* cur, s32 dx, s32 dy, s32 wrapX, s32 wrapY) {
    s32 w;
    do {
        func_800290DC(cur, dx, dy, 1, 1);
    } while (cur->b->cells[cur->y * cur->b->w + cur->x] == cur->b->cells[startIdx]);

    do {
        w = cur->b->w;
        if (cur->x == w - 1 && dx == -1) {
            func_800290DC(cur, 1, dy, 1, 1);
        } else if (cur->x == 0 && dx == 1) {
            func_800290DC(cur, -1, dy, 1, dx);
        } else if (cur->y == cur->b->h - 1 && dy == -1) {
            func_800290DC(cur, dx, 1, 1, 1);
        } else if (cur->y == 0 && dy == 1) {
            func_800290DC(cur, dx, -1, 1, dy);
        }
    } while (0);
}

void func_800290DC(GridCursor* c, s32 dx, s32 dy, s32 wrapY, s32 wrapX) {
    s32 nx = c->x + dx;
    s32 ny = c->y + dy;
    c->x = nx;
    c->y = ny;
    if (wrapX) {
        if (nx < 0) {
            c->x = c->b->w - 1;
        }
        if (c->x >= c->b->w) {
            c->x = 0;
        }
    } else {
        if (nx < 0) {
            c->x = 0;
        }
        if (c->x >= c->b->w) {
            c->x = c->b->w - 1;
        }
    }
    if (wrapY) {
        if (c->y < 0) {
            c->y = c->b->h - 1;
        }
        if (c->y >= c->b->h) {
            c->y = 0;
        }
    } else {
        if (c->y < 0) {
            c->y = 0;
        }
        if (c->y >= c->b->h) {
            c->y = c->b->h - 1;
        }
    }
}

extern s32 D_80048098;
extern s32 D_8004809C;
extern s32 D_800480A0;
extern s32 D_800480A8;

void func_800291FC(s32 arg0, s32 arg1) {
    D_80048098 = arg0;
    D_8004809C = arg1;
    D_800480A8 = 0;
}

typedef struct {
    s32 base;
    s32 active;
    s32 limit;
} F29210_State;

extern s32 D_80040834[];
extern s32 D_80042968;
extern s32 D_80047EC4;

#define F29210_ST (*(F29210_State*)D_80040834)

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029210);

typedef struct { char* unk0; char* unk4; char* unk8; } StrSlot3;

extern s32 func_80035C6C(void*);
extern void *func_80030BF4(void *, const void *, int);
extern s32 func_800207D0(StrSlot3*);
extern s32 func_8002B0D4(void);
extern s32 func_8002B0F8(void);
extern s32 func_80029A80(s32);
extern void func_80029ADC(void*);

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

s32 func_80029A80(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf((char*)&D_80019FBC);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_80029ADC(void* arg) {}

extern s32 D_80040834[];
extern s32 D_80042968;

void func_80029AE4(void) {
    D_80048098 = 0;
    D_8004809C = 0;
    D_80040834[1] = 0;
    D_80040834[2] = 0;
    D_80040834[0] = D_80042968;
}

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
} F29B0C_Quad;

typedef struct {
    s32 stride;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    char unkC[0];
} F29B0C_Item;

typedef struct {
    s32 unk0;
    u32 unk4;
} F29B0C_Self;

extern void* func_80030644(void* dst, s32 val, s32 count);
extern void func_8002D268(F29B0C_Quad* dst, void* src);

void func_80029B0C(F29B0C_Self* self, s32 arg1) {
    F29B0C_Item* item = (F29B0C_Item*)((char*)self + 8);
    u32 b = (self->unk4 >> 3) & 1;
    s32 i = b < 1;
    F29B0C_Quad q;
    F29B0C_Quad tmp;

    while (i < 2) {
        if (arg1 != 0 || i == 1) {
            func_80030644(&tmp, 0, 8);
            tmp.a = item->unk4;
            tmp.b = item->unk6;
            tmp.c = item->unk8;
            tmp.d = item->unkA;
            q = tmp;
            func_8002D268(&q, item->unkC);
        }
        item = (F29B0C_Item*)((char*)item + item->stride);
        i++;
    }
}

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} F29BE0_Tile;

typedef struct {
    u32 tag;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 uv;
    s8 c1;
    s8 c2;
    s16 e0;
    s16 e1;
} F29BE0_Prim;

extern u16 D_80047EF4;
extern u16 D_80047EF8;
extern s32 func_8002A9F8(UnkStruct08* arg0);
extern s32 func_8002AA0C(s32 arg0);
extern void func_800304A0(F29BE0_Prim* prim, s32* ot, s32 flag);
extern s32* VideoSys__GetOT(void);

INCLUDE_ASM("asm/game/nonmatchings/F2DC", func_80029BE0);

extern s32 D_80047EC8;

s32 func_80029D88(s32 arg0) {
    s64 hilo = (s64)arg0 * (s64)D_80047EC8;
    s32 v0 = hilo >> 16;
    return v0 >> 16;
}

extern s32 D_80047EE4;
extern s32 D_80047EE8;
extern void func_8002CB48(void*, s32*, s32);

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

extern s32* D_800480AC;
extern s32* D_800480B0;
extern void func_8002A960(s32*, s32);

void func_8002A7E4(void) {
    s32* v;
    char* data;
    char* p;

    v = D_800480AC;
    if (v != 0) {
        data = (char*)v[1];
        if (data != 0) {
            p = data + *(s32*)(data - 8) * 0x18;
            if (data != p) {
                p -= 0x18;
                for (;;) {
                    func_8002A960((s32*)p, 2);
                    if ((char*)v[1] == p) {
                        break;
                    }
                    p -= 0x18;
                }
            }
            delete((char*)v[1] - 8);
        }
        free(v);
    }
    v = D_800480B0;
    if (v != 0) {
        data = (char*)v[1];
        if (data != 0) {
            p = data + *(s32*)(data - 8) * 0x18;
            if (data != p) {
                p -= 0x18;
                for (;;) {
                    func_8002A960((s32*)p, 2);
                    if ((char*)v[1] == p) {
                        break;
                    }
                    p -= 0x18;
                }
            }
            delete((char*)v[1] - 8);
        }
        free(v);
    }
}

void func_8002A8E8(s32 arg0, s32 arg1, s32 arg2) {
    func_80029FA8(D_800480AC, arg0, arg1, arg2);
}

void func_8002A91C(s32 arg0, s32 arg1, s32 arg2) {
    func_80029FA8(D_800480B0, arg0, arg1, arg2);
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

extern void VideoSys__Flip(s32 arg0);
extern void func_80025DC0(u8* arg0, s32 arg1);
extern void func_80025954(u8* arg0);
extern u8* D_800480B4;

void func_8002AA14(void) {
    u8* p;
    VideoSys__Flip(1);
    p = D_800480B4;
    func_80025DC0(p + 0x3C, 0);
    func_80025954(p + 0x4);
}

}
