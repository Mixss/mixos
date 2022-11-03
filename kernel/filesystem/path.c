#include "path.h"
#include "../string/string.h"
#include "../config.h"
#include "../sysutils/sysutils.h"
#include "../memory/memory.h"

#include "../stdio/stdio.h"

static int path_valid_format(const char* path){
    int len = strlen(path);
    
    //return ((len > MAX_PATH_LENGTH) || (path[0] < '0' || path[0] > '9') ||
    //path[1] != ':' || path[2] != '/');
    return 0;
}

static int path_get_drive_number(const char** path){
    if(path_valid_format(*path) != 0)
        return ERR_BAD_PATH;

    int drive_no = *path[0] - 48;
    //skip drive number
    *path += 3;
    return drive_no;
}

static struct path_root* path_create_path_root(int drive_number){
    struct path_root* root = malloc(sizeof(struct path_root));
    root->drive_number = drive_number;
    root->first = 0;
    return root;
}

static const char* path_get_path_part(const char** path){
    print(path); print("\n");
    char* result = malloc(MAX_PATH_LENGTH);
    int i = 0;
    while(**path != '/' && **path != 0){
        result[i] = **path;
        *path ++;
        i++;
    }
    // delete beginning / from path
    if(**path == '/')
        *path ++;
    

    if(i==0)
        result = 0;


    return result;
}

struct path_part* path_parse_path_part(struct path_part* last_part, const char** path){
    const char* got_path_part = path_get_path_part(path);
    if(!got_path_part)
        return 0;

    struct path_part* part = malloc(sizeof(struct path_part));
    part->part = got_path_part;
    part->next = 0;

    if(last_part)
        last_part->next = part;

    return part;
}


struct path_root* path_parse(const char* path, const char* current_directory_path)
{
	int result = 0;
	const char* tmp_path = path;
	struct path_root* path_root = 0;



	if(strlen(path) > MAX_PATH_LENGTH){
		return path_root;
	}

	result = path_get_drive_number(&tmp_path);
	if (result < 0)
		return path_root;

	
	path_root = path_create_path_root(result);
	if(!path_root)
		return path_root;

	struct path_part* first_part = path_parse_path_part(NULL, &tmp_path);
	if(!first_part)
		return path_root;

	struct path_part* part = path_parse_path_part(first_part, &tmp_path);


    print("\n"); print(tmp_path); print("\n");


	while(part){
	    part = path_parse_path_part(part, &tmp_path);
	}

	return path_root;
}
