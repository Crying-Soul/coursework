#include <stdlib.h>
#include "structure_functions.h"
#include <stdio.h>
void printText(Text text){
    for (int i = 0; i < text.num_sentences; ++i) {
        printf("Sentence №%d:%s\n", (i+1), text.sentences[i].sentence);
    }
}

void freeText(Text text) {
    for (int i = 0; i < text.num_sentences; ++i) {
        free(text.sentences[i].sentence);
    }
    free(text.sentences);
}