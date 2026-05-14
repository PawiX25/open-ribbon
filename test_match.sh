#!/bin/bash
cd ~/openribbon
git checkout main >/dev/null 2>&1 || true
git fetch /mnt/d/openribbon/repo more-decomp:tmp -f >/dev/null 2>&1 || { echo "FETCH FAILED"; exit 2; }
git checkout tmp >/dev/null 2>&1
rm -rf build
mkdir -p build/asm/game/data build/asm/game/nonmatchings build/src/game
make >/tmp/buildlog 2>&1
if sha1sum --check sces028.sha >/dev/null 2>&1; then
    echo MATCH
else
    if [ -f build/MAIN_T.EXE ]; then
        DIFF=$(cmp -l iso/MAIN_T.EXE build/MAIN_T.EXE 2>/dev/null | wc -l)
        echo "MISMATCH: $DIFF bytes"
    else
        echo "BUILD FAILED"
        tail -5 /tmp/buildlog
    fi
fi
