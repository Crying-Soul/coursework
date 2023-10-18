#include <stdlib.h>
#include <stdio.h>
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
