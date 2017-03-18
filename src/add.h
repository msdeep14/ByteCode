#include "declaration.h"

int add(char file_name[]){
    //store input in stack first and finally write to file and the time of termination;
    //stack<string> stack_inp;
    list <string> lis;
    char *add_input;
    char *per = (char*)malloc(sizeof(char) * MAX_NAME);
    strcat(per,"a+");
    printf("enter contents of file\n");
    add_input = (char*)malloc(sizeof(char)*MAX_STRING+2);
    //scaf("%s",add_input);

    //enter contents till the escape sequence is entered. ascii == 27;
    //fgets(add_input,MAX_STRING,stdin);
    char ch;
    int x=1;

    while((ch = std::cin.get()) != 27){
        //printf("\ninside while\n");
        FILE *fp = open_file(file_name,per);
        if(fp == NULL){
            //printf("\nfp is null\n");
            return 0;
        }
        if(x!=1){
            string s_conv;
            s_conv.push_back(ch);
            lis.push_front(s_conv);
            fprintf(fp, "%c", ch);
        }
        x++;
        fgets(add_input,MAX_STRING,stdin);

        std::string str(add_input);
        string str_temp(str.begin(),str.end()-1);
        lis.push_front(str_temp);

        fprintf(fp,"%s",add_input);
        fflush(stdout);
        fflush(stdin);
        //fgets(add_input,MAX_STRING,stdin);
        fclose(fp);
    }
    printf("\nvalues\n");
    for (list<string>::iterator i = lis.begin(); i != lis.end(); ++i)
    cout << *i << endl;


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
