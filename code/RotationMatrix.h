#include "Matrix.h"
#include <cmath>

class RotationMatrix : public Matrix {
public:
    RotationMatrix(double theta); // theta in radians
    void apply(double &x, double &y) const override;
};

RotationMatrix::RotationMatrix(double theta) : Matrix(2,2) {
    (*this)(0,0) = std::cos(theta); (*this)(0,1) = -std::sin(theta);
    (*this)(1,0) = std::sin(theta); (*this)(1,1) = std::cos(theta);
}

void RotationMatrix::apply(double &x, double &y) const {
    double nx = (*this)(0,0)*x + (*this)(0,1)*y;
    double ny = (*this)(1,0)*x + (*this)(1,1)*y;
    x = nx; y = ny;
}
