#include "s21_test_math.h"

#define actual(x) s21_asin(x)
#define expected(x) asin(x)

static double normal_val[] = {0.0,      0.1,       -0.1,    0.123456, -0.123456,
                              0.000001, -0.000001, DBL_MIN, -DBL_MIN};

START_TEST(test_asin_normal) {
  double val = normal_val[_i];
  ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
}
END_TEST

static double edge_val[] = {-1.0, 1.0};

START_TEST(test_asin_edge) {
  double val = edge_val[_i];
  ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
}
END_TEST

static double anomally_val[] = {s21_INF_POSITIVE,
                                s21_INF_NEGATIVE,
                                s21_NAN,
                                1.000001,
                                -1.000001,
                                5.0,
                                -5.3};

START_TEST(test_asin_anomally) {
  double val = anomally_val[_i];
  if (s21_ISNAN(expected(val)))
    ck_assert_ldouble_nan(actual(val));
  else
    ck_assert_double_eq(actual(val), expected(val));
}
END_TEST

Suite *suite_s21_asin() {
  Suite *suite = suite_create("suite_s21_asin");

  TCase *normal_case = tcase_create("s21_asin_normal_val");
  tcase_add_loop_test(normal_case, test_asin_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_asin_edge_val");
  tcase_add_loop_test(edge_case, test_asin_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_asin_anomally_val");
  tcase_add_loop_test(anomally_case, test_asin_anomally, 0,
                      sizeof(anomally_val) / sizeof(anomally_val[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}
