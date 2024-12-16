#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cmath>

class Matrix {
protected:
    int rows;
    int cols;
    std::vector<std::vector<double>> a;
public:
    Matrix(int _rows, int _cols);
    virtual ~Matrix() = default;

    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    virtual void apply(double &x, double &y) const = 0; // apply transformation to a point
};

#endif
