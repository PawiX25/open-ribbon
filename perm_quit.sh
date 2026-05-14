#!/bin/bash
cat >> /home/pawcio/openribbon/nonmatchings/InputSys__Quit/base.c << 'EOF'

extern void PadStartCom(void);
extern void free(void *);

void InputSys__Quit(void) {
    s32 outer, inner;
    s32 *ptr;
    s32 *base;

    PadStartCom();
    for (outer = 0; outer < 2; outer++) {
        base = ((s32**)&UnkVar03)[outer];
        if (base != NULL) {
            ptr = base;
            for (inner = 0; inner < 4; inner++) {
                if (*ptr != 0) {
                    UnkFunc04((UnkStruct10 *)*ptr, 3);
                }
                ptr++;
            }
            free(base);
        }
    }
}
EOF
cd /home/pawcio/openribbon/nonmatchings/InputSys__Quit && bash compile.sh base.c /tmp/base.o 2>&1 | tail -3
timeout 240 python3 /home/pawcio/openribbon/tools/decomp-permuter/permuter.py -j 4 --stop-on-zero --quiet . 2>&1 | tail -10
