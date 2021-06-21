#pragma once

#include <fstream>
#include "Object.h"
#include "sstream"

class Hex
        : public Object{
protected:
    vector3D vertices[VERTICES_NUMBER_OF_HEX];
public:
    Hex();
    Hex(std::string fileNameOfModel, std::string fileNameOfBlock = "../data/HexBlock.txt",
                   Matrix3x3 initialOrientation = Matrix3x3(), vector3D initialPosition = vector3D());
    /*! write readable for gnuplot positions that are interpreted as non empty hex*/
    friend std::ostream & operator<<(std::ostream & ost, Hex &hex);
    /*! read position from model file */
    void readModelVerticesPosition();
    const vector3D & operator[](int index) const;
    vector3D & operator[](int index);
    /*! calculate actual position */
    void calculateActualPosition(vector3D posOfdroneBody);
    /*! Rotate all vertices by matrix*/
    void rotationByMatrix(Matrix3x3 rotMatrix);
    /*! Translate all vertices by vector*/
    void translationByVector(vector3D vec);

};

