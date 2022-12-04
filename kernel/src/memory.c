#include "memory.h"
#include "stdio.h"

void* memset(void* ptr, int c, size_t size)
{
    char* c_ptr = (char*) ptr;
    for (int i = 0; i < size; i++)
    {
        c_ptr[i] = (char) c;
    }
    return ptr;
}

void *malloc(size_t size) {
    void* address = addres_to_allocate;
    addres_to_allocate += size;
    if(addres_to_allocate >= 0xC0000000) {
        print("malloc() failed.\n");
        return 0; 
        }
    return address;
}