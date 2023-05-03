#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix return_matrix(*this);
  return_matrix.SumMatrix(other);
  return return_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix return_matrix(*this);
  return_matrix.SubMatrix(other);
  return return_matrix;
}

S21Matrix operator*(const S21Matrix &first, const S21Matrix &second) {
  S21Matrix return_matrix(first);
  return_matrix.MulMatrix(second);
  return return_matrix;
}

S21Matrix operator*(const S21Matrix &matrix, const double num) {
  S21Matrix return_matrix(matrix);
  return_matrix.MulNumber(num);
  return return_matrix;
}

S21Matrix operator*(const double num, const S21Matrix &matrix) {
  S21Matrix return_matrix(matrix);
  return_matrix.MulNumber(num);
  return return_matrix;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  Remove();
  Copy(other);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Number of row or column is out of range");
  }
  return matrix_[row][col];
}