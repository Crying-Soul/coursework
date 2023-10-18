#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "get_text_input.h"
#include "remove_lead_spaces.h"
#include "remove_repeats.h"
#include "datastructures.h"


Text split_text(char* raw_text, const char* spliters);
void free_text(Text text);
void print_text(Text text);
void remove_repeats(Text* text);

int main(void) {
	const char* spliters = ".?!;";
	printf("%s\n", "Course work for option 5.11, created by Egor Grebnev.");
	char* raw_text = get_text_input();

	Text text = split_text(raw_text, spliters);

    remove_repeats(&text);

    print_text(text);
	
	free_text(text);
	free(raw_text);
	return 0;
}


Text split_text(char *raw_text, const char *spliters) {
    int end_index = 0;
    Text text;
    text.num_sentences = 0;
    text.sentences = malloc(sizeof(Sentence));

    for (int i = 0; i <= (int)strlen(raw_text); i++) {
        if (strchr(spliters, raw_text[i]) != NULL || raw_text[i] == '\0') {
            text.num_sentences++;

            text.sentences = realloc(text.sentences, text.num_sentences * sizeof(Sentence));
            text.sentences[text.num_sentences - 1].sentence = malloc((end_index + 2) * sizeof(char));

            int chr_counter = 0;
            for (int j = end_index; j >= 0; j--) {
                text.sentences[text.num_sentences - 1].sentence[chr_counter++] = raw_text[i - j];
            }
            text.sentences[text.num_sentences - 1].sentence[chr_counter] = '\0';
            remove_lead_spaces(text.sentences[text.num_sentences - 1].sentence);
            end_index = 0;
            continue;
        }
        end_index++;
    }

    text.num_sentences = text.num_sentences - 1;
    return text;
}

void print_text(Text text){
    for (int i = 0; i < text.num_sentences; ++i) {
        printf("Sentence №%d:%s\n", (i+1), text.sentences[i].sentence);
    }
}

void free_text(Text text) {
    for (int i = 0; i < text.num_sentences; ++i) {
        free(text.sentences[i].sentence);
    }
    free(text.sentences);
}