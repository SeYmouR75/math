#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  long double compare = 0;
  int step = 0;

  if (x == s21_INF_POSITIVE) {
    result = x;
  } else if (x == 0) {
    result = s21_INF_NEGATIVE;
  } else if (x < 0) {
    result = s21_NAN;
  } else {
    while (x >= s21_E && x != s21_INF_POSITIVE) {
      x /= s21_E;
      step++;
    }
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  result += step;
  return result;
}