#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "memory.h"
#include <wchar.h>

#define MEMORY_CHUNK 20;

wchar_t *getTextInput()
{
	int end = 0, size = 0, capacity = MEMORY_CHUNK;
	wint_t ch;
	wchar_t *text = malloc(capacity * sizeof(wchar_t));
	checkMemoryAllocation(text, L"Insufficient memory for text structure");

	while ((ch = getwchar()) != WEOF && (end < 2))
	{
		if (ch == L'\n')
		{
			end++;
		}
		else
		{
			end = 0;
			if (size >= capacity - 1)
			{
				capacity += MEMORY_CHUNK;
				text = realloc(text, capacity * sizeof(wchar_t));
				checkMemoryAllocation(text, L"Insufficient memory for text structure");
			}
			text[size++] = ch;
		}
	}
	text[size] = L'\0';
	return realloc(text, (size + 1) * sizeof(wchar_t));
}
