#ifndef SRC_UNIT_S21_TEST_MATH_H_
#define SRC_UNIT_S21_TEST_MATH_H_

#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

Suite *suite_s21_abs();
Suite *suite_s21_fabs();
Suite *suite_s21_floor();
Suite *suite_s21_sin();
Suite *suite_s21_exp();
Suite *suite_s21_acos();
Suite *suite_s21_asin();
Suite *suite_s21_atan();
Suite *suite_s21_ceil();
Suite *suite_s21_cos();
Suite *suite_s21_fmod();
Suite *suite_s21_log();
Suite *suite_s21_pow();
Suite *suite_s21_sqrt();
Suite *suite_s21_tan();

#endif  // SRC_UNIT_S21_TEST_MATH_H_
