#include "counting.h"

int cyrillicCounter(const Sentence *sentence)
{
	int counter = 0;
	const char *str = sentence->sentence;
	while (*str)
	{
		if ((*str & 0xC0) == 0xC0 && (*(str + 1) & 0x80) == 0x80)
			counter++;
		str++;
	}

	return counter / 2;
}