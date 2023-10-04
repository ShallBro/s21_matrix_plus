#include "test_main.h"

TEST(matrix, EqMatrix) {
  S21Matrix matr;
  S21Matrix matr2;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  ASSERT_TRUE(matr.EqMatrix(matr2));
}

TEST(matrix, EqMatrix2) {
  S21Matrix matr;
  S21Matrix matr2;
  double value_matr[3] = {1, 2, 3};
  double value_matr1[3] = {3, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr1, 3);
  ASSERT_FALSE(matr.EqMatrix(matr2));
}

TEST(matrix, EqMatrix3) {
  S21Matrix matr(4, 4);
  S21Matrix matr2;
  double value_matr[4] = {1, 2, 3, 4};
  double value_matr1[3] = {3, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr1, 3);
  ASSERT_FALSE(matr.EqMatrix(matr2));
}

TEST(matrix, EqMatrix4) {
  S21Matrix matr(4, 4);
  S21Matrix matr2(1, 3);
  double value_matr[4] = {1, 2, 3, 4};
  double value_matr1[3] = {3, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr1, 3);
  ASSERT_FALSE(matr.EqMatrix(matr2));
}

TEST(matrix, EqMatrix5) {
  S21Matrix matr;
  S21Matrix matr2;
  double value_matr[3] = {1.12345, 2, 3};
  double value_matr1[3] = {1.12344, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr1, 3);
  ASSERT_FALSE(matr.EqMatrix(matr2));
}

TEST(matrix, SumMatrix) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix result;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      result(i, j) = matr(i, j) + matr2(i, j);
    }
  }
  matr.SumMatrix(matr2);
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, SumMatrix_Throw) {
  try {
    S21Matrix matr(3, 2);
    S21Matrix matr2(2, 3);
    matr.SumMatrix(matr2);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Sizes are not equal");
  }
}

TEST(matrix, SumMatrix2_Throw) {
  try {
    S21Matrix matr;
    S21Matrix matr2;
    S21Matrix result;
    matr.SetCols(0);
    matr.SumMatrix(matr2);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, SubMatrix) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix result;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      result(i, j) = matr(i, j) - matr2(i, j);
    }
  }
  matr.SubMatrix(matr2);
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, SubMatrix_Throw) {
  try {
    S21Matrix matr(3, 2);
    S21Matrix matr2(2, 3);
    matr.SubMatrix(matr2);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Sizes are not equal");
  }
}

TEST(matrix, SubMatrix2_Throw) {
  try {
    S21Matrix matr;
    S21Matrix matr2;
    S21Matrix result;
    matr.SetCols(0);
    matr.SubMatrix(matr2);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, MulNumber_Throw) {
  try {
    S21Matrix matr;
    S21Matrix matr2;
    S21Matrix result;
    matr.SetCols(0);
    double num = 6.235;
    matr.MulNumber(num);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, MulNumber) {
  S21Matrix matr;
  S21Matrix result;
  double num = 6.235;
  double value_matr[3] = {1, 2, 3};
  matr.FillMatrix(value_matr, 3);
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      result(i, j) = matr(i, j) * num;
    }
  }
  matr.MulNumber(num);
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, MulMatrix) {
  S21Matrix matr;
  S21Matrix matr2;
  S21Matrix result;
  double value_matr[3] = {1.34343, 2.34343, 3.34343};
  matr.FillMatrix(value_matr, 3);
  matr2.FillMatrix(value_matr, 3);
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      for (int n = 0; n < matr.GetRows(); n++)
        result(i, j) += matr(i, n) * matr2(n, j);
    }
  }
  matr.MulMatrix(matr2);
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, MulMatrix2) {
  try {
    S21Matrix matr;
    S21Matrix matr2;
    S21Matrix result;
    matr.SetCols(0);
    matr.MulMatrix(matr2);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, Transpose) {
  S21Matrix matr(2, 3);
  S21Matrix result(3, 2);
  double num = 1;
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      matr(i, j) = num;
      num++;
    }
  }
  matr = matr.Transpose();
  result(0, 0) = 1;
  result(0, 1) = 4;
  result(1, 0) = 2;
  result(1, 1) = 5;
  result(2, 0) = 3;
  result(2, 1) = 6;
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, Transpose2) {
  S21Matrix matr(2, 2);
  S21Matrix result(2, 2);
  double num = 1;
  for (int i = 0; i < matr.GetRows(); i++) {
    for (int j = 0; j < matr.GetCols(); j++) {
      matr(i, j) = num;
      num++;
    }
  }
  matr = matr.Transpose();
  result(0, 0) = 1;
  result(0, 1) = 3;
  result(1, 0) = 2;
  result(1, 1) = 4;
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, Transpose_Throw) {
  try {
    S21Matrix matr(2, 3);
    matr.SetRows(-1);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, CalcComplements_Throw) {
  try {
    S21Matrix matr;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Matrix is not square");
  }
}

TEST(matrix, CalcComplements_Throw2) {
  try {
    S21Matrix matr;
    matr.SetCols(-2331);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, CalcComplements) {
  S21Matrix matr;
  S21Matrix result;
  matr(0, 0) = 1;
  matr(0, 1) = 2;
  matr(0, 2) = 3;
  matr(1, 0) = 0;
  matr(1, 1) = 4;
  matr(1, 2) = 2;
  matr(2, 0) = 5;
  matr(2, 1) = 2;
  matr(2, 2) = 1;

  result(0, 0) = 0;
  result(0, 1) = 10;
  result(0, 2) = -20;
  result(1, 0) = 4;
  result(1, 1) = -14;
  result(1, 2) = 8;
  result(2, 0) = -8;
  result(2, 1) = -2;
  result(2, 2) = 4;
  matr = matr.CalcComplements();
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, CalcComplements2_Throw) {
  try {
    S21Matrix matr(3, 2);
    matr.CalcComplements();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Matrix is not square");
  }
}

TEST(matrix, CalcComplements3_Throw) {
  try {
    S21Matrix matr(3, 3);
    matr.SetCols(0);
    matr.CalcComplements();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, Determinant) {
  double det = 0;
  S21Matrix matr(1, 1);
  matr(0, 0) = 2;
  det = matr.Determinant();
  ASSERT_EQ(det, 2);
}

TEST(matrix, Determinant2) {
  double det = 0;
  S21Matrix matr(2, 2);
  double value_matr[2] = {3, 3};
  matr.FillMatrix(value_matr, 2);
  det = matr.Determinant();
  ASSERT_EQ(det, 0);
}

TEST(matrix, Determinant_3) {
  double det = 0;
  S21Matrix matr;
  matr(0, 0) = 0;
  matr(0, 1) = 9;
  matr(0, 2) = 5;
  matr(1, 0) = 4;
  matr(1, 1) = 3;
  matr(1, 2) = -5;
  matr(2, 0) = -1;
  matr(2, 1) = 6;
  matr(2, 2) = -4;
  det = matr.Determinant();
  ASSERT_EQ(det, 324);
}

TEST(matrix, Determinant4) {
  double det = 0;
  S21Matrix matr;
  matr(0, 0) = -1.2;
  matr(0, 1) = 2.1;
  matr(0, 2) = -4.2;
  matr(1, 0) = 5;
  matr(1, 1) = 8;
  matr(1, 2) = 3;
  matr(2, 0) = 3;
  matr(2, 1) = -2;
  matr(2, 2) = 7;
  det = matr.Determinant();
  ASSERT_NEAR(det, 13.8, 1e-6);
}

TEST(matrix, Determinant_Throw) {
  try {
    S21Matrix matr(4, 4);
    matr.SetRows(-1);
    matr.Determinant();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, Determinant_Throw2) {
  try {
    S21Matrix matr(4, 1);
    matr.Determinant();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Matrix is not square");
  }
}

TEST(matrix, InverseMatrix) {
  S21Matrix matr;
  S21Matrix result;
  matr(0, 0) = 2;
  matr(0, 1) = 5;
  matr(0, 2) = 7;
  matr(1, 0) = 6;
  matr(1, 1) = 3;
  matr(1, 2) = 4;
  matr(2, 0) = 5;
  matr(2, 1) = -2;
  matr(2, 2) = -3;

  result(0, 0) = 1;
  result(0, 1) = -1;
  result(0, 2) = 1;
  result(1, 0) = -38;
  result(1, 1) = 41;
  result(1, 2) = -34;
  result(2, 0) = 27;
  result(2, 1) = -29;
  result(2, 2) = 24;

  matr = matr.InverseMatrix();
  ASSERT_TRUE(matr.EqMatrix(result));
}

TEST(matrix, InverseMatrix_Throw) {
  try {
    S21Matrix matr(4, 4);
    matr.SetRows(-1);
    matr.InverseMatrix();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix");
  }
}

TEST(matrix, InverseMatrix_Throw_2) {
  try {
    S21Matrix matr(2, 2);
    matr(0, 0) = 1;
    matr(0, 1) = 2;
    matr(1, 0) = 2;
    matr(1, 1) = 4;
    matr.InverseMatrix();
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Determinant equals 0");
  }
}

TEST(getters_setters, Set) {
  S21Matrix matr(5, 5);
  double value_matr[5] = {1, 2, 3, 4, 5};
  matr.FillMatrix(value_matr, 5);
  matr.SetCols(6);
  for (int i = 0; i < matr.GetRows(); i++) {
    ASSERT_EQ(matr(i, 5), 0);
  }
}

TEST(getters_setters, Set2) {
  S21Matrix matr(5, 5);
  double value_matr[5] = {1, 2, 3, 4, 5};
  matr.FillMatrix(value_matr, 5);
  matr.SetRows(6);
  for (int i = 0; i < matr.GetCols(); i++) {
    ASSERT_EQ(matr(5, i), 0);
  }
}

TEST(getters_setters, Set3) {
  S21Matrix matr(5, 5);
  double value_matr[5] = {1, 2, 3, 4, 5};
  matr.FillMatrix(value_matr, 5);
  matr.SetRows(4);
  ASSERT_NE(matr.GetRows(), 5);
}

TEST(getters_setters, Set4) {
  S21Matrix matr(5, 5);
  double value_matr[5] = {1, 2, 3, 4, 5};
  matr.FillMatrix(value_matr, 5);
  matr.SetCols(4);
  ASSERT_NE(matr.GetCols(), 5);
}

TEST(getters_setters, Get) {
  S21Matrix matr(5, 8);
  ASSERT_EQ(matr.GetCols(), 8);
}

TEST(getters_setters, Get2) {
  S21Matrix matr(6, 5);
  ASSERT_EQ(matr.GetRows(), 6);
}
