#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
/**
 * @file polynomial.h
 *
 * @brief calculation of polynomial over F<sub>2</sub> of degree less than 128.
 *
 * Polynomial calculation for TinyMT jump function.
 * polynomial_power_mod is used in jump32.c and jump64.c
 *
 * @author Mutsuo Saito (Hiroshima University)
 * @author Makoto Matsumoto (The University of Tokyo)
 *
 * Copyright (C) 2011 Mutsuo Saito, Makoto Matsumoto,
 * Hiroshima University and University of Tokyo.
 * All rights reserved.
 *
 * The 3-clause BSD License is applied to this software, see
 * LICENSE.txt
 */

#include <stdint.h>
#include <inttypes.h>

/**
 * Polynomial over F<sub>2</sub>, whose degree is equal to or less than 128.
 * LSB of ar[0], i.e. ar[0] & 1, represent constant
 */
struct POLYNOMIAL128_T {
    uint64_t ar[2];
};

typedef struct POLYNOMIAL128_T polynomial;

void strtop(polynomial * poly, const char * str);
void polynomial_power_mod(polynomial * dist,
			  const polynomial * x,
			  uint64_t lower_power,
			  uint64_t upper_power,
			  const polynomial * mod);
#endif
