#include "s21_test_math.h"

#define actual(x) s21_abs(x)
#define expected(x) abs(x)

static int normal_val[] = {1, -1, 0, 1324, -1324};

START_TEST(test_abs_normal) {
  int val = normal_val[_i];
  ck_assert_int_eq(actual(val), expected(val));
}
END_TEST

static int edge_val[] = {INT_MAX, INT_MIN};

START_TEST(test_abs_edge) {
  int val = edge_val[_i];
  ck_assert_int_eq(actual(val), expected(val));
}
END_TEST

Suite *suite_s21_abs() {
  Suite *suite = suite_create("suite_s21_abs");

  TCase *normal_case = tcase_create("s21_abs_normal_val");
  tcase_add_loop_test(normal_case, test_abs_normal, 0,
                      sizeof(normal_val) / sizeof(normal_val[0]));
  suite_add_tcase(suite, normal_case);

  TCase *edge_case = tcase_create("s21_abs_edge_val");
  tcase_add_loop_test(edge_case, test_abs_edge, 0,
                      sizeof(edge_val) / sizeof(edge_val[0]));
  suite_add_tcase(suite, edge_case);

  return suite;
}