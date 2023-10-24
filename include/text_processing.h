#include "datastructures.h"
char* getTextInput();
void removeRepeats(Text* text);
void removeLeadSpaces(char* str);
void removeUpperCaseLettersSentence(Sentence* sentence);
void removeUpperCaseLettersText(Text* text);
Text split_text(char* raw_text, const char* spliters);
Text* createTextStruct(const char* spliters);
void sortTextByCyrillic(Text* text);
int cyrillicCounter(Sentence* sentence);
