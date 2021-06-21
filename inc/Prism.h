#pragma once

#include "Object.h"


class Prism: public Object{
public:
    Prism();
    Prism(std::string fileNameOfModel, std::string fileNameOfBlock = "../data/CuboidBlock.txt",
            Matrix3x3 initialOrientation = Matrix3x3(), vector3D initialPosition = vector3D());
    /*! read position of obstacle from file and convert it by scale*/
    void readModelVerticesPosition() override;
    /*! calculate actual position of obstacle*/
    void calculatePosition() override;
    std::string getType() override;

};

