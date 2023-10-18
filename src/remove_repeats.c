#include <stdlib.h>
#include <string.h>
#include "remove_repeats.h"
void remove_repeats(Text* text) {
    int newSize = text->num_sentences;
    for (int i = 0; i < newSize; ++i) {
        for (int j = i + 1; j < newSize; ++j) {
            if (strcasecmp(text->sentences[i].sentence, text->sentences[j].sentence) == 0) {
                free(text->sentences[j].sentence);
                text->sentences[j].sentence = text->sentences[--newSize].sentence;
                --j;
            }
        }
    }
    text->num_sentences = newSize;
}