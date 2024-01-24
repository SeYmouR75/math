#include "s21_test_math.h"

#define actual(x) s21_exp(x)
#define expected(x) exp(x)

static double normal_val[] = {1, -1, 0, 22};

START_TEST(test_exp_normal) {
  double val = normal_val[_i];
  ck_assert_double_eq_tol(actual(val), expected(val), 1e-06);
}
END_TEST

static long double edge_val[] = {-999999999999, 0.11111, -0.000000001, DBL_MAX,
                                 -DBL_MAX,      1e-9,    -1e-9};

START_TEST(test_exp_edge) {
  double val = edge_val[_i];

  ck_assert_double_eq(actual(val), expected(val));
}
END_TEST

static double anomally_val[] = {s21_INF_POSITIVE, s21_INF_NEGATIVE, s21_NAN};

START_TEST(test_exp_anomally) {
  double val = anomally_val[_i];

  if (s21_ISNAN(expected(val)))
    ck_assert_ldouble_nan(actual(val));
  else
    ck_assert_double_eq(actual(val), expected(val));
}
END_TEST

Suite *suite_s21_exp() {
  Suite *suite = suite_create("suite_s21_exp");

  TCase *normal_case = tcase_create("s21_exp_normal_val");
  tcase_add_loop_test(normal_case, test_exp_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_exp_edge_val");
  tcase_add_loop_test(edge_case, test_exp_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_exp_anomally_val");
  tcase_add_loop_test(anomally_case, test_exp_anomally, 0,
                      sizeof(anomally_val) / sizeof(anomally_val[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}