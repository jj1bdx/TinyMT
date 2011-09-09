#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "tinymt32.h"
#include "jump32.h"

int main(int argc, char *argv[]) {
    tinymt32_t tiny[5];
    char * poly = "d8524022ed8dff4a8dcc50c798faba43";
    // set parameters
    tiny[0].mat1 = 0x8f7011ee;
    tiny[0].mat2 = 0xfc78ff1f;
    tiny[0].tmat = 0x3793fdff;
    // initialize
    tinymt32_init(&tiny[0], 1);
    int i, j;

    for (i = 1; i < 5; i++) {
	// copy
	tiny[i] = tiny[0];
	// jump i * 2^64
	tinymt32_jump(&tiny[i], 0, i, poly);
    }

    for(i = 0; i < 20; i++) {
	for (j = 0; j < 5; j++) {
	    printf("%10"PRIu32" ", tinymt32_generate_uint32(&tiny[j]));
	}
	printf("\n");
    }
    return 0;
}
