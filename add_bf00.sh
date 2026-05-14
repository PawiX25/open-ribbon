#!/bin/bash
cat >> /home/pawcio/openribbon/nonmatchings/func_8002BF00/base.c << 'EOF'
extern s32 D_80040840[3];
extern s32 D_800481DC[3];
extern s32 D_800481CC[3];
extern s32 D_8001A298;
extern s32 D_8001A2B0;
extern s32 D_8004084C[3];

void func_8002BF00(void) {
    D_800481DC[0] = 3;
    D_800481DC[1] = 2;
    D_800481DC[2] = (s32)&D_8001A298;
    D_80040840[0] = 0;
    D_80040840[1] = 0;
    D_80040840[2] = 0;
    D_800481CC[0] = 1;
    D_800481CC[2] = (s32)&D_8001A2B0;
    D_800481CC[1] = 3;
    D_8004084C[0] = 0;
    D_8004084C[1] = 0;
    D_8004084C[2] = 0;
}
EOF
cd /home/pawcio/openribbon/nonmatchings/func_8002BF00 && bash compile.sh base.c /tmp/base.o 2>&1 | tail -3
