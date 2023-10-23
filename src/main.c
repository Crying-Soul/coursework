#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "text_processing.h"
#include "structure_functions.h"
#include "datastructures.h"

#define SENTENCE_SPLITTERS ".?!;"




int main(void) {
	
	int nextMove;
    printf("\033[92m%s\033[0m\n", "Course work for option 5.11, created by Egor Grebnev.");
    scanf("%d", &nextMove);
	
	
    
    switch (nextMove)
    {
        case 0:
            printText(createTextStruct(SENTENCE_SPLITTERS));
            break;
        case 1:
            printf("In process...");
            break;
        case 2:
            printf("In process...");
            break;
        case 3:
            Text* text = createTextStruct(SENTENCE_SPLITTERS);
            removeUpperCaseLettersText(text);
            printText(text);
            break;
        case 4:
            printf("In process...");
            break;
        case 5:
            printf("In process...");
            break;
        default:
            printf("Error: \033[91m%s\033[0m","Undefined function, try 0-5\n");
            break;
    }

	// freeText(text);
	// free(raw_text);
	return 0;
}


