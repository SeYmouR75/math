#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0.0;
  if (s21_ISNAN(x) || s21_ISINF(x))
    res = s21_NAN;
  else {
    x = s21_fmod(x, s21_PI);
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}
