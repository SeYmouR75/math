#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1.0;

  if (exp == 0) {
    result = 1.0;
  } else if (base == 1) {
    result = 1.0;
  } else if (s21_ISNAN(base) || s21_ISNAN(exp)) {
    result = s21_NAN;
  } else if (base == 0 && exp > 0 && (long)exp == exp && (long)exp % 2) {
    result = base;
  } else if (base == 0 && exp > 0 && ((long)exp != exp || (long)exp % 2 == 0)) {
    result = +0.0;
  } else if (base == 0 && exp < 0 && (long)exp == exp && (long)exp % 2) {
    result = 1.0 / base;
  } else if (base == 0 && exp < 0 && ((long)exp != exp || (long)exp % 2 == 0)) {
    result = s21_INF_POSITIVE;
  } else if (base == -1 && s21_ISINF(exp)) {
    result = 1.0;
  } else if (base == s21_INF_POSITIVE && exp < 0) {
    result = +0.0;
  } else if (base == s21_INF_POSITIVE && exp > 0) {
    result = s21_INF_POSITIVE;
  } else if (base == s21_INF_NEGATIVE && exp < 0 && (long)exp == exp &&
             (long)exp % 2) {
    result = -0.0;
  } else if (base == s21_INF_NEGATIVE && exp < 0 &&
             ((long)exp != exp || (long)exp % 2 == 0)) {
    result = +0.0;
  } else if (base == s21_INF_NEGATIVE && exp > 0 && (long)exp == exp &&
             (long)exp % 2) {
    result = s21_INF_NEGATIVE;
  } else if (base == s21_INF_NEGATIVE && exp > 0 &&
             ((long)exp != exp || (long)exp % 2 == 0)) {
    result = s21_INF_POSITIVE;
  } else if (s21_fabs(base) < 1 && exp == s21_INF_NEGATIVE) {
    result = s21_INF_POSITIVE;
  } else if (s21_fabs(base) > 1 && exp == s21_INF_NEGATIVE) {
    result = +0.0;
  } else if (s21_fabs(base) < 1 && exp == s21_INF_POSITIVE) {
    result = +0.0;
  } else if (s21_fabs(base) > 1 && exp == s21_INF_POSITIVE) {
    result = s21_INF_POSITIVE;
  } else {
    if ((long)exp == exp && exp > 0) {
      for (int i = 0; i < exp; i++) result *= base;
    } else if ((long)exp == exp && exp < 0) {
      for (int i = 0; i > exp; i--) result /= base;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }

  return result;
}
