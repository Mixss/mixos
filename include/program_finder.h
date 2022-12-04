#ifndef PROGRAM_FINDER_H
#define PROGRAM_FINDER_H

#define SEARCH_BEGIN_ADDRESS 0x12a41

#define PROGRAM_NAME_SIZE 8

// address is the memory adress where the program will be loaded
int find_programs(void* address, void* program_addresses[], char program_names[][PROGRAM_NAME_SIZE], int *number_of_programs);


#endif