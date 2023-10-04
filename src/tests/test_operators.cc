#include "test_main.h"

TEST(operators, equals) {
  S21Matrix matr;
  S21Matrix matr2;
  double value_matr[3] = {1, 2, 3};
  double value_matr2[3] = {3, 2, 2};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr2, 3);
  matr = matr2;
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      ASSERT_EQ(matr(i, j), matr2(i, j));
    }
  }
}

TEST(operators, equals_move) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix result;
  double value_matr[3] = {1, 2, 3};
  double value_matr2[3] = {3, 2, 2};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr2, 3);
  result.FillMatrix(value_matr2, 3);
  matr = std::move(matr2);
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      ASSERT_EQ(matr(i, j), result(i, j));
    }
  }
}

TEST(operator, index) {
  S21Matrix matr;
  matr(0, 0) = 2;
  ASSERT_EQ(matr(0, 0), 2);
}

TEST(operator, plus) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  S21Matrix result;
  S21Matrix result2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  // matr2.Print();
  result = matr + matr2;
  // result.Print();
  result2 = matr_test + matr2_test;
  ASSERT_TRUE(result.EqMatrix(result2));
}

TEST(operator, minus) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  S21Matrix result;
  S21Matrix result2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  result = matr - matr2;
  result2 = matr_test - matr2_test;
  ASSERT_TRUE(result.EqMatrix(result2));
}

TEST(operator, minus_assignment) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  matr -= matr2;
  matr_test -= matr2_test;
  ASSERT_TRUE(matr.EqMatrix(matr_test));
}

TEST(operator, plus_assignment) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  matr += matr2;
  matr_test += matr2_test;
  ASSERT_TRUE(matr.EqMatrix(matr_test));
}

TEST(operator, mult_obj_assignment) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  matr *= matr2;
  matr_test *= matr2_test;
  ASSERT_TRUE(matr.EqMatrix(matr_test));
}

TEST(operator, mult_num_assignment) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  matr *= 2;
  matr_test *= 2;
  ASSERT_TRUE(matr.EqMatrix(matr_test));
}

TEST(operator, mult_obj) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  S21Matrix result;
  S21Matrix result2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  result = matr * matr2;
  result2 = matr_test * matr2_test;
  ASSERT_TRUE(result.EqMatrix(result2));
}

TEST(operator, mult_num) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  S21Matrix result;
  S21Matrix result2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  result = matr * 2;
  result2 = matr_test * 2;
  ASSERT_TRUE(result.EqMatrix(result2));
}

TEST(operator, mult_num_2) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix matr_test;
  S21Matrix matr2_test;
  S21Matrix result;
  S21Matrix result2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  matr_test.FillMatrix(value_matr, 3);
  matr2_test.FillMatrix(value_matr, 3);
  result = 2 * matr;
  result2 = 2 * matr_test;
  ASSERT_TRUE(result.EqMatrix(result2));
}

TEST(operator, ifequals) {
  S21Matrix matr;
  S21Matrix matr2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  ASSERT_TRUE(matr == matr2);
}
