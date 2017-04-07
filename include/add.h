/*
** COPYRIGHT mandeep singh 2017 under
                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

*/

#include "declaration.h"

list<string> insert_by_token_into_list(list<string> undo_list,string total){
    // char * strtok ( char * str, const char * delimiters );
    char buffer[1024];
    const char * Into_buffer = (char*)malloc(sizeof(char)*1024);
    Into_buffer = total.c_str();
    strcpy(buffer, Into_buffer);
    char *token = strtok(buffer, " ");
    while (token) {
        string token_temp(token);
        undo_list.push_front(token_temp);
        token = strtok(NULL, " ");
    }
    return undo_list;
}

vector<list <string> > add(){
    vector <vector <string> > vec;
    std::vector <list<string> > list_store;
    list <string> ret_list;
    list <string> undo_list;
    char *add_input;
    char *per = (char*)malloc(sizeof(char) * MAX_NAME);
    strcat(per,"a+");
    //printf("enter contents of file\n");
    add_input = (char*)malloc(sizeof(char)*MAX_STRING+2);
    //enter contents till the escape sequence is entered. ascii == 27;
    fgets(add_input,MAX_STRING,stdin);
    char ch;

    while((ch = std::cin.get()) != 27){
        string total;
        total.push_back(ch);
        fgets(add_input,MAX_STRING,stdin);

        //str_temp because str takes "\n" as the last element of string which creates a empty push in the list;
        std::string str(add_input);
        string str_temp(str.begin(),str.end()-1);
        total +=str_temp;
        ret_list.push_front(total);

        /*
        * list element contains complete line as its element
        * break this list through spaces and store it in another list so that it can be useful for undo
        * return both list
        * for undo process undo_list and while processing also update ret_list

        * think of more efficient way.

        */
        undo_list = insert_by_token_into_list(undo_list,total);
        fflush(stdout);
        fflush(stdin);
    }
    list_store.push_back(ret_list);
    list_store.push_back(undo_list);
    return list_store;
}
