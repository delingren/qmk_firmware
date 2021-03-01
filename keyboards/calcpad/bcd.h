#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifndef FRACTION_DIGITS
#define FRACTION_DIGITS 8
#endif

// We adopt Knuth's convention. I.e. the decimal point is to the left of the
// fraction.
struct bcd_t {
  int8_t sign;                       // 1 or -1
  uint8_t fraction[FRACTION_DIGITS]; // BCD
  int exponent;
};

bool bcd_is_normalized(struct bcd_t);
char *bcd_to_string(char *, struct bcd_t);
struct bcd_t bcd_add(struct bcd_t, struct bcd_t);
