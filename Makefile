FILES = ./build/kernel.asm.o ./build/kernel.o ./build/idt.asm.o ./build/idt.o ./build/memory.o ./build/tty.o ./build/stdio.o ./build/sysutils.o ./build/io.o ./build/keyboard.o ./build/string.o ./build/disk.o
INCLUDES = -I./kernel
FLAGS = -g -ffreestanding -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 -Iinc

all: ./bin/boot.bin ./bin/kernel.bin
	rm -rf ./bin/os.bin
	dd if=./bin/boot.bin >> ./bin/os.bin
	dd if=./bin/kernel.bin >> ./bin/os.bin
	dd if=/dev/zero bs=512 count=100 >> ./bin/os.bin

./bin/kernel.bin: $(FILES)
	i686-elf-ld -g -relocatable $(FILES) -o ./build/kernelfull.o
	i686-elf-gcc $(FLAGS) -T ./kernel/linker.ld -o ./bin/kernel.bin -ffreestanding -O0 -nostdlib ./build/kernelfull.o

./bin/boot.bin: ./kernel/boot/boot.asm
	nasm -f bin ./kernel/boot/boot.asm -o ./bin/boot.bin

./build/kernel.asm.o: ./kernel/kernel.asm
	nasm -f elf ./kernel/kernel.asm -o ./build/kernel.asm.o

./build/idt.asm.o: ./kernel/idt/idt.asm
	nasm -f elf ./kernel/idt/idt.asm -o ./build/idt.asm.o

./build/kernel.o: ./kernel/kernel.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/kernel.c -o ./build/kernel.o

./build/idt.o: ./kernel/idt/idt.c
	i686-elf-gcc $(INCLUDES) -I./kernel/idt $(FLAGS) -std=gnu99 -c ./kernel/idt/idt.c -o ./build/idt.o

./build/memory.o: ./kernel/memory/memory.c
	i686-elf-gcc $(INCLUDES) -I./kernel/memory $(FLAGS) -std=gnu99 -c ./kernel/memory/memory.c -o ./build/memory.o

./build/tty.o: ./kernel/tty/tty.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/tty/tty.c -o ./build/tty.o

./build/stdio.o: ./kernel/stdio/stdio.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/stdio/stdio.c -o ./build/stdio.o

./build/sysutils.o: ./kernel/sysutils/sysutils.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/sysutils/sysutils.c -o ./build/sysutils.o

./build/io.o: ./kernel/io/io.asm
	nasm -f elf ./kernel/io/io.asm -o ./build/io.o

./build/keyboard.o: ./kernel/io/keyboard.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/io/keyboard.c -o ./build/keyboard.o

./build/string.o: ./kernel/string/string.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/string/string.c -o ./build/string.o

./build/disk.o: ./kernel/io/disk.c
	i686-elf-gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./kernel/io/disk.c -o ././build/disk.o

clean:
	rm -rf ./bin/*
	rm -rf ./build/*