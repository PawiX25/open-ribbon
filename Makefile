AS			:= mips-linux-gnu-as
LD			:= mips-linux-gnu-ld
OBJCOPY		:= mips-linux-gnu-objcopy

GCC			:= ./tools/bin/gcc -c -B./tools/bin/

CPPFLAGS	:= -Iinclude -Iinclude/psyq

CCFLAGS		:= -mips1 -mno-abicalls -mel -msplit-addresses -mgpOPT -mgpopt -msoft-float -fsigned-char -gcoff
CCFLAGS		+= -fno-exceptions -fno-rtti
CCFLAGS		+= $(CPPFLAGS)

AS_FLAGS	:= -Wa,-Iinclude,-no-pad-sections

SDATA_LIMIT	:= -G4
OPT_FLAGS	:= -Os

LOADER_ASMS = $(wildcard asm/loader/**/*.s asm/loader/*.s)
LOADER_ASMOBJS = $(patsubst asm/%.s, build/asm/%.o, $(LOADER_ASMS))

LOADER_SRCS := src/loader.cpp src/GameParams.cpp
LOADER_SRCOBJS := $(patsubst src/%.cpp, build/src/%.o, $(LOADER_SRCS))

all: build check

info:
	$(info LOADER_ASMS: $(LOADER_ASMS))
	$(info LOADER_ASMOBJS: $(LOADER_ASMOBJS))
	$(info LOADER_SRCS: $(LOADER_SRCS))
	$(info LOADER_SRCOBJS: $(LOADER_SRCOBJS))

clean:
	rm -rf build
	rm -rf asm/loader
	rm -rf loader.ld

configure:
	splat split config/loader.eu.yaml
	@mkdir -p build/src
	@mkdir -p build/asm/loader/data

build: build/loader.exe

check:
	sha1sum --check config/loader.eu.sha

expected: check
	@mkdir -p expected
	@rm -rf expected/build
	@cp -r build expected/build

build/loader.exe: build/loader.elf
	$(OBJCOPY) -O binary build/loader.elf $@

build/loader.elf: $(LOADER_ASMOBJS) $(LOADER_SRCOBJS)
	$(LD) -EL -o $@ \
		-Map build/loader.map \
		-T loader.ld \
		-T config/loader.undefined_funcs_auto.txt \
		-T config/loader.undefined_syms_auto.txt

build/asm/%.o: asm/%.s
	$(AS) -EL -Iinclude -no-pad-sections -o $@ $<

build/src/loader.o: src/loader.cpp
	$(GCC) $(CCFLAGS) $(SDATA_LIMIT) $(OPT_FLAGS) $(AS_FLAGS) $< -o $@

build/src/GameParams.o: src/GameParams.cpp
	$(GCC) $(CCFLAGS) $(SDATA_LIMIT) $(OPT_FLAGS) $(AS_FLAGS) $< -o $@

.PHONY: all clean configure build check expected
