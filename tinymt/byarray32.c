/**
 * @file byarray32.c
 *
 * @brief Simple check program for tinymt32
 *
 * @author Kenji Rikitake (Kyoto University)
 * @author Mutsuo Saito (Hiroshima University)
 * @author Makoto Matsumoto (The University of Tokyo)
 *
 * Copyright (C) 2012 Kenji Rikitake and Kyoto University.
 * All rights reserved.
 *
 * Copyright (C) 2011 Mutsuo Saito, Makoto Matsumoto,
 * Hiroshima University and University of Tokyo.
 * All rights reserved.
 *
 * The 3-clause BSD License is applied to this software, see
 * LICENSE.txt
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "tinymt32.h"

void state_dump(tinymt32_t *);

void state_dump(tinymt32_t *r) {
	printf("status: %u %u %u %u\n",
		r->status[0], r->status[1], r->status[2], r->status[3]);
}	


int main(int argc, char * argv[]) {
    if (argc < 4) {
	printf("%s mat1 mat2 tmat [seed]\n", argv[0]);
	return -1;
    }
    tinymt32_t tinymt;
    tinymt.mat1 = strtoul(argv[1], NULL, 16);
    tinymt.mat2 = strtoul(argv[2], NULL, 16);
    tinymt.tmat = strtoul(argv[3], NULL, 16);
    int seed = 1;
    uint32_t seed_array[4];

    if (argc >= 5) {
	seed = strtol(argv[4], NULL, 0);
    }
    printf("tinymt32 0x%08"PRIx32, tinymt.mat1);
    printf(" 0x%08"PRIx32, tinymt.mat2);
    printf(" 0x%08"PRIx32, tinymt.tmat);
    for (int n = 0; n < 4; n++) {
        seed_array[n] = seed + n;
    }
    printf(" seed array = [%d, %d, %d, %d]\n", 
        seed_array[0],
        seed_array[1],
        seed_array[2],
        seed_array[3]);
    tinymt32_init_by_array(&tinymt, seed_array, 4);
    state_dump(&tinymt);
    printf("mat1 %u ", tinymt.mat1);
    printf("mat2 %u ", tinymt.mat2);
    printf("tmat %u\n", tinymt.tmat);
    for (int i = 0; i < 10; i++) {
	    printf("%"PRIu32"\n", tinymt32_generate_uint32(&tinymt));
	    state_dump(&tinymt);
    }
}
