#include "s21_test_math.h"

#define actual(x) s21_sqrt(x)
#define expected(x) sqrt(x)

static double normal_val[] = {1.0,      0.1, 0.123456, 0.000001,
                              1.000001, 5.0, DBL_MIN,  3.402823e+11,
                              4,        16,  25};

START_TEST(test_sqrt_normal) {
  double val = normal_val[_i];
  ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
}
END_TEST

static double edge_val[] = {0.0, 1.0};

START_TEST(test_sqrt_edge) {
  double val = edge_val[_i];
  ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
}
END_TEST

static double anomally_val[] = {
    s21_NAN,   s21_INF_NEGATIVE, -1.0,      -0.1,
    -0.123456, s21_INF_POSITIVE, -1.000001, -5.3,
};

START_TEST(test_sqrt_anomally) {
  double val = anomally_val[_i];
  if (s21_ISNAN(expected(val))) {
    ck_assert_ldouble_nan(actual(val));
  } else if (s21_ISINF(expected(val))) {
    ck_assert_ldouble_infinite(actual(val));
  } else {
    ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
  }
}
END_TEST

Suite *suite_s21_sqrt() {
  Suite *suite = suite_create("suite_s21_sqrt");

  TCase *normal_case = tcase_create("s21_sqrt_normal_val");
  tcase_add_loop_test(normal_case, test_sqrt_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_sqrt_edge_val");
  tcase_add_loop_test(edge_case, test_sqrt_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_sqrt_anomally_val");
  tcase_add_loop_test(anomally_case, test_sqrt_anomally, 0,
                      sizeof(anomally_val) / sizeof(anomally_val[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}
