#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "text_processing.h"
char* getTextInput() {
	int capacity = 1, end=0, size = 0;
	char ch;
	char* text = malloc(capacity * sizeof(char));
	while ((ch = getchar()) && (end < 2)) {
		if (ch == '\n') 
			end++;
		
		else {
			end = 0;
			if (size >= capacity) {
				capacity *= 2;
				text = realloc(text, capacity * sizeof(char));
			}
			text[size++] = ch;
		} 
	}
	text = realloc(text, (capacity+1)*sizeof(char));
	return text;
}

void removeUpperCaseLettersSentence(Sentence* sentence) {
    char* input = sentence->sentence;
    int j = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isupper(input[i]) || !isalpha(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

void removeUpperCaseLettersText(Text* text) {
    for (int i = 0; i < text->num_sentences; ++i) {
        removeUpperCaseLettersSentence(&(text->sentences[i]));
    }
}

void removeRepeats(Text* text) {
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


void removeLeadSpaces(char* str) {
        char* start = str;
        while (*start && (*start == ' ' || *start == '\t' ||  *start == '\n')) {
                start++;
        }
        memmove(str, start, strlen(start) + 1);
}