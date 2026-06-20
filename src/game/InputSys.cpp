extern "C" void deletefn(void*) __asm__("delete");
#define delete deletefn

extern "C" {
#include "common.h"

#include "globals.h"

#include <psyq/STDIO.H>

extern void func_80033930(char*, char*);
extern void* func_800303BC(s32);
extern void func_800200E4(void*, s32);
extern void func_80033F90(void);
extern void func_800201C4(s32, u8*);
extern s32 VSync(s32);
extern char D_8003FE00[];

typedef struct {
    s32 sub[4];
    u8* unk10;
} InitPad;

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Init);

extern void PadStartCom(void);
extern void free(void *);

void InputSys__Quit(void) {
    s32 outer;
    s32 **new_var;
    s32 inner;
    s32 *ptr;
    s32 *base;
    PadStartCom();
    for (outer = 0; outer < 2; outer++) {
        new_var = &((s32 **)(&UnkVar03))[outer];
        base = *new_var;
        if (base != 0) {
            inner = 0;
            ptr = base;
            for (inner = 0; inner < 4; inner++) {
                if ((*ptr) != 0) {
                    UnkFunc04((UnkStruct10 *)(*ptr), 3);
                }
                ptr++;
            }
            free(base);
        }
    }
}

typedef struct {
    s32 sub[4];
    u8* unk10;
} InputPad;

extern void func_800201C4(s32, u8*);

void InputSys__Unk03(void) {
    int cond;
    UnkStruct01** pp;
    s32 i;
    for (i = 0; i < 2; i++) {
        InputPad* pad = ((InputPad**)(pp = &UnkVar03))[i];
        u8* m = pad->unk10;
        if ((m[1] & 0xF0) == 0x80) {
            s32 j;
            for (j = 0; j < 4; j++) {
                m = pad->unk10;
                cond = m[j * 8 + 2] == 0;
                if (cond) {
                    func_800201C4(pad->sub[j], &m[j * 8 + 2]);
                }
            }
        } else {
            func_800201C4(pad->sub[0], m);
        }
    }
}

extern char D_800191E8[];
extern char D_80019210[];

s32 InputSys__Unk00(s32 arg0) {
    s32 **new_var;
    if (arg0 >= 2) {
        printf(D_800191E8, D_80019210, 0xFD);
        exit(1);
    }
    new_var = &((s32 **)(&UnkVar03))[arg0];
    return **new_var;
}

typedef struct {
    char* start;
    char* end;
} StrInputSys;

typedef struct {
    char* unk0;
    char* unk4;
    char* unk8;
    char pad[8];
} StrSlot;

extern StrSlot D_8003FDB4[2];
extern StrInputSys* func_80020AE4(StrInputSys*, char*, char*);

void InputSys__Unk01(StrSlot* self, s32 arg1) {
    StrSlot* src;

    if (arg1 >= 2) {
        printf(D_800191E8, D_80019210, 0x103);
        exit(1);
    }

    src = (StrSlot*)((char*)&D_8003FDB4 + arg1 * 12);
    if (self != src) {
        func_80020AE4((StrInputSys*)src, self->unk0, self->unk4);
    }
    {
        char* hi = self->unk8;
        char* lo = self->unk0;
        s32 d = (s32)hi - (s32)lo;
        if (lo != 0) {
            if (d != 0) {
                MemorySys__free(lo);
            }
        }
    }
}

extern char D_8003FDCC;

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800207C4);

typedef struct {
    char* unk0;
    char* unk4;
    char* unk8;
} StrSlot3;

extern StrInputSys func_800211D4(void*, StrSlot3*);
extern s32 func_800341FC(char*, char*, s32);
extern char D_8003FDD8;

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800207D0);

void func_800208BC(void) {}

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_800191E8);

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_80019210);

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_80019234);

extern int (*D_80048028)();
extern char D_80019234[]; // "out of memory\n"
extern s32 MemorySys__malloc(s32);

void InputSys__alloc(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf((char*)&D_80019234);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

typedef struct {
    char* start;
    char* end;
    char* unk8;
} Str3;

extern void* func_80030BF4(void*, const void*, s32);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_80020920);

extern void *func_8003424C(void *, const void *, int);
extern void *func_80030BF4(void *, const void *, int);
extern StrInputSys* func_80020920(StrInputSys *, char *, char *, s8);

StrInputSys* func_80020AE4(StrInputSys* self, char* new_start, char* new_end) {
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
        func_80020920(self, new_start + (self->end - self->start), new_end, 0);
    }
    return self;
}

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_80020BA8);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800211D4);

typedef struct Node_2146C {
    char pad0[0x8];
    struct Node_2146C *next;
    char padC[4];
    s32 data;
    char pad14[4];
    s32 dataEnd;
} Node_2146C;

void func_8002146C(s32 arg0, Node_2146C *node) {
    Node_2146C *next;
    s32 end, start, diff;
    if (node != NULL) {
        do {
            func_8002146C(arg0, (Node_2146C*)((s32*)node)[3]);
            end = node->dataEnd;
            start = node->data;
            next = node->next;
            diff = end - start;
            if (start != 0 && diff != 0) {
                MemorySys__free((void*)start);
            }
            MemorySys__free(node);
            node = next;
        } while (node != NULL);
    }
}

typedef struct Inner_214E8 {
    s32 unk0;
    Node_2146C *head;
    struct Inner_214E8 *self_8;
    struct Inner_214E8 *self_C;
} Inner_214E8;

typedef struct {
    Inner_214E8 *inner;
    s32 unk4;
} Container_214E8;

extern void free(void *);

void func_800214E8(Container_214E8 *arg0, s32 flag) {
    Inner_214E8 *p;
    if (arg0->unk4 != 0) {
        p = arg0->inner;
        func_8002146C((s32)arg0, p->head);
        p = arg0->inner;
        p->self_8 = p;
        p = arg0->inner;
        p->head = NULL;
        p = arg0->inner;
        p->self_C = p;
        arg0->unk4 = 0;
    }
    MemorySys__free(arg0->inner);
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

typedef struct { char* unk0; char* unk4; char* unk8; } Slot157C;
extern char D_8003FDD8;

void func_8002157C(void) {
    char* data;
    char* p;
    Slot157C* s;

    UnkFunc04((UnkStruct10*)&D_8003FDD8, 2);
    func_800214E8((Container_214E8*)&D_8003FDCC, 2);

    data = (char*)&D_8003FDB4;
    if (data != 0) {
        p = data + 0x18;
        if (p != data) {
            do {
                char* hi;
                char* lo;
                s32 d;
                p -= 0xC;
                s = (Slot157C*)p;
                hi = s->unk8;
                lo = s->unk0;
                d = (s32)hi - (s32)lo;
                if (lo != 0) {
                    if (d != 0) {
                        MemorySys__free(lo);
                    }
                }
            } while ((char*)&D_8003FDB4 != p);
        }
    }
}

typedef struct CtorNode {
    s32 unk0;
    s32 unk4;
    struct CtorNode* unk8;
    struct CtorNode* unkC;
} CtorNode;

extern void func_800200AC(void*);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Ctor);

}
