/*
** COPYRIGHT mandeep singh 2017 under
                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

*/

#include "declaration.h"

list<string> add(char file_name[]){
    //store input in stack first and finally write to file and the time of termination;
    //stack<string> stack_inp;
    list <string> lis;
    char *add_input;
    char *per = (char*)malloc(sizeof(char) * MAX_NAME);
    strcat(per,"a+");
    printf("enter contents of file\n");
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
        lis.push_front(total);

        /*
        * list element contains complete line as its element
        * break this list through spaces and store it in another list so that it can be useful for undo
        * return both list
        * for undo process undo_list and while processing also update ret_list

        * think of more efficient way.

        */

        fflush(stdout);
        fflush(stdin);
    }
    /*
    //write list into file
    FILE *fp = open_file(file_name,per);
    printf("\nvalues\n");
    for (list<string>::reverse_iterator i = lis.rbegin(); i != lis.rend(); ++i){
        //cout << *i << endl;
        std::string str = *i;
        const char *cstr = str.c_str();
        fprintf(fp,"%s",cstr);
        str.clear();
        str = "\n";
        cstr = str.c_str();
        fprintf(fp,"%s",cstr);
    }
    */
    return lis;
}
