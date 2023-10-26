#ifndef TEXTPROCESSING_H
#define TEXTPROCESSING_H

#include "structures.h"

void removeRepeats(Text* text);
void removeLeadSpaces(char* str);
void removeUpperCaseLettersSentence(Sentence* sentence);
void removeUpperCaseLettersText(Text* text);
Text split_text(char* raw_text, const char* spliters);
Text* createTextStruct(const char* spliters);
void removeWithoutSpecialChars(Text* text);
void findSubStr(Text* text);

#endif