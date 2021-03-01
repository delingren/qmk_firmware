#include "gtest/gtest.h"

extern "C" {
    #include "../bcd.h"
}

char buffer[50];

TEST(print, one_digit) {
  struct bcd_t n1 = {1, {1}, 1};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "1");
}

TEST(print, a_few_digits) {
  struct bcd_t n1 = {1, {1, 2, 3, 4}, 2};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "12.34");
}

TEST(print, decimal_point) {
  struct bcd_t n1 = {1, {1}, 0};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "0.1");
}

TEST(print, decimal_point_and_leading_zeroes) {
  struct bcd_t n1 = {1, {1}, -2};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "0.001");
}

TEST(print, trailing_zeroes_after_decimal_point) {
  struct bcd_t n1 = {1, {1, 0, 0, 0, 0, 0, 0, 0}, -2};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "0.001");
}

TEST(print, trailing_zeroes_right_after_decimal_point) {
  struct bcd_t n1 = {1, {1, 0, 2, 0, 0, 0, 0, 0}, 3};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "102");
}

TEST(print, zeroes_in_the_middle) {
  struct bcd_t n1 = {1, {1, 0, 2, 0, 0, 3, 0, 0}, -2};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "0.00102003");
}


TEST(print, trailing_zeroes_whole_int) {
  struct bcd_t n1 = {1, {1, 0, 2, 0, 0, 3, 0, 0}, 8};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "10200300");
}

TEST(print, trailing_zeroes_both_parts) {
  struct bcd_t n1 = {1, {1, 0, 2, 0, 0, 3, 0, 0}, 5};
  bcd_to_string(buffer, n1);

  ASSERT_STREQ(buffer, "10200.3");
}
