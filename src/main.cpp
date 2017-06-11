/*
** COPYRIGHT mandeep singh 2017 under
                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

*/


#include "declaration.h"
#include "file_handler.h"
#include "add.h"

int convert_to_integer(std::vector<string> store_input_vec, char input[]){
	int ans = 0;
	string s = input;
	if(s==store_input_vec[0]) ans=1;
	else if(s==store_input_vec[1]) ans=2;
	else if(s==store_input_vec[2]) ans=3;
	else if(s == store_input_vec[3]) ans = 4;
	else if(s == store_input_vec[4]) ans = 5;
	else if(s == store_input_vec[5]) ans = 6;
	else ans = 0;
	return ans;
}

void print_message(){
	printf("\n\t\t\t\t\t\t\tByteCode\n");
	printf("\t\t\t\t\t\t\t=========\n\n");
	printf("\n\t\t\t\t\t\t developed by : msdeep14\n\n");
}

int main(int argc, char *argv[]){
	system("clear");
	print_message();
	int data_input_flag = 0; //set to 1 , once you enter the contents of file using :i
	char *ch_check; //flag for checking whether to exit without saving the file;
	ch_check = (char*)malloc(sizeof(char)*1);
	int flag=1,ret=0;
	string current_copy_line; //string has a copy of current line data;
	vector <list <string> > list_store;
	FILE *fp;
	char *file_name;
	//store input commands in string vector
	vector<string> store_input_vec;
	store_input_vec.push_back("i");
	store_input_vec.push_back("wq");
	store_input_vec.push_back("q");
	store_input_vec.push_back("u");
	store_input_vec.push_back("yc");
	store_input_vec.push_back("yp");
	file_name=(char*)malloc(sizeof(char)*MAX_NAME);
	//check for the no. of arguments
	// for creating new file -> ./bytecode -c myfile.txt
	if(argc == 3){
		if(strcmp(argv[1],"-c") == 0){
			//create new file
			//check if entered file name already exists
			char *per = (char*)malloc(sizeof(char) * MAX_NAME);
			strcpy(per,"w+");
			ret = check_file_existence(argv[2]);
			if(ret == 1){
				printf("\n%s already exists!!!\n",argv[2]);
				printf("for opening existing file enter : ./bytecode myfile.txt\n\n");
				exit(0);
			}
			fp = open_file(argv[2],per);
			strcpy(file_name,argv[2]);
		}else if(strcmp(argv[1],"-r") == 0){
			//open file in read mode;
			char *per = (char*)malloc(sizeof(char)*MAX_NAME);
			strcpy(per,"r");
			fp = open_file(argv[2],per);
			if(fp != NULL){
				print_file_contents(fp);
				return 0;
			}else{
				printf("\nfile don't exist!\n\t\texiting...\n\n");
				return 0;
			}
		}else{
			printf("\nwrong input, usage : ./bytecode -c myfile.txt\n\n");
			exit(0);
		}
	}
	//open a existing file
	else if(argc == 2){
		char *per = (char*)malloc(sizeof(char) * MAX_NAME);
		strcpy(per,"a+");
		fp = open_file(argv[1],per);
		strcpy(file_name,argv[1]);
		//print contents of file on terminal
		print_file_contents(fp);
		if(fp == NULL){
			printf("\n%s don't exist\n\n",argv[1]);
			exit(0);
		}
		//fclose(fp);
	}else{
		printf("\nwrong input, usage : ./bytecode -c myfile.txt\n OR SEE INSTRUCIONS\n");
		exit(0);
	}

	//file opened, write data to stream and finally to file on save.
	// i -> insert
	// q -> quit
	// wq -> save and quit
	// u -> undo
	// yc -> copies current line
	// yp -> paste copied line

	char *input = (char*)malloc(sizeof(char)*MAX_NAME);
	printf("\n:");
	scanf("%s",input);
	//convert input string to integer sequences
	int inp = convert_to_integer(store_input_vec,input);
	while(flag==1){
		switch(inp){
			case 1 :
				//add
				list_store = add();//
				if(list_store[1].size() == 0){
					printf("\nwrite operation failed!!!\n");
				}else{
					data_input_flag=1;
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
				//space before %c -> to wait for input, because by default it is taking new line;
				scanf(" %c",ch_check);
				if(*ch_check == 'Y' || *ch_check =='y'){
					flag = 0;
				}else if(*ch_check == 'n' || *ch_check == 'N'){
					printf("\nsaving the contents of file!\n");
					if(data_input_flag == 1){
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
						printf("\n\t\t empty file saved!!!\n\n");
					}
				}else{
					printf("\ncare for your data\nenter correct choice next time\nexiting...\n\n");
					delete_file(file_name);
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
						//int size = list_store[0].size();
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
					print_message();
					/*
					for (list<string>::reverse_iterator i = list_store[1].rbegin(); i != list_store[1].rend(); ++i){
				        cout << *i << endl;
				    }*/
					for(list<string> :: reverse_iterator i= list_store[0].rbegin();i!=list_store[0].rend();++i){
						cout<< *i <<endl;
					}
				}else{
					printf("\nnothing to undo!\n");
				}
				break;
			case 5:
				//option yp -> copies current line;
				current_copy_line = list_store[0].front();
				cout<<"\""<<current_copy_line<<"\" copied\n\n";
				break;
			case 6:
				//option yp -> paste the copied line
				list_store[0].push_front(current_copy_line);
				//also store this in undo_list word by word;
				list_store[1] =  insert_by_token_into_list(list_store[1],current_copy_line);
				system("clear");
				print_message();
				printf("\npaste operation successfull!!!\n\n");
				for(list<string> :: reverse_iterator i= list_store[0].rbegin();i!=list_store[0].rend();++i){
					cout<< *i <<endl;
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
			inp=convert_to_integer(store_input_vec,input);
		}
	}
	printf("\n\n");
	return 0;
}
