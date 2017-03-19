#include "declaration.h"
#include "file_handler.h"
#include "add.h"

int convert_to_integer(char input[]){
	int ans = 0;
	vector<string> vec;
	vec.push_back("i");
	vec.push_back("q");
	vec.push_back("wq");
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
	int flag=1,ret=0;
	list<string> ret_list;
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
			FILE *fp = open_file(argv[2],per);
			strcpy(file_name,argv[2]);
			fclose(fp);
		}
		else{
			printf("\nwrong input, usage : ./a.out -c myfile.txt\n\n");
			exit(0);
		}
	}
	//open a existing file
	else if(argc == 2){
		char *per = (char*)malloc(sizeof(char) * MAX_NAME);
		strcat(per,"a+");
		FILE *fp = open_file(argv[1],per);
		strcpy(file_name,argv[1]);
		if(fp == NULL){
			printf("\n%s don't exist\n\n",argv[1]);
			exit(0);
		}
		fclose(fp);
	}
	else{
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
				ret_list = add(file_name);//
				if(ret_list.size() == 0){
					printf("\nwrite operation failed!!!\n");
				}
				break;
			case 2 :
				// save and exit
				//do all the operations on returned list and finally write list to file on termination;
				//write_list_to_file(file_name,per,lis);
				flag=0;
				break;
			case 3:
				//exit;
				flag=0;
				break;
			case 4:
				//undo
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
