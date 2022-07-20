#include <stdio.h>
#include "meta.h"

void usageDisplay(char* programName) {
    puts("Usage:");
    printf("syntax : %s <file1> <file2>\n", programName);
    printf("sample : %s a.bin c.bin\n", programName);

    return;
}

