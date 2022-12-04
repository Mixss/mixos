#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Name wasn't given\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if(len > 8)
    {
        printf("Name too long\n");
        return 2;
    }
    FILE *file = fopen(argv[1], "wb");

    char c;
    int i;
    for(i=0; i<len; i++)
    {
        c = argv[1][i];
        fwrite(&c, 1, 1, file);
    }
    c = '\0';
    while(i<8)
    {
        fwrite(&c, 1, 1, file);
        i++;
    }

    

    fclose(file);
    return 0;
}