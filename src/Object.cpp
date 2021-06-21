#include "Object.h"

int Object::Total=0;

Object::Object() {
}
std::string Object::getFileNameOfModel() {
    return this->fileNameOfModel;
}

std::string Object::getFileNameOfBlock() {
    return this->fileNameOfBlock;
}

vector3D Object::getPosition() {
    return this->positionOfCenterOfMass;
}

Matrix3x3 Object::getOrientation() {
    return this->orientation;
}

void Object::setOrientation(Matrix3x3 orient) {
    this->orientation =orient;
}

void Object::setPosition(vector3D pos) {
    this->positionOfCenterOfMass = pos;
}

std::ostream &operator<<(std::ostream &ost, Object &cone) {
    ost << std::setprecision(10) << std::fixed;


    vector3D up = cone[2];
    up = up - cone[0];
    up = up/2;
    up = up + cone[0];
    vector3D down = cone[6];
    down = down - cone[4];
    down = down/2;
    down = down + cone[4];

    ost << up;
    ost << cone[2];
    ost << cone[6];
    ost << down << "#\n\n";

    ost << up;
    ost << cone[1];
    ost << cone[5];
    ost << down << "#\n\n";

    ost << up;
    ost << cone[0];
    ost << cone[4];
    ost << down << "#\n\n";

    ost << up;
    ost << cone[3];
    ost << cone[7];
    ost << down << "#\n\n";

    ost << up;
    ost << cone[2];
    ost << cone[6];
    ost << down << "#\n\n";

    return ost;
}


vector3D &Object::operator[](int index) {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("index out of range");
    }
}

const vector3D &Object::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("index out of range");
    }
}

int Object::getTotal() {
    return this->Total;
}

void Object::setScaleX(double scaleX) {
    this->scaleX = scaleX;
}

void Object::setScaleY(double scaleY) {
    this->scaleY = scaleY;
}

void Object::setScaleZ(double scaleZ) {
    this->scaleZ = scaleZ;
}

double Object::getScaleX() {
    return this->scaleX;
}

double Object::getScaleY() {
    return this->scaleY;
}

double Object::getScaleZ() {
    return this->scaleZ;
}