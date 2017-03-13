#include "declaration.h"
#include "file_handler.h"

int convert_to_integer(char input[]){
	int ans = 0;
	vector<string> vec;
	vec.push_back("i");
	vec.push_back("q");
	vec.push_back("wq");
	string s = input;
	if(s==vec[0]) ans=1;
	else if(s==vec[1]) ans=2;
	else if(s==vec[2]) ans=3;
	else ans = 0;
	return ans;
}

int main(int argc, char *argv[]){
	printf("\n\t\tHello world!!!\n\n");
	int flag=1;
	//check for the no. of arguments
	// for creating new file -> ./a.out -c myfile.txt
	if(argc == 3){
		if(strcmp(argv[1],"-c") == 0){
			//create new file
			char *per = (char*)malloc(sizeof(char) * MAX_NAME);
			strcat(per,"w+");
			FILE *fp = open_file(argv[2],per);

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
				break;
			case 2 :
				// save and exit
				flag=0;
				break;
			case 3:
				//exit;
				flag=0;
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
