#include "s21_math.h"

long double s21_exp(double x) {
  const int MAX_ITERATION = 950;
  long double result = 1.0;
  long double term = 1.0;

  if (x != x) {
    result = s21_NAN;
  } else if (x == s21_INF_POSITIVE) {
    result = s21_INF_POSITIVE;
  } else if (x == s21_INF_NEGATIVE) {
    result = 0.0;
  } else if (x < -25) {
    result = 0.0;
  } else if (x > 709) {
    result = s21_INF_POSITIVE;
  }
  if (x < 0) {
    x = -x;
    for (int i = 1; i <= MAX_ITERATION; i++) {
      term *= x / i;
      result += term;
      if (term < s21_EPSILON * result) {
        i = MAX_ITERATION + 1;
      }
    }
    result = 1.0 / result;
  } else {
    for (int i = 1; i <= MAX_ITERATION; i++) {
      term *= x / i;
      result += term;

      if (term < s21_EPSILON * result) {
        i = MAX_ITERATION + 1;
      }
    }
  }
  return result;
}
