#!/bin/bash
cat >> /home/pawcio/openribbon/nonmatchings/AudioSys__new/base.c << 'EOF'

typedef struct {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} AudioSysObj;

extern u32 D_8001918C;
extern void AudioSys__ParseVH(AudioSysObj *, s32);

AudioSysObj *AudioSys__new(AudioSysObj *self, s32 arg1) {
    self->unk18 = (s32)&D_8001918C;
    self->unk10 = 0;
    self->unk18 = (s32)AudioSys__ParseVH(self, -1);
    self->unk14 = -1;
    self->unk20 = ((AudioSysObj*)self->unk0)->unkC - (self->unkC + 0x200 - arg1);
    return self;
}
EOF
cd /home/pawcio/openribbon/nonmatchings/AudioSys__new && bash compile.sh base.c /tmp/base.o 2>&1 | tail -3
