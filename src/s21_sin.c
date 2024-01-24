#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;

  if (!s21_ISINF(x) && !s21_ISNAN(x)) {
    long double angle = s21_fmod(x, 2.0 * s21_PI);
    long double y = angle;

    for (int i = 1; i < 18; i++) {
      result += y;
      y *= -angle * angle / ((2 * i) * (2 * i + 1));
    }
  } else {
    result = s21_NAN;
  }

  return result;
}
