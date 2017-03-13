#include "declaration.h"

FILE * open_file(char file_name[] , char perm[]){
    FILE *fp;
    struct stat st = {0};
    char *name = (char *)malloc(sizeof(char) * (2 * MAX_NAME + 15));
       strcpy(name, "./FILES/");

    if (stat(name, &st) == -1)
        mkdir(name, 0775);

    strcat(name, file_name);
    fp = fopen(name, perm);
    if (!fp){
        printf("\nError in opening file\n");
    }
    free(name);
    return fp;
}
