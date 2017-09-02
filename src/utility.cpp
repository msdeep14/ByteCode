/*
author - mandeep singh
created - 03 sept 2017
COPYRIGHT mandeep singh
*/

#include "utility.h"

void printHelpInstructions(){
    printf("\n\t\t\t\tHelp Instructions\n\n");
    printf("1. Create new file\n ./bytecode -c filename\n\n2. Open already existing file\n./bytecode filename\n\n3. Read contents of file\n./bytecode -r filename\n\n4. File editing operations\n:i - insert\nescape - exit insert operation\n:wq - save and exit\n:q - exit without saving\n:u - undo\n:yc - copy current line\n:yp - paste copied line\n\n");
}
