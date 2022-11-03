#include "ppath.h"
#include "../string/string.h"
#include "../config.h"
#include "../sysutils/sysutils.h"
#include "../memory/memory.h"

#include "../stdio/stdio.h"

static int pathparser_path_valid_format(const char* path)
{
    int len = strlen(path);
    
    //return ((len > MAX_PATH_LENGTH) || (path[0] < '0' || path[0] > '9') ||
    //path[1] != ':' || path[2] != '/');
    //return (len >= 3 && (path[0]-48) && (path[1]==':' && path[2]=='/'));
    return 1;
}

static int pathparser_get_drive_by_path(const char** path)
{
    if(!pathparser_path_valid_format(*path))
    {
        return -1;
    }

    int drive_no = *path[0] -48;

    // Add 3 bytes to skip drive number 0:/ 1:/ 2:/
    *path += 3;
    return drive_no;
}

static struct path_root* pathparser_create_root(int drive_number)
{
    struct path_root* path_r = malloc(sizeof(struct path_root));
    path_r->drive_no = drive_number;
    path_r->first = 0;
    return path_r;
}


static const char* pathparser_get_path_part(const char** path)
{
    char* result_path_part = malloc(MAX_PATH_LENGTH);
    int i = 0;
    while(**path != '/' && **path != 0x00)
    {
        result_path_part[i] = **path;
        *path += 1;
        i++;
    }

    if (**path == '/')
    {
        // Skip the forward slash to avoid problems
        *path += 1;
    }

    if(i == 0)
    {

        result_path_part = 0;
    }

    return result_path_part;
}

struct path_part* pathparser_parse_path_part(struct path_part* last_part, const char** path)
{
    const char* path_part_str = pathparser_get_path_part(path);
    if (!path_part_str)
    {
        return 0;
    }

    struct path_part* part = malloc(sizeof(struct path_part));
    part->part = path_part_str;
    part->next = 0x00;

    if (last_part)
    {
        last_part->next = part;
    }

    return part;
}

struct path_root* pathparser_parse(const char* path, const char* current_directory_path)
{
    int res = 0;
    const char* tmp_path = path;
    struct path_root* path_root = 0;

    if (strlen(path) > MAX_PATH_LENGTH)
    {
        print_int(2);
        goto out;
    }

    res = pathparser_get_drive_by_path(&tmp_path);
    if (res < 0)
    {
        print_int(3);
        goto out;
    }

    path_root = pathparser_create_root(res);
    if (!path_root)
    {
        print_int(4);
        goto out;
    }

    struct path_part* first_part = pathparser_parse_path_part(NULL, &tmp_path);
    if (!first_part)
    {
        print_int(5);
        goto out;
    }

    path_root->first = first_part;
    struct path_part* part = pathparser_parse_path_part(first_part, &tmp_path);
    while(part)
    {
        part = pathparser_parse_path_part(part, &tmp_path);
    }
out:
    return path_root;
}