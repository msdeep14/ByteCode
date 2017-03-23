/*
** COPYRIGHT mandeep singh 2017 under
                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

*/


#include "declaration.h"
#include "file_handler.h"
#include "add.h"

int convert_to_integer(char input[]){
	int ans = 0;
	vector<string> vec;
	vec.push_back("i");
	vec.push_back("wq");
	vec.push_back("q");
	vec.push_back("u");
	string s = input;
	if(s==vec[0]) ans=1;
	else if(s==vec[1]) ans=2;
	else if(s==vec[2]) ans=3;
	else if(s == vec[3]) ans = 4;
	else ans = 0;
	return ans;
}

int main(int argc, char *argv[]){
	printf("\n\t\tHello world!!!\n\n");
	char ch_check = 'y';
	int flag=1,ret=0;
	vector <list <string> > list_store;
	FILE *fp;
	char *file_name;
	file_name=(char*)malloc(sizeof(char)*MAX_NAME);
	//check for the no. of arguments
	// for creating new file -> ./a.out -c myfile.txt
	if(argc == 3){
		if(strcmp(argv[1],"-c") == 0){
			//create new file
			//check if entered file name already exists
			char *per = (char*)malloc(sizeof(char) * MAX_NAME);
			strcat(per,"w+");
			ret = check_file_existence(argv[2],per);
			if(ret == 1){
				printf("\n%s already exists!!!\n",argv[2]);
				printf("for opening existing file enter : ./a.out myfile.txt\n\n");
				exit(0);
			}
			fp = open_file(argv[2],per);
			strcpy(file_name,argv[2]);
		}else if(strcmp(argv[1],"-r") == 0){
			//open file in read mode;
			char *per = (char*)malloc(sizeof(char)*MAX_NAME);
			strcat(per,"r");
			int c;
			fp = open_file(argv[2],per);
			if(fp != NULL){
				//diplay file on  terminal;
				while ((c = getc(fp)) != EOF){
					putchar(c);
				}
				return 0;
			}else{
				printf("\nfile don't exist!\n\t\texiting...\n\n");
				return 0;
			}
		}else{
			printf("\nwrong input, usage : ./a.out -c myfile.txt\n\n");
			exit(0);
		}
	}
	//open a existing file
	else if(argc == 2){
		char *per = (char*)malloc(sizeof(char) * MAX_NAME);
		strcat(per,"a+");
		fp = open_file(argv[1],per);
		strcpy(file_name,argv[1]);
		if(fp == NULL){
			printf("\n%s don't exist\n\n",argv[1]);
			exit(0);
		}
		//fclose(fp);
	}else{
		printf("\nwrong input, usage : ./a.out -c myfile.txt\n OR SEE INSTRUCIONS\n");
		exit(0);
	}

	//file opened, write data to stream and finally to file on save.
	// i -> insert
	// q -> quit
	// s -> save and quit
	//
	char *input = (char*)malloc(sizeof(char)*MAX_NAME);
	printf("\n:");
	scanf("%s",input);
	//convert input string to integer sequences
	int inp = convert_to_integer(input);
	while(flag==1){
		switch(inp){
			case 1 :
				//add
				list_store = add(file_name);//
				if(list_store[1].size() == 0){
					printf("\nwrite operation failed!!!\n");
				}
				/*
				for (list<string>::reverse_iterator i = list_store[1].rbegin(); i != list_store[1].rend(); ++i){
			        cout << *i << endl;
			    }*/
				break;
			case 2 :
				// save and exit
				//do all the operations on returned list and finally write list to file on termination;
				//write_list_to_file(file_name,per,lis);
				for (list<string>::reverse_iterator i = list_store[0].rbegin(); i != list_store[0].rend(); ++i){
			        std::string str = *i;
			        const char *cstr = str.c_str();
			        fprintf(fp,"%s",cstr);
			        str.clear();
			        str = "\n";
			        cstr = str.c_str();
			        fprintf(fp,"%s",cstr);
			    }
				printf("contents saved to file\nexiting...\n\n");
				flag=0;
				break;
			case 3:
				//don't save any contents and exit;
				printf("\nAre you sure you want to exit without saving (y/n)?\n");
				scanf("%c",&ch_check);
				if(ch_check == 'Y' || ch_check =='y'){
					flag = 0;
				}else if(ch_check == 'n' || ch_check == 'N'){
					printf("\nsaving the contents of file!\n");
					for (list<string>::reverse_iterator i = list_store[0].rbegin(); i != list_store[0].rend(); ++i){
				        std::string str = *i;
				        const char *cstr = str.c_str();
				        fprintf(fp,"%s",cstr);
				        str.clear();
				        str = "\n";
				        cstr = str.c_str();
				        fprintf(fp,"%s",cstr);
				    }
				}else{
					printf("\ncare for your data\nenter correct choice next time\nexiting...\n\n");
				}
				flag=0;
				break;
			case 4:
				//undo
				if(list_store[1].size() > 0){
					string front_element = list_store[1].front();
					list_store[1].pop_front();
					//also remove this string element from ret_list;
					if(list_store[0].size() != 0){
						int size = list_store[0].size();
						//string s_ret_list = list_store[0].front();
						int size_undo_list_element = front_element.size();
						if(size_undo_list_element >0){
							int size_list_store = list_store[0].front().size();
							int size_diff = size_list_store - size_undo_list_element;
							string to_change = list_store[0].front();
							cout<<"to_change,size :: "<<to_change<<", "<<size_list_store<<endl;
							//to_change[size_diff]="\0";
							//to_change.insert(size_diff-1,"\0");
							if(size_diff - 1 > 1){
								to_change.resize(size_diff-1);
								list_store[0].front() = to_change;
								//cout<<"changed:: "<<list_store[0].front()<<endl;
							}else{
								list_store[0].pop_front();
							}
						}else{
							list_store[0].pop_front();
						}
					}
					system("clear");
					/*
					for (list<string>::reverse_iterator i = list_store[1].rbegin(); i != list_store[1].rend(); ++i){
				        cout << *i << endl;
				    }*/
				}else{
					printf("\nnothing to undo!\n");
				}
				break;
			default:
				//printf("inp : %d\n",inp);
				printf("\nenter correct input sequence\n\n");
				break;
		}
		if(flag!=0){
			printf("\n\n:");
			scanf("%s",input);
			inp=convert_to_integer(input);
		}
	}
	printf("\n\n");
	return 0;
}
