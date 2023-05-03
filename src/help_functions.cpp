#include "s21_matrix_oop.h"

S21Matrix S21Matrix::MinorMatrix(const S21Matrix &other, int rows_i,
                                 int rows_j) {
  for (int i = 0, i_tmp = 0; i < other.rows_; i++, i_tmp++) {
    for (int j = 0, j_tmp = 0; j < other.rows_; j++, j_tmp++) {
      if (j == rows_j && i == rows_i) {
        i++;
        j++;
      } else if (j == rows_j) {
        j++;
      } else if (i == rows_i) {
        i++;
      }
      if (i < other.rows_ && j < other.rows_) {
        matrix_[i_tmp][j_tmp] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

void S21Matrix::Create() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

void S21Matrix::FillMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = rand() % 10;
    }
  }
}

void S21Matrix::Remove() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void S21Matrix::Copy(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  Create();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {
  if (rows < 1) {
    throw std::out_of_range("Number of rows is out of range");
  }
  S21Matrix tmp(*this);
  Remove();
  rows_ = rows;
  cols_ = tmp.cols_;
  Create();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i >= tmp.rows_) {
        matrix_[i][j] = 0;
      } else {
        matrix_[i][j] = tmp.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::setCols(int cols) {
  if (cols < 1) {
    throw std::out_of_range("Number of cols is out of range");
  }
  S21Matrix tmp(*this);
  Remove();
  rows_ = tmp.rows_;
  cols_ = cols;
  Create();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (j >= tmp.cols_) {
        matrix_[i][j] = 0;
      } else {
        matrix_[i][j] = tmp.matrix_[i][j];
      }
    }
  }
}