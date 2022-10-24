#ifndef DISK_H
#define DISK_H

#define NUMBER_OF_WORDS_IN_SECTOR 256

int disk_read_sector(int lba, int number_of_sectors, void* buffer);

#endif