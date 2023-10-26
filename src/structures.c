#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "log.h"

void printText(Text* text){
    for (int i = 0; i < text->num_sentences - 1; ++i) {
        logInfoDefault("Sentence №%d:%s", (i+1), text->sentences[i].sentence);
    }
}

void freeText(Text* text) {
    for (int i = 0; i < text->num_sentences - 1; ++i) {
        free(text->sentences[i].sentence);
    }
    free(text->sentences);
}