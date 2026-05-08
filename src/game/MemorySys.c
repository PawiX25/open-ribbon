#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Init);

void func_80021758(void) {} // MemorySys__Stub [Empty]

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Info);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpUsage);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpHead);

void MemorySys__Init01(void) {
    MemorySys__Init();
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__malloc);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__free);
#else
void MemorySys__free(s32 address) {
    if (address != 0) {
        func_8003439C();
        freeAmount += 1;
    }
}
#endif

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__CountHeapFree);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021AC0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbready);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbsync);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021CD0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Read);

s32 func_80021E6C(s32 a0_in, s32 *arg1, s32 *arg2) {
    extern s32* func_80023388(s32, s32);
    s32 *r;
    s32 ret = 1;
    r = func_80023388(a0_in, arg1[0]);
    if (r != NULL) {
        arg2[2] = 0;
        arg2[0] = (s32)(r + 1);
        arg2[1] = r[0];
    } else {
        ret = 0;
    }
    if (arg1[0] != 0 && arg1[2] - arg1[0] == 0) {
        MemorySys__free(arg1[0]);
    }
    return ret;
}

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

extern PakFile FileSys__LoadFile(char *);

void PackedFiles__Load(char *filename) {
    PakFile pf = D_8003FE68;
    FileSys__DeleteFile(pf);
    pf = FileSys__LoadFile(filename);
    D_8003FE68 = pf;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__LoadFile);

void FileSys__DeleteFile(PakFile pf)
{
    if (pf.size != 0 && pf.next != NULL)
        delete(pf.next);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Unknown);

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

extern PakFile D_8003FE5C;
extern PakFile D_8003FE50;
extern PakFile D_8003FE44;

void func_80022CDC(void) {
    s32 buf, end;
    buf = (s32)D_8003FE5C.next;
    end = D_8003FE5C.size;
    if (buf != 0 && (end - buf) == 0) {
        MemorySys__free(buf);
    }
    buf = (s32)D_8003FE50.next;
    end = D_8003FE50.size;
    if (buf != 0 && (end - buf) == 0) {
        MemorySys__free(buf);
    }
    buf = (s32)D_8003FE44.next;
    end = D_8003FE44.size;
    if (buf != 0 && (end - buf) == 0) {
        MemorySys__free(buf);
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

extern void func_80022C80(s32);
extern void func_80022D78(s32, s32, s8 *);

void func_80022D9C(void) {
    s8 buf[16];
    s8 *p;
    buf[0] = 0x20;

    D_8003FE44.next = NULL;
    D_8003FE44.unk4 = 0;
    D_8003FE44.size = 0;
    p = (s8*)MemorySys__malloc(0x41);
    if (p == NULL) p = (s8*)func_80022C80(0x41);
    D_8003FE44.next = (PakFile*)p;
    D_8003FE44.unk4 = (s32)p;
    D_8003FE44.size = (s32)(p + 0x41);
    func_80022D78((s32)p, 0x40, buf);
    *(s8*)D_8003FE44.unk4 = 0;

    buf[0] = 0x20;
    D_8003FE50.next = NULL;
    D_8003FE50.unk4 = 0;
    D_8003FE50.size = 0;
    p = (s8*)MemorySys__malloc(0x41);
    if (p == NULL) p = (s8*)func_80022C80(0x41);
    D_8003FE50.next = (PakFile*)p;
    D_8003FE50.unk4 = (s32)p;
    D_8003FE50.size = (s32)(p + 0x41);
    func_80022D78((s32)p, 0x40, buf);
    *(s8*)D_8003FE50.unk4 = 0;

    buf[0] = 0x20;
    D_8003FE5C.next = NULL;
    D_8003FE5C.unk4 = 0;
    D_8003FE5C.size = 0;
    p = (s8*)MemorySys__malloc(0x41);
    if (p == NULL) p = (s8*)func_80022C80(0x41);
    D_8003FE5C.next = (PakFile*)p;
    D_8003FE5C.unk4 = (s32)p;
    D_8003FE5C.size = (s32)(p + 0x41);
    func_80022D78((s32)p, 0x40, buf);
    *(s8*)D_8003FE5C.unk4 = 0;

    D_8003FE68.next = NULL;
}

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

extern s32 D_8003FE8C[];
extern void func_800231C4(s32*, s32, s32, s32);
extern void func_8002317C(s32*, s32*);
extern void func_80023174(s32*);

void func_8002310C(void) {
    s32 *p = D_8003FE8C;
    p[20] = (s32)(p + 1);
    func_800231C4(p, 0x1000, 0x1000, 0x1000);
    func_800231A8(p, 0, 0, 0);
    func_8002317C(p, p);
    func_80023174(p);
}

void func_80023174(s32* arg0) {
    *arg0 = 0;
}

void func_8002317C(UnkStruct09* arg0, int arg1) {
    arg0->unk48 = func_800231F4(arg1);
}

void func_800231A8(s32 *arg0, s32 a1, s32 a2, s32 a3) {
    s32 *p = (s32*)arg0[20];
    p[5] = a1;
    p[6] = a2;
    p[7] = a3;
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
    s8 current_character = *first_string;
    s8 other_character = *second_string;

    if ((u32)(current_character - 65) < 26) {
        current_character += 0x20;
    }
    if ((u32)(other_character - 65) < 26) {
        other_character += 0x20;
    }

    if (current_character < other_character) {
        return -1;
    }
    if (other_character < current_character) {
        return 1;
    }

    if (current_character != 0) {
        return func_80023220(first_string + 1, second_string + 1);
    }

    return 0;
}

s32 func_800232A0(s32 arg0) {
    return arg0 + func_80023210(func_80035C6C() + 1);
}

s32 func_800232D0(s32 *table, s8 *needle) {
    s32 lo = 0;
    s32 hi = table[0];
    s32 mid;
    s32 cmp;
    s32 *entry;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        entry = (s32*)((char*)table + table[mid + 1]);
        cmp = func_80023220(needle, (s8*)entry);
        if (cmp < 0) {
            hi = mid;
        } else if (cmp == 0) {
            return (s32)entry;
        } else {
            lo = mid + 1;
        }
    }
    return 0;
}

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

extern s32 func_80024820(s32);
extern void func_8002487C(s32 *);

s32* func_80023B20(s32 *out, char *str) {
    s32 fd[3];
    s32 len;
    s32 sz;
    s32 *new_buf;
    s32 *base;
    s32 byte_count;
    out[0] = 0;
    out[1] = (s32)func_800207C4();
    out[2] = (s32)func_800207C4();
    fd[0] = 0;
    fd[1] = 0;
    fd[2] = 0;
    out[3] = func_80035C6C(str);
    len = out[3] + 1;
    if ((u32)len > (u32)-2) {
        func_8002487C(fd);
    } else if (len == 0) {
        new_buf = NULL;
        fd[0] = (s32)new_buf;
        fd[1] = (s32)new_buf;
        fd[2] = (s32)((char*)new_buf + len);
    } else {
        new_buf = (s32*)MemorySys__malloc(len);
        if (new_buf == NULL) {
            new_buf = (s32*)func_80024820(len);
        }
        fd[0] = (s32)new_buf;
        fd[1] = (s32)new_buf;
        fd[2] = (s32)((char*)new_buf + len);
    }
    byte_count = (s32)((char*)out[3] + (s32)str - (s32)str);   // simplified: out[3]
    func_80030BF4((void*)fd[0], str, out[3]);
    base = (s32*)fd[0];
    fd[1] = (s32)((char*)base + out[3]);
    *(s8*)((char*)base + out[3]) = 0;
    InputSys__Unk01((s32*)out + 1, (s32)fd);
    return out;
}

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

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025584);

extern void UnkFunc05(s32 *, s32);

void func_80025590(s32 *arg0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    arg0[0] = a1;
    arg0[1] = 0;
    arg0[2] = a2;
    arg0[3] = 0;
    arg0[6] = 0;
    arg0[3] = 0x10000;
    arg0[5] = a3;
    arg0[4] = 0;
    v = (a2 << 16) | (((u32)a2) >> 16);
    arg0[1] = v;
    UnkFunc05(arg0, 0x8000);
}

void func_80025604(s32 *arg0) {
    s32 v;
    s32 lim;
    if (arg0[5] != 0) {
        v = arg0[6] + arg0[1];
        arg0[6] = v;
        if (v < 0) {
            v = (arg0[0] << 16) + v;
            arg0[6] = v;
        }
        lim = arg0[0] << 16;
        if (v >= lim) {
            arg0[6] = v - lim;
        }
        arg0[4] = 0;
    } else {
        v = arg0[6] + arg0[1];
        if (v < 0) {
            v = 0;
        } else {
            lim = arg0[0] << 16;
            if (v >= lim) {
                v = lim - 1;
            }
        }
        if (v != arg0[6]) {
            arg0[6] = v;
            arg0[4] = 0;
        } else {
            arg0[4] = 1;
        }
    }
}

void UnkFunc05(UnkStruct00 *arg0, s32 arg1)
{
    arg0->unk18 = arg1;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800256CC);

void func_800258B0(s32 *arg0, s32 flag) {
    s32 *p;
    PakFile pf;
    free((void*)arg0[13]);
    p = (s32*)arg0[8];
    if (p != NULL) {
        *p = *p - 1;
        if (*p == 0) {
            pf = *(PakFile *)&arg0[9];
            FileSys__DeleteFile(pf);
            free((void*)arg0[8]);
        }
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

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

void func_80025D1C(s32 *arg0, s32 flag) {
    s32 *p;
    PakFile pf;
    free((void*)arg0[12]);
    p = (s32*)arg0[7];
    if (p != NULL) {
        *p = *p - 1;
        if (*p == 0) {
            pf = *(PakFile *)&arg0[8];
            FileSys__DeleteFile(pf);
            free((void*)arg0[7]);
        }
    }
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025DC0);

extern s32 D_80047EC8;
extern s32 D_80047EFC;

s32 func_80025EBC(s32 a0) {
    s32 v1, v3;
    if (a0 == -0x61 || a0 == -0x62) return a0;
    v1 = D_80047EC8 / 30;
    v3 = ((v1 * a0) >> 16) - D_80047EFC;
    if (v3 < 0) v3 = 0;
    return v3;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025F44);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800262B4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002663C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026834);

s32 func_80026940(s32 *arg0) {
    s32 a1 = arg0[28];
    s32 *entry = (s32*)((char*)arg0[23] + a1 * 20);
    s32 v1 = entry[4];
    s32 a2;
    if (v1 == -0x61) return 0;
    a2 = 0;
    if (arg0[1] == a1 - 1) {
        s32 *p = (s32*)arg0[arg0[1] + 3];
        s32 v = p[4];
        a2 = (v != 0) ? 1 : 0;
    }
    return a2;
}

typedef struct Entry14 {
    char *name;
    char pad4[8];
    s32 key;
    s32 val;
} Entry14;

void func_800269A4(s32 *arg0, s32 arg1) {
    Entry14 *table = (Entry14*)arg0[23];
    s32 i;
    if (*table->name == 0) return;
    i = 0;
    do {
        if (table[i].key == arg1) {
            arg0[1] = i;
            arg0[0] = table[i].val;
            return;
        }
        i++;
    } while (*table[i].name != 0);
}

void func_80026A10(s32 *arg0) {
    Entry14 *table;
    s32 i;
    s32 *item;

    arg0[1] = 0;
    arg0[0] = 0;
    table = (Entry14*)arg0[23];
    if (*table->name == 0) return;
    i = 0;
    do {
        item = (s32*)arg0[3 + i];
        item[4] = 0;
        UnkFunc01((UnkStruct00*)item, 0x8000);
        i++;
    } while (*table[i].name != 0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026AA0);

extern u32 D_80019E38;

void func_80026CB8(s32 *arg0, s32 flag) {
    Entry10 *table;
    s32 i;
    s32 *p;
    arg0[2] = (s32)&D_80019E38;
    table = (Entry10*)arg0[13];
    if (*table->name != 0) {
        i = 0;
        do {
            p = (s32*)arg0[3 + i];
            if (p != NULL) {
                func_80025D1C(p, 3);
            }
            i++;
        } while (*table[i].name != 0);
    }
    arg0[2] = (s32)&D_80019F40;
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

extern void func_80025DC0(s32 *, s32);

void func_80026D78(s32 *arg0) {
    s32 idx = arg0[1];
    s32 *base = (s32*)arg0[13];
    s32 *entry = (s32*)((char*)base + idx * 16);
    s32 v1 = entry[3];
    s32 cmp;
    s32 *p;
    if (v1 == -0x62) return;
    cmp = (arg0[0] < v1) ? 1 : 0;
    if (entry[7] == arg0[0]) {
        cmp ^= 1;
        arg0[1] = idx + 1;
    }
    if (cmp != 0) {
        p = (s32*)arg0[arg0[1] + 3];
        func_80025DC0(p, 0);
    }
    arg0[0] = arg0[0] + 1;
}

s32 func_80026E08(s32 *arg0) {
    s32 a2 = arg0[14];
    s32 v1 = ((s32*)((char*)arg0[13] + a2 * 16))[3];
    s32 a1;
    if (v1 == -0x61) return 0;
    a1 = 0;
    if (arg0[1] == a2 - 1) {
        s32 *p = (s32*)arg0[arg0[1] + 3];
        s32 v = p[4];
        a1 = (v != 0) ? 1 : 0;
    }
    return a1;
}

typedef struct Entry10 {
    char *name;
    char pad4[4];
    s32 key;
    s32 val;
} Entry10;

void func_80026E64(s32 *arg0, s32 arg1) {
    Entry10 *table = (Entry10*)arg0[13];
    s32 i;
    if (*table->name == 0) return;
    i = 0;
    do {
        if (table[i].key == arg1) {
            arg0[1] = i;
            arg0[0] = table[i].val;
            return;
        }
        i++;
    } while (*table[i].name != 0);
}

void func_80026ED0(s32 *arg0) {
    Entry10 *table;
    s32 i;
    s32 *item;

    arg0[1] = 0;
    arg0[0] = 0;
    table = (Entry10*)arg0[13];
    if (*table->name == 0) return;
    i = 0;
    do {
        item = (s32*)arg0[3 + i];
        item[4] = 0;
        UnkFunc01((UnkStruct00*)item, 0x8000);
        i++;
    } while (*table[i].name != 0);
}

extern u32 D_80019F40;
extern u32 D_80019E08;

s32* func_80026F5C(s32 *arg0, s32 *arg1) {
    s32 i;
    arg0[2] = (s32)&D_80019F40;
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = (s32)&D_80019E08;
    arg0[3] = (s32)arg1;
    if (arg1[0] == -1) return arg0;
    i = 0;
    do {
        s32 *e = (s32*)((char*)arg0[3] + i);
        s32 r = func_80025EBC(e[1]);
        e = (s32*)((char*)arg0[3] + i);
        e[3] = r;
        i += 0x10;
    } while (*(s32*)((char*)arg0[3] + i) != -1);
    return arg0;
}

extern void AudioSys__UnkFunc01(s32 *, s32, s32, s32, s32);

void func_80027000(s32 *arg0) {
    s32 idx = arg0[1];
    s32 *base = (s32*)arg0[3];
    s32 *entry = (s32*)((char*)base + idx * 16);
    s32 v = entry[3];
    s32 v0;
    if (v == -0x61) return;
    if (v != arg0[0]) {
        arg0[0] = arg0[0] + 1;
        return;
    }
    {
        s32 raw = entry[0];
        s32 hi = raw >> 4;
        s32 lo = raw & 0xF;
        s32 buf[3];
        buf[0] = hi;
        buf[1] = lo;
        AudioSys__UnkFunc01(buf, 0, 0x40, -1, 0);
    }
    arg0[1] = idx + 1;
    arg0[0] = arg0[0] + 1;
}

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

void func_80027104(s32 *arg0, s32 arg1) {
    s32 *table = (s32*)arg0[3];
    s32 idx;
    s32 i;
    s32 *entry;
    s32 *p;
    if (table[0] <= 0) {
        arg0[1] = 0;
        return;
    }
    idx = 0;
    i = 0;
    do {
        entry = (s32*)((char*)table + i);
        i += 0x10;
        if (entry[2] == arg1) {
            s32 raw = entry[0];
            s32 hi = raw >> 4;
            s32 lo = raw & 0xF;
            s32 buf[3];
            arg0[1] = idx;
            arg0[0] = entry[3];
            buf[0] = hi;
            buf[1] = lo;
            AudioSys__UnkFunc01(buf, 0, 0x40, -1, 0);
            return;
        }
        p = (s32*)((char*)table + i);
        idx++;
    } while (p[0] > 0);
    arg0[1] = idx;
}