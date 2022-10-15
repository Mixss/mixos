#/bin/bash
make clean
export PREFIX="/home/mixss/Documents/gcc/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
make all
