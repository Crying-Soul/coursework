#include <stdio.h>
#include "text_processing.h"
#include "datastructures.h"

#define SENTENCE_SPLITTERS ".?!;"
void printHelp();
void userInputProcessing(int nextMove, Text *text);
int main(void)
{
    int nextMove;
    printf("\033[92m%s\033[0m\n", "Course work for option 5.11, created by Egor Grebnev.");
    scanf("%d", &nextMove);

    if (nextMove != 5)
    {
        Text *text = createTextStruct(SENTENCE_SPLITTERS);
        userInputProcessing(nextMove, text);
        freeText(text);
        return 0;
    }
    printHelp();
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
        printf("In process...");
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
        removeWithSpecialChars(text);
        printText(text);
        break;
    default:
        printf("Error: \033[91m%s\033[0m", "Undefined function, try 0-5\n");
        break;
    }
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