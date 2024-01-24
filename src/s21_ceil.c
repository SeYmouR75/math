#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0.0;
  if (s21_ISNAN(x) || s21_ISINF(x))
    res = x;
  else {
    long in_int = (long)x;

    if (x > 0 && (x - in_int)) in_int = in_int + 1;

    res = in_int;
    if (res == 0 && x < 0) res = -res;
  }
  return res;
}
