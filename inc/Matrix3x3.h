#pragma once
#include "Matrix.h"

class Matrix3x3
    : public Matrix<double, 3>{
public:
    Matrix3x3();
    Matrix3x3(double degree, char axis);
    Matrix3x3& operator=(const Matrix3x3 matrix3x3);
    Matrix3x3& operator=(const Matrix<double, 3> matrix3x3);
};

