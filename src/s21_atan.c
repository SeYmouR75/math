#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (x == s21_INF_POSITIVE) {
    result = s21_PI_2;
  } else if (x == s21_INF_NEGATIVE) {
    result = -s21_PI_2;
  } else if (s21_fabs(x - 1.0) < 1e-06) {
    result = s21_PI_4;
  } else if (s21_fabs(x + 1.0) < 1e-06) {
    result = -s21_PI_4;
  } else {
    int sign = 1;
    result = x;
    if (x < -1.0 || x > 1.0) {
      sign = -1;
      result = 1.0 / x;
    }
    for (int i = 1; i < 1000; i++) {
      result += (i % 2 ? -1 : 1) * s21_pow(x, (2 * i + 1) * sign) / (2 * i + 1);
    }
    if (sign < 0) result = (s21_PI * s21_fabs(x) / (2 * x)) - result;
  }
  return result;
}
