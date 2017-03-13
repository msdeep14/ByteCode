#include "declaration.h"
#include "file_handler.h"

int main(int argc, char *argv[]){
	printf("Hello world!!!\n\n");

	//check for the no. of arguments
	// for creating new file -> ./a.out -c myfile.txt
	if(argc == 3){
		if(strcmp(argv[1],"-c") == 0){
			//create new file
			char *per = (char*)malloc(sizeof(char) * MAX_NAME);
			strcat(per,"w+");
			FILE *fp = open_file(argv[2],per);
		}
		else{
			printf("\nwrong input, usage : ./a.out -c myfile.txt\n\n");
			exit(0);
		}
	}
	else if(argc == 2){
		char *per = (char*)malloc(sizeof(char) * MAX_NAME);
		strcat(per,"a+");
		FILE *fp = open_file(argv[2],per);
	}
	else{
		printf("\nwrong input, usage : ./a.out -c myfile.txt\n OR SEE INSTRUCIONS\n");
		exit(0);
	}

	return 0;
}
