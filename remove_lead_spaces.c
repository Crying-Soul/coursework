#include <string.h>

void remove_lead_spaces(char* str) {
        char* start = str;
        while (*start && (*start == ' ' || *start == '\t' ||  *start == '\n')) {
                start++;
        }
        memmove(str, start, strlen(start) + 1);
}