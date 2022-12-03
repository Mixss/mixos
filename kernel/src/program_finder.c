#include "program_finder.h"
#include "diskstream.h"
#include "stdio.h"

int find_programs(void* address)
{
    struct disk_stream* stream = diskstream_new(0);
    unsigned char bytes[512];
    unsigned char b;
    int search_offset = 0;
    int begin_found = 0;
    int found = 0;
    while(found == 0)
    {
        diskstreamer_seek(stream, SEARCH_BEGIN_ADDRESS + search_offset);
        diskstreamer_read(stream, &b, 1);
        // print_int(SEARCH_BEGIN_ADDRESS + search_offset);
        // print("\n");
        
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

    print("Found programs sector at ");
    print_int(SEARCH_BEGIN_ADDRESS + search_offset);
    print("\n");

    unsigned char *program_address = (unsigned char*) address;
    int end = 0;
    while(end == 0)
    {
        diskstreamer_seek(stream, SEARCH_BEGIN_ADDRESS + search_offset);
        diskstreamer_read(stream, &b, 1);

        if(b == 0xC3)
            end = 1;
        *program_address = b;
        program_address++;
        search_offset += 1;
    }

    /*
    if(b == 'H' && end_found == 0 )
            end_found++;
        else if (b == 'A' && end_found == 1)
            end_found++;
        else if (b == 'H' && end_found == 2)
            end_found++;
        else if (b == 'A' && end_found == 3)
            end = 1;
        else
            end_found = 0;
    */

    return 1;
}