#ifndef DISKSTREAM_H
#define DISKSTREAM_H

#include "disk.h"

struct disk_stream
{
    int pos;
    struct disk* disk;
};

struct disk_stream* diskstream_new(int disk_id);
int diskstreamer_seek(struct disk_stream* stream, int pos);
int diskstreamer_read(struct disk_stream* stream, void* out, int total);

#endif 