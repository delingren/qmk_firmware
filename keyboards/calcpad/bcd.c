#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bcd.h"

int imin(int x, int y) { return x > y ? y : x; }

int imax(int x, int y) { return x > y ? x : y; }

bool bcd_is_normalized(struct bcd_t n) {
  // if the fraction is 0, the exponent is also 0
  // if the fraction is not 0, its most sigficant digit is not 0
  return n.fraction[0] == 0 && n.exponent == 0 || n.fraction[0] > 0;
}

char *bcd_to_string(char *buffer, struct bcd_t n) {
  char *p = buffer;
  unsigned int pending_zeroes = 0;

  if (n.sign == -1) {
    *p++ = '-';
  }

  if (n.exponent <= 0) {
    // leading 0 before the decimal point
    *p++ = '0';
  }

  for (int i = imin(n.exponent, 0); i < imax(n.exponent + 1, FRACTION_DIGITS);
       i++) {
    uint8_t digit = (i < 0 || i >= FRACTION_DIGITS) ? 0 : n.fraction[i];

    if (i >= n.exponent) {
      if (digit == 0) {
        // a '0' after the decimal point is only printed if there is a non-zero
        // digit after it. i.e. it's not part of trailing zeros.
        pending_zeroes++;
        continue;
      }

      if (digit > 0 && pending_zeroes > 0) {
        // if there is any pending zeroes, now we need to print them, as well as
        // the potentially pending decimal point
        for (int j = 0; j < pending_zeroes; j++) {
          if (i - pending_zeroes + j == n.exponent) {
            *p++ = '.';
          }
          *p++ = '0';
        }
        pending_zeroes = 0;
      }
    }

    if (i == n.exponent) {
      *p++ = '.';
    }
    *p++ = '0' + digit;
  }

  *p++ = 0;
  return buffer;
}

int bcd_compare_abs(struct bcd_t a, struct bcd_t b) {
  if (a.fraction[0] == 0) {
    return b.fraction[0] == 0 ? 0 : -1;
  }

  if (b.fraction[0] == 0) {
    return 1;
  }

  if (a.exponent > b.exponent) {
    return 1;
  }

  if (a.exponent < b.exponent) {
    return -1;
  }

  for (int i = 0; i < FRACTION_DIGITS; i++) {
    int fa = a.fraction[i];
    int fb = b.fraction[i];

    if (fa > fb) {
      return 1;
    }

    if (fa < fb) {
      return -1;
    }
  }
  return 0;
}

struct bcd_t bcd_add(struct bcd_t a, struct bcd_t b) {
  struct bcd_t *u;
  struct bcd_t *v;
  struct bcd_t result;

  int ed; // exponent difference

  // a buffer for intermediate result
  uint8_t buffer[FRACTION_DIGITS * 2 + 2];

  if (bcd_compare_abs(a, b) >= 0) {
    u = &a;
    v = &b;
  } else {
    u = &b;
    v = &a;
  }

  // |u| >= |v|
  result.sign = u->sign;
  result.exponent = u->exponent + 1;
  ed = u->exponent - v->exponent;

  // shift u to the right 1 digit
  // shift v to the right ed+1 digits
  // leaving one digit to the left for the carry

  if (ed >= FRACTION_DIGITS + 2) {
    // v is too small. set result to u
    memcpy(result.fraction, u->fraction, sizeof(u->fraction));
  } else {
    uint8_t carry_borrow = 0;
    bool same_sign = u->sign == v->sign;
    int most_significant_digit = -1;

    // add u and v, digit by digit, from right to left
    // at the same time, keep track of the position of the most significant
    // digit for normalization later
    for (int i = FRACTION_DIGITS + ed; i >= 1; i--) {
      uint8_t fu, fv;
      fu = i <= FRACTION_DIGITS ? u->fraction[i - 1] : 0;
      fv = i >= ed + 1 ? v->fraction[i - ed - 1] : 0;

      buffer[i] = same_sign ? fu + fv + carry_borrow : fu - fv + carry_borrow;
      if (buffer[i] > 9) {
        buffer[i] -= 10;
        carry_borrow = 1;
      } else if (buffer[i] < 0) {
        buffer[i] += 10;
        carry_borrow = -1;
      } else {
        carry_borrow = 0;
      }

      if (buffer[i] > 0) {
        most_significant_digit = i;
      }
    }

    // carry_borrow should be 0 or 1, but not -1 since |u| > |v|
    buffer[0] = carry_borrow;
    if (carry_borrow > 0) {
      most_significant_digit = 0;
    }

    if (most_significant_digit == -1) {
      // result is 0. set exponent to 0 and sign to positive
      result.exponent = 0;
      result.sign = 1;
    } else {
      result.exponent -= most_significant_digit;
      for (int i = 0; i < FRACTION_DIGITS; i++) {
        uint8_t w = i + most_significant_digit < FRACTION_DIGITS * 2 + 2
                        ? buffer[i + most_significant_digit]
                        : 0;
        result.fraction[i] = w;
      }
    }
  }

  return result;
}
