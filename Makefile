all: mixos

mixos: ./isodir/boot/mixsos.bin
	grub-mkrescue -o system.iso isodir

./isodir/boot/mixsos.bin:  boot.o kernel.o stdio.o tty.o
	i386-elf-gcc -T ./kernel/arch/linker.ld -o ./isodir/boot/mixos.bin -ffreestanding -O2 -nostdlib ./build/boot.o ./build/kernel.o ./build/stdio.o ./build/tty.o -lgcc

kernel.o: 
	i386-elf-gcc -c ./kernel/kernel.c -o ./build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ./kernel/include/

boot.o: 
	nasm -felf ./kernel/arch/boot.asm -o ./build/boot.o

stdio.o: 
	i386-elf-gcc -c ./kernel/stdio.c -o ./build/stdio.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ./kernel/include/
tty.o:
	i386-elf-gcc -c ./kernel/arch/tty.c -o ./build/tty.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ./kernel/include/
clean:
	rm ./build/*