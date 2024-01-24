#include "s21_test_math.h"

#define actual(x) s21_log(x)
#define logected(x) log(x)

static double normal_val[] = {s21_E, 10, 3, 26941.289, 12.36};

START_TEST(test_log_normal) {
  double val = normal_val[_i];
  ck_assert_double_eq_tol(actual(val), logected(val), 1e-06);
}
END_TEST

static long double edge_val[] = {1};

START_TEST(test_log_edge) {
  double val = edge_val[_i];
  ck_assert_double_eq_tol(actual(val), logected(val), 1e-06);
}
END_TEST

static double anomally_val[] = {
    s21_INF_POSITIVE, s21_INF_NEGATIVE, s21_NAN, -1, -12.36, 0};

START_TEST(test_log_anomally) {
  double val = anomally_val[_i];
  if (s21_ISNAN(logected(val)))
    ck_assert_ldouble_nan(actual(val));
  else
    ck_assert_double_eq(actual(val), logected(val));
}
END_TEST

Suite *suite_s21_log() {
  Suite *suite = suite_create("suite_s21_log");

  TCase *normal_case = tcase_create("s21_log_normal_val");
  tcase_add_loop_test(normal_case, test_log_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_log_edge_val");
  tcase_add_loop_test(edge_case, test_log_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_log_anomally_val");
  tcase_add_loop_test(anomally_case, test_log_anomally, 0,
                      sizeof(anomally_val) / sizeof(anomally_val[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}