#ifndef CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

#include <math.h>

#include <iostream>

#define SUCCES 1
#define FAILURE 0

// по умолчанию все поля в классе приватные
class S21Matrix {
 public:
  // constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  ~S21Matrix();
  // operators
  S21Matrix operator+(const S21Matrix& other) const;  // +
  S21Matrix operator-(const S21Matrix& other) const;  // +
  S21Matrix operator*(const S21Matrix& other) const;  // +
  S21Matrix operator*(const double num) const;        // +
  friend S21Matrix operator*(const double num, const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);           // +
  S21Matrix& operator-=(const S21Matrix& other);           // +
  S21Matrix& operator*=(const S21Matrix& other);           // +
  S21Matrix& operator*=(const double num);                 // +
  bool operator==(const S21Matrix& other) const noexcept;  // +
  double& operator()(int i, int j);                        // +
  // methods
  void FillMatrix(double numbers[], int size) noexcept;
  bool CheckMatrix(const S21Matrix& other) const noexcept;
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);
  bool EqMatrix(const S21Matrix& other) const noexcept;  // +
  void SumMatrix(const S21Matrix& other);                // +
  void SubMatrix(const S21Matrix& other);                // +
  void MulNumber(const double num);                      // +
  void MulMatrix(const S21Matrix& other);                // +
  double Determinant();                                  // +
  S21Matrix Transpose();                                 // +
  S21Matrix CalcComplements();                           // +
  S21Matrix InverseMatrix();                             // +
 private:
  double** matrix_;
  int rows_;
  int cols_;
  void CreateMatrix(int rows, int columns);
  double Matrix_Determinant(const S21Matrix& other, int row, int column);
  void SumAndSubMatrix(char plus_or_minus, const S21Matrix& other);
};

#endif  // CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
