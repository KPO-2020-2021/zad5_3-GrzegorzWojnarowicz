#pragma once
#include <iostream>
#include <utility>
#include <cmath>
#include <float.h>
#include <fstream>
#include "Object.h"
#include "sstream"

class Cuboid: public Object{
protected:
    vector3D vertices[VERTICES_NUMBER_OF_CUBOID];
public:
    Cuboid();
    Cuboid(std::string fileNameOfModel, std::string fileNameOfBlock = "../data/CuboidBlock.txt",
           Matrix3x3 initialOrientation = Matrix3x3(), vector3D initialPosition = vector3D());
    /*! read position from model file */
    void readModelVerticesPosition();
    /*! calculate actual position */
    void calculateActualPosition();
    friend bool operator==(const Cuboid &cub1, const Cuboid &cub2);
    /*! Translate all vertices by vector*/
    void translationByVector(vector3D &Vec);
    /*! Rotate all vertices by matrix*/
    void rotationByMatrix(const Matrix3x3 &rotMatrix);
    const vector3D & operator[](int index) const;
    vector3D & operator[](int index);
    /*! write readable for gnuplot positions of cuboid vertices */
    friend std::ostream & operator<<(std::ostream & ost, Cuboid &cub);
};

