#ifndef TEXTPROCESSING_H
#define TEXTPROCESSING_H

#include "structures.h"

void removeRepeats(Text* text);
void removeLeadSpaces(wchar_t* str);
void removeUpperCaseLettersSentence(Sentence* sentence);
void removeUpperCaseLettersText(Text* text);
Text split_text(const wchar_t *raw_text, const wchar_t *spliters);
Text* createTextStruct(const wchar_t* spliters);
void removeWithoutSpecialChars(Text* text);
void findSubStr(Text* text);

#endif