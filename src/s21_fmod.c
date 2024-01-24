#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;

  if (s21_ISNAN(x) || s21_ISNAN(y) || s21_ISINF(x) || y == 0)
    result = s21_NAN;
  else if (s21_ISINF(y))
    result = x;
  else {
    long long int quotient = x / y;
    result = x - quotient * y;
  }

  return result;
}