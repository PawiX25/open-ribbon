#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

typedef struct HeapNode {
    struct HeapNode* unk0;
    s32 unk4;
} HeapNode;

extern HeapNode* D_80047FD0;
s32 MemorySys__CountHeapFree(void);
extern s32 D_80047FCC;

extern void func_8003428C(void);
extern char D_80019244[];
extern char D_8001926C[];

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Init);

void func_80021758(void) {} // MemorySys__Stub [Empty]

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Info);

extern char D_80019388[];
extern char D_80019398[];
extern char D_80019388[];
extern char D_80019398[];

void MemorySys__DumpUsage(void) {
    HeapNode* node;
    s32 total;
    s32 base;

    base = D_80047FCC - 8;
    printf(D_80019388, base - MemorySys__CountHeapFree());

    node = D_80047FD0;
    total = 0;
    while (node->unk4 != 0) {
        total += node->unk4 << 3;
        node = node->unk0;
    }

    printf(D_80019398, total);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpHead);

void MemorySys__Init01(void) {
    MemorySys__Init();
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__malloc);

extern void func_8003439C(void);
extern s32 D_80047FC8;

void MemorySys__free(void *address) {
    if (address != 0) {
        func_8003439C();
        D_80047FC8 += 1;
    }
}

s32 MemorySys__CountHeapFree(void) {
    HeapNode* node = D_80047FD0;
    s32 total = 0;
    while (node->unk4 != 0) {
        total += node->unk4 << 3;
        node = node->unk0;
    }
    return total;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021AC0);

extern s32 D_80047FFC;
extern s32* D_80047FF8;
extern s32 D_80048000;
extern s32 D_80048004;
extern char D_80019400[];
extern s32 func_800324D8(s32*, s32);
extern void func_80034DF0(void);

void cbready(s32 arg0) {
    s32 v = arg0 & 0xFF;

    if (v == 1) {
        s32 count = D_80047FFC;
        if (count > 0x200) {
            count = 0x200;
        }
        func_800324D8(D_80047FF8, count);
        D_80047FFC = D_80047FFC - count;
        D_80047FF8 = D_80047FF8 + count;
        if (D_80047FFC == 0) {
            func_80034DF0();
            D_80048000 = v;
        }
    } else {
        printf(D_80019400);
        D_80048004 = 0;
    }
}

extern void func_80034D6C(void* arg0, s32 arg1);
extern char D_80019414[];
extern s32 D_80048004;

void cbsync(s32 arg0) {
    if ((arg0 & 0xFF) == 2) {
        func_80034D6C(cbready, -1);
    } else {
        printf(D_80019414);
        D_80048004 = 0;
    }
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021CD0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Read);

typedef struct {
    char* unk0;
    char* unk4;
    char* unk8;
} StrBuf;

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021E6C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021EF4);

extern s32 D_800194A4[];

s32 PackedFiles__Unk00(s32 arg0, s32 *arg1, s32 arg2) {
    s32 c;
    s32 v;

    if (*arg1 >= 5) {
        if (arg2 == 0) {
            return 0;
        }
        *arg1 = 0;
    }
    c = *arg1;
    v = D_800194A4[c];
    *arg1 = c + 1;
    return arg0 | v;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Init);

extern PakFile D_8003FE68;

void PackedFiles__Quit(void) {
    PakFile pf = D_8003FE68;
    FileSys__DeleteFile(pf);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Load);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__LoadFile);

void FileSys__DeleteFile(PakFile pf)
{
    if (pf.size != 0 && pf.next != NULL)
        delete(pf.next);
}

extern char D_80019448[];
extern char D_80019470[];
extern s32 D_80047FF4;

void FileSys__Unknown(s32 arg0) {
    if (arg0 != 0) {
        if (D_80047FF4 != 0) {
            printf(D_80019448, D_80019470, 0x188);
            exit(1);
        }
    }
    D_80047FF4 = arg0;
}

typedef struct {
    char *start;
    char *end;
} FileSysStr0;

extern void *func_8003424C(void *, const void *, int); /* memcpy */
extern void *func_80030BF4(void *, const void *, int); /* memmove */

FileSysStr0* FileSys__Unk00(FileSysStr0* self, char* new_start, char* new_end) {
    char *curEnd;
    char *newEnd;

    if ((unsigned int)(self->end - self->start) >= (unsigned int)(new_end - new_start)) {
        func_8003424C(self->start, new_start, new_end - new_start);

        curEnd = self->end;
        newEnd = self->start + (new_end - new_start);

        if (newEnd != curEnd) {
            func_80030BF4(newEnd, curEnd, 1);
            self->end -= (curEnd - newEnd);
        }
    } else {
        func_8003424C(self->start, new_start, self->end - self->start);
        func_80022660(self, new_start + (self->end - self->start), new_end, 0);
    }

    return self;
}

void func_80022658(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022660);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022824);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022968);

void func_80022A58(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022A60);

extern int (*D_80048028)();
extern char D_80019494[]; // "out of memory\n"

void func_80022C80(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019494);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

extern StrBuf D_8003FE5C;
extern StrBuf D_8003FE50;
extern StrBuf D_8003FE44;

void func_80022CDC(void) {
    s32 d;
    d = (s32)D_8003FE5C.unk8 - (s32)D_8003FE5C.unk0;
    if (D_8003FE5C.unk0 != 0) {
        if (d != 0) {
            MemorySys__free(D_8003FE5C.unk0);
        }
    }
    d = (s32)D_8003FE50.unk8 - (s32)D_8003FE50.unk0;
    if (D_8003FE50.unk0 != 0) {
        if (d != 0) {
            MemorySys__free(D_8003FE50.unk0);
        }
    }
    d = (s32)D_8003FE44.unk8 - (s32)D_8003FE44.unk0;
    if (D_8003FE44.unk0 != 0) {
        if (d != 0) {
            MemorySys__free(D_8003FE44.unk0);
        }
    }
}

u8* func_80022D78(u8* dest, s32 count, u8* value) {
    // memset-like function
    u8* ptr = dest;

    while (count != 0) {
        *ptr++ = *value;
        count--;
    }

    return ptr;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022D9C);

void VideoSys__SetProjection(s32 h)
{
	s32 proj;

	s32 factor = 360;
	s32 scale = 2;

	s32 a = rcos((h / factor) / scale);
	s32 b = rsin((h / factor) / scale);

	proj = (((a * VWD0) / b) >> 1) * HWD0;
	proj = (proj * 3) / (VWD0 * 4);

	GsSetProjection(proj);
	InitClip(&evbfad, HWD0 + 8, VWD0 + 8, proj, proj / 2, 0xFFFF);
}

s32 func_80023060(SVECTOR* vec1, SVECTOR* vec2)
{
    if (Clip3F(vec1, vec2, vec2, evmx) >= 2)
    {
        *vec1 = evmx[0]->v;
        *vec2 = evmx[1]->v;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002310C);

void func_80023174(s32* arg0) {
    *arg0 = 0;
}

void func_8002317C(UnkStruct09* arg0, int arg1) {
    arg0->unk48 = func_800231F4(arg1);
}

void func_800231A8(s32 *arg0, s32 a1, s32 a2, s32 a3) {
    s32 *p = (s32*)arg0[20];
    s32 *q;
    p[5] = a1;
    q = (s32*)((char*)p + 0x14);
    q[1] = a2;
    q[2] = a3;
}

typedef struct {
    char pad0[0x50];
    s16 *unk50;
} F800231C4Struct;

s16 *func_800231C4(F800231C4Struct *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 *r = arg0->unk50;
    r[0] = arg1;
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = arg2;
    r[5] = 0;
    r[6] = 0;
    r[7] = 0;
    r[8] = arg3;
    return r;
}

extern int D_8003FE8C;

s32 func_800231F4(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != &D_8003FE8C) {
        var_v1 = arg0;
    }
    return var_v1;
}

s32 func_80023210(s32 value) {
    // rounds up a value to the nearest multiple of 4
    return (value + 3) & ~3;
}

s32 func_80023220(s8* first_string, s8* second_string) {
    s8 c1 = *first_string;
    s8 c2;
    s8 lc1 = ((u32)(c1 - 65) < 26) ? (c1 + 0x20) : c1;
    s8 lc2;

    c2 = *second_string;
    lc2 = ((u32)(c2 - 65) < 26) ? (c2 + 0x20) : c2;

    if (lc1 < lc2) {
        return -1;
    }
    if (lc2 < lc1) {
        return 1;
    }
    if (lc1 != 0) {
        return func_80023220(first_string + 1, second_string + 1);
    }
    return 0;
}

s32 func_800232A0(s32 arg0) {
    return arg0 + func_80023210(func_80035C6C() + 1);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800232D0);

s32 func_80023388(void) {
    s32 temp_return_value;

    temp_return_value = func_800232D0();

    if (temp_return_value != 0) {
        return func_800232A0(temp_return_value);
    }

    return 0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", main);

s32 func_80023A7C(s32 arg0, s32 arg1, s32 arg2) {
    return arg0 + (arg2 - arg1);
}

s32 func_80023A88(s32 arg0, s32 arg1, s32 arg2) {
    return arg0 + (arg2 - arg1);
}

extern char D_800195F4[]; // "out of memory\n"

void func_80023A94(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_800195F4);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_80023AF0(void) {}

s32* func_80023AF8(s32* arg0) {
    arg0[30] = 0; /* 0x78 */
    arg0[38] = 0; /* 0x98 */
    return arg0;
}

s32* func_80023B08(s32* arg0) {
    *arg0 = 0;
    return arg0;
}

s32* func_80023B14(s32* arg0) {
    *arg0 = 0;
    return arg0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023B20);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023C2C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023D38);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800245CC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800246EC);

extern int (*D_80048028)();
extern char D_80019704[]; // "out of memory\n"

void func_80024820(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019704); // "out of memory\n"
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_8002487C(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024884);

// part of TmdLineObj.cpp
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024A48);

typedef struct {
    s32 unk0;
    char pad4[8];
    void *unkC;
    char pad10[0x1C];
    void *unk2C;
} UnkStruct17;

void func_80024CC4(UnkStruct17* arg0, s32 arg1) {
    if (arg0->unkC != NULL) {
        delete(arg0->unkC);
    }
    if (arg0->unk0 != 0 && arg0->unk2C != NULL) {
        delete(arg0->unk2C);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

typedef struct {
    char pad0[0x20];
    s32 idx0;
    s32 idx1;
    s32 idx2;
    SVECTOR *vbuf;
} TriObj;

s32 func_80024D40(TriObj* arg0) {
    long sxy0, sxy1, sxy2;
    long flag;

    RotTransPers3(
        arg0->vbuf + arg0->idx0,
        arg0->vbuf + arg0->idx1,
        arg0->vbuf + arg0->idx2,
        &sxy0, &sxy1, &sxy2, &flag, &flag);

    return (u32)NormalClip(sxy0, sxy1, sxy2) >> 31;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024DBC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024F8C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025330);

extern s32 D_80048044;

void func_80025584(void) {
    D_80048044 = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025590);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025604);

void UnkFunc05(UnkStruct00 *arg0, s32 arg1)
{
    arg0->unk18 = arg1;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800256CC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800258B0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025954);

extern int D_8003FE8C;

s32 func_80025B18(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != &D_8003FE8C) {
        var_v1 = arg0;
    }
    return var_v1;
}

void TmdLineObj__Unk12(s32* arg0) { *arg0 = 0; }

void func_80025B3C(UnkStruct09* arg0, int arg1) {
    arg0->unk48 = func_80025B18(arg1);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025B68);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025D1C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025DC0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025EBC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025F44);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800262B4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002663C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026834);

typedef struct {
    char* name;
    char pad4[8];
    s32 key;
    s32 val;
} NameEntry;

typedef struct {
    char pad0[0x10];
    s32 unk10;
} EntryObj;

typedef struct {
    s32 unk0;
    s32 unk4;
    char pad8[4];
    EntryObj* unkC[20];
    NameEntry* unk5C;
    char pad60[0x10];
    s32 unk70;
} NameTableObj;

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026940);

void func_800269A4(NameTableObj* self, s32 key) {
    s32 idx;

    if (self->unk5C[0].name[0] == 0) {
        return;
    }
    idx = 0;
    do {
        if (self->unk5C[idx].key == key) {
            s32 val = self->unk5C[idx].val;
            self->unk4 = idx;
            self->unk0 = val;
            return;
        }
        idx++;
    } while (self->unk5C[idx].name[0] != 0);
}

void func_80026A10(NameTableObj* self) {
    s32 i;

    self->unk4 = 0;
    self->unk0 = 0;
    if (self->unk5C[0].name[0] == 0) {
        return;
    }
    i = 0;
    do {
        EntryObj* o = self->unkC[i];
        o->unk10 = 0;
        UnkFunc01(o, 0x8000U);
        i++;
    } while (self->unk5C[i].name[0] != 0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026AA0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026CB8);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026D78);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026E08);

typedef struct {
    char* name;
    char pad4[4];
    s32 key;
    s32 val;
} NameEntry2;

typedef struct {
    s32 unk0;
    s32 unk4;
    char pad8[4];
    EntryObj* unkC[10];
    NameEntry2* unk34;
} NameTableObj2;

void func_80026E64(NameTableObj2* self, s32 key) {
    s32 idx;

    if (self->unk34[0].name[0] == 0) {
        return;
    }
    idx = 0;
    do {
        if (self->unk34[idx].key == key) {
            s32 val = self->unk34[idx].val;
            self->unk4 = idx;
            self->unk0 = val;
            return;
        }
        idx++;
    } while (self->unk34[idx].name[0] != 0);
}

void func_80026ED0(NameTableObj2* self) {
    s32 i;

    self->unk4 = 0;
    self->unk0 = 0;
    if (self->unk34[0].name[0] == 0) {
        return;
    }
    i = 0;
    do {
        EntryObj* o = self->unkC[i];
        i++;
        o->unk10 = 0;
        UnkFunc01(o, 0x8000U);
    } while (self->unk34[i].name[0] != 0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026F5C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027000);

typedef struct {
    char pad0[0xC];
    s32 unkC;
} F800270XXEntry;

typedef struct {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    F800270XXEntry *unkC;
} F800270XXStruct;

extern s32 AudioSys__UnkFunc09();

s32 func_80027090(F800270XXStruct *arg0) {
    if (arg0->unkC[arg0->unk4].unkC == -97) {
        return 0;
    }
    return AudioSys__UnkFunc09(0) ^ 1;
}

extern s32 func_8001F5E4(s16);

void func_800270DC(s32 *arg0) {
    arg0[1] = 0;
    arg0[0] = 0;
    func_8001F5E4(0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027104);