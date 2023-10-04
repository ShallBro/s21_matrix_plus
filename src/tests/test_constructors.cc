#include "test_main.h"

TEST(constructors, defaults) {
  S21Matrix matr;
  ASSERT_EQ(matr.GetRows(), 3);
  ASSERT_EQ(matr.GetCols(), 3);
}

TEST(constructors, parametric) {
  S21Matrix matr(4, 4);
  ASSERT_EQ(matr.GetRows(), 4);
  ASSERT_EQ(matr.GetCols(), 4);
}

TEST(constructors, parametric_throw) {
  try {
    S21Matrix matr(0, 0);
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(constructors, copy) {
  S21Matrix matr(4, 4);
  S21Matrix copymatr(matr);
  ASSERT_EQ(matr.GetRows(), 4);
  ASSERT_EQ(matr.GetCols(), 4);
  ASSERT_EQ(copymatr.GetRows(), 4);
  ASSERT_EQ(copymatr.GetCols(), 4);
}

TEST(constructors, move) {
  S21Matrix matr(4, 4);
  S21Matrix movematr(std::move(matr));
  ASSERT_EQ(movematr.GetRows(), 4);
  ASSERT_EQ(movematr.GetCols(), 4);
}
