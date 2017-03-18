#include "declaration.h"

int add(char file_name[]){
    //store input in stack first and finally write to file and the time of termination;
    //std::stack<string> stack_inp;

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
    //stringstream ss;
    //string s_conv;
    //char c = 'a';


    while((ch = std::cin.get()) != 27){
        FILE *fp = open_file(file_name,per);
        if(fp == NULL){
            return 0;
        }
        if(x!=1){
            //ss << ch;
            //ss >> s_conv;
            //stack_inp.push(s_conv);
            fprintf(fp, "%c", ch);
        }
        x++;
        fgets(add_input,MAX_STRING,stdin);
        //add_input =  ch + add_input;
        //printf("%s\n",add_input);

        //fwrite(add_input,1,sizeof(add_input),fp);
        //fputs(add_input,fp);
        //std::string str(add_input);
        //stack_inp.push(str);
        fprintf(fp,"%s",add_input);
        fflush(stdout);
        fflush(stdin);
        //fgets(add_input,MAX_STRING,stdin);
        fclose(fp);
    }
    /*
    while (!stack_inp.empty()) {
        std::cout<<stack_inp.top();
        cout<<endl;
        stack_inp.pop();
    }*/

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
