ODIR=./build
IDIR=./include
EXEC=program

_OBJ = kernel.asm.o kernel.o idt.asm.o idt.o memory.o tty.o stdio.o io.o keyboard.o string.o disk.o diskstream.o program_finder.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
FLAGS = -g -ffreestanding -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 -I$(IDIR)

_DEPS = config.h disk.h diskstream.h idt.h io.h keyboard.h memory.h stdio.h string.h tty.h program_finder.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: kernel/src/%.c $(DEPS)
	i686-elf-gcc -c $< -o $@ $(FLAGS) -std=gnu99

all: ./bin/boot.bin ./bin/kernel.bin
	rm -rf ./bin/os.bin
	dd if=./bin/boot.bin >> ./bin/os.bin
	dd if=./bin/kernel.bin >> ./bin/os.bin
	dd if=/dev/zero bs=512 count=100 >> ./bin/os.bin 

./bin/kernel.bin: $(OBJ)
	i686-elf-ld -g -relocatable $(OBJ) -o ./build/kernelfull.o
	i686-elf-gcc $(FLAGS) -T ./kernel/linker.ld -o ./bin/kernel.bin -ffreestanding -O0 -nostdlib ./build/kernelfull.o

./bin/boot.bin: ./kernel/asm/boot.asm
	nasm -f bin ./kernel/asm/boot.asm -o ./bin/boot.bin

./build/kernel.asm.o: ./kernel/asm/kernel.asm
	nasm -f elf ./kernel/asm/kernel.asm -o ./build/kernel.asm.o

./build/idt.asm.o: ./kernel/asm/idt.asm
	nasm -f elf ./kernel/asm/idt.asm -o ./build/idt.asm.o

./build/io.o: ./kernel/asm/io.asm
	nasm -f elf ./kernel/asm/io.asm -o ./build/io.o

.PHONY: clean

clean:
	rm -rf $(ODIR)/*
	rm $(EXEC)
