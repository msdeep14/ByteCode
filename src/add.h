#include "declaration.h"

int add(char file_name[]){
    char *add_input;
    char *per = (char*)malloc(sizeof(char) * MAX_NAME);
    strcat(per,"a+");
    printf("enter contents of file\n");
    add_input = (char*)malloc(sizeof(char)*MAX_STRING+2);
    //scanf("%s",add_input);
    fgets(add_input,MAX_STRING,stdin);
    fgets(add_input,MAX_STRING,stdin);
    //printf("%s\n",add_input);
    FILE *fp = open_file(file_name,per);
    if(fp == NULL){
        return 0;
    }
    //fwrite(add_input,1,sizeof(add_input),fp);
    fputs(add_input,fp);
    fclose(fp);
    return 1;
}
