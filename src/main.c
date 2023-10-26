#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "log.h"
#include "text_processing.h"
#include "datastructures.h"

#define SENTENCE_SPLITTERS ".?!;"

void printHelp();
void processInput();
void userInputProcessing(int nextMove, Text *text);

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    logInfo("%s", "Course work for option 5.11, created by Egor Grebnev.");
    processInput();
    return 0;
}
void userInputProcessing(int nextMove, Text *text)
{
    switch (nextMove)
    {
    case 0:
        printText(text);
        break;
    case 1:
        findSubStr(text);
        break;
    case 2:
        sortTextByCyrillic(text);
        printText(text);
        break;
    case 3:
        removeUpperCaseLettersText(text);
        printText(text);
        break;
    case 4:
        removeWithoutSpecialChars(text);
        printText(text);
        break;
    default:
        printf("\033[1;33mError:\033[0m\033[91m%s\033[0m", "Undefined function, try 0-5\n");
        break;
    }
}
void processInput()
{
    char charMove = getchar();

    if (isdigit(charMove))
    {
        int intMove = charMove - '0';
        if (intMove != 5)
        {
            Text *text = createTextStruct(SENTENCE_SPLITTERS);
            userInputProcessing(intMove, text);
            freeText(text);
            return;
        }
        printHelp();
        return;
    }

    printf("\033[1;33mError:\033[0m\033[91m%s\033[0m", "Print numeric function\n");
}
void printHelp()
{
    printf("\033[1;34mСправка по функциям:\033[0m\n");
    printf("\033[1;33m0. Базовый вывод\033[0m - \033[1;37mвывод текста после первичной обязательной обработки.\033[0m\n");
    printf("\033[1;33m1. Поиск подстроки по формату\033[0m - \033[1;37mДля каждой подстроки в тексте, задающей время вида “часы:минуты”, вывести номер предложения в котором она  встречается и количество минут до текущего времени (время, в которое начала выполняться данная задача).\033[0m\n");
    printf("\033[1;33m2. Удаление заглавных букв\033[0m - \033[1;37mВ каждом предложении удалить все заглавные латинские буквы.\033[0m\n");
    printf("\033[1;33m3. Сортировка\033[0m - \033[1;37mОтсортировать предложения по уменьшению количеству кириллических букв.\033[0m\n");
    printf("\033[1;33m4. Удаление предложений\033[0m - \033[1;37mУдалить все предложения в которых нет специальных символов.\033[0m\n");
    printf("\033[1;33m5. Справка\033[0m - \033[1;37mВывод справки по функциям.\033[0m\n");
}