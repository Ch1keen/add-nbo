#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "meta.h"

int main(int argc, char** argv) {
    uint32_t first;
    uint32_t second;

    // Phase 1: Check weather argv[] is ready
    if(argc != 3) {
        usageDisplay(argv[0]);
	exit(0);
    }

    // Phase 2: Check whether file is ready or not
    FILE* firstFile  = fopen(argv[1], "r");
    FILE* secondFile = fopen(argv[2], "r");

    uint32_t tmp;
    if(!fread(&first, 4, 1, firstFile)) {
	puts("No streams from firstFile");
	return 0;
    }
    if(!fread(&second, 4, 1, secondFile)) {
	puts("No streams from secondFile");
	return 0;
    }

    
    // Phase 3: Byte Conversion
    first = htonl(first);
    second = htonl(second);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", first, first, second, second, first+second, first+second);

    // Phase 4: Closing
    fclose(firstFile);
    fclose(secondFile);
    return 0;
}
