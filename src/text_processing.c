#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include "text_processing.h"
#include "datastructures.h"

#define MEMORY_CHUNK 20;

char *getTextInput()
{
	int end = 0, size = 0, capacity = MEMORY_CHUNK;
	char ch;
	char *text = malloc(capacity * sizeof(char));
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
			}
			text[size++] = ch;
		}
	}
	text = realloc(text, (size + 1) * sizeof(char));
	text[size] = '\0';
	return text;
}

void removeUpperCaseLettersSentence(Sentence *sentence)
{
	char *input = sentence->sentence;
	int j = 0;
	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (!isupper(input[i]) || !isalpha(input[i]))
		{
			input[j++] = input[i];
		}
	}
	input[j] = '\0';
}

void removeUpperCaseLettersText(Text *text)
{
	for (int i = 0; i < text->num_sentences; ++i)
	{
		removeUpperCaseLettersSentence(&(text->sentences[i]));
	}
}

void removeRepeats(Text *text)
{
	int newSize = text->num_sentences;
	for (int i = 0; i < newSize; ++i)
	{
		for (int j = i + 1; j < newSize; ++j)
		{
			if (strcasecmp(text->sentences[i].sentence, text->sentences[j].sentence) == 0)
			{
				free(text->sentences[j].sentence);
				for (int k = j; k < newSize - 1; ++k)
				{
					text->sentences[k] = text->sentences[k + 1];
				}
				--newSize;
				--j;
			}
		}
	}

	text->num_sentences = newSize;
}
void removeLeadSpaces(char *str)
{
	char *start = str;
	while (*start && (*start == ' ' || *start == '\t'))
	{
		start++;
	}
	memmove(str, start, strlen(start) + 1);
}

Text split_text(char *raw_text, const char *spliters)
{
	int end_index = 0, chr_counter = 0;
	Text text;
	text.num_sentences = 0;
	text.sentences = malloc(sizeof(Sentence));

	for (size_t i = 0; i <= strlen(raw_text); i++)
	{
		if (strchr(spliters, raw_text[i]) != NULL)
		{

			text.num_sentences++;

			text.sentences = realloc(text.sentences, text.num_sentences * sizeof(Sentence));
			text.sentences[text.num_sentences - 1].sentence = malloc((end_index + 1) * sizeof(char));

			chr_counter = 0;

			for (int j = end_index; j >= 0; j--)
			{
				text.sentences[text.num_sentences - 1].sentence[chr_counter++] = raw_text[i - j];
			}
			text.sentences[text.num_sentences - 1].sentence[chr_counter] = '\0';
			removeLeadSpaces(text.sentences[text.num_sentences - 1].sentence);
			
			end_index = 0;
			continue;
		}
		end_index++;
	}
	printf("\n");
	printf("\n");
	return text;
}

Text *createTextStruct(const char *spliters)
{
	char *raw_text = getTextInput();
	Text *text = malloc(sizeof(Text));

	*text = split_text(raw_text, spliters);
	removeRepeats(text);

	free(raw_text);
	return text;
}

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
int compareSentences(const void *sentenceA, const void *sentenceB)
{
	return cyrillicCounter((const Sentence *)sentenceB) - cyrillicCounter((const Sentence *)sentenceA);
}

void sortTextByCyrillic(Text *text)
{
	qsort(text->sentences, text->num_sentences, sizeof(Sentence), compareSentences);
}

void removeWithoutSpecialChars(Text *text)
{
	int validSentenceCount = 0;
	const char *specialChars = "!@#$%^&*()_+-={}[]|\\:;\"'<>,?/";
	for (int i = 0; i < text->num_sentences; ++i)
	{
		if (strpbrk(text->sentences[i].sentence, specialChars) != NULL)
		{

			text->sentences[validSentenceCount] = text->sentences[i];
			validSentenceCount++;
		}
		else
		{

			free(text->sentences[i].sentence);
		}
	}

	text->num_sentences = validSentenceCount;
	text->sentences = realloc(text->sentences, sizeof(Sentence) * validSentenceCount);
}
void findSubStr(Text *text)
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	int currentMinutes = localTime->tm_hour * 60 + localTime->tm_min;

	for (int i = 0; i < text->num_sentences; i++)
	{
		char *sentence = text->sentences[i].sentence;
		size_t sentenceLength = strlen(sentence);

		if (sentenceLength < 5)
			continue;

		for (size_t j = 0; j < sentenceLength - 4; j++)
		{
			if (isdigit(sentence[j]) && isdigit(sentence[j + 1]) &&
				sentence[j + 2] == ':' &&
				isdigit(sentence[j + 3]) && isdigit(sentence[j + 4]))
			{

				int hours = (sentence[j] - '0') * 10 + (sentence[j + 1] - '0');
				int mins = (sentence[j + 3] - '0') * 10 + (sentence[j + 4] - '0');

				if (hours >= 0 && hours <= 23 && mins >= 0 && mins <= 59)
				{
					int totalMinutes = hours * 60 + mins;
					printf("Подстрока в предложении %d, минут до текущего времени: %d\n", i + 1, totalMinutes - currentMinutes);
				}
				else
					printf("\033[1;33mError:\033[0m \033[91mIncorrect time format in %d sentences\033[0m\n", i + 1);

				break;
			}
		}
	}
}
