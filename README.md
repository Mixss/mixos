# MixOS Operating System

This is 32-bit operating system for x86 cpu architecture written using **C** and **NASM**. The main aim of this system was to be able to run programs which could be written by any user and which would be stored on the hard disk.

![image](https://user-images.githubusercontent.com/19227717/214267676-aed99973-323c-4583-8aee-045c9f2e4c80.png)


## Usage

This operating system could probably run on any hardware however, it has only been tested with `qemu`. To use it you can execute the `run` script:
```
/run
``` 

## Terminal

The only thing that appears after booting is the terminal. It has two built-in commands:
- `help` - lists all the programs that have been correctly loaded from the disk.
- `info` - lists the physical addresses of the system functions available to the programmer for use in their program.

In addition, all the programs listed under the `help` command can be run using their names.

## Writing the programs

For now, the only way to write a program is to use NASM in [32 BITS] mode. The next limitation is that you can't use data/variables because the system only supports the code section of the program. If you want to call a system function, you have to do it by calling it by its physical address (can be found within the `info` command). Compile the assemlby code using
```
nasm -f bin
```

To install the program, you must also prepare an 8-byte binary file containing the name of it. In the `programs/names` directory there is a simple program called `exp`. It exports your name to this binary file (the program name must be given as an argument).

The process of installing the programs is performed using the `programs/install` script. If you want to install your program, you have to edit this file and insert two `dd` commands (before *end_mark*) - one with your program name (exported binary file) and the second with its binary code.

After booting up the system your program should be listed under the `help` command.

## Compilation

The system is compiled using the `i686-elf` cross-compiler and `nasm`. The compilation of the source code is set in the `Makefile`. The entire build process (with the installation of programs) can be handled using 
```
./build.sh
```
