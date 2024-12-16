#include "Matrix.h"

class ScalingMatrix : public Matrix {
public:
    ScalingMatrix(double scale);
    void apply(double &x, double &y) const override;
};

ScalingMatrix::ScalingMatrix(double scale) : Matrix(2,2) {
    (*this)(0,0) = scale; (*this)(0,1) = 0.0;
    (*this)(1,0) = 0.0;   (*this)(1,1) = scale;
}

void ScalingMatrix::apply(double &x, double &y) const {
    double nx = (*this)(0,0)*x + (*this)(0,1)*y;
    double ny = (*this)(1,0)*x + (*this)(1,1)*y;
    x = nx; y = ny;
}