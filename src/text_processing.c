#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
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
                text->sentences[j].sentence = text->sentences[--newSize].sentence;
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

    for (int i = 0; i <= (int)strlen(raw_text); i++)
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
        return text;
}

Text* createTextStruct(const char *spliters)
{
    char *raw_text = getTextInput();
    Text *text = (Text *)malloc(sizeof(Text)); 
    
    *text = split_text(raw_text, spliters);
    removeRepeats(text);
    
    free(raw_text); 
    return text;
}