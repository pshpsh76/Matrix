#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>

class Matrix {
    int n, m;
    vector<vector<T>> data;
public:
    Matrix(int _n, int _m);
    Matrix(vector<vector<T>>);
    pair<int, int> size() const;
    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(T) const;
    const Matrix operator*(const Matrix&) const;
    T& operator[](int i) { return data[i]; };
    const T& operator[](int i) const { return data[i]; };
    template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, Matrix<Type>&);
};

template<typename T>
Matrix<T>::Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    data.resize(n, vector<T>(m));
}

template<typename T>
Matrix<T>::Matrix(vector<vector<T>>& vect) {
    data = vect;
    n = vect.size();
    if (n != 0) m = vect[0].size();
    else m = 0;
}

template<typename T>
const Matrix Matrix<T>::operator+(const Matrix& a) const {
    if (a.size() != *(this)->size()) {
        throw "Matrices are of different sizes";
    }
    vector<vector<T>> res(n, vector<T>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = data[i][j] + a.data[i][j];
        }
    }
    return Matrix(res);
}

template<typename T>
const Matrix Matrix<T>::operator*(T c) const {
    vector<vector<T>> res(n, vector<T>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = data[i][j] * c;
        }
    }
    return Matrix(res);
}

template<typename T>
const Matrix Matrix<T>::operator*(const Matrix& a) const {
    if (m != a.n) {
        throw "The product of matrices for the given sizes is undefined";
    }
    vector<vector<T>> res(n, vector<T>(a.m));
    int k = a.m;
}

template<typename Type>
istream &operator>>(istream &, Matrix<Type> &) {
    return <#initializer#>;
}

template<typename Type>
ostream &operator<<(ostream &, Matrix<Type> &) {
    return <#initializer#>;
}

template<typename T>
pair<int, int> Matrix<T>::size() const {
    return {n, m};
}

#endif //MATRIX_MATRIX_H
