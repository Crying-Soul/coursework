#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include "log.h"
#include "txtprocessing.h"
#include "memory.h"
#include "input.h"

void removeUpperCaseLettersSentence(Sentence *sentence)
{
	wchar_t *input = sentence->sentence;
	int j = 0;
	for (int i = 0; input[i] != L'\0'; ++i)
	{
		if (!iswupper(input[i]) || !iswalpha(input[i]))
		{
			input[j++] = input[i];
		}
	}
	input[j] = L'\0';
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
			if (wcscasecmp(text->sentences[i].sentence, text->sentences[j].sentence) == 0)
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

void removeLeadSpaces(wchar_t *str)
{
	wchar_t *start = str;
	while (*start && (iswspace(*start) || *start == L'\t'))
	{
		start++;
	}
	wmemmove(str, start, wcslen(start) + 1);
}
Text split_text(const wchar_t *raw_text, const wchar_t *spliters)
{
	int end_index = 0, chr_counter = 0;
	Text text;
	text.num_sentences = 0;
	text.sentences = (Sentence *)malloc(sizeof(Sentence));
	checkMemoryAllocation(text.sentences, L"Insufficient memory for text structure");

	for (size_t i = 0; i < wcslen(raw_text); i++)
	{
		if (wcschr(spliters, raw_text[i]) != NULL)
		{

			text.num_sentences++;

			text.sentences = (Sentence *)realloc(text.sentences, text.num_sentences * sizeof(Sentence));
			text.sentences[text.num_sentences - 1].sentence = (wchar_t *)malloc((end_index + 2) * sizeof(wchar_t));
			checkMemoryAllocation(text.sentences[text.num_sentences - 1].sentence, L"Insufficient memory for text structure");

			chr_counter = 0;

			for (int j = end_index; j >= 0; j--)
			{
				text.sentences[text.num_sentences - 1].sentence[chr_counter++] = raw_text[i - j];
			}
			text.sentences[text.num_sentences - 1].sentence[chr_counter] = L'\0';
			removeLeadSpaces(text.sentences[text.num_sentences - 1].sentence);

			end_index = 0;
			continue;
		}
		end_index++;
	}

	return text;
}

Text *createTextStruct(const wchar_t *spliters) {
    Text *text = malloc(sizeof(Text));
    checkMemoryAllocation(text, L"Insufficient memory for text structure");

    wchar_t *raw_text = getTextInput();
    *text = split_text(raw_text, spliters);
    removeRepeats(text);
    free(raw_text);

    return text;
}


void removeWithoutSpecialChars(Text *text)
{
	int validSentenceCount = 0;
	for (int i = 0; i < text->num_sentences; ++i)
	{
		wchar_t *sentence = text->sentences[i].sentence;
		int hasSpecialChars = 0;
		for (size_t j = 0; !hasSpecialChars && sentence[j + 1] != L'\0'; ++j)
		{
			hasSpecialChars = !iswalpha(sentence[j]) && !iswdigit(sentence[j]) && !iswspace(sentence[j]);
		}

		if (hasSpecialChars)
		{
			text->sentences[validSentenceCount++] = text->sentences[i];
		}
		else
		{
			free(text->sentences[i].sentence);
		}
	}

	text->num_sentences = validSentenceCount;
	text->sentences = realloc(text->sentences, sizeof(Sentence) * validSentenceCount);
	checkMemoryAllocation(text->sentences, L"Memory override error for text structure");
}
void findSubStr(Text *text)
{
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	int currentMinutes = localTime->tm_hour * 60 + localTime->tm_min;

	for (int i = 0; i < text->num_sentences; ++i)
	{
		wchar_t *sentence = text->sentences[i].sentence;
		size_t sentenceLength = wcslen(sentence);

		if (sentenceLength >= 5)
		{
			for (size_t j = 0; j < sentenceLength - 4; ++j)
			{
				if (iswdigit(sentence[j]) && iswdigit(sentence[j + 1]) &&
					sentence[j + 2] == L':' &&
					iswdigit(sentence[j + 3]) && iswdigit(sentence[j + 4]))
				{

					int hours = (sentence[j] - L'0') * 10 + (sentence[j + 1] - L'0');
					int mins = (sentence[j + 3] - L'0') * 10 + (sentence[j + 4] - L'0');

					if (hours >= 0 && hours <= 23 && mins >= 0 && mins <= 59)
					{
						int totalMinutes = hours * 60 + mins;
						logInfoDefault(L"Подстрока в предложении %d, минут до текущего времени: %d", i + 1, totalMinutes - currentMinutes);
					}
					else
					{
						logWarn(L"Incorrect time format in %d sentences", i + 1);
					}
					break;
				}
			}
		}
	}
}
