#include "Matrix.h"

class TranslationMatrix : public Matrix {
    double xShift, yShift;
public:
    TranslationMatrix(double xShift, double yShift);
    void apply(double &x, double &y) const override;
};

TranslationMatrix::TranslationMatrix(double xShift_, double yShift_) : Matrix(2,2), xShift(xShift_), yShift(yShift_) {
    // We won't use the matrix directly here, just store shifts.
    // Identity matrix is fine
    (*this)(0,0) = 1.0; (*this)(0,1) = 0.0;
    (*this)(1,0) = 0.0; (*this)(1,1) = 1.0;
}

void TranslationMatrix::apply(double &x, double &y) const {
    x += xShift;
    y += yShift;
}