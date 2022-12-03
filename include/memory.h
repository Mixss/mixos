#ifndef MEMORY_H
#define MEMORY_H

#define PROGRAM_MEMORY_START_ADDRESS 0x02000000

#include <stddef.h>

static void* addres_to_allocate = (void*)PROGRAM_MEMORY_START_ADDRESS;


void* memset(void* ptr, int c, size_t size);
void *malloc(size_t size);
#endif