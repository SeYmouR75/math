#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0.0;

  if (!s21_ISINF(x) && !s21_ISNAN(x) && x >= -1.0 && x <= 1.0) {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    result = s21_NAN;
  }

  return result;
}
