#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** split_text(char* text, int* num_sentences, const char* spliters);
void remove_lead_spaces(char* str);
char* get_text_input();

int main(void) {
	int num_sentences = 0;
	const char* spliters = ".?!";
	printf("%s\n", "Course work for option 5.11, created by Egor Grebnev.");
	char* text = get_text_input();
	char** splitted_text = split_text(text, &num_sentences, spliters);


	for (int i = 0; i < num_sentences; i++) {
		printf("Предложение %d:%s\n",i+1, splitted_text[i]);
		free(splitted_text[i]);
	}
	//       printf("Количество предложений до %d и количество предложений после %d\n", num_sentences - 1, result_num_sentences - 1);
	free(splitted_text);
	free(text);
	return 0;
}

char* get_text_input() {
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

char** split_text(char* text, int* num_sentences, const char* spliters) {
	int count_sentences = 0;
	int end_index = 0;
	char** splitted_text = malloc(sizeof(char*));

	for (int i = 0; i <= (int)strlen(text); i++) {
		if (strchr(spliters, text[i]) != NULL) {
			count_sentences++;

			splitted_text = realloc(splitted_text, count_sentences * sizeof(char*));
			splitted_text[count_sentences - 1] = malloc((end_index + 2) * sizeof(char));

			int chr_counter = 0;
			for (int j = end_index; j >= 0; j--) {
				splitted_text[count_sentences - 1][chr_counter++] = text[i - j];
			}
			splitted_text[count_sentences - 1][chr_counter] = '\0';
			remove_lead_spaces(splitted_text[count_sentences - 1]);
			end_index = 0;
			continue;
		}
		end_index++;
	}

	*num_sentences = count_sentences - 1;
	return splitted_text;
}
void remove_lead_spaces(char* str) {
        char* start = str;

        while (*start && (*start == ' ' || *start == '\t' ||  *start == '\n')) {
                start++;
        }

        memmove(str, start, strlen(start) + 1);
}
