#include "program_finder.h"
#include "diskstream.h"
#include "stdio.h"
#include <stddef.h>

int find_programs(void* address, void* program_addresses[], char program_names[][PROGRAM_NAME_SIZE], int *number_of_programs)
{
    struct disk_stream* stream = diskstream_new(0);
    unsigned char b;
    int search_offset = 0;
    int begin_found = 0;
    int found = 0;
    while(found == 0)
    {
        diskstreamer_seek(stream, SEARCH_BEGIN_ADDRESS + search_offset);
        diskstreamer_read(stream, &b, 1);
        
        if(b == 'M' && begin_found == 0)
            begin_found++;
        else if(b == 'Z' && begin_found == 1)
            begin_found++;
        else if(b == 'M' && begin_found == 2)
            begin_found++;
        else if(b == 'Z' && begin_found == 3)
            found = 1;
        else
            begin_found = 0;

        search_offset += 1;
    }

    // print("Found programs sector at ");
    // print_int(SEARCH_BEGIN_ADDRESS + search_offset);
    // print("\n");

    unsigned char *program_address = (unsigned char*) address;
    unsigned char *last_adr = (unsigned char*) address;
    int end_of_programs = 0;
    
    while(1)
    {
        int end = 0;
        // read program name

        for(int i=0; i<PROGRAM_NAME_SIZE; i++)
        {
            diskstreamer_seek(stream, SEARCH_BEGIN_ADDRESS + search_offset);
            diskstreamer_read(stream, &b, 1);

            if(b == 255)
            {
                end_of_programs = 1;
                break;
            }
                
            
            program_names[*number_of_programs][i] = b;
            search_offset++;
        }

        if(end_of_programs == 1)
            break;

        while(end == 0)
        {
            diskstreamer_seek(stream, SEARCH_BEGIN_ADDRESS + search_offset);
            diskstreamer_read(stream, &b, 1);

            if(b == 0xC3)
            {
                end = 1;
                address = program_address +1;
            }
                
            *program_address = b;
            program_address++;
            search_offset += 1;
        }

        program_addresses[*number_of_programs] = last_adr;
        last_adr = address;

        *number_of_programs += 1;
    }

    return 1;
}