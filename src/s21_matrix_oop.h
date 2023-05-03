#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define SUCCESS true
#define FAILURE false
#define eps 1e-07

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double **matrix_;

 public:
  // Constructors and destructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // Task functions
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // Operators
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  friend S21Matrix operator*(const S21Matrix &first, const S21Matrix &second);
  friend S21Matrix operator*(const double num, const S21Matrix &matrix);
  friend S21Matrix operator*(const S21Matrix &matrix, const double num);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num);
  double &operator()(int row, int col);

  // Accessors and mutators
  int getRows() const;
  int getCols() const;
  void setRows(int rows);
  void setCols(int cols);

  // Help functions
  S21Matrix MinorMatrix(const S21Matrix &other, int rows_i, int rows_j);
  void Create();
  void Copy(const S21Matrix &other);
  void FillMatrix();
  void Remove();
};

S21Matrix operator*(const double num, const S21Matrix &matrix);
S21Matrix operator*(const S21Matrix &matrix, const double num);
S21Matrix operator*(const S21Matrix &first, const S21Matrix &second);

#endif  //  SRC_S21_MATRIX_OOP_H_