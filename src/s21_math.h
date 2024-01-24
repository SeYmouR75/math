#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_NAN 0.0 / 0.0
#define s21_INF_POSITIVE 1.0 / 0.0
#define s21_INF_NEGATIVE -1.0 / 0.0
#define s21_ISINF(x) (x == s21_INF_POSITIVE || x == s21_INF_NEGATIVE) ? 1 : 0
#define s21_ISNAN(x) (x != x) ? 1 : 0
#define s21_PI 3.14159265358979323846
#define s21_PI_2 1.57079632679489661923
#define s21_PI_4 0.78539816339744830962
#define s21_E 2.7182818284590452354
#define s21_EPSILON 2.2204460492503131e-016

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_sin(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
