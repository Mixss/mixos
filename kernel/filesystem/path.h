#ifndef PATH_H
#define PATH_H

struct path_root
{
    int drive_number;
    struct path_part* first;
};

struct path_part
{
    const char* part;
    struct path_part* next;
};

// returns 0 if path is valid
//  static int path_valid_format(const char* path); 

//  static struct path_root* path_create_path_root(int drive_number); 

//  // these functions change the path received - they cut already parsed elements 
//  static int path_get_drive_number(const char** path); 
//  static const char* path_get_path_part(const char** path); 

// struct path_part* path_parse_path_part(struct path_part* last_part, const char** path); 

struct path_root* path_parse(const char* path, const char* current_directory_path);


#endif