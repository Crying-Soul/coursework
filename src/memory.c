#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "log.h"

void checkMemoryAllocation(void *ptr, const wchar_t *errorMessage) {
    if (ptr == NULL) {
        fwprintf(stderr, L"Error: %ls\n", errorMessage);
        logErr(errorMessage);
        exit(EXIT_FAILURE);
    }
}