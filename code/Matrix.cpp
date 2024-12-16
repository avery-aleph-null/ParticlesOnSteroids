#include "Matrix.h"

Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols), a(_rows, std::vector<double>(_cols,0.0)) {}

double& Matrix::operator()(int i, int j) {
    return a[i][j];
}

const double& Matrix::operator()(int i, int j) const {
    return a[i][j];
}
