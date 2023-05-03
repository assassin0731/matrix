#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(test_check_rows, test1) {
  S21Matrix my_matrix(3, 3);
  EXPECT_EQ(3, my_matrix.getRows());
}

TEST(test_check_cols, test2) {
  S21Matrix my_matrix(3, 3);
  EXPECT_EQ(3, my_matrix.getCols());
}

TEST(test_eq_matrix_1, test3) {
  S21Matrix first;
  S21Matrix second;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  int result = first.EqMatrix(second);
  EXPECT_EQ(1, result);
}

TEST(test_eq_matrix_2, test4) {
  S21Matrix first;
  S21Matrix second;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  first(0, 0) = 100;
  int result = first.EqMatrix(second);
  EXPECT_EQ(0, result);
}

TEST(test_eq_matrix_3, test5) {
  S21Matrix first;
  S21Matrix second(4, 4);
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  int result = first.EqMatrix(second);
  EXPECT_EQ(0, result);
  // EXPECT_THROW(first.EqMatrix(second), std::out_of_range);
}

TEST(test_eq_matrix_4, test6) {
  S21Matrix first;
  first.FillMatrix();
  S21Matrix second(first);
  int result = first.EqMatrix(second);
  EXPECT_EQ(1, result);
}

TEST(test_eq_matrix_5, test7) {
  S21Matrix first(30, 40);
  S21Matrix second(30, 40);
  int count = 0;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 40; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  int result = first.EqMatrix(second);
  EXPECT_EQ(1, result);
}

TEST(test_eq_matrix_6, test8) {
  S21Matrix first(30, 40);
  S21Matrix second(30, 40);
  int count = 0;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 40; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  first(20, 20) = 0;
  int result = first.EqMatrix(second);
  EXPECT_EQ(0, result);
}

TEST(test_sum_matrix_1, test9) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  first.SumMatrix(second);
  EXPECT_EQ(2, first(0, 0));
  EXPECT_EQ(4, first(0, 1));
  EXPECT_EQ(6, first(1, 0));
  EXPECT_EQ(8, first(1, 1));
}

TEST(test_sum_matrix_2, test10) {
  S21Matrix first(2, 2);
  S21Matrix second(3, 3);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  EXPECT_THROW(first.SumMatrix(second), std::out_of_range);
}

TEST(test_sum_matrix_3, test11) {
  S21Matrix first(3, 4);
  S21Matrix second(3, 4);

  double counter = 1.01;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      first(i, j) = counter;
      counter += 0.01;
      second(i, j) = counter;
    }
  }
  first.SumMatrix(second);
  EXPECT_NEAR(2.03, first(0, 0), eps);
  EXPECT_NEAR(2.05, first(0, 1), eps);
  EXPECT_NEAR(2.07, first(0, 2), eps);
  EXPECT_NEAR(2.09, first(0, 3), eps);
  EXPECT_NEAR(2.11, first(1, 0), eps);
  EXPECT_NEAR(2.13, first(1, 1), eps);
  EXPECT_NEAR(2.15, first(1, 2), eps);
  EXPECT_NEAR(2.17, first(1, 3), eps);
  EXPECT_NEAR(2.19, first(2, 0), eps);
  EXPECT_NEAR(2.21, first(2, 1), eps);
  EXPECT_NEAR(2.23, first(2, 2), eps);
  EXPECT_NEAR(2.25, first(2, 3), eps);
}

TEST(test_sub_matrix_1, test12) {
  S21Matrix first(3, 4);
  S21Matrix second(3, 4);

  double counter = 1.01;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      first(i, j) = counter;
      counter += 0.01;
      second(i, j) = counter;
    }
  }
  first.SubMatrix(second);
  EXPECT_NEAR(-0.01, first(0, 0), eps);
  EXPECT_NEAR(-0.01, first(0, 1), eps);
  EXPECT_NEAR(-0.01, first(0, 2), eps);
  EXPECT_NEAR(-0.01, first(0, 3), eps);
  EXPECT_NEAR(-0.01, first(1, 0), eps);
  EXPECT_NEAR(-0.01, first(1, 1), eps);
  EXPECT_NEAR(-0.01, first(1, 2), eps);
  EXPECT_NEAR(-0.01, first(1, 3), eps);
  EXPECT_NEAR(-0.01, first(2, 0), eps);
  EXPECT_NEAR(-0.01, first(2, 1), eps);
  EXPECT_NEAR(-0.01, first(2, 2), eps);
  EXPECT_NEAR(-0.01, first(2, 3), eps);
}

TEST(test_sub_matrix_2, test13) {
  S21Matrix first(2, 2);
  S21Matrix second(3, 3);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  EXPECT_THROW(first.SubMatrix(second), std::out_of_range);
}

TEST(test_mul_number_1, test14) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      count++;
    }
  }
  first.MulNumber(2);
  EXPECT_EQ(2, first(0, 0));
  EXPECT_EQ(4, first(0, 1));
  EXPECT_EQ(6, first(1, 0));
  EXPECT_EQ(8, first(1, 1));
}

TEST(test_mul_number_2, test15) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count + 0.5;
      count++;
    }
  }
  first.MulNumber(2);
  EXPECT_NEAR(3, first(0, 0), eps);
  EXPECT_NEAR(5, first(0, 1), eps);
  EXPECT_NEAR(7, first(1, 0), eps);
  EXPECT_NEAR(9, first(1, 1), eps);
}

TEST(test_mul_matrix_1, test16) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  first.MulMatrix(second);
  EXPECT_EQ(7, first(0, 0));
  EXPECT_EQ(10, first(0, 1));
  EXPECT_EQ(15, first(1, 0));
  EXPECT_EQ(22, first(1, 1));
}

TEST(test_mul_matrix_2, test17) {
  S21Matrix first(2, 2);
  S21Matrix second(3, 3);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  EXPECT_THROW(first.MulMatrix(second), std::out_of_range);
}

TEST(test_transp_matrix_1, test18) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count++;
    }
  }
  S21Matrix second(first.Transpose());
  EXPECT_EQ(1, second(0, 0));
  EXPECT_EQ(3, second(0, 1));
  EXPECT_EQ(2, second(1, 0));
  EXPECT_EQ(4, second(1, 1));
}

TEST(test_transp_matrix_2, test19) {
  S21Matrix first(3, 1);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      first(i, j) = count++;
    }
  }
  S21Matrix second(first.Transpose());
  EXPECT_EQ(1, second(0, 0));
  EXPECT_EQ(2, second(0, 1));
  EXPECT_EQ(3, second(0, 2));
}

TEST(test_calc_comp_matrix_1, test20) {
  S21Matrix first(3, 3);
  first(0, 0) = 1;
  first(0, 1) = 2;
  first(0, 2) = 3;
  first(1, 0) = 0;
  first(1, 1) = 4;
  first(1, 2) = 2;
  first(2, 0) = 5;
  first(2, 1) = 2;
  first(2, 2) = 1;
  S21Matrix second(first.CalcComplements());
  EXPECT_EQ(0, second(0, 0));
  EXPECT_EQ(10, second(0, 1));
  EXPECT_EQ(-20, second(0, 2));
  EXPECT_EQ(4, second(1, 0));
  EXPECT_EQ(-14, second(1, 1));
  EXPECT_EQ(8, second(1, 2));
  EXPECT_EQ(-8, second(2, 0));
  EXPECT_EQ(-2, second(2, 1));
  EXPECT_EQ(4, second(2, 2));
}

TEST(test_calc_comp_matrix_2, test21) {
  S21Matrix first(2, 3);
  first(0, 0) = 1;
  first(0, 1) = 2;
  first(0, 2) = 3;
  first(1, 0) = 0;
  first(1, 1) = 4;
  first(1, 2) = 2;
  EXPECT_THROW(S21Matrix second(first.CalcComplements()), std::out_of_range);
}

TEST(test_determ_matrix_1, test22) {
  S21Matrix first(2, 3);
  first(0, 0) = 1;
  first(0, 1) = 2;
  first(0, 2) = 3;
  first(1, 0) = 0;
  first(1, 1) = 4;
  first(1, 2) = 2;
  EXPECT_THROW(first.Determinant(), std::out_of_range);
}

TEST(test_determ_matrix_2, test23) {
  S21Matrix first(3, 3);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = count++;
    }
  }
  EXPECT_EQ(0, first.Determinant());
}

TEST(test_determ_matrix_3, test24) {
  S21Matrix first(4, 4);
  first(0, 0) = 9;
  first(0, 1) = 2;
  first(0, 2) = 2;
  first(0, 3) = 4;

  first(1, 0) = 3;
  first(1, 1) = 4;
  first(1, 2) = 4;
  first(1, 3) = 4;

  first(2, 0) = 4;
  first(2, 1) = 4;
  first(2, 2) = 9;
  first(2, 3) = 9;

  first(3, 0) = 1;
  first(3, 1) = 1;
  first(3, 2) = 5;
  first(3, 3) = 1;

  EXPECT_EQ(-578, first.Determinant());
}

TEST(test_inverse_matrix_1, test25) {
  S21Matrix first(3, 3);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = count++;
    }
  }
  EXPECT_THROW(S21Matrix second(first.InverseMatrix()), std::out_of_range);
}

TEST(test_inverse_matrix_2, test26) {
  S21Matrix first(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 0;
    }
  }

  first(0, 0) = 1;
  first(0, 3) = 3;
  first(1, 2) = 2;
  first(2, 1) = 2;
  first(2, 3) = 5;
  first(3, 0) = 3;
  first(4, 1) = 4;
  first(4, 4) = 6;

  first = first.InverseMatrix();

  EXPECT_EQ(first(0, 0), 0);
  EXPECT_EQ(first(0, 1), 0);
  EXPECT_EQ(first(0, 2), 0);
  EXPECT_NEAR(first(0, 3), 1. / 3, eps);
  EXPECT_EQ(first(0, 4), 0);
  EXPECT_NEAR(first(1, 0), -5. / 6, eps);
  EXPECT_EQ(first(1, 1), 0);
  EXPECT_NEAR(first(1, 2), 0.5, eps);
  EXPECT_NEAR(first(1, 3), 5. / 18, eps);
  EXPECT_EQ(first(1, 4), 0);
  EXPECT_EQ(first(2, 0), 0);
  EXPECT_NEAR(first(2, 1), 0.5, eps);
  EXPECT_EQ(first(2, 2), 0);
  EXPECT_EQ(first(2, 3), 0);
  EXPECT_EQ(first(2, 4), 0);
  EXPECT_NEAR(first(3, 0), 1. / 3, eps);
  EXPECT_EQ(first(3, 1), 0);
  EXPECT_EQ(first(3, 2), 0);
  EXPECT_NEAR(first(3, 3), -1. / 9, eps);
  EXPECT_EQ(first(3, 4), 0);
  EXPECT_NEAR(first(4, 0), 5. / 9, eps);
  EXPECT_EQ(first(4, 1), 0);
  EXPECT_NEAR(first(4, 2), -1. / 3, eps);
  EXPECT_NEAR(first(4, 3), -5. / 27, eps);
  EXPECT_NEAR(first(4, 4), 1. / 6, eps);
}

TEST(test_operator_plus_matrix_1, test27) {
  S21Matrix first(3, 3);
  S21Matrix second(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 1;
      second(i, j) = 2;
    }
  }
  second = first + second;
  EXPECT_EQ(3, second(0, 0));
  EXPECT_EQ(3, second(0, 1));
  EXPECT_EQ(3, second(0, 2));
  EXPECT_EQ(3, second(1, 0));
  EXPECT_EQ(3, second(1, 1));
  EXPECT_EQ(3, second(1, 2));
  EXPECT_EQ(3, second(2, 0));
  EXPECT_EQ(3, second(2, 1));
  EXPECT_EQ(3, second(2, 2));
}

TEST(test_operator_plus_matrix_2, test28) {
  S21Matrix first(3, 3);
  S21Matrix second(3, 4);

  EXPECT_THROW(first + second, std::out_of_range);
}

TEST(test_operator_minus_matrix_1, test29) {
  S21Matrix first(3, 3);
  S21Matrix second(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 1;
      second(i, j) = 2;
    }
  }
  second = first - second;
  EXPECT_EQ(-1, second(0, 0));
  EXPECT_EQ(-1, second(0, 1));
  EXPECT_EQ(-1, second(0, 2));
  EXPECT_EQ(-1, second(1, 0));
  EXPECT_EQ(-1, second(1, 1));
  EXPECT_EQ(-1, second(1, 2));
  EXPECT_EQ(-1, second(2, 0));
  EXPECT_EQ(-1, second(2, 1));
  EXPECT_EQ(-1, second(2, 2));
}

TEST(test_mul_operator_1, test30) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      count++;
    }
  }
  first = first * 2;
  EXPECT_EQ(2, first(0, 0));
  EXPECT_EQ(4, first(0, 1));
  EXPECT_EQ(6, first(1, 0));
  EXPECT_EQ(8, first(1, 1));
}

TEST(test_mul_operator_2, test31) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      count++;
    }
  }
  first = 2 * first;
  EXPECT_EQ(2, first(0, 0));
  EXPECT_EQ(4, first(0, 1));
  EXPECT_EQ(6, first(1, 0));
  EXPECT_EQ(8, first(1, 1));
}

TEST(test_mul_operator_3, test32) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  first = first * second;
  EXPECT_EQ(7, first(0, 0));
  EXPECT_EQ(10, first(0, 1));
  EXPECT_EQ(15, first(1, 0));
  EXPECT_EQ(22, first(1, 1));
}

TEST(test_mul_operator_4, test33) {
  S21Matrix first(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      count++;
    }
  }
  first *= 2;
  EXPECT_EQ(2, first(0, 0));
  EXPECT_EQ(4, first(0, 1));
  EXPECT_EQ(6, first(1, 0));
  EXPECT_EQ(8, first(1, 1));
}

TEST(test_mul_operator_5, test34) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count;
      second(i, j) = count++;
    }
  }
  first *= second;
  EXPECT_EQ(7, first(0, 0));
  EXPECT_EQ(10, first(0, 1));
  EXPECT_EQ(15, first(1, 0));
  EXPECT_EQ(22, first(1, 1));
}

TEST(test_operator_plus_1, test35) {
  S21Matrix first(3, 3);
  S21Matrix second(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 1;
      second(i, j) = 2;
    }
  }
  second += first;
  EXPECT_EQ(3, second(0, 0));
  EXPECT_EQ(3, second(0, 1));
  EXPECT_EQ(3, second(0, 2));
  EXPECT_EQ(3, second(1, 0));
  EXPECT_EQ(3, second(1, 1));
  EXPECT_EQ(3, second(1, 2));
  EXPECT_EQ(3, second(2, 0));
  EXPECT_EQ(3, second(2, 1));
  EXPECT_EQ(3, second(2, 2));
}

TEST(test_operator_minus_1, test36) {
  S21Matrix first(3, 3);
  S21Matrix second(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 1;
      second(i, j) = 2;
    }
  }
  second -= first;
  EXPECT_EQ(1, second(0, 0));
  EXPECT_EQ(1, second(0, 1));
  EXPECT_EQ(1, second(0, 2));
  EXPECT_EQ(1, second(1, 0));
  EXPECT_EQ(1, second(1, 1));
  EXPECT_EQ(1, second(1, 2));
  EXPECT_EQ(1, second(2, 0));
  EXPECT_EQ(1, second(2, 1));
  EXPECT_EQ(1, second(2, 2));
}

TEST(test_operator_eq_1, test37) {
  S21Matrix first;
  S21Matrix second;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  first(0, 0) = 100;
  int result = 0;
  if (first == second) {
    result = 1;
  }
  EXPECT_EQ(0, result);
}

TEST(test_operator_eq_2, test38) {
  S21Matrix first;
  S21Matrix second;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = ++count + 1.01234567;
      second(i, j) = count + 1.01234567;
    }
  }
  int result = 0;
  if (first == second) {
    result = 1;
  }
  EXPECT_EQ(1, result);
}

TEST(test_get_cols_rows_1, test39) {
  S21Matrix first;
  EXPECT_EQ(3, first.getCols());
  EXPECT_EQ(3, first.getRows());
}

TEST(test_operator_brackets_1, test40) {
  S21Matrix first;
  EXPECT_THROW(first(4, 4) = 1, std::out_of_range);
}

TEST(test_operator_brackets_2, test41) {
  S21Matrix first;
  EXPECT_THROW(first(4, 4), std::out_of_range);
}

TEST(test_operator_brackets_3, test42) {
  S21Matrix first;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = count++;
    }
  }
  EXPECT_EQ(first(0, 1), 1);
}

TEST(test_constructor_1, test43) {
  EXPECT_THROW(S21Matrix first(3, 0), std::out_of_range);
}

TEST(test_determ_matrix_4, test44) {
  S21Matrix first(1, 1);
  first(0, 0) = 3;
  EXPECT_EQ(3, first.Determinant());
}

TEST(test_set_rows_matrix_1, test45) {
  S21Matrix first(2, 2);
  int count = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count++;
    }
  }
  first.setRows(3);
  EXPECT_EQ(0, first(0, 0));
  EXPECT_EQ(1, first(0, 1));
  EXPECT_EQ(2, first(1, 0));
  EXPECT_EQ(3, first(1, 1));
  EXPECT_EQ(0, first(2, 0));
  EXPECT_EQ(0, first(2, 1));
}

TEST(test_set_rows_matrix_2, test46) {
  S21Matrix first(2, 2);
  EXPECT_THROW(first.setRows(0), std::out_of_range);
}

TEST(test_set_colss_matrix_1, test47) {
  S21Matrix first(2, 2);
  int count = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = count++;
    }
  }
  first.setCols(3);
  EXPECT_EQ(0, first(0, 0));
  EXPECT_EQ(1, first(0, 1));
  EXPECT_EQ(0, first(0, 2));
  EXPECT_EQ(2, first(1, 0));
  EXPECT_EQ(3, first(1, 1));
  EXPECT_EQ(0, first(1, 2));
}

TEST(test_set_cols_matrix_2, test48) {
  S21Matrix first(2, 2);
  EXPECT_THROW(first.setCols(-1), std::out_of_range);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}