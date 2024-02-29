#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.h"
#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix();

    Matrix(int rows, int cols);

    Array<T>& operator[](int row);
    const Array<T>& operator[](int row) const;

    int num_rows() const;
    int num_cols() const;

    void fill(const T& val);

    
    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
Matrix<T>::Matrix() : rows(0), cols(0) {}

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows) {
    for (int i = 0; i < rows; ++i) {
        data[i] = Array<T>(cols);
    }
}


template <typename T>
Array<T>& Matrix<T>::operator[](int row) {
    return data[row];
}

template <typename T>
const Array<T>& Matrix<T>::operator[](int row) const {
    return data[row];
}

template <typename T>
int Matrix<T>::num_rows() const {
    return rows;
}

template <typename T>
int Matrix<T>::num_cols() const {
    return cols;
}

template <typename T>
void Matrix<T>::fill(const T& val) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = val;
        }
    }
}

template <typename T>
template <typename Fn>
void Matrix<T>::fill_with_fn(Fn fn) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = fn(i, j);
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.num_rows(); ++i) {
        for (int j = 0; j < matrix.num_cols(); ++j) {
            out << matrix[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
    for (int i = 0; i < matrix.num_rows(); ++i) {
        for (int j = 0; j < matrix.num_cols(); ++j) {
            in >> matrix[i][j];
        }
    }
    return in;
}

#endif


