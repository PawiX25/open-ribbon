#!/bin/bash
sed -i 's/NULL/0/g' /home/pawcio/openribbon/nonmatchings/InputSys__Unk01/base.c
cat >> /home/pawcio/openribbon/nonmatchings/InputSys__Unk01/base.c << 'EOF'

typedef struct {
    char *start;
    char *end;
    s32 capEnd;
} StrUnk01;

extern StrUnk01 D_8003FDB4[];
extern void *func_80020AE4(void *, char *, char *);

void InputSys__Unk01(StrUnk01 *self, s32 arg1) {
    StrUnk01 *src;
    s32 capEnd;
    char *start;
    s32 diff;
    if (arg1 >= 2) {
        printf(D_800191E8, D_80019210, 0x103);
        exit(1);
    }
    src = &D_8003FDB4[arg1];
    if (self != src) {
        func_80020AE4(self, src->start, src->end);
    }
    capEnd = self->capEnd;
    start = self->start;
    if (start != 0) {
        diff = capEnd - (s32)start;
        if (diff != 0) {
            MemorySys__free(start);
        }
    }
}
EOF
cd /home/pawcio/openribbon/nonmatchings/InputSys__Unk01
bash compile.sh base.c /tmp/base.o 2>&1 | tail -3
timeout 240 python3 /home/pawcio/openribbon/tools/decomp-permuter/permuter.py -j 4 --stop-on-zero --quiet . 2>&1 | tail -8
