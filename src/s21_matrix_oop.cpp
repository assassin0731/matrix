#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { Create(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Rows or columns are less then 1");
  }
  Create();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  Create();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.cols_ = other.rows_ = 0;
}

S21Matrix::~S21Matrix() { Remove(); }

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool return_value = SUCCESS;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_ && return_value != FAILURE; i++) {
      for (int j = 0; j < cols_ && return_value != FAILURE; j++) {
        if (abs(abs(matrix_[i][j]) - abs(other.matrix_[i][j])) > eps) {
          return_value = FAILURE;
        }
      }
    }
  } else {
    return_value = FAILURE;
  }
  return return_value;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different rows or cols");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different rows or cols");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range("Cols of first doesn't match rows of second");
  }
  S21Matrix tmp((S21Matrix &&) * this);
  rows_ = tmp.rows_;
  cols_ = other.cols_;
  Create();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
      for (int k = 0; k < tmp.cols_; k++) {
        matrix_[i][j] += tmp.matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transponse_matrix(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      transponse_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return transponse_matrix;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::out_of_range("Matrix is not square");
  }
  double return_value = 0;
  if (rows_ == 1) {
    return_value = matrix_[0][0];
  } else if (rows_ == 2) {
    return_value =
        matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix tmp(rows_ - 1, rows_ - 1);
    double cycle_for = 1;
    for (int i = 0; i < rows_; i++) {
      return_value += cycle_for * matrix_[0][i] *
                      tmp.MinorMatrix(*this, 0, i).Determinant();
      cycle_for *= -1;
    }
  }
  return return_value;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::out_of_range("Matrix is not square");
  }
  S21Matrix return_matrix(rows_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < rows_; j++) {
      S21Matrix tmp(rows_ - 1, rows_ - 1);
      double determ = tmp.MinorMatrix(*this, i, j).Determinant();
      return_matrix.matrix_[i][j] = determ * pow(-1, i + j);
    }
  }
  return return_matrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determ = Determinant();
  if (abs(determ) < eps) {
    throw std::out_of_range("Determinant is 0");
  }
  S21Matrix transp_alg_dop(CalcComplements().Transpose());
  transp_alg_dop.MulNumber(1. / determ);
  return transp_alg_dop;
}
