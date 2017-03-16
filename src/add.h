#include "declaration.h"

int add(char file_name[]){
    char *add_input;
    char *per = (char*)malloc(sizeof(char) * MAX_NAME);
    strcat(per,"a+");
    printf("enter contents of file\n");
    add_input = (char*)malloc(sizeof(char)*MAX_STRING+2);
    //scaf("%s",add_input);

    //enter contents till the escape sequence is entered. ascii == 27;
    //fgets(add_input,MAX_STRING,stdin);
    char ch;

    while((ch = std::cin.get()) != 27){
        fgets(add_input,MAX_STRING,stdin);
        //printf("%s\n",add_input);
        FILE *fp = open_file(file_name,per);
        if(fp == NULL){
            return 0;
        }
        //fwrite(add_input,1,sizeof(add_input),fp);
        fputs(add_input,fp);
        //fgets(add_input,MAX_STRING,stdin);
        fclose(fp);
    }
    /*
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
    */
    return 1;
}
