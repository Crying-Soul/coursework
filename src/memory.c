#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "log.h"

void checkMemoryAllocation(void *ptr, const char *errorMessage) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: %s\n", errorMessage);
		logErr("%s", errorMessage);
        exit(EXIT_FAILURE);
    }
}