#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0.0;

  if (x == s21_INF_POSITIVE || x == 0) {
    result = x;
  } else if (x == s21_INF_NEGATIVE || s21_ISNAN(x) || x < 0) {
    result = s21_NAN;
  } else {
    result = s21_pow(x, 0.5);
  }

  return result;
}
