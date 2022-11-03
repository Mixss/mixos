#include "diskstream.h"
#include "../memory/memory.h"

#include "../config.h"

struct disk_stream* diskstream_new(int disk_id){
    struct disk* disk = disk_get(disk_id);
    if(disk == 0)
        return 0;

    struct disk_stream* streamer = malloc(sizeof(struct disk_stream));
    streamer->pos = 0;
    streamer->disk = disk;
    return streamer;
}

int diskstreamer_seek(struct disk_stream* stream, int pos)
{
    stream->pos = pos;
    return 0;
}

int diskstreamer_read(struct disk_stream* stream, void* out, int total)
{
    int sector = stream->pos / 512;
    int offset = stream->pos % 512;
    char buf[512];
    int res = disk_read_sector(sector, 1, buf);
    if(res < 0)
        return res;

    int total_to_read = total > 512 ? 512 : total;

    for(int i=0; i<total_to_read; i++){
        *(char*)out++ = buf[offset+i];
    }

    stream->pos += total_to_read;
    if(total > 512){
        res = diskstreamer_read(stream, out, total-512);
    }
    return res;
}
