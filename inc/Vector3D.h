#pragma once
#include "Vector.h"


class vector3D
        :public Vector<double ,3>{
private:
    static int Total;
    static int Actual;
public:
    vector3D();
    vector3D(double x, double y, double z);
    ~vector3D();
    vector3D(const vector3D &v);
    static int getActual();
    static int getTotal();

    vector3D& operator=(const vector3D vec);
    vector3D& operator=(const Vector<double, 3> vec);
};
