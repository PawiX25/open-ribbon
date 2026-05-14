#!/bin/bash
# Replace NULL with 0 in base.c
sed -i 's/NULL/0/g' /home/pawcio/openribbon/nonmatchings/InputSys__Quit/base.c
cd /home/pawcio/openribbon/nonmatchings/InputSys__Quit
bash compile.sh base.c /tmp/base.o 2>&1 | tail -3
timeout 240 python3 /home/pawcio/openribbon/tools/decomp-permuter/permuter.py -j 4 --stop-on-zero --quiet . 2>&1 | tail -8
