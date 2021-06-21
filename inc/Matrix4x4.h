#pragma once
#include "Matrix.h"

class Matrix4x4
        : public Matrix<double, 4>{
public:
    Matrix4x4();
    Matrix4x4(double jaw, double pitch, double roll, Vector<double, 3> axis);
    Matrix4x4& operator=(const Matrix4x4 matrix4x4);
    Matrix4x4& operator=(const Matrix<double, 4> matrix4x4);

};

