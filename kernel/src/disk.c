#include "io.h"
#include "disk.h"

struct disk disk;

int disk_read_sector(int lba, int number_of_sectors, void* buffer) {
    // send drive and bits 24 -27 of lba
    outb(0x1F6, (lba >> 24) | 0b11100000 );
    // send number of sectors
    outb(0x1F2, number_of_sectors);
    // send bits 0-7 of lba
    outb(0x1F3, lba & 0xFF);
    // send bits 8-15 of lba
    outb(0x1F4, (lba >> 8) & 0xFF);
    // send bits 16-23 of lba
    outb(0x1F5, (lba >> 16) & 0xFF);
    // read with retry
    outb(0x1F7, 0x20);

    unsigned short* ptr = (unsigned short*) buffer;
    for(int i=0; i<number_of_sectors; i++){
        char flag = insb(0x1F7);
        // the sector buffer requires servicing until the sector buffer is ready.
        while(!(flag & 0x08)){
            flag = insb(0x1F7);
        }

        // taking data from disk
        for(int j=0; j< NUMBER_OF_WORDS_IN_SECTOR; j++){
            *ptr = insw(0x1F0);
            ptr++;
        }

    }
    return 0;
}

struct disk* disk_get(int index)
{
    if (index != 0)
        return 0;
    
    return &disk;
}