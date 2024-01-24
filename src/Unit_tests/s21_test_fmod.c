#include "s21_test_math.h"

#define actual(x, y) s21_fmod(x, y)
#define expected(x, y) fmod(x, y)

static double normal_val_x[] = {1.0,    17.0,      -17.0,      0.1,
                                -0.1,   1324.1324, -1324.1324, 350.10867,
                                12.432, 10.87,     -543.8547,  -32};
static double normal_val_y[] = {-0.1235, 1.0,        2.0,    3.0,
                                4.0,     -34453.123, -125.0, 14567.56};

START_TEST(test_fmod_normal) {
  double x = normal_val_x[_i];
  for (int j = 0; j <= 7; j++) {
    double y = normal_val_y[j];
    // printf("x:%f y:%f s21:%Lf orig:%f\n", x, y , actual(x, y), expected(x,
    // y));
    ck_assert_double_eq_tol(actual(x, y), expected(x, y), 1e-6);
  }
}
END_TEST

static double edge_val_x[] = {-(double)INT_MIN, (double)INT_MIN,
                              -(double)INT_MAX, (double)INT_MAX, 0};
static double edge_val_y[] = {1.0, 3.0, 0, s21_INF_POSITIVE};

START_TEST(test_fmod_edge) {
  double x = edge_val_x[_i];
  for (int j = 0; j <= 3; j++) {
    double y = edge_val_y[j];
    // printf("x:%f y:%f s21:%Lf orig:%f\n", x, y , actual(x, y), expected(x,
    // y));
    if (s21_ISNAN(expected(x, y)))
      ck_assert_ldouble_nan(actual(x, y));
    else
      ck_assert_double_eq(actual(x, y), expected(x, y));
  }
}
END_TEST

static double anomally_val_x[] = {s21_INF_POSITIVE, s21_INF_NEGATIVE, s21_NAN};
static double anomally_val_y[] = {s21_INF_POSITIVE, s21_NAN, s21_INF_NEGATIVE,
                                  0, -0.00001};

START_TEST(test_fmod_anomally) {
  double x = anomally_val_x[_i];
  for (int j = 0; j <= 4; j++) {
    double y = anomally_val_y[j];
    // printf("x:%f y:%f s21:%Lf orig:%f\n", x, y , actual(x, y), expected(x,
    // y));
    if (s21_ISNAN(expected(x, y)))
      ck_assert_ldouble_nan(actual(x, y));
    else
      ck_assert_double_eq(actual(x, y), expected(x, y));
  }
}
END_TEST

Suite *suite_s21_fmod() {
  Suite *suite = suite_create("suite_s21_fmod");

  TCase *normal_case = tcase_create("s21_fmod_normal_val");
  tcase_add_loop_test(normal_case, test_fmod_normal, 0,
                      sizeof(normal_val_x) / sizeof(normal_val_x[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_fmod_edge_val");
  tcase_add_loop_test(edge_case, test_fmod_edge, 0,
                      sizeof(edge_val_x) / sizeof(edge_val_x[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_fmod_anomally_val");
  tcase_add_loop_test(anomally_case, test_fmod_anomally, 0,
                      sizeof(anomally_val_x) / sizeof(anomally_val_x[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}
