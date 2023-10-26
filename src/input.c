#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "memory.h"
#define MEMORY_CHUNK 20;
char *getTextInput()
{
	int end = 0, size = 0, capacity = MEMORY_CHUNK;
	char ch;
	char *text = malloc(capacity * sizeof(char));
	checkMemoryAllocation(text, "Insufficient memory for text structure");
	while ((ch = getchar()) && (end < 2))
	{
		if (ch == '\n')
			end++;

		else
		{
			end = 0;
			if (size >= capacity - 1)
			{
				capacity += MEMORY_CHUNK;
				text = realloc(text, capacity * sizeof(char));
				checkMemoryAllocation(text, "Insufficient memory for text structure");
			}
			text[size++] = ch;
		}
	}
	text = realloc(text, (size + 1) * sizeof(char));
	checkMemoryAllocation(text, "Insufficient memory for text structure");
	text[size] = '\0';
	return text;
}
