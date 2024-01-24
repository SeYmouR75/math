#include "s21_math.h"

long double s21_floor(double x) {
  long double result = (long long int)x;

  if (x != x) {
    result = s21_NAN;
  } else if (x == s21_INF_POSITIVE) {
    result = s21_INF_POSITIVE;
  } else if (x == s21_INF_NEGATIVE) {
    result = s21_INF_NEGATIVE;
  } else if (x < 0 && x != result) {
    result -= 1;
  }
  return result;
}
