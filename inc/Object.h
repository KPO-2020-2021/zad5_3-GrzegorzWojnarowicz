#pragma once

#include <fstream>
#include "Vector3D.h"
#include "Matrix3x3.h"

class Object{
protected:
    static int Total;
    std::string fileNameOfModel;
    std::string fileNameOfBlock;
    Matrix3x3 orientation;
    vector3D positionOfCenterOfMass;
    vector3D vertices[VERTICES_NUMBER_OF_CUBOID];
    double scaleX;
    double scaleY;
    double scaleZ;
public:
    Object();
    /*! read position of vertices from model file */
    virtual void readModelVerticesPosition() {};
    /*! calculate actual position of every drone component */
    virtual void calculatePosition() {};
    std::string getFileNameOfModel();
    std::string getFileNameOfBlock();
    vector3D getPosition();
    Matrix3x3 getOrientation();
    void setOrientation(Matrix3x3 orient);
    void setPosition(vector3D pos);
    friend std::ostream & operator<<(std::ostream & ost, Object &scnObj);
    const vector3D & operator[](int index) const;
    vector3D & operator[](int index);
    /*! get total number of objects constructed. */
    int getTotal();
    virtual std::string getType() {return std::string("unknown object");};
    void setScaleX(double scaleX);
    void setScaleY(double scaleY);
    void setScaleZ(double scaleZ);
    double getScaleX();
    double getScaleY();
    double getScaleZ();


};

