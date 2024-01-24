#include "s21_test_math.h"

#define actual(x, y) s21_pow(x, y)
#define expected(x, y) pow(x, y)

static double normal_val[][2] = {
    {1.0, s21_NAN},     {-2.16, 3}, {12345.67, 0.123},    {12345.67, 4},
    {12658745.2, -0.3}, {1.5, 19},  {576.73463, 2.3},     {25, 3},
    {1.00078, 22},      {49, 0.5},  {0.000008, 5.000008}, {4.34567, 3.3},
    {0.90909091, -12}};

START_TEST(test_pow_normal) {
  double val1 = normal_val[_i][0], val2 = normal_val[_i][1];
  ck_assert_double_eq_tol(actual(val1, val2), expected(val1, val2), 1e-6);
}
END_TEST

static double edge_val[][2] = {{23.34, 0},        {1.0, 72.3},   {+0.0, 5},
                               {-0.0, 7},         {-0.0, 8},     {+0.0, 8},
                               {12345.67, 0.123}, {12345.67, 4}, {12345.2, 2}};

START_TEST(test_pow_edge) {
  double val1 = edge_val[_i][0], val2 = edge_val[_i][1];
  ck_assert_double_eq_tol(actual(val1, val2), expected(val1, val2), 1e-6);
}
END_TEST

static double anomally_val[][2] = {{s21_NAN, 3.8},
                                   {12, s21_NAN},
                                   {+0.0, -3},
                                   {-0.0, -3},
                                   {-0.0, -4},
                                   {s21_INF_POSITIVE, 2},
                                   {s21_INF_NEGATIVE, 9},
                                   {s21_INF_NEGATIVE, 8},
                                   {0.3, s21_INF_NEGATIVE},
                                   {2.5, s21_INF_NEGATIVE},
                                   {0.3, s21_INF_POSITIVE},
                                   {-2.5, s21_INF_POSITIVE},
                                   {-1, s21_INF_NEGATIVE},
                                   {s21_NAN, 0},
                                   {1, s21_NAN},
                                   {s21_INF_POSITIVE, -3.14},
                                   {s21_INF_NEGATIVE, -9},
                                   {s21_INF_NEGATIVE, -8},
                                   {-12345.67, -0.123}};

START_TEST(test_pow_anomally) {
  double val1 = anomally_val[_i][0], val2 = anomally_val[_i][1];
  if (s21_ISNAN(expected(val1, val2))) {
    ck_assert_ldouble_nan(actual(val1, val2));
  } else if (s21_ISINF(expected(val1, val2))) {
    ck_assert_ldouble_infinite(actual(val1, val2));
  } else {
    ck_assert_double_eq_tol(actual(val1, val2), expected(val1, val2), 1e-6);
  }
}
END_TEST

Suite *suite_s21_pow() {
  Suite *suite = suite_create("suite_s21_pow");

  TCase *normal_case = tcase_create("s21_pow_normal_val");
  tcase_add_loop_test(normal_case, test_pow_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_pow_edge_val");
  tcase_add_loop_test(edge_case, test_pow_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  TCase *anomally_case = tcase_create("s21_pow_anomally_val");
  tcase_add_loop_test(anomally_case, test_pow_anomally, 0,
                      sizeof(anomally_val) / sizeof(anomally_val[0]));
  suite_add_tcase(suite, anomally_case);

  return suite;
}
