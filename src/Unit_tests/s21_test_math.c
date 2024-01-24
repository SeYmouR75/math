#include "s21_test_math.h"

#include <stdio.h>

void run_suite(Suite *suite) {
  SRunner *sr = srunner_create(suite);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests() {
  Suite *suites_core[] = {
      suite_s21_abs(),  suite_s21_fabs(), suite_s21_floor(), suite_s21_exp(),
      suite_s21_sin(),  suite_s21_cos(),  suite_s21_acos(),  suite_s21_asin(),
      suite_s21_atan(), suite_s21_ceil(), suite_s21_fmod(),  suite_s21_log(),
      suite_s21_pow(),  suite_s21_sqrt(), suite_s21_tan(),   NULL};

  for (Suite **cur = suites_core; *cur != NULL; cur++) {
    printf("\n==================================\n");
    run_suite(*cur);
    printf("\n==================================\n");
  }
}

int main() {
  run_tests();
  return 0;
}
